#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "cZoneUnitCtrl.h"
#include "../../XFramework/uLight.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
class cZoneUnitCtrl;
class uDDOModel;
class uLight;

// Declarations
class Bind;
class uPointLightExt;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class Bind : public MtObject
{
public:
    enum
    {
        TYPE_NONE = 0,
        TYPE_CAMERA_TARGET = 1,
        TYPE_CAMERA_LANTERN = 2,
        TYPE_CAMERA_SCARE = 3,
        TYPE_MODEL_EM = 4,
        TYPE_MODEL_SM = 5,
        TYPE_MODEL_IT = 6,
        TYPE_MODEL_PL = 7,
        TYPE_MODEL_PL_CAM = 8,
        TYPE_MODEL_CHR_CAM = 9,
        TYPE_NUM = 10,
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
    Bind();
    virtual ~Bind();
    const Bind& operator=(const Bind& other);
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    void applyUnit(uLight* pul, u32 type);
    uDDOModel* getTarget();
public:
    s32 mBindType;  // offset: 0x8
    u8 mLayoutNo0;  // offset: 0xc
    u16 mLayoutNo1;  // offset: 0xe
    s32 mJointNo;  // offset: 0x10
    MtVector3 mFakeAngle;  // offset: 0x20
    static MyDTI DTI;
};

class uPointLightExt : public uPointLight
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
    uPointLightExt();
    virtual ~uPointLightExt();
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void moveAfter();  // vtable slot 10
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    bool isDisableZone() const;
    void setDisableZone(bool v);
    const MtVector3& getOffset() const;
    void setOffset(const MtVector3& ofs);
    void setEnableSchedulerWorldOffset(bool f);
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
    void resetZoneUnitCtrl();
    const MtVector3& getBaseLightColor() const;
    void setBaseLightColor(const MtVector3& v);
private:
    void setColor(const MtVector3&);
public:
    Bind mBind;  // offset: 0x480
protected:
    cZoneUnitCtrl mZoneUnitCtrl;  // offset: 0x4b0
    bool mDisableZone;  // offset: 0x4d0
    bool mEnableSchedulerWorldOffset;  // offset: 0x4d1
    bool mEnableMoveDraw;  // offset: 0x4d2
    bool mRnoPLE;  // offset: 0x4d3
    bool mMoveSkip;  // offset: 0x4d4
    f32 mZoneIntensityBlend;  // offset: 0x4d8
    MtVector3 mOffset;  // offset: 0x4e0
    MtVector3 mBaseLightColor;  // offset: 0x4f0
public:
    static MyDTI DTI;
};

inline void* Bind::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uPointLightExt::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void Bind::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::Bind::DTI)->memFree(p_addr);
}

inline Bind::Bind() {
    this->mBindType = 0;
    this->mLayoutNo0 = 0;
    this->mLayoutNo1 = 0;
    this->mJointNo = -1;
    this->mFakeAngle = ::MtVector3::Zero;
}

inline MtAllocator* uPointLightExt::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::uPointLightExt::DTI);
}

inline void uPointLightExt::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uPointLightExt::DTI)->memFree(p_addr);
}
