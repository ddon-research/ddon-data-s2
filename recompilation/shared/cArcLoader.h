#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class rArchive;

// Declarations
class cArcLoaderBase;
class cAsyncArc;
class cTagArcLoad;
template <unsigned int N> class cArcLoader;

// Type aliases from DWARF
using u32 = unsigned int;
using ARC_TAGID = u32;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using cArcLoader01 = cArcLoader<1>;
using cArcLoader04 = cArcLoader<4>;
using s16 = short;
using s32 = int;
using size_t = _Sizet;
using u8 = unsigned char;

class cArcLoaderBase : public MtObject
{
public:
    enum
    {
        PICK_FLAG_NONE = 0,
        PICK_FLAG_NOPICK = 1,
        PICK_FLAG_FILL = 255,
    };
    enum
    {
        STATE_WAIT = 0,
        STATE_STACK = 1,
        STATE_ACTIVE = 2,
        STATE_LOADED = 3,
        STATE_NUM = 4,
    };
    enum
    {
        FLAG_ON_CANCEL = 1,
        FLAG_ON_FAILED = 2,
        FLAG_NONE = 0,
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
    cArcLoaderBase();
    virtual ~cArcLoaderBase();
    bool loadReqTag(ARC_TAGID t, s16 pri);
    bool loadReqTag();
    void clear();
    void releaseArc();
protected:
    void reqCancel();
public:
    bool isArcLoad() const;
    rArchive* getArcPtr(u32 index);
    ARC_TAGID getArcTag(u32 index);
    u8 getArcNum() const;
    void addTag(ARC_TAGID t);
    void setPrio(s16 pri);
    bool isLoadFinish() const;
    bool isResultFailed() const;
    void setArcPtr(rArchive* pArc, ARC_TAGID t, u32 index);
private:
    s32 loadReqTagCore();
public:
    void updateLoadFilish();
    void updateLoadFilishRes(ARC_TAGID tag, rArchive* pRes);
    void setArcPtrIndex(rArchive* pArc, u32 index);
    u8 getStateArcLoader() const;
    void setStateArcLoader(u8 state);
    void setStateArcLoaderClear();
    void setStateArcLoaderWaitLoad(s16 handle);
    void onPickedFlag();
    void offPickedFlag();
    void setRetFlagArcLoader(bool isCancel, bool isFailed);
private:
    bool isArcLoadActive() const;
    bool isResultCancel() const;
    u32 getState() const;
protected:
    rArchive* * mppArc;  // offset: 0x8
    u8 mMaxNum;  // offset: 0x10
public:
    ARC_TAGID* mpTag;  // offset: 0x18
    u8 mNum;  // offset: 0x20
    u8 mReqNum;  // offset: 0x21
    u8 mPickedFlag;  // offset: 0x22
    u8 mTicketEnable;  // offset: 0x23
    s16 mPri;  // offset: 0x24
    s16 mHandle;  // offset: 0x26
private:
    u8 mState;  // offset: 0x28
    u8 mRetFlag;  // offset: 0x29
public:
    static MyDTI DTI;
};

template <>
class cArcLoader<16> : public cArcLoaderBase
{
public:
    cArcLoader();
private:
    rArchive* mArcBuff[16];  // offset: 0x30
    ARC_TAGID mTagBuff[16];  // offset: 0xb0
};

template <>
class cArcLoader<1> : public cArcLoaderBase
{
public:
    cArcLoader();
private:
    rArchive* mArcBuff[1];  // offset: 0x30
    ARC_TAGID mTagBuff[1];  // offset: 0x38
};

template <>
class cArcLoader<32> : public cArcLoaderBase
{
public:
    cArcLoader();
private:
    rArchive* mArcBuff[32];  // offset: 0x30
    ARC_TAGID mTagBuff[32];  // offset: 0x130
};

template <>
class cArcLoader<4> : public cArcLoaderBase
{
public:
    cArcLoader();
private:
    rArchive* mArcBuff[4];  // offset: 0x30
    ARC_TAGID mTagBuff[4];  // offset: 0x50
};

class cAsyncArc : public cArcLoader01
{
public:
    void setTagId(ARC_TAGID id);
    void releaseArc();
    void cancelArc();
    void clear();
};

class cTagArcLoad : public cArcLoader04
{
public:
    void setupArcLoad();
    void setArcTagEx(ARC_TAGID tag);
    void startArcLoad();
    bool moveArcTag();
};
