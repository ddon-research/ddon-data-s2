#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "uScrModel.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
class cDDMaterialCtrl;
class cDraw;
class rModel;

// Declarations
class uSkyWaterModel;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class uSkyWaterModel : public uScrBaseModel
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
    uSkyWaterModel();
    virtual ~uSkyWaterModel();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void move();  // vtable slot 9
    virtual void moveAfter();  // vtable slot 10
    virtual bool isPrioAttrTransparency(cDraw* pDraw);  // vtable slot 30
    virtual void draw(cDraw* pdraw);  // vtable slot 12
    virtual void setup();  // vtable slot 6
    virtual void setCommonState(cDraw* pdraw);  // vtable slot 32
    virtual void setModel(rModel* pmod);  // vtable slot 29
private:
    void drawModelDepth(cDraw* pdraw);
    virtual void callbackChangeVisibleTrueToFalse() {}  // vtable slot 19
protected:
    bool mUseOriginalColor;  // offset: 0x11f0
private:
    bool mUseSkyColor;  // offset: 0x11f1
    f32 mSunColorHeight;  // offset: 0x11f4
    f32 mSunColorScale;  // offset: 0x11f8
    f32 mSaturationScale;  // offset: 0x11fc
    f32 mIntensityScale;  // offset: 0x1200
    f32 mAmbColorHeight;  // offset: 0x1204
    f32 mAmbColorScale;  // offset: 0x1208
    MtVector3 mSunColor;  // offset: 0x1210
    MtVector3 mAmbColor;  // offset: 0x1220
    MtVector3 mDiffuseScale;  // offset: 0x1230
    MtVector3 mAlbedoColor;  // offset: 0x1240
    MtVector3 mSpecularColor;  // offset: 0x1250
    MtVector3* mpOrgDiffuseColor;  // offset: 0x1260
    MtVector3 mDiffuseScaleMin;  // offset: 0x1270
    cDDMaterialCtrl* mpDDMaterialCtrl;  // offset: 0x1280
public:
    static MyDTI DTI;
private:
    static const u32 DIFFUSE_CORRECT_MATERIAL_ID = 2;
};

inline void* uSkyWaterModel::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void uSkyWaterModel::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uSkyWaterModel::DTI)->memFree(p_addr);
}
