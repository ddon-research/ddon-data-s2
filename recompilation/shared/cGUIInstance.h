#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtColor.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "MtPrimitive2D.h"
#include "sCamera.h"

// Forward declarations
class MtAABB;
class MtAllocator;
class MtColor;
class MtDTI;
class MtMatrix;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtRay;
class MtRect;
class MtSize;
class MtUI;
class MtVector3;
class MtVector4;
class cGUIObjRoot;
class cGUIObject;
class cGUIVariable;
namespace nGUI { struct ANIM_SECTION; }
namespace nGUI { class Draw; }
namespace nGUI { struct INIT_PARAM; }
namespace nGUI { struct PROP_SETTER; }
class rGUI;
class uGUI;
class uGUIBase;
class uGUIGauge;
class uGUIMapMini;
class uGUIPhoto;

// Declarations
class cGUIInstAnimControl;
class cGUIInstAnimVariable;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIInstScissorMask;
class cGUIInstance;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cGUIInstance : public MtObject
{
    // inferred: cGUIInstAnimVariable::setVariableId names cGUIInstance::mpUnit
    friend class cGUIInstAnimVariable;
    // inferred: uGUI::updateInstanceMatrix names cGUIInstance::mAttr
    friend class uGUI;
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
    cGUIInstance();
    virtual ~cGUIInstance();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createEditProperty(MtPropertyList& s);  // vtable slot 6
    virtual void createEventProperty(MtPropertyList& s);  // vtable slot 7
    virtual void init();  // vtable slot 8
    virtual void clear();  // vtable slot 9
    void msgPlay(f32 delta);
    void msgDraw(nGUI::Draw& drawObj);
    void msgCalcMatrix(const MtMatrix& wmat);
    u32 msgCheckHit(const MtVector3& pt, bool checkMouseReaction, f32 ratio, const MtRay* const pRay, const MtMatrix* const pInvViewMat);
    void setPriority(u32 prio);
    u32 getPriority() const;
    uGUI* getUnit() const;
    rGUI* getResource() const;
    u32 getId() const;
    u32 getDuplicateId() const;
    bool isVisible() const;
    void setVisible(bool v);
    bool isPlay() const;
    void setPlay(bool e);
    bool isMouseReaction() const;
    void setMouseReaction(bool e);
    bool isExecute() const;
    void setExecute(bool v);
    bool isPlayable() const;
    virtual bool isAnimationEnd() const;  // vtable slot 10
    bool isAutoClear() const;
    void setAutoClear(bool);
    bool is3D() const;
    bool isCreateDynamic() const;
    bool isExecutePlay() const;
    void setExecuteTree(bool e);
    const MtMatrix& getMatrix() const;
    cGUIInstance* getChild() const;
    cGUIInstance* getNext() const;
    cGUIInstance* getParent() const;
    u32 getChildNum() const;
    void addChild(cGUIInstance* pInstance);
    cGUIInstance* getInstanceFromId(u32 id);
    cGUIInstance* getDuplicateInstanceFromId(u32 id) const;
    cGUIInstance* getDuplicateInstanceFromIndex(u32 index) const;
    void setDrawView(u32);
    u32 getDrawView() const;
    MtRect getBoundingBox2D() const;
    MtAABB getBoundingBox3D(const MtMatrix* pInvViewMat) const;
    nGUI::INIT_PARAM* getInitParamPtr() const;
    u32 getInitParamNum() const;
protected:
    virtual void play(f32) = 0;  // vtable slot 11
    // Address: 0x01b71b50 - 0x01b71b51 (1 bytes)
    virtual void beginDraw(nGUI::Draw& drawObj) {}  // vtable slot 12
    virtual void draw(nGUI::Draw&) = 0;  // vtable slot 13
    // Address: 0x01b71b60 - 0x01b71b61 (1 bytes)
    virtual void endDraw(nGUI::Draw& drawObj) {}  // vtable slot 14
    virtual void calcMatrix(const MtMatrix&) = 0;  // vtable slot 15
    virtual bool checkHit(const MtVector3& pt, f32 ratio, const MtRay* const pRay, const MtMatrix* const pInvViewMat) const;  // vtable slot 16
    void calcBillboardMatrix(MtMatrix& mat, const u32 type, const MtMatrix* pInvViewMat) const;
    void sort();
    void msgInvisible();
    // Address: 0x01b71b80 - 0x01b71b81 (1 bytes)
    virtual void invisible() {}  // vtable slot 17
    void setPlayable(bool v);
    void setUpdateMatrix(bool v);
    bool isUpdateMatrix() const;
    void setUpdateMatrixOld(bool v);
    bool isUpdateMatrixOld() const;
    void setUpdatePriority(bool v);
    bool isUpdatePriority() const;
    void setExecuteMsg(bool v);
    bool isExecuteMsg() const;
    static void* memAlloc(u32 size);
    static void memFree(void* p_addr);
    virtual MtAABB calcBoundingBox(const MtMatrix* pInvViewMat) const;  // vtable slot 18
private:
    void setUnit(uGUI* pUnit);
    void setResource(rGUI* pResource);
    void setId(const u32 id);
    void setDuplicateId(const u32 id);
    void set3D(bool v);
    void setCreateDynamic(bool v);
    void setUpdateParentMatrix(bool v);
    virtual bool isUpdateParentMatrix() const;  // vtable slot 19
    void setChild(cGUIInstance* pInstance);
    void setNext(cGUIInstance* pInstance);
    void setParent(cGUIInstance* pInstance);
    void setupParent();
    void setInitParam(nGUI::INIT_PARAM* pInitParam, u32 num);
    // Address: 0x01b71ba0 - 0x01b71ba1 (1 bytes)
    virtual void setExtendData(void* pData) {}  // vtable slot 20
    // Address: 0x01b71bb0 - 0x01b71bb1 (1 bytes)
    virtual void copyExtendData(cGUIInstance* pInstance) {}  // vtable slot 21
    bool isDeleteChild() const;
    void setDeleteChild(bool IsNewDeleteChild);
private:
    u32 mId;  // offset: 0x8
    u32 mPriority;  // offset: 0xc
protected:
    MtMatrix mMat;  // offset: 0x10
    bool mIsDeleteChild;  // offset: 0x50
private:
    u32 mDuplicateId;  // offset: 0x54
    u32 mAttr;  // offset: 0x58
    u32 mDrawView : 16;  // offset: 0x5c
    u32 mInitParamNum : 16;  // offset: 0x5c
    nGUI::INIT_PARAM* mpInitParam;  // offset: 0x60
    cGUIInstance* mpChild;  // offset: 0x68
    cGUIInstance* mpNext;  // offset: 0x70
    cGUIInstance* mpParent;  // offset: 0x78
    uGUI* mpUnit;  // offset: 0x80
    rGUI* mpResource;  // offset: 0x88
public:
    static MyDTI DTI;
    static const nGUI::PROP_SETTER PROP_SETTER_EXECUTE;
private:
    static const u32 ATTR_VISIBLE = 1;
    static const u32 ATTR_PLAY = 2;
    static const u32 ATTR_MOUSE_REACTION = 4;
    static const u32 ATTR_EXECUTE = 8;
    static const u32 ATTR_PLAYABLE = 16;
    static const u32 ATTR_AUTO_CLEAR = 64;
    static const u32 ATTR_UPDATE_MATRIX = 65536;
    static const u32 ATTR_UPDATE_MATRIX_OLD = 131072;
    static const u32 ATTR_UPDATE_PRIORITY = 262144;
    static const u32 ATTR_SORT_CHILD = 524288;
    static const u32 ATTR_EXECUTE_MSG = 1048576;
    static const u32 ATTR_3D = 2097152;
    static const u32 ATTR_CREATE_DYNAMIC = 4194304;
    static const u32 ATTR_UPDATE_PARENT_MATRIX = 8388608;
    static const u32 ATTR_EXECUTE_PLAY = 10;
};

