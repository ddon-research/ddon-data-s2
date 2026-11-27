#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtString.h"
#include "cControl.h"
#include "cGUIControlMgr.h"
#include "nDDOUtility.h"
#include "nNet.h"
#include "uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cGUIControlMgr;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class cGUIObjTexture;
namespace nNet { struct stFeedbackData; }
class rGUI;
class uUIMockUp;

// Declarations
class uGUIPawnReview;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class uGUIPawnReview : public uGUIBase
{
public:
    enum POS_V
    {
        POS_V_FEEDBACK_START = 0,
        POS_V_FEEDBACK_END = 2,
        POS_V_BUTTON = 3,
        POS_V_NUM = 4,
    };
    enum CONTROL_ID
    {
        CONTROL_V = 0,
        CONTROL_BUTTON = 1,
        CONTROL_NUM = 2,
    };
    enum CONTROL_CATEGORY
    {
        CONTROL_CATEGORY_DEFAULT = 0,
    };
    enum BUTTON_ID
    {
        BUTTON_ID_DECIDE = 0,
        BUTTON_ID_CANCEL = 1,
        BUTTON_NUM = 2,
    };
    enum INPUTEVENT
    {
        INPUTEVENT_MOVE = 66,
        INPUTEVENT_DECIDE = 67,
    };
public:
    class MyDTI;
    struct PawnParam;
    struct PawnFeedbackParam;
    struct FeedbackItem;
    struct DATA;
public:
    using FeedbackItems = nDDOUtility::cArray<uGUIPawnReview::FeedbackItem, 3>;
    using EditButtons = nDDOUtility::cArray<uGUIBase::cReferenceUIEditBtn, 3>;
    using Buttons = nDDOUtility::cArray<uGUIBase::cReferenceUIButton, 2>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct PawnFeedbackParam
    {
    public:
        u8 mStarNum;  // offset: 0x0
        u8 mCommentNo;  // offset: 0x1
        u8 mCount;  // offset: 0x2
        u8 mCountMax;  // offset: 0x3
    };
public:
    struct FeedbackItem
    {
    public:
        FeedbackItem();
    public:
        cGUIInstNull* mpINST_Null_reviewlist;  // offset: 0x0
        cGUIInstAnimation* mpINST_fix_star;  // offset: 0x8
        nDDOUtility::cArray<cGUIObjTexture*, 5> mpOBJ_fix_star_f_stars;  // offset: 0x10
        cGUIObjMessage* mpOBJ_msg_review_m_review;  // offset: 0x38
        cGUIObjMessage* mpOBJ_msg_review_m_header;  // offset: 0x40
        cGUIObjMessage* mpOBJ_msg_review_m_use;  // offset: 0x48
        cGUIObjMessage* mpOBJ_msg_review_m_num;  // offset: 0x50
    };
public:
    struct DATA
    {
    public:
        cGUIInstNull* mpINST_Null;  // offset: 0x0
        cGUIInstNull* mpINST_Null_all;  // offset: 0x8
        cGUIInstAnimation* mpINST_msg_loadicon_root;  // offset: 0x10
        cGUIInstAnimation* mpINST_msg_loadicon;  // offset: 0x18
        cGUIObjMessage* mpOBJ_msg_top_m_top00;  // offset: 0x20
        cGUIObjMessage* mpOBJ_msg_top_m_top01;  // offset: 0x28
        cGUIObjMessage* mpOBJ_msg_prof_m_name;  // offset: 0x30
        cGUIObjMessage* mpOBJ_msg_prof_m_lv00;  // offset: 0x38
        cGUIObjMessage* mpOBJ_msg_prof_m_num00;  // offset: 0x40
        cGUIObjMessage* mpOBJ_msg_prof_m_lv01;  // offset: 0x48
        cGUIObjMessage* mpOBJ_msg_prof_m_num01;  // offset: 0x50
    };
public:
    struct PawnParam
    {
    public:
        MtStringEx<13> mName;  // offset: 0x0
        u8 mJobId;  // offset: 0x14
        u32 mJobLv;  // offset: 0x18
        u32 mCraftRank;  // offset: 0x1c
        uGUIPawnReview::PawnFeedbackParam mFeedbackParams[3];  // offset: 0x20
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
    uGUIPawnReview();
    virtual ~uGUIPawnReview();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    virtual void updatePtr();  // vtable slot 17
    virtual s32 getSMenuCursorY();  // vtable slot 72
    bool show();
    void updateFeedback(nNet::FEEDBACK_TYPE feedbackType, const nNet::stFeedbackData* feedbackData);
private:
    void updateInit();
    void updateWait();
    void updateExit();
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void setupControls();
    void updateFocus();
    u32 evCtrlMoveFocus(cControl::Message* msg);
    void evMoveFocus();
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    void initMockUp();
    void setupMockUp();
    void updateMockUp();
    void applyPawnParam();
    void feedbackItemSetup();
    void feedbackItemSetStarNum(u8 feedbackType, u8 starNum);
    void feedbackItemSetComment(u8 feedbackType, u8 starNum, u8 commentNo);
    void feedbackItemSetCount(u8 feedbackType, u8 count, u8 countMax);
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    cGUIControlMgr mControlMgr;  // offset: 0x8d0
    nDDOUtility::cArray<POS_V, 4> mValidPosVs;  // offset: 0xd80
    s32 mValidPosVNum;  // offset: 0xd90
    PawnParam mPawnParam;  // offset: 0xd94
    uUIMockUp* mpMockUp;  // offset: 0xdc0
    uGUIBase::cReferenceUIIconJob mIconJob;  // offset: 0xdc8
    FeedbackItems mFeedbackItems;  // offset: 0xe20
    EditButtons mEditButtons;  // offset: 0xf28
    Buttons mButtons;  // offset: 0x1018
    uGUIBase::cReferenceUICloseBtn mCloseButton;  // offset: 0x1338
    DATA mData;  // offset: 0x1390
    bool mIsSetup;  // offset: 0x13e8
public:
    static MyDTI DTI;
    static const u8 STAR_NUM_EMPTY = 0;
    static const u8 STAR_NUM_INVALID = 255;
};

inline void* uGUIPawnReview::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../XFramework/cGUIInstance.h"
#include "uUIMockUp.h"

inline void uGUIPawnReview::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIPawnReview::DTI)->memFree(p_addr);
}

inline void uGUIPawnReview::setupMockUp() {
    if (this->mpMockUp == nullptr) {
        return;
    }
    this->mpMockUp->::uUIMockUp::setupPawnModel();
    this->mpMockUp->::uUIMockUp::setDisp(false);
}

inline void uGUIPawnReview::updateMockUp() {
    if (this->mData.mpINST_msg_loadicon_root == nullptr) {
        return;
    }
    if ((this->mData.mpINST_msg_loadicon_root->::cGUIInstance::mAttr & 1u) == 0) {
        return;
    }
    if (this->mpMockUp == nullptr) {
        return;
    }
    if (!this->mpMockUp->::uUIMockUp::isComplete()) {
        return;
    }
    this->mpMockUp->::uUIMockUp::setDisp(true);
    if (this->mData.mpINST_msg_loadicon_root == nullptr) {
        return;
    }
    this->mData.mpINST_msg_loadicon_root->::cGUIInstance::setVisible(false);
}
