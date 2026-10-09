#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "cRemoteCall.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtMemoryStream;
class MtObject;
class MtStream;
namespace nNetBase { class cNetBase; }
namespace nNetMsgData { namespace Base { struct stMsgBaseData; } }
namespace nNetMsgData { namespace Head { struct stMsgHead; } }
namespace nNetwork { class Coder; }
namespace nNetwork { class Decoder; }
class uControl;

// Declarations
namespace nNetMsg { class cCoder; }
namespace nNetMsg { class cDecoder; }
namespace nNetMsg { class cNetMsgBase; }

namespace nNetMsg {
    enum MSG_ADR
    {
        MSG_ADR_LOCAL = 0,
        MSG_ADR_ALL = 1,
        MSG_ADR_OTHER = 2,
        MSG_ADR_PEER = 3,
        MSG_ADR_SERVER = 4,
        MSG_ADR_MAX = 5,
        MSG_ADR_DEFAULT = -1,
    };
}  // namespace nNetMsg

namespace nNetMsg {
    enum MSG_PRIO
    {
        MSG_PRIO_MAX = 16,
        MSG_PRIO_HIGH = 15,
        MSG_PRIO_NORMAL = 4,
        MSG_PRIO_LOW = 0,
        MSG_PRIO_H_H = 15,
        MSG_PRIO_H_N = 14,
        MSG_PRIO_H_L = 13,
        MSG_PRIO_N_H = 6,
        MSG_PRIO_N_N = 5,
        MSG_PRIO_N_L = 4,
        MSG_PRIO_L_H = 2,
        MSG_PRIO_L_N = 1,
        MSG_PRIO_L_L = 0,
        MSG_PRIO_DEFAULT = -1,
    };
}  // namespace nNetMsg

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __int64_t = long int;
using __uint64_t = long unsigned int;
using f32 = float;
using f64 = double;
using s16 = short;
using s32 = int;
using s64 = __int64_t;
using s8 = signed char;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

namespace nNetMsg {
    class cCoder : public ::MtObject
    {
        // inferred: nNetMsg::cNetMsgBase::pushUniqueId names nNetMsg::cNetMsgBase::mCod.mpCod
        friend class nNetMsg::cNetMsgBase;
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
        cCoder();
        cCoder(MtStream&);
        virtual ~cCoder();
        bool isOverFlow();
        void operator<<(const bool val);
        void operator<<(const s8);
        void operator<<(const s16);
        void operator<<(const s32 val);
        void operator<<(const s64);
        void operator<<(const u8 val);
        void operator<<(const u16 val);
        void operator<<(const u32 val);
        void operator<<(const u64 val);
        void operator<<(const f32 val);
        void operator<<(const f64 val);
        void write(const void*, u32);
        nNetwork::Coder* setCoder(MtStream& stream);
    private:
        nNetwork::Coder* mpCod;  // offset: 0x8
    public:
        static MyDTI DTI;
    };
}  // namespace nNetMsg

namespace nNetMsg {
    class cDecoder : public ::MtObject
    {
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
        cDecoder();
        cDecoder(MtStream& stream);
        virtual ~cDecoder();
        bool isDrain();
        void operator>>(bool& val);
        void operator>>(s8&);
        void operator>>(s16&);
        void operator>>(s32& val);
        void operator>>(s64&);
        void operator>>(u8& val);
        void operator>>(u16& val);
        void operator>>(u32& val);
        void operator>>(u64& val);
        void operator>>(f32& val);
        void operator>>(f64& val);
        u32 read(void* buff, u32 size);
        nNetwork::Decoder* setDecoder(MtStream& stream);
    private:
        nNetwork::Decoder* mpDec;  // offset: 0x8
    public:
        static MyDTI DTI;
    };
}  // namespace nNetMsg

namespace nNetMsg {
    class cNetMsgBase : public ::RpcTypeSet
    {
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
        cNetMsgBase();
        virtual ~cNetMsgBase();
        static nNetMsg::cNetMsgBase* createNetMsg(u32 msgId, nNetBase::cNetBase* pNetMsg);
        s32 getCallbackIndex();
        MtMemoryStream* getStream();
        void setStream(MtMemoryStream& stream);
        bool sendMessageCore();
        bool receiveMessageCore();
        u32 getSessionInstanceIndex();
        void setSessionInstanceIndex(u32 index);
        u8 getMsgGroup();
        u8 getMsgId();
        bool setCharacterId(u32 characterId);
    protected:
        // Address: 0x01a41090 - 0x01a41091 (1 bytes)
        virtual void setupIncludePacket(uControl& ctrl) {}  // vtable slot 8
        void setIncludePacket(u32 bit);
        bool isIncludePacket(u32 bit);
        u32 getIncludePacket();
        nNetMsg::cCoder& getCoder();
        nNetMsg::cDecoder& getDecoder();
        u32 getCharacterId();
        void push(const void*, u32);
        void pop(void*, u32);
        void sendLogStart(u32, u32);
        void receiveLogStart(u32, u32);
    public:
        void sendLogEnd();
        void receiveLogEnd();
        void setSendForceLogOn();
        void setSendForceLogOff();
        void setRecvForceLogOn();
        void setRecvForceLogOff();
        void setIsLogPush();
        void setIsLogPop();
        void setAdr(nNetMsg::MSG_ADR adr);
        void setMsgHead(nNetMsgData::Head::stMsgHead* pHead);
        nNetMsgData::Head::stMsgHead* getMsgHead();
    protected:
        nNetMsg::MSG_ADR getAdr();
        nNetBase::cNetBase* getNetBase();
        void pushUniqueId(u32 uniqueId);
    public:
        static u32 popUniqueId(u32 uniqueId);
    private:
        void setMsgGroup(u8 group);
        void setMsgId(u8 id);
    protected:
        MtMemoryStream* mpStream;  // offset: 0x10
        nNetMsg::cCoder mCod;  // offset: 0x18
        nNetMsg::cDecoder mDec;  // offset: 0x28
        nNetBase::cNetBase* mpNetBase;  // offset: 0x38
        nNetMsgData::Head::stMsgHead* mpMsgHead;  // offset: 0x40
    private:
        u32 mCharacterId;  // offset: 0x48
        u32 mIncludePacket;  // offset: 0x4c
        u32 mSessionInstanceIndex;  // offset: 0x50
        u8 mMsgGroup;  // offset: 0x54
        u8 mMsgId;  // offset: 0x55
        nNetMsg::MSG_ADR mAdr;  // offset: 0x58
        nNetMsgData::Base::stMsgBaseData* mpMsgBaseData;  // offset: 0x60
    public:
        static MyDTI DTI;
    };
}  // namespace nNetMsg

// Inline, no code of its own: checked where it is inlined.
inline nNetMsg::cCoder::cCoder() {
    this->mpCod = static_cast<nNetwork::Coder*>(nullptr);
}

// Inline, no code of its own: checked where it is inlined.
inline nNetMsg::cDecoder::cDecoder() {
    this->mpDec = static_cast<nNetwork::Decoder*>(nullptr);
}
