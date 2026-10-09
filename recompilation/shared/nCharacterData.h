#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
class BitReader;
class BitWriter;
class cItemParam;

// Declarations
namespace nCharacterData { struct stCharacterName; }
namespace nCharacterData { struct stChatCstmCh; }
namespace nCharacterData { struct stEquipData; }
namespace nCharacterData { struct stItemParam; }
namespace nCharacterData { struct stMessageSet; }

namespace nCharacterData {
    enum ARROW_EQUIP
    {
        ARROW_EQUIP_NONE = 0,
        ARROW_EQUIP_1 = 1,
        ARROW_EQUIP_2 = 2,
        ARRWO_EQUIP_NUM = 2,
    };
}  // namespace nCharacterData

namespace nCharacterData {
    enum EQUIP_CATEGORY
    {
        EQUIP_CATEGORY_TOP = 0,
        EQUIP_CATEGORY_WEP_MAIN = 1,
        EQUIP_CATEGORY_WEP_SUB = 2,
        EQUIP_CATEGORY_ARMOR_HELM = 3,
        EQUIP_CATEGORY_ARMOR_BODY = 4,
        EQUIP_CATEGORY_WEAR_BODY = 5,
        EQUIP_CATEGORY_ARMOR_ARM = 6,
        EQUIP_CATEGORY_ARMOR_LEG = 7,
        EQUIP_CATEGORY_WEAR_LEG = 8,
        EQUIP_CATEGORY_ACCESSORY = 9,
        EQUIP_CATEGORY_JEWELRY = 10,
        EQUIP_CATEGORY_LANTERN = 11,
        EQUIP_CATEGORY_COSTUME = 12,
        EQUIP_CATEGORY_END = 13,
    };
}  // namespace nCharacterData

namespace nCharacterData {
    enum EQUIP_SLOT_TYPE
    {
        EQUIP_SLOT_TYPE_START = 0,
        EQUIP_SLOT_WEAPON_TOP = 1,
        EQUIP_SLOT_WEP_MAIN = 1,
        EQUIP_SLOT_WEP_SUB = 2,
        EQUIP_SLOT_WEP_END = 3,
        EQUIP_SLOT_PROTECTOR_TOP = 3,
        EQUIP_SLOT_ARMOR_HELM = 3,
        EQUIP_SLOT_ARMOR_BODY = 4,
        EQUIP_SLOT_WEAR_BODY = 5,
        EQUIP_SLOT_ARMOR_ARM = 6,
        EQUIP_SLOT_ARMOR_LEG = 7,
        EQUIP_SLOT_WEAR_LEG = 8,
        EQUIP_SLOT_ACCESSORY = 9,
        EQUIP_SLOT_JEWELRY1 = 10,
        EQUIP_SLOT_JEWELRY2 = 11,
        EQUIP_SLOT_JEWELRY3 = 12,
        EQUIP_SLOT_JEWELRY4 = 13,
        EQUIP_SLOT_JEWELRY5 = 14,
        EQUIP_SLOT_LANTERN = 15,
        EQUIP_SLOT_PROTECTOR_END = 16,
        EQUIP_SLOT_TYPE_NUM = 16,
        EQUIP_SLOT_JOB_START = 17,
        EQUIP_SLOT_JOB_ITEM_A = 17,
        EQUIP_SLOT_JOB_ITEM_B = 18,
        EQUIP_SLOT_JOB_END = 19,
        EQUIP_SLOT_TYPE_END = 19,
    };
}  // namespace nCharacterData

namespace nCharacterData {
    enum EQUIP_TYPE
    {
        EQUIP_TYPE_PERFORMANCE = 0,
        EQUIP_TYPE_VISUAL = 1,
        EQUIP_TYPE_NUM = 2,
    };
}  // namespace nCharacterData

namespace nCharacterData {
    enum FLAG_BIT
    {
        FLAG_IS_EQUIP = 0,
        FLAG_IS_NOT_CALC = 1,
        FLAG_MAX = 2,
    };
}  // namespace nCharacterData

namespace nCharacterData {
    enum ITEM_BAG_TYPE
    {
        ITEM_BAG_TYPE_STORAGE = 0,
        ITEM_BAG_TYPE_PL = 1,
        ITEM_BAG_TYPE_EX_STORAGE = 2,
        ITEM_BAG_TYPE_TEMPORARY = 3,
        ITEM_BAG_TYPE_POST = 4,
        ITEM_BAG_TYPE_BAGGAGE_FREE = 5,
        ITEM_BAG_TYPE_BAGGAGE_RENTAL01 = 6,
        ITEM_BAG_TYPE_MAX = 7,
    };
}  // namespace nCharacterData

namespace nCharacterData {
    enum MESSAGE_LINK
    {
        MESSAGE_LINK_PAD_UP = 0,
        MESSAGE_LINK_PAD_DOWN = 1,
        MESSAGE_LINK_PAD_LEFT = 2,
        MESSAGE_LINK_PAD_RIGHT = 3,
        MESSAGE_LINK_DUMMY04 = 4,
        MESSAGE_LINK_DUMMY05 = 5,
        MESSAGE_LINK_DUMMY06 = 6,
        MESSAGE_LINK_DUMMY07 = 7,
        MESSAGE_LINK_DUMMY08 = 8,
        MESSAGE_LINK_DUMMY09 = 9,
        MESSAGE_LINK_DUMMY10 = 10,
        MESSAGE_LINK_DUMMY11 = 11,
        MESSAGE_LINK_DUMMY12 = 12,
        MESSAGE_LINK_DUMMY13 = 13,
        MESSAGE_LINK_DUMMY14 = 14,
        MESSAGE_LINK_DUMMY15 = 15,
        MESSAGE_LINK_MAX = 16,
    };
}  // namespace nCharacterData

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

