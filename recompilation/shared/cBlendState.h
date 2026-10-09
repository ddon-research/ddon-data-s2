#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;

// Declarations
class cBlendState;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using u32 = unsigned int;
using SO_HANDLE = u32;
using _Sizet = long unsigned int;
using size_t = _Sizet;

class cBlendState : public MtObject
{
public:
    enum eDefaultBState
    {
        BLEND_RGBA = 0,
        BLEND_ADD_SA_ONE = 0,
        BLEND_ADD_SA_ISA = 1,
        BLEND_ADD_SC_ONE = 2,
        BLEND_ADD_SC_ISA = 3,
        BLEND_ADD_ONE_ONE = 4,
        BLEND_RS_SA_ONE = 5,
        BLEND_RS_SA_ISA = 6,
        BLEND_RS_SC_ONE = 7,
        BLEND_RS_SC_ISA = 8,
        BLEND_RS_ONE_ONE = 9,
        BLEND_MIN_SA_ONE = 10,
        BLEND_MAX_SA_ONE = 11,
        BLEND_ADD_DC_ONE = 12,
        BLEND_ADD_DC_ISA = 13,
        BLEND_ADD_DCA_ONE = 14,
        BLEND_ADD_DCA_ISA = 15,
        BLEND_NONE = 16,
        BLEND_RGB = 17,
        BLEND_ADD_SA_ONE_RGB = 17,
        BLEND_ADD_SA_ISA_RGB = 18,
        BLEND_ADD_SC_ONE_RGB = 19,
        BLEND_ADD_SC_ISA_RGB = 20,
        BLEND_ADD_ONE_ONE_RGB = 21,
        BLEND_RS_SA_ONE_RGB = 22,
        BLEND_RS_SA_ISA_RGB = 23,
        BLEND_RS_SC_ONE_RGB = 24,
        BLEND_RS_SC_ISA_RGB = 25,
        BLEND_RS_ONE_ONE_RGB = 26,
        BLEND_MIN_SA_ONE_RGB = 27,
        BLEND_MAX_SA_ONE_RGB = 28,
        BLEND_ADD_DC_ONE_RGB = 29,
        BLEND_ADD_DC_ISA_RGB = 30,
        BLEND_ADD_DCA_ONE_RGB = 31,
        BLEND_ADD_DCA_ISA_RGB = 32,
        BLEND_NONE_RGB = 33,
        BLEND_MAX = 34,
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
    cBlendState();
    virtual ~cBlendState();
    SO_HANDLE getBlendStateHandle(eDefaultBState abst);
protected:
    SO_HANDLE mBSHandle[34];  // offset: 0x8
public:
    static MyDTI DTI;
};
