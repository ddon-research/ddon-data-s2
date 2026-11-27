#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "Protocol/PacketData/Common.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "Protocol/PacketData/Quest.h"
#include "nQuest.h"

// Forward declarations
class CDataCommonU32;
class CDataOrderConditionInfo;
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
namespace nQuest { class SCHEDULE_ID; }

// Declarations
class cQuestSvReqCycleContentsPlayEnd;
class cQuestSvReqDecideDeliveryItem;
class cQuestSvReqGetActiveQuest;
class cQuestSvReqGetAreaBonusList;
class cQuestSvReqGetLightQuestList;
class cQuestSvReqGetPartyQuestProgressInfo;
class cQuestSvReqGetQuestCompleteList;
class cQuestSvReqGetRankingDataRankByQuestScheduleId;
class cQuestSvReqGetRecommendedQuestInfoList;
class cQuestSvReqGetSetQuestInfoList;
class cQuestSvReqGetSetQuestList;
class cQuestSvReqGetTutorialQuestList;
class cQuestSvReqGpCompleteLightQuestList;
class cQuestSvReqQuestCancel;
class cQuestSvReqQuestCompleteFlagClear;
class cQuestSvReqQuestOrder;
class cQuestSvReqQuestProgress;
class cQuestSvReqSendLeaderQuestOrderConditionInfo;
class cQuestSvReqSendLeaderWaitOrderQuestList;
class cQuestSvReqStartQuestTime;
class cQuestSvRequest;

// Type aliases from DWARF
using CommonU32Vec = MtTypedArray<CDataCommonU32>;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using OrderConditionInfoVec = MtTypedArray<CDataOrderConditionInfo>;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class cQuestSvRequest : public MtObject
{
public:
    enum R0
    {
        R0_NONE = 0,
        R0_REQUEST = 1,
        R0_WAIT_RESULT = 2,
        R0_END = 3,
    };
public:
    class MyDTI;
public:
    using PCallbackFunc = void(MtObject::*)(u32);
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
    virtual u32 getComId() const = 0;  // vtable slot 6
    cQuestSvRequest& setFromClass(MtObject* pFrom);
    const MtObject* getFromClass() const;
    cQuestSvRequest& setCallbackFunc(PCallbackFunc pCallbackFunc);
    bool isDelete() const;
    virtual bool isScheduleIdSame(nQuest::SCHEDULE_ID scheduleId) const;  // vtable slot 7
    bool waitsResult() const;
protected:
    u8 getRno() const;
    cQuestSvRequest& setRno(u8 rno0);
    bool hasFromClass() const;
    bool hasCallbackFunc() const;
    MT_CTSTR getRequestName() const;
public:
    virtual bool serverRequest() const = 0;  // vtable slot 8
    void forceDelete();
    void executeCallbackFuncError();
    virtual void resetParam();  // vtable slot 9
protected:
    virtual void executeCallbackFunc(u32 errorCode);  // vtable slot 10
    void executeRequest();
    void waitResult();
public:
    cQuestSvRequest();
    virtual ~cQuestSvRequest() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void move();  // vtable slot 11
protected:
    u8 mRno0;  // offset: 0x8
    MtObject* mpFromClass;  // offset: 0x10
    PCallbackFunc mpCallbackFunc;  // offset: 0x18
public:
    static MyDTI DTI;
};

class cQuestSvReqCycleContentsPlayEnd : public cQuestSvRequest
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
    virtual u32 getComId() const;  // vtable slot 6
    virtual bool serverRequest() const;  // vtable slot 8
public:
    static MyDTI DTI;
};

class cQuestSvReqDecideDeliveryItem : public cQuestSvRequest
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
    virtual u32 getComId() const;  // vtable slot 6
    virtual bool serverRequest() const;  // vtable slot 8
    nQuest::SCHEDULE_ID getScheduleId() const;
    cQuestSvReqDecideDeliveryItem& setScheduleId(nQuest::SCHEDULE_ID scheduleId);
    virtual bool isScheduleIdSame(nQuest::SCHEDULE_ID scheduleId) const;  // vtable slot 7
    cQuestSvReqDecideDeliveryItem();
protected:
    nQuest::SCHEDULE_ID mScheduleId;  // offset: 0x28
public:
    static MyDTI DTI;
};

class cQuestSvReqGetActiveQuest : public cQuestSvRequest
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
    virtual u32 getComId() const;  // vtable slot 6
    virtual bool serverRequest() const;  // vtable slot 8
