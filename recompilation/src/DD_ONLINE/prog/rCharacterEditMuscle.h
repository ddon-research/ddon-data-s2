#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtObject;
class MtPropertyList;
class MtVector3;

// Declarations
class cCharacterEditMuscle;
class rCharacterEditMuscle;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class cCharacterEditMuscle : public MtObject
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
    cCharacterEditMuscle();
    virtual ~cCharacterEditMuscle() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    MtVector3 mFatP;  // offset: 0x10
    MtVector3 mFatM;  // offset: 0x20
    MtVector3 mMuscle;  // offset: 0x30
    static MyDTI DTI;
    static const u16 DATA_VERSION = 256;
};

class rCharacterEditMuscle : public rTbl2<cCharacterEditMuscle>
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
    virtual bool loadData(MtDataReader& in, cCharacterEditMuscle* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

inline cCharacterEditMuscle::cCharacterEditMuscle() {
    this->mMuscle.z = 0.0f;
    this->mMuscle.pad_ = 0.0f;
    this->mMuscle.x = 0.0f;
    this->mMuscle.y = 0.0f;
    this->mFatM.z = 0.0f;
    this->mFatM.pad_ = 0.0f;
    this->mFatM.x = 0.0f;
    this->mFatM.y = 0.0f;
    this->mFatP.z = 0.0f;
    this->mFatP.pad_ = 0.0f;
    this->mFatP.x = 0.0f;
    this->mFatP.y = 0.0f;
}
