#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtObject.h"
#include "../MT/MtPrimitive3D.h"
#include "../MT/MtSynchronize.h"
#include "cAIService.h"
#include "sCollision.h"

// Forward declarations
class MtAABB;
class MtAllocator;
class MtCriticalSection;
class MtDTI;
class MtOBB;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
class cAIPathTrace;
class cUnit;
class rAIDynamicLayout;
class uCoord;

// Declarations
class cAISvDynamicPathFinding;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cAISvDynamicPathFinding : public cAIService
{
public:
    enum ATTRIBUTE
    {
        ATTR_MOVE = 1,
        ATTR_NO_MOVE = 2,
    };
public:
    class MyDTI;
    class GroupManagement;
    class UnitManagement;
    class TraceManagement;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class UnitManagement : public MtObject
    {
        friend class cAISvDynamicPathFinding;
    public:
        class MyDTI;
        class Unit;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class Unit : public MtObject
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
            Unit();
            virtual ~Unit() {}
        public:
            uCoord* mpUnit;  // offset: 0x8
            MtOBB mOBB;  // offset: 0x10
            MtVector3 mPrevPos;  // offset: 0x60
            s32 mGroupIndex;  // offset: 0x70
            u8 mAttribute;  // offset: 0x74
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
        UnitManagement();
        virtual ~UnitManagement();
        void addUnit(cUnit* pUnit, const MtOBB& obb, u32 attr);
        void removeUnit(cUnit* pUnit);
        void removeUnitAll();
    protected:
        Unit* mpUnits;  // offset: 0x8
        u32 mNumberOfUnit;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
public:
    class TraceManagement : public MtObject
    {
    public:
        class MyDTI;
        class Trace;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class Trace : public MtObject
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
            Trace();
            virtual ~Trace();
        public:
            cAIPathTrace* mpAddr;  // offset: 0x8
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
        TraceManagement();
        virtual ~TraceManagement();
        void addTrace(cAIPathTrace* pTrace);
        void removeTrace(cAIPathTrace* pTrace);
        void sendInterrupt();
    public:
        Trace* mpTrace;  // offset: 0x8
        u32 mNumberOfTrace;  // offset: 0x10
        static MyDTI DTI;
    };
public:
    class GroupManagement : public MtObject
    {
        friend class cAISvDynamicPathFinding;
    public:
        enum AXIS_TYPE
        {
            AXIS_X = 1,
            AXIS_Y = 2,
            AXIS_Z = 4,
        };
    public:
        class MyDTI;
        class Group;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class Group : public MtObject
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
            Group();
            virtual ~Group();
            void setSize(u32 size);
            u32 getSize();
            void setUnitIndex(u32 index, u32 n);
            u32 getUnitIndex(u32 n);
            void setNumberOfVertex(u32 num);
            u32 getNumberOfVertex();
            void setVertex(const MtVector3& pos, u32 n);
            MtVector3 getVertex(u32 n);
        public:
            MtAABB mAABB;  // offset: 0x10
            MtVector3* mpVertex;  // offset: 0x30
            u32 mNumberOfVertex;  // offset: 0x38
            u32* mpUnitIndex;  // offset: 0x40
            u32 mNumberOfUnit;  // offset: 0x48
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
        GroupManagement();
        virtual ~GroupManagement();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void setTime(f32);
        void setRange(f32 range);
        void useAttribute(bool);
        f32 getRange();
        bool isUpdate();
        cAISvDynamicPathFinding::UnitManagement* getUnitManagement();
        void addUnit(cUnit* pUnit, const MtOBB& obb, u32 attr);
        void removeUnit(cUnit* pUnit);
        void removeUnitAll();
        void addTrace(cAIPathTrace* pTrace);
        void removeTrace(cAIPathTrace* pTrace);
    protected:
        bool update();
        void reset();
        bool MergeToPos();
        bool GroupScanning();
        bool GroupScanning(cUnit* pUnit);
        void insertGroup(cUnit* pUnit);
        void removeGroup(cUnit* pUnit, u32 index);
        void GrahamScanning(Group* pGroup, u32 axis, MtVector3* vertex, u32 num);
        bool crossLine(const MtVector3& p0, const MtVector3& p1, const MtVector3& v1, u32 axis);
    protected:
        f32 mCurrentTime;  // offset: 0x8
        f32 mDeltaTime;  // offset: 0xc
        f32 mRange;  // offset: 0x10
        u32 mNumberOfGroup;  // offset: 0x14
        Group* mpGroup;  // offset: 0x18
        cAISvDynamicPathFinding::UnitManagement mUnit;  // offset: 0x20
        cAISvDynamicPathFinding::TraceManagement mTrace;  // offset: 0x38
        bool mUpdate;  // offset: 0x50
        bool mRemove;  // offset: 0x51
        bool mAttribute;  // offset: 0x52
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
    cAISvDynamicPathFinding();
    virtual ~cAISvDynamicPathFinding();
    virtual void reset();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    void setUnit(cUnit* pUnit, const MtOBB& obb, u32 attr);
    bool setUnit(cUnit* pUnit, u32 attr);
    void setTrace(cAIPathTrace* pTrace);
    void removeUnit(cUnit* pUnit);
    void removeUnitAll();
    void removeTrace(cAIPathTrace* pTrace);
    void setRange(f32);
    void setUpdateTime(f32);
    void useAttribute(bool);
    u32 getNumberOfGroup();
    GroupManagement::Group* getGroupPath(u32 groupNum);
    void setPath(rAIDynamicLayout* rLayout);
    rAIDynamicLayout* getPath();
    void removePath();
    void update();
    void setCollisionParam(u32, u32);
    void setCollisionParam(const sCollision::Param&);
    sCollision::Param getCollisionParam();
protected:
    GroupManagement mGroup;  // offset: 0x30
    rAIDynamicLayout* mpDynamicPath;  // offset: 0x88
    sCollision::Param mParam;  // offset: 0x90
private:
    MtCriticalSection mCs;  // offset: 0x1b0
public:
    static MyDTI DTI;
};

inline void* cAISvDynamicPathFinding::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cAISvDynamicPathFinding::GroupManagement::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void cAISvDynamicPathFinding::GroupManagement::setRange(f32 range) {
    this->mRange = range;
    this->mUpdate = true;
}

inline f32 cAISvDynamicPathFinding::GroupManagement::getRange() {
    return this->mRange;
}

inline void* cAISvDynamicPathFinding::GroupManagement::Group::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cAISvDynamicPathFinding::UnitManagement::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cAISvDynamicPathFinding::UnitManagement::UnitManagement() {
    this->mpUnits = nullptr;
    this->mNumberOfUnit = 0;
}

inline void* cAISvDynamicPathFinding::UnitManagement::Unit::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cAISvDynamicPathFinding::TraceManagement::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cAISvDynamicPathFinding::TraceManagement::TraceManagement() {
    this->mpTrace = nullptr;
    this->mNumberOfTrace = 0;
}

inline void* cAISvDynamicPathFinding::TraceManagement::Trace::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void cAISvDynamicPathFinding::GroupManagement::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cAISvDynamicPathFinding::GroupManagement::DTI)->memFree(p_addr);
}

