#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtColor.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "cControl.h"
#include "nCharacterEdit.h"
#include "nDDOUtility.h"
#include "nGUIExt.h"
#include "uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtDTI;
class MtObject;
class MtVector2;
class cControl;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIInstance;
class cGUIObjMessage;
class cGUIObjPolygon;
class cGUIObjTexture;
class cUndoData;
class rSoundRequest;
class uCharacterEdit;
class uGUICharacterEdit;

// Declarations
class uGUICharaEditPartsWrap;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUICharaEditPartsWrap : public uGUIBase
{
public:
    enum VOICE_PITCH_TYPE
    {
        VOICE_PITCH_L = 0,
        VOICE_PITCH_M = 1,
        VOICE_PITCH_H = 2,
        VOICE_PITCH_MAX = 2,
        VOICE_PITCH_START = 94,
    };
public:
    class MyDTI;
    class cDupliObjectBase;
    class cPartsBase;
    class cPartsSlider;
    class cReferenceUIEditSliderExt;
    class cPartsImage;
    class cPartsDupliBase;
    class cPartsColor;
    class cPartsColorEye;
    class cPartsColorHairAll;
    class cPartsPulldown;
    class cPartsMask;
    class cPartsRadioButton;
    class cPartsRadioSlider;
    class cReferenceUIRadioButtonExt;
    class cPartsMyName;
    class cPartsHList;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cDupliObjectBase : public MtObject
    {
        friend class uGUICharaEditPartsWrap;
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
        cDupliObjectBase();
        virtual void deleteInstance() {}  // vtable slot 6
        virtual MtVector2 getPointerPos(uGUIBase* pBase);  // vtable slot 7
        virtual void setFocus(bool b);  // vtable slot 8
        virtual bool isFocus();  // vtable slot 9
        virtual s32 getSelect();  // vtable slot 10
        virtual void update() {}  // vtable slot 11
        bool isEnableUID();
        s32 getUID();
        void setUID(s32 n);
    private:
        bool mFocus;  // offset: 0x8
        s32 mUID;  // offset: 0xc
    public:
        static MyDTI DTI;
    };
public:
    class cPartsBase : public uGUIBase::cSupportBase
    {
        friend class uGUICharaEditPartsWrap;
    public:
        enum
        {
            EXIT_PARTS_NONE = 0,
            EXIT_PARTS_END = 1,
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
        cPartsBase();
        virtual ~cPartsBase();
        virtual void update();  // vtable slot 6
        void setOrgInst(cGUIInstNull* pNull);
        cGUIInstNull* getOrgInst();
        virtual void deleteInstance(uGUICharacterEdit* pUnit);  // vtable slot 7
        virtual s32 getNextY();  // vtable slot 8
        virtual cControl* getCtrl();  // vtable slot 9
        virtual MtVector2 getPointerPos(uGUIBase* pBase);  // vtable slot 10
        virtual void setFocus(bool b);  // vtable slot 11
        virtual bool isFocus();  // vtable slot 12
        virtual bool isOldFocus();  // vtable slot 13
        void setClose(bool b);
        bool isClose();
        MtTypedArray<uGUICharaEditPartsWrap::cPartsBase>& getPartsArray();
        s32 size();
        virtual cGUIInstance* getParentInstance();  // vtable slot 14
        void setPos(const MtVector2& pos, bool instantly);
        MtVector2 getPos();
        virtual bool isCanFocus();  // vtable slot 15
        virtual void evChangeFocus(nCharacterEdit::DIR dir, bool in) {}  // vtable slot 16
        virtual f32 getSelectIdx(u32 idx, nCharacterEdit::PARTS_EVENT ev);  // vtable slot 17
        virtual void setEditType(s32 idx, s32 n);  // vtable slot 18
        virtual s32 getEditType(s32 idx) const;  // vtable slot 19
        virtual u32 getEditTypeNum() const;  // vtable slot 20
        virtual u32 getEditActiveTypeNum() const;  // vtable slot 21
        void setVisibleSizeY(s32);
        s32 getVisibleSizeY();
        virtual void evClose(bool isClose);  // vtable slot 22
        f32 getPosRivise();
        virtual bool isForceRegisterRedoUndo();  // vtable slot 23
        void setAddRetIdx(f32 f);
        void setOwner(uGUICharacterEdit* pOwner, uCharacterEdit* pEdit);
        uGUICharaEditPartsWrap::cPartsBase* getChildParts(u32 i) const;
        virtual void callbackApplyUndoRedo(cUndoData& undoData);  // vtable slot 24
        virtual void callbackEditDefault();  // vtable slot 25
        virtual void moveInputParts() {}  // vtable slot 26
        virtual void moveInputPartsAlways();  // vtable slot 27
        virtual void moveEventParts(u32 inputEvent);  // vtable slot 28
        virtual u32 evCtrlPartsDecide(cControl::Message* msg);  // vtable slot 29
        virtual u32 evCtrlPartsCancel(cControl::Message* msg);  // vtable slot 30
        virtual u32 evCtrlPartsMoveH(cControl::Message* msg);  // vtable slot 31
        virtual u32 evCtrlPartsMoveV(cControl::Message* msg);  // vtable slot 32
        virtual u32 evCtrlPartsMouseClick(cControl::Message* msg);  // vtable slot 33
        virtual u32 evCtrlPartsMouseW(cControl::Message* msg);  // vtable slot 34
        virtual u32 evCtrlPartsMouseOver(cControl::Message* msg);  // vtable slot 35
        virtual void evInputPartsOpen() {}  // vtable slot 36
        virtual void evInputPartsDecide();  // vtable slot 37
        virtual void evInputPartsClose();  // vtable slot 38
        virtual void evInputPartsMoveH() {}  // vtable slot 39
        virtual void evInputPartsMoveV() {}  // vtable slot 40
        virtual void evInputPartsMouseOver() {}  // vtable slot 41
    protected:
        void setInputPartsEvent(u32 inputEvent);
        void callChildInputParts(u32 childNo, bool isOpenPartsCheck);
        void callChildEventParts(u32 childNo, bool isOpenPartsCheck, u32 inputEvent);
        bool isOpenParts() const;
        rSoundRequest* getSoundRes();
    public:
        uGUIBase::cDupliInstNull mInst;  // offset: 0x18
        cControl* mpBottunCtrl_PrSub;  // offset: 0x40
    protected:
        cGUIInstNull* mpOrgNull;  // offset: 0x48
        MtTypedArray<uGUICharaEditPartsWrap::cPartsBase> mChildArray;  // offset: 0x50
        bool mFocus;  // offset: 0x70
        bool mOldFocus;  // offset: 0x71
        bool mIsClose;  // offset: 0x72
        nDDOUtility::cArray<int, 6> mEditType;  // offset: 0x74
        uGUIBase::cCalcMovePos mMovePos;  // offset: 0x90
        MtVector2 mPos;  // offset: 0xb0
        MtVector2 mNowPos;  // offset: 0xb8
        f32 mAddRetIdx;  // offset: 0xc0
        s32 mVisibleSizeY;  // offset: 0xc4
        uGUICharacterEdit* mpGuiCharacterEdit;  // offset: 0xc8
        uCharacterEdit* mpCharacterEdit;  // offset: 0xd0
        u32 mExitTyep;  // offset: 0xd8
    public:
        static MyDTI DTI;
    };
public:
    class cReferenceUIEditSliderExt : public uGUIBase::cReferenceUIEditSlider
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
        cReferenceUIEditSliderExt();
        virtual ~cReferenceUIEditSliderExt();
        virtual void setMsgNumStr(s32 n, bool bInit);  // vtable slot 19
        void setEditType(nCharacterEdit::EDIT_TYPE type);
        void setOwner(uGUICharaEditPartsWrap::cPartsBase* pParts, uGUICharacterEdit* pGuiCharaEdit, uCharacterEdit* pCharacterEdit);
        void setValRange(f32 minVal, f32 maxVal);
        f32 getValMin() const;
        f32 getValMax() const;
    protected:
        f32 mMinVal;  // offset: 0x12c
        f32 mMaxVal;  // offset: 0x130
        uGUICharaEditPartsWrap::cPartsBase* mpOwnerParts;  // offset: 0x138
        uGUICharacterEdit* mpGUICharacterEdit;  // offset: 0x140
        uCharacterEdit* mpCharacterEdit;  // offset: 0x148
        nCharacterEdit::EDIT_TYPE mEditType;  // offset: 0x150
    public:
        static MyDTI DTI;
    };
public:
    class cPartsDupliBase : public uGUICharaEditPartsWrap::cPartsBase
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
        cPartsDupliBase();
        virtual void deleteInstance(uGUICharacterEdit* pUnit);  // vtable slot 7
        virtual s32 getNextY();  // vtable slot 8
    public:
        cGUIInstNull* mpParentInstance;  // offset: 0xe0
        MtTypedArray<uGUICharaEditPartsWrap::cDupliObjectBase> mArray;  // offset: 0xe8
        MtVector2 mOffset;  // offset: 0x108
        s32 mX;  // offset: 0x110
        s32 mY;  // offset: 0x114
        static MyDTI DTI;
    };
