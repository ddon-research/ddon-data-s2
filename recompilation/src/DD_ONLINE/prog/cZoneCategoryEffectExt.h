#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtColor.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../XFramework/cZoneContents.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;

// Declarations
class cZCEFLControl;
class cZCEffectColorControl;
class cZCEffectColorControlBase;
class cZCEffectColorControlColorOff;
class cZCEffectColorControlDayOff;
class cZCEffectColorControlDisregard;
class cZCEffectColorControlNightOff;
class cZCEffectColorControlWater;
class cZCEffectControl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cZCEffectColorControl : public cZoneContents
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
    cZCEffectColorControl();
    virtual ~cZCEffectColorControl() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    u32 getCorrectType() const;
    const MtColor& getColor() const;
    f32 getColorBlend() const;
    f32 getIntensity() const;
    f32 getIntensityBlend() const;
    const MtColor& getShadowColor() const;
    f32 getShadowColorBlend() const;
    f32 getShadowIntensity() const;
    f32 getShadowIntensityBlend() const;
    f32 getEnvMapPowerScale() const;
    bool getUseSkyColor() const;
    bool getUseShadowColor() const;
    bool getUseMixColor() const;
    bool getUsePointLightSupplement() const;
    void setDefaultColor();
    void copyColorToShadowColor();
protected:
    u32 mCorrectType;  // offset: 0x1c
private:
    MtColor mColor;  // offset: 0x20
    f32 mColorBlend;  // offset: 0x24
    f32 mIntensity;  // offset: 0x28
    f32 mIntensityBlend;  // offset: 0x2c
    MtColor mShadowColor;  // offset: 0x30
    f32 mShadowColorBlend;  // offset: 0x34
    f32 mShadowIntensity;  // offset: 0x38
    f32 mShadowIntensityBlend;  // offset: 0x3c
    f32 mEnvMapPowerScale;  // offset: 0x40
    bool mUseSkyColor;  // offset: 0x44
    bool mUseShadowColor;  // offset: 0x45
    bool mUseMixColor;  // offset: 0x46
    bool mUsePointLightSupplement;  // offset: 0x47
public:
    static MyDTI DTI;
};

class cZCEffectColorControlBase : public cZCEffectColorControl
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
    cZCEffectColorControlBase();
public:
    static MyDTI DTI;
};

class cZCEffectColorControlColorOff : public cZCEffectColorControl
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
    cZCEffectColorControlColorOff();
public:
    static MyDTI DTI;
};

class cZCEffectColorControlDayOff : public cZCEffectColorControl
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
    cZCEffectColorControlDayOff();
public:
    static MyDTI DTI;
};

class cZCEffectColorControlDisregard : public cZCEffectColorControl
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
    cZCEffectColorControlDisregard();
public:
    static MyDTI DTI;
};

class cZCEffectColorControlNightOff : public cZCEffectColorControl
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
    cZCEffectColorControlNightOff();
public:
    static MyDTI DTI;
};

class cZCEffectColorControlWater : public cZCEffectColorControl
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
    cZCEffectColorControlWater();
public:
    static MyDTI DTI;
};

class cZCEffectControl : public cZoneContents
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
    cZCEffectControl();
public:
    static MyDTI DTI;
};

class cZCEFLControl : public cZCEffectControl
{
public:
    class MyDTI;
    class cResourceSet;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cResourceSet : public MtObject
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
        cResourceSet();
        virtual ~cResourceSet() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        u32 getResourceType() const;
        void setResourceType(u32 type);
        u32 getIndexNo() const;
        void setIndexNo(u32 index);
        u32 getElementNo() const;
        void setElementNo(u32 element);
    private:
        u32 mResourceType;  // offset: 0x8
        u32 mIndexNo;  // offset: 0xc
        u32 mElementNo;  // offset: 0x10
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
    cZCEFLControl();
    virtual ~cZCEFLControl();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    cResourceSet* getResourceSet(u32 Index);
    void setResourceSet(cResourceSet* pResourceSet, u32 Index);
    u32 getResourceSetNum();
    void setResourceSetNum(u32 Num);
    MtTypedArray<cResourceSet>* getResourceSetList();
private:
    MtTypedArray<cResourceSet> mSetList;  // offset: 0x20
public:
    static MyDTI DTI;
    static const u32 ZONE_UNIT_HANDLE_MAX = 32;
};

inline void* cZCEFLControl::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cZCEFLControl::cZCEFLControl() {
    this->mSetList.::MtArray::mpArray = nullptr;
    this->mSetList.::MtArray::mLength = 0;
    this->mSetList.::MtArray::mBufsiz = 0;
}

inline u32 cZCEFLControl::getResourceSetNum() {
    return this->mSetList.::MtArray::mLength;
}

inline void* cZCEFLControl::cResourceSet::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void cZCEFLControl::cResourceSet::setResourceType(u32 type) {
    this->mResourceType = type;
}

inline void cZCEFLControl::cResourceSet::setIndexNo(u32 index) {
    this->mIndexNo = index;
}

inline void cZCEFLControl::cResourceSet::setElementNo(u32 element) {
    this->mElementNo = element;
}

inline void* cZCEffectColorControl::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cZCEffectColorControlBase::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cZCEffectColorControlColorOff::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cZCEffectColorControlDayOff::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cZCEffectColorControlDisregard::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cZCEffectColorControlNightOff::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cZCEffectColorControlWater::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cZCEffectControl::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cZCEffectControl::cZCEffectControl() {
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void* cZCEFLControl::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cZCEFLControl::DTI)->memAlloc(sz, align, ::cZCEFLControl::DTI.::MtDTI::getID());
}

inline void cZCEFLControl::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cZCEFLControl::DTI)->memFree(p_addr);
}

inline MtAllocator* cZCEFLControl::cResourceSet::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::cZCEFLControl::cResourceSet::DTI);
}

inline void cZCEFLControl::cResourceSet::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cZCEFLControl::cResourceSet::DTI)->memFree(p_addr);
}

inline void cZCEffectColorControl::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cZCEffectColorControl::DTI)->memFree(p_addr);
}

inline void cZCEffectColorControlBase::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cZCEffectColorControlBase::DTI)->memFree(p_addr);
}

inline void cZCEffectColorControlColorOff::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cZCEffectColorControlColorOff::DTI)->memFree(p_addr);
}

inline void cZCEffectColorControlDayOff::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cZCEffectColorControlDayOff::DTI)->memFree(p_addr);
}

inline void cZCEffectColorControlDisregard::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cZCEffectColorControlDisregard::DTI)->memFree(p_addr);
}

inline void cZCEffectColorControlNightOff::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cZCEffectColorControlNightOff::DTI)->memFree(p_addr);
}

inline void cZCEffectColorControlWater::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cZCEffectColorControlWater::DTI)->memFree(p_addr);
}

inline void* cZCEffectControl::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cZCEffectControl::DTI)->memAlloc(sz, align, ::cZCEffectControl::DTI.::MtDTI::getID());
}

inline void cZCEffectControl::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cZCEffectControl::DTI)->memFree(p_addr);
}
