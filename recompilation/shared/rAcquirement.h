#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "cUIObject.h"
#include "rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtObject;

// Declarations
namespace rAcquirement { class cSkillLevelData; }
namespace rAcquirement { class cCustomSkillData; }
namespace rAcquirement { class cNormalSkillData; }
namespace rAcquirement { class cAbilityLevelData; }
namespace rAcquirement { class cAbilityData; }
namespace rAcquirement { class cAbilityAddData; }
namespace rAcquirement { class rCustomSkillData; }
namespace rAcquirement { class rNormalSkillData; }
namespace rAcquirement { class rAbilityData; }
namespace rAcquirement { class rAbilityAddData; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

namespace rAcquirement {

    // Forward declarations
    class cSkillLevelData;
    class cCustomSkillData;
    class cNormalSkillData;
    class cAbilityLevelData;
    class cAbilityData;
    class cAbilityAddData;
    class rCustomSkillData;
    class rNormalSkillData;
    class rAbilityData;
    class rAbilityAddData;

    class cSkillLevelData : public ::cUIResource
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
        cSkillLevelData();
        void load(MtDataReader& r);
    public:
        u16 mMsgExpIndex;  // offset: 0x8
        u16 mNeedLv;  // offset: 0xa
        u32 mNeedJp;  // offset: 0xc
        static MyDTI DTI;
    };

    class cCustomSkillData : public ::cUIResource
    {
    public:
        enum
        {
            DATA_VERSION = 1,
        };
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
        cCustomSkillData();
    public:
        u16 mId;  // offset: 0x8
        u16 mMsgNameIndex;  // offset: 0xa
        u16 mIconId;  // offset: 0xc
        MtTypedArray<rAcquirement::cSkillLevelData> mLvArray;  // offset: 0x10
        static MyDTI DTI;
    };

    class cNormalSkillData : public ::cUIResource
    {
    public:
        enum
        {
            DATA_VERSION = 5,
        };
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
        cNormalSkillData();
    public:
        u32 mNeedJp;  // offset: 0x8
        u16 mNeedLv;  // offset: 0xc
        u16 mSkillNo;  // offset: 0xe
        u16 mIconId;  // offset: 0x10
        u8 mIndex;  // offset: 0x12
        u8 mMsgIndex;  // offset: 0x13
        u8 mCategory;  // offset: 0x14
        u8 mPreSkillIndex;  // offset: 0x15
        u8 mSlotNo;  // offset: 0x16
        static MyDTI DTI;
    };

