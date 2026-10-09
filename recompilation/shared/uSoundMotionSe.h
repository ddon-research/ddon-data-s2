#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cUnit.h"
#include "rSoundMotionSe.h"
#include "sCollision.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtLineSegment;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtQuaternion;
class MtUI;
class MtVector3;
class cResource;
class cpMotionSe;
class rSoundAttributeSe;
class rSoundMotionSe;
class rSoundRequest;
class rSoundStreamRequest;
class uCoord;
class uModel;

// Declarations
class uSoundMotionSe;

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

class uSoundMotionSe : public cUnit
{
    // inferred: cpMotionSe::setMotType names cpMotionSe::mMotionSe.mMotType
    friend class cpMotionSe;
public:
    enum
    {
        MOTION_SE_REQ_NO_1 = 0,
        MOTION_SE_REQ_NO_2 = 1,
        MOTION_SE_REQ_NO_3 = 2,
    };
    enum
    {
        MOTION_SE_PL_BASE = 0,
        MOTION_SE_PL_VOICE = 1,
        MOTION_SE_PL_SKILL = 2,
        MOTION_SE_PL_JOB = 3,
        MOTION_SE_PL_MAIN_WEP = 4,
        MOTION_SE_PL_FREE_0 = 5,
        MOTION_SE_PL_SUB_WEP = 6,
        MOTION_SE_PL_FREE_1 = 7,
        MOTION_SE_PL_ARMOR = 8,
        MOTION_SE_PL_FREE_2 = 9,
        MOTION_SE_PL_OM = 10,
        MOTION_SE_PL_SPECIAL = 11,
        MOTION_SE_NPC_VOICE = 12,
        MOTION_SE_PL_STAGE = 13,
        MOTION_SE_EM_SHARE = 14,
    };
    enum
    {
        MOTION_SE_EM_VOICE = 1,
        MOTION_SE_EM_SHELL = 10,
    };
public:
    struct MotSpdData;
    class MyDTI;
public:
    struct MotSpdData
    {
    public:
        f32 reqSpdMin;  // offset: 0x0
        f32 reqSpdMiddle;  // offset: 0x4
        f32 reqSpdMax;  // offset: 0x8
    };
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
    uSoundMotionSe();
    virtual ~uSoundMotionSe();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void move();  // vtable slot 9
    uModel* getTarModel();
    void setTarModel(uModel* p_setModel);
    void setMotType(u8 type);
    rSoundMotionSe* getMotionSe();
    void setMotionSe(rSoundMotionSe* pMotionSe);
    rSoundAttributeSe* getAttributeSe();
    void setAttributeSe(rSoundAttributeSe* pAttributeSe);
    rSoundRequest* getAttributeRequest(u32 index);
    void setAttributeRequest(rSoundRequest* pReq, u32 index, bool isClear);
    void setBaseReq(rSoundRequest* p);
    rSoundRequest* getBaseReq();
    void setRequestNum();
    void setRequest(rSoundRequest* pReq, u32 type);
    rSoundRequest* getRequest(u32 type);
    u32 getRequestNum();
    void setStreamRequest(rSoundStreamRequest* pReq);
    rSoundStreamRequest* getStreamRequest();
    rSoundRequest* getSeRequest(u32 ReqType);
    void setReqIdType(u32 type);
    void setMotionSeCallFlag(u32 index, bool flag);
    void requestMotionSebyWork(u16 work, u8 motType);
    u32 getAttributeRequestNum();
    void clearMotSeqOld(u32 Type);
    void clearMotSeqOld();
    u32 checkDeepWater(sCollision::TriangleInfo& info);
    void setSeqFilter(u32 seq);
    void clearSeqFilter();
private:
    bool getMotionSeCallFlag(u32 index);
protected:
    virtual void requestSe(rSoundRequest* pRequest, u32 reqNo, MtObject* thisId);  // vtable slot 24
    virtual void requestSe(rSoundRequest* pRequest, u32 reqNo, MtObject* thisId, MtVector3& pos);  // vtable slot 25
    virtual void requestSe(rSoundRequest* pRequest, u32 reqNo, MtObject* thisId, MtVector3& pos, MtQuaternion& quaternion);  // vtable slot 26
    virtual void requestSe(rSoundRequest* pRequest, u32 reqNo, MtObject* thisId, uCoord* pCoord, s32 jointId);  // vtable slot 27
    virtual void requestStream(rSoundStreamRequest* pRequest, u32 reqNo, u32 thisId);  // vtable slot 28
    virtual void requestStream(rSoundStreamRequest* pRequest, u32 reqNo, u32 thisId, MtVector3& pos);  // vtable slot 29
    virtual void requestStream(rSoundStreamRequest* pRequest, u32 reqNo, u32 thisId, MtVector3& pos, MtQuaternion& quaternion);  // vtable slot 30
    virtual void requestStream(rSoundStreamRequest* pRequest, u32 reqNo, u32 thisId, uCoord* pCoord, s32 jointId);  // vtable slot 31
    virtual void requestSe(cResource* pRequest, u32 reqNo, u32 thisId);  // vtable slot 32
    virtual void requestSe(cResource* pRequest, u32 reqNo, u32 thisId, MtVector3& pos);  // vtable slot 33
    virtual void requestSe(cResource* pRequest, u32 reqNo, u32 thisId, MtVector3& pos, MtQuaternion& quaternion);  // vtable slot 34
    virtual void requestSe(cResource* pRequest, u32 reqNo, u32 thisId, uCoord* pCoord, s32 jointId);  // vtable slot 35
    virtual void setMotSeSeqPageNo(u8 pageNo);  // vtable slot 36
    virtual u8 getMotSeSeqPageNo();  // vtable slot 37
    virtual void setMotSeSeqStartIndex(u8 startIndex);  // vtable slot 38
    virtual u8 getMotSeSeqStartIndex();  // vtable slot 39
    virtual void setMotSeSeqNum(u8 seqNum);  // vtable slot 40
    virtual u8 getMotSeSeqNum();  // vtable slot 41
    virtual s16 getReqNo(rSoundMotionSe::cSoundMotionSeData::MOTION_SE_DATA* pMotionSeData);  // vtable slot 42
    virtual u32 findIntersection(MtLineSegment& lineSegment);  // vtable slot 43
    virtual u32 getAttributeID();  // vtable slot 44
    virtual u32 getAttributeIDNoUseFindIntersect();  // vtable slot 45
    virtual u32 getAttributeResourceIndex(u32 attributeID);  // vtable slot 46
    // Address: 0x01b23410 - 0x01b23411 (1 bytes)
    virtual void setDummyU32(u32 num) {}  // vtable slot 47
    virtual void setSePositionOffset(rSoundRequest* pRequest, const u32 reqNo, const u32 thisId, const MtVector3& offset, bool isLink);  // vtable slot 48
    virtual void setStreamPositionOffset(rSoundStreamRequest* pRequest, const u32 reqNo, const u32 thisId, const MtVector3& offset, bool isLink);  // vtable slot 49
    void moveMotionSe();
    s32 getMotionSeIndex(u16 work);
    void updateMotSeq();
    void requestMotionSe(rSoundMotionSe::cSoundMotionSeData::MOTION_SE_DATA* pMotionSeData, u32 reqNo, s32 jointNo);
    void requestAttributeSe(rSoundMotionSe::cSoundMotionSeData::MOTION_SE_DATA* pMotSeData, s32 jointID);
    void UpdatePtr(uModel* * ppUnit);
    u32 getReqId(rSoundMotionSe::cSoundMotionSeData::MOTION_SE_DATA* p);
protected:
    u8 mMotSeSeqPageNo;  // offset: 0x48
    u8 mMotSeSeqStartIndex;  // offset: 0x49
    u8 mMotSeSeqNum;  // offset: 0x4a
    uModel* mpTarModel;  // offset: 0x50
    rSoundMotionSe* mpMotionSe;  // offset: 0x58
    rSoundRequest* mpRequest[16];  // offset: 0x60
    rSoundStreamRequest* mpStreamRequest;  // offset: 0xe0
    rSoundAttributeSe* mpAttributeSe;  // offset: 0xe8
    rSoundRequest* * mpAttributeRequest;  // offset: 0xf0
    bool mRequestAllow[16];  // offset: 0xf8
    u8 mMotType;  // offset: 0x108
    u32 mMotSeq[8];  // offset: 0x10c
    u32 mMotSeqOld[8];  // offset: 0x12c
    u32 mMotSeqTri[8];  // offset: 0x14c
    u32 mFilterSeq;  // offset: 0x16c
    u32 mReqIdType;  // offset: 0x170
public:
    static const u32 MOT_SE_MOT_BASE = 1;
    static const u32 MOT_SE_MOT_BLEND1 = 2;
    static const u32 MOT_SE_MOT_BLEND2 = 4;
    static const u32 MOT_SE_MOT_BLEND3 = 8;
    static const u32 MOT_SE_MOT_BLEND4 = 16;
    static const u32 MOT_SE_MOT_BLEND5 = 32;
    static const u32 MOT_SE_MOT_BLEND6 = 64;
    static const u32 MOT_SE_MOT_BLEND7 = 128;
    static const u8 DEFAULT_MOT_SE_SEQ_PAGE_NO = 3;
    static const u8 DEFAULT_MOT_SE_SEQ_START_INDEX = 0;
    static const u8 DEFAULT_MOT_SE_SEQ_NUM = 32;
    static const u8 MOT_SE_SEQ_PAGE_MAX = 31;
    static const u8 MOT_SE_SEQ_NUM_MAX = 32;
    static const u8 ATTRIBUTE_SE_REQUEST_NUM = 26;
    static const u32 MOT_SPD_INDEX_NUM;
    static const MotSpdData mMotSpdTbl[];
    static MyDTI DTI;
};
