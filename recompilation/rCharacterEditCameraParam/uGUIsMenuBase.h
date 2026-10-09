#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/nDDOUtility.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector2;
class cControl;
class cGUIInstAnimation;
class cGUIInstNull;
class uGUISystemMsg;

// Declarations
class uGUIsMenuBase;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIsMenuBase : public uGUIBase
{
public:
    enum EXIT_TYPE
    {
        EXIT_TYPE_NONE = 0,
        EXIT_TYPE_OK = 1,
        EXIT_TYPE_CANCEL = 2,
    };
public:
    class MyDTI;
    class cPulldown;
    class cVar;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cPulldown : public MtObject
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
        cPulldown();
    public:
        uGUIBase::cDupliInstNull mInst;  // offset: 0x8
        uGUIBase::cReferenceUIPullDown mPulldown;  // offset: 0x30
        static MyDTI DTI;
    };
public:
    class cVar
    {
    public:
        cVar();
        void set(s32*, u32);
        s32& get(u32);
    private:
        s32* mpPtr;  // offset: 0x0
        u32 mNum;  // offset: 0x8
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
    uGUIsMenuBase(u32 initFlags, bool isChatSubMenu);
    virtual ~uGUIsMenuBase();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    s32& getRno(u32);
    s32& getCursor(u32);
    virtual bool changeFlow(u32 sw, bool force);  // vtable slot 91
    virtual bool reserveFlow(u32 sw, bool force);  // vtable slot 92
    // Address: 0x01afb110 - 0x01afb111 (1 bytes)
    virtual void updateInit() {}  // vtable slot 93
    virtual void updateWaiting();  // vtable slot 94
    // Address: 0x01ae02b0 - 0x01ae02b1 (1 bytes)
    virtual void execChangeFlow() {}  // vtable slot 95
    virtual void move();  // vtable slot 9
    void setCurrentFrame(cGUIInstAnimation* pObj, f32 frame, bool fix);
    bool moveEventPullDown();
    s32 isWakeupPullDown();
    void setAllFocusOffForReferenceUI();
    bool setPointerPosFromFocusReferenceUI();
    bool setPointerPosFromFocusReferenceUI(u32 prio);
    void setFocusCtrl(cControl*, bool);
    void resetItemNum(cControl* pCtrl, s32 num, s32 pos);
    void setCtrlFocus(cControl*, bool);
    EXIT_TYPE getExitType();
    void addSMenuObj(MtObject* pObj);
protected:
    void setPointerPosReq(const MtVector2& pos);
    void setPointerPosReq(const MtVector2& pos, u32 uPrio, bool isMove);
    void setPointerPosReqIgnoreZeroPos(const MtVector2& pos, u32 uPrio, bool isMove);
    bool isSizeOverCheckMtArray(u32, MtArray*);
protected:
    bool mIsDisablePointerPosReq;  // offset: 0x8c8
    MtTypedArray<cPulldown> mPulldownArray;  // offset: 0x8d0
    u32 mSwitch;  // offset: 0x8f0
    u32 mVAR_sw;  // offset: 0x8f4
    u32 mVAR_change_flow;  // offset: 0x8f8
    EXIT_TYPE mExitType;  // offset: 0x8fc
    nDDOUtility::cArray<MtObject*, 4> mpSMenuObjs;  // offset: 0x900
private:
    cVar mVarCursor;  // offset: 0x920
    cVar mVarRno;  // offset: 0x930
    u32 mReserveSwitch;  // offset: 0x940
    bool mIsReserveForce;  // offset: 0x944
    s32 mMoveNum;  // offset: 0x948
    uGUISystemMsg* mpGUISystemMsg;  // offset: 0x950
public:
    static MyDTI DTI;
};
