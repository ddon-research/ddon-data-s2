#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "cUIObject.h"
#include "nGUIMyRoom.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cFurniture;
class cFurnitureGroup;
class cFurnitureLayout;
class rFurnitureGroup;
class rFurnitureLayout;
class rGUIMessage;

// Declarations
namespace nFurnitureMenuFlow { struct FurnitureParam; }
namespace nFurnitureMenuFlow { class cElement; }
namespace nFurnitureMenuFlow { class cFurnitureGroupListItems; }
namespace nFurnitureMenuFlow { class cFurnitureListItems; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

namespace nFurnitureMenuFlow {
    struct FurnitureParam
    {
    public:
        MT_CTSTR mName;  // offset: 0x0
        u32 mItemId;  // offset: 0x8
        u32 mSortNo;  // offset: 0xc
        u32 mLayoutId;  // offset: 0x10
        bool mIsSet;  // offset: 0x14
    };
}  // namespace nFurnitureMenuFlow

namespace nFurnitureMenuFlow {
    class cElement : public ::cUIObject
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
        cElement();
        virtual ~cElement() {}
        virtual u32 getSortNo() const = 0;  // vtable slot 6
    public:
        static MyDTI DTI;
    };
}  // namespace nFurnitureMenuFlow

namespace nFurnitureMenuFlow {
    class cFurnitureGroupListItems : public nGUIMyRoom::cListItems
    {
    public:
        class cItem;
    public:
        class cItem : public nFurnitureMenuFlow::cElement
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
            cItem();
            cItem(u32 groupId, u32 sortNo, bool isDisable);
            virtual ~cItem();
            virtual u32 getSortNo() const;  // vtable slot 6
        public:
            u32 mGroupId;  // offset: 0x8
            u32 mSortNo;  // offset: 0xc
            bool mIsDisable;  // offset: 0x10
            static MyDTI DTI;
        };
    public:
        cFurnitureGroupListItems();
        virtual ~cFurnitureGroupListItems();
        void init(const cFurniture& furniture, rFurnitureGroup* furnitureGroups, rGUIMessage* furnitureGroupNames, rFurnitureLayout* furnitureLayouts, rGUIMessage* furnitureLayoutNames);
        void release();
        u32 getGroupId(u32 itemIndex) const;
        u32 getCameraNo(u32 itemIndex) const;
        virtual u32 getItemNum() const;  // vtable slot 2
        virtual MT_CTSTR getItemString(u32 itemIndex) const;  // vtable slot 3
        virtual bool isItemDisable(u32 itemIndex) const;  // vtable slot 4
    private:
        const cFurnitureGroup* getGroup(u32 groupId) const;
        static bool PredicateItem(const cItem* a, const cItem* b, u32 param);
    private:
        rFurnitureGroup* mFurnitureGroups;  // offset: 0x8
        rGUIMessage* mFurnitureGroupNames;  // offset: 0x10
        MtTypedArray<cItem> mItems;  // offset: 0x18
    };
}  // namespace nFurnitureMenuFlow

namespace nFurnitureMenuFlow {
    class cFurnitureListItems : public nGUIMyRoom::cPopupListItems
    {
    public:
        class cItem;
        class cInfo;
    public:
        class cInfo : public nFurnitureMenuFlow::cElement
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
            cInfo();
            cInfo(nFurnitureMenuFlow::FurnitureParam furnitureParam);
            virtual ~cInfo();
            virtual u32 getSortNo() const;  // vtable slot 6
        public:
            nFurnitureMenuFlow::FurnitureParam mParam;  // offset: 0x8
            static MyDTI DTI;
        };
    public:
        class cItem : public nFurnitureMenuFlow::cElement
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
            cItem();
            cItem(u32 layoutId, u32 sortNo);
            virtual ~cItem();
            virtual u32 getSortNo() const;  // vtable slot 6
        public:
            u32 mLayoutId;  // offset: 0x8
            u32 mSortNo;  // offset: 0xc
            MtTypedArray<nFurnitureMenuFlow::cFurnitureListItems::cInfo> mInfos;  // offset: 0x10
            static MyDTI DTI;
        };
    public:
        cFurnitureListItems();
        virtual ~cFurnitureListItems();
        void init(u32 furnitureGroupId, const cFurniture& furniture, rFurnitureLayout* furnitureLayouts, rGUIMessage* furnitureLayoutNames);
        void release();
        u32 getGroupId() const;
        u32 getItemId(u32 itemIndex, u32 itemListIndex) const;
        virtual u32 getItemNum() const;  // vtable slot 2
        virtual MT_CTSTR getItemString(u32 itemIndex) const;  // vtable slot 3
        virtual u32 getItemListIndex(u32 itemIndex) const;  // vtable slot 4
        virtual u32 getItemListSize(u32 itemIndex) const;  // vtable slot 5
        virtual MT_CTSTR getItemListString(u32 itemIndex, u32 itemListIndex) const;  // vtable slot 6
    private:
        const cFurnitureLayout* getLayout(u32 layoutId) const;
        const cItem* getItem(u32 itemIndex) const;
        bool getParam(nFurnitureMenuFlow::FurnitureParam& param, u32 itemIndex, u32 itemListIndex) const;
        void add(const nFurnitureMenuFlow::FurnitureParam& param);
        static bool PredicateInfo(const cInfo* a, const cInfo* b, u32 param);
        static bool PredicateItem(const cItem* a, const cItem* b, u32 param);
    private:
        u32 mGroupId;  // offset: 0x8
        rFurnitureLayout* mFurnitureLayouts;  // offset: 0x10
        rGUIMessage* mFurnitureLayoutNames;  // offset: 0x18
        MtTypedArray<cItem> mItems;  // offset: 0x20
    };
}  // namespace nFurnitureMenuFlow

// Inline, no code of its own: checked where it is inlined.
inline nFurnitureMenuFlow::cElement::cElement() {
}

// Inline, no code of its own: checked where it is inlined.
inline nFurnitureMenuFlow::cFurnitureGroupListItems::cItem::cItem() {
    this->mGroupId = static_cast<u32>(4294967295);
    this->mSortNo = static_cast<u32>(0);
    this->mIsDisable = false;
}