public:
    static MyDTI DTI;
};

class cQuestSvReqGetAreaBonusList : public cQuestSvRequest
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
    virtual u32 getComId() const;  // vtable slot 6
    virtual bool serverRequest() const;  // vtable slot 8
public:
    static MyDTI DTI;
};

class cQuestSvReqGetLightQuestList : public cQuestSvRequest
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
    virtual u32 getComId() const;  // vtable slot 6
    virtual bool serverRequest() const;  // vtable slot 8
    u32 getBoardId() const;
    cQuestSvReqGetLightQuestList& setBoardId(u32 x);
    cQuestSvReqGetLightQuestList();
protected:
    u32 mBoardId;  // offset: 0x28
public:
    static MyDTI DTI;
};

class cQuestSvReqGetPartyQuestProgressInfo : public cQuestSvRequest
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
    virtual u32 getComId() const;  // vtable slot 6
    virtual bool serverRequest() const;  // vtable slot 8
public:
    static MyDTI DTI;
};

class cQuestSvReqGetQuestCompleteList : public cQuestSvRequest
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
    virtual u32 getComId() const;  // vtable slot 6
    virtual bool serverRequest() const;  // vtable slot 8
    nQuest::SV_QUEST_TYPE getQuestType() const;
    cQuestSvReqGetQuestCompleteList& setQuestType(nQuest::SV_QUEST_TYPE x);
    cQuestSvReqGetQuestCompleteList();
protected:
    nQuest::SV_QUEST_TYPE mQuestType;  // offset: 0x28
public:
    static MyDTI DTI;
};

class cQuestSvReqGetRankingDataRankByQuestScheduleId : public cQuestSvRequest
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
    virtual u32 getComId() const;  // vtable slot 6
    virtual bool serverRequest() const;  // vtable slot 8
    nQuest::SCHEDULE_ID getScheduleId() const;
    cQuestSvReqGetRankingDataRankByQuestScheduleId& setScheduleId(nQuest::SCHEDULE_ID scheduleId);
    virtual bool isScheduleIdSame(nQuest::SCHEDULE_ID scheduleId) const;  // vtable slot 7
    u32 getRank() const;
    cQuestSvReqGetRankingDataRankByQuestScheduleId& setRank(u32);
    u16 getNum() const;
    cQuestSvReqGetRankingDataRankByQuestScheduleId& setNum(u16);
protected:
    virtual void executeCallbackFunc(u32 errorCode);  // vtable slot 10
public:
    cQuestSvReqGetRankingDataRankByQuestScheduleId();
protected:
    nQuest::SCHEDULE_ID mScheduleId;  // offset: 0x28
    u32 mRank;  // offset: 0x38
    u16 mNum;  // offset: 0x3c
public:
    static MyDTI DTI;
};

class cQuestSvReqGetRecommendedQuestInfoList : public cQuestSvRequest
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
    virtual u32 getComId() const;  // vtable slot 6
    virtual bool serverRequest() const;  // vtable slot 8
protected:
    virtual void executeCallbackFunc(u32 errorCode);  // vtable slot 10
public:
    static MyDTI DTI;
};

class cQuestSvReqGetSetQuestInfoList : public cQuestSvRequest
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
    virtual u32 getComId() const;  // vtable slot 6
    virtual bool serverRequest() const;  // vtable slot 8
    u32 getAreaNo() const;
    cQuestSvReqGetSetQuestInfoList& setAreaNo(u32 x);
    cQuestSvReqGetSetQuestInfoList();
protected:
    virtual void executeCallbackFunc(u32 errorCode);  // vtable slot 10
protected:
    u32 mAreaNo;  // offset: 0x28
public:
    static MyDTI DTI;
};

class cQuestSvReqGetSetQuestList : public cQuestSvRequest
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
    virtual u32 getComId() const;  // vtable slot 6
    virtual bool serverRequest() const;  // vtable slot 8
    u32 getAreaNo() const;
    cQuestSvReqGetSetQuestList& setAreaNo(u32 x);
    cQuestSvReqGetSetQuestList();
protected:
    u32 mAreaNo;  // offset: 0x28
public:
    static MyDTI DTI;
};

class cQuestSvReqGetTutorialQuestList : public cQuestSvRequest
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
    virtual u32 getComId() const;  // vtable slot 6
    virtual bool serverRequest() const;  // vtable slot 8
    u32 getStageNo() const;
    cQuestSvReqGetTutorialQuestList& setStageNo(u32 x);
    cQuestSvReqGetTutorialQuestList();
