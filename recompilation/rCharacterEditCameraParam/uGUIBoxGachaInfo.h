#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/MtObject.h"
#include "../shared/MtString.h"
#include "../shared/cControl.h"
#include "../shared/uGUIBase.h"
#include "uGUIsMenuBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;
class MtVector2;
class MtVector4;
class cControl;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class cGUIObjNull;
class cGUIObjPolygon;
class cGUIObjTexture;
class cGUIObjTextureRef;
class rGUI;
class uGUIGPShop;
class uGUIPopDetail01;
class uGUISystemMsg;

// Declarations
class uGUIBoxGachaInfo;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using f64 = double;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIBoxGachaInfo : public uGUIsMenuBase
{
public:
    enum GACHA_BTN_FLAG
    {
        GACHA_BTN_NONE = 0,
        GACHA_BTN_BOUGHT_BOX_MAX = 1,
        GACHA_BTN_GP_NOT_ENOUGH = 2,
        GACHA_BTN_CT_NOT_ENOUGH = 4,
        GACHA_BTN_GP_NOT_LINEDUP = 8,
        GACHA_BTN_CT_NOT_LINEDUP = 16,
        GACHA_BTN_BOX_FAIL = 32,
        GACHA_BTN_BOX_FULL = 64,
        GACHA_BTN_DRAW_FAIL = 128,
        GACHA_BTN_CT_DWORD = -1,
    };
    enum
    {
        CTRL_TYPE_LIST = 0,
        CTRL_TYPE_INFO = 1,
    };
    enum PTS_GUIDE_BIT
    {
        PTS_BROWSER = 1,
        PTS_DETAIL = 2,
        PTS_BIT_MAX = 2,
    };
    enum
    {
        SELECT_NONE = 0,
        SELECT_DECIDE = 1,
        SELECT_CANCEL = 2,
        SELECT_END = 3,
    };
    enum GRADE_TYPE
    {
        GRADE_S = 0,
        GRADE_A = 1,
        GRADE_B = 2,
        GRADE_C = 3,
        GRADE_D = 4,
        GRADE_NUM = 5,
    };
    enum SETTLEMENT_TYPE
    {
        NONE_SETTLEMENT = 0,
        GP_SETTLEMENT = 1,
        CT_SETTLEMENT = 2,
        SETTLEMENT_NUM = 3,
    };
    enum
    {
        LIST_MAX = 6,
        PLAY_MAX = 3,
        PLAY_NONE = -1,
        PRICE_MAX = 3,
    };
    enum INFO_GROUP
    {
        INFO_GROUP_SUMMARY = 0,
        INFO_GROUP_ITEMLIST = 1,
        INFO_GROUP_DETAIL = 2,
        INFO_GROUP_RESULT = 3,
        INFO_GROUP_NUM = 4,
    };
    enum
    {
        SUMMARY_TRIAL = 0,
        SUMMARY_00 = 1,
        SUMMARY_01 = 2,
        SUMMARY_02 = 3,
        SUMMARY_BOX = 4,
        SUMMARY_RATE = 5,
        SUMMARY_FREE = 6,
        SUMMARY_MORE = 7,
        SUMMARY_MAX = 8,
    };
    enum BUTTON_TYPE
    {
        NONE_BUTTON = -1,
        BUY_BUTTON = 0,
        RESET_BUTTON = 1,
        BUTTON_NUM = 2,
    };
    enum
    {
        DIALOG_CONFI = 0,
        DIALOG_PLAY = 1,
        DIALOG_RESET = 2,
        DIALOG_RESETMES = 3,
        DIALOG_SHOP = 4,
        DIALOG_SETTLEMENT = 5,
    };
    enum
    {
        INPUTEVENT_DECIDE = 66,
        INPUTEVENT_CANCEL = 67,
        INPUTEVENT_ADJUST_CURSOR_H = 68,
        INPUTEVENT_ADJUST_TAB = 69,
        INPUTEVENT_START_BTN = 70,
        INPUTEVENT_UP = 71,
        INPUTEVENT_DOWN = 72,
    };
public:
    class MyDTI;
    struct stLotList;
    class cLotList;
    struct stCommon;
    struct stSummary;
    class cSumList;
    struct stGradeList;
    struct stList;
    class cListItem;
    struct stItemlistRatio;
    struct stDetail;
    class cLotInfo;
    struct stPlayType;
    class cListInfo;
    class cItemInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cLotList : public uGUIBase::cScrollListItemBase
    {
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
        cLotList();
    public:
        cGUIInstNull* mpInstNullLotlist;  // offset: 0x58
        cGUIInstAnimation* mpInstAnm;  // offset: 0x60
        cGUIObjNull* mpObjNullIcon;  // offset: 0x68
        cGUIObjTextureRef* mpObjTexRefIcon;  // offset: 0x70
        cGUIObjMessage* mpObjMsgName;  // offset: 0x78
        cGUIObjMessage* mpObjMsgComment;  // offset: 0x80
        cGUIInstAnimation* mpInstImgLoadAnm;  // offset: 0x88
        uGUIBase::cTexRefJpegDownloader mRefJpegDL;  // offset: 0x90
        static MyDTI DTI;
    };
public:
    struct stCommon
    {
    public:
        stCommon();
    public:
        cGUIInstNull* mpInstScrNull;  // offset: 0x0
        cGUIInstNull* mpInstNullTxt;  // offset: 0x8
        cGUIInstAnimation* mpInstAnmHeader;  // offset: 0x10
        cGUIObjMessage* mpObjMsgHeader;  // offset: 0x18
        cGUIObjMessage* mpObjMsgHeaderSub;  // offset: 0x20
        cGUIInstAnimation* mpInstResetBtnAnm;  // offset: 0x28
        cGUIInstAnimation* mpInstGPBtnAnm;  // offset: 0x30
        uGUIBase::cReferenceUITab mTab;  // offset: 0x40
        uGUIBase::cReferenceUIScrollBar mScrollBar;  // offset: 0xf0
        uGUIBase::cReferenceUICloseBtn mClose;  // offset: 0x198
        uGUIBase::cScrollCtrl mScrollCtrl;  // offset: 0x1f0
    };
public:
    class cSumList : public uGUIBase::cScrollListItemBase
    {
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
        cSumList();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x58
        cGUIInstAnimation* mpInstAnm;  // offset: 0x60
        cGUIInstAnimation* mpInstCaption;  // offset: 0x68
        cGUIInstNull* mpInstNullPlay;  // offset: 0x70
        cGUIInstNull* mpInstNullPlay2;  // offset: 0x78
        cGUIInstAnimation* mpInstPlayGP[3];  // offset: 0x80
        cGUIInstAnimation* mpInstPlayCT[3];  // offset: 0x98
        cGUIInstAnimation* mpInstClass[5];  // offset: 0xb0
        cGUIInstAnimation* mpInstNote1;  // offset: 0xd8
        cGUIInstAnimation* mpInstNote2;  // offset: 0xe0
        cGUIInstAnimation* mpInstFree;  // offset: 0xe8
        cGUIInstAnimation* mpInstBoxInfo;  // offset: 0xf0
        cGUIInstAnimation* mpPlayAnm;  // offset: 0xf8
        cGUIObjMessage* mpObjCaptionlistMsg;  // offset: 0x100
        cGUIObjMessage* mpObjNote2;  // offset: 0x108
        cGUIObjMessage* mpObjFree;  // offset: 0x110
        cGUIObjMessage* mpObjNote1;  // offset: 0x118
        static MyDTI DTI;
    };
public:
    struct stGradeList
    {
    public:
        stGradeList();
    public:
        cGUIInstNull* mpInstGradeNull;  // offset: 0x0
        cGUIInstAnimation* mpInstGradeAnm;  // offset: 0x8
        cGUIInstAnimation* mpInstGradeMes;  // offset: 0x10
        cGUIObjTexture* mpObjGradeTex;  // offset: 0x18
        cGUIObjMessage* mpObjMsgGrade;  // offset: 0x20
    };
public:
    class cListItem : public uGUIBase::cScrollListItemBase
    {
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
        cListItem();
    public:
        cGUIInstNull* mpInstItemlistNull;  // offset: 0x58
        cGUIInstNull* mpInstNullPointer;  // offset: 0x60
        cGUIInstAnimation* mpInstItemlistAnm;  // offset: 0x68
        cGUIObjMessage* mpObjItemlistMsg;  // offset: 0x70
        cGUIObjMessage* mpObjItemNumMsg;  // offset: 0x78
        cGUIObjMessage* mpObjItemNumMsg2;  // offset: 0x80
        cGUIInstNull* mpInstItemiconNull;  // offset: 0x88
        cGUIInstAnimation* mpInstItemiconAnm;  // offset: 0x90
        cGUIInstAnimation* mpInstItemiconbaseAnm;  // offset: 0x98
        cGUIInstAnimation* mpInstItemiconinfoAnm;  // offset: 0xa0
        uGUIBase::cReferenceUIIconItem mIcon;  // offset: 0xb0
        static MyDTI DTI;
    };
public:
    struct stItemlistRatio
    {
    public:
        stItemlistRatio();
    public:
        cGUIInstNull* mpInstRatioNull;  // offset: 0x0
        cGUIInstAnimation* mpInstRatiobase;  // offset: 0x8
        cGUIObjMessage* mpObjRatioMsg;  // offset: 0x10
        cGUIInstAnimation* mpInstRatioTxt;  // offset: 0x18
        cGUIObjMessage* mpObjRatioTxt;  // offset: 0x20
        cGUIInstAnimation* mpInstRatioCautionTxt;  // offset: 0x28
        cGUIObjMessage* mpObjRatioCautionTxt;  // offset: 0x30
        cGUIInstAnimation* mpInstRatioCaption;  // offset: 0x38
        cGUIInstAnimation* mpInstRatio_Anm[5];  // offset: 0x40
        cGUIInstAnimation* mpInstBoxInfo;  // offset: 0x68
    };
public:
    struct stDetail
    {
    public:
        stDetail();
    public:
        cGUIInstNull* mpInstDetailNull;  // offset: 0x0
        cGUIInstAnimation* mpInstDetailAnm;  // offset: 0x8
        cGUIObjMessage* mpObjDetailHeadMsg;  // offset: 0x10
        cGUIObjMessage* mpObjDetailMsg;  // offset: 0x18
    };
public:
    struct stPlayType
    {
    public:
        stPlayType();
    public:
        s32 mType;  // offset: 0x0
        s32 mPriceGP[3];  // offset: 0x4
        s32 mPriceCT[3];  // offset: 0x10
        s32 mDrawGP[3];  // offset: 0x1c
        s32 mDrawCT[3];  // offset: 0x28
        s32 mDrawIdGP[3];  // offset: 0x34
        s32 mDrawIdCT[3];  // offset: 0x40
        bool mSaleGP[3];  // offset: 0x4c
        bool mSaleCT[3];  // offset: 0x4f
        bool mPlayGP;  // offset: 0x52
        bool mPlayCT;  // offset: 0x53
    };
public:
    class cItemInfo : public MtObject
    {
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
        cItemInfo();
        cItemInfo(u32, u32, f64);
        // Address: 0x01ae1660 - 0x01ae1661 (1 bytes)
        virtual ~cItemInfo() {}
    public:
        u32 mItemId;  // offset: 0x8
        u32 mItemNum;  // offset: 0xc
        u32 mItemGrade;  // offset: 0x10
        u32 mItemDrawOne;  // offset: 0x14
        f64 mProbability;  // offset: 0x18
        static MyDTI DTI;
    };
public:
    struct stLotList
    {
    public:
        stLotList();
    public:
        cGUIObjPolygon* mpObjPolyMaskTop;  // offset: 0x0
        cGUIObjPolygon* mpObjPolyMaskCenter;  // offset: 0x8
        cGUIObjPolygon* mpObjPolyMaskBottom;  // offset: 0x10
        uGUIBoxGachaInfo::cLotList mList[15];  // offset: 0x18
        uGUIBase::cScrollList mListCtrl;  // offset: 0x2b40
        f32 mListTop;  // offset: 0x2df0
        f32 mListOffset;  // offset: 0x2df4
        static const u32 list_num = 15;
    };
public:
    struct stSummary
    {
    public:
        stSummary();
    public:
        cGUIInstAnimation* mpInstImgAnm;  // offset: 0x0
        cGUIInstAnimation* mpInstBar;  // offset: 0x8
        cGUIObjPolygon* mpObjPolyMaskTop;  // offset: 0x10
        cGUIObjPolygon* mpObjPolyMaskCenter;  // offset: 0x18
        cGUIObjPolygon* mpObjPolyMaskBottom;  // offset: 0x20
        cGUIObjTextureRef* mpObjImgTex;  // offset: 0x28
        cGUIObjMessage* mpObjImgMsg;  // offset: 0x30
        uGUIBase::cTexRefJpegDownloader mRefImageLoader;  // offset: 0x38
        cGUIInstAnimation* mpInstImgLoadAnm;  // offset: 0x288
        cGUIInstAnimation* mpInstBaseAnm;  // offset: 0x290
        cGUIObjMessage* mpObjBaseMsg;  // offset: 0x298
        cGUIInstAnimation* mpInstGPCaptionAnm;  // offset: 0x2a0
        cGUIObjMessage* mpObjGPCaptionMsg;  // offset: 0x2a8
        cGUIInstAnimation* mpInstCTCaptionAnm;  // offset: 0x2b0
        cGUIObjMessage* mpObjCTCaptionMsg;  // offset: 0x2b8
        cGUIObjMessage* mpObjCautionMsg;  // offset: 0x2c0
        bool mbFocus[2];  // offset: 0x2c8
        uGUIBoxGachaInfo::cSumList mSumList[8];  // offset: 0x2d0
        bool mDraw[8];  // offset: 0xbd0
        uGUIBase::cScrollList mListCtrl;  // offset: 0xbe0
        f32 mListTop;  // offset: 0xe90
        f32 mListBottom;  // offset: 0xe94
    };
public:
    struct stList
    {
    public:
        stList();
    public:
        cGUIObjPolygon* mpObjPolyMaskTop;  // offset: 0x0
        cGUIObjPolygon* mpObjPolyMaskCenter;  // offset: 0x8
        cGUIObjPolygon* mpObjPolyMaskBottom;  // offset: 0x10
        cGUIInstAnimation* mpInstBar;  // offset: 0x18
        uGUIBoxGachaInfo::cListItem mList[20];  // offset: 0x20
        uGUIBase::cScrollList mListCtrl;  // offset: 0x2be0
        f32 mListTop;  // offset: 0x2e90
        f32 mListOffset;  // offset: 0x2e94
        uGUIBase::cReferenceUIVlCursor mCursor;  // offset: 0x2ea0
        MtVector2 mCursorOffset;  // offset: 0x2f50
        static const u32 list_num = 20;
    };
public:
    class cLotInfo : public uGUIBase::cScrollListInfoBase
    {
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
        cLotInfo();
    public:
        MtString mListAddr;  // offset: 0x28
        MtString mGachaName;  // offset: 0x30
        MtString mGachaCaption;  // offset: 0x38
        u32 mId;  // offset: 0x40
        bool mSetUp;  // offset: 0x44
        uGUIBoxGachaInfo::stPlayType mPlay[3];  // offset: 0x48
        static MyDTI DTI;
    };
public:
    class cListInfo : public uGUIBase::cScrollListInfoBase
    {
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
        cListInfo();
    public:
        uGUIBoxGachaInfo::cItemInfo mItemInfo;  // offset: 0x28
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
    uGUIBoxGachaInfo();
    virtual ~uGUIBoxGachaInfo();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    void setupListLot(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index);
    void setupListLot(cLotList* pLot, cLotInfo* pInfo, u32 index, bool select);
    void hideListLot(uGUIBase::cScrollListItemBase* pLotBase);
    void setupListItem(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index);
    void setupListItem(cListItem* pItem, cListInfo* pInfo, u32 index, bool select);
    void hideListItem(uGUIBase::cScrollListItemBase* pItemBase);
    void setupListSummary(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index);
    void hideListSummary(uGUIBase::cScrollListItemBase* pItemBase);
    bool isDecide();
    bool isCancel();
    bool isEnd();
    void clearButton();
    void setDetailPos(MtVector4&);
    void setInfoPos(MtVector4&);
    void setValidCtrl(bool flg);
    bool isValidCtrl();
    void setDrawGacha(bool flg);
    bool isDrawGacha();
    void setResetGacha(bool flg);
    bool isResetGacha();
    void setGPShop(bool flg);
    bool isGPShop();
    void refreshInfo();
    void setBoughtItemNum(u32);
    void setNowRequestBoughtItemNum(bool);
    void addGetItemNum(u32 num);
    void clearGetItemNum();
    void restartFromBoughtBox();
    void adjustCursor(bool isFocus);
    bool isOpenDialog();
    void clearFocusBtn();
    void setItemDetailEnable(bool flg);
    void forceRefresh();
    void dlAbort();
    void setBoxFlag(bool flag);
    void createLotList();
    void gachaReset();
    void resetDialogReq();
    void requestBoughtBoxList();
    bool getBoughtBoxListRequestServer();
    void getBoughtBoxListCallBack();
private:
    virtual void updatePtr();  // vtable slot 17
    virtual void updateInit();  // vtable slot 93
    void updateWait();
    void updateExit();
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void init();
    void clearList();
    void clearResultList();
    void clearListSummary();
    void createList();
    void createListBox();
    void createListSummary();
    void createResultList();
    void createFree(cGUIInstAnimation* pCaption, cGUIObjMessage* pText);
    void adjustTabCursor(bool isFocus);
    void adjustSummaryCursor(bool isFocus);
    void adjustDetailCursor();
    void selectFlow(u32 flowID);
    void updateDetail();
    void updateItem();
    void setupDialog();
    void setupDialogReset();
    void setupDialogResetMes();
    void setupDialogGPShop();
    void setupDialogSettlement();
    bool updateDialog();
    void setupPlayDialog();
    void updatePriceInfo();
    void checkPriceInfo(u32 settlement, u32 price, u32 draw_num, s32 draw);
    bool dispError();
    void updateJpegLoader();
    void updateBtnGuide();
    void clearLotList();
    void listLotUpdate();
    void listLotUpdate(cLotList* pLot, cLotInfo* pInfo);
    void startGPShop();
    bool moveGPShop();
    void setPlayType(cLotInfo* pInfo, s32 num, u32 settlement, s32 price, s32 drawid, s32 last, bool sale);
    void evDecide();
    void evCancel();
    void evUpDown();
    void evAdjustCursorV();
    void evAdjustCursorH();
    void evAdjustTab();
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlAdjustCursorH(cControl::Message* msg);
    u32 evCtrlTabLRMove(cControl::Message* msg);
    u32 evCtrlBtnClick(cControl::Message* msg);
    u32 evCtrlStart(cControl::Message* msg);
    u32 evCtrlUp(cControl::Message* msg);
    u32 evCtrlDown(cControl::Message* msg);
    s32 getCtrlPos(cControl* pCtrl);
    void setBtnFlag(const GACHA_BTN_FLAG flag);
    void clearBtnFlag(const GACHA_BTN_FLAG);
    bool isBtnFlag(const u32 flags) const;
    cLotInfo* getLotInfo(u32 index);
private:
    rGUI* mpGUIRes;  // offset: 0x958
    cGUIInstNull* mpInstNull;  // offset: 0x960
    cControl* mpButtonCtrl;  // offset: 0x968
    uGUIBase::cHorizontalList* mpHCtrl;  // offset: 0x970
    uGUIBase::cHorizontalList* mpTabCtrl;  // offset: 0x978
    uGUIBase::cReferenceUIBtnGuide mBtnGuide;  // offset: 0x980
    uGUIBase::cReferenceUIBtnGuide::stGuideBtnData mTblGuide[2];  // offset: 0xa18
    uGUIBase::cReferenceUIButton mResetBtn;  // offset: 0xa68
    uGUIBase::cReferenceUIButton mGPBtn;  // offset: 0xbf8
    stLotList mLotList;  // offset: 0xd90
    stCommon mCommon;  // offset: 0x3b90
    stSummary mSummary;  // offset: 0x3e70
    stGradeList mGradeList[5];  // offset: 0x4d10
    stList mList;  // offset: 0x4de0
    stItemlistRatio mItemlistRatio;  // offset: 0x7d40
    stItemlistRatio mResultlistRatio;  // offset: 0x7db0
    stDetail mDetail;  // offset: 0x7e20
    stList mResult;  // offset: 0x7e40
    uGUIPopDetail01* mpDetail;  // offset: 0xada0
    uGUISystemMsg* mpGUISystemMsg;  // offset: 0xada8
    uGUIGPShop* mpGPShop;  // offset: 0xadb0
    MtVector4 mDetailPos;  // offset: 0xadc0
    MtVector4 mInfoPos;  // offset: 0xadd0
    u32 mFlowId;  // offset: 0xade0
    u32 mBtnFlag;  // offset: 0xade4
    u32 mSelectResult;  // offset: 0xade8
    u32 mBoughtItemNum;  // offset: 0xadec
    bool mIsBoughtBoxItemReqNow;  // offset: 0xadf0
    bool mIsBoughtBoxItemReqReserv;  // offset: 0xadf1
    u32 mGetItemNum;  // offset: 0xadf4
    s32 mInfoIndex;  // offset: 0xadf8
    s32 mInfoIndexOld;  // offset: 0xadfc
    f32 mParamTitleSize;  // offset: 0xae00
    f32 mParamItemSize;  // offset: 0xae04
    f32 mParamRatioMargin;  // offset: 0xae08
    f32 mBtnSize;  // offset: 0xae0c
    bool mIsValidGrdageList[5];  // offset: 0xae10
    bool mIsValidCtrl;  // offset: 0xae15
    bool mIsOpenDialog;  // offset: 0xae16
    bool mIsDrawGacha;  // offset: 0xae17
    bool mIsResetGacha;  // offset: 0xae18
    bool mIsGPShop;  // offset: 0xae19
    bool mIsForceRefresh;  // offset: 0xae1a
    bool mIsRefresh;  // offset: 0xae1b
    bool mIsDetailMulti;  // offset: 0xae1c
    bool mIsNowRequestBoughtItemNum;  // offset: 0xae1d
    bool mBox;  // offset: 0xae1e
    u32 mCtrlType;  // offset: 0xae20
    bool mBtnCtrl;  // offset: 0xae24
    u32 mItemNum[5];  // offset: 0xae28
    u32 mItemDraw[5];  // offset: 0xae3c
    f32 mItemRatio[5];  // offset: 0xae50
    u32 mSettlement;  // offset: 0xae64
    u32 mPlay;  // offset: 0xae68
    u32 mChoice;  // offset: 0xae6c
    u32 mChoiceSettlement[6];  // offset: 0xae70
    bool mResultDisp;  // offset: 0xae88
    bool mIsFreeWord;  // offset: 0xae89
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline uGUIBoxGachaInfo::cItemInfo::cItemInfo() {
    this->mProbability = 0.0;
    this->mItemGrade = static_cast<u32>(0);
    this->mItemDrawOne = static_cast<u32>(0);
    this->mItemId = static_cast<u32>(0);
    this->mItemNum = static_cast<u32>(0);
}
