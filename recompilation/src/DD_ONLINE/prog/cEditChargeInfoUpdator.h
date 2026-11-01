#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;

// Declarations
class cEditChargeInfoUpdator;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cEditChargeInfoUpdator : public MtObject
{
public:
    enum ROUTINE_NO
    {
        ROUTINE_BUY_INIT = 0,
        ROUTINE_BUY_REQ = 1,
        ROUTINE_BUY_WAIT = 2,
        ROUTINE_BUY_ERROR = 3,
        ROUTINE_GET_GP_INIT = 4,
        ROUTINE_GET_GP_REQ = 5,
        ROUTINE_GET_GP_REQ_WAIT = 6,
        ROUTINE_GET_GP_ERROR = 7,
        ROUTINE_END = 8,
    };
    enum RESULT_TYPE
    {
        RESULT_NONE = 0,
        RESULT_OK = 1,
        RESULT_ERROR = 2,
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
    cEditChargeInfoUpdator();
    void init();
    void move();
    void final();
    RESULT_TYPE getResultType() const;
    bool isEnd() const;
private:
    void setResultType(RESULT_TYPE type);
private:
    ROUTINE_NO mRno;  // offset: 0x8
    RESULT_TYPE mResultType;  // offset: 0xc
public:
    static MyDTI DTI;
};
