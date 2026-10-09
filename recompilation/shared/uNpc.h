#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtString.h"
#include "nDDOModel.h"
#include "uHuman.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtString;
class MtUI;
class MtVector3;
class cpFsmCtrl;
class cpPawnThink;
class rkThinkData;
class uControlNpc;
class uDDOModel;

// Declarations
class uNpc;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s16 = short;
using s32 = int;
using s8 = signed char;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class uNpc : public uHuman
{
public:
    enum
    {
        HEAD_CTRL_TARGET_POSITION = 0,
        HEAD_CTRL_TARGET_PLAYER = 1,
        HEAD_CTRL_TARGET_NPC = 2,
        HEAD_CTRL_TARGET_ENEMY = 3,
        HEAD_CTRL_TARGET_NUM = 4,
    };
    enum
    {
        MOT_FINGER_NPC_JOBBASE = 20,
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
    u32 getNpcId() const;
    void setNpcId(u32 id);
    MT_CTSTR getNpcName() const;
    MT_CTSTR getClassName() const;
    s8 getDefNPCMotCategory() const;
    s8 getDefNPCMotNo() const;
    s8 getDefTurnType() const;
    u16 getThinkIndex() const;
    u16 getJobLv() const;
    void setNpcName(MT_CTSTR name);
    s32 getShopId() const;
    virtual void initCharacterEdit();  // vtable slot 198
    void setDefNPCMotAct(u32 noHokan);
    void setTalkMotAct(s16 talkMotNo);
    u32 getQuestId() const;
    void setDispGauge(bool disp);
    bool isPartnerPawn() const;
    void setPartnerPawn();
protected:
    void setAge(u32);
    void setSex(u8 sex);
    u32 getClothType() const;
    s32 getWaypointGoto() const;
    void setWaypointGoto(s32 gotoPointNo);
public:
    void setHeadCtrlSpeedRate(f32 speedRate);
    void setHeadCtrlEnable(bool isEnable, bool isDisableSeq);
    void setHeadCtrlParam(bool isDisableSeq, u32 type, const MtVector3& pos, u32 group, u32 setId, s32 jointId);
    void setHeadCtrlParam(bool isDisableSeq, const MtVector3& pos);
    virtual void initHeadCtrl();  // vtable slot 199
    void setHeadCtrl(s16 headCtrl);
    void lookAtPlayer();
    virtual void setTouch(uDDOModel* pUnit, bool isTouchSave);  // vtable slot 166
    virtual void requestReleaseTouch(uDDOModel* pRelease, nDDOModel::TOUCH_RELEASE_TYPE type);  // vtable slot 167
    void loadFSM(MT_CTSTR filePath);
    bool isAttend();
    bool isDispMiniMap();
    bool isPlayMusic();
    bool isDisableTalkMotCancel();
    bool isMotionCancelMyRoom();
    void controlLantern(const uControlNpc* pCtrl);
    u32 trace(MtVector3& TargetPos, MtVector3& DestPos, f32& DestDir);
    void setInvincible(bool IsInvincible);
    void setGripFinger();
    uNpc();
    virtual ~uNpc();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void setup();  // vtable slot 6
    virtual void update();  // vtable slot 205
    virtual void move();  // vtable slot 9
    virtual void createComponent();  // vtable slot 43
    virtual void setupComponentPtr();  // vtable slot 44
    cpFsmCtrl* getFsmCtrl();
    void changeThinkToDefault();
    void changeThinkToPlayer();
    void changeThinkToEnemy();
    void setCheckedCollisionBtl();
    void setCheckedCollisionNml();
private:
    rkThinkData* getThinkData();
private:
    MtString mNpcName;  // offset: 0x3770
    MtString mClassName;  // offset: 0x3778
    u32 mAge;  // offset: 0x3780
    cpFsmCtrl* mpFsmCtrl;  // offset: 0x3788
    u32 mNpcTblIndex;  // offset: 0x3790
    s32 mShopId;  // offset: 0x3794
    bool mIsCreateLightComponent;  // offset: 0x3798
    cpPawnThink* mpPawnThink;  // offset: 0x37a0
    bool mIsClassNameDispOld;  // offset: 0x37a8
    bool mIsPartnerPawn;  // offset: 0x37a9
public:
    static MyDTI DTI;
};
