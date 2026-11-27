// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "MtNetUtilityPS4.h"
#include "MtAllocator.h"
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMemory.h"
#include "MtMemoryAllocator.h"
#include "MtNetCom.h"
#include "MtNetObject.h"
#include "MtObject.h"
#include "MtString.h"
#include "MtThread.h"
#include "../generated/shared/_rtc.h"
#include "../generated/shared/json2.h"
#include "../generated/shared/np_matching2.h"
#include "../generated/shared/np_npid.h"
#include "../generated/shared/np_webapi.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& MtNet::Utility::PS4::BlockList::getDTI() const {
    return MtNet::Utility::PS4::BlockList::DTI;
}

__attribute__((weak)) void MtNet::Utility::PS4::BlockList::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::MtNet::Utility::PS4::BlockList::DTI)->memFree(p_addr);
}

inline MtNet::Utility::PS4::BlockList::BlockList() {
    ::memset(static_cast<void*>(&mValidNum), 0, 3604ul);
}

inline MtNet::Utility::PS4::BlockList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

MtNet::Utility::PS4::BlockList::MyDTI MtNet::Utility::PS4::BlockList::DTI("BlockList", &::MtNetObject::DTI, 3640ul, 0u, 0u);

MtObject* MtNet::Utility::PS4::BlockList::MyDTI::newInstance() const {
    return new (16u) ::MtNet::Utility::PS4::BlockList;
}

const MtDTI& MtNet::Utility::PS4::Json::getDTI() const {
    return MtNet::Utility::PS4::Json::DTI;
}

void* MtNet::Utility::PS4::Json::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::MtNet::Utility::PS4::Json::DTI)->memAlloc(sz, align, ::MtNet::Utility::PS4::Json::DTI.mID);
}

__attribute__((weak)) void MtNet::Utility::PS4::Json::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::MtNet::Utility::PS4::Json::DTI)->memFree(p_addr);
}

MtNet::Utility::PS4::Json::~Json() {
    DDON_STUB("MtNet::Utility::PS4::Json::~Json")
    /* stub */
}

__attribute__((weak)) s32 MtNet::Utility::PS4::Json::parseFriendList(MtNet::Utility::PS4::Json::FriendList& list, MT_CTSTR str_ptr) {
    DDON_STUB("MtNet::Utility::PS4::Json::parseFriendList")
    return {};
}

__attribute__((weak)) s32 MtNet::Utility::PS4::Json::parseBlockList(MtNet::Utility::PS4::Json::BlockList& list, MT_CTSTR str_ptr) {
    DDON_STUB("MtNet::Utility::PS4::Json::parseBlockList")
    return {};
}

__attribute__((weak)) s32 MtNet::Utility::PS4::Json::constructSession(MtStringEx<4096>& ret_str, int64_t join_max, MtNetCom::IInvitePS4::SessionParam* invite_param_ptr) {
    DDON_STUB("MtNet::Utility::PS4::Json::constructSession")
    return {};
}

__attribute__((weak)) s32 MtNet::Utility::PS4::Json::constructPlayedWith(MtNet::Utility::PS4::MtNetString& ret_str, SceNpOnlineId* self_id_ptr, SceNpTitleId* title_id_ptr, SceNpOnlineId* online_id_tbl, size_t online_id_num, MtStringEx<1024>* explain_str_ptr) {
    DDON_STUB("MtNet::Utility::PS4::Json::constructPlayedWith")
    return {};
}

void* MtNet::Utility::PS4::Json::allocate(size_t size, void* arg_ptr) {
    return ::MtMemory::mpAllocatorType[7]->memAlloc(size, 16u);
}

void MtNet::Utility::PS4::Json::deallocate(void* ptr, void* arg_ptr) {
    ::MtMemory::mpAllocatorType[7]->memFree(ptr);
}

__attribute__((weak)) const sce::Json::Value& MtNet::Utility::PS4::Json::nullAccessCallback(sce::Json::ValueType accesstype, const sce::Json::Value* parent_ptr, void* context_ptr) {
    DDON_STUB("MtNet::Utility::PS4::Json::nullAccessCallback")
    __builtin_unreachable();
}

