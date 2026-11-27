#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "../../XFramework/cSystem.h"
#include "rTable.h"
#include "uSkyLight.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
struct MtFloat2;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtString;
class MtUI;
class MtVector3;
class cStateTransitionFromGameInfo;
class uCharacterEditBase;
class uDDOModel;
class uPointLightExt;

// Declarations
class cActorLight;
class rActorLight;
class sLightExt;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class cActorLight : public MtObject
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
    s32 getStageNo();
    void setStageNo(s32 no);
    cActorLight();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
public:
    s32 mStageNo;  // offset: 0x8
    MtString mName;  // offset: 0x10
    MtVector3 mColor;  // offset: 0x20
    f32 mBalance;  // offset: 0x30
    MtFloat2 mShadowAtten;  // offset: 0x34
    MtVector3 mPos;  // offset: 0x40
    f32 mStart;  // offset: 0x50
    f32 mEnd;  // offset: 0x54
    static const u32 DATA_VERSION = 1;
    static MyDTI DTI;
};

class rActorLight : public rTable
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
    rActorLight();
    virtual const MtDTI& getDataDTI();  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u16 getDataVersion();  // vtable slot 18
    virtual bool load(MtStream& in);  // vtable slot 11
    bool loadData(MtDataReader& in);
    virtual bool save(MtStream& out);  // vtable slot 12
    bool saveData(MtDataWriter& out);
    bool loadData(MtDataReader& in, cActorLight* pData);
    bool saveData(MtDataWriter& out, cActorLight* pData);
    cActorLight* getData(u32 Idx);
    void setData(MtObject*, u32);
public:
    static MyDTI DTI;
};

class sLightExt : public cSystem
{
    friend class uCharacterEditBase;
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
    sLightExt();
    virtual ~sLightExt();
    virtual void reset();  // vtable slot 6
    void setup();
    void final();
    virtual void move();  // vtable slot 7
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    static sLightExt* getInstance();
    void setTargetModel(uDDOModel* target);
    uDDOModel* getTargetModel();
    void stageInit(s32 bind_type);
    void stageFinal();
    f32 getZoneFadeRate() const;
    void requestStateTransSpritDragon();
    void forceStateTransEndSpritDragon();
    void addStateTransSpritDragon(cStateTransitionFromGameInfo* pAdd);
    void relStateTransSpritDragon(cStateTransitionFromGameInfo* pRel);
public:
    bool mbEnableActorLight2;  // offset: 0x11
    bool mbDispSunDir;  // offset: 0x12
    uPointLightExt* mpuActorLight;  // offset: 0x18
    rActorLight* mprActorLight;  // offset: 0x20
    uDDOModel* mpuTargetModel;  // offset: 0x28
    bool mbIsEditRoom;  // offset: 0x30
protected:
    s32 mRno;  // offset: 0x34
    f32 mZoneFadeFrame;  // offset: 0x38
private:
    MtTypedArray<cStateTransitionFromGameInfo> mStateTransSpritDragonArray;  // offset: 0x40
public:
    static MyDTI DTI;
protected:
    static sLightExt* mpInstance;
};

inline void* cActorLight::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* rActorLight::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

#include "../../MT/MtAllocator.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtDataWriter.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* cActorLight::getAllocator() {
    return MtMemoryAllocator::getAllocator(cActorLight::DTI);
}

inline void* cActorLight::operator new(size_t sz, u32 align) {
    return getAllocator()->memAlloc(sz, align, cActorLight::DTI.getID());
}

inline void cActorLight::operator delete(void* p_addr) {
    getAllocator()->memFree(p_addr);
}

inline cActorLight::cActorLight() {
    mStageNo = -1;
    mColor = MtVector3(3.184f, 4.0f, 3.908f);
    mBalance = -0.5f;
    mShadowAtten.x = 0.8f;
    mShadowAtten.y = 0.0f;
    mPos = MtVector3(20.0f, -40.0f, 50.0f);
    mStart = 50.0f;
    mEnd = 150.0f;
}

inline bool rActorLight::loadData(MtDataReader& in, cActorLight* pData) {
    pData->mColor = in.readV3();
    pData->mBalance = in.readF32();
    pData->mShadowAtten.x = in.readF32();
    pData->mShadowAtten.y = in.readF32();
    pData->mPos = in.readV3();
    pData->mStart = in.readF32();
    pData->mEnd = in.readF32();
    return true;
}

inline bool rActorLight::saveData(MtDataWriter& out, cActorLight* pData) {
    MtFloat3 v;
    v.x = pData->mColor.x;
    v.y = pData->mColor.y;
    v.z = pData->mColor.z;
    out.writeV3(v);
    out.writeF32(pData->mBalance);
    out.writeF32(pData->mShadowAtten.x);
    out.writeF32(pData->mShadowAtten.y);
    v.x = pData->mPos.x;
    v.y = pData->mPos.y;
    v.z = pData->mPos.z;
    out.writeV3(v);
    out.writeF32(pData->mStart);
    out.writeF32(pData->mEnd);
    return true;
}

inline bool rActorLight::saveData(MtDataWriter& out) {
    out.writeU32(rTable::mMagic);
    out.writeU16(cActorLight::DATA_VERSION);
    out.writeU16(0);
    out.writeU32(mArray.length());
    for (u32 i = 0; i < mArray.length(); i++) {
        cActorLight* pObj = static_cast<cActorLight*>(mArray[i]);
        if (pObj != nullptr) {
            saveData(out, pObj);
        }
    }
    return true;
}

inline void* sLightExt::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline sLightExt* sLightExt::getInstance() {
    return ::sLightExt::mpInstance;
}

inline uDDOModel* sLightExt::getTargetModel() {
    return this->mpuTargetModel;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../XFramework/cResource.h"

inline void* rActorLight::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::rActorLight::DTI)->memAlloc(sz, align, ::rActorLight::DTI.::MtDTI::getID());
}

inline void rActorLight::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::rActorLight::DTI)->memFree(p_addr);
}

inline rActorLight::rActorLight() {
    this->::cResource::setAttribute(16u);
}

inline MtAllocator* sLightExt::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::sLightExt::DTI);
}

inline void sLightExt::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::sLightExt::DTI)->memFree(p_addr);
}
