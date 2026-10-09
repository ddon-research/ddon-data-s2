#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "cAIObject.h"
#include "cResource.h"
#include "nDDOUtility.h"
#include "rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtObject;
class MtStream;

// Declarations
class cAIPawnAutoMotionNode;
class cAIPawnAutoWordNode;
class rAIPawnAutoMotionTbl;
class rAIPawnAutoWordTbl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using cAIPawnTalkMotSituationFlag = nDDOUtility::cBitSet<10>;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cAIPawnAutoMotionNode : public cAIResource
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
    cAIPawnAutoMotionNode();
    virtual ~cAIPawnAutoMotionNode();
    u32 getEMotActionNo();
    void load(MtDataReader& r);
public:
    u32 mMotType;  // offset: 0x8
    u32 mGroupNo;  // offset: 0xc
    u32 mGroupSelectType;  // offset: 0x10
    u32 mWaitMoveType;  // offset: 0x14
    f32 mBeginMinFrame;  // offset: 0x18
    f32 mBeginMaxFrame;  // offset: 0x1c
    cAIPawnTalkMotSituationFlag mEnableSituation;  // offset: 0x20
private:
    u32 mEMotActionNo;  // offset: 0x24
public:
    static MyDTI DTI;
};

class cAIPawnAutoWordNode : public cAIResource
{
public:
    enum
    {
        DATA_VERSION = 4,
    };
public:
    class MyDTI;
public:
    using cPersonalityMsgNos = nDDOUtility::cArray<unsigned int, 9>;
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
    cAIPawnAutoWordNode();
    virtual ~cAIPawnAutoWordNode();
public:
    u32 mAutoWordSituationID;  // offset: 0x8
    u32 mAutoCommonSituationID;  // offset: 0xc
    u32 mLinkAutoMotionType;  // offset: 0x10
    cPersonalityMsgNos mPersonalityMsgNos;  // offset: 0x14
    cPersonalityMsgNos mPersonalitySndNos;  // offset: 0x38
    static MyDTI DTI;
};

class rAIPawnAutoMotionTbl : public cResource
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
    rAIPawnAutoMotionTbl();
    virtual ~rAIPawnAutoMotionTbl();
    bool isMatchMotType(u32 motGroup, u32 motType);
    cAIPawnAutoMotionNode* getData(u32 idx);
    u32 getDataNum() const;
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual bool load(MtStream& in);  // vtable slot 11
public:
    MtTypedArray<cAIPawnAutoMotionNode> mArray;  // offset: 0x70
    static MyDTI DTI;
};

class rAIPawnAutoWordTbl : public rTbl2<cAIPawnAutoWordNode>
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
    virtual bool loadData(MtDataReader& r, cAIPawnAutoWordNode* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};
