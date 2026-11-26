// The runtime interface. A generated
// driver names one root and how to construct, load, save and destroy it;
// the runtime runs it over files, one forked child per file.
#pragma once

#include <cstddef>

class MtStream;

struct DdonRoot {
    const char* name;
    void* (*create)();
    bool (*load)(void* root, MtStream& in);
    // The root's own `save`, run after a `load` that returned
    // true, into a fresh output stream whose bytes are compared with the
    // file. Null when the root's virtual `save` is `cResource::save` (the
    // bundle's `load-save.json`, from DWARF): the file reports `no own save`.
    bool (*save)(void* root, MtStream& out);
    void (*destroy)(void* root);
    // The field dump, after a `load` that returned true and its
    // save, before destroy: it hands the runtime its JSON through
    // `ddon_dump_append`. Null when the driver has none.
    void (*dump)(void* root);
    // The derived save: a save written by inverting the
    // root's load, never the game's code. Run after `save`, in a child of its
    // own, into a second fresh output stream; its result is recorded apart
    // (`derived_*`) and changes nothing the game's own save or the load
    // reports. Null when the bundle has none for the root.
    bool (*derived_save)(void* root, MtStream& out);
};

// Appends to the file's field dump (`dump.h`).
void ddon_dump_append(const char* text, std::size_t size);

// The inner resources (`fixtures.cpp`): a
// request the host's `sResource` answered goes into the file's record as a
// note, `{"class","path","via","mode","outcome"}`; no outcome of the file
// reads it.
void ddon_inner_requested(const char* class_name, const char* path, const char* via, unsigned mode,
                          const char* outcome);
// Counts one instance the host built for a request (loaded or not), and one
// destroyed by its last release.
void ddon_inner_created();
void ddon_inner_released();

// How an inner load's trial ended: its load ran clean and returned true, ran
// clean and returned false, found no file, or met a wall (a stub reached, a
// trap, a crash), whose text `ddon_inner_trial` copies out. `direct`: no
// trial, since every trial of the class so far loaded (031
// plan-HOST-STAGE-2); the load runs in the file's process, and any wall
// after it has the file run again, each of its loads in a trial.
enum class DdonInnerTrial { loaded, refused, no_file, wall, direct };
// The request a trial answers, as its note names it.
struct DdonInnerKey {
    const char* class_name;
    const char* path;
    const char* via;
    unsigned mode;
};
// Runs `attempt(context)` in a child of its own, as the derived save runs:
// whatever it reaches stays there. `attempt` returns 0 (loaded), 1 (refused)
// or 2 (no file).
// The rerun of a clean trial replays it: the same code from
// the same state, so it asks the same inner requests in the same order. The
// child sends back each request's verdict with its key, and the requests of
// the rerun that follows take them in order instead of a trial of their own;
// the first whose key differs, and every one after it, runs its own trial.
DdonInnerTrial ddon_inner_trial(const DdonInnerKey& key, int (*attempt)(void* context),
                                void* context, char* wall, std::size_t size);
// Runs a clean trial's rerun, `rerun(context)`, and returns its code; the
// verdicts its trial sent back last no longer than it does.
int ddon_inner_rerun(int (*rerun)(void* context), void* context);
// A dependent resource's file (the ELF's `sResource::loadBlocking`, 0x126dfb0:
// `<root>\<path>.<ext>`): `<path>.<ext>` beside the root's own file, under
// its archive's directory, as a read-only stream; null when the corpus holds
// none there. Closed by `ddon_inner_file_close`. `*staged`, unless null, is
// whether the stage gave the file, in the form its own root reads it in.
MtStream* ddon_inner_file(const char* path, const char* ext, bool* staged);
void ddon_inner_file_close(MtStream* stream);
// Whether the stage translates the files of a class's root (the format
// census): what the PC client wrote for it is no image its load reads.
bool ddon_entry_translated(const char* class_name);
// The image the stage gives a plain file of extension `ext` that holds
// exactly these bytes, found by their SHA-256; null where the run staged no
// such file. Closed by `ddon_inner_file_close`.
MtStream* ddon_entry_image(const void* bytes, std::size_t size, const char* ext);

