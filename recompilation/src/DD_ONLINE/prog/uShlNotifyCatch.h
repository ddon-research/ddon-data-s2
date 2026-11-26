#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "cpShlShotCtrl.h"
#include "uShlSpeed.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cHitInfo;
class cShlParamBase;

// Declarations
class cShlParamNotifyCatch;
class uShlNotifyCatch;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamNotifyCatch : public cShlParamSpeed
{
public:
    enum NOTIFY_ATTR
    {
        NOTIFY_ATTR_ALIVE_ONLY_CLUTCH = 1,
        NOTIFY_ATTR_CREATE_SHL_FOR_LARGE_ENEMY = 2,
        NOTIFY_ATTR_HIT_EFFECT_SE = 4,
        NOTIFY_ATTR_FORCE_ANCHOR = 8,
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
    virtual MtDTI& getShlDTI() const;  // vtable slot 6
    cShlParamNotifyCatch();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
    bool isOwnerCatch() const;
private:
    bool isNotifyAttrFlagOn(u32 attr) const;
private:
    bool mIsOwnerCatch;  // offset: 0x1ed
    u32 mNotifyAttrFlag;  // offset: 0x1f0
    cpShlShotCtrl::cShlShotReqInfo mShlReqInfo;  // offset: 0x200
public:
    static MyDTI DTI;
};

class uShlNotifyCatch : public uShlSpeed
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
    const cShlParamNotifyCatch* getShlParam() const;
    uShlNotifyCatch();
    virtual ~uShlNotifyCatch() {}
    virtual void setup();  // vtable slot 6
    virtual void update();  // vtable slot 174
    virtual void callbackReplaceHitInfo_Atk(cHitInfo* pHitInfo) {}  // vtable slot 74
    virtual void callbackCatch(cHitInfo* pHitInfo);  // vtable slot 118
    virtual bool isOwnerCatch() const;  // vtable slot 185
private:
    bool checkStateClutch() const;
    bool isNotifyAttrFlagOn(u32 attr) const;
private:
    bool mIsHitSeCall;  // offset: 0x2b86
    bool mIsKillRequest;  // offset: 0x2b87
public:
    static MyDTI DTI;
};

inline void* cShlParamNotifyCatch::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamNotifyCatch::cShlParamNotifyCatch() : mIsOwnerCatch(true), mNotifyAttrFlag(0u) {
}

inline bool cShlParamNotifyCatch::isOwnerCatch() const {
    return this->mIsOwnerCatch;
}

inline void* uShlNotifyCatch::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uShlNotifyCatch::uShlNotifyCatch() {
    this->mIsHitSeCall = false;
    this->mIsKillRequest = false;
}
