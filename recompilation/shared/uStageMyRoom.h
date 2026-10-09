#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "Common.h"
#include "MtCollection.h"
#include "MtDTI.h"
#include "cFurnitureMenuFlow.h"
#include "cItemParam.h"
#include "cUnit.h"
#include "uAnimal.h"

// Forward declarations
class CDataCommonU32;
class CDataMyRoomOption;
class MtAllocator;
class MtDTI;
class MtObject;
class cContextInstHm;
class cFurniture;
class cFurnitureMenuFlow;
class cItemParam;
class cNetGameServer;
class rAnimalData;
class rFurnitureData;
class rFurnitureGroup;
class rFurnitureItem;
class rFurnitureLayout;
class rGUIMessage;
class uAnimal;
class uControlNpc;

// Declarations
class uStageMyRoom;

// Type aliases from DWARF
using CMyRoomOption = CDataMyRoomOption;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s8 = signed char;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class uStageMyRoom : public cUnit
{
    // inferred: cNetGameServer::updateMyRoomBgm names uStageMyRoom::mPlayBgmAcquirementNo
    friend class cNetGameServer;
public:
    enum
    {
        PATTERN_FOREST = 0,
        PATTERN_COW = 1,
        PATTERN_PIG = 2,
        PATTERN_RABIT = 3,
        PATTERN_GRIFFIN = 4,
        PATTERN_NONE = 5,
        PATTERN_NUM = 6,
        NPCID_PARTNER = 7100,
    };
    enum
    {
        R0_MOVE_INIT = 0,
        R0_MOVE_MAIN = 1,
        R0_MOVE_EXIT = 2,
        R1_MOVE_INIT = 0,
        R1_MOVE_GET_LIST = 1,
        R1_MOVE_GET_REWARD = 2,
        R1_MOVE_GET_HISTORY = 3,
        R1_MOVE_GET_HISTORY2 = 4,
        R1_MOVE_WAIT = 5,
        R1_MOVE_MAIN = 6,
        R1_MOVE_WATCH = 7,
        R1_MOVE_GET_AVAILABLE_LIST = 8,
        R1_MOVE_GET_RELEASE_LIST = 9,
        R1_MOVE_EXIT = 10,
    };
    enum
    {
        ANIMAL_TYPE_NUM = 4,
    };
public:
    class MyDTI;
    struct ANIMAL_PATTERN;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct ANIMAL_PATTERN
    {
    public:
        u8 rate;  // offset: 0x0
        u8 max[4];  // offset: 0x1
        s8 type[4];  // offset: 0x5
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
    uStageMyRoom();
    virtual ~uStageMyRoom();
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    bool isWarpIn();
    u32 getPartnerPawnId();
    bool isPawnInParty();
    u8 getPawnEva();
private:
    void moveInit();
    void moveMain();
public:
    bool isRewardEditOK();
    void setRewardEditOK(bool flag);
    bool isLikabilityMax();
    void setLikabilityMax(bool isLikabilityMax);
    bool isAlreadyPass();
    void setAlreadyPass(bool isAlreadyPass);
    bool isLayoutFurniture();
    void setLayoutFurniture(bool isLayoutFurniture);
    bool isCraftFurniture();
    void setCraftFurniture(bool isCraftFurniture);
    void copyItemParam(cContextInstHm* pContext, bool isInit, u32 pawnId);
    void setItemParam(u32 index, cItemParam* pItemParam, u32 type);
    cItemParam* getItemParam(u32 index, u32 type);
    void setItemParamHead(cItemParam* pItemParam, u32 type);
    cItemParam* getItemParamHead(u32 type);
    void setFadeOutUnit(bool isFade);
private:
    void movePartnerPawn();
    u32 getPawnSlotNo(u32 pawnId);
    uControlNpc* getCtrlPartner();
public:
    void loadFurniture();
    bool isSetFurniture(u32 idx);
    bool isSetOm(u32 om_id);
    bool isSetItem(u32 item_id);
    void checkRoomWear();
    void checkRoomWearTrial();
    cFurniture* getFurniture();
    rFurnitureData* getFurnitureData();
    rFurnitureGroup* getFurnitureGroup();
    rFurnitureLayout* getFurnitureLayout();
    rFurnitureItem* getFurnitureItem();
    rGUIMessage* getFurnitureGroupName();
    rGUIMessage* getFurnitureLayoutName();
    void bootFurnitureMenu();
    bool isBootFurnitureMenu() const;
    bool isRoomWearCamera() const;
    bool setMyRoomOption(const CMyRoomOption& opt);
    u32 getMyRoomBgmListByIndex(u32 index);
    u32 getMyRoomBgmListCount();
    u32 getMyRoomBgmNowPlayAbilityNumber();
    void setMyRoomBgmNowPlayAbilityNumber(u32 abiNo);
private:
    void initFurniture();
    void moveFurniture();
    void releaseFurniture();
public:
    u32 getPatternId() const;
private:
    void initAnimal();
    void moveAnimal();
    void releaseAnimal();
    void clearAnimal();
    void createAnimal();
    void createAnimalPtn(u32 pattern_id);
    void controlCamera();
private:
    u32 mPartnerPawnId;  // offset: 0x48
    u32 mPartnerPawnSlot;  // offset: 0x4c
    u8 mPawnEva;  // offset: 0x50
    bool mIsUnitFade;  // offset: 0x51
    bool mIsWarpIn;  // offset: 0x52
    bool mIsPawnInParty;  // offset: 0x53
    bool mIsRewardEditOK;  // offset: 0x54
    bool mIsLikabilityMax;  // offset: 0x55
    bool mIsAlreadyPass;  // offset: 0x56
    bool mIsLayoutFurniture;  // offset: 0x57
    bool mIsCraftFurniture;  // offset: 0x58
    cItemParam mItemParam[2][7];  // offset: 0x60
    cItemParam mItemParamHead[2];  // offset: 0x6f0
    rFurnitureData* mpFurnitureData;  // offset: 0x7e0
    rFurnitureGroup* mpFurnitureGroup;  // offset: 0x7e8
    rFurnitureLayout* mpFurnitureLayout;  // offset: 0x7f0
    rFurnitureItem* mpFurnitureItem;  // offset: 0x7f8
    rGUIMessage* mpFurnitureGroupName;  // offset: 0x800
    rGUIMessage* mpFurnitureLayoutName;  // offset: 0x808
    cFurniture* mpFurniture;  // offset: 0x810
    cFurnitureMenuFlow mFurnitureMenuFlow;  // offset: 0x818
    bool mIsMoveMenu;  // offset: 0x900
    MtTypedArray<CDataCommonU32> mBgmAcquirementNoList;  // offset: 0x908
    u32 mPlayBgmAcquirementNo;  // offset: 0x928
    rAnimalData* mpAnimalData;  // offset: 0x930
    MtTypedArray<uAnimal> mAnimalList;  // offset: 0x938
    u32 mPatternId;  // offset: 0x958
public:
    static MyDTI DTI;
private:
    static const ANIMAL_PATTERN mAnimalPatternTbl[6];
};
