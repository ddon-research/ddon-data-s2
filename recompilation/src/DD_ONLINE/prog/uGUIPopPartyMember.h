#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "cControl.h"
#include "nDDOUtility.h"
#include "uGUIBase.h"
#include "uGUIsMenuBase.h"

// Forward declarations
class CDataPartyMember;
class MtAllocator;
class MtDTI;
class MtObject;
class cGUIInstNull;
class cGUIObjMessage;
class rGUI;
class uGUIBase;

// Declarations
class uGUIPopPartyMember;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIPopPartyMember : public uGUIsMenuBase
{
public:
    class MyDTI;
    struct PartyMember;
    struct DATA;
public:
    using PartyMembers = nDDOUtility::cArray<uGUIPopPartyMember::PartyMember, 8>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct PartyMember
    {
    public:
        PartyMember();
    public:
        cGUIInstNull* mpINST_Null_list;  // offset: 0x0
        cGUIObjMessage* mpOBJ_msg_list_m_name;  // offset: 0x8
        cGUIObjMessage* mpOBJ_msg_list_m_num;  // offset: 0x10
        uGUIBase::cReferenceUIIconOnlineStatus mIconOnlineStatus;  // offset: 0x18
        uGUIBase::cReferenceUIIconJob mIconJob;  // offset: 0x68
    };
public:
    struct DATA
    {
    public:
        cGUIInstNull* mpINST_Null;  // offset: 0x0
        cGUIInstNull* mpINST_Null_all;  // offset: 0x8
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
    static bool Show(uGUIBase* base);
    uGUIPopPartyMember();
    virtual ~uGUIPopPartyMember();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    virtual s32 getSMenuCursorY();  // vtable slot 72
    bool show();
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
private:
    virtual void updateInit();  // vtable slot 93
    void updateWait();
    void updateExit();
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    void updatePointerPos();
    void partyMemberSetup(PartyMember& partyMember, cGUIInstNull* pINST_Null_list, f32 offsetY);
    void partyMemberSetParam(PartyMember& partyMember, const CDataPartyMember& dataPartyMember);
    void partyMemberSetParam(PartyMember& partyMember, MT_CTSTR name, u32 onlineStatus, u32 jobId, u32 jobLv, bool isPawn);
private:
    rGUI* mpGUIRes;  // offset: 0x958
    uGUIBase::cVerticalList* mpCtrlV;  // offset: 0x960
    uGUIBase::cReferenceUIButton mButton;  // offset: 0x968
    PartyMembers mPartyMembers;  // offset: 0xaf8
    DATA mData;  // offset: 0x10f8
    bool mIsSetup;  // offset: 0x1108
public:
    static MyDTI DTI;
};

inline void* uGUIPopPartyMember::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void uGUIPopPartyMember::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIPopPartyMember::DTI)->memFree(p_addr);
}
