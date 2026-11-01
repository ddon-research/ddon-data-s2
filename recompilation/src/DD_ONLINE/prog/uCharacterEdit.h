#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "Protocol/PacketData/Character.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "cCharacterData.h"
#include "cEditChargeInfoUpdator.h"
#include "cStageEpvCtrl.h"
#include "../../XFramework/cUnit.h"
#include "nCharacterData.h"
#include "nCharacterEdit.h"
#include "nDDOUtility.h"
#include "nGUIExt.h"
#include "../../generated/shared/nHuman.h"
#include "nNet.h"
#include "../../XFramework/uFreeCamera.h"
#include "uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtString;
class MtUI;
class MtVector3;
class cArcLoaderBase;
class cCharacterData;
class cCharacterEditCameraParam;
class cEditChargeInfoUpdator;
class cEditParam;
class cEditValue;
class cEfcHandle;
class cResource;
class cStageEpvCtrl;
class cStorageDataEdit;
class cpCharacterEdit;
namespace nCharacterData { struct stCharacterName; }
namespace nCharacterData { struct stEquipData; }
namespace nCharacterEdit { class cPaletteParams; }
namespace nCharacterEdit { struct stEquipIconCash; }
namespace nCharacterEdit { struct stStageIconCash; }
class rCharacterEdit;
class rCharacterEditCameraParam;
class rEditStageParam;
class rEffectProvider;
class rEquipPresetPalette;
class rGUIMessage;
class rSndPitchLimit;
class rSoundRequest;
class rWeatherParamInfoTbl;
class rWeatherStageInfo;
class uEditSaveLoadFlow;
class uGUICharacterEdit;
class uGUICharacterEditPopCard;
class uGUIGPShop;
class uGUIJobSelect;
class uGUISystemMsg;
class uMockUpModel;
class uScheduler;

// Declarations
class cEditParamList;
class cUndoData;
class uCharacterEdit;
class uCharacterEditBase;
class uCharacterEditCamera;
class uCharacterEditCameraBase;

// Type aliases from DWARF
using CHAR_NAME = nCharacterData::stCharacterName;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using TICKET = cArcLoaderBase*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using __uintptr_t = __uint64_t;
using cCategoryParamListArray = nDDOUtility::cArray<MtTypedArray<cEditParamList>, 17>;
using cEditParamListArray = MtTypedArray<cEditParamList>;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;
using uintptr = __uintptr_t;

class cEditParamList : public MtObject
{
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
    cEditParamList();
public:
    s32 mEditType;  // offset: 0x8
    bool mIsChange;  // offset: 0xc
    static MyDTI DTI;
};

class cUndoData : public MtObject
{
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
    cUndoData();
    virtual ~cUndoData();
    void resetUndoData();
public:
    nCharacterEdit::EDIT_TYPE mEdit;  // offset: 0x8
    s32 mSaveValue;  // offset: 0xc
    s32 mNeedBodyPreset;  // offset: 0x10
    cEditParam* mpEditParam;  // offset: 0x18
    nCharacterEdit::BODY_TYPE mBodyType;  // offset: 0x20
    nDDOUtility::cArray<int, 32> mVoicePitches;  // offset: 0x24
    static MyDTI DTI;
};

