#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtColor.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "MtPrimitive2D.h"
#include "nGUI.h"

// Forward declarations
class MtAABB;
class MtAllocator;
class MtColor;
class MtDTI;
struct MtFloat2;
struct MtFloat4;
class MtMatrix;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtRay;
class MtRect;
class MtRectF;
class MtSize;
class MtSizeF;
class MtString;
class MtUI;
class MtVector3;
class MtVector4;
class cGUIFontFilter;
class cGUIInstAnimation;
namespace nGUI { struct ANIMATION; }
namespace nGUI { struct BufferObject; }
namespace nGUI { struct DRAW_LIST; }
namespace nGUI { class Draw; }
namespace nGUI { struct MTAG; }
namespace nGUI { struct MessageDrawState; }
namespace nGUI { struct OBJECT; }
namespace nGUI { struct PARAM; }
namespace nGUI { struct PARAM_WORK; }
namespace nGUI { struct SEQUENCE; }
namespace nGUI { struct TEXTURE; }
class rGUI;
class rGUIFont;
class rGUIMessage;
class uGUI;
class uGUIBase;
class uGUIInputText;
class uGUIMyRoomPopup;

// Declarations
class cGUIObj2D;
class cGUIObjMessage;
class cGUIObjNull;
class cGUIObjPolygon;
class cGUIObjRoot;
class cGUIObjTexture;
class cGUIObject;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cGUIObject : public MtObject
{
    // inferred: cGUIInstAnimation::invisible calls cGUIObject::msgInvisible
    friend class cGUIInstAnimation;
    // inferred: cGUIObjMessage::getValidResolutionAdjust names cGUIObject::mParentResolutionAdjust
    friend class cGUIObjMessage;
    // inferred: cGUIObjRoot::triggerEvent names cGUIObject::mpUnit
    friend class cGUIObjRoot;
    // inferred: cGUIObjTexture::setTextureId names cGUIObject::mpResource
    friend class cGUIObjTexture;
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
    cGUIObject();
    virtual ~cGUIObject();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool isDrawableStatic() const;  // vtable slot 6
    u32 msgCheckHit(const MtVector3& pt, f32 ratio, const MtRay* const pRay);
    const MtMatrix& getMatrix() const;
    void setPriority(u32 prio);
    u32 getPriority() const;
    uGUI* getUnit();
    void setResource(rGUI* pResource);
    rGUI* getResource() const;
    u32 getId() const;
    void setVisible(bool v);
    bool isVisible() const;
    void setLoop(bool v);
    bool isLoop() const;
    void setFixFrame(bool v);
    bool isFixFrame() const;
    bool isPlayable() const;
    bool isAutoClear() const;
    void setAutoClear(bool e);
    bool isMoveFrame() const;
    bool is3D() const;
    bool isAnimate() const;
    void setFrameCount(u32 count);
    u32 getFrameCount() const;
    void setLoopStartFrame(u32 loopFrame);
    u32 getLoopStartFrame() const;
    void setCurrentFrame(f32 frame, bool changeFixFrame);
    f32 getCurrentFrame() const;
    cGUIObject* getChild() const;
    cGUIObject* getNext() const;
    cGUIObject* getParent() const;
    cGUIObjRoot* getRoot();
    u32 getChildNum(bool tree) const;
    cGUIObject* getObjectFromId(u32 id) const;
    const nGUI::PARAM* getPropertyParam(MT_CTSTR pPropertyName) const;
    MtRect getBoundingBox2D() const;
    MtAABB getBoundingBox3D() const;
    virtual MtAABB calcBoundingBox() const;  // vtable slot 7
    virtual u32 getValidResolutionAdjust() const;  // vtable slot 8
    u32 getParentResolutionAdjust() const;
    bool isDeleteChild() const;
    void setDeleteChild(bool IsNewDeleteChild);
protected:
    virtual void init();  // vtable slot 9
    virtual void initProperty();  // vtable slot 10
    // Address: 0x0196f6a0 - 0x0196f6a1 (1 bytes)
    virtual void play(f32 delta) {}  // vtable slot 11
    // Address: 0x0196f6b0 - 0x0196f6b1 (1 bytes)
    virtual void beginDraw(nGUI::Draw& drawObj) {}  // vtable slot 12
    // Address: 0x0198a600 - 0x0198a601 (1 bytes)
    virtual void draw(nGUI::Draw& drawObj) {}  // vtable slot 13
    // Address: 0x0196f6c0 - 0x0196f6c1 (1 bytes)
    virtual void endDraw(nGUI::Draw& drawObj) {}  // vtable slot 14
    virtual void calcMatrix(const MtMatrix& wmat);  // vtable slot 15
    virtual bool checkHit(const MtVector3& pt, f32 ratio, const MtRay* const pRay) const;  // vtable slot 16
    void sort();
    void msgInvisible();
    // Address: 0x0196f6e0 - 0x0196f6e1 (1 bytes)
    virtual void invisible() {}  // vtable slot 17
    void setPlayable(bool v);
    void setMoveFrame(bool v);
    void setUpdateMatrix(bool v);
    bool isUpdateMatrix() const;
    void setUpdateMatrixOld(bool v);
    bool isUpdateMatrixOld() const;
    void setUpdatePriority(bool v);
    bool isUpdatePriority() const;
    void setExecuteMsg(bool v);
    bool isExecuteMsg() const;
    // Address: 0x0198a620 - 0x0198a621 (1 bytes)
    virtual void setUpdateDraw() {}  // vtable slot 18
    virtual void setParentResolutionAdjust(u32 type);  // vtable slot 19
    void setDrawable(bool v);
    bool isDrawable() const;
    virtual void* memAlloc(u32 size);  // vtable slot 20
    virtual void memFree(void* p_addr);  // vtable slot 21
private:
    void setUnit(uGUI* pUnit);
    void setId(const u32 id);
    void set3D(bool v);
    void setAnimate(bool v);
    void setUpdateParentMatrix(bool v);
    bool isUpdateParentMatrix() const;
    void setChild(cGUIObject* pObject);
    void setNext(cGUIObject* pObject);
    void setParent(cGUIObject* pObject);
    void setObjectInfo(nGUI::OBJECT* pObjectInfo, nGUI::PARAM_WORK* pParamWork);
    nGUI::OBJECT* getObjectInfo() const;
    // Address: 0x0196f780 - 0x0196f781 (1 bytes)
    virtual void setExtendData(void* pData) {}  // vtable slot 22
protected:
    MtMatrix mMat;  // offset: 0x10
private:
    u32 mId;  // offset: 0x50
    u32 mAttr;  // offset: 0x54
    f32 mCurrentFrame;  // offset: 0x58
    u32 mFrameCount : 16;  // offset: 0x5c
    u32 mLoopStartFrame : 16;  // offset: 0x5c
    u32 mPriority : 16;  // offset: 0x60
    u32 mParentResolutionAdjust : 4;  // offset: 0x60
    u32 mAnimateParamNum : 8;  // offset: 0x60
    u32 mDeleteChild : 1;  // offset: 0x60
    nGUI::PARAM_WORK* mpParamWork;  // offset: 0x68
    cGUIObject* mpChild;  // offset: 0x70
    cGUIObject* mpNext;  // offset: 0x78
    cGUIObject* mpParent;  // offset: 0x80
    uGUI* mpUnit;  // offset: 0x88
    rGUI* mpResource;  // offset: 0x90
    nGUI::OBJECT* mpObjectInfo;  // offset: 0x98
public:
    static MyDTI DTI;
private:
    static const u32 ATTR_VISIBLE = 1;
    static const u32 ATTR_LOOP = 4;
    static const u32 ATTR_FIX_FRAME = 8;
    static const u32 ATTR_PLAYABLE = 16;
    static const u32 ATTR_AUTO_CLEAR = 32;
    static const u32 ATTR_MOVE_FRAME = 65536;
    static const u32 ATTR_UPDATE_MATRIX = 131072;
    static const u32 ATTR_UPDATE_MATRIX_OLD = 262144;
    static const u32 ATTR_UPDATE_PRIORITY = 524288;
    static const u32 ATTR_SORT_CHILD = 1048576;
    static const u32 ATTR_EXECUTE_MSG = 2097152;
    static const u32 ATTR_3D = 4194304;
    static const u32 ATTR_ANIMATE = 8388608;
    static const u32 ATTR_UPDATE_PARENT_MATRIX = 16777216;
    static const u32 ATTR_DRAWABLE = 33554432;
};