protected:
    u32 mStageNo;  // offset: 0x28
public:
    static MyDTI DTI;
};

class cQuestSvReqGpCompleteLightQuestList : public cQuestSvRequest
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
    virtual u32 getComId() const;  // vtable slot 6
    virtual bool serverRequest() const;  // vtable slot 8
    u32 getBoardId() const;
    cQuestSvReqGpCompleteLightQuestList& setBoardId(u32 x);
    cQuestSvReqGpCompleteLightQuestList();
protected:
    u32 mBoardId;  // offset: 0x28
public:
    static MyDTI DTI;
};

class cQuestSvReqQuestCancel : public cQuestSvRequest
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
    virtual u32 getComId() const;  // vtable slot 6
    virtual bool serverRequest() const;  // vtable slot 8
    nQuest::SCHEDULE_ID getScheduleId() const;
    cQuestSvReqQuestCancel& setScheduleId(nQuest::SCHEDULE_ID scheduleId);
    virtual bool isScheduleIdSame(nQuest::SCHEDULE_ID scheduleId) const;  // vtable slot 7
    virtual void resetParam();  // vtable slot 9
    cQuestSvReqQuestCancel();
protected:
    nQuest::SCHEDULE_ID mScheduleId;  // offset: 0x28
public:
    static MyDTI DTI;
};

class cQuestSvReqQuestCompleteFlagClear : public cQuestSvRequest
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
    virtual u32 getComId() const;  // vtable slot 6
    virtual bool serverRequest() const;  // vtable slot 8
    nQuest::SCHEDULE_ID getScheduleId() const;
    cQuestSvReqQuestCompleteFlagClear& setScheduleId(nQuest::SCHEDULE_ID scheduleId);
    virtual bool isScheduleIdSame(nQuest::SCHEDULE_ID scheduleId) const;  // vtable slot 7
protected:
    nQuest::SCHEDULE_ID mScheduleId;  // offset: 0x28
public:
    static MyDTI DTI;
};

class cQuestSvReqQuestOrder : public cQuestSvRequest
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
    virtual u32 getComId() const;  // vtable slot 6
    virtual bool serverRequest() const;  // vtable slot 8
    nQuest::SCHEDULE_ID getScheduleId() const;
    cQuestSvReqQuestOrder& setScheduleId(nQuest::SCHEDULE_ID scheduleId);
    virtual bool isScheduleIdSame(nQuest::SCHEDULE_ID scheduleId) const;  // vtable slot 7
    cQuestSvReqQuestOrder();
protected:
    nQuest::SCHEDULE_ID mScheduleId;  // offset: 0x28
public:
    static MyDTI DTI;
};

class cQuestSvReqQuestProgress : public cQuestSvRequest
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
    virtual u32 getComId() const;  // vtable slot 6
    virtual bool serverRequest() const;  // vtable slot 8
    nQuest::SCHEDULE_ID getScheduleId() const;
    cQuestSvReqQuestProgress& setScheduleId(nQuest::SCHEDULE_ID scheduleId);
    virtual bool isScheduleIdSame(nQuest::SCHEDULE_ID scheduleId) const;  // vtable slot 7
    u32 getProcessNo() const;
    cQuestSvReqQuestProgress& setProcessNo(u32 x);
    u32 getCharacterId() const;
    cQuestSvReqQuestProgress& setCharacterId(u32 x);
    virtual void resetParam();  // vtable slot 9
    cQuestSvReqQuestProgress();
protected:
    nQuest::SCHEDULE_ID mScheduleId;  // offset: 0x28
    u32 mProcessNo;  // offset: 0x38
    u32 mCharacterId;  // offset: 0x3c
public:
    static MyDTI DTI;
};

class cQuestSvReqSendLeaderQuestOrderConditionInfo : public cQuestSvRequest
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
    virtual u32 getComId() const;  // vtable slot 6
    virtual bool serverRequest() const;  // vtable slot 8
    OrderConditionInfoVec& getOrderConditionInfoList();
    virtual ~cQuestSvReqSendLeaderQuestOrderConditionInfo();
private:
    OrderConditionInfoVec mOrderConditionInfoList;  // offset: 0x28
public:
    static MyDTI DTI;
};

