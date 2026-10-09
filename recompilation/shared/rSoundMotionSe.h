#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "cResource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtString;
class MtUI;
class MtVector3;

// Declarations
class rSoundMotionSe;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s16 = short;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class rSoundMotionSe : public cResource
{
public:
    enum MOTION_SE_REQ_TYPE
    {
        MOTION_SE_REQ_TYPE_0 = 0,
        MOTION_SE_REQ_TYPE_1 = 1,
        MOTION_SE_REQ_TYPE_2 = 2,
        MOTION_SE_REQ_TYPE_3 = 3,
        MOTION_SE_REQ_TYPE_4 = 4,
        MOTION_SE_REQ_TYPE_5 = 5,
        MOTION_SE_REQ_TYPE_6 = 6,
        MOTION_SE_REQ_TYPE_7 = 7,
        MOTION_SE_REQ_TYPE_8 = 8,
        MOTION_SE_REQ_TYPE_9 = 9,
        MOTION_SE_REQ_TYPE_10 = 10,
        MOTION_SE_REQ_TYPE_11 = 11,
        MOTION_SE_REQ_TYPE_12 = 12,
        MOTION_SE_REQ_TYPE_13 = 13,
        MOTION_SE_REQ_TYPE_14 = 14,
        MOTION_SE_REQ_TYPE_15 = 15,
        MOTION_SE_REQ_TYPE_SE_END = 16,
        MOTION_SE_REQ_TYPE_STREAM = 16,
        MOTION_SE_REQ_TYPE_ATTR = 17,
        MOTION_SE_REQ_MAX_NUM = 18,
    };
public:
    class MyDTI;
    struct HEADER;
    class cSoundMotionSeData;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct HEADER
    {
    public:
        u32 Magic;  // offset: 0x0
        u8 Version;  // offset: 0x4
    };
public:
    class cSoundMotionSeData : public MtObject
    {
    public:
        class MyDTI;
        struct MOTION_SE_DATA;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        struct MOTION_SE_DATA
        {
        public:
            s32 mSeJointID;  // offset: 0x0
            f32 mUpMarginY;  // offset: 0x4
            f32 mDownMarginY;  // offset: 0x8
            MtVector3 mOffset;  // offset: 0x10
            bool mSeJointAttachFlag;  // offset: 0x20
            bool mAttributeSeFlag;  // offset: 0x21
            s16 mUniqueID;  // offset: 0x22
            s16 mSeReqNo_1;  // offset: 0x24
            s16 mSeReqNo_2;  // offset: 0x26
            s16 mSeReqNo_3;  // offset: 0x28
            u8 mFreeArea[2];  // offset: 0x2a
            u32 mRequestType;  // offset: 0x2c
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
        cSoundMotionSeData();
        virtual ~cSoundMotionSeData();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        MOTION_SE_DATA* getData();
        void setComment(const MtString&);
        MtString getComment();
        u32 getReqType();
    private:
        MOTION_SE_DATA mData;  // offset: 0x10
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
    rSoundMotionSe();
    virtual ~rSoundMotionSe();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& in);  // vtable slot 12
    cSoundMotionSeData* getMotionSeData(u32 index);
    cSoundMotionSeData* getMotionSeDataFromUniqueID(u16 uniqueID);
    void clearMotionSeData();
    void addMotionSe();
    void eraseMotionSe(u32 index);
    u32 getMotionSeDataNum();
    MtTypedArray<cSoundMotionSeData>* getArrayPointer();
    void createIDToIndexTbl();
protected:
    HEADER mHeader;  // offset: 0x70
    MtTypedArray<cSoundMotionSeData> mMotionSe;  // offset: 0x78
    u16* mpIDToIndexTbl;  // offset: 0x98
    u16 mIDToIndexTblNum;  // offset: 0xa0
public:
    static MyDTI DTI;
    static const u32 FREE_AREA_NUM = 2;
    static const u32 MOTION_SPD_FREE_NO = 0;
    static const u32 HUMAN_TYPE_FREE_NO = 1;
    static const u32 MOTION_SE_REQ_TYPE_NUM = 16;
protected:
    static const u32 NativeFileMagic = 4543309;
    static const s32 NativeFileVersion = 9;
};
