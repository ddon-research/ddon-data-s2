#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "cParticleGenerator.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtMatrix;
class MtObject;
class MtVector3;
class cDraw;
class cParticle;
class cPolygon;
class cPolygonDrawParam;
class cPrim;
namespace nPrim { struct Vertex; }
class uEffect;
class uSynchroAdhesion;

// Declarations
class cParticleGeneratorAdhesion;
class cParticleGeneratorPolygon;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cParticleGeneratorPolygon : public cParticleGenerator
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
    cParticleGeneratorPolygon();
    virtual ~cParticleGeneratorPolygon();
    virtual bool constructParam(uEffect* pOwner, u32 ListNo, u32 ManagerNo);  // vtable slot 6
    virtual void initParam();  // vtable slot 8
    virtual void applyWorldOffset(const MtVector3& Offset);  // vtable slot 17
    virtual void updateConst();  // vtable slot 19
    virtual void draw(cDraw* pDraw, s32 Transparency, u8*);  // vtable slot 21
protected:
    virtual bool initParticle(cParticle* pParticle, cParticleGenerator::ParticleParam& Param);  // vtable slot 23
    virtual bool moveParticleLoop();  // vtable slot 24
    bool moveParticlePolygon(cParticle* pParticle);
    void moveParticlePolygonCullingLoop();
    void drawParticlePolygonLoop(cDraw* pDraw, s32 Transparency);
    void drawParticleCullingPolygonLoop(cDraw* pDraw, s32 Transparency);
    void setPolygonVertex(cPolygon* pPolygon, nPrim::Vertex* pVertex, const MtMatrix& Wmat, const cPolygonDrawParam& DrawParam);
    void drawDividePolygon(cPrim* pPrim, cPolygon* pPolygon, nPrim::Vertex* pVertex, s32 Zofs, s32 OtDepth, u32 DivideNum);
public:
    static MyDTI DTI;
};

class cParticleGeneratorAdhesion : public cParticleGeneratorPolygon
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
    cParticleGeneratorAdhesion();
    virtual ~cParticleGeneratorAdhesion();
    virtual void initParam();  // vtable slot 8
    virtual void update();  // vtable slot 20
    virtual void draw(cDraw* pDraw, s32 Transparency, u8* pDrawBuff);  // vtable slot 21
    u32 getAdhesionDivideMax() const;
    void setAdhesionDivideMax(u32 Max);
protected:
    virtual bool initParticle(cParticle* pParticle, cParticleGenerator::ParticleParam& Param);  // vtable slot 23
    virtual bool moveParticleLoop();  // vtable slot 24
private:
    bool moveParticleAdhesion(cParticle* pParticle);
    uSynchroAdhesion* getSynchroAdhesion(cPolygon* pPolygon);
private:
    u32 mAdhesionDivideMax;  // offset: 0x22c
public:
    static MyDTI DTI;
};

inline void* cParticleGeneratorAdhesion::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cParticleGeneratorPolygon::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void cParticleGeneratorAdhesion::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cParticleGeneratorAdhesion::DTI)->memFree(p_addr);
}

inline void cParticleGeneratorPolygon::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cParticleGeneratorPolygon::DTI)->memFree(p_addr);
}
