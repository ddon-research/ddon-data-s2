#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "uDDOModel.h"
#include "uShlGenerator.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtUIList;
class MtVector3;
class cShlParamBase;
class uDDOModel;

namespace nShlEmMultiLock {
    enum SHL_SET_LOCATE
    {
        LOCATE_GENERATOR = 0,
        LOCATE_TARGET = 1,
        LOCATE_TARGET_POS_VEC = 2,
        LOCATE_MAX = 3,
    };
}  // namespace nShlEmMultiLock

// Declarations
class cShlParamMultiLock;
class uShlEmMultiLock;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cShlParamMultiLock : public cShlParamGenerator
{
public:
    enum RANGE
    {
        RANGE_NEAR = 0,
        RANGE_MIDDLE = 1,
        RANGE_FAR = 2,
        RANGE_OUT = 3,
        RANGE_MAX = 4,
    };
public:
    class MyDTI;
    class cRangePointTbl;
    class cShootCtrlParamMultiLock;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cRangePointTbl : public MtObject
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
        cRangePointTbl();
        cRangePointTbl(f32, u32);
        virtual ~cRangePointTbl() {}
        cShlParamMultiLock::cRangePointTbl& operator=(const cShlParamMultiLock::cRangePointTbl& tbl);
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUIList* createUIList(MtUIList* pList);  // vtable slot 6
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        u32 getPoint(f32 range) const;
    private:
        f32 mRange;  // offset: 0x8
        u32 mPoint;  // offset: 0xc
    public:
        static MyDTI DTI;
    };
public:
    class cShootCtrlParamMultiLock : public cShlParamGenerator::cShootCtrlParam
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
        cShootCtrlParamMultiLock();
        virtual ~cShootCtrlParamMultiLock() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        u8 getGroup() const;
        nShlEmMultiLock::SHL_SET_LOCATE getShlSetLocate() const;
    private:
        u8 mGroup;  // offset: 0x44
        nShlEmMultiLock::SHL_SET_LOCATE mShlSetLocate;  // offset: 0x48
    public:
        static MyDTI DTI;
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
    virtual MtDTI& getShlDTI() const;  // vtable slot 6
    cShlParamMultiLock();
    virtual ~cShlParamMultiLock() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
    virtual void addShlList(const cShlParamGenerator* pParam);  // vtable slot 12
    u32 getDistPoint(f32 range) const;
    u32 getAnglePoint(f32 range) const;
    u32 getEvalPoint(f32 range) const;
private:
    bool mNoCalcTgtDir;  // offset: 0x18c
    u32 mLockNum;  // offset: 0x190
    u32 mPlayerPoint;  // offset: 0x194
    u32 mPawnPoint;  // offset: 0x198
    u32 mNpcPoint;  // offset: 0x19c
    cRangePointTbl mDist[4];  // offset: 0x1a0
    cRangePointTbl mAngle[4];  // offset: 0x1e0
    cRangePointTbl mEval[4];  // offset: 0x220
public:
    static MyDTI DTI;
};

