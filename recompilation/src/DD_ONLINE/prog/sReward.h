#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../XFramework/cSystem.h"

// Forward declarations
class CDataPartnerPawnReward;
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;

// Declarations
class sReward;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class sReward : public cSystem
{
public:
    enum
    {
        REWARD_TYPE_NOTHING = 0,
        STATUS_BUSY = 0,
        STATUS_REQUEST = 1,
        STATUS_REQUEST_UPDATE = 2,
        STATUS_SUCCESS = 3,
        STATUS_ERROR = 4,
        TALK_RELEASE_LV_NONE = 0,
        TALK_RELEASE_LV_1 = 1,
        TALK_RELEASE_LV_2 = 2,
        TALK_RELEASE_LV_3 = 3,
        TALK_RELEASE_LV_4 = 4,
        TALK_RELEASE_LV_5 = 5,
        TALK_RELEASE_LV_6 = 6,
        TALK_RELEASE_LV_MAX = 6,
    };
public:
    class MyDTI;
    class cAvailableReward;
    class cReleaseReward;
    class cReleaseRewardEdit;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cAvailableReward : public MtObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
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
        cAvailableReward();
        virtual ~cAvailableReward();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    public:
        u8 mRewardType;  // offset: 0x8
        u32 mParamTypeId;  // offset: 0xc
        u32 mUid;  // offset: 0x10
        static MyDTI DTI;
    };
public:
    class cReleaseReward : public MtObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
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
        cReleaseReward();
        virtual ~cReleaseReward();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    public:
        u32 mRewardNo;  // offset: 0x8
        static MyDTI DTI;
    };
public:
    class cReleaseRewardEdit : public MtObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
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
        cReleaseRewardEdit();
        virtual ~cReleaseRewardEdit();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    public:
        u32 mRewardType;  // offset: 0x8
        u32 mRewardNo;  // offset: 0xc
        static MyDTI DTI;
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
    static sReward* getInstance();
    sReward();
    virtual ~sReward();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void reset();  // vtable slot 6
    virtual void move();  // vtable slot 7
    bool isAvailableReward();
    bool isAvailableRewardEdit();
    u32 getAvailableRewardEditNo();
    void requestGetAvailableList();
    void requestGetReleaseList();
    void requestReceiveReward(bool update);
    void requestAvailableAchieve();
    bool isFinishGetAvailableList();
    bool isFinishGetReleaseList();
    bool isFinishReceiveReward();
    bool isFinishAvailableAchieve();
    u32 getNextRewardType();
    u32 getNextRewardNo();
    u32 getTalkReleaseLv();
    MtTypedArray<cAvailableReward>& getAvailableReward();
    MtTypedArray<cReleaseReward>& getReleaseEmote();
    MtTypedArray<cReleaseReward>& getReleaseTalk();
    MtTypedArray<cReleaseRewardEdit>& getReleaseEdit();
    MtTypedArray<cReleaseReward>& getReleaseAbility();
    u32 getStatusAvailableList();
    u32 getStatusReleaseList();
    u32 getStatusReceiveReward();
    u32 getStatusAvailableAchieve();
    bool isAvailableAchieve();
    void setAvailableAchieve(bool isAvailableAchieve);
    void setAvailableReward(const MtTypedArray<CDataPartnerPawnReward>& list);
    void setReleaseReward(const MtTypedArray<CDataPartnerPawnReward>& list);
private:
    void moveAvailableList();
    void moveReleaseList();
    void moveReceiveReward();
    void moveAvailableAchieve();
    void resetAvailableReward();
    void resetReleaseReward();
