#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../XFramework/cSystem.h"
#include "cZoneListenerMulti.h"
#include "cZoneUnitCtrl.h"
#include "nDDOUtility.h"
#include "../../generated/shared/nZoneUnitCtrl.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector3;
class cZoneMultiListener;
class cZoneMultiStack;
class cZoneUnitCtrl;
class rZone;

// Declarations
class sZoneUnitCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class sZoneUnitCtrl : public cSystem
{
public:
    class MyDTI;
public:
    using cZoneStackArray = nDDOUtility::cArray<cZoneMultiStack, 3>;
    using cZoneUnitCtrlkArray = nDDOUtility::cArray<cZoneUnitCtrl, 3>;
    using cZoneUnitCtrlTypeFlag = nDDOUtility::cBitSet<3>;
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
    sZoneUnitCtrl();
    virtual ~sZoneUnitCtrl();
    virtual void move();  // vtable slot 7
    virtual void reset();  // vtable slot 6
    u32 addZoneUnitCtrl(ZONE_UNIT_CTRL_TYPE type, rZone* pZone, const MtVector3& pos);
    void eraseZoneUnitCtrl(ZONE_UNIT_CTRL_TYPE type, u32 handle);
    void releaseZoneUnitCtrlAll();
    cZoneMultiStack* getZoneStack(ZONE_UNIT_CTRL_TYPE type);
    cZoneUnitCtrl* getZoneUnitCtrl(ZONE_UNIT_CTRL_TYPE type);
    bool checkZone(cZoneMultiListener& dst, ZONE_UNIT_CTRL_TYPE type);
    bool isDisableZoneCtrlType(ZONE_UNIT_CTRL_TYPE type) const;
    void reqZoneCtrlDisable(ZONE_UNIT_CTRL_TYPE type);
    void updateZoneContactHandle();
    static sZoneUnitCtrl* getInstance();
private:
    cZoneStackArray mZoneStack;  // offset: 0x18
    cZoneUnitCtrlkArray mUnitCtrl;  // offset: 0xa8
    cZoneUnitCtrlTypeFlag mDisableType;  // offset: 0x108
    cZoneUnitCtrlTypeFlag mReqDisableType;  // offset: 0x10c
public:
    static MyDTI DTI;
private:
    static sZoneUnitCtrl* mpInstance;
};