namespace nCharacterData {
    struct stCharacterName
    {
    public:
        void clearName();
        MT_CTSTR getFirstName() const;
        MT_CTSTR getLastName() const;
        void setFirstName(MT_CTSTR setName);
        void setLastName(MT_CTSTR setName);
        void setName(const nCharacterData::stCharacterName& name);
        nCharacterData::stCharacterName& operator=(const nCharacterData::stCharacterName& source);
    public:
        MT_CHAR mFirstName[13];  // offset: 0x0
        MT_CHAR mLastName[9];  // offset: 0xd
    };
}  // namespace nCharacterData

namespace nCharacterData {
    struct stChatCstmCh
    {
    public:
        bool serialize(BitWriter& w) const;
        bool deserialize(BitReader& r, u32 version, u32 releaseVersion);
        void copyData(const nCharacterData::stChatCstmCh& src);
    public:
        MT_CHAR mName[17];  // offset: 0x0
        u32 mBit;  // offset: 0x14
    };
}  // namespace nCharacterData

namespace nCharacterData {
    struct stEquipData
    {
    public:
        u8 getPresetMax() const;
        void setPresetMax(u8 num);
        u8 getPresetNum() const;
        void setPresetNum(u8 num);
        bool checkEquipVisual() const;
        void setEquipVisual(bool flag);
        bool checkHelmVisual() const;
        void setHelmVisualOff(bool flag);
        bool checkLanternVisual() const;
        void setLanternVisualOff(bool flag);
        u8 convEquipCateToIndex(nCharacterData::EQUIP_SLOT_TYPE category) const;
        u8 getCategoryType(u32 index);
        bool checkEquipCategory(nCharacterData::EQUIP_SLOT_TYPE category) const;
        void setDefaultData();
        void setEquipToItemParam(u8 category, cItemParam* pItemParam, u8 type);
        u32 getEquip(const u8 category, const u8 type) const;
        void setEquip(u8 category, u32 item, const u8 type);
        u32 getPreset(const u8 preset, const u8 category, const u8 type) const;
        void setPreset(u8 preset, u8 category, u32 item, const u8 type);
        u32 getElementParam(const u8 category, const u8 no, const u8 type) const;
        void setElementParam(u8 category, u32 item, u8 no, const u8 type);
        u32 getCraftParam(const u8 category, const u8 type) const;
        void setCraftParam(u8 category, u32 param, const u8 type);
        void setColor(u8 category, u32 param, u8 type);
        u32 getColor(const u8 category, u8 type) const;
        void setExp(u8 category, u32 exp, u8 type);
        u32 getExp(const u8 category, u8 type) const;
        void setJewelrySlotNum(u8 num);
        u8 getJewelrySlotNum() const;
        void setJobItem(u32 itemNo, nCharacterData::ARROW_EQUIP no);
        u32 getJobItem(nCharacterData::ARROW_EQUIP no) const;
        void copyData(const nCharacterData::stEquipData& src);
    public:
        u32 mEquip[2][15];  // offset: 0x0
        u32 mPreset[10][2][15];  // offset: 0x78
        u32 mElementParam[2][15][4];  // offset: 0x528
        u32 mCraftParam[2][15];  // offset: 0x708
        u32 mJobEquip[2];  // offset: 0x780
        u8 mColorNo[2][15];  // offset: 0x788
        u32 mExp[2][15];  // offset: 0x7a8
        u8 mPresetMax;  // offset: 0x820
        u8 mPresetNum;  // offset: 0x821
        bool mIsEquipVisual;  // offset: 0x822
        bool mIsHelmVisualOff;  // offset: 0x823
        bool mIsLanternVisualOff;  // offset: 0x824
        u8 mJewelrySlotNum;  // offset: 0x825
        static const nCharacterData::EQUIP_SLOT_TYPE mEquipTbl[15];
    };
}  // namespace nCharacterData

namespace nCharacterData {
    struct stItemParam
    {
        // inferred: cItemParam::getItemNum names cItemParam::mItemParam.mItemNum_Guard
        friend class ::cItemParam;
    public:
        u16 getItemNum() const;
        void setItemNum(u16 NewValue);
        bool serialize(BitWriter& w) const;
        bool deserialize(BitReader& r, u32 version);
        void setDefaultData();
        void addItem(u32 ItemNo, u32 ItemNum);
        bool getFlag(nCharacterData::FLAG_BIT bit) const;
        void onFlag(nCharacterData::FLAG_BIT bit);
        void offFlag(nCharacterData::FLAG_BIT);
    public:
        u32 mItemNo;  // offset: 0x0
    private:
        u16 mItemNum_Guard;  // offset: 0x4
    public:
        u16 mItemLocalNum;  // offset: 0x6
        u16 mKey;  // offset: 0x8
        u8 mFlag;  // offset: 0xa
    };
}  // namespace nCharacterData

namespace nCharacterData {
    struct stMessageSet
    {
    public:
        void copyData(const nCharacterData::stMessageSet& src, u32 version);
    public:
        MT_CHAR setName[97];  // offset: 0x0
        MT_CHAR message[10][97];  // offset: 0x61
        u32 mEmotion[10];  // offset: 0x42c
        bool mEmotToChat[10];  // offset: 0x454
    };
}  // namespace nCharacterData
