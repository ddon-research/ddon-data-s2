#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/MtString.h"
#include "../shared/nGUIItem.h"
#include "../shared/nKeyCustom.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;
class MtVector2;
class MtVector3;
class cDraw;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class cGUIObjTexture;
class cGUIObject;
class cItemParam;
namespace nGUIItem { class cItem; }
class rGUI;

// Declarations
class uGUIPointer;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class uGUIPointer : public uGUIBase
{
public:
    enum
    {
        DRAW_ICON_NONE = 0,
        DRAW_ICON_ITEM = 1,
        DRAW_ICON_SKILL = 2,
    };
    enum
    {
        GUIDE_HEIGHT_LOW = 0,
        GUIDE_HEIGHT_HIGH = 1,
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
    uGUIPointer();
    virtual ~uGUIPointer();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    void setPointerPos(const MtVector2& pos, s32 frame);
    void interruptPos(const MtVector2& pos);
    void hideReq(u32 uPrio);
    void hide();
    void pickItemCommon(u32 uPrio);
    void pickItem(u32 item_id, u32 uPrio);
    void pickItem(cItemParam* pParam, u32 uPrio);
    void pickItem(const nGUIItem::cItem& item);
    void releaseItem();
    const nGUIItem::cItem& getItem();
    void pickSkill(u32 skill_id, u32 type, u32 lv, u32 uPrio);
    void setGuide(MT_CTSTR msg, u32 uPrio, nKeyCustom::KB_CUSTOM keyCustom);
    void setGuideMsg(MT_CTSTR msg, u32 height_type, nKeyCustom::KB_CUSTOM keyCustom, bool isForceDraw);
    void setGuideSize(f32 size);
    void hideGuide();
    void clearGuideMsg();
    void updateGuideMsg(u32 uPrio);
    void setPosRequest(const MtVector2& pos, u32 uPrio, u32 uUnitPrioGrp, const MtVector2& popTarget);
    void setPopTarget(const MtVector2& popTarget, u32 uPrio);
    void setPopCmdPrio(u32 uPrio);
    bool isEnablePosPopCmd();
    void setupPosFromReq();
    void setVisibleIcon(bool b);
    MtVector3 getPosPopCmd();
    MtVector2 getRequestPosPrev();
protected:
    virtual void adjustScale();  // vtable slot 84
public:
    virtual bool isForceSamplerLinear(cGUIObject* pObj) const;  // vtable slot 46
private:
    void updateInit();
    void updateWait();
    void updateExit();
    void setObjVisible(cGUIObject*, bool);
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    u32 mPrioGrp;  // offset: 0x8d0
    cGUIInstNull* mpInstNullPointer;  // offset: 0x8d8
    cGUIInstNull* mpInstNullGuide;  // offset: 0x8e0
    cGUIInstNull* mpInstNullItemIcon;  // offset: 0x8e8
    cGUIInstNull* mpInstNullSkillIcon;  // offset: 0x8f0
    cGUIInstNull* mpInstNullPopCmd;  // offset: 0x8f8
    cGUIInstAnimation* mpInstAnimFinger;  // offset: 0x900
    cGUIInstAnimation* mpInstAnimGuide;  // offset: 0x908
    cGUIObjMessage* mpObjMsgGuide;  // offset: 0x910
    cGUIObjMessage* mpObjMsgGuideButton;  // offset: 0x918
    cGUIObjTexture* mpObjTexGuideBaseLeft;  // offset: 0x920
    cGUIObjTexture* mpObjTexGuideBaseCenter;  // offset: 0x928
    cGUIObjTexture* mpObjTexGuideBaseRight;  // offset: 0x930
    uGUIBase::cReferenceUIIconItem mIcon;  // offset: 0x940
    nGUIItem::cItem mItemData;  // offset: 0xac0
    bool mIsCatch;  // offset: 0xb20
    uGUIBase::cReferenceUIIconSkill mSkillIcon;  // offset: 0xb28
    uGUIBase::cCalcMovePos mPos;  // offset: 0xbe8
    MtVector2 mBasePos;  // offset: 0xc08
    MtVector2 mOffset;  // offset: 0xc10
    f32 mHideTimer;  // offset: 0xc18
    u32 mRequestUnitPrioGrp;  // offset: 0xc1c
    MtVector2 mRequestPos;  // offset: 0xc20
    MtVector2 mRequestPosPrev;  // offset: 0xc28
    MtVector2 mPopCmdTarget;  // offset: 0xc30
    u32 mRequestPrio;  // offset: 0xc38
    u32 mRequestHidePrio;  // offset: 0xc3c
    u32 mPopCmdPrio;  // offset: 0xc40
    u32 mPopTargetPrio;  // offset: 0xc44
    u32 mRequestIconPrio;  // offset: 0xc48
    u8 mDrawIconFlag;  // offset: 0xc4c
    u32 mRequestGuidePrio;  // offset: 0xc50
    bool mIsDrawGuide;  // offset: 0xc54
    bool mIsForceDrawGuide;  // offset: 0xc55
    MtString mGuideMsg;  // offset: 0xc58
    MtString mUpdateGuideMsg;  // offset: 0xc60
    nKeyCustom::KB_CUSTOM mGuideKeyCustom;  // offset: 0xc68
    nKeyCustom::KB_CUSTOM mUpdateGuideKeyCustom;  // offset: 0xc6c
    f32 mGuideMsgHeight;  // offset: 0xc70
    f32 mGuideMsgHeightDefault;  // offset: 0xc74
    f32 mGuideMsgHeightHigh;  // offset: 0xc78
public:
    static MyDTI DTI;
    static const s32 move_frame_immediate = 0;
    static const s32 move_frame_fast = 2;
    static const s32 move_frame_slow = 4;
    static const s32 hide_time = 1;
};
