#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/cDelegate.h"
#include "../shared/cResPath.h"
#include "../shared/cpComponent.h"
#include "../shared/uModel.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtString;
class MtVector3;
class cArcLoaderBase;
class cpEquip;
class rCharacterEdit;
class rCharacterEditColorDef;
class rCharacterEditModelPalette;
class rCharacterEditMuscle;
class rCharacterEditPresetPalette;
class rCharacterEditTexturePalette;
class rCharacterEditVoicePalette;
class rFacialEditJointPreset;
class rFatAdjust;
class rModel;
class rSoundRequest;
class rSoundStreamRequest;
class rTexture;
class uCnsEdit;
class uCnsScaleFix;
class uModel;

// Declarations
class cpCharacterEdit;

// Type aliases from DWARF
using u32 = unsigned int;
using ARC_TAGID = u32;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using TICKET = cArcLoaderBase*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u8 = unsigned char;

class cpCharacterEdit : public cpComponent
{
public:
    enum
    {
        COG0 = 0,
        UPPER1 = 1,
        UPPER2 = 2,
        NECK3 = 3,
        HEAD4 = 4,
        R_SHOULDER5 = 5,
        R_SHOULDER54 = 6,
        R_ARM6 = 7,
        R_ARM7 = 8,
        R_ARM8 = 9,
        R_ARM56 = 10,
        L_SHOULDER9 = 11,
        L_SHOULDER55 = 12,
        L_ARM10 = 13,
        L_ARM11 = 14,
        L_ARM12 = 15,
        L_ARM57 = 16,
        R_TEAT66 = 17,
        R_TEAT67 = 18,
        L_TEAT68 = 19,
        L_TEAT69 = 20,
        LOWER13 = 21,
        R_LEG14 = 22,
        R_LEG15 = 23,
        R_LEG16 = 24,
        R_LEG70 = 25,
        L_LEG18 = 26,
        L_LEG19 = 27,
        L_LEG20 = 28,
        L_LEG71 = 29,
        CHIN105 = 30,
        CHIN106 = 31,
        WP_NULL_R = 32,
        WP_NULL_L = 33,
        WP_NULL_TW = 34,
        WP_NULL_TR = 35,
        WP_NULL_TL = 36,
        EDIT_BODY_JOINT_NUM = 37,
        R_HAND = 37,
        L_HAND = 53,
        FACIAL_TOP = 69,
        EYEBROW_080 = 69,
        EYEBROW_081 = 70,
        EYEBROW_082 = 71,
        EYEBROW_083 = 72,
        EYEBROW_084 = 73,
        EYEBROW_085 = 74,
        EYEBROW_086 = 75,
        EYE_087 = 76,
        EYE_088 = 77,
        EYE_089 = 78,
        EYE_090 = 79,
        EYE_091 = 80,
        EYE_092 = 81,
        EYE_093 = 82,
        EYE_094 = 83,
        EYE_095 = 84,
        EYE_096 = 85,
        EYE_097 = 86,
        EYE_098 = 87,
        EYE_099 = 88,
        EYE_100 = 89,
        NOSE_101 = 90,
        NOSE_102 = 91,
        CHEEK_103 = 92,
        CHEEK_104 = 93,
        JAW_105 = 94,
        CHIN_106 = 95,
        MOUTH_107 = 96,
        MOUTH_108 = 97,
        MOUTH_109 = 98,
        MOUTH_110 = 99,
        MOUTH_111 = 100,
        MOUTH_112 = 101,
        MOUTH_113 = 102,
        MOUTH_114 = 103,
        MOUTH_115 = 104,
        MOUTH_116 = 105,
        MOUTH_117 = 106,
        MOUTH_118 = 107,
        MOUTH_119 = 108,
        MOUTH_120 = 109,
        HEAD_200 = 110,
        FOREHEAD_201 = 111,
        EAR_202 = 112,
        EAR_203 = 113,
        EAR_204 = 114,
        EAR_205 = 115,
        EYE_206 = 116,
        EYE_207 = 117,
        EYE_208 = 118,
        EYE_209 = 119,
        EYEBROW_210 = 120,
        NOSE_211 = 121,
        NOSE_212 = 122,
        NOSE_213 = 123,
        NOSE_214 = 124,
        NOSE_215 = 125,
        CHEEK_216 = 126,
        CHEEK_217 = 127,
        CHEEK_218 = 128,
        CHEEK_219 = 129,
        CHEEK_220 = 130,
        CHIN_221 = 131,
        MOUTH_222 = 132,
        MOUTH_223 = 133,
        FACIAL_JOINT_BOTTOM = 133,
        FACIAL_JOINT_NUM = 65,
        EDIT_JOINT_NUM = 134,
    };
    enum
    {
        CNS_SCALE_R_ARM1 = 0,
        CNS_SCALE_R_ARM2 = 1,
        CNS_SCALE_L_ARM1 = 2,
        CNS_SCALE_L_ARM2 = 3,
        CNS_SCALE_R_LEG1 = 4,
        CNS_SCALE_R_LEG2 = 5,
        CNS_SCALE_L_LEG1 = 6,
        CNS_SCALE_L_LEG2 = 7,
        CNS_SCALE_TEAT66 = 8,
        CNS_SCALE_TEAT67 = 9,
        CNS_SCALE_TEAT68 = 10,
        CNS_SCALE_TEAT69 = 11,
        CNS_SCALE_FIX_NUM = 12,
    };
    enum
    {
        FACIAL_PARTS_PRESET_TYPE_EYE = 0,
        FACIAL_PARTS_PRESET_TYPE_NOSE = 1,
        FACIAL_PARTS_PRESET_TYPE_MOUTH = 2,
        FACIAL_PARTS_PRESET_TYPE_NUM = 3,
    };
    enum
    {
        COLOR_DEF_SKIN = 0,
        COLOR_DEF_HAIR = 1,
        COLOR_DEF_MAKEUP = 2,
        COLOR_DEF_NUM = 3,
    };
    enum
    {
        HAIR_ARC = 0,
        BEARD_ARC = 1,
        EYEBROW_ARC = 2,
        MAKEUP_ARC = 3,
        SCAR_ARC = 4,
        EYE_ARC = 5,
        NOSE_ARC = 6,
        MOUTH_ARC = 7,
        VOICE_ARC = 8,
        ARC_NUM = 9,
    };
    enum
    {
        FLAG_SET_RESOURCE_IGNORE_NULL = 1,
    };
    enum
    {
        R_HAND_JNT_NO_TOP = 22,
        R_HAND_NUM = 16,
        L_HAND_JNT_NO_TOP = 38,
        L_HAND_NUM = 16,
    };
    enum
    {
        J001_F = 0,
        J002_F = 1,
        J003_F = 2,
        J005_F = 3,
        J006_F = 4,
        J007_F = 5,
        J009_F = 6,
        J010_F = 7,
        J011_F = 8,
        J013_F = 9,
        J014_F = 10,
        J015_F = 11,
        J018_F = 12,
        J054_F = 13,
        J055_F = 14,
        J056_F = 15,
        J057_F = 16,
        J066_F = 17,
        J068_F = 18,
        J070_F = 19,
        J071_F = 20,
        J106_F = 21,
        FAT_NUM = 22,
    };
    enum
    {
        EYE_PRESET_087 = 0,
        EYE_PRESET_088 = 1,
        EYE_PRESET_089 = 2,
        EYE_PRESET_090 = 3,
        EYE_PRESET_091 = 4,
        EYE_PRESET_092 = 5,
        EYE_PRESET_093 = 6,
        EYE_PRESET_094 = 7,
        EYE_PRESET_095 = 8,
        EYE_PRESET_096 = 9,
        EYE_PRESET_097 = 10,
        EYE_PRESET_098 = 11,
        EYE_PRESET_099 = 12,
        EYE_PRESET_100 = 13,
        EYE_PRESET_206 = 14,
        EYE_PRESET_207 = 15,
        EYE_PRESET_208 = 16,
        EYE_PRESET_209 = 17,
        EYE_PRESET_NUM = 18,
    };
    enum
    {
        NOSE_PRESET_101 = 0,
        NOSE_PRESET_102 = 1,
        NOSE_PRESET_211 = 2,
        NOSE_PRESET_212 = 3,
        NOSE_PRESET_213 = 4,
        NOSE_PRESET_214 = 5,
        NOSE_PRESET_215 = 6,
        NOSE_PRESET_NUM = 7,
    };
    enum
    {
        MOUTH_PRESET_107 = 0,
        MOUTH_PRESET_108 = 1,
        MOUTH_PRESET_109 = 2,
        MOUTH_PRESET_110 = 3,
        MOUTH_PRESET_111 = 4,
        MOUTH_PRESET_112 = 5,
        MOUTH_PRESET_113 = 6,
        MOUTH_PRESET_114 = 7,
        MOUTH_PRESET_115 = 8,
        MOUTH_PRESET_116 = 9,
        MOUTH_PRESET_117 = 10,
        MOUTH_PRESET_118 = 11,
        MOUTH_PRESET_119 = 12,
        MOUTH_PRESET_120 = 13,
        MOUTH_PRESET_222 = 14,
        MOUTH_PRESET_223 = 15,
        MOUTH_PRESET_NUM = 16,
    };
    enum
    {
        EYEBROW_ORG_080 = 0,
        EYEBROW_ORG_081 = 1,
        EYEBROW_ORG_082 = 2,
        EYEBROW_ORG_083 = 3,
        EYEBROW_ORG_084 = 4,
        EYEBROW_ORG_085 = 5,
        EYEBROW_ORG_086 = 6,
        EYE_ORG_087 = 7,
        EYE_ORG_088 = 8,
        EYE_ORG_089 = 9,
        EYE_ORG_090 = 10,
        EYE_ORG_091 = 11,
        EYE_ORG_092 = 12,
        EYE_ORG_093 = 13,
        EYE_ORG_094 = 14,
        EYE_ORG_095 = 15,
        EYE_ORG_096 = 16,
        EYE_ORG_097 = 17,
        EYE_ORG_098 = 18,
        EYE_ORG_099 = 19,
        EYE_ORG_100 = 20,
        NOSE_ORG_101 = 21,
        NOSE_ORG_102 = 22,
        CHEEK_ORG_103 = 23,
        CHEEK_ORG_104 = 24,
        JAW_ORG_105 = 25,
        CHIN_ORG_106 = 26,
        MOUTH_ORG_107 = 27,
        MOUTH_ORG_108 = 28,
        MOUTH_ORG_109 = 29,
        MOUTH_ORG_110 = 30,
        MOUTH_ORG_111 = 31,
        MOUTH_ORG_112 = 32,
        MOUTH_ORG_113 = 33,
        MOUTH_ORG_114 = 34,
        MOUTH_ORG_115 = 35,
        MOUTH_ORG_116 = 36,
        MOUTH_ORG_117 = 37,
        MOUTH_ORG_118 = 38,
        MOUTH_ORG_119 = 39,
        MOUTH_ORG_120 = 40,
        HEAD_ORG_200 = 41,
        FOREHEAD_ORG_201 = 42,
        EAR_ORG_202 = 43,
        EAR_ORG_203 = 44,
        EAR_ORG_204 = 45,
        EAR_ORG_205 = 46,
        EYE_ORG_206 = 47,
        EYE_ORG_207 = 48,
        EYE_ORG_208 = 49,
        EYE_ORG_209 = 50,
        EYEBROW_ORG_210 = 51,
        NOSE_ORG_211 = 52,
        NOSE_ORG_212 = 53,
        NOSE_ORG_213 = 54,
        NOSE_ORG_214 = 55,
        NOSE_ORG_215 = 56,
        CHEEK_ORG_216 = 57,
        CHEEK_ORG_217 = 58,
        CHEEK_ORG_218 = 59,
        CHEEK_ORG_219 = 60,
        CHEEK_ORG_220 = 61,
        CHIN_ORG_221 = 62,
        MOUTH_ORG_222 = 63,
        MOUTH_ORG_223 = 64,
        FACE_NUM = 65,
    };
public:
    class MyDTI;
    struct stFacialJntTbl;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stFacialJntTbl
    {
    public:
        u32 mPreset;  // offset: 0x0
        u32 mCnsNo;  // offset: 0x4
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
    cpCharacterEdit();
    virtual ~cpCharacterEdit();
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void updatePtr();  // vtable slot 9
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void setEquipComponent(cpEquip* pEquip);
    void setFlag(u32);
    u32 getFlag();
    void onFlag(u32 flag);
    void offFlag(u32);
    f32 getHeightScale();
    void setResource(rCharacterEdit* pRes);
    rCharacterEdit* getResource();
    void setJobFatAdjust(rFatAdjust* pRes);
    rFatAdjust* getJobFatAdjust();
    void setCustomFatAdjust(rFatAdjust* pRes);
    rFatAdjust* getCustomFatAdjust();
    void setEventFatAdjust(rFatAdjust* pRes);
    rFatAdjust* getEventFatAdjust();
    void updateBody(bool generate_body);
    void updateUnderwear();
    void updateHair();
    void updateBeard();
    void updateEyePreset();
    void updateNosePreset();
    void updateMouthPreset();
    void updateEyebrow();
    void updateMakeup();
    void updateScar();
    void updateVoice();
    void updateAll();
    void updateBodyReq();
    void updateHairReq();
    void updateBeardReq();
    void updateEyePresetReq();
    void updateNosePresetReq();
    void updateMouthPresetReq();
    void updateEyebrowReq();
    void updateMakeupReq();
    void updateScarReq();
    void updateVoiceReq();
    void updateAllReq();
    static rCharacterEdit* createBodyPresetResource(u32 body_type);
    rModel* createHairResource();
    rModel* createBeardResource();
    rModel* createMakeupResource();
    static ARC_TAGID makeHairArcTagId(s32 no);
    static ARC_TAGID makeBeardArcTagId(s32 no);
    static ARC_TAGID makeEyebrowArcTagId(s32 no);
    static ARC_TAGID makeMakeupArcTagId(s32 no);
    static ARC_TAGID makeScarArcTagId(s32 no);
    static ARC_TAGID makeEyeArcTagId(s32 no);
    static ARC_TAGID makeNoseArcTagId(s32 no);
    static ARC_TAGID makeMouthArcTagId(s32 no);
    void randomFace();
    void randomMakeup();
    void randomBody();
    bool findModelPalette(u32 No, cResPath<rCharacterEditModelPalette>& ResPath);
    bool findModelPalette(u32 No, MT_CTSTR arc_tag, MT_CTSTR search_name);
    bool findModelPalette(u32 No, rCharacterEditModelPalette* pPalette);
    bool findPresetPalette(u32 No, cResPath<rCharacterEditPresetPalette>& ResPath);
    bool findPresetPalette(u32 No, MT_CTSTR arc_tag, MT_CTSTR search_name);
    bool findPresetPalette(u32 No, rCharacterEditPresetPalette* pPalette);
    bool findTexturePalette(u32 No, cResPath<rCharacterEditTexturePalette>& ResPath);
    bool findTexturePalette(u32 No, MT_CTSTR arc_tag, MT_CTSTR search_name);
    bool findTexturePalette(u32 No, rCharacterEditTexturePalette* pPalette);
    bool findVoicePalette(u32 No, cResPath<rCharacterEditVoicePalette>& ResPath);
    bool findVoicePalette(u32 No, MT_CTSTR arc_tag, MT_CTSTR search_name);
    bool findVoicePalette(u32 No, rCharacterEditVoicePalette* pPalette);
    rCharacterEditVoicePalette* getVoicePalette(u8 bodyType, u32 unitType) const;
    u32 getVoicePalletSize(u8 bodyType, u32 unitType);
    rSoundRequest* getVoiceRes() const;
    rSoundStreamRequest* getVoiceStreamRes() const;
    bool isLoading();
    void setBaking();
    bool isBaking();
    rCharacterEditColorDef* getColorDef(u32 type);
    bool isSleep();
    void setSleep(bool sleep);
protected:
    void setMuscleConstRes(rCharacterEditMuscle* pRes);
    rCharacterEditMuscle* getMuscleConstRes();
    void setOrgJointPresetRes(rFacialEditJointPreset* pRes);
    rFacialEditJointPreset* getOrgJointPresetRes();
    void setFacialEditJointPresetRes(rFacialEditJointPreset* pRes, u32 type);
    rFacialEditJointPreset* getFacialEditJointPresetRes(u32 type);
    void setFacialEditJointPresetResNum();
    u32 getFacialEditJointPresetResNum();
    void setColorDef(rCharacterEditColorDef* pRes, u32 type);
    void setColorDefNum();
    u32 getColorDefNum();
    void calcBodyEdit();
    void calcFacialEdit();
    void calcHitai();
    void calcMemoto();
    void calcHoho();
    void calcMe();
    void calcMayu();
    void calcMimi();
    void calcMiken();
    void calcUehoho();
    void calcShitahoho();
    void calcHana();
    void calcKuchi();
    void calcMaterial();
    void getMuscle(u32 MuscleConstIdx, MtVector3& fat, MtVector3& muscle);
    void calcEyeScale(u32 CnsNo, u32 UpperCnsNo, u32 UpperOrgNo, u32 LowerCnsNo, u32 LowerOrgNo);
    void adjustCOG(uModel::Joint* pJnt, uModel* pModel, uCnsEdit* pCnsEdit);
    void adjustBody(uModel::Joint* pJnt, uModel* pModel, uCnsEdit* pCnsEdit);
    void adjustWeaponNull(uModel::Joint* pJnt, uModel* pModel, uCnsEdit* pCnsEdit);
    void adjustFacial(uModel::Joint* pJnt, uModel* pModel, uCnsEdit* pCnsEdit);
    void updateFatAdjust(uModel* pModel);
    void createConstraint();
    uCnsEdit* createConstraint(s32 JntNo, u32 pri);
    void removeConstraint();
    void requestArcLoad(u32 type);
    void waitArcLoad();
    bool setupHair();
    bool setupBeard();
    bool setupEyePreset();
    bool setupNosePreset();
    bool setupMouthPreset();
    bool setupEyebrow();
    bool setupMakeup();
    bool setupScar();
    bool setupVoice();
    bool setupBakeingEyePreset();
    bool setupBakeingNosePreset();
    bool setupBakeingMouthPreset();
    MtString getVoiceSearchName(u8 bodyType, u32 unitType) const;
public:
    MT_CTSTR getPaletteAlt() const;
    bool isNeedUpdateMatrixRetry() const;
    void setUpdateMatrixRetry(bool flag);
public:
    bool mUpdateBodyReq;  // offset: 0x50
    bool mUpdateHairReq;  // offset: 0x51
    bool mUpdateBeardReq;  // offset: 0x52
    bool mUpdateEyePresetReq;  // offset: 0x53
    bool mUpdateNosePresetReq;  // offset: 0x54
    bool mUpdateMouthPresetReq;  // offset: 0x55
    bool mUpdateEyebrowReq;  // offset: 0x56
    bool mUpdateMakeupReq;  // offset: 0x57
    bool mUpdateScarReq;  // offset: 0x58
    bool mUpdateVoiceReq;  // offset: 0x59
    bool mUpdateAllReq;  // offset: 0x5a
    cDelegate_0<void> callbackSetupVoice;  // offset: 0x60
protected:
    uModel* mpBodyModel;  // offset: 0x78
    uModel* mpMakeupModel;  // offset: 0x80
    uModel* mpHairModel;  // offset: 0x88
    uModel* mpBeardModel;  // offset: 0x90
    rCharacterEdit* mpResource;  // offset: 0x98
    rCharacterEditMuscle* mpMuscleConstRes;  // offset: 0xa0
    rFacialEditJointPreset* mpOrgJointPresetRes;  // offset: 0xa8
    rFacialEditJointPreset* mpFacialEditJointPreset[3];  // offset: 0xb0
    rCharacterEditColorDef* mpColorDef[3];  // offset: 0xc8
    cpEquip* mpEquip;  // offset: 0xe0
    uCnsEdit* mpCnsEdit[134];  // offset: 0xe8
    uCnsScaleFix* mpCnsScaleFix[12];  // offset: 0x518
    rTexture* mpEyebrowTex;  // offset: 0x578
    rTexture* mpMakeupTex;  // offset: 0x580
    rTexture* mpScarTex;  // offset: 0x588
    rSoundRequest* mpVoice;  // offset: 0x590
    rSoundStreamRequest* mpVoiceStream;  // offset: 0x598
    TICKET mArcTicket[9];  // offset: 0x5a0
    bool mArcLoadReq[9];  // offset: 0x5e8
    bool mIsArcReady[9];  // offset: 0x5f1
    u32 mRequestedNo[9];  // offset: 0x5fc
    u32 mLoadMode;  // offset: 0x620
    bool mIsBaking;  // offset: 0x624
    bool mSleep;  // offset: 0x625
    u32 mSleepRno;  // offset: 0x628
    u32 mSleepTimer;  // offset: 0x62c
    rFatAdjust* mpJobFatAdjust;  // offset: 0x630
    rFatAdjust* mpCustomFatAdjust;  // offset: 0x638
    rFatAdjust* mpEventFatAdjust;  // offset: 0x640
    MtVector3 mFatAdjust;  // offset: 0x650
    MtVector3 mFatAdjustTrans;  // offset: 0x660
    f32 mFatAdjustBlend;  // offset: 0x670
    f32 mThreshold;  // offset: 0x674
    f32 mHeightScale;  // offset: 0x678
    f32 mHeadScale;  // offset: 0x67c
    u32 mFlag;  // offset: 0x680
private:
    bool mIsmNeedUpdateMatrixRetry;  // offset: 0x684
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline f32 cpCharacterEdit::getHeightScale() {
    return this->mHeightScale;
}

// Inline, no code of its own: checked where it is inlined.
inline bool cpCharacterEdit::isNeedUpdateMatrixRetry() const {
    return this->mIsmNeedUpdateMatrixRetry;
}
