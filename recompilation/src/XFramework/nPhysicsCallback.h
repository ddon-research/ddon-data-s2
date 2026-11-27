#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
class MtAllocator;
class MtObject;

// Declarations
namespace nPhysics { class Callback; }

// Type aliases from DWARF
using MT_MFUNC = void(MtObject::*)();
using u32 = unsigned int;

namespace nPhysics {
    class Callback
    {
    public:
        struct INFO;
    public:
        struct INFO
        {
        public:
            const nPhysics::Callback::INFO& operator=(const nPhysics::Callback::INFO& source);
        public:
            MtObject* Object;  // offset: 0x0
            MT_MFUNC Function;  // offset: 0x8
        };
    public:
        Callback();
        ~Callback();
        void initialize(MtAllocator* allocator);
        u32 get_num() const;
        void execute(const u32 index);
        void add(MtObject* object, MT_MFUNC function);
        bool remove(MtObject* object, MT_MFUNC function);
    private:
        MtAllocator* Allocator;  // offset: 0x0
        INFO* Info;  // offset: 0x8
        u32 Num;  // offset: 0x10
        u32 Size;  // offset: 0x14
    };
}  // namespace nPhysics
