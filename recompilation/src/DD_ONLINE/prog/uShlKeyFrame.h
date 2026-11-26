#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtEaseCurve.h"
#include "../../MT/MtObject.h"
#include "nDDOUtility.h"
#include "uShlBase.h"
#include "uShlSpeed.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtHermiteCurve;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class cShlParamBase;
class uShlBase;
class uShlSpeed;

// Declarations
template <typename shlclass, typename ParentClass> class cShlParamKeyFrame;
template <typename ParentClass> class uShlKeyFrame;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
namespace nDDOUtility { using cKeyFrameValueF32 = nDDOUtility::cKeyFrameValue<float, MtObject>; }
using size_t = _Sizet;
using u32 = unsigned int;

template <>
class cShlParamKeyFrame<uShlKeyFrame<uShlBase>, cShlParamBase> : public cShlParamBase
{
public:
    enum TYPE
    {
        TYPE_SCALE = 0,
        TYPE_SPEED = 1,
        TYPE_TIME_EFFECT = 2,
    };
    enum CURVE
    {
        CURVE_LINEAR = 0,
        CURVE_SPLINE = 1,
    };
public:
    class MyDTI;
public:
    using ThisClass = cShlParamKeyFrame<uShlKeyFrame<uShlBase>, cShlParamBase>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
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
    virtual MtDTI& getShlDTI() const;  // vtable slot 6
    cShlParamKeyFrame();
    virtual ~cShlParamKeyFrame();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    TYPE type;  // offset: 0x160
    CURVE curve;  // offset: 0x164
    f32 valueScale;  // offset: 0x168
    f32 effectTimer;  // offset: 0x16c
    nDDOUtility::cKeyFrameValueF32 keyFrame;  // offset: 0x170
    static MyDTI DTI;
};

template <>
class cShlParamKeyFrame<uShlKeyFrame<uShlSpeed>, cShlParamSpeed> : public cShlParamSpeed
{
public:
    enum TYPE
    {
        TYPE_SCALE = 0,
        TYPE_SPEED = 1,
        TYPE_TIME_EFFECT = 2,
    };
    enum CURVE
    {
        CURVE_LINEAR = 0,
        CURVE_SPLINE = 1,
    };
public:
    class MyDTI;
public:
    using ThisClass = cShlParamKeyFrame<uShlKeyFrame<uShlSpeed>, cShlParamSpeed>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
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
    virtual MtDTI& getShlDTI() const;  // vtable slot 6
    cShlParamKeyFrame();
    virtual ~cShlParamKeyFrame();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    TYPE type;  // offset: 0x1f0
    CURVE curve;  // offset: 0x1f4
    f32 valueScale;  // offset: 0x1f8
    f32 effectTimer;  // offset: 0x1fc
    nDDOUtility::cKeyFrameValueF32 keyFrame;  // offset: 0x200
    static MyDTI DTI;
};

inline cShlParamKeyFrame<uShlKeyFrame<uShlBase>, cShlParamBase>::cShlParamKeyFrame() : type(static_cast<TYPE>(0)), curve(static_cast<CURVE>(0)), valueScale(1.0f), effectTimer(0.0f) {
    keyFrame.value[0].value = 1.0f;
}

inline cShlParamKeyFrame<uShlKeyFrame<uShlSpeed>, cShlParamSpeed>::cShlParamKeyFrame() : type(static_cast<TYPE>(0)), curve(static_cast<CURVE>(0)), valueScale(1.0f), effectTimer(0.0f) {
    keyFrame.value[0].value = 1.0f;
}

template <>
class uShlKeyFrame<uShlBase> : public uShlBase
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
    uShlKeyFrame();
    virtual ~uShlKeyFrame();
    virtual void initSub();  // vtable slot 177
    virtual void updateSub();  // vtable slot 175
    void updateKeyFrame(f32 value);
    void setParam_Speed(f32 spd);
private:
    f32 mTimeMax;  // offset: 0x2ab0
    MtHermiteCurve mCurve;  // offset: 0x2ab4
public:
    static MyDTI DTI;
};

template <>
class uShlKeyFrame<uShlSpeed> : public uShlSpeed
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
    uShlKeyFrame();
    virtual ~uShlKeyFrame();
    virtual void initSub();  // vtable slot 177
    virtual void updateSub();  // vtable slot 175
    void updateKeyFrame(f32 value);
    void setParam_Speed(f32 spd);
private:
    f32 mTimeMax;  // offset: 0x2b88
    MtHermiteCurve mCurve;  // offset: 0x2b8c
public:
    static MyDTI DTI;
};