public:
    class cPartsColor : public uGUICharaEditPartsWrap::cPartsDupliBase
    {
    public:
        class MyDTI;
        class cObject;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class cObject : public uGUICharaEditPartsWrap::cDupliObjectBase
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
            cObject();
            virtual void deleteInstance();  // vtable slot 6
            virtual void setFocus(bool b);  // vtable slot 8
            virtual MtVector2 getPointerPos(uGUIBase* pBase);  // vtable slot 7
            void setImage(s32 idx);
            virtual void setSelect(bool b);  // vtable slot 12
            virtual void update();  // vtable slot 11
        public:
            uGUIBase::cDupliInstNull mInst;  // offset: 0x10
            cGUIObjTexture* mpTex;  // offset: 0x38
            cGUIInstAnimation* mpInstImage;  // offset: 0x40
            cGUIInstAnimation* mpInstCheck;  // offset: 0x48
            MtColor mColor;  // offset: 0x50
            cGUIObjPolygon* mpObjMouseOver;  // offset: 0x58
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
        cPartsColor();
        virtual ~cPartsColor();
        virtual void update();  // vtable slot 6
        virtual cControl* getCtrl();  // vtable slot 9
        void setSelect(s32 idx);
        virtual f32 getSelectIdx(u32 idx, nCharacterEdit::PARTS_EVENT ev);  // vtable slot 17
        f32 getSelectCore();
        f32 getScrBarOffsetEx() const;
        virtual nCharacterEdit::EDIT_TYPE getDecidePointType() const;  // vtable slot 42
        void setToDecidedPoint();
        void resetToCheckPoint();
        virtual void moveInputParts();  // vtable slot 26
        virtual void moveEventParts(u32 inputEvent);  // vtable slot 28
        virtual void callbackApplyUndoRedo(cUndoData& undoData);  // vtable slot 24
        virtual void callbackEditDefault();  // vtable slot 25
        virtual u32 evCtrlPartsCancel(cControl::Message* msg);  // vtable slot 30
        virtual u32 evCtrlPartsMouseOver(cControl::Message* msg);  // vtable slot 35
        virtual void evInputPartsOpen();  // vtable slot 36
        virtual void evInputPartsDecide();  // vtable slot 37
        virtual void evInputPartsClose();  // vtable slot 38
        virtual void evInputPartsMoveV();  // vtable slot 40
    public:
        uGUIBase::cReferenceUIScrollBar mRefScrBar;  // offset: 0x118
        uGUIBase::cMatrix* mpCtrlMat;  // offset: 0x1c0
        s32 mSelect;  // offset: 0x1c8
        s32 mSelectOld;  // offset: 0x1cc
        static MyDTI DTI;
        static const u32 VISIBLE_H_NUM = 5;
    };