inline void* cAISvDynamicPathFinding::UnitManagement::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cAISvDynamicPathFinding::UnitManagement::DTI)->memAlloc(sz, align, ::cAISvDynamicPathFinding::UnitManagement::DTI.::MtDTI::mID);
}

inline void* cAISvDynamicPathFinding::UnitManagement::Unit::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cAISvDynamicPathFinding::UnitManagement::Unit::DTI)->memAlloc(sz, align, ::cAISvDynamicPathFinding::UnitManagement::Unit::DTI.::MtDTI::mID);
}

inline void cAISvDynamicPathFinding::UnitManagement::Unit::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cAISvDynamicPathFinding::UnitManagement::Unit::DTI)->memFree(p_addr);
}

inline cAISvDynamicPathFinding::UnitManagement::Unit::Unit() {
    this->mpUnit = nullptr;
    this->mGroupIndex = -1;
    this->mPrevPos.x = ::MtVector3::Zero.x;
    this->mPrevPos.y = ::MtVector3::Zero.y;
    this->mPrevPos.z = ::MtVector3::Zero.z;
    this->mPrevPos.pad_ = 0.0f;
    this->mAttribute = 0;
}

inline void* cAISvDynamicPathFinding::TraceManagement::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cAISvDynamicPathFinding::TraceManagement::DTI)->memAlloc(sz, align, ::cAISvDynamicPathFinding::TraceManagement::DTI.::MtDTI::mID);
}

inline void cAISvDynamicPathFinding::TraceManagement::Trace::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cAISvDynamicPathFinding::TraceManagement::Trace::DTI)->memFree(p_addr);
}
