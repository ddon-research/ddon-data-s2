#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
class CPacket;

// Declarations
namespace nLoginSession { class CPacket_C2L_DECIDE_CHARACTER_ID_REQ; }

// Type aliases from DWARF
using s32 = int;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

namespace nLoginSession {
    class CPacket_C2L_DECIDE_CHARACTER_ID_REQ
    {
    public:
        CPacket_C2L_DECIDE_CHARACTER_ID_REQ();
        s32 WritePacket(CPacket* pPacket, u32 in_CharacterID, u32 in_ClientVersion, u8 in_Type, u8 in_RotationServerID, u32 in_WaitNum, u8 in_Counter);
        s32 ReadPacket(CPacket*);
        u16 Error() const;
        u32 CharacterID() const;
        u32 ClientVersion() const;
        u8 Type() const;
        u8 RotationServerID() const;
        u32 WaitNum() const;
        u8 Counter() const;
        bool isReceived() const;
    private:
        u16 m_usError;  // offset: 0x0
        u32 m_unCharacterID;  // offset: 0x4
        u32 m_unClientVersion;  // offset: 0x8
        u8 m_ucType;  // offset: 0xc
        u8 m_ucRotationServerID;  // offset: 0xd
        u32 m_unWaitNum;  // offset: 0x10
        u8 m_ucCounter;  // offset: 0x14
        bool m_bIsReceived;  // offset: 0x15
    };
}  // namespace nLoginSession
