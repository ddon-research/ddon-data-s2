#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtString.h"
#include "../shared/sGUIExt.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cGUIInstAnimation;
class cGUIObjMessage;
class cGUIObjNull;
class cGUIObjTexture;
class rGUI;

// Declarations
class uGUIShopTitle;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

class uGUIShopTitle : public uGUIBase
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
    uGUIShopTitle();
    virtual ~uGUIShopTitle();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    void setTitle(MT_CTSTR title, MT_CTSTR sub_title);
    void setDrawType(sGUIExt::SHOPTITLE_TYPE::Type Type);
    void setChargesAttr(u32 uAttr);
    void updateMoney();
    void changeMoneyType();
private:
    void updateInit();
    void updateWait();
    void updateExit();
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    cGUIInstAnimation* mpInstAnimBase;  // offset: 0x8d0
    cGUIInstAnimation* mpInstAnimMoney;  // offset: 0x8d8
    uGUIBase::cReferenceUIChargesInfo mChargesInfo;  // offset: 0x8e0
    cGUIObjNull* mpObjNullMoney;  // offset: 0xa38
    cGUIObjNull* mpObjNullGacha;  // offset: 0xa40
    cGUIObjNull* mpObjNullPawnpoint;  // offset: 0xa48
    cGUIObjMessage* mpObjMsgTitle;  // offset: 0xa50
    cGUIObjMessage* mpObjMsgTitleSub;  // offset: 0xa58
    cGUIObjMessage* mpObjMsgMoney;  // offset: 0xa60
    cGUIObjMessage* mpObjMsgMoneyValue;  // offset: 0xa68
    cGUIObjMessage* mpObjMsgGpValue;  // offset: 0xa70
    cGUIObjMessage* mpObjMsgCtValue;  // offset: 0xa78
    cGUIObjMessage* mpObjMsgPoint;  // offset: 0xa80
    cGUIObjMessage* mpObjMsgPointValue;  // offset: 0xa88
    cGUIObjTexture* mpObjTexIcon;  // offset: 0xa90
    MtStringEx<64> mTitleText;  // offset: 0xa98
    MtStringEx<64> mTitleTextSub;  // offset: 0xadc
    sGUIExt::SHOPTITLE_TYPE::Type mType;  // offset: 0xb20
    u64 mVal;  // offset: 0xb28
    u64 mValTicket;  // offset: 0xb30
    u64 mPointVal;  // offset: 0xb38
    u32 mChargesAttr;  // offset: 0xb40
public:
    static MyDTI DTI;
};
