#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
namespace nUserSession { class CPacket_S2C_QUEST_PHASE_NOTICE; }

// Declarations
class cQuestSvNotQuestPhase;
class cQuestSvNotice;
class cQuestSvNoticeCallback;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cQuestSvNotice : public MtObject
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
    virtual void* getNoticePacket() const = 0;  // vtable slot 6
    cQuestSvNotice();
    virtual ~cQuestSvNotice() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void move();  // vtable slot 7
public:
    static MyDTI DTI;
};

class cQuestSvNoticeCallback : public MtObject
{
public:
    class MyDTI;
public:
    using PCallbackFunc = void(MtObject::*)(void*);
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
    const MtDTI& getNoticeClassDTI() const;
    cQuestSvNoticeCallback& setNoticeDTI(const MtDTI& noticeClassDti);
    cQuestSvNoticeCallback& setFromClass(MtObject* pFrom);
    cQuestSvNoticeCallback& setCallbackFunc(PCallbackFunc pCallbackFunc);
protected:
    bool hasFromClass() const;
    bool hasCallbackFunc() const;
public:
    virtual void executeCallbackFunc(void* pPacket);  // vtable slot 6
    cQuestSvNoticeCallback();
    virtual ~cQuestSvNoticeCallback();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
protected:
    MtDTI mNoticeClassDti;  // offset: 0x8
    MtObject* mpFromClass;  // offset: 0x40
    PCallbackFunc mpCallbackFunc;  // offset: 0x48
public:
    static MyDTI DTI;
};

class cQuestSvNotQuestPhase : public cQuestSvNotice
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
    virtual void* getNoticePacket() const;  // vtable slot 6
    nUserSession::CPacket_S2C_QUEST_PHASE_NOTICE* getPacket() const;
    cQuestSvNotQuestPhase& setPacket(nUserSession::CPacket_S2C_QUEST_PHASE_NOTICE* pPacket);
    cQuestSvNotQuestPhase();
    virtual ~cQuestSvNotQuestPhase();
public:
    nUserSession::CPacket_S2C_QUEST_PHASE_NOTICE* mpPacket;  // offset: 0x8
    static MyDTI DTI;
};

inline cQuestSvNotQuestPhase::cQuestSvNotQuestPhase() {
    this->mpPacket = nullptr;
}

inline cQuestSvNotice::cQuestSvNotice() {
}

inline cQuestSvNoticeCallback::cQuestSvNoticeCallback() {
    this->mpCallbackFunc = static_cast<cQuestSvNoticeCallback::PCallbackFunc>(0);
    this->mpFromClass = nullptr;
}
