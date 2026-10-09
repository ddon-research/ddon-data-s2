#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "rSwingModel.h"

// Forward declarations
class MtAABB;
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class cDraw;
namespace nDraw { class Texture; }
namespace nDraw { class VertexBuffer; }
class rSwingModel;
class rTexture;

// Declarations
class cSwing;
class cSwingModel;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cSwing : public MtObject
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
    cSwing();
    virtual ~cSwing();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual MtUI* getUI(MtProperty& prop);  // vtable slot 6
    void applyWind(cDraw* p_draw, MtAABB& boundary, u32 max_wind);
    void setWindMask(u32 mask);
    void setWindGroup(u32 group);
    void setFrequencyFactor(f32 freq);
    void setWeight(f32 pwr);
    u32 getWindMask() const;
    u32 getWindGroup() const;
    virtual f32 getFrequencyFactor() const;  // vtable slot 7
    virtual f32 getWeight() const;  // vtable slot 8
protected:
    u32 mWindMask;  // offset: 0x8
    u32 mWindGroup;  // offset: 0xc
    f32 mFrequencyFactor;  // offset: 0x10
    f32 mWeight;  // offset: 0x14
public:
    static MyDTI DTI;
};

class cSwingModel : public cSwing
{
public:
    class MyDTI;
    struct SWING_CONTEXT;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct SWING_CONTEXT
    {
    public:
        struct VERTEX_STATE;
    public:
        struct VERTEX_STATE
        {
        public:
            nDraw::VertexBuffer* p_vb;  // offset: 0x0
            const rSwingModel::PRIMITIVE_QUANT_INFO* p_quant;  // offset: 0x8
            const rSwingModel::PRIMITIVE_QUANT_INFO* p_current_quant;  // offset: 0x10
            u32 current_base;  // offset: 0x18
            u32 current_stride;  // offset: 0x1c
            bool use_high_precision;  // offset: 0x20
        };
    public:
        VERTEX_STATE state[2];  // offset: 0x0
        nDraw::Texture* p_depth_bias_texture;  // offset: 0x50
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
    cSwingModel();
    virtual ~cSwingModel();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual MtUI* getUI(MtProperty& prop);  // vtable slot 6
    void draw(cDraw* p_draw);
    void setDepthBias(f32 depth_bias);
    f32 getDepthBias();
    void setDepthBiasTexture(rTexture* p_depth_bias_texture);
    rTexture* getDepthBiasTexture();
    void setSwing(rSwingModel* p_resource);
    rSwingModel* getSwing();
    void setAfterSwing(rSwingModel* p_resource);
    rSwingModel* getAfterSwing();
    void setup(cDraw* pdraw, const MtAABB& aabb);
    void initContext(SWING_CONTEXT& context);
    bool updateCheck(const SWING_CONTEXT& context);
    void updateQuant(SWING_CONTEXT& context, u32 prim);
    void apply(cDraw* p_draw, SWING_CONTEXT& context);
    void applyWind(cDraw* p_draw, MtAABB& boundary, SWING_CONTEXT& context);
    virtual f32 getFrequencyFactor() const;  // vtable slot 7
    virtual f32 getWeight() const;  // vtable slot 8
protected:
    void setBillboardEnable(cDraw* pdraw, bool use_billboard, bool rotation, bool fix_y_axis, bool default_swing);
    void setupBillboard(cDraw* pdraw);
protected:
    f32 mShadowDepthBias;  // offset: 0x18
    rSwingModel* mpSwing;  // offset: 0x20
    rSwingModel* mpAfterSwing;  // offset: 0x28
    rTexture* mpDepthBiasTexture;  // offset: 0x30
public:
    static MyDTI DTI;
};
