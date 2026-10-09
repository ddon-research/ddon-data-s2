#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/MtObject.h"
#include "../shared/MtString.h"
#include "../shared/rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtObject;
class MtPropertyList;
class MtString;
class MtVector3;

// Declarations
class cStageMap;
class rStageMap;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class cStageMap : public MtObject
{
public:
    class MyDTI;
    class cParam;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cParam : public MtObject
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
        cParam();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void copy(cStageMap::cParam* src);
        bool load(MtDataReader& r);
        bool save(MtDataWriter& w);
    public:
        u32 mAreaNo;  // offset: 0x8
        f32 mSize;  // offset: 0xc
        MtString mModelName;  // offset: 0x10
        MtVector3 mConnectPos;  // offset: 0x20
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
    cStageMap();
    virtual ~cStageMap();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    cParam* getParam(u32 index) const;
    u32 getParamNum() const;
    MtTypedArray<cParam>* getParam();
    void addParam(cParam* p);
    void copy(cStageMap* pSrc);
public:
    u16 mStageNo;  // offset: 0x8
    u16 mPartsNum;  // offset: 0xa
    f32 mOffsetY;  // offset: 0xc
    u32 mStageFlag;  // offset: 0x10
    MtTypedArray<cParam> mParamList;  // offset: 0x18
    static MyDTI DTI;
    static const u16 DATA_VERSION = 1;
};

class rStageMap : public rTbl2<cStageMap>
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
    virtual bool loadData(MtDataReader& in, cStageMap* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
    cStageMap* searchStageMap(u32 stageNo);
    bool isField(u32 stageNo);
    bool isPartsStage(u32 stageNo);
    bool isMergoda(u32 stageNo);
    u32 getPartsNum(u32 stageNo);
    f32 getPartsSizeZLength(u32 stageNo, u32 uIdx);
    f32 getPartsOffsetY(u32 stageNo, u32 uIdx);
    MT_CTSTR getPartsFileName(u32 stageNo, u32 uIdx);
    MtVector3 getPartsConnectPos(u32 stageNo, u32 uIdx);
public:
    static MyDTI DTI;
};
