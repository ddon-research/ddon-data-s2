#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "../MT/MtJsonReader.h"
#include "../MT/MtString.h"
#include "cCaplinkContext.h"
#include "cCaplinkDataDef.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;
namespace nCaplink { class cUserBaseInfo; }
namespace nCaplink { class cUserProfile; }
class sCaplinkManager;

// Declarations
namespace nCaplink { class LoginCogKeyAns; }
namespace nCaplink { class LoginCogKeyReqCtx; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __int64_t = long int;
using __uint64_t = long unsigned int;
using f64 = double;
using s32 = int;
using s64 = __int64_t;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

namespace nCaplink {
    class LoginCogKeyAns : public nCaplink::ContextListener
    {
        friend class ::sCaplinkManager;
    public:
        LoginCogKeyAns();
        virtual void init();  // vtable slot 6
        bool isLogin() const;
        const nCaplink::cUserBaseInfo* getMyInfo() const;
        MT_CTSTR getSystemMessage() const;
        void setLogin(bool flag);
        void setMyInfo(nCaplink::cUserBaseInfo my_info);
        void setMessage(MtString message);
    private:
        bool mIsLogin;  // offset: 0x20
        nCaplink::cUserBaseInfo mMyInfo;  // offset: 0x28
        MtString mMessage;  // offset: 0x2a8
    };
}  // namespace nCaplink

namespace nCaplink {
    class LoginCogKeyReqCtx : public nCaplink::HttpRequestContext
    {
    public:
        class MyDTI;
        class JsonParser;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class JsonParser : public MtJsonReader::Handler
        {
        public:
            JsonParser();
            void setParent(nCaplink::LoginCogKeyReqCtx* parent);
            virtual void fieldName(MT_CTSTR chars, const u32 length);  // vtable slot 6
            virtual void string(MT_CTSTR chars, const u32 length);  // vtable slot 7
            virtual void number(u64 value);  // vtable slot 8
            virtual void number(s64 value);  // vtable slot 9
            virtual void number(f64 value);  // vtable slot 10
        private:
            nCaplink::cUserProfile mTemp;  // offset: 0x10
            bool mbTempKey;  // offset: 0x6b8
            bool mbCommonKey;  // offset: 0x6b9
            bool mbKey;  // offset: 0x6ba
            bool mbUniqueId;  // offset: 0x6bb
            bool mbNickname;  // offset: 0x6bc
            bool mbMessage;  // offset: 0x6bd
            bool mCode;  // offset: 0x6be
            bool mDetailMessage;  // offset: 0x6bf
            nCaplink::LoginCogKeyReqCtx* mpParent;  // offset: 0x6c0
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
        LoginCogKeyReqCtx();
        LoginCogKeyReqCtx(MT_CTSTR content_user_id, s32 platform_id);
        virtual void update();  // vtable slot 8
        void setUniqueId(MT_CTSTR unique_id);
        void setNickname(MT_CTSTR nickname);
        void setContentId(MT_CTSTR);
        void setMessage(MT_CTSTR message);
    private:
        void reqCommonKey();
        void reqReauth();
    private:
        MtString mContentUserId;  // offset: 0x68
        MtString mUniqueId;  // offset: 0x70
        MtString mNickname;  // offset: 0x78
        MtString mMessage;  // offset: 0x80
        MtString mContentId;  // offset: 0x88
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

inline bool nCaplink::LoginCogKeyAns::isLogin() const {
    return this->mIsLogin;
}

inline void* nCaplink::LoginCogKeyReqCtx::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline nCaplink::LoginCogKeyReqCtx::LoginCogKeyReqCtx() {
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void nCaplink::LoginCogKeyReqCtx::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nCaplink::LoginCogKeyReqCtx::DTI)->memFree(p_addr);
}
