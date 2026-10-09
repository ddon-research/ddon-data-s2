#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "cpJobBase.h"
#include "nDDOGame.h"
#include "nHuman.h"
#include "rItemList.h"
#include "uDDOModel.h"
#include "uShlAlchemy.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector3;
class cContextInterface;
class cEfcHandle;
class cGeneralPoint;
class cHitInfo;
class cHitInfoAfter;
class uBaseModel;
class uCharacter;
class uDDOModel;
class uShlAlchemy;
class uShlAlchemyCS03;
class uShlBase;

// Declarations
class cpJob09;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cpJob09 : public cpJobBase
{
public:
    enum JOB09_SHL_TYPE
    {
        J09ST_UNDEFINED = 0,
        J09ST_CS_04 = 1,
        J09ST_CS_05 = 2,
        J09ST_CS_06_LAND = 3,
        J09ST_CS_06_AIR = 4,
        J09ST_CS_07 = 5,
        J09ST_CS_10 = 6,
    };
    enum GUI_STATE
    {
        GS_NONE = 0,
        GS_MEDAL_CHANGE = 1,
        GS_ELEMENT_CHANGE = 2,
    };
    enum ELEMENT_BUTTON
    {
        EB_ATTACK1 = 0,
        EB_ATTACK2 = 1,
        EB_ATTACK3 = 2,
        EB_ATTACK4 = 3,
    };
    enum SPAlCHEMY_INPUT_TYPE
    {
        SPAlCHEMY_INPUT_TYPE_ATTACK1 = 0,
        SPAlCHEMY_INPUT_TYPE_ATTACK2 = 1,
    };
    enum SP_ALCHEMY_STAT
    {
        STAT_LAND = 0,
        STAT_AIR = 1,
        STAT_CLIMB = 2,
    };
    enum SPALCHEMY_INPUT_STATE
    {
        SPALCHEMY_LOOP_STATE_NO_INPUT = 0,
        SPALCHEMY_LOOP_STATE_INPUT_JUST = 1,
        SPALCHEMY_LOOP_STATE_INPUT_MISS = 2,
    };
    enum
    {
        JOB09_TUTORIAL_CHECK_NONE = 0,
        JOB09_TUTORIAL_CHECK_01 = 1,
        JOB09_TUTORIAL_CHECK_02 = 2,
        JOB09_TUTORIAL_CHECK_03 = 3,
    };
    enum
    {
        SEQ_ALCHEMY_CORE = 10,
        SEQ_ALCHEMY_FINISH = 11,
    };
public:
    class MyDTI;
    class cAlchemyEvaluationData;
    class cJob09ShlInfo;
    struct stMedalItemInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cAlchemyEvaluationData : public MtObject
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
        cAlchemyEvaluationData();
        void resetEvaluationDate();
    public:
        f32 mShlCount;  // offset: 0x8
        f32 mEvaluation;  // offset: 0xc
        uCharacter* mpTarget;  // offset: 0x10
        static MyDTI DTI;
    };
public:
    class cJob09ShlInfo : public MtObject
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
        cJob09ShlInfo();
        // Address: 0x01a5ba80 - 0x01a5ba81 (1 bytes)
        virtual ~cJob09ShlInfo() {}
    public:
        uShlBase* mpJob09Shl;  // offset: 0x8
        cpJob09::JOB09_SHL_TYPE mJob09ShlType;  // offset: 0x10
        static MyDTI DTI;
    };
