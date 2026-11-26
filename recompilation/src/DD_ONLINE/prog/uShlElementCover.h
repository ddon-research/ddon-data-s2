#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../generated/shared/nDDOGame.h"
#include "nDDOUtility.h"
#include "uShlCustomCondition.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cEfcHandle;
class cShlParamBase;

// Declarations
class cShlParamElemntCover;
class uShlElementCover;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamElemntCover : public cShlParamCustomConditionBase
{
public:
    class MyDTI;
    struct stEffectSeInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stEffectSeInfo
    {
    public:
        stEffectSeInfo();
        void copy(const cShlParamElemntCover::stEffectSeInfo& src);
    public:
        u32 mEpvIndex;  // offset: 0x0
        u32 mEpvElement;  // offset: 0x4
        s32 mSeReqNo;  // offset: 0x8
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
    cShlParamElemntCover();
    virtual void createProperty(MtPropertyList& proplist);  // vtable slot 4
    virtual void createPropertyEffect(MtPropertyList& s);  // vtable slot 8
    virtual void createPropertySE(MtPropertyList& s);  // vtable slot 9
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
    bool getIsCondition();
public:
    f32 mAdjustRateCover[10];  // offset: 0x1bc
    f32 adjustRateDamage[10];  // offset: 0x1e4
    nDDOUtility::cArray<stEffectSeInfo, 7> mEffectInfo;  // offset: 0x20c
    static MyDTI DTI;
};

class uShlElementCover : public uShlCustomConditionBase
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
    const cShlParamElemntCover* getShlParam() const;
    uShlElementCover();
    virtual ~uShlElementCover() {}
    virtual void setup();  // vtable slot 6
    virtual void initSub();  // vtable slot 177
    virtual void kill();  // vtable slot 16
    virtual void updateEfcHandle();  // vtable slot 58
    void setCoverEffect();
    void setCoverSe();
    void setElementTypeCover(nDDOGame::ELEMENT_TYPE type);
    virtual void reCreateInfo();  // vtable slot 186
private:
    nDDOGame::ELEMENT_TYPE mElementTypeCover;  // offset: 0x2ad4
    cEfcHandle* mpCoverEffHandle;  // offset: 0x2ad8
public:
    static MyDTI DTI;
};

inline void* cShlParamElemntCover::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamElemntCover::cShlParamElemntCover() {
    for (u32 i = 0; i < 10u; i++) {
        mAdjustRateCover[i] = 1.0f;
        adjustRateDamage[i] = 0.0f;
    }
}

inline cShlParamElemntCover::stEffectSeInfo::stEffectSeInfo() : mEpvIndex(0u), mEpvElement(0u), mSeReqNo(0) {
}

inline void* uShlElementCover::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