class cGUIInstNull : public cGUIInstance
{
    // inferred: uGUIGauge::setupAura names cGUIInstNull::mPosition.x
    friend class uGUIGauge;
    // inferred: uGUIPhoto::initList names cGUIInstNull::mPosition.y
    friend class uGUIPhoto;
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
    cGUIInstNull();
    virtual ~cGUIInstNull();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void setDrawPass(u32 pass);
    u32 getDrawPass() const;
    void setDepthState(u32 state);
    u32 getDepthState() const;
    void setAlignment(u32 align);
    u32 getAlignment() const;
    void setColorControl(u32 type);
    u32 getColorControl() const;
    virtual void setResolutionAdjust(u32 type);  // vtable slot 22
    u32 getResolutionAdjust() const;
    u32 getValidResolutionAdjust() const;
    u32 getParentResolutionAdjust() const;
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
    void setPosition(const MtVector4& pos);
    const MtVector4& getPosition() const;
    void setPositionX(f32 v);
    f32 getPositionX() const;
    void setPositionY(f32 v);
    f32 getPositionY() const;
    void setPositionZ(f32 v);
    f32 getPositionZ() const;
    void setScaleX(f32 v);
    f32 getScaleX() const;
    void setScaleY(f32 v);
    f32 getScaleY() const;
    void setScaleZ(f32 v);
    f32 getScaleZ() const;
    void setRotation(const MtVector4& rot);
    const MtVector4& getRotation() const;
    void setRotationX(f32 v);
    f32 getRotationX() const;
    void setRotationY(f32 v);
    f32 getRotationY() const;
    void setRotationZ(f32 v);
    f32 getRotationZ() const;
    void setColorScale(const MtVector4& color);
    MtVector4 getColorScale() const;
    void setAmbientColor(const MtColor& color);
    MtColor getAmbientColor() const;
    void setSaturation(f32 v);
    f32 getSaturation() const;
protected:
    // Address: 0x01b71bf0 - 0x01b71bf1 (1 bytes)
    virtual void play(f32 delta) {}  // vtable slot 11
    virtual void beginDraw(nGUI::Draw& drawObj);  // vtable slot 12
    virtual void draw(nGUI::Draw& drawObj);  // vtable slot 13
    virtual void endDraw(nGUI::Draw& drawObj);  // vtable slot 14
    virtual void calcMatrix(const MtMatrix& wmat);  // vtable slot 15
    void setCDrawPass(nGUI::Draw& drawObj);
    virtual void setParentResolutionAdjust(u32 type);  // vtable slot 23
private:
    void setChildResolutionAdjust(cGUIInstance* pInstance, u32 type);
private:
    u32 mDrawPass : 4;  // offset: 0x90
    u32 mDepthState : 4;  // offset: 0x90
    u32 mAlignment : 4;  // offset: 0x90
    u32 mColorControl : 4;  // offset: 0x90
    u32 mResolutionAdjust : 4;  // offset: 0x90
    u32 mParentResolutionAdjust : 4;  // offset: 0x90
    u32 mReferencePosition : 1;  // offset: 0x90
    u32 mReferenceRotation : 1;  // offset: 0x90
    u32 mReferenceScaleX : 2;  // offset: 0x90
    u32 mReferenceScaleY : 2;  // offset: 0x90
    u32 mReferenceScaleZ : 2;  // offset: 0x90
    MtColor mAmbientColor;  // offset: 0x94
    MtVector4 mColorScale;  // offset: 0xa0
    MtVector4 mPosition;  // offset: 0xb0
    MtVector4 mScale;  // offset: 0xc0
    MtVector4 mRotation;  // offset: 0xd0
public:
    static MyDTI DTI;
};

