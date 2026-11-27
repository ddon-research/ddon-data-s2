#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "Common.h"
#include "../../../../MT/MtCollection.h"
#include "../../../../MT/MtDTI.h"
#include "../../../../MT/MtString.h"
#include "../../cPacket.h"

// Forward declarations
class CDataCommonString;
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;

// Declarations
class CDataErrorMessage;
class CDataNGWordInfo;
class CDataSameLetterInfo;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using b8 = bool;
using size_t = _Sizet;
using u32 = unsigned int;

class CDataErrorMessage : public CPacketDataBase
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
    explicit CDataErrorMessage();
    explicit CDataErrorMessage(u32, u32, const char*, const char*);
public:
    u32 m_unMessageID;  // offset: 0x8
    u32 m_unErrorID;  // offset: 0xc
    MtString m_wstrMessage;  // offset: 0x10
    MtString m_wstrDevelopMessage;  // offset: 0x18
    static MyDTI DTI;
};

class CDataNGWordInfo : public CPacketDataBase
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
    explicit CDataNGWordInfo();
    explicit CDataNGWordInfo(const char*, b8, b8);
public:
    MtString m_wstrText;  // offset: 0x8
    b8 m_bIsName;  // offset: 0x10
    b8 m_bIsChat;  // offset: 0x11
    static MyDTI DTI;
};

class CDataSameLetterInfo : public CPacketDataBase
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
    explicit CDataSameLetterInfo();
    explicit CDataSameLetterInfo(const MtTypedArray<CDataCommonString>&);
public:
    MtTypedArray<CDataCommonString> m_SameLetterList;  // offset: 0x8
    static MyDTI DTI;
};

inline void* CDataErrorMessage::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline CDataErrorMessage::CDataErrorMessage() {
    this->m_unMessageID = 0;
    this->m_unErrorID = 0;
}

inline void* CDataNGWordInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline CDataNGWordInfo::CDataNGWordInfo() {
    this->m_bIsName = false;
    this->m_bIsChat = false;
}

inline void* CDataSameLetterInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline CDataSameLetterInfo::CDataSameLetterInfo() {
}

// Included after the classes: the generic bodies below need these complete.
#include "../../../../MT/MtMemoryAllocator.h"

inline MtAllocator* CDataErrorMessage::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::CDataErrorMessage::DTI);
}

inline MtAllocator* CDataNGWordInfo::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::CDataNGWordInfo::DTI);
}

inline MtAllocator* CDataSameLetterInfo::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::CDataSameLetterInfo::DTI);
}
