#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
namespace nObjCondition { struct stOcdActiveInfo; }

// Declarations
namespace nObjCondition { struct stOcdActiveData; }

namespace nObjCondition {
    enum IMMUNE_BOOST_LV
    {
        IMMUNE_BOOST_LV_0 = 0,
        IMMUNE_BOOST_LV_1 = 1,
        IMMUNE_BOOST_LV_2 = 2,
        IMMUNE_BOOST_LV_3 = 3,
        IMMUNE_BOOST_LV_4 = 4,
        IMMUNE_BOOST_LV_5 = 5,
        IMMUNE_BOOST_LV_6 = 6,
        IMMUNE_BOOST_LV_7 = 7,
        IMMUNE_BOOST_LV_MAX = 7,
        IMMUNE_BOOST_LV_NUM = 8,
        IMMUNE_BOOST_LV_INVALID = 9,
    };
}  // namespace nObjCondition

namespace nObjCondition {
    enum OCD_IMMUNE_MODE
    {
        OCD_IMMUNE_MODE_NORMAL = 0,
        OCD_IMMUNE_MODE_BOOST = 1,
    };
}  // namespace nObjCondition

namespace nObjCondition {
    enum OCD_MODE
    {
        OCD_MODE_NONE = 0,
        OCD_MODE_ACTIVE = 1,
        OCD_MODE_NUM = 2,
    };
}  // namespace nObjCondition

namespace nObjCondition {
    enum OCD_MODE_REQ_RESULT
    {
        OCD_RESULT_NONE = 0,
        OCD_RESULT_INIT = 1,
        OCD_RESULT_INIT_AND_ACTION = 2,
        OCD_RESULT_INIT_FAILED = 3,
        OCD_RESULT_END = 4,
        OCD_RESULT_END_AND_ACTION = 5,
        OCD_RESULT_MULTI = 6,
        OCD_RESULT_TIME_END = 7,
        OCD_RESULT_TIME_END_AND_ACTION = 8,
    };
}  // namespace nObjCondition

namespace nObjCondition {
    enum OCD_REASON
    {
        OCD_REASON_NONE = 0,
        OCD_REASON_HIT = 1,
        OCD_REASON_SCROLL = 2,
        OCD_REASON_NUM = 3,
    };
}  // namespace nObjCondition

namespace nObjCondition {
    enum OCD_REQ_MODE
    {
        OCD_REQ_NONE = 0,
        OCD_REQ_INIT = 1,
        OCD_REQ_END = 2,
        OCD_REQ_MULTI = 3,
        OCD_REQ_TIME_END = 4,
    };
}  // namespace nObjCondition

namespace nObjCondition {
    enum OCD_SYSTEM_FLAG
    {
        SYSTEM_FLAG_SE_OFF = 1,
        SYSTEM_FLAG_EFF_OFF = 2,
        SYSTEM_FLAG_UI_OFF = 4,
        SYSTEM_FLAG_CYCLE_EFF_OFF = 8,
    };
}  // namespace nObjCondition

// Type aliases from DWARF
using u8 = unsigned char;

namespace nObjCondition {
    struct stOcdActiveData
    {
    public:
        stOcdActiveData();
        void reset(bool isImuneReset);
        void copy(const nObjCondition::stOcdActiveData& src, bool isImuneCopy);
        void setInfo(const nObjCondition::stOcdActiveInfo& info, bool isImmuneCopy);
    public:
        u8 mActiveLv;  // offset: 0x0
        u8 mImmuneLv;  // offset: 0x1
    };
}  // namespace nObjCondition