class cGUIInstScissorMask : public cGUIInstNull
{
    // inferred: uGUIMapMini::execPosition names cGUIInstScissorMask::mSize.h
    friend class uGUIMapMini;
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
    cGUIInstScissorMask();
    virtual ~cGUIInstScissorMask();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void setEnableScissor(bool v);
    bool isEnableScissor() const;
    void setSize(const MtSize& size);
    MtSize getSize() const;
protected:
    virtual void calcMatrix(const MtMatrix& wmat);  // vtable slot 15
    virtual void beginDraw(nGUI::Draw& drawObj);  // vtable slot 12
    virtual void endDraw(nGUI::Draw& drawObj);  // vtable slot 14
    virtual bool checkHit(const MtVector3& pt, f32 ratio, const MtRay* const pRay, const MtMatrix* const pInvViewMat) const;  // vtable slot 16
private:
    void setUpdateSize(bool v);
    bool isUpdateSize() const;
    void setEnabledScissor(bool v);
    bool isEnabledScissor() const;
    void calcScissorMask(MtRect& rect) const;
private:
    u32 mEnableScissor : 1;  // offset: 0xe0
    u32 mUpdateSize : 1;  // offset: 0xe0
    u32 mEnabledScissor : 1;  // offset: 0xe0
    MtSize mSize;  // offset: 0xe8
    MtRect mScissorRect;  // offset: 0xf0
    MtRect mParentScissorRect;  // offset: 0x100
public:
    static MyDTI DTI;
};

