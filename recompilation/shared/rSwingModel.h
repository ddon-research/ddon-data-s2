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
class MtObject;
class MtPropertyList;
class MtStream;
class MtTime;
class MtVector3;
namespace nDraw { class VertexBuffer; }

// Declarations
class rSwingModel;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class rSwingModel : public cResource
{
public:
    enum SWING_MODE
    {
        SM_DEFAULT = 0,
        SM_YAXIS = 1,
        SM_ALL = 2,
        SM_BILLBOARD = 3,
    };
public:
    class MyDTI;
    struct PRIMITIVE_QUANT_INFO;
    struct HEADER;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct PRIMITIVE_QUANT_INFO
    {
    public:
        static void* operator new(size_t);
        static void* operator new[](size_t s);
        static void operator delete(void*);
        static void operator delete[](void* pObj);
    public:
        MtVector3 quant_scale;  // offset: 0x0
        u32 vertex_base;  // offset: 0x10
        MtVector3 quant_offset;  // offset: 0x20
        u32 vertex_num : 16;  // offset: 0x30
        u32 vertex_stride : 8;  // offset: 0x30
        u32 no_wind : 1;  // offset: 0x30
        u32 billboard_flag : 1;  // offset: 0x30
        u32 billboard_rotate : 1;  // offset: 0x30
        u32 billboard_fix_axis : 1;  // offset: 0x30
        u32 reserved : 3;  // offset: 0x30
    };
public:
    struct HEADER
    {
    public:
        u32 magic;  // offset: 0x0
        u16 version;  // offset: 0x4
        u16 dummy;  // offset: 0x6
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
    rSwingModel();
    virtual ~rSwingModel();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    const PRIMITIVE_QUANT_INFO* getPrimitiveQuantInfo() const;
    nDraw::VertexBuffer* getVertexBuffer() const;
    virtual MtTime getUpdateTime(MT_CTSTR fullpath);  // vtable slot 6
    bool getHighPrecisionMode() const;
    bool getAdjustPosition() const;
    bool getAdjustNormalTangent() const;
    bool getUseWorldPosition() const;
    u32 getSwingMode() const;
    f32 getFrequencyFactor() const;
protected:
    PRIMITIVE_QUANT_INFO* mpPrimQuantInfo;  // offset: 0x70
    nDraw::VertexBuffer* mpVertexBuffer;  // offset: 0x78
    bool mHighPrecisionMode;  // offset: 0x80
    bool mAdjustPosition;  // offset: 0x81
    bool mAdjustNormalTangent;  // offset: 0x82
    bool mUseWorldPosition;  // offset: 0x83
    u32 mSwingMode;  // offset: 0x84
    f32 mFrequencyFactor;  // offset: 0x88
    static const u32 DEFAULT_VERTEX_STRIDE = 4;
    static const u32 HIGH_PRECISION_VERTEX_STRIDE = 8;
    static const u32 MAX_VERTEX_STRIDE = 8;
public:
    static MyDTI DTI;
protected:
    static const u32 HEADER_MAGIC = 5068627;
    static const u16 DATA_VERSION = 3805;
};

// Inline, no code of its own: checked where it is inlined.
// inferred: the constructor from _ZNK11rSwingModel5MyDTI11newInstanceEv at 0x011e1250-0x011e12b5, code DWARF attributes to no inlined copy
inline rSwingModel::rSwingModel() {
    this->::cResource::mAttr = static_cast<u32>(16);
    this->mSwingMode = static_cast<u32>(0);
    this->mHighPrecisionMode = false;
    this->mpVertexBuffer = static_cast<nDraw::VertexBuffer*>(nullptr);
    this->mpPrimQuantInfo = static_cast<rSwingModel::PRIMITIVE_QUANT_INFO*>(nullptr);
    this->mAdjustPosition = true;
    this->mAdjustNormalTangent = false;
    this->mUseWorldPosition = false;
    this->mFrequencyFactor = 1.0f;
}
