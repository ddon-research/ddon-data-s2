#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtString.h"
#include "../shared/MtSynchronize.h"
#include "../shared/cUIObject.h"

// Forward declarations
class MtAllocator;
class MtCriticalSection;
class MtDTI;
class MtObject;
class MtString;
class cArcLoaderBase;
namespace rAcquirement { class cNormalSkillData; }
namespace rAcquirement { class rNormalSkillData; }
class rGUIMessage;

// Declarations
namespace cAcquirement { class cNormalSkillData; }
namespace cAcquirement { class cSkillDataBase; }

// Type aliases from DWARF
using u32 = unsigned int;
using ARC_TAGID = u32;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using TICKET = cArcLoaderBase*;
using _Sizet = long unsigned int;
using size_t = _Sizet;

namespace cAcquirement {
    class cSkillDataBase : public ::cUIObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        cSkillDataBase();
        virtual ~cSkillDataBase();
        void release();
        void load(u32 job_id);
        bool updateLoad();
        virtual bool isComplete() const;  // vtable slot 6
        u32 getJobId() const;
    protected:
        // Address: 0x0194f9b0 - 0x0194f9b1 (1 bytes)
        virtual void releaseResource() {}  // vtable slot 7
        // Address: 0x0194f9c0 - 0x0194f9c1 (1 bytes)
        virtual void loadResource() {}  // vtable slot 8
        MT_CTSTR getMsg(rGUIMessage* pRes, u32 index) const;
    private:
        TICKET mTicket;  // offset: 0x8
        u32 mJobId;  // offset: 0x10
        MtCriticalSection mCS;  // offset: 0x18
    protected:
        ARC_TAGID mTag;  // offset: 0x20
        MtString mTagStr;  // offset: 0x28
    public:
        static MyDTI DTI;
    };
}  // namespace cAcquirement

namespace cAcquirement {
    class cNormalSkillData : public cAcquirement::cSkillDataBase
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        cNormalSkillData();
        virtual ~cNormalSkillData();
        virtual bool isComplete() const;  // vtable slot 6
        const rAcquirement::cNormalSkillData* getDataFromSkillIndex(u32 skill_index) const;
        const rAcquirement::cNormalSkillData* getDataFromPreIndex(u32 pre_index) const;
        const rAcquirement::cNormalSkillData* getData(u32 index) const;
        u32 length() const;
        u32 getSkillIndex(u32 index) const;
        u32 getMsgIndex(u32 skill_index) const;
        u32 getIconId(u32 skill_index) const;
        MT_CTSTR getInfoMsg(u32 skill_index) const;
        MT_CTSTR getCommandMsg(u32 skill_index) const;
        MT_CTSTR getInfo(u32 index) const;
        MT_CTSTR getCommand(u32 index) const;
    private:
        virtual void releaseResource();  // vtable slot 7
        virtual void loadResource();  // vtable slot 8
    private:
        rAcquirement::rNormalSkillData* mpData;  // offset: 0x30
        rGUIMessage* mpMsgInfo;  // offset: 0x38
        rGUIMessage* mpMsgCommand;  // offset: 0x40
    public:
        static MyDTI DTI;
    };
}  // namespace cAcquirement
