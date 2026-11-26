#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "uShlCustomSpline.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
class cEfcHandle;
class cShlParamBase;

// Declarations
class cShlParamJob04CS14;
class uShlJob04CS14;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamJob04CS14 : public cShlParamCustomSpline
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
    cShlParamJob04CS14();
    virtual void createProperty(MtPropertyList& proplist);  // vtable slot 4
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    static MyDTI DTI;
};

class uShlJob04CS14 : public uShlCustomSpline
{
public:
    enum BLAST_OPTION_TYPE
    {
        BLAST_OPTION_FIRST = 0,
        BLAST_OPTION_SHOT_AFTER = 1,
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
    const cShlParamJob04CS14* getShlParam() const;
    uShlJob04CS14();
    virtual ~uShlJob04CS14() {}
    virtual void setup();  // vtable slot 6
    virtual void updateSub();  // vtable slot 175
    virtual void kill();  // vtable slot 16
    virtual void updateEfcHandle();  // vtable slot 58
    virtual void movePos();  // vtable slot 186
    void reqBlastOptionEfType(BLAST_OPTION_TYPE type);
private:
    cEfcHandle* reqBlastOptionEffect(const MtVector3& pos, s32 no);
private:
    cEfcHandle* mFirstEfcHnd;  // offset: 0x2cc8
    cEfcHandle* mShotAfterEfcHnd;  // offset: 0x2cd0
    bool mAlreadyShot;  // offset: 0x2cd8
    bool mIsNeedShotClear;  // offset: 0x2cd9
public:
    static MyDTI DTI;
};

inline void* cShlParamJob04CS14::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamJob04CS14::cShlParamJob04CS14() {
}

inline void* uShlJob04CS14::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uShlJob04CS14::uShlJob04CS14() {
    this->mAlreadyShot = false;
    this->mIsNeedShotClear = false;
    this->mShotAfterEfcHnd = nullptr;
    this->mFirstEfcHnd = nullptr;
}
