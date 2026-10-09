#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/cQuestFunctionManagerBAse.h"
#include "cQuestSvRequest.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class cQuestSvReqQuestProgress;
class cQuestSvRequest;
namespace nQuest { class SCHEDULE_ID; }

// Declarations
class cQuestSvRequestManager;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cQuestSvRequestManager : public cQuestFunctionManagerBase
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
    static cQuestSvRequest* pushRequest(const MtDTI& requestClassDti);
    static void popRequest(const MtObject* pFromClass);
    static bool hasRequest(const MtObject* pFromClass);
    static bool canRequest(bool isDispAnnounce);
    bool isEmpty() const;
    bool canReqQuestProgres() const;
protected:
    cQuestSvRequestManager& pushRequest(cQuestSvRequest* pSvReq);
    cQuestSvRequestManager& removeRequest(cQuestSvRequest* pRequest);
    cQuestSvRequestManager& removeRequest(const MtObject* pFromClass);
    bool requests(const MtObject* pFromClass) const;
public:
    void updateRequest();
    void finalGame();
    void deleteRequestQueue(nQuest::SCHEDULE_ID scheduleId);
    virtual void release();  // vtable slot 6
    void cancelQuestProgress();
    cQuestSvRequestManager();
    virtual ~cQuestSvRequestManager();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
protected:
    f32 mQuesetRequestElapsedTime;  // offset: 0x8
    MtTypedArray<cQuestSvRequest> mQuestSvRequestQueue;  // offset: 0x10
    cQuestSvReqQuestProgress* mpQuestProgressReq;  // offset: 0x30
public:
    static MyDTI DTI;
};
