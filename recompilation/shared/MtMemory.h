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
class rEffect2D;
class rEffectStrip;
class rVibration;
class sItemManager;
class sRender;
class sScreenShot;

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
    // inferred: MtCipher::~MtCipher names MtMemory::mpAllocatorType
    friend class MtCipher;
    // inferred: MtDataReader::MtDataReader names MtMemory::mpAllocatorType
    friend class MtDataReader;
    // inferred: MtDataWriter::MtDataWriter names MtMemory::mpAllocatorType
    friend class MtDataWriter;
    // inferred: MtMemoryAllocator::Initializer::Initializer names MtMemory::mpAllocatorType
    friend class MtMemoryAllocator::Initializer;
    // inferred: MtMemoryAllocator::getAllocator names MtMemory::mpAllocatorType
    friend MtAllocator* MtMemoryAllocator::getAllocator(const MtDTI& dti);
    // inferred: MtNet::Utility::PS4::Json::allocate names MtMemory::mpAllocatorType
    friend class MtNet::Utility::PS4::Json;
    // inferred: MtObject::operator new names MtMemory::mpAllocatorType
    friend class MtObject;
    // inferred: cGeneralPointPtr::operator new[] names MtMemory::mpAllocatorType
    friend class cGeneralPointPtr;
    // inferred: nDraw::IndexBuffer::~IndexBuffer names MtMemory::mpAllocatorType
    friend class nDraw::IndexBuffer;
    // inferred: nDraw::VertexBuffer::~VertexBuffer names MtMemory::mpAllocatorType
    friend class nDraw::VertexBuffer;
    // inferred: nNetMsgData::Head::deserialize names MtMemory::mpAllocatorType
    friend nNetMsgData::Head::stMsgHead* nNetMsgData::Head::deserialize(nNetwork::Decoder& dec);
    // inferred: nNetMsgData::Head::freeData names MtMemory::mpAllocatorType
    friend void nNetMsgData::Head::freeData(nNetMsgData::Head::stMsgHead* pData);
    // inferred: rEffect2D::save names MtMemory::mpAllocatorType
    friend class rEffect2D;
    // inferred: rEffectStrip::load names MtMemory::mpAllocatorType
    friend class rEffectStrip;
    // inferred: rVibration::load names MtMemory::mpAllocatorType
    friend class rVibration;
    // inferred: sItemManager::releaseSortBinary names MtMemory::mpAllocatorType
    friend class sItemManager;
    // inferred: sRender::endScreenShot names MtMemory::mpAllocatorType
    friend class sRender;
    // inferred: sScreenShot::reset names MtMemory::mpAllocatorType
    friend class sScreenShot;
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