inline MtNet::Utility::PS4::Json::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

MtNet::Utility::PS4::Json::MyDTI MtNet::Utility::PS4::Json::DTI("Json", &::MtNetObject::DTI, 80ul, 0u, 0u);

MtNet::Utility::PS4::Json* MtNet::Utility::PS4::Json::mInstancePtr;

__attribute__((weak)) MtObject* MtNet::Utility::PS4::Json::MyDTI::newInstance() const {
    DDON_STUB("MtNet::Utility::PS4::Json::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& MtNet::Utility::PS4::Match::getDTI() const {
    return MtNet::Utility::PS4::Match::DTI;
}

void* MtNet::Utility::PS4::Match::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::MtNet::Utility::PS4::Match::DTI)->memAlloc(sz, align, ::MtNet::Utility::PS4::Match::DTI.mID);
}

MtNet::Utility::PS4::Match::Match(SceUserServiceUserId user_id, SceNpMatching2CreateContextParam& context_param) {
    DDON_STUB("MtNet::Utility::PS4::Match::Match")
    /* stub */
}

MtNet::Utility::PS4::Match::~Match() {
    DDON_STUB("MtNet::Utility::PS4::Match::~Match")
    /* stub */
}

__attribute__((weak)) s32 MtNet::Utility::PS4::Match::termContext(const MtNetObject& owner_obj) {
    DDON_STUB("MtNet::Utility::PS4::Match::termContext")
    return {};
}

void MtNet::Utility::PS4::Match::setContextEvent(SceNpMatching2ContextId context_id, SceNpMatching2Event event_id, SceNpMatching2EventCause event_cause, int error_code) {
    if (mContextId != context_id) {
        return;
    }
    if (event_id != 28417) {
        if (event_id == 28419) {
            mIsContextStopped = true;
        } else {
            if (event_id == 28418) {
                mIsContextStarted = true;
                if (error_code > -1) {
                    mContextAsyncResult = 1;
                } else {
                    mContextAsyncResult = error_code;
                }
            }
        }
    } else {
        mIsContextStartOver = true;
        if (error_code > -1) {
            mContextError = -2141909971;
        } else {
            mContextError = error_code;
        }
    }
}

inline MtNet::Utility::PS4::Match::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

MtNet::Utility::PS4::Match::MyDTI MtNet::Utility::PS4::Match::DTI("Match", &::MtNetObject::DTI, 120ul, 0u, 0u);

