#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtCollisionUtil.h"
#include "../MT/MtDTI.h"
#include "uScrollCollision.h"

// Forward declarations
class MtAllocator;
namespace MtCollisionUtil { class MtArrayEx; }
class MtDTI;
class MtObject;
class MtPropertyList;
namespace nCollision { class cScrCommonFilter; }
class rGeometry2Group;
class uGeometry2Group;
class uModel;
class uScrollCollisionGeometryModel;

// Declarations
class uScrollCollisionGeometryGroupModel;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class uScrollCollisionGeometryGroupModel : public uScrollCollision
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
    uScrollCollisionGeometryGroupModel();
    virtual ~uScrollCollisionGeometryGroupModel();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MT_CTSTR getName();  // vtable slot 14
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void sync();  // vtable slot 11
    virtual void moveAfter();  // vtable slot 10
    bool registResource(rGeometry2Group* pRGeometry2);
    rGeometry2Group* getRegistResource();
    void unregistResource();
    void setScrFilterAll(const nCollision::cScrCommonFilter& filter);
    void setScrFilter(const nCollision::cScrCommonFilter& filter, u32 ScrollType);
    void setScrTypeAll(u32 ScrollType);
    void setScrType(u32 ScrollType, u32 GroupIndex);
    u32 getScrType(u32 GroupIndex) const;
    void setScrGroupAll(u8 ScrollGroupIndex);
    void setScrGroup(u8 ScrollGroupIndex, u32 GroupIndex);
    u32 getScrGroup(u32 GroupIndex) const;
    u32 getScrGroupIndex(u32 GroupIndex) const;
    bool isActiveGroup(u32 GroupIndex) const;
    void setActiveGroupAll(bool set);
    void setActiveGroup(bool set, u32 GroupIndex);
    void registOwner(uModel* pOwner);
    void unregistOwner();
    uModel* getOwner();
    uScrollCollisionGeometryModel* getScrGeometryUnit(u32 GroupIndex);
    const uScrollCollisionGeometryModel* getScrGeometryUnitConst(u32 GroupIndex) const;
    u32 getScrGeometryUnitNum() const;
protected:
    void registMemberToUnit();
protected:
    rGeometry2Group* mpRGeometryGroup;  // offset: 0x48
    uGeometry2Group* mpGeometryGroupUnit_Inside;  // offset: 0x50
    MtCollisionUtil::MtArrayEx mGeometryUnitArray;  // offset: 0x58
    bool mFlgOwnerRegist;  // offset: 0x90
    uModel* mpOwnerModel;  // offset: 0x98
public:
    static MyDTI DTI;
};

inline void* uScrollCollisionGeometryGroupModel::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