class cQuestSvReqSendLeaderWaitOrderQuestList : public cQuestSvRequest
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
    virtual u32 getComId() const;  // vtable slot 6
    virtual bool serverRequest() const;  // vtable slot 8
    CommonU32Vec& getScheduleIdList();
    virtual ~cQuestSvReqSendLeaderWaitOrderQuestList();
private:
    CommonU32Vec mScheduleIdList;  // offset: 0x28
public:
    static MyDTI DTI;
};

class cQuestSvReqStartQuestTime : public cQuestSvRequest
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
    virtual u32 getComId() const;  // vtable slot 6
    virtual bool serverRequest() const;  // vtable slot 8
public:
    static MyDTI DTI;
};

inline void* cQuestSvReqCycleContentsPlayEnd::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cQuestSvReqDecideDeliveryItem::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cQuestSvReqGetActiveQuest::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cQuestSvReqGetAreaBonusList::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cQuestSvReqGetLightQuestList::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cQuestSvReqGetLightQuestList::cQuestSvReqGetLightQuestList() {
    this->mBoardId = 0;
}

inline void* cQuestSvReqGetPartyQuestProgressInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cQuestSvReqGetQuestCompleteList::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cQuestSvReqGetQuestCompleteList::cQuestSvReqGetQuestCompleteList() {
    this->mQuestType = static_cast<nQuest::SV_QUEST_TYPE>(0);
}

inline void* cQuestSvReqGetRankingDataRankByQuestScheduleId::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cQuestSvReqGetRecommendedQuestInfoList::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cQuestSvReqGetSetQuestInfoList::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cQuestSvReqGetSetQuestInfoList::cQuestSvReqGetSetQuestInfoList() {
    this->mAreaNo = 0;
}

inline void* cQuestSvReqGetSetQuestList::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cQuestSvReqGetSetQuestList::cQuestSvReqGetSetQuestList() {
    this->mAreaNo = 0;
}

inline void* cQuestSvReqGetTutorialQuestList::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cQuestSvReqGetTutorialQuestList::cQuestSvReqGetTutorialQuestList() {
    this->mStageNo = 0;
}

inline void* cQuestSvReqGpCompleteLightQuestList::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cQuestSvReqGpCompleteLightQuestList::cQuestSvReqGpCompleteLightQuestList() {
    this->mBoardId = 0;
}

inline void* cQuestSvReqQuestCancel::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cQuestSvReqQuestCompleteFlagClear::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cQuestSvReqQuestOrder::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cQuestSvReqQuestProgress::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cQuestSvReqSendLeaderQuestOrderConditionInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cQuestSvReqSendLeaderWaitOrderQuestList::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cQuestSvReqStartQuestTime::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cQuestSvRequest::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cQuestSvRequest::cQuestSvRequest() {
    this->mRno0 = 0;
    this->mpCallbackFunc = static_cast<cQuestSvRequest::PCallbackFunc>(0);
    this->mpFromClass = nullptr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void* cQuestSvReqCycleContentsPlayEnd::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cQuestSvReqCycleContentsPlayEnd::DTI)->memAlloc(sz, align, ::cQuestSvReqCycleContentsPlayEnd::DTI.::MtDTI::getID());
}

inline void cQuestSvReqCycleContentsPlayEnd::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cQuestSvReqCycleContentsPlayEnd::DTI)->memFree(p_addr);
}

inline void cQuestSvReqDecideDeliveryItem::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cQuestSvReqDecideDeliveryItem::DTI)->memFree(p_addr);
}

inline void* cQuestSvReqGetActiveQuest::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cQuestSvReqGetActiveQuest::DTI)->memAlloc(sz, align, ::cQuestSvReqGetActiveQuest::DTI.::MtDTI::getID());
}

inline void cQuestSvReqGetActiveQuest::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cQuestSvReqGetActiveQuest::DTI)->memFree(p_addr);
}

inline void* cQuestSvReqGetAreaBonusList::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cQuestSvReqGetAreaBonusList::DTI)->memAlloc(sz, align, ::cQuestSvReqGetAreaBonusList::DTI.::MtDTI::getID());
}

inline void cQuestSvReqGetAreaBonusList::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cQuestSvReqGetAreaBonusList::DTI)->memFree(p_addr);
}

inline void* cQuestSvReqGetLightQuestList::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cQuestSvReqGetLightQuestList::DTI)->memAlloc(sz, align, ::cQuestSvReqGetLightQuestList::DTI.::MtDTI::getID());
}

