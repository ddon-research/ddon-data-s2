#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "cpShlBase.h"
#include "uShlBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
class cHitInfo;
class cShlParamCompCondition;
class cShlParamComponent;
class cpShlBase;

// Declarations
class cShlParamComponentCtrl;
class uShlComponentCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamComponentCtrl : public cShlParamBase
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
    virtual MtDTI& getShlDTI() const;  // vtable slot 6
    virtual ~cShlParamComponentCtrl();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void copy(const cShlParamBase* pParam);  // vtable slot 11
protected:
    MtTypedArray<cShlParamComponent> mShlComponent;  // offset: 0x160
public:
    static MyDTI DTI;
};

class uShlComponentCtrl : public uShlBase
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
    const cShlParamComponentCtrl* getShlParam() const;
    virtual ~uShlComponentCtrl();
protected:
    virtual void initSub();  // vtable slot 177
    virtual void updateSub();  // vtable slot 175
    virtual void setCollisionSub(s32 seqNo, s32 groupNo, s32 atckNo, s32 shared_uid);  // vtable slot 180
    virtual u32 getCollisionIndex() const;  // vtable slot 181
    virtual void kill();  // vtable slot 16
    virtual void callbackReplaceHitInfo_Atk(cHitInfo* pHitInfo);  // vtable slot 74
public:
    void setEffectEpvTimer(f32 timer);
    const cShlParamCompCondition* getParamCondition() const;
    const cpShlBase* getShlComponent(MtDTI& dti) const;
    bool hasCondition() const;
    u32 getOwnerSkillLv() const;
    void requestSe(u32 reqNo, MtObject* thisObj, const MtVector3& postion);
protected:
    MtTypedArray<cpShlBase> mShlComponent;  // offset: 0x2ab0
public:
    static MyDTI DTI;
};

inline void* cShlParamComponentCtrl::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uShlComponentCtrl::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
