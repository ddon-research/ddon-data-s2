#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtPrimitive2D.h"
#include "../shared/MtString.h"
#include "../shared/cResource.h"
#include "../shared/nGUI.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtSize;
class MtStream;
class MtString;
class MtUI;
class cGUIFontFilter;
namespace nDraw { class VertexBuffer; }
namespace nGUI { struct ACTION; }
namespace nGUI { struct ANIMATION; }
namespace nGUI { struct CAMERA_SETTING; }
namespace nGUI { struct FLOW; }
namespace nGUI { struct FLOW_FUNCTION; }
namespace nGUI { struct FLOW_INPUT; }
namespace nGUI { struct FLOW_PROCESS; }
namespace nGUI { struct FLOW_SWITCH; }
namespace nGUI { struct FONT; }
namespace nGUI { struct GENERALRESOURCE; }
namespace nGUI { struct GUIRESOURCE; }
namespace nGUI { struct INIT_PARAM; }
namespace nGUI { struct INPUT_CONDITION; }
namespace nGUI { struct INSTANCE; }
namespace nGUI { struct KEY; }
namespace nGUI { struct MESSAGE; }
namespace nGUI { struct OBJECT; }
namespace nGUI { struct OBJ_SEQUENCE; }
namespace nGUI { struct PARAM; }
namespace nGUI { struct SEQUENCE; }
namespace nGUI { struct SWITCH_CONDITION; }
namespace nGUI { struct SWITCH_OPERATOR; }
namespace nGUI { struct TEXTURE; }
namespace nGUI { struct VARIABLE; }
namespace nGUI { struct VERTEX; }
class rTexture;

// Declarations
class rGUI;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_STR = MT_CHAR*;
using _Sizet = long unsigned int;
using u32 = unsigned int;
namespace nGUI { using CAMERA_SETTING_ID = u32; }
using size_t = _Sizet;
using time_t = long int;
using t64 = time_t;
using u8 = unsigned char;

