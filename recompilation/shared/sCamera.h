#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtColor.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "MtPrimitive2D.h"
#include "cSystem.h"

// Forward declarations
class MtAABB;
class MtAllocator;
class MtColor;
class MtDTI;
struct MtFloat2;
class MtMatrix;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtRect;
class MtSphere;
class MtUI;
class MtVector4;
class cDraw;
namespace nDraw { class Scene; }
class rSceneTexture;
class sCameraExt;
class uCamera;
class uDOFFilter;

// Declarations
class sCamera;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class sCamera : public cSystem
{
    // inferred: uDOFFilter::setNear names sCamera::mpInstance
    friend class uDOFFilter;
public:
    enum VIEWPORT_NO
    {
        VIEWPORT_0 = 0,
        VIEWPORT_1 = 1,
        VIEWPORT_2 = 2,
        VIEWPORT_3 = 3,
        VIEWPORT_4 = 4,
        VIEWPORT_5 = 5,
        VIEWPORT_6 = 6,
        VIEWPORT_7 = 7,
        MAX_VIEWPORT = 8,
    };
    enum REGION_MODE
    {
        REGION_FULLSCREEN = 0,
        REGION_FREE = 1,
        REGION_TOP = 2,
        REGION_BOTTOM = 3,
        REGION_LEFT = 4,
        REGION_RIGHT = 5,
        REGION_TOPLEFT = 6,
        REGION_BOTTOMLEFT = 7,
        REGION_TOPRIGHT = 8,
        REGION_BOTTOMRIGHT = 9,
        REGION_VIRTUAL = 10,
    };
    enum INSTANCING_DISSOLVE_PRIO
    {
        IDP_DEFAULT = 0,
        IDP_EM_LARGE = 1,
        IDP_EVENT = 2,
        IDP_MAX = 3,
    };
public:
    class MyDTI;
    class Viewport;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class Viewport : public MtObject
    {
        // inferred: sCameraExt::getMainCamera names sCamera::mViewport[0].mpCamera
        friend class sCameraExt;
        // inferred: uDOFFilter::setNear names sCamera::mViewport[0].mpCamera
        friend class uDOFFilter;
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
        Viewport();
        virtual ~Viewport();
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        bool setup(cDraw* pdraw);
        void updateRegion();
        uCamera* getCamera();
        void detachCamera();
        void attachCamera(uCamera* pcam);
        u32 getPriority();
        void setPriority(u32 pri);
        u32 getMode();
        void setMode(u32 mode);
        void setVisible(bool a);
        bool isVisible();
        const MtRect& getRegion() const;
        void setRegion(const MtRect& r);
        u32 getDisplay();
        void setDisplay(u32);
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        const MtVector4* getFrustum();
        const MtMatrix& getViewMat();
        const MtMatrix& getProjMat();
        void setSceneTexture(rSceneTexture* ptex);
        rSceneTexture* getSceneTexture();
        u32 getNo() const;
    private:
        void updateFrustum();
    private:
        uCamera* mpCamera;  // offset: 0x8
        uCamera* mpTestCamera;  // offset: 0x10
        rSceneTexture* mpSceneTexture;  // offset: 0x18
        bool mVisible;  // offset: 0x20
        u8 mNo;  // offset: 0x21
        u8 mPriority;  // offset: 0x22
        u8 mMode;  // offset: 0x23
        u8 mDisplay;  // offset: 0x24
        MtRect mRegion;  // offset: 0x28
        MtVector4 mFrustum[6];  // offset: 0x40
        MtMatrix mViewMat;  // offset: 0xa0
        MtMatrix mProjMat;  // offset: 0xe0
        MtMatrix mPrevViewMat;  // offset: 0x120
        MtMatrix mPrevProjMat;  // offset: 0x160
    public:
        static MyDTI DTI;
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
    sCamera();
    virtual ~sCamera();
    virtual void reset();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void draw(cDraw* pdraw, nDraw::Scene* pscene, u32 display_no);  // vtable slot 10
    static sCamera* getInstance();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    void clearBlank(cDraw* pdraw, const MtRect& srect);
    Viewport* getViewport(VIEWPORT_NO vp);
    void setCamera(VIEWPORT_NO vp, uCamera* pcam);
    uCamera* getCamera(VIEWPORT_NO vp);
    void setRegion(VIEWPORT_NO vp, const MtRect& r);
    void setRegion(VIEWPORT_NO, REGION_MODE);
    void setVisible(VIEWPORT_NO, bool);
    bool isVisible(VIEWPORT_NO vp);
    const MtRect& getRegion(VIEWPORT_NO vp) const;
    void setScreenRect(const MtRect& r);
    MtRect getScreenRect();
    void setSubPixelOffset(f32 x, f32 y);
    MtFloat2 getSubPixelOffset();
    void setViewSubFrame(f32 ofs);
    void setWorldSubFrame(f32 ofs);
    f32 getViewSubFrame();
    f32 getWorldSubFrame();
    bool isPause();
    void setPause(bool);
    void setBlankColor(MtColor);
    MtColor getBlankColor();
    void setBGColor(MtColor color);
    MtColor getBGColor();
    void setVirtualRect(const MtRect&);
    const MtRect& getVirtualRect();
    void updateViewportFrustum(uCamera* pCamera);
    bool isDispAABB(VIEWPORT_NO vp, const MtAABB& a);
    bool isDispSphere(VIEWPORT_NO vp, const MtSphere& a);
    f32 getInstancingDissolveStartDistance();
    f32 getInstancingDissolveEndDistance();
    f32 getInstancingDissolveAlpha();
    void setInstancingDissolveStartDistance(f32 set);
    void setInstancingDissolveEndDistance(f32 set);
    void setInstancingDissolveAlpha(f32 set);
    void setInstancingDissolveParam(u32 set);
    void setInstancingDissolveDefaultParam();
    void setInstancingDissolveEmLargeParam();
    void setInstancingDissolveEventParam();
protected:
    f32 mSubPixelOfsX;  // offset: 0x14
    f32 mSubPixelOfsY;  // offset: 0x18
    f32 mViewSubFrame;  // offset: 0x1c
    f32 mWorldSubFrame;  // offset: 0x20
    Viewport mViewport[8];  // offset: 0x30
    MtRect mScreenRect;  // offset: 0xd30
    MtRect mVirtualRect;  // offset: 0xd40
    MtColor mBlankColor;  // offset: 0xd50
    MtColor mBGColor;  // offset: 0xd54
    bool mPause;  // offset: 0xd58
private:
    f32 mInstancingDissolveStartDistance;  // offset: 0xd5c
    f32 mInstancingDissolveEndDistance;  // offset: 0xd60
    f32 mInstancingDissolveAlpha;  // offset: 0xd64
public:
    static MyDTI DTI;
protected:
    static sCamera* mpInstance;
};

// Inline, no code of its own: checked where it is inlined.
inline sCamera* sCamera::getInstance() {
    return ::sCamera::mpInstance;
}
