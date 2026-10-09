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
class rNPCMotMyRoom;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s16 = short;
using s8 = signed char;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class rNPCMotMyRoom : public cResource
{
public:
    enum
    {
        BANK_CO = 0,
        BANK_NPC_SP = 5,
        BANK_NPC_CO = 8,
        BANK_AREA = 10,
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
            void copy(rNPCMotMyRoom::InfoBinary::MotDataBinary* src);
        public:
            s16 mMotNoM;  // offset: 0x8
            s16 mMotNoW;  // offset: 0xa
            s16 mWait;  // offset: 0xc
            s16 mRandWait;  // offset: 0xe
            u8 mBankNo;  // offset: 0x10
            u8 mProbability;  // offset: 0x11
            s8 mNext;  // offset: 0x12
            s8 mCancel;  // offset: 0x13
            s8 mFrame;  // offset: 0x14
            u16 mHaveItem;  // offset: 0x16
            s16 mItemMotNo;  // offset: 0x18
            s16 mMessage;  // offset: 0x1a
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
        u32 getMotionNo(u32 idx, u8 sex);
        u8 getProbability(u32 idx);
        s8 getNext(u32 idx);
        s8 getCancel(u32 idx);
        u16 getHaveItem(u32 idx);
        s16 getItemMotNo(u32 idx);
        s16 getWait(u32 idx);
        s16 getRandomWait(u32 idx);
        s8 getFrame(u32 idx);
        s16 getMessage(u32 idx);
        virtual MotDataBinary* getMotList(u32 index);  // vtable slot 6
        virtual u32 getMotListNum();  // vtable slot 7
        bool isTransOff();
    public:
        MotDataBinary* mpMotList;  // offset: 0x8
        u32 mMotListNum;  // offset: 0x10
        bool mTransOff;  // offset: 0x14
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
    rNPCMotMyRoom();
    virtual ~rNPCMotMyRoom();
    virtual void clear();  // vtable slot 15
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    u32 getMagicHeader() const;
    u32 getDataVersion() const;
    void destruct();
    virtual u32 getInfoNum() const;  // vtable slot 16
    virtual InfoBinary* getInfo(u32 index) const;  // vtable slot 17
public:
    InfoBinary* mpArray;  // offset: 0x70
    u32 mArrayNum;  // offset: 0x78
    static MyDTI DTI;
    static const u8 DATA_VERSION = 4;
};

// Inline, no code of its own: checked where it is inlined.
inline rNPCMotMyRoom::InfoBinary::InfoBinary() {
    this->mTransOff = false;
    this->mpMotList = static_cast<rNPCMotMyRoom::InfoBinary::MotDataBinary*>(nullptr);
    this->mMotListNum = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline bool rNPCMotMyRoom::InfoBinary::isTransOff() {
    return this->mTransOff;
}

// Inline, no code of its own: checked where it is inlined.
inline rNPCMotMyRoom::InfoBinary::MotDataBinary::MotDataBinary() {
    this->mMotNoM = static_cast<s16>(-1);
    this->mMotNoW = static_cast<s16>(-1);
    this->mWait = static_cast<s16>(-1);
    this->mRandWait = static_cast<s16>(0);
    this->mBankNo = static_cast<u8>(8);
    this->mProbability = static_cast<u8>(100);
    this->mNext = static_cast<s8>(1);
    this->mCancel = static_cast<s8>(0);
    this->mFrame = static_cast<s8>(-1);
    this->mHaveItem = static_cast<u16>(0);
    this->mItemMotNo = static_cast<s16>(-1);
    this->mMessage = static_cast<s16>(-1);
}
