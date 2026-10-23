#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/nDDOUtility.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector2;
class MtVector3;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjChildAnimationRoot;
class cGUIObjMessage;
class cGUIObjTexture;
class cpJob09;
class rGUI;

// Declarations
class uGUIGaugeArtsV01_03;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIGaugeArtsV01_03 : public uGUIBase
{
public:
    enum MEDAL_MODE
    {
        MEDAL_MODE_HIDE = 0,
        MEDAL_MODE_SWITCH_INIT = 1,
        MEDAL_MODE_SWITCHING = 2,
        MEDAL_MODE_SWITCH_WAIT = 3,
    };
    enum SW
    {
        SW_MEDAL = 0,
        SW_ELEMENT = 1,
    };
    enum JOB09_ELEMENT_TYPE
    {
        JOB09_ELEMENT_FIRE = 0,
        JOB09_ELEMENT_ICE = 1,
        JOB09_ELEMENT_THUNDER = 2,
        JOB09_ELEMENT_HOLY = 3,
        JOB09_ELEMENT_DARK = 4,
        JOB09_ELEMENT_NUM = 5,
    };
public:
    class MyDTI;
    struct stMedalInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stMedalInfo
    {
    public:
        cGUIObjTexture* mpOBJ_msg_fix_medal_f_icon;  // offset: 0x0
        cGUIObjMessage* mpOBJ_msg_fix_medal_m_num;  // offset: 0x8
        cGUIObjMessage* mpOBJ_msg_fix_medal_m_name;  // offset: 0x10
        cGUIObjTexture* mpOBJ_msg_fix_medal_icon_itemdisable;  // offset: 0x18
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
    MtVector3 getGaugeMousePosition(MtVector3& pos);
    const MtVector2 getGaugeMouseChantInfo();
    bool getGaugeMouseInputMode();
    MtVector3 getGaugeCenterPos();
    MtVector2& getGaugeCursorOffset();
    void setGaugeCursorOffset(MtVector2&);
    void addGaugeCursorOffset(MtVector2& pos);
    void adjustGaugeCursorOffsetLimit();
    f32 getGaugeLimitLength();
    uGUIGaugeArtsV01_03();
    virtual ~uGUIGaugeArtsV01_03();
    virtual void setup();  // vtable slot 6
    virtual bool loadResource();  // vtable slot 76
    virtual void kill();  // vtable slot 16
private:
    void updateInit();
    void updateWait();
    void updateExit();
    void updateDisp();
    void dispMedalInfo(const cpJob09* pJob);
    void setActPltType();
public:
    bool isMedalChanging() const;
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    cGUIInstNull* mpINST_Null;  // offset: 0x8d0
    cGUIInstNull* mpINST_Null_all;  // offset: 0x8d8
    cGUIInstAnimation* mpINST_msg_fix_medal;  // offset: 0x8e0
    cGUIInstNull* mpINST_Null_guide;  // offset: 0x8e8
    cGUIInstAnimation* mpINST_msg_guide;  // offset: 0x8f0
    uGUIBase::cReferenceUIBtnGuide mBtnGuide;  // offset: 0x8f8
    nDDOUtility::cArray<stMedalInfo, 3> mMedalInfos;  // offset: 0x990
    u32 mLastMedalEquipType;  // offset: 0x9f0
    MEDAL_MODE mMedalMode;  // offset: 0x9f4
    s32 mLastSw;  // offset: 0x9f8
    cGUIInstAnimation* mpINST_fix_element;  // offset: 0xa00
    cGUIObjTexture* mpOBJ_fix_element_stick;  // offset: 0xa08
    cGUIObjMessage* mpOBJ_fix_element_m_btn;  // offset: 0xa10
    nDDOUtility::cArray<cGUIObjChildAnimationRoot*, 5> mpOBJ_fix_element_elms;  // offset: 0xa18
    nDDOUtility::cArray<uGUIBase::cReferenceUIBtnGuide::stGuideBtnData, 3> mButtonGuideDatas;  // offset: 0xa40
    bool mGaugeMouseInputMode;  // offset: 0xab8
    MtVector2 mGaugeCursorOffset;  // offset: 0xac0
    f32 mGaugeLimitLength;  // offset: 0xac8
    uGUIBase::cInputGuideMonitor mInputGuideMonitor;  // offset: 0xacc
public:
    static MyDTI DTI;
    static const u32 MEDAL_KIND_NUM = 3;
    static const u32 BUTTON_GUIDE_BIT_MEDAL = 1;
    static const u32 BUTTON_GUIDE_BIT_ELEMENT1 = 2;
    static const u32 BUTTON_GUIDE_BIT_ELEMENT2 = 4;
};
