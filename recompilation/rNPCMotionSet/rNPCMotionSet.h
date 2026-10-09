#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/cResource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtStream;

// Declarations
class rNPCMotionSet;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s16 = short;
using s32 = int;
using s8 = signed char;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class rNPCMotionSet : public cResource
{
public:
    enum
    {
        BANK_OM = 0,
        BANK_EM_NPC = 5,
        BANK_NPC = 8,
        BANK_DEMO = 10,
        BANK_SS_NPC = 13,
        BANK_EMO = 6,
    };
public:
    class MyDTI;
    class InfoBinary;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class InfoBinary : public MtObject
    {
    public:
        class MyDTI;
        class MotDataBinary;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class MotDataBinary : public MtObject
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
            MotDataBinary();
            void copy(rNPCMotionSet::InfoBinary::MotDataBinary* src);
        public:
            s16 mMotionNo;  // offset: 0x8
            s16 mWait;  // offset: 0xa
            s16 mRandWait;  // offset: 0xc
            s16 mStartFrame;  // offset: 0xe
            u8 mBankNo;  // offset: 0x10
            u8 mProbability;  // offset: 0x11
            s8 mNext;  // offset: 0x12
            s8 mFrame;  // offset: 0x13
            bool mDispItem;  // offset: 0x14
            bool mPlayMusic;  // offset: 0x15
            bool mDisableCancel;  // offset: 0x16
            static MyDTI DTI;
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
        InfoBinary();
        virtual ~InfoBinary();
        u32 getMotionNo(u32 idx);
        u8 getProbability(u32 idx);
        s8 getNext(u32 idx);
        bool getDispItem(u32 idx);
        bool getPlayMusic(u32 idx);
        bool getDisableCancel(u32 idx);
        s16 getWait(u32 idx);
        s16 getStartFrame(u32 idx);
        s16 getRandomWait(u32 idx);
        s8 getFrame(u32 idx);
        virtual MotDataBinary* getMotList(u32 index);  // vtable slot 6
        virtual u32 getMotListNum();  // vtable slot 7
        bool isTransOff();
        bool isRandomOn();
        s16 getTalkMot();
        s16 getHeadCtrl();
        u8 getTurnType();
    public:
        MotDataBinary* mpMotList;  // offset: 0x8
        u32 mMotListNum;  // offset: 0x10
        bool mTransOff;  // offset: 0x14
        bool mRandomOn;  // offset: 0x15
        s16 mTalkMot;  // offset: 0x16
        s16 mHeadCtrl;  // offset: 0x18
        u8 mTurnType;  // offset: 0x1a
        static MyDTI DTI;
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
    rNPCMotionSet();
    virtual ~rNPCMotionSet();
    virtual void clear();  // vtable slot 15
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    u32 getMagicHeader() const;
    u32 getDataVersion() const;
    void destruct();
    virtual u32 getInfoNum(s32 type) const;  // vtable slot 16
    virtual InfoBinary* getInfo(s32 type, u32 index) const;  // vtable slot 17
public:
    InfoBinary* mpArray[8];  // offset: 0x70
    u32 mArrayNum[8];  // offset: 0xb0
    static MyDTI DTI;
    static const u8 DATA_VERSION = 14;
};

// Inline, no code of its own: checked where it is inlined.
inline rNPCMotionSet::InfoBinary::InfoBinary() {
    this->mTransOff = false;
    this->mRandomOn = false;
    this->mTalkMot = static_cast<s16>(-1);
    this->mHeadCtrl = static_cast<s16>(0);
    this->mTurnType = static_cast<u8>(0);
    this->mpMotList = static_cast<rNPCMotionSet::InfoBinary::MotDataBinary*>(nullptr);
    this->mMotListNum = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline rNPCMotionSet::InfoBinary::MotDataBinary::MotDataBinary() {
    this->mMotionNo = static_cast<s16>(-1);
    this->mWait = static_cast<s16>(-1);
    this->mRandWait = static_cast<s16>(0);
    this->mStartFrame = static_cast<s16>(0);
    this->mBankNo = static_cast<u8>(8);
    this->mProbability = static_cast<u8>(100);
    this->mNext = static_cast<s8>(1);
    this->mFrame = static_cast<s8>(-1);
    this->mDispItem = false;
    this->mPlayMusic = false;
    this->mDisableCancel = false;
}
