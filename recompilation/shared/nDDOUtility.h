#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtString;
class MtVector3;
class MtVector4;

// Declarations
namespace nDDOUtility { template <typename T, unsigned int N> class cArray; }
namespace nDDOUtility { template <unsigned int BIT_NUM> class cBitSet; }
namespace nDDOUtility { template <typename T, typename UI> class cKeyFrameValue; }
namespace nDDOUtility { template <typename T> class cNoObjectArray; }
namespace nDDOUtility { template <unsigned int NODE> class cRNSpline; }
namespace nDDOUtility { template <typename T> class cScopedPtr; }
namespace nDDOUtility { class cRNSplineBase; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using size_type = u32;
using u8 = unsigned char;

namespace nDDOUtility {

    // Forward declarations
    class cRNSplineBase;

    class cRNSplineBase
    {
    public:
        struct stSplineData;
    public:
        struct stSplineData
        {
        public:
            MtVector3 position;  // offset: 0x0
            MtVector3 velocity;  // offset: 0x10
            f32 distance;  // offset: 0x20
        };
    public:
        cRNSplineBase();
        virtual ~cRNSplineBase();
        void init();
        virtual void addNode(const MtVector3& pos);  // vtable slot 2
        void buildSpline();
        MtVector3 getPosition(f32 time);
        f32 getMaxDistance() const;
        f32 getNodeCount() const;
    protected:
        MtVector3 getStartVelocity(s32 index);
        MtVector3 getEndVelocity(s32 index);
    public:
        virtual stSplineData* getNodePtr() = 0;  // vtable slot 3
    private:
        f32 mMaxDistance;  // offset: 0x8
        s32 mMaxNodeNum;  // offset: 0xc
        s32 mNodeCount;  // offset: 0x10
    };

