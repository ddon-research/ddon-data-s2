#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtPropertyList;
class cpInput;
class uDDOModel;

// Declarations
class cLeverGacha;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cLeverGacha : public MtObject
{
    // inferred: cpInput::isLeverGachaSuccess names cpInput::mLeverGacha.mResult
    friend class cpInput;
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
    cLeverGacha();
    // Address: 0x019af090 - 0x019af091 (1 bytes)
    virtual ~cLeverGacha() {}
    virtual void createProperty(MtPropertyList& proplist);  // vtable slot 4
    void commandReset(s32 param);
    void initLeverGacha(s32 count);
    bool isLeverGachaSuccess();
    bool checkLeverGacha(const cpInput& Input, const uDDOModel* pModel);
private:
    s32 mCntMax;  // offset: 0x8
    bool mResult;  // offset: 0xc
    f32 mCnt;  // offset: 0x10
    s32 mOldAngleType;  // offset: 0x14
    f32 mOldLvLx;  // offset: 0x18
    f32 mOldLvLy;  // offset: 0x1c
    s32 mOldMouseX;  // offset: 0x20
    s32 mOldMouseY;  // offset: 0x24
    s32 mOldMouseZ;  // offset: 0x28
public:
    static MyDTI DTI;
};
