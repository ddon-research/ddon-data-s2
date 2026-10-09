#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtProperty;
class MtPropertyList;
class MtUI;
namespace nQuest { class SCHEDULE_ID; }

// Declarations
class cQuestSvRequest;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
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
