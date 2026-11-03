#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtString.h"
#include "nDDOUtility.h"
#include "nGUIExt.h"
#include "uGUIBase.h"
#include "uGUIGaugeEnemy.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cDraw;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObj2D;
class cGUIObjChildAnimationRoot;
class cGUIObjMessage;
class cGUIObjTexture;
class rGUI;
class rScheduler;
class uCharacter;
class uScheduler;

// Declarations
class uGUIGaugeEnemyBoss;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
namespace nGUIExt { using StringEnemyName = MtStringEx<256>; }
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIGaugeEnemyBoss : public uGUIBase
{
public:
    class MyDTI;
    struct DATA;
    struct OcdInfo;
    struct stGaugeInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct DATA
    {
    public:
        cGUIInstNull* mpINST_Null;  // offset: 0x0
        cGUIInstNull* mpINST_Null_all;  // offset: 0x8
        cGUIInstAnimation* mpINST_fix_icon;  // offset: 0x10
        cGUIInstAnimation* mpINST_fix_icon_quest;  // offset: 0x18
        uGUIGaugeEnemy::TargetIcons mTargetIcons;  // offset: 0x20
        uGUIGaugeEnemy::HateIcon mHateIcon;  // offset: 0x40
        cGUIInstAnimation* mpINST_fix_gauge;  // offset: 0x60
        cGUIInstAnimation* mpINST_fix_anger;  // offset: 0x68
        nDDOUtility::cArray<cGUIObjTexture*, 2> mpOBJ_fix_gauge_f_life;  // offset: 0x70
        nDDOUtility::cArray<cGUIObj2D*, 4> mpOBJ_fix_anger_f_anger;  // offset: 0x80
        cGUIObjTexture* mpOBJ_fix_anger_f_delay;  // offset: 0xa0
        nDDOUtility::cArray<cGUIObjChildAnimationRoot*, 3> mpOBJ_fix_anger_effect;  // offset: 0xa8
        cGUIObjMessage* mpOBJ_msg_name_m_name;  // offset: 0xc0
        cGUIObjMessage* mpOBJ_msg_name_m_lang;  // offset: 0xc8
        cGUIObjMessage* mpOBJ_msg_name_m_lv;  // offset: 0xd0
        nDDOUtility::cArray<cGUIInstNull*, 58> mpINST_Null_jyoutais;  // offset: 0xd8
    };
public:
    struct OcdInfo
    {
    public:
        f32 mFrame;  // offset: 0x0
        nGUIExt::OCD_ICON_ANIM mIconAnim;  // offset: 0x4
    };
public:
    struct stGaugeInfo
    {
    public:
        MT_CHAR mName[13];  // offset: 0x0
        s32 mLvLast;  // offset: 0x10
        f32 mHpLast;  // offset: 0x14
        f32 mAngerRateLast;  // offset: 0x18
        f32 mDelayRateCurrent;  // offset: 0x1c
        f32 mDelayRateStart;  // offset: 0x20
        f32 mDelayRateEnd;  // offset: 0x24
        f32 mDelayWaitElapsedTime;  // offset: 0x28
        f32 mDelayDecreaseElapsedTime;  // offset: 0x2c
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
    uGUIGaugeEnemyBoss();
    virtual ~uGUIGaugeEnemyBoss();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    virtual void updatePtr();  // vtable slot 17
    const uCharacter* getCharacter();
    void setCharacter(uCharacter* pCharacter);
    bool isForceUpdate();
    void setForceUpdate(bool bForceUpdate);
    virtual void changeFlow(u32 flowId);  // vtable slot 91
private:
    void updateExit();
    void updateWait();
    void updateDamage();
    void updateDead();
    bool checkDead();
    bool checkDamage();
    void updateDisp();
    void updateIconStatus();
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    rScheduler* mpSdlRes;  // offset: 0x8d0
    uScheduler* mpScheduler;  // offset: 0x8d8
    DATA mData;  // offset: 0x8e0
    nDDOUtility::cArray<uGUIBase::cReferenceUIIconStatus, 58> mStatusIcons;  // offset: 0xb88
    OcdInfo mGoodOcdInfos[27];  // offset: 0x1bd8
    OcdInfo mBadOcdInfos[31];  // offset: 0x1cb0
    uCharacter* mpCharacter;  // offset: 0x1da8
    nGUIExt::StringEnemyName mNameEnemy;  // offset: 0x1db0
    stGaugeInfo mGaugeInfo;  // offset: 0x1eb4
    uGUIBase::cReferenceUIIconQuest mQuestIcon;  // offset: 0x1ee8
    uGUIBase::cReferenceUIIconShake mShakeIcon;  // offset: 0x1fc8
    f32 mDelayWaitTime;  // offset: 0x2030
    f32 mDelayDecreaseTime;  // offset: 0x2034
    f32 mSpacingLvAndLvNum;  // offset: 0x2038
    f32 mSpacingLvNumAndName;  // offset: 0x203c
    s32 mOmCtrledType;  // offset: 0x2040
    bool mForceUpdate;  // offset: 0x2044
    bool mIsInitDisp;  // offset: 0x2045
    uGUIGaugeEnemy::RageShrinkIcon mRageShrinkIcon;  // offset: 0x2048
public:
    static MyDTI DTI;
    static const u32 NUM_OBJ_fix_gauge_f_life = 2;
    static const u32 NUM_OBJ_fix_anger_f_anger = 4;
    static const u32 NUM_OBJ_fix_anger_effect = 3;
    static const u32 OCD_ICON_COLUMN_NUM = 12;
    static const u32 OCD_GOOD_NUM = 27;
    static const u32 OCD_BAD_NUM = 31;
    static const u32 OCD_ICON_NUM = 58;
    static const u32 OCD_ICON_ROW_NUM = 5;
};

inline void* uGUIGaugeEnemyBoss::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
