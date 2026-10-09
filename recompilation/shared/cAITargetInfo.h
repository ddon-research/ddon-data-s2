#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "cGeneralPointPtr.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector3;
class cGeneralPoint;
class cGeneralPointPtr;
class uDDOModel;

// Declarations
class cAITargetInfo;
class cAITargetInfoArray;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cAITargetInfo : public MtObject
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
    cAITargetInfo();
    bool isEnableHitInfo() const;
    const MtVector3& getAITargetInfoOfsPos() const;
    f32 getAITargetInfRadius() const;
public:
    uDDOModel* mpTargetUnit;  // offset: 0x8
    cGeneralPointPtr mpTargetPoint;  // offset: 0x10
    f32 mEnableFrame;  // offset: 0x20
    f32 mEvaluation;  // offset: 0x24
    static MyDTI DTI;
};

class cAITargetInfoArray : public MtTypedArray<cAITargetInfo>
{
public:
    using CheckFunc = bool(MtObject::*)(cAITargetInfo*, void*);
    using EvaFunc = f32(MtObject::*)(cAITargetInfo*, cAITargetInfoArray*, f32, void*);
    using CheckFuncStatic = bool(*)(cAITargetInfo*, void*);
public:
    cAITargetInfoArray();
    void moveAITargetInfoArray(f32 deltatime);
    void updatePtr();
    cAITargetInfo* findUnit(const uDDOModel* pUnit);
    cAITargetInfo* findPoint(cGeneralPoint* pGp);
    cAITargetInfo* findNear(const MtVector3& pos, f32 maxLen);
    cAITargetInfo* findNearFunc(const MtVector3& pos, CheckFuncStatic func, void* pParam, f32 maxLen);
    void addInfoUnit(uDDOModel* pUnit, f32 frame, f32 eva, bool isAddEva);
    void addInfoPoint(cGeneralPoint* pGp, f32 frame, f32 eva, bool isAddEva);
    void setCheckFuncDef();
    void setEvaFuncDef();
    f32 getMaxEvaluation() const;
    cGeneralPoint* getHitPoint(u32 idx);
private:
    bool checkFuncDef(cAITargetInfo* pTarget, void* pParam);
    f32 evaFuncDef(cAITargetInfo* pTarget, cAITargetInfoArray* pArray, f32 deltaTime, void* pParam);
    uDDOModel* getHitUnitCore(u32 idx);
    f32 calcEnvMinMax(f32 eva);
    static bool sortFunc(const cAITargetInfo* pA, const cAITargetInfo* pB, u32);
private:
    MtObject* mpChkFuncOwner;  // offset: 0x20
    CheckFunc mCheckFunc;  // offset: 0x28
    void* mpCheckEvaParam;  // offset: 0x38
    MtObject* mpEvaFuncOwner;  // offset: 0x40
    EvaFunc mEvaFunc;  // offset: 0x48
    void* mpEvaEvaParam;  // offset: 0x58
    f32 mMaxEvaluation;  // offset: 0x60
    f32 mMinEvaluation;  // offset: 0x64
    f32 mSubEvaluation;  // offset: 0x68
};

// Inline, no code of its own: checked where it is inlined.
inline cAITargetInfo::cAITargetInfo() {
    this->mpTargetUnit = static_cast<uDDOModel*>(nullptr);
    this->mEnableFrame = 0.0f;
    this->mEvaluation = 0.0f;
}
