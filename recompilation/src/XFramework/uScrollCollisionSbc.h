#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "sCollision.h"
#include "uModel.h"
#include "uScrollCollision.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtMatrix;
class MtObject;
class MtPropertyList;
class MtQuaternion;
class MtVector3;
class cDraw;
class rCollision;
class rModel;
class rMotionList;
class uModel;

// Declarations
class uScrollCollisionSbc;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using u32 = unsigned int;
namespace nCollision { using SBC_HANDLE = u32; }
using size_t = _Sizet;
using u8 = unsigned char;

class uScrollCollisionSbc : public uScrollCollision
{
public:
    enum JOINT_CONNECT_OFFSET_MODE
    {
        JOINT_CONNECT_OFFSET_NONE = 0,
        JOINT_CONNECT_OFFSET_ADD = 1,
        JOINT_CONNECT_OFFSET_ROTATE_ADD = 2,
    };
    enum MODE_MOVE_TARGET
    {
        MODE_ALL = 0,
        MODE_TARGET_PARTS_INDEX_ONLY = 1,
        MODE_TARGET_PARTS_ID_ONLY = 2,
    };
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
    uScrollCollisionSbc();
    virtual ~uScrollCollisionSbc();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void sync();  // vtable slot 11
    virtual void moveAfter();  // vtable slot 10
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    bool registResourceByFileName(MT_CTSTR RSbcFileName);
    bool registResourceByFileNameDetail(MT_CTSTR RSbcFileName, u32 ScrollType, u8 ScrollGroupIndex);
    bool registResourceByResource(rCollision* pRSbc);
    bool registResourceByResourceDetail(rCollision* pRSbc, u32 ScrollType, u8 ScrollGroupIndex);
    void registResourceByHandle(sCollision::SBC_HANDLE SbcHandle);
    void unregistResource();
    rCollision* getRegistResource();
    sCollision::SBC_HANDLE getSbcHandle();
    u32 getSbcType();
    void setSbcType(u32 NewSbcType);
    u8 getSbcGroupByIndex();
    void setSbcGroupByIndex(u8 NewScrollGroupIndex);
    u32 getSbcGroupByBit();
    void setSbcGroupByBit(u32 NewScrollGroupBit);
    void registOwner(uModel* pOwner);
    uModel* getRegistOwner();
    void unregistOwner();
    rModel* getOwnerRModel();
    void setOwnerRModel(rModel* pRModel);
    rMotionList* getOwnerRMotionList();
    void setOwnerRMotionList(rMotionList* pRMotionList);
    u32 getOwnerMotionNo();
    void setOwnerMotionNo(u32 NextMotionNo);
    MtVector3 getOwnerNullPos();
    void setOwnerNullPos(const MtVector3& pos);
    bool isEnableSetOwnerNullPos();
    void setEnableSetOwnerNullPos(bool FlagEnable);
    MtVector3 getOwnerNullAngle();
    void setOwnerNullAngle(const MtVector3& angle);
    MtQuaternion getOwnerNullQuat();
    void setOwnerNullQuat(const MtQuaternion& qt);
    bool isEnableSetOwnerNullAngleQuat();
    void setEnableSetOwnerNullAngleQuat(bool FlagEnable);
    bool isEnableActiveLink() const;
    void setEnableActiveLink(bool flag);
    bool isSbcActive() const;
    bool setSbcActive(bool flag);
    void registConnectJointByIndex(u32 ConnectJointIndex);
    bool isRegistConnectJointByIndex();
    void registConnectJointByNo(u32 ConnectJointNo);
    bool isRegistConnectJointByNo();
    void unregistConnectJoint();
    bool isRegistConnectJoint();
    bool isUseWorldMatrix() const;
    void setUseWorldMatrix(bool set);
    JOINT_CONNECT_OFFSET_MODE getConnectOffsetMode();
    void setConnectOffsetMode(JOINT_CONNECT_OFFSET_MODE NextJointConnectMode);
    const MtVector3& getConnectOffset();
    void setConnectOffset(const MtVector3& NextJointConnectOffset);
    u32 getMoveTargetLimitMode();
    void setMoveTargetLimitMode(u32 NextMoveMode);
    u32 getMoveTargetPartsIndex();
    void setMoveTargetPartsIndex(u32 NextMoveTargetPartsIndex);
    u32 getMoveTargetPartsID();
    void setMoveTargetPartsID(u32 NextMoveTargetPartsID);
    void* memAlloc(size_t);
    void memFree(void*);
    size_t memSize(void*);
protected:
    void moveConnect();
    void moveConnectDefault();
    void moveConnectWorldMatrix();
    MtVector3 getConnectPos();
    const MtQuaternion& getConnectQuat();
    MtMatrix getConnectWorldMatrix();
    uModel::Joint* getConnectJoint();
    void startConnectJointForUI();
    void registConnectJointByIndexForUI(bool FlgRegist);
    void registConnectJointByNoForUI(bool FlgRegist);
    void setSbcActiveForUI(bool flag);
    void registResourceForUI(rCollision* pRSbc);
    void setDummyBool(bool FlgSet);
protected:
    uModel* mpOwner;  // offset: 0x48
    rCollision* mpRSbc;  // offset: 0x50
    sCollision::SBC_HANDLE mSbcHandle;  // offset: 0x58
    MtVector3 mConnectOffset;  // offset: 0x60
    MtVector3 mBeforeOwnerPos;  // offset: 0x70
    MtQuaternion mBeforeOwnerQt;  // offset: 0x80
    MtMatrix mBeforeOwnerWorldMatrix;  // offset: 0x90
    bool mFlgHandleRegistByOutside;  // offset: 0xd0
    bool mFlgEnableOwner;  // offset: 0xd1
    bool mFlgBeforeOwnerMove;  // offset: 0xd2
    bool mFlgOwnerSetPosOK;  // offset: 0xd3
    bool mFlgOwnerSetAngleQuatOK;  // offset: 0xd4
    bool mFlgBeforeResetset;  // offset: 0xd5
    bool mFlgBeforeActive;  // offset: 0xd6
    bool mFlgConnectModelJoint;  // offset: 0xd7
    bool mFlgConnectModelJointIndex;  // offset: 0xd8
    u32 mConnectModelJointIndex;  // offset: 0xdc
    u32 mConnectModelJointNo;  // offset: 0xe0
    u32 mConnectOffsetMode;  // offset: 0xe4
    bool mFlgConnectModelJointNo;  // offset: 0xe8
    bool mFlgUseWorldMatrix;  // offset: 0xe9
    bool mFlgUseWorldMatrixEraseScale;  // offset: 0xea
    bool mFlgEnableActiveLink;  // offset: 0xeb
    u32 mMoveTargetLimitMode;  // offset: 0xec
    u32 mMoveTargetPartsIndex;  // offset: 0xf0
    u32 mMoveTargetPartsID;  // offset: 0xf4
    bool mFlgNextForceUpdate;  // offset: 0xf8
    bool mFlgNextForceResetset;  // offset: 0xf9
public:
    static MyDTI DTI;
};

inline void* uScrollCollisionSbc::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline bool uScrollCollisionSbc::isUseWorldMatrix() const {
    return this->mFlgUseWorldMatrix;
}

inline void uScrollCollisionSbc::setUseWorldMatrix(bool set) {
    this->mFlgUseWorldMatrix = set;
}