inline void cQuestSvReqGetLightQuestList::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cQuestSvReqGetLightQuestList::DTI)->memFree(p_addr);
}

inline void* cQuestSvReqGetPartyQuestProgressInfo::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cQuestSvReqGetPartyQuestProgressInfo::DTI)->memAlloc(sz, align, ::cQuestSvReqGetPartyQuestProgressInfo::DTI.::MtDTI::getID());
}

inline void cQuestSvReqGetPartyQuestProgressInfo::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cQuestSvReqGetPartyQuestProgressInfo::DTI)->memFree(p_addr);
}

inline void* cQuestSvReqGetQuestCompleteList::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cQuestSvReqGetQuestCompleteList::DTI)->memAlloc(sz, align, ::cQuestSvReqGetQuestCompleteList::DTI.::MtDTI::getID());
}

inline void cQuestSvReqGetQuestCompleteList::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cQuestSvReqGetQuestCompleteList::DTI)->memFree(p_addr);
}

inline void cQuestSvReqGetRankingDataRankByQuestScheduleId::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cQuestSvReqGetRankingDataRankByQuestScheduleId::DTI)->memFree(p_addr);
}

inline void* cQuestSvReqGetRecommendedQuestInfoList::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cQuestSvReqGetRecommendedQuestInfoList::DTI)->memAlloc(sz, align, ::cQuestSvReqGetRecommendedQuestInfoList::DTI.::MtDTI::getID());
}

inline void cQuestSvReqGetRecommendedQuestInfoList::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cQuestSvReqGetRecommendedQuestInfoList::DTI)->memFree(p_addr);
}

inline void* cQuestSvReqGetSetQuestInfoList::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cQuestSvReqGetSetQuestInfoList::DTI)->memAlloc(sz, align, ::cQuestSvReqGetSetQuestInfoList::DTI.::MtDTI::getID());
}

inline void cQuestSvReqGetSetQuestInfoList::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cQuestSvReqGetSetQuestInfoList::DTI)->memFree(p_addr);
}

inline void* cQuestSvReqGetSetQuestList::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cQuestSvReqGetSetQuestList::DTI)->memAlloc(sz, align, ::cQuestSvReqGetSetQuestList::DTI.::MtDTI::getID());
}

inline void cQuestSvReqGetSetQuestList::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cQuestSvReqGetSetQuestList::DTI)->memFree(p_addr);
}

inline void* cQuestSvReqGetTutorialQuestList::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cQuestSvReqGetTutorialQuestList::DTI)->memAlloc(sz, align, ::cQuestSvReqGetTutorialQuestList::DTI.::MtDTI::getID());
}

inline void cQuestSvReqGetTutorialQuestList::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cQuestSvReqGetTutorialQuestList::DTI)->memFree(p_addr);
}

inline void* cQuestSvReqGpCompleteLightQuestList::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cQuestSvReqGpCompleteLightQuestList::DTI)->memAlloc(sz, align, ::cQuestSvReqGpCompleteLightQuestList::DTI.::MtDTI::getID());
}

inline void cQuestSvReqGpCompleteLightQuestList::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cQuestSvReqGpCompleteLightQuestList::DTI)->memFree(p_addr);
}

inline void cQuestSvReqQuestCancel::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cQuestSvReqQuestCancel::DTI)->memFree(p_addr);
}

inline void cQuestSvReqQuestCompleteFlagClear::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cQuestSvReqQuestCompleteFlagClear::DTI)->memFree(p_addr);
}

inline void cQuestSvReqQuestOrder::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cQuestSvReqQuestOrder::DTI)->memFree(p_addr);
}

inline void cQuestSvReqQuestProgress::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cQuestSvReqQuestProgress::DTI)->memFree(p_addr);
}

inline void cQuestSvReqSendLeaderQuestOrderConditionInfo::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cQuestSvReqSendLeaderQuestOrderConditionInfo::DTI)->memFree(p_addr);
}

inline void cQuestSvReqSendLeaderWaitOrderQuestList::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cQuestSvReqSendLeaderWaitOrderQuestList::DTI)->memFree(p_addr);
}

inline void* cQuestSvReqStartQuestTime::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cQuestSvReqStartQuestTime::DTI)->memAlloc(sz, align, ::cQuestSvReqStartQuestTime::DTI.::MtDTI::getID());
}

inline void cQuestSvReqStartQuestTime::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cQuestSvReqStartQuestTime::DTI)->memFree(p_addr);
}
