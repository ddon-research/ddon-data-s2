#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtProperty;
class MtPropertyList;
class MtString;
class MtUI;
class rGUIMessage;
class rMsgSet;
class rSituationMsgCtrl;
class rSoundStreamRequest;

// Declarations
class cTalkMsgData;
class cVoiceReqTbl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cVoiceReqTbl : public MtObject
{
public:
    cVoiceReqTbl();
    virtual ~cVoiceReqTbl();
public:
    rSoundStreamRequest* mpRequest;  // offset: 0x8
    u32 mNpcId;  // offset: 0x10
};

class cTalkMsgData : public MtObject
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
    cTalkMsgData();
    virtual ~cTalkMsgData();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    void reset();
    void initData(rGUIMessage* pMsgData, rMsgSet* pMsgSetData);
    void setMsgData(rGUIMessage* pMsgData);
    void setMsgSetData(rMsgSet* pMsgSetData);
    void setVoiceReqTblFromQuest(u32 QuestNo);
    void setVoiceReqTblFromEvent(u32 StageNo, u32 EventNo);
    void setVoiceReqTblCore(MtString Path);
    void setDispGrpNo(u32 GrpNo);
    void setDispGrpSerialNo(u32 SerialNo);
    void setDispPageNo(u32 PageNo);
    bool addDispPageNo();
    u32 getDispPageNum();
    u32 getDispTime();
    MT_CTSTR getMessage(u32 GrpNo, u32 PageNo);
    MT_CTSTR getMessage();
    u32 getGrpDataNum();
    u32 getDispPageNo();
    void setDispGrpNoFromGrpType(u32 GrpType, bool IsChkHistory, bool IsForceUseGrp);
    bool isExistGrpType(u32 GrpType, bool IsChkHistory);
    void setBaseMsgGrp();
    u32 getTalkNpcId();
    u32 getTalkNpcId(u32 Idx);
    bool isDispNpcName();
    u32 getDispGrpType();
    u32 getDispMsgType();
    s32 getVoiceReqNo();
    rSoundStreamRequest* getVoiceReqResource(u32 NpcId);
    u32 getSetMotionNo();
protected:
    rGUIMessage* mpMsgData;  // offset: 0x8
    rMsgSet* mpMsgSetData;  // offset: 0x10
    rSituationMsgCtrl* mpSituation;  // offset: 0x18
    MtTypedArray<cVoiceReqTbl> mVoiceReqData;  // offset: 0x20
    u32 mDispGrpNo;  // offset: 0x40
    u32 mDispPageNo;  // offset: 0x44
    s32* mpDispedMsgNo;  // offset: 0x48
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline u32 cTalkMsgData::getDispPageNo() {
    return this->mDispPageNo;
}