__attribute__((weak)) MtObject* MtNet::Utility::PS4::Match::MyDTI::newInstance() const {
    DDON_STUB("MtNet::Utility::PS4::Match::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& MtNet::Utility::PS4::MtNetString::getDTI() const {
    return MtNet::Utility::PS4::MtNetString::DTI;
}

MtNet::Utility::PS4::MtNetString::~MtNetString() {
    if (mBufSize == 0) {
        return;
    }
    ::MtMemoryAllocator::getAllocator(::MtNet::Utility::PS4::MtNetString::DTI)->memFree(static_cast<void*>(mBufPtr));
}

inline MtNet::Utility::PS4::MtNetString::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

MtNet::Utility::PS4::MtNetString::MyDTI MtNet::Utility::PS4::MtNetString::DTI("MtNetString", &::MtNetObject::DTI, 56ul, 0u, 0u);

__attribute__((weak)) MtObject* MtNet::Utility::PS4::MtNetString::MyDTI::newInstance() const {
    DDON_STUB("MtNet::Utility::PS4::MtNetString::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& MtNet::Utility::PS4::MtNetThread::getDTI() const {
    return MtNet::Utility::PS4::MtNetThread::DTI;
}

inline MtNet::Utility::PS4::MtNetThread::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

MtNet::Utility::PS4::MtNetThread::MyDTI MtNet::Utility::PS4::MtNetThread::DTI("MtNetThread", &::MtThread::DTI, 112ul, 0u, 0u);

__attribute__((weak)) MtObject* MtNet::Utility::PS4::MtNetThread::MyDTI::newInstance() const {
    DDON_STUB("MtNet::Utility::PS4::MtNetThread::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& MtNet::Utility::PS4::ReqCtx::getDTI() const {
    return MtNet::Utility::PS4::ReqCtx::DTI;
}

__attribute__((noinline)) MtNet::Utility::PS4::ReqCtx::~ReqCtx() {
    DDON_STUB("MtNet::Utility::PS4::ReqCtx::~ReqCtx")
    /* stub */
}

inline MtNet::Utility::PS4::ReqCtx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

MtNet::Utility::PS4::ReqCtx::MyDTI MtNet::Utility::PS4::ReqCtx::DTI("ReqCtx", &::MtNetObject::DTI, 256ul, 0u, 0u);

__attribute__((weak)) MtObject* MtNet::Utility::PS4::ReqCtx::MyDTI::newInstance() const {
    DDON_STUB("MtNet::Utility::PS4::ReqCtx::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& MtNet::Utility::PS4::WebApi::getDTI() const {
    return MtNet::Utility::PS4::WebApi::DTI;
}

void* MtNet::Utility::PS4::WebApi::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::MtNet::Utility::PS4::WebApi::DTI)->memAlloc(sz, align, ::MtNet::Utility::PS4::WebApi::DTI.mID);
}

MtNet::Utility::PS4::WebApi::~WebApi() {
    DDON_STUB("MtNet::Utility::PS4::WebApi::~WebApi")
    /* stub */
}

__attribute__((weak)) MtNet::Utility::PS4::ReqCtxPtr MtNet::Utility::PS4::WebApi::reqInitialize(const void* owner_ptr, int32_t lib_ctx_id, SceNpServiceLabel service_label, bool disuse_friend, bool disuse_presence, bool disuse_match, bool disuse_entitlement) {
    DDON_STUB("MtNet::Utility::PS4::WebApi::reqInitialize")
    return {};
}

bool MtNet::Utility::PS4::WebApi::pollInitialize(MtNet::Utility::PS4::ReqCtxPtr req_ptr, s32& result, int32_t& normal_filter_id, int32_t& service_handle_id, int32_t& service_filter_id) {
    bool b9_0;
    if (req_ptr->mIsComplete) {
        if (req_ptr->mErrorNo != 0) {
            result = req_ptr->mErrorNo;
        } else {
            result = 0;
            normal_filter_id = static_cast<int32_t>(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(req_ptr) + 192));
            service_handle_id = static_cast<int32_t>(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(req_ptr) + 200));
            service_filter_id = static_cast<int32_t>(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(req_ptr) + 208));
        }
        lock();
        u32 v1_0 = mReqCtxPtrArray.mLength;
        if (v1_0 != 0) {
            MtObject* * v1_1 = mReqCtxPtrArray.mpArray;
            unsigned int i1_3 = 0;
            u32 v4_0;
            unsigned int v5_1;
            u32 v5_2;
            unsigned int v5_3;
            for (;;) {
                if (req_ptr == v1_1[i1_3]) {
                    if (!mReqCtxPtrArray.mAutoDelete) {
                        v4_0 = v1_0;
                    } else {
                        if (req_ptr == nullptr) {
                            v4_0 = v1_0;
                        } else {
                            delete req_ptr;
                            v4_0 = mReqCtxPtrArray.mLength;
                        }
                    }
                    if ((i1_3 + 1u) < v4_0) {
                        v5_1 = i1_3 + 1u;
                        v5_2 = v4_0;
                        v5_3 = i1_3;
                        for (;;) {
                            mReqCtxPtrArray.mpArray[v5_3] = mReqCtxPtrArray.mpArray[v5_1];
                            if (v5_2 != (v5_1 + 1u)) {
                                v5_3 = v5_1;
                                v5_1 = v5_1 + 1u;
                            } else {
                                break;
                            }
                        }
                    }
                    mReqCtxPtrArray.mLength = v4_0 - 1u;
                    break;
                } else {
                    if ((i1_3 + 1u) < v1_0) {
                        i1_3 = i1_3 + 1u;
                    } else {
                        break;
                    }
                }
            }
        }
        if (req_ptr != nullptr) {
            delete req_ptr;
        }
        unlock();
        b9_0 = true;
    } else {
        b9_0 = false;
    }
    return b9_0;
}

