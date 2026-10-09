#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "cResource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtUI;

// Declarations
class rFieldAreaList;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class rFieldAreaList : public cResource
{
public:
    class MyDTI;
    class cFieldAreaInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cFieldAreaInfo : public MtObject
    {
    public:
        class MyDTI;
        class cStageNo;
    public:
        using StageNoArray = MtTypedArray<rFieldAreaList::cFieldAreaInfo::cStageNo>;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class cStageNo : public MtObject
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
            cStageNo();
            cStageNo(s32 stageNo);
            virtual void createProperty(MtPropertyList& s);  // vtable slot 4
            void load(MtDataReader& r);
            void save(MtDataWriter& w);
        public:
            s32 mStageNo;  // offset: 0x8
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
        const StageNoArray& getStageNoList() const;
        u32 getGMDIndex() const;
        cFieldAreaInfo();
        virtual ~cFieldAreaInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    public:
        StageNoArray mStageNoList;  // offset: 0x8
        StageNoArray mBelongStageNoList;  // offset: 0x28
        u32 mFieldAreaId;  // offset: 0x48
        u32 mGmdIdx;  // offset: 0x4c
        u32 mVersionId;  // offset: 0x50
        u16 mLandId;  // offset: 0x54
        u16 mAreaId;  // offset: 0x56
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
    u32 getDispFieldAreaNum(u32 landId, u32 areaId) const;
    u32 getDispFieldAreaId(u32 landId, u32 areaId, u32 idx) const;
    const cFieldAreaInfo* getFieldAreaInfo(u32 fieldAreaId) const;
    const cFieldAreaInfo* getFieldAreaInfoFromStageNo(s32 stageNo) const;
    const cFieldAreaInfo* getFieldAreaInfoFromLandArea(u32 landId, u32 areaId, u32 idx) const;
    u32 getFieldAreaIdFromBelongStage(s32 stageNo) const;
    u32 getFieldAreaIdFromStageList(s32 stageNo) const;
    s32 getStageNoFromFieldAreaId(u32 idx, u32 stageNo) const;
    u32 getMagicHeader() const;
    u32 getDataVersion() const;
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    rFieldAreaList();
    virtual ~rFieldAreaList();
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
protected:
    void destruct();
protected:
    cFieldAreaInfo* mpArray;  // offset: 0x70
    u32 mArrayNum;  // offset: 0x78
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline rFieldAreaList::cFieldAreaInfo::cStageNo::cStageNo() {
    this->mStageNo = static_cast<s32>(-1);
}
