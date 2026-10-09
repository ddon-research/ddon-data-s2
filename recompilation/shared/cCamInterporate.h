#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtMatrix;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
class uCamera;

// Declarations
class cCamInterAll;
class cCamInterporateAng;
class cCamInterporateAng3Time;
class cCamInterporateRange;
class cCamInterporateRangeAng;
class cCamInterporateVec3;
template <typename Type> class cCamInterporate;
template <typename Type> class cCamInterporateTime;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using cCamInterporateF32 = cCamInterporate<float>;
using cCamInterporateVec3Time = cCamInterporateTime<MtVector3>;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

template <>
class cCamInterporate<MtVector3> : public MtObject
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
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete(void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
    cCamInterporate();
    virtual ~cCamInterporate();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    cCamInterporate<MtVector3>& operator=(const cCamInterporate<MtVector3>& r);
    virtual void copy(const cCamInterporate<MtVector3>* pParam);  // vtable slot 6
    void initialize(const MtVector3& pos, const MtVector3& velocity, f32 spring);
    const MtVector3& interporate(const MtVector3& targetPos, f32 rate);
    const MtVector3& interporate(const MtVector3& nowPos, const MtVector3& targetPos, f32 rate);
    void setNow(const MtVector3& vec);
    void setVelocity(const MtVector3& vec);
    void setSpring(f32 spring);
    const MtVector3& getNow() const;
    f32 getSpring() const;
    void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);
protected:
    void calcAngle(f32& outX, f32& outY, const MtVector3& vec) const;
private:
    virtual MtVector3 calcDisplace(const MtVector3& now, const MtVector3& end);  // vtable slot 7
    virtual MtVector3 calcAccel(const MtVector3& displace, const MtVector3& velocity);  // vtable slot 8
    virtual void updateVelocity(const MtVector3& accel);  // vtable slot 9
    virtual void updatePosition(const MtVector3& velocity);  // vtable slot 10
protected:
    MtVector3 mNow;  // offset: 0x10
    MtVector3 mVelocity;  // offset: 0x20
    f32 mSpring;  // offset: 0x30
    f32 mDamping;  // offset: 0x34
public:
    static MyDTI DTI;
};

template <>
class cCamInterporate<float> : public MtObject
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
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete(void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
    cCamInterporate();
    virtual ~cCamInterporate();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    cCamInterporate<float>& operator=(const cCamInterporate<float>& r);
    virtual void copy(const cCamInterporate<float>* pParam);  // vtable slot 6
    void initialize(const float& pos, const float& velocity, f32 spring);
    const float& interporate(const float& targetPos, f32 rate);
    void setNow(const float& vec);
    void setVelocity(const float& vec);
    void setSpring(f32 spring);
    const float& getNow() const;
private:
    virtual float calcDisplace(const float& now, const float& end);  // vtable slot 7
    virtual float calcAccel(const float& displace, const float& velocity);  // vtable slot 8
    virtual void updateVelocity(const float& accel);  // vtable slot 9
    virtual void updatePosition(const float& velocity);  // vtable slot 10
protected:
    float mNow;  // offset: 0x8
    float mVelocity;  // offset: 0xc
    f32 mSpring;  // offset: 0x10
    f32 mDamping;  // offset: 0x14
public:
    static cCamInterporate<f32>::MyDTI DTI;
};

template <typename Type>
class cCamInterporateTime : public cCamInterporate<Type>
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
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete(void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
    cCamInterporateTime();
    // Address: 0x0195f5a0 - 0x0195f5a1 (1 bytes)
    virtual ~cCamInterporateTime() {}
    void initializeTime(const Type& pos, const Type& velocity, f32 spring, f32 time, f32 nearlyZero);
    const Type& interporateTime(const Type& targetPos, f32 time);
    virtual void copy(const cCamInterporate<Type>* pParam);  // vtable slot 6
    bool endCheck();
    void end();
    bool isEnd() const;
private:
    bool mIsEnd;  // offset: 0x38
    f32 mTime;  // offset: 0x3c
    f32 mTimeMax;  // offset: 0x40
    f32 mStartSpring;  // offset: 0x44
    f32 mNearlyZero;  // offset: 0x48
    Type mDisplace;  // offset: 0x50
public:
    static MyDTI DTI;
};

class cCamInterporateAng : public cCamInterporateF32
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
    cCamInterporateAng();
    // Address: 0x0195fcc0 - 0x0195fcc1 (1 bytes)
    virtual ~cCamInterporateAng() {}
    virtual f32 calcDisplace(const f32& now, const f32& end);  // vtable slot 7
    virtual f32 calcAccel(const f32& displace, const f32& velocity);  // vtable slot 8
    virtual void updateVelocity(const f32& accel);  // vtable slot 9
    virtual void updatePosition(const f32& velocity);  // vtable slot 10
public:
    static MyDTI DTI;
};

