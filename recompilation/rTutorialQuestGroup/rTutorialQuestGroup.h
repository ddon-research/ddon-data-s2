#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/cResource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtObject;
class MtPropertyList;
class MtStream;

// Declarations
class rTutorialQuestGroup;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class rTutorialQuestGroup : public cResource
{
public:
    class MyDTI;
    class cGroup;
public:
    using GroupArray = MtTypedArray<rTutorialQuestGroup::cGroup>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cGroup : public MtObject
    {
    public:
        class MyDTI;
        class cQuestId;
    public:
        using QuestIdArray = MtTypedArray<rTutorialQuestGroup::cGroup::cQuestId>;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class cQuestId : public MtObject
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
            u32 getId() const;
            cQuestId();
            cQuestId(u32 id);
            virtual ~cQuestId();
            virtual void createProperty(MtPropertyList& s);  // vtable slot 4
            virtual void save(MtDataWriter& w);  // vtable slot 6
            virtual void load(MtDataReader& r);  // vtable slot 7
        protected:
            u32 mId;  // offset: 0x8
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
        u32 getGroupId() const;
        u32 getQuestIdNum() const;
        u32 getQuestId(u32 idx) const;
        cGroup();
        cGroup(u32 groupId);
        virtual ~cGroup();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual void save(MtDataWriter& w);  // vtable slot 6
        virtual void load(MtDataReader& r);  // vtable slot 7
    public:
        QuestIdArray mQuestIds;  // offset: 0x8
        u32 mGroupId;  // offset: 0x28
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
    const cGroup* getGroup(u32 groupId) const;
    u32 getMagicHeader() const;
    u16 getDataVersion() const;
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    rTutorialQuestGroup();
    virtual ~rTutorialQuestGroup();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual bool load(MtStream& in);  // vtable slot 11
protected:
    GroupArray mGroups;  // offset: 0x70
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline rTutorialQuestGroup::cGroup::cGroup() {
    this->mGroupId = static_cast<u32>(0);
}
