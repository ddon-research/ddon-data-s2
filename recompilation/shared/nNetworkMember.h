#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtNetDevice.h"
#include "MtNetSession.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtProperty;
class MtPropertyList;
class MtUI;
namespace nNetwork { class SessionDatabase; }

// Declarations
namespace nNetwork { class Member; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

namespace nNetwork {
    class Member : public ::MtObject
    {
        // inferred: nNetwork::SessionDatabase::isValid names nNetwork::Member::mInfo.mIsValid
        friend class nNetwork::SessionDatabase;
    public:
        enum
        {
            ATTR_NONE = 0,
            ATTR_SELF = 1,
            ATTR_ENTRY = 2,
            ATTR_MATCH = 4,
            ATTR_TERMINATE = 8,
            ATTR_MUTE = 16,
            ATTR_TALKING = 32,
            ATTR_RESTRICT = 64,
        };
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        Member();
        virtual ~Member();
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
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        void clear();
        const MtNetSession::Member& getInfo() const;
        MtNetSession::Member& getInfo();
        bool isValid() const;
        bool isHost() const;
        bool isPrivate() const;
        MT_CTSTR getName() const;
        bool isSelf() const;
        void setSelf(bool f);
        bool isEntry() const;
        void setEntry(bool f);
        bool isMatch() const;
        void setMatch(bool f);
        bool isTerminate() const;
        void setTerminate(bool f);
        bool isMute() const;
        void setMute(bool f);
        bool isTalking() const;
        void setTalking(bool f);
        bool isRestrict() const;
        void setRestrict(bool f);
        bool isNewbie() const;
        void setNewbie(bool f);
        u32 getGroup() const;
        void setGroup(u32 group_attr);
        bool isGroup(u32 group_index) const;
        void setGroup(u32 group_index, bool f);
        s32 getRouteIndex() const;
        void setRouteIndex(s32 index);
        u32 getId() const;
        void setId(u32 id);
        u32 getTag() const;
        void setTag(u32 tag);
        u32 incTag();
        const u8* getConfig() const;
        void setConfig(const void* bin);
    private:
        void dbgDrop();
        void dbgMute();
        void dbgRestrict();
        void setName(MT_CTSTR name);
    private:
        u32 mId;  // offset: 0x8
        u32 mTag;  // offset: 0xc
        s32 mRouteIndex;  // offset: 0x10
        union
        {
        public:
            u32 mConfiguration;  // offset: 0x0
            struct
            {
            public:
                u32 mAttribute : 16;  // offset: 0x0
                u32 mGroup : 16;  // offset: 0x0
            };  // offset: 0x0
        };  // offset: 0x14
        MtNetTime::Total mTalkTime;  // offset: 0x18
        MtNetTime::Total mJoinTime;  // offset: 0x20
        u8 mConfig[64];  // offset: 0x28
        MtNetSession::Member mInfo;  // offset: 0x68
    public:
        static const u32 TALKING_TIMEOUT = 250;
        static MyDTI DTI;
    };
}  // namespace nNetwork
