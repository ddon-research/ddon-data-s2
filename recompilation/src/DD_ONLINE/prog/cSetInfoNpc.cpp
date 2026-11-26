// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cSetInfoNpc.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtDataWriter.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#include "cContextInterface.h"
#include "cFSMRelate.h"
#include "cSetInfoCharacter.h"
#include "../../generated/shared/nDDOIO.h"
#include "sNpcManager.h"
#include "sWorldOffset.h"
#include "uControl.h"
#include "uControlNpc.h"
#include "uDDOModel.h"
#include "uNpc.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cSetInfoNpc::getDTI() const {
    return cSetInfoNpc::DTI;
}

void* cSetInfoNpc::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

__attribute__((noinline)) cSetInfoNpc::cSetInfoNpc() {
    mNpcId = -1;
    mFilePath = "";
    mIsCommunicate = false;
    mClothType = 0;
    mDefNPCMotCategory = 0;
    mDefNPCMotNo = -1;
    mLantern = 0;
    mThinkIndex = 0;
    mJobLv = 0;
    mDisableScrAdj = false;
    mDisableLedgerFinger = false;
    mIsForceListTalk = false;
    mIsAttand = false;
    mDisableTouchAction = false;
    mDispElseQuestTalk = true;
}

cSetInfoNpc::~cSetInfoNpc() {
}

void cSetInfoNpc::createProperty(MtPropertyList& s) {
    this->cSetInfoCharacter::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mNpcId", &mNpcId, 0u, 0u);
    mFsmResource.cFSMRelate::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mIsCommunicate", &mIsCommunicate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mClothType", &mClothType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDefNPCMotCategory", &mDefNPCMotCategory, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDefNPCMotNo", &mDefNPCMotNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mThinkIndex", &mThinkIndex, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mJobLv", &mJobLv, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLantern", &mLantern, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDisableScrAdj", &mDisableScrAdj, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDisableLedgerFinger", &mDisableLedgerFinger, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsForceListTalk", &mIsForceListTalk, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsAttand", &mIsAttand, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDisableTouchAction", &mDisableTouchAction, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDispElseQuestTalk", &mDispElseQuestTalk, 0u, 0u);
}

__attribute__((weak)) bool cSetInfoNpc::load(MtDataReader& r) {
    mNpcId = r.readS32();
    char t0[256];
    r.readString(t0, 256u);
    mFilePath = t0;
    {
        bool t1 = false;
        if (r.mSeekPt < r.mBufsiz || r.refill()) {
            u8 t2 = r.mBuffer[r.mSeekPt];
            r.mSeekPt = r.mSeekPt + 1;
            t1 = t2 != 0;
        }
        mIsCommunicate = t1;
    }
    {
        u8& t4 = mClothType;
        u8 t3 = 0;
        if (r.mSeekPt < r.mBufsiz || r.refill()) {
            t3 = r.mBuffer[r.mSeekPt];
            r.mSeekPt = r.mSeekPt + 1;
        }
        t4 = t3;
    }
    {
        s8& t6 = mDefNPCMotCategory;
        s8 t5 = 0;
        if (r.mSeekPt < r.mBufsiz || r.refill()) {
            t5 = static_cast<s8>(r.mBuffer[r.mSeekPt]);
            r.mSeekPt = r.mSeekPt + 1;
        }
        t6 = t5;
    }
    {
        s8& t8 = mDefNPCMotNo;
        s8 t7 = 0;
        if (r.mSeekPt < r.mBufsiz || r.refill()) {
            t7 = static_cast<s8>(r.mBuffer[r.mSeekPt]);
            r.mSeekPt = r.mSeekPt + 1;
        }
        t8 = t7;
    }
    mThinkIndex = r.readU16();
    mJobLv = r.readU16();
    {
        u8& t10 = mLantern;
        u8 t9 = 0;
        if (r.mSeekPt < r.mBufsiz || r.refill()) {
            t9 = r.mBuffer[r.mSeekPt];
            r.mSeekPt = r.mSeekPt + 1;
        }
        t10 = t9;
    }
    {
        bool t11 = false;
        if (r.mSeekPt < r.mBufsiz || r.refill()) {
            u8 t12 = r.mBuffer[r.mSeekPt];
            r.mSeekPt = r.mSeekPt + 1;
            t11 = t12 != 0;
        }
        mDisableScrAdj = t11;
    }
    {
        bool t13 = false;
        if (r.mSeekPt < r.mBufsiz || r.refill()) {
            u8 t14 = r.mBuffer[r.mSeekPt];
            r.mSeekPt = r.mSeekPt + 1;
            t13 = t14 != 0;
        }
        mDisableLedgerFinger = t13;
    }
    {
        bool t15 = false;
        if (r.mSeekPt < r.mBufsiz || r.refill()) {
            u8 t16 = r.mBuffer[r.mSeekPt];
            r.mSeekPt = r.mSeekPt + 1;
            t15 = t16 != 0;
        }
        mIsForceListTalk = t15;
    }
    {
        bool t17 = false;
        if (r.mSeekPt < r.mBufsiz || r.refill()) {
            u8 t18 = r.mBuffer[r.mSeekPt];
            r.mSeekPt = r.mSeekPt + 1;
            t17 = t18 != 0;
        }
        mIsAttand = t17;
    }
    {
        bool t19 = false;
        if (r.mSeekPt < r.mBufsiz || r.refill()) {
            u8 t20 = r.mBuffer[r.mSeekPt];
            r.mSeekPt = r.mSeekPt + 1;
            t19 = t20 != 0;
        }
        mDisableTouchAction = t19;
    }
    {
        bool t21 = false;
        if (r.mSeekPt < r.mBufsiz || r.refill()) {
            u8 t22 = r.mBuffer[r.mSeekPt];
            r.mSeekPt = r.mSeekPt + 1;
            t21 = t22 != 0;
        }
        mDispElseQuestTalk = t21;
    }
    return this->cSetInfoCharacter::load(r);
}

__attribute__((weak)) bool cSetInfoNpc::save(MtDataWriter& w) {
    nDDOIO::writeData(w, mNpcId);
    nDDOIO::writeData(w, mFsmResource.getName());
    nDDOIO::writeData(w, mIsCommunicate);
    nDDOIO::writeData(w, mClothType);
    w.writeS8(mDefNPCMotCategory);
    w.writeS8(mDefNPCMotNo);
    nDDOIO::writeData(w, mThinkIndex);
    nDDOIO::writeData(w, mJobLv);
    nDDOIO::writeData(w, mLantern);
    nDDOIO::writeData(w, mDisableScrAdj);
    nDDOIO::writeData(w, mDisableLedgerFinger);
    nDDOIO::writeData(w, mIsForceListTalk);
    nDDOIO::writeData(w, mIsAttand);
    nDDOIO::writeData(w, mDisableTouchAction);
    nDDOIO::writeData(w, mDispElseQuestTalk);
    return this->cSetInfoCharacter::save(w);
}

__attribute__((weak)) bool cSetInfoNpc::applyInfo(cUnit* pu) const {
    DDON_STUB("cSetInfoNpc::applyInfo")
    return {};
}

__attribute__((weak)) void cSetInfoNpc::copy(cSetInfo* p) {
    DDON_STUB("cSetInfoNpc::copy")
    /* stub */
}

inline cSetInfoNpc::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cSetInfoNpc::MyDTI cSetInfoNpc::DTI("cSetInfoNpc", &::cSetInfoCharacter::DTI, 120ul, 0u, 0u);

__attribute__((weak)) MtObject* cSetInfoNpc::MyDTI::newInstance() const {
    return new (16u) cSetInfoNpc;
}

