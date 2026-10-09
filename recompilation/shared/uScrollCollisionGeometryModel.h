#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "uScrollCollision.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
namespace nCollision { class cScrCommonFilter; }
class rGeometry2;
class uGeometry2;
class uModel;
class uScrollCollisionGeometry;
class uScrollCollisionGeometryGroupModel;

// Declarations
class uScrollCollisionGeometryModel;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class uScrollCollisionGeometryModel : public uScrollCollision
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
    uScrollCollisionGeometryModel();
    virtual ~uScrollCollisionGeometryModel();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MT_CTSTR getName();  // vtable slot 14
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void sync();  // vtable slot 11
    virtual void moveAfter();  // vtable slot 10
    bool registResourceByFileName(MT_CTSTR path);
    bool registResource(rGeometry2* pRGeometry2);
    rGeometry2* getRegistResource();
    void unregistResource();
    void setScrFilter(const nCollision::cScrCommonFilter& ScrFilter);
    void setScrType(u32 ScrollType);
    u32 getScrType() const;
    void setScrGroup(u8 ScrollGroupIndex);
    u32 getScrGroup() const;
    u32 getScrGroupIndex() const;
    bool isActive() const;
    void setActive(bool set);
    void registOwner(uModel* pOwner);
    void unregistOwner();
    uModel* getOwner();
    bool isEnableSbcLockTarget() const;
    void setEnableSbcLockTarget(bool FlgEnable);
    uScrollCollisionGeometry* getScrGeometryUnit();
    bool isActiveScrGeometryUnit() const;
    void setActiveScrGeometryUnit(bool FlgSetActive);
    bool isDrawScrGeometryUnit() const;
    void setDrawScrGeometryUnit(bool FlgSetDraw);
    u32 getScrGeometryNum() const;
protected:
    void registMemberToUnit();
    void setDummyU32(u32);
private:
    void setGroupGeometry(uModel* pOwnerModel, uScrollCollisionGeometryGroupModel* pParentUnit, uGeometry2* pGroupGeometry);
protected:
    rGeometry2* mpRGeometry;  // offset: 0x48
    uGeometry2* mpGeometryUnit_Inside;  // offset: 0x50
    uScrollCollisionGeometry* mpScrGeometryUnit_Outside;  // offset: 0x58
    bool mFlgOwnerRegist;  // offset: 0x60
    uModel* mpOwnerModel;  // offset: 0x68
    bool mFlgEnableSbcLockTarget;  // offset: 0x70
private:
    uScrollCollisionGeometryGroupModel* mpParentGeometryGroup;  // offset: 0x78
    bool mFlgGroupMode;  // offset: 0x80
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
// inferred: the constructor from _ZNK29uScrollCollisionGeometryModel5MyDTI11newInstanceEv at 0x0130a5e0-0x0130a63c, code DWARF attributes to no inlined copy
inline uScrollCollisionGeometryModel::uScrollCollisionGeometryModel() {
    this->::cUnit::mDrawMode = static_cast<u32>(1);
    this->mpOwnerModel = static_cast<uModel*>(nullptr);
    this->mFlgOwnerRegist = false;
    this->mpScrGeometryUnit_Outside = static_cast<uScrollCollisionGeometry*>(nullptr);
    this->mpGeometryUnit_Inside = static_cast<uGeometry2*>(nullptr);
    this->mpRGeometry = static_cast<rGeometry2*>(nullptr);
    this->mFlgEnableSbcLockTarget = true;
    this->mpParentGeometryGroup = static_cast<uScrollCollisionGeometryGroupModel*>(nullptr);
    this->mFlgGroupMode = false;
}
