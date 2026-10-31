#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "cCaplinkContext.h"
#include "cCaplinkDataDef.h"

// Forward declarations
namespace nCaplink { class cUserProfile; }

// Declarations
namespace nCaplink { class UserProfileGetAns; }

namespace nCaplink {
    class UserProfileGetAns : public nCaplink::ContextListener
    {
    public:
        UserProfileGetAns();
        virtual void init();  // vtable slot 6
        const nCaplink::cUserProfile* getUserProfile() const;
        void setUserProfile(const nCaplink::cUserProfile& user_profile);
    private:
        nCaplink::cUserProfile mUserProfile;  // offset: 0x20
    };
}  // namespace nCaplink
