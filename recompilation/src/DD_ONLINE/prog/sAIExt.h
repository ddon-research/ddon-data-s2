#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "nDDOUtility.h"
#include "../../XFramework/rNavigationMesh.h"
#include "res_ptr.h"
#include "../../XFramework/sAI.h"

// Forward declarations
class MtAABB;
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector3;
class cAISvNavPathFinding;
class rNavigationMesh;

// Declarations
class sAIExt;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class sAIExt : public sAI
{
public:
    class MyDTI;
    class cSvNav;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cSvNav
    {
    public:
        cSvNav();
    public:
        void* mpOwnerHandle;  // offset: 0x0
        cAISvNavPathFinding* mpSvNav;  // offset: 0x8
        res_ptr<rNavigationMesh> mpReqNavMesh;  // offset: 0x10
        res_ptr<rNavigationMesh> mpUseNavMesh;  // offset: 0x18
        MtVector3 mReqOfsPos;  // offset: 0x20
        MtVector3 mUseOfsPos;  // offset: 0x30
        MT_CTSTR mSvName;  // offset: 0x40
        u32 mUpdateUID;  // offset: 0x48
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
    sAIExt();
    virtual ~sAIExt();
    virtual void move();  // vtable slot 7
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 9
    void createSvNav();
    void deleteSvNav();
    s32 setNavigationMesh(void* pOwner, rNavigationMesh* pNaviMesh, const MtVector3& ofsPos);
    void resetNavigationMesh(void* pOwner, s32 handle);
    void resetNavigationMeshAll();
    cAISvNavPathFinding* getNavigationMeshService();
    cAISvNavPathFinding* getNavigationMeshService(u32 idx);
    cAISvNavPathFinding* getNavigationMeshService(const MtVector3& pos);
    cAISvNavPathFinding* getNavigationMeshService(const MtVector3& nowPos, const MtVector3& targetPos);
    cAISvNavPathFinding* getNavigationMeshService(void* pOwner, s32 handle);
    bool isNavigationMesh();
    u32 getNavigationMeshUID(cAISvNavPathFinding* pSvNav);
    bool isNaviMeshUpdate() const;
    void offNaviMeshMatrix();
private:
    void setNaviMeshMatrix(cAISvNavPathFinding* pSvNav, const MtVector3& ofsPos);
    bool isNavMeshIntersect(const MtAABB& aabb, const MtVector3& pos) const;
private:
    MtVector3 mAbsoluteWorldOffset;  // offset: 0x60
    nDDOUtility::cArray<cSvNav, 3> mSvNavStack;  // offset: 0x70
    u32 mUpdateUID;  // offset: 0x160
    bool mIsNaviMeshUpdate;  // offset: 0x164
public:
    static MyDTI DTI;
};

inline void* sAIExt::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
