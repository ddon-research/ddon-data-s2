#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../../../../../MT/MtObject.h"
#include "../../../../../../MT/MtSynchronize.h"
#include "../httpPatch.h"

// Forward declarations
class MtCriticalSection;
class MtObject;
class MtSemaphore;
class MtThread;

// Declarations
namespace via { class Request; }
namespace via { template <typename T> class RequestList; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using s32 = int;
using u32 = unsigned int;

namespace via {
    class Request : public ::MtObject
    {
    public:
        using RequestCallback = void(MtObject::*)(void*);
        using RequestEvent = void(MtObject::*)(void*);
    public:
        Request(u32 semaphore_init_count, u32 semaphore_max_count, MT_CTSTR semaphore_name);
        virtual ~Request();
        void setInitializeEvent(RequestEvent);
        void setFinalizeEvent(RequestEvent);
        void setThreadPriority(s32);
        void exit();
        bool resume(MtObject* object, RequestCallback callback, MT_CTSTR thread_name, void* argument_ptr);
        virtual void request();  // vtable slot 6
        s32 getRequestCount() const;
        void requestThread(void* param_ptr);
    protected:
        bool isExit() const;
        bool isResume() const;
        void requestWait();
        virtual void requestLoop(void* param_ptr);  // vtable slot 7
        bool resume(MT_CTSTR thread_name, void* argument_ptr);
        void lock();
        void unlock();
        const via::Request& operator=(const via::Request&);
    private:
        MtThread* mThreadHandle;  // offset: 0x8
        MtSemaphore mSemaphore;  // offset: 0x10
        RequestCallback mCallback;  // offset: 0x18
        RequestEvent mInitializeEvent;  // offset: 0x28
        RequestEvent mFinalizeEvent;  // offset: 0x38
        bool mExit;  // offset: 0x48
        bool mResume;  // offset: 0x49
    protected:
        s32 mCount;  // offset: 0x4c
        MtCriticalSection mMutex;  // offset: 0x50
        MtObject* mObject;  // offset: 0x58
        MtCriticalSection mRequest;  // offset: 0x60
    };
}  // namespace via

namespace via {
    template <typename T>
    class RequestList : public via::Request
    {
    public:
        using RequestListUpdateEvent = void(MtObject::*)(T&);
        using RequestListCallback = void(MtObject::*)(void*, T&);
    public:
        RequestList(u32 semaphore_init_count, u32 semaphore_max_count, MT_CTSTR semaphore_name);
        bool request(T req);
        void setDataPushEvent(RequestListUpdateEvent event);
        void setDataPopEvent(RequestListUpdateEvent event);
        virtual void requestLoop(void* param_ptr);  // vtable slot 7
        bool resume(MtObject* object, RequestListCallback callback, MT_CTSTR thread_name, void* argument_ptr);
    private:
        virtual void request();  // vtable slot 6
    private:
        MtCollisionUtil::MtArrayTemplateEx<T, true, 1> mList;  // offset: 0x68
        RequestListUpdateEvent mPushCallback;  // offset: 0x88
        RequestListUpdateEvent mPopCallback;  // offset: 0x98
        RequestListCallback mCallbackTemplate;  // offset: 0xa8
    };
}  // namespace via

template <typename T>
void via::RequestList<T>::request() {
    this->::via::Request::request();
}
