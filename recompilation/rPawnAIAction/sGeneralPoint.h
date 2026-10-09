#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/cSystem.h"
#include "../shared/nDDOUtility.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector3;
class cGeneralPoint;
class cGeneralPointPtr;

// Declarations
class cGeneralPointIterator;
class sGeneralPoint;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using cGpCategoryFlag = nDDOUtility::cBitSet<32>;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cGeneralPointIterator
{
public:
    cGeneralPointIterator();
    cGpCategoryFlag& categoryFlag();
    void setOwner(const MtObject* pOwner);
    void setOwnerDTI(const MtDTI* pDti);
    void setObjectID(s32 id);
    void toBegin();
    void toNext();
    bool isEnd() const;
    cGeneralPoint* getGeneralPoint();
private:
    void findCurrent();
private:
    s32 mCurIdx;  // offset: 0x0
    cGpCategoryFlag mCategoryFlag;  // offset: 0x4
    const MtObject* mpOwner;  // offset: 0x8
    const MtDTI* mpOwnerDTI;  // offset: 0x10
    s32 mObjectID;  // offset: 0x18
};

class sGeneralPoint : public cSystem
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
    sGeneralPoint();
    virtual ~sGeneralPoint();
    virtual void move();  // vtable slot 7
    virtual void reset();  // vtable slot 6
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 9
private:
    void updateGeneralPointPtr();
    s32 findEnableGeneralPointPtr(s32 beginIdx, bool enable);
    void clearGeneralPointDelete();
    void updateGeneralPointDelete();
    void updateGeneralPointStack();
    void updateGeneralPointSort();
    s32 findEnableGeneralPoint(s32 beginIdx, bool enable);
    static int sortDataFunc(const void* a, const void* b);
public:
    cGeneralPoint* createPoint(const MtDTI& dti);
    void releasePoint(cGeneralPoint* pGeneral);
    cGeneralPoint* getGeneralPoint(s32 idx);
    s32 getGeneralPointNum() const;
    s32 getCategoryEndIdx(s32 category) const;
    void addPtr(cGeneralPointPtr* pPtr);
    void erasePtr(cGeneralPointPtr* pPtr);
    static sGeneralPoint* getInstance();
public:
    nDDOUtility::cArray<cGeneralPoint*, 2048> mPointRefArray;  // offset: 0x18
    s32 mPointRefNum;  // offset: 0x4018
    s32 mPointRefStackIdx;  // offset: 0x401c
    nDDOUtility::cArray<int, 32> mPointRefEnd;  // offset: 0x4020
    nDDOUtility::cArray<cGeneralPointPtr*, 6144> mPointPtrArray;  // offset: 0x40a0
    s32 mPointPtrNum;  // offset: 0x100a0
    s32 mPointPtrStackIdx;  // offset: 0x100a4
    bool mPointPtrEraseReq;  // offset: 0x100a8
    static MyDTI DTI;
private:
    static sGeneralPoint* mpInstance;
};

// Inline, no code of its own: checked where it is inlined.
inline sGeneralPoint* sGeneralPoint::getInstance() {
    return ::sGeneralPoint::mpInstance;
}
