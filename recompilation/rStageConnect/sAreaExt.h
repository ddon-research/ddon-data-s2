#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "sArea.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
class aStage;
class cArea;
class rStageJoint;
class rStageList;
class uSoundOcclusion;

// Declarations
class sAreaExt;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class sAreaExt : public sArea
{
public:
    enum eJumpType
    {
        JUMP_TYPE_RELOAD_CODE = 0,
        JUMP_TYPE_RELOAD_MENU = 1,
        JUMP_TYPE_CODE = 2,
        JUMP_TYPE_MENU = 3,
        JUMP_TYPE_NUM = 4,
    };
    enum STAGE_TYPE
    {
        STAGE_TYPE_NORMAL = 0,
        STAGE_TYPE_DARKNESS = 1,
        STAGE_TYPE_EXTENSION = 2,
        STAGE_TYPE_NUM = 3,
    };
    enum
    {
        LV_ROOT = 0,
        LV_INIT = 1,
        LV_TITLE = 1,
        LV_MENU = 1,
        LV_GAME = 1,
        LV_LOBBY = 2,
        LV_STAGE = 2,
        LV_GRID = 0,
    };
public:
    class MyDTI;
    struct stLoadingInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stLoadingInfo
    {
    public:
        stLoadingInfo();
    public:
        union
        {
        public:
            struct
            {
            public:
                u32 isAreaLoading : 1;  // offset: 0x0
                u32 isAreaLoadTrigger : 1;  // offset: 0x0
                u32 isAreaLoadRelease : 1;  // offset: 0x0
                u32 wasAreaLoading : 1;  // offset: 0x0
                u32 nRemainArea : 4;  // offset: 0x0
            };  // offset: 0x0
            u32 data;  // offset: 0x0
        };  // offset: 0x0
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
    sAreaExt();
    virtual ~sAreaExt();
    cArea* getCurrentArea() const;
    aStage* getCurrentStage() const;
    virtual void createMenu(MtPropertyList& s);  // vtable slot 8
    bool isAppendShaderPackageExist(const MtDTI& dti) const;
    void loadResource();
    void releaseResource();
    virtual void move();  // vtable slot 7
    virtual void reload();  // vtable slot 10
    virtual void reloadViaMenu();  // vtable slot 13
    virtual void jump(const MtDTI& dti);  // vtable slot 11
    virtual void jumpViaMenu(const MtDTI& dti);  // vtable slot 14
    void jumpStage(s32 stageNo);
    void jumpStage(s32 stageNo, s32 posNo);
    void jumpStage(const MtDTI& dti, s32 stageNo, s32 posNo);
    s32 getLobbyJumpPosNo();
    bool isAreaLoading() const;
    bool isAreaLoadTrigger() const;
    bool isAreaLoadRelease() const;
    const MtDTI* getJumpAreaDti() const;
    rStageList* getStageList() const;
    bool isLobby() const;
    bool isLobby(s32 stgNo) const;
    bool isField() const;
    bool isField(s32 stgNo) const;
    bool isLestaniaStage() const;
    bool isLestaniaStage(s32 stageNo) const;
    bool isJointStage(s32 stgNo) const;
    bool isSafeArea() const;
    bool isJobActArea() const;
    bool isJobActArea(s32 stgNo) const;
    bool isMergoda() const;
    bool isInBase() const;
    bool isInBaseArea() const;
    bool isSetQuestBoard() const;
    bool isStage() const;
    bool isClanBaseArea(s32 stgNo);
    u32 getStageType(s32 stgNo) const;
    u32 getStageMsgId(s32 stgNo) const;
    s32 convertStageId(s32 stgNo) const;
    s32 convertStageIndex(s32 stgNo) const;
    bool isExistStage(s32 stgNo) const;
    bool isPartsStage();
    bool isPartsUsage();
    u32 getPartsNum();
    u32 getPartsSize(u32 index);
    f32 getPartsSizeZLength(u32 uIdx);
    f32 getPartsOffsetY(u32 uIdx);
    MT_CTSTR getPartsFileName(u32 index);
    s32 getPartsGroupNo(u32 index);
    rStageJoint* getStageJointRes();
    u32 getStageAreaNo(MtVector3& pos);
    s32 getStageJointNo();
    uSoundOcclusion* getSoundOcclusion();
    bool isRandomStage();
    bool isMatchJumpArea(const MtDTI* dti) const;
    u32 getGrassReceiverFrame() const;
    u8 getRecommendLevel(s32 stgNo) const;
    bool isDisableCreateCharacter(s32 stgNo) const;
    void clearReadyBit();
    void setReadyBit(u32 index);
    bool checkReadyBit(u32 index);
    void setAreaJumpSync(bool flag);
    bool isAreaJumpSync() const;
protected:
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void addMenuDDO(MtPropertyList& s, sArea::AreaInfo* pinfo);
    void requestJump(eJumpType type, const MtDTI& dti);
    MT_CTSTR getJumpTypeString(eJumpType type);
    void traceJumpInfo(eJumpType type, const MtDTI& to, s32 stageNo);
    void updateLoadingInfo();
    const stLoadingInfo& getLoadingInfo() const;
public:
    void setIsBaseOld(bool isBase);
private:
    stLoadingInfo mLoadingInfo;  // offset: 0x7068
    u32 mPostponeFrames;  // offset: 0x706c
    bool* mpAppendShaderPackageTable[3];  // offset: 0x7070
    rStageList* mpStageList;  // offset: 0x7088
    u32 mGrassReceiverFrame;  // offset: 0x7090
protected:
    bool mIsAreaJumpSync;  // offset: 0x7094
    u32 mReadyBit;  // offset: 0x7098
    bool mIsBaseOld;  // offset: 0x709c
public:
    static MyDTI DTI;
private:
    static const u32 POSTPONE_FIRST_CHANCE = 4294967293;
};

// Inline, no code of its own: checked where it is inlined.
inline rStageList* sAreaExt::getStageList() const {
    return this->mpStageList;
}
