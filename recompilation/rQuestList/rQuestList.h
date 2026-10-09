#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/MtString.h"
#include "../shared/cResource.h"
#include "../shared/nLayout.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtString;
class MtUI;
class cSetInfo;
class cUnit;
namespace nLayout { struct stLayoutID; }

// Declarations
class cQuestGroup;
class cQuestSet;
class cQuestStage;
class rQuestList;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cQuestSet : public MtObject
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
    cQuestSet();
    virtual ~cQuestSet();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void createPropertyForTool(MtPropertyList& s);
    void setDisp(bool isDisp);
    void setLayoutInfo(u32 questId, u32 stageNo, u32 groupNo);
    s32 getSetID();
    void setSetID(s32 id);
public:
    cUnit* mpUnit;  // offset: 0x8
    cSetInfo* mpSetInfo;  // offset: 0x10
    s32 mSetID;  // offset: 0x18
    u32 mKind;  // offset: 0x1c
    u32 mUnitNo;  // offset: 0x20
    u32 mOmID;  // offset: 0x24
    MtString mComment;  // offset: 0x28
protected:
    u32 mQuestId;  // offset: 0x30
    nLayout::stLayoutID mLayoutId;  // offset: 0x34
    bool mIsDisp;  // offset: 0x38
public:
    static MyDTI DTI;
};

class cQuestGroup : public MtObject
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
    cQuestGroup();
    virtual ~cQuestGroup();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    s32 getCondition() const;
    void setCondition(s32 condition);
    s32 getEraseCondition() const;
    bool hasEraseCondition() const;
    void setEraseCondition(bool b);
public:
    MtTypedArray<cQuestSet> mQusetSet;  // offset: 0x8
    MtString mComment;  // offset: 0x28
    u32 mGroupNo;  // offset: 0x30
protected:
    s32 mCondition;  // offset: 0x34
    s32 mEraseCondition;  // offset: 0x38
public:
    static MyDTI DTI;
};

class cQuestStage : public MtObject
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
    cQuestStage();
    virtual ~cQuestStage();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    s32 mStageNo;  // offset: 0x8
    MtTypedArray<cQuestGroup> mQuestGrp;  // offset: 0x10
    static MyDTI DTI;
};

class rQuestList : public cResource
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
    rQuestList();
    virtual ~rQuestList();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    cQuestStage* getQuestStage(u32 stageNo);
    cQuestGroup* getQuestGroup(u32 stageNo, u32 grpNo);
    cQuestSet* getQuestSet(u32 stageNo, u32 grpNo, u32 setNo);
public:
    bool mbNoDelete;  // offset: 0x70
    MtTypedArray<cQuestStage> mQuestStage;  // offset: 0x78
    static MyDTI DTI;
    static const u32 DATA_VERSION;
};

// Inline, no code of its own: checked where it is inlined.
inline cQuestGroup::cQuestGroup() {
    this->mGroupNo = static_cast<u32>(16);
    this->mCondition = static_cast<s32>(0);
    this->mEraseCondition = static_cast<s32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline cQuestSet::cQuestSet() {
    this->mSetID = static_cast<s32>(0);
    this->mpSetInfo = static_cast<cSetInfo*>(nullptr);
    this->mpUnit = static_cast<cUnit*>(nullptr);
    this->mUnitNo = static_cast<u32>(16);
    this->mOmID = static_cast<u32>(0);
    this->mKind = static_cast<u32>(0);
    this->mIsDisp = false;
    this->mQuestId = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline cQuestStage::cQuestStage() {
    this->mStageNo = static_cast<s32>(0);
}
