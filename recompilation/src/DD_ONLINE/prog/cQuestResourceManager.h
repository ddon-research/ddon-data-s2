#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "cQuestFunctionManagerBAse.h"
#include "nQuest.h"
#include "rCycleQuestInfo.h"
#include "rTutorialQuestGroup.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cArcLoaderBase;
class cJobMasterCtrl;
class cTalkMsgData;
namespace nQuest { class QUEST_ID; }
class rCycleQuestInfo;
class rGUIMessage;
class rJobMasterCtrl;
class rJobTutorialQuestList;
class rPawnQuestTalk;
class rQuestSequenceList;
class rQuestTextData;
class rTutorialQuestGroup;

// Declarations
class cQuestResourceManager;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using TICKET = cArcLoaderBase*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

class cQuestResourceManager : public cQuestFunctionManagerBase
{
public:
    enum
    {
        QUEST_RESOURCE_NUM = 200,
    };
public:
    class MyDTI;
    class cQuestResource;
    class cQuestContentResource;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cQuestResource : public MtObject
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
        MT_CTSTR getQuestName() const;
        MT_CTSTR getRewardName() const;
        MT_CTSTR getOrderMsg() const;
        MT_CTSTR getPurposeMsg(s32 purposeNo) const;
        MT_CTSTR getFindInfoMsg() const;
        MT_CTSTR getFindInfoDetailMsg() const;
        MT_CTSTR getSayPatternMsg(s32 msgIdx) const;
        u32 getPurposeNum() const;
        MT_CTSTR getContentsDetailMsg() const;
        MT_CTSTR getCycleContentsDetailMsg() const;
        cTalkMsgData* getMessageData() const;
        cTalkMsgData* getExmineData() const;
        rPawnQuestTalk* getPawnQuestTalk() const;
        nQuest::QUEST_ID getQuestId() const;
        u32 getQuestIdU32() const;
        bool isFinishedLoading() const;
        bool hasQuestText() const;
        s32 getGmdIdx(nQuest::QUEST_TEXT_TYPE textType) const;
        s32 getGmdIdx(nQuest::QUEST_TEXT_TYPE textType, s32 idx) const;
        u32 getPriority() const;
        u64 getTimeStamp() const;
        void setTimeStamp(u64 createTime);
        void init(nQuest::QUEST_ID questId);
        void move();
    protected:
        bool loadArchive();
        void loadResource();
        void loadMessageData();
        void loadExmineData();
    public:
        cQuestResource();
        cQuestResource(u64 time);
        virtual ~cQuestResource();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        TICKET mArcTicket;  // offset: 0x8
        u64 mCreateTime;  // offset: 0x10
        rGUIMessage* mpQuestText;  // offset: 0x18
        rQuestTextData* mpQuestTextDetail;  // offset: 0x20
        cTalkMsgData* mpQuestMessageData;  // offset: 0x28
        cTalkMsgData* mpQuestExmineData;  // offset: 0x30
        rPawnQuestTalk* mpPawnQuestTalk;  // offset: 0x38
        nQuest::QUEST_ID mQuestId;  // offset: 0x40
        bool mIsFinishedLoading;  // offset: 0x50
    public:
        static MyDTI DTI;
    };
