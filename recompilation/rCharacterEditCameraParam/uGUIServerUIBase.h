#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtString.h"
#include "../shared/ServerUI.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class CDataUIListCommand;
class CDataUIListElement;
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;
class cServerUIClientControl;
namespace nUserSession { class CPacket_S2C_OPEN_UI_NTC; }

// Declarations
class uGUIServerUIBase;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using UIListCommandVec = MtTypedArray<CDataUIListCommand>;
using UIListElementVec = MtTypedArray<CDataUIListElement>;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class uGUIServerUIBase : public uGUIBase
{
    // inferred: cServerUIClientControl::closeServerUI calls uGUIServerUIBase::end
    friend class cServerUIClientControl;
public:
    class MyDTI;
    struct CommandInfo;
public:
    using CallbackCommnad = void(uGUIServerUIBase::*)();
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct CommandInfo
    {
    public:
        CommandInfo();
        void reset();
    public:
        u32 mCommandId;  // offset: 0x0
        u32 mEndType;  // offset: 0x4
        u32 mArgNum1;  // offset: 0x8
        u32 mArgNum2;  // offset: 0xc
        uGUIServerUIBase::CallbackCommnad mpCallbackCommndFunc;  // offset: 0x10
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
    uGUIServerUIBase(u32 initFlags, bool isChatSubMenu);
    virtual ~uGUIServerUIBase();
protected:
    bool setupBase();
    virtual void end();  // vtable slot 79
    bool isEnableServerUI();
    bool requestCommand(u32 serverUICommand, u32 argNum1, u32 argNum2);
private:
    void enableControl();
    void disableControl();
    void initServerUI(cServerUIClientControl* pControl, nUserSession::CPacket_S2C_OPEN_UI_NTC* packet);
    CDataUIListCommand* getCommnadInfo(u32 commnadId);
    bool startRequest(u32 serverUICommand);
    bool requestUICommand();
    void callbackUICommand();
protected:
    u32 mServerUIId;  // offset: 0x8c8
    u16 mServerUIType;  // offset: 0x8cc
    MtString mTitleJP;  // offset: 0x8d0
    MtString mTitleEN;  // offset: 0x8d8
    u32 mArgNum1;  // offset: 0x8e0
    UIListCommandVec mCommandList;  // offset: 0x8e8
    UIListElementVec mElementList;  // offset: 0x908
    bool mIsEnableServerUI;  // offset: 0x928
private:
    cServerUIClientControl* mpServerUIControl;  // offset: 0x930
    CommandInfo mCommandInfo;  // offset: 0x938
    bool mIsRequestCommand;  // offset: 0x958
public:
    static MyDTI DTI;
};
