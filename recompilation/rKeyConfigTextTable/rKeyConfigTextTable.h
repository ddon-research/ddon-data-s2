#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/cUIObject.h"
#include "../shared/rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtObject;
namespace nMenuKeyConfig { class KeyListItems; }

// Declarations
namespace nKeyConfigTextTable { class cKeyText; }
class rKeyConfigTextTable;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
namespace nKeyConfigTextTable { using KeyTexts = MtTypedArray<nKeyConfigTextTable::cKeyText>; }
using size_t = _Sizet;
using u32 = unsigned int;

namespace nKeyConfigTextTable {
    class cKeyText : public ::cUIObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        cKeyText();
        // Address: 0x01a983f0 - 0x01a983f1 (1 bytes)
        virtual ~cKeyText() {}
        void copy(const nKeyConfigTextTable::cKeyText& other);
    public:
        u32 mKeyCustom;  // offset: 0x8
        u32 mDetailMsgId;  // offset: 0xc
        u32 mSortNo;  // offset: 0x10
        u32 mGroupMsgId;  // offset: 0x14
        u32 mSerialNumber;  // offset: 0x18
        u32 mCustomSortNo;  // offset: 0x1c
        static MyDTI DTI;
    };
}  // namespace nKeyConfigTextTable

class rKeyConfigTextTable : public rTbl2<nKeyConfigTextTable::cKeyText>
{
    // inferred: nMenuKeyConfig::KeyListItems::getItemNum names rKeyConfigTextTable::mSortedArray.::MtArray::mLength
    friend class nMenuKeyConfig::KeyListItems;
public:
    class MyDTI;
public:
    using Predicate = bool(*)(const nKeyConfigTextTable::cKeyText*, const nKeyConfigTextTable::cKeyText*, u32);
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
    rKeyConfigTextTable();
    virtual ~rKeyConfigTextTable();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
    virtual bool loadData(MtDataReader& r, nKeyConfigTextTable::cKeyText* data);  // vtable slot 16
    void createSortedArray();
    void sort(Predicate predicate);
    const nKeyConfigTextTable::KeyTexts& refSortedArray() const;
    const nKeyConfigTextTable::cKeyText* getSortedData(u32 index) const;
    void setCustomSortNo(u32 index, u32 customSortNo);
private:
    nKeyConfigTextTable::KeyTexts mSortedArray;  // offset: 0x80
public:
    static MyDTI DTI;
    static const u32 DATA_VERSION = 1;
};

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline nKeyConfigTextTable::cKeyText::cKeyText() {
    // inferred: the base constructor inlined with no DWARF copy left no code: cUIObject() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->mKeyCustom = static_cast<u32>(0);
    this->mDetailMsgId = static_cast<u32>(4294967295);
    this->mSerialNumber = static_cast<u32>(0);
    this->mCustomSortNo = static_cast<u32>(0);
    this->mSortNo = static_cast<u32>(0);
    this->mGroupMsgId = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline rKeyConfigTextTable::rKeyConfigTextTable() {
}
