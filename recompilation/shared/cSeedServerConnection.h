#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtNetDevice.h"
#include "MtObject.h"
#include "MtStream.h"
#include "MtSynchronize.h"

// Forward declarations
class CPacket;
class MtAllocator;
class MtCriticalSection;
class MtDTI;
struct MtNetAddress;
struct MtNetIpAddress;
class MtNetSocket;
class MtObject;
class MtString;
class MtThread;
class cNetGameServer;
class cNetLoginServer;

// Declarations
class cSeedServerConnection;
class cSeedServerStream;

// Type aliases from DWARF
using BOOL = int;
using DWORD = unsigned int;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class cSeedServerStream : public MtMemoryStream
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
    cSeedServerStream(u32 bufsiz, u32 mode, MtAllocator* pallocator);
    cSeedServerStream(void*, u32, u32);
    u8* rdbuf() const;
    cSeedServerStream& seekp(s32 aPos);
    u32 tellp() const;
    u32 operator<<(const cSeedServerStream&);
public:
    static MyDTI DTI;
};

class cSeedServerConnection : public MtObject
{
    // inferred: cNetGameServer::isLogin names cSeedServerConnection::mConnStatus
    friend class cNetGameServer;
    // inferred: cNetLoginServer::isConnectServer names cSeedServerConnection::mConnStatus
    friend class cNetLoginServer;
public:
    enum eConnStatus
    {
        CONN_NONE = 0,
        CONN_RESOLVING = 1,
        CONN_CONNECTING = 2,
        CONN_HANDSHAKING = 3,
        CONN_CONNECTED = 4,
        CONN_DISCONNECTING = 5,
        CONN_DISCONNECTED = 6,
        CONN_ERROR = 7,
    };
public:
    class MyDTI;
    class cCalcBps;
    struct cGuardData;
    struct stPacketHeader;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cCalcBps
    {
    public:
        cCalcBps();
        // Address: 0x01a606a0 - 0x01a606a1 (1 bytes)
        virtual ~cCalcBps() {}
        virtual void init();  // vtable slot 2
        virtual void update(s32 byte, s32 sec);  // vtable slot 3
        virtual s32 getBps(s32 value);  // vtable slot 4
        virtual s32 getNowSize();  // vtable slot 5
    protected:
        s32 mCurrentIndex;  // offset: 0x8
        s32 mTotalByte[10];  // offset: 0xc
        f32 mTime;  // offset: 0x34
    };
public:
    struct cGuardData
    {
    public:
        char mCommonKey[49];  // offset: 0x0
        bool mIsEnableCipher;  // offset: 0x31
    };
public:
    struct stPacketHeader
    {
    public:
        stPacketHeader();
        stPacketHeader(cSeedServerStream&);
        stPacketHeader(u8* in);
        void setParam(u8* in);
        void createHeader(u16 inSize, u16 inType, u16 inError);
        u32 getSize();
    public:
        u16 size;  // offset: 0x0
        u16 type;  // offset: 0x2
        u16 error;  // offset: 0x4
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
    cSeedServerConnection();
    virtual ~cSeedServerConnection();
    virtual void initialize();  // vtable slot 6
    void connect(MT_CTSTR peerAddr, u16 port);
    void connect(MtNetAddress& addr);
    virtual void disconnect(eConnStatus aNextStatus);  // vtable slot 7
    virtual void move();  // vtable slot 8
    virtual void moveNone();  // vtable slot 9
    virtual void moveResolving();  // vtable slot 10
    virtual void moveConnecting();  // vtable slot 11
    virtual void moveHandShaking();  // vtable slot 12
    virtual void moveConnected();  // vtable slot 13
    virtual cSeedServerStream* moveConnected_decrypt(u32 aReadSize);  // vtable slot 14
    virtual void moveDisconnecting();  // vtable slot 15
    virtual void moveDisconnected();  // vtable slot 16
    virtual void moveError();  // vtable slot 17
    s32 recvBuffer(s32& totalRead);
    s32 analyzePacket(s32 totalRead);
    virtual BOOL callOnPacketFunc(u32 index, CPacket* pPacket);  // vtable slot 18
    virtual u32 getOnPacketFuncNum();  // vtable slot 19
    void sendBuffer();
    void onResolved(bool result, MtNetIpAddress& ipAddress);
    virtual void onConnected(bool result);  // vtable slot 20
    // Address: 0x01a608b0 - 0x01a608b1 (1 bytes)
    virtual void onDisconnectedByPeer(s32 aMtNetError) {}  // vtable slot 21
    // Address: 0x01a608c0 - 0x01a608c1 (1 bytes)
    virtual void onSocketError(s32 aMtNetError) {}  // vtable slot 22
    virtual void onHandshakeDone(bool result);  // vtable slot 23
    void Send(char* pBuf, DWORD dwSize);
    cSeedServerStream& readStream();
    cSeedServerStream& pendingStream();
    bool garbageReadStream(bool isHalf);
    void controlReadStream();
    eConnStatus getStatus() const;
    static MT_CTSTR getStatusName(eConnStatus aStatus);
    MT_CTSTR getStatusName();
    bool isEnableCipher();
    void setIsEnableCipher(bool flag);
    void getCommonKey(char* output);
    void setCommonKey(char* src);
    bool isHaveCommonKey();
    void clearCommonKey();
    u32 cryptCamellia(u8* dst, u8* src, u32 size, char* pKey);
    u32 decryptCamellia(u8* dst, u8* src, u32 size, char* pKey);
    virtual bool isNoCipher(u16 command);  // vtable slot 24
    virtual u32 getHandShakeSendCommandNo();  // vtable slot 25
    virtual u32 getHandShakeRecvCommandNo();  // vtable slot 26
    virtual u32 getLogoutRecvCommandNo();  // vtable slot 27
    virtual bool isCarryOver(u32 command);  // vtable slot 28
    bool isExit();
    void setIsExit(bool flag);
protected:
    void setStatus(eConnStatus status);
    u32 readHeader(cSeedServerStream&, stPacketHeader&);
    u32 getPacketSize(u8* in);
    u32 getPacketSize(cSeedServerStream& in);
    void writePacketSize(u16* out, u16 size);
    bool getApendErrorMessage(CPacket* pPacket, MtString& str);
public:
    cCalcBps* getSendBps();
    cCalcBps* getRecvBps();
private:
    void getCommonKeyPrivate(MT_CHAR* output) const;
    void setCommonKeyPrivate(const MT_CHAR* NewValue);
    bool isEnableCipherPrivate() const;
    void setEnableCipherPrivate(bool NewValue);
private:
    bool mIsExit;  // offset: 0x8
    bool mIsReadStreamHalf;  // offset: 0x9
    f32 mReadStreamHalfTimer;  // offset: 0xc
protected:
    MtCriticalSection mCS;  // offset: 0x10
    MtNetSocket* mpSocket;  // offset: 0x18
    cSeedServerStream* mpReadStream;  // offset: 0x20
    cSeedServerStream mPendingStream;  // offset: 0x28
    MtThread* mpResolver;  // offset: 0x50
    MtNetAddress mPeerAddress;  // offset: 0x58
private:
    eConnStatus mConnStatus;  // offset: 0x60
    MtNetTime::Total mSendBlockStartTime;  // offset: 0x68
    cCalcBps mSendBps;  // offset: 0x70
    cCalcBps mRecvBps;  // offset: 0xa8
    cGuardData mGuardData;  // offset: 0xe0
public:
    static MyDTI DTI;
};