    void setFileName(const MtString& src, MT_CHAR* dst);
    void setFileName(const MtString& src, MtString& dst);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOUtility.cpp:72
    void requestOnTutorialFlg(s32 questTarget);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOUtility.cpp:213
    void arraySuffle(MtArray& dst, s32 begin, s32 end);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOUtility.cpp:232
    void getParentDirName(MT_CTSTR filePath, MT_CHAR* dirPath);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nDDOUtility.cpp:262
    template <typename T> void arrayCopy(MtTypedArray<T>& dst, const MtTypedArray<T>& src);

}  // namespace nDDOUtility

namespace nDDOUtility {
    // Layout verified against DWARF for cArray<CDataNamedEnemyParamClient, 5>, cArray<char, 13>, cArray<MtObject*, 4>, cArray<MtString, 3>, cArray<MtStringEx<32>, 20>, cArray<MtStringEx<64>, 2>, cArray<MtVector3, 10>, cArray<MtVector3, 2>, cArray<MtVector3, 3>, cArray<MtVector3, 4>, cArray<MtVector4, 6>, cArray<cShotReqInfo2::stShotReq2Param, 3>, cArray<bool, 31>, cArray<bool, 32>, cArray<bool, 8>, cArray<cAIGrid, 2>, cArray<cArcLoader<16>*, 2048>, cArray<cArcLoader<16>, 2048>, cArray<cArcLoaderBase*, 256>, cArray<cCharacterData::SCM::stSCCPlt, 8>, cArray<cCharacterData::SCM::stSCMPlt, 4>, cArray<cCharacterData::stCardPawnRental, 20>, cArray<cCharacterData::stCardPawnValue, 3>, cArray<cCharacterData::stPawnData::Ability, 10>, cArray<cContextPlayerInfo::cAbility, 10>, cArray<cCorePointReqestInfo, 8>, cArray<cCyclePartReqInfo, 6>, cArray<cErosionRegion, 4>, cArray<cGUIInstAnimation*, 2>, cArray<cGUIInstAnimation*, 3>, cArray<cGUIInstAnimation*, 4>, cArray<cGUIInstNull*, 2>, cArray<cGUIObjMessage*, 1>, cArray<cGUIObjMessage*, 2>, cArray<cGUIObjMessage*, 4>, cArray<cGUIObjNull*, 3>, cArray<cGUIObjPolygon*, 9>, cArray<cGUIObjTexture*, 3>, cArray<cGUIObjTexture*, 6>, cArray<cGeneralPoint*, 2048>, cArray<cGeneralPointPtr*, 6144>, cArray<cGeneralPointPtr, 32>, cArray<cGeneralPointPtr, 3>, cArray<cGeneralPointPtr, 4>, cArray<MtTypedArray<nGUIItem::cItem>, 1>, cArray<MtTypedArray<nGUIItem::cItem>, 7>, cArray<cObjHitCache, 1024>, cArray<nDDOUtility::cArray<cObjHitCache, 1024>, 6>, cArray<nDDOUtility::cArray<nObjCondition::stOcdActiveData, 32>, 7>, cArray<nDDOUtility::cArray<bool, 32>, 7>, cArray<cOcdCache, 3>, cArray<MtStringEx<256>, 9>, cArray<nDDOUtility::cArray<nHuman::HM_SKILL_LV, 20>, 10>, cArray<nDDOUtility::cArray<nHuman::HM_SKILL_LV, 10>, 10>, cArray<cStaminaCtrl::stOverRideParam, 16>, cArray<cTentacleInfo, 4>, cArray<MtTypedArray<cWeatherScriptCmd>, 4>, cArray<MtTypedArray<cWeatherScriptCmdCtrl>, 4>, cArray<cZoneMultiListener::stStack, 16>, cArray<cZoneMultiListener::stStack, 48>, cArray<cZoneUnitCtrl::unZoneGroup, 8>, cArray<cEfcHandle*, 32>, cArray<cHitNode*, 256>, cArray<sEffectExt::cZoneEffectUnit*, 256>, cArray<cpJobBase*, 10>, cArray<rAttackParam*, 4>, cArray<rBowActParamList*, 2>, cArray<rMotionList*, 4>, cArray<rMotionParam*, 4>, cArray<rObjCollision*, 4>, cArray<rSoundRequest*, 4>, cArray<const nHumanBow::cBowActParam*, 2>, cArray<const nHumanBow::cBowActParam*, 4>, cArray<cpHumanWarpCtrl::stHumanWarpInfo, 1>, cArray<cpInput::KEY_CMD_DEF, 16>, cArray<cpJob02::cPullUpInfo::info, 3>, cArray<float, 17>, cArray<float, 3>, cArray<float, 4>, cArray<float, 5>, cArray<float, 7>, cArray<float, 8>, cArray<nHuman::CUSTOM_SKILL_ENUM, 2>, cArray<nHuman::HM_SKILL_LV, 10>, cArray<nHuman::HM_SKILL_LV, 20>, cArray<nHuman::stShellRequestInfo, 8>, cArray<nJobParam::cJobInfo, 10>, cArray<nKeyCommand::stKeyCommand*, 4>, cArray<nKeyCommand::stKeyCommandForFunction*, 8>, cArray<nKeyCustom::KB_CUSTOM, 4>, cArray<nObjCondition::stHolyAbsorpReqInfo, 8>, cArray<nObjCondition::stOcdActiveData, 32>, cArray<res_ptr<rArchiveListArray>, 128>, cArray<rGUIMessage*, 4>, cArray<rJobLevelUpTbl2*, 10>, cArray<rJumpParamTbl*, 2>, cArray<rOcdStatusParamRes*, 4>, cArray<rStaminaDecTbl*, 2>, cArray<int, 2>, cArray<int, 32>, cArray<int, 8>, cArray<sAIPawnTalkMgr::cAIPawnTalkInfo, 16>, cArray<sAIPawnTalkMgr::cAIPawnTalkWaitNode, 32>, cArray<sGUIExt::cJpegDecode::cDecodeSet, 16>, cArray<sGUIExt::cLifeGaugeWork, 8>, cArray<sGUIExt::stGatheringData, 4>, cArray<sSetManager::cOmGroupData, 512>, cArray<nDDOUtility::cArray<cCharacterData::SCM::stSCCPlt, 8>, 3>, cArray<nDDOUtility::cArray<cCharacterData::SCM::stSCMPlt, 4>, 3>, cArray<unsigned short, 10>, cArray<unsigned short, 44>, cArray<unsigned short, 6>, cArray<unsigned int, 16>, cArray<unsigned int, 3>, cArray<unsigned int, 4>, cArray<unsigned int, 5>, cArray<unsigned int, 64>, cArray<unsigned int, 8>, cArray<unsigned int, 9>, cArray<uCameraGame::stReqHistory, 20>, cArray<uDDOModel::stTouchReleaseInfo, 8>, cArray<uEnemy::stEnchantInfo, 16>, cArray<uGUIAim::cTargetMarker, 16>, cArray<uGUIBase::cReferenceUIBtnGuide::stGuideBtnData, 1>, cArray<uGUIBase::cReferenceUIButton, 2>, cArray<uGUIBase::cReferenceUIButton, 4>, cArray<uGUIBase::cReferenceUIIconStatus, 2>, cArray<uGUIChat::cLogInfo*, 300>, cArray<uGUIChat::cLogInfo, 300>, cArray<uGUIChat::cLogItem, 29>, cArray<uGUIGauge::Aura*, 6>, cArray<uGUIGauge::Aura, 2>, cArray<uGUIGauge::GaugePtr, 8>, cArray<uGUIGauge::StockGauge, 7>, cArray<uGUIGaugeEnemy::StatusInfo, 2>, cArray<uGUIGaugeEnemy::TargetIcon, 2>, cArray<uGUIGaugeNpc::StatusInfo, 2>, cArray<uGUIKeyConfig::KeyHistory, 3>, cArray<uGUIKeyConfig::KeyHistoryParam, 1>, cArray<uGUIKeyConfig::cCategoryItem, 22>, cArray<uGUIKeyConfig::cKeySettingItem, 12>, cArray<uGUIMyRoom::cList::cItem, 9>, cArray<uGUIMyRoomPopup::cList::cItem, 8>, cArray<uGUIPopTopSel::CLAN_MENU_ID, 12>, cArray<uGUIPopTopSel::stNumberIcon, 2>, cArray<uGUISystemMsg::stReserveSE, 50>, cArray<uGUIUseItemBase::stPopup, 4>, cArray<uHuman::cLimitActCtrl::stInfo, 16>, cArray<uHuman::cReqIKInfo, 5>, cArray<uHuman::stEnchantInfo, 16>
    template <typename T, unsigned int N>
    class cArray
    {
    public:
        using reference = T&;
        using const_reference = const T&;
        using value_type = T;
    public:
        reference operator[](size_type i);
        const_reference operator[](size_type i) const;
        static size_type size();
        void fill(const T& value);
        void copy(const nDDOUtility::cArray<T, N>& other);
        value_type* data();
    public:
        T elems[N];  // offset: 0x0
    };
}  // namespace nDDOUtility

namespace nDDOUtility {
    template <>
    class cBitSet<10>
    {
    public:
        enum
        {
            AR_NUM = 1,
        };
    public:
        cBitSet();
        ~cBitSet();
        bool check(u32 bit) const;
        bool checkOr(const nDDOUtility::cBitSet<10>& src) const;
        bool checkAnd(const nDDOUtility::cBitSet<10>& src) const;
        bool checkNone() const;
        void set(u32 bit);
        void clear();
        static u32 getArrayNum();
        u32* toArrayPtr();
    private:
        u32 mBit[1];  // offset: 0x0
    };
}  // namespace nDDOUtility

namespace nDDOUtility {
    template <>
    class cBitSet<11>
    {
    public:
        enum
        {
            AR_NUM = 1,
        };
    public:
        cBitSet();
        ~cBitSet();
        nDDOUtility::cBitSet<11>& operator=(const nDDOUtility::cBitSet<11>& r);
        bool check(u32 bit) const;
        static u32 getArrayNum();
        u32 getArrayData(u32 index) const;
        u32* toArrayPtr();
    private:
        u32 mBit[1];  // offset: 0x0
    };
}  // namespace nDDOUtility

namespace nDDOUtility {
    template <>
    class cBitSet<128>
    {
    public:
        enum
        {
            AR_NUM = 4,
        };
    public:
        cBitSet();
        cBitSet(u32 val0);
        ~cBitSet();
        nDDOUtility::cBitSet<128>& operator=(const nDDOUtility::cBitSet<128>& r);
        bool check(u32 bit) const;
        bool checkOr(const nDDOUtility::cBitSet<128>& src) const;
        bool checkOr(u32 no0, u32 no1) const;
        bool checkOr(u32 no0, u32 no1, u32 no2) const;
        bool checkAnd(const nDDOUtility::cBitSet<128>& src) const;
        bool checkNone() const;
        void set(u32 bit);
        void set(const nDDOUtility::cBitSet<128>& src);
        void off(u32 bit);
        void andEq(const nDDOUtility::cBitSet<128>& src);
        void onoff(u32 bit, bool on);
        void clear();
        static u32 getArrayNum();
        u32 getArrayData(u32 index) const;
        u32* toArrayPtr();
    private:
        u32 mBit[4];  // offset: 0x0
    };
}  // namespace nDDOUtility

namespace nDDOUtility {
    template <>
    class cBitSet<14>
    {
    public:
        enum
        {
            AR_NUM = 1,
        };
    public:
        cBitSet();
        ~cBitSet();
        nDDOUtility::cBitSet<14>& operator=(const nDDOUtility::cBitSet<14>& r);
        bool check(u32 bit) const;
        bool checkOr(u32 no0, u32 no1) const;
        void set(u32 bit);
        void clear();
        static u32 getArrayNum();
        u32 getArrayData(u32 index) const;
        u32* toArrayPtr();
    private:
        u32 mBit[1];  // offset: 0x0
    };
}  // namespace nDDOUtility

namespace nDDOUtility {
    template <>
    class cBitSet<1664>
    {
    public:
        enum
        {
            AR_NUM = 52,
        };
    public:
        cBitSet();
        ~cBitSet();
        bool check(u32 bit) const;
        void set(u32 bit);
        void off(u32 bit);
        void clear();
    private:
        u32 mBit[52];  // offset: 0x0
    };
}  // namespace nDDOUtility

namespace nDDOUtility {
    template <>
    class cBitSet<16>
    {
    public:
        enum
        {
            AR_NUM = 1,
        };
    public:
        cBitSet();
        ~cBitSet();
        bool check(u32 bit) const;
        void set(u32 bit);
        void off(u32 bit);
        void clear();
    private:
        u32 mBit[1];  // offset: 0x0
    };
}  // namespace nDDOUtility

namespace nDDOUtility {
    template <>
    class cBitSet<17>
    {
    public:
        enum
        {
            AR_NUM = 1,
        };
    public:
        cBitSet();
        ~cBitSet();
        bool check(u32 bit) const;
        void set(u32 bit);
        void off(u32 bit);
        void onoff(u32 bit, bool on);
        void clear();
    private:
        u32 mBit[1];  // offset: 0x0
    };
}  // namespace nDDOUtility

namespace nDDOUtility {
    template <>
    class cBitSet<1>
    {
    public:
        cBitSet();
        ~cBitSet();
        bool check(u32 bit) const;
        void set(u32 bit);
        void off(u32 bit);
        void onoff(u32 bit, bool on);
    private:
        u32 mBit[1];  // offset: 0x0
    };
}  // namespace nDDOUtility

namespace nDDOUtility {
    template <>
    class cBitSet<22>
    {
    public:
        enum
        {
            AR_NUM = 1,
        };
    public:
        cBitSet();
        ~cBitSet();
        nDDOUtility::cBitSet<22>& operator=(const nDDOUtility::cBitSet<22>& r);
        bool check(u32 bit) const;
        void clear(u8 val);
        static u32 getArrayNum();
        u32 getArrayData(u32 index) const;
        u32* toArrayPtr();
    private:
        u32 mBit[1];  // offset: 0x0
    };
}  // namespace nDDOUtility

namespace nDDOUtility {
    template <>
    class cBitSet<256>
    {
    public:
        enum
        {
            AR_NUM = 8,
        };
    public:
        cBitSet();
        ~cBitSet();
        bool check(u32 bit) const;
        bool checkNone() const;
        void set(u32 bit);
        void off(u32 bit);
        void clear();
        static u32 getArrayNum();
        u32* toArrayPtr();
    private:
        u32 mBit[8];  // offset: 0x0
    };
}  // namespace nDDOUtility

namespace nDDOUtility {
    template <>
    class cBitSet<2>
    {
    public:
        enum
        {
            AR_NUM = 1,
        };
    public:
        cBitSet();
        ~cBitSet();
        nDDOUtility::cBitSet<2>& operator=(const nDDOUtility::cBitSet<2>& r);
        bool check(u32 bit) const;
        void set(u32 bit);
        void clear();
        static u32 getArrayNum();
        u32 getArrayData(u32 index) const;
        u32* toArrayPtr();
    private:
        u32 mBit[1];  // offset: 0x0
    };
}  // namespace nDDOUtility

namespace nDDOUtility {
    template <>
    class cBitSet<32>
    {
    public:
        enum
        {
            AR_NUM = 1,
        };
    public:
        cBitSet();
        ~cBitSet();
        nDDOUtility::cBitSet<32>& operator=(const nDDOUtility::cBitSet<32>& r);
        bool check(u32 bit) const;
        void set(u32 bit);
        void set(u32, u32);
        void set(u32, u32, u32);
        void off(u32 bit);
        void andEq(const nDDOUtility::cBitSet<32>& src);
        bool eq(const nDDOUtility::cBitSet<32>&);
        void onoff(u32 bit, bool on);
        void clear();
        void clear(u8 val);
        u32 searchEmpty() const;
        static u32 getArrayNum();
        u32 getArrayData(u32 index) const;
        u32* toArrayPtr();
    private:
        u32 mBit[1];  // offset: 0x0
    };
}  // namespace nDDOUtility

namespace nDDOUtility {
    template <>
    class cBitSet<33>
    {
    public:
        enum
        {
            AR_NUM = 2,
        };
    public:
        cBitSet();
        ~cBitSet();
        bool check(u32 bit) const;
        static u32 getArrayNum();
        u32* toArrayPtr();
    private:
        u32 mBit[2];  // offset: 0x0
    };
}  // namespace nDDOUtility

namespace nDDOUtility {
    template <>
    class cBitSet<3>
    {
    public:
        enum
        {
            AR_NUM = 1,
        };
    public:
        cBitSet();
        cBitSet(u32 val0);
        ~cBitSet();
        nDDOUtility::cBitSet<3>& operator=(const nDDOUtility::cBitSet<3>& r);
        bool check(u32 bit) const;
        void set(u32 bit);
        void off(u32 bit);
        void onoff(u32 bit, bool on);
        void clear();
        static u32 getArrayNum();
        u32 getArrayData(u32 index) const;
        u32* toArrayPtr();
    private:
        u32 mBit[1];  // offset: 0x0
    };
}  // namespace nDDOUtility

namespace nDDOUtility {
    template <>
    class cBitSet<4096>
    {
    public:
        enum
        {
            AR_NUM = 128,
        };
    public:
        cBitSet();
        ~cBitSet();
        bool check(u32) const;
        void set(u32 bit);
        void off(u32 bit);
        void clear();
    private:
        u32 mBit[128];  // offset: 0x0
    };
}  // namespace nDDOUtility

namespace nDDOUtility {
    template <>
    class cBitSet<46>
    {
    public:
        enum
        {
            AR_NUM = 2,
        };
    public:
        cBitSet();
        ~cBitSet();
        bool check(u32 bit) const;
        void set(u32 bit);
        void off(u32 bit);
        void clear();
    private:
        u32 mBit[2];  // offset: 0x0
    };
}  // namespace nDDOUtility

namespace nDDOUtility {
    template <>
    class cBitSet<4>
    {
    public:
        enum
        {
            AR_NUM = 1,
        };
    public:
        cBitSet();
        ~cBitSet();
        nDDOUtility::cBitSet<4>& operator=(const nDDOUtility::cBitSet<4>& r);
        bool check(u32 bit) const;
        void set(u32 bit);
        void off(u32 bit);
        void onoff(u32 bit, bool on);
        void clear();
        static u32 getArrayNum();
        u32 getArrayData(u32 index) const;
        u32* toArrayPtr();
    private:
        u32 mBit[1];  // offset: 0x0
    };
}  // namespace nDDOUtility

namespace nDDOUtility {
    template <>
    class cBitSet<512>
    {
    public:
        enum
        {
            AR_NUM = 16,
        };
    public:
        cBitSet();
        ~cBitSet();
        bool check(u32 bit) const;
        void set(u32 bit);
        void off(u32 bit);
        void clear();
    private:
        u32 mBit[16];  // offset: 0x0
    };
}  // namespace nDDOUtility

namespace nDDOUtility {
    template <>
    class cBitSet<59>
    {
    public:
        enum
        {
            AR_NUM = 2,
        };
    public:
        cBitSet();
        ~cBitSet();
        bool check(u32 bit) const;
        void set(u32 bit);
        void clear();
    private:
        u32 mBit[2];  // offset: 0x0
    };
}  // namespace nDDOUtility

namespace nDDOUtility {
    template <>
    class cBitSet<5>
    {
    public:
        enum
        {
            AR_NUM = 1,
        };
    public:
        cBitSet();
        ~cBitSet();
        bool check(u32 bit) const;
        void set(u32 bit);
        void off(u32 bit);
        void clear();
        u32 calcBitNum32(u32 Flag) const;
        u32 calcBitNum() const;
    private:
        u32 mBit[1];  // offset: 0x0
    };
}  // namespace nDDOUtility

namespace nDDOUtility {
    template <>
    class cBitSet<64>
    {
    public:
        enum
        {
            AR_NUM = 2,
        };
    public:
        cBitSet();
        cBitSet(u32 val0);
        ~cBitSet();
        bool check(u32 bit) const;
        bool checkNone() const;
        void set(u32 bit);
        void off(u32 bit);
        void onoff(u32 bit, bool on);
        void clear();
        static u32 getArrayNum();
        u32 getArrayData(u32 index) const;
        u32* toArrayPtr();
    private:
        u32 mBit[2];  // offset: 0x0
    };
}  // namespace nDDOUtility

namespace nDDOUtility {
    template <>
    class cBitSet<6>
    {
    public:
        enum
        {
            AR_NUM = 1,
        };
    public:
        cBitSet();
        ~cBitSet();
        bool check(u32 bit) const;
        bool checkOr(const nDDOUtility::cBitSet<6>& src) const;
        void set(u32 bit);
        void off(u32 bit);
        void onoff(u32 bit, bool on);
        void clear();
        static u32 getArrayNum();
        u32* toArrayPtr();
    private:
        u32 mBit[1];  // offset: 0x0
    };
}  // namespace nDDOUtility

namespace nDDOUtility {
    template <>
    class cBitSet<7>
    {
    public:
        cBitSet();
        ~cBitSet();
        bool check(u32 bit) const;
        void set(u32 bit);
    private:
        u32 mBit[1];  // offset: 0x0
    };
}  // namespace nDDOUtility

namespace nDDOUtility {
    template <>
    class cBitSet<8>
    {
    public:
        enum
        {
            AR_NUM = 1,
        };
    public:
        cBitSet();
        ~cBitSet();
        nDDOUtility::cBitSet<8>& operator=(const nDDOUtility::cBitSet<8>& r);
        bool check(u32 bit) const;
        void set(u32 bit);
        void off(u32 bit);
        bool eq(const nDDOUtility::cBitSet<8>& src);
        void onoff(u32 bit, bool on);
        void clear();
        u32 getArrayData(u32 index) const;
        u32 calcBitNum32(u32 Flag) const;
        u32 calcBitNum() const;
    private:
        u32 mBit[1];  // offset: 0x0
    };
}  // namespace nDDOUtility

namespace nDDOUtility {
    template <>
    class cKeyFrameValue<MtVector4, MtObject> : public ::MtObject
    {
    public:
        class MyDTI;
        struct stKeyValue;
    public:
        using value_type = MtVector4;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        struct stKeyValue
        {
        public:
            stKeyValue();
        public:
            f32 key;  // offset: 0x0
            nDDOUtility::cKeyFrameValue<MtVector4, MtObject>::value_type value;  // offset: 0x10
        };
    public:
        static void usage();
        virtual const MtDTI& getDTI() const;  // vtable slot 5
        static MtAllocator* getAllocator();
        static void* operator new(size_t sz, u32 align);
        static void* operator new[](size_t sz, u32 align);
        static void* operator new(size_t sz, void* p_addr);
        static void* operator new[](size_t sz, void* p_addr);
        static void operator delete(void* p_addr);
        static void operator delete[](void* p_addr);
        static void operator delete(void* p_addr, u32 align);
        static void operator delete[](void* p_addr, u32 align);
        cKeyFrameValue();
        virtual ~cKeyFrameValue();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        const nDDOUtility::cKeyFrameValue<MtVector4, MtObject>& operator=(const nDDOUtility::cKeyFrameValue<MtVector4, MtObject>& r);
        value_type getValue(f32 key) const;
    public:
        u32 keyNum;  // offset: 0x8
        stKeyValue value[8];  // offset: 0x10
        static MyDTI DTI;
        static const u32 MAX_KEY_NUM = 8;
    };
}  // namespace nDDOUtility

namespace nDDOUtility {
    template <>
    class cKeyFrameValue<float, MtObject> : public ::MtObject
    {
    public:
        class MyDTI;
        struct stKeyValue;
    public:
        using value_type = float;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        struct stKeyValue
        {
        public:
            stKeyValue();
        public:
            f32 key;  // offset: 0x0
            nDDOUtility::cKeyFrameValue<f32, MtObject>::value_type value;  // offset: 0x4
        };
    public:
        static void usage();
        virtual const MtDTI& getDTI() const;  // vtable slot 5
        static MtAllocator* getAllocator();
        static void* operator new(size_t sz, u32 align);
        static void* operator new[](size_t sz, u32 align);
        static void* operator new(size_t sz, void* p_addr);
        static void* operator new[](size_t sz, void* p_addr);
        static void operator delete(void* p_addr);
        static void operator delete[](void* p_addr);
        static void operator delete(void* p_addr, u32 align);
        static void operator delete[](void* p_addr, u32 align);
        cKeyFrameValue();
        virtual ~cKeyFrameValue();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        const nDDOUtility::cKeyFrameValue<float, MtObject>& operator=(const nDDOUtility::cKeyFrameValue<float, MtObject>& r);
        nDDOUtility::cKeyFrameValue<f32, MtObject>::value_type getValue(f32 key) const;
    public:
        u32 keyNum;  // offset: 0x8
        nDDOUtility::cKeyFrameValue<f32, MtObject>::stKeyValue value[8];  // offset: 0xc
        static nDDOUtility::cKeyFrameValue<f32, MtObject>::MyDTI DTI;
        static const u32 MAX_KEY_NUM = 8;
    };
}  // namespace nDDOUtility

namespace nDDOUtility {
    template <typename T>
    class cNoObjectArray
    {
    public:
        cNoObjectArray();
        virtual ~cNoObjectArray();
        void setAutoDelete(bool f);
        bool isAutoDelete() const;
        void add(T* pobj);
        T* & operator[](u32 index);
        u32 length() const;
        void clear(bool buffree);
        void deleteAll(bool buffree);
        void erase(u32 index);
        static MtAllocator* getAllocator();
        static void operator delete(void* padr);
    private:
        void extendBuffer(u32 siz);
    private:
        u32 mLength;  // offset: 0x8
        u32 mBufsiz;  // offset: 0xc
        bool mAutoDelete;  // offset: 0x10
        T* * mpArray;  // offset: 0x18
    };
}  // namespace nDDOUtility

namespace nDDOUtility {
    // Layout verified against DWARF for cRNSpline<8>
    template <unsigned int NODE>
    class cRNSpline : public nDDOUtility::cRNSplineBase
    {
    public:
        cRNSpline();
        virtual ~cRNSpline();
        virtual void addNode(const MtVector3& pos);  // vtable slot 2
        virtual nDDOUtility::cRNSplineBase::stSplineData* getNodePtr();  // vtable slot 3
    private:
        nDDOUtility::cRNSplineBase::stSplineData mNode[8];  // offset: 0x20
    };
}  // namespace nDDOUtility

namespace nDDOUtility {
    template <typename T>
    class cScopedPtr
    {
    public:
        cScopedPtr();
        ~cScopedPtr();
        void set(T* p);
        void clear();
        T* operator=(T* p);
        T* get();
    public:
        T* mpInst;  // offset: 0x0
    };
}  // namespace nDDOUtility

// Included after the classes: the generic bodies below need these complete.
#include "MtAllocator.h"
#include "MtMemoryAllocator.h"

// Generic (024 T808): every instance that renders gives this body; the unit of each instance's compile unit, else nDDOUtility.cpp, instantiates it for the body oracle.
// approximate: the family's one template definition, for an instance the renderer refused (constitution 2.4.0); its verdict is reported
template <typename T>
nDDOUtility::cNoObjectArray<T>::~cNoObjectArray() {
    if (this->mAutoDelete != false) {
        if (this->mLength != static_cast<u32>(0)) {
            // inferred: the value the loop at 0x1adec10 carries; no location-less local in scope fits
            u32 v0_0 = this->mLength;
            // inferred: the counter this loop steps; no location-less local in scope fits
            for (unsigned int i0_3 = static_cast<unsigned int>(0);;) {
                if (this->mpArray[i0_3] != static_cast<T*>(nullptr)) {
                    delete this->mpArray[i0_3];
                    if ((i0_3 + static_cast<unsigned int>(1)) < this->mLength) {
                        v0_0 = this->mLength;
                        i0_3 += static_cast<unsigned int>(1);
                    } else {
                        break;
                    }
                } else {
                    if ((i0_3 + static_cast<unsigned int>(1)) < v0_0) {
                        i0_3 += static_cast<unsigned int>(1);
                    } else {
                        break;
                    }
                }
            }
        }
        if (this->mpArray != static_cast<T* *>(nullptr)) {
            ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(this->mpArray));
        }
        this->mpArray = static_cast<T* *>(nullptr);
        this->mLength = static_cast<u32>(0);
        this->mBufsiz = static_cast<u32>(0);
    } else {
        if (this->mpArray != static_cast<T* *>(nullptr)) {
            ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(this->mpArray));
        }
    }
    this->mpArray = static_cast<T* *>(nullptr);
    this->mLength = static_cast<u32>(0);
    this->mBufsiz = static_cast<u32>(0);
}

// Generic (024 T808): every instance that renders gives this body; the unit of each instance's compile unit, else nDDOUtility.cpp, instantiates it for the body oracle.
template <unsigned int NODE>
nDDOUtility::cRNSplineBase::stSplineData* nDDOUtility::cRNSpline<NODE>::getNodePtr() {
    return &this->mNode[0];
}

// Generic (024 T808): every instance that renders gives this body; the unit of each instance's compile unit, else nDDOUtility.cpp, instantiates it for the body oracle.
template <unsigned int NODE>
nDDOUtility::cRNSpline<NODE>::~cRNSpline() {
}

// Generic (024 T863c): every instance's inlined copies give this body; no code of its own, checked where it is inlined (rendered.json inline_proofs).
template <typename T>
inline nDDOUtility::cScopedPtr<T>::cScopedPtr() {
    this->mpInst = static_cast<T*>(nullptr);
}
