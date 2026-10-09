#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
class uGUIKeyConfig;

// Declarations
namespace nGUIKeyConfig { struct Key; }
namespace nGUIKeyConfig { class cCategoryListItems; }
namespace nGUIKeyConfig { class cInputEventHandler; }
namespace nGUIKeyConfig { class cKeyListItems; }

namespace nGUIKeyConfig {
    enum CATEGORY_STATE
    {
        CATEGORY_STATE_NONE = 0,
        CATEGORY_STATE_NO_OVERLAP = 1,
        CATEGORY_STATE_OVERLAPPED = 2,
    };
}  // namespace nGUIKeyConfig

namespace nGUIKeyConfig {
    enum KEY_STATE
    {
        KEY_STATE_POSSIBLE_OK = 0,
        KEY_STATE_POSSIBLE_NG = 1,
        KEY_STATE_IMPOSSIBLE_OK = 2,
        KEY_STATE_IMPOSSIBLE_NG = 3,
        KEY_STATE_POSSIBLE_OK_DIFFERED_FROM_CURRENT = 4,
        KEY_STATE_POSSIBLE_OK_DIFFERED_FROM_DEFAULT = 5,
    };
}  // namespace nGUIKeyConfig

namespace nGUIKeyConfig {
    enum SORT_TYPE
    {
        SORT_TYPE_NUMBER = 0,
        SORT_TYPE_KEY = 1,
        SORT_TYPE_NUM = 2,
    };
}  // namespace nGUIKeyConfig

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using s32 = int;
using u16 = unsigned short;
using u32 = unsigned int;

namespace nGUIKeyConfig {
    struct Key
    {
    public:
        Key();
        Key(const nGUIKeyConfig::Key& other);
        bool isValid() const;
        bool isMouse() const;
        bool isShift() const;
        bool isCtrl() const;
        bool isAlt() const;
        bool isModifier() const;
        void setBlank();
        bool operator==(nGUIKeyConfig::Key other) const;
        bool operator!=(nGUIKeyConfig::Key other) const;
    public:
        u16 mType;  // offset: 0x0
        u16 mFlags;  // offset: 0x2
    };
}  // namespace nGUIKeyConfig

namespace nGUIKeyConfig {
    class cCategoryListItems
    {
    public:
        cCategoryListItems();
        virtual ~cCategoryListItems() {}
        virtual u32 getItemNum() const = 0;  // vtable slot 2
        virtual MT_CTSTR getName(u32) const = 0;  // vtable slot 3
        virtual nGUIKeyConfig::CATEGORY_STATE getState(u32) const = 0;  // vtable slot 4
    };
}  // namespace nGUIKeyConfig

namespace nGUIKeyConfig {
    class cInputEventHandler
    {
    public:
        cInputEventHandler();
        virtual ~cInputEventHandler() {}
        virtual void onClose(uGUIKeyConfig& guiKeyConfig);  // vtable slot 2
        virtual void onInitialize(uGUIKeyConfig& guiKeyConfig, u32 categoryListIndex);  // vtable slot 3
        virtual void onBlankAll(uGUIKeyConfig& guiKeyConfig, u32 categoryListIndex);  // vtable slot 4
        virtual void onUndo(uGUIKeyConfig& guiKeyConfig, u32 categoryListIndex, u32 keyListIndex, nGUIKeyConfig::Key key);  // vtable slot 5
        virtual void onApply(uGUIKeyConfig& guiKeyConfig, u32 categoryListIndex);  // vtable slot 6
        virtual void onChangeCategory(uGUIKeyConfig& guiKeyConfig, u32 categoryListIndex);  // vtable slot 7
        virtual void onChangeKey(uGUIKeyConfig& guiKeyConfig, u32 categoryListIndex, u32 keyListIndex, nGUIKeyConfig::Key key);  // vtable slot 8
        virtual void onChangeSortType(uGUIKeyConfig& guiKeyConfig, nGUIKeyConfig::SORT_TYPE sortType);  // vtable slot 9
        virtual void onKeyListSubMenu(uGUIKeyConfig& guiKeyConfig, u32 categoryListIndex, u32 keyListIndex);  // vtable slot 10
        virtual void onCategoryListSubMenu(uGUIKeyConfig& guiKeyConfig, u32 categoryListIndex);  // vtable slot 11
    };
}  // namespace nGUIKeyConfig

namespace nGUIKeyConfig {
    class cKeyListItems
    {
    public:
        cKeyListItems();
        virtual ~cKeyListItems() {}
        virtual MT_CTSTR getGroupName(s32) const = 0;  // vtable slot 2
        virtual u32 getItemNum(u32) const = 0;  // vtable slot 3
        virtual s32 getGroupId(u32, u32) const = 0;  // vtable slot 4
        virtual s32 getSerialNumber(u32, u32) const = 0;  // vtable slot 5
        virtual nGUIKeyConfig::Key getKey(u32, u32) const = 0;  // vtable slot 6
        virtual MT_CTSTR getDetail(u32, u32) const = 0;  // vtable slot 7
        virtual nGUIKeyConfig::KEY_STATE getState(u32, u32) const = 0;  // vtable slot 8
        virtual s32 getOverlapSerialNumber(u32, u32) const = 0;  // vtable slot 9
        virtual u32 getOption(u32, u32) const = 0;  // vtable slot 10
    };
}  // namespace nGUIKeyConfig
