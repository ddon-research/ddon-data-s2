#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "cGeneralPoint.h"
#include "cpComponent.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
class cJointInfo;
class rJointInfo;
class uDDOModel;

// Declarations
class cpLockOn;

namespace nLockOnTarget {
    enum LOCKON_ALL_CTRL
    {
        STATE_NONE = 0,
        STATE_ALL_OFF = 1,
        STATE_ALL_REF_ON = 2,
        STATE_ALL_REF_OFF = 3,
    };
}  // namespace nLockOnTarget

namespace nLockOnTarget {
    enum LOCKON_TARGET_STATE
    {
        STATE_NORMAL = 0,
        STATE_BREAK = 1,
    };
}  // namespace nLockOnTarget

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class cpLockOn : public cpComponent
{
public:
    enum FIND_MODE
    {
        MODE_DEFAULT = 0,
        MODE_NEAREST = 1,
    };
public:
    class MyDTI;
    class cLockOnTarget;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cLockOnTarget : public cGeneralPoint
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
        cLockOnTarget();
        // Address: 0x01a5c150 - 0x01a5c151 (1 bytes)
        virtual ~cLockOnTarget() {}
        u16 getJointInfoID() const;
        void setJointInfoID(u16 ID);
        nLockOnTarget::LOCKON_TARGET_STATE getLockOnTargetState() const;
        void setLockOnTargetState(nLockOnTarget::LOCKON_TARGET_STATE state);
    public:
        MtVector3 mBaseDir;  // offset: 0x60
        MtVector3 mOfsPos;  // offset: 0x70
        bool mCalcOfsPos;  // offset: 0x80
        u32 mAttr;  // offset: 0x84
        f32 mBaseRadius;  // offset: 0x88
    protected:
        u16 mJointInfoID;  // offset: 0x8c
        nLockOnTarget::LOCKON_TARGET_STATE mLockOnState;  // offset: 0x90
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
    cpLockOn();
    virtual ~cpLockOn();
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void sync();  // vtable slot 15
    virtual void updatePtr();  // vtable slot 9
    virtual void kill();  // vtable slot 8
    void update();
    void after();
    void setResource(rJointInfo* pRes);
    rJointInfo* getResource();
    void loadLockOnTarget();
    void releaseLockOnTarget();
    cLockOnTarget* getLockOnTarget(u32 index);
    void setGpCategory(s32 category);
    void unregister();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void callbackRegisterLockOnTarget();
    void setLockOnTargetFromJointInfo(cLockOnTarget* pTarget, cJointInfo* pInfo);
    void requestLockOnTargetAllOff();
    void requestLockOnTargetRefAll(bool flag);
    void setLockOnTargetState(u32 jointInfoID, nLockOnTarget::LOCKON_TARGET_STATE state);
protected:
    bool setLockOnTargetActive(u32 jointInfoID, bool isActive);
    bool setLockOnTargetActiveAll(bool isActive);
    bool setLockOnTargetActiveRefAll(bool isActive);
    void updateLockOnTargetState();
    void updateLockOnTarget(cLockOnTarget* pLockOnTarget);
public:
    MtTypedArray<cLockOnTarget> mArray;  // offset: 0x50
    uDDOModel* mpModel;  // offset: 0x70
    rJointInfo* mpResource;  // offset: 0x78
    bool mNoEntry;  // offset: 0x80
protected:
    nLockOnTarget::LOCKON_ALL_CTRL mRequestLockOffAll;  // offset: 0x84
public:
    static MyDTI DTI;
};
