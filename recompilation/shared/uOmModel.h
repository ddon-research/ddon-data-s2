#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "cDDMaterialCtrl.h"
#include "cOmComponent.h"
#include "nDDOModel.h"
#include "sCollision.h"
#include "uDDOModel.h"
#include "uModel.h"

// Forward declarations
class ItemGetInfo;
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
class cDDMaterialCtrl;
class cDamageSeInfo;
class cDraw;
class cGatherItemList;
class cHitInfo;
class cHitInfoAfter;
class cOmComponent;
class cOmControl;
class cOmParam;
class cpOmLadder;
class uEffect;
class uPlayer;

// Declarations
class uOmModel;
class uOmShell;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using u32 = unsigned int;
namespace nCollision { using SBC_HANDLE = u32; }
using s32 = int;
using size_t = _Sizet;

class uOmModel : public uDDOModel
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
    uOmModel();
    virtual ~uOmModel();
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void moveAfter();  // vtable slot 10
    virtual void kill();  // vtable slot 16
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    virtual void updatePtr();  // vtable slot 17
    u32 getUID() const;
    void setUID(u32 uid);
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
    virtual u32 getLODLevel(s32 dist);  // vtable slot 35
    cOmControl* getOmCtrl() const;
    const cOmParam* getOmParam() const;
    cpOmLadder* getOmLadder();
    void setOmLadder(cpOmLadder* ptr);
    void setActiveScrSbc(bool f);
    void setActiveEfcSbc(bool f);
    sCollision::SBC_HANDLE getSBCHandle(u32 type, u32 index);
    virtual void callbackDamage(cHitInfo* pHitLocalInfo);  // vtable slot 88
    virtual void callbackAttack(cHitInfo* pHitInfo);  // vtable slot 83
    virtual void callbackCheck(cHitInfo* pHitInfo);  // vtable slot 123
    virtual void callbackChecked(cHitInfo* pHitInfo);  // vtable slot 124
    virtual void makeHitSeInfo_Attack(cDamageSeInfo* pSeInfo);  // vtable slot 163
    virtual void makeOcdAttackInfo(cHitInfoAfter* pHitInfo);  // vtable slot 156
    virtual void makeOcdAttackInfoShl(cHitInfoAfter* pHitInfo);  // vtable slot 155
    void makeOcdAttackInfoCom(cHitInfoAfter* pHitInfo);
    void setObjCollisionLayerOn(u32 no, bool on);
    virtual void notifyDeleteShell(s32 work);  // vtable slot 68
    virtual void updateEfcHandle();  // vtable slot 58
    virtual void setTouch(uDDOModel* pUnit, bool isTouchSave);  // vtable slot 166
    virtual void requestReleaseTouch(uDDOModel* pRelease, nDDOModel::TOUCH_RELEASE_TYPE type);  // vtable slot 167
    uDDOModel* getCatchUnit();
    void moveCatch();
    cGatherItemList* getGatherItemList();
    u32 getItemGetInfoNum();
    ItemGetInfo* getItemGetInfo(u32 idx);
    bool isGatherEmpty();
    bool isGather();
    bool isAQCDraw();
    virtual u32 getHitLightToModel();  // vtable slot 36
    void shotShl();
    void shotShl(const MtVector3& pos);
    bool isSingleBed();
    void moveHead();
public:
    cOmComponent mOmComp;  // offset: 0x2470
    cDDMaterialCtrl mMatCtrl;  // offset: 0x2550
    cpOmLadder* mpCpOmLadder;  // offset: 0x3800
    MtVector3 mHitPos;  // offset: 0x3810
    uPlayer* mpuAtkPL;  // offset: 0x3820
    f32 mShlTimer;  // offset: 0x3828
    u32 mRnoHead;  // offset: 0x382c
    static MyDTI DTI;
};

class uOmShell : public uModel
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
    uOmShell();
    virtual ~uOmShell();
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void kill();  // vtable slot 16
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void updatePtr();  // vtable slot 17
    virtual u32 getHitLightToModel();  // vtable slot 36
public:
    f32 mStartRoll;  // offset: 0x1f60
    f32 mAxisZRndScale;  // offset: 0x1f64
    f32 mDelayTimer;  // offset: 0x1f68
    f32 mZValue;  // offset: 0x1f6c
    f32 mStep;  // offset: 0x1f70
    MtVector3 mStartPos;  // offset: 0x1f80
    MtVector3 mEndPos;  // offset: 0x1f90
    uEffect* mpuFx;  // offset: 0x1fa0
    cOmControl* mpCtrl;  // offset: 0x1fa8
    static MyDTI DTI;
};
