#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtColor.h"
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/MtObject.h"
#include "../shared/MtPrimitive2D.h"
#include "../shared/MtString.h"
#include "../shared/cControl.h"
#include "../shared/cUIObject.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtDTI;
struct MtFloat2;
struct MtFloat4;
class MtObject;
class MtPoint;
class MtSize;
class MtString;
class MtVector2;
class MtVector3;
class MtVector4;
class cControl;
class cDraw;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIInstScissorMask;
class cGUIInstance;
class cGUIObjColorAdjust;
class cGUIObjMessage;
class cGUIObjNull;
class cGUIObjPolygon;
class cGUIObjTexture;
class cGUIObjTextureRef;
class cGUIObjTextureSet;
class cGUIObject;
namespace nMarker { class cMarkerInfo; }
namespace nQuest { class SCHEDULE_ID; }
class rGUI;
class rGUIMessage;
class rTexture;
class uDDOModel;
class uGUIPopCmd01;

// Declarations
class uGUIMap;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIMap : public uGUIBase
{
public:
    enum OM_REFERENCE_TYPE
    {
        OM_CTRL_REFERENCE = 0,
        OM_SAVE_REFERENCE = 1,
        OM_REFERENCE_NUM = 2,
    };
    enum PTS_GUIDE_BIT
    {
        PTS_MOVE = 1,
        PTS_ZOOM = 2,
        PTS_FREE = 4,
        PTS_FREE_CHANGE = 8,
        PTS_TRANS = 16,
        PTS_LAND = 32,
        PTS_BIT_MAX = 6,
    };
    enum
    {
        CTRLTYPE_MENU = 0,
        CTRLTYPE_MINI = 1,
        CTRLTYPE_AREAMASTER = 2,
        CTRLTYPE_QUESTLOG = 3,
        CTRLTYPE_AREAMASTER_LARGE = 4,
    };
    enum
    {
        FNCF_NONE = 0,
        FNCF_MENUDISABLE = 1,
        FNCF_NDISP = 2,
        FNCF_NQST = 4,
    };
    enum
    {
        MARKER_PLAYER = 0,
        MARKER_PARTY_START = 1,
        MARKER_PARTY_END = 9,
        MARKER_SUBPARTY_START = 9,
        MARKER_SUBPARTY_END = 13,
        MARKER_ENEMY_START = 13,
        MARKER_ENEMY_END = 29,
        MARKER_OM_START = 29,
        MARKER_OM_END = 45,
        MARKER_NPCCLASS_START = 45,
        MARKER_NPCCLASS_END = 61,
        MARKER_LM_START = 61,
        MARKER_LM_END = 87,
        MARKER_LMLOBBY_START = 87,
        MARKER_LMLOBBY_END = 95,
        MARKER_QUESTINFO_START = 95,
        MARKER_QUESTINFO_END = 127,
        MARKER_SIGNAL_START = 127,
        MARKER_SIGNAL_END = 135,
        MARKER_USER_START = 135,
        MARKER_USER_END = 141,
        MARKER_DEBUG_START = 141,
        MARKER_DEBUG_END = 142,
        MARKER_MAX = 143,
    };
    enum
    {
        INPUTEVENT_SET_FREEMARKER = 66,
        INPUTEVENT_CHANGE_FREEMARKER = 67,
        INPUTEVENT_DIRECT_LINK = 68,
        INPUTEVENT_END = 69,
        INPUTEVENT_CHG_ALPHA = 70,
        INPUTEVENT_MAP_TYPE_MOVE = 71,
        INPUTEVENT_SUB_MENU = 72,
    };
    enum
    {
        OM_TREASURE_ABILITY = 0,
        OM_GATHER_ABILITY = 1,
        OM_ABILITY_MAX = 2,
    };
public:
    class MyDTI;
    class cLandId;
    struct stTabInfo;
    struct stPrimMask;
    struct stPrimWork;
    class cMarker;
    class cMarkerUpdInfo;
    class cMarkerLandInfo;
    class cPointerCursor;
    struct stSetupInstAndObjInfo;
    struct stAttendInfo;
    struct stChkWork;
    class cQuestMarkerData;
    struct stPTMarkerInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cLandId : public cUIObject
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
        cLandId();
        cLandId(u32 id);
    public:
        u32 mLandId;  // offset: 0x8
        static MyDTI DTI;
    };
