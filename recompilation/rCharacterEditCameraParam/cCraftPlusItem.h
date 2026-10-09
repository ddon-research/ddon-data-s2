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
class cCraftQualityData;
class rCraftQuality;

// Declarations
class cCraftPlusItem;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cCraftPlusItem : public MtObject
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
    cCraftPlusItem();
    virtual ~cCraftPlusItem();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void setQualityResource(rCraftQuality* pResource);
    cCraftQualityData* getQualityResource(u32 itemID);
    void releaseQualityResource();
private:
    void init();
private:
    rCraftQuality* mpQualityResource;  // offset: 0x8
public:
    static MyDTI DTI;
    static const u32 ITEM_RANK_NUM = 12;
};

// Inline, no code of its own: checked where it is inlined.
inline void cCraftPlusItem::init() {
    this->mpQualityResource = static_cast<rCraftQuality*>(nullptr);
}
