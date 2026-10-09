#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "cCharacterData.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtPropertyList;
class cStorageDataEdit;

// Declarations
class cEditParam;
class cEditValue;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s16 = short;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cEditValue : public MtObject
{
    // inferred: cEditParam::save names cEditParam::mSokutoubu.mValue
    friend class cEditParam;
public:
    enum
    {
        EDIT_BODY = 1,
        EDIT_FACE = 2,
        EDIT_CONST = 4,
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
    cEditValue();
    cEditValue(const cEditValue& src);
    void setValue(f32 value, f32 min, f32 max, u32 Flag);
    void setValue(f32 value);
    f32 getValue() const;
    void setRandom(f32 range);
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    static void readData(MtDataReader& in, cEditValue& data);
    static void writeData(MtDataWriter& out, cEditValue& data);
    void mergeOnSlider();
public:
    f32 mDefault;  // offset: 0x8
    f32 mMin;  // offset: 0xc
    f32 mMax;  // offset: 0x10
    u32 mFlag;  // offset: 0x14
    s16 mDiv;  // offset: 0x18
protected:
    f32 mValue;  // offset: 0x1c
public:
    static MyDTI DTI;
};

class cEditParam : public MtObject
{
public:
    enum
    {
        UNIT_TYPE_PL = 0,
        UNIT_TYPE_PAWN = 1,
        UNIT_TYPE_NPC = 2,
        UNIT_TYPE_ONEOFF_NPC = 3,
        UNIT_TYPE_NUM = 4,
    };
    enum
    {
        MALE = 0,
        FEMALE = 1,
    };
    enum
    {
        FLAG_ARISEN_SCAR_SET = 1,
        FLAG_PAWN_SCAR_SET = 2,
        FLAG_ARISEN_SCAR_DISP = 4,
        FLAG_PAWN_SCAR_DISP = 8,
        FLAG_ARISEN_SCAR = 5,
        FLAG_PAWN_SCAR = 10,
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
    cEditParam();
    // Address: 0x01967ff0 - 0x01967ff1 (1 bytes)
    virtual ~cEditParam() {}
    bool load(MtDataReader& in);
    bool save(MtDataWriter& out);
    void copy(const cEditParam* pSrc, bool DoNotCopyFlagAndUnitType);
    void copyBody(const cEditParam* pSrc);
    void copyFace(const cEditParam* pSrc);
    void copyBodyPreset(u32 sex);
    void copyConstValue(u32 sex);
    void copyConstValue(const cEditParam* pSrc);
    void copyRange(cEditValue& Dst, const cEditValue& Src);
    void copyToCharacterData(cCharacterData::stCharacterEdit* pDst);
    void copyFromCharacterData(const cCharacterData::stCharacterEdit* pSrc);
    void copyToStrageData(cStorageDataEdit* pDstData) const;
    void copyFromStrageData(const cStorageDataEdit* pSrcData);
    bool isEditValid();
    bool isParamValid(cEditValue& val);
    void resetCharacterEdit();
public:
    f32 mRandomRangeFace;  // offset: 0x8
    f32 mRandomRangeBody;  // offset: 0xc
    u32 mVersion;  // offset: 0x10
    u32 mUnitType;  // offset: 0x14
    u32 mFlag;  // offset: 0x18
    u8 mBodyType;  // offset: 0x1c
    s32 mHair;  // offset: 0x20
    s32 mBeard;  // offset: 0x24
    s32 mMakeup;  // offset: 0x28
    s32 mScar;  // offset: 0x2c
    s32 mVoice;  // offset: 0x30
    s32 mVoicePitch;  // offset: 0x34
    s32 mRace;  // offset: 0x38
    s32 mPersonality;  // offset: 0x3c
    s32 mSpeechFreq;  // offset: 0x40
    s32 mEyePresetNo;  // offset: 0x44
    s32 mNosePresetNo;  // offset: 0x48
    s32 mMouthPresetNo;  // offset: 0x4c
    s32 mEyebrowTexNo;  // offset: 0x50
    s32 mColorSkin;  // offset: 0x54
    s32 mColorHair;  // offset: 0x58
    s32 mColorBeard;  // offset: 0x5c
    s32 mColorEyebrow;  // offset: 0x60
    s32 mColorREye;  // offset: 0x64
    s32 mColorLEye;  // offset: 0x68
    s32 mColorMakeup;  // offset: 0x6c
    cEditValue mSokutoubu;  // offset: 0x70
    cEditValue mHitai;  // offset: 0x90
    cEditValue mMimijyouge;  // offset: 0xb0
    cEditValue mKannkaku;  // offset: 0xd0
    cEditValue mMabisasijyouge;  // offset: 0xf0
    cEditValue mHanakuchijyouge;  // offset: 0x110
    cEditValue mAgosakihaba;  // offset: 0x130
    cEditValue mAgozengo;  // offset: 0x150
    cEditValue mAgosakijyouge;  // offset: 0x170
    cEditValue mHitomiookisa;  // offset: 0x190
    cEditValue mMeookisa;  // offset: 0x1b0
    cEditValue mMekaiten;  // offset: 0x1d0
    cEditValue mMayukaiten;  // offset: 0x1f0
    cEditValue mMimiookisa;  // offset: 0x210
    cEditValue mMimimuki;  // offset: 0x230
    cEditValue mElfmimi;  // offset: 0x250
    cEditValue mMikentakasa;  // offset: 0x270
    cEditValue mMikenhaba;  // offset: 0x290
    cEditValue mHohoboneryou;  // offset: 0x2b0
    cEditValue mHohobonejyouge;  // offset: 0x2d0
    cEditValue mHohoniku;  // offset: 0x2f0
    cEditValue mErahonejyouge;  // offset: 0x310
    cEditValue mErahonehaba;  // offset: 0x330
    cEditValue mHanajyouge;  // offset: 0x350
    cEditValue mHanahaba;  // offset: 0x370
    cEditValue mHanatakasa;  // offset: 0x390
    cEditValue mHanakakudo;  // offset: 0x3b0
    cEditValue mKuchihaba;  // offset: 0x3d0
    cEditValue mKuchiatsusa;  // offset: 0x3f0
    cEditValue mEyebrowUVOffsetX;  // offset: 0x410
    cEditValue mEyebrowUVOffsetY;  // offset: 0x430
    cEditValue mWrinkle;  // offset: 0x450
    cEditValue mWrinkleAlbedoBlendRate;  // offset: 0x470
    cEditValue mWrinkleDetailNormalPower;  // offset: 0x490
    cEditValue mMuscleAlbedoBlendRate;  // offset: 0x4b0
    cEditValue mMuscleDetailNormalPower;  // offset: 0x4d0
    cEditValue mHeight;  // offset: 0x4f0
    cEditValue mHeightScaleArmRateP;  // offset: 0x510
    cEditValue mHeightScaleArmRateM;  // offset: 0x530
    cEditValue mHeightScaleLegRateP;  // offset: 0x550
    cEditValue mHeightScaleLegRateM;  // offset: 0x570
    cEditValue mHeightScaleBodyRateP;  // offset: 0x590
    cEditValue mHeightScaleBodyRateM;  // offset: 0x5b0
    cEditValue mHeadSize;  // offset: 0x5d0
    cEditValue mHeadRateP;  // offset: 0x5f0
    cEditValue mHeadRateM;  // offset: 0x610
    cEditValue mNeckOffset;  // offset: 0x630
    cEditValue mNeckScale;  // offset: 0x650
    cEditValue mUpperBodyScaleX;  // offset: 0x670
    cEditValue mUpperBodyScaleZ;  // offset: 0x690
    cEditValue mBellySize;  // offset: 0x6b0
    cEditValue mTeatScale;  // offset: 0x6d0
    cEditValue mTekubiSize;  // offset: 0x6f0
    cEditValue mTekubiOffset;  // offset: 0x710
    cEditValue mArmScaleYZ;  // offset: 0x730
    cEditValue mKoshiOffset;  // offset: 0x750
    cEditValue mKoshiSize;  // offset: 0x770
    cEditValue mKoshiScale;  // offset: 0x790
    cEditValue mThighScale;  // offset: 0x7b0
    cEditValue mAnkleOffset;  // offset: 0x7d0
    cEditValue mFat;  // offset: 0x7f0
    cEditValue mMuscle;  // offset: 0x810
    cEditValue mMotionFilter;  // offset: 0x830
    static MyDTI DTI;
    static const u32 DATA_VERSION = 23;
    static const u32 RELEASE_VERSION = 0;
};

// Inline, no code of its own: checked where it is inlined.
inline cEditValue::cEditValue() {
    this->mDefault = 0.0f;
    this->mValue = 0.0f;
    this->mMin = -3.4028235e38f;
    this->mMax = 3.4028235e38f;
    this->mFlag = static_cast<u32>(0);
    this->mDiv = static_cast<s16>(200);
}
