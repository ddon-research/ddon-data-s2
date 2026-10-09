#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/cResource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtUI;
class MtVector3;
class rSoundRequest;
class uCoord;

// Declarations
class rSoundAttributeSe;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class rSoundAttributeSe : public cResource
{
public:
    enum ATTRIBUTE_SE_TYPE
    {
        ATTRIBUTE_SE_TYPE_ATTRIBUTE = 0,
        ATTRIBUTE_SE_TYPE_0 = 1,
        ATTRIBUTE_SE_TYPE_1 = 2,
        ATTRIBUTE_SE_TYPE_2 = 3,
        ATTRIBUTE_SE_TYPE_3 = 4,
        ATTRIBUTE_SE_TYPE_4 = 5,
        ATTRIBUTE_SE_TYPE_5 = 6,
        ATTRIBUTE_SE_TYPE_6 = 7,
        ATTRIBUTE_SE_TYPE_7 = 8,
        ATTRIBUTE_SE_TYPE_8 = 9,
        ATTRIBUTE_SE_TYPE_9 = 10,
        ATTRIBUTE_SE_TYPE_10 = 11,
    };
    enum
    {
        ATTR_TYPE_SOIL = 0,
        ATTR_TYPE_SAND = 1,
        ATTR_TYPE_BOG = 2,
        ATTR_TYPE_STONE = 3,
        ATTR_TYPE_WOOD = 4,
        ATTR_TYPE_METAL = 5,
        ATTR_TYPE_GRASS = 6,
        ATTR_TYPE_CLOTH = 7,
        ATTR_TYPE_TREE = 8,
        ATTR_TYPE_CARPET = 9,
        ATTR_TYPE_ROCK = 10,
        ATTR_TYPE_DEADLEAF = 11,
        ATTR_TYPE_BONE = 12,
        ATTR_TYPE_GRAVEL = 13,
        ATTR_TYPE_MUD = 14,
        ATTR_TYPE_WATER = 15,
        ATTR_TYPE_STRAW = 16,
        ATTR_TYPE_ROOFTILE = 17,
        ATTR_TYPE_MAGICSPA = 18,
        ATTR_TYPE_POISONBOG = 19,
        ATTR_TYPE_TAR = 20,
        ATTR_TYPE_DEEPBOG = 21,
        ATTR_TYPE_DEEPWATER = 22,
        ATTR_TYPE_DEEPMAGICSPA = 23,
        ATTR_TYPE_DEEPPOISONBOG = 24,
        ATTR_TYPE_DEEPTAR = 25,
        ATTR_TYPE_MAX = 26,
    };
public:
    class MyDTI;
    class cSoundAttributeSeData;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cSoundAttributeSeData : public MtObject
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
        cSoundAttributeSeData();
        virtual ~cSoundAttributeSeData();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual void copy(rSoundAttributeSe::cSoundAttributeSeData* p_src);  // vtable slot 6
        u32 getSeReqID(u32 se_id);
        bool getUseFindIntersect();
        u32 getReqType();
    private:
        u32 mReqType;  // offset: 0x8
        u32 mSeReqID_00;  // offset: 0xc
        u32 mSeReqID_01;  // offset: 0x10
        u32 mSeReqID_02;  // offset: 0x14
        u32 mSeReqID_03;  // offset: 0x18
        u32 mSeReqID_04;  // offset: 0x1c
        u32 mSeReqID_05;  // offset: 0x20
        u32 mSeReqID_06;  // offset: 0x24
        u32 mSeReqID_07;  // offset: 0x28
        u32 mSeReqID_08;  // offset: 0x2c
        u32 mSeReqID_09;  // offset: 0x30
        u32 mSeReqID_10;  // offset: 0x34
        u32 mSeReqID_11;  // offset: 0x38
        u32 mSeReqID_12;  // offset: 0x3c
        u32 mSeReqID_13;  // offset: 0x40
        u32 mSeReqID_14;  // offset: 0x44
        u32 mSeReqID_15;  // offset: 0x48
        u32 mSeReqID_16;  // offset: 0x4c
        u32 mSeReqID_17;  // offset: 0x50
        u32 mSeReqID_18;  // offset: 0x54
        u32 mSeReqID_19;  // offset: 0x58
        u32 mSeReqID_20;  // offset: 0x5c
        u32 mSeReqID_21;  // offset: 0x60
        u32 mSeReqID_22;  // offset: 0x64
        u32 mSeReqID_23;  // offset: 0x68
        u32 mSeReqID_24;  // offset: 0x6c
        u32 mSeReqID_25;  // offset: 0x70
        u32 mSeReqID_26;  // offset: 0x74
        u32 mSeReqID_27;  // offset: 0x78
        u32 mSeReqID_28;  // offset: 0x7c
        u32 mSeReqID_29;  // offset: 0x80
        u32 mSeReqID_30;  // offset: 0x84
        u32 mSeReqID_31;  // offset: 0x88
        bool mUseFindIntersect;  // offset: 0x8c
    public:
        static MyDTI DTI;
        static const u32 maxAttributeSeData = 32;
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
    rSoundAttributeSe();
    virtual ~rSoundAttributeSe();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    bool createAttributeSeData(u32 num);
    void clearAttributeSeData();
    void paramInit();
    void copy(rSoundAttributeSe* pRah);
    s32 getAttributeSeDataNum();
    void setAttributeSeDataNum(s32 data_num);
    cSoundAttributeSeData* getAttributeSeData(s32 index);
    u32 getAttributeSeData_reqID(s32 index, u32 se_id);
    void setAttributeSeData(cSoundAttributeSeData* pDataTop, s32 DataNum);
    void setAttributeSeDataList(cSoundAttributeSeData* pData, s32 index);
    bool getUseFindIntersect(s32 index);
    u32 getReqType(s32 index);
    void RequestAttributeSe(rSoundRequest* pRes, u32 se_id, u32 thisId, const MtVector3& se_pos, u32 material_id);
    cSoundAttributeSeData* getpAttributeSeData();
protected:
    virtual void requestSe(rSoundRequest* pRequest, u32 reqNo, u32 thisId);  // vtable slot 16
    virtual void requestSe(rSoundRequest* pRequest, u32 reqNo, u32 thisId, const MtVector3& pos);  // vtable slot 17
    virtual void requestSe(rSoundRequest* pRequest, u32 reqNo, u32 thisId, uCoord* pCoord, s32 jointId);  // vtable slot 18
private:
    void createAttributeSeDataForProperty(u32 num);
private:
    s32 mAttributeSeDataNum;  // offset: 0x70
    cSoundAttributeSeData* mpAttributeSeData;  // offset: 0x78
public:
    static MyDTI DTI;
    static const s32 NativeFileVersion = 3;
};

// Inline, no code of its own: checked where it is inlined.
inline rSoundAttributeSe::rSoundAttributeSe() {
    this->mAttributeSeDataNum = static_cast<s32>(0);
    this->mpAttributeSeData = static_cast<rSoundAttributeSe::cSoundAttributeSeData*>(nullptr);
    this->::cResource::mAttr = static_cast<u32>(16);
}

// Inline, no code of its own: checked where it is inlined.
inline bool rSoundAttributeSe::cSoundAttributeSeData::getUseFindIntersect() {
    return this->mUseFindIntersect;
}
