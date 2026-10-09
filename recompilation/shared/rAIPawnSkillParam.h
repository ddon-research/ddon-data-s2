#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cAIObject.h"
#include "nDDOUtility.h"
#include "rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtObject;
class MtVector3;

// Declarations
class cAIPawnSkillParamNode;
class rAIPawnSkillParamTbl;
struct stSkillRangeXZY;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using cAIPawnOcdArray = nDDOUtility::cArray<unsigned int, 16>;
using cAIPawnSkillParamFlag = nDDOUtility::cBitSet<14>;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

struct stSkillRangeXZY
{
public:
    f32 MaxRangeXZ;  // offset: 0x0
    f32 MinRangeXZ;  // offset: 0x4
    f32 MaxRangeY;  // offset: 0x8
    f32 MinRangeY;  // offset: 0xc
};

class cAIPawnSkillParamNode : public cAIResource
{
public:
    enum
    {
        DATA_VERSION = 6,
    };
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
    cAIPawnSkillParamNode();
    virtual ~cAIPawnSkillParamNode();
    void load(MtDataReader& r);
    void calcSkillRange(stSkillRangeXZY* pDst, bool isLand);
    bool isInRange(const MtVector3& srcPos, const MtVector3& targetPos, f32 targetSize, bool isLand);
    s32 getActionNo();
public:
    s32 mJob;  // offset: 0x8
    s32 mActNo;  // offset: 0xc
    s32 mNormalSkillId;  // offset: 0x10
    stSkillRangeXZY mSkillRange;  // offset: 0x14
    u32 mInputInfo;  // offset: 0x24
    u32 mInputInfoReady;  // offset: 0x28
    cAIPawnSkillParamFlag mAIPawnSkillParamFlag;  // offset: 0x2c
    cAIPawnOcdArray mSkillOcd;  // offset: 0x30
    static MyDTI DTI;
};

class rAIPawnSkillParamTbl : public rTbl2<cAIPawnSkillParamNode>
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
    rAIPawnSkillParamTbl();
    virtual ~rAIPawnSkillParamTbl();
    virtual bool loadCore(MtDataReader& r);  // vtable slot 21
    virtual bool loadData(MtDataReader& r, cAIPawnSkillParamNode* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline rAIPawnSkillParamTbl::rAIPawnSkillParamTbl() {
}