public:
    struct stTabInfo
    {
    public:
        stTabInfo();
    public:
        u32 mapType;  // offset: 0x0
        u32 stageNo;  // offset: 0x4
    };
public:
    struct stPrimMask
    {
    public:
        MtVector3 mPos;  // offset: 0x0
        MtVector3 mScale;  // offset: 0x10
        MtVector3 mRot;  // offset: 0x20
        MtVector2 mDist;  // offset: 0x30
        u32 mIdx;  // offset: 0x38
        bool mIsEnable;  // offset: 0x3c
    };
public:
    struct stPrimWork
    {
    public:
        bool mIsEnableTex;  // offset: 0x0
        cGUIInstance* mpInst;  // offset: 0x8
        cGUIObjTextureRef* mpObjTex;  // offset: 0x10
        rTexture* mpTex;  // offset: 0x18
    };
public:
    class cMarker : public MtObject
    {
    public:
        enum
        {
            USEF_NONE = 0,
            USEF_INST_T = 1,
            USEF_INST_C = 2,
            USEF_INST_B = 4,
            USEF_INST_Q = 8,
            USEF_INST_N = 16,
        };
        enum
        {
            TYPE_PLAYER = 0,
            TYPE_PARTY = 1,
            TYPE_SUBPARTY = 2,
            TYPE_ENEMY = 3,
            TYPE_OM = 4,
            TYPE_NPCCLASS = 5,
            TYPE_LM = 6,
            TYPE_LMLOBBY = 7,
            TYPE_QUESTINFO = 8,
            TYPE_SIGNAL = 9,
            TYPE_USER = 10,
            TYPE_DEBUG = 11,
            TYPE_MAX = 12,
        };
        enum
        {
            FLG_NONE = 0,
            FLG_FILTER = 1,
            FLG_SNAPPC = 2,
            FLG_DISPWFIELD = 4,
            FLG_DISABLE = 8,
            FLG_NONE_BOTTOM = 16,
            FLG_DISPTGT = 32,
            FLG_VERTEX_COL = 64,
        };
        enum
        {
            DISPF_NONE = 0,
            DISPF_INST_T = 1,
            DISPF_INST_C = 2,
            DISPF_INST_B = 4,
            DISPF_INST_Q = 8,
        };
        enum
        {
            FIXF_DISABLE = -1,
            FIXF_NDISP = 0,
            FIXF_PL_DEF = 1,
            FIXF_PL_BUSY = 2,
            FIXF_PL_LOST = 3,
            FIXF_PT_DEF = 5,
            FIXF_PT_BUSY = 6,
            FIXF_PT_LOST = 7,
            FIXF_PT_MULTI = 8,
            FIXF_FREE = 10,
            FIXF_FREEL = 11,
            FIXF_PT_SUB = 20,
            FIXF_EM_NORMAL = 30,
            FIXF_EM_SQRARE = 31,
            FIXF_EM_CHARGE = 32,
            FIXF_QST_M_NA = 40,
            FIXF_QST_M_AE = 41,
            FIXF_QST_M_AD = 42,
            FIXF_QST_S_NA = 43,
            FIXF_QST_S_AE = 44,
            FIXF_QST_S_AD = 45,
            FIXF_QST_S_CD = 46,
            FIXF_QST_S_HT = 47,
            FIXF_QST_L_AE = 48,
            FIXF_QST_L_AD = 49,
            FIXF_QST_L_BLANK = 50,
            FIXF_OM_GATHER = 60,
            FIXF_OM_LADDER = 61,
            FIXF_OM_DOOR = 62,
            FIXF_OM_LEVER = 63,
            FIXF_OM_LOCK = 64,
            FIXF_OM_BROKENWALL = 65,
            FIXF_OM_WARP = 66,
            FIXF_OM_BASE = 67,
            FIXF_OM_ENTDANGEON = 68,
            FIXF_OM_ENTBASEMENT = 69,
            FIXF_OM_WELL = 70,
            FIXF_OM_AREACHG = 71,
            FIXF_OM_ARC = 72,
            FIXF_OM_CLOSE_DOOR = 73,
            FIXF_OM_MUSHROOM = 74,
            FIXF_OM_AREA_WARP = 75,
            FIXF_EST_SHOP = 100,
            FIXF_EST_INN = 101,
            FIXF_EST_INN2 = 102,
            FIXF_EST_PARTY = 103,
            FIXF_EST_CLAN = 104,
            FIXF_EST_CRAFT = 105,
            FIXF_EST_BEAUTY = 106,
            FIXF_EST_NEWS = 107,
            FIXF_EST_BO = 108,
            FIXF_EST_JM = 109,
            FIXF_OM_WAREHOUSE = 110,
            FIXF_OM_DELIVERY = 111,
            FIXF_OM_RIMSTONE = 112,
            FIXF_OM_WARPCMN = 113,
            FIXF_OM_WARPMINE = 114,
            FIXF_OM_QB = 115,
            FIXF_OM_EB = 116,
            FIXF_OM_RB = 117,
            FIXF_EST_AM = 118,
            FIXF_OM_ORB_TREE = 119,
            FIXF_LAND_LOBBY = 100,
            FIXF_LAND_WARPMINE = 101,
            FIXF_SP_DIV = 160,
            FIXF_MAX = 161,
        };
        enum
        {
            FIXUF_NDISP = 0,
            FIXUF_CAMERA = 1,
            FIXUF_BALLOON = 2,
        };
        enum
        {
            PRIO_NONE = 0,
            PRIO_SIGNAL = 1,
            PRIO_OM = 2,
            PRIO_NPCCLASS = 3,
            PRIO_LM = 4,
            PRIO_LMLOBBY = 4,
            PRIO_QST = 5,
            PRIO_USERMARKER = 37,
            PRIO_EM = 39,
            PRIO_SUBPT = 40,
            PRIO_PT = 41,
            PRIO_PL = 42,
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
        cMarker();
        virtual ~cMarker();
        virtual void setMarkerPos(f32 fZoomRate, f32 fRot, MtFloat2 wh, MtFloat4 rect);  // vtable slot 6
        void setDispF(u32 uFlag);
        void orDispF(u32 uFlag);
        void xorDispF(u32 uFlag);
        void clrDispF(u32 uFlag);
        bool isDispF(u32 uFlag);
        u32 getDispF();
        void setUseF(u32 uFlag);
        void orUseF(u32);
        void xorUseF(u32);
        void clrUseF(u32);
        bool isUseF(u32 uFlag);
        u32 getUseF();
    public:
        bool mEnable;  // offset: 0x8
        u32 mType;  // offset: 0xc
        u32 mFlg;  // offset: 0x10
        u32 mDispF;  // offset: 0x14
        u32 mUseF;  // offset: 0x18
        u32 mPrio;  // offset: 0x1c
        u32 mSeqId;  // offset: 0x20
        u32 mSdlId;  // offset: 0x24
        u32 mCnt;  // offset: 0x28
        s32 mId;  // offset: 0x2c
        s32 mFloorId;  // offset: 0x30
        s32 mFixFrame;  // offset: 0x34
        s32 mFixFrameU;  // offset: 0x38
        f32 mRot;  // offset: 0x3c
        f32 mRotU;  // offset: 0x40
        f32 mScale;  // offset: 0x44
        f32 mScaleT;  // offset: 0x48
        f32 mDispClamp;  // offset: 0x4c
        f32 mDispClampInside;  // offset: 0x50
        f32 mDispTimer;  // offset: 0x54
        MtVector3 mPos;  // offset: 0x60
        MtVector3 mPosReal;  // offset: 0x70
        MtVector3 mPosOfs;  // offset: 0x80
        MtVector2 mPos2Ofs;  // offset: 0x90
        MtColor mColor;  // offset: 0x98
        MtString mName;  // offset: 0xa0
        cGUIInstNull* mpInstNull;  // offset: 0xa8
        cGUIInstAnimation* mpInstIcon;  // offset: 0xb0
        cGUIInstAnimation* mpInstIconT;  // offset: 0xb8
        cGUIInstAnimation* mpInstIconB;  // offset: 0xc0
        cGUIInstAnimation* mpInstName;  // offset: 0xc8
        cGUIObjTexture* mpObjIcon;  // offset: 0xd0
        cGUIObjMessage* mpObjName;  // offset: 0xd8
        cGUIObjMessage* mpObjCount0;  // offset: 0xe0
        cGUIObjMessage* mpObjCount1;  // offset: 0xe8
        cGUIObjMessage* mpObjIconNum;  // offset: 0xf0
        cGUIObjColorAdjust* mpObjColor;  // offset: 0xf8
        cGUIObjTextureSet* mpObjTexSetT;  // offset: 0x100
        cGUIObjColorAdjust* mpObjColorT;  // offset: 0x108
        uGUIBase::cReferenceUIIconQuest mIconQuest;  // offset: 0x110
        static MyDTI DTI;
    };
public:
    class cMarkerUpdInfo : public MtObject
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
        cMarkerUpdInfo();
        virtual ~cMarkerUpdInfo();
    public:
        bool mEnable;  // offset: 0x8
        u32 mIdx;  // offset: 0xc
        u32 mGroupNo;  // offset: 0x10
        u32 mQuestId;  // offset: 0x14
        bool mIsDefFloor;  // offset: 0x18
        MtVector2 mDist;  // offset: 0x20
        f32 mEffectiveRange;  // offset: 0x28
        u32 mPosIdx;  // offset: 0x2c
        s32 mSaveId;  // offset: 0x30
        uDDOModel* mpUnit;  // offset: 0x38
        static MyDTI DTI;
    };
