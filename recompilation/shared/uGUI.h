#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtPrimitive2D.h"
#include "MtStlAllocator.h"
#include "MtStlCustom.h"
#include "cGUIInstance.h"
#include "cGUIObject.h"
#include "cGUIVariable.h"
#include "nGUI.h"
#include "sCamera.h"
#include "uCoord.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtRay;
class MtRect;
class MtSize;
class MtUI;
class MtVector2;
class MtVector3;
class cDraw;
class cGUIInstAnimControl;
class cGUIInstAnimVariable;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIInstRoot;
class cGUIInstScissorMask;
class cGUIInstance;
class cGUIObjChildAnimationRoot;
class cGUIObjColorAdjust;
class cGUIObjMessage;
class cGUIObjNull;
class cGUIObjPolygon;
class cGUIObjRoot;
class cGUIObjScissorMask;
class cGUIObjText;
class cGUIObjTexture;
class cGUIObjTextureSet;
class cGUIObject;
class cGUIVarFloat;
class cGUIVarInt;
class cGUIVariable;
namespace nGUI { struct ACTION; }
namespace nGUI { class Draw; }
namespace nGUI { struct FLOW; }
namespace nGUI { struct PARAM_WORK; }
namespace nGUI { struct PROCESS_WORK; }
namespace nGUI { struct SWITCH_CONDITION; }
class rGUI;

