#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/sVibration.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class rVibration;

// Declarations
class sVibrationExt;

// Type aliases from DWARF
using u32 = unsigned int;
using ARC_TAGID = u32;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;

class sVibrationExt : public sVibration
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
    sVibrationExt();
    virtual ~sVibrationExt();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void move();  // vtable slot 7
    void setVibration(rVibration* pVibration, u32 ResType);
    void setVibrationByPath(MT_CTSTR Path, u32 ResType);
    void setVibrationByArc(ARC_TAGID ArchiveTagId, s32 SearchId, u32 ResType);
    void releaseVibration(u32 ResType);
    void releaseVibrationAll();
    rVibration* getVibration(u32);
    u32 getVibrationNum();
    void setVibrationNum(u32);
    void reqVibration(u32 ResType, u32 ListNo, u32 Priority);
    void reqVibration(u32 ListNo, u32 Priority, rVibration* pExtVibration);
    static sVibration::VibFlag getGamePadVibFlag();
    void setVibrationEnable(const bool isEnable);
protected:
    rVibration* mprVibration[4];  // offset: 0x8f0
    u32 mPriority;  // offset: 0x910
public:
    static MyDTI DTI;
    static const u32 RESOURCE_TYPE_NUM = 4;
};
