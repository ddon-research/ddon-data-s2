#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "cpComponent.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cStatusCheck;
class rStatusCheck;

// Declarations
class cpStatusCheck;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cpStatusCheck : public cpComponent
{
public:
    class MyDTI;
    class cResult_info;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cResult_info
    {
    public:
        cResult_info();
    public:
        bool mOver;  // offset: 0x0
        bool mAdd;  // offset: 0x1
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
    cpStatusCheck();
    virtual ~cpStatusCheck();
    virtual void setup();  // vtable slot 6
    virtual void updatePtr();  // vtable slot 9
    void setResource(rStatusCheck* pRes);
    u32 checkSelectGroupType(s32 groupNo);
    u32 getResultCount();
    s32 getResult(u32 resultIdx);
private:
    bool checkType(cStatusCheck* pResData);
    void result_init();
public:
    rStatusCheck* mpStatusCheckRes;  // offset: 0x50
private:
    s32 mResult[8];  // offset: 0x58
    u32 mResultCount;  // offset: 0x78
public:
    static MyDTI DTI;
    static const u32 RESULT_NUM = 8;
};

inline void* cpStatusCheck::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cpStatusCheck::cResult_info::cResult_info() {
}
