// load-resource: loads one resource file of the game with the reconstructed
// library, the way the engine does it.
//
//   load-resource <root class> <file> [--save <out>] [--dump]
//
// The engine opens a resource file as an MtStream, creates the resource
// class through its MtDTI (the class registry's descriptor), and calls the
// resource's own virtual `load`. This program does the same with the
// reconstructed classes: every byte it interprets is interpreted by the
// reconstructed `load`, never by code here.

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

#include "runtime.h"   // DdonRoot: how to create, load, save and destroy one root class
#include "MtStream.h"  // the engine's stream interface (reconstructed)

// The roots this export can load (roots.cpp, generated from the harness
// report the export was made from), null-terminated.
extern const DdonRoot* const ddon_sample_roots[];
// What a root's field dump wrote (host.cpp).
extern std::string ddon_sample_dump;

namespace {

// A file's bytes in memory, as the engine's stream. The same class serves
// `--save`: writing past the end grows the buffer.
class MemoryStream final : public MtStream {
public:
    explicit MemoryStream(std::vector<unsigned char> bytes = {}) : mBytes(std::move(bytes)) {}

    const std::vector<unsigned char>& bytes() const { return mBytes; }
    // How often the reader asked for bytes at the end of the file. Once is
    // normal: the engine's reader refills its buffer after a read that ends
    // where the buffer does, and gets nothing.
    unsigned readsAtEnd() const { return mReadsAtEnd; }

    bool isReadable() override { return true; }
    bool isWritable() override { return true; }
    bool isSeekable() override { return true; }
    bool isAsyncReadable() override { return false; }
    bool isAsyncReading() const override { return false; }
    bool isAsyncOperationSucceeded() const override { return true; }
    u32 getPosition() override { return mPos; }
    u32 getLength() override { return static_cast<u32>(mBytes.size()); }

    u32 read(void* ptr, u32 size) override {
        u32 left = getLength() - mPos;
        u32 n = size < left ? size : left;
        mReadsAtEnd += size != 0 && left == 0;
        std::memcpy(ptr, mBytes.data() + mPos, n);
        mPos += n;
        return n;
    }
    u32 readAsync(void* ptr, u32 size) override { return read(ptr, size); }

    u32 write(const void* ptr, u32 size) override {
        if (mPos + size > mBytes.size()) {
            mBytes.resize(mPos + size);
        }
        std::memcpy(mBytes.data() + mPos, ptr, size);
        mPos += size;
        return size;
    }

    // A seek outside the buffer stops at its edge.
    u32 seek(s32 offset, MtStream::SEEK_ORIGIN origin) override {
        std::int64_t base = origin == ORG_BEGIN ? 0 : origin == ORG_CURRENT ? mPos : getLength();
        std::int64_t target = base + offset;
        target = target < 0 ? 0 : target > getLength() ? getLength() : target;
        mPos = static_cast<u32>(target);
        return mPos;
    }
    void skip(u32 size) override { seek(static_cast<s32>(size), ORG_CURRENT); }

private:
    std::vector<unsigned char> mBytes;
    u32 mPos = 0;
    unsigned mReadsAtEnd = 0;
};

bool read_file(const char* path, std::vector<unsigned char>& bytes) {
    std::FILE* file = std::fopen(path, "rb");
    if (!file) {
        return false;
    }
    unsigned char buffer[65536];
    for (std::size_t n; (n = std::fread(buffer, 1, sizeof buffer, file)) > 0;) {
        bytes.insert(bytes.end(), buffer, buffer + n);
    }
    std::fclose(file);
    return true;
}

bool write_file(const char* path, const std::vector<unsigned char>& bytes) {
    std::FILE* file = std::fopen(path, "wb");
    if (!file) {
        return false;
    }
    bool ok = std::fwrite(bytes.data(), 1, bytes.size(), file) == bytes.size();
    return std::fclose(file) == 0 && ok;
}

int usage(const char* program) {
    std::fprintf(stderr, "usage: %s <root class> <file> [--save <out>] [--dump]\nroots:", program);
    for (const DdonRoot* const* root = ddon_sample_roots; *root; ++root) {
        std::fprintf(stderr, " %s", (*root)->name);
    }
    std::fprintf(stderr, "\n");
    return 2;
}

}  // namespace

int main(int argc, char** argv) {
    if (argc < 3) {
        return usage(argv[0]);
    }
    const char* save_path = nullptr;
    bool dump = false;
    for (int i = 3; i < argc; ++i) {
        if (std::strcmp(argv[i], "--save") == 0 && i + 1 < argc) {
            save_path = argv[++i];
        } else if (std::strcmp(argv[i], "--dump") == 0) {
            dump = true;
        } else {
            return usage(argv[0]);
        }
    }
    const DdonRoot* root = nullptr;
    for (const DdonRoot* const* entry = ddon_sample_roots; *entry; ++entry) {
        if (std::strcmp((*entry)->name, argv[1]) == 0) {
            root = *entry;
        }
    }
    if (!root) {
        std::fprintf(stderr, "load-resource: no root named %s\n", argv[1]);
        return usage(argv[0]);
    }
    std::vector<unsigned char> bytes;
    if (!read_file(argv[2], bytes)) {
        std::fprintf(stderr, "load-resource: cannot read %s\n", argv[2]);
        return 2;
    }
    const std::size_t size = bytes.size();

    // The engine's services the library calls (its heap, its resource
    // manager, the class registry), set up once: host/fixtures.cpp.
    ddon_fixtures_init();

    // Create the resource as the engine does, and let it read the file.
    MemoryStream in(std::move(bytes));
    void* object = root->create();
    bool loaded = root->load(object, in);
    // The reader seeks back what it buffered and did not use, so the
    // position after `load` is the bytes the format consumed.
    u32 read = in.getPosition();
    std::printf("%s: load %s, read %u of %zu bytes%s\n", root->name,
                loaded ? "returned true" : "returned false", read, size,
                in.readsAtEnd() > 1 ? " (and asked again at the end)" : "");

    if (loaded && dump) {
        if (root->dump) {
            root->dump(object);
            std::printf("dump: %s\n", ddon_sample_dump.c_str());
        } else {
            std::printf("dump: %s has no field dump (it is no table)\n", root->name);
        }
    }

    if (loaded && save_path) {
        if (!root->save) {
            std::printf("save: %s has no save of its own (cResource::save)\n", root->name);
        } else {
            // The resource writes itself back; compare the output with the
            // file by hand (cmp, fc /b) for a round trip.
            MemoryStream out;
            bool saved = root->save(object, out);
            bool written = write_file(save_path, out.bytes());
            std::printf("save: %s, %zu bytes to %s%s\n", saved ? "returned true" : "returned false",
                        out.bytes().size(), save_path, written ? "" : " (could not write it)");
        }
    }

    root->destroy(object);
    // A whole load: `load` returned true and consumed every byte, asking at
    // the end no more than once.
    return loaded && read == size && in.readsAtEnd() <= 1 ? 0 : 1;
}
