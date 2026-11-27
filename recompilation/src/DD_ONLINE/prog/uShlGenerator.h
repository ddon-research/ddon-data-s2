#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "uShlBase.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
class cPlActWpnBow;

// Declarations
class cShlParamGenerator;
class uShlGenerator;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamGenerator : public cShlParamBase
{
public:
    enum
    {
        CO_NONE = 0,
        CO_ACTIVE_OWNER_DELTA_TIME = 2,
        CO_CREATE_TO_TARGET_POS = 4,
        CO_OFFSET_DIR_INIT_TARGET = 8,
        CO_CREATE_INIT_POS = 16,
        CO_CREATE_CONTROL = 32,
    };
public:
    class MyDTI;
    class cShootCtrlParam;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cShootCtrlParam : public MtObject
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
        cShootCtrlParam();
        virtual ~cShootCtrlParam() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    public:
        f32 waitFrame;  // offset: 0x8
        s32 shlNo;  // offset: 0xc
        MtVector3 offset;  // offset: 0x10
        MtVector3 offsetRnd;  // offset: 0x20
        f32 degX;  // offset: 0x30
        f32 degY;  // offset: 0x34
        f32 degRndX;  // offset: 0x38
        f32 degRndY;  // offset: 0x3c
        s32 joint;  // offset: 0x40
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
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createPropertyEffect(MtPropertyList& s);  // vtable slot 8
    cShlParamGenerator();
    virtual ~cShlParamGenerator();
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
    virtual void addShlList(const cShlParamGenerator* pParam);  // vtable slot 12
public:
    bool isOwnerScaleOffset;  // offset: 0x160
    MtArray shlList;  // offset: 0x168
    u32 generatorOption;  // offset: 0x188
    static MyDTI DTI;
};

class uShlGenerator : public uShlBase
{
    friend class cPlActWpnBow;
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
    const cShlParamGenerator* getShlParam() const;
    uShlGenerator();
    virtual ~uShlGenerator();
    virtual void setup();  // vtable slot 6
    virtual void initSub();  // vtable slot 177
    virtual void updateSub();  // vtable slot 175
    u32 getSetNum() const;
protected:
    virtual void setShl(u32 shlNo, const MtVector3& offset, f32 degX, f32 degY);  // vtable slot 186
    u32 getShlSetNum();
public:
    void setShlSetLimit(u32 limit);
protected:
    u32 mShlSetNum;  // offset: 0x2ab0
    f32 mShlSetFrame;  // offset: 0x2ab4
    u32 mShlSetLimit;  // offset: 0x2ab8
    bool mIsLockon;  // offset: 0x2abc
    MtVector3 mInitDir;  // offset: 0x2ac0
public:
    static MyDTI DTI;
};

inline void* cShlParamGenerator::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamGenerator::cShlParamGenerator() {
    this->isOwnerScaleOffset = false;
    this->generatorOption = 0;
    this->shlList.mAutoDelete = true;
}

inline void* cShlParamGenerator::cShootCtrlParam::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamGenerator::cShootCtrlParam::cShootCtrlParam() {
    this->waitFrame = 0.0f;
    this->shlNo = -1;
    this->degRndX = 0.0f;
    this->degRndY = 0.0f;
    this->degX = 0.0f;
    this->degY = 0.0f;
    this->offsetRnd.z = 0.0f;
    this->offsetRnd.pad_ = 0.0f;
    this->offsetRnd.x = 0.0f;
    this->offsetRnd.y = 0.0f;
    this->offset.z = 0.0f;
    this->offset.pad_ = 0.0f;
    this->offset.x = 0.0f;
    this->offset.y = 0.0f;
    this->joint = -1;
}

inline void* uShlGenerator::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void* cShlParamGenerator::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cShlParamGenerator::DTI)->memAlloc(sz, align, ::cShlParamGenerator::DTI.::MtDTI::getID());
}

inline void cShlParamGenerator::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cShlParamGenerator::DTI)->memFree(p_addr);
}

inline MtAllocator* cShlParamGenerator::cShootCtrlParam::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::cShlParamGenerator::cShootCtrlParam::DTI);
}

inline void* uShlGenerator::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uShlGenerator::DTI)->memAlloc(sz, align, ::uShlGenerator::DTI.::MtDTI::getID());
}

inline void uShlGenerator::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uShlGenerator::DTI)->memFree(p_addr);
}

inline const cShlParamGenerator* uShlGenerator::getShlParam() const {
    return static_cast<const cShlParamGenerator*>(this->::uShlBase::mpShlParam2);
}