public:
    class cMarkerLandInfo : public MtObject
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
        cMarkerLandInfo();
        virtual ~cMarkerLandInfo();
    public:
        MtVector3 mWorldPos;  // offset: 0x10
        MtVector2 mDist;  // offset: 0x20
        u32 mType;  // offset: 0x28
        u32 mSpotMessId;  // offset: 0x2c
        s32 mMessId;  // offset: 0x30
        static MyDTI DTI;
    };
public:
    class cPointerCursor : public MtObject
    {
    public:
        enum
        {
            MINI_MAP = 0,
            MENU_MAP = 1,
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
        cPointerCursor();
        virtual ~cPointerCursor();
        void execPadCursorCtrl(s32 type, f32 rot, f32 scale);
        void execMouseCursorCtrl(s32 type, f32 rot, f32 scale);
    private:
        MtVector2 fitingCursorInFrame();
        void movingDispMapPos(f32 rot, const MtVector2& moveValue);
    public:
        bool mEnable;  // offset: 0x8
        MtVector2 mPos;  // offset: 0x10
        MtVector2 mPosFocusInfo;  // offset: 0x18
        MtVector2 mMove;  // offset: 0x20
        MtPoint mPosMouse;  // offset: 0x28
        f32 mSpd;  // offset: 0x30
        f32 mDistSnap;  // offset: 0x34
        u32 mFocusMarkerId;  // offset: 0x38
        u32 mFocusMarkerPrio;  // offset: 0x3c
        bool mIsVisible;  // offset: 0x40
        cGUIInstance* mpInstPointer;  // offset: 0x48
        cGUIInstance* mpInstFocusQuest;  // offset: 0x50
        cGUIObjNull* mpObjMsgFocusQstNull;  // offset: 0x58
        cGUIObjMessage* mpObjMsgFocusQstBtn;  // offset: 0x60
        cGUIObjMessage* mpObjMsgFocusQstTitle;  // offset: 0x68
        uGUIBase::cAdjustableWindow mWindow;  // offset: 0x70
        cGUIInstScissorMask* mpInstMask;  // offset: 0x110
        static MyDTI DTI;
    };
public:
    struct stSetupInstAndObjInfo
    {
    public:
        u32 mId_InstNull;  // offset: 0x0
        u32 mId_InstNullMap;  // offset: 0x4
        u32 mId_InstNullOfst;  // offset: 0x8
        u32 mId_InstMask;  // offset: 0xc
        u32 mId_InstPrim;  // offset: 0x10
        u32 mId_InstMarker;  // offset: 0x14
        u32 mId_InstIcon;  // offset: 0x18
        u32 mId_InstIconCovered;  // offset: 0x1c
        u32 mId_InstIconUnder;  // offset: 0x20
        u32 mId_InstIconQuest;  // offset: 0x24
        u32 mId_InstName;  // offset: 0x28
        u32 mId_InstPointer;  // offset: 0x2c
        u32 mId_InstFocusInfo;  // offset: 0x30
        u32 mId_InstFocusInfoWindow;  // offset: 0x34
        u32 mId_InstCompass;  // offset: 0x38
        u32 mId_InstZoomSlider;  // offset: 0x3c
        u32 mId_InstBack;  // offset: 0x40
        u32 mId_InstPosition;  // offset: 0x44
        u32 mId_InstFooter;  // offset: 0x48
        u32 mId_InstFilter;  // offset: 0x4c
        u32 mId_InstBtnGuaid;  // offset: 0x50
        u32 mId_InstStayPlPos;  // offset: 0x54
        u32 mId_InstFieldBack;  // offset: 0x58
        u32 mId_InstGuide00;  // offset: 0x5c
        u32 mId_InstGuide01;  // offset: 0x60
        u32 mId_InstMsgMarker;  // offset: 0x64
        u32 mId_ObjBack;  // offset: 0x68
        u32 mId_ObjZoomSlider;  // offset: 0x6c
        u32 mId_ObjPosX;  // offset: 0x70
        u32 mId_ObjPosY;  // offset: 0x74
        u32 mId_ObjFooterAreaname;  // offset: 0x78
        u32 mId_ObjFooterMask;  // offset: 0x7c
        u32 mId_ObjFooterBackL;  // offset: 0x80
        u32 mId_ObjFooterBackC;  // offset: 0x84
        u32 mId_ObjFooterBackR;  // offset: 0x88
        u32 mId_ObjMsgMarkerNumber;  // offset: 0x8c
        u32 mId_VarDistFooter;  // offset: 0x90
        u32 mId_VarSizeQuestguide;  // offset: 0x94
        u32 mId_InstBtnMenu;  // offset: 0x98
        u32 mId_InstMsgLand;  // offset: 0x9c
        u32 mId_InstNullSubmenu;  // offset: 0xa0
        u32 mId_ObjBtnMenuMouseOver;  // offset: 0xa4
        u32 mId_ObjMsgLand;  // offset: 0xa8
        u32 mId_VarOffsetSubmenu;  // offset: 0xac
        u32 mId_VarAnimBeaconDoor;  // offset: 0xb0
        u32 mId_InstPrimMask;  // offset: 0xb4
    };
public:
    struct stAttendInfo
    {
    public:
        stAttendInfo();
    public:
        s32 mNpcIdx[8];  // offset: 0x0
    };
public:
    struct stChkWork
    {
    public:
        stChkWork();
    public:
        s32 mIdx;  // offset: 0x0
        f32 mDist;  // offset: 0x4
    };
public:
    class cQuestMarkerData : public MtObject
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
        cQuestMarkerData();
        cQuestMarkerData(u32, u32, s32, MtVector2&, bool);
        // Address: 0x01afb8b0 - 0x01afb8b1 (1 bytes)
        virtual ~cQuestMarkerData() {}
    public:
        u32 mScheduleId;  // offset: 0x8
        u32 mPrio;  // offset: 0xc
        s32 mIndex;  // offset: 0x10
        MtVector2 mDist;  // offset: 0x18
        bool mDefFloor;  // offset: 0x20
        static MyDTI DTI;
    };
