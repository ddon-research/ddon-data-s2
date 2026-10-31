#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtPrimitive2D.h"
#include "nDDOUtility.h"
#include "nInputText.h"
#include "uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtRectF;
class MtSizeF;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class cGUIObjPolygon;
namespace nInputText { struct CandidateList; }
namespace nInputText { class cUnicodeString; }
class rGUI;

// Declarations
class uGUIPopCnvWnd;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIPopCnvWnd : public uGUIBase
{
public:
    class MyDTI;
    struct stCnvWndInst;
    struct stCnvWndObj;
    class cStrData;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stCnvWndInst
    {
    public:
        cGUIInstNull* null;  // offset: 0x0
        cGUIInstNull* null_all;  // offset: 0x8
        cGUIInstNull* null_list;  // offset: 0x10
        cGUIInstAnimation* txt;  // offset: 0x18
        cGUIInstAnimation* window;  // offset: 0x20
    };
public:
    struct stCnvWndObj
    {
    public:
        cGUIObjMessage* txt;  // offset: 0x0
        cGUIObjPolygon* cursor;  // offset: 0x8
        cGUIObjMessage* num;  // offset: 0x10
    };
public:
    class cStrData
    {
    public:
        using cStr = uGUIBase::cExGUIMessageObj<256>;
    public:
        cStrData();
        ~cStrData();
    public:
        uGUIBase::cDupliInstNull mInst;  // offset: 0x0
        cStr mStr;  // offset: 0x28
        cGUIInstNull* mpInst_list;  // offset: 0x150
        cGUIInstAnimation* mpInst_msgText;  // offset: 0x158
        cGUIObjMessage* mpObj_m_txt;  // offset: 0x160
        cGUIObjPolygon* mpObj_cursor;  // offset: 0x168
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
    uGUIPopCnvWnd();
    virtual ~uGUIPopCnvWnd();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void adjustScale();  // vtable slot 84
    void applyCandidateList(const nInputText::CandidateList& candidateList, const MtRectF& compositionRect, bool isDispCompositionRectSide);
private:
    void updateInit();
    void updateWait();
    void updateExit();
    void updateDisp();
    void updateWindowSize(f32 maxTextWidth, f32 dispNum, cGUIObjPolygon* objCursor);
    MtSizeF calcWindowSize() const;
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    stCnvWndInst mInst;  // offset: 0x8d0
    stCnvWndObj mObj;  // offset: 0x8f8
    nInputText::CandidateList mCandidateList;  // offset: 0x910
    nDDOUtility::cArray<cStrData, 36> mDupliStrs;  // offset: 0xd80
    uGUIBase::cAdjustableWindow mWindow;  // offset: 0x4140
    nInputText::cUnicodeString mUnicodeString;  // offset: 0x41e0
    MtRectF mCompositionRect;  // offset: 0x69e8
    bool mIsDispCompositionRectSide;  // offset: 0x69f8
    bool mIsVisible;  // offset: 0x69f9
public:
    static MyDTI DTI;
    static const u32 INPAGE_MAX = 36;
};