class cGUIInstAnimation : public cGUIInstNull
{
    // inferred: uGUIBase::getObjectFromId names cGUIInstAnimation::mpObjRoot
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
    cGUIInstAnimation();
    virtual ~cGUIInstAnimation();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createEventProperty(MtPropertyList& s);  // vtable slot 7
    virtual void init();  // vtable slot 8
    virtual void clear();  // vtable slot 9
    void setMaskType(u32 v);
    u32 getMaskType() const;
    void setSpeed(f32 speed);
    f32 getSpeed() const;
    void setFoundation(bool v);
    bool isFoundation() const;
    void setResourceId(u32 id);
    u32 getResourceId() const;
    rGUI* getAnimationResource() const;
    void setAnimationId(u32 id);
    u32 getAnimationId() const;
    static cGUIObjRoot* createAnimation(uGUI* pUnit, rGUI* pResource, u32 animationId, cGUIObject* * & pObjectTable, bool& IsAllocByPlacementNew);
    void setSequenceId(u32 id);
    u32 getSequenceId() const;
    void setSequenceFromName(MT_CTSTR pName);
    void setBillboard(u32 type);
    u32 getBillboard() const;
    virtual void resetCurrentFrame();  // vtable slot 24
    void setCurrentFrame(f32 frame, bool changeFixFrame);
    f32 getCurrentFrame() const;
    virtual bool isAnimationEnd() const;  // vtable slot 10
    void setStopFrame(f32);
    f32 getStopFrame() const;
    void gotoAndPlay(f32 frame, bool changeFixFrame);
    void gotoAndStop(f32 frame, bool changeFixFrame);
    void clearInvisibleMessage(bool visible);
    cGUIObjRoot* getRootObject() const;
    u32 getObjectNum() const;
    cGUIObject* getObjectFromId(u32 id) const;
    cGUIObject* getObjectFromIndex(u32 index) const;
    cGUIObject* getObjectFromName(MT_CTSTR name) const;
    f32 getObjectCurrentFrameFromId(u32) const;
    f32 getObjectCurrentFrameFromIndex(u32) const;
    f32 getObjectCurrentFrameFromName(MT_CTSTR) const;
    f32 getObjectCurrentFrame(cGUIObject*) const;
    u32 getHitObjectId(const MtVector3& pt, f32 ratio);
    u32 getFrameCount() const;
    virtual void setResolutionAdjust(u32 type);  // vtable slot 22
    bool isHitObject(cGUIObject* pObject, const MtVector3& pt, f32 ratio) const;
    bool isHitObject(u32, const MtVector3&, f32) const;
    bool isHitObject3D(cGUIObject* pObject, const MtVector3& pt, sCamera::VIEWPORT_NO viewNo, f32 ratio) const;
    bool isHitObject3D(u32, const MtVector3&, sCamera::VIEWPORT_NO, f32) const;
    bool isDeleteGUIObject() const;
    void setDeleteGUIObject(bool IsDelete);
    bool isDeleteObjectBuffer() const;
    void setDeleteObjectBuffer(bool IsDelete);
    u32 getInsideAllocateSize() const;
protected:
    virtual void play(f32 delta);  // vtable slot 11
    virtual void beginDraw(nGUI::Draw& drawObj);  // vtable slot 12
    virtual void draw(nGUI::Draw& drawObj);  // vtable slot 13
    void drawFinaly(nGUI::Draw& drawObj);
    virtual void endDraw(nGUI::Draw& drawObj);  // vtable slot 14
    virtual void calcMatrix(const MtMatrix& wmat);  // vtable slot 15
    virtual void invisible();  // vtable slot 17
    virtual bool checkHit(const MtVector3& pt, f32 ratio, const MtRay* const pRay, const MtMatrix* const pInvViewMat) const;  // vtable slot 16
    virtual MtAABB calcBoundingBox(const MtMatrix* pInvViewMat) const;  // vtable slot 18
    virtual void setParentResolutionAdjust(u32 type);  // vtable slot 23
private:
    void setCurrentFrame(cGUIObject* pObject, f32 frame, bool changeFixFrame);
    void clearInvisibleMessage(cGUIObject* pObject, bool visible);
private:
    f32 mCurrentFrame;  // offset: 0xe0
    f32 mStopFrame;  // offset: 0xe4
    u32 mMaskType : 4;  // offset: 0xe8
    u32 mBillboard : 4;  // offset: 0xe8
    u32 mFoundation : 1;  // offset: 0xe8
    u32 mDeleteGUIObject : 1;  // offset: 0xe8
    u32 mDelete_pObjectBuffer : 1;  // offset: 0xe8
    u32 padding : 21;  // offset: 0xe8
    f32 mSpeed;  // offset: 0xec
    u32 mResourceId;  // offset: 0xf0
    u32 mAnimationId;  // offset: 0xf4
    cGUIObject* * mpObject;  // offset: 0xf8
    cGUIObjRoot* mpObjRoot;  // offset: 0x100
public:
    static MyDTI DTI;
};

