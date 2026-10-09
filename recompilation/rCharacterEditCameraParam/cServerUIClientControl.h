#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "uGUIServerUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
namespace nUserSession { class CPacket_S2C_OPEN_UI_NTC; }
class sGUIExt;
class uGUIServerUIBase;

// Declarations
class cServerUIClientControl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cServerUIClientControl : public MtObject
{
    // inferred: sGUIExt::requestOpenServerUI names cServerUIClientControl::mState
    friend class sGUIExt;
public:
    enum
    {
        STATE_NONE = 0,
        STATE_REQUEST = 1,
        STATE_WAIT = 2,
    };
    enum
    {
        SERVER_UI_DISP_NUM = 5,
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
    bool isActiveServerUI();
    bool isRequestServerUI();
    cServerUIClientControl();
    virtual ~cServerUIClientControl();
    void move();
    void openServerUI(u32 UIId);
    void catchServerUINtc(nUserSession::CPacket_S2C_OPEN_UI_NTC* packet);
    void closeServerUI(uGUIServerUIBase* pUI);
    void closeServerUIAll();
    void closeServerUIChild();
private:
    void setupCurrent(uGUIServerUIBase* pCurrent);
private:
    u32 mState;  // offset: 0x8
    u32 mRequestId;  // offset: 0xc
    MtTypedArray<uGUIServerUIBase> mServerUIList;  // offset: 0x10
    uGUIServerUIBase* mpCurrentUI;  // offset: 0x30
    uGUIServerUIBase* mpParentUI;  // offset: 0x38
public:
    static MyDTI DTI;
};
