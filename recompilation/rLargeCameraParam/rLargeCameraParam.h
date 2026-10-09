#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtObject;
class MtPropertyList;

// Declarations
class cLargeCameraParam;
class rLargeCameraParam;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cLargeCameraParam : public MtObject
{
public:
    enum CAMERA_TYPE
    {
        TYPE_D_CAMERA = 0,
        TYPE_E_CAMERA = 1,
        TYPE_F_CAMERA = 2,
        TYPE_G_CAMERA = 3,
        TYPE_H_CAMERA = 4,
        TYPE_I_CAMERA = 5,
        TYPE_J_CAMERA = 6,
        TYPE_K_CAMERA = 7,
        TYPE_L_CAMERA = 8,
        TYPE_M_CAMERA = 9,
    };
    enum ResStatus
    {
        DATA_VERSION = 3,
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
    cLargeCameraParam();
    // Address: 0x01a99480 - 0x01a99481 (1 bytes)
    virtual ~cLargeCameraParam() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    u32 getEmId();
    f32 getRange1();
    f32 getRange2();
    f32 getCamera();
    bool getGroup();
public:
    u32 mEmId;  // offset: 0x8
    f32 mRange1;  // offset: 0xc
    f32 mRange2;  // offset: 0x10
    u32 mCamera;  // offset: 0x14
    bool mGroup;  // offset: 0x18
    static MyDTI DTI;
};

class rLargeCameraParam : public rTbl2<cLargeCameraParam>
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
    virtual bool loadData(MtDataReader& in, cLargeCameraParam* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cLargeCameraParam::cLargeCameraParam() {
    this->mEmId = static_cast<u32>(0);
    this->mRange1 = 1000.0f;
    this->mRange2 = 1300.0f;
    this->mCamera = static_cast<u32>(0);
    this->mGroup = false;
}
