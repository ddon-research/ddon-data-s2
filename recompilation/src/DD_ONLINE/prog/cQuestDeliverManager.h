#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "Protocol/PacketData/Item.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "cQuestFunctionManagerBAse.h"
#include "nQuest.h"

// Forward declarations
class CDataDeliveredItem;
class CDataItemUIDList;
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
namespace nQuest { class SCHEDULE_ID; }
namespace nQuest { class cDeliveredItemInfo; }
namespace nQuest { class cQuestDeliverRequestInfo; }
namespace nQuest { class cQuestDeliveredInfo; }

// Declarations
class cQuestDeliverManager;

// Type aliases from DWARF
using ItemUIDListVec = MtTypedArray<CDataItemUIDList>;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cQuestDeliverManager : public cQuestFunctionManagerBase
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
    bool isReqDeliverItem() const;
    const nQuest::cQuestDeliverRequestInfo* getQuestDeliverRequestInfo(const nQuest::SCHEDULE_ID& scheduleId) const;
    nQuest::cQuestDeliveredInfo* getQuestDeliveredInfo(const nQuest::SCHEDULE_ID& scheduleId) const;
    bool fulfillDeliverItem(nQuest::SCHEDULE_ID scheduleId, u32 itemId) const;
    void deliverItem(const nQuest::SCHEDULE_ID& scheduleId, ItemUIDListVec& itemUIDList);
    void updateDeliveredInfo(nQuest::SCHEDULE_ID scheduleId, u32 charcterId, const MtTypedArray<CDataDeliveredItem>& deliveredList);
    virtual void release();  // vtable slot 6
    void deleteDeliveredInfo(nQuest::SCHEDULE_ID scheduleId, u32 itemId);
    void decideDeliverItem(nQuest::SCHEDULE_ID scheduleId, u32 itemId);
    void callbackLeaveParty();
    void callbackLeaveParty(u32 characterId);
protected:
    void callbackDeliverItem(void* pParam);
    nQuest::cDeliveredItemInfo* getDeliveredItemInfo(u32 itemId, nQuest::cQuestDeliveredInfo* pDelInfo);
    nQuest::cDeliveredItemInfo::cDeliverCharacterInfo* getDeliverCharacterInfo(u32 characterId, nQuest::cDeliveredItemInfo* pDelItemInfo);
    void callbackDecideDeliveryItem(void* pPacket);
public:
    cQuestDeliverManager();
    virtual ~cQuestDeliverManager();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
protected:
    ItemUIDListVec mDeliverItemList;  // offset: 0x8
    MtTypedArray<nQuest::cQuestDeliveredInfo> mDeliverInfo;  // offset: 0x28
    bool mIsReqDeliverItem;  // offset: 0x48
public:
    static MyDTI DTI;
};

inline void* cQuestDeliverManager::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* cQuestDeliverManager::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::cQuestDeliverManager::DTI);
}

inline void cQuestDeliverManager::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cQuestDeliverManager::DTI)->memFree(p_addr);
}
