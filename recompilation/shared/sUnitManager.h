#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "cSystem.h"
#include "nCastUtility.h"
#include "uBaseModel.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector2;
class cFSMUnit;
class cUseComp;
namespace nLayout { struct stLayoutID; }
class uBaseModel;
class uDDOBaseModel;
class uDDOModel;

// Declarations
class sUnitManager;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

class sUnitManager : public cSystem
{
    // inferred: cFSMUnit::isExistEnemyUnit names sUnitManager::mRefArray.::MtArray::mLength
    friend class cFSMUnit;
public:
    enum
    {
        ADD_TYPE_TOP = 0,
        ADD_TYPE_BOTTOM = 1,
    };
public:
    class MyDTI;
    class cLODDistData;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cLODDistData : public MtObject
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
        cLODDistData();
        cLODDistData(f32 low, f32 med, sUnitManager* um);
        // Address: 0x01acfe50 - 0x01acfe51 (1 bytes)
        virtual ~cLODDistData() {}
        f32 getLow();
        void setLow(f32 set);
        f32 getMed();
        void setMed(f32 set);
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    private:
        f32 mLow;  // offset: 0x8
        f32 mMed;  // offset: 0xc
        sUnitManager* mpOwner;  // offset: 0x10
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
    sUnitManager();
    virtual ~sUnitManager();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void init();  // vtable slot 10
    virtual void reset();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void clear();  // vtable slot 11
    virtual bool update();  // vtable slot 12
    void addUnit(uBaseModel* p, u32 unique_id, u32 line, u64 unit_group, u32 add_type);
    static estUnitType<uDDOModel, void> newDDOModel(const MtDTI& dti, cUseComp* info);
    static estUnitType<uDDOBaseModel, void> newDDOBaseModel(const MtDTI& dti);
    estUnitType<uBaseModel, void> createUnit(const MtDTI& dti, u32 unique_id, u32 line, u64 unit_group, u32 add_type, cUseComp* info);
    virtual void releaseUnit(uBaseModel* p);  // vtable slot 13
    virtual void releaseUnit(u32 uniqId);  // vtable slot 14
    void releaseUnitAll();
    MtObject* getUnitDTI(MtDTI& dti, u32 index);
    estUnitType<uBaseModel, void> getUnitDirect(u32 index);
    s32 getUnitNumAll();
    u32 getUnitNum();
    virtual uBaseModel* getLayoutUnit(u32 uid);  // vtable slot 15
    uBaseModel* getLayoutUnit(nLayout::stLayoutID lot, u32 no);
    void releaseLayoutUnitGroup(nLayout::stLayoutID lot);
    bool compareLayoutID(nLayout::stLayoutID l, nLayout::stLayoutID r);
protected:
    bool isExist(uBaseModel* pMdl);
    virtual bool isEnableUnit(uBaseModel* pUnit);  // vtable slot 16
    // Address: 0x01ac3eb0 - 0x01ac3eb1 (1 bytes)
    virtual void returnTicket(u32 uniqId) {}  // vtable slot 17
private:
    void createLodDistData();
public:
    void setLodDistDataToAllUnit();
    virtual u32 getLodDistDataKindNum();  // vtable slot 18
    virtual u32 getLodDistDataKind(uBaseModel* bm);  // vtable slot 19
    virtual MtVector2 getLosDistDataParam(u32 num);  // vtable slot 20
    cLODDistData* getLodDistData(u32 index);
    void setLodDistData(cLODDistData*, u32);
    u32 getLodDistDataNum();
    void setLodDistDataNum(u32);
    // Address: 0x01ac6f50 - 0x01ac6f51 (1 bytes)
    virtual void setLODDist(uBaseModel* bm) {}  // vtable slot 21
protected:
    MtTypedArray<uBaseModel> mRefArray;  // offset: 0x18
    MtTypedArray<uBaseModel> mAddArray;  // offset: 0x38
    MtTypedArray<uBaseModel> mDelArray;  // offset: 0x58
    bool mbModify;  // offset: 0x78
private:
    MtTypedArray<cLODDistData> mLODDistData;  // offset: 0x80
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline sUnitManager::cLODDistData::cLODDistData() {
    this->mLow = 3000.0f;
    this->mMed = 1000.0f;
    this->mpOwner = static_cast<sUnitManager*>(nullptr);
}
