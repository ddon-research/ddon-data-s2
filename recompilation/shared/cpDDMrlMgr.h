#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "MtString.h"
#include "cDDMaterialCtrl.h"
#include "cpComponent.h"
#include "rOutlineParamList.h"
#include "sEffectExt.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtString;
class MtVector4;
class cDDMaterialCtrl;
class cOutlineCtrl;
class cpEquip;
class uDDOModel;

// Declarations
class cpDDMrlMgr;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cpDDMrlMgr : public cpComponent
{
public:
    enum MATERIAL_OWNER_KIND
    {
        MOK_DDOMODEL = 1,
        MOK_PLAYER = 2,
        MOK_ENEMY = 4,
        MOK_HUMANENEMY = 8,
        MOK_ACTORMODEL = 16,
        MOK_HUMAN = 32,
        MOK_WEAPON = 64,
        MOK_OTHER = -2147483648,
    };
    enum MATERIAL_ANIM_KIND_NUM
    {
        ANIM_NUM_DEFAULT = 0,
        ANIM_NUM_ANGRY = 1,
        ANIM_NUM_DEATH = 2,
        ANIM_NUM_SPELL_CAST = 3,
        ANIM_NUM_WEAK_POINT01 = 4,
        ANIM_NUM_WEAK_POINT02 = 5,
        ANIM_NUM_WEAK_POINT03 = 6,
        ANIM_NUM_LANTERN_ON = 7,
        ANIM_NUM_PARTS_BREAK1 = 8,
        ANIM_NUM_PARTS_BREAK2 = 9,
        ANIM_NUM_PARTS_BREAK3 = 10,
        ANIM_NUM_PARTS_BREAK4 = 11,
        ANIM_NUM_PARTS_BREAK5 = 12,
        ANIM_NUM_PARTS_BREAK6 = 13,
        ANIM_NUM_PARTS_BREAK7 = 14,
        ANIM_NUM_PARTS_BREAK8 = 15,
        ANIM_NUM_PARTS_BREAK9 = 16,
        ANIM_NUM_LEVEL0 = 17,
        ANIM_NUM_LEVEL1 = 18,
        ANIM_NUM_LEVEL2 = 19,
        ANIM_NUM_LEVEL3 = 20,
        ANIM_NUM_LEVEL4 = 21,
        ANIM_NUM_CHARGE = 22,
        ANIM_NUM_MAX = 23,
        ANIM_NUM_LIMIT = 31,
    };
public:
    class MyDTI;
    class cMaterialAnimationRequestData;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cMaterialAnimationRequestData : public MtObject
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
        cMaterialAnimationRequestData();
        virtual ~cMaterialAnimationRequestData();
        void init();
        void setName(MT_CTSTR set);
        void setMaterialId(u32 set);
        void setIsMaintenance(bool set);
        void setSupFrame(f32 set);
        void setReqFrame(f32);
        MT_CTSTR getName();
        u32 getMaterialId();
        bool getIsMaintenance();
        f32 getSupFrame();
        f32 getReqFrame();
        bool isSameData(MT_CTSTR name, u32 MaterialId);
    private:
        MtString mName;  // offset: 0x8
        u32 mMaterialId;  // offset: 0x10
        bool mIsMaintenance;  // offset: 0x14
        f32 mSupFrame;  // offset: 0x18
        f32 mReqFrame;  // offset: 0x1c
    public:
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
    cpDDMrlMgr();
    virtual ~cpDDMrlMgr();
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void updatePtr();  // vtable slot 9
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    void setupDDMrlCtrl();
    cDDMaterialCtrl* getDDMrlCtrl(u32 set);
    void setDDMrlCtrlEquip(cDDMaterialCtrl* set);
    void releaseDDMrlCtrlEquip(cDDMaterialCtrl* set);
    void setCommonStateMrlCtrl();
    void setDDShadingState();
    void getTargetModelArray(MtTypedArray<uDDOModel>* pTargetArray, bool isAddThis);
    void getTargetModelArray(MtTypedArray<uDDOModel>* pTargetArray, cpEquip* pEquip);
    void requestOutline(sEffectExt::OUTLINE type);
    void requestOutlineMode(u32 mode);
    void setOutlineColor(MtVector4& endOCol, MtVector4& endICol);
    void setOutlineParam(u32 mode, u32 blendT, u32 colT, MtVector4& colO, MtVector4& colI, f32 balanceOffset, f32 balanceScale, f32 balance);
    f32 getNowOutlineLoopFrame();
    void setOutlineTypeSdl(u32 type);
    u32 getOutlineTypeSdl();
    void requestDeadShader();
    bool isEndDeadShader();
    void requestAilmentShader(u32 type, u32 prio);
    void requestDefaultShader(u32 prio);
    void requestFireShader(u32);
    void requestFreezeShader(u32);
    void requestGeneralShader(u32);
    void requestWetOilShader(u32);
    void requestStoneShader(u32);
    void requestGoldShader(u32 prio);
    void requestErosionShader(u32);
    void requestMaterialMode(u32 set);
    void resetMaterialMode();
    void requestBlackModel();
    void requestMaterialDiffuseColor(const MtVector4& color);
    void requestBloodStainPhase(u32 phase);
    void requestHakuryuStonePhase(u32 phase);
    void requestFireDamagePhase(u32 phase);
    void requestEnchantMaterialAnimation(u32 elemType);
    void resetEnchantMaterialAnimation();
    void requestAlchemyShellLevel(u32 level);
    void setDefaultMaterialMode(u32 set);
    void setStonePassageFrame(f32 set);
    void setStonePassageFrame(cDDMaterialCtrl* pMaterialCtrl, f32 set);
    void setGoldPassageFrame(cDDMaterialCtrl* pMaterialCtrl, f32 set);
    void setGoldPassageFrame(f32 set);
    void setErosionLevel(cDDMaterialCtrl* pMaterialCtrl, s32 setLevel);
    void setErosionLevel(s32 setLevel);
    void setToDefaultFrame(u32 set);
    void requestElementEmMode(u32 Element);
    void updateMaterialAnimation();
    bool isExistAnimation(MT_CTSTR name);
    bool isActionAnimation(MT_CTSTR name, u32 MaterialId);
    bool isActionSomethingAnimation();
    void requestMaterialAnimation(MT_CTSTR name, u32 MaterialId, MtTypedArray<cMaterialAnimationRequestData>* pTgtArray);
    void requestMaterialAnimation(u32 num, u32 MaterialId);
    void requestMaterialAnimationDefault();
    void requestMaterialAnimationAngry();
    void requestMaterialAnimationDead();
    void requestMaterialAnimationSpellCast();
    void requestMaterialAnimationWeakPoint(u32 num);
    void requestMaterialAnimationWeakPoint1();
    void requestMaterialAnimationWeakPoint2();
    void requestMaterialAnimationWeakPoint3();
    void requestMaterialAnimationLanternOn();
    void requestMaterialAnimationPartsbreak1();
    void requestMaterialAnimationPartsbreak2();
    void requestMaterialAnimationPartsbreak3();
    void requestMaterialAnimationPartsbreak4();
    void requestMaterialAnimationPartsbreak5();
    void requestMaterialAnimationPartsbreak(u32 Id);
    void requestMaterialAnimationLevel(u32 PartsId, u32 LevelId);
    void requestMaterialAnimationCharge(u32);
    bool isActionDeadMaterialAnimation();
    bool isExistSameDataFromOld(MT_CTSTR name, u32 MaterialId);
    void initDDMaterialCtrl();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void setDDMrlCtrl(cDDMaterialCtrl* ptr, u32 set);
    u32 getDDMrlCtrlNum();
    void setDDMrlCtrlNum(u32 set);
public:
    bool mbDirty;  // offset: 0x50
    bool mbDirtyAnim;  // offset: 0x51
    bool mbDirtyBaseShaderMode;  // offset: 0x52
    bool mbDirtyShaderMode;  // offset: 0x53
    bool mbDirtyMrlMode;  // offset: 0x54
    bool mbDirtyOutline;  // offset: 0x55
private:
    cDDMaterialCtrl mpDDMrlCtrl;  // offset: 0x60
    cOutlineCtrl mOutlineCtrl;  // offset: 0x1310
    cDDMaterialCtrl* mpDDMrlCtrlEquip[16];  // offset: 0x1350
    u32 mShaderMode;  // offset: 0x13d0
    u32 mShaderModePriority;  // offset: 0x13d4
    u32 mOwnerModelKind;  // offset: 0x13d8
    u32 mSdlOutlineRequestNo;  // offset: 0x13dc
    MtTypedArray<cMaterialAnimationRequestData> mNowMARD;  // offset: 0x13e0
    MtTypedArray<cMaterialAnimationRequestData> mOldMARD;  // offset: 0x1400
public:
    static MyDTI DTI;
    static const MT_CTSTR ANIM_NAME_TBL[23];
    static const f32 ANIM_DEF_SUP_FRAME;
};
