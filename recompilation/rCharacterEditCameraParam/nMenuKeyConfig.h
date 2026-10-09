#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "nGUIKeyConfig.h"
#include "../shared/nKeyCustom.h"

// Forward declarations
class cKeyCustom;
class cKeyCustomManager;
namespace nGUIKeyConfig { struct Key; }
namespace nKeyConfigTextTable { class cKeyText; }
class rGUIMessage;
class rKeyConfigTextTable;

// Declarations
namespace nMenuKeyConfig { class CategoryListItems; }
namespace nMenuKeyConfig { class KeyCustomManagers; }
namespace nMenuKeyConfig { class KeyListItems; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using s32 = int;
using u32 = unsigned int;

namespace nMenuKeyConfig {
    class CategoryListItems : public nGUIKeyConfig::cCategoryListItems
    {
    public:
        CategoryListItems(nMenuKeyConfig::KeyCustomManagers& keyCustomManagers, nMenuKeyConfig::KeyCustomManagers* baseKeyCustomManagers);
        // Address: 0x01980ac0 - 0x01980ac1 (1 bytes)
        virtual ~CategoryListItems() {}
        virtual u32 getItemNum() const;  // vtable slot 2
        virtual MT_CTSTR getName(u32 itemIndex) const;  // vtable slot 3
        virtual nGUIKeyConfig::CATEGORY_STATE getState(u32 itemIndex) const;  // vtable slot 4
    private:
        nMenuKeyConfig::KeyCustomManagers& mKeyCustomManagers;  // offset: 0x8
        nMenuKeyConfig::KeyCustomManagers* mBaseKeyCustomManagers;  // offset: 0x10
    };
}  // namespace nMenuKeyConfig

namespace nMenuKeyConfig {
    class KeyCustomManagers
    {
    public:
        KeyCustomManagers();
        ~KeyCustomManagers();
        void init();
        void init(const nMenuKeyConfig::KeyCustomManagers& source);
        void release();
        void apply(u32 categoryNo, const nMenuKeyConfig::KeyCustomManagers& source, u32 sourceCategoryNo);
        void apply(u32 categoryNo, const nMenuKeyConfig::KeyCustomManagers& source);
        void apply(const nMenuKeyConfig::KeyCustomManagers& source);
        bool isExistChange(bool isCheckName) const;
        bool isExistChange(u32 categoryNo, bool isCheckName) const;
        bool isExistChange(const nMenuKeyConfig::KeyCustomManagers* source, bool isCheckName) const;
        bool isExistChange(u32 categoryNo, const nMenuKeyConfig::KeyCustomManagers* source, bool isCheckName) const;
        bool isExistOverlap() const;
        bool isExistOverlap(u32 categoryNo) const;
        void setBlank(u32 categoryNo, nKeyCustom::KB_CUSTOM keyCustom);
        void restore(u32 categoryNo, nKeyCustom::KB_CUSTOM keyCustom);
        void setDefault(u32 categoryNo, nKeyCustom::KB_CUSTOM keyCustom);
        cKeyCustomManager* getManager(u32 categoryNo) const;
        cKeyCustom* getData(u32 categoryNo, nKeyCustom::KB_CUSTOM keyCustom) const;
        MT_CTSTR getName(u32 categoryNo) const;
        void setName(u32 categoryNo, MT_CTSTR name);
    private:
        cKeyCustomManager* mKeyCustomManagers[3];  // offset: 0x0
    };
}  // namespace nMenuKeyConfig

namespace nMenuKeyConfig {
    class KeyListItems : public nGUIKeyConfig::cKeyListItems
    {
    public:
        KeyListItems(nMenuKeyConfig::KeyCustomManagers& keyCustomManagers, const rGUIMessage* resMsgGroup, const rGUIMessage* resMsgDetail, const rKeyConfigTextTable* resTextTable);
        // Address: 0x01980ae0 - 0x01980ae1 (1 bytes)
        virtual ~KeyListItems() {}
        virtual MT_CTSTR getGroupName(s32 groupId) const;  // vtable slot 2
        virtual u32 getItemNum(u32 categoryListIndex) const;  // vtable slot 3
        virtual s32 getGroupId(u32 itemIndex, u32 categoryListIndex) const;  // vtable slot 4
        virtual s32 getSerialNumber(u32 itemIndex, u32 categoryListIndex) const;  // vtable slot 5
        virtual nGUIKeyConfig::Key getKey(u32 itemIndex, u32 categoryListIndex) const;  // vtable slot 6
        virtual MT_CTSTR getDetail(u32 itemIndex, u32 categoryListIndex) const;  // vtable slot 7
        virtual nGUIKeyConfig::KEY_STATE getState(u32 itemIndex, u32 categoryListIndex) const;  // vtable slot 8
        virtual s32 getOverlapSerialNumber(u32 itemIndex, u32 categoryListIndex) const;  // vtable slot 9
        virtual u32 getOption(u32 itemIndex, u32 categoryListIndex) const;  // vtable slot 10
        const nKeyConfigTextTable::cKeyText* getKeyText(u32 itemIndex) const;
        nKeyCustom::KB_CUSTOM getKeyCustom(u32 itemIndex) const;
        cKeyCustom* getKeyCustomData(u32 itemIndex, u32 categoryListIndex) const;
    private:
        nMenuKeyConfig::KeyCustomManagers& mKeyCustomManagers;  // offset: 0x8
        const rGUIMessage* mResMsgGroup;  // offset: 0x10
        const rGUIMessage* mResMsgDetail;  // offset: 0x18
        const rKeyConfigTextTable* mResTextTable;  // offset: 0x20
    };
}  // namespace nMenuKeyConfig
