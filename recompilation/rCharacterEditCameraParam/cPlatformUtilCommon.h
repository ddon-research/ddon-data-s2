#pragma once

#include <cstdint>
#include <cstddef>

// Declarations
namespace nPlatformUtil { namespace nGameLiveStram { struct POSTYPE; } }
namespace nPlatformUtil { namespace nSharePlay { struct APPROVE_MODE; } }
namespace nPlatformUtil { namespace nSharePlay { struct CONTROLLER_MODE; } }
namespace nPlatformUtil { namespace nSharePlay { struct STATUS; } }
namespace nPlatformUtil { namespace nSystemService { struct CALL_TYPE; } }
namespace nPlatformUtil { namespace nSystemService { struct EVENT_TYPE; } }

namespace nPlatformUtil {
    namespace nGameLiveStram {
        struct POSTYPE
        {
        public:
            enum DummyName
            {
                TOPLEFT = 0,
                TOPRIGHT = 1,
                BOTTOMLEFT = 2,
                BOTTOMRIGHT = 3,
            };
        public:
            using TYPE = nPlatformUtil::nGameLiveStram::POSTYPE::DummyName;
        };
    }  // namespace nGameLiveStram
}  // namespace nPlatformUtil

namespace nPlatformUtil {
    namespace nSharePlay {
        struct APPROVE_MODE
        {
        public:
            enum DummyName
            {
                ALL_ON = 0,
                SCREEN_ONLY = 1,
                ALL_OFF = 2,
            };
        public:
            using TYPE = nPlatformUtil::nSharePlay::APPROVE_MODE::DummyName;
        };
    }  // namespace nSharePlay
}  // namespace nPlatformUtil

namespace nPlatformUtil {
    namespace nSharePlay {
        struct CONTROLLER_MODE
        {
        public:
            enum DummyName
            {
                NONE = 0,
                WATCHING_HOST = 1,
                PLAYING_AS_HOST = 2,
                PLAYING_WITH_HOST = 3,
            };
        public:
            using TYPE = nPlatformUtil::nSharePlay::CONTROLLER_MODE::DummyName;
        };
    }  // namespace nSharePlay
}  // namespace nPlatformUtil

namespace nPlatformUtil {
    namespace nSharePlay {
        struct STATUS
        {
        public:
            enum DummyName
            {
                DORMANT = 0,
                READY = 1,
                CONNECTED = 2,
            };
        public:
            using TYPE = nPlatformUtil::nSharePlay::STATUS::DummyName;
        };
    }  // namespace nSharePlay
}  // namespace nPlatformUtil

namespace nPlatformUtil {
    namespace nSystemService {
        struct CALL_TYPE
        {
        public:
            enum DummyName
            {
                ONCE = 0,
                BEGIN = 1,
                END = 2,
            };
        public:
            using TYPE = nPlatformUtil::nSystemService::CALL_TYPE::DummyName;
        };
    }  // namespace nSystemService
}  // namespace nPlatformUtil

namespace nPlatformUtil {
    namespace nSystemService {
        struct EVENT_TYPE
        {
        public:
            enum DummyName
            {
                ON_RESUME = 0,
                GAME_LIVE_STREAMING_STATUS_UPDATE = 1,
                SESSION_INVITATION = 2,
                ENTITLEMENT_UPDATE = 3,
                GAME_CUSTOM_DATA = 4,
                LAUNCH_APP = 5,
                APP_LAUNCH_LINK = 6,
                INBACKGROUNDEXECUTION = 7,
                MAX = 8,
            };
        public:
            using TYPE = nPlatformUtil::nSystemService::EVENT_TYPE::DummyName;
        };
    }  // namespace nSystemService
}  // namespace nPlatformUtil