// Declarations
class uGUI;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using time_t = long int;
using t64 = time_t;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class uGUI : public uCoord
{
public:
    class MyDTI;
    struct DuplicateBuffer;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct DuplicateBuffer
    {
    public:
        static void* operator new(size_t);
        static void* operator new[](size_t);
        static void* operator new(size_t, void*);
        static void* operator new[](size_t, void*);
        static void operator delete(void*);
        static void operator delete[](void*);
    public:
        cGUIInstance* pDuplicateInstance;  // offset: 0x0
        u8* pBatchMemAlloc;  // offset: 0x8
        cGUIObjText* pObjTextList;  // offset: 0x10
        cGUIObjMessage* pObjMessageList;  // offset: 0x18
        cGUIObjChildAnimationRoot* pObjChildAnimationRootList;  // offset: 0x20
        cGUIObjNull* pObjNullList;  // offset: 0x28
        cGUIObjTextureSet* pObjTextureSetList;  // offset: 0x30
        cGUIObjTexture* pObjTextureList;  // offset: 0x38
        cGUIObjPolygon* pObjPolygonList;  // offset: 0x40
        cGUIObjScissorMask* pObjScissorMaskList;  // offset: 0x48
        cGUIObjColorAdjust* pObjColorAdjustList;  // offset: 0x50
        cGUIObjRoot* pObjRootList;  // offset: 0x58
        u8* pDuplicateMemAllocBuffer;  // offset: 0x60
        u16 guiObjTextUseCount;  // offset: 0x68
        u16 guiObjMessageUseCount;  // offset: 0x6a
        u16 guiObjChildAnimationRootUseCount;  // offset: 0x6c
        u16 guiObjNullUseCount;  // offset: 0x6e
        u16 guiObjTextureSetUseCount;  // offset: 0x70
        u16 guiObjTextureUseCount;  // offset: 0x72
        u16 guiObjPolygonUseCount;  // offset: 0x74
        u16 guiObjScissorMaskUseCount;  // offset: 0x76
        u16 guiObjColorAdjustUseCount;  // offset: 0x78
        u16 guiObjRootUseCount;  // offset: 0x7a
        u32 duplicateMemAllocBufferUsePosition;  // offset: 0x7c
        const void* pNeedNumInfo;  // offset: 0x80
        MtTypedArray<cGUIObject> unknownObjectArray;  // offset: 0x88
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
    uGUI();
    virtual ~uGUI();
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void moveAfter();  // vtable slot 10
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    virtual void draw3D(nGUI::Draw& drawObj);  // vtable slot 28
    virtual void draw2D(nGUI::Draw& drawObj);  // vtable slot 29
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MT_CTSTR getName();  // vtable slot 14
    virtual void setResource(rGUI* pResource);  // vtable slot 30
    virtual bool setResourceWithCheck(rGUI* pResource, t64 t, bool isForceSet);  // vtable slot 31
    virtual bool errorResourceCheck(rGUI* pResource);  // vtable slot 32
    rGUI* getResource() const;
    bool isPlay() const;
    virtual void setPlay(bool v);  // vtable slot 33
    bool isWait() const;
    void setWait(bool v);
    void setVirtualScreen(bool v);
    bool isVirtualScreen() const;
    void setUseViewInstance(bool v);
    bool isUseViewInstance() const;
    void setManual3DPriority(bool v);
    bool isManual3DPriority() const;
    bool is3D() const;
    void setDrawStencil(bool v);
    bool isDrawStencil() const;
    void setStencilRef(u8 v);
    u8 getStencilRef() const;
    bool isUpdateMatrix() const;
    const MtVector2& getAlignmentPosition(nGUI::ALIGNMENT type) const;
    const MtVector2& getResolutionAdjustScale(nGUI::RESOLUTION_ADJUST type) const;
    void setPriority(u32 prio);
    u32 getPriority() const;
    void setScreenLayer(u32 layer);
    u32 getScreenLayer() const;
    u32 getScreenDrawPriority() const;
    cGUIVariable* getVariable(u32 id) const;
    cGUIVariable* getVariableFromIndex(const u32) const;
    cGUIVariable* getVariableFromName(MT_CTSTR pName) const;
    u32 checkHitInstance3D(const MtVector3& pt, sCamera::VIEWPORT_NO viewNo, bool checkMouseReaction, f32 ratio) const;
    u32 checkHitInstance(const MtVector3& pt, bool checkMouseReaction, f32 ratio) const;
    bool isHitInstance3D(cGUIInstance* pInstance, const MtVector3& pt, sCamera::VIEWPORT_NO viewNo, f32 ratio) const;
    bool isHitInstance3D(u32, const MtVector3&, sCamera::VIEWPORT_NO, f32) const;
    bool isHitInstance(cGUIInstance* pInstance, const MtVector3& pt, f32 ratio) const;
    bool isHitInstance(u32, const MtVector3&, f32) const;
    void calcCheckHitRay(MtRay& ray, const MtVector3& pt, sCamera::VIEWPORT_NO viewNo) const;
    void calcBillboardCheckHitRay(MtRay& ray, const MtVector3& pt, sCamera::VIEWPORT_NO viewNo) const;
    bool isPlacementNewMode() const;
    // Address: 0x01ad77b0 - 0x01ad77b1 (1 bytes)
    virtual void callbackAnimationEvent(u32 instanceID, u32 animationID, u32 eventNo) {}  // vtable slot 34
    // Address: 0x01ad77c0 - 0x01ad77c1 (1 bytes)
    virtual void callbackFlowEvent(u32 flowID, u32 eventNo) {}  // vtable slot 35
    void callbackFlowEvent(u32 eventNo);
    // Address: 0x01ad77d0 - 0x01ad77d1 (1 bytes)
    virtual void callbackTextEvent(u32 type, u32 param0, u32 param1) {}  // vtable slot 36
    // Address: 0x01ad77e0 - 0x01ad77e1 (1 bytes)
    virtual void callbackTextTyping(cGUIObject* pObject, u32 charCount) {}  // vtable slot 37
    // Address: 0x01ad77f0 - 0x01ad77f1 (1 bytes)
    virtual void callbackTextTyping(cGUIInstance* pInstance, u32 charCount) {}  // vtable slot 38
    // Address: 0x01ad7800 - 0x01ad7801 (1 bytes)
    virtual void callbackTextTypingCode(cGUIObject* pObject, u32 code) {}  // vtable slot 39
    // Address: 0x01ad7810 - 0x01ad7811 (1 bytes)
    virtual void callbackTextTypingCode(cGUIInstance* pInstance, u32 code) {}  // vtable slot 40
    // Address: 0x01ad7820 - 0x01ad7821 (1 bytes)
    virtual void callbackTextCondition(cGUIObject* pObject, u32 newCondition, u32 oldCondition) {}  // vtable slot 41
    // Address: 0x01ad7830 - 0x01ad7831 (1 bytes)
    virtual void callbackTextCondition(cGUIInstance* pInstance, u32 newCondition, u32 oldCondition) {}  // vtable slot 42
protected:
    virtual void clear();  // vtable slot 43
    void calcMatrix(const MtRect& viewport);
    void play(f32 delta);
    nGUI::FLOW* getFlow(const u32 id) const;
    nGUI::FLOW* getFlowFromName(MT_CTSTR pName) const;
    void clearInvisibleMessage();
    cGUIVariable* createVariable(const MtDTI& dti);
    void deleteVariable(cGUIVariable* pVariable);
    void clearVariableUpdateFlag();
    virtual void* memAlloc(u32 size);  // vtable slot 44
    virtual void memFree(void* p_addr);  // vtable slot 45
    void setUpdateMatrix(bool v);
    void updateAlignmentPosition(const MtRect& viewPort);
    void updateResolutionAdjustScale(const MtSize& defaultSize, const MtSize& viewSize);
private:
    void set3D(bool v);
    void setInitialized(bool v);
    bool isInitialized() const;
    void setProcessFirstFrame(bool v);
    bool isProcessFirstFrame() const;
    void clearInvisibleMessage(cGUIInstance* pInstance, bool visible);
public:
    cGUIInstance* getInstance(const u32 id, bool isAssert) const;
    cGUIInstance* getInstanceFromIndex(const u32 index) const;
    cGUIInstance* getInstanceFromName(MT_CTSTR name) const;
    const DuplicateBuffer* getDuplicateBufferPtr(u32) const;
    const DuplicateBuffer& getDuplicateBufferFast(u32) const;
    u32 getDuplicateBufferNum() const;
    virtual bool isForceSamplerLinear(cGUIObject* pObj) const;  // vtable slot 46
protected:
    cGUIInstance* createInstance(const MtDTI& dti);
    void deleteInstance(cGUIInstance* pInstance);
    cGUIInstance* duplicateInstance(cGUIInstance* pInstance);
    void addRootChild(cGUIInstance* pInstance);
    cGUIInstance* getRootChild() const;
    cGUIInstance* getParentInstance(cGUIInstance* pInstance) const;
    void updateInstanceMatrix(cGUIInstance* pInstance);
    cGUIObject* allocGUIObject(const MtDTI* pdti);
    void* allocBufferForDuplicateInstance(u32 AllocSize);
private:
    bool deleteDuplicateInstance(cGUIInstance* pInstance);
public:
    void setFramerate(u32 mode);
    f32 getFramerate() const;
    bool isInitFlow() const;
    bool playNextProcessFlow();
    bool isEndFlowAnimation(bool checkAnimationInstance) const;
    bool isEndAnimation(cGUIInstance* pInstance) const;
protected:
    virtual void evChangeFlow(const nGUI::FLOW* pNewFlow, const nGUI::FLOW* pNowFlow);  // vtable slot 47
    virtual void evEnd();  // vtable slot 48
    f32 getPlayTime() const;
    f32 getPlayTimeOld() const;
    f32 getFlowFrame() const;
    f32 getFlowFrameOld() const;
    virtual bool setPlayingFlow(const nGUI::FLOW* pFlow, bool callEvent);  // vtable slot 49
    virtual nGUI::FLOW* getPlayingFlow() const;  // vtable slot 50
    virtual bool moveFlowStart(const nGUI::FLOW* pFlow);  // vtable slot 51
    virtual bool moveFlowEnd(const nGUI::FLOW* pFlow);  // vtable slot 52
    virtual void initInstance(cGUIInstance* pInstance);  // vtable slot 53
    virtual bool moveFlowProcess(const nGUI::FLOW* pFlow);  // vtable slot 54
    virtual void doAction(const nGUI::ACTION* pAction);  // vtable slot 55
    virtual void doAnimation(const nGUI::PROCESS_WORK* pProcess, bool forcePlay);  // vtable slot 56
    virtual bool doEndCondition(const nGUI::PROCESS_WORK* pProcess);  // vtable slot 57
    bool isAnimationEnd(const cGUIInstance* pInstance);
    virtual bool moveFlowInput(const nGUI::FLOW* pFlow);  // vtable slot 58
    virtual bool moveFlowSwitch(const nGUI::FLOW* pFlow);  // vtable slot 59
    virtual bool moveFlowFunction(const nGUI::FLOW* pFlow);  // vtable slot 60
    u32 getProcessEndCondition(u32 id) const;
    virtual bool checkSwitchCondition(const nGUI::SWITCH_CONDITION* const pCondition);  // vtable slot 61
private:
    void setChangeFlow(bool v);
    bool isChangeFlow() const;
    void setInitFlow(bool v);
private:
    rGUI* mpResource;  // offset: 0x110
    cGUIInstRoot* mpInstanceRoot;  // offset: 0x118
    cGUIInstance* * mpInstanceList;  // offset: 0x120
    u8* mpBatchMemAlloc;  // offset: 0x128
    cGUIInstNull* mpInstanceNullList;  // offset: 0x130
    cGUIInstScissorMask* mpInstanceScissorMaskList;  // offset: 0x138
    cGUIInstAnimation* mpInstanceAnimationList;  // offset: 0x140
    cGUIInstAnimVariable* mpInstanceAnimVariableList;  // offset: 0x148
    cGUIInstAnimControl* mpInstanceAnimControlList;  // offset: 0x150
    MtTypedArray<cGUIInstance> mUnknownInstanceArray;  // offset: 0x158
    u32 mInstanceNullUseCount;  // offset: 0x178
    u32 mInstanceScissorMaskUseCount;  // offset: 0x17c
    u32 mInstanceAnimationUseCount;  // offset: 0x180
    u32 mInstanceAnimVariableUseCount;  // offset: 0x184
    u32 mInstanceAnimControlUseCount;  // offset: 0x188
    cGUIObjText* mpObjTextList;  // offset: 0x190
    cGUIObjMessage* mpObjMessageList;  // offset: 0x198
    cGUIObjChildAnimationRoot* mpObjChildAnimationRootList;  // offset: 0x1a0
    cGUIObjNull* mpObjNullList;  // offset: 0x1a8
    cGUIObjTextureSet* mpObjTextureSetList;  // offset: 0x1b0
    cGUIObjTexture* mpObjTextureList;  // offset: 0x1b8
    cGUIObjPolygon* mpObjPolygonList;  // offset: 0x1c0
    cGUIObjScissorMask* mpObjScissorMaskList;  // offset: 0x1c8
    cGUIObjColorAdjust* mpObjColorAdjustList;  // offset: 0x1d0
    cGUIObjRoot* mpObjRootList;  // offset: 0x1d8
    u8* mpDuplicateMemAllocBuffer;  // offset: 0x1e0
    u32 mDuplicateMemAllocBufferUsePosition;  // offset: 0x1e8
    MtTypedArray<cGUIObject> mUnknownObjectArray;  // offset: 0x1f0
    u32 mGUIObjTextUseCount;  // offset: 0x210
    u32 mGUIObjMessageUseCount;  // offset: 0x214
    u32 mGUIObjChildAnimationRootUseCount;  // offset: 0x218
    u32 mGUIObjNullUseCount;  // offset: 0x21c
    u32 mGUIObjTextureSetUseCount;  // offset: 0x220
    u32 mGUIObjTextureUseCount;  // offset: 0x224
    u32 mGUIObjPolygonUseCount;  // offset: 0x228
    u32 mGUIObjScissorMaskUseCount;  // offset: 0x22c
    u32 mGUIObjColorAdjustUseCount;  // offset: 0x230
    u32 mGUIObjRootUseCount;  // offset: 0x234
    cGUIVarInt* mpVarIntList;  // offset: 0x238
    cGUIVarFloat* mpVarFloatList;  // offset: 0x240
    MtTypedArray<cGUIVariable> mUnknownVariableArray;  // offset: 0x248
    u32 mVarIntUseCount;  // offset: 0x268
    u32 mVarFloatUseCount;  // offset: 0x26c
    MtStlVector<DuplicateBuffer, MtStlAllocator<DuplicateBuffer> > mDuplicateBufferArray;  // offset: 0x270
    MtStlVector<unsigned int, MtStlAllocator<unsigned int> > mDuplicateBufferNoUseIndexArray;  // offset: 0x290
    u32 mDuplicatingBufferIndex;  // offset: 0x2b0
    bool mIsPlacementNewMode;  // offset: 0x2b4
    u32 mProcessWorkNum;  // offset: 0x2b8
    nGUI::PROCESS_WORK* mpProcessWork;  // offset: 0x2c0
    nGUI::PARAM_WORK* mpProcessParamWork;  // offset: 0x2c8
    nGUI::PARAM_WORK* mpInstExeParam;  // offset: 0x2d0
    f32 mFramerate;  // offset: 0x2d8
    f32 mPlayTime;  // offset: 0x2dc
    f32 mPlayTimeOld;  // offset: 0x2e0
    f32 mFlowFrame;  // offset: 0x2e4
    f32 mFlowFrameOld;  // offset: 0x2e8
    nGUI::FLOW* mpPlayingFlow;  // offset: 0x2f0
    u32 mStackCount;  // offset: 0x2f8
    nGUI::FLOW* mpStack[8];  // offset: 0x300
    u32 mAttr;  // offset: 0x340
    u32 mPriority;  // offset: 0x344
    u32 mScreenLayer;  // offset: 0x348
    u32 mStencilRef : 8;  // offset: 0x34c
    u32 mInstanceId;  // offset: 0x350
    u32 mFlowId;  // offset: 0x354
    u32 mVariableId;  // offset: 0x358
    s32 mProcessVariable;  // offset: 0x35c
    MtRect mViewSize;  // offset: 0x360
    MtVector2 mAlignmentPosition[10];  // offset: 0x370
    MtVector2 mResolutionAdjustScale[11];  // offset: 0x3c0
    MtArray mVariableArray;  // offset: 0x418
public:
    static MyDTI DTI;
private:
    static const u32 ATTR_PLAY = 1;
    static const u32 ATTR_WAIT = 2;
    static const u32 ATTR_VIRTUAL_SCREEN = 4;
    static const u32 ATTR_USE_VIEW_INSTANCE = 8;
    static const u32 ATTR_DRAW_STENCIL = 16;
    static const u32 ATTR_CHANGEFLOW = 256;
    static const u32 ATTR_FLOWINIT = 512;
    static const u32 ATTR_3D = 1024;
    static const u32 ATTR_UPDATE_MATRIX = 2048;
    static const u32 ATTR_INITIALIZED = 4096;
    static const u32 ATTR_PROCESS_FIRSTFRAME = 8192;
    static const u32 ATTR_MANUAL_3D_PRIORITY = 1048576;
};
