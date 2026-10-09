#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "cSystem.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
namespace nNetMsgData { struct stNetPos; }

// Declarations
class sWorldOffset;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class sWorldOffset : public cSystem
{
public:
    enum
    {
        ST_NONE = 0,
        ST_INIT = 1,
        ST_MOVE = 2,
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
    sWorldOffset();
    virtual ~sWorldOffset();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void move();  // vtable slot 7
    void Init(const MtVector3& targetPos);
    void clear();
    void InitEdit(const MtVector3& targetPos);
    void clearEdit();
    MtVector3 getRealPos(const MtVector3& worldPos) const;
    nNetMsgData::stNetPos getRealNetPos(const MtVector3& worldPos) const;
    MtVector3 getRealOffset(s32 splitN, s32 splitM);
    MtVector3 getRealOffsetTail(s32 splitN, s32 splitM);
    MtVector3 getOffsetPos(const MtVector3& RealPos) const;
    MtVector3 getOffsetNetPos(const nNetMsgData::stNetPos& RealPos) const;
    bool isUseWorldOffset();
    bool calcOffsetTail(const MtVector3& pos, s32& outX, s32& outZ);
private:
    bool calcOffset(const MtVector3& targetPos);
    bool calcOffsetEx(const MtVector3& targetPos);
public:
    static sWorldOffset* getInstance();
    bool isWorldOffset() const;
    bool isUpdate();
    u32 getStatus();
    void setStatus(u32);
    MtVector3 getWorldOffset();
    MtVector3 getWorldAbsoluteOffset();
    s32 getX();
    s32 getZ();
private:
    void setEnableWorldOffset(bool flag);
    void setWorldOffset(const MtVector3& ofs);
    void setWorldAbsoluteOffset(const MtVector3& ofs);
    void addWorldAbsoluteOffset(const MtVector3& ofs);
private:
    bool mEnabelWorldOffset;  // offset: 0x11
    u32 mStatus;  // offset: 0x14
    u32 mRno;  // offset: 0x18
    s32 mIdX;  // offset: 0x1c
    s32 mIdZ;  // offset: 0x20
    MtVector3 mWorldOffset;  // offset: 0x30
    MtVector3 mWorldAbsoluteOffset;  // offset: 0x40
    bool mUpdate;  // offset: 0x50
public:
    static MyDTI DTI;
private:
    static sWorldOffset* mpInstance;
};
