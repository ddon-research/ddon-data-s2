#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtPrimitive2D.h"
#include "nDDOUtility.h"
#include "uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtRectF;
class MtVector2;
class MtVector3;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjChildAnimationRoot;
class cGUIObjColorAdjust;
class cGUIObjMessage;
class cGUIObjTexture;
class cGUIObjTextureSet;
class rGUI;

// Declarations
class uGUIGaugeArts;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIGaugeArts : public uGUIBase
{
public:
    enum HUNTER_MODE
    {
        HUNTER_MODE_HIDE = 0,
        HUNTER_MODE_SWITCH_INIT = 1,
        HUNTER_MODE_SWITCH_WAIT = 2,
        HUNTER_MODE_RELOAD_MOVE = 3,
        HUNTER_MODE_RELOAD_FAIL = 4,
        HUNTER_MODE_RELOAD_END = 5,
    };
    enum JOB05_ELEMENT_TYPE
    {
        JOB05_ELEMENT_FIRE = 0,
        JOB05_ELEMENT_ICE = 1,
        JOB05_ELEMENT_THUNDER = 2,
        JOB05_ELEMENT_HOLY = 3,
        JOB05_ELEMENT_DARK = 4,
        JOB05_ELEMENT_NUM = 5,
    };
public:
    class MyDTI;
    struct Arrowset;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct Arrowset
    {
    public:
        cGUIInstAnimation* mpINST;  // offset: 0x0
        cGUIObjMessage* mpOBJ_msg_fix_arrowset_m_num;  // offset: 0x8
        cGUIObjMessage* mpOBJ_msg_fix_arrowset_m_f_name;  // offset: 0x10
        cGUIObjColorAdjust* mpOBJ_msg_fix_arrowset_f_ColorAdjust;  // offset: 0x18
        cGUIInstAnimation* mpINST_icon_itemdisable;  // offset: 0x20
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
    uGUIGaugeArts();
    virtual ~uGUIGaugeArts();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
private:
    void updateInit();
    void updateWait();
    void updateExit();
    void updateDisp();
    void initHunterMode();
    void setActPltType();
private:
    HUNTER_MODE mHunterMode;  // offset: 0x8c8
    u32 mLastArrowEquipType;  // offset: 0x8cc
    f32 mRemainingDispFrame;  // offset: 0x8d0
    rGUI* mpGUIRes;  // offset: 0x8d8
    cGUIInstNull* mpINST_Null;  // offset: 0x8e0
    cGUIInstNull* mpINST_Null_all;  // offset: 0x8e8
    cGUIInstAnimation* mpINST_fix_element;  // offset: 0x8f0
    cGUIObjTexture* mpOBJ_fix_element_stick;  // offset: 0x8f8
    cGUIObjMessage* mpOBJ_fix_element_m_btn;  // offset: 0x900
    nDDOUtility::cArray<cGUIObjChildAnimationRoot*, 5> mpOBJ_fix_element_elms;  // offset: 0x908
    cGUIInstNull* mpINST_Null_jobactn;  // offset: 0x930
    cGUIInstAnimation* mpINST_gauge_flash;  // offset: 0x938
    cGUIInstAnimation* mpINST_msg_just;  // offset: 0x940
    cGUIInstAnimation* mpINST_fix_gauge;  // offset: 0x948
    cGUIObjTextureSet* mpOBJ_msg_fix_gauge_f_reloadbar00;  // offset: 0x950
    cGUIObjTexture* mpOBJ_msg_fix_gauge_f_reloadbar01;  // offset: 0x958
    cGUIObjTexture* mpOBJ_msg_fix_gauge_f_reloadbar02;  // offset: 0x960
    cGUIObjTexture* mpOBJ_msg_fix_gauge_activeline;  // offset: 0x968
    cGUIObjTexture* mpOBJ_msg_fix_gauge_active;  // offset: 0x970
    cGUIObjTexture* mpOBJ_msg_fix_gauge_justline;  // offset: 0x978
    cGUIObjTexture* mpOBJ_msg_fix_gauge_just;  // offset: 0x980
    cGUIInstNull* mpINST_Null_arrow;  // offset: 0x988
    cGUIInstNull* mpINST_Null_guide;  // offset: 0x990
    cGUIInstAnimation* mpINST_msg_guide;  // offset: 0x998
    uGUIBase::cReferenceUIBtnGuide mBtnGuide;  // offset: 0x9a0
    nDDOUtility::cArray<Arrowset, 3> mArrowsets;  // offset: 0xa38
    MtRectF mReloadBarSize;  // offset: 0xab0
    f32 mReloadBarStartX;  // offset: 0xac0
    f32 mReloadGaugeWidth;  // offset: 0xac4
    f32 mAlpha;  // offset: 0xac8
    nDDOUtility::cArray<uGUIBase::cReferenceUIBtnGuide::stGuideBtnData, 2> mButtonGuideDatas;  // offset: 0xad0
    bool mGaugeMouseInputMode;  // offset: 0xb20
    MtVector2 mGaugeCursorOffset;  // offset: 0xb28
    f32 mGaugeLimitLength;  // offset: 0xb30
    uGUIBase::cInputGuideMonitor mInputGuideMonitor;  // offset: 0xb34
public:
    static MyDTI DTI;
    static const u32 ARROWPLT_NUM = 3;
    static const u32 ARROW_EQUIP_INVALID = 4294967295;
    static const u32 BUTTON_GUIDE_BIT_HUNTER = 1;
    static const u32 BUTTON_GUIDE_BIT_SHIELDSAGE = 2;
};
