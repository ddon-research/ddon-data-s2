#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "cShlFuwaFuwaCtrl2.h"
#include "nDDOUtility.h"
#include "uShlSpeed.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cDraw;
class cShlFuwaFuwaCtrl2;
class cShlFuwaFuwaInfo2;
class cShlParamBase;

// Declarations
class cShlParamFuwaFuwa2;
class uShlFuwaFuwa2;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamFuwaFuwa2 : public cShlParamSpeed
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
    virtual MtDTI& getShlDTI() const;  // vtable slot 6
    cShlParamFuwaFuwa2();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    nDDOUtility::cArray<cShlFuwaFuwaInfo2, 8> mFuwaFuwaInfoArray;  // offset: 0x1f0
private:
    u32 mSeqNoMax;  // offset: 0x2f0
public:
    static MyDTI DTI;
};

class uShlFuwaFuwa2 : public uShlSpeed
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
    const cShlParamFuwaFuwa2* getShlParam() const;
    uShlFuwaFuwa2();
    virtual ~uShlFuwaFuwa2();
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    virtual void initSub();  // vtable slot 177
    virtual void updateSub();  // vtable slot 175
protected:
    cShlFuwaFuwaCtrl2 mFuwaCtrl2;  // offset: 0x2b90
    u32 mFuwaFuwaSeqNo;  // offset: 0x2c50
public:
    static MyDTI DTI;
};

inline void* cShlParamFuwaFuwa2::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uShlFuwaFuwa2::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uShlFuwaFuwa2::uShlFuwaFuwa2() {
    this->mFuwaFuwaSeqNo = 0;
}
