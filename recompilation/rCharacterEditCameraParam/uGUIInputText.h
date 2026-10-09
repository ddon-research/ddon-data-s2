#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/MtPrimitive2D.h"
#include "../shared/MtString.h"
#include "../shared/nDDOUtility.h"
#include "nInputText.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
struct MtFloat2;
class MtObject;
class MtPointF;
class MtRectF;
class MtSize;
class MtVector3;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class cGUIObjNull;
class cGUIObjPolygon;
namespace nInputText { struct Context; }
namespace nInputText { struct ConvertInfo; }
namespace nInputText { class cUnicodeString; }
class rGUI;

// Declarations
class uGUIInputText;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIInputText : public uGUIBase
{
public:
    enum TEXT_TYPE
    {
        TEXT_TYPE_FIXED = 0,
        TEXT_TYPE_FIXED_SELECT = 1,
        TEXT_TYPE_COMPOSITE = 2,
        TEXT_TYPE_COMPOSITE_TARGET = 3,
        TEXT_TYPE_NUM = 4,
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
    uGUIInputText();
    virtual ~uGUIInputText();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void moveAfter();  // vtable slot 10
    f32 getCaretWidth() const;
    void setPosScale(const MtFloat2& pos, f32 scale);
    void setPosScale(const cGUIObjMessage* objMessage, const MtVector3& unitPos, f32 scale);
    void setProperty(const MtFloat2& pos, const MtSize& fontSize, const MtFloat2& messageSize, u32 autoWrap, u32 layout, u32 controlPoint, f32 instNullScale, f32 inputModeIconWidth, bool isWallpaper, const MtFloat2* maskSize);
    void setProperty(const cGUIObjMessage* objMessage, const MtVector3& unitPos, f32 instNullScale, f32 inputModeIconWidth, const cGUIObjPolygon* objMask);
    const MtRectF& applyInputTextContext(const nInputText::Context& inputTextContext);
    bool isTextVisible() const;
protected:
    // Address: 0x01af2f60 - 0x01af2f61 (1 bytes)
    virtual void adjustScale() {}  // vtable slot 84
private:
    void updateExit();
    void updateInit();
    void updateIdle();
    void updateCaretPosition(u32 characterIndex, u32 characterCount, const cGUIObjMessage* objMessage);
    MtPointF updateTextPosition();
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    cGUIInstNull* mpINST_Null_all;  // offset: 0x8d0
    cGUIInstAnimation* mpINST_msg_text;  // offset: 0x8d8
    cGUIObjPolygon* mpOBJ_msg_text_caret;  // offset: 0x8e0
    cGUIObjPolygon* mpOBJ_msg_text_wallpaper;  // offset: 0x8e8
    cGUIObjPolygon* mpOBJ_msg_text_mask_center;  // offset: 0x8f0
    cGUIObjNull* mpOBJ_msg_text_Null_txt;  // offset: 0x8f8
    nDDOUtility::cArray<cGUIObjMessage*, 4> mpOBJ_msg_texts;  // offset: 0x900
    MtStringEx<6144> mText;  // offset: 0x920
    nInputText::cUnicodeString mInputString;  // offset: 0x2124
    nInputText::cUnicodeString mDispString;  // offset: 0x492c
    nInputText::ConvertInfo mConvertInfo;  // offset: 0x7138
    bool mIsCaretDisp;  // offset: 0x9980
    bool mIsVisible;  // offset: 0x9981
    bool mIsVisibleWallpaper;  // offset: 0x9982
    MtRectF mCompositionRect;  // offset: 0x9984
    MtFloat2 mMaskSize;  // offset: 0x9994
    f32 mInputModeIconWidth;  // offset: 0x999c
    MtFloat2 mPos;  // offset: 0x99a0
    f32 mScale;  // offset: 0x99a8
public:
    static MyDTI DTI;
};