public:
    class cPartsColorEye : public uGUICharaEditPartsWrap::cPartsColor
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
        cPartsColorEye();
        void setLeftEyeColorDef(s32);
        void setRightEyeColorDef(s32);
        virtual void evInputPartsOpen();  // vtable slot 36
        virtual void evInputPartsDecide();  // vtable slot 37
        virtual void callbackApplyUndoRedo(cUndoData& undoData);  // vtable slot 24
        virtual void callbackEditDefault();  // vtable slot 25
        virtual f32 getSelectIdx(u32 idx, nCharacterEdit::PARTS_EVENT ev);  // vtable slot 17
        void setEditLeftEye(bool flag);
        void setEditRightEye(bool flag);
        virtual nCharacterEdit::EDIT_TYPE getDecidePointType() const;  // vtable slot 42
    private:
        bool mIsLeftEdit;  // offset: 0x1d0
        bool mIsRightEdit;  // offset: 0x1d1
        s32 mLeftEyeDef;  // offset: 0x1d4
        s32 mRightEyeDef;  // offset: 0x1d8
    public:
        static MyDTI DTI;
    };
public:
    class cPartsColorHairAll : public uGUICharaEditPartsWrap::cPartsColor
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
        cPartsColorHairAll();
        virtual f32 getSelectIdx(u32 idx, nCharacterEdit::PARTS_EVENT ev);  // vtable slot 17
        void setDefaultValue(nCharacterEdit::EDIT_HAIR_COLOR_INDEX index, s32 color);
        virtual void evInputPartsDecide();  // vtable slot 37
        virtual void evInputPartsOpen();  // vtable slot 36
        virtual void callbackApplyUndoRedo(cUndoData& undoData);  // vtable slot 24
        virtual void callbackEditDefault();  // vtable slot 25
    private:
        f32 mEditValueDefault[3];  // offset: 0x1d0
    public:
        static MyDTI DTI;
    };
