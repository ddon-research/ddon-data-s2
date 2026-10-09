#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtPropertyList;
class rStageCustom;

// Declarations
class cStageCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cStageCtrl : public MtObject
{
public:
    enum
    {
        TYPE_ENTRANCE = 0,
        TYPE_LINK = 1,
        TYPE_END = 2,
        TYPE_LOAD = 3,
        TYPE_EXIT = 4,
        TYPE_WARP = 5,
        TYPE_EMPTY = 6,
        TYPE_MAX = 7,
        BIT_NONE = 0,
        BIT_ENTRANCE = 1,
        BIT_LINK = 2,
        BIT_END = 4,
        BIT_LOAD = 8,
        BIT_EXIT = 16,
        BIT_WARP = 32,
        BIT_EMPTY = 64,
    };
public:
    class MyDTI;
    class Area;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class Area : public MtObject
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
        Area();
        Area(s32 areaNo, s32 depth, s32 groupNo);
        // Address: 0x01a61a40 - 0x01a61a41 (1 bytes)
        virtual ~Area() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    public:
        s32 mAreaNo;  // offset: 0x8
        s32 mDepth;  // offset: 0xc
        s32 mGroupNo;  // offset: 0x10
        static MyDTI DTI;
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
    cStageCtrl();
    virtual ~cStageCtrl();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void clear();
    void copy(cStageCtrl* src);
    Area* getArea(u32 idx);
    s32 getAreaNo(u32 idx);
    u32 getAreaNum() const;
    s32 getGroupNo(u32 idx);
    void createCustomArea(rStageCustom* pRes);
    bool isInit() const;
public:
    MtTypedArray<Area> mAreaArray;  // offset: 0x8
    s32 mPartsDungeonNo;  // offset: 0x28
    bool mIsInit;  // offset: 0x2c
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cStageCtrl::Area::Area() {
    this->mAreaNo = static_cast<s32>(-1);
    this->mDepth = static_cast<s32>(-1);
    this->mGroupNo = static_cast<s32>(-1);
}
