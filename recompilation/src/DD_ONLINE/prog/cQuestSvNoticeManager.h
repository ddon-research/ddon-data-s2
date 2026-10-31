#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "cQuestFunctionManagerBAse.h"
#include "cQuestSvNotice.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cQuestSvNotice;
class cQuestSvNoticeCallback;

// Declarations
class cQuestSvNoticeManager;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cQuestSvNoticeManager : public cQuestFunctionManagerBase
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
    static cQuestSvNoticeCallback* addCallbackFunc(const MtDTI& callbackClassDti, const MtDTI& noticeClassDti);
    bool isEmpty() const;
protected:
    cQuestSvNoticeManager& addCallbackFunc(cQuestSvNoticeCallback* pSvNotCallback);
    cQuestSvNoticeManager& pushNotice(cQuestSvNotice* pSvNot);
public:
    void updateNotice();
    virtual void release();  // vtable slot 6
    void popNotice(const MtDTI& popNoticeDti);
protected:
    void executeCallback(cQuestSvNotice* pNotice);
public:
    cQuestSvNoticeManager();
    virtual ~cQuestSvNoticeManager();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
protected:
    MtTypedArray<cQuestSvNoticeCallback> mCallbackList;  // offset: 0x8
    MtTypedArray<cQuestSvNotice> mNoticeList;  // offset: 0x28
public:
    static MyDTI DTI;
};
