#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/cpComponent.h"
#include "uCnsShakeCtrl.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector3;
class cAttackParam;
class cCollGeom;
class cHitInfo;
class cHitInfoAfter;
class cpIKCtrl;
class rShakeCtrl;
class uCnsShakeCtrl;
class uDDOModel;

// Declarations
class cpShakeCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

class cpShakeCtrl : public cpComponent
{
    // inferred: uCnsShakeCtrl::shake names cpShakeCtrl::mpResource
    friend class uCnsShakeCtrl;
public:
    enum
    {
        BANK_NUM = 4,
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
    cpShakeCtrl();
    virtual ~cpShakeCtrl();
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 11
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    virtual void setupComponentPtr();  // vtable slot 12
    void setResource(rShakeCtrl* pRes, u32 bank);
    rShakeCtrl* getResource(u32);
    u32 getResourceNum();
    void setResourceNum(u32);
    void initShakeCtrl();
    void updateShakeCtrl();
    void shake(u32 JntNo, const MtVector3& shakeDir, s32 ResourceNo);
    void shake(cHitInfo* pHitInfo, bool force_shake, s32 ResourceNo);
    void shake(cHitInfoAfter* pHitInfo, bool force_shake, s32 ResourceNo);
    void setIKCtrl(cpIKCtrl* pIKCtrl);
    uCnsShakeCtrl* findCnsShakeCtrl(s32 JntNo);
    uCnsShakeCtrl* findNearestCnsShakeCtrl(s32 JntNo);
    void enableConstraint(bool enable);
    void addIgnorOST(u64 OST);
    bool isIgnorOST(u64 OST);
    void addIgnorBadOCD(u32 OcdUID);
    bool isIgnorBadOCD(u32 OCDFlag);
protected:
    void setCurrentResource(rShakeCtrl* pRes);
    rShakeCtrl* getCurrentResource();
    void removeConstraint();
    void shake(const cAttackParam* pAttackParam, const cCollGeom* pDfdGeom, uDDOModel* pAtkModel, uDDOModel* pDfdModel, bool force_shake, u32 ResourceNo);
public:
    uDDOModel* mpModel;  // offset: 0x50
protected:
    MtTypedArray<uCnsShakeCtrl> mCnsShakeCtrlArray;  // offset: 0x58
    rShakeCtrl* mpResource;  // offset: 0x78
    rShakeCtrl* mpBank[4];  // offset: 0x80
    cpIKCtrl* mpIKCtrl;  // offset: 0xa0
    s32 mCurrentResNo;  // offset: 0xa8
    MtVector3 mDir;  // offset: 0xb0
    u64 mIgnorOST;  // offset: 0xc0
    u32 mIgnorBadOCD;  // offset: 0xc8
public:
    static MyDTI DTI;
};
