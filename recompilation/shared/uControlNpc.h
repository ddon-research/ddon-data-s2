#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtString.h"
#include "uControl.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtString;
class cpTalk;
class uDDOModel;
class uNpc;

// Declarations
class uControlNpc;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using s8 = signed char;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class uControlNpc : public uControl
{
    // inferred: cpTalk::startFaceMot names uControlNpc::mIsEyeClose
    friend class cpTalk;
    // inferred: uNpc::controlLantern names uControlNpc::mIsFsmEventNpc
    friend class uNpc;
public:
    enum
    {
        RNO_GET_PAWN_DATA_INIT = 0,
        RNO_GET_PAWN_DATA_PAWN_ID = 1,
        RNO_GET_MY_PAWN_DATA_SLOT_NO = 2,
        RNO_GET_RENTAL_PAWN_DATA_SLOT_NO = 3,
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
    uControlNpc();
    virtual ~uControlNpc();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void updatePtr();  // vtable slot 17
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    void setOwner(uDDOModel* pOwner);
    virtual s32 getNpcId();  // vtable slot 24
    void setNpcItem(u32 npcItem);
    u32 getNpcItem();
    virtual MT_CTSTR getName();  // vtable slot 14
    MT_CTSTR getNpcName() const;
    bool isDispClassName();
    MT_CTSTR getClassName();
    MT_CTSTR getClassNameForce();
    u8 getSex() const;
    void setNpcName(MT_CTSTR name);
    void setClassName(MT_CTSTR className);
    void setSex(u8 sex);
    MT_CTSTR getFSMFilePath();
    void setFSMFilePath(MT_CTSTR filePath);
    bool isFsmEventNpc() const;
    void setFsmEventNpc(bool isFsmEventNpc);
    u32 getClothType() const;
    void setClothType(u32 clothType);
    s8 getDefNPCMotCategory() const;
    void setDefNPCMotCategory(s8 category);
    s8 getDefNPCMotNo() const;
    void setDefNPCMotNo(s8 no);
    s8 getDefTurnType() const;
    void setDefTurnType(s8 no);
    u16 getThinkIndex() const;
    void setThinkIndex(u16 index);
    u16 getJobLv() const;
    void setJobLv(u16 jobLv);
    void setJobParam();
    bool isForceDispOff();
    void setForceDispOff(bool IsSet);
    bool isInvincible();
    void setInvincible(bool IsInvincible);
    bool isNpcArc();
    void setNpcArc(bool IsSet);
    void setPawnId(u32 pawnId, bool equip);
    u32 getPawnId() const;
    void setMyPawnSlotNo(u32 slotNo, bool equip);
    u32 getMyPawnSlotNo() const;
    void setRentalPawnSlotNo(u32 slotNo, bool equip);
    u32 getRentalPawnSlotNo() const;
    bool isCharaData();
    bool isEditData();
    bool isSetup();
    void setNpcInfo(bool flag);
    bool isNpcInfo();
    bool isPawnData();
    void setEquipInfo();
    void moveGetPawnData();
    void setHumanData(u32 type, u32 index);
    bool isAdjScrOff();
    void setAdjScrOff(bool IsAdj);
    void onAdjScrOff();
    void offAdjScrOff();
    bool isAttend();
    void setAttend(bool IsAttend);
    bool isDispWepMain() const;
    void setDispWepMain(bool isDisp);
    bool isDispWepSub() const;
    void setDispWepSub(bool isDisp);
    bool isDisableTouchAction();
    void setDisableTouchAction(bool IsDisable);
    bool isDisableLedgerFinger();
    void setDisableLedgerFinger(bool disableLedgerFinger);
    bool isForceListTalk();
    void setForceListTalk(bool IsForceListTalk);
    bool hasFsmRes();
    bool isUseEditResource();
    u8 getFinger() const;
    void setFinger(u8 finger);
    u8 getJobId() const;
    void setJobId(u8 job);
    u8 getVoiceType() const;
    void setVoiceType(u8 voiceType);
    u8 getUnitType() const;
    void setUnitType(u8 unitType);
    u32 getUnitTypeParam() const;
    void setUnitTypeParam(u32 unitTypeParam);
    u8 getLantern() const;
    void setLantern(u8 lantern);
    u32 getFunctionType(u32 Idx);
    void calcPlDistance();
    void checkMasterChange();
    f32 getPlDistance();
    bool isUseMotionListLight();
    virtual bool isArcLoadFinish();  // vtable slot 25
    void setBaseRot(f32 Rot);
    f32 getBaseRot();
    void setEnableTalkAct(bool IsEnable);
    bool isEnableTalkAct();
    void setDispElseQuestTalk(bool IsDisp);
    bool isDispElseQuestTalk();
    void resetRnoGetPawnData();
    void setEyeClose(bool IsClose);
    bool isEyeClose();
    void setDispMiniMap(bool IsDisp);
    bool isDispMiniMap();
    void setUseJobParamEx(bool IsUse);
    bool isUseJobParamEx();
protected:
    void updateDispWeapon();
    void setupNpcLedgerParam();
    u32 getClanMyPartnerPawn();
    u32 getClanMemberPartnerPawn(u32 idx);
public:
    void setWepAtk(f32 WepAtk);
    void setWepMAtk(f32 WepMAtk);
    f32 getWepAtk();
    f32 getWepMAtk();
protected:
    MtString mNpcName;  // offset: 0x288
    MtString mClassName;  // offset: 0x290
    u8 mSex;  // offset: 0x298
    MtString mFSMFilePath;  // offset: 0x2a0
    u8 mClothType;  // offset: 0x2a8
    s8 mDefNPCMotCategory;  // offset: 0x2a9
    s8 mDefNPCMotNo;  // offset: 0x2aa
    s8 mDefTurnType;  // offset: 0x2ab
    u8 mLantern;  // offset: 0x2ac
    u16 mThinkIndex;  // offset: 0x2ae
    u16 mJobLv;  // offset: 0x2b0
    MtString mUnitName;  // offset: 0x2b8
    bool mIsFsmEventNpc;  // offset: 0x2c0
    bool mIsForceDispOff;  // offset: 0x2c1
    bool mIsPawnData;  // offset: 0x2c2
    bool mIsEquip;  // offset: 0x2c3
    u8 mRnoGetPawnData;  // offset: 0x2c4
    u32 mPawnId;  // offset: 0x2c8
    u32 mMyPawnSlotNo;  // offset: 0x2cc
    u32 mRentalPawnSlotNo;  // offset: 0x2d0
    bool mIsScrAdjOff;  // offset: 0x2d4
    bool mIsSetupPawn;  // offset: 0x2d5
    u32 mNpcItem;  // offset: 0x2d8
    bool mIsDisableTouchAction;  // offset: 0x2dc
    bool mIsAttend;  // offset: 0x2dd
    bool mIsDispWepMain;  // offset: 0x2de
    bool mIsDispWepSub;  // offset: 0x2df
    bool mIsEditData;  // offset: 0x2e0
    bool mIsSetup;  // offset: 0x2e1
    bool mIsNpcInfo;  // offset: 0x2e2
    bool mDisableLedgerFinger;  // offset: 0x2e3
    bool mIsForceListTalk;  // offset: 0x2e4
    bool mIsInvincible;  // offset: 0x2e5
    bool mIsNpcArc;  // offset: 0x2e6
    u8 mJobId;  // offset: 0x2e7
    u8 mFinger;  // offset: 0x2e8
    u8 mVoiceType;  // offset: 0x2e9
    u8 mUnitType;  // offset: 0x2ea
    u32 mUnitTypeParam;  // offset: 0x2ec
    f32 mPlDistance;  // offset: 0x2f0
    f32 mPlDistCalcTimer;  // offset: 0x2f4
    f32 mPlDistCalcTime;  // offset: 0x2f8
    f32 mMasterChangeCheckTimer;  // offset: 0x2fc
    f32 mBaseRot;  // offset: 0x300
    bool mIsEnableTalkAct;  // offset: 0x304
    bool mIsDispElseQuestTalk;  // offset: 0x305
    bool mIsEyeClose;  // offset: 0x306
    bool mIsDispMiniMap;  // offset: 0x307
    bool mIsUseJobParamEx;  // offset: 0x308
    f32 mWepAtk;  // offset: 0x30c
    f32 mWepMAtk;  // offset: 0x310
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline u32 uControlNpc::getNpcItem() {
    return this->mNpcItem;
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline bool uControlNpc::isFsmEventNpc() const {
    return this->mIsFsmEventNpc;
}

// Inline, no code of its own: checked where it is inlined.
inline bool uControlNpc::isAttend() {
    return this->mIsAttend;
}
