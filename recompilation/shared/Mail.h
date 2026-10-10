#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "Community.h"
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtString.h"
#include "cPacket.h"

// Forward declarations
class CDataCommunityCharacterBaseInfo;
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;

// Declarations
class CDataMailAttachmentInfo;
class CDataMailAttachmentList;
class CDataMailGPInfo;
class CDataMailInfo;
class CDataMailItemInfo;
class CDataMailLegendPawnInfo;
class CDataMailOptionCourseInfo;
class CDataMailTextInfo;

// Type aliases from DWARF
using CCommunityCharacterBaseInfo = CDataCommunityCharacterBaseInfo;
using CMailAttachmentInfo = CDataMailAttachmentInfo;
using CMailAttachmentList = CDataMailAttachmentList;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __int64_t = long int;
using __uint64_t = long unsigned int;
using b8 = bool;
using s64 = __int64_t;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class CDataMailAttachmentInfo : public CPacketDataBase
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
    explicit CDataMailAttachmentInfo();
    explicit CDataMailAttachmentInfo(u64, b8);
public:
    u64 m_ullAttachmentId;  // offset: 0x8
    b8 m_bIsReceived;  // offset: 0x10
    static MyDTI DTI;
};

class CDataMailGPInfo : public CPacketDataBase
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
    explicit CDataMailGPInfo();
    explicit CDataMailGPInfo(const CMailAttachmentInfo&, u32, u32);
public:
    CMailAttachmentInfo m_AttachmentInfo;  // offset: 0x8
    u32 m_unNum;  // offset: 0x20
    u32 m_unType;  // offset: 0x24
    static MyDTI DTI;
};

class CDataMailInfo : public CPacketDataBase
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
    explicit CDataMailInfo();
    explicit CDataMailInfo(u64, u8, u8, const CCommunityCharacterBaseInfo&, const char*, const char*, s64);
public:
    u64 m_ullId;  // offset: 0x8
    u8 m_ucState;  // offset: 0x10
    u8 m_ucItemState;  // offset: 0x11
    CCommunityCharacterBaseInfo m_BaseInfo;  // offset: 0x18
    MtString m_wstrSenderName;  // offset: 0x48
    MtString m_wstrMailText;  // offset: 0x50
    s64 m_llSenderDate;  // offset: 0x58
    static MyDTI DTI;
};

class CDataMailItemInfo : public CPacketDataBase
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
    explicit CDataMailItemInfo();
    explicit CDataMailItemInfo(const CMailAttachmentInfo&, u32, u16);
public:
    CMailAttachmentInfo m_AttachmentInfo;  // offset: 0x8
    u32 m_unItemId;  // offset: 0x20
    u16 m_usNum;  // offset: 0x24
    static MyDTI DTI;
};

class CDataMailLegendPawnInfo : public CPacketDataBase
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
    explicit CDataMailLegendPawnInfo();
    explicit CDataMailLegendPawnInfo(const CMailAttachmentInfo&, u32, const char*);
public:
    CMailAttachmentInfo m_AttachmentInfo;  // offset: 0x8
    u32 m_unPawnId;  // offset: 0x20
    MtString m_wstrName;  // offset: 0x28
    static MyDTI DTI;
};

class CDataMailOptionCourseInfo : public CPacketDataBase
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
    explicit CDataMailOptionCourseInfo();
    explicit CDataMailOptionCourseInfo(const CMailAttachmentInfo&, u32, u32, u32);
public:
    CMailAttachmentInfo m_AttachmentInfo;  // offset: 0x8
    u32 m_unOptionCourseId;  // offset: 0x20
    u32 m_unOptionCourseLineupId;  // offset: 0x24
    u32 m_unTime;  // offset: 0x28
    static MyDTI DTI;
};

class CDataMailAttachmentList : public CPacketDataBase
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
    explicit CDataMailAttachmentList();
    explicit CDataMailAttachmentList(const MtTypedArray<CDataMailItemInfo>&, const MtTypedArray<CDataMailGPInfo>&, const MtTypedArray<CDataMailOptionCourseInfo>&, const MtTypedArray<CDataMailLegendPawnInfo>&);
public:
    MtTypedArray<CDataMailItemInfo> m_ItemList;  // offset: 0x8
    MtTypedArray<CDataMailGPInfo> m_GPList;  // offset: 0x28
    MtTypedArray<CDataMailOptionCourseInfo> m_OptionCourseList;  // offset: 0x48
    MtTypedArray<CDataMailLegendPawnInfo> m_LegendPawnList;  // offset: 0x68
    static MyDTI DTI;
};

class CDataMailTextInfo : public CPacketDataBase
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
    explicit CDataMailTextInfo();
    explicit CDataMailTextInfo(const char*, const CMailAttachmentList&);
public:
    MtString m_wstrText;  // offset: 0x8
    CMailAttachmentList m_MailAttachmentList;  // offset: 0x10
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataMailAttachmentInfo::CDataMailAttachmentInfo() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_ullAttachmentId = static_cast<u64>(0);
    this->m_bIsReceived = false;
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataMailAttachmentList::CDataMailAttachmentList() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataMailGPInfo::CDataMailGPInfo() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_unNum = static_cast<u32>(0);
    this->m_unType = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataMailItemInfo::CDataMailItemInfo() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_unItemId = static_cast<u32>(0);
    this->m_usNum = static_cast<u16>(0);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataMailLegendPawnInfo::CDataMailLegendPawnInfo() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_unPawnId = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataMailOptionCourseInfo::CDataMailOptionCourseInfo() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->m_unOptionCourseId = static_cast<u32>(0);
    this->m_unOptionCourseLineupId = static_cast<u32>(0);
    this->m_unTime = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline CDataMailTextInfo::CDataMailTextInfo() {
    // inferred: the base constructor inlined with no DWARF copy left no code: CPacketDataBase() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
}
