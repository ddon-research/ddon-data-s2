#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "cUIObject.h"
#include "rTbl2.h"

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

inline nKeyConfigTextTable::cKeyText::cKeyText() {
    this->mKeyCustom = 0;
    this->mDetailMsgId = 0xFFFFFFFF;
    this->mSerialNumber = 0;
    this->mCustomSortNo = 0;
    this->mSortNo = 0;
    this->mGroupMsgId = 0;
}

inline rKeyConfigTextTable::rKeyConfigTextTable() {
}
