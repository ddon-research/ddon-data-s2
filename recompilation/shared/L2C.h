#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "Character.h"
#include "GP.h"
#include "Message.h"
#include "MtCollection.h"
#include "MtDTI.h"
#include "Server.h"
#include "ServerSetting.h"
#include "cPacket.h"

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
class sGame;

// Declarations
namespace nLoginSession { class CPacket_L2C_CLIENT_CHALLENGE_RES; }
namespace nLoginSession { class CPacket_L2C_CREATE_CHARACTER_DATA_NTC; }
namespace nLoginSession { class CPacket_L2C_CREATE_CHARACTER_DATA_RES; }
namespace nLoginSession { class CPacket_L2C_DECIDE_CANCEL_CHARACTER_RES; }
namespace nLoginSession { class CPacket_L2C_DECIDE_CHARACTER_ID_RES; }
namespace nLoginSession { class CPacket_L2C_DELETE_CHARACTER_INFO_RES; }
namespace nLoginSession { class CPacket_L2C_GET_CHARACTER_LIST_RES; }
namespace nLoginSession { class CPacket_L2C_GET_ERROR_MESSAGE_LIST_NTC; }
namespace nLoginSession { class CPacket_L2C_GET_ERROR_MESSAGE_LIST_RES; }
namespace nLoginSession { class CPacket_L2C_GET_GAME_SERVER_LIST_RES; }
namespace nLoginSession { class CPacket_L2C_GET_LOGIN_SETTING_RES; }
namespace nLoginSession { class CPacket_L2C_GP_COURSE_GET_INFO_RES; }
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
        // inferred: sGame::clearChargeCourse names sGame::mPacketGPCourseInfo.m_CourseInfo.::MtArray::mLength
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
