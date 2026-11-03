#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "uEffectExt.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
class cDraw;
class uEffect;

// Declarations
class uEfCam;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class uEfCam : public uEffectExt
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
    uEfCam();
    virtual ~uEfCam();
    virtual void move();  // vtable slot 9
    virtual void sync();  // vtable slot 11
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void updateWorldMatrix();  // vtable slot 26
    bool getRepeatFlag();
    void setRepeatFlag(bool Flag);
    bool getYAngleFlag();
    void setYAngleFlag(bool Flag);
    MtVector3 getCamOfs() const;
    void setCamOfs(const MtVector3& Ofs);
protected:
    virtual uEffect* openEffect();  // vtable slot 57
private:
    void repeatParticlePos();
private:
    bool mRepeatFlag;  // offset: 0x370
    bool mYAngleFlag;  // offset: 0x371
    MtVector3 mCamOfs;  // offset: 0x380
public:
    static MyDTI DTI;
};

inline void* uEfCam::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
