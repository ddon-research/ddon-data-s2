// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rOmParam.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtDataWriter.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "cResPath.h"
#include "../../XFramework/cResource.h"
#include "../../generated/shared/nDDOIO.h"
#include "rCaughtInfoParam.h"
#include "../../XFramework/rCollision.h"
#include "../../XFramework/rDeformWeightMap.h"
#include "rEffectProvider.h"
#include "rJointInfo.h"
#include "../../XFramework/rModel.h"
#include "../../XFramework/rMotionList.h"
#include "rObjCollision.h"
#include "../../XFramework/rRigidBody.h"
#include "rSoundMotionSe.h"
#include "../../XFramework/rSoundRequest.h"
#include "../../XFramework/rSwingModel.h"
#include "rTable.h"
#include "../../XFramework/rZone.h"
#include "uOmModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cOmParam::getDTI() const {
    return cOmParam::DTI;
}

cOmParam::~cOmParam() {
}

__attribute__((weak)) void cOmParam::createProperty(MtPropertyList& s) {
}

u32 cOmParam::getOmUnitID() const {
    return mUnitDTIID;
}

u32 cOmParam::getOmFlag() const {
    return mUseComponent;
}

bool cOmParam::isOmStatus(u32 flag) const {
    return (flag & mDetailBehavior) != 0;
}

bool cOmParam::isReqSeFlag(u32 flag) const {
    return true;
}

bool cOmParam::chkVersion() const {
    return mVersion <= 8224u;
}

bool cOmParam::chkVersion(u32 targetVersion) const {
    return targetVersion >= mVersion;
}

inline cOmParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cOmParam::MyDTI cOmParam::DTI("cOmParam", &::MtObject::DTI, 416ul, 0u, 0u);

__attribute__((weak)) MtObject* cOmParam::MyDTI::newInstance() const {
    return new (16u) cOmParam;
}

const MtDTI& rOmParam::getDTI() const {
    return rOmParam::DTI;
}

inline void* rOmParam::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rOmParam::DTI)->memAlloc(sz, align, rOmParam::DTI.getID());
}

inline void rOmParam::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rOmParam::DTI)->memFree(p_addr);
}

inline rOmParam::rOmParam() {
    setAttribute(16u);
}

const MtDTI& rOmParam::getDataDTI() {
    return cOmParam::DTI;
}

MT_CTSTR rOmParam::getExt() const {
    return "omp";
}

u16 rOmParam::getDataVersion() {
    return 56;
}

bool rOmParam::load(MtStream& in) {
    MtDataReader r(in, 4096u);
    return loadData(r);
}

__attribute__((weak)) bool rOmParam::loadData(MtDataReader& in) {
    u32 magic = in.readU32();
    u32 version = in.readU16();
    if (magic != mMagic || version != cOmParam::DATA_VERSION) {
        return false;
    }
    u32 dmy = in.readU16();
    u32 Num = in.readU32();
    bool ret = true;
    for (u32 i = 0; i < Num; i++) {
        cOmParam* pObj = new (16u) cOmParam;
        if (pObj != nullptr) {
            loadData(in, pObj);
            mArray.add(pObj);
        }
    }
    return ret;
}

__attribute__((weak)) bool rOmParam::save(MtStream& out) {
    MtDataWriter w(out, MtDataWriter::DEFAULT_BUFFERSIZE, MtDataWriter::DEFAULT_LABELSIZE);
    return saveData(w);
}

bool rOmParam::loadData(MtDataReader& in, cOmParam* pData) {
    nDDOIO::readData(in, pData->mOmID);
    nDDOIO::readData(in, pData->mrModel);
    nDDOIO::readData(in, pData->mrObjCollision);
    nDDOIO::readData(in, pData->mrMotionList);
    nDDOIO::readData(in, pData->mrSoundMotionSe);
    nDDOIO::readData(in, pData->mUnitDTIID);
    nDDOIO::readData(in, pData->mUseComponent);
    nDDOIO::readData(in, pData->mOmSetType);
    nDDOIO::readData(in, pData->mrEffectProvider);
    nDDOIO::readData(in, pData->mrSoundRequest);
    nDDOIO::readData(in, pData->mReqSeFlag);
    nDDOIO::readData(in, pData->mFxIndex[0]);
    nDDOIO::readData(in, pData->mSeIndex[0]);
    nDDOIO::readData(in, pData->mFxIndex[1]);
    nDDOIO::readData(in, pData->mSeIndex[1]);
    nDDOIO::readData(in, pData->mFxIndex[2]);
    nDDOIO::readData(in, pData->mSeIndex[2]);
    nDDOIO::readData(in, pData->mFxIndex[3]);
    nDDOIO::readData(in, pData->mSeIndex[3]);
    nDDOIO::readData(in, pData->mrSwingModel);
    nDDOIO::readData(in, pData->mrSoftBody);
    nDDOIO::readData(in, pData->mrRigidBody);
    nDDOIO::readData(in, pData->mrBrRigidBody);
    nDDOIO::readData(in, pData->mrBrModel);
    nDDOIO::readData(in, pData->mrBrSoftBody);
    nDDOIO::readData(in, pData->mrCaught);
    nDDOIO::readData(in, pData->mrZone);
    nDDOIO::readData(in, pData->mrOmZone);
    nDDOIO::readData(in, pData->mrJointInfo);
    nDDOIO::readData(in, pData->mDetailBehavior);
    nDDOIO::readData(in, pData->mMapIcon);
    nDDOIO::readData(in, pData->mKillLength);
    nDDOIO::readData(in, pData->mbUseNightColor);
    pData->mNightColor = in.readV3();
    pData->mRigidTime = in.readF32();
    pData->mRigidForce = in.readF32();
    pData->mRigidOfsY = in.readF32();
    pData->mRigidVelocity = in.readF32();
    pData->mRigidWorldOfsY = in.readF32();
    pData->mRigid1Frame = in.readF32();
    pData->mOffSeLength = in.readF32();
    pData->mKeyOfs = in.readV3();
    nDDOIO::readData(in, pData->mbNav);
    pData->mNavOBBPos = in.readV3();
    pData->mNavOBBExtent = in.readV3();
    nDDOIO::readData(in, pData->mbAtk);
    pData->mShotGroup = in.readU32();
    pData->mWepType = in.readS32();
    pData->mThrowVelocity = in.readF32();
    pData->mThrowVectorY = in.readF32();
    pData->mArcTagID = in.readU32();
    pData->mTargetJntNo = in.readS32();
    pData->mTargetOfs = in.readV3();
    nDDOIO::readData(in, pData->mColliOffFrame);
    nDDOIO::readData(in, pData->mBlinkType);
    nDDOIO::readData(in, pData->mrCollision[0][0]);
    nDDOIO::readData(in, pData->mrCollision[0][1]);
    nDDOIO::readData(in, pData->mrCollision[1][0]);
    nDDOIO::readData(in, pData->mrCollision[1][1]);
    nDDOIO::readData(in, pData->mVersion);
    return true;
}