class cGUIObj2D : public cGUIObject
{
    // inferred: uGUIBase::setWindowTitle names cGUIObj2D::mPosition.x
    friend class uGUIBase;
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
    cGUIObj2D();
    virtual ~cGUIObj2D();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void setPosition(const MtVector4& pos);
    const MtVector4& getPosition() const;
    void setPositionX(f32 v);
    f32 getPositionX() const;
    void setPositionY(f32 v);
    f32 getPositionY() const;
    void setPositionZ(f32 v);
    f32 getPositionZ() const;
    void setRotation(const MtVector4& rot);
    const MtVector4& getRotation() const;
    void setRotationX(f32 v);
    f32 getRotationX() const;
    void setRotationY(f32 v);
    f32 getRotationY() const;
    void setRotationZ(f32 v);
    f32 getRotationZ() const;
    void setControlPoint(u32 cp);
    u32 getControlPoint() const;
    u32 getControlPointH() const;
    u32 getControlPointV() const;
    void setReferencePosition(bool v);
    bool isReferencePosition() const;
    void setReferenceRotation(bool v);
    bool isReferenceRotation() const;
    void setReferenceScaleX(u32 type);
    u32 getReferenceScaleX() const;
    void setReferenceScaleY(u32 type);
    u32 getReferenceScaleY() const;
    void setReferenceScaleZ(u32 type);
    u32 getReferenceScaleZ() const;
    void getRectFromSize(MtRectF& rect, const MtFloat2& size) const;
protected:
    virtual void calcMatrix(const MtMatrix& wmat);  // vtable slot 15
    void calcBoundingPosition(MtVector3* pPosition, const MtFloat2& size, f32 ratio) const;
    bool checkHitLine(const MtVector3* pLine, u32 lineNum, const MtVector3& pt) const;
protected:
    MtVector4 mPosition;  // offset: 0xa0
    MtVector4 mRotation;  // offset: 0xb0
    u32 mControlPoint : 4;  // offset: 0xc0
    u32 mReferencePosition : 1;  // offset: 0xc0
    u32 mReferenceRotation : 1;  // offset: 0xc0
    u32 mReferenceScaleX : 2;  // offset: 0xc0
    u32 mReferenceScaleY : 2;  // offset: 0xc0
    u32 mReferenceScaleZ : 2;  // offset: 0xc0
    u32 padding : 20;  // offset: 0xc0
public:
    static MyDTI DTI;
    static const u32 CTRLPNT_LEFT = 0;
    static const u32 CTRLPNT_CENTERH = 1;
    static const u32 CTRLPNT_RIGHT = 2;
    static const u32 CTRLPNT_TOP = 0;
    static const u32 CTRLPNT_CENTERV = 4;
    static const u32 CTRLPNT_BOTTOM = 8;
    static const u32 CTRLPNT_LT = 0;
    static const u32 CTRLPNT_H_MASK = 3;
    static const u32 CTRLPNT_V_MASK = 12;
};

