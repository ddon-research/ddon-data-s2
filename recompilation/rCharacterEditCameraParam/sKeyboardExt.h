#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "sKeyboard.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;

// Declarations
class sKeyboardExt;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class sKeyboardExt : public sKeyboard
{
public:
    enum KB_EX_TYPE
    {
        KB_EX_NOTHING = 0,
        KB_EX_LBUTTON = 1,
        KB_EX_RBUTTON = 2,
        KB_EX_CANCEL = 3,
        KB_EX_MBUTTON = 4,
        KB_EX_XBUTTON1 = 5,
        KB_EX_XBUTTON2 = 6,
        KB_EX_BACK = 8,
        KB_EX_TAB = 9,
        KB_EX_CLEAR = 12,
        KB_EX_RETURN = 13,
        KB_EX_SHIFT = 16,
        KB_EX_CONTROL = 17,
        KB_EX_MENU = 18,
        KB_EX_PAUSE = 19,
        KB_EX_CAPITAL = 20,
        KB_EX_KANA = 21,
        KB_EX_JUNJA = 23,
        KB_EX_FINAL = 24,
        KB_EX_HANJA = 25,
        KB_EX_ESCAPE = 27,
        KB_EX_CONVERT = 28,
        KB_EX_NONCONVERT = 29,
        KB_EX_ACCEPT = 30,
        KB_EX_MODECHANGE = 31,
        KB_EX_SPACE = 32,
        KB_EX_PRIOR = 33,
        KB_EX_NEXT = 34,
        KB_EX_END = 35,
        KB_EX_HOME = 36,
        KB_EX_LEFT = 37,
        KB_EX_UP = 38,
        KB_EX_RIGHT = 39,
        KB_EX_DOWN = 40,
        KB_EX_SELECT = 41,
        KB_EX_PRINT = 42,
        KB_EX_EXECUTE = 43,
        KB_EX_SNAPSHOT = 44,
        KB_EX_INSERT = 45,
        KB_EX_DELETE = 46,
        KB_EX_HELP = 47,
        KB_EX_0 = 48,
        KB_EX_1 = 49,
        KB_EX_2 = 50,
        KB_EX_3 = 51,
        KB_EX_4 = 52,
        KB_EX_5 = 53,
        KB_EX_6 = 54,
        KB_EX_7 = 55,
        KB_EX_8 = 56,
        KB_EX_9 = 57,
        KB_EX_A = 65,
        KB_EX_B = 66,
        KB_EX_C = 67,
        KB_EX_D = 68,
        KB_EX_E = 69,
        KB_EX_F = 70,
        KB_EX_G = 71,
        KB_EX_H = 72,
        KB_EX_I = 73,
        KB_EX_J = 74,
        KB_EX_K = 75,
        KB_EX_L = 76,
        KB_EX_M = 77,
        KB_EX_N = 78,
        KB_EX_O = 79,
        KB_EX_P = 80,
        KB_EX_Q = 81,
        KB_EX_R = 82,
        KB_EX_S = 83,
        KB_EX_T = 84,
        KB_EX_U = 85,
        KB_EX_V = 86,
        KB_EX_W = 87,
        KB_EX_X = 88,
        KB_EX_Y = 89,
        KB_EX_Z = 90,
        KB_EX_LWIN = 91,
        KB_EX_RWIN = 92,
        KB_EX_APPS = 93,
        KB_EX_SLEEP = 95,
        KB_EX_NUMPAD0 = 96,
        KB_EX_NUMPAD1 = 97,
        KB_EX_NUMPAD2 = 98,
        KB_EX_NUMPAD3 = 99,
        KB_EX_NUMPAD4 = 100,
        KB_EX_NUMPAD5 = 101,
        KB_EX_NUMPAD6 = 102,
        KB_EX_NUMPAD7 = 103,
        KB_EX_NUMPAD8 = 104,
        KB_EX_NUMPAD9 = 105,
        KB_EX_MULTIPLY = 106,
        KB_EX_ADD = 107,
        KB_EX_SEPARATOR = 108,
        KB_EX_SUBTRACT = 109,
        KB_EX_DECIMAL = 110,
        KB_EX_DIVIDE = 111,
        KB_EX_F1 = 112,
        KB_EX_F2 = 113,
        KB_EX_F3 = 114,
        KB_EX_F4 = 115,
        KB_EX_F5 = 116,
        KB_EX_F6 = 117,
        KB_EX_F7 = 118,
        KB_EX_F8 = 119,
        KB_EX_F9 = 120,
        KB_EX_F10 = 121,
        KB_EX_F11 = 122,
        KB_EX_F12 = 123,
        KB_EX_F13 = 124,
        KB_EX_F14 = 125,
        KB_EX_F15 = 126,
        KB_EX_F16 = 127,
        KB_EX_F17 = 128,
        KB_EX_F18 = 129,
        KB_EX_F19 = 130,
        KB_EX_F20 = 131,
        KB_EX_F21 = 132,
        KB_EX_F22 = 133,
        KB_EX_F23 = 134,
        KB_EX_F24 = 135,
        KB_EX_NUMLOCK = 144,
        KB_EX_SCROLL = 145,
        KB_EX_LSHIFT = 160,
        KB_EX_RSHIFT = 161,
        KB_EX_LCONTROL = 162,
        KB_EX_RCONTROL = 163,
        KB_EX_LMENU = 164,
        KB_EX_RMENU = 165,
        KB_EX_OEM_1 = 186,
        KB_EX_OEM_PLUS = 187,
        KB_EX_OEM_COMMA = 188,
        KB_EX_OEM_MINUS = 189,
        KB_EX_OEM_PERIOD = 190,
        KB_EX_OEM_2 = 191,
        KB_EX_OEM_3 = 192,
        KB_EX_OEM_4 = 219,
        KB_EX_OEM_5 = 220,
        KB_EX_OEM_6 = 221,
        KB_EX_OEM_7 = 222,
        KB_EX_OEM_8 = 223,
        KB_EX_OEM_102 = 226,
    };
public:
    class MyDTI;
    class cKeyArray;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cKeyArray : public MtObject
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
        cKeyArray();
        // Address: 0x01ac63e0 - 0x01ac63e1 (1 bytes)
        virtual ~cKeyArray() {}
        sKeyboardExt::cKeyArray& operator=(const sKeyboardExt::cKeyArray&);
        bool isAnyKey();
        sKeyboardExt::KB_EX_TYPE getInputKey();
        bool isInput(sKeyboard::KB_TYPE kb);
        void clearKey(sKeyboard::KB_TYPE);
    public:
        u32 mKey0;  // offset: 0x8
        u32 mKey1;  // offset: 0xc
        u32 mKey2;  // offset: 0x10
        u32 mKey3;  // offset: 0x14
        u32 mKey4;  // offset: 0x18
        u32 mKey5;  // offset: 0x1c
        u32 mKey6;  // offset: 0x20
        u32 mKey7;  // offset: 0x24
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
    sKeyboardExt();
    virtual ~sKeyboardExt();
    virtual void move();  // vtable slot 7
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    bool isKbGetOn();
    bool isConnect();
    bool isOnShift(sKeyboard::TYPE) const;
    bool isOnCtrl(sKeyboard::TYPE type) const;
    bool isOnAlt(sKeyboard::TYPE type) const;
    bool isOnModifierKey(sKeyboard::TYPE) const;
    bool isAnyTrigger(sKeyboard::TYPE type) const;
    bool isAnyRelease(sKeyboard::TYPE type) const;
    cKeyArray getOnKey(sKeyboard::TYPE type) const;
    cKeyArray getOldKey(sKeyboard::TYPE type) const;
    cKeyArray getReleaseKey(sKeyboard::TYPE type) const;
    void setKeyStateClearNum(u32 keyStateClearNum);
protected:
    void evChangeType();
protected:
    u32 mKeyStateClearNum;  // offset: 0xa80
public:
    static MyDTI DTI;
    static const u32 mKbHanjaIdx = 0;
    static const u32 mKbHanjaBit = 25;
    static const u32 mKbLButtonIdx = 0;
    static const u32 mKbLButtonBit = 1;
    static const u32 mKbRButtonIdx = 0;
    static const u32 mKbRButtonBit = 2;
    static const u32 mKbMButtonIdx = 0;
    static const u32 mKbMButtonBit = 4;
    static const u32 mKbXButton1Idx = 0;
    static const u32 mKbXButton1Bit = 5;
    static const u32 mKbXButton2Idx = 0;
    static const u32 mKbXButton2Bit = 6;
};

// Inline, no code of its own: checked where it is inlined.
inline sKeyboardExt::cKeyArray::cKeyArray() {
    this->mKey6 = static_cast<u32>(0);
    this->mKey7 = static_cast<u32>(0);
    this->mKey4 = static_cast<u32>(0);
    this->mKey5 = static_cast<u32>(0);
    this->mKey2 = static_cast<u32>(0);
    this->mKey3 = static_cast<u32>(0);
    this->mKey0 = static_cast<u32>(0);
    this->mKey1 = static_cast<u32>(0);
}
