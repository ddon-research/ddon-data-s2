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
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtDTI;
class MtObject;
class MtSize;
class MtString;
class MtVector2;
struct _CREDIT_WORK_;
class cControl;
class cGUIInstAnimation;
class cGUIObjMessage;
class cGUIObjTextureRef;
class rGUI;
class rGUIMessage;
class rSoundStreamRequest;
class rTexture;

// Declarations
class uGUICredit;

// Type aliases from DWARF
using CREDIT_WORK = _CREDIT_WORK_;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUICredit : public uGUIBase
{
public:
    enum
    {
        TYPE_FROMTITLE = 0,
        TYPE_FROMENDING = 1,
    };
    enum
    {
        INPUTEVENT_END = 66,
    };
public:
    class MyDTI;
    class cElement;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cElement : public MtObject
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
        cElement();
        virtual ~cElement();
    public:
        cGUIInstAnimation* mpInst;  // offset: 0x8
        cGUIObjMessage* mpObjMsg;  // offset: 0x10
        cGUIObjTextureRef* mpObjLogo;  // offset: 0x18
        CREDIT_WORK* mpCreditData;  // offset: 0x20
        u32 mCtrlPt;  // offset: 0x28
        u32 mLayout;  // offset: 0x2c
        s32 mLogoId;  // offset: 0x30
        MtSize mFontSize;  // offset: 0x38
        MtVector2 mPos;  // offset: 0x40
        MtColor mColor;  // offset: 0x48
        MtString mColTag;  // offset: 0x50
        MT_CHAR mIconRC;  // offset: 0x58
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
    uGUICredit();
    virtual ~uGUICredit();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    void setCreditType(u32 uType);
    void setCreditTime(f32);
    void setEndWaitTime(f32);
private:
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void updateInit();
    void updateWait();
    void updateFadeOut();
    void updateExit();
    void updateDisp();
    u32 evCtrlSkip(cControl::Message* msg);
protected:
    // Address: 0x01af05d0 - 0x01af05d1 (1 bytes)
    virtual void adjustScale() {}  // vtable slot 84
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    rGUIMessage* mpGUIMsg;  // offset: 0x8d0
    MtTypedArray<cElement> mElem;  // offset: 0x8d8
    cGUIInstAnimation* mpInstDupli[96];  // offset: 0x8f8
    cGUIObjMessage* mpObjDupli[96];  // offset: 0xbf8
    cGUIObjMessage* mpObj2Dupli[96];  // offset: 0xef8
    cGUIObjMessage* mpObj3Dupli[96];  // offset: 0x11f8
    cGUIObjTextureRef* mpObjLogoDupli[96];  // offset: 0x14f8
    rTexture* mpTexLogo[4];  // offset: 0x17f8
    rSoundStreamRequest* mpSoundRes;  // offset: 0x1818
    cControl* mpCtrl;  // offset: 0x1820
    f32 mPosYInit;  // offset: 0x1828
    f32 mPosYLimit;  // offset: 0x182c
    f32 mMoveY;  // offset: 0x1830
    f32 mSpdRate;  // offset: 0x1834
    f32 mCreditTime;  // offset: 0x1838
    f32 mEndWaitTime;  // offset: 0x183c
    u32 mCreditType;  // offset: 0x1840
    bool mIsReqSkip;  // offset: 0x1844
    bool mIsAprilfool;  // offset: 0x1845
public:
    static MyDTI DTI;
private:
    static const u32 INSTDUPLI_MAX = 96;
    static const s32 DIST_FRMOUT = 96;
    static const u32 LOGO_MAX = 4;
    static const u32 INVALID_LOGO = 255;
};
