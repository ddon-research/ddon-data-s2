#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtColor.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtPrimitive2D.h"
#include "cUnit.h"
#include "nPrim.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtColor;
class MtDTI;
struct MtFloat2;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtRect;
class MtUI;
class MtVector3;
class cDraw;
namespace nDraw { class Texture; }
namespace nPrim { class PrimVertex; }
class rRenderTargetTexture;
class uCamera;

// Declarations
class uScreenSpace;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uScreenSpace : public cUnit
{
public:
    enum eTexSize
    {
        E_TEX_SIZE_128x128 = 0,
        E_TEX_SIZE_256x256 = 1,
        E_TEX_SIZE_512x512 = 2,
        E_TEX_SIZE_1024x1024 = 3,
        E_TEX_SIZE_2048x2048 = 4,
        E_TEX_SIZE_NONE = 5,
        E_TEX_SIZE_MAX = 6,
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
    uScreenSpace();
    virtual ~uScreenSpace();
    virtual void setup();  // vtable slot 6
    virtual void draw(cDraw* p_draw);  // vtable slot 12
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& prop_list);  // vtable slot 4
    nDraw::Texture* getColorTex() const;
    nDraw::Texture* getDepthTex() const;
    const MtFloat2& getTexCoordLT() const;
    const MtFloat2& getScrTexCoordRB() const;
    void setScrTexCoordLT(const MtFloat2&);
    void setTexCoordRB(const MtFloat2&);
    const MtRect& getScrRect() const;
    void setScrRect(const MtRect&);
    void setTextureSize(u32 sz);
    u32 getTextureSize();
    const bool& getDraw2D() const;
    void setDraw2D(const bool& enable);
    const u32& getAttribute() const;
    void setAttribute(const u32&);
    const s32& getDepth() const;
    void setDepth(const s32&);
    const MtColor& getClearColor() const;
    void setClearColor(const MtColor& cc);
    const nPrim::PrimVertex& getVertices(u32) const;
    void setVertices(u32 idx, const nPrim::PrimVertex& vv);
    const u32& getPass() const;
    void setPass(u32);
    void setSceneDrawMode(u32);
    u32 getSceneDrawMode() const;
    void setSceneView(u32 draw_view);
    u32 getSceneView() const;
    MtVector3 getCameraPos() const;
    void setCameraPos(const MtVector3& pos);
    MtVector3 getCameraUp() const;
    void setCameraUp(const MtVector3& up);
    MtVector3 getCameraTarget() const;
    void setCameraTarget(const MtVector3& tgt);
    bool isUseRenderTargetTex() const;
    rRenderTargetTexture* getRenderTarget() const;
    void setRenderTarget(rRenderTargetTexture* p_rt);
    uCamera* getCamera() const;
    void setCamera(uCamera*);
    bool isUseCamera() const;
    void setPriority(u32 prio);
    u32 getPriority() const;
    u32 getScreenLayer() const;
    void setScreenLayer(u32 layer);
    void setDepthToAlpha(bool enable);
    bool isDepthToAlpha() const;
    bool isFXAA() const;
    void setFXAA(bool enable);
    bool isDistortionEnabled() const;
    void setDistortionEnable(bool enable);
protected:
    virtual s32 createTexture(u32 sz);  // vtable slot 24
    virtual s32 releaseTexture();  // vtable slot 25
    virtual s32 createDepth(rRenderTargetTexture* p_rt);  // vtable slot 26
    virtual void drawUnit(cDraw* p_draw);  // vtable slot 27
    s32 drawScene(cDraw* p_draw, nDraw::Texture* p_rt, nDraw::Texture* p_ds);
    virtual void createDistortion(u32 width, u32 height);  // vtable slot 28
protected:
    rRenderTargetTexture* mpRenderTarget;  // offset: 0x48
    nDraw::Texture* mpColorTarget;  // offset: 0x50
    nDraw::Texture* mpDepthTarget;  // offset: 0x58
    nDraw::Texture* mpTempColorTarget;  // offset: 0x60
    nDraw::Texture* mpDistortionTex;  // offset: 0x68
    MtFloat2 mTexCoordLT;  // offset: 0x70
    MtFloat2 mTexCoordRB;  // offset: 0x78
    MtRect mDrawPos;  // offset: 0x80
    MtVector3 mCameraPos;  // offset: 0x90
    MtVector3 mCameraUp;  // offset: 0xa0
    MtVector3 mCameraTarget;  // offset: 0xb0
    f32 mNearPlane;  // offset: 0xc0
    f32 mFarPlane;  // offset: 0xc4
    f32 mFOV;  // offset: 0xc8
    u32 mSceneDrawMode;  // offset: 0xcc
    u32 mSceneView;  // offset: 0xd0
    MtColor mClearColor;  // offset: 0xd4
    u32 mTextureSize;  // offset: 0xd8
    bool mDraw2D;  // offset: 0xdc
    bool mFXAA;  // offset: 0xdd
    nPrim::PrimVertex mVertices[4];  // offset: 0xe0
    u32 mAttribute;  // offset: 0x260
    s32 mDepth;  // offset: 0x264
    MtArray mPointTable;  // offset: 0x268
    uCamera* mpCamera;  // offset: 0x288
    u32 mPass;  // offset: 0x290
    u32 mPriority;  // offset: 0x294
    u32 mLayer;  // offset: 0x298
    bool mDepthToAlpha;  // offset: 0x29c
    bool mDistortionEnabled;  // offset: 0x29d
public:
    static MyDTI DTI;
};
