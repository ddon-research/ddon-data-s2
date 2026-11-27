#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../XFramework/cSystem.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class cInputTextKeyboardHook;
namespace nIMEPS4 { class CandidateDispInfo; }
namespace nInputText { struct CandidateList; }

namespace nIME {
    enum CHARACTER_ATTRIBUTE
    {
        CHARACTER_ATTRIBUTE_CONFIRMED = 0,
        CHARACTER_ATTRIBUTE_SELECTED = 1,
        CHARACTER_ATTRIBUTE_BEFORE_CONVERT = 2,
        CHARACTER_ATTRIBUTE_CONVERTING = 3,
    };
}  // namespace nIME

namespace nIME {
    enum INPUT_EVENT_ID
    {
        INPUT_EVENT_ID_NONE = 0,
        INPUT_EVENT_ID_CONFIRMED = 1,
        INPUT_EVENT_ID_PUSHED_SPACE = 2,
        INPUT_EVENT_ID_PUSHED_ENTER = 3,
        INPUT_EVENT_ID_PUSHED_ESCAPE = 4,
        INPUT_EVENT_ID_PUSHED_BACK_SPACE = 5,
        INPUT_EVENT_ID_PUSHED_LEFT_ARROW = 6,
        INPUT_EVENT_ID_PUSHED_RIGHT_ARROW = 7,
        INPUT_EVENT_ID_PUSHED_HOME = 8,
        INPUT_EVENT_ID_PUSHED_END = 9,
        INPUT_EVENT_ID_PUSHED_DELETE = 10,
        INPUT_EVENT_ID_PUSHED_IME_OFF = 11,
        INPUT_EVENT_ID_PUSHED_IME_ON = 12,
    };
}  // namespace nIME

// Declarations
namespace nIME { class CandidateDispInfo; }
namespace nIME { class InputEvent; }
namespace nIME { class InputInfo; }
class sIME;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_WCHAR = wchar_t;
using MT_CWSTR = const MT_WCHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

namespace nIME {
    class CandidateDispInfo
    {
        friend class nIMEPS4::CandidateDispInfo;
        friend struct nInputText::CandidateList;
    public:
        CandidateDispInfo();
        virtual ~CandidateDispInfo();
        virtual void clear();  // vtable slot 2
        void setListNum(u32 listNum);
        void setListSelectIndex(u32 listSelectIndex);
        virtual void setDispString(u32, MT_CWSTR) = 0;  // vtable slot 3
        virtual MT_CWSTR getDispString(u32) const = 0;  // vtable slot 4
        virtual u32 getDispNumMax() const = 0;  // vtable slot 5
        u32 getListNum() const;
        u32 getListSelectIndex() const;
        u32 getPageNum() const;
        u32 getDispPageIndex() const;
        u32 getDispStartIndex() const;
        u32 getDispIndex() const;
        u32 getDispNum() const;
    private:
        u32 mListNum;  // offset: 0x8
        u32 mListSelectIndex;  // offset: 0xc
    };
}  // namespace nIME

namespace nIME {
    class InputEvent
    {
        friend class ::sIME;
    public:
        InputEvent();
        void clear();
        void setId(nIME::INPUT_EVENT_ID id);
        nIME::INPUT_EVENT_ID getId() const;
        void setFlags(u32 flags);
        u32 getFlags() const;
        void setParam(nIME::INPUT_EVENT_ID id, u32 flags);
        bool isCtrl() const;
        bool isShift() const;
        bool isAlt() const;
        bool isMoveCaret() const;
    private:
        nIME::INPUT_EVENT_ID mId;  // offset: 0x0
        u32 mFlags;  // offset: 0x4
    };
}  // namespace nIME

namespace nIME {
    class InputInfo
    {
    public:
        InputInfo();
        virtual ~InputInfo();
        virtual void clear() = 0;  // vtable slot 2
        virtual u32 getCaretIndex() const = 0;  // vtable slot 3
        virtual nIME::CHARACTER_ATTRIBUTE getCharacterAttribute(u32) const = 0;  // vtable slot 4
    };
}  // namespace nIME

class sIME : public cSystem
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
    static sIME* getInstance();
    sIME();
    virtual ~sIME();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void move();  // vtable slot 7
    virtual bool start(MT_CWSTR initialString, cInputTextKeyboardHook* keyboardHook);  // vtable slot 10
    virtual void end();  // vtable slot 11
    bool isActive() const;
    const nIME::InputEvent& getInputEvent() const;
    virtual bool confirm();  // vtable slot 12
    virtual bool cancel();  // vtable slot 13
    virtual MT_CWSTR getInputString() const;  // vtable slot 14
    virtual MT_CWSTR getConfirmString() const;  // vtable slot 15
    virtual void clearConfirmString();  // vtable slot 16
    virtual const nIME::InputInfo& refInputInfo() const = 0;  // vtable slot 17
    virtual const nIME::CandidateDispInfo& refCandidateDispInfo() const = 0;  // vtable slot 18
protected:
    nIME::InputEvent mInputEvent;  // offset: 0x14
    bool mActive;  // offset: 0x1c
    cInputTextKeyboardHook* mKeyboardHook;  // offset: 0x20
public:
    static MyDTI DTI;
protected:
    static sIME* mpInstance;
};

inline u32 nIME::CandidateDispInfo::getListNum() const {
    return this->mListNum;
}

inline u32 nIME::CandidateDispInfo::getListSelectIndex() const {
    return this->mListSelectIndex;
}

inline void* sIME::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void sIME::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::sIME::DTI)->memFree(p_addr);
}
