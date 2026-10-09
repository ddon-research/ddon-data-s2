#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "cpComponent.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector3;
class uDDOModel;

// Declarations
class cpSafePos;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cpSafePos : public cpComponent
{
    // inferred: uDDOModel::countUpSafePosWarpLoop names cpSafePos::mInfiLoopCheckCount
    friend class uDDOModel;
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
    cpSafePos();
    virtual ~cpSafePos();
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    virtual void setup();  // vtable slot 6
    virtual void updatePtr();  // vtable slot 9
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 11
    void compMoveAfter();
    void initPos(const MtVector3& clearPos);
    const MtVector3& getSafePos();
    bool isNowSafePos();
    void countUpSafePosWarpLoop();
    void clearLoopCount();
private:
    bool checkSafePos();
public:
    void forceUpdateSafePos(const MtVector3& pos);
    void requestSafePosSetLand();
private:
    void updateSafePos(const MtVector3& pos);
public:
    uDDOModel* mpModel;  // offset: 0x50
private:
    MtVector3 mPosHistory[60];  // offset: 0x60
    bool mIsNowSafePos;  // offset: 0x420
    u32 mInfiLoopCheckCount;  // offset: 0x424
public:
    static MyDTI DTI;
private:
    static const u32 POS_HISTORY_MAX = 60;
};

// Inline, no code of its own: checked where it is inlined.
inline bool cpSafePos::isNowSafePos() {
    return this->mIsNowSafePos;
}
