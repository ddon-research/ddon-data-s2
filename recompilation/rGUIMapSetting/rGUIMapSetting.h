#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/MtObject.h"
#include "../shared/MtPrimitive2D.h"
#include "../shared/cResource.h"

// Forward declarations
class AreaHitShape;
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
struct MtFloat2;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtRect;
class MtStream;
class MtUI;

// Declarations
class rGUIMapSetting;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class rGUIMapSetting : public cResource
{
public:
    class MyDTI;
    class cData;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cData : public MtObject
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
        cData();
        virtual ~cData();
        void release();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        void setShapeType(s32 n);
        s32 getShapeType();
        virtual bool load(MtDataReader& r);  // vtable slot 6
        virtual bool save(MtDataWriter& w);  // vtable slot 7
    public:
        AreaHitShape* mpShape;  // offset: 0x8
        s32 mShapeType;  // offset: 0x10
        u32 mFloorId;  // offset: 0x14
        bool mVisible;  // offset: 0x18
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
    rGUIMapSetting();
    virtual ~rGUIMapSetting();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual MT_CTSTR getName() const;  // vtable slot 16
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual void clear();  // vtable slot 15
    u32 getHouseTopNum();
    bool getUseIdTex();
protected:
    MtTypedArray<cData> mArray;  // offset: 0x70
    MtFloat2 mCenter;  // offset: 0x90
    MtRect mRect;  // offset: 0x98
    s32 mFloorBaseId;  // offset: 0xa8
    u32 mFloorBaseSizeId;  // offset: 0xac
    u32 mTextureNumX;  // offset: 0xb0
    u32 mTextureNumY;  // offset: 0xb4
    f32 mFoundationScale;  // offset: 0xb8
    f32 mOffsetPosX;  // offset: 0xbc
    f32 mOffsetPosY;  // offset: 0xc0
    bool mUseIdTex;  // offset: 0xc4
public:
    static MyDTI DTI;
    static const u32 DATA_VERSION = 4;
    static const u32 DATA_MAGIC = 5262663;
};

// Inline, no code of its own: checked where it is inlined.
inline rGUIMapSetting::cData::cData() {
    this->mpShape = static_cast<AreaHitShape*>(nullptr);
    this->mFloorId = static_cast<u32>(0);
    this->mShapeType = static_cast<s32>(9);
    this->mVisible = true;
}
