#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/MtString.h"
#include "../shared/nHuman.h"
#include "../shared/nKeyCustom.h"
#include "sKeyboard.h"
#include "sKeyboardExt.h"
#include "sMouse.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtPropertyList;
class MtString;
class cKeyCustomParam;
class rKeyCustomParam;

// Declarations
class cKeyCustom;
class cKeyCustomManager;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class cKeyCustom : public MtObject
{
public:
    class MyDTI;
    struct stKeyCustom;
    struct stKeyResource;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stKeyCustom
    {
    public:
        u8 mJobId;  // offset: 0x0
        u8 mKbcIndex;  // offset: 0x1
        union
        {
        public:
            struct
            {
            public:
                u16 mValidKey : 1;  // offset: 0x0
                u16 mValidBtn : 1;  // offset: 0x0
                u16 mCtrl : 1;  // offset: 0x0
                u16 mShift : 1;  // offset: 0x0
                u16 mAlt : 1;  // offset: 0x0
                u16 mTab : 1;  // offset: 0x0
                u16 mToggle : 1;  // offset: 0x0
                u16 mPadding00 : 9;  // offset: 0x0
            };  // offset: 0x0
            u16 mKbmFlag;  // offset: 0x0
        };  // offset: 0x2
        u16 mKey;  // offset: 0x4
        u16 mBtn;  // offset: 0x6
        union
        {
        public:
            struct
            {
            public:
                u16 mValidPad : 1;  // offset: 0x0
                u16 mLB : 1;  // offset: 0x0
                u16 mRB : 1;  // offset: 0x0
                u16 mLT : 1;  // offset: 0x0
                u16 mRT : 1;  // offset: 0x0
                u16 mLS : 1;  // offset: 0x0
                u16 mRS : 1;  // offset: 0x0
                u16 mPadding01 : 1;  // offset: 0x0
                u16 mValidPad2 : 1;  // offset: 0x0
                u16 mLB2 : 1;  // offset: 0x0
                u16 mRB2 : 1;  // offset: 0x0
                u16 mLT2 : 1;  // offset: 0x0
                u16 mRT2 : 1;  // offset: 0x0
                u16 mLS2 : 1;  // offset: 0x0
                u16 mRS2 : 1;  // offset: 0x0
                u16 mPadding02 : 1;  // offset: 0x0
            };  // offset: 0x0
            u16 mPadFlag;  // offset: 0x0
        };  // offset: 0x8
        u32 mPad;  // offset: 0xc
        u32 mPad2;  // offset: 0x10
    };
public:
    struct stKeyResource
    {
    public:
        union
        {
        public:
            struct
            {
            public:
                u16 mKbmNo2Stroke : 1;  // offset: 0x0
                u16 mKbmLongPress : 1;  // offset: 0x0
                u16 mKbmNoChange : 1;  // offset: 0x0
                u16 mKbmNoBlank : 1;  // offset: 0x0
                u16 mKbmBothMode : 1;  // offset: 0x0
                u16 mPadding00 : 11;  // offset: 0x0
            };  // offset: 0x0
            u16 mKbmResFlag;  // offset: 0x0
        };  // offset: 0x0
        union
        {
        public:
            struct
            {
            public:
                u32 mPadLongPress : 1;  // offset: 0x0
                u32 mPadNoChange : 1;  // offset: 0x0
                u32 mPadNoBlank : 1;  // offset: 0x0
                u32 mPadBothMode : 1;  // offset: 0x0
                u32 mPadding03 : 12;  // offset: 0x0
            };  // offset: 0x0
            u16 mPadResFlag;  // offset: 0x0
        };  // offset: 0x4
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
    cKeyCustom();
    cKeyCustom(const cKeyCustom&);
    cKeyCustom(const cKeyCustomParam* pRes);
    void clearAll();
    virtual ~cKeyCustom();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    cKeyCustom& operator=(const cKeyCustom& custom);
    cKeyCustom& operator=(const stKeyCustom& st);
    stKeyCustom& getStruct();
    bool operator==(const cKeyCustom& custom) const;
    bool operator!=(const cKeyCustom& custom) const;
    cKeyCustom& operator=(const cKeyCustomParam* pRes);
    void onSoloExcludeModifierKey(nKeyCustom::EXCLUDE_MODIFIER_KEY bit);
    bool checkSoloExcludeModifierKey(nKeyCustom::EXCLUDE_MODIFIER_KEY bit);
    void clrSoloExcludeModifierKey();
    void dataWrite(MtDataWriter& dw);
    void dataRead(MtDataReader& rd);
    nKeyCustom::KB_CUSTOM getKbcIndex();
    void setKbcIndex(nKeyCustom::KB_CUSTOM);
    bool isCtrl();
    void setCtrl(bool flag);
    bool isShift();
    void setShift(bool flag);
    bool isAlt();
    void setAlt(bool flag);
    bool isToggleSetting();
    void setToggleSetting(bool flag);
    bool isLB();
    void setLB(bool flag);
    bool isRB();
    void setRB(bool flag);
    bool isLT();
    void setLT(bool flag);
    bool isRT();
    void setRT(bool flag);
    bool isLS();
    void setLS(bool flag);
    bool isRS();
    void setRS(bool flag);
    bool isLB2();
    void setLB2(bool flag);
    bool isRB2();
    void setRB2(bool flag);
    bool isLT2();
    void setLT2(bool flag);
    bool isRT2();
    void setRT2(bool flag);
    bool isLS2();
    void setLS2(bool flag);
    bool isRS2();
    void setRS2(bool flag);
    bool isTab();
    void setTab(bool flag);
    bool isKbmNo2Stroke();
    bool isKbmBothMode();
    bool isPadBothMode();
    bool isKbmNoChange();
    bool isPadNoChange();
    bool isKbmNoBlank();
    bool isPadNoBlank();
    bool isKbmLongPress();
    bool isPadLongPress();
    nKeyCustom::OVERLAP_GROUP getOverlapGroup();
    bool isOverlap() const;
    nKeyCustom::KB_CUSTOM getOverlapKeyCustom() const;
    void setOverlap(nKeyCustom::KB_CUSTOM keyCustom);
    void clearOverlap();
    void clearKey();
    void clearBtn();
    void clearPad();
    void setKbmBlank();
    void setKbmRestore(cKeyCustom* pKc);
    void setKbmDefault(cKeyCustom* pKc);
    void setPadBlank();
    void setPadRestore(cKeyCustom* pKc);
    void setPadDefault(cKeyCustom* pKc);
    bool isKbmOverlap(cKeyCustom* pKc);
    bool isPadOverlap(cKeyCustom* pKc);
    bool isValidPad();
    void setValidPad(bool flag);
    u32 getPad() const;
    void setPad(const u32 kb);
    bool isValidPad2();
    void setValidPad2(bool flag);
    u32 getPad2() const;
    void setPad2(const u32 kb);
    bool isValidKey();
    void setValidKey(bool flag);
    sKeyboard::KB_TYPE getKey() const;
    void setKey(const sKeyboardExt::KB_EX_TYPE kb);
    void changeKey(const sKeyboard::KB_TYPE kb);
    bool isValidBtn();
    void setValidBtn(bool flag);
    sMouse::BUTTON getBtn() const;
    void setBtn(const sMouse::BUTTON btn);
    void changeBtn(const sMouse::BUTTON btn);
private:
    stKeyCustom mSt;  // offset: 0x8
    stKeyResource mStR;  // offset: 0x1c
    nKeyCustom::OVERLAP_GROUP mOverlapGroup;  // offset: 0x24
    nKeyCustom::KB_CUSTOM mOverlapKeyCustom;  // offset: 0x28
    u8 mSoloExcludeModifierKey;  // offset: 0x2c
public:
    static MyDTI DTI;
};

class cKeyCustomManager : public MtObject
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
    cKeyCustomManager();
    cKeyCustomManager(rKeyCustomParam* pRes);
    cKeyCustomManager(nHuman::JOB_ENUM jobId, rKeyCustomParam* pRes);
    virtual ~cKeyCustomManager();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    cKeyCustomManager& operator=(const cKeyCustomManager& custom);
    bool isEqual(const cKeyCustomManager& custom, bool isCheckName) const;
    bool operator==(const cKeyCustomManager& custom) const;
    bool operator!=(const cKeyCustomManager&) const;
    void reset();
    void dataWrite(u8 jobId, MtDataWriter& dw);
    void dataRead(MtDataReader& rd, s32 subVersion);
    void setResourceKeyCustomParam(rKeyCustomParam* pRes, nHuman::JOB_ENUM jobId, nKeyCustom::KB_CUSTOM top, nKeyCustom::KB_CUSTOM end);
    cKeyCustom* getData(u32 kb);
    void checkOverlap();
    bool isExistOverlap();
private:
    bool checkOverlapGroup(nKeyCustom::OVERLAP_GROUP src, nKeyCustom::OVERLAP_GROUP dst);
    bool isSoloExcludeModifierKey(u32 kb, nKeyCustom::EXCLUDE_MODIFIER_KEY key);
    void setSoloExcludeModifierKey();
    bool isCtrl(u32 kb);
    bool isShift(u32 kb);
    bool isAlt(u32 kb);
    bool isToggleSetting(u32 kb);
    bool isLB(u32 kb);
    bool isRB(u32 kb);
    bool isLT(u32 kb);
    bool isRT(u32 kb);
    bool isLS(u32 kb);
    bool isRS(u32 kb);
    bool isLB2(u32 kb);
    bool isRB2(u32 kb);
    bool isLT2(u32 kb);
    bool isRT2(u32 kb);
    bool isLS2(u32 kb);
    bool isRS2(u32 kb);
    bool isTab(u32);
    bool isKbmNo2Stroke(u32);
    bool isKbmBothMode(u32 kb);
    bool isPadBothMode(u32 kb);
    bool isKbmNoChange(u32 kb);
    bool isPadNoChange(u32);
    bool isKbmNoBlank(u32);
    bool isPadNoBlank(u32);
    bool isValidPad(u32 kb);
    u32 getPad(u32 kb);
    bool isValidPad2(u32 kb);
    u32 getPad2(u32 kb);
    bool isValidKey(u32 kb);
    sKeyboard::KB_TYPE getKey(u32 kb);
    bool isValidBtn(u32 kb);
    sMouse::BUTTON getBtn(u32 kb);
    nKeyCustom::OVERLAP_GROUP getOverlapGroup(u32 kb);
    bool isOverlap(u32);
public:
    const MtString& getUserName() const;
    void setUserName(MT_CTSTR str);
private:
    MtString mUserName;  // offset: 0x8
    MtTypedArray<cKeyCustom> mCustomArray;  // offset: 0x10
public:
    static MyDTI DTI;
};
