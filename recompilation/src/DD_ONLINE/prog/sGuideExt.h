#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtNetCom.h"
#include "../../XFramework/sGuideBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;

// Declarations
class sGuideExt;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class sGuideExt : public sGuideBase
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
    sGuideExt();
    virtual ~sGuideExt();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    static sGuideExt* getInstance();
    void initInnerString();
    void setRichPresence(u32 user_index);
private:
    virtual void moveEx();  // vtable slot 13
    virtual void onNotifyEvent(u32 notifyID, u32 param);  // vtable slot 14
    virtual void onSystemUIDispChanged(bool disp) {}  // vtable slot 15
    virtual void onSigninLevelChanged(s32 level) {}  // vtable slot 16
    virtual void onServiceConnectionChanged(void* data_ptr) {}  // vtable slot 17
    virtual void onInviteAccepted(s32 index) {}  // vtable slot 18
    virtual void onPhysicalLinkChanged(bool is_active) {}  // vtable slot 19
    virtual void onFriendListChanged(s32 index, s32 action) {}  // vtable slot 20
    virtual void onAppSuspend() {}  // vtable slot 21
    virtual void onAppShutdown() {}  // vtable slot 22
private:
    MtNetCom::INative* mpNav;  // offset: 0x30
    MtNetCom::IRichPresence* mpRichPresence;  // offset: 0x38
public:
    static MyDTI DTI;
private:
    static sGuideExt* mpInstance;
};

inline void* sGuideExt::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* sGuideExt::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::sGuideExt::DTI);
}

inline void sGuideExt::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::sGuideExt::DTI)->memFree(p_addr);
}