public:
    struct stMedalItemInfo
    {
    public:
        rItemList::rItemParam* param;  // offset: 0x0
        u32 num;  // offset: 0x8
        u32 disp_num;  // offset: 0xc
        u32 joutai_icon_frame;  // offset: 0x10
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
    cpJob09();
    virtual ~cpJob09();
    virtual void setup();  // vtable slot 6
    virtual void before();  // vtable slot 15
    virtual void update();  // vtable slot 16
    virtual void after();  // vtable slot 18
    virtual void updatePtr();  // vtable slot 9
    virtual void updateEfcHandle();  // vtable slot 10
    virtual void kill();  // vtable slot 8
    void compMoveAfter();
    virtual void setupJobData();  // vtable slot 21
    virtual void callbackAttack(cHitInfo* pHitInfo);  // vtable slot 30
    virtual void callbackCreateShl(uShlBase* pShl);  // vtable slot 52
    virtual void makeOcdAttackInfoShl(cHitInfoAfter* pHitInfo);  // vtable slot 46
    virtual void makeDamageAttackInfo(cHitInfoAfter* pHitInfo);  // vtable slot 43
    virtual void makeShlDamageAttackInfo(cHitInfoAfter* pHitInfo);  // vtable slot 44
    void startSpAlchemy(SPAlCHEMY_INPUT_TYPE type);
    void endSpAlchemy();
    void resetSpAlchemyLevel();
    void resetSpAlchemyInputStat();
    void spAlchemyInputJust();
    void spAlchemyInputMiss();
    void checkJustInput();
    u32 getSpAlchemyJustCount() const;
    void setSpAlchemyJustCount(const u32 lv);
    u32 getSpAlchemyStat() const;
    void setSpAlchemyCurrentLevel(const u32 lv);
    u32 getSpAlchemyCurrentLevel() const;
    u32 getSpAlchemyEndLevel() const;
    bool continueSpAlchemy();
    bool stopSpAlchemy();
    bool finishSpAlchemy();
    void checkInputSPStartAction();
    void getSpAlchemyCorePos(s32& joint, MtVector3& pos, const SP_ALCHEMY_STAT stat);
    void setSpAlchemyMinEndLv();
    u32 getMedalIndex() const;
    void setMedalIndex(const u32);
    u32 getMedalItemId() const;
    void setMedalItemId(const u32 item_id);
    u32 getCurrentMedalId(const u32 index) const;
    void medalAlchem();
    void requestChangeMedal(s32 index);
    bool canEndureInClimb();
    bool canMedalChange(bool check_anime_end) const;
private:
    void updateMedalType();
    void changeMedalType(const s32 index);
public:
    void updateCS03Shl();
    void setContextCS03ValueMax(bool flg);
    bool isAlchemyShlMaxValue();
    void callbackCreateShlCS03(uShlAlchemyCS03* pShl);
    void initElementChange();
    bool changeElement();
    void resetTmpElementType();
    nDDOGame::ELEMENT_TYPE getTmpElementType() const;
    nHuman::HM_SKILL_LV getElementLv() const;
    nDDOGame::ELEMENT_TYPE getElementType();
    bool getElemDecide() const;
    void setElemDecide(bool flg);
    void setTmpElementType(nDDOGame::ELEMENT_TYPE type);
private:
    void setElementType(f32 angle);
public:
    bool dispMedalHud(bool start_check) const;
    bool getMedalEquipItemInfo(stMedalItemInfo& info, u32 medal_index) const;
    u32 getGUIJotaiIconFrame(u32 medal_index);
    void requestGUIMedalChange();
    bool isGUIMedalChange() const;
    void clearGUIMedalChange();
    void requestGUIElementChange();
    void clearGUIElementChange();
    void finishMedalChangeAnime();
    bool isGUIMedalChangeAnime() const;
    GUI_STATE getGUIDispState() const;
    ELEMENT_BUTTON getElementButton() const;
private:
    void requestAlchemyEffect(s32 IndexNo, s32 ElementNo);
    void requestAlchemyFinishEffect(s32 IndexNo, s32 ElementNo);
    void updateAlchemyCoreEfcHandle();
public:
    void setAlchemyCoreEffectData(s32 IndexNo, s32 ElementNo, u32 seq_no);
    void setAlchemyCoreEffectFinishData(s32 finish_index_no, s32 finish_element_no, u32 finish_seq, bool old_set);
    void setAlchemyCoreEffectPosCtrlParam(s32 joint, MtVector3& ofset, bool old_set);
    void resetEffectCtrlData();
    void finishAlchemyCoreEffec(bool call_finish);
    void setAlchemyCoreSe(s32 index, s32 finish_index, s32 stop_index, bool old_set);
    void startGoldBody();
    void endGoldBody();
    bool checkIsEndGoldBody(bool pad_check);
    virtual void callbackDamageAfter_apply(cHitInfoAfter* pHitInfo);  // vtable slot 41
    bool checkCndEnableGoldBody(bool no_check_seq);
    bool isGoldBody() const;
private:
    void updateGoldBody();
    void callBackDamageGoldBody(cHitInfoAfter* pHitInfo);
public:
    void addShl(uShlBase* pShl, JOB09_SHL_TYPE type);
    void getJob09ShlArray(const JOB09_SHL_TYPE type, MtTypedArray<uShlBase>* pArray);
private:
    void updateAlchemyEvaluationValue();
    void updateAlchemyEvaluationSubWriteData(MtTypedArray<cAlchemyEvaluationData>& list, const uShlAlchemy& shl);
public:
    void resetBurstInfo();
    void requestStateBurst(uShlAlchemy* pShl, const MtVector3& hit_pos);
    bool isExistShlBurst();
    void clearBurstShl();
    void requestStickInEffect(bool is_climb);
    void finishStickInEffect(bool set_finish_effect, bool is_climb);
    uShlAlchemy* getBurstShl() const;
    uShlAlchemy* getPawnTargetBurstShl(const cGeneralPoint* pTarget) const;
    uShlAlchemy* getPawnTargetBurstShl(const uBaseModel* pTarget) const;
    void requestStickInEffectSe(u32 se_no);
private:
    void makeOcdAttackInfoShlCS13(cHitInfoAfter* pHitInfo);
    void makeDamageAttackInfoCS13(cHitInfoAfter* pHitInfo);
public:
    bool canGraze(cHitInfoAfter* pHitInfo) const;
protected:
    void updateGraze();
    void updateGrazeEntry();
    void updateGrazeTimer();
    bool isGrazeEntry() const;
    bool isGraze() const;
    f32 getNextGrazeTimer() const;
    void startGraze();
    void callBackDamageGraze(cHitInfoAfter* pHitInfo);
public:
    nHuman::HM_SKILL_LV getFrightBoardLevel() const;
    bool checkCndEnableDelayCombo() const;
    bool checkCndEnableSecondJump() const;
    bool checkCndEnableAirAlchemyRelease() const;
    bool checkCndEnableAirCS06() const;
    void addSecondJumpCount();
    void addAirAlchemyReleaseCount();
    void addAirCS06();
    bool checkCndEnableAirCS10() const;
    void addCS10Count();
    void clearCS03StoredTarget();
    u32 getCS03StoredTargetNum();
    uDDOModel* getCS03StoredTarget(u32 num);
    void callbackAttackSubShellCommon(cHitInfo* pHitInfo);
    void flgOnCurrentCreateCSShl();
    bool isFlgCurrentCreateCSShl() const;
    cEfcHandle* requestAreaEffect(u32 time, uDDOModel* pRequestUnit);
    virtual void callbackCSChange();  // vtable slot 54
    virtual void callbackWarpInStage();  // vtable slot 55
    bool isSpAlchemyAction(SP_ALCHEMY_STAT type) const;
    bool isCustom09Action() const;
private:
    void storeCS03Target(const cHitInfo* pHitInfo);
    void addAlchemyValue(cHitInfo* pHitInfo);
    void writeContext(cContextInterface& Con);
    void readContext(cContextInterface& Con);
    void addAlchemyShl(uShlAlchemy* pShl, bool add_cs03);
    bool isNormalAlchemAction(bool check_delay) const;
    s32 getShlAlchemyStickModelProveHateLevel(uDDOModel& target) const;
    bool isEquipJobItem() const;
    void changeCs03ToNml(uShlAlchemyCS03& shl);
    uShlAlchemy* searchNearAlchemyShl(u32 uid, const MtVector3& pos, const f32 dis);
    uShlAlchemy* searchNearAlchemyShl(const MtVector3& pos, const f32 dis);
    uShlAlchemy* searchNearAlchemyShlEx(cHitInfo* pHitInfo, u32 uid, const MtVector3& pos, const f32 dis_add, const f32 dis_create);
    uShlAlchemy* searchNearAlchemyShlExCore(u32 uid, const MtVector3& pos, const MtVector3& pos2, const bool usePos2, const f32 dis_add, const f32 dis_create);
    f32 getSearchDistanceSq(const MtVector3& base_pos, const MtVector3& pos1, const MtVector3& pos2, const bool usePos2);
public:
    void entryExplosionShl();
    void entryExplosionShlCS09();
    bool checkShlAlchemyValue(u32 value) const;
private:
    cEfcHandle* mpEfcHandle;  // offset: 0x58
    u32 mSequenceNo;  // offset: 0x60
    s32 mAlchemyCoreIndexNo;  // offset: 0x64
    s32 mAlchemyCoreElementNo;  // offset: 0x68
    u32 mFinishSequenceNo;  // offset: 0x6c
    f32 mFinishTimer;  // offset: 0x70
    s32 mFinishIndexNo;  // offset: 0x74
    s32 mFinishElementNo;  // offset: 0x78
    s32 mConstJoint;  // offset: 0x7c
    MtVector3 mAlchemyCoreOfset;  // offset: 0x80
    s32 mFinishIndexNoOld;  // offset: 0x90
    s32 mFinishElementNoOld;  // offset: 0x94
    s32 mConstJointOld;  // offset: 0x98
    MtVector3 mAlchemyCoreOfsetOld;  // offset: 0xa0
    s32 mAlchemyCoreLoopSe;  // offset: 0xb0
    s32 mAlchemyCoreStopSe;  // offset: 0xb4
    s32 mAlchemyCoreStopSeOld;  // offset: 0xb8
    s32 mAlchemyCoreFinishSe;  // offset: 0xbc
    s32 mAlchemyCoreFinishSeOld;  // offset: 0xc0
    bool mIsGoldBody;  // offset: 0xc4
    f32 mGoldBodyStUseRate;  // offset: 0xc8
    f32 mGoldShaderTime;  // offset: 0xcc
    MtTypedArray<cAlchemyEvaluationData> mArrAlchemyEvaluationData;  // offset: 0xd0
    f32 mBurstShlAlchemyValue;  // offset: 0xf0
    cEfcHandle* mpEfcHandleCS09;  // offset: 0xf8
protected:
    f32 mGrazeTimer;  // offset: 0x100
    f32 mGrazeEntryTimer;  // offset: 0x104
    u32 mGrazeCount;  // offset: 0x108
    bool mIsGrazeEntry;  // offset: 0x10c
    bool mIsGraze;  // offset: 0x10d
private:
    MtTypedArray<uShlAlchemy> mShlArray;  // offset: 0x110
    MtTypedArray<uShlAlchemyCS03> mCS03ShlArray;  // offset: 0x130
    MtTypedArray<uShlAlchemy> mExplosionShlArray;  // offset: 0x150
    MtTypedArray<uDDOModel> mCS03StoredTarget;  // offset: 0x170
    MtTypedArray<cJob09ShlInfo> mJob09ShlInfo;  // offset: 0x190
    bool mIsMoveExplosion;  // offset: 0x1b0
    f32 mExplosionInterval;  // offset: 0x1b4
    u32 mSpAlchemyJustCount;  // offset: 0x1b8
    u32 mSpAlchemyCurrentLevel;  // offset: 0x1bc
    u32 mSpAlchemyEndLevel;  // offset: 0x1c0
    u32 mSpAlchemyInputStat;  // offset: 0x1c4
    bool mIsSpAlchmy;  // offset: 0x1c8
    u32 mSpAlchemyInputType;  // offset: 0x1cc
    u32 mCurrentMedalIndex;  // offset: 0x1d0
    u32 mAlchemyReleaseMedalId;  // offset: 0x1d4
    nDDOGame::ELEMENT_TYPE mEnchantType;  // offset: 0x1d8
    nDDOGame::ELEMENT_TYPE mEnchantTypeOld;  // offset: 0x1dc
    nDDOGame::ELEMENT_TYPE mTmpEnchantType;  // offset: 0x1e0
    f32 mElemChangeInterval;  // offset: 0x1e4
    bool mElemDecide;  // offset: 0x1e8
    GUI_STATE mGUIDispState;  // offset: 0x1ec
    ELEMENT_BUTTON mElementButton;  // offset: 0x1f0
    bool mFlgMedalSwitchAnime;  // offset: 0x1f4
    f32 mMedalHudDispTimeForPad;  // offset: 0x1f8
    f32 mMedalChangeInvalidTimer;  // offset: 0x1fc
    bool mFlgCurrentCreateCSShl;  // offset: 0x200
    u32 mCountAirAlchemyRelease;  // offset: 0x204
    u32 mCountSecondJump;  // offset: 0x208
    u32 mCountAirCS06;  // offset: 0x20c
    u32 mCountCS10;  // offset: 0x210
    u32 mTutorialCheckType;  // offset: 0x214
    uDDOModel* mpTutorialTargetEnemy;  // offset: 0x218
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline bool cpJob09::isGrazeEntry() const {
    return this->mIsGrazeEntry;
}

// Inline, no code of its own: checked where it is inlined.
inline cpJob09::cAlchemyEvaluationData::cAlchemyEvaluationData() {
    this->mpTarget = static_cast<uCharacter*>(nullptr);
    this->mShlCount = 0.0f;
    this->mEvaluation = 0.0f;
}

// Inline, no code of its own: checked where it is inlined.
inline cpJob09::cJob09ShlInfo::cJob09ShlInfo() {
    this->mpJob09Shl = static_cast<uShlBase*>(nullptr);
    this->mJob09ShlType = static_cast<cpJob09::JOB09_SHL_TYPE>(0);
}
