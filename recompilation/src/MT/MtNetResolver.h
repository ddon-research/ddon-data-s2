#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtNetDevice.h"
#include "MtNetObject.h"

// Forward declarations
struct MtNetIpAddress;
class MtPropertyList;

// Declarations
class MtNetResolver;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using s32 = int;

class MtNetResolver : public MtNetObject
{
public:
    MtNetResolver(const MT_CTSTR name);
    virtual ~MtNetResolver();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    s32 check();
    void get(s32 index, MtNetIpAddress* address);
private:
    void nativeConstructor();
    void nativeDestructor();
    void nativeCreateProperty(MtPropertyList& s);
private:
    MT_CHAR mName[512];  // offset: 0x24
    MtNetIpAddress mAddress[4];  // offset: 0x224
    s32 mAddressNum;  // offset: 0x234
public:
    static const s32 MAX_SIZE_BUF_NAME = 512;
    static const s32 MAX_NUM_ADDRESS = 4;
};
