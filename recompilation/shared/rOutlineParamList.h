#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "cResource.h"
#include "nDDOUtility.h"
#include "sEffectExt.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtStream;
class MtVector4;
class cpDDMrlMgr;

// Declarations
class cOutlineCtrl;
class cOutlineParam;
class rOutlineParamList;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
namespace nDDOUtility { using cKeyFrameValueColor = nDDOUtility::cKeyFrameValue<MtVector4, MtObject>; }
namespace nDDOUtility { using cKeyFrameValueF32 = nDDOUtility::cKeyFrameValue<float, MtObject>; }
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cOutlineCtrl
{
public:
    cOutlineCtrl();
    void request(sEffectExt::OUTLINE type);
    void request(const cOutlineParam* pNew);
    void update(cpDDMrlMgr* pOwnerMrlMgr);
    const cOutlineParam* const getOutlineParam();
private:
    const cOutlineParam* mpRequestParam;  // offset: 0x0
    const cOutlineParam* mpParam;  // offset: 0x8
    f32 mAnimFrame;  // offset: 0x10
    f32 mEndFrame;  // offset: 0x14
    u32 mEndFrameMax;  // offset: 0x18
    MtVector4 mEndColorO;  // offset: 0x20
    MtVector4 mEndColorI;  // offset: 0x30
};

class cOutlineParam : public MtObject
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
    cOutlineParam();
    virtual ~cOutlineParam();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    u32 mPriority;  // offset: 0x8
    f32 mFrame;  // offset: 0xc
    bool mIsLoop;  // offset: 0x10
    bool mIsOWAgain;  // offset: 0x11
    u32 mEndFrame;  // offset: 0x14
    f32 mWeatherRate;  // offset: 0x18
    u32 mOutlineBlendType;  // offset: 0x1c
    u32 mOutlineColorType;  // offset: 0x20
    nDDOUtility::cKeyFrameValueColor mOutlineOColor;  // offset: 0x30
    nDDOUtility::cKeyFrameValueColor mOutlineIColor;  // offset: 0x140
    nDDOUtility::cKeyFrameValueF32 mOutlineBalanceOffset;  // offset: 0x250
    nDDOUtility::cKeyFrameValueF32 mOutlineBalanceScale;  // offset: 0x2a0
    nDDOUtility::cKeyFrameValueF32 mOutlineBalance;  // offset: 0x2f0
    bool mIsUseShaderParam;  // offset: 0x340
    u32 mShaderMode;  // offset: 0x344
    f32 mShaderBlendRate;  // offset: 0x348
    nDDOUtility::cKeyFrameValueF32 mShaderBasePower;  // offset: 0x350
    static MyDTI DTI;
};

class rOutlineParamList : public cResource
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
    rOutlineParamList();
    virtual ~rOutlineParamList();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void clear();  // vtable slot 15
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    const MtArray& getParamList() const;
    void setParamList(const MtArray& list);
    const cOutlineParam* const getParam(sEffectExt::OUTLINE index);
protected:
    MtArray mParamList;  // offset: 0x70
public:
    static MyDTI DTI;
protected:
    static const u8 DATA_VERSION = 1;
};
