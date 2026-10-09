#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtPrimitive2D.h"
#include "cResource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
struct MtFloat2;
class MtObject;
class MtPoint;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtUI;

// Declarations
class cEffectAnim;
class rEffectAnim;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using s16 = short;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class rEffectAnim : public cResource
{
public:
    enum ANIM_FLAG
    {
        ANIM_FLAG_MOVE = 1,
        ANIM_FLAG_LOOP = 2,
        ANIM_FLAG_REVERSE = 4,
        ANIM_FLAG_FINISH = 8,
        ANIM_FLAG_BASE = 15,
        ANIM_FLAG_REVERSE_RAND = 16,
        ANIM_FLAG_HFLIP = 256,
        ANIM_FLAG_VFLIP = 512,
        ANIM_FLAG_HFLIP_RAND = 1024,
        ANIM_FLAG_VFLIP_RAND = 2048,
        ANIM_FLAG_ROT = 4096,
        ANIM_FLAG_NO_INP = 8192,
        ANIM_FLAG_EXTEND = 16144,
        ANIM_FLAG_MODEL_EXCL = 7952,
        ANIM_FLAG_KEYFRAME = 32768,
    };
public:
    class MyDTI;
    struct SEQ_INDEX;
    struct SEQ_PAT;
    struct EAN_HEADER;
public:
    using SEQ_INDEX = rEffectAnim::SEQ_INDEX;
    using SEQ_PAT = rEffectAnim::SEQ_PAT;
    using EAN_HEADER = rEffectAnim::EAN_HEADER;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct SEQ_INDEX
    {
    public:
        u32 SeqPatTopOffset;  // offset: 0x0
        u32 SeqPatNum : 16;  // offset: 0x4
        u32 DefaultAnimFlag : 16;  // offset: 0x4
        MtPoint DefaultPatCenter;  // offset: 0x8
        MtPoint ConPatBasePoint;  // offset: 0x10
        u32 ConPatColNum : 16;  // offset: 0x18
        u32 ConPatTotalNum : 16;  // offset: 0x18
        u32 ConPatSizeW : 16;  // offset: 0x1c
        u32 ConPatSizeH : 16;  // offset: 0x1c
    };
public:
    struct SEQ_PAT
    {
    public:
        union
        {
        public:
            struct
            {
            public:
                s16 U;  // offset: 0x0
                s16 V;  // offset: 0x2
                s16 W;  // offset: 0x4
                s16 H;  // offset: 0x6
            };  // offset: 0x0
            u64 Rect;  // offset: 0x0
        };  // offset: 0x0
        f32 U0;  // offset: 0x8
        f32 V0;  // offset: 0xc
        f32 U1;  // offset: 0x10
        f32 V1;  // offset: 0x14
    };
public:
    struct EAN_HEADER
    {
    public:
        u32 Magic;  // offset: 0x0
        u32 Version;  // offset: 0x4
        u32 ParamBuffSize;  // offset: 0x8
        u32 SeqNum : 24;  // offset: 0xc
        u32 OptionFlag : 8;  // offset: 0xc
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
    rEffectAnim();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual void clear();  // vtable slot 15
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    u32 getResourceSize() const;
    u32 getSeqNum() const;
    void setDummyU32(u32);
    SEQ_INDEX* getSeqIndex(u32 SeqNo) const;
    SEQ_PAT* getSeqPat(SEQ_INDEX* pSeqIndex, u32 PatNo) const;
    SEQ_PAT* getSeqPat(u32 SeqNo, u32 PatNo) const;
    bool checkBuild() const;
protected:
    virtual ~rEffectAnim();
    bool allocMemory(u32 ParamBuffSize);
private:
    void constructParam();
    void destructParam();
protected:
    u32 mParamBuffSize;  // offset: 0x70
    u32 mSeqNum : 24;  // offset: 0x74
    u32 mOptionFlag : 8;  // offset: 0x74
    union
    {
    public:
        u8* mpParamBuff;  // offset: 0x0
        rEffectAnim::SEQ_INDEX* mSeqIndexArray;  // offset: 0x0
    };  // offset: 0x78
public:
    static MyDTI DTI;
protected:
    static const u32 EAN_MAGIC = 5128517;
    static const u32 EAN_VERSION;
};

class cEffectAnim
{
public:
    cEffectAnim();
    void clear();
    void init(rEffectAnim* pAnim, u32 SeqNo, f32 PatNoRate, u32 AnimFlag, f32 PatSpeed);
    bool move();
    bool move(f32 PatNoRate);
    u32 getAnimFlag() const;
    void setPatSpeed(f32 PatSpeed);
    void setPatSpeedEx(f32 PatSpeed);
    f32 getPatNoRate() const;
    void stop();
    f32 getBlendPatInfo(f32, f32, f32, u32*, u32*) const;
    u32 getPatNo(f32 OldPatNoRate, f32 CurPatNoRate, f32 InpRate) const;
    rEffectAnim::SEQ_PAT* getSeqPat(rEffectAnim* pAnim, u32 PatNo) const;
    rEffectAnim::SEQ_PAT* getSeqPat(rEffectAnim* pAnim, f32 OldPatNoRate, f32 CurPatNoRate, f32 InpRate) const;
    MtFloat2 getSeqPatOfs(rEffectAnim* pAnim, f32 OldPatNoRate, f32 CurPatNoRate, f32 InpRate) const;
    u32 getSeqNo() const;
private:
    u32 mAnimFlag : 16;  // offset: 0x0
    u32 mSeqNo : 16;  // offset: 0x0
    u32 mPatNum : 16;  // offset: 0x4
    u32 mPatNoMax : 16;  // offset: 0x4
    f32 mPatNoRate;  // offset: 0x8
    f32 mPatSpeed;  // offset: 0xc
};
