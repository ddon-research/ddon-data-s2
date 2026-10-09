#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtString.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtString;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class rGUI;
class rGUIMessage;

// Declarations
class uGUITelop;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUITelop : public uGUIBase
{
public:
    enum
    {
        TYPE_CUTIN = 0,
        TYPE_FSM = 1,
    };
public:
    class MyDTI;
    struct DATA;
    struct PAGE;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct DATA
    {
    public:
        cGUIInstNull* mpInstNullD;  // offset: 0x0
        cGUIInstAnimation* mpInstName;  // offset: 0x8
        cGUIInstAnimation* mpInstMsg;  // offset: 0x10
        cGUIObjMessage* mpObjMsgName;  // offset: 0x18
        cGUIObjMessage* mpObjMsgMsg;  // offset: 0x20
    };
public:
    struct PAGE
    {
    public:
        bool mEnable;  // offset: 0x0
        MtString mNameNpc;  // offset: 0x8
        MtString mMessage;  // offset: 0x10
        f32 mCntSkipChk;  // offset: 0x18
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
    uGUITelop();
    virtual ~uGUITelop();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    rGUIMessage* getMessageResource();
    void setMessageResource(rGUIMessage* pRes);
    void setType(u32 uType);
    void setNameNpc(MT_CTSTR msg, u32 uPage);
    void setMessage(MT_CTSTR msg, u32 uPage);
    void setCntSkipChk(f32 fCnt, u32 uPage);
    u32 getMessageIndex();
    void setMessageIndex(u32 n);
    u32 getPageNum();
    u32 getCurrentPage();
    u32 getFinalPageIdx();
    void ejectPage();
private:
    void updateInit();
    void updateWait();
    void updateExit();
    void adjustPositionName();
private:
    DATA mData;  // offset: 0x8c8
    PAGE mPage[64];  // offset: 0x8f0
    rGUI* mpGUIRes;  // offset: 0x10f0
    rGUIMessage* mpMessageResource;  // offset: 0x10f8
    u32 mMessageIndex;  // offset: 0x1100
    bool mReserve;  // offset: 0x1104
    u32 mType;  // offset: 0x1108
    f32 mCntSkip;  // offset: 0x110c
    u32 mCurrentPage;  // offset: 0x1110
public:
    static MyDTI DTI;
    static const u32 PAGE_MAX = 64;
};

// Inline, no code of its own: checked where it is inlined.
inline u32 uGUITelop::getCurrentPage() {
    return this->mCurrentPage;
}
