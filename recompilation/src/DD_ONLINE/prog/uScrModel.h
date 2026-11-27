#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "cZoneUnitCtrl.h"
#include "../../XFramework/uBaseModel.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
class cDraw;
class cZoneUnitCtrl;

// Declarations
class uScrBaseModel;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uScrBaseModel : public uBaseModel
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
    uScrBaseModel();
    virtual ~uScrBaseModel();
    virtual void setup();  // vtable slot 6
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void move();  // vtable slot 9
    virtual void moveAfter();  // vtable slot 10
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    virtual void setCommonState(cDraw* pDraw);  // vtable slot 32
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
    bool isDisableZone() const;
    virtual u32 getHitLightToModel();  // vtable slot 36
    void resetZoneUnitCtrl(u32 zoneHandle);
    const MtVector3& getOffsetPos() const;
    void setOffsetPos(const MtVector3& ofs);
    virtual u32 getLODLevel(s32 dist);  // vtable slot 35
private:
    virtual void callbackChangeVisibleTrueToFalse();  // vtable slot 19
protected:
    cZoneUnitCtrl mZoneUnitCtrl;  // offset: 0x11b0
    bool mDisableZone;  // offset: 0x11d0
private:
    bool mMoveSkip;  // offset: 0x11d1
    MtVector3 mOffsetPos;  // offset: 0x11e0
public:
    static MyDTI DTI;
};

inline void* uScrBaseModel::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline const MtVector3& uScrBaseModel::getOffsetPos() const {
    return this->mOffsetPos;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void* uScrBaseModel::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uScrBaseModel::DTI)->memAlloc(sz, align, ::uScrBaseModel::DTI.::MtDTI::getID());
}

inline void uScrBaseModel::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uScrBaseModel::DTI)->memFree(p_addr);
}
