#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtNetObject.h"

// Forward declarations
struct MtNetError;

// Declarations
namespace nDialog { struct stInfo; }

namespace nDialog {
    enum DLOG_ATTR
    {
        DLOG_ATTR_NONE = 0,
        DLOG_ATTR_TIMER_CLOSE = 1,
        DLOG_ATTR_PAUSE = 2,
        DLOG_ATTR_DEF_CURSOR_YES = 4,
        DLOG_ATTR_NETWORK_ERROR = 8,
        DLOG_ATTR_NET_SERVICE_ERROR = 16,
        DLOG_ATTR_CANCEL = 32,
        DLOG_ATTR_PL_NO_STOP = 64,
    };
}  // namespace nDialog

namespace nDialog {
    enum DLOG_PRIO
    {
        DLOG_PRIO_LOW = 0,
        DLOG_PRIO_NORMAL = 1,
        DLOG_PRIO_HIGH = 2,
        DLOG_PRIO_STORAGE = 3,
    };
}  // namespace nDialog

namespace nDialog {
    enum DLOG_TYPE
    {
        DLOG_TYPE_DISPONLY = 0,
        DLOG_TYPE_OK = 1,
        DLOG_TYPE_SEL2 = 2,
        DLOG_TYPE_SEL3 = 3,
        DLOG_TYPE_NUM = 4,
    };
}  // namespace nDialog

namespace nDialog {
    enum FUNC
    {
        FUNC_NONE = 0,
        FUNC_REQ = 1,
        FUNC_END = 2,
        FUNC_FASTEND = 3,
    };
}  // namespace nDialog

namespace nDialog {
    enum MSG_NO
    {
        MSG_NO_NET_ERR_CONTEXT_LOST = 0,
        MSG_NO_NET_ERR_LINK_STATE_INACTIVE = 1,
        MSG_NO_NET_ERR_CONTEXT_START_ABORT = 2,
        MSG_NO_NET_ERR_CONTEXT_START_FAIL = 3,
        MSG_NO_NET_ERR_DEFAULT_REQUEST = 4,
        MSG_NO_NET_ERR_DEFAULT_SERVICE = 5,
        MSG_NO_NET_ERR_DEFAULT_CONTEXT = 6,
        MSG_NO_SV_ERR_CONNECT_FAIL = 7,
        MSG_NO_SV_ERR_CONNECT_FAIL_LAUNCHER = 8,
        MSG_NO_SV_ERR_DISCONNECTED = 9,
        MSG_NO_SV_ERR_LOGIN_FAIL = 10,
        MSG_NO_SV_ERR_LOGIN_FAIL_LAUNCHER = 11,
        MSG_NO_SV_ERR_READ_PACKET = 12,
        MSG_NO_SV_ERR_TIMEOUT = 13,
        MSG_NO_SV_ERR_AFK_TIMEOUT = 14,
        MSG_NO_SV_ERR_DIFFERENT_VERSION = 15,
        MSG_NO_NET_ERR_NORET_CONTEXT_LOST = 16,
        MSG_NO_NET_ERR_NORET_LINK_STATE_INACTIVE = 17,
        MSG_NO_SV_ERR_NORET_DISCONNECTED = 18,
        MSG_NO_SV_ERR_NORET_READ_PACKET = 19,
        MSG_NO_SV_ERR_NORET_TIMEOUT = 20,
        MSG_NO_SV_ERR_NORET_AFK_TIMEOUT = 21,
        MSG_NO_NET_ERR_SUPPLEMENTARY_EXPLANATION = 22,
        MSG_NO_MAX = 23,
        MSG_NO_FREE = -1,
    };
}  // namespace nDialog

namespace nDialog {
    enum RESULT
    {
        RLT_NONE = 0,
        RLT_CONTINUE = 1,
        RLT_YES = 2,
        RLT_NO = 3,
        RLT_OK = 4,
        RLT_SEL_0 = 5,
        RLT_SEL_1 = 6,
        RLT_SEL_2 = 7,
        RLT_END = 8,
    };
}  // namespace nDialog

namespace nDialog {
    enum SEL_CUR
    {
        SEL_CUR_0 = 0,
        SEL_CUR_1 = 1,
        SEL_CUR_2 = 2,
        SEL_CUR_NUM = 3,
        SEL_CUR_ERR = 4,
    };
}  // namespace nDialog

namespace nDialog {
    enum STATE
    {
        STATE_NONE = 0,
        STATE_WAIT = 1,
        STATE_INIT = 2,
        STATE_OPEN = 3,
        STATE_MOVE = 4,
        STATE_CLOSE = 5,
        STATE_END = 6,
        STATE_CELL_START = 7,
        STATE_CELL_WAIT = 8,
        STATE_CELL_END = 9,
        STATE_NUM = 10,
    };
}  // namespace nDialog

// Type aliases from DWARF
using MT_CHAR = char;
using f32 = float;
using u32 = unsigned int;

namespace nDialog {
    struct stInfo
    {
    public:
        u32 id;  // offset: 0x0
        u32 handle;  // offset: 0x4
        nDialog::DLOG_TYPE type;  // offset: 0x8
        nDialog::STATE state;  // offset: 0xc
        f32 timer;  // offset: 0x10
        nDialog::MSG_NO msgNo;  // offset: 0x14
        nDialog::DLOG_ATTR attr;  // offset: 0x18
        nDialog::DLOG_PRIO prio;  // offset: 0x1c
        MtNetError netError;  // offset: 0x20
        nDialog::RESULT result;  // offset: 0x2c
        nDialog::FUNC function;  // offset: 0x30
        MT_CHAR str[256];  // offset: 0x34
        void(*pFuncYes)();  // offset: 0x138
        void(*pFuncNo)();  // offset: 0x140
        void(*pFuncOk)();  // offset: 0x148
        void(*pFuncSel0)();  // offset: 0x150
        void(*pFuncSel1)();  // offset: 0x158
        void(*pFuncSel2)();  // offset: 0x160
    };
}  // namespace nDialog
