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
class rDungeonMarker;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s16 = short;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class rDungeonMarker : public cResource
{
public:
    class MyDTI;
    class cWarpInfo;
    class cPosition;
public:
    using WarpInfoArray = MtTypedArray<rDungeonMarker::cWarpInfo>;
    using PositionArray = MtTypedArray<rDungeonMarker::cPosition>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cWarpInfo : public MtObject
    {
    public:
        class MyDTI;
        class cIndex;
    public:
        using IndexArray = MtTypedArray<rDungeonMarker::cWarpInfo::cIndex>;
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
            void load(MtDataReader& r);
            void save(MtDataWriter& w);
            virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        public:
            u8 mIndex;  // offset: 0x8
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
        cWarpInfo();
        virtual ~cWarpInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    public:
        IndexArray mPosIndex;  // offset: 0x8
        s16 mGroupNo;  // offset: 0x28
        u16 mTargetStageNo;  // offset: 0x2a
        s16 mTargetGroupNo;  // offset: 0x2c
        static MyDTI DTI;
    };
public:
    class cPosition : public MtObject
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
        cPosition();
        virtual ~cPosition();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    public:
        MtVector3 mPos;  // offset: 0x10
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
    u32 getWarpStageNo() const;
    u32 getWarpPosNum(s32 groupNo, u32 targetStageNo, s32 targetGroupNo) const;
    const MtVector3& getWarpPos(s32 groupNo, u32 targetStageNo, s32 targetGroupNo, u32 index) const;
    u32 getMagicHeader() const;
    u32 getVersion() const;
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    rDungeonMarker();
    virtual ~rDungeonMarker();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
protected:
    WarpInfoArray mWarpInfoList;  // offset: 0x70
    PositionArray mPositionList;  // offset: 0x90
    u16 mWarpStageNo;  // offset: 0xb0
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline rDungeonMarker::cWarpInfo::cWarpInfo() {
    this->mGroupNo = static_cast<s16>(-1);
    this->mTargetStageNo = static_cast<u16>(0);
    this->mTargetGroupNo = static_cast<s16>(-1);
}
