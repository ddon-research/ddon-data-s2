#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/cpComponent.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cpSequenceCtrl;
class rCnsTinyChain;
class uCnsTinyChain;
class uModel;

// Declarations
class cpTinyChain;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cpTinyChain : public cpComponent
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
    cpTinyChain();
    virtual ~cpTinyChain();
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void updatePtr();  // vtable slot 9
    virtual void kill();  // vtable slot 8
    rCnsTinyChain* getResource();
    void setResource(rCnsTinyChain* pResource);
    void setCnsTinyChain(uModel* pModel, MT_CTSTR Path);
    void setCnsTinyChain(uModel* pModel, rCnsTinyChain* pResource);
    virtual void setActive(bool isActive);  // vtable slot 13
    void reset();
    void resetForEvent(u32 stabilizeNum);
    void initActiveSequence(s32 pageNo, s32 indexNo, f32 blendSpeed);
    void updateActiveSequence();
    void endActiveSequence();
    void setBlendSpeedCain(f32 blendSpeed);
protected:
    rCnsTinyChain* mprCnsTinyChain;  // offset: 0x50
    uCnsTinyChain* mpCnsTinyChain;  // offset: 0x58
    cpSequenceCtrl* mpSequenceCtrl;  // offset: 0x60
    bool mIsActiveSequence;  // offset: 0x68
    f32 mBlendSpeedChain;  // offset: 0x6c
    s32 mCheckSeqPageNo;  // offset: 0x70
    s32 mCheckSeqIndex;  // offset: 0x74
public:
    static MyDTI DTI;
protected:
    static const u32 STABLIZE_NUM = 20;
    static const u32 EVENT_STABLIZE_NUM = 200;
};
