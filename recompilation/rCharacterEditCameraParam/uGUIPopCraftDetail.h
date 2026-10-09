#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtColor.h"
#include "../shared/MtDTI.h"
#include "../shared/MtString.h"
#include "../shared/rItemList.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtDTI;
class MtObject;
class MtPropertyList;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIInstance;
class cGUIObjColorAdjust;
class cGUIObjMessage;
class cGUIObjNull;
class cGUIObjPolygon;
class cGUIObjTexture;
class cItemParam;
class rGUI;
class rGUIMessage;

// Declarations
class uGUIPopCraftDetail;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIPopCraftDetail : public uGUIBase
{
public:
    class MyDTI;
    struct stTop;
    struct stResultInfo;
    struct stSell;
    struct stMaterial;
    struct stMaterialItem;
    struct stCrestResult;
    struct stPage;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stTop
    {
    public:
        stTop();
    public:
        cGUIInstAnimation* mpInstAnim;  // offset: 0x0
        cGUIInstAnimation* mpInstAnimGradeIcon[4];  // offset: 0x8
        cGUIObjMessage* mpObjMsgCategory;  // offset: 0x28
        cGUIObjMessage* mpObjMsgName;  // offset: 0x30
        cGUIObjMessage* mpObjMsgRank;  // offset: 0x38
        cGUIObjMessage* mpObjMsgRankVal;  // offset: 0x40
        cGUIObjMessage* mpObjMsgPlayerEquipVal;  // offset: 0x48
        cGUIObjMessage* mpObjMsgPawnEquipVal;  // offset: 0x50
        cGUIObjMessage* mpObjMsgBagVal;  // offset: 0x58
        cGUIObjMessage* mpObjMsgBoxVal;  // offset: 0x60
        cGUIObjTexture* mpObjTexEquipPlayer;  // offset: 0x68
        cGUIObjTexture* mpObjTexEquipPawn;  // offset: 0x70
        cGUIObjTexture* mpObjTexBag;  // offset: 0x78
        cGUIObjTexture* mpObjTexBox;  // offset: 0x80
        cGUIObjTexture* mpObjTexEquip;  // offset: 0x88
        uGUIBase::cReferenceUIIconItem mIcon;  // offset: 0x90
        uGUIBase::cReferenceUIBtnGuide mGuide;  // offset: 0x210
        static const u32 grade_icon_num = 4;
    };
public:
    struct stResultInfo
    {
    public:
        stResultInfo();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstAnimation* mpInstAnim;  // offset: 0x8
        cGUIObjMessage* mpObjMsgJobLv;  // offset: 0x10
        cGUIObjMessage* mpObjMsgJobLvVal;  // offset: 0x18
        cGUIObjMessage* mpObjMsgGender;  // offset: 0x20
        cGUIObjMessage* mpObjMsgExp;  // offset: 0x28
        cGUIObjMessage* mpObjMsgExpVal;  // offset: 0x30
        cGUIObjMessage* mpObjMsgExpUnit;  // offset: 0x38
        cGUIObjMessage* mpObjMsgMake;  // offset: 0x40
        cGUIObjMessage* mpObjMsgMakeVal;  // offset: 0x48
        cGUIObjNull* mpObjNullMakeRise;  // offset: 0x50
        cGUIObjMessage* mpObjMsgMakeRiseVal;  // offset: 0x58
        cGUIObjMessage* mpObjMsgPoint;  // offset: 0x60
        cGUIObjMessage* mpObjMsgPointVal;  // offset: 0x68
        cGUIObjTexture* mpObjTexPoint;  // offset: 0x70
        cGUIObjTexture* mpObjTexPointRise;  // offset: 0x78
        cGUIObjNull* mpObjNullCost;  // offset: 0x80
        cGUIObjMessage* mpObjMsgCost;  // offset: 0x88
        cGUIObjMessage* mpObjMsgCostVal;  // offset: 0x90
        cGUIObjNull* mpObjNullCostRise;  // offset: 0x98
        cGUIObjMessage* mpObjMsgCostRiseVal;  // offset: 0xa0
        cGUIObjMessage* mpObjMsgCostUnit;  // offset: 0xa8
        cGUIObjMessage* mpObjMsgTime;  // offset: 0xb0
        cGUIObjMessage* mpObjMsgTimeVal;  // offset: 0xb8
        cGUIObjNull* mpObjNullTimeRise;  // offset: 0xc0
        cGUIObjMessage* mpObjMsgTimeRiseVal;  // offset: 0xc8
        cGUIObjMessage* mpObjMsgHeader00;  // offset: 0xd0
        cGUIObjMessage* mpObjMsgHeader01;  // offset: 0xd8
        MtColor mExpDefColor;  // offset: 0xe0
        MtColor mCostRiseDefColor;  // offset: 0xe4
        cGUIObjMessage* mpObjMsgNotice;  // offset: 0xe8
        uGUIBase::cReferenceUIIconJob mJobIcon[10];  // offset: 0xf0
    };
public:
    struct stSell
    {
    public:
        stSell();
    public:
        cGUIInstAnimation* mpInstAnim;  // offset: 0x0
        cGUIObjMessage* mpObjMsgPrice;  // offset: 0x8
        cGUIObjMessage* mpObjMsgPriceVal;  // offset: 0x10
        cGUIObjMessage* mpObjMsgPriceUnit;  // offset: 0x18
        cGUIObjMessage* mpObjMsgBazaar;  // offset: 0x20
        cGUIObjMessage* mpObjMsgBazaarOk;  // offset: 0x28
    };
public:
    struct stMaterialItem
    {
    public:
        stMaterialItem();
    public:
        cGUIInstAnimation* mpInstAnim;  // offset: 0x0
        cGUIObjMessage* mpObjMsgName;  // offset: 0x8
        cGUIObjMessage* mpObjMsgNeed;  // offset: 0x10
        cGUIObjMessage* mpObjMsgHaveBag;  // offset: 0x18
        cGUIObjMessage* mpObjMsgHaveBox;  // offset: 0x20
        cGUIObjMessage* mpObjMsgHaveChest;  // offset: 0x28
        cGUIObjColorAdjust* mpObjColAdj;  // offset: 0x30
        cGUIObjPolygon* mpObjPolyColor;  // offset: 0x38
    };
public:
    struct stCrestResult
    {
    public:
        stCrestResult();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIObjMessage* mpObjMsgName;  // offset: 0x8
        cGUIObjNull* mpObjNullCost;  // offset: 0x10
        cGUIObjMessage* mpObjMsgCost;  // offset: 0x18
        cGUIObjMessage* mpObjMsgCostVal;  // offset: 0x20
        cGUIObjNull* mpObjNullCostRise;  // offset: 0x28
        cGUIObjMessage* mpObjMsgCostRiseVal;  // offset: 0x30
        cGUIObjMessage* mpObjMsgCostUnit;  // offset: 0x38
        cGUIObjMessage* mpObjMsgExp;  // offset: 0x40
        cGUIObjMessage* mpObjMsgExpVal;  // offset: 0x48
        cGUIObjMessage* mpObjMsgExpUnit;  // offset: 0x50
    };
public:
    struct stPage
    {
    public:
        stPage();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        uGUIBase::cReferenceUIPageDot mPageDot;  // offset: 0x8
        static const u32 page_max = 8;
    };
public:
    struct stMaterial
    {
    public:
        stMaterial();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstAnimation* mpInstAnimTerms;  // offset: 0x8
        cGUIObjMessage* mpObjMsgName;  // offset: 0x10
        cGUIObjMessage* mpObjMsgNeed;  // offset: 0x18
        cGUIObjMessage* mpObjMsgHeader;  // offset: 0x20
        uGUIPopCraftDetail::stMaterialItem mList[9];  // offset: 0x28
        static const u32 list_num = 9;
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
    uGUIPopCraftDetail();
    virtual ~uGUIPopCraftDetail();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    void setupInfo(cItemParam* pParam, u32 type, u32 category, u32 recipe_index, u32 recipe_id);
    void setupCrestInfo(cItemParam* pParam);
    void setupColorInfo(cItemParam* pParam);
    void setPageNum(u32 page_num);
    bool isEnoughGold();
    bool isEnoughMaterial();
private:
    void updateInit();
    void updateExit();
    void setupCrestResult(stCrestResult& crest, cGUIInstance* pInstNull, cGUIInstance* pInstHeader, cGUIInstance* pInstResult);
    void setupBasicInfo(cItemParam* pParam, rItemList::rItemParam* pItemParam);
    void setupTime(cGUIObjMessage* pObjMsg, u32 time);
    const MtColor& getColor(u32 item_id);
    void setItemName(cGUIObjMessage* pObjMsg, MT_CTSTR name);
    void setItemName(cGUIObjMessage* pObjMsg, MT_CTSTR name, const MtColor& color);
    void setExpVal(cGUIObjMessage* pObj, const u32 val);
    MT_CTSTR getMsg(u32 index);
    MT_CTSTR getParamMsg(u32 index);
    MT_CTSTR getCmnMsg(u32 index);
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    rGUIMessage* mpGMDRes;  // offset: 0x8d0
    rGUIMessage* mpGMDParamRes;  // offset: 0x8d8
    rGUIMessage* mpGMDJewelryCtgr;  // offset: 0x8e0
    cGUIInstNull* mpInstNull;  // offset: 0x8e8
    stTop mTop;  // offset: 0x8f0
    stResultInfo mResInfo;  // offset: 0xba0
    stSell mSell;  // offset: 0x1000
    stMaterial mMaterial;  // offset: 0x1030
    stCrestResult mCrestEquip;  // offset: 0x1298
    stCrestResult mCrestBreak;  // offset: 0x12f0
    stPage mPage;  // offset: 0x1348
    bool mIsEnoughGold;  // offset: 0x13d8
    bool mIsEnoughMaterial;  // offset: 0x13d9
    MtStringEx<128> mTempStr;  // offset: 0x13dc
public:
    static MyDTI DTI;
};
