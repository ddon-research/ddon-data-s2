#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtString;

// Declarations
class CPacket;
class CPacketBase;
class CPacketDataBase;

// Type aliases from DWARF
using DWORD = unsigned int;
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

namespace nPacket {

    int Read(CPacket& packet, u8& v);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/cPacket.cpp:38
    int Read(CPacket& packet, u32& v);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/cPacket.cpp:40
    int Read(CPacket& packet, u64& v);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/cPacket.cpp:41
    int Read(CPacket& packet, s8& v);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/cPacket.cpp:42
    int Read(CPacket& packet, s16& v);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/cPacket.cpp:43
    int Read(CPacket& packet, s32& v);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/cPacket.cpp:44
    int Read(CPacket& packet, s64& v);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/cPacket.cpp:45
    int Read(CPacket& packet, bool& v);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/cPacket.cpp:48
    int Read(CPacket& packet, f32& v);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/cPacket.cpp:52
    int Read(CPacket& packet, f64& v);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/cPacket.cpp:71
    int Read(CPacket& packet, u16& v);
    int Read(CPacket& packet, MtString& str);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/cPacket.cpp:90
    int Read(CPacket& packet, unsigned char* pBuf, int size);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/cPacket.cpp:124
    int Write(CPacket& packet, u8 v);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/cPacket.cpp:131
    int Write(CPacket& packet, u32 v);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/cPacket.cpp:133
    int Write(CPacket& packet, u64 v);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/cPacket.cpp:134
    int Write(CPacket& packet, s8 v);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/cPacket.cpp:135
    int Write(CPacket& packet, s16 v);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/cPacket.cpp:136
    int Write(CPacket& packet, s32 v);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/cPacket.cpp:137
    int Write(CPacket& packet, s64 v);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/cPacket.cpp:138
    int Write(CPacket& packet, bool v);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/cPacket.cpp:141
    int Write(CPacket& packet, const unsigned char* pBuf, int size);
    int Write(CPacket& packet, f32 v);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/cPacket.cpp:145
    int Write(CPacket& packet, f64 v);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/cPacket.cpp:158
    int Write(CPacket& packet, u16 v);
    int Write(CPacket& packet, MT_CTSTR t);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/cPacket.cpp:171
    int Write(CPacket& packet, const MtString& str);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/cPacket.cpp:191

}  // namespace nPacket

class CPacketBase
{
public:
    explicit CPacketBase();
    explicit CPacketBase(const unsigned char* pBuf, const size_t sizeBuf);
    virtual ~CPacketBase();
    const void* Data() const;
    void* Ptr();
    DWORD Size() const;
    bool IsEmpty() const;
    size_t Capacity() const;
    size_t PotentialCapacity() const;
    void Clear();
    void TrimLeft();
    bool IsReserve(const size_t more);
    size_t ReadBytes(void* pBuf, const size_t size);
    size_t WriteBytes(const void* const pBuf, const size_t size);
    void SeekReaderCursor(const size_t pos);
    void SeekWriterCursor(const size_t);
public:
    unsigned char* m_pStart;  // offset: 0x8
    unsigned char* m_pEnd;  // offset: 0x10
    unsigned char* m_pReader;  // offset: 0x18
    unsigned char* m_pWriter;  // offset: 0x20
    MtAllocator* mpAllocator;  // offset: 0x28
    unsigned char* m_pBuffer;  // offset: 0x30
private:
    static const size_t BuffSize = 25000;
};

class CPacketDataBase : public MtObject
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
    CPacketDataBase();
    // Address: 0x01a50590 - 0x01a50591 (1 bytes)
    virtual ~CPacketDataBase() {}
public:
    static MyDTI DTI;
};

class CPacket : public CPacketBase
{
public:
    explicit CPacket();
    explicit CPacket(const unsigned char* pBuf, size_t sizeBuf);
    virtual ~CPacket();
    void Update();
    u16 Type();
};

// Inline, no code of its own: checked where it is inlined.
inline CPacketDataBase::CPacketDataBase() {
}
