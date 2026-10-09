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
class MtDataReader;
class MtDataWriter;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtUI;

// Declarations
class rStageList;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class rStageList : public cResource
{
public:
    class MyDTI;
    class Info;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class Info : public MtObject
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
        Info();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        void copy(rStageList::Info* src);
        bool load(MtDataReader& r);
        bool save(MtDataWriter& w);
    public:
        u32 mStageNo;  // offset: 0x8
        u32 mType;  // offset: 0xc
        u8 mRecommendLevel;  // offset: 0x10
        u32 mMessageId;  // offset: 0x14
        u32 mVersion;  // offset: 0x18
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
    rStageList();
    virtual ~rStageList();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    u32 getMagicHeader() const;
    u32 getDataVersion() const;
    void destruct();
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual Info* getInfo(u32 index) const;  // vtable slot 16
    virtual u32 getNum() const;  // vtable slot 17
    u32 getStageNo(u32 idx) const;
    u32 getStageType(s32 stgNo) const;
    u32 getStageMsgId(s32 stgNo) const;
    u32 getVersion(s32 stgNo) const;
    u32 getVersionForAlt(s32 stgNo) const;
    bool isLobby(s32 stgNo) const;
    bool isField(s32 stgNo) const;
    Info* searchInfo(s32 stgNo) const;
public:
    Info* mpArrayInfo;  // offset: 0x70
    u32 mArrayInfoNum;  // offset: 0x78
    static const u8 DATA_VERSION = 34;
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline rStageList::Info::Info() {
    this->mStageNo = static_cast<u32>(0);
    this->mType = static_cast<u32>(0);
    this->mRecommendLevel = static_cast<u8>(0);
    this->mMessageId = static_cast<u32>(0);
    this->mVersion = static_cast<u32>(39321);
}
