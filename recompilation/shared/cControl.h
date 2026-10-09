#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "MtString.h"
#include "nGUIExt.h"
#include "nKeyCustom.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtString;
class cGUIInstance;
class cGUIObject;
namespace nInputTextKeyboardHook { struct Keycode; }
class uGUIAreaMaster;
class uGUIBase;
class uGUICaplinkChat;
class uGUICaplinkFriendList;
class uGUICaplinkTalk;
class uGUICaplinkTopMenu;
class uGUIChat;
class uGUIDialogTextBox;
class uGUIGiveAndTake;
class uGUILoginBonus;
class uGUINewspaper;
class uGUIOption;
class uGUIPhotoAlbum;

// Declarations
class cControl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cControl : public MtObject
{
    // inferred: uGUIAreaMaster::eventAdjustTab names cControl::mCurrentPos
    friend class uGUIAreaMaster;
    // inferred: uGUICaplinkChat::evCtrlDecide names cControl::mCurrentPos
    friend class uGUICaplinkChat;
    // inferred: uGUICaplinkFriendList::eventAdjustTab names cControl::mCurrentPos
    friend class uGUICaplinkFriendList;
    // inferred: uGUICaplinkTalk::eventDecide names cControl::mCurrentPos
    friend class uGUICaplinkTalk;
    // inferred: uGUICaplinkTopMenu::eventDecide names cControl::mCurrentPos
    friend class uGUICaplinkTopMenu;
    // inferred: uGUIChat::evCtrlMenuMoveV names cControl::mCurrentPos
    friend class uGUIChat;
    // inferred: uGUIDialogTextBox::moveInput names cControl::mCurrentPos
    friend class uGUIDialogTextBox;
    // inferred: uGUIGiveAndTake::setupCtrl names cControl::mCtrlF
    friend class uGUIGiveAndTake;
    // inferred: uGUILoginBonus::updateWait names cControl::mCurrentPos
    friend class uGUILoginBonus;
    // inferred: uGUINewspaper::evCtrlEventCursorDecide names cControl::mCurrentPos
    friend class uGUINewspaper;
    // inferred: uGUIOption::evCtrlTabMove names cControl::mItemNum
    friend class uGUIOption;
    // inferred: uGUIPhotoAlbum::evCtrlMouse names cControl::mCurrentPos
    friend class uGUIPhotoAlbum;
public:
    enum
    {
        KONF_NONE = 0,
        KONF_ON = 1,
        KONF_TRG = 2,
        KONF_REP = 4,
        KONF_MOVEKEY = 8,
    };
    enum
    {
        CTRLF_NONE = 0,
        CTRLF_REPMOVE = 1,
        CTRLF_PRLLMOVE = 2,
        CTRLF_REVERSEMOVE = 4,
        CTRLF_DISABLEKEY = 8,
        CTRLF_DISABLEMOUSE = 16,
        CTRLF_LOCK = 32,
        CTRLF_EXECKBINPUT = 64,
        CTRLF_EXECNUMBOXEDIT = 128,
        CTRLF_EXECSOFTKEYBOARD = 256,
    };
    enum
    {
        RET_CONTINUE = 0,
        RET_SKIP = 1,
        RET_FREE = 2,
    };
public:
    class MyDTI;
    struct Message;
    class cMouseExecution;
    struct BUTTON_INFO;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct Message : public MtObject
    {
    public:
        nGUIExt::MSG_REASON reason;  // offset: 0x8
        u32 flags;  // offset: 0xc
        s32 current;  // offset: 0x10
        s32 old;  // offset: 0x14
        s32 mouse_hit_id;  // offset: 0x18
        cControl* pSender;  // offset: 0x20
        void* pData;  // offset: 0x28
        u32 changeSE;  // offset: 0x30
        s32 click_vol;  // offset: 0x34
    };
public:
    class cMouseExecution : public MtObject
    {
    public:
        class MyDTI;
        class cMouseTouchInfo;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class cMouseTouchInfo : public MtObject
        {
        public:
            enum
            {
                MTIF_NONE = 0,
                MTIF_DISABLE = 1,
                MTIF_TCHILD = 2,
                MTIF_INMASK = 4,
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
            cMouseTouchInfo();
            // Address: 0x01963390 - 0x01963391 (1 bytes)
            virtual ~cMouseTouchInfo() {}
        public:
            u32 mFlg;  // offset: 0x8
            cGUIInstance* mpInstMT;  // offset: 0x10
            cGUIObject* mpObjMT;  // offset: 0x18
            cGUIObject* mpObjMO;  // offset: 0x20
            cGUIInstance* mpInstMask;  // offset: 0x28
            cGUIObject* mpObjMask;  // offset: 0x30
            s32 mPos;  // offset: 0x38
            u32 mMOType;  // offset: 0x3c
            u32 mAnmType;  // offset: 0x40
            nGUIExt::MSG_REASON msgMT;  // offset: 0x44
            s32 mClickVol;  // offset: 0x48
            MtObject* mpData;  // offset: 0x50
            u32 mLimitedReasonFlags;  // offset: 0x58
            static MyDTI DTI;
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
        cMouseExecution();
        virtual ~cMouseExecution();
        void move();
        void setParentCtrl(cControl* pParentCtrl);
        void clear();
        void sort();
        const cMouseTouchInfo* getMouseOverInfo() const;
        void clearFlag();
    public:
        cControl* mpParentCtrl;  // offset: 0x8
        MtTypedArray<cMouseTouchInfo> mMTI;  // offset: 0x10
        u32 mMouseOverIndex;  // offset: 0x30
        bool mIsMouseOver;  // offset: 0x34
        bool mIsOOMT;  // offset: 0x35
        static MyDTI DTI;
        static const u32 INVALID_IDX = 4294967295;
    };
public:
    struct BUTTON_INFO
    {
    public:
        BUTTON_INFO(u32& _uKeyOnF, s32& _sAddPos, bool& _bSendMsg);
    public:
        u32& uKeyOnF;  // offset: 0x0
        s32& sAddPos;  // offset: 0x8
        bool& bSendMsg;  // offset: 0x10
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
    static bool IsSameKeycode(const nInputTextKeyboardHook::Keycode& keycode, nKeyCustom::KB_CUSTOM kbCustom);
    static bool IsTrigger(nGUIExt::MSG_REASON msgReason);
    static bool IsRepeat(nGUIExt::MSG_REASON msgReason);
    void resetMessageEvent();
    void setEnableMsgEv(nGUIExt::MSG_REASON, bool);
    bool isEnableMsgEv(nGUIExt::MSG_REASON mr) const;
    void setSpdUpChkCnt(u32);
    u32 getSpdUpChkCnt();
    void setSpdUpChk(u32 uValue);
    u32 getSpdUpChk();
    void setSpdUpAdd(s32);
    s32 getSpdUpAdd();
    void setSpdUpAddAdd(s32 sValue);
    s32 getSpdUpAddAdd();
    void setSpdUpAddMax(s32 sValue);
    s32 getSpdUpAddMax();
    virtual void updateButton(nGUIExt::MSG_REASON Reason, BUTTON_INFO bt);  // vtable slot 6
    virtual void checkLoop(u32 uKeyOnF, s32 sMoveDir, nGUIExt::MSG_REASON Reason, s32& sAddPos);  // vtable slot 7
    bool isOnKeyLeft();
    bool isOnKeyRight();
    bool isOnKeyUp();
    bool isOnKeyDown();
    void setCheckKeyExtend();
    bool isExecuteMsgEvent();
    bool isSetKeyInfo(nGUIExt::MSG_REASON Reason);
    bool isSetKeyInfo();
    virtual bool isTabType() const;  // vtable slot 8
    virtual s32 getInputDirection(nGUIExt::MSG_REASON Reason) const;  // vtable slot 9
private:
    void sendMessage(nGUIExt::MSG_REASON reason, u32 flags, s32 current, s32 old, s32 mouse_hit_id, s32 click_vol);
    bool moveKey(nGUIExt::MSG_REASON reason);
    void moveKey();
    void moveKeyQueue();
    void moveChild();
    void moveChildCore(cControl* pChild);
    u32 moveMessageEvent(Message* pMsg);
    bool setkeyinfo(nGUIExt::MSG_REASON Reason, u32 Keyon);
    bool isOnKey(u32 Btn);
    Message* dispatchMessage();
    u32 checkKeyOn(nGUIExt::MSG_REASON msg);
    void purgeMessage();
    bool isParentInputActive();
public:
    u32 addMouseTouchList(cGUIInstance* pInst, s32 sPos, cGUIObject* pObjMO, u32 uAnmType);
    u32 addMouseTouchList(cGUIInstance* pInst, s32 sPos, u32 uMOType, u32 uAnmType);
    u32 addMouseTouchList(cGUIInstance* pInst, cGUIObject* pObj, s32 sPos, cGUIObject* pObjMO, u32 uMOType, u32 uAnmType, s32 sClickVol);
    u32 addMouseTouchListLight(cGUIInstance* pInstHit, cGUIObject* pObjHit, s32 sPos, s32 sClickVol);
    u32 getMouseTouchListLength();
    void clearMouseTouchList();
    void eraseMouseTouchList(s32 sPos);
    void eraseMouseTouchListVol(s32 sClickVol);
    void eraseMouseTouchListPosVol(s32 sPos, s32 sClickVol);
    void setMouseTouchListPos(u32 uIdx, s32 sPos);
    void setMouseTouchListPos(cGUIInstance* pInstSearch, s32 sPos);
    void setMouseTouchListPos(cGUIObject* pObjSearch, s32 sPos);
    void setMouseTouchListFlg(u32 uIdx, u32 uFlag);
    void orMouseTouchListFlg(u32 uIdx, u32 uFlag);
    void xorMouseTouchListFlg(u32, u32);
    void clrMouseTouchListFlg(u32 uIdx, u32 uFlag);
    bool isMouseTouchListFlg(u32, u32);
    u32 getMouseTouchListFlg(u32);
    void setMouseTouchListMask(u32 uIdx, cGUIObject* pObjMask);
    void setMouseTouchListMask(u32 uIdx, cGUIInstance* pInstMask);
    bool isMouseOver() const;
    s32 getMouseOverPos() const;
    s32 getMouseOverClickVol() const;
    void clearMouseExecFlag();
    static u32 MOUSE_REASON_FLAG(nGUIExt::MSG_REASON mr);
    void setMouseTouchListLimitedReason(u32 uIdx, u32 limitedReasonFlags);
    void setMouseTouchListData(u32 uIdx, MtObject* pData);
    static bool MACRO_REASONCHK(nGUIExt::MSG_REASON);
    virtual void setUsePresetSE(bool bUse);  // vtable slot 10
    virtual void setPresetSE(u32 uIdx, u32 uSEId);  // vtable slot 11
    u32 getPresetSEId(nGUIExt::MSG_REASON reason) const;
    virtual void reqPresetSE(Message* pMsg);  // vtable slot 12
    virtual void reqPresetSE(nGUIExt::MSG_REASON reason);  // vtable slot 13
    bool isCanUsePresetSE(Message* pMsg);
    virtual bool execute();  // vtable slot 14
    bool isExecuteEnable();
    bool isPadMove();
    bool isMouseMove();
    virtual void setFocus(bool flag);  // vtable slot 15
    bool getFocus();
    bool isLoop();
    virtual void setLoop(bool flag);  // vtable slot 16
    bool isTrgLoop();
    virtual void setTrgLoop(bool flag);  // vtable slot 17
    void setNoMoveNoEvent();
    void setMovePosAuto(bool);
    void setMovePosMW(bool);
    bool isMovePosMW();
    virtual void setCurrentPos(s32 sPos, bool bDisableLoop);  // vtable slot 18
    s32 getItemNum() const;
    u32 resetItemNum(s32 num, const u32* tags, s32 pos);
    virtual void setParent(cControl* parent, s32 bind_pos);  // vtable slot 19
    s32 getCurrentPos() const;
    void setParent(uGUIBase* parent);
    uGUIBase* getParent() const;
    cControl* getNext();
    bool isLeftLimit();
    bool isRightLimit();
    bool isTopLimit();
    bool isBottomLimit();
    bool isLeftLimitForLoop();
    bool isRightLimitForLoop();
    bool isTopLimitForLoop();
    bool isBottomLimitForLoop();
    void setDebugMode(bool);
    u32 getTag(s32) const;
    u32 getCurrentTag() const;
    u32 getOldTag() const;
    s32 getOldPos() const;
    bool isDiifPos();
    void setSingleInputMode(bool flag);
    s32 getBindPos() const;
    virtual f32 getRatioMultiLine(s32 DispRange) const;  // vtable slot 20
    virtual f32 getRatio() const;  // vtable slot 21
    s32 getDetailPos() const;
    void setEnableLimitLeft(bool);
    void setCtrlF(u32 uFlag);
    void orCtrlF(u32 uFlag);
    void xorCtrlF(u32);
    void clrCtrlF(u32 uFlag);
    bool isCtrlF(u32 uFlag);
    u32 getCtrlF();
    void setName(MT_CTSTR name);
    MT_CTSTR getName();
    cControl(s32 num, const u32* tags, s32 visible);
    virtual ~cControl();
protected:
    void setFocusSub(bool flag);
    bool isEnableLimitLeft() const;
private:
    u32(MtObject::*messageEvent[46])(Message*);  // offset: 0x8
    u32(MtObject::*messageEventOOMT[46])(Message*);  // offset: 0x2e8
    void* mpMessageEventData[46];  // offset: 0x5c8
    void* mpMessageEventDataOOMT[46];  // offset: 0x738
    Message mMessageQueue[8];  // offset: 0x8a8
    s32 mQueueWriteIndex;  // offset: 0xa68
    s32 mQueueReadIndex;  // offset: 0xa6c
    u8 mKeyInfoBuff[34];  // offset: 0xa70
    s32 mCheckKeyNum;  // offset: 0xa94
    u32 mSpdUpChkCnt;  // offset: 0xa98
    u32 mSpdUpChk;  // offset: 0xa9c
    s32 mSpdUpAdd;  // offset: 0xaa0
    s32 mSpdUpAddAdd;  // offset: 0xaa4
    s32 mSpdUpAddMax;  // offset: 0xaa8
    bool mAutoDispatch;  // offset: 0xaac
    bool mDebugMode;  // offset: 0xaad
    bool mIsEnableMsgEv[46];  // offset: 0xaae
    bool mIsExecuteMsgEvent;  // offset: 0xadc
    bool mIsSetNoMoveEvent;  // offset: 0xadd
public:
    cMouseExecution mMouseExec;  // offset: 0xae0
protected:
    bool mUsePresetSE;  // offset: 0xb18
    u32 mTblPresetSE[50];  // offset: 0xb1c
    bool mIsEnableLimitLeft;  // offset: 0xbe4
    bool mFocus;  // offset: 0xbe5
    bool mSingleInputMode;  // offset: 0xbe6
    bool mEnableLoop;  // offset: 0xbe7
    bool mEnableTrgLoop;  // offset: 0xbe8
    bool mMovePosAuto;  // offset: 0xbe9
    bool mMovePosMW;  // offset: 0xbea
    cControl* mpParent;  // offset: 0xbf0
    cControl* mpChild;  // offset: 0xbf8
    cControl* mpNext;  // offset: 0xc00
    s32 mBindPos;  // offset: 0xc08
    uGUIBase* mpParentGUI;  // offset: 0xc10
    s32 mCurrentPos;  // offset: 0xc18
    s32 mOldPos;  // offset: 0xc1c
    s32 mReserveAddPos;  // offset: 0xc20
    u32 mReserveAddKey;  // offset: 0xc24
    s32 mReserveMousePos;  // offset: 0xc28
    u32* mTags;  // offset: 0xc30
    s32 mItemNum;  // offset: 0xc38
    u32 mCtrlF;  // offset: 0xc3c
    MtString mName;  // offset: 0xc40
public:
    static MyDTI DTI;
    static const u32 BTN_NUM = 17;
    static const u32 BTN_NUM_EXT = 21;
    static const u32 KB_NUM = 12;
    static const u32 QUEUE_MAX = 8;
    static const u32 INVALID_SEID = 0;
    static const u32 DEFAULT_SEID = 4294967295;
    static const u32 HOLDFRAMEMAX_DEFAULT = 15;
    static const u32 INVALID_SE_NO = 4294967295;
    static const nKeyCustom::KB_CUSTOM tblBtn[21];
    static const nKeyCustom::KB_CUSTOM tblKey[12];
};

// Inline, no code of its own: checked where it is inlined.
inline bool cControl::isExecuteMsgEvent() {
    return this->mIsExecuteMsgEvent;
}

// Inline, no code of its own: checked where it is inlined.
inline bool cControl::getFocus() {
    return this->mFocus;
}

// Inline, no code of its own: checked where it is inlined.
inline s32 cControl::getItemNum() const {
    return this->mItemNum;
}

// Inline, no code of its own: checked where it is inlined.
inline s32 cControl::getCurrentPos() const {
    return this->mCurrentPos;
}

// Inline, no code of its own: checked where it is inlined.
inline s32 cControl::getOldPos() const {
    return this->mOldPos;
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline s32 cControl::getBindPos() const {
    return this->mBindPos;
}
