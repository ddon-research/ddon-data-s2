#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
class CDataCharacterListElement;
class CDataClanHistoryElement;
class CDataClanJoinRequest;
class CDataClanScoutEntryInviteInfo;
class CDataClanSearchResult;
class CDataLobbyMemberInfo;
class CDataPartyMemberMinimum;
class CDataPawnHistory;
class MtAllocator;
class MtDataWriter;
class cAISvUserProcess;
class cAIUserProcessContainer;
class cMenuLostPawnRevive;
class cMenuSubMenu;
namespace nCaplink { class ContextListener; }
namespace nUserSession { class CPacket_S2C_ADD_BLACK_LIST_RES; }
namespace nUserSession { class CPacket_S2C_SEND_TELL_MSG_RES; }
class sAI;
class sBrowser;
class sMain;
class uGUIBase;
class uGUINewspaper;

// Declarations
class MtString;
template <int _size> class MtStringEx;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_STR = MT_CHAR*;
using s32 = int;
using u32 = unsigned int;
using u8 = unsigned char;

// Functions the classes below befriend, declared first
namespace nDDOIO { void writeData(MtDataWriter& w, const MtString& data); }

class MtString
{
    friend class CDataCharacterListElement;
    friend class CDataClanHistoryElement;
    friend class CDataClanJoinRequest;
    friend class CDataClanScoutEntryInviteInfo;
    friend class CDataClanSearchResult;
    friend class CDataLobbyMemberInfo;
    friend class CDataPartyMemberMinimum;
    friend class CDataPawnHistory;
    friend class cAISvUserProcess;
    friend class cAIUserProcessContainer;
    friend class cMenuLostPawnRevive;
    friend class cMenuSubMenu;
    friend class nCaplink::ContextListener;
    friend void nDDOIO::writeData(MtDataWriter& w, const MtString& data);
    friend class nUserSession::CPacket_S2C_ADD_BLACK_LIST_RES;
    friend class nUserSession::CPacket_S2C_SEND_TELL_MSG_RES;
    friend class sAI;
    friend class sBrowser;
    friend class sMain;
    friend class uGUIBase;
    friend class uGUINewspaper;
public:
    struct STRING;
public:
    struct STRING
    {
    public:
        s32 ref;  // offset: 0x0
        u32 length;  // offset: 0x4
        u8 str[1];  // offset: 0x8
    };
public:
    static void setAllocator(MtAllocator* pa);
    static MtAllocator* getAllocator();
    static u32 length(MT_CTSTR s);
    static void copy(MT_STR a, MT_CTSTR b);
    static void copy(MT_STR a, MT_CTSTR b, const u32 max);
    static void concatenate(MT_STR a, MT_CTSTR b, const u32 max);
    static s32 compare(MT_CTSTR a, MT_CTSTR b);
    static s32 compare(MT_CTSTR a, MT_CTSTR b, u32 n);
    static s32 icompare(MT_CTSTR a, MT_CTSTR b);
    static s32 icompare(MT_CTSTR, MT_CTSTR, u32);
    static MT_CTSTR strstr(MT_CTSTR from, MT_CTSTR key);
    static MT_CTSTR stristr(MT_CTSTR from, MT_CTSTR key);
    MtString();
    MtString(MT_CTSTR str);
    MtString(const MtString& str);
    ~MtString();
    u32 length() const;
    MT_CTSTR ptr() const;
    const MtString& copy(MT_CTSTR str);
    const MtString& copy(const MtString& str);
    s32 compare(MT_CTSTR str) const;
    s32 compare(const MtString& str) const;
    s32 icompare(const MtString& str) const;
    void concat(MT_CHAR c);
    void concat(MT_CTSTR str);
    void concat(const MtString& str);
    const MtString& format(MT_CTSTR format, ...);
    operator const char *() const;
    const MtString& operator=(MT_CTSTR str);
    const MtString& operator=(const MtString& str);
    void operator+=(MT_CHAR c);
    void operator+=(MT_CTSTR str);
    void operator+=(const MtString& str);
    MtString operator+(MT_CTSTR str);
    MtString operator+(const MtString& str);
    bool operator==(MT_CTSTR str) const;
    bool operator==(const MtString& str) const;
    bool operator!=(MT_CTSTR str) const;
    bool operator!=(const MtString& str) const;
    bool operator<(MT_CTSTR) const;
    bool operator<(const MtString& str) const;
    bool operator>(MT_CTSTR) const;
    bool operator>(const MtString& str) const;
    bool operator<=(MT_CTSTR) const;
    bool operator<=(const MtString&) const;
    bool operator>=(MT_CTSTR) const;
    bool operator>=(const MtString&) const;
protected:
    void create(MT_CTSTR str);
    void release();
    s32 compare(STRING* a, STRING* b) const;
    STRING* concat(STRING* a, STRING* b);
protected:
    STRING* value;  // offset: 0x0
private:
    static MtAllocator* mpAllocator;
};

template <int _size>
class MtStringEx
{
public:
    MtStringEx();
    MtStringEx(MT_CTSTR str);
    MtStringEx(const MtString& str);
    u32 length() const;
    MT_CTSTR ptr() const;
    MT_CTSTR copy(MT_CTSTR str);
    void concat(MT_CTSTR str);
    s32 compare(MT_CTSTR str) const;
    MT_CTSTR format(MT_CTSTR format, ...);
    operator const char *() const;
    MT_CTSTR operator=(MT_CTSTR str);
    MT_CTSTR operator=(const MtString& str);
    void operator+=(MT_CTSTR str);
    void operator+=(MtString str);
    bool operator==(MT_CTSTR str) const;
    void concat(MT_CHAR c);
    void operator+=(MT_CHAR c);
protected:
    u32 mLength;  // offset: 0x0
    char mStr[_size];  // offset: 0x4
};

inline MtString::MtString() {
    this->value = nullptr;
}

inline MT_CTSTR MtString::ptr() const {
    return (this->value == nullptr) ? "" : reinterpret_cast<MT_CTSTR>(this->value->str);
}

// Included after the classes: the generic bodies below need these complete.
#include "MtAllocator.h"

template <int _size>
inline MtStringEx<_size>::MtStringEx() {
    this->mStr[0] = 0;
    this->mLength = 0;
}

#include <sce_atomic.h>
#include <string.h>
inline MtString::MtString(MT_CTSTR str) {
    create(str);
}

inline MtString::MtString(const MtString& str) {
    value = str.value;
    if (value != nullptr) {
        sceAtomicIncrement32(&value->ref);
    }
}

inline void MtString::create(MT_CTSTR str) {
    if (str != nullptr) {
        u32 length = static_cast<u32>(strlen(str));
        if (length != 0u) {
            value = static_cast<STRING*>(mpAllocator->memAlloc(sizeof(STRING) + length, 16u));
            value->ref = 1;
            value->length = length;
            strcpy(reinterpret_cast<char*>(value->str), str);
        } else {
            value = nullptr;
        }
    } else {
        value = nullptr;
    }
}

inline u32 MtString::length() const {
    return (value == nullptr) ? 0u : value->length;
}

inline const MtString& MtString::operator=(MT_CTSTR str) {
    if (ptr() != str) {
        release();
        create(str);
    }
    return *this;
}

inline void MtString::release() {
    if (value != nullptr) {
        if (sceAtomicDecrement32(&value->ref) == 1) {
            mpAllocator->memFree(value);
        }
        value = nullptr;
    }
}

__attribute__((used)) inline MtString::~MtString() {
    release();
}