class cCamInterporateAng3Time : public cCamInterporateVec3Time
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
    cCamInterporateAng3Time();
    // Address: 0x0195fd60 - 0x0195fd61 (1 bytes)
    virtual ~cCamInterporateAng3Time() {}
private:
    virtual MtVector3 calcDisplace(const MtVector3& now, const MtVector3& end);  // vtable slot 7
    virtual MtVector3 calcAccel(const MtVector3& displace, const MtVector3& velocity);  // vtable slot 8
    virtual void updateVelocity(const MtVector3& accel);  // vtable slot 9
    virtual void updatePosition(const MtVector3& velocity);  // vtable slot 10
    MtVector3 getRadianDifferenceVec3(const MtVector3& v0, const MtVector3& v1);
    void clampRadianVec3(MtVector3& vec);
public:
    static MyDTI DTI;
};

class cCamInterporateRange : public cCamInterporate<MtVector3>
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
    cCamInterporateRange();
    // Address: 0x019513e0 - 0x019513e1 (1 bytes)
    virtual ~cCamInterporateRange() {}
    const MtVector3& interporateSph(const MtVector3&, f32, f32);
    const MtVector3& interporateTransform(const MtVector3& targetPos, const MtMatrix& m, const MtVector3& vec, f32 rate);
private:
    bool calcAdjustElem(f32& target, f32 now, f32 range) const;
public:
    static MyDTI DTI;
};

class cCamInterporateRangeAng : public cCamInterporateAng
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
    cCamInterporateRangeAng();
    // Address: 0x019513f0 - 0x019513f1 (1 bytes)
    virtual ~cCamInterporateRangeAng() {}
    f32 interporateRangeAng(f32 targetPos, f32 radius, f32 rate);
public:
    static MyDTI DTI;
};

class cCamInterporateVec3 : public cCamInterporate<MtVector3>
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
    cCamInterporateVec3();
    // Address: 0x01959300 - 0x01959301 (1 bytes)
    virtual ~cCamInterporateVec3() {}
    const MtVector3& interporateRot(const MtVector3& targetPos, const MtVector3& center, f32 rate);
    const MtVector3& interporateRot(f32 iX, f32 iY, f32 iD, const MtVector3& center, f32 rate);
    const MtVector3& interporateForTarget(const MtVector3& targetPos, f32 rate);
public:
    static MyDTI DTI;
};

class cCamInterAll : public MtObject
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
    cCamInterAll();
    // Address: 0x0195f6e0 - 0x0195f6e1 (1 bytes)
    virtual ~cCamInterAll() {}
private:
    void interporateAllInit(f32 time);
public:
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    cCamInterAll& operator=(const cCamInterAll& r);
    void copy(const cCamInterAll* pParam);
    void initializeAll(uCamera* pCam, f32 frame, f32 startSpring);
    void initializeAll(const MtVector3& eye, const MtVector3& look, const MtVector3& up, f32 fov, f32 frame, f32 startSpring);
    bool interporateAllRR(const MtVector3&, const MtVector3&, const MtVector3&, const MtVector3&, const MtVector3&, f32, f32);
    bool interporateAllXR(const MtVector3& eye, const MtVector3& look, const MtVector3& lookCenter, const MtVector3& up, f32 fov, f32 time);
    bool interporateAllRX(const MtVector3&, const MtVector3&, const MtVector3&, const MtVector3&, f32, f32);
    bool interporateAllXX(const MtVector3& eye, const MtVector3& look, const MtVector3& up, f32 fov, f32 time);
    void reset();
    const MtVector3& getEyePos() const;
    const MtVector3& getLookPos() const;
    const MtVector3& getUpVec() const;
    f32 getFov() const;
    void end();
    bool IsEnd() const;
    void setInterFrame(f32 frame);
    void setSprintC(f32);
    void setSprintT(f32);
    void setSprintU(f32);
    void setSprintF(f32);
private:
    bool mIsEnd;  // offset: 0x8
    f32 mInterFrameNow;  // offset: 0xc
    f32 mInterFrame;  // offset: 0x10
    cCamInterporateVec3 mInterC;  // offset: 0x20
    cCamInterporateVec3 mInterT;  // offset: 0x60
    cCamInterporateVec3 mInterU;  // offset: 0xa0
    cCamInterporateF32 mInterF;  // offset: 0xe0
    MtVector3 mInitC;  // offset: 0x100
    MtVector3 mInitT;  // offset: 0x110
    MtVector3 mInitU;  // offset: 0x120
    f32 mInitF;  // offset: 0x130
public:
    static MyDTI DTI;
};

// Generic (024 T808): every instance that renders gives this body; cCamInterporate.cpp instantiates each for the body oracle.
template <typename Type>
const MtDTI& cCamInterporateTime<Type>::getDTI() const {
    return cCamInterporateTime<Type>::DTI;
}
