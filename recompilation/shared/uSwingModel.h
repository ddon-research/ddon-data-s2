#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cSwing.h"
#include "uBaseModel.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
class cDraw;
class cSwingModel;
namespace nDraw { class Material; }
class rModel;
class rSwingModel;
class rTexture;

// Declarations
class uSwingModel;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uSwingModel : public uBaseModel
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
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void draw(cDraw* pdraw);  // vtable slot 12
    void setSwing(rSwingModel* p_resource);
    rSwingModel* getSwing();
    void setAfterSwing(rSwingModel*);
    rSwingModel* getAfterSwing();
    void setDepthBiasTexture(rTexture* p_texture);
    void setDepthBias(f32 bias);
    void setWindMask(u32);
    void setWindGroup(u32);
    void setFrequencyFactor(f32);
    void setWeight(f32);
    u32 getWindMask() const;
    u32 getWindGroup() const;
    f32 getFrequencyFactor() const;
    f32 getWeight() const;
    void resetShaderFunction(cDraw* pDraw);
    virtual f32 getLodDist(f32 vdist, const MtVector3& cpos);  // vtable slot 37
protected:
    virtual void setCommonState(cDraw* pdraw);  // vtable slot 32
    virtual void drawModel(cDraw* pdraw, rModel* pmod, nDraw::Material* * pmaterials, const MtVector3& cpos, s32 basecullmask, s32 shadow_cullmask);  // vtable slot 33
protected:
    cSwingModel mSwing;  // offset: 0x11b0
public:
    static MyDTI DTI;
};
