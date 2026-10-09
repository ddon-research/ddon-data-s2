#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/MtObject.h"
#include "../shared/cResource.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtUI;
class MtVector3;

// Declarations
class rOccluder;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class rOccluder : public cResource
{
public:
    class MyDTI;
    class cQuad;
    struct HEADER;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cQuad : public MtObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        static MtDTI* getMyDTIPtr();
        static void usage();
        virtual const MtDTI& getDTI() const;  // vtable slot 5
        static MtAllocator* getAllocator();
        static void setAllocator(u32);
        static void* operator new(size_t sz, u32 align);
        static void* operator new[](size_t sz, u32 align);
        static void* operator new(size_t sz, void* p_addr);
        static void* operator new[](size_t sz, void* p_addr);
        static void operator delete(void* p_addr);
        static void operator delete[](void* p_addr);
        static void operator delete(void* p_addr, u32 align);
        static void operator delete[](void* p_addr, u32 align);
        cQuad();
        virtual ~cQuad();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        bool save(MtStream& out);
        bool load(MtStream& in);
        const MtVector3* getPoints() const;
        bool isActive() const;
        void setActive(bool);
        virtual void debugDraw(const MtColor& color);  // vtable slot 6
        virtual void fitting();  // vtable slot 7
    protected:
        MtVector3 mQuad[4];  // offset: 0x10
        bool mActive;  // offset: 0x50
        bool mEnable;  // offset: 0x51
    public:
        static MyDTI DTI;
    };
public:
    struct HEADER
    {
    public:
        u32 magic;  // offset: 0x0
        u16 version;  // offset: 0x4
        u16 dummy;  // offset: 0x6
    };
public:
    static MtDTI* getMyDTIPtr();
    static void usage();
    virtual const MtDTI& getDTI() const;  // vtable slot 5
    static MtAllocator* getAllocator();
    static void setAllocator(u32);
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete(void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
    rOccluder();
    virtual ~rOccluder();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    cQuad* getOccluder() const;
    u32 getOccluderCount() const;
protected:
    u32 mOccluderCount;  // offset: 0x70
    cQuad* mpOccluder;  // offset: 0x78
public:
    static MyDTI DTI;
protected:
    static const u16 DATA_VERSION = 3411;
    static const u32 HEADER_MAGIC = 4408143;
};

// Inline, no code of its own: checked where it is inlined.
// inferred: the constructor from _ZNK9rOccluder5MyDTI11newInstanceEv at 0x011dc870-0x011dc8a4, code DWARF attributes to no inlined copy
inline rOccluder::rOccluder() {
    this->::cResource::mAttr = static_cast<u32>(18);
    this->mOccluderCount = static_cast<u32>(0);
    this->mpOccluder = static_cast<rOccluder::cQuad*>(nullptr);
}
