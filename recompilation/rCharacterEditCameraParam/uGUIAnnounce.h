#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtString.h"
#include "../shared/sGUIExt.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjColorAdjust;
class cGUIObjMessage;
class rGUI;

// Declarations
class uGUIAnnounce;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIAnnounce : public uGUIBase
{
public:
    enum
    {
        TYPE_AUTO_END = 0,
        TYPE_ANY_KEY = 1,
        TYPE_INFINIT = 2,
        TYPE_NO_LEADER = 3,
        TYPE_RETRY = 4,
        TYPE_ENTRYBOARD_READY = 5,
        TYPE_ENTRYBOARD_DEPART = 6,
        TYPE_ENTRYBOARD_REENTRY = 7,
        TYPE_DISABLE_CONTENTS = 8,
        TYPE_NO_SITUATION = 9,
    };
    enum COLOR
    {
        COLOR_BLUE = 0,
        COLOR_RED = 1,
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
    uGUIAnnounce();
    virtual ~uGUIAnnounce();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void callbackAnimationEvent(u32 instanceID, u32 animationID, u32 eventNo);  // vtable slot 34
    void start(const sGUIExt::AnnounceString& text, u32 col, bool isAnalyze, s32 frame);
    void finish();
    void setType(u32 type);
    bool checkSameMsg(MT_CTSTR pMsg, MT_CTSTR pAnalyze0, MT_CTSTR pAnalyze1, u32 analyzeNum1, u32 analyzeNum2);
private:
    void updateInit();
    void updateWait();
    void updateKeyWait();
    void updateInfinit();
    void updateNoLeader();
    void updateEntryBoardReady();
    void updateEntryBoardDepart();
    void updateEntryBoardReentry();
    void updateDisableContents();
    void updateNoSituation();
    void updateEndWait();
    void updateExit();
    void adjustWindowSize();
    void adjustWindowColor();
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    cGUIInstNull* mpINST_Null_all;  // offset: 0x8d0
    cGUIInstAnimation* mpInstAnim;  // offset: 0x8d8
    cGUIObjMessage* mpObjMsg;  // offset: 0x8e0
    cGUIObjColorAdjust* mpObjColAdjWindow;  // offset: 0x8e8
    cGUIObjColorAdjust* mpObjColAdjText;  // offset: 0x8f0
    uGUIBase::cAdjustableWindow mWindowSizeCtrl;  // offset: 0x8f8
    sGUIExt::AnnounceString mText;  // offset: 0x998
    u32 mType;  // offset: 0xa9c
    u32 mColor;  // offset: 0xaa0
    f32 mFrame;  // offset: 0xaa4
    bool mIsStart;  // offset: 0xaa8
    bool mIsAnalyze;  // offset: 0xaa9
public:
    static MyDTI DTI;
private:
    static const s32 disp_frame = 90;
};