class cGUIObjMessage : public cGUIObj2D
{
    // inferred: uGUIMyRoomPopup::setTitle calls cGUIObjMessage::clearMessage
    friend class uGUIMyRoomPopup;
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
    cGUIObjMessage();
    virtual ~cGUIObjMessage();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool isDrawableStatic() const;  // vtable slot 6
    void setAutoWrap(u32 wrapMode);
    bool isAutoWrap() const;
    u32 getAutoWrap() const;
    void setAutoScale(bool e);
    bool isAutoScale() const;
    void setMonospace(bool e);
    bool isMonospace() const;
    void setUseRuby(bool e);
    bool isUseRuby() const;
    void setAnalyzeTag(bool e);
    bool isAnalyzeTag() const;
    void setFontSlot(u32 slot);
    u32 getFontSlot() const;
    void setFontFilter0(u32 id);
    u32 getFontFilter0() const;
    void setFontFilter1(u32 id);
    u32 getFontFilter1() const;
    void setFontFilter(u32 id, u32 index);
    u32 getFontFilter(u32 index) const;
    void setLayout(u32 layout);
    u32 getLayout() const;
    void setLetterHAlign(u32 letterHAlign);
    u32 getLetterHAlign() const;
    void setLetterVAlign(u32 letterVAlign);
    u32 getLetterVAlign() const;
    void setLineSpace(s32 space);
    s32 getLineSpace() const;
    void setLetterSpace(s32 space);
    s32 getLetterSpace() const;
    void setMessageId(u32 id);
    u32 getMessageId() const;
    void setMessageIndexName(const MtString& name);
    MT_CTSTR getMessageIndexName() const;
    void setFontSize(const MtSize& size);
    MtSize getFontSize() const;
    void setSize(const MtFloat2& size);
    const MtFloat2 getSize() const;
    void setColor(const MtColor& color);
    MtColor getColor() const;
    void setAlpha(u8 alpha);
    u8 getAlpha() const;
    void setRGB(const MtColor& rgb);
    MtColor getRGB() const;
    void setSamplerState(u32 state);
    u32 getSamplerState() const;
    void setIconColorType(u32 type);
    u32 getIconColorType() const;
    void setResolutionAdjust(u32 type);
    u32 getResolutionAdjust() const;
    virtual u32 getValidResolutionAdjust() const;  // vtable slot 8
    void setMessage(MT_CTSTR msg, u32 length);
    void setMessage(MT_CTSTR msg);
    void setSpecifiedPageMessage(MT_CTSTR, u32);
    void setGenderMessage(MT_CTSTR msg, nGUI::GENDER speakerGender, nGUI::GENDER listenerGender, u32 length);
    void setGenderMessage(MT_CTSTR, nGUI::GENDER, nGUI::GENDER);
    void setDrawChar(bool v, u32 start, u32 end);
    bool isValidMessage(MT_CTSTR msg) const;
    rGUIFont* getFont(u32 index) const;
    bool hasTagDisp() const;
    f32 getMessageWidth() const;
    f32 getMessageHeight() const;
    u32 getLineNum(u32 pageIndex) const;
    f32 getLineHeight(u32 lineIndex, u32 pageIndex) const;
    u32 getPageNum() const;
    u32 getDrawingCharPos() const;
    MtFloat2 getPageSize(u32 pageIndex) const;
    u32 getPageCharCount(u32 pageIndex, bool countIcon) const;
    u32 getLineCharCount(u32 lineIndex, u32 pageIndex, bool countIcon) const;
    MtFloat2 getLinePos(u32 lineIndex, u32 pageIndex) const;
    MtFloat2 getCharPos(u32 charIndex, u32 lineIndex, u32 pageIndex, bool countIcon) const;
    MtSizeF getCharSize(u32 charIndex, u32 lineIndex, u32 pageIndex, bool countIcon) const;
    virtual MtAABB calcBoundingBox() const;  // vtable slot 7
    rGUIMessage* getMessageResource() const;
protected:
    virtual void play(f32 delta);  // vtable slot 11
    void updateSamplerState();
    virtual void draw(nGUI::Draw& drawObj);  // vtable slot 13
    virtual bool checkHit(const MtVector3& pt, f32 ratio, const MtRay* const pRay) const;  // vtable slot 16
    virtual void invisible();  // vtable slot 17
    virtual void analyzeMessage(MT_CTSTR msg, u32 length, s32 pageIndex);  // vtable slot 23
    virtual void analyzeGenderMessage(MT_CTSTR msg, nGUI::GENDER speakerGender, nGUI::GENDER listenerGender, u32 length);  // vtable slot 24
    virtual void clearMessage();  // vtable slot 25
    void clearDrawMTag();
    virtual void recalcFontSize();  // vtable slot 26
    void setUpdateSize(bool v);
    bool isUpdateSize() const;
    void setCreateDrawInfo(bool v);
    bool isCreateDrawInfo() const;
    void setNotDrawFont(bool v);
    bool isNotDrawFont() const;
    virtual void setUpdateDraw();  // vtable slot 18
    void checkFontFilter();
    cGUIFontFilter* getFontFilterFromId(u32 id) const;
    virtual nGUI::MTAG* getDrawStartMTag() const;  // vtable slot 27
    virtual nGUI::MTAG* getDrawEndMTag() const;  // vtable slot 28
    virtual bool isPageEnd() const;  // vtable slot 29
    void createDrawMTagList(nGUI::MessageDrawState& state);
    void allocBuffer(nGUI::MessageDrawState& state);
    void updateDraw(nGUI::MessageDrawState& state);
    void updateDrawMTagFont(nGUI::MessageDrawState& state, nGUI::MTAG* pMTag);
    void updateDrawMTagColor(nGUI::MessageDrawState& state, nGUI::MTAG* pMTag);
    void updateDrawMTagRGB(nGUI::MessageDrawState& state, nGUI::MTAG* pMTag);
    void updateDrawMTagChar(nGUI::MessageDrawState& state, nGUI::MTAG* pMTag);
    virtual void updateDrawMTagExtend(nGUI::MessageDrawState& state, nGUI::MTAG* pMTag);  // vtable slot 30
    void executeDraw(nGUI::MessageDrawState& state, nGUI::Draw& drawObj);
    virtual void drawMTagExtend(nGUI::Draw& drawObj, nGUI::MTAG* pMTag);  // vtable slot 31
protected:
    nGUI::MTAG* mpMTag;  // offset: 0xc8
    nGUI::MTAG* mpDrawMTag;  // offset: 0xd0
    f32 mMsgWidth;  // offset: 0xd8
    f32 mMsgHeight;  // offset: 0xdc
    u32 mError;  // offset: 0xe0
    MtColor mColor;  // offset: 0xe4
    MtSize mFontSize;  // offset: 0xe8
    MtFloat2 mSize;  // offset: 0xf0
    nGUI::BufferObject mVertexObject;  // offset: 0xf8
    nGUI::BufferObject mIndexObject;  // offset: 0x110
private:
    u32 mMsgAttr;  // offset: 0x128
    u32 mFontSlot;  // offset: 0x12c
    u32 mLayout : 8;  // offset: 0x130
    u32 mLetterHAlign : 2;  // offset: 0x130
    u32 mLetterVAlign : 2;  // offset: 0x130
    u32 mSamplerState : 4;  // offset: 0x130
    u32 mIconColorType : 2;  // offset: 0x130
    u32 mAutoWrap : 2;  // offset: 0x130
    u32 mResolutionAdjust : 4;  // offset: 0x130
    s32 mLineSpace : 16;  // offset: 0x134
    s32 mLetterSpace : 16;  // offset: 0x134
    u32 mMessageId;  // offset: 0x138
    MT_CTSTR mpMessageIndexName;  // offset: 0x140
    u32 mFontFilterId[2];  // offset: 0x148
    nGUI::BufferObject mFFVertexObject[2];  // offset: 0x150
    nGUI::BufferObject mFFIndexObject[2];  // offset: 0x180
    nGUI::MTAG* mpFFDrawMTag[2];  // offset: 0x1b0
    u32 mOldSamplerState : 4;  // offset: 0x1c0
    u32 mSamplerChangeFlag : 1;  // offset: 0x1c0
    u32 mSamplerPadding : 27;  // offset: 0x1c0
public:
    static MyDTI DTI;
    static const u32 ATTR_AUTO_SCALE_W = 1;
    static const u32 ATTR_MONOSPACE = 2;
    static const u32 ATTR_USE_RUBY = 4;
    static const u32 ATTR_ANALYZE_TAG = 8;
    static const u32 ATTR_UPDATE_SIZE = 65536;
    static const u32 ATTR_CREATE_DRAWINFO = 131072;
    static const u32 ATTR_NOT_DRAW_FONT = 262144;
};

