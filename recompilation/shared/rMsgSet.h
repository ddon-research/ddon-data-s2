#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "cResource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtObject;
class MtPropertyList;
class MtStream;
class cTalkMsgData;

// Declarations
class rMsgSet;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class rMsgSet : public cResource
{
public:
    class MyDTI;
    class cMsgGroup;
    class cMsgData;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cMsgData : public MtObject
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
        cMsgData(u32 msgSerial, u32 msgType, u32 jumpGrpSerial, u32 dispType, u32 dispTime, u32 setMot, s32 voiceReqNo, u8 TalkFaceType);
        virtual ~cMsgData();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        bool load(MtDataReader& r);
        bool save(MtDataWriter& w);
        u32 getGmdIndex();
        u32 getMsgType();
        s32 getVoiceReqNo();
        u32 getSetMotionNo();
        u32 getDispTime() const;
    protected:
        u32 mMsgSerial;  // offset: 0x8
        u32 mGmdIndex;  // offset: 0xc
        u32 mMsgType;  // offset: 0x10
        u32 mJumpGroupSerial;  // offset: 0x14
        u32 mDispType;  // offset: 0x18
        u32 mDispTime;  // offset: 0x1c
        u32 mSetMotion;  // offset: 0x20
        s32 mVoiceReqNo;  // offset: 0x24
        u8 mTalkFaceType;  // offset: 0x28
    public:
        static MyDTI DTI;
    };
public:
    class cMsgGroup : public MtObject
    {
        // inferred: cTalkMsgData::isDispNpcName names rMsgSet::cMsgGroup::mNameDispOff
        friend class cTalkMsgData;
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
        cMsgGroup(u32 GroupSerial, u32 GroupType, u32 NpcId, u32 GrpNameSerial, bool NameDispOff);
        virtual ~cMsgGroup();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        bool load(MtDataReader& r, rMsgSet::cMsgData* PreAllocMsgDataArray, u32& PreAllocMsgDataUseCount, const u32 PreAllocMsgDataMaxCount);
        bool save(MtDataWriter& w);
        u32 getMsgDataNum();
        rMsgSet::cMsgData* getMsgData(u32 Idx);
        u32 getNpcId();
        u32 getGroupSerial();
        u32 getGroupType();
        bool isNameDispOff();
    protected:
        u32 mGroupSerial;  // offset: 0x8
        u32 mGroupType;  // offset: 0xc
        u32 mNpcId;  // offset: 0x10
        u32 mGroupNameSerial;  // offset: 0x14
        bool mNameDispOff;  // offset: 0x18
        MtTypedArray<rMsgSet::cMsgData> mMsgData;  // offset: 0x20
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
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    u32 getMagicHeader() const;
    u32 getDataVersion() const;
    u32 getMsgGroupNum();
    rMsgSet();
    virtual ~rMsgSet();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    cMsgGroup* getGroupData(u32 Idx);
private:
    void deleteAllocateMemory();
protected:
    MtTypedArray<cMsgGroup> mArray;  // offset: 0x70
    cMsgGroup* mpNativeMsgGroupArray;  // offset: 0x90
    u32 mNativeMsgGroupArrayNum;  // offset: 0x98
    cMsgData* mpNativeMsgDataArray;  // offset: 0xa0
    u32 mNativeMsgDataArrayNum;  // offset: 0xa8
public:
    static MyDTI DTI;
protected:
    static const u32 MAGIC = 1953720173;
    static const u16 DATA_VERSION = 3;
};

// Inline, no code of its own: checked where it is inlined.
inline u32 rMsgSet::cMsgGroup::getNpcId() {
    return this->mNpcId;
}

// Inline, no code of its own: checked where it is inlined.
inline u32 rMsgSet::cMsgGroup::getGroupType() {
    return this->mGroupType;
}

// Inline, no code of its own: checked where it is inlined.
inline u32 rMsgSet::cMsgData::getGmdIndex() {
    return this->mGmdIndex;
}

// Inline, no code of its own: checked where it is inlined.
inline u32 rMsgSet::cMsgData::getMsgType() {
    return this->mMsgType;
}

// Inline, no code of its own: checked where it is inlined.
inline s32 rMsgSet::cMsgData::getVoiceReqNo() {
    return this->mVoiceReqNo;
}

// Inline, no code of its own: checked where it is inlined.
inline u32 rMsgSet::cMsgData::getSetMotionNo() {
    return this->mSetMotion;
}
