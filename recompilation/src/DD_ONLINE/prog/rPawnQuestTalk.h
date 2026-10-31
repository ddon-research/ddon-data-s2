#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../XFramework/cResource.h"

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
class rPawnQuestTalk;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class rPawnQuestTalk : public cResource
{
public:
    enum MSGTYPE
    {
        MSGTYPE_BATTLE_ORDER_UI = 0,
        MSGTYPE_BATTLE_ORDER = 1,
        MSGTYPE_BATTLE_NO_ORDER = 2,
        MSGTYPE_BATTLE_TALK = 3,
        MSGTYPE_DELIVER_ORDER_UI = 4,
        MSGTYPE_DELIVER_ORDER = 5,
        MSGTYPE_DELIVER_NO_ORDER = 6,
        MSGTYPE_DELIVER_DELIVER = 7,
        MSGTYPE_DELIVER_NO_DELIVER = 8,
        MSGTYPE_PHOTO_ORDER_UI = 9,
        MSGTYPE_PHOTO_ORDER = 10,
        MSGTYPE_PHOTO_NO_ORDER = 11,
        MSGTYPE_PHOTO_TALK = 12,
        MSGTYPE_PHOTO_CLEAR = 13,
    };
    enum RESTYPE
    {
        RESTYPE_PAWN_STAGE = 0,
        RESTYPE_QUEST = 1,
    };
public:
    class MyDTI;
    class cTalkData;
public:
    using TalkDataArray = MtTypedArray<rPawnQuestTalk::cTalkData>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cTalkData : public MtObject
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
        u32 getGroupSerial() const;
        rPawnQuestTalk::MSGTYPE getMsgType() const;
        rPawnQuestTalk::RESTYPE getResType() const;
        u8 getPersonality() const;
    protected:
        void setMsgType(u8 msgType);
    public:
        void load(MtDataReader& r);
        void save(MtDataWriter& w);
        cTalkData();
        virtual ~cTalkData();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    protected:
        u32 mGroupSerial;  // offset: 0x8
        u8 mMsgType;  // offset: 0xc
        u8 mResType;  // offset: 0xd
        u8 mParsonality;  // offset: 0xe
    public:
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
    bool getTalkData(MSGTYPE msgType, u32 personality, u32& groupSerial, RESTYPE& resType) const;
    u32 getMagicHeader() const;
    u32 getDataVersion() const;
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    rPawnQuestTalk();
    virtual ~rPawnQuestTalk();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
protected:
    TalkDataArray mTalkDataList;  // offset: 0x70
public:
    static MyDTI DTI;
};

inline u32 rPawnQuestTalk::cTalkData::getGroupSerial() const {
    return this->mGroupSerial;
}

inline rPawnQuestTalk::cTalkData::cTalkData() {
    this->mGroupSerial = 0;
    this->mMsgType = 0;
    this->mResType = 1;
    this->mParsonality = 1;
}
