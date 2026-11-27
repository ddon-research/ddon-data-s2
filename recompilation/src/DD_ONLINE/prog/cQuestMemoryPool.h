#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "cQuestFunctionManagerBAse.h"
#include "nQuest.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cQuestTask;
namespace nQuest { class cQuestCommand; }

// Declarations
class cQuestMemoryPool;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cQuestMemoryPool : public cQuestFunctionManagerBase
{
public:
    enum
    {
        POOL_QUEST_COMMAND_SIZE = 2400,
    };
public:
    template <typename _ManagedClass> class cQuestMemoryBlock;
    class MyDTI;
    class cQuestMemoryCore;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cQuestMemoryCore : public MtObject
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
        bool isUsed() const;
        cQuestMemoryPool::cQuestMemoryCore& setUsed(bool isUsed);
        cQuestMemoryCore();
        virtual ~cQuestMemoryCore();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        bool mIsUsed;  // offset: 0x8
    public:
        static MyDTI DTI;
    };
public:
    template <typename _ManagedClass>
    class cQuestMemoryBlock : public cQuestMemoryPool::cQuestMemoryCore
    {
    public:
        _ManagedClass* getManagedClass();
    protected:
        _ManagedClass mManagedClass;  // offset: 0x10
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
    u32 getMemoryBlockUseNum() const;
    nQuest::cQuestCommand* allocQuestCommand(cQuestTask* pTask);
    void freeQuestCommand(nQuest::cQuestCommand* pCommand);
    virtual void release();  // vtable slot 6
    cQuestMemoryPool();
    virtual ~cQuestMemoryPool();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
protected:
    cQuestMemoryBlock<nQuest::cQuestCommand> mQuestCommandPool[2400];  // offset: 0x8
    u32 mUsedNum;  // offset: 0x1c208
public:
    static MyDTI DTI;
};

inline void* cQuestMemoryPool::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cQuestMemoryPool::cQuestMemoryCore::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cQuestMemoryPool::cQuestMemoryCore::cQuestMemoryCore() {
    this->mIsUsed = false;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* cQuestMemoryPool::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::cQuestMemoryPool::DTI);
}

inline void cQuestMemoryPool::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cQuestMemoryPool::DTI)->memFree(p_addr);
}

inline void* cQuestMemoryPool::cQuestMemoryCore::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cQuestMemoryPool::cQuestMemoryCore::DTI)->memAlloc(sz, align, ::cQuestMemoryPool::cQuestMemoryCore::DTI.::MtDTI::getID());
}

inline void cQuestMemoryPool::cQuestMemoryCore::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cQuestMemoryPool::cQuestMemoryCore::DTI)->memFree(p_addr);
}