public:
    struct stPTMarkerInfo
    {
    public:
        stPTMarkerInfo();
    public:
        s32 mIdx;  // offset: 0x0
        MtVector3 mPos;  // offset: 0x10
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
    uGUIMap();
    virtual ~uGUIMap();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    virtual void updatePtr();  // vtable slot 17
    virtual MtSize getMapTexSize();  // vtable slot 91
    void setupCommon();
    void updateDisp();
    void setStart(bool);
    bool isStarted();
    void setCtrlType(u32 uType);
    u32 getCtrlType();
    void setFuncF(u32);
    void orFuncF(u32 uFlag);
    void xorFuncF(u32);
    void clrFuncF(u32 uFlag);
    bool isFuncF(u32 uFlag);
    u32 getFuncF();
    bool isOnSCM();
    bool isOnTab();
    void setPosMouse(MtPoint point);
    MtVector2 getPos2CenterMapOld();
    void setLandType(s32 type);
    s32 getLandType();
    void changeLandType();
    bool calcMapPos(MtVector2& out_center_pos, MtVector2& out_disp_pos, bool bForceGet, bool bAreaMaster);
    void clearUpdFrm();
    void getPointerRealPos(MtVector3& pos);
private:
    void updateInit();
    void updateWait();
    void updateExit();
    virtual void moveInput();  // vtable slot 87
    u32 evCtrlEnd(cControl::Message* msg);
    u32 evCtrlChgAlpha(cControl::Message* msg);
    u32 evCtrlMapTypeMove(cControl::Message* msg);
    u32 evCtrlSetFreeMarker(cControl::Message* msg);
    u32 evCtrlChangeFreeMarker(cControl::Message* msg);
    u32 evCtrlSubmenu(cControl::Message* msg);
    virtual void evEnd();  // vtable slot 48
    void evChgAlpha();
    void evMapTypeMove();
    void evSubMenu();
    void setupMarker();
    void createMarker(u32 uType, s32 sId);
    void execBaseElement();
    void execPrimInstance();
    void execMarker();
    void execPrimitiveMask(MtFloat2 wh, MtFloat4 rect);
    void execCompass();
    void execZoomSlider();
    void execPointerCursor();
protected:
    virtual void execPosition();  // vtable slot 92
    virtual void execFooter();  // vtable slot 93
    virtual void execBtnGuaid();  // vtable slot 94
private:
    void updateNpcAttendMarkerInfo(stAttendInfo* info, u32& dispMax);
    void updateEmMarkerInfo();
    void updateOmMarkerInfo();
    void registerOM(u32 index, OM_REFERENCE_TYPE type, stChkWork& checkWork);
    void updatepPatchInfo();
    void updateNpcClassMarkerInfo();
    void updateQuestMarkerInfo();
    void updateLandMarkerInfo();
protected:
    void zoomInput();
    void markerInput();
    u32 evCtrlZoomMove(cControl::Message* msg);
    void updateDispMapPos(bool bForce);
    void updateDispAreaName();
    void setPrimAlpha(u32 uIdx, u32 uAlpha);
    void setPrimAlphaAll(u32 uAlpha);
    void moveUpdate();
    virtual void moveEvent();  // vtable slot 88
    u32 evCtrlDirectLink(cControl::Message* msg);
    void evSetFreeMarker();
    void evChangeFreeMarker();
    void evDirectLink();
    s32 getLandTypeFromStageNo(s32 stageNo);
    s32 getStageNoFromLandType(s32 landType);
private:
    void updatePrimInstance(rTexture* pTex, f32 fPosX, f32 fPosY, f32 fObjSize, f32 fTexSize, bool bLoading);
    void _updatePrimInstance(u32 uPrimIdx, bool bVisible, f32 fPosX, f32 fPosY, u32 uAlpha);
    void setPrimTexture(u32 uIdx, rTexture* pTex);
    void clearPrimTexture(bool bForce);
    void initPrimTextureEnable();
    void updateFocusMarker();
    void updateDelFreeMarker();
    bool isMouseOverMenuMap();
    bool calcOmAbility(MtVector3& omPos, MtVector2& outVec, s32 om_Ability);
    bool isQuestDispClamp(nQuest::SCHEDULE_ID ScheduleId);
    bool isBelongDisplayGroup(s32 nowGroup, s32 targetGroup);
    bool isBelongDisplayFloor(MtVector3& pos, s32& groupNo, bool isCheckTgtstg);
    bool isUpdateMarkerInfoOnField();
    bool isSameStage(s32 stageNoMe, s32 stageNo);
    MtVector2 calcDistFromCenter(MtVector3& vec);
    bool registerMarkerInfo(cMarkerUpdInfo* Tbl, cMarkerUpdInfo* regi, stChkWork& chkWork, u32& registNum, u32 registMax, bool isReplace);
    bool registerMarkerInfo(cMarkerLandInfo* Tbl, cMarkerLandInfo* regi, stChkWork& chkWork, u32& registNum, u32 registMax, bool isReplace);
    MtVector3 getNearPlayerPosCalc(const nMarker::cMarkerInfo* pMarker);
    s32 getOmMarkerFixF(u32 icon);
    s32 getNpcClassMarkerFixf(u32 funcType);
    s32 getLandMarkerFixf(u32 type);
    MtVector4 getObjMarkerPos(MtVector3& vPos, f32 fRot, f32 fDispClamp, f32 fDispClampInside, MtFloat2 wh, MtFloat4 rect);
    void changeLandName(s32 landType);
    void changeFieldBackSequence(s32 worldType);
    u32 submenuCallBack(MtObject* pDummy, MtObject* pUnit);
    void changeSubMenuDispState();
private:
    cControl* mpCtrl;  // offset: 0x8c8
    uGUIBase::cHorizontalList* mpCtrlMapType;  // offset: 0x8d0
    cControl* mpCtrlSubMenu;  // offset: 0x8d8
    uGUIPopCmd01* mpSubMenu;  // offset: 0x8e0
    MtPoint mPosMouse;  // offset: 0x8e8
    MtTypedArray<cLandId> mLandIdParam;  // offset: 0x8f0
    stTabInfo mTabInfo[5];  // offset: 0x910
    u32 mCtrlTabType;  // offset: 0x938
    u32 mTabNum;  // offset: 0x93c
    s32 mOffsetSubmenu;  // offset: 0x940
    s32 mVarOpenDoorBeacon;  // offset: 0x944
    bool mStart;  // offset: 0x948
    bool mIsNewMarkerSystem;  // offset: 0x949
    bool mOpenSubMenu;  // offset: 0x94a
    bool mIsEnableLandSubMenu;  // offset: 0x94b
protected:
    rGUI* mpGUIRes;  // offset: 0x950
    rGUIMessage* mpGUIMsgGuide;  // offset: 0x958
    cGUIInstance* mpInstNull_map;  // offset: 0x960
    cGUIInstAnimation* mpInstBack;  // offset: 0x968
    cGUIInstScissorMask* mpInstMask;  // offset: 0x970
    cGUIInstNull* mpInstNull_ofst;  // offset: 0x978
    cGUIInstance* mpInstPrim_org;  // offset: 0x980
    cGUIInstance* mpInstmarker_org;  // offset: 0x988
    cGUIInstance* mpInstcompass;  // offset: 0x990
    cGUIInstance* mpInstZoomSlider;  // offset: 0x998
    cGUIInstAnimation* mpInstPosition;  // offset: 0x9a0
    cGUIInstance* mpInstFooter;  // offset: 0x9a8
    cGUIInstance* mpInstFilter;  // offset: 0x9b0
    cGUIInstAnimation* mpInstStayPlPos;  // offset: 0x9b8
    cGUIInstAnimation* mpInstFieldBack;  // offset: 0x9c0
    cGUIObjTexture* mpObjField;  // offset: 0x9c8
    cGUIObjTexture* mpObjBack;  // offset: 0x9d0
    cGUIObjPolygon* mpObjBackCollision;  // offset: 0x9d8
    cGUIObject* mpObjZoomSlider;  // offset: 0x9e0
    cGUIObjMessage* mpObjPosX;  // offset: 0x9e8
    cGUIObjMessage* mpObjPosY;  // offset: 0x9f0
    cGUIObject* mpObjfooter_base;  // offset: 0x9f8
    cGUIObject* mpObjfooter_pos;  // offset: 0xa00
    cGUIObjMessage* mpObjFooterAreaname;  // offset: 0xa08
    cGUIObjPolygon* mpObjFooterMask;  // offset: 0xa10
    cGUIObjTexture* mpObjFooterBackL;  // offset: 0xa18
    cGUIObjTexture* mpObjFooterBackC;  // offset: 0xa20
    cGUIObjTexture* mpObjFooterBackR;  // offset: 0xa28
    rTexture* mpTexBlank;  // offset: 0xa30
    cGUIInstance* mpInstBtnMenu;  // offset: 0xa38
    cGUIObject* mpObjBtnMenuMouseOver;  // offset: 0xa40
    cGUIInstance* mpInstMsgLand;  // offset: 0xa48
    cGUIObjMessage* mpObjMsgLand;  // offset: 0xa50
    cGUIInstNull* mpInstNullSubmenu;  // offset: 0xa58
    cGUIInstance* mpInstMsgMarker;  // offset: 0xa60
    cGUIObjMessage* mpObjMsgMarkerNumber;  // offset: 0xa68
    cGUIInstance* mpInstPrim_Mask;  // offset: 0xa70
    stPrimMask mTblPrimMask[20];  // offset: 0xa80
    cGUIObjPolygon* mpObjPrimMaskPoly[20];  // offset: 0xf80
    stPrimWork mTblPrim[16];  // offset: 0x1020
    uGUIBase::cReferenceUICloseBtn mCloseBtn;  // offset: 0x1220
    uGUIBase::cReferenceUITab mTab;  // offset: 0x1280
    uGUIBase::cReferenceUIBtnGuide mBtnGuide;  // offset: 0x1330
    uGUIBase::cReferenceUIBtnGuide::stGuideBtnData mTblGuide[6];  // offset: 0x13c8
    MtTypedArray<cMarker> mMarker;  // offset: 0x14b8
    cMarkerUpdInfo mTblEMInfo[16];  // offset: 0x14d8
    cMarkerUpdInfo mTblOMInfo[16];  // offset: 0x18d8
    cMarkerUpdInfo mTblNpcClsInfo[16];  // offset: 0x1cd8
    cMarkerUpdInfo mTblQstInfo[32];  // offset: 0x20d8
    cMarkerLandInfo mTblLMInfo[26];  // offset: 0x28e0
    bool mSetDefaultTexture;  // offset: 0x2f60
    bool mDispFooter;  // offset: 0x2f61
    bool mIsDrawMap;  // offset: 0x2f62
    bool mIsOnSCM;  // offset: 0x2f63
    bool mIsOnTab;  // offset: 0x2f64
    bool mPreVisiblePos;  // offset: 0x2f65
    f32 mZoomRate;  // offset: 0x2f68
    f32 mZoomRateWork;  // offset: 0x2f6c
    u32 mZoomRateCount;  // offset: 0x2f70
    f32 mRot;  // offset: 0x2f74
    MT_CHAR mNameMap[256];  // offset: 0x2f78
    MtVector3 mPosCenterMapMenu;  // offset: 0x3080
    MtVector2 mPos2CenterMap;  // offset: 0x3090
    MtVector2 mPos2CenterMapOld;  // offset: 0x3098
    u32 mCtrlType;  // offset: 0x30a0
    s32 mFloor;  // offset: 0x30a4
    u32 mUpdCntEMInfo;  // offset: 0x30a8
    u32 mUpdCntOMInfo;  // offset: 0x30ac
    u32 mUpdCntNpcClsInfo;  // offset: 0x30b0
    u32 mUpdCntQstInfo;  // offset: 0x30b4
    u32 mUpdCntLMInfo;  // offset: 0x30b8
    u32 mUpdCntPatchInfo;  // offset: 0x30bc
    f32 mUpdFrmEMInfo;  // offset: 0x30c0
    f32 mUpdFrmOMInfo;  // offset: 0x30c4
    f32 mUpdFrmPatchInfo;  // offset: 0x30c8
    f32 mUpdFrmNpcClsInfo;  // offset: 0x30cc
    f32 mUpdFrmQstInfo;  // offset: 0x30d0
    f32 mUpdFrmLMInfo;  // offset: 0x30d4
    f32 mDistMarkerInfo;  // offset: 0x30d8
    f32 mDelCntFreeMarker;  // offset: 0x30dc
    s32 mDistFooter;  // offset: 0x30e0
    u32 mFuncF;  // offset: 0x30e4
    u32 mChgAlphaStep;  // offset: 0x30e8
    u32 mMapTypeOld;  // offset: 0x30ec
    s32 mQuestGuideHeight;  // offset: 0x30f0
    bool mSkipUpdateDisp;  // offset: 0x30f4
    s32 mPartyMarkerMemberIndexSave[8];  // offset: 0x30f8
    s32 mLandType;  // offset: 0x3118
    s32 mNowGroupNo;  // offset: 0x311c
    bool mIsUsePrio[1120];  // offset: 0x3120
    cPointerCursor mPointerCursor;  // offset: 0x3580
    stSetupInstAndObjInfo mSetupInfo;  // offset: 0x3698
    uGUIBase::cVerticalList* mpCtrlZoom;  // offset: 0x3750
    uGUIBase::cHorizontalList* mpCtrlMarkerIdx;  // offset: 0x3758
    cControl* mpCtrlMarker;  // offset: 0x3760
public:
    static MyDTI DTI;
protected:
    static const u32 NPCATTENDMARKERDISP_MAX = 4;
    static const u32 EMMARKERDISP_MAX = 16;
    static const u32 OMMARKERDISP_MAX = 16;
    static const u32 NPCCLASSMARKERDISP_MAX = 16;
    static const u32 LANDMARKERDISP_MAX = 26;
    static const u32 LMLOBBYDISP_MAX = 8;
    static const u32 QUESTMARKERDISP_MAX = 32;
    static const u32 PRIM_MASK_MAX = 20;
    static const u32 TAB_INFO_MAX = 5;
    static const u32 INVALID_INSTID = 4294967295;
    static const u32 INVALID_MARKERID = 4294967295;
    static const u32 ZOOMRATE_DIST = 3;
};