class uShlEmMultiLock : public uShlGenerator
{
public:
    class MyDTI;
    class cTargetList;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cTargetList : public MtObject
    {
        friend class uShlEmMultiLock;
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
        cTargetList();
        cTargetList(uDDOModel*, u32);
        virtual ~cTargetList() {}
        void updatePtr();
        uDDOModel* getTarget() const;
        void setTarget(uDDOModel* tgt);
        u32 getPrio() const;
        void setPrio(u32 prio);
    private:
        uDDOModel* mpTarget;  // offset: 0x8
        u32 mPrio;  // offset: 0x10
    public:
        static MyDTI DTI;
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
    const cShlParamMultiLock* getShlParam() const;
    uShlEmMultiLock();
    virtual ~uShlEmMultiLock();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void setup();  // vtable slot 6
    virtual void initSub();  // vtable slot 177
    virtual void updatePtr();  // vtable slot 17
    virtual void updateEfcHandle();  // vtable slot 58
    static bool sortTargetList(const cTargetList* pListA, const cTargetList* pListB, u32);
protected:
    virtual void setShl(u32 shlNo, const MtVector3& offset, f32 degX, f32 degY);  // vtable slot 186
private:
    bool registryTarget();
    bool registryTargetSlave();
    u32 calcPriorityPoint(uDDOModel* pTgt);
private:
    bool mNoCalcTgtDir;  // offset: 0x2ad0
    bool mIsBlind;  // offset: 0x2ad1
    u32 mShlSetNumGrp[6];  // offset: 0x2ad4
    u32 mLockNum;  // offset: 0x2aec
    MtVector3 mBaseVec;  // offset: 0x2af0
    MtTypedArray<uDDOModel> mTmpTargetArray;  // offset: 0x2b00
    MtTypedArray<cTargetList> mTargetArray;  // offset: 0x2b20
public:
    static MyDTI DTI;
};

inline void* cShlParamMultiLock::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamMultiLock::cShlParamMultiLock() {
    this->mNoCalcTgtDir = false;
    this->mLockNum = 0;
    this->mPlayerPoint = 10;
    this->mPawnPoint = 5;
    this->mNpcPoint = 1;
}

inline void* cShlParamMultiLock::cRangePointTbl::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamMultiLock::cRangePointTbl::cRangePointTbl() {
    this->mRange = 0.0f;
    this->mPoint = 0;
}

inline void* cShlParamMultiLock::cShootCtrlParamMultiLock::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamMultiLock::cShootCtrlParamMultiLock::cShootCtrlParamMultiLock() : mGroup(0), mShlSetLocate(static_cast<nShlEmMultiLock::SHL_SET_LOCATE>(0)) {
}

inline void* uShlEmMultiLock::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uShlEmMultiLock::cTargetList::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uShlEmMultiLock::cTargetList::cTargetList() {
    this->mpTarget = nullptr;
    this->mPrio = 0;
}

inline u32 uShlEmMultiLock::cTargetList::getPrio() const {
    return this->mPrio;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void* cShlParamMultiLock::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cShlParamMultiLock::DTI)->memAlloc(sz, align, ::cShlParamMultiLock::DTI.::MtDTI::getID());
}

inline void cShlParamMultiLock::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cShlParamMultiLock::DTI)->memFree(p_addr);
}

inline void* cShlParamMultiLock::cRangePointTbl::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cShlParamMultiLock::cRangePointTbl::DTI)->memAlloc(sz, align, ::cShlParamMultiLock::cRangePointTbl::DTI.::MtDTI::getID());
}

inline void cShlParamMultiLock::cRangePointTbl::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cShlParamMultiLock::cRangePointTbl::DTI)->memFree(p_addr);
}

inline void cShlParamMultiLock::cShootCtrlParamMultiLock::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cShlParamMultiLock::cShootCtrlParamMultiLock::DTI)->memFree(p_addr);
}

inline void* uShlEmMultiLock::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uShlEmMultiLock::DTI)->memAlloc(sz, align, ::uShlEmMultiLock::DTI.::MtDTI::getID());
}

inline void uShlEmMultiLock::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uShlEmMultiLock::DTI)->memFree(p_addr);
}

inline uShlEmMultiLock::uShlEmMultiLock() {
    this->mNoCalcTgtDir = false;
    this->mIsBlind = false;
    this->mShlSetNumGrp[4] = 0;
    this->mShlSetNumGrp[5] = 0;
    this->mShlSetNumGrp[2] = 0;
    this->mShlSetNumGrp[3] = 0;
    this->mShlSetNumGrp[0] = 0;
    this->mShlSetNumGrp[1] = 0;
    this->mLockNum = 1;
    this->mBaseVec = ::MtVector3::Zero;
    this->mTmpTargetArray.::MtArray::mpArray = nullptr;
    this->mTmpTargetArray.::MtArray::mBufsiz = 0;
    this->mTmpTargetArray.::MtArray::mLength = 0;
    this->mTargetArray.::MtArray::mpArray = nullptr;
    this->mTargetArray.::MtArray::mLength = 0;
    this->mTargetArray.::MtArray::mBufsiz = 0;
}

inline void* uShlEmMultiLock::cTargetList::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uShlEmMultiLock::cTargetList::DTI)->memAlloc(sz, align, ::uShlEmMultiLock::cTargetList::DTI.::MtDTI::getID());
}

inline void uShlEmMultiLock::cTargetList::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uShlEmMultiLock::cTargetList::DTI)->memFree(p_addr);
}
