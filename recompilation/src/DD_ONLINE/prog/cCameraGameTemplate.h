#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../generated/shared/nCameraGame.h"
#include "uCameraGame.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
class cCamExParam;
class cCamImpBase;
namespace nCameraGame { class cTemplateParam; }
class uCameraGame;

// Declarations
class cCamExParamTemplate;
class cCamImpTemplate;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cCamExParamTemplate : public cCamExParam
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
    cCamExParamTemplate();
    virtual ~cCamExParamTemplate();
    virtual cCamImpBase* createCamImpInstance(uCameraGame* pCamera) const;  // vtable slot 6
    virtual void copy(const cCamExParam* pParam);  // vtable slot 8
    const nCameraGame::cTemplateParam* getTemplateParam(u32 index) const;
    u32 getTemplateParamNum() const;
public:
    MtArray mTemplateParamArray;  // offset: 0x1d8
    static MyDTI DTI;
};

class cCamImpTemplate : public cCamImpBase
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
    cCamImpTemplate();
    virtual ~cCamImpTemplate();
protected:
    virtual void initSub(MtVector3& cameraPos, MtVector3& targetPos, f32& angX, f32& angY);  // vtable slot 9
    virtual void ctrlSub(MtVector3& idealCam, MtVector3& idealTar, f32& angX, f32& angY);  // vtable slot 10
    virtual void moveSub(MtVector3& idealCam, MtVector3& idealTar, f32& angX, f32& angY);  // vtable slot 11
    virtual void interporateSub(MtVector3& cameraPos, MtVector3& targetPos);  // vtable slot 12
    virtual void adjustSub(MtVector3& cameraPos, MtVector3& targetPos, MtVector3& idealCam, MtVector3& idealTar);  // vtable slot 13
    virtual void finalSub();  // vtable slot 14
    virtual nCameraGame::CAMERA_TYPE getType() const;  // vtable slot 7
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    const cCamExParam* getExParam(u32 index);
    void setTemplateParam();
protected:
    const cCamExParamTemplate* mpParamTemplate;  // offset: 0xb0
private:
    cCamImpBase* mpImple;  // offset: 0xb8
    f32 mFrame;  // offset: 0xc0
    f32 mExtendFrame;  // offset: 0xc4
    u32 mIndex;  // offset: 0xc8
public:
    static MyDTI DTI;
};

inline void* cCamExParamTemplate::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cCamImpTemplate::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
