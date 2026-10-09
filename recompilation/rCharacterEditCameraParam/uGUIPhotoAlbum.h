#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/MtObject.h"
#include "../shared/cControl.h"
#include "../shared/uGUIBase.h"
#include "uGUIsMenuBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector2;
class cControl;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIInstance;
class cGUIObjMessage;
class cGUIObjPolygon;
class cGUIObjTexture;
class cGUIObjTextureRef;
class cGUIObject;
class rGUI;
class rGUIMessage;
class uGUIPhotoUpload;
class uGUISystemMsg;

// Declarations
class uGUIPhotoAlbum;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIPhotoAlbum : public uGUIsMenuBase
{
public:
    enum PR_UPLOAD
    {
        PR_UPLOAD_INIT = 0,
        PR_UPLOAD_WAIT = 1,
    };
    enum ALBUM_MODE
    {
        VIEW_MODE = 0,
        UPLOAD_MODE = 1,
        MODE_MAX = 2,
    };
    enum
    {
        SELECT_NONE = 0,
        SELECT_DECIDE = 1,
        SELECT_CANCEL = 2,
    };
    enum
    {
        CATE_FULL_SCREEN = 0,
        CATE_UPLOAD = 1,
        CATE_NUM = 2,
    };
    enum
    {
        INPUTEVENT_DECIDE = 66,
        INPUTEVENT_CANCEL = 67,
        INPUTEVENT_ADJUST_CURSOR = 68,
        INPUTEVENT_ADJUST_SIDE_CURSOR = 69,
        INPUTEVENT_START_BTN = 70,
    };
public:
    class MyDTI;
    class cItem;
    struct stAlbum;
    struct stFull;
    struct stCategoryList;
    struct stCategory;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cItem : public MtObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR, MtDTI*, size_t, u32, u32);
        };
    public:
        static MtDTI* getMyDTIPtr();
        virtual const MtDTI& getDTI() const;  // vtable slot 5
        static MtAllocator* getAllocator();
        static void setAllocator(u32);
        static void operator delete(void*);
        cItem();
    public:
        uGUIBase::cDupliInstNull mInst;  // offset: 0x8
        uGUIBase::cReferenceUIIconItem mRefItem;  // offset: 0x30
        static MyDTI DTI;
    };
public:
    struct stAlbum
    {
    public:
        stAlbum();
    public:
        cGUIInstance* mpInstWindowFrame;  // offset: 0x0
        cGUIInstAnimation* mpInstAnmTitle;  // offset: 0x8
        cGUIInstAnimation* mpInstAnmSavelimit;  // offset: 0x10
        cGUIInstAnimation* mpInstAnmDate;  // offset: 0x18
        cGUIInstAnimation* mpInstAnmSamnail;  // offset: 0x20
        cGUIInstAnimation* mpInstAnmPhotoBase;  // offset: 0x28
        cGUIInstAnimation* mpInstAnmHead;  // offset: 0x30
        cGUIObjMessage* mpObjMsgTitle00;  // offset: 0x38
        cGUIObjMessage* mpObjMsgTitle01;  // offset: 0x40
        cGUIObjMessage* mpObjMsgSaveTitle;  // offset: 0x48
        cGUIObjMessage* mpObjMsgSaveSlash;  // offset: 0x50
        cGUIObjMessage* mpObjMsgSaveNum;  // offset: 0x58
        cGUIObjMessage* mpObjMsgSaveMax;  // offset: 0x60
        cGUIObjMessage* mpObjMsgDateDate;  // offset: 0x68
        cGUIObjMessage* mpObjMsgDateTime;  // offset: 0x70
        cGUIObjMessage* mpObjMsgHeadTitle;  // offset: 0x78
        cGUIObjTextureRef* mpObjTexRefSamnail;  // offset: 0x80
        cGUIObjPolygon* mpObjPolyPhotoBase;  // offset: 0x88
        uGUIBase::cReferenceUINumPager mNumPageBtn;  // offset: 0x90
        uGUIBase::cReferenceUICloseBtn mClose;  // offset: 0x138
    };
