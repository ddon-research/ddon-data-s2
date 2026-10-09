#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtColor.h"
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/MtString.h"
#include "../shared/nDDOUtility.h"
#include "../shared/nGUIExt.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtDTI;
class MtObject;
class MtString;
class MtVector3;
class cContextInstHm;
class cDraw;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjColorAdjust;
class cGUIObjMessage;
class cGUIObjNull;
class cGUIObjTexture;
class cOmControl;
class cpOmWarp;
namespace nGUIExt { struct HeadUiInfo; }
namespace nGUIExt { struct OcdIconParam; }
class rGUI;
class uDDOModel;
class uHuman;

// Declarations
class uGUIGaugeNpc;
class uGUIGaugeNpcBase;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIGaugeNpcBase : public uGUIBase
{
public:
    enum MODE
    {
        MODE_INVALID = 0,
        MODE_CHARACTER_LIFE = 1,
        MODE_DEFENCE = 2,
        MODE_CHARACTER = 3,
        MODE_NPC = 4,
        MODE_OM = 5,
        MODE_PLAYER = 6,
        MODE_NUM = 7,
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
    static uDDOModel* GetSelectedTouchTarget();
    static MODE GetMode(uDDOModel* unit);
    static u32 GetFlowId(MODE mode);
    static MtVector3 CalcUiPos(const uDDOModel* unit);
    uGUIGaugeNpcBase();
    virtual ~uGUIGaugeNpcBase();
    virtual bool loadResource();  // vtable slot 76
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    virtual void moveAfter();  // vtable slot 10
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    virtual void updatePtr();  // vtable slot 17
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
    void setUnit(uDDOModel* pUnit);
protected:
    void setupInstances();
    void updateExit();
    bool updatePos(const uDDOModel* unit);
    bool isPartyMember() const;
    bool setFlow(u32 flowId);
    void setPriorityByMode(MODE mode);
protected:
    rGUI* mpGUIRes;  // offset: 0x8c8
    MtVector3 mWorldOffset;  // offset: 0x8d0
    MtVector3 mPrioPos;  // offset: 0x8e0
    MODE mMode;  // offset: 0x8f0
    uDDOModel* mpUnit;  // offset: 0x8f8
    uHuman* mpHuman;  // offset: 0x900
    cGUIInstNull* mpINST_Null;  // offset: 0x908
    cGUIInstNull* mpINST_Null_all;  // offset: 0x910
    cGUIInstAnimation* mpINST_target;  // offset: 0x918
    cGUIInstAnimation* mpINST_msg_name;  // offset: 0x920
    cGUIInstAnimation* mpINST_msg_npcname;  // offset: 0x928
    cGUIInstAnimation* mpINST_fix_gaugepc;  // offset: 0x930
    cGUIInstAnimation* mpINST_fix_icon00;  // offset: 0x938
    cGUIInstAnimation* mpINST_fix_icon_quest;  // offset: 0x940
    cGUIInstAnimation* mpINST_autorun_icon;  // offset: 0x948
    cGUIInstAnimation* mpINST_fix_classicon;  // offset: 0x950
    cGUIInstAnimation* mpINST_areamaster_icon;  // offset: 0x958
    cGUIInstAnimation* mpINST_sos_icon;  // offset: 0x960
    cGUIInstNull* mpINST_Null_charges;  // offset: 0x968
    nDDOUtility::cArray<cGUIInstAnimation*, 2> mpINST_fix_jyoutais;  // offset: 0x970
public:
    static MyDTI DTI;
    static const u32 OCD_ICON_NUM = 2;
};

class uGUIGaugeNpc : public uGUIGaugeNpcBase
{
public:
    class MyDTI;
    struct stData;
    struct StatusInfo;
    class IOcdIcon;
public:
    using cLocalStr = MtStringEx<128>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stData
    {
    public:
        cGUIObjMessage* mpOBJ_msg_name_m_name;  // offset: 0x0
        cGUIObjMessage* mpOBJ_msg_npcname_m_npcname;  // offset: 0x8
        cGUIObjTexture* mpOBJ_fix_icon00_f_icon;  // offset: 0x10
        cGUIObjTexture* mpOBJ_fix_icon00_base;  // offset: 0x18
        cGUIObjColorAdjust* mpOBJ_fix_gaugepc_ColorAdjust;  // offset: 0x20
        cGUIObjMessage* mpOBJ_fix_gaugepc_m_name;  // offset: 0x28
        cGUIObjNull* mpOBJ_fix_gaugepc_Null_hp;  // offset: 0x30
        cGUIObjTexture* mpOBJ_fix_gaugepc_fix_life;  // offset: 0x38
        cGUIObjTexture* mpOBJ_fix_gaugepc_fix_life_dying;  // offset: 0x40
        cGUIObjTexture* mpOBJ_fix_gaugepc_fix_ailment00;  // offset: 0x48
        cGUIObjTexture* mpOBJ_fix_gaugepc_fix_life_siro00;  // offset: 0x50
        cGUIObjNull* mpOBJ_fix_gaugepc_Null_timer;  // offset: 0x58
        cGUIObjTexture* mpOBJ_fix_gaugepc_fix_timer;  // offset: 0x60
        cGUIObjNull* mpOBJ_fix_gaugepc_Null_rescue;  // offset: 0x68
        cGUIObjTexture* mpOBJ_fix_gaugepc_f_rescue;  // offset: 0x70
        cGUIObjColorAdjust* mpOBJ_sos_icon_ColorAdjust;  // offset: 0x78
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
    class IOcdIcon : public nGUIExt::OcdIconInterface
    {
    public:
        IOcdIcon(uGUIGaugeNpc& owner, uHuman& human);
        // Address: 0x01afb610 - 0x01afb611 (1 bytes)
        virtual ~IOcdIcon() {}
    protected:
        uGUIGaugeNpc::IOcdIcon& operator=(const uGUIGaugeNpc::IOcdIcon&);
        virtual u32 getOcdIconParamNum() const;  // vtable slot 2
        virtual nGUIExt::OCD_ICON_CATEGORY getOcdIconCategory(u32 paramIndex) const;  // vtable slot 3
        virtual nGUIExt::OcdIconParam& refOcdIconParam(u32 paramIndex);  // vtable slot 4
        virtual bool isOcdActive(u32 ocdId) const;  // vtable slot 5
        virtual bool isOcdAccumulating(u32 ocdId) const;  // vtable slot 6
        virtual void setOcdIcon(u32 iconIndex, u32 ocdId, nGUIExt::OCD_ICON_ANIM iconAnim, f32 animFrame);  // vtable slot 7
    private:
        uGUIGaugeNpc& mOwner;  // offset: 0x8
        uHuman& mHuman;  // offset: 0x10
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
    uGUIGaugeNpc();
    virtual ~uGUIGaugeNpc();
    virtual void setup();  // vtable slot 6
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    void setMode(uGUIGaugeNpcBase::MODE mode);
    void resetMode(uGUIGaugeNpcBase::MODE mode);
    uGUIGaugeNpcBase::MODE getMode();
    void setObjectName(MT_CTSTR name);
    MT_CTSTR getObjectName();
    void setTitleName(MT_CTSTR name);
    MT_CTSTR getTitleName();
    bool checkClosedByOmCtrl();
private:
    bool checkClosedByOmCtrl(cOmControl* omCtrl);
    void updateInit();
    void updateWait();
    void updateDisp();
    void updateMode();
    void updateName();
    void updateHpGauge(cContextInstHm* context);
    void updateInjuredGauge(cContextInstHm* context);
    bool updateRescueGauge(cContextInstHm* context);
    u32 updateOcdIcon();
    void updateOmInfo();
    void updateTargetIcon();
    void setOnlineIconPositionX(cGUIInstAnimation* instIcon);
    void setStatusIconPositionX(cGUIInstAnimation* instIcon, s32 index);
    cpOmWarp* getOmWarpComponent();
    void updateOmWarpNames();
    void setOmWarpName(u32 warpIndex);
    void setNameColor();
    void clearAllMessages();
    bool isVisibleSosIcon(uHuman& human);
    bool isVisibleAreaMasterIcon(u32 npcId);
    bool isVisibleAchieveIcon(u32 npcId);
    bool isVisiblePawnExpeditionIcon(u32 npcId);
    bool isVisibleJobMasterIcon(u32 npcId);
    bool checkFloorGroup() const;
private:
    stData mData;  // offset: 0x980
    uGUIBase::cReferenceUIIconQuest mIconQuest;  // offset: 0xa00
    uGUIBase::cReferenceUIIconOnlineStatus mIconOnlineStatus;  // offset: 0xae0
    uGUIBase::cReferenceUIChargesInfo mChargesInfo;  // offset: 0xb30
    cLocalStr mObjectName;  // offset: 0xc88
    cLocalStr mObjectNameOld;  // offset: 0xd0c
    cLocalStr mTitleName;  // offset: 0xd90
    cLocalStr mTitleNameOld;  // offset: 0xe14
    uGUIGaugeNpcBase::MODE mMode;  // offset: 0xe98
    uGUIGaugeNpcBase::MODE mModeOld;  // offset: 0xe9c
    nGUIExt::HEAD_UI_TYPE mHeadUiType;  // offset: 0xea0
    bool mForceVisible;  // offset: 0xea4
    bool mIsDrawTargetIcon;  // offset: 0xea5
    u32 mDownRno;  // offset: 0xea8
    nGUIExt::HeadUiInfo mHeadUiInfo;  // offset: 0xeac
    MtColor mNameColor;  // offset: 0xec4
    MtColor mNameAmbientColor;  // offset: 0xec8
    f32 mOnlineIconWidth;  // offset: 0xecc
    s32 mMarginIconOnline;  // offset: 0xed0
    s32 mMarginIconStatus;  // offset: 0xed4
    s32 mOffsetIconStatus;  // offset: 0xed8
    f32 mSosIconAlpha;  // offset: 0xedc
    nDDOUtility::cArray<StatusInfo, 2> mStatusInfos;  // offset: 0xee0
    nDDOUtility::cArray<uGUIBase::cReferenceUIIconStatus, 2> mStatusIcons;  // offset: 0xf20
    u32 mOmWarpIndex;  // offset: 0xfb0
    f32 mOmWarpFrame;  // offset: 0xfb4
    nDDOUtility::cArray<MtString, 3> mOmWarpNames;  // offset: 0xfb8
    u32 mOmWarpNum;  // offset: 0xfd0
public:
    static MyDTI DTI;
};