class rGUI : public cResource
{
public:
    class MyDTI;
    struct HEADER;
    struct InstanceNeedObjectInfo;
    struct AnimationSearch;
    struct ObjectSearch;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct HEADER
    {
    public:
        u32 magic;  // offset: 0x0
        u32 version;  // offset: 0x4
        u32 size;  // offset: 0x8
        u32 attr;  // offset: 0xc
        t64 updateTime;  // offset: 0x10
        u32 instanceId;  // offset: 0x18
        u32 flowId;  // offset: 0x1c
        u32 variableId;  // offset: 0x20
        u32 startInstanceIndex;  // offset: 0x24
        u32 animationNum;  // offset: 0x28
        u32 sequenceNum;  // offset: 0x2c
        u32 objectNum;  // offset: 0x30
        u32 objSequenceNum;  // offset: 0x34
        u32 initParamNum;  // offset: 0x38
        u32 paramNum;  // offset: 0x3c
        u32 keyNum;  // offset: 0x40
        u32 instanceNum;  // offset: 0x44
        u32 flowNum;  // offset: 0x48
        u32 flowProcessNum;  // offset: 0x4c
        u32 flowInputNum;  // offset: 0x50
        u32 flowSwitchNum;  // offset: 0x54
        u32 flowFunctionNum;  // offset: 0x58
        u32 actionNum;  // offset: 0x5c
        u32 inputConditionNum;  // offset: 0x60
        u32 switchConditionNum;  // offset: 0x64
        u32 switchOperatorNum;  // offset: 0x68
        u32 variableNum;  // offset: 0x6c
        u32 textureNum;  // offset: 0x70
        u32 fontNum;  // offset: 0x74
        u32 fontFilterNum;  // offset: 0x78
        u32 messageNum;  // offset: 0x7c
        u32 guiResourceNum;  // offset: 0x80
        u32 generalResourceNum;  // offset: 0x84
        u32 cameraSettingNum;  // offset: 0x88
        u32 instExeParamNum;  // offset: 0x8c
        u32 vertexBufferSize;  // offset: 0x90
        u32 baseZ : 2;  // offset: 0x94
        u32 framerateMode : 1;  // offset: 0x94
        u32 languageSettingNo : 2;  // offset: 0x94
        u32 padding : 27;  // offset: 0x94
        MtSize viewSize;  // offset: 0x98
        union
        {
        public:
            u32 startFlowIndex;  // offset: 0x0
            nGUI::FLOW* startFlowAdrs;  // offset: 0x0
        };  // offset: 0xa0
        union
        {
        public:
            u32 animationOffset;  // offset: 0x0
            nGUI::ANIMATION* pAnimation;  // offset: 0x0
        };  // offset: 0xa8
        union
        {
        public:
            u32 sequenceOffset;  // offset: 0x0
            nGUI::SEQUENCE* pSequence;  // offset: 0x0
        };  // offset: 0xb0
        union
        {
        public:
            u32 objectOffset;  // offset: 0x0
            nGUI::OBJECT* pObject;  // offset: 0x0
        };  // offset: 0xb8
        union
        {
        public:
            u32 objSequenceOffset;  // offset: 0x0
            nGUI::OBJ_SEQUENCE* pObjSequence;  // offset: 0x0
        };  // offset: 0xc0
        union
        {
        public:
            u32 initParamOffset;  // offset: 0x0
            nGUI::INIT_PARAM* pInitParam;  // offset: 0x0
        };  // offset: 0xc8
        union
        {
        public:
            u32 paramOffset;  // offset: 0x0
            nGUI::PARAM* pParam;  // offset: 0x0
        };  // offset: 0xd0
        union
        {
        public:
            u32 instanceOffset;  // offset: 0x0
            nGUI::INSTANCE* pInstance;  // offset: 0x0
        };  // offset: 0xd8
        union
        {
        public:
            u32 flowOffset;  // offset: 0x0
            nGUI::FLOW* pFlow;  // offset: 0x0
        };  // offset: 0xe0
        union
        {
        public:
            u32 flowProcessOffset;  // offset: 0x0
            nGUI::FLOW_PROCESS* pFlowProcess;  // offset: 0x0
        };  // offset: 0xe8
        union
        {
        public:
            u32 flowInputOffset;  // offset: 0x0
            nGUI::FLOW_INPUT* pFlowInput;  // offset: 0x0
        };  // offset: 0xf0
        union
        {
        public:
            u32 flowSwitchOffset;  // offset: 0x0
            nGUI::FLOW_SWITCH* pFlowSwitch;  // offset: 0x0
        };  // offset: 0xf8
        union
        {
        public:
            u32 flowFunctionOffset;  // offset: 0x0
            nGUI::FLOW_FUNCTION* pFlowFunction;  // offset: 0x0
        };  // offset: 0x100
        union
        {
        public:
            u32 actionOffset;  // offset: 0x0
            nGUI::ACTION* pAction;  // offset: 0x0
        };  // offset: 0x108
        union
        {
        public:
            u32 inputConditionOffset;  // offset: 0x0
            nGUI::INPUT_CONDITION* pInputCondition;  // offset: 0x0
        };  // offset: 0x110
        union
        {
        public:
            u32 switchOperatorOffset;  // offset: 0x0
            nGUI::SWITCH_OPERATOR* pSwitchOperator;  // offset: 0x0
        };  // offset: 0x118
        union
        {
        public:
            u32 switchConditionOffset;  // offset: 0x0
            nGUI::SWITCH_CONDITION* pSwitchCondition;  // offset: 0x0
        };  // offset: 0x120
        union
        {
        public:
            u32 variableOffset;  // offset: 0x0
            nGUI::VARIABLE* pVariable;  // offset: 0x0
        };  // offset: 0x128
        union
        {
        public:
            u32 textureOffset;  // offset: 0x0
            nGUI::TEXTURE* pTexture;  // offset: 0x0
        };  // offset: 0x130
        union
        {
        public:
            u32 fontOffset;  // offset: 0x0
            nGUI::FONT* pFont;  // offset: 0x0
        };  // offset: 0x138
        union
        {
        public:
            u32 fontFilterOffset;  // offset: 0x0
            void* pFontFilter;  // offset: 0x0
        };  // offset: 0x140
        union
        {
        public:
            u32 messageOffset;  // offset: 0x0
            nGUI::MESSAGE* pMessage;  // offset: 0x0
        };  // offset: 0x148
        union
        {
        public:
            u32 guiResourceOffset;  // offset: 0x0
            nGUI::GUIRESOURCE* pGUIResource;  // offset: 0x0
        };  // offset: 0x150
        union
        {
        public:
            u32 generalResourceOffset;  // offset: 0x0
            nGUI::GENERALRESOURCE* pGeneralResource;  // offset: 0x0
        };  // offset: 0x158
        union
        {
        public:
            u32 cameraSettingOffset;  // offset: 0x0
            nGUI::CAMERA_SETTING* pCameraSetting;  // offset: 0x0
        };  // offset: 0x160
        union
        {
        public:
            u32 stringOffset;  // offset: 0x0
            MT_STR pString;  // offset: 0x0
        };  // offset: 0x168
        union
        {
        public:
            u32 keyOffset;  // offset: 0x0
            nGUI::KEY* pKey;  // offset: 0x0
        };  // offset: 0x170
        union
        {
        public:
            u32 keyValue8Offset;  // offset: 0x0
            u8* pKeyValue8;  // offset: 0x0
        };  // offset: 0x178
        union
        {
        public:
            u32 keyValue32Offset;  // offset: 0x0
            u8* pKeyValue32;  // offset: 0x0
        };  // offset: 0x180
        union
        {
        public:
            u32 keyValue128Offset;  // offset: 0x0
            u8* pKeyValue128;  // offset: 0x0
        };  // offset: 0x188
        union
        {
        public:
            u32 extendDataOffset;  // offset: 0x0
            u8* pExtendData;  // offset: 0x0
        };  // offset: 0x190
        union
        {
        public:
            u32 instExeParamOffset;  // offset: 0x0
            nGUI::PARAM* pInstExeParam;  // offset: 0x0
        };  // offset: 0x198
        union
        {
        public:
            u32 vertexOffset;  // offset: 0x0
            nGUI::VERTEX* pVertex;  // offset: 0x0
        };  // offset: 0x1a0
    };
public:
    struct InstanceNeedObjectInfo
    {
    public:
        static void* operator new(size_t);
        static void* operator new[](size_t);
        static void* operator new(size_t, void*);
        static void* operator new[](size_t, void*);
        static void operator delete(void*);
        static void operator delete[](void*);
    public:
        u32 objTextNeedNum;  // offset: 0x0
        u32 objMessageNeedNum;  // offset: 0x4
        u32 objChildAnimationRootNeedNum;  // offset: 0x8
        u32 objNullNeedNum;  // offset: 0xc
        u32 objTextureSetNeedNum;  // offset: 0x10
        u32 objTextureNeedNum;  // offset: 0x14
        u32 objPolygonNeedNum;  // offset: 0x18
        u32 objScissorMaskNeedNum;  // offset: 0x1c
        u32 objColorAdjustNeedNum;  // offset: 0x20
        u32 objRootNeedNum;  // offset: 0x24
        u32 createAnimationBufferSize;  // offset: 0x28
        u32 objRootNeedSetObjectBufferSize;  // offset: 0x2c
    };
public:
    struct AnimationSearch
    {
    public:
        static void* operator new(size_t);
        static void* operator new[](size_t);
        static void* operator new(size_t, void*);
        static void* operator new[](size_t, void*);
        static void operator delete(void*);
        static void operator delete[](void*);
    public:
        u32 InstanceIndex;  // offset: 0x0
        u32 ResourceID;  // offset: 0x4
        u32 AnimationID;  // offset: 0x8
    };
public:
    struct ObjectSearch
    {
    public:
        static void* operator new(size_t);
        static void* operator new[](size_t);
        static void* operator new(size_t, void*);
        static void* operator new[](size_t, void*);
        static void operator delete(void*);
        static void operator delete[](void*);
    public:
        u32 InstanceIndex;  // offset: 0x0
        rGUI* pGUI;  // offset: 0x8
        u32 AnimationID;  // offset: 0x10
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
    rGUI();
    virtual ~rGUI();
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool loadEnd();  // vtable slot 10
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual void clear();  // vtable slot 15
    virtual bool setData();  // vtable slot 16
    bool hasNative();
    bool isSetData() const;
    u32 getBaseZ() const;
    nGUI::LANGUAGE_SETTING getLanguageSettingNo() const;
    nDraw::VertexBuffer* getVertexBuffer() const;
    virtual t64 getUpdateTime2() const;  // vtable slot 17
    u32 getInstanceId() const;
    u32 getFlowId() const;
    u32 getVariableId() const;
    u32 getSequenceNum() const;
    nGUI::SEQUENCE* getSequence(u32 id) const;
    nGUI::SEQUENCE* getSequenceAdrs() const;
    u32 getInitParamNum() const;
    nGUI::INIT_PARAM* getInitParam() const;
    u32 getParamNum() const;
    nGUI::PARAM* getParam() const;
    u32 getObjectNum() const;
    nGUI::OBJECT* getObjectAdrs() const;
    u32 getAnimationNum() const;
    nGUI::ANIMATION* getAnimationAdrs() const;
    nGUI::ANIMATION* getAnimation(u32 id) const;
    u32 getInstanceNum() const;
    u32 getStartInstanceIndex() const;
    nGUI::INSTANCE* getInstanceAdrs() const;
    nGUI::INSTANCE* getInstance(u32 id) const;
    nGUI::FLOW* getStartFlow() const;
    u32 getFlowNum() const;
    nGUI::FLOW* getFlowAdrs() const;
    u32 getFlowProcessNum() const;
    nGUI::FLOW_PROCESS* getFlowProcessAdrs() const;
    u32 getFlowSwitchNum() const;
    nGUI::FLOW_SWITCH* getFlowSwitchAdrs() const;
    u32 getFlowFunctionNum() const;
    nGUI::FLOW_FUNCTION* getFlowFunctionAdrs() const;
    u32 getVariableNum() const;
    nGUI::VARIABLE* getVariableAdrs() const;
    u32 getTextureNum() const;
    nGUI::TEXTURE* getTextureFromId(u32 id) const;
    nGUI::TEXTURE* getTextureFromName(MT_CTSTR pName) const;
    rTexture* replaceTexture(u32 id, rTexture* pTexture);
    u32 getFontNum() const;
    nGUI::FONT* getFontFromId(u32 id) const;
    virtual u32 getFontFilterNum() const;  // vtable slot 18
    virtual cGUIFontFilter* getFontFilterFromId(u32 id) const;  // vtable slot 19
    u32 getMessageNum() const;
    nGUI::MESSAGE* getMessageFromId(u32 id) const;
    u32 getGUIResourceNum() const;
    nGUI::GUIRESOURCE* getGUIResourceFromId(u32 id) const;
    u32 getGeneralResourceNum() const;
    nGUI::GENERALRESOURCE* getGeneralResourceFromId(u32 id) const;
    u32 getCameraSettingNum() const;
    nGUI::CAMERA_SETTING* getCameraSettingAdrs() const;
    nGUI::CAMERA_SETTING* getCameraSettingFromId(nGUI::CAMERA_SETTING_ID id) const;
    u32 getInstExeParamNum() const;
    nGUI::PARAM* getInstExeParamAdrs() const;
    void setViewSize(const MtSize&);
    MtSize getViewSize() const;
    void setPreviewUnitName(const MtString&);
    MT_CTSTR getPreviewUnitName() const;
    void getRelativePath(MT_STR retPath, u32 length, MT_CTSTR srcPath);
    static void getRelativePath(MT_STR retPath, u32 length, MT_CTSTR basePath, MT_CTSTR srcPath);
    void getResourcePath(MT_STR retPath, u32 length, MT_CTSTR srcPath);
    static void getResourcePath(MT_STR retPath, u32 length, MT_CTSTR basePath, MT_CTSTR srcPath);
    bool isUseAlphaMask() const;
    bool is3D() const;
    nGUI::FRAMERATE_MODE getFramerateMode() const;
    void setFramerateMode(nGUI::FRAMERATE_MODE mode);
    u32 getInstanceNullNeedNum() const;
    u32 getInstanceScissorMaskNeedNum() const;
    u32 getInstanceAnimationNeedNum() const;
    u32 getInstanceAnimVariableNeedNum() const;
    u32 getInstanceAnimControlNeedNum() const;
    u32 getGUIObjTextNeedNum() const;
    u32 getGUIObjMessageNeedNum() const;
    u32 getGUIObjChildAnimationRootNeedNum() const;
    u32 getGUIObjNullNeedNum() const;
    u32 getGUIObjTextureSetNeedNum() const;
    u32 getGUIObjTextureNeedNum() const;
    u32 getGUIObjPolygonNeedNum() const;
    u32 getGUIObjScissorMaskNeedNum() const;
    u32 getGUIObjColorAdjustNeedNum() const;
    u32 getGUIObjRootNeedNum() const;
    u32 getGUIVarIntNeedNum() const;
    u32 getGUIVarFloatNeedNum() const;
    const InstanceNeedObjectInfo* getInstanceNeedObjectInfoPtr(u32 InstanceID) const;
    u32 getCreateAnimationBufferSize() const;
    u32 getObjRootNeedSetObjectBufferSize() const;
protected:
    void setIsSetData(bool v);
    void setBaseZ(u32 type);
    void setLanguageSettingNo(u32 v);
    void setUseAlphaMask(bool e);
    void set3D(bool e);
    virtual void* memAlloc(u32 size);  // vtable slot 20
    virtual void memFree(void* p_addr);  // vtable slot 21
private:
    nGUI::TEXTURE* getTextureAdrs() const;
    nGUI::FONT* getFontAdrs() const;
    nGUI::GUIRESOURCE* getGUIResourceAdrs() const;
    nGUI::GENERALRESOURCE* getGeneralResourceAdrs() const;
    nGUI::MESSAGE* getMessageAdrs() const;
    void createFontFilter();
protected:
    HEADER* mpHeader;  // offset: 0x70
    u32 mAttr;  // offset: 0x78
    u32 mIsSetData : 1;  // offset: 0x7c
    u32 mBaseZ : 2;  // offset: 0x7c
    u32 mFramerateMode : 1;  // offset: 0x7c
    u32 mLanguageSettingNo : 2;  // offset: 0x7c
    u32 padding : 26;  // offset: 0x7c
    MtSize mViewSize;  // offset: 0x80
    MtString mPreviewUnitName;  // offset: 0x88
    cGUIFontFilter* * mpFontFilter;  // offset: 0x90
    nDraw::VertexBuffer* mpVertexBuffer;  // offset: 0x98
    InstanceNeedObjectInfo* mpInstanceNeedObjectInfo;  // offset: 0xa0
    u32 mInstanceNullNeedNum;  // offset: 0xa8
    u32 mInstanceScissorMaskNeedNum;  // offset: 0xac
    u32 mInstanceAnimationNeedNum;  // offset: 0xb0
    u32 mInstanceAnimVariableNeedNum;  // offset: 0xb4
    u32 mInstanceAnimControlNeedNum;  // offset: 0xb8
    u32 mGUIObjTextNeedNum;  // offset: 0xbc
    u32 mGUIObjMessageNeedNum;  // offset: 0xc0
    u32 mGUIObjChildAnimationRootNeedNum;  // offset: 0xc4
    u32 mGUIObjNullNeedNum;  // offset: 0xc8
    u32 mGUIObjTextureSetNeedNum;  // offset: 0xcc
    u32 mGUIObjTextureNeedNum;  // offset: 0xd0
    u32 mGUIObjPolygonNeedNum;  // offset: 0xd4
    u32 mGUIObjScissorMaskNeedNum;  // offset: 0xd8
    u32 mGUIObjColorAdjustNeedNum;  // offset: 0xdc
    u32 mGUIObjRootNeedNum;  // offset: 0xe0
    u32 mGUIVarIntNeedNum;  // offset: 0xe4
    u32 mGUIVarFloatNeedNum;  // offset: 0xe8
    u32 mCreateAnimationBufferSize;  // offset: 0xec
    u32 mObjRootNeedSetObjectBufferSize;  // offset: 0xf0
public:
    static MyDTI DTI;
    static const u32 VERSION = 139027;
private:
    static const u32 ATTR_USE_ALPHA_MASK = 1;
    static const u32 ATTR_3D = 2;
};