class uCharacterEditBase : public cUnit
{
    friend class uGUICharacterEdit;
public:
    enum MODE
    {
        MODE_LOAD_ARC = 0,
        MODE_LOAD_UNIT = 1,
        MODE_MAIN = 2,
        MODE_END = 3,
    };
    enum EXIT_TYPE
    {
        EXIT_TYPE_NONE = 0,
        EXIT_TYPE_SUCCESS = 1,
        EXIT_TYPE_CANCEL = 2,
    };
    enum MOT_FACE
    {
        MOT_FACE_MABATAKI = 100,
        MOT_FACE_YOROKOBI = 101,
        MOT_FACE_IKARI = 102,
        MOT_FACE_ODOROKI = 103,
        MOT_FACE_TALK = 104,
        MOT_FACE_MAX = 105,
        MOT_FACE_START = 101,
    };
    enum
    {
        LOAD_ARC_INIT = 0,
        LOAD_ARC_WAIT = 1,
        LOAD_SCR_INIT = 2,
        LOAD_SCR_WAIT = 3,
        LOAD_ARC_END = 4,
    };
    enum
    {
        ARC_TAG_COMMON_EDIT_COMMON = 0,
        ARC_TAG_COMMON_NUM = 1,
    };
    enum
    {
        LOAD_UNIT_INIT = 0,
        LOAD_UNIT_MODEL = 1,
        LOAD_UNIT_END = 2,
    };
public:
    class MyDTI;
    struct stTemp;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stTemp
    {
    public:
        stTemp();
    public:
        s32 mVoice;  // offset: 0x0
        s32 mPersonal;  // offset: 0x4
        s32 mSpeechFreq;  // offset: 0x8
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
    uCharacterEditBase();
    virtual ~uCharacterEditBase();
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    virtual void release();  // vtable slot 24
    virtual bool moveLoadArc();  // vtable slot 25
    virtual void moveLoadUnit();  // vtable slot 26
    virtual void moveMain() {}  // vtable slot 27
    virtual void moveEnd() {}  // vtable slot 28
    void releaseScrScheduler();
    void setScrScheduler(s32 scr_idx, s32 time_idx);
    u32 getStageListNum();
    u32 getStageListNo(u32 idx);
    bool isStageChangeTime(u32 idx) const;
    void setAction(u32 ActNo, bool init);
    void setFaceAnime(s32 idx, bool force);
    MODE getMode();
    u32 getProc();
    bool isMale();
protected:
    virtual MT_CTSTR getSndPitchSearchName() const;  // vtable slot 29
    virtual void applyStageType() {}  // vtable slot 30
    virtual uCharacterEditCameraBase* createCamera() = 0;  // vtable slot 31
    void setMode(MODE mode);
    void setProc(s32 pr);
    bool isProcInit();
protected:
    MODE mMode;  // offset: 0x48
    MtVector3 mCamPosFar;  // offset: 0x50
    MtVector3 mCamPosNear;  // offset: 0x60
    f32 mCamPosRate;  // offset: 0x70
    f32 mCamRotX;  // offset: 0x74
    f32 mCamRotY;  // offset: 0x78
    f32 mCamRimitY;  // offset: 0x7c
    u32 mProc;  // offset: 0x80
    s32 mFrameTimer;  // offset: 0x84
    s32 mStageIdx;  // offset: 0x88
    s32 mNeedStageIdx;  // offset: 0x8c
    s32 mOldStageIdx;  // offset: 0x90
    u32 mTimeIdx;  // offset: 0x94
    u32 mNeedTimeIdx;  // offset: 0x98
    u32 mOldTimeIdx;  // offset: 0x9c
    s32 mActNo;  // offset: 0xa0
    s32 mActNoMax;  // offset: 0xa4
    const s32* mpActTable;  // offset: 0xa8
    nHuman::JOB_ENUM mJobNo;  // offset: 0xb0
    cEfcHandle* mpEffectHandle;  // offset: 0xb8
    s32 mVoiceReqNoOld;  // offset: 0xc0
    s32 mVoiceReqNo;  // offset: 0xc4
    uintptr mConThisId;  // offset: 0xc8
    u32 mCoordinateTagID;  // offset: 0xd0
    u32 mNeedCoordinateTagID;  // offset: 0xd4
    bool mIsCoordinateOriginal;  // offset: 0xd8
    bool mIsNeedCoordinateOriginal;  // offset: 0xd9
    s32 mBodyPreset;  // offset: 0xdc
    s32 mNeedBodyPreset;  // offset: 0xe0
    f32 mCameraLength;  // offset: 0xe4
    s32 mFaceAnimeNo;  // offset: 0xe8
    f32 mWait;  // offset: 0xec
    bool mIsEquipHead;  // offset: 0xf0
    bool mIsNeedEquipHead;  // offset: 0xf1
    EXIT_TYPE mExit;  // offset: 0xf4
    bool mIsEnd;  // offset: 0xf8
    bool mIsProcInit;  // offset: 0xf9
    bool mDisableCameraMove;  // offset: 0xfa
    bool mIsComplete;  // offset: 0xfb
    u32 mStageType;  // offset: 0xfc
    s32 mRno3;  // offset: 0x100
    cpCharacterEdit* mpCharacterEdit;  // offset: 0x108
    rEditStageParam* mpEditStageParam;  // offset: 0x110
    rCharacterEdit* mpEditRes;  // offset: 0x118
    rWeatherParamInfoTbl* mpWeatherParam;  // offset: 0x120
    rWeatherStageInfo* mpWeatherStage;  // offset: 0x128
    rEffectProvider* mpEffectProv;  // offset: 0x130
    rSoundRequest* mpSndReqEdit;  // offset: 0x138
    rSndPitchLimit* mpSndPitchLimit;  // offset: 0x140
    rGUIMessage* mpGmdDialog;  // offset: 0x148
    stTemp mTemp;  // offset: 0x150
    uCharacterEditCameraBase* mpCamera;  // offset: 0x160
    uMockUpModel* mpModel;  // offset: 0x168
    uScheduler* mpModelSchl;  // offset: 0x170
    uScheduler* mpFilterSchl;  // offset: 0x178
    uScheduler* mpLightSchl;  // offset: 0x180
    uScheduler* mpOmListSchl;  // offset: 0x188
    cStageEpvCtrl mStageEpvCtrl;  // offset: 0x190
    MtArray mStageList;  // offset: 0x240
    TICKET mArcTicketEditCommon;  // offset: 0x260
    TICKET mArcTicketStage;  // offset: 0x268
public:
    static MyDTI DTI;
    static const s32 ActListMale[];
    static const u32 ActListMaleNum;
    static const s32 ActListFemale[];
    static const u32 ActListFemaleNum;
    static const s32 DISABLE_IDX = -10;
};

class uCharacterEditCameraBase : public uFreeCamera
{
    friend class uCharacterEdit;
public:
    enum CAMERA_MOVE
    {
        CAMERA_MOVE_NONE = 0,
        CAMERA_MOVE_L = 1,
        CAMERA_MOVE_R = 2,
    };
    enum MODE
    {
        MODE_DEFAULT = 0,
        MODE_RESET = 1,
    };
public:
    class MyDTI;
    class cLimit;
    class cInterpolationVector3;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cLimit : public MtObject
    {
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
        cLimit();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        f32 length();
        bool load(MtDataReader& r);
        bool save(MtDataWriter& w);
        void set(f32 _max, f32 _min);
    public:
        f32 max;  // offset: 0x8
        f32 min;  // offset: 0xc
        static MyDTI DTI;
    };
public:
    class cInterpolationVector3
    {
    public:
        void set(const MtVector3& v, f32 speed);
        MtVector3 get();
        void setMinPower(f32);
        void setFixDelta(bool);
        void execute();
        f32 getPow();
    public:
        uGUIBase::cInterpolationValue mX;  // offset: 0x0
        uGUIBase::cInterpolationValue mY;  // offset: 0x28
        uGUIBase::cInterpolationValue mZ;  // offset: 0x50
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
    uCharacterEditCameraBase();
    virtual ~uCharacterEditCameraBase();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void setResetMode();  // vtable slot 27
    cCharacterEditCameraParam* getCameraParam(MT_CTSTR str);
    virtual void updateCameraParam();  // vtable slot 28
    void updateCameraData();
    void updateInterPos();
    void moveKey();
    void rotateModel();
    void reset();
    void isLimitCheck(f32& value, cLimit& limit);
    void setCameraRiviseSpeed(f32 f);
    void lockCameraMove();
    void clearLock();
    bool isLock() const;
    void addRotateRSY(f32 add_y);
protected:
    void convertCameraParam(f32& f);
    void initCameraParam();
protected:
    rCharacterEditCameraParam* mpCameraParam;  // offset: 0xe8
    cCharacterEditCameraParam* mpNowCameraParam;  // offset: 0xf0
    cCharacterEditCameraParam* mpOldCameraParam;  // offset: 0xf8
    f32 mLength;  // offset: 0x100
    uGUIBase::cInterpolationValue mInterLength;  // offset: 0x108
    MtVector3 mRotateRS;  // offset: 0x130
    MtVector3 mRotateLS;  // offset: 0x140
    bool mIsLSenableRotate;  // offset: 0x150
    f32 mZoomSpeed;  // offset: 0x154
    f32 mRotateSpeed;  // offset: 0x158
    cInterpolationVector3 mInterTargetPos;  // offset: 0x160
    cInterpolationVector3 mInterCameraPos;  // offset: 0x1d8
    f32 mAngle;  // offset: 0x250
    f32 mAngleAdd;  // offset: 0x254
    MtVector3 mResetAngle;  // offset: 0x260
    f32 mResetMaxSpeed;  // offset: 0x270
    CAMERA_MOVE mCameraMode;  // offset: 0x274
    s32 mWaitFrame;  // offset: 0x278
    uMockUpModel* mpModel;  // offset: 0x280
    uCharacterEditBase* mpEditUnit;  // offset: 0x288
    nDDOUtility::cArray<MtVector3, 2> mParamCameraPos;  // offset: 0x290
    nDDOUtility::cArray<MtVector3, 2> mParamTargetPos;  // offset: 0x2b0
    nDDOUtility::cArray<MtVector3, 2> mParamGlobalOffset;  // offset: 0x2d0
    f32 mCameraRiviseSpeed;  // offset: 0x2f0
    MODE mMode;  // offset: 0x2f4
    bool mIsLock;  // offset: 0x2f8
public:
    static MyDTI DTI;
};

class uCharacterEdit : public uCharacterEditBase
{
    friend class uGUICharacterEdit;
public:
    enum EDIT_LOAD_RNO
    {
        EDIT_LOAD_ARC_INIT = 0,
        EDIT_LOAD_ARC_WAIT = 1,
        EDIT_LOAD_ARC_END = 2,
    };
    enum CHARA_REGIST_ROUTINE
    {
        REGIST_ROUTINE_SETUP = 0,
        REGIST_ROUTINE_REQ_SV = 1,
        REGIST_ROUTINE_WAIT_SV = 2,
        REGIST_ROUTINE_CREATE_WAIT_REQ_SV = 3,
        REGIST_ROUTINE_CREATE_WAIT_WAIT_SV = 4,
        REGIST_ROUTINE_END_ANNOUNCE_REQ = 5,
        REGIST_ROUTINE_END_ANNOUNCE_WAIT = 6,
        REGIST_ROUTINE_PLAYER_SALON_REQ_SV = 7,
        REGIST_ROUTINE_PLAYER_SALON_WAIT_SV = 8,
        REGIST_ROUTINE_PAWN_SALON_REQ_SV = 9,
        REGIST_ROUTINE_PAWN_SALON_WAIT_SV = 10,
        REGIST_ROUTINE_ERROR_DIALOG = 11,
        REGIST_ROUTINE_END = 12,
    };
    enum GOLD_STONE_ROUTINE
    {
        GOLD_STONE_ROUTINE_SETUP = 0,
        GOLD_STONE_ROUTINE_DIALOG_WAIT = 1,
        GOLD_STONE_ROUTINE_CHECK = 2,
        GOLD_STONE_ROUTINE_SHORTAGE = 3,
        GOLD_STONE_ROUTINE_SHORTAGE_WAIT = 4,
        GOLD_STONE_ROUTINE_SHOP_INIT = 5,
        GOLD_STONE_ROUTINE_SHOP_WAIT = 6,
        GOLD_STONE_ROUTINE_EDIT_SAVE_SETUP = 7,
        GOLD_STONE_ROUTINE_EDIT_SAVE_MOVE = 8,
        GOLD_STONE_ROUTINE_END = 9,
    };
    enum EDIT_SAVE_LOAD_ROUTINE
    {
        EDIT_SAVE_LOAD_ROUTINE_INIT = 0,
        EDIT_SAVE_LOAD_ROUTINE_WAIT = 1,
        EDIT_SAVE_LOAD_ROUTINE_END = 2,
    };
    enum CHARA_REGIST_RESULT
    {
        REGIST_RESULT_NONE = 0,
        REGIST_RESULT_SUCCESS = 1,
        REGIST_RESULT_FAILED = 2,
        REGIST_RESULT_CANCEL = 3,
        REGIST_RESULT_ERROR = 4,
    };
    enum GOLD_STONE_RESULT
    {
        GOLD_STONE_RESULT_NONE = 0,
        GOLD_STONE_RESULT_SUCCESS = 1,
        GOLD_STONE_RESULT_FAILED = 2,
        GOLD_STONE_RESULT_CANCEL = 3,
        GOLD_STONE_RESULT_ERROR = 4,
    };
    enum CREATE_GUI
    {
        CREATE_GUI_EDIT = 0,
        CREATE_GUI_JOB = 1,
        CREATE_GUI_ARISEN_CARD = 2,
    };
    enum
    {
        MOVE_R3_MOVE = 0,
        MOVE_R3_WAIT_FADEOUT = 1,
        MOVE_R3_LOAD = 2,
        MOVE_R3_WAIT = 3,
        MOVE_R3_CHANGE = 4,
        MOVE_R3_WORLD_OFFSET = 5,
        MOVE_R3_SCR_END = 6,
        MOVE_R3_TIME = 7,
        MOVE_R3_TIME_END = 8,
        MOVE_R3_END = 9,
    };
    enum MOVE_MAIN
    {
        MOVE_MAIN_INIT = 0,
        MOVE_MAIN_CHAGE_INFO_INIT = 1,
        MOVE_MAIN_CHAGE_INFO_MOVE = 2,
        MOVE_MAIN_CHAGE_INFO_FINAL = 3,
        MOVE_MAIN_EDIT_PRICE_REQ = 4,
        MOVE_MAIN_EDIT_PRICE_WAIT = 5,
        MOVE_MAIN_EDIT_PRICE_ERROR = 6,
        MOVE_MAIN_SETUP = 7,
        MOVE_MAIN_SET_MODEL = 8,
        MOVE_MAIN_WAIT = 9,
        MOVE_MAIN_START_EFFECT = 10,
        MOVE_MAIN_INIT_EDIT_FIRST = 11,
        MOVE_MAIN_INIT_EDIT = 12,
        MOVE_MAIN_LOOP_EDIT = 13,
        MOVE_MAIN_CAMERA_MOVE1 = 14,
        MOVE_MAIN_INIT_JOB = 15,
        MOVE_MAIN_LOOP_JOB = 16,
        MOVE_MAIN_CAMERA_MOVE2 = 17,
        MOVE_MAIN_GOLD_STONE_SETUP = 18,
        MOVE_MAIN_GOLD_STONE = 19,
        MOVE_MAIN_CHAR_REGIST_SETUP = 20,
        MOVE_MAIN_CHAR_REGIST = 21,
        MOVE_MAIN_END_SUCCESS_EFFECT_INIT = 22,
        MOVE_MAIN_END_SUCCESS_EFFECT = 23,
        MOVE_MAIN_ARISEN_CARD = 24,
        MOVE_MAIN_END_INIT_FADE = 25,
        MOVE_MAIN_END_FADE_LOOP = 26,
        MOVE_MAIN_END = 27,
        MOVE_MAIN_ERROR = 28,
        MOVE_MAIN_CANCEL = 29,
    };
    enum GOLD_DIALOG_POS
    {
        GOLD_DIALOG_DECIDE = 0,
        GOLD_DIALOG_RETRY = 1,
        GOLD_DIALOG_SAVE = 2,
    };
public:
    class MyDTI;
    class cParlorParam;
    struct stStageEquipCash;
public:
    using cUndoFixedArray = nDDOUtility::cArray<cUndoData, 8>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cParlorParam
    {
    public:
        cParlorParam();
        virtual ~cParlorParam();
    public:
        nHuman::JOB_ENUM mJob;  // offset: 0x8
        nCharacterData::stEquipData mEquipData;  // offset: 0xc
        cEditParam* mpEditParam;  // offset: 0x838
    };
public:
    struct stStageEquipCash
    {
    public:
        stStageEquipCash();
    public:
        nDDOUtility::cArray<nCharacterEdit::stStageIconCash, 12> mStageIconCash;  // offset: 0x0
        nDDOUtility::cArray<nCharacterEdit::stEquipIconCash, 12> mEquipIconCash;  // offset: 0xc
        bool mIsSaved;  // offset: 0x18
        static const u8 STAGE_MAX = 12;
        static const u8 EQUIP_MAX = 12;
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
    uCharacterEdit();
    virtual ~uCharacterEdit();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void updatePtr();  // vtable slot 17
    virtual void release();  // vtable slot 24
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual bool moveLoadArc();  // vtable slot 25
    virtual void moveLoadUnit();  // vtable slot 26
    virtual void moveMain();  // vtable slot 27
    virtual void moveEnd();  // vtable slot 28
    void setUpCharaRegist();
    void setUpGoldStone();
    CHARA_REGIST_RESULT charaRegistPlayer();
    CHARA_REGIST_RESULT charaRegistInGame();
    GOLD_STONE_RESULT checkGoldStone();
    void checkGoldStoneSaveSetup();
    bool checkGoldStoneSaveMove();
    void saveTemp();
    void loadTemp();
    void setModel(bool isAction);
    void changeActionTbl();
    void requestVoice();
    void stopVoice();
    void callbackSetupVoice();
    void changeDefaultVoice();
    void changeMotion(bool isActionEnd);
    void setEdit(nGUIExt::CHARA_EDIT edit);
    nGUIExt::CHARA_EDIT getEdit();
    void createGUI(CREATE_GUI gui);
    void changeSCR();
    void changeCoordinate(bool force);
    void changeEquip();
    void changeBodyPreset();
    void changeTypeSex();
    void changeFaceAnime(bool increment);
    void managedFaceAnime();
    uMockUpModel* getModel() const;
    cpCharacterEdit* findCpCharacterEdit() const;
    nCharacterEdit::BODY_TYPE getBodyType() const;
    void setCharName(CHAR_NAME& name);
    const CHAR_NAME& getCharName();
    MT_CTSTR getFirstName();
    void setFirstName(MT_CTSTR str);
    MT_CTSTR getLastName();
    void setLastName(MT_CTSTR str);
    nNet::PAWN_SHARE_RANGE getShareRange() const;
    void setShareRange(nNet::PAWN_SHARE_RANGE range);
    bool isSalon() const;
    cEditParam* getEditParam();
    nHuman::JOB_ENUM getJob();
    u32 getStageNum();
    void registerRedoUndo(nCharacterEdit::EDIT_TYPE type);
    void resetRedoUndo();
    void applyRedoUndo(cUndoData& data, bool isUndo);
    void execUndo();
    void execRedo();
    bool isAbleUndo() const;
    bool isAbleRedo() const;
    MtString getSaveFolder();
    void save(u32 no);
    void load(u32 no);
    void lockCameraMove();
    bool isInActiveEdit(nCharacterEdit::EDIT_TYPE editType, nCharacterEdit::BODY_TYPE bodyType) const;
    void changeShape(nCharacterEdit::EDIT_TYPE type, f32 value, s32 ev, MtObject* pPartsPointer, bool isRegistRedoUndo);
    bool isOverWriteForce(nCharacterEdit::EDIT_TYPE type) const;
    void loadEditData(const cStorageDataEdit& strageData);
    void randamFace();
    void initEdit(bool isAction);
    void copyEditParam(cEditParam* pParam);
    void mergeParamSlider(cEditParam* pParam);
    void mergeParamSlider(cEditParam* pParam, nCharacterEdit::EDIT_TYPE type);
    void copyCompareEditParam(cEditParam* pParam);
    void updatePartsAll();
    void customEditValue(nCharacterEdit::EDIT_TYPE type, f32 v);
    s32 getEditParameter(nCharacterEdit::EDIT_TYPE type, cEditParam* pParam);
    MtProperty getPropertyEditParameter(nCharacterEdit::EDIT_TYPE type, cEditParam* pParam);
    bool setEditParameter(nCharacterEdit::EDIT_TYPE type, f32 value, cEditParam* pParam);
    cEditValue* getEditValueParameter(nCharacterEdit::EDIT_TYPE type, cEditParam* pParam);
    f32 getEditValue(nCharacterEdit::EDIT_TYPE type, cEditParam* pParam);
    rCharacterEdit* getEditRes();
    uCharacterEditBase::EXIT_TYPE getExit();
    static f32 convertPadPower(f32 f);
    void setCharacterData(cCharacterData* pData);
    void setJobEquip(nCharacterData::stEquipData& Data, u8 job);
    void setSlotNo(s32 slotNo);
    s32 getSlotNo() const;
    void setEditPawnData(cCharacterData::stPawnData* pData);
    bool isChargedVoiceData(u32 voiceType, u32 voiceUID) const;
    void notifyChangeScr_On();
    void notifyChangeScr_Off();
    void setParlorEquipData(nCharacterData::stEquipData& data);
    void setParlorJobId(u32 jobId);
    void setParlorEditParam(cEditParam* p);
    nCharacterEdit::EDIT_UPDATE_FLAG getChageNeed(nCharacterEdit::EDIT_TYPE type) const;
    cEditParamListArray& getCategporyParamListArray(nCharacterEdit::CATE category);
    bool isSavedStageEquipInfo() const;
    void saveStageIconInfo(const nCharacterEdit::stStageIconCash& info, u32 index);
    void saveEquipIconInfo(nCharacterEdit::stEquipIconCash info, u32 index);
    const nCharacterEdit::stStageIconCash& getStageSaveInfo(u32 index) const;
    const nCharacterEdit::stEquipIconCash& getEquipSaveInfo(u32 index) const;
    void addCountInitWarn(nCharacterEdit::EDIT_WARN_TYPE category);
    u32 getCountInitWarn(nCharacterEdit::EDIT_WARN_TYPE category) const;
    s32 getPaletteNum(nCharacterEdit::PALETTE palette) const;
    const MtTypedArray<nCharacterEdit::cPaletteParams>& getEditPalette(nCharacterEdit::PALETTE palette) const;
    bool isRewardParts(nCharacterEdit::PALETTE palette, u32 partsID) const;
protected:
    void loadPaletteNum();
    cResource* getPaletteResource(MT_CTSTR search_name);
    virtual MT_CTSTR getSndPitchSearchName() const;  // vtable slot 29
    s32 searchDiffEditParam(cEditParam* pParam, bool isChangeReq);
    u32 checkDiffEditParam(cEditParam* pEditParam, bool isChangeReq);
    void initCategoryParamList();
    void registerCategoryParamList(s32 category, s32 editType);
    bool isChangeEditValue(const cEditValue* pValue1, const cEditValue* pValue2) const;
    void applyChangeReq(nCharacterEdit::EDIT_TYPE type);
    void updateGpUI();
    virtual void applyStageType();  // vtable slot 30
    virtual uCharacterEditCameraBase* createCamera();  // vtable slot 31
    u32 getSalonChargeFlag();
    nCharacter::E_EDIT_UPDATE_TYPE getEditUpdateType(u32 flag) const;
    void setEquipPresetPalette(rEquipPresetPalette* pRes);
    const rEquipPresetPalette* getEquipPresetPalette() const;
    u32 getDefaultPresetNo() const;
    void reqChatActive();
    bool isOffline();
    bool isCompleteRegistParamList() const;
    void completeRegistParamList();
    void initEditCommon();
public:
    nNet::PAWN_SHARE_RANGE mShareRange;  // offset: 0x270
    cParlorParam mPalorParam;  // offset: 0x278
    EDIT_LOAD_RNO mEditLoadRno;  // offset: 0xab8
    TICKET mArcTicketEdit;  // offset: 0xac0
protected:
    u32 mInitWarnCount[6];  // offset: 0xac8
    stStageEquipCash mStageEquipChash;  // offset: 0xae0
    cCategoryParamListArray mCategporyParamListArray;  // offset: 0xb00
    nDDOUtility::cArray<int, 8> mPaletteNums;  // offset: 0xd20
    nDDOUtility::cArray<MtTypedArray<nCharacterEdit::cPaletteParams>, 8> mPaletteParams;  // offset: 0xd40
    nCharacterEdit::BODY_TYPE mBodyType;  // offset: 0xe40
    nGUIExt::CHARA_EDIT mEdit;  // offset: 0xe44
    CHARA_REGIST_ROUTINE mCharaRegistRno;  // offset: 0xe48
    GOLD_STONE_ROUTINE mGoldStoneRno;  // offset: 0xe4c
    u32 mSalonChargeFlag;  // offset: 0xe50
    u64 mSalonPrice;  // offset: 0xe58
    uGUICharacterEdit* mpGUIEdit;  // offset: 0xe60
    uGUIJobSelect* mpGUIJob;  // offset: 0xe68
    uGUICharacterEditPopCard* mpGUICard;  // offset: 0xe70
    uGUISystemMsg* mpGUISystemMsg;  // offset: 0xe78
    uGUIGPShop* mpGUIGoldStonShop;  // offset: 0xe80
    CHAR_NAME mName;  // offset: 0xe88
    cEditParam* mpCompareEditParam;  // offset: 0xea0
    cUndoFixedArray mUndoList;  // offset: 0xea8
    s32 mUndoMax;  // offset: 0x13e8
    s32 mUndoNowMax;  // offset: 0x13ec
    s32 mUndoLocal;  // offset: 0x13f0
    cCharacterData* mpCharData;  // offset: 0x13f8
    s32 mSlotNo;  // offset: 0x1400
    cCharacterData::stPawnData* mpEditData;  // offset: 0x1408
    bool mIsVoiceCallReq;  // offset: 0x1410
    uEditSaveLoadFlow* mpSaveLoadFlow;  // offset: 0x1418
    rEquipPresetPalette* mpEquipPresetPalette;  // offset: 0x1420
    u32 mOldLoginWaitNum;  // offset: 0x1428
    f32 mLoginWaitTimer;  // offset: 0x142c
    f32 mLoadingTimer;  // offset: 0x1430
    f32 mFadeWaitTimer;  // offset: 0x1434
    bool mIsChangeStage;  // offset: 0x1438
    bool mIsChangeTime;  // offset: 0x1439
    bool mIsOnceOfflineDialog;  // offset: 0x143a
    bool mIsDefaultUseWindowActive;  // offset: 0x143b
    EDIT_SAVE_LOAD_ROUTINE mSaveLoadRno;  // offset: 0x143c
    bool mIsRegistedParamList;  // offset: 0x1440
    cEditChargeInfoUpdator mEditChargeInfoUpdator;  // offset: 0x1448
public:
    static MyDTI DTI;
    static const u32 PRESET_DEF_PL = 0;
    static const u32 PRESET_DEF_PAWN = 1;
};

class uCharacterEditCamera : public uCharacterEditCameraBase
{
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
    uCharacterEditCamera();
    virtual ~uCharacterEditCamera();
public:
    static MyDTI DTI;
};

inline cEditParamList::cEditParamList() {
    this->mIsChange = false;
    this->mEditType = 0;
}

inline void uCharacterEdit::checkGoldStoneSaveSetup() {
    this->mSaveLoadRno = static_cast<uCharacterEdit::EDIT_SAVE_LOAD_ROUTINE>(0);
}

inline nGUIExt::CHARA_EDIT uCharacterEdit::getEdit() {
    return this->mEdit;
}

inline u32 uCharacterEdit::getSalonChargeFlag() {
    return this->mSalonChargeFlag;
}

inline const rEquipPresetPalette* uCharacterEdit::getEquipPresetPalette() const {
    return this->mpEquipPresetPalette;
}

inline void uCharacterEdit::completeRegistParamList() {
    this->mIsRegistedParamList = true;
}

inline void uCharacterEditCameraBase::lockCameraMove() {
    this->mIsLock = true;
}

inline void uCharacterEditCameraBase::clearLock() {
    this->mIsLock = false;
}

inline void uCharacterEditCameraBase::addRotateRSY(f32 add_y) {
    if ((this->mRotateRS.y + add_y) > 3.141593f) {
        if (-3.141593f > (-6.283186f + (this->mRotateRS.y + add_y))) {
            this->mRotateRS.y = 6.283186f + (-6.283186f + (this->mRotateRS.y + add_y));
        } else {
            this->mRotateRS.y = -6.283186f + (this->mRotateRS.y + add_y);
        }
    } else {
        if (-3.141593f > (this->mRotateRS.y + add_y)) {
            this->mRotateRS.y = 6.283186f + (this->mRotateRS.y + add_y);
        } else {
            this->mRotateRS.y = this->mRotateRS.y + add_y;
        }
    }
}

inline uCharacterEditCameraBase::cLimit::cLimit() {
    this->max = 0.0f;
    this->min = 0.0f;
}