public:
    class cPartsPulldown : public uGUICharaEditPartsWrap::cPartsBase
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
        cPartsPulldown();
        virtual ~cPartsPulldown();
        virtual void setFocus(bool b);  // vtable slot 11
        virtual MtVector2 getPointerPos(uGUIBase* pBase);  // vtable slot 10
        virtual void update();  // vtable slot 6
        virtual void moveInputParts();  // vtable slot 26
        virtual void moveInputPartsAlways();  // vtable slot 27
        virtual void moveEventParts(u32 inputEvent);  // vtable slot 28
        virtual u32 evCtrlPartsDecide(cControl::Message* msg);  // vtable slot 29
        virtual u32 evCtrlPartsCancel(cControl::Message* msg);  // vtable slot 30
        virtual u32 evCtrlPartsMouseClick(cControl::Message* msg);  // vtable slot 33
        void evInputPartsOpenPullDown();
        void evInputPartsClosePullDown();
        void evInputPartsExitPullDown();
        virtual void callbackApplyUndoRedo(cUndoData& undoData);  // vtable slot 24
        virtual void callbackEditDefault();  // vtable slot 25
    public:
        uGUIBase::cReferenceUIPullDown mRefPulldown;  // offset: 0xe0
        cControl* mpCtrlButton;  // offset: 0x6f0
        static MyDTI DTI;
    };
public:
    class cPartsMask : public uGUICharaEditPartsWrap::cPartsBase
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
        cPartsMask();
        virtual ~cPartsMask();
        virtual void update();  // vtable slot 6
        virtual MtVector2 getPointerPos(uGUIBase* pBase);  // vtable slot 10
        virtual cGUIInstance* getParentInstance();  // vtable slot 14
        void setMaskSizeY(s32 n);
        virtual bool isCanFocus();  // vtable slot 15
        virtual void evClose(bool isClose);  // vtable slot 22
        f32 getPosRivise();
        virtual void moveInputParts();  // vtable slot 26
        virtual void moveEventParts(u32 inputEvent);  // vtable slot 28
        virtual void callbackApplyUndoRedo(cUndoData& undoData);  // vtable slot 24
        virtual void callbackEditDefault();  // vtable slot 25
    public:
        cGUIInstAnimation* mpInstMask;  // offset: 0xe0
        cGUIObjPolygon* mpTexTop;  // offset: 0xe8
        cGUIObjPolygon* mpTexCenter;  // offset: 0xf0
        cGUIObjPolygon* mpTexBottom;  // offset: 0xf8
        s32 mMaskSize;  // offset: 0x100
        uGUIBase::cCalcMovePos mMoveSize;  // offset: 0x108
        static MyDTI DTI;
    };