__attribute__((weak)) MtNet::Utility::PS4::ReqCtxPtr MtNet::Utility::PS4::WebApi::reqGetFriendList(const void* owner_ptr, int32_t usr_ctx_id, SceNpOnlineId* online_id_ptr, s32 offset) {
    DDON_STUB("MtNet::Utility::PS4::WebApi::reqGetFriendList")
    return {};
}

bool MtNet::Utility::PS4::WebApi::pollGetFriendList(MtNet::Utility::PS4::ReqCtxPtr req_ptr, s32& result, MtNet::Utility::PS4::Json::FriendList& list) {
    bool b9_0;
    if (req_ptr->mIsComplete) {
        s32 v0_0;
        if (req_ptr->mErrorNo != 0) {
            v0_0 = req_ptr->mErrorNo;
        } else {
            v0_0 = (::MtNet::Utility::PS4::Json::mInstancePtr)->::MtNet::Utility::PS4::Json::parseFriendList(list, req_ptr->mRecvStr.mBufPtr);
        }
        result = v0_0;
        lock();
        u32 v1_0 = mReqCtxPtrArray.mLength;
        if (v1_0 != 0) {
            MtObject* * v1_1 = mReqCtxPtrArray.mpArray;
            unsigned int i1_3 = 0;
            u32 v4_0;
            unsigned int v5_1;
            u32 v5_2;
            unsigned int v5_3;
            for (;;) {
                if (req_ptr == v1_1[i1_3]) {
                    if (!mReqCtxPtrArray.mAutoDelete) {
                        v4_0 = v1_0;
                    } else {
                        if (req_ptr == nullptr) {
                            v4_0 = v1_0;
                        } else {
                            delete req_ptr;
                            v4_0 = mReqCtxPtrArray.mLength;
                        }
                    }
                    if ((i1_3 + 1u) < v4_0) {
                        v5_1 = i1_3 + 1u;
                        v5_2 = v4_0;
                        v5_3 = i1_3;
                        for (;;) {
                            mReqCtxPtrArray.mpArray[v5_3] = mReqCtxPtrArray.mpArray[v5_1];
                            if (v5_2 != (v5_1 + 1u)) {
                                v5_3 = v5_1;
                                v5_1 = v5_1 + 1u;
                            } else {
                                break;
                            }
                        }
                    }
                    mReqCtxPtrArray.mLength = v4_0 - 1u;
                    break;
                } else {
                    if ((i1_3 + 1u) < v1_0) {
                        i1_3 = i1_3 + 1u;
                    } else {
                        break;
                    }
                }
            }
        }
        if (req_ptr != nullptr) {
            delete req_ptr;
        }
        unlock();
        b9_0 = true;
    } else {
        b9_0 = false;
    }
    return b9_0;
}

__attribute__((weak)) MtNet::Utility::PS4::ReqCtxPtr MtNet::Utility::PS4::WebApi::reqGetBlockList(const void* owner_ptr, int32_t usr_ctx_id, SceNpOnlineId* online_id_ptr, s32 offset) {
    DDON_STUB("MtNet::Utility::PS4::WebApi::reqGetBlockList")
    return {};
}

