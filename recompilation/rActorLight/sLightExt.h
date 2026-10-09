#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/MtObject.h"
#include "../shared/MtString.h"
#include "../shared/rTable.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
struct MtFloat2;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtString;
class MtUI;
class MtVector3;

// Declarations
class cActorLight;
class rActorLight;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class cActorLight : public MtObject
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
    s32 getStageNo();
    void setStageNo(s32 no);
    cActorLight();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
public:
    s32 mStageNo;  // offset: 0x8
    MtString mName;  // offset: 0x10
    MtVector3 mColor;  // offset: 0x20
    f32 mBalance;  // offset: 0x30
    MtFloat2 mShadowAtten;  // offset: 0x34
    MtVector3 mPos;  // offset: 0x40
    f32 mStart;  // offset: 0x50
    f32 mEnd;  // offset: 0x54
    static const u32 DATA_VERSION = 1;
    static MyDTI DTI;
};

class rActorLight : public rTable
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
    rActorLight();
    virtual const MtDTI& getDataDTI();  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u16 getDataVersion();  // vtable slot 18
    virtual bool load(MtStream& in);  // vtable slot 11
    bool loadData(MtDataReader& in);
    virtual bool save(MtStream& out);  // vtable slot 12
    bool saveData(MtDataWriter& out);
    bool loadData(MtDataReader& in, cActorLight* pData);
    bool saveData(MtDataWriter& out, cActorLight* pData);
    cActorLight* getData(u32 Idx);
    void setData(MtObject*, u32);
public:
    static MyDTI DTI;
};
