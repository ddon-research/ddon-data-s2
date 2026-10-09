#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtString.h"
#include "../shared/cSystem.h"
#include "../shared/ime_types.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtString;
class MtUI;
struct SceImeEvent;
struct SceImeKeyboardInfo;
struct SceImeKeyboardParam;

// Declarations
class sKeyboard;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class sKeyboard : public cSystem
{
public:
    enum TYPE
    {
        TYPE_DEFAULT = 0,
        MAX_TYPE = 1,
    };
    enum KB_TYPE
    {
        KB_LBUTTON = 1,
        KB_RBUTTON = 2,
        KB_CANCEL = 3,
        KB_MBUTTON = 4,
        KB_XBUTTON1 = 5,
        KB_XBUTTON2 = 6,
        KB_BACK = 8,
        KB_TAB = 9,
        KB_CLEAR = 12,
        KB_RETURN = 13,
        KB_SHIFT = 16,
        KB_CONTROL = 17,
        KB_MENU = 18,
        KB_PAUSE = 19,
        KB_CAPITAL = 20,
        KB_KANA = 21,
        KB_JUNJA = 23,
        KB_FINAL = 24,
        KB_HANJA = 25,
        KB_ESCAPE = 27,
        KB_CONVERT = 28,
        KB_NONCONVERT = 29,
        KB_ACCEPT = 30,
        KB_MODECHANGE = 31,
        KB_SPACE = 32,
        KB_PRIOR = 33,
        KB_NEXT = 34,
        KB_END = 35,
        KB_HOME = 36,
        KB_LEFT = 37,
        KB_UP = 38,
        KB_RIGHT = 39,
        KB_DOWN = 40,
        KB_SELECT = 41,
        KB_PRINT = 42,
        KB_EXECUTE = 43,
        KB_SNAPSHOT = 44,
        KB_INSERT = 45,
        KB_DELETE = 46,
        KB_HELP = 47,
        KB_0 = 48,
        KB_1 = 49,
        KB_2 = 50,
        KB_3 = 51,
        KB_4 = 52,
        KB_5 = 53,
        KB_6 = 54,
        KB_7 = 55,
        KB_8 = 56,
        KB_9 = 57,
        KB_A = 65,
        KB_B = 66,
        KB_C = 67,
        KB_D = 68,
        KB_E = 69,
        KB_F = 70,
        KB_G = 71,
        KB_H = 72,
        KB_I = 73,
        KB_J = 74,
        KB_K = 75,
        KB_L = 76,
        KB_M = 77,
        KB_N = 78,
        KB_O = 79,
        KB_P = 80,
        KB_Q = 81,
        KB_R = 82,
        KB_S = 83,
        KB_T = 84,
        KB_U = 85,
        KB_V = 86,
        KB_W = 87,
        KB_X = 88,
        KB_Y = 89,
        KB_Z = 90,
        KB_LWIN = 91,
        KB_RWIN = 92,
        KB_APPS = 93,
        KB_SLEEP = 95,
        KB_NUMPAD0 = 96,
        KB_NUMPAD1 = 97,
        KB_NUMPAD2 = 98,
        KB_NUMPAD3 = 99,
        KB_NUMPAD4 = 100,
        KB_NUMPAD5 = 101,
        KB_NUMPAD6 = 102,
        KB_NUMPAD7 = 103,
        KB_NUMPAD8 = 104,
        KB_NUMPAD9 = 105,
        KB_MULTIPLY = 106,
        KB_ADD = 107,
        KB_SEPARATOR = 108,
        KB_SUBTRACT = 109,
        KB_DECIMAL = 110,
        KB_DIVIDE = 111,
        KB_F1 = 112,
        KB_F2 = 113,
        KB_F3 = 114,
        KB_F4 = 115,
        KB_F5 = 116,
        KB_F6 = 117,
        KB_F7 = 118,
        KB_F8 = 119,
        KB_F9 = 120,
        KB_F10 = 121,
        KB_F11 = 122,
        KB_F12 = 123,
        KB_F13 = 124,
        KB_F14 = 125,
        KB_F15 = 126,
        KB_F16 = 127,
        KB_F17 = 128,
        KB_F18 = 129,
        KB_F19 = 130,
        KB_F20 = 131,
        KB_F21 = 132,
        KB_F22 = 133,
        KB_F23 = 134,
        KB_F24 = 135,
        KB_NUMLOCK = 144,
        KB_SCROLL = 145,
        KB_LSHIFT = 160,
        KB_RSHIFT = 161,
        KB_LCONTROL = 162,
        KB_RCONTROL = 163,
        KB_LMENU = 164,
        KB_RMENU = 165,
        KB_OEM_1 = 186,
        KB_OEM_PLUS = 187,
        KB_OEM_COMMA = 188,
        KB_OEM_MINUS = 189,
        KB_OEM_PERIOD = 190,
        KB_OEM_2 = 191,
        KB_OEM_3 = 192,
        KB_OEM_4 = 219,
        KB_OEM_5 = 220,
        KB_OEM_6 = 221,
        KB_OEM_7 = 222,
        KB_OEM_8 = 223,
        KB_OEM_102 = 226,
    };
public:
    class MyDTI;
    struct STATE;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct STATE
    {
    public:
        u32 on[8];  // offset: 0x0
        u32 old[8];  // offset: 0x20
        u32 trg[8];  // offset: 0x40
        u32 release[8];  // offset: 0x60
        u32 change[8];  // offset: 0x80
        u32 rep[8];  // offset: 0xa0
        u64 rep_timer[256];  // offset: 0xc0
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
    sKeyboard();
    virtual ~sKeyboard();
    virtual void move();  // vtable slot 7
    static sKeyboard* getInstance();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    void setActive(bool v);
    bool isActive();
    void setRepeatTime(u32, u32);
    u32 getOn(u32 kb, TYPE type) const;
    u32 getOld(u32 kb, TYPE type) const;
    u32 getTrigger(u32 kb, TYPE type) const;
    u32 getRelease(u32 kb, TYPE type) const;
    u32 getChange(u32 kb, TYPE type) const;
    u32 getRepeat(u32 kb, TYPE type) const;
    MT_CTSTR getKeyName(u32 vk);
    TYPE getCurrentType();
    void clearKeyState();
    bool isKeyboardConnected();
    bool isSystemIntercepted();
protected:
    MtString getKeyStateName(u32* state);
    void updateState(STATE* pstate);
    static void keyboardEvent(void* arg, const SceImeEvent* e);
    void checkMouseState(u32 mouseButton, u32 keyboardButton);
protected:
    u8 mVKTable[256];  // offset: 0x11
    STATE mState[1];  // offset: 0x118
    u32 mRepeatStartTime;  // offset: 0x9d8
    u32 mRepeatTime;  // offset: 0x9dc
    MtString mKeyOn;  // offset: 0x9e0
    MtString mKeyOld;  // offset: 0x9e8
    MtString mKeyRelease;  // offset: 0x9f0
    MtString mKeyRep;  // offset: 0x9f8
    MtString mKeyTrg;  // offset: 0xa00
    MtString mKeyChange;  // offset: 0xa08
    bool mActive;  // offset: 0xa10
    bool mIsDisconnected;  // offset: 0xa11
    bool mTryConnection;  // offset: 0xa12
    bool mIsConnected;  // offset: 0xa13
    u32 mKeyState[8];  // offset: 0xa14
    SceImeKeyboardParam mKeyboardParam;  // offset: 0xa38
    SceImeKeyboardInfo mKeyboardInfo;  // offset: 0xa58
    bool mIsSystemIntercepted;  // offset: 0xa7c
public:
    static MyDTI DTI;
protected:
    static const u8 mKbAssign[];
    static const s32 KB_NO_ASSIGN = 0;
    static const s32 KB_KEY_NUM = 144;
    static sKeyboard* mpInstance;
};
