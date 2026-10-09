#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtNetDevice.h"
#include "MtObject.h"
#include "MtStream.h"
#include "MtString.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtDTI;
class MtMemoryStream;
struct MtNetAddress;
class MtNetResolver;
class MtNetSocket;
class MtString;

// Declarations
class cWebsocketClient;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cWebsocketClient : public MtObject
{
public:
    enum wsState
    {
        WS_STATE_NONE = 0,
        WS_STATE_OPENING = 1,
        WS_STATE_HANDSHAKE = 2,
        WS_STATE_HANDSHAKE_WAIT = 3,
        WS_STATE_NORMAL = 4,
        WS_STATE_CLOSING = 5,
        WS_STATE_FATAL = 6,
    };
    enum wsFrameType
    {
        WS_EMPTY_FRAME = 240,
        WS_ERROR_FRAME = 241,
        WS_INCOMPLETE_FRAME = 242,
        WS_TEXT_FRAME = 1,
        WS_BINARY_FRAME = 2,
        WS_PING_FRAME = 9,
        WS_PONG_FRAME = 10,
        WS_OPENING_FRAME = 243,
        WS_CLOSING_FRAME = 8,
    };
public:
    class MyDTI;
    struct Handshake;
    class cListener;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct Handshake
    {
    public:
        s32 mStatusCode;  // offset: 0x0
        MT_CHAR mSecWebSocketAccept[128];  // offset: 0x4
    };
public:
    class cListener : public MtObject
    {
    public:
        virtual void onOpen(cWebsocketClient::Handshake handshake);  // vtable slot 6
        virtual void onMessage(MtString result);  // vtable slot 7
        virtual void onError(s32 code);  // vtable slot 8
        virtual void onClose();  // vtable slot 9
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
    cWebsocketClient();
    virtual ~cWebsocketClient();
    bool addListener(cListener* pListener);
    void removeListener(cListener* pListener);
    wsState getState();
    void init();
    void close();
    bool openHandshake(MT_CTSTR pUrl, MT_CTSTR key);
    void freeHandshake();
    bool send(char* pBuffer, size_t length, wsFrameType frameType);
    void move();
    void ping();
private:
    void wsMakeFrame(char* data, size_t dataLength, unsigned char* outFrame, size_t* outLength, wsFrameType frameType);
    wsFrameType wsParseInputFrame(char* inputFrame, size_t inputLength, char* * dataPtr, size_t* dataLength);
    void changeState(wsState state);
    bool parseUrl(MT_CTSTR pUrl);
    s32 parseResponseHeader(MT_CTSTR pBuffer, Handshake* pHeader);
    void connect();
    void handshake();
    void pong();
    void message(MT_CTSTR message);
    void error(s32 err_code);
private:
    wsState mWsState;  // offset: 0x8
    s32 mStateSub;  // offset: 0xc
    s32 mSocketLib;  // offset: 0x10
    MtNetSocket* mpSocket;  // offset: 0x18
    MtNetAddress mServerAddr;  // offset: 0x20
    MtNetResolver* mpResolver;  // offset: 0x28
    MtString mHeader;  // offset: 0x30
    MtString mUrl;  // offset: 0x38
    MT_CHAR mHostName[128];  // offset: 0x40
    MT_CHAR mPath[64];  // offset: 0xc0
    MtMemoryStream mStream;  // offset: 0x100
    Handshake mHandshake;  // offset: 0x128
    s32 mHandshakeSize;  // offset: 0x1ac
    MtArray mpListenerArray;  // offset: 0x1b0
    f32 mTimeOut;  // offset: 0x1d0
    MT_CHAR mNormalRecvBuff[16384];  // offset: 0x1d4
    u32 mNormalRecvSize;  // offset: 0x41d4
public:
    static MyDTI DTI;
};
