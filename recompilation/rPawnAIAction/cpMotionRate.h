#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/cpComponent.h"
#include "../shared/uModel.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class uDDOModel;

// Declarations
class cpMotionRate;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cpMotionRate : public cpComponent
{
public:
    class MyDTI;
public:
    using SEQ_CHECK_CALLBACK = bool(MtObject::*)(uModel::Motion*);
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
    cpMotionRate();
    virtual ~cpMotionRate();
    void saveMotionSpeed(uDDOModel* pModel);
    void loadMotionSpeed(uDDOModel* pModel);
    void setMotionSpeed(uDDOModel* pModel);
    void setSeqCheckCallback(SEQ_CHECK_CALLBACK Func);
protected:
    f32 mSpeed[8];  // offset: 0x50
    u32 mSeqPage;  // offset: 0x70
    u32 mSeqNo;  // offset: 0x74
    u32 mMkfNo;  // offset: 0x78
    f32 mSaveMotSpeed[8];  // offset: 0x7c
    SEQ_CHECK_CALLBACK mSeqCheckCallback;  // offset: 0xa0
public:
    static MyDTI DTI;
    static const u32 DEFAULT_SEQ_PAGE = 1;
    static const u32 DEFAULT_SEQ_NO = 22;
    static const u32 DEFAULT_MKF_NO = 2;
};
