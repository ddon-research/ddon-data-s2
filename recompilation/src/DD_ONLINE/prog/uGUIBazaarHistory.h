#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "cControl.h"
#include "uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cControl;
class cGUIInstAnimation;
class cGUIObjMessage;
class rGUI;
class rGUIMessage;
class rSoundRequest;
class uGUIBazaar;

// Declarations
class uGUIBazaarHistory;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIBazaarHistory : public uGUIBase
{
    friend class uGUIBazaar;
public:
    enum
    {
        MODE_TYPE_PURCHASE = 0,
        MODE_TYPE_EXHIBIT = 1,
    };
    enum
    {
        LIST_TYPE_EXHIBIT = 0,
        LIST_TYPE_TRADE = 1,
    };
public:
    class MyDTI;
    class cItemHistory;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cItemHistory : public MtObject
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
        cItemHistory();
        virtual ~cItemHistory() {}
    public:
        cGUIInstAnimation* mpInstHistory;  // offset: 0x8
        cGUIObjMessage* mpObjMsgPrice;  // offset: 0x10
        cGUIObjMessage* mpObjMsgPriceG;  // offset: 0x18
        cGUIObjMessage* mpObjMsgNum;  // offset: 0x20
        cGUIObjMessage* mpObjMsgDate;  // offset: 0x28
        cGUIObjMessage* mpObjMsgTotalPrice;  // offset: 0x30
        cGUIObjMessage* mpObjMsgTotalPriceG;  // offset: 0x38
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
    uGUIBazaarHistory();
    virtual ~uGUIBazaarHistory();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void move();  // vtable slot 9
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    void begin();
    bool isBegin() const;
    void hide();
    void setFocus(bool isFocus);
    void setItemNo(u32 itemNo);
    void setMode(u32 mode);
protected:
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
private:
    void updateInit();
    void updateMove();
    void updateWait();
    void updateChange();
    void initialize();
    u32 evCtrlTopBtn(cControl::Message* msg);
    MT_CTSTR getMsg(u32 index);
    MT_CTSTR getCmnMsg(u32 index);
    void updateTradeList();
    void updateExhibitList();
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    rGUIMessage* mpGMDRes;  // offset: 0x8d0
    rSoundRequest* mpSNDRes;  // offset: 0x8d8
    bool mIsBegin;  // offset: 0x8e0
    cGUIObjMessage* mpObjMsgTitle;  // offset: 0x8e8
    cGUIObjMessage* mpObjMsgHeader00;  // offset: 0x8f0
    cGUIObjMessage* mpObjMsgHeader01;  // offset: 0x8f8
    cGUIObjMessage* mpObjMsgHeader02;  // offset: 0x900
    cGUIObjMessage* mpObjMsgHeader03;  // offset: 0x908
    uGUIBase::cReferenceUIBtnGuide mBtnGuide;  // offset: 0x910
    cItemHistory mItemHistory[10];  // offset: 0x9a8
    cControl* mpCtrl;  // offset: 0xc28
    bool mFocus;  // offset: 0xc30
    bool mStay;  // offset: 0xc31
    u32 mMode;  // offset: 0xc34
    u32 mListType;  // offset: 0xc38
    s32 mListNum;  // offset: 0xc3c
    u32 mItemNo;  // offset: 0xc40
public:
    static MyDTI DTI;
    static const u32 HISTORY_LIST_NUM = 10;
};

inline void* uGUIBazaarHistory::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUIBazaarHistory::cItemHistory::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUIBazaarHistory::cItemHistory::cItemHistory() {
    this->mpObjMsgTotalPriceG = nullptr;
    this->mpObjMsgTotalPrice = nullptr;
    this->mpObjMsgDate = nullptr;
    this->mpObjMsgNum = nullptr;
    this->mpObjMsgPriceG = nullptr;
    this->mpObjMsgPrice = nullptr;
    this->mpInstHistory = nullptr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* uGUIBazaarHistory::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::uGUIBazaarHistory::DTI);
}

inline void uGUIBazaarHistory::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIBazaarHistory::DTI)->memFree(p_addr);
}

inline void* uGUIBazaarHistory::cItemHistory::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uGUIBazaarHistory::cItemHistory::DTI)->memAlloc(sz, align, ::uGUIBazaarHistory::cItemHistory::DTI.::MtDTI::getID());
}

inline void uGUIBazaarHistory::cItemHistory::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIBazaarHistory::cItemHistory::DTI)->memFree(p_addr);
}
