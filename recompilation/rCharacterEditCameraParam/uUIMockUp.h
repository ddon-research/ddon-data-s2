#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtColor.h"
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/cEquipData.h"
#include "../shared/nPrim.h"
#include "uMockUpModel.h"
#include "../shared/uScreenSpace.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtCriticalSection;
class MtDTI;
struct MtFloat2;
class MtObject;
class MtPropertyList;
class MtVector2;
class cCharacterData;
class cContextInstHm;
class cEquipData;
class cItemParam;
namespace nCharacterData { struct stEquipData; }
namespace nPrim { class PrimVertex; }
class rCharacterEdit;
class rMotionList;
class rRenderTargetTexture;
class uInfiniteLightExt;
class uMockUpModel;

// Declarations
class uUIMockUp;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class uUIMockUp : public uScreenSpace
{
public:
    enum
    {
        RESET_TYPE_MARGE = 0,
        RESET_TYPE_PERFORMANCE = 1,
        RESET_TYPE_VISUAL = 2,
    };
    enum
    {
        MODE_PLAYER = 0,
        MODE_PAWN = 1,
        MODE_HUMAN = 2,
        MODE_SAVEDATA = 3,
        MODE_MANNEQUINE_MALE = 4,
        MODE_MANNEQUINE_FEMALE = 5,
    };
public:
    class MyDTI;
    class DispInfo;
    class cAutoCriticalSection;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class DispInfo
    {
    public:
        DispInfo();
        bool isSameModel(uUIMockUp::DispInfo& info);
        void resetItem();
        void setMannequineItem(u32 item_id, s32 color, const cItemParam* pItemParam);
        void endMannequine();
        void setItem(u32 item_id, s32 color, const cItemParam* pItemParam);
        void removeItem(u8 category);
    public:
        void* mpData;  // offset: 0x0
        u32 mMode;  // offset: 0x8
        uMockUpModel::stItemData mItemData[15];  // offset: 0xc
        uMockUpModel::stItemData mMannequineItemData;  // offset: 0x570
        bool mIsMannequine;  // offset: 0x5cc
        bool mIsDisp;  // offset: 0x5cd
    };
public:
    class cAutoCriticalSection
    {
    public:
        cAutoCriticalSection();
        ~cAutoCriticalSection();
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
    uUIMockUp();
    virtual ~uUIMockUp();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void move();  // vtable slot 9
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    virtual void setup();  // vtable slot 6
    void setupMyPlayerModel();
    void setupPawnModel();
    void setupFromSaveData(cCharacterData* pEdit, rMotionList* pmot);
    void setupPawnModelContext(const cContextInstHm* pPawnContext);
    void setupPlayerModelContext(const cContextInstHm* pContextHm);
    void setRenderTargetTexture(rRenderTargetTexture* pRTT);
    void changeEquip(const cItemParam* pItemParam);
    void changeEquip(u32 itemId, s32 color, const cItemParam* pItemParam);
    void resetEquip();
    void resetEquip(const cEquipData& equip_data, bool isSetBaseEquip);
    void setBaseEquip(const cEquipData&);
private:
    void resetEquipSub(uMockUpModel::stItemData(&item_id_table)[15]);
    void setupEquipFromContext(const cContextInstHm* pContext, uMockUpModel::stItemData(&item_id_table)[15]);
    void setupEquipFromEquipData(const cEquipData& equipData, uMockUpModel::stItemData(&item_id_table)[15]);
    void setupEquipFromEquipStruct(const nCharacterData::stEquipData& stEquip, uMockUpModel::stItemData(&item_id_table)[15]);
public:
    void removeEquip(u8 category);
    bool isComplete();
    void setDisp(bool isDisp);
    void setMannequinEquip(cItemParam* pParam);
    void setMannequinEquip(u32 itemId, s32 color, cItemParam* pParam);
    void setMannequinEquip(const cContextInstHm* pContext, u32 itemId, s32 color, cItemParam* pParam);
    void setupMannequineModel(bool isMale);
    void endMannequinMode();
    bool isEquipEnable(const cContextInstHm* pContext, u32 itemId);
    void setResetType(u32 type);
    void resetModel();
    void setPosDisp(const MtVector2&);
    MtVector2 getPosDisp();
    void setWHDisp(const MtFloat2&);
    MtFloat2 getWHDisp();
    void setColor(MtColor);
    MtColor getColor();
    void setCamDist(f32);
    f32 getCamDist();
    void setCamYOfs(f32);
    f32 getCamYOfs();
    void setCamDistDef(f32 fDist);
    f32 getCamDistDef();
    void setCamYOfsDef(f32 fYOfs);
    f32 getCamYOfsDef();
    void setHideEnable(bool isEnable);
    void setMotion(u32 MotNo, f32 Frame, f32 hokan);
    f32 getMotionMaxFrame(u32 MotNo);
    void useEmotion();
    void setChatSubMenu(bool bFlg);
    void setEnableRotate(bool isEnable);
private:
    void createModel(bool isForceCreate);
    void setupModelContext(const cContextInstHm* pContextHm, u32 Mode);
    void setupCostume(u32 item_id);
    bool isCostume(u32 item_id);
    void updateVertices();
    void updateCameraPos();
    void setupCameraDist(f32 model_height);
    void setupCameraDist();
    void setActive(bool isActive);
    void setupActive();
    void delList();
private:
    nPrim::PrimVertex mVtx[4];  // offset: 0x2a0
    MtVector2 mPosDisp;  // offset: 0x420
    MtFloat2 mWHDisp;  // offset: 0x428
    MtColor mColor;  // offset: 0x430
    f32 mCamDist;  // offset: 0x434
    f32 mCamYOfs;  // offset: 0x438
    f32 mCamDistDef;  // offset: 0x43c
    f32 mCamYOfsDef;  // offset: 0x440
    f32 mModelHeight;  // offset: 0x444
    u32 mJointNo;  // offset: 0x448
    u32 mResetType;  // offset: 0x44c
    const cContextInstHm* mpContext;  // offset: 0x450
    rCharacterEdit* mpEdit;  // offset: 0x458
    cCharacterData* mpCharacterData;  // offset: 0x460
    rMotionList* mpMotionList;  // offset: 0x468
    DispInfo mLocalInfo;  // offset: 0x470
    cEquipData mEquipData;  // offset: 0xa40
    bool mIsCreatedModel;  // offset: 0x1ca8
    bool mIsUseEmotion;  // offset: 0x1ca9
    bool mIsInitDisp;  // offset: 0x1caa
    bool mIsActive;  // offset: 0x1cab
    bool mIsChatSubMenu;  // offset: 0x1cac
    bool mIsEnableRotate;  // offset: 0x1cad
    bool mIsHideEnable;  // offset: 0x1cae
public:
    static MyDTI DTI;
private:
    static DispInfo mModelInfo;
    static uInfiniteLightExt* mpLight;
    static uMockUpModel* mpModel;
    static MtCriticalSection mCS;
    static u32 mRefCount;
public:
    static const u32 mockup_list_num = 5;
private:
    static uUIMockUp* mMockUpList[5];
};
