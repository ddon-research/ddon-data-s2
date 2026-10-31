#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../PacketData/Character.h"
#include "../PacketData/GP.h"
#include "../PacketData/Message.h"
#include "../../../../MT/MtCollection.h"
#include "../../../../MT/MtDTI.h"
#include "../../../../MT/MtString.h"
#include "../PacketData/Server.h"
#include "../PacketData/ServerSetting.h"
#include "../../cPacket.h"

// Forward declarations
class CDataCharacterListInfo;
class CDataErrorMessage;
class CDataGPCourseEffectParam;
class CDataGPCourseInfo;
class CDataGameServerListInfo;
class CDataLoginSetting;
class CPacket;
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;
class sGame;

// Declarations
namespace nLoginSession { class CPacket_L2C_CLIENT_CHALLENGE_RES; }
namespace nLoginSession { class CPacket_L2C_CREATE_CHARACTER_DATA_NTC; }
namespace nLoginSession { class CPacket_L2C_CREATE_CHARACTER_DATA_RES; }
namespace nLoginSession { class CPacket_L2C_DECIDE_CANCEL_CHARACTER_RES; }
namespace nLoginSession { class CPacket_L2C_DECIDE_CHARACTER_ID_RES; }
namespace nLoginSession { class CPacket_L2C_DELETE_CHARACTER_INFO_RES; }
namespace nLoginSession { class CPacket_L2C_EJECTION_NTC; }
namespace nLoginSession { class CPacket_L2C_GET_CHARACTER_LIST_RES; }
namespace nLoginSession { class CPacket_L2C_GET_ERROR_MESSAGE_LIST_NTC; }
namespace nLoginSession { class CPacket_L2C_GET_ERROR_MESSAGE_LIST_RES; }
namespace nLoginSession { class CPacket_L2C_GET_GAME_SERVER_LIST_RES; }
namespace nLoginSession { class CPacket_L2C_GET_GAME_SESSION_KEY_RES; }
namespace nLoginSession { class CPacket_L2C_GET_LOGIN_SETTING_RES; }
namespace nLoginSession { class CPacket_L2C_GP_COURSE_GET_INFO_RES; }
namespace nLoginSession { class CPacket_L2C_LOGIN_RES; }
namespace nLoginSession { class CPacket_L2C_LOGIN_WAIT_NUM_NTC; }
namespace nLoginSession { class CPacket_L2C_LOGOUT_RES; }
namespace nLoginSession { class CPacket_L2C_NEXT_CONNECT_SERVER_NTC; }
namespace nLoginSession { class CPacket_L2C_PING_RES; }

// Type aliases from DWARF
using CGameServerListInfo = CDataGameServerListInfo;
using CLoginSetting = CDataLoginSetting;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

namespace nLoginSession {
    class CPacket_L2C_CLIENT_CHALLENGE_RES : public ::CPacketDataBase
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
        CPacket_L2C_CLIENT_CHALLENGE_RES();
        s32 WritePacket(CPacket*, s32, u8, u8, const u8(&)[62]);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u8 PasswordSrcSize() const;
        u8 PasswordEncSize() const;
        auto PasswordEnc() -> u8(&)[62];
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u8 m_ucPasswordSrcSize;  // offset: 0x10
        u8 m_ucPasswordEncSize;  // offset: 0x11
        u8 m_ucPasswordEnc[62];  // offset: 0x12
        bool m_bIsReceived;  // offset: 0x50
    public:
        static MyDTI DTI;
    };
}  // namespace nLoginSession

namespace nLoginSession {
    class CPacket_L2C_CREATE_CHARACTER_DATA_NTC : public ::CPacketDataBase
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
        CPacket_L2C_CREATE_CHARACTER_DATA_NTC();
        s32 WritePacket(CPacket*, s32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 CharacterID() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unCharacterID;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x14
    public:
        static MyDTI DTI;
    };
}  // namespace nLoginSession

namespace nLoginSession {
    class CPacket_L2C_CREATE_CHARACTER_DATA_RES : public ::CPacketDataBase
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
        CPacket_L2C_CREATE_CHARACTER_DATA_RES();
        s32 WritePacket(CPacket*, s32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 WaitNum() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unWaitNum;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x14
    public:
        static MyDTI DTI;
    };
}  // namespace nLoginSession