bool MtNet::Utility::PS4::WebApi::pollGetBlockList(MtNet::Utility::PS4::ReqCtxPtr req_ptr, s32& result, MtNet::Utility::PS4::Json::BlockList& list) {
    bool b9_0;
    if (req_ptr->mIsComplete) {
        s32 v0_0;
        if (req_ptr->mErrorNo != 0) {
            v0_0 = req_ptr->mErrorNo;
        } else {
            v0_0 = (::MtNet::Utility::PS4::Json::mInstancePtr)->::MtNet::Utility::PS4::Json::parseBlockList(list, req_ptr->mRecvStr.mBufPtr);
        }
        result = v0_0;
        lock();
        u32 v1_0 = mReqCtxPtrArray.mLength;
        if (v1_0 != 0) {
            MtObject* * v1_1 = mReqCtxPtrArray.mpArray;
            unsigned int i1_3 = 0;
            u32 v4_0;
            unsigned int v5_1;
            u32 v5_2;
            unsigned int v5_3;
            for (;;) {
                if (req_ptr == v1_1[i1_3]) {
                    if (!mReqCtxPtrArray.mAutoDelete) {
                        v4_0 = v1_0;
                    } else {
                        if (req_ptr == nullptr) {
                            v4_0 = v1_0;
                        } else {
                            delete req_ptr;
                            v4_0 = mReqCtxPtrArray.mLength;
                        }
                    }
                    if ((i1_3 + 1u) < v4_0) {
                        v5_1 = i1_3 + 1u;
                        v5_2 = v4_0;
                        v5_3 = i1_3;
                        for (;;) {
                            mReqCtxPtrArray.mpArray[v5_3] = mReqCtxPtrArray.mpArray[v5_1];
                            if (v5_2 != (v5_1 + 1u)) {
                                v5_3 = v5_1;
                                v5_1 = v5_1 + 1u;
                            } else {
                                break;
                            }
                        }
                    }
                    mReqCtxPtrArray.mLength = v4_0 - 1u;
                    break;
                } else {
                    if ((i1_3 + 1u) < v1_0) {
                        i1_3 = i1_3 + 1u;
                    } else {
                        break;
                    }
                }
            }
        }
        if (req_ptr != nullptr) {
            delete req_ptr;
        }
        unlock();
        b9_0 = true;
    } else {
        b9_0 = false;
    }
    return b9_0;
}

__attribute__((weak)) MtNet::Utility::PS4::ReqCtxPtr MtNet::Utility::PS4::WebApi::reqSetPresenceGameStatus(const void* owner_ptr, int32_t usr_ctx_id, SceNpOnlineId* online_id_ptr, MtStringEx<256>* status_str_ptr) {
    DDON_STUB("MtNet::Utility::PS4::WebApi::reqSetPresenceGameStatus")
    return {};
}

bool MtNet::Utility::PS4::WebApi::pollSetPresenceGameStatus(MtNet::Utility::PS4::ReqCtxPtr req_ptr, s32& result) {
    return pollCommon(req_ptr, result);
}

__attribute__((weak)) MtNet::Utility::PS4::ReqCtxPtr MtNet::Utility::PS4::WebApi::reqSetPresenceGameData(const void* owner_ptr, int32_t usr_ctx_id, SceNpOnlineId* online_id_ptr, void* data_ptr, s32 data_size) {
    DDON_STUB("MtNet::Utility::PS4::WebApi::reqSetPresenceGameData")
    return {};
}

bool MtNet::Utility::PS4::WebApi::pollSetPresenceGameData(MtNet::Utility::PS4::ReqCtxPtr req_ptr, s32& result) {
    return pollCommon(req_ptr, result);
}

__attribute__((weak)) MtNet::Utility::PS4::ReqCtxPtr MtNet::Utility::PS4::WebApi::reqSetPlayedWith(const void* owner_ptr, int32_t usr_ctx_id, SceNpOnlineId* self_id_ptr, SceNpTitleId* title_id_ptr, SceNpOnlineId* online_id_tbl, size_t online_id_num, MtStringEx<1024>* explain_str_ptr) {
    DDON_STUB("MtNet::Utility::PS4::WebApi::reqSetPlayedWith")
    return {};
}

bool MtNet::Utility::PS4::WebApi::pollSetPlayedWith(MtNet::Utility::PS4::ReqCtxPtr req_ptr, s32& result) {
    return pollCommon(req_ptr, result);
}

__attribute__((weak)) MtNet::Utility::PS4::ReqCtxPtr MtNet::Utility::PS4::WebApi::reqNew(const void* owner_ptr, MtNet::Utility::PS4::ReqCtx::ReqType req_type, size_t send_size, size_t recv_size) {
    DDON_STUB("MtNet::Utility::PS4::WebApi::reqNew")
    return {};
}

