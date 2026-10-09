#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtPropertyList;

// Declarations
class cCursor;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cCursor : public MtObject
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
    cCursor();
    virtual ~cCursor();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void setupX(s32 min, s32 max, bool loop, bool trg, bool arrowOnly, bool clamp);
    void setupY(s32 min, s32 max, bool loop, bool trg, bool arrowOnly, bool clamp);
    void setupXY(s32 minX, s32 maxX, s32 minY, s32 maxY, bool loop, bool trg, bool arrowOnly, bool clamp);
    s32 updateX(s32& cursor);
    s32 updateY(s32& cursor);
    void updateXY(s32& cursorX, s32& cursorY);
    void stop(bool isStop);
    bool isStop();
private:
    bool mIsStop;  // offset: 0x8
    bool mIsLoop;  // offset: 0x9
    bool mIsTrg;  // offset: 0xa
    bool mIsArrowOnly;  // offset: 0xb
    bool mIsClamp;  // offset: 0xc
    s32 mMaxX;  // offset: 0x10
    s32 mMinX;  // offset: 0x14
    s32 mMaxY;  // offset: 0x18
    s32 mMinY;  // offset: 0x1c
public:
    static MyDTI DTI;
};
