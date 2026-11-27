#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../../../MT/MtDTI.h"
#include "../../cPacket.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;

// Declarations
class CDataSwitchStorage;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class CDataSwitchStorage : public CPacketDataBase
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
    explicit CDataSwitchStorage();
    explicit CDataSwitchStorage(u8, u8);
public:
    u8 m_ucTargetStorageType;  // offset: 0x8
    u8 m_ucChangeStorageType;  // offset: 0x9
    static MyDTI DTI;
};

inline void* CDataSwitchStorage::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline CDataSwitchStorage::CDataSwitchStorage() {
    this->m_ucTargetStorageType = 0;
    this->m_ucChangeStorageType = 0;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../../../MT/MtMemoryAllocator.h"

inline MtAllocator* CDataSwitchStorage::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::CDataSwitchStorage::DTI);
}
