#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/MtObject.h"
#include "../shared/cResource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtObject;
class MtPropertyList;
class MtStream;
class MtVector3;

// Declarations
class rStageAdjoinList;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class rStageAdjoinList : public cResource
{
public:
    class MyDTI;
    class cAdjoinInfo;
    class cJumpPosition;
public:
    using AdjoinInfoArray = MtTypedArray<rStageAdjoinList::cAdjoinInfo>;
    using JumpPositionArray = MtTypedArray<rStageAdjoinList::cJumpPosition>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cAdjoinInfo : public MtObject
    {
    public:
        class MyDTI;
        class cIndex;
    public:
        using IndexArray = MtTypedArray<rStageAdjoinList::cAdjoinInfo::cIndex>;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class cIndex : public MtObject
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
            virtual void createProperty(MtPropertyList& s);  // vtable slot 4
            void load(MtDataReader& r);
            void save(MtDataWriter& w);
        public:
            u16 mIndex;  // offset: 0x8
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
        void load(MtDataReader& r);
        void save(MtDataWriter& w);
        cAdjoinInfo();
        virtual ~cAdjoinInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    public:
        IndexArray mIndex;  // offset: 0x8
        u16 mDestinationStageNo;  // offset: 0x28
        u16 mNextStageNo;  // offset: 0x2a
        u8 mPriority;  // offset: 0x2c
        static MyDTI DTI;
    };
public:
    class cJumpPosition : public MtObject
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
        void load(MtDataReader& r);
        void save(MtDataWriter& w);
        cJumpPosition();
        virtual ~cJumpPosition();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    public:
        MtVector3 mPos;  // offset: 0x10
        u32 mQuestId;  // offset: 0x20
        u32 mFlagId;  // offset: 0x24
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
    u32 getStageNo() const;
    cAdjoinInfo* getNextStageAdjoinInfo(s32 destinationStageNo) const;
    cAdjoinInfo* getNextStageAdjoinInfo(s32 destinationStageNo, u8 priority) const;
    cJumpPosition* getJumpPosition(u32 index) const;
    u32 getMagicHeader() const;
    u32 getDataVersion() const;
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    rStageAdjoinList();
    virtual ~rStageAdjoinList();
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
protected:
    AdjoinInfoArray mAdjoinInfo;  // offset: 0x70
    JumpPositionArray mJumpPosition;  // offset: 0x90
    u16 mStageNo;  // offset: 0xb0
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline rStageAdjoinList::cAdjoinInfo::cAdjoinInfo() {
    this->mDestinationStageNo = static_cast<u16>(0);
    this->mNextStageNo = static_cast<u16>(0);
    this->mPriority = static_cast<u8>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline rStageAdjoinList::cJumpPosition::cJumpPosition() {
    this->mQuestId = static_cast<u32>(0);
    this->mFlagId = static_cast<u32>(0);
}
