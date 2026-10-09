#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtSynchronize.h"
#include "../shared/cCharacterData.h"
#include "../shared/cEquipData.h"
#include "../shared/uDDOModel.h"

// Forward declarations
class MtAllocator;
class MtCriticalSection;
class MtDTI;
class MtObject;
class cArcLoaderBase;
class cCharacterData;
class cContextInstHm;
class cEquipData;
class cItemParam;
class cWeaponResTable;
class cpCharacterEdit;
class cpEquip;
class cpIKCtrl;
class cpJointEx2;
class cpMotionFilter;
class cpTinyChain;
namespace nCharacterData { struct stEquipData; }
class rCharacterEdit;
class rMotionParam;

// Declarations
class uMockUpModel;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using TICKET = cArcLoaderBase*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using s8 = signed char;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class uMockUpModel : public uDDOModel
{
public:
    class MyDTI;
    struct stRequest;
    struct stItemData;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stItemData
    {
    public:
        stItemData();
        stItemData(u32 id, s32 color, const cItemParam* pParam);
        stItemData(const uMockUpModel::stItemData& data);
        void init();
        void setData(u32 id, s32 color, const cItemParam* pParam);
        void copy(const uMockUpModel::stItemData& data);
        bool isDifference(const uMockUpModel::stItemData& comp) const;
        bool isInvalidUID() const;
        void clearUID();
    public:
        MT_CHAR mUID[64];  // offset: 0x0
        u32 mCraftElementItemNo[4];  // offset: 0x40
        u32 mId;  // offset: 0x50
        s32 mColor;  // offset: 0x54
        u8 mSex;  // offset: 0x58
    };
public:
    struct stRequest
    {
    public:
        TICKET mTicket;  // offset: 0x0
        uMockUpModel::stItemData mNowItem;  // offset: 0x8
        uMockUpModel::stItemData mLoadingItem;  // offset: 0x64
        uMockUpModel::stItemData mNextItem;  // offset: 0xc0
        bool mIsLoading;  // offset: 0x11c
        bool mIsOff;  // offset: 0x11d
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
    uMockUpModel();
    virtual ~uMockUpModel();
    virtual void createComponent();  // vtable slot 43
    virtual void setupComponentPtr();  // vtable slot 44
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void after();  // vtable slot 173
    void updateBody(bool SetInitAction);
    void updateBodyReq();
    void updateMotion();
    virtual void updateMatrix();  // vtable slot 71
    void updateArmIK();
    void setArmorVisible(bool visible);
    void initEquipData();
    void setEquipData(const cEquipData& equip_data);
    void setupEdit(rCharacterEdit* pRes);
    void setupEdit(cCharacterData::stCharacterEdit* pStCharacterEdit);
    void requestLoadEquip(u32 itemId, s32 color, const cItemParam* pItemParam);
    void requestLoadEquip(const stItemData& itemData);
    void requestLoadEquipCore(const stItemData& itemData);
    void removeEquip(u8 category);
    bool resetEquipReq(u8 category);
    bool isComplete();
    void setDisp(bool isDisp);
    void setMannequinEquip(u32 itemId, s32 color, cItemParam* pParam);
    void endManneuquinMode();
    void resetSimulation();
    void setMotionParam(rMotionParam* pMotParam);
    bool setEmotionList();
    void setAction(u32 ActNo, bool isInit);
    void setStopPauseAction(u32 motNo, f32 frame, f32 hokan);
    void reserveStartPause(u32 motNo, f32 frame, f32 hokan);
    f32 getMotionMaxFrame(u32 motNo) const;
    void setEquipFromEquipData(const cEquipData& equipData);
    void setEquipFromCharaData(cCharacterData& charaData);
    void setFingerMotion();
    void setGrassWind(bool isGrassWind);
    cpIKCtrl* getIKCtrlPtr() const;
private:
    void setEquip(const stItemData& itemData);
public:
    void changeWeapon(u32 index, cWeaponResTable* pWepResData, u32 wepCategory, u8 partsPatern, s8 colorPatern, u8 partsPatern2, s8 colorPatern2);
    void changeArmor(u32 index, cWeaponResTable* pWepResData, u8 partsPatern, s8 colorPatern);
    void changeLantan(cWeaponResTable* pWepResData, u8 partsPatern, s8 colorPatern);
    void changeEquipFromContext(const cContextInstHm* pContext, u32 option);
    void changeEquipFromCharaData(const nCharacterData::stEquipData& charaData, u32 option);
    void changeEquipFromEquipData(const cEquipData& equipData, u32 option);
    void removeEquipAll();
    void resetEquipReqAll();
    void updateEquipLoad();
public:
    cpCharacterEdit* mpCharacterEdit;  // offset: 0x2470
    cpTinyChain* mpTinyChain;  // offset: 0x2478
    cpMotionFilter* mpMotionFilter;  // offset: 0x2480
    cpJointEx2* mpJointEx2;  // offset: 0x2488
    cpEquip* mpEquip;  // offset: 0x2490
    rMotionParam* mpMotionParam;  // offset: 0x2498
private:
    stRequest mReq[15];  // offset: 0x24a0
    cEquipData mEquipData;  // offset: 0x3580
    bool mIsMannequinMode;  // offset: 0x47e8
    rCharacterEdit* mpResource;  // offset: 0x47f0
    u32 mSex;  // offset: 0x47f8
    bool mSetInitAction;  // offset: 0x47fc
    bool mIsGrassWind;  // offset: 0x47fd
    bool mSimResetReq;  // offset: 0x47fe
    bool mUpdateBodyReq;  // offset: 0x47ff
    cpIKCtrl* mpIKCtrl;  // offset: 0x4800
    bool mIsStartPause;  // offset: 0x4808
    u32 mStartPauseMotNo;  // offset: 0x480c
    f32 mStartPauseMotFrame;  // offset: 0x4810
    f32 mStartPauseMotHokan;  // offset: 0x4814
    u32 mFrameCount;  // offset: 0x4818
    MtCriticalSection mCS;  // offset: 0x4820
public:
    static MyDTI DTI;
};
