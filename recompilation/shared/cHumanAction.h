#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "cAction.h"
#include "cpInput.h"
#include "nHuman.h"
#include "nShlBase.h"
#include "uModel.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector3;
class cActParam;
class uDDOModel;
class uHuman;

// Declarations
class cHumanActBase;
class cHumanActSetNpcMotMyRoom;
class cHumanActSetNpcMotion;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

namespace nHumanActUtility {

    u32 getSequenceCountNum(uHuman& human, u32 bit, MOT_TYPE blend, u32 seqPage);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/cHumanAction.cpp:166
    f32 getAttackAngleY(uHuman& human, f32 range);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/cHumanAction.cpp:205
    f32 getAttackAngleY2(uHuman& human, f32 range);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/cHumanAction.cpp:234
    f32 getAttackAngleY3(uHuman& human, f32 range);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/cHumanAction.cpp:262
    f32 getAttackAngleY4(uHuman& human, f32 range);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/cHumanAction.cpp:300
    bool reqSetSynchronizeEffect(uHuman* pHuman, u32 epvType, u64 syncFlag, u32 endType, s32 indexNo, s32 elementNo, s32 JointNo, const MtVector3& offset);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/cHumanAction.cpp:357
    bool reqSetSynchronizeEffectToTarget(uHuman* pHuman, uDDOModel* pTarget, u32 epvType, u64 syncFlag, u32 endType, s32 indexNo, s32 elementNo, s32 JointNo, const MtVector3& offset);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/cHumanAction.cpp:438
    void reqOnSyncFlag(uHuman* pHuman, u64 syncFlag);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/cHumanAction.cpp:506
    void requestOnTutorialFlg(s32 questTarget);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/cHumanAction.cpp:539
    void setInvincibleTime(uHuman& human, f32 time, bool isApplyAbility);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/cHumanAction.cpp:550
    cpInput::unBtnInfo getSpecifiedCustomBtnInfo(nHuman::CUSTOM_SKILL_ENUM skillID, uHuman* pHuman);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/cHumanAction.cpp:619
    cpInput::unBtnInfo getRendaCustomBtnInfo(nHuman::CUSTOM_SKILL_ENUM skillID, uHuman* pHuman);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/cHumanAction.cpp:711
    bool searchMyShlFromShlID(uDDOModel& mod, nShlBase::SHL_ID id);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/cHumanAction.cpp:884
    bool cheakSequence(uHuman& human, u32 bit, u32 seqPage, MOT_TYPE s);
    bool judgeDirLorR(const MtVector3& v1, const MtVector3& v2);
    f32 getSequenceCountFrame(uHuman& human, u32 seqCnt, u32 bit, MOT_TYPE blend, u32 seqPage);
    cpInput::unBtnInfo getAllocatedBtnInfo(nHuman::CUSTOM_SKILL_ENUM skillID, uHuman* pHuman);
    f32 getSequenceCountFrame(u32 seqCnt, u32 bit, MOT_TYPE blend, u32 seqPage, uHuman* pHuman);
    void setCstmResource(nHuman::CUSTOM_SKILL_ENUM skillID, uHuman* pHuman);
    void resetCstmResource(uHuman* pHuman);
    void staminaRequestExternalUpdate(u32 bank, s32 index, bool isDeltaTime, u32 skillLv, uHuman* pHuman);
    u32 getActionNo(uDDOModel& mod);

}  // namespace nHumanActUtility

class cHumanActBase : public cAction
{
public:
    enum
    {
        UPDATE_VELOCITY_NONE = 0,
        UPDATE_VELOCITY_UPDATE = 1,
        UPDATE_VELOCITY_NO_SPD = 2,
        UPDATE_QUAT_CAM_DIR = 4,
        UPDATE_VELOCITY_CAM_DIR = 8,
        UPDATE_VELOCITY_NUM = 9,
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
    cHumanActBase();
    virtual void init();  // vtable slot 7
    virtual void move();  // vtable slot 8
    virtual void final();  // vtable slot 9
    nHuman::HM_SKILL_LV getSkillLevel() const;
    void setSkillLevel(nHuman::HM_SKILL_LV lv);
protected:
    bool updateFinalQuat();
    bool updateFinalQuatAndVelocity(f32 velocityRate, u32 type);
    void changeJobCommonMotion(u32& motNo);
    void getCustomSkillIDAndLevelFromActNo(u32 ActionNo);
    void getCustomSkillIDAndLevelFromActNo_PreInit(u32 ActionNo);
    bool checkActParamBit(nHuman::HM_ACTPARAM_BIT bit);
    bool isCustomSKillBuildUp() const;
    void actionWorkFlag_On();
    void actionWorkFlag_Off();
    bool isActionWorkFlag_On() const;
    void setEndActNoSendOcdBadStatus();
private:
    void clearActionWorkFlag();
public:
    nHuman::CUSTOM_SKILL_ENUM getActCustomSkillId() const;
protected:
    uHuman* mpHuman;  // offset: 0x28
    const cActParam* mpParam;  // offset: 0x30
    nHuman::HM_SKILL_LV mSkillLv;  // offset: 0x38
    nHuman::CUSTOM_SKILL_ENUM mCustomSkillID;  // offset: 0x3c
    bool mIsBeforeActDrawingSword;  // offset: 0x40
public:
    static MyDTI DTI;
};

class cHumanActSetNpcMotMyRoom : public cHumanActBase
{
public:
    enum
    {
        SEQ_DISP_ITEM = 18,
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
    u32 getMotionNo() const;
    u32 getNoHokan() const;
    u32 getIndex() const;
    u32 getEmotion() const;
    s32 getPlayMotNo() const;
    s32 getMotIndex() const;
    void setNextMotion();
    virtual void init();  // vtable slot 7
    virtual void move();  // vtable slot 8
    virtual void final();  // vtable slot 9
private:
    bool mIsCancel;  // offset: 0x41
    bool mIsLoop;  // offset: 0x42
    s32 mNextNPCMotIndex;  // offset: 0x44
    s32 mCancelNPCMotIndex;  // offset: 0x48
    s32 mNPCMotIndex;  // offset: 0x4c
    f32 mNPCMotTimer;  // offset: 0x50
    u32 mMotNo;  // offset: 0x54
    u8 mSex;  // offset: 0x58
public:
    static MyDTI DTI;
};

class cHumanActSetNpcMotion : public cHumanActBase
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
    u32 getCategory() const;
    u32 getMotionNo() const;
    u32 getNoHokan() const;
    s32 getMotIndex() const;
    virtual void init();  // vtable slot 7
    virtual void move();  // vtable slot 8
    virtual void final();  // vtable slot 9
private:
    s32 mNextNPCMotIndex;  // offset: 0x44
    s32 mNPCMotIndex;  // offset: 0x48
    f32 mNPCMotTimer;  // offset: 0x4c
    MtVector3 mInitPos;  // offset: 0x50
public:
    static MyDTI DTI;
};