// The file's own bytes `[offset, offset + size)`, for a host fact the
// fixtures note while the load runs (an archive
// entry's stored bytes, kept for rArchive's host writer): null unless
// `stream` is the file's input stream, its load has not returned yet and the
// range lies inside the file. Never read after load, so no save reads its
// input through it.
const unsigned char* ddon_input_bytes(const MtStream* stream, std::size_t offset, std::size_t size);

// Counts, in the derived save's record, an archive's entry of `size` stored
// bytes that the host's writer kept as stored, with nothing its resource saved
// to hold them against.
void ddon_note_kept_entry(const char* class_name, std::size_t size);

// Storage for a root, from the host (not the engine's allocator).
void* ddon_host_alloc(std::size_t size, std::size_t align);
void ddon_host_free(void* memory);
// `ddon_host_alloc` for what the fixtures keep for themselves, never a block
// the game holds: no file's leak.
void* ddon_own_alloc(std::size_t size, std::size_t align);
std::size_t ddon_host_size(void* memory);
// A file's value that a load overwrites where it read it (rModel's
// `PRIMITIVE_INFO::connect_id`): a host-only plant keeps it as the load runs,
// by the record's address, and a derived save takes it back
// (`resources/derived-saves`, a `host_fact`). Nothing is kept after load.
void ddon_keep_overwritten(const void* record, unsigned value);
bool ddon_overwritten(const void* record, unsigned* value);
// The properties of the file's XFS database as the game's load meets them, which a
// host-only plant keeps: `MtSerializer::mappingObject` each property's record
// (`name`, `param32`, its `place` among class `id`'s, `skipped` where no class of
// the bundle registers it), `MtSerializer::readClass` the bytes `[from, to)` it
// skips as such a property's value of the instance `object`. A derived save puts
// the skipped ones back into the database the game's writer wrote, and takes out
// the properties the file does not hold (`resources/derived-saves`, a
// `host_fact`; `xfs_put_back.h`). The database begins at `at` of what the save has
// written and ends it. False where one has no place. What it takes from the file
// is listed, class by class, in the entry (`DdonPutBack`), counted in the file's
// record (`derived_put_back`), and refused by name where no row lists it.
void ddon_keep_property(unsigned id, unsigned place, const char* name, unsigned param32,
                        bool skipped);
void ddon_keep_value(const MtStream* stream, unsigned object, unsigned place, unsigned from,
                     unsigned to);
struct DdonPutBackRow {
    enum Kind : unsigned char { kKept, kLeftOut, kAttribute };
    Kind kind;
    const char* class_name;
    const char* property;
    // `MtProperty::TYPE`, and an attribute's bits in the file and as registered.
    unsigned type;
    unsigned file;
    unsigned registered;
};
struct DdonPutBack {
    const DdonPutBackRow* rows;
    std::size_t count;
};
bool ddon_put_back_skipped(MtStream& out, const DdonPutBack& lists, unsigned at = 0);
// The name the bundle's registry gives a class's id, or null (`fixtures.cpp`).
__attribute__((weak)) const char* ddon_class_name(unsigned id);
// The engine's allocators' storage (`fixtures.cpp`), each block known while it
// lives: what the game itself allocated, by its start.
void* ddon_game_alloc(std::size_t size, std::size_t align);
void ddon_game_free(void* memory);
bool ddon_game_allocated(const void* memory);
// The bytes the game asked for of a live block of its own, exactly, or 0: a
// load that reads a file whole into one block asks for the file's length (031
// plan-DERIVED-8's derived saves).
std::size_t ddon_game_size(const void* memory);

// A body that does not exist in the bundle was reached: the run of this
// file ends here (generated traps call it).
extern "C" [[noreturn]] void ddon_trap(const char* name);

// Engine services the fixtures provide, set up before any file runs.
void ddon_fixtures_init();

// `place_path` gives a constructed root its file's game path, before `load`:
// a list line is `<file>\t<game path>`; a line with no tab,
// or no `place_path`, gives none.
int ddon_runner_main(int argc, char** argv, const DdonRoot& root,
                      void (*place_path)(void* root, const char* path) = nullptr);
