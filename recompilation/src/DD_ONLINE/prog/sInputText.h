#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../XFramework/cSystem.h"
#include "nInputText.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class cInputTextKeyboardHook;
namespace nInputText { struct Context; }

// Declarations
class sInputText;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_WCHAR = wchar_t;
using MT_CWSTR = const MT_WCHAR*;
using MT_WSTR = MT_WCHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

class sInputText : public cSystem
{
public:
    enum MODE
    {
        MODE_NUMBER = 0,
        MODE_ASCII = 1,
        MODE_JAPANESE = 2,
    };
    enum STATE
    {
        STATE_NONE = 0,
        STATE_INPUT = 1,
        STATE_COMPLETE = 2,
        STATE_CANCEL = 4,
        STATE_COMPOSITION = 8,
        STATE_CANDIDATE = 16,
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
    static sInputText* GetInstance();
    sInputText();
    virtual ~sInputText();
    virtual void move();  // vtable slot 7
    virtual void reset() {}  // vtable slot 6
    virtual void createMenu(MtPropertyList& s) {}  // vtable slot 8
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual bool startInput(MT_CWSTR initText, u32 maxCharacterCount, MODE mode, bool isImeOn, bool isPassword, cInputTextKeyboardHook* keyboardHook);  // vtable slot 10
    virtual void endInput();  // vtable slot 11
    virtual void completeComposition();  // vtable slot 12
    virtual void cancelComposition();  // vtable slot 13
    virtual void forceBackupContext();  // vtable slot 14
    MT_CWSTR getInput() const;
    MT_WSTR getInput();
    MT_CTSTR getInputUTF8();
    u32 getCharCountMax() const;
    u32 getState() const;
    bool isBusy() const;
    bool isComplete() const;
    bool isCancel() const;
    bool isInputEnable() const;
    bool isCompositionEnable() const;
    bool isCandidateEnable() const;
    bool isImeAvailable() const;
    bool isImeOn() const;
    bool isPassword() const;
protected:
    bool isState(u32 state) const;
    void setState(u32 state, bool onoff);
    void updateDeltaTime();
    virtual u32 getCaretBlinkTime() const;  // vtable slot 15
    void updateCaret();
    void resetCaret();
    void setCursorToTop(bool IsShift);
    void setCursorToEnd(bool IsShift);
    bool processKeyEscape();
    bool processKeyEnter();
    bool processKeyBackspace();
    bool processKeyRightArrow(bool isShift);
    bool processKeyLeftArrow(bool isShift);
    bool processKeyHome(bool isShift);
    bool processKeyEnd(bool isShift);
    bool processKeyDelete();
protected:
    MODE mMode;  // offset: 0x14
    u32 mCharCountMax;  // offset: 0x18
    u64 mPrevTimer;  // offset: 0x20
    u32 mDeltaTime;  // offset: 0x28
    u32 mCaretBlinkTime;  // offset: 0x2c
    u32 mCaretTimer;  // offset: 0x30
    bool mCaretReset;  // offset: 0x34
    bool mIsPassword;  // offset: 0x35
    cInputTextKeyboardHook* mKeyboardHook;  // offset: 0x38
    nInputText::Context mContext;  // offset: 0x40
    nInputText::Context mContextBackup;  // offset: 0x5510
    nInputText::Context mContextDisp;  // offset: 0xa9e0
public:
    static MyDTI DTI;
protected:
    static sInputText* mpInstance;
};

inline void* sInputText::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline bool sInputText::isImeOn() const {
    return this->mContextBackup.mIsImeOn;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void sInputText::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::sInputText::DTI)->memFree(p_addr);
}
