#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "cKeyCustom.h"
#include "../shared/cSystem.h"
#include "../shared/nHuman.h"
#include "../shared/nKeyCustom.h"
#include "sKeyboard.h"
#include "sMouse.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtObject;
class MtPropertyList;
class MtString;
class MtVector2;
class MtVector3;
class cArcLoaderBase;
class cKeyCustomManager;
class rKeyCustomParam;

// Declarations
class sInputManager;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using TICKET = cArcLoaderBase*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class sInputManager : public cSystem
{
public:
    class MyDTI;
    struct header;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct header
    {
    public:
        u32 magic;  // offset: 0x0
        u32 version;  // offset: 0x4
        u16 settingNum;  // offset: 0x8
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
    sInputManager();
    virtual ~sInputManager();
    static sInputManager* getInstance();
    virtual void reset();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void loadResource();
    void releaseResource();
protected:
    void init();
    void main();
public:
    u32 getInputMode();
    void setInputMode(u32 mode);
private:
    bool checkDisableInputGame(nKeyCustom::KB_CUSTOM kb);
public:
    void setDisableInputGame(bool Disable);
    bool isDisableInputGame() const;
    void setDisableInputGameByPauseMenu(bool Disable);
    bool isDisableInputGameByPauseMenu() const;
    bool isConnectPad();
    bool isConnectKeyboard();
    bool isConnectMouse();
    u32 getPadId();
    bool isValidPad();
    bool isValidKeyboard();
    bool isValidMouse();
    void setJobId(nHuman::JOB_ENUM job);
    bool isChatMode();
private:
    u32 isCtrlKeyOn(nKeyCustom::KB_CUSTOM kb);
    u32 isShiftKeyOn(nKeyCustom::KB_CUSTOM kb);
    u32 isAltKeyOn(nKeyCustom::KB_CUSTOM kb);
    u32 isLBKeyOn(nKeyCustom::KB_CUSTOM kb, u32 padId);
    u32 isLTKeyOn(nKeyCustom::KB_CUSTOM kb, u32 padId);
    u32 isLSKeyOn(nKeyCustom::KB_CUSTOM kb, u32 padId);
    u32 isRBKeyOn(nKeyCustom::KB_CUSTOM kb, u32 padId);
    u32 isRTKeyOn(nKeyCustom::KB_CUSTOM kb, u32 padId);
    u32 isRSKeyOn(nKeyCustom::KB_CUSTOM kb, u32 padId);
    bool checkModifierKeyKbm(nKeyCustom::KB_CUSTOM kb, nKeyCustom::MODE_TYPE mode);
    bool checkModifierKeyPad(nKeyCustom::KB_CUSTOM kb, nKeyCustom::MODE_TYPE mode, u32 padId);
    bool checkModifierKeyPad2(nKeyCustom::KB_CUSTOM kb, nKeyCustom::MODE_TYPE mode, u32 padId);
public:
    bool isCustomKeyToggleSetting(nKeyCustom::KB_CUSTOM kb);
    s32 getToggleSeesawKeyIndex(u32 no);
    void setChangeHoldBowKey(u32 key);
    const MtString& getCustomSettingName(u32 no) const;
    bool getCustomKeySetting(nKeyCustom::KB_CUSTOM kb, u32& key, u32& modifier);
    void getCustomPadSetting(nKeyCustom::KB_CUSTOM kb, u32& pad, u32& modifier);
    void getCustomPadSetting2(nKeyCustom::KB_CUSTOM kb, u32& pad, u32& modifier);
    u32 getCustomKeyOn(nKeyCustom::KB_CUSTOM kb, u32 padId);
    u32 getCustomKeyOld(nKeyCustom::KB_CUSTOM, u32);
    u32 getCustomKeyTrigger(nKeyCustom::KB_CUSTOM kb, u32 padId);
    u32 getCustomKeyRelease(nKeyCustom::KB_CUSTOM kb, u32 padId);
    u32 getCustomKeyChange(nKeyCustom::KB_CUSTOM, u32);
    u32 getCustomKeyRepeat(nKeyCustom::KB_CUSTOM kb, u32 padId);
    u32 getDefaultKeyOn(nKeyCustom::KB_CUSTOM, u32);
    u32 getDefaultKeyOld(nKeyCustom::KB_CUSTOM, u32);
    u32 getDefaultKeyTrigger(nKeyCustom::KB_CUSTOM kb, u32 padId);
    u32 getDefaultKeyRelease(nKeyCustom::KB_CUSTOM, u32);
    u32 getDefaultKeyChange(nKeyCustom::KB_CUSTOM, u32);
    u32 getDefaultKeyRepeat(nKeyCustom::KB_CUSTOM, u32);
    u32 getSystemKeyOn(nKeyCustom::KB_CUSTOM, u32);
    u32 getSystemKeyOld(nKeyCustom::KB_CUSTOM, u32);
    u32 getSystemKeyTrigger(nKeyCustom::KB_CUSTOM kb, u32 padId);
    u32 getSystemKeyRelease(nKeyCustom::KB_CUSTOM, u32);
    u32 getSystemKeyChange(nKeyCustom::KB_CUSTOM, u32);
    u32 getSystemKeyRepeat(nKeyCustom::KB_CUSTOM kb, u32 padId);
    MT_CTSTR getCustomKeyTagParam(nKeyCustom::KB_CUSTOM keyCustom) const;
    nKeyCustom::KB_CUSTOM getCustomKeyIdFromTagParam(MT_CTSTR tagParam) const;
    u32 getCustomKeySkillTrigger(nKeyCustom::KB_CUSTOM kb);
    u32 getCustomKeySkillOn(nKeyCustom::KB_CUSTOM kb);
    u32 getCustomKeySkillDerive(nKeyCustom::KB_CUSTOM kb, nKeyCustom::GET_TYPE type, u32 padId);
    f32 getAnlgInfoLx() const;
    f32 getAnlgInfoLy() const;
    f32 getAnlgInfoRx() const;
    f32 getAnlgInfoRy() const;
    f32 getPressInfoR2() const;
    f32 getPressInfoL2() const;
    s32 getMouseAxisX();
    s32 getMouseAxisY();
    s32 getMouseAxisZ();
    bool getMouseTrgLeft();
    bool getMouseTrgRight();
    MtVector3 getMousePos();
    MtVector2 getMouseMove();
    void clearCustomKeyToggle();
    void clearMouseWheelSeesawSwitchIndex();
    void changeMouseWheelSeesawSwitchIndex();
    void writeData(MtDataWriter& w, u32 SaveVersion);
    void readData(MtDataReader& r, u32 CurrentVersion, u32 LoadVersion);
    void editApply(cKeyCustomManager& cmn, u32 categoryNo);
    void editCancel(cKeyCustomManager& cmn, u32 categoryNo);
    bool editCompare(cKeyCustomManager& cmn, u32 categoryNo, bool isCheckName);
    void editDefault(cKeyCustomManager& cmn);
    void editCancel(cKeyCustomManager& cmn, u32 categoryNo, nKeyCustom::KB_CUSTOM kb);
    void editDefault(cKeyCustomManager& cmn, nKeyCustom::KB_CUSTOM kb);
    bool editCompare(cKeyCustomManager& cmn, u32 categoryNo, nKeyCustom::KB_CUSTOM kb);
    bool editCompareDefault(cKeyCustomManager& cmn, nKeyCustom::KB_CUSTOM kb);
    void setSoloExcludeModifierKey(cKeyCustomManager& tmp);
private:
    void checkDetectInputDevice();
public:
    bool isCtrl(nKeyCustom::KB_CUSTOM kb, nKeyCustom::MODE_TYPE mode);
    bool isShift(nKeyCustom::KB_CUSTOM kb, nKeyCustom::MODE_TYPE mode);
    bool isAlt(nKeyCustom::KB_CUSTOM kb, nKeyCustom::MODE_TYPE mode);
    bool isTab(nKeyCustom::KB_CUSTOM, nKeyCustom::MODE_TYPE);
    bool isToggleSetting(nKeyCustom::KB_CUSTOM kb, nKeyCustom::MODE_TYPE mode);
    bool isToggleOn(nKeyCustom::KB_CUSTOM, nKeyCustom::MODE_TYPE);
    bool isToggleOff(nKeyCustom::KB_CUSTOM, nKeyCustom::MODE_TYPE);
    bool isSoloExcludeModifierKey(nKeyCustom::KB_CUSTOM kb, nKeyCustom::MODE_TYPE mode);
    bool isKeySettingEmpty(nKeyCustom::KB_CUSTOM kb);
    bool isPadSettingEmpty(nKeyCustom::KB_CUSTOM);
    bool isValidKey(nKeyCustom::KB_CUSTOM kb, nKeyCustom::MODE_TYPE mode);
    sKeyboard::KB_TYPE getCustomKey(nKeyCustom::KB_CUSTOM kb);
    sKeyboard::KB_TYPE getDefaultKey(nKeyCustom::KB_CUSTOM kb);
    bool isValidBtn(nKeyCustom::KB_CUSTOM kb, nKeyCustom::MODE_TYPE mode);
    sMouse::BUTTON getCustomBtn(nKeyCustom::KB_CUSTOM kb);
    sMouse::BUTTON getDefaultBtn(nKeyCustom::KB_CUSTOM kb);
    bool isLB(nKeyCustom::KB_CUSTOM kb, nKeyCustom::MODE_TYPE mode);
    bool isLT(nKeyCustom::KB_CUSTOM kb, nKeyCustom::MODE_TYPE mode);
    bool isLS(nKeyCustom::KB_CUSTOM kb, nKeyCustom::MODE_TYPE mode);
    bool isRB(nKeyCustom::KB_CUSTOM kb, nKeyCustom::MODE_TYPE mode);
    bool isRT(nKeyCustom::KB_CUSTOM kb, nKeyCustom::MODE_TYPE mode);
    bool isRS(nKeyCustom::KB_CUSTOM kb, nKeyCustom::MODE_TYPE mode);
    bool isLB2(nKeyCustom::KB_CUSTOM kb, nKeyCustom::MODE_TYPE mode);
    bool isLT2(nKeyCustom::KB_CUSTOM kb, nKeyCustom::MODE_TYPE mode);
    bool isLS2(nKeyCustom::KB_CUSTOM kb, nKeyCustom::MODE_TYPE mode);
    bool isRB2(nKeyCustom::KB_CUSTOM kb, nKeyCustom::MODE_TYPE mode);
    bool isRT2(nKeyCustom::KB_CUSTOM kb, nKeyCustom::MODE_TYPE mode);
    bool isRS2(nKeyCustom::KB_CUSTOM kb, nKeyCustom::MODE_TYPE mode);
    bool isKbmBothMode(nKeyCustom::KB_CUSTOM kb);
    bool isPadBothMode(nKeyCustom::KB_CUSTOM kb);
    bool isKbmNoChange(nKeyCustom::KB_CUSTOM kb);
    bool isPadNoChange(nKeyCustom::KB_CUSTOM);
    bool isKbmNoBlank(nKeyCustom::KB_CUSTOM);
    bool isPadNoBlank(nKeyCustom::KB_CUSTOM);
    bool isKbmNo2Blank(nKeyCustom::KB_CUSTOM);
    bool isValidPad(nKeyCustom::KB_CUSTOM kb, nKeyCustom::MODE_TYPE mode);
    u32 getCustomPad(nKeyCustom::KB_CUSTOM kb);
    u32 getDefaultPad(nKeyCustom::KB_CUSTOM kb);
    bool isValidPad2(nKeyCustom::KB_CUSTOM kb, nKeyCustom::MODE_TYPE mode);
    u32 getCustomPad2(nKeyCustom::KB_CUSTOM kb);
    u32 getDefaultPad2(nKeyCustom::KB_CUSTOM kb);
    nKeyCustom::OVERLAP_GROUP getOverlapGroup(nKeyCustom::KB_CUSTOM kb);
    bool isOverlap(nKeyCustom::KB_CUSTOM, nKeyCustom::MODE_TYPE);
    bool isKbmAnyTrigger();
    bool isKbmAnyRelease();
    bool isPadAnyTrigger();
    bool isPadAnyRelease();
private:
    void setKbmInputData(cKeyCustomManager& tmp, u32 categoryNo, u32 index);
    void setPadInputData(cKeyCustomManager& tmp, u32 categoryNo, u32 index);
    void setKbmBlank(cKeyCustomManager& tmp, u32 categoryNo, u32 index);
    void setKbmRestore(cKeyCustomManager& tmp, u32 categoryNo, u32 index);
    void setKbmDefault(cKeyCustomManager& tmp, u32 categoryNo, u32 index);
    void setPadBlank(cKeyCustomManager& tmp, u32 categoryNo, u32 index);
    void setPadRestore(cKeyCustomManager& tmp, u32 categoryNo, u32 index);
    void setPadDefault(cKeyCustomManager& tmp, u32 categoryNo, u32 index);
    u32 getKeyCommon(nKeyCustom::KB_CUSTOM kb, nKeyCustom::GET_TYPE type, nKeyCustom::MODE_TYPE mode, u32 padId);
    rKeyCustomParam* getResourceCommonPresetKey();
    rKeyCustomParam* getResourceJobPresetKey(s32);
    void setPreset(u32);
private:
    u8 mRno0;  // offset: 0x11
    u8 mRno1;  // offset: 0x12
    u8 mRno2;  // offset: 0x13
    u8 mRno3;  // offset: 0x14
    bool mIsChatMode;  // offset: 0x15
    bool mArcLoadFinish;  // offset: 0x16
    bool mNoInputDevice;  // offset: 0x17
    f32 mNoDeviceTimer;  // offset: 0x18
    s32 mInputMode;  // offset: 0x1c
    s32 mInputModeOld;  // offset: 0x20
    s32 mCustomJobId;  // offset: 0x24
    sKeyboard::TYPE mKeyboardCurrentType;  // offset: 0x28
    sMouse::TYPE mMouseCurrentType;  // offset: 0x2c
    MtVector3 mMousePos;  // offset: 0x30
    MtVector2 mMouseMove;  // offset: 0x40
    header mHeader;  // offset: 0x48
    u16 mCategoryNo;  // offset: 0x54
    cKeyCustomManager mCommonKeyCustomManager[3];  // offset: 0x58
    cKeyCustomManager mCommonKeyDefaultManager;  // offset: 0xe8
    bool mToggle[130];  // offset: 0x118
    s32 mMouseWheelSeesawSwitchIndex[2];  // offset: 0x19c
    u32 mChangeHoldBowKey;  // offset: 0x1a4
    TICKET mArcTicketPresetKey;  // offset: 0x1a8
    rKeyCustomParam* mprCommonPresetKey;  // offset: 0x1b0
    rKeyCustomParam* mprJobPresetKey[10];  // offset: 0x1b8
    bool mDisableInputGame;  // offset: 0x208
    bool mDisableInputGameByPauseMenu;  // offset: 0x209
public:
    static MyDTI DTI;
    static const u32 MAGIC = 5063499;
private:
    static sInputManager* mpInstance;
};

// Inline, no code of its own: checked where it is inlined.
inline sInputManager* sInputManager::getInstance() {
    return ::sInputManager::mpInstance;
}
