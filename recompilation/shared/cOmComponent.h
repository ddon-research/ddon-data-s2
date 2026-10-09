#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
class MtObject;
class cEfcHandle;
class cOmControl;
class cOmParam;
class cpComponent;
class rEffectProvider;
class rMotionList;
class rObjCollision;
class rSoundRequest;
class uBaseModel;
class uDDOModel;
class uOmModel;

// Declarations
class cOmComponent;

// Type aliases from DWARF
using s32 = int;
using u32 = unsigned int;
using u8 = unsigned char;

class cOmComponent
{
public:
    cOmComponent();
    virtual ~cOmComponent();
    void init(const cOmParam* pParam, cOmControl* pCtrl, u32 flag, uBaseModel* pum);
    void setup(uBaseModel* pum);
    void move(uBaseModel* pum);
    void kill(uBaseModel* pum);
    virtual void reqKill();  // vtable slot 2
    void updatePtr();
    cOmControl* getHandler();
    const cOmParam* getOmParam();
    void createComponent(cpComponent* pRootCP, MtObject* pOwner, u32 questNo);
    bool isOnFlag(u32 flag);
    void initObjCollision(uOmModel* puom, rObjCollision* pRes);
    void eraseObjCollision(uOmModel* puom);
    void killNodeAll(uOmModel* puom);
    void initMotionList(uOmModel* puom, rMotionList* pRes);
    void eraseMotionList(uOmModel* puom);
    void initSoundReq(rSoundRequest* pRes);
    void eraseSoundReq();
    void keyOffSe();
    void initMotionSe(uOmModel* puom, const cOmParam* pParam);
    void loopSeControl(uBaseModel* pum);
    void initEffectProvider(uOmModel* puom, rEffectProvider* pRes);
    void eraseEffectProvider(uOmModel* puom);
    void updateEfcHandle();
    void setEffect(s32 index, uOmModel* puom);
    void finishFx(s32 index, uOmModel* puom);
public:
    bool mbReqKill;  // offset: 0x8
    cOmControl* mpOmControl;  // offset: 0x10
    uOmModel* mpOmModel;  // offset: 0x18
    u32 mOmType;  // offset: 0x20
    u32 mUseComponent;  // offset: 0x24
    u32 mRno;  // offset: 0x28
    rSoundRequest* mpSoundRequest;  // offset: 0x30
    bool mIsCallSe;  // offset: 0x38
    cEfcHandle* mphEfc[16];  // offset: 0x40
    bool mbHit;  // offset: 0xc0
    bool mEnduranceHit;  // offset: 0xc1
    uDDOModel* mpuCatchOld;  // offset: 0xc8
    bool mbSlave;  // offset: 0xd0
    u8 mSyncValue;  // offset: 0xd1
    static const u32 FxNum = 16;
};
