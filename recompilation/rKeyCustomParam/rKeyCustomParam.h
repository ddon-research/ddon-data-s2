#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/nKeyCustom.h"
#include "../shared/rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtObject;

// Declarations
class cKeyCustomParam;
class rKeyCustomParam;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class cKeyCustomParam : public MtObject
{
public:
    enum KBM_FLAG_BIT
    {
        KBM_FLAG_BIT_VALID_KEY = 1,
        KBM_FLAG_BIT_VALID_BTN = 2,
        KBM_FLAG_BIT_DISABLE_CHANGE = 4,
        KBM_FLAG_BIT_DISABLE_BLANK = 8,
        KBM_FLAG_BIT_CTRL = 16,
        KBM_FLAG_BIT_SHIFT = 32,
        KBM_FLAG_BIT_ALT = 64,
        KBM_FLAG_BIT_TOGGLE = 128,
        KBM_FLAG_BIT_TAB = 256,
        KBM_FLAG_BIT_DISABLE_2STROKE = 512,
        KBM_FLAG_BIT_LONG_PRESS = 16384,
        KBM_FLAG_BIT_BOTH_INPUT_MODE = 32768,
    };
    enum PAD_FLAG_BIT
    {
        PAD_FLAG_BIT_VALID_PAD = 1,
        PAD_FLAG_BIT_DISABLE_CHANGE = 2,
        PAD_FLAG_BIT_DISABLE_BLANK = 4,
        PAD_FLAG_BIT_LB = 8,
        PAD_FLAG_BIT_LT = 16,
        PAD_FLAG_BIT_LS = 32,
        PAD_FLAG_BIT_RB = 64,
        PAD_FLAG_BIT_RT = 128,
        PAD_FLAG_BIT_RS = 256,
        PAD_FLAG_BIT_LONG_PRESS = 16384,
        PAD_FLAG_BIT_BOTH_INPUT_MODE = 32768,
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
    cKeyCustomParam();
    cKeyCustomParam(const cKeyCustomParam&);
    // Address: 0x01a988e0 - 0x01a988e1 (1 bytes)
    virtual ~cKeyCustomParam() {}
    bool getValidKey();
    void setValidKey(bool);
    bool getValidBtn();
    void setValidBtn(bool);
    bool isCtrl();
    bool isShift();
    bool isAlt();
    bool isTab();
    bool isToggle();
    bool isKbmLongPress();
    bool isKbmChange();
    bool isKbmBlank();
    bool isKbm2Stroke();
    bool getValidPad();
    bool getValidPad2();
    void setValidPad(bool);
    void setValidPad2(bool);
    bool isLB();
    bool isLB2();
    bool isLT();
    bool isLT2();
    bool isLS();
    bool isLS2();
    bool isRB();
    bool isRB2();
    bool isRT();
    bool isRT2();
    bool isRS();
    bool isRS2();
    bool isL1();
    bool isL1_2();
    bool isL2();
    bool isL2_2();
    bool isL3();
    bool isL3_2();
    bool isR1();
    bool isR1_2();
    bool isR2();
    bool isR2_2();
    bool isR3();
    bool isR3_2();
    bool isPadChange();
    bool isPad2Change();
    bool isPadBlank();
    bool isPad2Blank();
    bool isPadLongPress();
    nKeyCustom::OVERLAP_GROUP getOverlapGroup() const;
public:
    u16 mKbc;  // offset: 0x8
    u16 mOverlapGroup;  // offset: 0xa
    u32 mGmdId;  // offset: 0xc
    u16 mKbmFlags;  // offset: 0x10
    u16 mKey;  // offset: 0x12
    u16 mBtn;  // offset: 0x14
    u16 mPadFlags;  // offset: 0x16
    u16 mPadFlags2;  // offset: 0x18
    u32 mPad;  // offset: 0x1c
    u32 mPad2;  // offset: 0x20
    static MyDTI DTI;
    static const u16 DATA_VERSION = 21;
};

class rKeyCustomParam : public rTbl2<cKeyCustomParam>
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
    virtual bool loadData(MtDataReader& in, cKeyCustomParam* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cKeyCustomParam::cKeyCustomParam() {
    this->mPad = static_cast<u32>(0);
    this->mPad2 = static_cast<u32>(0);
    this->mPadFlags2 = static_cast<u16>(0);
    this->mKbmFlags = static_cast<u16>(0);
    this->mKey = static_cast<u16>(0);
    this->mBtn = static_cast<u16>(0);
    this->mPadFlags = static_cast<u16>(0);
    this->mKbc = static_cast<u16>(0);
    this->mOverlapGroup = static_cast<u16>(0);
    this->mGmdId = static_cast<u32>(0);
}