class cGUIInstAnimVariable : public cGUIInstAnimation
{
    // inferred: cGUIInstAnimControl::play names cGUIInstAnimVariable::mpVariable
    friend class cGUIInstAnimControl;
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
    cGUIInstAnimVariable();
    virtual ~cGUIInstAnimVariable();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void init();  // vtable slot 8
    virtual void setVariableId(u32 id);  // vtable slot 25
    u32 getVariableId() const;
    virtual bool isAnimationEnd() const;  // vtable slot 10
protected:
    cGUIVariable* getVariable() const;
private:
    virtual void play(f32 delta);  // vtable slot 11
private:
    u32 mVariableId;  // offset: 0x108
    cGUIVariable* mpVariable;  // offset: 0x110
public:
    static MyDTI DTI;
};

class cGUIInstAnimControl : public cGUIInstAnimVariable
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
    cGUIInstAnimControl();
    virtual ~cGUIInstAnimControl();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void init();  // vtable slot 8
    bool isSectionEnd() const;
    bool isLoopSection() const;
    virtual bool isAnimationEnd() const;  // vtable slot 10
    virtual void restart();  // vtable slot 26
    virtual void resetCurrentFrame();  // vtable slot 24
protected:
    virtual void play(f32 delta);  // vtable slot 11
private:
    void setUseSequence(bool v);
    bool isUseSequence() const;
    void playSection(f32 delta);
    void playSequence(f32 delta);
    nGUI::ANIM_SECTION* searchSection(s32 value) const;
    virtual void setExtendData(void* pData);  // vtable slot 20
    virtual void copyExtendData(cGUIInstance* pInstance);  // vtable slot 21
private:
    u32 mAnimSectionNum;  // offset: 0x118
    s32 mNowValue;  // offset: 0x11c
    f32 mSectionCurrentFrame;  // offset: 0x120
    bool mUseSequence;  // offset: 0x124
    nGUI::ANIM_SECTION* mpAnimSection;  // offset: 0x128
    nGUI::ANIM_SECTION* mpNowAnimSection;  // offset: 0x130
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline cGUIObjRoot* cGUIInstAnimation::getRootObject() const {
    return this->mpObjRoot;
}

// Inline, no code of its own: checked where it is inlined.
inline cGUIInstance* cGUIInstance::getChild() const {
    return this->mpChild;
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline cGUIInstance* cGUIInstance::getParent() const {
    return this->mpParent;
}
