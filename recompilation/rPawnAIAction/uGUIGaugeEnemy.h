#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/MtString.h"
#include "../shared/nDDOUtility.h"
#include "../shared/nGUIExt.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtRectF;
class MtVector3;
class cDraw;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class cGUIObjPolygon;
class cGUIObjTexture;
namespace nGUIExt { struct OcdIconParam; }
class rGUI;
class uCharacter;
class uEnemy;

// Declarations
class uGUIGaugeEnemy;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
namespace nGUIExt { using StringEnemyName = MtStringEx<256>; }
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIGaugeEnemy : public uGUIBase
{
public:
    class MyDTI;
    struct DATA;
    struct TargetIcon;
    struct HateIcon;
    struct stGaugeInfo;
    struct StatusInfo;
    class RageShrinkIcon;
    class IOcdIcon;
public:
    using TargetIcons = nDDOUtility::cArray<uGUIGaugeEnemy::TargetIcon, 2>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct TargetIcon
    {
    public:
        enum TYPE
        {
            TYPE_NONE = 0,
            TYPE_TANKER = 1,
            TYPE_PAWN = 2,
        };
    public:
        void setup(uGUIBase* base, u32 instId, u32 pawnIconSeqId);
        void set(TYPE targetIconType);
    public:
        cGUIInstAnimation* mpINST_fix_target;  // offset: 0x0
        TYPE mType;  // offset: 0x8
        u32 mPawnIconSeqId;  // offset: 0xc
    };
public:
    struct HateIcon
    {
    public:
        void setup(uGUIBase* base, u32 instId_fix_hate, u32 instId_hate_anim00);
        void updateEvaluationPoint(uCharacter* character);
        void resetEvaluationPoint();
    public:
        cGUIInstAnimation* mpINST_fix_hate;  // offset: 0x0
        cGUIInstAnimation* mpINST_hate_anim00;  // offset: 0x8
        f32 mLastEvaluationPercent;  // offset: 0x10
        f32 mEvaluationPercent;  // offset: 0x14
        f32 mFrame;  // offset: 0x18
    };
public:
    struct stGaugeInfo
    {
    public:
        MT_CHAR mName[13];  // offset: 0x0
        s32 mLvLatest;  // offset: 0x10
        f32 mHpLatest;  // offset: 0x14
        f32 mAngerRateLast;  // offset: 0x18
    };
public:
    struct StatusInfo
    {
    public:
        StatusInfo();
        void init();
    public:
        nGUIExt::OcdIconParam mParam;  // offset: 0x0
    };
public:
    class RageShrinkIcon
    {
    public:
        enum STATE
        {
            STATE_OFF = 0,
            STATE_RAGE = 1,
            STATE_CHANCE = 2,
            STATE_DAMAGE = 3,
        };
    public:
        RageShrinkIcon();
        void setup(uGUIBase* base, u32 instId_null_angericon, u32 instId_angericon);
        bool update(const uCharacter* character, bool isInit, bool isAngerDamage);
        STATE getState() const;
        STATE checkState(const uCharacter* character, bool isAngerDamage) const;
    private:
        STATE mState;  // offset: 0x0
        cGUIInstNull* mpINST_Null_angericon;  // offset: 0x8
        cGUIInstAnimation* mpINST_angericon;  // offset: 0x10
        cGUIObjPolygon* mpOBJ_fix_angericon_f_gauge;  // offset: 0x18
    };
public:
    class IOcdIcon : public nGUIExt::OcdIconInterface
    {
    public:
        IOcdIcon(uGUIGaugeEnemy& owner, uCharacter& character);
        // Address: 0x01afb580 - 0x01afb581 (1 bytes)
        virtual ~IOcdIcon() {}
    protected:
        uGUIGaugeEnemy::IOcdIcon& operator=(const uGUIGaugeEnemy::IOcdIcon&);
        virtual u32 getOcdIconParamNum() const;  // vtable slot 2
        virtual nGUIExt::OCD_ICON_CATEGORY getOcdIconCategory(u32 paramIndex) const;  // vtable slot 3
        virtual nGUIExt::OcdIconParam& refOcdIconParam(u32 paramIndex);  // vtable slot 4
        virtual bool isOcdActive(u32 ocdId) const;  // vtable slot 5
        virtual bool isOcdAccumulating(u32 ocdId) const;  // vtable slot 6
        virtual void setOcdIcon(u32 iconIndex, u32 ocdId, nGUIExt::OCD_ICON_ANIM iconAnim, f32 animFrame);  // vtable slot 7
    private:
        uGUIGaugeEnemy& mOwner;  // offset: 0x8
        uCharacter& mCharacter;  // offset: 0x10
    };
public:
    struct DATA
    {
    public:
        cGUIInstNull* mpINST_Null;  // offset: 0x0
        cGUIInstNull* mpINST_Null_enemy;  // offset: 0x8
        cGUIInstAnimation* mpINST_msg_name;  // offset: 0x10
        cGUIObjMessage* mpOBJ_msg_name_m_name;  // offset: 0x18
        cGUIObjMessage* mpOBJ_msg_name_m_lang;  // offset: 0x20
        cGUIObjMessage* mpOBJ_msg_name_m_lv;  // offset: 0x28
        cGUIInstAnimation* mpINST_fix_icon;  // offset: 0x30
        cGUIInstAnimation* mpINST_fix_icon_quest;  // offset: 0x38
        uGUIGaugeEnemy::TargetIcons mTargetIcons;  // offset: 0x40
        uGUIGaugeEnemy::HateIcon mHateIcon;  // offset: 0x60
        cGUIInstAnimation* mpINST_fix_gauge;  // offset: 0x80
        cGUIObjTexture* mpOBJ_fix_gauge_f_life;  // offset: 0x88
        cGUIObjTexture* mpOBJ_fix_gauge_f_anger;  // offset: 0x90
        nDDOUtility::cArray<cGUIInstNull*, 2> mpINST_Null_jyoutais;  // offset: 0x98
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
    static void SetTargetIcons(TargetIcons& targetIcons, uCharacter* character);
    static void SetQuestIcon(cGUIInstAnimation* pINST_fix_icon, s32 omCtrledType, uGUIBase::cReferenceUIIconQuest& questIcon, uCharacter* character);
    static void SetHateIcon(HateIcon& hateIcon, uCharacter* character, const TargetIcons& targetIcons, f32 deltaTime);
    static void SetStatusIcon(uGUIBase::cReferenceUIIconStatus& statusIcon, u32 ocdId, nGUIExt::OCD_ICON_ANIM iconAnim, f32 animFrame, uCharacter& character);
    static bool IsDispAngerGauge(const uEnemy* enemy);
    static void CenteringName(cGUIObjMessage* pOBJ_msg_name_m_lang, cGUIObjMessage* pOBJ_msg_name_m_lv, cGUIObjMessage* pOBJ_msg_name_m_name, f32 spacingLvAndLvNum, f32 spacingLvNumAndName);
    uGUIGaugeEnemy();
    virtual ~uGUIGaugeEnemy();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    virtual void moveAfter();  // vtable slot 10
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    virtual void updatePtr();  // vtable slot 17
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
    const uCharacter* getCharacter();
    void setCharacter(uCharacter* pCharacter);
    bool isForceUpdate();
    void setForceUpdate(bool bForceUpdate);
    void startForceDisp();
private:
    void updatePosition();
    bool updateScaling();
    void updateName();
    void updateExit();
    void updateInit();
    void updateWait();
    void updateDisp();
    void setForceVisible(bool);
    bool isInvisibleEnemy() const;
    bool calcBoundingBox(MtRectF& boundingBox);
    MtVector3 calcUiPos() const;
    void setDispState(bool isVisible, f32 z);
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    DATA mData;  // offset: 0x8d0
    uCharacter* mpCharacter;  // offset: 0x978
    nGUIExt::StringEnemyName mNameEnemy;  // offset: 0x980
    stGaugeInfo mGaugeInfo;  // offset: 0xa84
    f32 mFarLength;  // offset: 0xaa0
    f32 mHeadLength;  // offset: 0xaa4
    uGUIBase::cReferenceUIIconQuest mQuestIcon;  // offset: 0xaa8
    uGUIBase::cReferenceUIIconShake mShakeIcon;  // offset: 0xb88
    MtVector3 mWorldOffset;  // offset: 0xbf0
    MtVector3 mPrioPos;  // offset: 0xc00
    uGUIBase::cScreenAdjustPos mScreenAdjustPos;  // offset: 0xc10
    nDDOUtility::cArray<StatusInfo, 2> mStatusInfos;  // offset: 0xc90
    nDDOUtility::cArray<uGUIBase::cReferenceUIIconStatus, 2> mStatusIcons;  // offset: 0xcd0
    f32 mSpacingLvAndLvNum;  // offset: 0xd60
    f32 mSpacingLvNumAndName;  // offset: 0xd64
    s32 mOmCtrledType;  // offset: 0xd68
    bool mForceUpdate;  // offset: 0xd6c
    bool mForceVisible;  // offset: 0xd6d
    bool mIsInitDisp;  // offset: 0xd6e
    f32 mForceDispTime;  // offset: 0xd70
    RageShrinkIcon mRageShrinkIcon;  // offset: 0xd78
public:
    static MyDTI DTI;
    static const u32 OCD_ICON_NUM = 2;
    static const u32 TARGET_ICON_NUM = 2;
    static const f32 OCD_ICON_ACCUMULATING_ALPHA;
};