public:
    class cQuestContentResource : public MtObject
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
        rGUIMessage* getContentTextRes() const;
        nQuest::QUEST_ID getQuestId() const;
        u32 getQuestIdU32() const;
        bool isFinishedLoading() const;
        bool hasCycleContentInfo() const;
        u32 getContentCategory() const;
        u32 getContentSubCategory() const;
        bool isContentRelease() const;
        void setIsContentRelease(bool isContentRelease);
        void initContentCategory(u32 ContentCategory, u32 ContentSubCategory);
        void move();
    protected:
        bool loadArchive();
        void loadResource();
    public:
        cQuestContentResource();
        virtual ~cQuestContentResource();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        TICKET mArcTicket;  // offset: 0x8
        rGUIMessage* mpCycleQuestInfo;  // offset: 0x10
        u32 mContentCategory;  // offset: 0x18
        u32 mContentSubCategory;  // offset: 0x1c
        bool mIsFinishedLoading;  // offset: 0x20
        bool mIsContentRelease;  // offset: 0x21
    public:
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
    MT_CTSTR getQuestName(nQuest::QUEST_ID questId) const;
    MT_CTSTR getRewardBoxQuestName(nQuest::QUEST_ID questId) const;
    MT_CTSTR getOrderMsg(nQuest::QUEST_ID questId) const;
    MT_CTSTR getPurposeMsg(nQuest::QUEST_ID questId, s32 purposeNo) const;
    MT_CTSTR getFindInfoMsg(nQuest::QUEST_ID questId) const;
    MT_CTSTR getFindInfoDetailMsg(nQuest::QUEST_ID questId) const;
    MT_CTSTR getSayPatternMsg(nQuest::QUEST_ID questId, s32 msgIdx) const;
    u32 getPurposeNum(nQuest::QUEST_ID questId) const;
    MT_CTSTR getContentsDetailMsg(nQuest::QUEST_ID questId) const;
    MT_CTSTR getCycleContentsDetailMsg(nQuest::QUEST_ID questId) const;
    cTalkMsgData* getMessageData(nQuest::QUEST_ID questId) const;
    cTalkMsgData* getExmineData(nQuest::QUEST_ID questId) const;
    rPawnQuestTalk* getPawnQuestTalk(nQuest::QUEST_ID questId) const;
    u32 getQuestSequence(nQuest::QUEST_ID questId) const;
    MT_CTSTR getOrderCondition(u32 Idx) const;
    MT_CTSTR getLightQuestPurpose(u32 Idx) const;
    cJobMasterCtrl* getJobMasterCtrlData(u32 JobId) const;
    u32 getJobTutorialQuestNum() const;
    nQuest::QUEST_ID getJobTutorialQuestId(u32 idx) const;
    rCycleQuestInfo::cCycleQuestInfo* getCycleQuestInfo(u32 ContentType, u32 ContentSubType);
    MT_CTSTR getContentTextCore(u32 ContentType, u32 ContentSubType, u32 Idx);
    MT_CTSTR getCycleContentsName(u32 ContentType, u32 ContentSubType);
    MT_CTSTR getCycleContentsInfo(u32 ContentType, u32 ContentSubType);
    MT_CTSTR getCycleContentsOrderPlace(u32 ContentType, u32 ContentSubType);
    MT_CTSTR getCycleContentsSituationName(u32 ContentType, u32 ContentSubType, u32 Period);
    MT_CTSTR getCycleContentsSituationInfo(u32 ContentType, u32 ContentSubType, u32 Period);
    MT_CTSTR getCycleContentsSituationDetailedInfo(u32 ContentType, u32 ContentSubType, u32 Period);
    u32 getCycleContentsGatherStageNo(u32 ContentType, u32 ContentSubType);
    u32 getCycleContentsGatherStartPos(u32 ContentType, u32 ContentSubType);
    u32 getCycleContentsGatherNpcId(u32 ContentType, u32 ContentSubType);
    u32 getCycleContentsCategory(u32 NpcId);
    u32 getCycleContentsSubCategory(u32 NpcId);
    u32 getCycleContentsSubCategory(u32 NpcId, u32 Id);
    u32 getCycleContentsSubCategoryNum(u32 NpcId);
    const rTutorialQuestGroup::cGroup* getTutorialQuestGroup(u32 groupId) const;
    bool isFinishedLoading(nQuest::QUEST_ID questId) const;
    bool isFinishedLoadingRewardBox(nQuest::QUEST_ID questId) const;
    bool hasQuestText(nQuest::QUEST_ID questId) const;
    bool hasRequest(nQuest::QUEST_ID questId) const;
    void setFlagContentRelease(u32 ContentCategory, u32 ContentSubCategory, bool isContentRelease);
    void setFlagOpenNewspaper(bool isOpen);
