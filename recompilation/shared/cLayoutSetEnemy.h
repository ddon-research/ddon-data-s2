#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cLayoutSet.h"
#include "rLayout.h"
#include "rLayoutGroupParam.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cContextInstance;
class cGroupParam;
class cLayoutPreset;
class cSetInfoEnemy;
namespace nLayout { struct stUniqueID; }
class rLayout;
class uCharacter;
class uControlEnemy;

// Declarations
class cLayoutSetEnemy;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cLayoutSetEnemy : public cLayoutSet
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
    cLayoutSetEnemy();
    virtual ~cLayoutSetEnemy();
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void finish();  // vtable slot 8
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtObject* setLayoutUnit(rLayout* pLayout, u32 no, bool isForceSet, u32 mode);  // vtable slot 18
    virtual MtObject* setLayoutUnitSever(rLayout* pLayout, u32 no, bool isForceSet, u32 mode);  // vtable slot 19
    virtual bool deleteAllUnit();  // vtable slot 11
    virtual void deleteUnit(MtObject* pObj);  // vtable slot 12
    s32 getIndexFromID(u32 id) const;
    static const cLayoutPreset* getPresetTbl(MT_CTSTR name);
    static s32 getEnemySetTblIndex(MT_CTSTR name);
    static s32 getEnemySetTblIndex(s32 uinitID);
    void setLifeArea(uCharacter* pChara);
    virtual MtObject* getUnit(u32 id);  // vtable slot 10
    uControlEnemy* createUnitEnemy(rLayout::SetInfo* psi, const cLayoutPreset* preset, cGroupParam::EmSetInfo* pesi);
    uControlEnemy* createControl(u32 EmId, nLayout::stUniqueID* pUniqueId, cSetInfoEnemy* pSetInfoEm, cContextInstance* pContext);
    void addOmControlToDrop(cGroupParam* pGP);
protected:
    virtual bool canSetUnit() const;  // vtable slot 14
private:
    virtual void moveSetUnit();  // vtable slot 17
    void moveSetUnitSever();
    void moveSetUnitSubGroupSever(u32 flagNo, u32 idx);
public:
    static MyDTI DTI;
};
