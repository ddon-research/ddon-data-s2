#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cDelegate.h"
#include "cpComponent.h"
#include "nSequence.h"
#include "uModel.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class uDDOModel;

// Declarations
class cpSequenceCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cpSequenceCtrl : public cpComponent
{
public:
    enum CHECK_TYPE
    {
        CHECK_NONE = 0,
        CHECK_TRIGGER = 1,
        CHECK_RELEASE = 2,
    };
    enum
    {
        SEQ_STAT_INIT = 0,
        SEQ_STAT_LOOP = 1,
    };
public:
    class MyDTI;
    struct stRange;
    struct stSeqCnt;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stRange
    {
    public:
        cpSequenceCtrl::CHECK_TYPE mCheckType;  // offset: 0x0
        u32 mBlend;  // offset: 0x4
        u32 mPage;  // offset: 0x8
        u32 mTop;  // offset: 0xc
        u32 mBottom;  // offset: 0x10
    };
public:
    struct stSeqCnt
    {
    public:
        bool mActive;  // offset: 0x0
        u32 mBlend;  // offset: 0x4
        u32 mPage;  // offset: 0x8
        u32 mBit;  // offset: 0xc
        s32 mFrame;  // offset: 0x10
        s32 mCount;  // offset: 0x14
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
    cpSequenceCtrl();
    virtual ~cpSequenceCtrl();
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void updatePtr();  // vtable slot 9
    void callbackSetMotion(u32 blend, u32 mot_no, f32 hokan, f32 frame, f32 speed, u32 attr);
    void callbackAfterUpdateMotion();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    u32 getSequence(u32 page, MOT_TYPE s);
    u32 getSequenceOld(u32 page, MOT_TYPE s);
    u32 getSequenceTrg(u32 page, MOT_TYPE s);
    u32 getSequenceRel(u32 page, MOT_TYPE s);
    bool checkSequence(u32 bit, u32 page, MOT_TYPE s);
    void setupSequenceCallback(nSequence::SEQ_CALLBACK_NO no, CHECK_TYPE check_type, MOT_TYPE blend, u32 page, u32 top, u32 bottom);
    void setupSequenceCount(s32 no, bool active, MOT_TYPE blend, u32 page, u32 bit);
    s32 getSequenceCount(s32 no);
protected:
    void updateSequence();
    void updateSequence(s32 page, s32 blend);
    void updateSequenceCount();
    void updateMotion();
public:
    cDelegate_4<void, cpSequenceCtrl*, unsigned int, unsigned int, unsigned short> callbackSequenceTrigger;  // offset: 0x50
    cDelegate_4<void, cpSequenceCtrl*, unsigned int, unsigned int, unsigned short> callbackSequenceRelease;  // offset: 0x68
private:
    uDDOModel* mpModel;  // offset: 0x80
    u8 mMotSeqStatus[8][4];  // offset: 0x88
    u32 mMotSeqOld[8][4];  // offset: 0xa8
    u32 mMotSeqNew[8][4];  // offset: 0x128
    u32 mMotSeqTrg[8][4];  // offset: 0x1a8
    u32 mMotSeqRel[8][4];  // offset: 0x228
    stRange mTrgRange[10];  // offset: 0x2a8
    stSeqCnt mSeqCnt[10];  // offset: 0x370
public:
    static MyDTI DTI;
private:
    static const s32 RangeMax = 10;
    static const s32 SeqCntMax = 10;
};
