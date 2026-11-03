#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "cGeneralPointPtr.h"
#include "cpComponent.h"
#include "cpLockOn.h"
#include "../../generated/shared/nDDOGame.h"
#include "../../generated/shared/nDDOModel.h"
#include "nDDOUtility.h"
#include "../../generated/shared/nGUIAim.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class rSoundRequest;
class uDDOModel;

// Declarations
class cpLockOnTargetManager;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cpLockOnTargetManager : public cpComponent
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
    cpLockOnTargetManager();
    virtual ~cpLockOnTargetManager();
    bool isInit() const;
    void init(u32 maxLockOnNum, bool isSameMulti, nGUIAim::TARGET_MARKER_TYPE targetMarkerType, nDDOModel::LOCKON_TARGET_TYPE lockOnTargetType);
    void setMaxLockOnNum(u32 num);
    void add(const cpLockOn::cLockOnTarget* p, bool isEffect);
    bool insertToEmpty(const cpLockOn::cLockOnTarget* p, bool isEffect, bool isSE);
    void erase();
    void erase(const cpLockOn::cLockOnTarget* p);
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void updateEfcHandle();  // vtable slot 10
    void end(u32 index);
    void endAll();
    const cpLockOn::cLockOnTarget* getPtr(u32 index) const;
    const cpLockOn::cLockOnTarget* getPtrNewest(u32) const;
    u32 getMax() const;
    u32 getLockNum() const;
    void setEffectiveDist(f32 d);
    bool isEffective(const cpLockOn::cLockOnTarget* pTarget) const;
    void setEpvNoLockOnNow(s32);
    void setElementMaterialFlag(nDDOGame::ELEMENT_TYPE element);
    void setLockOnType(nDDOModel::LOCKON_TARGET_TYPE type);
    nDDOModel::LOCKON_TARGET_TYPE getLockOnType() const;
private:
    void setLockOnEffect(u32 index, const cpLockOn::cLockOnTarget* p);
private:
    u32 mMaxNum;  // offset: 0x50
    u32 mNextIndex;  // offset: 0x54
    nDDOUtility::cArray<cGpPtr<const cpLockOn::cLockOnTarget>, 8> mPtrs;  // offset: 0x58
    nDDOUtility::cArray<unsigned int, 8> mTargetMarkerIds;  // offset: 0xd8
    u32 mTargetMarkerIdNow;  // offset: 0xf8
    const cpLockOn::cLockOnTarget* mpLockOnLast;  // offset: 0x100
    nGUIAim::TARGET_MARKER_TYPE mTargetMarkerType;  // offset: 0x108
    nDDOModel::LOCKON_TARGET_TYPE mLockOnType;  // offset: 0x10c
    rSoundRequest* mprSE;  // offset: 0x110
    s32 mSENoLockOn;  // offset: 0x118
    bool mIsInit;  // offset: 0x11c
    bool mIsSameMulti;  // offset: 0x11d
    f32 mEffectiveDist;  // offset: 0x120
    u32 mMaterialFlag;  // offset: 0x124
public:
    uDDOModel* mpModel;  // offset: 0x128
    static MyDTI DTI;
    static const u32 MAX = 8;
    static const f32 DEFAULT_EFFECTIVE_DIST;
};

inline void* cpLockOnTargetManager::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void cpLockOnTargetManager::setEffectiveDist(f32 d) {
    this->mEffectiveDist = d;
}
