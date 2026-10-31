#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtAllocator.h"

// Forward declarations
class MtAllocator;
class MtCipher;
class MtCriticalSection;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtDefaultAllocator;
namespace MtMemoryAllocator { class Initializer; }
namespace MtNet { namespace Utility { namespace PS4 { class Json; } } }
class MtObject;
class cGeneralPointPtr;
namespace nDraw { class IndexBuffer; }
namespace nDraw { class VertexBuffer; }
namespace nNetMsgData { namespace Head { struct stMsgHead; } }
namespace nNetwork { class Decoder; }
class rArchive;
class rEffect2D;
class rEffectAnim;
class rEffectList;
class rEffectStrip;
class rVibration;
class sBrowser;
class sItemManager;
class sMain;
class sRender;
class sScreenShot;
class uSoundOcclusion;

// Declarations
class MtMemory;

// Type aliases from DWARF
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

// Functions the classes below befriend, declared first
namespace MtMemoryAllocator { MtAllocator* getAllocator(const MtDTI& dti); }
namespace nNetMsgData { namespace Head { stMsgHead* deserialize(nNetwork::Decoder& dec); } }
namespace nNetMsgData { namespace Head { void freeData(stMsgHead* pData); } }

class MtMemory
{
    friend class MtCipher;
    friend class MtDataReader;
    friend class MtDataWriter;
    friend class MtMemoryAllocator::Initializer;
    friend MtAllocator* MtMemoryAllocator::getAllocator(const MtDTI& dti);
    friend class MtNet::Utility::PS4::Json;
    friend class MtObject;
    friend class cGeneralPointPtr;
    friend class nDraw::IndexBuffer;
    friend class nDraw::VertexBuffer;
    friend nNetMsgData::Head::stMsgHead* nNetMsgData::Head::deserialize(nNetwork::Decoder& dec);
    friend void nNetMsgData::Head::freeData(nNetMsgData::Head::stMsgHead* pData);
    friend class rArchive;
    friend class rEffect2D;
    friend class rEffectAnim;
    friend class rEffectList;
    friend class rEffectStrip;
    friend class rVibration;
    friend class sBrowser;
    friend class sItemManager;
    friend class sMain;
    friend class sRender;
    friend class sScreenShot;
    friend class uSoundOcclusion;
public:
    static void terminateAllocator();
    static u32 getAllocatorNum();
    static MtAllocator* getAllocatorIndex(u32 index);
    static MtAllocator* getAllocator(u32 alloc_type);
    static void setAllocator(u32 alloc_type, MtAllocator* p_alloc);
    static MtAllocator* getDefaultAllocator();
    static void* memAlloc(MtAllocator::TYPE type, size_t size);
    static void memFree(MtAllocator::TYPE type, void* ptr, void* misc);
    static size_t getTotalSize();
    static size_t getAvailSize();
    static size_t getAvailAllocatorSize();
    static void clear(void* padr, size_t size);
    static void clear128(void* padr, size_t size);
    static void set(void* padr, s32 value, size_t size);
    static void set128(void*, s32, size_t);
    static void copy(void* pdst, const void* psrc, size_t size);
    static void copy128(void*, const void*, size_t);
    static void move(void* pdst, const void* psrc, size_t size);
    static bool equal(const void* a, const void* b, size_t size);
private:
    static void attach(MtAllocator* pa);
    static void detach(MtAllocator* pa);
    MtMemory();
    ~MtMemory();
private:
    MtDefaultAllocator mDefaultAllocator;  // offset: 0x0
    static MtMemory mInstance;
    static MtCriticalSection mCS;
    static u32 mAllocatorNum;
    static MtAllocator* mpAllocator[64];
    static MtAllocator* mpAllocatorType[64];
    static u64 mMemoryLeakFlag;
};
