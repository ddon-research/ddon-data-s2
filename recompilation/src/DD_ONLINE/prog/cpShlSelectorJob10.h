#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "cpShlBase.h"
#include "cpShlSelector.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cHitInfo;
class cShlParamComponent;

// Declarations
class cShlParamCompSelectorJob10Cs08;
class cpShlSelectorJob10Cs08;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamCompSelectorJob10Cs08 : public cShlParamCompSelector
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
    virtual const MtDTI& getComponentDTI() const;  // vtable slot 6
    virtual ~cShlParamCompSelectorJob10Cs08();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void copy(const cShlParamComponent* pParamBase);  // vtable slot 7
public:
    MtTypedArray<cShlParamComponent> mShlList;  // offset: 0x28
    bool mIsReqSe;  // offset: 0x48
    static MyDTI DTI;
};

class cpShlSelectorJob10Cs08 : public cpShlSelector
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
    virtual void initSub();  // vtable slot 15
    virtual void kill();  // vtable slot 8
    virtual void callbackReplaceHitInfo_Atk(cHitInfo* pHitInfo);  // vtable slot 17
protected:
    virtual u32 getSelectedIndex() const;  // vtable slot 18
protected:
    bool mIsChargeMax;  // offset: 0x58
public:
    static MyDTI DTI;
};

inline void* cShlParamCompSelectorJob10Cs08::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cpShlSelectorJob10Cs08::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