namespace nLoginSession {
    class CPacket_L2C_DECIDE_CANCEL_CHARACTER_RES : public ::CPacketDataBase
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
        CPacket_L2C_DECIDE_CANCEL_CHARACTER_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nLoginSession

namespace nLoginSession {
    class CPacket_L2C_DECIDE_CHARACTER_ID_RES : public ::CPacketDataBase
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
        CPacket_L2C_DECIDE_CHARACTER_ID_RES();
        s32 WritePacket(CPacket*, s32, u32, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        u32 CharacterID() const;
        u32 WaitNum() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        u32 m_unCharacterID;  // offset: 0x10
        u32 m_unWaitNum;  // offset: 0x14
        bool m_bIsReceived;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace nLoginSession

namespace nLoginSession {
    class CPacket_L2C_DELETE_CHARACTER_INFO_RES : public ::CPacketDataBase
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
        CPacket_L2C_DELETE_CHARACTER_INFO_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nLoginSession

namespace nLoginSession {
    class CPacket_L2C_EJECTION_NTC : public ::CPacketDataBase
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
        CPacket_L2C_EJECTION_NTC();
        s32 WritePacket(CPacket*, const char*);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        const char* Message() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        MtString m_wstrMessage;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace nLoginSession

namespace nLoginSession {
    class CPacket_L2C_GET_CHARACTER_LIST_RES : public ::CPacketDataBase
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
        CPacket_L2C_GET_CHARACTER_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataCharacterListInfo>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataCharacterListInfo>& CharacterList() const;
        MtTypedArray<CDataCharacterListInfo>& CharacterList();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataCharacterListInfo> m_CharacterList;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nLoginSession

namespace nLoginSession {
    class CPacket_L2C_GET_ERROR_MESSAGE_LIST_NTC : public ::CPacketDataBase
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
        CPacket_L2C_GET_ERROR_MESSAGE_LIST_NTC();
        s32 WritePacket(CPacket*, const MtTypedArray<CDataErrorMessage>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        const MtTypedArray<CDataErrorMessage>& ErrorMessage() const;
        MtTypedArray<CDataErrorMessage>& ErrorMessage();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        MtTypedArray<CDataErrorMessage> m_ErrorMessage;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nLoginSession

namespace nLoginSession {
    class CPacket_L2C_GET_ERROR_MESSAGE_LIST_RES : public ::CPacketDataBase
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
        CPacket_L2C_GET_ERROR_MESSAGE_LIST_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nLoginSession

namespace nLoginSession {
    class CPacket_L2C_GET_GAME_SERVER_LIST_RES : public ::CPacketDataBase
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
        CPacket_L2C_GET_GAME_SERVER_LIST_RES();
        s32 WritePacket(CPacket*, s32, const MtTypedArray<CDataGameServerListInfo>&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const MtTypedArray<CDataGameServerListInfo>& GameServerListInfo() const;
        MtTypedArray<CDataGameServerListInfo>& GameServerListInfo();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtTypedArray<CDataGameServerListInfo> m_GameServerListInfo;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nLoginSession

namespace nLoginSession {
    class CPacket_L2C_GET_GAME_SESSION_KEY_RES : public ::CPacketDataBase
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
        CPacket_L2C_GET_GAME_SESSION_KEY_RES();
        s32 WritePacket(CPacket*, s32, const char*, u16);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const char* SessionKey() const;
        u16 GameServerUniqueID() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtString m_wstrSessionKey;  // offset: 0x10
        u16 m_usGameServerUniqueID;  // offset: 0x18
        bool m_bIsReceived;  // offset: 0x1a
    public:
        static MyDTI DTI;
    };
}  // namespace nLoginSession

namespace nLoginSession {
    class CPacket_L2C_GET_LOGIN_SETTING_RES : public ::CPacketDataBase
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
        CPacket_L2C_GET_LOGIN_SETTING_RES();
        s32 WritePacket(CPacket*, s32, const CLoginSetting&);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const CLoginSetting& LoginSetting() const;
        CLoginSetting& LoginSetting();
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        CLoginSetting m_LoginSetting;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x50
    public:
        static MyDTI DTI;
    };
}  // namespace nLoginSession

namespace nLoginSession {
    class CPacket_L2C_GP_COURSE_GET_INFO_RES : public ::CPacketDataBase
    {
        friend class ::sGame;
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
        CPacket_L2C_GP_COURSE_GET_INFO_RES();
        s32 WritePacket(CPacket*, u32, const MtTypedArray<CDataGPCourseInfo>&, const MtTypedArray<CDataGPCourseEffectParam>&, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 Result() const;
        const MtTypedArray<CDataGPCourseInfo>& CourseInfo() const;
        MtTypedArray<CDataGPCourseInfo>& CourseInfo();
        const MtTypedArray<CDataGPCourseEffectParam>& Effects() const;
        MtTypedArray<CDataGPCourseEffectParam>& Effects();
        u32 Version() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unResult;  // offset: 0xc
        MtTypedArray<CDataGPCourseInfo> m_CourseInfo;  // offset: 0x10
        MtTypedArray<CDataGPCourseEffectParam> m_Effects;  // offset: 0x30
        u32 m_unVersion;  // offset: 0x50
        bool m_bIsReceived;  // offset: 0x54
    public:
        static MyDTI DTI;
    };
}  // namespace nLoginSession

namespace nLoginSession {
    class CPacket_L2C_LOGIN_RES : public ::CPacketDataBase
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
        CPacket_L2C_LOGIN_RES();
        s32 WritePacket(CPacket* pPacket, s32 in_Result, const char* in_strOnetimeToken);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const char* OnetimeToken() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        MtString m_wstrOnetimeToken;  // offset: 0x10
        bool m_bIsReceived;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
}  // namespace nLoginSession

namespace nLoginSession {
    class CPacket_L2C_LOGIN_WAIT_NUM_NTC : public ::CPacketDataBase
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
        CPacket_L2C_LOGIN_WAIT_NUM_NTC();
        s32 WritePacket(CPacket*, u32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        u32 WaitNum() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        u32 m_unWaitNum;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nLoginSession

namespace nLoginSession {
    class CPacket_L2C_LOGOUT_RES : public ::CPacketDataBase
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
        CPacket_L2C_LOGOUT_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nLoginSession

namespace nLoginSession {
    class CPacket_L2C_NEXT_CONNECT_SERVER_NTC : public ::CPacketDataBase
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
        CPacket_L2C_NEXT_CONNECT_SERVER_NTC();
        s32 WritePacket(CPacket*, s32, const CGameServerListInfo&, u8);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        const CGameServerListInfo& GameServer() const;
        CGameServerListInfo& GameServer();
        u8 Counter() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        CGameServerListInfo m_GameServer;  // offset: 0x10
        u8 m_ucCounter;  // offset: 0x58
        bool m_bIsReceived;  // offset: 0x59
    public:
        static MyDTI DTI;
    };
}  // namespace nLoginSession

namespace nLoginSession {
    class CPacket_L2C_PING_RES : public ::CPacketDataBase
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
        CPacket_L2C_PING_RES();
        s32 WritePacket(CPacket*, s32);
        s32 ReadPacket(CPacket* pPacket);
        u16 Error() const;
        s32 Result() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x8
        s32 m_nResult;  // offset: 0xc
        bool m_bIsReceived;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nLoginSession

inline nLoginSession::CPacket_L2C_CLIENT_CHALLENGE_RES::CPacket_L2C_CLIENT_CHALLENGE_RES() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
    this->m_ucPasswordEnc[58] = 0;
    this->m_ucPasswordEnc[59] = 0;
    this->m_ucPasswordEnc[60] = 0;
    this->m_ucPasswordEnc[61] = 0;
    this->m_ucPasswordEnc[50] = 0;
    this->m_ucPasswordEnc[51] = 0;
    this->m_ucPasswordEnc[52] = 0;
    this->m_ucPasswordEnc[53] = 0;
    this->m_ucPasswordEnc[54] = 0;
    this->m_ucPasswordEnc[55] = 0;
    this->m_ucPasswordEnc[56] = 0;
    this->m_ucPasswordEnc[57] = 0;
    this->m_ucPasswordEnc[42] = 0;
    this->m_ucPasswordEnc[43] = 0;
    this->m_ucPasswordEnc[44] = 0;
    this->m_ucPasswordEnc[45] = 0;
    this->m_ucPasswordEnc[46] = 0;
    this->m_ucPasswordEnc[47] = 0;
    this->m_ucPasswordEnc[48] = 0;
    this->m_ucPasswordEnc[49] = 0;
    this->m_ucPasswordEnc[34] = 0;
    this->m_ucPasswordEnc[35] = 0;
    this->m_ucPasswordEnc[36] = 0;
    this->m_ucPasswordEnc[37] = 0;
    this->m_ucPasswordEnc[38] = 0;
    this->m_ucPasswordEnc[39] = 0;
    this->m_ucPasswordEnc[40] = 0;
    this->m_ucPasswordEnc[41] = 0;
    this->m_ucPasswordEnc[26] = 0;
    this->m_ucPasswordEnc[27] = 0;
    this->m_ucPasswordEnc[28] = 0;
    this->m_ucPasswordEnc[29] = 0;
    this->m_ucPasswordEnc[30] = 0;
    this->m_ucPasswordEnc[31] = 0;
    this->m_ucPasswordEnc[32] = 0;
    this->m_ucPasswordEnc[33] = 0;
    this->m_ucPasswordEnc[18] = 0;
    this->m_ucPasswordEnc[19] = 0;
    this->m_ucPasswordEnc[20] = 0;
    this->m_ucPasswordEnc[21] = 0;
    this->m_ucPasswordEnc[22] = 0;
    this->m_ucPasswordEnc[23] = 0;
    this->m_ucPasswordEnc[24] = 0;
    this->m_ucPasswordEnc[25] = 0;
    this->m_ucPasswordEnc[10] = 0;
    this->m_ucPasswordEnc[11] = 0;
    this->m_ucPasswordEnc[12] = 0;
    this->m_ucPasswordEnc[13] = 0;
    this->m_ucPasswordEnc[14] = 0;
    this->m_ucPasswordEnc[15] = 0;
    this->m_ucPasswordEnc[16] = 0;
    this->m_ucPasswordEnc[17] = 0;
    this->m_ucPasswordEnc[2] = 0;
    this->m_ucPasswordEnc[3] = 0;
    this->m_ucPasswordEnc[4] = 0;
    this->m_ucPasswordEnc[5] = 0;
    this->m_ucPasswordEnc[6] = 0;
    this->m_ucPasswordEnc[7] = 0;
    this->m_ucPasswordEnc[8] = 0;
    this->m_ucPasswordEnc[9] = 0;
    this->m_nResult = 0;
    this->m_ucPasswordSrcSize = 0;
    this->m_ucPasswordEncSize = 0;
    this->m_ucPasswordEnc[0] = 0;
    this->m_ucPasswordEnc[1] = 0;
}

inline nLoginSession::CPacket_L2C_CREATE_CHARACTER_DATA_NTC::CPacket_L2C_CREATE_CHARACTER_DATA_NTC() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unCharacterID = 0;
    this->m_bIsReceived = false;
}

inline nLoginSession::CPacket_L2C_CREATE_CHARACTER_DATA_RES::CPacket_L2C_CREATE_CHARACTER_DATA_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_unWaitNum = 0;
    this->m_bIsReceived = false;
}

inline nLoginSession::CPacket_L2C_DECIDE_CANCEL_CHARACTER_RES::CPacket_L2C_DECIDE_CANCEL_CHARACTER_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nLoginSession::CPacket_L2C_DECIDE_CHARACTER_ID_RES::CPacket_L2C_DECIDE_CHARACTER_ID_RES() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
    this->m_unWaitNum = 0;
    this->m_nResult = 0;
    this->m_unCharacterID = 0;
}

inline nLoginSession::CPacket_L2C_DELETE_CHARACTER_INFO_RES::CPacket_L2C_DELETE_CHARACTER_INFO_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nLoginSession::CPacket_L2C_EJECTION_NTC::CPacket_L2C_EJECTION_NTC() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
}

inline nLoginSession::CPacket_L2C_GET_CHARACTER_LIST_RES::CPacket_L2C_GET_CHARACTER_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nLoginSession::CPacket_L2C_GET_ERROR_MESSAGE_LIST_NTC::CPacket_L2C_GET_ERROR_MESSAGE_LIST_NTC() {
    this->m_usError = 0;
    this->m_bIsReceived = false;
}

inline nLoginSession::CPacket_L2C_GET_ERROR_MESSAGE_LIST_RES::CPacket_L2C_GET_ERROR_MESSAGE_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nLoginSession::CPacket_L2C_GET_GAME_SERVER_LIST_RES::CPacket_L2C_GET_GAME_SERVER_LIST_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nLoginSession::CPacket_L2C_GP_COURSE_GET_INFO_RES::CPacket_L2C_GP_COURSE_GET_INFO_RES() {
    this->m_usError = 0;
    this->m_unResult = 0;
    this->m_unVersion = 0;
    this->m_bIsReceived = false;
}

inline nLoginSession::CPacket_L2C_LOGIN_RES::CPacket_L2C_LOGIN_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nLoginSession::CPacket_L2C_LOGIN_WAIT_NUM_NTC::CPacket_L2C_LOGIN_WAIT_NUM_NTC() {
    this->m_usError = 0;
    this->m_unWaitNum = 0;
    this->m_bIsReceived = false;
}

inline nLoginSession::CPacket_L2C_LOGOUT_RES::CPacket_L2C_LOGOUT_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}

inline nLoginSession::CPacket_L2C_PING_RES::CPacket_L2C_PING_RES() {
    this->m_usError = 0;
    this->m_nResult = 0;
    this->m_bIsReceived = false;
}
