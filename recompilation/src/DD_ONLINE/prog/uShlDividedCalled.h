#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "uShlBase.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtDTI;
class MtObject;
class MtPropertyList;

// Declarations
class cShlParamDividedCalled;
class uShlDividedCalled;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamDividedCalled : public cShlParamBase
{
public:
    class MyDTI;
    class cDividedCalledParam;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cDividedCalledParam : public MtObject
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
        cDividedCalledParam();
        virtual ~cDividedCalledParam() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual void createPropertyTool(MtPropertyList& s);  // vtable slot 6
    public:
        u32 value;  // offset: 0x8
        s32 shlNo;  // offset: 0xc
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
    cShlParamDividedCalled();
    virtual ~cShlParamDividedCalled();
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
    virtual void addShlList(const cShlParamDividedCalled* pParam);  // vtable slot 12
public:
    MtArray shlList;  // offset: 0x160
    static MyDTI DTI;
};

class uShlDividedCalled : public uShlBase
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
    const cShlParamDividedCalled* getShlParam() const;
    uShlDividedCalled();
    virtual ~uShlDividedCalled();
    virtual void setup();  // vtable slot 6
    virtual void updateSub();  // vtable slot 175
    void setDivideValue(u32 value);
public:
    u32 mDivideValue;  // offset: 0x2ab0
    static MyDTI DTI;
};

inline void* cShlParamDividedCalled::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamDividedCalled::cShlParamDividedCalled() {
    this->shlList.mAutoDelete = true;
}

inline void* cShlParamDividedCalled::cDividedCalledParam::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamDividedCalled::cDividedCalledParam::cDividedCalledParam() {
    this->value = 0;
    this->shlNo = -1;
}

inline void* uShlDividedCalled::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uShlDividedCalled::uShlDividedCalled() {
    this->mDivideValue = 0;
}
