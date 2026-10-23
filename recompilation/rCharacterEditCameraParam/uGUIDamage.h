#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtColor.h"
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtDTI;
class MtObject;
class MtVector2;
class MtVector3;
class MtVector4;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjColorAdjust;
class cGUIObjMessage;
class rGUI;

// Declarations
class uGUIDamage;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class uGUIDamage : public uGUIBase
{
public:
    enum
    {
        TYPE_DAMAGE = 0,
        TYPE_RECOVER = 1,
        TYPE_NUMBER_NUM = 2,
        TYPE_OCD_START = 2,
        TYPE_OCD_END = 3,
        TYPE_STAMINA = 4,
        TYPE_NUM = 5,
    };
    enum
    {
        FLAG_NONE = 0,
        FLAG_ENEMY = 1,
        FLAG_FATAL = 2,
        FLAG_SLIP = 4,
        FLAG_INVINCIBLE = 8,
        FLAG_FALL_DAMAGE = 16,
        FLAG_PARTY_MEMBER = 32,
    };
public:
    class MyDTI;
    struct stInstInfo;
    struct CoreInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stInstInfo
    {
    public:
        enum STEP
        {
            STEP_INVALID = 0,
            STEP_FADEIN = 1,
            STEP_DISP = 2,
            STEP_FADEOUT = 3,
        };
    public:
        void init();
        void setSequence(u16 flags);
        void setColor(const MtColor& color);
        void setColorScale(const MtVector4& colorScale);
        void updatePos();
        void updateValue();
        void update(uGUIDamage& guiDamage, f32 dispTime, f32 fadeInTime, f32 fadeOutTime, f32 deltaTime);
    private:
        void updateFadeIn(uGUIDamage& guiDamage, f32 fadeInTime, f32 deltaTime);
        void updateDisp(uGUIDamage& guiDamage, f32 fadeInTime, f32 dispTime, f32 deltaTime);
        void updateFadeOut(uGUIDamage& guiDamage, f32 fadeInTime, f32 dispTime, f32 fadeOutTime, f32 deltaTime);
    public:
        bool mEnable;  // offset: 0x0
        u8 mType;  // offset: 0x1
        u32 mFlags;  // offset: 0x4
        s32 mValue;  // offset: 0x8
        f32 mRate;  // offset: 0xc
        f32 mDamageScale;  // offset: 0x10
        cGUIInstNull* mpINST_Null_damege;  // offset: 0x18
        cGUIInstAnimation* mpINST_msg_damage;  // offset: 0x20
        cGUIObjColorAdjust* mpOBJ_msg_damage_ColorAdjust;  // offset: 0x28
        cGUIObjMessage* mpOBJ_msg_damage_m_damage;  // offset: 0x30
        cGUIInstAnimation* mpINST_msg_system;  // offset: 0x38
        cGUIObjColorAdjust* mpOBJ_msg_system_ColorAdjust;  // offset: 0x40
        cGUIObjMessage* mpOBJ_msg_system_m_txt;  // offset: 0x48
        cGUIInstNull* mpINST_Null_status;  // offset: 0x50
        cGUIInstAnimation* mpINST_fix_status;  // offset: 0x58
        cGUIInstAnimation* mpINST_msg;  // offset: 0x60
        cGUIObjColorAdjust* mpOBJ_msg_ColorAdjust;  // offset: 0x68
        cGUIObjMessage* mpOBJ_msg_m_txt;  // offset: 0x70
        STEP mStep;  // offset: 0x78
        f32 mElapsedTime;  // offset: 0x7c
        MtVector3 mPos;  // offset: 0x80
        MtVector2 mPosOfs;  // offset: 0x90
        f32 mPosMoveY;  // offset: 0x98
    };
public:
    struct CoreInfo
    {
    public:
        bool mEnable;  // offset: 0x0
        u8 mWaitFrame;  // offset: 0x1
        u8 mType;  // offset: 0x2
        u32 mFlags;  // offset: 0x4
        s32 mValue;  // offset: 0x8
        f32 mRate;  // offset: 0xc
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
    uGUIDamage();
    virtual ~uGUIDamage();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
    void generateInstance(u8 uType, s32 sValue, f32 fRate, u32 uFlags, const MtVector3* vPos);
protected:
    virtual bool fixCameraRelatedScreenPos();  // vtable slot 81
    virtual void adjustScale();  // vtable slot 84
private:
    void updateInit();
    void updateWait();
    void updateExit();
    void prepareInstInfo(stInstInfo& instInfo);
    void initInstInfo(stInstInfo& instInfo, u8 uType, s32 sValue, f32 fRate, u32 uFlags);
    void reapplyInstInfo(stInstInfo& instInfo, s32 sValue);
    void generateDummyDamageInstance();
    void endDamageInstance(u32 uIdx);
    MtColor getFontColor(u8 uType, u16 uFlags, s32 sValue) const;
    void pushTextCoreInfo(u8 uType, s32 sValue, f32 fRate, u32 uFlags);
    bool popTextCoreInfo(CoreInfo& coreInfo);
    void updateTextInstInfo(f32 deltaTime);
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    cGUIInstNull* mpINST_Null_damege;  // offset: 0x8d0
    stInstInfo mInstInfos[32];  // offset: 0x8e0
    stInstInfo mSlipInstInfos[2];  // offset: 0x1ce0
    stInstInfo mTextInstInfos[4];  // offset: 0x1e20
    u32 mGenerateHead;  // offset: 0x20a0
    u32 mPriorityTop;  // offset: 0x20a4
    u32 mInstInfoIdx;  // offset: 0x20a8
    u32 mTextInstInfoIndex;  // offset: 0x20ac
    CoreInfo mTextCoreInfos[256];  // offset: 0x20b0
    u32 mTextCoreInfoHead;  // offset: 0x30b0
    u32 mTextCoreInfoNum;  // offset: 0x30b4
    f32 mDispTime;  // offset: 0x30b8
    f32 mSlipDispTime;  // offset: 0x30bc
    f32 mFadeInTime;  // offset: 0x30c0
    f32 mFadeOutTime;  // offset: 0x30c4
    f32 mFatalDamageScale;  // offset: 0x30c8
    MtColor mPartyDamageColor;  // offset: 0x30cc
    MtColor mPartyFatalDamageColor;  // offset: 0x30d0
    MtColor mPartyRecoverColor;  // offset: 0x30d4
    MtColor mPartySlipDamageColor;  // offset: 0x30d8
    MtColor mPartySlipRecoverColor;  // offset: 0x30dc
    MtColor mEnemyDamageColor;  // offset: 0x30e0
    MtColor mEnemyFatalDamageColor;  // offset: 0x30e4
    MtColor mEnemyRecoverColor;  // offset: 0x30e8
    MtColor mEnemySlipDamageColor;  // offset: 0x30ec
    MtColor mEnemySlipRecoverColor;  // offset: 0x30f0
    MtColor mGoodStatusStartColor;  // offset: 0x30f4
    MtColor mGoodStatusEndColor;  // offset: 0x30f8
    MtColor mBadStatusStartColor;  // offset: 0x30fc
    MtColor mBadStatusEndColor;  // offset: 0x3100
    MtColor mStaminaColor;  // offset: 0x3104
public:
    static MyDTI DTI;
    static const u32 NUMBER_INSTINFO_MAX = 32;
    static const u32 TEXT_INSTINFO_MAX = 4;
private:
    static const u32 TEXT_CORE_INFO_NUM = 256;
};
