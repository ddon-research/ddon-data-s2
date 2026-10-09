#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "MtPrimitive2D.h"
#include "cSystem.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtDTI;
class MtObject;
class MtPoint;
class MtProperty;
class MtPropertyList;
class MtSize;
class MtUI;
class MtVector2;
class MtVector3;
class MtVector4;
struct ScePadData;
class cBrowserPS4;

// Declarations
class sPad;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using s16 = short;
using s32 = int;
using s8 = signed char;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class sPad : public cSystem
{
    // inferred: cBrowserPS4::checkValidDevice names sPad::mpInstance
    friend class cBrowserPS4;
public:
    enum PAD_PORT_TYPE
    {
        PAD_USER_STD = 0,
        PAD_USER_SPE = 2,
        PAD_SYS_REMOTE = 16,
    };
    enum KIND
    {
        KIND_NONE = 0,
        KIND_UNKNOWN = 1,
        KIND_JOYPAD = 2,
        KIND_PS3PAD = 3,
        KIND_X360PAD = 4,
        KIND_XBOXONEPAD = 5,
        KIND_ARCADE_STICK = 6,
        KIND_FLIGHT_STICK = 7,
        KIND_WHEEL = 8,
        KIND_DANCEPAD = 9,
        KIND_GUITAR = 10,
        KIND_DRUM_KIT = 11,
        KIND_BIGBUTTON = 12,
        KIND_CTR = 13,
        KIND_VITAPAD = 14,
        KIND_PS4PAD = 15,
        KIND_NUM = 16,
    };
    enum DECIDE_BUTTON
    {
        DECIDE_Obutton = 8192,
        DECIDE_Xbutton = 16384,
    };
    enum CANCEL_BUTTON
    {
        CANCEL_Xbutton = 16384,
        CANCEL_Obutton = 8192,
    };
public:
    class MyDTI;
    class Pad;
    struct PAD_INFO;
    struct PAD_FREE;
    struct PAD_REPEAT;
    struct PAD_VIB;
    struct PAD_VIB_LIST;
    struct PAD_DATA;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct PAD_INFO
    {
    public:
        u8 Be_flag;  // offset: 0x0
        u8 Rno;  // offset: 0x1
        s8 Pad_no;  // offset: 0x2
        u8 Kind;  // offset: 0x3
        u32 Ability;  // offset: 0x4
        u32 Input_attr;  // offset: 0x8
        u32 Socket_no;  // offset: 0xc
        s32 connectionType;  // offset: 0x10
    };
public:
    struct PAD_FREE
    {
    public:
        s8 Press_free;  // offset: 0x0
        u8 Trigger_free;  // offset: 0x1
        s16 Analog_free;  // offset: 0x2
        s16 Analog_cross_free;  // offset: 0x4
    };
public:
    struct PAD_REPEAT
    {
    public:
        u16 Start;  // offset: 0x0
        u16 Next2;  // offset: 0x2
        u16 Timer[24];  // offset: 0x4
    };
public:
    struct PAD_VIB_LIST
    {
    public:
        u8 Be_flag;  // offset: 0x0
        u8 reserved;  // offset: 0x1
        u16 Timer;  // offset: 0x2
        s32 MilliSec;  // offset: 0x4
        s32 Value;  // offset: 0x8
        s32 Add;  // offset: 0xc
    };
public:
    struct PAD_DATA
    {
    public:
        u32 On;  // offset: 0x0
        u32 Old;  // offset: 0x4
        u32 Trg;  // offset: 0x8
        u32 Rel;  // offset: 0xc
        u32 Chg;  // offset: 0x10
        u32 Rep;  // offset: 0x14
        s32 Rx;  // offset: 0x18
        s32 Ry;  // offset: 0x1c
        s32 Lx;  // offset: 0x20
        s32 Ly;  // offset: 0x24
        u8 Rz;  // offset: 0x28
        u8 Lz;  // offset: 0x29
        MtVector2 analogButton;  // offset: 0x30
        MtVector4 orientation;  // offset: 0x40
        MtVector3 acceleration;  // offset: 0x50
        MtVector3 angularVelocity;  // offset: 0x60
        MtPoint touch[2];  // offset: 0x70
        u32 touchNum;  // offset: 0x80
    };
public:
    struct PAD_VIB
    {
    public:
        s32 Vib_data[2];  // offset: 0x0
        u8 Vib_result;  // offset: 0x8
        u8 Vib_zero_count;  // offset: 0x9
        u8 Vib_retry_flag;  // offset: 0xa
        u8 Vib_set_timer;  // offset: 0xb
        sPad::PAD_VIB_LIST List_high[8];  // offset: 0xc
        sPad::PAD_VIB_LIST List_low[8];  // offset: 0x8c
    };
public:
    class Pad : public MtObject
    {
    public:
        enum REQUEST_VIB
        {
            REQUEST_NONE = 0,
            REQUEST_STOP = 1,
            REQUEST_IMMEDIATESTOP = 2,
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
        Pad();
        virtual ~Pad();
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        u32 getOn() const;
        u32 getOld() const;
        u32 getTrigger() const;
        u32 getRelease() const;
        u32 getChange() const;
        u32 getRepeat() const;
        s32 getStickLX() const;
        s32 getStickRX() const;
        s32 getStickLY() const;
        s32 getStickRY() const;
        s32 getTriggerL() const;
        s32 getTriggerR() const;
        u8 getAnalogButtonL2() const;
        u8 getAnalogButtonR2() const;
        u16 getTouchData1X() const;
        u16 getTouchData1Y() const;
        u16 getTouchData2X() const;
        u16 getTouchData2Y() const;
        s32 getSensorAccX() const;
        s32 getSensorAccY() const;
        s32 getSensorAccZ() const;
        s32 getSensorGX() const;
        s32 getSensorGY() const;
        s32 getSensorGZ() const;
        s32 getSensorOX() const;
        s32 getSensorOY() const;
        s32 getSensorOZ() const;
        s32 getSensorOW() const;
        u32 getAbility() const;
        u32 getKind() const;
        u32 getSocketNo() const;
        u32 getPadNo() const;
        void setInputAttr(u32);
        u32 getInputAttr() const;
        s16 getAnalogFree() const;
        s16 getAnalogCrossFree() const;
        s8 getPressFree() const;
        u8 getTriggerFree() const;
        void setAnalogFree(s16);
        void setAnalogCrossFree(s16);
        void setPressFree(s8);
        void setTriggerFree(u8);
        void setVibLow(u16 start_value, u16 end_value, u16 time);
        void setVibHigh(u16 start_value, u16 end_value, u16 time);
        void clearVibList();
        void setVibValue(u16, u16, u16);
        void vibLow();
        void vibHigh();
        void stopVib();
        void immediateStopVib(bool bclearVibList);
        void close();
        void detect();
    protected:
        u16 getRepeatStart() const;
        void setRepeatStart(u16 n);
        u16 getRepeatTime() const;
        void setRepeatTime(u16 n);
        void setVibList(sPad::PAD_VIB_LIST* pList_top, u16 start_value, u16 end_value, u16 time);
        void clearPad();
        void initData();
        void initVib();
        void updateRepeat();
        bool readPad();
    public:
        sPad::PAD_INFO Info;  // offset: 0x8
        sPad::PAD_FREE Free;  // offset: 0x1c
        sPad::PAD_REPEAT Repeat;  // offset: 0x22
        sPad::PAD_VIB Vib;  // offset: 0x58
        sPad::PAD_DATA Data;  // offset: 0x170
    protected:
        bool mTriggerVibLow;  // offset: 0x200
        bool mTriggerVibHigh;  // offset: 0x201
        u16 mVibStartValue;  // offset: 0x202
        u16 mVibEndValue;  // offset: 0x204
        u16 mVibTime;  // offset: 0x206
        u8 mRequestVib;  // offset: 0x208
    public:
        static MyDTI DTI;
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
    sPad(u32 PlatformAttribute);
    virtual ~sPad();
    virtual void move();  // vtable slot 7
    void setRepeat(u32 no);
    void setRepeat(u32 no, u32 start_time, u32 next_time);
    static sPad* getInstance();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    void setActive(bool);
    bool isActive() const;
    const Pad& getPad(u32) const;
    Pad& getPad(u32 pad_no);
    const Pad* getPadPointer(u32);
    u32 getOn(u32 pad_no) const;
    u32 getOld(u32 pad_no) const;
    u32 getTrigger(u32 pad_no) const;
    u32 getRelease(u32 pad_no) const;
    u32 getChange(u32 pad_no) const;
    u32 getRepeat(u32 pad_no) const;
    s32 getStickLX(u32 pad_no) const;
    s32 getStickLY(u32 pad_no) const;
    s32 getStickRX(u32 pad_no) const;
    s32 getStickRY(u32 pad_no) const;
    s32 getTriggerL(u32) const;
    s32 getTriggerR(u32) const;
    u8 getAnalogButtonL2(u32) const;
    u8 getAnalogButtonR2(u32) const;
    u16 getTouchData1X(u32) const;
    u16 getTouchData1Y(u32) const;
    u16 getTouchData2X(u32) const;
    u16 getTouchData2Y(u32) const;
    s32 getSensorAccX(u32) const;
    s32 getSensorAccY(u32) const;
    s32 getSensorAccZ(u32) const;
    s32 getSensorGX(u32) const;
    s32 getSensorGY(u32) const;
    s32 getSensorGZ(u32) const;
    s32 getSensorOX(u32) const;
    s32 getSensorOY(u32) const;
    s32 getSensorOZ(u32) const;
    s32 getSensorOW(u32) const;
    s32 getConnectionType(u32) const;
    bool isRemotePlay(u32 user_no);
    void ResetPadOrientation(u32 pad_no);
    void SetPadLightBar(u32 pad_no, MtColor color);
    void ResetPadLightBar(u32 pad_no);
    MtSize getTouchPanelSize(u32 pad_no);
    void setMotionSensorState(u32 pad_no, bool f);
    void SetAngularVelocityDeadbandState(u32 pad_no, bool f);
    void SetTiltCorrectionState(u32 pad_no, bool f);
    bool isPhysical(u32 padno) const;
    bool open(u32 pad_no, u32 input_attr);
    void setAnalogOn(u32);
    void setAnalogOff(u32);
    void setVibOn(u32 padno);
    void setVibOff(u32 padno);
    void setPressOn(u32);
    void setPressOff(u32);
    void setAnalogOnAll();
    void setAnalogOffAll();
    void setVibOnAll();
    void setVibOffAll();
    void setPressOnAll();
    void setPressOffAll();
    void setInputAttr(u32, u32);
    u32 getInputAttr(u32) const;
    u32 getAbility(u32) const;
    void setAnalogFree(u32, u8);
    void setAnalogCrossFree(u32, u8);
    void setPressFree(u32, u8);
    void setTriggerFree(u32, u8);
    void setPadRepeatDefault(u32 st, u32 nx);
    void setVibLow(u32, u16, u16, u16);
    void setVibHigh(u32, u16, u16, u16);
    void clearVibList(u32 no);
    void stopVib();
    void immediateStopVib(bool bclearVibList);
    u32 getDecideButton() const;
    u32 getCancelButton() const;
protected:
    bool initPS4Pad(Pad* pPadWk);
    bool initPS4PadSpec(Pad* pPadWk);
    void cnvPS4Pad(Pad* pPadWk, ScePadData* read_data);
    void cnvPS4PadForTVRemoteControl(Pad* pPadWk, ScePadData* read_data);
    bool isPadConnected(s32 user_no, PAD_PORT_TYPE type);
    bool isSystemIntercepted(s32 user_no, PAD_PORT_TYPE type);
    bool openSpecPad(u32 pad_no, u32 input_attr);
    bool openTVRemoteControl(u32 input_attr);
    void moveVib(Pad* pPadWk, u32 PadNo);
    u32 calcVibList(PAD_VIB_LIST* pList_top);
public:
    virtual void clearInputData();  // vtable slot 10
protected:
    bool mActive;  // offset: 0x11
    u64 mPrevTimer;  // offset: 0x18
    u32 mDeltaTime;  // offset: 0x20
    u32 mSysRepeadStDefault;  // offset: 0x24
    u32 mSysRepeadNxDefault;  // offset: 0x28
    Pad mPad[4];  // offset: 0x30
    Pad mPadSpec[4];  // offset: 0x870
    Pad mPadSysRemoteControl;  // offset: 0x10b0
    u32 mDecideButton;  // offset: 0x12c0
    u32 mCancelButton;  // offset: 0x12c4
public:
    static const u32 RNO_INIT = 0;
    static const u32 RNO_READ = 1;
    static const u32 INPUT_ATTR_ANALOG_OFF = 1;
    static const u32 INPUT_ATTR_VIB_OFF = 2;
    static const u32 INPUT_ATTR_PRESS_OFF = 4;
    static const u32 INPUT_ATTR_AUTO_DETECT = 8;
    static const u32 ABILITY_ANALOG = 1;
    static const u32 ABILITY_VIB = 2;
    static const u32 ABILITY_PRESS = 4;
    static const u32 ABILITY_FFB = 8;
    static const u32 ABILITY_WIRELESS = 16;
    static const u32 ABILITY_VOICE = 32;
    static const u32 ABILITY_PMD = 64;
    static const u32 ABILITY_SENSOR = 128;
    static const u32 ABILITY_HP_STICK = 256;
    static const u32 ABILITY_TOUCHPANEL = 512;
    static const u32 Select = 1;
    static const u32 LS = 2;
    static const u32 RS = 4;
    static const u32 Start = 8;
    static const u32 Lup = 16;
    static const u32 Lright = 32;
    static const u32 Ldown = 64;
    static const u32 Lleft = 128;
    static const u32 LB = 256;
    static const u32 RB = 512;
    static const u32 LT = 1024;
    static const u32 RT = 2048;
    static const u32 Rup = 4096;
    static const u32 Rright = 8192;
    static const u32 Rdown = 16384;
    static const u32 Rleft = 32768;
    static const u32 ALup = 65536;
    static const u32 ALright = 131072;
    static const u32 ALdown = 262144;
    static const u32 ALleft = 524288;
    static const u32 ARup = 1048576;
    static const u32 ARright = 2097152;
    static const u32 ARdown = 4194304;
    static const u32 ARleft = 8388608;
    static const u32 Touch = 16777216;
    static const u32 ELup = 65552;
    static const u32 ELright = 131104;
    static const u32 ELdown = 262208;
    static const u32 ELleft = 524416;
    static MyDTI DTI;
protected:
    static sPad* mpInstance;
};

// Inline, no code of its own: checked where it is inlined.
inline sPad* sPad::getInstance() {
    return ::sPad::mpInstance;
}

// Inline, no code of its own: checked where it is inlined.
inline bool sPad::isActive() const {
    return this->mActive;
}