private:
    u32 mStatusReceiveReward;  // offset: 0x14
    u32 mStatusAvailableList;  // offset: 0x18
    u32 mStatusReleaseList;  // offset: 0x1c
    u32 mStatusAvailableAchieve;  // offset: 0x20
    bool mIsAvailableAchieve;  // offset: 0x24
    MtTypedArray<cAvailableReward> mAvailableReward;  // offset: 0x28
    MtTypedArray<cReleaseReward> mReleaseEmote;  // offset: 0x48
    MtTypedArray<cReleaseReward> mReleaseTalk;  // offset: 0x68
    MtTypedArray<cReleaseRewardEdit> mReleaseEdit;  // offset: 0x88
    MtTypedArray<cReleaseReward> mReleaseAbility;  // offset: 0xa8
public:
    static MyDTI DTI;
private:
    static sReward* mpInstance;
};

inline void* sReward::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* sReward::cAvailableReward::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline sReward::cAvailableReward::cAvailableReward() {
    this->mRewardType = 0;
    this->mParamTypeId = 0;
    this->mUid = 0;
}

inline void* sReward::cReleaseReward::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline sReward::cReleaseReward::cReleaseReward() {
    this->mRewardNo = 0;
}

inline void* sReward::cReleaseRewardEdit::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline sReward::cReleaseRewardEdit::cReleaseRewardEdit() {
    this->mRewardType = 0;
    this->mRewardNo = 0;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"
#include "cNetGameServer.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"

inline MtAllocator* sReward::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::sReward::DTI);
}

inline void sReward::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::sReward::DTI)->memFree(p_addr);
}

inline void sReward::moveAvailableList() {
    if (this->mStatusAvailableList == 0) {
        if (static_cast<sNetworkExt*>(::sNetwork::mpInstance)->mpGameServer->mStatus[522] == static_cast<sNetworkExt::NET_STAT>(4)) {
            this->mStatusAvailableList = 4;
        } else {
            if (static_cast<sNetworkExt*>(::sNetwork::mpInstance)->mpGameServer->mStatus[522] == static_cast<sNetworkExt::NET_STAT>(2)) {
                this->mStatusAvailableList = 3;
            }
        }
    } else {
        if (this->mStatusAvailableList == 1) {
            static_cast<sNetworkExt*>(::sNetwork::mpInstance)->mpGameServer->::cNetGameServer::getPawnLikabilityRewardList();
            this->mStatusAvailableList = 0;
        }
    }
}

inline void sReward::moveReleaseList() {
    if (this->mStatusReleaseList == 0) {
        if (static_cast<sNetworkExt*>(::sNetwork::mpInstance)->mpGameServer->mStatus[524] == static_cast<sNetworkExt::NET_STAT>(4)) {
            this->mStatusReleaseList = 4;
        } else {
            if (static_cast<sNetworkExt*>(::sNetwork::mpInstance)->mpGameServer->mStatus[524] == static_cast<sNetworkExt::NET_STAT>(2)) {
                this->mStatusReleaseList = 3;
            }
        }
    } else {
        if (this->mStatusReleaseList == 1) {
            static_cast<sNetworkExt*>(::sNetwork::mpInstance)->mpGameServer->::cNetGameServer::getPawnLikabilityReleasedRewardList();
            this->mStatusReleaseList = 0;
        }
    }
}

inline void* sReward::cAvailableReward::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::sReward::cAvailableReward::DTI)->memAlloc(sz, align, ::sReward::cAvailableReward::DTI.::MtDTI::getID());
}

inline void sReward::cAvailableReward::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::sReward::cAvailableReward::DTI)->memFree(p_addr);
}

inline void* sReward::cReleaseReward::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::sReward::cReleaseReward::DTI)->memAlloc(sz, align, ::sReward::cReleaseReward::DTI.::MtDTI::getID());
}

inline void sReward::cReleaseReward::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::sReward::cReleaseReward::DTI)->memFree(p_addr);
}

inline void* sReward::cReleaseRewardEdit::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::sReward::cReleaseRewardEdit::DTI)->memAlloc(sz, align, ::sReward::cReleaseRewardEdit::DTI.::MtDTI::getID());
}

inline void sReward::cReleaseRewardEdit::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::sReward::cReleaseRewardEdit::DTI)->memFree(p_addr);
}
