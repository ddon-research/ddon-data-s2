#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "cHitInfoAfterLocal.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtVector3;
class cHitInfo;
class cHitInfoAfterLocal;

// Declarations
class cDamageMsg;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;

class cDamageMsg : public MtObject
{
public:
    class MyDTI;
    struct GuardData;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct GuardData
    {
    public:
        u64 mAttackerUID;  // offset: 0x0
        u64 mAttackParamUID;  // offset: 0x8
        u64 mDfdNodeUID;  // offset: 0x10
        MtVector3 mDamageDir;  // offset: 0x20
        u16 mAtkAdjustUniqueId;  // offset: 0x30
        bool mIsAttackerShl;  // offset: 0x32
        u32 mShlOwnerID;  // offset: 0x34
        bool mIsReceiveInfo;  // offset: 0x38
        u32 mAttackAttr;  // offset: 0x3c
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
    cDamageMsg();
    void copy(const cDamageMsg& msg);
    void makeInfoFromHitNode(const cHitInfo* pHitInfo);
    void setAttackerUID(u32 uID);
    u32 getAttackerUID() const;
    void setAttackParamUID(u64 uID);
    u64 getAttackParamUID() const;
    void setDfdNodeUID(u64 uID);
    u64 getDfdNodeUID() const;
    void setAtkAdjustUniqueId(u16 uID);
    u16 getAtkAdjustUniqueId() const;
    void setDamageDir(const MtVector3& damage_dir);
    const MtVector3& getDamageDir() const;
    void setIsAttackerShl(bool);
    bool isAttackerShl(bool) const;
    void setShlOwnerUID(u64 uID);
    u32 getShlOwnerUID() const;
    bool isReceiveInfo() const;
    void onReceiveFlag();
    u32 getAttackAttr() const;
    void setAttackAttr(u32 attr);
private:
    u64 getAttackerUIDPrivate() const;
    void setAttackerUIDPrivate(u64 NewValue);
    u64 getAttackParamUIDPrivate() const;
    void setAttackParamUIDPrivate(u64 NewValue);
    u64 getDfdNodeUIDPrivate() const;
    void setDfdNodeUIDPrivate(u64 NewValue);
    const MtVector3& getDamageDirPrivate() const;
    void setDamageDirPrivate(const MtVector3& NewValue);
    u16 getAtkAdjustUniqueIdPrivate() const;
    void setAtkAdjustUniqueIdPrivate(u16 NewValue);
    bool isAttackerShlPrivate() const;
    void setAttackerShlPrivate(bool NewValue);
    u32 getShlOwnerIDPrivate() const;
    void setShlOwnerIDPrivate(u32 NewValue);
    bool isReceiveInfoPrivate() const;
    void setReceiveInfoPrivate(bool NewValue);
    u32 getAttackAttrPrivate() const;
    void setAttackAttrPrivate(u32 NewValue);
private:
    GuardData mData;  // offset: 0x10
public:
    cHitInfoAfterLocal mLocalInfo;  // offset: 0x50
    static MyDTI DTI;
};
