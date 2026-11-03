#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtGeomSphere.h"
#include "../../MT/MtMath.h"
#include "../../XFramework/cAIObject.h"
#include "cpComponent.h"
#include "nDDOUtility.h"
#include "rAISensor.h"
#include "res_ptr.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtGeomSphere;
class MtMatrix;
class MtObject;
class MtVector2;
class MtVector3;
class cAISensorNodeRes;
class cGeneralPoint;
class rAISensor;
class uCoord;
class uDDOModel;

// Declarations
class cAISensorGetParam;
class cAISensorNode;
class cpAISensor;

// Type aliases from DWARF
using u32 = unsigned int;
using AISensorCheckFunc = u32(MtObject::*)(void*, void*);
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using cAISensorCheckFuncPtr = nDDOUtility::cObjectFunc<unsigned int(MtObject::*)(void*, void*)>;
using cGpCategoryFlag = nDDOUtility::cBitSet<32>;
using f32 = float;
using s32 = int;
using size_t = _Sizet;

class cAISensorGetParam
{
public:
    enum
    {
        AISENSOR_CHECK_OPTION_DEFAULT = 0,
        AISENSOR_CHECK_OPTION_IGNORE_TARGET_SCR_COLLITION = 1,
        AISENSOR_CHECK_OPTION_IGNORE_DISACTIVE = 2,
    };
public:
    cAISensorGetParam();
    bool isEq(const cAISensorGetParam&);
    void setCategoryFlag(const cGpCategoryFlag&);
    void setCategory(u32 cat0);
    void setCategory(u32, u32);
    void setCategory(u32, u32, u32);
    void setOwnerDTI(const MtDTI* pDti);
    void setObjectID(s32);
    void setUserFlag(u32);
    void setCheckOption(u32 option);
    const cGpCategoryFlag& getCategoryFlag() const;
    const MtDTI* getOwnerDTI() const;
    s32 getObjectID() const;
    u32 getUserFlag() const;
    u32 getCheckOption() const;
private:
    cGpCategoryFlag mGpCategoryFlag;  // offset: 0x0
    const MtDTI* mpOwnerDTI;  // offset: 0x8
    s32 mObjectID;  // offset: 0x10
    u32 mUserTypeBit;  // offset: 0x14
    u32 mCheckOption;  // offset: 0x18
};

class cAISensorNode : public cAIObject
{
public:
    enum
    {
        FLAG_UPDATED = 0,
        FLAG_NUM = 1,
    };
public:
    class MyDTI;
public:
    using cAISensorNodeFlag = nDDOUtility::cBitSet<1>;
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
    cAISensorNode();
    void setSensorNode(const cAISensorNodeRes* pRes);
    void updateNodeMatrix(uCoord* pOwner);
    void searchSensor(MtTypedArray<uDDOModel>& dst, const cAISensorGetParam& param, cAISensorCheckFuncPtr& func, void* pParam);
    void searchSensor(MtTypedArray<cGeneralPoint>& dst, const cAISensorGetParam& param, cAISensorCheckFuncPtr& func, void* pParam);
private:
    void searchSensorSubDirAdjust(f32& efcAngle, MtVector2& dir);
    bool searchSensorSubRadius(const cGeneralPoint* pGp, const MtGeomSphere& sphere);
    bool searchSensorSubAngle(const MtVector3& gpPos, const MtGeomSphere& sphere, const MtVector2& dir, f32 efcAngle);
    bool searchSensorSubScr(u32 statusFlag, cGeneralPoint& gp, const MtGeomSphere& sphere, f32 efcAngle, bool ignoreTargetScr);
public:
    cAISensorNodeFlag& aiSensorNodeFlag();
    const cAISensorNodeRes* getRes() const;
private:
    const cAISensorNodeRes* mpRes;  // offset: 0x8
    cAISensorNodeFlag mNodeFlag;  // offset: 0x10
    MtMatrix mNodeMatrix;  // offset: 0x20
    MtGeomSphere mNodeGeom;  // offset: 0x60
public:
    static MyDTI DTI;
};

class cpAISensor : public cpComponent
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
    cpAISensor();
    virtual ~cpAISensor();
    void setSensorRes(rAISensor* pRes);
    void clear();
    bool isEnableSensor();
    virtual void move();  // vtable slot 7
    void searchSensor(MtTypedArray<uDDOModel>& dst, const cAISensorGetParam& param);
    void searchSensor(MtTypedArray<cGeneralPoint>& dst, const cAISensorGetParam& param);
    virtual void updatePtr();  // vtable slot 9
    void setActiveGroupAll(bool active);
    void setActiveGroup(bool active, u32 flag);
    void setActiveGroupOnly(u32 flag);
    void setCheckFunc(MtObject*, AISensorCheckFunc, void*);
private:
    s32 mEnableGroupFlag;  // offset: 0x50
    cAISensorCheckFuncPtr mFunc;  // offset: 0x58
    void* mpFuncParam;  // offset: 0x70
    res_ptr<rAISensor> mpSensorRes;  // offset: 0x78
    MtTypedArray<cAISensorNode> mpNodes;  // offset: 0x80
    cAISensorGetParam mCasheParam;  // offset: 0xa0
public:
    static MyDTI DTI;
};

inline const MtDTI* cAISensorGetParam::getOwnerDTI() const {
    return this->mpOwnerDTI;
}

inline s32 cAISensorGetParam::getObjectID() const {
    return this->mObjectID;
}

inline u32 cAISensorGetParam::getUserFlag() const {
    return this->mUserTypeBit;
}

inline void* cAISensorNode::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline const cAISensorNodeRes* cAISensorNode::getRes() const {
    return this->mpRes;
}

inline void* cpAISensor::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
