#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "cDelegate.h"
#include "cSystem.h"
#include "cpLockOn.h"
#include "ctl_storageArray.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
class cpLockOn;
class uBaseModel;
class uDDOModel;

// Declarations
class sLockOnManager;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class sLockOnManager : public cSystem
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
    sLockOnManager();
    virtual ~sLockOnManager();
    static sLockOnManager* getInstance();
    virtual void reset();  // vtable slot 6
    void sync();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void add(cpLockOn::cLockOnTarget* pLockOnTarget);
    void registerLockOn(cpLockOn* pLockOn);
    void unregisterLockOn(cpLockOn* pLockOn);
    cpLockOn::cLockOnTarget* searchLockOnTarget(uDDOModel* pModel, cpLockOn::FIND_MODE mode, f32 dist, f32 range, s32 category, f32 height, uDDOModel* pTagOnly);
    const cpLockOn::cLockOnTarget* getShootTarget(uDDOModel* pMdl, const MtVector3& shootVec, const MtVector3& shootPos, f32 dist, f32 range, const uDDOModel* pCantLockTarget, MtTypedStorageArray<cpLockOn::cLockOnTarget, 16>* pAr, s32 category);
    cpLockOn::cLockOnTarget* getLockOnTarget(uDDOModel* pTargetModel);
    cpLockOn::cLockOnTarget* getMagicTarget(uDDOModel* pMdl, const MtVector3& shootVec, const MtVector3& shootPos, f32 dist, f32 range, const uDDOModel* pCantLockTarget, MtTypedStorageArray<cpLockOn::cLockOnTarget, 32>* pAr, s32 category);
    s32 getLockOnTargetIdx(uBaseModel* pTargetModel, s32 beginIdx);
    cpLockOn::cLockOnTarget* getLockOnTargetFormIdx(s32);
    bool getAllLockOnTarget(uDDOModel* pTargetModel, MtTypedArray<cpLockOn::cLockOnTarget>& arr);
private:
    f32 calcLineLength(const MtVector3& BasePos, f32 AngleY, const MtVector3& TargetPos);
public:
    MtTypedArray<cpLockOn::cLockOnTarget> mTargetArray;  // offset: 0x18
    cDelegate_0<void> callbackRegisterLockOnTarget;  // offset: 0x38
    static MyDTI DTI;
    static sLockOnManager* mpInstance;
};

// Inline, no code of its own: checked where it is inlined.
inline sLockOnManager* sLockOnManager::getInstance() {
    return ::sLockOnManager::mpInstance;
}