class cGUIObjNull : public cGUIObj2D
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
    cGUIObjNull();
    virtual ~cGUIObjNull();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void setScaleX(f32 v);
    f32 getScaleX() const;
    void setScaleY(f32 v);
    f32 getScaleY() const;
    void setScaleZ(f32 v);
    f32 getScaleZ() const;
protected:
    virtual void calcMatrix(const MtMatrix& wmat);  // vtable slot 15
protected:
    MtVector4 mScale;  // offset: 0xd0
public:
    static MyDTI DTI;
};

class cGUIObjPolygon : public cGUIObj2D
{
    // inferred: uGUIInputText::getCaretWidth names cGUIObjPolygon::mSize.x
    friend class uGUIInputText;
public:
    enum VERTEX
    {
        VERTEX_LT = 0,
        VERTEX_RT = 1,
        VERTEX_LB = 2,
        VERTEX_RB = 3,
        VERTEX_NUM = 4,
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
    cGUIObjPolygon();
    virtual ~cGUIObjPolygon();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool isDrawableStatic() const;  // vtable slot 6
    void setMaskType(u32 v);
    u32 getMaskType() const;
    void setVertexColorLT(const MtColor& color);
    MtColor getVertexColorLT() const;
    void setVertexColorRT(const MtColor& color);
    MtColor getVertexColorRT() const;
    void setVertexColorLB(const MtColor& color);
    MtColor getVertexColorLB() const;
    void setVertexColorRB(const MtColor& color);
    MtColor getVertexColorRB() const;
    void setVertexColorUp(const MtColor& color);
    MtColor getVertexColorUp() const;
    void setVertexColorDown(const MtColor& color);
    MtColor getVertexColorDown() const;
    void setVertexColorLeft(const MtColor& color);
    MtColor getVertexColorLeft() const;
    void setVertexColorRight(const MtColor& color);
    MtColor getVertexColorRight() const;
    virtual void setVertexColor(const MtColor& color);  // vtable slot 23
    MtColor getVertexColor() const;
    void setColor(const MtColor& color, u32 index);
    MtColor getColor(u32 index) const;
    virtual void setVertexAlpha(u8 alpha);  // vtable slot 24
    u8 getVertexAlpha() const;
    void setAlpha(u8 alpha, u32 index);
    u8 getAlpha(u32 index) const;
    virtual void setVertexRGB(const MtColor& rgb);  // vtable slot 25
    MtColor getVertexRGB() const;
    void setRGB(const MtColor& rgb, u32 index);
    MtColor getRGB(u32 index) const;
    void setBlendState(u32 state);
    u32 getBlendState() const;
    void setReverseClockwise(bool v);
    bool isReverseClockwise() const;
    virtual void setSize(const MtFloat2& size);  // vtable slot 26
    const MtFloat2 getSize() const;
    virtual MtAABB calcBoundingBox() const;  // vtable slot 7
protected:
    virtual void beginDraw(nGUI::Draw& drawObj);  // vtable slot 12
    virtual void draw(nGUI::Draw& drawObj);  // vtable slot 13
    virtual void endDraw(nGUI::Draw& drawObj);  // vtable slot 14
    virtual bool checkHit(const MtVector3& pt, f32 ratio, const MtRay* const pRay) const;  // vtable slot 16
    void applyMask(nGUI::Draw& drawObj);
    virtual void setUpdateDraw();  // vtable slot 18
    void updateColorState();
protected:
    MtColor mColor[4];  // offset: 0xc4
    MtFloat2 mSize;  // offset: 0xd4
    nGUI::BufferObject mVertexObject;  // offset: 0xe0
private:
    u32 mMaskType : 4;  // offset: 0xf8
    u32 mBlendState : 8;  // offset: 0xf8
    u32 mPolygonAttr : 16;  // offset: 0xf8
public:
    static MyDTI DTI;
protected:
    static const u32 ATTR_RCW = 1;
};

class cGUIObjRoot : public cGUIObject
{
    // inferred: cGUIInstAnimation::getSequenceId names cGUIObjRoot::mpPlayingSequence
    friend class cGUIInstAnimation;
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
    cGUIObjRoot();
    virtual ~cGUIObjRoot();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void msgInit();  // vtable slot 23
    void msgPlay(f32 delta, bool force);
    void msgDraw(nGUI::Draw& drawObj);
    void msgCalcMatrix(const MtMatrix& wmat, bool update);
    void requestCreateDrawList();
    bool isUpdateRootMatrix() const;
    void setSequenceId(u32 id);
    u32 getSequenceId() const;
    void setSequenceFromName(MT_CTSTR);
    u32 getSequenceIdFromName(MT_CTSTR pName) const;
    u32 getTotalFrameCount() const;
    u32 getObjectNum() const;
    cGUIObject* getObjectFromName(MT_CTSTR name) const;
    virtual void setParentResolutionAdjust(u32 type);  // vtable slot 19
    u32 getInsideAllocateSize() const;
protected:
    virtual void init();  // vtable slot 9
    void triggerEvent(u32 eventNo);
private:
    void setRequestCreateDrawList(bool v);
    bool isRequestCreateDrawList() const;
    void setUpdateRootMatrix(bool v);
    void createDrawList();
    void setAnimationId(u32 animationId);
    void setObject(nGUI::ANIMATION* pAnimation, cGUIObject* * pObject);
    void setSequence(u32 sequenceNum, nGUI::SEQUENCE* pSequence);
    nGUI::PARAM_WORK* getParamWorkTop() const;
    void setInstanceId(u32 id);
    u32 getInstanceId() const;
private:
    nGUI::DRAW_LIST* mpDrawList;  // offset: 0xa0
    u32 mInstanceId;  // offset: 0xa8
    u32 mAnimationId;  // offset: 0xac
    u32 mRootAttr;  // offset: 0xb0
    u32 mSequenceNum;  // offset: 0xb4
    nGUI::SEQUENCE* mpPlayingSequence;  // offset: 0xb8
    nGUI::SEQUENCE* mpSequence;  // offset: 0xc0
    nGUI::ANIMATION* mpAnimation;  // offset: 0xc8
    cGUIObject* * mpObject;  // offset: 0xd0
    nGUI::PARAM_WORK* mpParamWorkTop;  // offset: 0xd8
    bool mIsDeleteParamWorkTop;  // offset: 0xe0
public:
    static MyDTI DTI;
private:
    static const u32 ATTR_CREATE_DRAW_LIST = 1;
    static const u32 ATTR_UPDATE_ROOT_MATRIX = 2;
};

class cGUIObjTexture : public cGUIObjPolygon
{
public:
    enum TILING
    {
        TILING_NONE = 0,
        TILING_SCALE = 1,
        TILING_NO_SCALE = 2,
        TILING_NUM = 3,
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
    cGUIObjTexture();
    virtual ~cGUIObjTexture();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void setSamplerState(u32 state);
    u32 getSamplerState() const;
    virtual void setSize(const MtFloat2& size);  // vtable slot 26
    void setTiling(u32 mode);
    u32 getTiling() const;
    void setTextureId(u32 id);
    u32 getTextureId() const;
    void setTextureRect(const MtFloat4& rect);
    MtFloat4 getTextureRect() const;
protected:
    virtual void setUpdateDraw();  // vtable slot 18
    void updateSamplerState();
    virtual void draw(nGUI::Draw& drawObj);  // vtable slot 13
    bool drawWithTiling(nGUI::Draw& drawObj, nGUI::SamplerState::SAMPLER_MODE& sampler);
    bool drawWithoutTiling(nGUI::Draw& drawObj, nGUI::SamplerState::SAMPLER_MODE& sampler);
protected:
    u32 mTextureId;  // offset: 0xfc
    nGUI::TEXTURE* mpTexture;  // offset: 0x100
private:
    u32 mSamplerState : 4;  // offset: 0x108
    u32 mTiling : 2;  // offset: 0x108
    u32 mPadding : 26;  // offset: 0x108
    MtFloat4 mTextureRect;  // offset: 0x10c
    nGUI::BufferObject mIndexObject;  // offset: 0x120
    u32 mOldSamplerState : 4;  // offset: 0x138
    u32 mSamplerChangeFlag : 1;  // offset: 0x138
    u32 mSamplerPadding : 27;  // offset: 0x138
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline f32 cGUIObjMessage::getMessageWidth() const {
    return this->mMsgWidth;
}

// Inline, no code of its own: checked where it is inlined.
inline f32 cGUIObjMessage::getMessageHeight() const {
    return this->mMsgHeight;
}
