#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtEaseCurve.h"
#include "../../MT/MtObject.h"
#include "cpShlBase.h"
#include "nDDOUtility.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtHermiteCurve;
class MtObject;
class MtPropertyList;

// Declarations
class cShlParamCompKeyFrame;
class cpShlKeyFrame;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
namespace nDDOUtility { using cKeyFrameValueF32 = nDDOUtility::cKeyFrameValue<float, MtObject>; }
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamCompKeyFrame : public cShlParamComponent
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
    virtual const MtDTI& getComponentDTI() const;  // vtable slot 6
    cShlParamCompKeyFrame();
    virtual ~cShlParamCompKeyFrame() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void copy(const cShlParamComponent* pParamBase);  // vtable slot 7
public:
    TYPE type;  // offset: 0x8
    CURVE curve;  // offset: 0xc
    f32 valueScale;  // offset: 0x10
    f32 effectTimer;  // offset: 0x14
    nDDOUtility::cKeyFrameValueF32 keyFrame;  // offset: 0x18
    static MyDTI DTI;
};

class cpShlKeyFrame : public cpShlBase
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
    cpShlKeyFrame();
    virtual void initSub();  // vtable slot 15
    virtual void updateSub();  // vtable slot 16
    void updateKeyFrame(f32 value);
private:
    f32 mTimeMax;  // offset: 0x58
    MtHermiteCurve mCurve;  // offset: 0x5c
public:
    static MyDTI DTI;
};

inline void* cShlParamCompKeyFrame::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamCompKeyFrame::cShlParamCompKeyFrame() : type(static_cast<cShlParamCompKeyFrame::TYPE>(0)), curve(static_cast<cShlParamCompKeyFrame::CURVE>(0)), valueScale(1.0f), effectTimer(0.0f) {
    keyFrame.value[0].value = 1.0f;
}

inline void* cpShlKeyFrame::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