protected:
    cQuestResource* getQuestResource(nQuest::QUEST_ID questId) const;
    cQuestResource* getQuestResourceRewardBox(nQuest::QUEST_ID questId) const;
    cQuestContentResource* getQuestContentResource(u32 ContentCategory, u32 ContentSubCategory) const;
public:
    void requestLoadResource(nQuest::QUEST_ID questId);
    void requestLoadResourceRewardBox(nQuest::QUEST_ID questId);
    void initContentCategory(u32 ContentCategory, u32 ContentSubCategory);
    void move();
    virtual void release();  // vtable slot 6
    void releaseRewardBox();
    void initGame();
    void releaseContentResource();
protected:
    cQuestResource* newInstanceQuestResource(nQuest::QUEST_ID questId);
    void deleteInstanceQuestResource(cQuestResource* * pResource);
    void releaseQuestResource();
public:
    cQuestResourceManager();
    virtual ~cQuestResourceManager();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
protected:
    MtTypedArray<cQuestResource> mRewardBoxResource;  // offset: 0x8
    cQuestResource* mpQuestResource[200];  // offset: 0x28
    rQuestSequenceList* mpQuestSequence;  // offset: 0x668
    rJobTutorialQuestList* mpJobTutoQuestList;  // offset: 0x670
    rGUIMessage* mpOrderCondition;  // offset: 0x678
    rGUIMessage* mpLightQuestText;  // offset: 0x680
    rJobMasterCtrl* mpJobMasterCtrl;  // offset: 0x688
    rCycleQuestInfo* mpCycleQuestInfo;  // offset: 0x690
    rTutorialQuestGroup* mpTutoQuestGroup;  // offset: 0x698
    u32 mQuestResourceNum;  // offset: 0x6a0
    MtTypedArray<cQuestContentResource> mContentResource;  // offset: 0x6a8
    bool mIsOpenNews;  // offset: 0x6c8
public:
    static MyDTI DTI;
};

inline void* cQuestResourceManager::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cQuestResourceManager::cQuestResource::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline u64 cQuestResourceManager::cQuestResource::getTimeStamp() const {
    return this->mCreateTime;
}

inline void* cQuestResourceManager::cQuestContentResource::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline rGUIMessage* cQuestResourceManager::cQuestContentResource::getContentTextRes() const {
    return this->mpCycleQuestInfo;
}

inline u32 cQuestResourceManager::cQuestContentResource::getContentCategory() const {
    return this->mContentCategory;
}

inline u32 cQuestResourceManager::cQuestContentResource::getContentSubCategory() const {
    return this->mContentSubCategory;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"
#include "sArchiveManager.h"

inline MtAllocator* cQuestResourceManager::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::cQuestResourceManager::DTI);
}

inline void cQuestResourceManager::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cQuestResourceManager::DTI)->memFree(p_addr);
}

inline void cQuestResourceManager::cQuestResource::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cQuestResourceManager::cQuestResource::DTI)->memFree(p_addr);
}

inline void* cQuestResourceManager::cQuestContentResource::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cQuestResourceManager::cQuestContentResource::DTI)->memAlloc(sz, align, ::cQuestResourceManager::cQuestContentResource::DTI.::MtDTI::getID());
}

inline void cQuestResourceManager::cQuestContentResource::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cQuestResourceManager::cQuestContentResource::DTI)->memFree(p_addr);
}

inline cQuestResourceManager::cQuestContentResource::cQuestContentResource() {
    this->mArcTicket = ::sArchiveManager::INVALID_TICKET;
    this->mIsFinishedLoading = false;
    this->mIsContentRelease = false;
    this->mContentCategory = 0;
    this->mContentSubCategory = 0;
    this->mpCycleQuestInfo = nullptr;
}
