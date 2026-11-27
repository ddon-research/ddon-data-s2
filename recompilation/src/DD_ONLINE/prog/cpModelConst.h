#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "cConstModelParam.h"
#include "cpComponent.h"
#include "nDDOUtility.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cConstModelParam;
class rConstModelParam;
class uDDOModel;

namespace nModelConst {
    enum VISIBLE_SEQ_NO
    {
        VISIBLE_SEQ_0 = 0,
        VISIBLE_SEQ_1 = 1,
        VISIBLE_SEQ_NO_MAX = 2,
        VISIBLE_SEQ_0_DEF = 17,
        VISIBLE_SEQ_1_DEF = 18,
        VISIBLE_PAGE_NO_DEF = 1,
    };
}  // namespace nModelConst

// Declarations
class cModelConstInfo;
class cpModelConst;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cModelConstInfo : public MtObject
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
    uDDOModel* getConstModel() const;
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
    cModelConstInfo();
    void kill();
    void setOwner(uDDOModel* pModel, cpModelConst* pConstModel);
    void setConstModel(uDDOModel* pConstModel, const cConstModelParam& param);
    bool isConstModel() const;
    void removeConstModel();
public:
    cConstModelParam mConstParam;  // offset: 0x10
    cpModelConst* mpCpModelConst;  // offset: 0x30
    uDDOModel* mpModel;  // offset: 0x38
    uDDOModel* mpConstModel;  // offset: 0x40
    bool mIsAutoKill;  // offset: 0x48
    static MyDTI DTI;
};

class cpModelConst : public cpComponent
{
public:
    class MyDTI;
public:
    using cConstInfoList = nDDOUtility::cArray<cModelConstInfo, 2>;
    using cVisibleSeqList = nDDOUtility::cArray<int, 2>;
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
    cpModelConst();
    virtual ~cpModelConst();
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 8
    virtual void update();  // vtable slot 15
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    virtual void updatePtr();  // vtable slot 9
    virtual void updateEfcHandle();  // vtable slot 10
    void setConstModel(uDDOModel* pConstModel, u32 index, const cConstModelParam& param, bool isAutoKill);
    void setConstModelFromRes(uDDOModel* pConstModel, u32 index, u32 resIndex, bool isAutoKill);
    bool isConstModel(u32 index) const;
    void removeConstModel(u32 index);
    cModelConstInfo& getModelConstInfo(u32);
    void setConstModelVisble(bool visible, u32 index);
    void setConstModelVisbleAll(bool visible);
    void setVisibleSeqNo(nModelConst::VISIBLE_SEQ_NO index, u32 seqNo);
    void setVisiblePageNo(u32 pageNo);
    void setVisibleSeqActive(bool);
    void setConstModelRes(rConstModelParam* pRes);
    rConstModelParam* getConstModelRes() const;
private:
    void removeConstMdoelAll();
    void updateVisibleSeqence();
private:
    uDDOModel* mpModel;  // offset: 0x50
    cConstInfoList mConstInfoList;  // offset: 0x60
    cVisibleSeqList mSeqNoList;  // offset: 0x100
    u32 mSeqPageNo;  // offset: 0x108
    bool mIsVisibleSeqActive;  // offset: 0x10c
    rConstModelParam* mpConstModelRes;  // offset: 0x110
public:
    static MyDTI DTI;
};

inline void* cModelConstInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cpModelConst::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void cModelConstInfo::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cModelConstInfo::DTI)->memFree(p_addr);
}

inline MtAllocator* cpModelConst::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::cpModelConst::DTI);
}

inline void cpModelConst::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cpModelConst::DTI)->memFree(p_addr);
}
