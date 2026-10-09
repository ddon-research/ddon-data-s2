#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/nCharacterData.h"
#include "../shared/nDDOUtility.h"
#include "../shared/nGUIExt.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtDTI;
class MtObject;
class MtPropertyList;
class cContextInstHm;
class cContextPlayerInfo;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjChildAnimationRoot;
class cGUIObjColorAdjust;
class cGUIObjMessage;
class cGUIObjNull;
class cGUIObjPolygon;
class cGUIObjTexture;
class cGUIObject;
class cpJob04;
namespace nCharacterData { struct stCharacterName; }
namespace nGUIExt { struct OcdIconParam; }
class rGUI;
class uHuman;

// Declarations
class uGUIGauge;

// Type aliases from DWARF
using CHAR_NAME = nCharacterData::stCharacterName;
using __uint64_t = long unsigned int;
using u64 = __uint64_t;
using HP_DATATYPE = u64;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class uGUIGauge : public uGUIBase
{
public:
    enum AuraGroup
    {
        AuraGroup_Normal = 0,
        AuraGroup_Custom = 1,
        AuraGroupNum = 2,
    };
    enum AuraType
    {
        AuraType_Heal = 0,
        AuraType_Saint = 1,
        AuraType_Attack = 2,
        AuraType_Defence = 3,
        AuraType_Iron = 4,
        AuraType_Solace = 5,
        AuraTypeNum = 6,
        AuraTypeInvalid = -1,
    };
    enum GAUGE_ID
    {
        GAUGE_MY_PLAYER = 0,
        GAUGE_PARTY_MEMBER_START = 1,
        GAUGE_PARTY_MEMBER_END = 7,
        GAUGE_NUM = 8,
    };
public:
    class MyDTI;
    struct AuraParam;
    struct cGaugeInfo;
    struct StockGauge;
    struct Aura;
    struct GaugePtr;
    class IOcdIcon;
public:
    using IsUseAuraFunc = bool(*)(cpJob04&);
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct AuraParam
    {
    public:
        uGUIGauge::IsUseAuraFunc mIsUseAuraFunc;  // offset: 0x0
        u32 mId;  // offset: 0x8
        uGUIGauge::AuraGroup mGroup;  // offset: 0xc
        s32 mIconFrame;  // offset: 0x10
    };
public:
    struct cGaugeInfo : public MtObject
    {
    public:
        class MyDTI;
        struct StatusInfo;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        struct StatusInfo
        {
        public:
            StatusInfo();
            void init();
        public:
            nGUIExt::OcdIconParam mParam;  // offset: 0x0
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
        cGaugeInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void initGaugeInfo();
    public:
        s32 mMemberIndex;  // offset: 0x8
        s32 mLvLatest;  // offset: 0xc
        HP_DATATYPE mHpLatest;  // offset: 0x10
        HP_DATATYPE mHpWhiteLatest;  // offset: 0x18
        HP_DATATYPE mHpMaxLatest;  // offset: 0x20
        f32 mStLatest;  // offset: 0x28
        f32 mStMaxLatest;  // offset: 0x2c
        u32 mStateLiveLatest;  // offset: 0x30
        f32 mLostTimerRateLatest;  // offset: 0x34
        u64 mExpLatest;  // offset: 0x38
        u32 mReviveNumLatest;  // offset: 0x40
        f32 mMoveFrame;  // offset: 0x44
        StatusInfo mStatusInfos[3];  // offset: 0x48
        CHAR_NAME mName;  // offset: 0xa8
        u32 mNameType;  // offset: 0xc0
        u8 mJobLatest;  // offset: 0xc4
        bool mEnable;  // offset: 0xc5
        bool mUpdate;  // offset: 0xc6
        bool mUpdateEnd;  // offset: 0xc7
        static MyDTI DTI;
    };
public:
    struct StockGauge
    {
    public:
        cGUIInstAnimation* mpINST_fix_elelment_gauge;  // offset: 0x0
        cGUIObjNull* mpOBJ_fix_elelment_gauge_Null_flash;  // offset: 0x8
        cGUIObjPolygon* mpOBJ_fix_elelment_gauge_mask_full;  // offset: 0x10
        cGUIObjChildAnimationRoot* mpOBJ_fix_elelment_gauge_pl_gauge_base;  // offset: 0x18
        cGUIObjNull* mpOBJ_pl_gauge_base_Null_gauge;  // offset: 0x20
        cGUIObjNull* mpOBJ_pl_gauge_base_Null_gather_light;  // offset: 0x28
        cGUIObjColorAdjust* mpOBJ_pl_gauge_base_ColorAdjust;  // offset: 0x30
        cGUIObjTexture* mpOBJ_pl_gauge_base_gather_light;  // offset: 0x38
        f32 mLastRate;  // offset: 0x40
    };
public:
    struct Aura
    {
    public:
        uGUIGauge::AuraType mAuraType;  // offset: 0x0
        cGUIInstAnimation* mpINST_msg_job04;  // offset: 0x8
        cGUIObjMessage* mpOBJ_msg_job04_m_txt;  // offset: 0x10
        cGUIObjTexture* mpOBJ_msg_job04_icon;  // offset: 0x18
    };
public:
    struct GaugePtr
    {
    public:
        cGUIInstNull* mpInst;  // offset: 0x0
        cGUIInstAnimation* mpPawnIconInst;  // offset: 0x8
        cGUIInstAnimation* mpPartyLeaderInst;  // offset: 0x10
        cGUIInstAnimation* mpDeathFlashInst;  // offset: 0x18
        nDDOUtility::cArray<cGUIInstAnimation*, 3> mpLostFlashInst;  // offset: 0x20
        nDDOUtility::cArray<cGUIInstAnimation*, 3> mpOcdInst;  // offset: 0x38
        cGUIObjNull* mpHpNullObj;  // offset: 0x50
        cGUIObjNull* mpStNullObj;  // offset: 0x58
        cGUIObjNull* mpTimerNullObj;  // offset: 0x60
        cGUIObjNull* mpReviveNumNullObj;  // offset: 0x68
        cGUIObjMessage* mpNameObj;  // offset: 0x70
        cGUIObjChildAnimationRoot* mpHpObj;  // offset: 0x78
        cGUIObjChildAnimationRoot* mpHpDyingObj;  // offset: 0x80
        cGUIObjChildAnimationRoot* mpHpWhiteObj;  // offset: 0x88
        cGUIObjChildAnimationRoot* mpHpCurseObj;  // offset: 0x90
        cGUIObjMessage* mpHpValueObj;  // offset: 0x98
        cGUIObjChildAnimationRoot* mpTimerObj;  // offset: 0xa0
        cGUIObjTexture* mpReviveNumObj;  // offset: 0xa8
        cGUIObjChildAnimationRoot* mpRescueObj;  // offset: 0xb0
        cGUIObjColorAdjust* mpStColObj;  // offset: 0xb8
        cGUIObjChildAnimationRoot* mpStObj;  // offset: 0xc0
        cGUIObjMessage* mpLvObj;  // offset: 0xc8
        cGUIObjMessage* mpLvNumObj;  // offset: 0xd0
        cGUIObjChildAnimationRoot* mpSosObj;  // offset: 0xd8
        cGUIObjNull* mpOBJ_msg_fix_gaugesml_Null_f_pawn;  // offset: 0xe0
        nDDOUtility::cArray<cGUIObjTexture*, 3> mpOcdObj;  // offset: 0xe8
        cGUIInstAnimation* mpINST_msg_fix_classicon;  // offset: 0x100
        cGUIObjTexture* mpOBJ_msg_fix_classicon_f_icon_job;  // offset: 0x108
        cGUIObjTexture* mpOBJ_msg_fix_classicon_f_classicon;  // offset: 0x110
        cGUIInstAnimation* mpINST_msg_state;  // offset: 0x118
        cGUIObjMessage* mpOBJ_msg_state_m_state;  // offset: 0x120
    };
public:
    class IOcdIcon : public nGUIExt::OcdIconInterface
    {
    public:
        IOcdIcon(uGUIGauge::GaugePtr& gaugePtr, uGUIGauge::cGaugeInfo& gaugeInfo, const cContextInstHm& contextInstHm);
        // Address: 0x01afb4d0 - 0x01afb4d1 (1 bytes)
        virtual ~IOcdIcon() {}
        bool isFlashing() const;
    protected:
        uGUIGauge::IOcdIcon& operator=(const uGUIGauge::IOcdIcon&);
        virtual u32 getOcdIconParamNum() const;  // vtable slot 2
        virtual nGUIExt::OCD_ICON_CATEGORY getOcdIconCategory(u32 paramIndex) const;  // vtable slot 3
        virtual nGUIExt::OcdIconParam& refOcdIconParam(u32 paramIndex);  // vtable slot 4
        virtual bool isOcdActive(u32 ocdId) const;  // vtable slot 5
        virtual bool isOcdAccumulating(u32 ocdId) const;  // vtable slot 6
        virtual void setOcdIcon(u32 iconIndex, u32 ocdId, nGUIExt::OCD_ICON_ANIM iconAnim, f32 animFrame);  // vtable slot 7
    private:
        uGUIGauge::GaugePtr& mGaugePtr;  // offset: 0x8
        uGUIGauge::cGaugeInfo& mGaugeInfo;  // offset: 0x10
        const cContextInstHm& mContextInstHm;  // offset: 0x18
        bool mIsFlashing;  // offset: 0x20
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
    uGUIGauge();
    virtual ~uGUIGauge();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    void addGauge(s32 memberIndex);
    void removeGauge(s32 memberIndex);
    void setVisibleState(bool bVisible);
    bool isVisibleState();
private:
    void updateInit();
    void updateWait();
    void updateExit();
    f32 clamp(f32, f32, f32);
    void setTextureObjectColor(cGUIObject* pObj, const MtColor& color);
    void initMemberGauge(u32 gaugeId);
    static void SetCurrentFrameRecursively(cGUIObject* object, f32 frame, bool changeFixFrame);
    static bool IsEndObjectAnimation(cGUIObject* object);
    void setupCurseHpRate();
    void setupTireStamina();
    void updateHunterArrow(uHuman* human);
    void setupAura();
    void initAura();
    void updateAura(uHuman* human);
    Aura* getUnusedAura(AuraGroup auraGroup);
    bool updateAlchemyMedal(uHuman* human);
    void initStockGauge(StockGauge& stockGauge, cGUIInstAnimation* instAnimation);
    void updateStockGauge(uHuman* human);
    void updateSorcerer(uHuman* human);
    void updateName(GaugePtr& gaugePtr, cGaugeInfo& gaugeInfo, const cContextInstHm& contextInstHm, bool isMyPlayer, bool isPawn);
    void updateLevel(GaugePtr& gaugePtr, cGaugeInfo& gaugeInfo, const cContextInstHm& contextInstHm);
    void updateLeaderIcon(GaugePtr& gaugePtr, const cContextInstHm& contextInstHm);
    void updatePawnIcon(GaugePtr& gaugePtr, bool isPawn, const cContextInstHm& contextInstHm);
    void updateHp(GaugePtr& gaugePtr, cGaugeInfo& gaugeInfo, const cContextInstHm& contextInstHm, f32 hpMaxRate, u8 jobId, bool isFlowChange);
    void updateReviveNum(GaugePtr& gaugePtr, cGaugeInfo& gaugeInfo, const cContextInstHm& contextInstHm, bool isMyPlayer, bool isPawn);
    void updateAbilityLine(const cContextInstHm& contextInstHm, const cContextPlayerInfo& contextPlayerInfo, f32 hpMaxRate, bool isMyPlayer, bool isDead);
    bool updateLostTimer(GaugePtr& gaugePtr, cGaugeInfo& gaugeInfo, const cContextInstHm& contextInstHm);
    void updateRescueGauge(GaugePtr& gaugePtr, const cContextInstHm& contextInstHm);
    void updateState(GaugePtr& gaugePtr, const cContextInstHm& contextInstHm, bool isDead);
    bool updateOcdIcon(GaugePtr& gaugePtr, cGaugeInfo& gaugeInfo, const cContextInstHm& contextInstHm);
    void updateStamina(GaugePtr& gaugePtr, cGaugeInfo& gaugeInfo, const cContextInstHm& contextInstHm, const cContextPlayerInfo& contextPlayerInfo, bool isFlowChange);
    void updateErosionRescueGauge(GaugePtr& gaugePtr, const cContextInstHm& contextInstHm);
    void updateJob(GaugePtr& gaugePtr, cGaugeInfo& gaugeInfo, u8 jobId, u32 seqId);
    cGaugeInfo* setGauge(u32 gaugeId, s32 memberIndex);
    bool setFlow(u32 flowId);
    void setMemberGaugePosition(cGUIInstNull* instGauge, f32 moveFrame);
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    bool mVisibleState;  // offset: 0x8d0
    cGaugeInfo mTblGaugeInfo[8];  // offset: 0x8d8
    f32 mPartyMengerGaugeInstX;  // offset: 0xf18
    cGUIInstNull* mpINST_Null;  // offset: 0xf20
    cGUIInstNull* mpINST_Null_all;  // offset: 0xf28
    cGUIInstAnimation* mpINST_move;  // offset: 0xf30
    cGUIObjNull* mpOBJ_move_Null;  // offset: 0xf38
    cGUIInstNull* mpINST_PT_gauge00;  // offset: 0xf40
    cGUIObjNull* mpOBJ_msg_fix_gauge_Null_element;  // offset: 0xf48
    nDDOUtility::cArray<StockGauge, 7> mStockGauges;  // offset: 0xf50
    nDDOUtility::cArray<float, 7> mStockGaugeOffsets;  // offset: 0x1148
    f32 mINST_fix_elelment_gauge_x;  // offset: 0x1164
    cGUIObjNull* mpOBJ_msg_fix_gauge_Null_hunter;  // offset: 0x1168
    cGUIObjMessage* mpOBJ_msg_fix_gauge_m_num03;  // offset: 0x1170
    cGUIObjMessage* mpOBJ_msg_fix_gauge_m_num04;  // offset: 0x1178
    cGUIObjMessage* mpOBJ_msg_fix_gauge_m_ctgry;  // offset: 0x1180
    cGUIInstAnimation* mpINST_msg_job04;  // offset: 0x1188
    nDDOUtility::cArray<Aura, 2> mAuras;  // offset: 0x1190
    f32 mAuraBaseX;  // offset: 0x11d0
    f32 mAuraOffsetX;  // offset: 0x11d4
    nDDOUtility::cArray<Aura*, 6> mActiveAuras;  // offset: 0x11d8
    cGUIObjNull* mpOBJ_msg_fix_gauge_Null_alche;  // offset: 0x1208
    cGUIObjMessage* mpOBJ_msg_fix_gauge_m_num05;  // offset: 0x1210
    cGUIObjMessage* mpOBJ_msg_fix_gauge_m_ctgry00;  // offset: 0x1218
    cGUIObjTexture* mpOBJ_msg_fix_gauge_f_joutai_icon;  // offset: 0x1220
    cGUIObjMessage* mpOBJ_msg_fix_gauge_m_num06;  // offset: 0x1228
    cGUIObjMessage* mpOBJ_msg_fix_gauge_m_skill;  // offset: 0x1230
    cGUIInstAnimation* mpINST_revival_flash;  // offset: 0x1238
    cGUIObjTexture* mpOBJ_msg_fix_gauge_f_ability_line00;  // offset: 0x1240
    cGUIObjTexture* mpOBJ_msg_fix_gauge_f_ability_line01;  // offset: 0x1248
    nDDOUtility::cArray<GaugePtr, 8> mGaugePtrs;  // offset: 0x1250
    f32 mCurseHpRate;  // offset: 0x1b90
    f32 mTireStamina;  // offset: 0x1b94
public:
    static MyDTI DTI;
private:
    static const s32 MEMBER_INDEX_INVALID = -1;
    static const u32 LOST_FLASH_INST_NUM = 3;
    static const u32 BASE_OBJ_NUM = 2;
    static const u32 STOCK_NUM = 7;
    static const u32 OCD_ICON_NUM = 3;
    static const AuraParam AuraParams[];
};

// Inline, no code of its own: checked where it is inlined.
inline bool uGUIGauge::isVisibleState() {
    return this->mVisibleState;
}
