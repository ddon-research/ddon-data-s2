#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "../MT/MtLogisticMap.h"
#include "../MT/MtMath.h"
#include "../MT/MtObject.h"
#include "sScene.h"
#include "uGrassEffect.h"

// Forward declarations
class MtAABB;
class MtAllocator;
class MtDTI;
struct MtFloat3;
class MtLogisticMap;
class MtMatrix;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
class MtVector4;

// Declarations
class uGrassWind;
class uGrassWindDirection;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class uGrassWind : public uGrassEffect
{
public:
    enum GRPUP
    {
        GROUP_0 = 1,
        GROUP_1 = 2,
        GROUP_2 = 4,
        GROUP_3 = 8,
        GROUP_4 = 16,
        GROUP_5 = 32,
        GROUP_6 = 64,
        GROUP_7 = 128,
        FORCEDWORD = -1,
    };
    enum GRASSWINDTYPE
    {
        GWT_UNKNOWN = 0,
        GWT_DIRECTION = 1,
        GWT_POINT = 2,
        GWT_LINE = 4,
    };
public:
    class MyDTI;
    class cSwingParameters;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cSwingParameters : public MtObject
    {
        friend class uGrassWindDirection;
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
        cSwingParameters();
        virtual ~cSwingParameters();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual void update(f32 frequency, f32 phase);  // vtable slot 6
        virtual MtVector4 getRotationAngle(const MtVector3& pos, const f32 user_phase);  // vtable slot 7
        f32 getCurrentPhaseSpeed();
    protected:
        virtual void updateSpeed();  // vtable slot 8
    protected:
        MtMatrix mWindMatrix;  // offset: 0x10
        bool mUseLogistic;  // offset: 0x50
        bool mUseInterpolateSpeed;  // offset: 0x51
        f32 mInterpolateSpeed;  // offset: 0x54
        MtLogisticMap mDirectionalLogistic;  // offset: 0x58
        MtLogisticMap mTurblanceLogistic;  // offset: 0x60
        f32 mUpdateInterval;  // offset: 0x68
        f32 mModelAmp;  // offset: 0x6c
        f32 mModelPhaseCoeff;  // offset: 0x70
        f32 mElapsed;  // offset: 0x74
        f32 mElapsed2;  // offset: 0x78
        f32 mElapsed3;  // offset: 0x7c
        f32 mElapsed4;  // offset: 0x80
        f32 mCurrentPhaseSpeed;  // offset: 0x84
        f32 mCurrentPhaseSpeed2;  // offset: 0x88
        f32 mBasePhaseSpeed;  // offset: 0x8c
        f32 mBasePhaseSpeed2;  // offset: 0x90
        f32 mPhaseSpeed;  // offset: 0x94
        f32 mPhaseSpeed2;  // offset: 0x98
        f32 mNoiseRate;  // offset: 0x9c
        f32 mNoiseRate2;  // offset: 0xa0
        f32 mBias;  // offset: 0xa4
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
    uGrassWind(f32 Amplification, f32 Frequency, f32 Phase, u32 Priority);
    virtual ~uGrassWind();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void getAABB(MtAABB& aabb) {}  // vtable slot 24
    MtVector4 getParams();
    virtual MtVector4 getInfo();  // vtable slot 25
    virtual MtVector4 getInfo2();  // vtable slot 26
    virtual MtVector3 getDirection(const MtVector3& pos);  // vtable slot 27
    virtual MtVector4 getAngle(const MtVector3& pos, const f32& phase);  // vtable slot 28
    virtual MtVector3 getForce(const MtVector3& pos);  // vtable slot 29
    u32 getType();
    void setAmplification(f32 amp);
    void setPhase(f32 phase);
    void setFrequency(f32 freq);
    void setElapsedPhase(f32);
    f32 getAmplification() const;
    f32 getPhase() const;
    f32 getFrequency() const;
    f32 getElapsedPhase() const;
    u32 getGroup() const;
    void setGroup(u32 value);
    virtual sScene::Node* getSceneNode();  // vtable slot 30
    virtual void getDrawUnitState(u32& type, u32& priority) const;  // vtable slot 18
protected:
    u32 mType;  // offset: 0xf7c
    f32 mAmplification;  // offset: 0xf80
    f32 mFrequency;  // offset: 0xf84
    f32 mPhase;  // offset: 0xf88
    f32 mElapsedPhase;  // offset: 0xf8c
    u32 mWindGroup;  // offset: 0xf90
public:
    static MyDTI DTI;
};

class uGrassWindDirection : public uGrassWind
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
    uGrassWindDirection(MtFloat3 Direction);
    virtual ~uGrassWindDirection();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void move();  // vtable slot 9
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
    virtual void getAABB(MtAABB& aabb);  // vtable slot 24
    virtual MtVector4 getInfo();  // vtable slot 25
    virtual MtVector3 getDirection(const MtVector3& pos);  // vtable slot 27
    virtual MtVector4 getAngle(const MtVector3& pos, const f32& phase);  // vtable slot 28
    virtual MtVector3 getForce(const MtVector3& pos);  // vtable slot 29
    void setDirection(const MtVector3& direction);
    virtual void getDrawUnitState(u32& type, u32& priority) const;  // vtable slot 18
protected:
    MtFloat3 mDirection;  // offset: 0xf94
    uGrassWind::cSwingParameters mParam;  // offset: 0xfa0
public:
    static MyDTI DTI;
};

inline void* uGrassWind::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGrassWind::cSwingParameters::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGrassWindDirection::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
