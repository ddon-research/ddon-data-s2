#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
class cContextCharacter;

// Declarations
namespace nObjCondition { struct stHolyAbsorpReqInfo; }
namespace nObjCondition { struct stHolyAbsorpReqMsg; }
namespace nObjCondition { struct stOcdActiveInfo; }
namespace nObjCondition { struct stOcdActiveMsg; }

namespace nObjCondition {
    enum OCD_BAD_TYPE
    {
        OCD_BAD_TYPE_INIT = 4097,
        OCD_BAD_POISON = 4097,
        OCD_BAD_SLOW = 4098,
        OCD_BAD_SLEEP = 4099,
        OCD_BAD_FAINT = 4100,
        OCD_BAD_WET = 4101,
        OCD_BAD_OIL = 4102,
        OCD_BAD_SEAL = 4103,
        OCD_BAD_CURSE = 4104,
        OCD_BAD_SOFT_BODY = 4105,
        OCD_BAD_STONE = 4106,
        OCD_BAD_GOLD = 4107,
        OCD_BAD_SPREAD = 4108,
        OCD_BAD_FREEZE = 4109,
        OCD_BAD_ELECTRIC = 4110,
        OCD_BAD_HOLY_ABSORP = 4111,
        OCD_BAD_BLIND = 4112,
        OCD_BAD_FIRE_DEF = 4113,
        OCD_BAD_ICE_DEF = 4114,
        OCD_BAD_ELECTRIC_DEF = 4115,
        OCD_BAD_HOLY_DEF = 4116,
        OCD_BAD_DARK_DEF = 4117,
        OCD_BAD_PHYS_ATK = 4118,
        OCD_BAD_PHYS_DEF = 4119,
        OCD_BAD_MGC_ATK = 4120,
        OCD_BAD_MGC_DEF = 4121,
        OCD_BAD_SLEEP_CHANCE_TIME = 4122,
        OCD_BAD_EROSION_LV1 = 4123,
        OCD_BAD_EROSION_LV2 = 4124,
        OCD_BAD_EROSION_LV3 = 4125,
        OCD_BAD_EROSION_LVMAX = 4126,
        OCD_BAD_ITEM_SEAL = 4127,
        OCD_BAD_TYPE_END = 4128,
    };
}  // namespace nObjCondition

// Type aliases from DWARF
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

namespace nObjCondition {
    struct stHolyAbsorpReqMsg
    {
        // inferred: cContextCharacter::clearAbsorpReqArray names cContextCharacter::mAbsorpReqArray[0].mReqMsg.mAtkUID
        friend class ::cContextCharacter;
    public:
        stHolyAbsorpReqMsg();
        void clear();
        void copy(const nObjCondition::stHolyAbsorpReqMsg& msg);
        void setAtkUID(u32 atkUID);
        void setDfdUID(u32 dfdUID);
        void setHealVal(u16 heal);
        u32 getAtkUID() const;
        u32 getDfdUID() const;
        u16 getHealVal() const;
    private:
        u32 mAtkUID;  // offset: 0x0
        u32 mDfdUID;  // offset: 0x4
        u16 mHealVal;  // offset: 0x8
    };
}  // namespace nObjCondition

namespace nObjCondition {
    struct stOcdActiveInfo
    {
    public:
        stOcdActiveInfo();
        void reset();
        void copy(const nObjCondition::stOcdActiveInfo&);
    public:
        u8 mBank;  // offset: 0x0
        u8 mIndex;  // offset: 0x1
        u8 mActiveLv;  // offset: 0x2
        u8 mImmuneLv;  // offset: 0x3
    };
}  // namespace nObjCondition

namespace nObjCondition {
    struct stOcdActiveMsg
    {
    public:
        stOcdActiveMsg();
        void copy(const nObjCondition::stOcdActiveMsg& src);
        void reset();
        void setOcdActiveMsg(const nObjCondition::stOcdActiveMsg& src);
        void clearStandby();
    public:
        u8 mOcdUIDMsg;  // offset: 0x0
        u8 mOcdActiveLvMsg;  // offset: 0x1
        bool mIsStandby;  // offset: 0x2
    };
}  // namespace nObjCondition

namespace nObjCondition {
    struct stHolyAbsorpReqInfo
    {
        // inferred: cContextCharacter::getAbsorpReqNum names cContextCharacter::mAbsorpReqArray[0].mIsSeted
        friend class ::cContextCharacter;
    public:
        stHolyAbsorpReqInfo();
        void clear();
        void setReqMsg(const nObjCondition::stHolyAbsorpReqMsg& msg);
        const nObjCondition::stHolyAbsorpReqMsg& getReqMsg() const;
        bool isSeted() const;
    private:
        nObjCondition::stHolyAbsorpReqMsg mReqMsg;  // offset: 0x0
        bool mIsSeted;  // offset: 0xc
    };
}  // namespace nObjCondition
