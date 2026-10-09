#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "cpComponent.h"
#include "nDDOUtility.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector3;
class uHuman;

// Declarations
class cpHumanWarpCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cpHumanWarpCtrl : public cpComponent
{
public:
    enum WARP_RNO_ONEWAY_OM
    {
        WARP_RNO_ONEWAY_OM_START = 1,
        WARP_RNO_ONEWAY_OM_ACT_REQUEST = 2,
        WARP_RNO_ONEWAY_OM_MOVE = 3,
        WARP_RNO_ONEWAY_OM_AFTER_MOVE = 4,
    };
    enum WARP_TYPE
    {
        WARP_TYPE_INIT = 0,
        WARP_TYPE_ONE_WAY_OM = 0,
        WARP_TYPE_NUM = 1,
    };
    enum WARP_RNO_COMMON
    {
        WARP_RNO_COMMON_NONE = 0,
        WARP_RNO_COMMON_END = 1,
    };
public:
    class MyDTI;
    struct stHumanWarpInfo;
public:
    using cHumanWarpInfoArray = nDDOUtility::cArray<cpHumanWarpCtrl::stHumanWarpInfo, 1>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stHumanWarpInfo
    {
    public:
        void reset();
    public:
        MtVector3 mWarpWorldPos;  // offset: 0x0
        f32 mWarpAngle;  // offset: 0x10
        u32 mWarpRno;  // offset: 0x14
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
    cpHumanWarpCtrl();
    virtual ~cpHumanWarpCtrl();
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 8
    virtual void updatePtr();  // vtable slot 9
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 11
    void before();
    void update();
    void after();
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    void requestOneWayWarp(const MtVector3& worldPos, const f32 angle);
    u32 getWarpRno(u32 type) const;
private:
    void beforeSubOneWayOm();
private:
    cHumanWarpInfoArray mHumanWarpInfo;  // offset: 0x50
    uHuman* mpHuman;  // offset: 0x70
public:
    static MyDTI DTI;
};
