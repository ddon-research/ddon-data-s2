#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "cpComponent.h"
#include "rAIPawnEmParam.h"
#include "res_ptr.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cAIPawnEmNode;
class rAIPawnEmParam;

// Declarations
class cpAIPawnEmChecker;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cpAIPawnEmChecker : public cpComponent
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
    cpAIPawnEmChecker();
    virtual ~cpAIPawnEmChecker();
protected:
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void updatePtr();  // vtable slot 9
    void updateActiveAIPawnEmPrmNode();
    void updateEnableSearchCore();
public:
    u32 getActivePrmNodeNum() const;
    const cAIPawnEmNode* getActivePrmNode(u32 idx) const;
    s32 getRootPoint() const;
    f32 getDistance() const;
    f32 getRangeSize() const;
    bool isEnableSearchCore() const;
    void setAIPawnEmParam(rAIPawnEmParam* pRes);
    void getActiveAIPawnEmPrmNode(MtTypedArray<cAIPawnEmNode>& dst);
    rAIPawnEmParam* getAIPawnEmParam();
    const rAIPawnEmParam* getAIPawnEmParam() const;
    bool isWeakAttr(u32 attr) const;
private:
    res_ptr<rAIPawnEmParam> mpEmParam;  // offset: 0x50
    MtTypedArray<cAIPawnEmNode> mActivePrmNode;  // offset: 0x58
    bool mIsEnableSearchCore;  // offset: 0x78
public:
    static MyDTI DTI;
};

inline void* cpAIPawnEmChecker::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
