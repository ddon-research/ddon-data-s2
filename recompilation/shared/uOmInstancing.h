#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtSynchronize.h"
#include "cInstancing.h"
#include "uOmSwingModel.h"

// Forward declarations
class MtAllocator;
class MtCriticalSection;
class MtDTI;
class MtMatrix;
class MtObject;
class MtPropertyList;
class MtVector3;
class cDraw;
class cInstancingFromMatrices;
namespace nDraw { class Material; }
class rModel;
class uOmSwingModel;

// Declarations
class uOmSwingInstancing;
class uOmSwingModelInstancing;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;
using uParentuOmSwingModel = uInstancing<uOmSwingModel, cInstancingFromMatrices>;

class uOmSwingModelInstancing : public uParentuOmSwingModel
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
    virtual void move();  // vtable slot 9
    void drawBaseModel(cDraw* pdraw, rModel* pmod, nDraw::Material* * pmaterials, const MtVector3& cpos, s32 basecullmask, s32 shadow_cullmask);
    virtual void drawModel(cDraw* pdraw, rModel* pmod, nDraw::Material* * pmaterials, const MtVector3& cpos, s32 basecullmask, s32 shadow_cullmask);  // vtable slot 33
    void drawModelNonSkinInstance(cDraw* pdraw, rModel* pmod, nDraw::Material* * pmaterials, const MtVector3& cpos, s32 basecullmask, s32 shadow_cullmask);
public:
    static MyDTI DTI;
};

class uOmSwingInstancing : public uOmSwingModelInstancing
{
public:
    enum
    {
        HOLD_MAX = 1024,
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
    uOmSwingInstancing();
    virtual ~uOmSwingInstancing();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    bool delInstance(u64 resID);
    void delInstance();
    void delAllInstances();
    void addInstance(MtMatrix* pMat, u32 MatNum, u64 resID, bool isFade);
    virtual void init(s32 omNumber);  // vtable slot 40
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    // Address: 0x01b0a3c0 - 0x01b0a3c1 (1 bytes)
    virtual void updateLodDistance() {}  // vtable slot 39
    u32 getInstanceNum();
    MtMatrix getInstanceMatrix(u32);
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
public:
    MtVector3 mWorldOffset;  // offset: 0x27b0
    MtVector3 mWorldAbsOffset;  // offset: 0x27c0
private:
    MtCriticalSection mCS;  // offset: 0x27d0
    u32 mHoldNum;  // offset: 0x27d8
    u32 mHoldID[1024];  // offset: 0x27dc
    u64 mResID[1024];  // offset: 0x37e0
public:
    static MyDTI DTI;
};