    class cAbilityLevelData : public ::cUIResource
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
        cAbilityLevelData();
        void load(MtDataReader& r);
    public:
        u16 mNeedLv;  // offset: 0x8
        u32 mNeedJp;  // offset: 0xc
        static MyDTI DTI;
    };

    class cAbilityData : public ::cUIResource
    {
    public:
        enum
        {
            DATA_VERSION = 3,
        };
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
        cAbilityData();
    public:
        u16 mId;  // offset: 0x8
        u16 mMsgNameIndex;  // offset: 0xa
        u16 mMsgExpIndex;  // offset: 0xc
        u16 mIconId;  // offset: 0xe
        u16 mCost;  // offset: 0x10
        u16 mSortNo;  // offset: 0x12
        bool mIsPawnDisable;  // offset: 0x14
        static MyDTI DTI;
    };

    class cAbilityAddData : public ::cUIResource
    {
    public:
        enum
        {
            DATA_VERSION = 1,
        };
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
        cAbilityAddData();
    public:
        u16 mId;  // offset: 0x8
        u8 mSortCategory;  // offset: 0xa
        MtTypedArray<rAcquirement::cAbilityLevelData> mLvArray;  // offset: 0x10
        static MyDTI DTI;
    };

    class rCustomSkillData : public ::rTbl2<rAcquirement::cCustomSkillData>
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
        virtual bool loadData(MtDataReader& r, rAcquirement::cCustomSkillData* pData);  // vtable slot 16
        virtual MT_CTSTR getExt() const;  // vtable slot 7
        virtual u32 getDataVersion() const;  // vtable slot 20
    public:
        static MyDTI DTI;
    };

    class rNormalSkillData : public ::rTbl2<rAcquirement::cNormalSkillData>
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
        virtual bool loadData(MtDataReader& r, rAcquirement::cNormalSkillData* pData);  // vtable slot 16
        virtual MT_CTSTR getExt() const;  // vtable slot 7
        virtual u32 getDataVersion() const;  // vtable slot 20
    public:
        static MyDTI DTI;
    };

    class rAbilityData : public ::rTbl2<rAcquirement::cAbilityData>
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
        virtual bool loadData(MtDataReader& r, rAcquirement::cAbilityData* pData);  // vtable slot 16
        virtual MT_CTSTR getExt() const;  // vtable slot 7
        virtual u32 getDataVersion() const;  // vtable slot 20
    public:
        static MyDTI DTI;
    };

    class rAbilityAddData : public ::rTbl2<rAcquirement::cAbilityAddData>
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
        virtual bool loadData(MtDataReader& r, rAcquirement::cAbilityAddData* pData);  // vtable slot 16
        virtual MT_CTSTR getExt() const;  // vtable slot 7
        virtual u32 getDataVersion() const;  // vtable slot 20
    public:
        static MyDTI DTI;
    };

}  // namespace rAcquirement

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline rAcquirement::cSkillLevelData::cSkillLevelData() {
    // inferred: the base constructor inlined with no DWARF copy left no code: cUIResource() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->mMsgExpIndex = static_cast<u16>(0);
    this->mNeedLv = static_cast<u16>(0);
    this->mNeedJp = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline rAcquirement::cCustomSkillData::cCustomSkillData() {
    // inferred: the base constructor inlined with no DWARF copy left no code: cUIResource() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->mId = static_cast<u16>(0);
    this->mMsgNameIndex = static_cast<u16>(0);
    this->mIconId = static_cast<u16>(0);
    this->mLvArray.::MtArray::mAutoDelete = true;
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline rAcquirement::cNormalSkillData::cNormalSkillData() {
    // inferred: the base constructor inlined with no DWARF copy left no code: cUIResource() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->mSlotNo = static_cast<u8>(0);
    this->mCategory = static_cast<u8>(0);
    this->mPreSkillIndex = static_cast<u8>(0);
    this->mIconId = static_cast<u16>(0);
    this->mIndex = static_cast<u8>(0);
    this->mMsgIndex = static_cast<u8>(0);
    this->mNeedJp = static_cast<u32>(0);
    this->mNeedLv = static_cast<u16>(0);
    this->mSkillNo = static_cast<u16>(0);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline rAcquirement::cAbilityLevelData::cAbilityLevelData() {
    // inferred: the base constructor inlined with no DWARF copy left no code: cUIResource() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->mNeedLv = static_cast<u16>(0);
    this->mNeedJp = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline rAcquirement::cAbilityData::cAbilityData() {
    // inferred: the base constructor inlined with no DWARF copy left no code: cUIResource() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->mIsPawnDisable = false;
    this->mCost = static_cast<u16>(0);
    this->mSortNo = static_cast<u16>(0);
    this->mId = static_cast<u16>(0);
    this->mMsgNameIndex = static_cast<u16>(0);
    this->mMsgExpIndex = static_cast<u16>(0);
    this->mIconId = static_cast<u16>(0);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline rAcquirement::cAbilityAddData::cAbilityAddData() {
    // inferred: the base constructor inlined with no DWARF copy left no code: cUIResource() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->mId = static_cast<u16>(0);
    this->mSortCategory = static_cast<u8>(0);
    this->mLvArray.::MtArray::mAutoDelete = true;
}
