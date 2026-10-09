#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cNetMsgBase.h"
#include "cRemoteProcedure.h"
#include "nNetMsgData.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtString;
class MtUI;
class cRemoteCall;
namespace nNetMsg { class cNetMsgBase; }
class uControl;

// Declarations
namespace nNetBase { class cNetBase; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using u32 = unsigned int;
using RPC_ID = u32;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u8 = unsigned char;

namespace nNetBase {
    class cNetBase : public ::cRemoteProcedure
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
        cNetBase();
        virtual ~cNetBase();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    protected:
        void castMsgAddress(nNetMsg::cNetMsgBase* pMsg);
    private:
        bool sendLocal(RPC_ID receiver_id, nNetMsg::cNetMsgBase& call);
        void sendOthers(RPC_ID receiver_id, nNetMsg::cNetMsgBase& call, s32 protocol);
        void sendAll(RPC_ID receiver_id, nNetMsg::cNetMsgBase& call, s32 protocol);
        void sendPeer(RPC_ID receiver_id, nNetMsg::cNetMsgBase& call, s32 protocol, u32 characterId);
        void sendServer(RPC_ID receiver_id, nNetMsg::cNetMsgBase& call);
        void sendCategory(MT_CTSTR class_name, const MtString& category, nNetMsg::cNetMsgBase& call, s32 member_id);
    public:
        static nNetBase::cNetBase* createNetRpc(u32 rpcType);
        void setup(RPC_ID id);
        RPC_ID getRpcId();
        virtual uControl* getOwner() const;  // vtable slot 11
        // Address: 0x019af470 - 0x019af471 (1 bytes)
        virtual void setOwner(uControl* pOwner) {}  // vtable slot 12
        u32 getGITK();
        void setGITK(u32 gitk);
        void setGITKGroup(u8 g);
        void setGITKId(u8 i);
        void setGITKType(u8 t);
        void setGITKKind(u8 k);
        void setMsgId(u8);
        u8 getGITKGroup();
        u8 getGITKId();
        u8 getGITKType();
        u8 getGITKKind();
        u8 getMsgId();
        virtual void sendNetMessage(u32 netMsgId);  // vtable slot 13
        virtual void receiveNetMessage(nNetMsg::cNetMsgBase& call, s32 member_index);  // vtable slot 14
        // Address: 0x019af480 - 0x019af481 (1 bytes)
        virtual void sendNetAction(nNetMsgData::nCtrl::NET_MSG_ID msgId, nNetMsg::MSG_PRIO prio, nNetMsg::MSG_ADR adr, u32 characterId) {}  // vtable slot 15
        // Address: 0x019af490 - 0x019af491 (1 bytes)
        virtual void sendNetGame(nNetMsgData::nGame::NET_MSG_ID_GAME msgId, nNetMsg::MSG_PRIO prio, nNetMsg::MSG_ADR adr, u32 characterId) {}  // vtable slot 16
        // Address: 0x019af4a0 - 0x019af4a1 (1 bytes)
        virtual void sendNetGameEasy(nNetMsgData::nGame::NET_MSG_ID_GAME_EASY kind, u32 characterId) {}  // vtable slot 17
        // Address: 0x019af4b0 - 0x019af4b1 (1 bytes)
        virtual void sendNetSet(nNetMsgData::nSetMgr::NET_MSG_ID_SET msgId, nNetMsg::MSG_PRIO prio, nNetMsg::MSG_ADR adr, u32 characterId) {}  // vtable slot 18
        // Address: 0x019af4c0 - 0x019af4c1 (1 bytes)
        virtual void sendNetItem(nNetMsgData::nItemMgr::NET_MSG_ID_ITEM msgId, nNetMsg::MSG_PRIO prio, nNetMsg::MSG_ADR adr, u32 characterId) {}  // vtable slot 19
        // Address: 0x019af4d0 - 0x019af4d1 (1 bytes)
        virtual void sendNetTool(nNetMsgData::nTool::NET_MSG_ID_TOOL msgId, nNetMsg::MSG_PRIO prio, nNetMsg::MSG_ADR adr, u32 characterId) {}  // vtable slot 20
        // Address: 0x019af4e0 - 0x019af4e1 (1 bytes)
        virtual void sendNetToolEasy(nNetMsgData::nTool::NET_MSG_ID_TOOL_EASY kind, u32 characterId) {}  // vtable slot 21
    protected:
        virtual bool processRemoteCall(cRemoteCall& rpc, bool isParallel, s32 member_id);  // vtable slot 9
    public:
        u8 getLastSendMsgId();
        void setLastSendMsgId(u8 id);
        u8 getLastRecvMsgId();
        void setLastRecvMsgId(u8 id);
        u32 getLastSendFrame();
    protected:
        void setLastSendFrame(u32 frame);
    public:
        nNetMsg::MSG_PRIO getPrio();
        void setPrio(nNetMsg::MSG_PRIO prio);
        nNetMsg::MSG_ADR getAdr();
        void setAdr(nNetMsg::MSG_ADR adr);
        u32 getCharacterId();
        void setCharacterId(u32 id);
    private:
        u8 mGroup;  // offset: 0x60
        u8 mId;  // offset: 0x61
        u8 mType;  // offset: 0x62
        u8 mKind;  // offset: 0x63
        RPC_ID mRpcId;  // offset: 0x64
        u32 mLastSendFrame;  // offset: 0x68
        nNetMsg::MSG_PRIO mPrio;  // offset: 0x6c
        nNetMsg::MSG_ADR mAdr;  // offset: 0x70
        u32 mCharacterId;  // offset: 0x74
        u8 mLastSendMsgId;  // offset: 0x78
        u8 mLastRecvMsgId;  // offset: 0x79
    public:
        static MyDTI DTI;
    };
}  // namespace nNetBase

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline RPC_ID nNetBase::cNetBase::getRpcId() {
    return this->mRpcId;
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline nNetMsg::MSG_PRIO nNetBase::cNetBase::getPrio() {
    return this->mPrio;
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline u32 nNetBase::cNetBase::getCharacterId() {
    return this->mCharacterId;
}