public:
    struct stFull
    {
    public:
        stFull();
    public:
        cGUIInstNull* mpInstNullRightbottom;  // offset: 0x0
        cGUIInstNull* mpInstNullLefttop;  // offset: 0x8
        cGUIInstAnimation* mpInstAnmTitle;  // offset: 0x10
        cGUIInstAnimation* mpInstAnmSamnailFull;  // offset: 0x18
        cGUIInstAnimation* mpInstAnmGuideBtn;  // offset: 0x20
        cGUIObjMessage* mpObjMsgTitle00;  // offset: 0x28
        cGUIObjMessage* mpObjMsgTitle01;  // offset: 0x30
        cGUIObjMessage* mpObjMsgNumpagerNum;  // offset: 0x38
        cGUIObjTextureRef* mpObjTexRefSamnailFull;  // offset: 0x40
        uGUIBase::cReferenceUINumPager mNumPageBtn;  // offset: 0x48
        uGUIBase::cReferenceUIBtnGuide mBtnGuide;  // offset: 0xf0
    };
public:
    struct stCategory
    {
    public:
        stCategory();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstAnimation* mpInstAnm;  // offset: 0x8
        cGUIObjTexture* mpObjTex;  // offset: 0x10
        cGUIObjMessage* mpObjMsg;  // offset: 0x18
    };
public:
    struct stCategoryList
    {
    public:
        stCategoryList();
    public:
        uGUIPhotoAlbum::stCategory mCate[2];  // offset: 0x0
        uGUIBase::cReferenceUIVlCursor mCursor;  // offset: 0x40
        MtVector2 mCursorOffset;  // offset: 0xf0
        bool mEnable[2];  // offset: 0xf8
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
    uGUIPhotoAlbum();
    virtual ~uGUIPhotoAlbum();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    bool isDecide();
    bool isCancel();
    void clearButton();
private:
    virtual void updatePtr();  // vtable slot 17
    virtual void updateInit();  // vtable slot 93
    void updateWait();
    void updateUpload();
    void updateExit();
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void init();
    void selectFlow(u32 flowID);
    bool changePhoto();
    void updateAlpha();
    void changeCategoryEnable();
    void evDecide();
    void evCancel();
    void evStart();
    void evAdjustCursor();
    void adjustCategory();
    void evAdjustSideCursor();
    void adjustPage();
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlStart(cControl::Message* msg);
    u32 evCtrlAdjustCursor(cControl::Message* msg);
    u32 evCtrlAdjustSideCursor(cControl::Message* msg);
    u32 evCtrlMouse(cControl::Message* msg);
    s32 getCtrlPos(cControl* pCtrl);
    bool updateSysMsg();
protected:
    virtual void adjustScale();  // vtable slot 84
public:
    virtual bool isForceSamplerLinear(cGUIObject* pObj) const;  // vtable slot 46
private:
    MtTypedArray<cItem> mItemArray;  // offset: 0x958
    rGUI* mpGUIRes;  // offset: 0x978
    rGUIMessage* mpGMDRes;  // offset: 0x980
    cGUIInstNull* mpInstNull;  // offset: 0x988
    cGUIInstNull* mpInstNullAlbum;  // offset: 0x990
    cGUIInstNull* mpInstNullRBottom;  // offset: 0x998
    cGUIInstNull* mpInstNullLTop;  // offset: 0x9a0
    uGUISystemMsg* mpGUISystemMsg;  // offset: 0x9a8
    uGUIPhotoUpload* mpGUIPhotoUpload;  // offset: 0x9b0
    cControl* mpButtonCtrl;  // offset: 0x9b8
    uGUIBase::cVerticalList* mpVCtrl;  // offset: 0x9c0
    uGUIBase::cHorizontalList* mpHCtrl;  // offset: 0x9c8
    PR_UPLOAD mUploadProc;  // offset: 0x9d0
    stAlbum mAlbum;  // offset: 0x9d8
    stFull mFull;  // offset: 0xb68
    stCategoryList mCateList;  // offset: 0xcf0
    ALBUM_MODE mAlbumMode;  // offset: 0xdf0
    u32 mFlowId;  // offset: 0xdf4
    u32 mSelectResult;  // offset: 0xdf8
    s32 mMaxPage;  // offset: 0xdfc
    bool mbChangePhoto;  // offset: 0xe00
    bool mbSuccessRead;  // offset: 0xe01
    bool mbSetupPhoto;  // offset: 0xe02
    f32 mTimer;  // offset: 0xe04
    f32 mAlpha;  // offset: 0xe08
    bool mIsDisp;  // offset: 0xe0c
public:
    static MyDTI DTI;
};
