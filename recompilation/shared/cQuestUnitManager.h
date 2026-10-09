#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "cOmControl.h"
#include "uControlNpc.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtPropertyList;
class cOmControl;
class cQuestGroup;
class cQuestSet;
class rQuestList;
class uControlNpc;

// Declarations
class cQuestUnitGroup;
class cQuestUnitManager;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cQuestUnitGroup : public MtObject
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
    cQuestUnitGroup();
    virtual ~cQuestUnitGroup();
    void init(cQuestGroup* pGroup, u32 QuestId);
    void move();
    void release();
    void updateOm(cQuestSet* pSet, u32 idx);
    void updateNpc(cQuestSet* pSet, u32 idx);
    cOmControl* createOm(cQuestSet* pSet);
    uControlNpc* createNpc(cQuestSet* pSet);
    u32 getGroupNo();
protected:
    cQuestGroup* mpGroup;  // offset: 0x8
    MtTypedArray<cOmControl> mCtrlListOm;  // offset: 0x10
    MtTypedArray<uControlNpc> mCtrlListNpc;  // offset: 0x30
    u32 mQuestId;  // offset: 0x50
public:
    static MyDTI DTI;
};

class cQuestUnitManager : public MtObject
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
    cQuestUnitManager();
    virtual ~cQuestUnitManager();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void init(u32 questId, s32 stageNo, rQuestList* pRes);
    void move();
    void release();
    cQuestUnitGroup* getGroup(u32) const;
    u32 getGroupNum() const;
    u32 getQuestId() const;
    s32 getStageNo() const;
private:
    u32 mQuestId;  // offset: 0x8
    s32 mStageNo;  // offset: 0xc
    rQuestList* mpQuestList;  // offset: 0x10
    MtTypedArray<cQuestUnitGroup> mGroupList;  // offset: 0x18
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cQuestUnitGroup::cQuestUnitGroup() {
    this->mpGroup = static_cast<cQuestGroup*>(nullptr);
    this->mQuestId = static_cast<u32>(0);
    this->mCtrlListOm.::MtArray::mAutoDelete = false;
    this->mCtrlListNpc.::MtArray::mAutoDelete = false;
}