__attribute__((weak)) bool rOmParam::saveData(MtDataWriter& out, cOmParam* pData) {
    nDDOIO::writeData(out, pData->mOmID);
    nDDOIO::writeData(out, pData->mrModel);
    nDDOIO::writeData(out, pData->mrObjCollision);
    nDDOIO::writeData(out, pData->mrMotionList);
    nDDOIO::writeData(out, pData->mrSoundMotionSe);
    nDDOIO::writeData(out, pData->mUnitDTIID);
    nDDOIO::writeData(out, pData->mUseComponent);
    nDDOIO::writeData(out, pData->mOmSetType);
    nDDOIO::writeData(out, pData->mrEffectProvider);
    nDDOIO::writeData(out, pData->mrSoundRequest);
    nDDOIO::writeData(out, pData->mReqSeFlag);
    nDDOIO::writeData(out, pData->mFxIndex[0]);
    nDDOIO::writeData(out, pData->mSeIndex[0]);
    nDDOIO::writeData(out, pData->mFxIndex[1]);
    nDDOIO::writeData(out, pData->mSeIndex[1]);
    nDDOIO::writeData(out, pData->mFxIndex[2]);
    nDDOIO::writeData(out, pData->mSeIndex[2]);
    nDDOIO::writeData(out, pData->mFxIndex[3]);
    nDDOIO::writeData(out, pData->mSeIndex[3]);
    nDDOIO::writeData(out, pData->mrSwingModel);
    nDDOIO::writeData(out, pData->mrSoftBody);
    nDDOIO::writeData(out, pData->mrRigidBody);
    nDDOIO::writeData(out, pData->mrBrRigidBody);
    nDDOIO::writeData(out, pData->mrBrModel);
    nDDOIO::writeData(out, pData->mrBrSoftBody);
    nDDOIO::writeData(out, pData->mrCaught);
    nDDOIO::writeData(out, pData->mrZone);
    nDDOIO::writeData(out, pData->mrOmZone);
    nDDOIO::writeData(out, pData->mrJointInfo);
    nDDOIO::writeData(out, pData->mDetailBehavior);
    nDDOIO::writeData(out, pData->mMapIcon);
    nDDOIO::writeData(out, pData->mKillLength);
    nDDOIO::writeData(out, pData->mbUseNightColor);
    nDDOIO::writeData(out, pData->mNightColor);
    out.writeF32(pData->mRigidTime);
    out.writeF32(pData->mRigidForce);
    out.writeF32(pData->mRigidOfsY);
    out.writeF32(pData->mRigidVelocity);
    out.writeF32(pData->mRigidWorldOfsY);
    out.writeF32(pData->mRigid1Frame);
    out.writeF32(pData->mOffSeLength);
    nDDOIO::writeData(out, pData->mKeyOfs);
    nDDOIO::writeData(out, pData->mbNav);
    nDDOIO::writeData(out, pData->mNavOBBPos);
    nDDOIO::writeData(out, pData->mNavOBBExtent);
    nDDOIO::writeData(out, pData->mbAtk);
    out.writeU32(pData->mShotGroup);
    out.writeS32(pData->mWepType);
    out.writeF32(pData->mThrowVelocity);
    out.writeF32(pData->mThrowVectorY);
    out.writeU32(pData->mArcTagID);
    out.writeS32(pData->mTargetJntNo);
    nDDOIO::writeData(out, pData->mTargetOfs);
    nDDOIO::writeData(out, pData->mColliOffFrame);
    nDDOIO::writeData(out, pData->mBlinkType);
    nDDOIO::writeData(out, pData->mrCollision[0][0]);
    nDDOIO::writeData(out, pData->mrCollision[0][1]);
    nDDOIO::writeData(out, pData->mrCollision[1][0]);
    nDDOIO::writeData(out, pData->mrCollision[1][1]);
    nDDOIO::writeData(out, pData->mVersion);
    return true;
}

inline rOmParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rOmParam::MyDTI rOmParam::DTI("rOmParam", &::rTable::DTI, 176ul, 0u, 0u);

MtObject* rOmParam::MyDTI::newInstance() const {
    return new (16u) rOmParam;
}

