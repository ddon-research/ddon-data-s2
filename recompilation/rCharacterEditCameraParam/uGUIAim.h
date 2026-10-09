#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/nDDOModel.h"
#include "../shared/nDDOUtility.h"
#include "../shared/nGUIAim.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector3;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjNull;
class cGUIObjTexture;
class cGUIObjTextureSet;
class rGUI;
class uPlayer;

// Declarations
class uGUIAim;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIAim : public uGUIBase
{
public:
    enum MODE
    {
        MODE_NONE = 0,
        MODE_LOCK_ON_MARKER = 1,
        MODE_JOB02 = 2,
        MODE_JOB03 = 3,
        MODE_JOB06_CS13_MANUAL = 4,
        MODE_JOB08 = 5,
        MODE_JOB10 = 6,
    };
public:
    class MyDTI;
    struct DATA;
    struct cTargetMarker;
public:
    using TargetMarkerScales = nDDOUtility::cArray<float, 3>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct DATA
    {
    public:
        cGUIInstNull* mpINST_Null;  // offset: 0x0
        cGUIInstNull* mpINST_Null_all;  // offset: 0x8
        cGUIInstAnimation* mpINST_fix_gauge00;  // offset: 0x10
        cGUIObjNull* mpOBJ_fix_gauge00_f_Null_distance;  // offset: 0x18
        cGUIObjTextureSet* mpOBJ_fix_gauge00_distance;  // offset: 0x20
        cGUIObjTextureSet* mpOBJ_fix_gauge00_distance_shadow;  // offset: 0x28
        cGUIObjNull* mpOBJ_fix_gauge00_Null_blur;  // offset: 0x30
        cGUIObjTexture* mpOBJ_fix_gauge00_base;  // offset: 0x38
        cGUIObjTexture* mpOBJ_fix_gauge00_f_leftdown;  // offset: 0x40
        cGUIObjTexture* mpOBJ_fix_gauge00_f_lefttop;  // offset: 0x48
        cGUIObjTexture* mpOBJ_fix_gauge00_f_rightdown;  // offset: 0x50
        cGUIObjTexture* mpOBJ_fix_gauge00_f_righttop;  // offset: 0x58
        cGUIInstAnimation* mpINST_seaker;  // offset: 0x60
        cGUIInstAnimation* mpINST_maker;  // offset: 0x68
        cGUIInstAnimation* mpINST_earcher_reticle;  // offset: 0x70
        cGUIInstAnimation* mpINST_fix_earcher_critical;  // offset: 0x78
        cGUIInstAnimation* mpINST_earcher_maker;  // offset: 0x80
        cGUIInstAnimation* mpINST_earcher_fullgage;  // offset: 0x88
    };
public:
    struct cTargetMarker
    {
    public:
        enum STATE
        {
            STATE_FADE_IN = 0,
            STATE_LOOP = 1,
            STATE_FADE_OUT = 2,
            STATE_NUM = 3,
            STATE_INVALID = 3,
        };
        enum LOCK_ON_RANGE
        {
            LOCK_ON_RANGE_NEAR = 0,
            LOCK_ON_RANGE_JUST = 1,
            LOCK_ON_RANGE_FAR = 2,
            LOCK_ON_RANGE_NUM = 3,
        };
    public:
        cTargetMarker();
        bool isUsed() const;
        void setup(uGUIBase* guiBase, cGUIInstAnimation* pINST_maker, cGUIInstAnimation* pINST_seaker_maker, cGUIInstAnimation* pINST_earcher_maker);
        bool start(nGUIAim::TARGET_MARKER_TYPE targetMarkerType, nDDOModel::LOCKON_TARGET_TYPE lockOnTargetType, const MtVector3& targetPos, const uGUIAim::TargetMarkerScales& targetMarkerScales);
        void end();
        void update(uPlayer* player);
        void setTargetPos(const MtVector3& targetPos);
        bool applyTargetPos();
        static u32 GetSequenceId(STATE state, nGUIAim::TARGET_MARKER_TYPE targetMarkerType, uPlayer* player);
    public:
        cGUIInstAnimation* mpINST_maker;  // offset: 0x0
        cGUIInstAnimation* mpINST_seaker_maker;  // offset: 0x8
        cGUIInstAnimation* mpINST_earcher_maker;  // offset: 0x10
        cGUIInstAnimation* mpINST_current;  // offset: 0x18
        STATE mState;  // offset: 0x20
        nGUIAim::TARGET_MARKER_TYPE mTargetMarkerType;  // offset: 0x24
        nDDOModel::LOCKON_TARGET_TYPE mLockOnTargetType;  // offset: 0x28
        MtVector3 mTargetPos;  // offset: 0x30
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
    static MODE CheckMode(uPlayer* player);
    uGUIAim();
    virtual ~uGUIAim();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    void onMagicBowShot();
    u32 setTargetMarker(nGUIAim::TARGET_MARKER_TYPE targetMarkerType, nDDOModel::LOCKON_TARGET_TYPE lockOnTargetType, const MtVector3& targetPos);
    void endTargetMarker(u32 targetMarkerId);
    void setTargetMarkerPos(u32 targetMarkerId, const MtVector3& pos);
    bool isValidTargetMarkerId(u32 targetMarkerId) const;
    void clearAllAimTargetMarkers();
    void setTargetMarkerScale(nGUIAim::TARGET_MARKER_TYPE targetMarkerType, f32 scale);
protected:
    virtual bool fixCameraRelatedScreenPos();  // vtable slot 81
    virtual void adjustScale();  // vtable slot 84
private:
    void updateInit();
    void updateWait();
    void updateIn();
    void updateLoop();
    void updateEnd();
    void updateExit();
    void drawInfo(uPlayer* player);
private:
    DATA mData;  // offset: 0x8c8
    rGUI* mpGUIRes;  // offset: 0x958
    MODE mMode;  // offset: 0x960
    TargetMarkerScales mTargetMarkerScales;  // offset: 0x964
    nDDOUtility::cArray<cTargetMarker, 16> mTargetMarkers;  // offset: 0x970
    bool mIsMagicBowShot;  // offset: 0xd70
public:
    static MyDTI DTI;
    static const u32 TARGET_MARKER_NUM = 16;
    static const f32 DEFAULT_TARGET_MARKER_SCALE_MAGIC;
    static const f32 DEFAULT_TARGET_MARKER_SCALE_MAGIC_BOW;
    static const f32 DEFAULT_TARGET_MARKER_SCALE_WIRE;
};
