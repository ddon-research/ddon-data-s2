#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cSystem.h"
#include "nDDOUtility.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cHitNode;

// Declarations
class sAIPawnNotice;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class sAIPawnNotice : public cSystem
{
public:
    class MyDTI;
public:
    using cAIPawnHitNodeStack = nDDOUtility::cArray<cHitNode*, 256>;
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
    sAIPawnNotice();
    virtual ~sAIPawnNotice();
    virtual void move();  // vtable slot 7
    virtual void reset();  // vtable slot 6
    static sAIPawnNotice* getInstance();
    void initGame();
    void initStage();
    s32 getRefNodeNum() const;
    const cHitNode* getRefNode(s32 idx) const;
    void reqAddHitNodeNotice(cHitNode* pNotice);
    void reqDelHitNodeNotice(cHitNode* pNotice);
private:
    void updateCheckNodeNotice();
private:
    s32 mRefNodeStackIdx;  // offset: 0x14
    s32 mRefNodeNum;  // offset: 0x18
    cAIPawnHitNodeStack mRefNodeStack;  // offset: 0x20
    bool mReqDelete;  // offset: 0x820
public:
    static MyDTI DTI;
private:
    static sAIPawnNotice* mpInstance;
};

// Inline, no code of its own: checked where it is inlined.
inline sAIPawnNotice* sAIPawnNotice::getInstance() {
    return ::sAIPawnNotice::mpInstance;
}
