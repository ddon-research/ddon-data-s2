#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;

// Declarations
class cFurnitureGroup;
class cFurnitureItem;
class cFurnitureLayout;
class rFurnitureGroup;
class rFurnitureItem;
class rFurnitureLayout;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cFurnitureGroup : public MtObject
{
public:
    enum
    {
        DATA_VERSION = 1,
    };
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
    cFurnitureGroup();
    virtual ~cFurnitureGroup() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
public:
    u32 mID;  // offset: 0x8
    u32 mCameraNo;  // offset: 0xc
    u32 mGmdIdx;  // offset: 0x10
    u8 mSortNo;  // offset: 0x14
    static MyDTI DTI;
};

class cFurnitureItem : public MtObject
{
public:
    enum
    {
        DATA_VERSION = 1,
    };
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
    cFurnitureItem();
    virtual ~cFurnitureItem() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
public:
    u32 mItemId;  // offset: 0x8
    u32 mLayoutId;  // offset: 0xc
    u32 mOmId;  // offset: 0x10
    static MyDTI DTI;
};

class cFurnitureLayout : public MtObject
{
public:
    enum
    {
        DATA_VERSION = 1,
    };
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
    cFurnitureLayout();
    virtual ~cFurnitureLayout() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
public:
    u32 mID;  // offset: 0x8
    u32 mGroupId;  // offset: 0xc
    bool mIsRemovable;  // offset: 0x10
    u8 mSortNo;  // offset: 0x11
    u32 mGmdIdx;  // offset: 0x14
    static MyDTI DTI;
};

class rFurnitureGroup : public rTbl2<cFurnitureGroup>
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
    virtual bool loadData(MtDataReader& r, cFurnitureGroup* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

class rFurnitureItem : public rTbl2<cFurnitureItem>
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
    virtual bool loadData(MtDataReader& r, cFurnitureItem* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

class rFurnitureLayout : public rTbl2<cFurnitureLayout>
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
    virtual bool loadData(MtDataReader& r, cFurnitureLayout* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

inline void* cFurnitureGroup::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cFurnitureGroup::cFurnitureGroup() {
    this->mSortNo = 0;
    this->mGmdIdx = 0;
    this->mID = 0;
    this->mCameraNo = 0;
}

inline void* cFurnitureItem::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cFurnitureItem::cFurnitureItem() {
    this->mItemId = 0;
    this->mLayoutId = 0;
    this->mOmId = 0;
}

inline void* cFurnitureLayout::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cFurnitureLayout::cFurnitureLayout() {
    this->mGmdIdx = 0;
    this->mIsRemovable = false;
    this->mSortNo = 0;
    this->mID = 0;
    this->mGroupId = 0;
}

inline void* rFurnitureGroup::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* rFurnitureItem::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* rFurnitureLayout::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void cFurnitureGroup::operator delete[](void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cFurnitureGroup::DTI)->memFree(p_addr);
}

inline void* cFurnitureGroup::operator new[](size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cFurnitureGroup::DTI)->memAlloc(sz, align, ::cFurnitureGroup::DTI.::MtDTI::getID());
}

inline void cFurnitureItem::operator delete[](void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cFurnitureItem::DTI)->memFree(p_addr);
}

inline void* cFurnitureItem::operator new[](size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cFurnitureItem::DTI)->memAlloc(sz, align, ::cFurnitureItem::DTI.::MtDTI::getID());
}

inline void cFurnitureLayout::operator delete[](void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cFurnitureLayout::DTI)->memFree(p_addr);
}

inline void* cFurnitureLayout::operator new[](size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cFurnitureLayout::DTI)->memAlloc(sz, align, ::cFurnitureLayout::DTI.::MtDTI::getID());
}
