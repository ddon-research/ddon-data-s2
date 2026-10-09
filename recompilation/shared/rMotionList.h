#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cResource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtStream;
namespace nMotion { struct MOTION_INFO; }

// Declarations
class rMotionList;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class rMotionList : public cResource
{
public:
    class MyDTI;
    struct MOTION_LIST_HDR;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct MOTION_LIST_HDR
    {
    public:
        u32 magic;  // offset: 0x0
        u16 version;  // offset: 0x4
        u16 motion_num;  // offset: 0x6
        nMotion::MOTION_INFO* pmotion[1];  // offset: 0x8
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
    rMotionList();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    u32 getMotionNum() const;
    nMotion::MOTION_INFO* getMotionInfo(u32 no) const;
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual void clear();  // vtable slot 15
protected:
    virtual ~rMotionList();
    void* memAlloc(u32 size);
    void memFree(void* p_addr);
protected:
    MOTION_LIST_HDR* mpHdr;  // offset: 0x70
public:
    static MyDTI DTI;
    static const s32 MAX_MOTION = 256;
    static const s32 MAX_SEQPAGE = 4;
    static const s32 MAX_KEYFRAME_TRACK = 31;
protected:
    static const u16 DATA_VERSION = 67;
};

// Inline, no code of its own: checked where it is inlined.
// inferred: the constructor from _ZNK11rMotionList5MyDTI11newInstanceEv at 0x011d8930-0x011d895d, code DWARF attributes to no inlined copy
inline rMotionList::rMotionList() {
    this->::cResource::mAttr = static_cast<u32>(16);
    this->mpHdr = static_cast<rMotionList::MOTION_LIST_HDR*>(nullptr);
}
