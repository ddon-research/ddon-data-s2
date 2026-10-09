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
class rPartnerPawnTalk;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class rPartnerPawnTalk : public cResource
{
public:
    enum
    {
        TYPE_GREETING = 0,
        TYPE_TALK = 1,
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
        class TalkDataBinary;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class TalkDataBinary : public MtObject
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
            TalkDataBinary();
            void copy(rPartnerPawnTalk::InfoBinary::TalkDataBinary* src);
        public:
            u16 mTalk;  // offset: 0x8
            u16 mType;  // offset: 0xa
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
        u16 getMessage(u16 type);
        u16 getGreetingMessage();
        u16 getTalkMessage();
        virtual TalkDataBinary* getTalkList(u32 index);  // vtable slot 6
        virtual u32 getTalkListNum();  // vtable slot 7
    public:
        TalkDataBinary* mpTalkList;  // offset: 0x8
        u32 mTalkListNum;  // offset: 0x10
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
    rPartnerPawnTalk();
    virtual ~rPartnerPawnTalk();
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
    static const u8 DATA_VERSION = 1;
};

// Inline, no code of its own: checked where it is inlined.
inline rPartnerPawnTalk::InfoBinary::InfoBinary() {
    this->mpTalkList = static_cast<rPartnerPawnTalk::InfoBinary::TalkDataBinary*>(nullptr);
    this->mTalkListNum = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline rPartnerPawnTalk::InfoBinary::TalkDataBinary::TalkDataBinary() {
    this->mTalk = static_cast<u16>(0);
    this->mType = static_cast<u16>(1);
}
