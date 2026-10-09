#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cLayoutSet.h"
#include "rLayout.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cOmControl;
class rLayout;

// Declarations
class cLayoutSetOm;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cLayoutSetOm : public cLayoutSet
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
    cLayoutSetOm();
    virtual ~cLayoutSetOm();
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void finish();  // vtable slot 8
    virtual void splitKillSub();  // vtable slot 9
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtObject* setLayoutUnit(rLayout* pLayout, u32 no, bool isForceSet, u32 mode);  // vtable slot 18
    MtObject* setLayoutUnitClient(rLayout* pLayout, u32 no, bool isForceSet, u32 mode);
    MtObject* setLayoutUnitSever(rLayout* pLayout, u32 no, bool isForceSet, u32 mode);
    virtual bool deleteAllUnit();  // vtable slot 11
    virtual void deleteUnit(MtObject* pObj);  // vtable slot 12
    s32 getIndexFromID(u32 id) const;
    s32 getOmSetTblIndex(MT_CTSTR name);
    virtual void updateUnitPtrArray(bool isErase);  // vtable slot 13
    void setLotType(rLayout::TYPE lotType);
    rLayout::TYPE getLotType(rLayout::TYPE);
protected:
    virtual bool canSetUnit() const;  // vtable slot 14
    virtual bool isUseUnitData() const;  // vtable slot 15
    virtual bool isLoadAreaChangeSet() const;  // vtable slot 16
    virtual void moveSetUnit();  // vtable slot 17
    void moveSetUnitClient();
    void moveSetUnitSever();
private:
    cOmControl* createUnitOm(const rLayout::SetInfo* psi);
protected:
    rLayout::TYPE mLotType;  // offset: 0x84
public:
    static MyDTI DTI;
};