__attribute__((weak)) void MtNet::Utility::PS4::WebApi::execute(void* param_ptr) {
    DDON_STUB("MtNet::Utility::PS4::WebApi::execute")
    /* stub */
}

__attribute__((weak)) bool MtNet::Utility::PS4::WebApi::pollCommon(MtNet::Utility::PS4::ReqCtxPtr req_ptr, s32& result) {
    bool b8_0;
    if (req_ptr->mIsComplete) {
        result = req_ptr->mErrorNo;
        lock();
        u32 v0_0 = mReqCtxPtrArray.mLength;
        if (v0_0 != 0) {
            MtObject* * v0_1 = mReqCtxPtrArray.mpArray;
            unsigned int i0_3 = 0;
            u32 v3_0;
            unsigned int v4_1;
            u32 v4_2;
            unsigned int v4_3;
            for (;;) {
                if (req_ptr == v0_1[i0_3]) {
                    if (!mReqCtxPtrArray.mAutoDelete) {
                        v3_0 = v0_0;
                    } else {
                        if (req_ptr == nullptr) {
                            v3_0 = v0_0;
                        } else {
                            delete req_ptr;
                            v3_0 = mReqCtxPtrArray.mLength;
                        }
                    }
                    if ((i0_3 + 1u) < v3_0) {
                        v4_1 = i0_3 + 1u;
                        v4_2 = v3_0;
                        v4_3 = i0_3;
                        for (;;) {
                            mReqCtxPtrArray.mpArray[v4_3] = mReqCtxPtrArray.mpArray[v4_1];
                            if (v4_2 != (v4_1 + 1u)) {
                                v4_3 = v4_1;
                                v4_1 = v4_1 + 1u;
                            } else {
                                break;
                            }
                        }
                    }
                    mReqCtxPtrArray.mLength = v3_0 - 1u;
                    break;
                } else {
                    if ((i0_3 + 1u) < v0_0) {
                        i0_3 = i0_3 + 1u;
                    } else {
                        break;
                    }
                }
            }
        }
        if (req_ptr != nullptr) {
            delete req_ptr;
        }
        unlock();
        b8_0 = true;
    } else {
        b8_0 = false;
    }
    return b8_0;
}

__attribute__((weak)) void MtNet::Utility::PS4::WebApi::initialize(MtNet::Utility::PS4::ReqCtxPtr req_ptr) {
    DDON_STUB("MtNet::Utility::PS4::WebApi::initialize")
    /* stub */
}

__attribute__((weak)) void MtNet::Utility::PS4::WebApi::createWebSession(MtNet::Utility::PS4::ReqCtxPtr req_ptr) {
    DDON_STUB("MtNet::Utility::PS4::WebApi::createWebSession")
    /* stub */
}

__attribute__((weak)) void MtNet::Utility::PS4::WebApi::sendRequest(MtNet::Utility::PS4::ReqCtxPtr req_ptr, int32_t usr_ctx_id, MT_CTSTR api_group_ptr, MT_CTSTR req_path, SceNpWebApiHttpMethod req_method, const SceNpWebApiContentParameter* cont_param_ptr, const void* req_data_ptr, size_t req_data_size, void* res_buf_ptr, size_t res_buf_size, size_t& read_size) {
    DDON_STUB("MtNet::Utility::PS4::WebApi::sendRequest")
    /* stub */
}

inline MtNet::Utility::PS4::WebApi::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

MtNet::Utility::PS4::WebApi::MyDTI MtNet::Utility::PS4::WebApi::DTI("WebApi", &::MtNet::Utility::PS4::MtNetThread::DTI, 416ul, 0u, 0u);

MtNet::Utility::PS4::WebApi* MtNet::Utility::PS4::WebApi::mInstancePtr;

__attribute__((weak)) MtObject* MtNet::Utility::PS4::WebApi::MyDTI::newInstance() const {
    DDON_STUB("MtNet::Utility::PS4::WebApi::MyDTI::newInstance")
    return nullptr;
}

template MtTypedArray<MtNet::Utility::PS4::ReqCtx>::~MtTypedArray();

