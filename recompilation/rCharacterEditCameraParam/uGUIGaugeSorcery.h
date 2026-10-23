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
class cGUIObjColorAdjust;
class cGUIObjMessage;
class cGUIObjNull;
class cGUIObjTexture;
class cGUIObjTextureSet;
class cpChantCommand;
class cpChargeCtrl;
class rGUI;

// Declarations
class uGUIGaugeSorcery;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIGaugeSorcery : public uGUIBase
{
public:
    enum STATE
    {
        STATE_NONE = 0,
        STATE_WAIT = 1,
        STATE_CHANT = 2,
        STATE_PAUSE = 3,
        STATE_SUCCESS = 4,
        STATE_TIMEOUT = 5,
        STATE_END = 6,
    };
    enum BONUS_RATE_STEP
    {
        BONUS_RATE_STEP_INIT = 0,
        BONUS_RATE_STEP_IDLE = 1,
        BONUS_RATE_STEP_CHANGE = 2,
        BONUS_RATE_STEP_FIX = 3,
    };
public:
    class MyDTI;
    struct stPoint;
public:
    using FontTexObjs = nDDOUtility::cArray<cGUIObjTexture*, 3>;
    using Points = nDDOUtility::cArray<uGUIGaugeSorcery::stPoint, 32>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stPoint
    {
    public:
        cGUIInstNull* mpINST_Null;  // offset: 0x0
        cGUIInstAnimation* mpINST_point;  // offset: 0x8
        cGUIObjColorAdjust* mpOBJ_point_ColorAdjust00;  // offset: 0x10
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
    uGUIGaugeSorcery();
    virtual ~uGUIGaugeSorcery();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    virtual void updatePtr();  // vtable slot 17
    MtVector3 getGaugeMousePosition(MtVector3& pos);
    const MtVector2 getGaugeMouseChantInfo();
    bool getGaugeMouseInputMode();
    MtVector3 getGaugeCenterPos();
    MtVector2& getGaugeCursorOffset();
    void setGaugeCursorOffset(MtVector2&);
    void addGaugeCursorOffset(MtVector2& pos);
    void adjustGaugeCursorOffsetLimit();
    f32 getGaugeLimitLength();
private:
    void updateInit();
    void updateWait();
    void updateExit();
    void updateDisp(cpChargeCtrl& chargeCtrl);
    void updateDisp(cpChantCommand& chantCommand);
    static void SetFontFrame(FontTexObjs& fontTexObjs, s32 word);
    static void UpdatePoints(Points& points, s32 pointNum, s32 nowPointNo, s32 wordNo, cpChantCommand& chantCommand);
    static void RemovePoints(Points& points);
    void setBonusRateMessage(cGUIObjMessage* objMessage, f32 bonusRate);
    void updateBonusRate(cpChantCommand& chantCommand);
    void changeBonusRate(cpChantCommand& chantCommand);
    void fixBonusRate();
    void setState(STATE state);
    void setActPltType();
private:
    STATE mState;  // offset: 0x8c8
    rGUI* mpGUIRes;  // offset: 0x8d0
    cGUIInstNull* mpINST_Null;  // offset: 0x8d8
    cGUIInstNull* mpINST_Null_all;  // offset: 0x8e0
    cGUIInstNull* mpINST_Null_cursor;  // offset: 0x8e8
    cGUIInstAnimation* mpINST_cursor;  // offset: 0x8f0
    cGUIInstAnimation* mpINST_msg_fix_base;  // offset: 0x8f8
    cGUIObjMessage* mpOBJ_msg_fix_base_m_btn;  // offset: 0x900
    cGUIObjNull* mpOBJ_msg_fix_base_Null_rate;  // offset: 0x908
    cGUIObjMessage* mpOBJ_msg_fix_base_m_stock;  // offset: 0x910
    cGUIObjMessage* mpOBJ_msg_fix_base_m_stock01;  // offset: 0x918
    cGUIObjTextureSet* mpOBJ_msg_fix_base_arrow;  // offset: 0x920
    cGUIObjChildAnimationRoot* mpOBJ_msg_fix_base_fix_font;  // offset: 0x928
    FontTexObjs mFontTexObjs;  // offset: 0x930
    cGUIObjChildAnimationRoot* mpOBJ_msg_fix_base_fix_gauge;  // offset: 0x948
    cGUIObjTexture* mpOBJ_fix_gauge_f_gauge00;  // offset: 0x950
    cGUIObjTexture* mpOBJ_fix_gauge_f_gauge01;  // offset: 0x958
    cGUIInstAnimation* mpINST_ef_base;  // offset: 0x960
    cGUIObjColorAdjust* mpOBJ_ef_base_ColorAdjust;  // offset: 0x968
    Points mPoints;  // offset: 0x970
    uGUIBase::cInputGuideMonitor mInputGuideMonitor;  // offset: 0xc70
    bool mGaugeMouseInputMode;  // offset: 0xc78
    MtVector2 mGaugeCursorOffset;  // offset: 0xc80
    f32 mGaugeLimitLength;  // offset: 0xc88
    BONUS_RATE_STEP mBonusRateStep;  // offset: 0xc8c
public:
    static MyDTI DTI;
    static const u32 FONT_TEX_OBJ_NUM = 3;
};
