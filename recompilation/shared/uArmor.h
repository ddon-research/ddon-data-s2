#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "uDDOModel.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector4;
class cDraw;
class cWeaponResTable;
class rDDOModelMontage;
class rDeformWeightMap;
class rModel;
class uModel;
class uSimSoftBody;

// Declarations
class uArmor;

// Type aliases from DWARF
using u32 = unsigned int;
using ARC_SEARCHID = u32;
using ARC_TAGID = u32;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using s8 = signed char;
using size_t = _Sizet;
using u8 = unsigned char;

class uArmor : public uDDOModel
{
public:
    enum
    {
        OTHER_INFO_NOT_PLAY_EXPRESSION = 0,
        OTHER_INFO_SHAKE_BUST = 1,
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
    uArmor();
    virtual ~uArmor();
    virtual void setup();  // vtable slot 6
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void move();  // vtable slot 9
    virtual void moveAfter();  // vtable slot 10
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    virtual void createComponent();  // vtable slot 43
    void callbackUpdateMatrix();
    static uArmor* createArmorModel(cWeaponResTable* pWepResData, uModel* pParent, u8 partsPatern, s8 colorPatern);
    static uArmor* createArmorModel(uModel* pParent, rModel* pModelRes, rDeformWeightMap* pDwm);
    static uArmor* createArmorModelHumanEnemy(cWeaponResTable* pWepResData, uModel* pParent);
    void setParts();
    void setAlbedoColor(u32 mat_idx, const MtVector4& color);
    void setSpecularColor(u32 mat_idx, const MtVector4& color);
    void setArchiveInfo(cWeaponResTable* pData);
    cWeaponResTable* getArchiveInfo();
    uModel* getOwner();
    rModel* getModelRes();
    u8 getModelType();
    u8 getOtherInfo();
    u32 getHideInfo();
    rDeformWeightMap* getDwmRes();
protected:
    void setSoftBody();
    void setSoftBody(ARC_TAGID ArcTagId, s32 SearchId, u32 Mode);
    void setParts(u8 partsPatern);
    void setParts(ARC_TAGID ArcTagId, ARC_SEARCHID SearchId, u8 partsPatern);
    void setColor(s8 colorPatern);
    void setColor(ARC_TAGID ArcTagId, ARC_SEARCHID SearchId, s8 colorPatern);
    void setHumanEnemyMontage();
public:
    u8 mPartsPatern;  // offset: 0x246a
    s8 mColorPatern;  // offset: 0x246b
    u8 mModelType;  // offset: 0x246c
    u8 mOtherInfo;  // offset: 0x246d
    u32 mHideInfo;  // offset: 0x2470
    rDDOModelMontage* mpMontage;  // offset: 0x2478
    u32 mMontageType;  // offset: 0x2480
    bool mChangeColor;  // offset: 0x2484
    MtVector4 mColor;  // offset: 0x2490
    uSimSoftBody* mpSimSoftBody;  // offset: 0x24a0
protected:
    uModel* mpOwner;  // offset: 0x24a8
    cWeaponResTable* mpWepResData;  // offset: 0x24b0
    rModel* mpModelRes;  // offset: 0x24b8
    rDeformWeightMap* mpDwmRes;  // offset: 0x24c0
    bool mUseHumanEnemyMontage;  // offset: 0x24c8
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline cWeaponResTable* uArmor::getArchiveInfo() {
    return this->mpWepResData;
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline uModel* uArmor::getOwner() {
    return this->mpOwner;
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline rModel* uArmor::getModelRes() {
    return this->mpModelRes;
}
