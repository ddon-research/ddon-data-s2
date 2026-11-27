#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "uShlGenerator.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
class cPlActWpnBow;
class cShlParamBase;

// Declarations
class cShlParamArrowRainCtrl;
class uShlArrowRainCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamArrowRainCtrl : public cShlParamGenerator
{
public:
    class MyDTI;
    class cShootCtrlParamArrowRainCtrl;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cShootCtrlParamArrowRainCtrl : public cShlParamGenerator::cShootCtrlParam
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
        cShootCtrlParamArrowRainCtrl();
        virtual ~cShootCtrlParamArrowRainCtrl() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        u32 getUnderArrowNum() const;
        s32 getExplodeShlNo() const;
        f32 getRadiusRate() const;
    private:
        u32 underArrowNum;  // offset: 0x44
        s32 explodeShlNo;  // offset: 0x48
        f32 radiusRate;  // offset: 0x4c
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
    cShlParamArrowRainCtrl();
    virtual ~cShlParamArrowRainCtrl() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
    virtual void addShlList(const cShlParamGenerator* pParam);  // vtable slot 12
public:
    static MyDTI DTI;
};

class uShlArrowRainCtrl : public uShlGenerator
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
    const cShlParamArrowRainCtrl* getShlParam() const;
    uShlArrowRainCtrl();
    virtual ~uShlArrowRainCtrl();
    virtual void setup();  // vtable slot 6
    virtual void initSub();  // vtable slot 177
    virtual void updateSub();  // vtable slot 175
    virtual void updateEfcHandle();  // vtable slot 58
    void setUseArrowNum(u32 num);
protected:
    virtual void setShl(u32 shlNo, const MtVector3& offset, f32 degX, f32 degY);  // vtable slot 186
private:
    bool mIsExplosion;  // offset: 0x2ad0
    u32 mUseArrowNum;  // offset: 0x2ad4
public:
    static MyDTI DTI;
};

inline void* cShlParamArrowRainCtrl::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamArrowRainCtrl::cShlParamArrowRainCtrl() {
}

inline void* cShlParamArrowRainCtrl::cShootCtrlParamArrowRainCtrl::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamArrowRainCtrl::cShootCtrlParamArrowRainCtrl::cShootCtrlParamArrowRainCtrl() : underArrowNum(0xffffffffu), explodeShlNo(-1), radiusRate(1.0f) {
}

inline u32 cShlParamArrowRainCtrl::cShootCtrlParamArrowRainCtrl::getUnderArrowNum() const {
    return this->underArrowNum;
}

inline f32 cShlParamArrowRainCtrl::cShootCtrlParamArrowRainCtrl::getRadiusRate() const {
    return this->radiusRate;
}

inline void* uShlArrowRainCtrl::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uShlArrowRainCtrl::uShlArrowRainCtrl() {
    this->mUseArrowNum = 1;
    this->mIsExplosion = false;
}

inline void uShlArrowRainCtrl::setUseArrowNum(u32 num) {
    this->mUseArrowNum = num;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"
#include "uShlBase.h"

inline void* cShlParamArrowRainCtrl::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cShlParamArrowRainCtrl::DTI)->memAlloc(sz, align, ::cShlParamArrowRainCtrl::DTI.::MtDTI::getID());
}

inline void cShlParamArrowRainCtrl::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cShlParamArrowRainCtrl::DTI)->memFree(p_addr);
}

inline void cShlParamArrowRainCtrl::cShootCtrlParamArrowRainCtrl::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cShlParamArrowRainCtrl::cShootCtrlParamArrowRainCtrl::DTI)->memFree(p_addr);
}

inline void* uShlArrowRainCtrl::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uShlArrowRainCtrl::DTI)->memAlloc(sz, align, ::uShlArrowRainCtrl::DTI.::MtDTI::getID());
}

inline void uShlArrowRainCtrl::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uShlArrowRainCtrl::DTI)->memFree(p_addr);
}

inline const cShlParamArrowRainCtrl* uShlArrowRainCtrl::getShlParam() const {
    return static_cast<const cShlParamArrowRainCtrl*>(this->::uShlBase::mpShlParam2);
}