public:
    class cPartsRadioButton : public uGUICharaEditPartsWrap::cPartsBase
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
        cPartsRadioButton();
        virtual ~cPartsRadioButton();
        virtual void deleteInstance(uGUICharacterEdit* pUnit);  // vtable slot 7
        virtual void update();  // vtable slot 6
        virtual cControl* getCtrl();  // vtable slot 9
        virtual s32 getNextY();  // vtable slot 8
        virtual f32 getSelectIdx(u32 idx, nCharacterEdit::PARTS_EVENT ev);  // vtable slot 17
        virtual void moveInputParts();  // vtable slot 26
        virtual void moveEventParts(u32 inputEvent);  // vtable slot 28
        virtual void evInputPartsDecide();  // vtable slot 37
        virtual void callbackApplyUndoRedo(cUndoData& undoData);  // vtable slot 24
        virtual void callbackEditDefault();  // vtable slot 25
        void setToDecidedPoint();
    public:
        uGUIBase::cReferenceUIRadioButton mRefRadioButton;  // offset: 0xe0
        cGUIObjMessage* mpMsgTitle;  // offset: 0x1d0
        static MyDTI DTI;
    };
public:
    class cReferenceUIRadioButtonExt : public uGUIBase::cReferenceUIRadioButton
    {
        friend class uGUICharaEditPartsWrap;
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
        cReferenceUIRadioButtonExt();
        virtual ~cReferenceUIRadioButtonExt();
        void setIsSelectForbit(bool flag);
        bool isSelectForbit() const;
    protected:
        bool mIsSelectForbit;  // offset: 0xf0
    public:
        static MyDTI DTI;
    };
public:
    class cPartsMyName : public uGUICharaEditPartsWrap::cPartsBase
    {
    public:
        enum NAME_INPUT_RNO
        {
            NAME_INPUT_SELECT = 0,
            NAME_INPUT_NAME = 1,
        };
        enum NAME_TYPE
        {
            NAME_FIRST = 0,
            NAME_LAST = 1,
            NAME_TYPE_NUM = 2,
        };
        enum NAME_CHECK
        {
            NAME_CHECK_OK = 0,
            NAME_CHECK_FAIL = 1,
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
        cPartsMyName();
        virtual ~cPartsMyName();
        virtual void update();  // vtable slot 6
        void updateCheckMark(MT_CTSTR name, cGUIObjTexture* pTex, nCharacterEdit::EDIT_NAME_TYPE nameType);
        void checkNameInvalid();
        virtual cControl* getCtrl();  // vtable slot 9
        virtual f32 getSelectIdx(u32 idx, nCharacterEdit::PARTS_EVENT ev);  // vtable slot 17
        virtual MtVector2 getPointerPos(uGUIBase* pBase);  // vtable slot 10
        bool isInputWait() const;
        virtual void moveInputParts();  // vtable slot 26
        virtual void moveEventParts(u32 inputEvent);  // vtable slot 28
        virtual u32 evCtrlPartsMouseClick(cControl::Message* msg);  // vtable slot 33
        virtual void evInputPartsOpen();  // vtable slot 36
        virtual void evInputPartsDecide();  // vtable slot 37
        virtual void evInputPartsClose();  // vtable slot 38
        virtual void evInputNameInputCancel();  // vtable slot 42
        virtual void callbackApplyUndoRedo(cUndoData& undoData);  // vtable slot 24
        virtual void callbackEditDefault();  // vtable slot 25
        void notifyNameInput();
        void resetNameInput();
    public:
        cGUIInstAnimation* mpAnim;  // offset: 0xe0
        uGUIBase::cVerticalList* mpCtrlV;  // offset: 0xe8
        cControl* mpBottonCtrl;  // offset: 0xf0
        NAME_INPUT_RNO mNameInputRno;  // offset: 0xf8
        nGUIExt::CHARA_EDIT mEdit;  // offset: 0xfc
        uGUIBase::cReferenceUITextBox mTextFirst;  // offset: 0x100
        uGUIBase::cReferenceUITextBox mTextLast;  // offset: 0x268
        cGUIObjMessage* mpMsgNameCheck;  // offset: 0x3d0
        nDDOUtility::cArray<cGUIObjTexture*, 2> mpCheckMarks;  // offset: 0x3d8
        static MyDTI DTI;
    };
public:
    class cPartsHList : public uGUICharaEditPartsWrap::cPartsBase
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
        cPartsHList();
        virtual ~cPartsHList();
        virtual void setFocus(bool b);  // vtable slot 11
        virtual MtVector2 getPointerPos(uGUIBase* pBase);  // vtable slot 10
    public:
        cGUIInstAnimation* mpInstance;  // offset: 0xe0
        static MyDTI DTI;
    };
