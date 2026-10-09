#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/MtPrimitive3D.h"
#include "../shared/cAIObject.h"
#include "../shared/cResource.h"
#include "../shared/nDDOUtility.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtMatrix;
class MtObject;
class MtSphere;
class MtStream;
class MtVector3;

// Declarations
class cAISensorNodeRes;
class rAISensor;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using cGpCategoryFlag = nDDOUtility::cBitSet<32>;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cAISensorNodeRes : public cAIResource
{
public:
    enum
    {
        JNT_NO_WORD = -2,
        JNT_NO_NONE = -1,
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
    cAISensorNodeRes();
    void load(MtDataReader& r);
    void save(MtDataWriter& w);
public:
    MtSphere mSphere;  // offset: 0x10
    MtVector3 mDir;  // offset: 0x20
    f32 mEffectiveAngle;  // offset: 0x30
    s32 mJntNo;  // offset: 0x34
    cGpCategoryFlag mCategoryFlag;  // offset: 0x38
    u32 mGroupFlag;  // offset: 0x3c
    u32 mUserFlag;  // offset: 0x40
    u32 mStatusFlag;  // offset: 0x44
    static MyDTI DTI;
};

class rAISensor : public cResource
{
public:
    enum
    {
        MAGIC_NUM = 844254803,
        DATA_VERSION = 1,
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
    rAISensor();
    virtual ~rAISensor();
    u32 getNodeNum() const;
    const cAISensorNodeRes* getNode(u32 idx) const;
    static void calcMatrix(MtMatrix* pDst, MtObject* pOwner, const cAISensorNodeRes* pNode);
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual bool load(MtStream& in);  // vtable slot 11
protected:
    u32 mMagic;  // offset: 0x70
    u32 mVersion;  // offset: 0x74
    MtTypedArray<cAISensorNodeRes> mNodes;  // offset: 0x78
public:
    static MyDTI DTI;
};
