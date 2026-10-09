#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "cResource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
struct MtFloat3;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtUI;

// Declarations
class rVibration;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class rVibration : public cResource
{
public:
    enum VIB_TYPE
    {
        VIB_TYPE_NONE = 0,
        VIB_TYPE_SINGLE = 1,
        VIB_TYPE_NUM = 2,
    };
    enum VIB_OPTION_FLAG
    {
        VIB_OPTION_FLAG_RESERVED0 = 1,
        VIB_OPTION_FLAG_RESERVED1 = 2,
        VIB_OPTION_FLAG_RESERVED2 = 4,
        VIB_OPTION_FLAG_RESERVED3 = 8,
        VIB_OPTION_FLAG_FADE = -2147483648,
    };
public:
    class MyDTI;
    struct VIB_INDEX;
    struct VIB_COMMON;
    struct VIB_PAD_SINGLE;
    struct VIB_CAM_SINGLE;
    struct VIB_HEADER;
public:
    using VIB_INDEX = rVibration::VIB_INDEX;
    using VIB_COMMON = rVibration::VIB_COMMON;
    using VIB_PAD_SINGLE = rVibration::VIB_PAD_SINGLE;
    using VIB_CAM_SINGLE = rVibration::VIB_CAM_SINGLE;
    using VIB_HEADER = rVibration::VIB_HEADER;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct VIB_INDEX
    {
    public:
        u32 PadVibType : 8;  // offset: 0x0
        u32 PadVibParamOffset : 24;  // offset: 0x0
        u32 CamVibType : 8;  // offset: 0x4
        u32 CamVibParamOffset : 24;  // offset: 0x4
        u32 VIBIndex3208;  // offset: 0x8
        u32 VIBIndex320c;  // offset: 0xc
    };
public:
    struct VIB_COMMON
    {
    public:
        u32 VibOptionFlag;  // offset: 0x0
        u32 VCommon3207;  // offset: 0x4
        f32 VibFadeStartDist;  // offset: 0x8
        f32 VibFadeEndDist;  // offset: 0xc
    };
public:
    struct VIB_PAD_SINGLE : public rVibration::VIB_COMMON
    {
    public:
        f32 HighVibStartRate;  // offset: 0x10
        f32 HighVibEndRate;  // offset: 0x14
        u32 HighVibTime;  // offset: 0x18
        u32 VPSingle321c;  // offset: 0x1c
        f32 LowVibStartRate;  // offset: 0x20
        f32 LowVibEndRate;  // offset: 0x24
        u32 LowVibTime;  // offset: 0x28
        u32 VPSingle322c;  // offset: 0x2c
    };
public:
    struct VIB_CAM_SINGLE : public rVibration::VIB_COMMON
    {
    public:
        MtFloat3 VibVec;  // offset: 0x10
        f32 VibTargetScale;  // offset: 0x1c
        u32 VibCycle;  // offset: 0x20
        u32 VibTime;  // offset: 0x24
        u32 VibAttenuateTime;  // offset: 0x28
        u32 VCSingle322c;  // offset: 0x2c
    };
public:
    struct VIB_HEADER
    {
    public:
        u32 Magic;  // offset: 0x0
        u32 Version;  // offset: 0x4
        u32 ParamBuffSize;  // offset: 0x8
        u32 BaseFps : 16;  // offset: 0xc
        u32 ListNum : 16;  // offset: 0xc
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
    rVibration();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual void clear();  // vtable slot 15
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    u32 getResourceSize() const;
    f32 getBaseFps() const;
    u32 getListNum() const;
    void setDummyU32(u32);
    void setDummyF32(f32);
    VIB_INDEX* getVIBIndex(u32 ListNo);
    VIB_COMMON* getPadVibParam(VIB_INDEX* pIndex);
    VIB_COMMON* getPadVibParam(u32 ListNo);
    VIB_COMMON* getCamVibParam(VIB_INDEX* pIndex);
    VIB_COMMON* getCamVibParam(u32 ListNo);
protected:
    virtual ~rVibration();
    bool allocMemory(u32 ParamBuffSize);
private:
    void constructParam();
    void destructParam();
    void freeMemory();
protected:
    u8* mpParamBuff;  // offset: 0x70
    u32 mParamBuffSize;  // offset: 0x78
    f32 mBaseFps;  // offset: 0x7c
    u32 mListNum;  // offset: 0x80
public:
    static MyDTI DTI;
protected:
    static const u32 VIB_MAGIC = 4344150;
    static const u32 VIB_VERSION;
};

// Inline, no code of its own: checked where it is inlined.
// inferred: the constructor from _ZNK10rVibration5MyDTI11newInstanceEv at 0x01205960-0x0120599f, code DWARF attributes to no inlined copy
inline rVibration::rVibration() {
    this->mListNum = static_cast<u32>(0);
    this->mParamBuffSize = static_cast<u32>(0);
    this->mBaseFps = 0.0f;
    this->mpParamBuff = static_cast<u8*>(nullptr);
    this->::cResource::mAttr = static_cast<u32>(22);
}