public:
    class cPartsSlider : public uGUICharaEditPartsWrap::cPartsBase
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
        cPartsSlider();
        virtual ~cPartsSlider();
        virtual void update();  // vtable slot 6
        virtual MtVector2 getPointerPos(uGUIBase* pBase);  // vtable slot 10
        virtual f32 getSelectIdx(u32 idx, nCharacterEdit::PARTS_EVENT ev);  // vtable slot 17
        virtual void moveInputParts();  // vtable slot 26
        virtual void moveInputPartsAlways();  // vtable slot 27
        virtual void evInputPartsOpen();  // vtable slot 36
        virtual void evInputPartsDecide();  // vtable slot 37
        virtual void evInputPartsClose();  // vtable slot 38
        virtual void evChangeFocus(nCharacterEdit::DIR dir, bool in);  // vtable slot 16
        virtual void callbackApplyUndoRedo(cUndoData& undoData);  // vtable slot 24
        virtual void callbackEditDefault();  // vtable slot 25
        void setToDecidedPos();
    public:
        uGUICharaEditPartsWrap::cReferenceUIEditSliderExt mRefSlider;  // offset: 0xe0
        u32 mSavePointerPos;  // offset: 0x238
        static MyDTI DTI;
    };
public:
    class cPartsImage : public uGUICharaEditPartsWrap::cPartsDupliBase
    {
    public:
        class MyDTI;
        class cObject;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class cObject : public uGUICharaEditPartsWrap::cDupliObjectBase
        {
        public:
            enum OBJECT_FLAG
            {
                FLAG_NONE = 0,
                FLAG_REWARD = 1,
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
            cObject();
            virtual void deleteInstance();  // vtable slot 6
            virtual void setFocus(bool b);  // vtable slot 8
            virtual MtVector2 getPointerPos(uGUIBase* pBase);  // vtable slot 7
            void setImage(s32 idx);
            virtual void setSelect(bool b);  // vtable slot 12
            virtual void update();  // vtable slot 11
        public:
            uGUIBase::cDupliInstNull mInst;  // offset: 0x10
            s32 mImageIdx;  // offset: 0x38
            cGUIInstAnimation* mpInstImage;  // offset: 0x40
            cGUIInstAnimation* mpInstCheck;  // offset: 0x48
            cGUIObjMessage* mpObjMsg;  // offset: 0x50
            cGUIObjPolygon* mpObjMouseOver;  // offset: 0x58
            u32 mObjectFlag;  // offset: 0x60
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
        cPartsImage();
        virtual ~cPartsImage();
        virtual void update();  // vtable slot 6
        virtual cControl* getCtrl();  // vtable slot 9
        void setSelect(s32 idx);
        virtual f32 getSelectIdx(u32 idx, nCharacterEdit::PARTS_EVENT ev);  // vtable slot 17
        void setToDecidedPoint();
        void resetToCheckPoint();
        s32 findDecidedIndex(s32 editParam);
        virtual void moveInputParts();  // vtable slot 26
        virtual void moveEventParts(u32 inputEvent);  // vtable slot 28
        virtual void callbackApplyUndoRedo(cUndoData& undoData);  // vtable slot 24
        virtual void callbackEditDefault();  // vtable slot 25
        virtual u32 evCtrlPartsCancel(cControl::Message* msg);  // vtable slot 30
        virtual u32 evCtrlPartsMouseOver(cControl::Message* msg);  // vtable slot 35
        virtual void evInputPartsOpen();  // vtable slot 36
        virtual void evInputPartsDecide();  // vtable slot 37
        virtual void evInputPartsClose();  // vtable slot 38
        virtual void evInputPartsMoveH();  // vtable slot 39
        virtual void evInputPartsMoveV();  // vtable slot 40
        virtual void evInputPartsMouseOver();  // vtable slot 41
    public:
        uGUIBase::cReferenceUIScrollBar mRefScrBar;  // offset: 0x118
        uGUIBase::cMatrix* mpCtrlMat;  // offset: 0x1c0
        s32 mSelect;  // offset: 0x1c8
        s32 mSelectOld;  // offset: 0x1cc
        bool mIsFirstFrame;  // offset: 0x1d0
        static MyDTI DTI;
        static const u32 VISIBLE_H_NUM = 4;
    };
public:
    class cPartsRadioSlider : public uGUICharaEditPartsWrap::cPartsBase
    {
    public:
        enum UI_TYPE
        {
            UI_TYPE_BUTTON = 0,
            UI_TYPE_SLIDER = 1,
        };
        enum ICON_KEY
        {
            ICON_KEY_LOCK = 0,
            ICON_KEY_UNLOCK = 1,
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
        cPartsRadioSlider();
        virtual ~cPartsRadioSlider();
        virtual void update();  // vtable slot 6
        virtual MtVector2 getPointerPos(uGUIBase* pBase);  // vtable slot 10
        virtual f32 getSelectIdx(u32 idx, nCharacterEdit::PARTS_EVENT ev);  // vtable slot 17
        virtual void moveInputParts();  // vtable slot 26
        virtual void evInputPartsOpen();  // vtable slot 36
        virtual void evInputPartsDecide();  // vtable slot 37
        virtual void evInputPartsClose();  // vtable slot 38
        virtual void evChangeFocus(nCharacterEdit::DIR dir, bool in);  // vtable slot 16
        virtual void callbackApplyUndoRedo(cUndoData& undoData);  // vtable slot 24
        virtual void callbackEditDefault();  // vtable slot 25
        void reqRegistRedoUndo();
        virtual u32 evCtrlPartsDecide(cControl::Message* msg);  // vtable slot 29
        f32 calcVoicePitch(s32 pitchPos) const;
    public:
        uGUICharaEditPartsWrap::cReferenceUIEditSliderExt mRefSlider;  // offset: 0xe0
        uGUICharaEditPartsWrap::cReferenceUIRadioButtonExt mRefRadioButton;  // offset: 0x238
        cGUIInstAnimation* mpInstLock;  // offset: 0x330
        uGUIBase::cReferenceUIChargesInfo mChargeIcon;  // offset: 0x338
        s32 mIdx;  // offset: 0x490
        nCharacterEdit::CHARGE_TYPE mChargeType;  // offset: 0x494
        u32 mUID;  // offset: 0x498
        u32 mSavePointerPos;  // offset: 0x49c
        static MyDTI DTI;
        static const u32 OFFSET_Y = 43;
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
    uGUICharaEditPartsWrap();
    virtual ~uGUICharaEditPartsWrap();
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void kill();  // vtable slot 16
public:
    static MyDTI DTI;
};

inline void* uGUICharaEditPartsWrap::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUICharaEditPartsWrap::cDupliObjectBase::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUICharaEditPartsWrap::cDupliObjectBase::cDupliObjectBase() {
    this->mFocus = false;
    this->mUID = -1;
}

inline void* uGUICharaEditPartsWrap::cPartsBase::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUICharaEditPartsWrap::cPartsSlider::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUICharaEditPartsWrap::cReferenceUIEditSliderExt::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUICharaEditPartsWrap::cReferenceUIEditSliderExt::cReferenceUIEditSliderExt() {
    this->mEditType = static_cast<nCharacterEdit::EDIT_TYPE>(0);
    this->mpCharacterEdit = nullptr;
    this->mpGUICharacterEdit = nullptr;
    this->mpOwnerParts = nullptr;
    this->mMinVal = 0.0f;
    this->mMaxVal = 1.0f;
}

inline f32 uGUICharaEditPartsWrap::cReferenceUIEditSliderExt::getValMin() const {
    return this->mMinVal;
}

inline f32 uGUICharaEditPartsWrap::cReferenceUIEditSliderExt::getValMax() const {
    return this->mMaxVal;
}

inline void* uGUICharaEditPartsWrap::cPartsImage::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUICharaEditPartsWrap::cPartsImage::cObject::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUICharaEditPartsWrap::cPartsDupliBase::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUICharaEditPartsWrap::cPartsColor::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUICharaEditPartsWrap::cPartsColor::cObject::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUICharaEditPartsWrap::cPartsColorEye::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUICharaEditPartsWrap::cPartsColorHairAll::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUICharaEditPartsWrap::cPartsPulldown::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUICharaEditPartsWrap::cPartsMask::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUICharaEditPartsWrap::cPartsRadioButton::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUICharaEditPartsWrap::cPartsRadioSlider::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUICharaEditPartsWrap::cReferenceUIRadioButtonExt::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUICharaEditPartsWrap::cPartsMyName::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUICharaEditPartsWrap::cPartsHList::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
