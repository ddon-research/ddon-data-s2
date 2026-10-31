#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtNetObject.h"

// Forward declarations
struct MtNetAddress;
struct MtNetIpAddress;

// Declarations
class MtNetSocket;

// Type aliases from DWARF
using s32 = int;

class MtNetSocket : public MtNetObject
{
public:
    enum
    {
        TYPE_NONE = 0,
        TYPE_TCP = 1,
        TYPE_UDP = 2,
        TYPE_SSL = 3,
    };
    enum
    {
        OPTION_NONE = 0,
        OPTION_TCP_NO_DELAY = 2,
    };
public:
    MtNetSocket();
    virtual ~MtNetSocket();
    virtual void setIpAddressAny(MtNetIpAddress*) = 0;  // vtable slot 11
    virtual bool isIpAddressAny(const MtNetIpAddress*) = 0;  // vtable slot 12
    virtual void setIpAddressBroadcast(MtNetIpAddress*) = 0;  // vtable slot 13
    virtual bool isIpAddressBroadcast(const MtNetIpAddress*) = 0;  // vtable slot 14
    virtual bool isEable() const = 0;  // vtable slot 15
    virtual void getInfoSelf(MtNetAddress*) const = 0;  // vtable slot 16
    virtual void getInfoPeer(MtNetAddress*) const = 0;  // vtable slot 17
    virtual s32 getType() const = 0;  // vtable slot 18
    virtual s32 startConnect(MtNetAddress*) = 0;  // vtable slot 19
    virtual s32 pollConnect() = 0;  // vtable slot 20
    virtual s32 listen(MtNetAddress*) = 0;  // vtable slot 21
    virtual s32 accept(MtNetSocket* *) = 0;  // vtable slot 22
    virtual s32 receive(MtNetAddress*, void*, s32) = 0;  // vtable slot 23
    virtual s32 send(const MtNetAddress*, const void*, s32) = 0;  // vtable slot 24
};
