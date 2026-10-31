#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtObject.h"
#include "sCamera.h"

// Forward declarations
class MtAllocator;
class MtDTI;
struct MtFloat3;
class MtHermiteCurve;
class MtObject;
class MtPropertyList;
class MtString;
class MtVector3;
class MtVector4;
class cGUIFontFilter;
class cGUIObject;
namespace nDraw { class Texture; }
namespace nGUI { class Draw; }
class rGUIFont;
class rTexture;

// Declarations
namespace nGUI { struct ACTION; }
namespace nGUI { struct ANIMATION; }
namespace nGUI { class BlendState; }
namespace nGUI { struct BufferObject; }
namespace nGUI { struct CAMERA_SETTING; }
namespace nGUI { struct FLOW; }
namespace nGUI { struct FLOW_FUNCTION; }
namespace nGUI { struct FLOW_INPUT; }
namespace nGUI { struct FLOW_PROCESS; }
namespace nGUI { struct FLOW_SWITCH; }
namespace nGUI { struct FONT; }
namespace nGUI { struct GENERALRESOURCE; }
namespace nGUI { struct GUIRESOURCE; }
namespace nGUI { struct ICON_INFO; }
namespace nGUI { struct INIT_PARAM; }
namespace nGUI { struct INPUT_CONDITION; }
namespace nGUI { struct INSTANCE; }
namespace nGUI { struct KEY; }
namespace nGUI { struct MESSAGE; }
namespace nGUI { struct MTAG; }
namespace nGUI { struct OBJECT; }
namespace nGUI { struct OBJ_SEQUENCE; }
namespace nGUI { struct PARAM; }
namespace nGUI { struct PARAM_WORK; }
namespace nGUI { struct PROCESS_WORK; }
namespace nGUI { struct SEQUENCE; }
namespace nGUI { struct SWITCH_CONDITION; }
namespace nGUI { struct SWITCH_OPERATOR; }
namespace nGUI { class SamplerState; }
namespace nGUI { struct TEXTURE; }
namespace nGUI { struct VARIABLE; }
namespace nGUI { struct VERTEX; }
namespace nGUI { struct PROP_SETTER; }
namespace nGUI { struct MessageDrawState; }
namespace nGUI { struct DRAW_LIST; }
namespace nGUI { struct ANIM_SECTION; }
namespace nGUI { struct CLASS_INFO; }
namespace nGUI { class WrapPoint; }
namespace nGUI { struct TEXT_STATUS; }
namespace nGUI { struct FreePolygonPoint; }
namespace nGUI { class Language; }

namespace nGUI {
    enum ALIGNMENT
    {
        ALIGNMENT_NONE = 0,
        ALIGNMENT_LT = 1,
        ALIGNMENT_CT = 2,
        ALIGNMENT_RT = 3,
        ALIGNMENT_LC = 4,
        ALIGNMENT_CC = 5,
        ALIGNMENT_RC = 6,
        ALIGNMENT_LB = 7,
        ALIGNMENT_CB = 8,
        ALIGNMENT_RB = 9,
        ALIGNMENT_NUM = 10,
    };
}  // namespace nGUI

namespace nGUI {
    enum AUTOWRAP
    {
        AUTOWRAP_NONE = 0,
        AUTOWRAP_WIDTH = 1,
        AUTOWRAP_POINT = 2,
        AUTOWRAP_NUM = 3,
    };
}  // namespace nGUI

namespace nGUI {
    enum BASE_Z
    {
        BASE_Z_ORIGIN = 0,
        BASE_Z_PARALLAX_ZERO = 1,
        BASE_Z_NEAR_CLIP = 2,
        BASE_Z_NUM = 3,
    };
}  // namespace nGUI

namespace nGUI {
    enum BILLBOARD
    {
        BILLBOARD_NONE = 0,
        BILLBOARD_XYZ = 1,
        BILLBOARD_Y = 2,
        BILLBOARD_NUM = 3,
    };
}  // namespace nGUI

namespace nGUI {
    enum COLOR_CONTROL
    {
        COLOR_CONTROL_SCALING = 0,
        COLOR_CONTROL_ATTRIBUTE = 1,
        COLOR_CONTROL_NONE = 2,
        COLOR_CONTROL_NUM = 3,
    };
}  // namespace nGUI

namespace nGUI {
    enum DEPTH_STATE
    {
        DEPTH_FOLLOW = 0,
        DEPTH_DISABLE = 1,
        DEPTH_TEST = 2,
        DEPTH_WRITE = 3,
        DEPTH_TEST_WRITE = 4,
        DEPTH_STATE_NUM = 5,
    };
}  // namespace nGUI

namespace nGUI {
    enum DRAW_PASS
    {
        DRAW_PASS_FOLLOW = 0,
        DRAW_PASS_SOLID = 1,
        DRAW_PASS_SCREEN = 2,
        DRAW_PASS_TRANSPARENT = 3,
        DRAW_PASS_NUM = 4,
        DRAW_PASS_USER_OFFSET = 16,
    };
}  // namespace nGUI

namespace nGUI {
    enum END_CONDITION_TYPE
    {
        EC_FLOW_ANIMATION_END = 0,
        EC_FRAME_COUNT = 1,
        EC_INFINITE = 2,
        EC_CHANGE_VARIABLE = 3,
        EC_ANIMATION_END = 4,
        END_CONDITION_TYPE_NUM = 5,
    };
}  // namespace nGUI

namespace nGUI {
    enum FLOW_TYPE
    {
        FLOW_TYPE_START = 0,
        FLOW_TYPE_END = 1,
        FLOW_TYPE_PROCESS = 2,
        FLOW_TYPE_INPUT = 3,
        FLOW_TYPE_SWITCH = 4,
        FLOW_TYPE_FUNCTION = 5,
        FLOW_TYPE_NUM = 6,
    };
}  // namespace nGUI

namespace nGUI {
    enum FRAMERATE_MODE
    {
        FRAMERATE_60FPS = 0,
        FRAMERATE_30FPS = 1,
        FRAMERATE_MODE_NUM = 2,
    };
}  // namespace nGUI

namespace nGUI {
    enum GENDER
    {
        GENDER_UNSPECIFIED = 0,
        GENDER_MALE = 1,
        GENDER_FEMALE = 2,
    };
}  // namespace nGUI

namespace nGUI {
    enum HW_PLATFORM
    {
        HW_PLATFORM_DEFAULT = 0,
        HW_PLATFORM_WINDOWS = 1,
        HW_PLATFORM_PS3 = 2,
        HW_PLATFORM_XBOX = 3,
        HW_PLATFORM_WIIU = 4,
        HW_PLATFORM_XBOXONE = 5,
        HW_PLATFORM_PS4 = 6,
        HW_PLATFORM_NUM = 7,
    };
}  // namespace nGUI

namespace nGUI {
    enum ICON_COLOR_TYPE
    {
        ICON_COLOR_NOINFLUENCE = 0,
        ICON_COLOR_ALPHA = 1,
        ICON_COLOR_ALL = 2,
        ICON_COLOR_TYPE_NUM = 3,
    };
}  // namespace nGUI

namespace nGUI {
    enum LANGUAGE
    {
        LANGUAGE_JAPANESE = 0,
        LANGUAGE_ENGLISH = 1,
        LANGUAGE_FRENCH = 2,
        LANGUAGE_SPANISH = 3,
        LANGUAGE_GERMAN = 4,
        LANGUAGE_ITALIAN = 5,
        LANGUAGE_KOREAN = 6,
        LANGUAGE_CHINESE_T = 7,
        LANGUAGE_CHINESE_S = 8,
        LANGUAGE_PORTUGUESE = 9,
        LANGUAGE_RUSSIAN = 10,
        LANGUAGE_POLISH = 11,
        LANGUAGE_DUTCH = 12,
        LANGUAGE_FINNISH = 13,
        LANGUAGE_SWEDISH = 14,
        LANGUAGE_DANISH = 15,
        LANGUAGE_NORWEGIAN = 16,
        LANGUAGE_CZECH = 17,
        LANGUAGE_HUNGARIAN = 18,
        LANGUAGE_SLOVAK = 19,
        LANGUAGE_OTHER = 20,
        LANGUAGE_PORTUGUESE_BR = 21,
        LANGUAGE_NUM = 22,
        LANGUAGE_INVALID = -1,
    };
}  // namespace nGUI

namespace nGUI {
    enum LANGUAGE_SETTING
    {
        LANGUAGE_SETTING0 = 0,
        LANGUAGE_SETTING1 = 1,
        LANGUAGE_SETTING2 = 2,
        LANGUAGE_SETTING_NUM = 3,
    };
}  // namespace nGUI

namespace nGUI {
    enum LETTER_HALIGN
    {
        LETTER_HALIGN_LEFT = 0,
        LETTER_HALIGN_CENTER = 1,
        LETTER_HALIGN_RIGHT = 2,
        LETTER_HALIGN_NUM = 3,
    };
}  // namespace nGUI

namespace nGUI {
    enum LETTER_VALIGN
    {
        LETTER_VALIGN_TOP = 0,
        LETTER_VALIGN_CENTER = 1,
        LETTER_VALIGN_BOTTOM = 2,
        LETTER_VALIGN_BASELINE = 3,
        LETTER_VALIGN_NUM = 4,
    };
}  // namespace nGUI

namespace nGUI {
    enum MASK_TYPE
    {
        MASK_TYPE_NONE = 0,
        MASK_TYPE_ON = 1,
        MASK_TYPE_REVERSE = 2,
        MASK_TYPE_ALPHA = 3,
        MASK_TYPE_ON_ADD = 4,
        MASK_TYPE_REVERSE_ADD = 5,
        MASK_TYPE_ALPHA_ADD = 6,
        MASK_TYPE_NUM = 7,
    };
}  // namespace nGUI

namespace nGUI {
    enum PARAM_TYPE
    {
        PARAM_TYPE_UNKNOWN = 0,
        PARAM_TYPE_INT = 1,
        PARAM_TYPE_FLOAT = 2,
        PARAM_TYPE_BOOL = 3,
        PARAM_TYPE_VECTOR = 4,
        PARAM_TYPE_RESOURCE = 5,
        PARAM_TYPE_STRING = 6,
        PARAM_TYPE_TEXTURE = 7,
        PARAM_TYPE_FONT = 8,
        PARAM_TYPE_MESSAGE = 9,
        PARAM_TYPE_VARIABLE = 10,
        PARAM_TYPE_ANIMATION = 11,
        PARAM_TYPE_EVENT = 12,
        PARAM_TYPE_GUIRESOURCE = 13,
        PARAM_TYPE_FONT_FILTER = 14,
        PARAM_TYPE_ANIMEVENT = 15,
        PARAM_TYPE_SEQUENCE = 16,
        PARAM_TYPE_INIT_BOOL = 17,
        PARAM_TYPE_INIT_INT = 18,
        PARAM_TYPE_GENERALRESOURCE = 19,
    };
}  // namespace nGUI

namespace nGUI {
    enum RESOLUTION_ADJUST
    {
        RESOLUTION_ADJUST_FOLLOW = 0,
        RESOLUTION_ADJUST_NONE = 1,
        RESOLUTION_ADJUST_VARIABLE = 2,
        RESOLUTION_ADJUST_VARIABLE_STRETCH = 3,
        RESOLUTION_ADJUST_VARIABLE_SHRINK = 4,
        RESOLUTION_ADJUST_SMALLPROP = 5,
        RESOLUTION_ADJUST_SMALLPROP_STRETCH = 6,
        RESOLUTION_ADJUST_SMALLPROP_SHRINK = 7,
        RESOLUTION_ADJUST_BIGPROP = 8,
        RESOLUTION_ADJUST_BIGPROP_STRETCH = 9,
        RESOLUTION_ADJUST_BIGPROP_SHRINK = 10,
        RESOLUTION_ADJUST_NUM = 11,
    };
}  // namespace nGUI

namespace nGUI {
    enum SCALING_TYPE
    {
        SCALING_TYPE_NONE = 0,
        SCALING_TYPE_POSITION = 1,
        SCALING_TYPE_SIZE = 2,
        SCALING_TYPE_FULL = 3,
        SCALING_TYPE_NUM = 4,
    };
}  // namespace nGUI

namespace nGUI {
    enum TEXT_CONDITION
    {
        TEXT_CONDITION_STOP = 0,
        TEXT_CONDITION_NORMAL = 1,
        TEXT_CONDITION_TIME = 2,
        TEXT_CONDITION_STAY = 3,
        TEXT_CONDITION_PAGE = 4,
        TEXT_CONDITION_DISP = 5,
        TEXT_CONDITION_NUM = 6,
    };
}  // namespace nGUI

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_MFUNC = void(MtObject::*)();
using u32 = unsigned int;
using SO_HANDLE = u32;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using __uintptr_t = __uint64_t;
using f32 = float;
namespace nGUI { using CAMERA_SETTING_ID = u32; }
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u8 = unsigned char;
using uintptr = __uintptr_t;

namespace nGUI {

    // Forward declarations
    struct PROP_SETTER;
    struct MessageDrawState;
    struct DRAW_LIST;
    struct ANIM_SECTION;
    struct CLASS_INFO;
    class WrapPoint;
    struct TEXT_STATUS;
    struct FreePolygonPoint;
    class Language;

    struct PROP_SETTER
    {
    public:
        void setInteger(MtObject* pOwner, const s32 v) const;
        void setU32(MtObject* pOwner, const u32 v) const;
        void setF32(MtObject* pOwner, const f32 v) const;
        void setString(MtObject* pOwner, MT_CTSTR v) const;
        void setBool(MtObject* pOwner, const bool v) const;
        void setVector4(MtObject* pOwner, const MtVector4& v) const;
        void callEvent(MtObject* pOwner, u32 param) const;
    public:
        u32 type : 16;  // offset: 0x0
        u32 callNo : 16;  // offset: 0x0
        MT_CTSTR name;  // offset: 0x8
        MT_MFUNC func;  // offset: 0x10
    };

    struct MessageDrawState
    {
    public:
        MessageDrawState(nGUI::Draw* pDraw, nGUI::BufferObject* vo, nGUI::BufferObject* io, nGUI::MTAG* * pMTag, nGUI::MTAG* pDrawStart, nGUI::MTAG* pDrawEnd, bool pe, cGUIFontFilter* pFilter, u32 index);
        void setColor(u32 col, u32 type);
        nGUI::MTAG* searchDrawMTag(nGUI::MTAG* pMTag, nDraw::Texture* pTexture) const;
        nGUI::MTAG* searchDrawExtendMTag(nGUI::MTAG* pMTag, nGUI::MTAG* pExtendMTag) const;
        nGUI::MTAG* searchDrawLineMTag(nGUI::MTAG* pMTag, nGUI::MTAG* pLineMTag) const;
    public:
        rGUIFont* pFont;  // offset: 0x0
        cGUIFontFilter* pFontFilter;  // offset: 0x8
        u32 ffIndex;  // offset: 0x10
        u32 zbiasOffset;  // offset: 0x14
        u32 color;  // offset: 0x18
        u32 iconColor;  // offset: 0x1c
        f32 fontWidth;  // offset: 0x20
        f32 fontHeight;  // offset: 0x24
        bool pageEnd;  // offset: 0x28
        bool is3D;  // offset: 0x29
        nGUI::MTAG* pDrawStartMTag;  // offset: 0x30
        nGUI::MTAG* pDrawEndMTag;  // offset: 0x38
        nGUI::MTAG* * ppDrawMTagTop;  // offset: 0x40
        nGUI::MTAG* pDrawSearchTopMTag;  // offset: 0x48
        nGUI::Draw* pDrawObj;  // offset: 0x50
        nGUI::VERTEX* pVertex;  // offset: 0x58
        nGUI::BufferObject* pVertexObject;  // offset: 0x60
        u16* pIndex;  // offset: 0x68
        nGUI::BufferObject* pIndexObject;  // offset: 0x70
    };

    struct DRAW_LIST
    {
    public:
        enum TYPE
        {
            TYPE_DRAW_BEGIN = 0,
            TYPE_DRAW_END = 1,
            TYPE_END = 2,
        };
    public:
        u32 type;  // offset: 0x0
        cGUIObject* pObject;  // offset: 0x8
    };

    struct ANIM_SECTION
    {
    public:
        u32 id;  // offset: 0x0
        u32 attr : 16;  // offset: 0x4
        u32 padding : 16;  // offset: 0x4
        s32 value;  // offset: 0x8
        union
        {
        public:
            f32 startFrame;  // offset: 0x0
            u32 sequenceId;  // offset: 0x0
        };  // offset: 0xc
        f32 endFrame;  // offset: 0x10
        static const u32 ATTR_LOOP = 1;
        static const u32 ATTR_REVERSE = 2;
    };

    struct CLASS_INFO
    {
    public:
        u32 dtiId;  // offset: 0x0
        u32 setterNum;  // offset: 0x4
        const nGUI::PROP_SETTER* pPropSetter;  // offset: 0x8
    };

    class WrapPoint : public ::MtObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        static MtDTI* getMyDTIPtr();
        virtual const MtDTI& getDTI() const;  // vtable slot 5
        static MtAllocator* getAllocator();
        static void setAllocator(u32);
        static void operator delete(void* p_addr);
        virtual ~WrapPoint() {}
        u32 getUnicode() const;
        bool isStartNewLineAfterContdWrapPts() const;
        void setStartNewLineAfterContdWrapPts(bool);
        bool isValid() const;
        void setValid(bool);
    private:
        WrapPoint();
    public:
        static void* operator new(size_t sz, u32 align);
        static void usage();
        static void* operator new[](size_t sz, u32 align);
        static void* operator new(size_t sz, void* p_addr);
        static void* operator new[](size_t sz, void* p_addr);
        static void operator delete[](void* p_addr);
        static void operator delete(void* p_addr, u32 align);
        static void operator delete[](void* p_addr, u32 align);
        WrapPoint(u32 unicode, bool startNewLineAfterContdWrapPts, bool isValid);
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    private:
        u32 mUnicode;  // offset: 0x8
        bool mStartNewLineAfterContdWrapPts;  // offset: 0xc
        bool mIsValid;  // offset: 0xd
    public:
        static MyDTI DTI;
    };

    struct TEXT_STATUS
    {
    public:
        TEXT_STATUS();
    private:
        s32 position;  // offset: 0x0
        nGUI::TEXT_CONDITION condition;  // offset: 0x4
    };

    struct FreePolygonPoint
    {
    public:
        MtVector3 pos;  // offset: 0x0
    };

    class Language : public ::MtObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        static nGUI::LANGUAGE getLanguageId(MT_CTSTR language);
        static MT_CTSTR getLanguageName(nGUI::LANGUAGE language);
        static MT_CTSTR getLanguageShortName(nGUI::LANGUAGE language);
        static nGUI::LANGUAGE getLanguageFromApp(u32 index);
    public:
        static MyDTI DTI;
    private:
        static MT_CTSTR LANGUAGE_NAME[22];
        static MT_CTSTR LANGUAGE_SHORT_NAME[22];
    };

    void calcScale(f32& offsetScale, f32& objectScale, const f32 localScale, const f32 parentScale, const SCALING_TYPE type);
    u32 getLocalIdFromSystemFontFilterId(u32 id);
    bool isUseSystemFontFilter(u32 id);
    u32 getUTF8ByteCount(MT_CTSTR pChar);
    const MtDTI& getTextureDTIFromRType(u32 rtype);
    f32 getFramerate(FRAMERATE_MODE mode);
    void initProperty(MtObject* pOwner, INIT_PARAM* pInitParam);
    void playProperty(f32 frame, f32 bFrame, PARAM_WORK* pParamWork, bool forcePlay);
    u32 popToUnicode(u32& code, MT_CTSTR& pStr);
    void replaceInvalidCharcter(MtString& dstString, MT_CTSTR srcString, MT_CTSTR replaceString, const rGUIFont* pFont);
    MtVector4 getScreenPos(const MtVector3& pos, const sCamera::VIEWPORT_NO vpNo, f32* pProjZ);
    bool checkName(MT_CTSTR name);

}  // namespace nGUI

namespace nGUI {
    struct ACTION
    {
    public:
        u32 type;  // offset: 0x0
        u32 objectIndex;  // offset: 0x4
        union
        {
        public:
            u32 substitutionIndex;  // offset: 0x0
            s32 value;  // offset: 0x0
        };  // offset: 0x8
        union
        {
        public:
            u32 propNameOffset;  // offset: 0x0
            MT_CTSTR propName;  // offset: 0x0
        };  // offset: 0x10
    };
}  // namespace nGUI

namespace nGUI {
    struct ANIMATION
    {
    public:
        u32 id;  // offset: 0x0
        u32 objectNum : 16;  // offset: 0x4
        u32 sequenceNum : 16;  // offset: 0x4
        u32 drawableObjectNum : 16;  // offset: 0x8
        u32 animateParamNum : 16;  // offset: 0x8
        u32 objectIndex;  // offset: 0xc
        union
        {
        public:
            u32 nameOffset;  // offset: 0x0
            MT_CTSTR pName;  // offset: 0x0
        };  // offset: 0x10
        union
        {
        public:
            u32 sequenceIndex;  // offset: 0x0
            nGUI::SEQUENCE* pSequence;  // offset: 0x0
        };  // offset: 0x18
    };
}  // namespace nGUI

namespace nGUI {
    class BlendState : public ::MtObject
    {
    public:
        enum BLEND_MODE
        {
            BLEND_DEFAULT = 0,
            BLEND_BlendAlpha = 1,
            BLEND_BlendInvAlpha = 2,
            BLEND_Add = 3,
            BLEND_Mul = 4,
            BLEND_AddAlpha = 5,
            BLEND_AddInvAlpha = 6,
            BLEND_BlendFactor = 7,
            BLEND_BlendFactorAlpha = 8,
            BLEND_Max = 9,
            BLEND_AddColor = 10,
            BLEND_BlendColor = 11,
            BLEND_RevSubAlpha = 12,
            BLEND_RevSubInvAlpha = 13,
            BLEND_RevSubBlendAlpha = 14,
            BLEND_RevSubColor = 15,
            BLEND_RevSubBlendColor = 16,
            BLEND_RevSub = 17,
            BLEND_ColorBlendAlphaAdd = 18,
            BLEND_AddRGB = 19,
            BLEND_AddInvColor = 20,
            BLEND_MODE_NUM = 21,
        };
    public:
        class MyDTI;
        struct BLEND_DATA;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        struct BLEND_DATA
        {
        public:
            SO_HANDLE handle;  // offset: 0x0
            bool alphaTest;  // offset: 0x4
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
        static const BLEND_DATA& getBlendData(BLEND_MODE mode);
    public:
        static MyDTI DTI;
    private:
        static const BLEND_DATA BLEND_DATA_TABLE[21];
    };
}  // namespace nGUI

namespace nGUI {
    struct BufferObject
    {
    public:
        BufferObject();
        bool isValid() const;
    public:
        u32 pos;  // offset: 0x0
        u32 size : 24;  // offset: 0x4
        u32 valid : 1;  // offset: 0x4
        u32 update : 3;  // offset: 0x4
        u32 commandCache : 1;  // offset: 0x4
        u32 type : 2;  // offset: 0x4
        u32 blank : 1;  // offset: 0x4
        nGUI::BufferObject* pBack;  // offset: 0x8
        nGUI::BufferObject* pNext;  // offset: 0x10
        static const u32 ALLOC_SIZE_MAX = 16777215;
    };
}  // namespace nGUI

namespace nGUI {
    struct CAMERA_SETTING
    {
    public:
        nGUI::CAMERA_SETTING_ID id;  // offset: 0x0
        f32 nearPlane;  // offset: 0x4
        f32 farPlane;  // offset: 0x8
        MtFloat3 cameraPos;  // offset: 0xc
        MtFloat3 targetPos;  // offset: 0x18
        MtFloat3 cameraUp;  // offset: 0x24
        union
        {
        public:
            u32 nameOffset;  // offset: 0x0
            MT_CTSTR pName;  // offset: 0x0
        };  // offset: 0x30
    };
}  // namespace nGUI

namespace nGUI {
    struct FLOW
    {
    public:
        u32 id;  // offset: 0x0
        u32 type;  // offset: 0x4
        u32 attr;  // offset: 0x8
        union
        {
        public:
            u32 nameOffset;  // offset: 0x0
            MT_CTSTR pName;  // offset: 0x0
        };  // offset: 0x10
        union
        {
        public:
            u32 nextIndex;  // offset: 0x0
            nGUI::FLOW* nextAdrs;  // offset: 0x0
            u32 processIndex;  // offset: 0x0
            u32 inputIndex;  // offset: 0x0
            nGUI::FLOW_INPUT* inputAdrs;  // offset: 0x0
            u32 switchIndex;  // offset: 0x0
            nGUI::FLOW_SWITCH* switchAdrs;  // offset: 0x0
            u32 functionIndex;  // offset: 0x0
            nGUI::FLOW_FUNCTION* functionAdrs;  // offset: 0x0
        };  // offset: 0x18
        static const u32 ATTR_SKIPPABLE = 1;
    };
}  // namespace nGUI

namespace nGUI {
    struct FLOW_FUNCTION
    {
    public:
        union
        {
        public:
            u32 startIndex;  // offset: 0x0
            nGUI::FLOW* startAdrs;  // offset: 0x0
        };  // offset: 0x0
        union
        {
        public:
            u32 nextIndex;  // offset: 0x0
            nGUI::FLOW* nextAdrs;  // offset: 0x0
        };  // offset: 0x8
    };
}  // namespace nGUI

namespace nGUI {
    struct FLOW_INPUT
    {
    public:
        u32 conditionNum;  // offset: 0x0
        union
        {
        public:
            u32 conditionIndex;  // offset: 0x0
            nGUI::INPUT_CONDITION* conditionAdrs;  // offset: 0x0
        };  // offset: 0x8
    };
}  // namespace nGUI

namespace nGUI {
    struct FLOW_PROCESS
    {
    public:
        u32 isLoop : 8;  // offset: 0x0
        u32 loopStart : 24;  // offset: 0x0
        u32 totalFrame;  // offset: 0x4
        u32 paramNum;  // offset: 0x8
        u32 paramIndex;  // offset: 0xc
        u32 actionNum;  // offset: 0x10
        u32 endConditionType;  // offset: 0x14
        u32 endConditionParam;  // offset: 0x18
        union
        {
        public:
            u32 nextIndex;  // offset: 0x0
            nGUI::FLOW* nextAdrs;  // offset: 0x0
        };  // offset: 0x20
        union
        {
        public:
            u32 actionIndex;  // offset: 0x0
            nGUI::ACTION* actionAdrs;  // offset: 0x0
        };  // offset: 0x28
    };
}  // namespace nGUI

namespace nGUI {
    struct FLOW_SWITCH
    {
    public:
        u32 conditionNum;  // offset: 0x0
        union
        {
        public:
            u32 conditionIndex;  // offset: 0x0
            nGUI::SWITCH_CONDITION* conditionAdrs;  // offset: 0x0
        };  // offset: 0x8
    };
}  // namespace nGUI

namespace nGUI {
    struct FONT
    {
    public:
        u32 id;  // offset: 0x0
        rGUIFont* pFont;  // offset: 0x8
        union
        {
        public:
            u32 pathOffset;  // offset: 0x0
            MT_CTSTR path;  // offset: 0x0
        };  // offset: 0x10
    };
}  // namespace nGUI

namespace nGUI {
    struct GENERALRESOURCE
    {
    public:
        u32 id;  // offset: 0x0
        u32 dtiId;  // offset: 0x4
        void* pResource;  // offset: 0x8
        union
        {
        public:
            u32 pathOffset;  // offset: 0x0
            MT_CTSTR path;  // offset: 0x0
        };  // offset: 0x10
    };
}  // namespace nGUI

namespace nGUI {
    struct GUIRESOURCE
    {
    public:
        u32 id;  // offset: 0x0
        void* pResource;  // offset: 0x8
        union
        {
        public:
            u32 pathOffset;  // offset: 0x0
            MT_CTSTR path;  // offset: 0x0
        };  // offset: 0x10
    };
}  // namespace nGUI

namespace nGUI {
    struct ICON_INFO
    {
    public:
        MT_CTSTR iconName;  // offset: 0x0
        u32 code;  // offset: 0x8
    };
}  // namespace nGUI

namespace nGUI {
    struct INIT_PARAM
    {
    public:
        u32 paramType : 8;  // offset: 0x0
        const nGUI::PROP_SETTER* pFunc;  // offset: 0x8
        union
        {
        public:
            u32 propNameOffset;  // offset: 0x0
            MT_CTSTR propName;  // offset: 0x0
        };  // offset: 0x10
        union
        {
        public:
            u32 valueOffset;  // offset: 0x0
            u8* pValue;  // offset: 0x0
            bool bValue;  // offset: 0x0
            s32 iValue;  // offset: 0x0
        };  // offset: 0x18
    };
}  // namespace nGUI

namespace nGUI {
    struct INPUT_CONDITION
    {
    public:
        union
        {
        public:
            u32 nextIndex;  // offset: 0x0
            nGUI::FLOW* nextAdrs;  // offset: 0x0
        };  // offset: 0x0
    };
}  // namespace nGUI

namespace nGUI {
    struct INSTANCE
    {
    public:
        u32 id;  // offset: 0x0
        u32 attr;  // offset: 0x4
        u32 nextIndex;  // offset: 0x8
        u32 childIndex;  // offset: 0xc
        u32 initParamNum;  // offset: 0x10
        union
        {
        public:
            u32 nameOffset;  // offset: 0x0
            MT_CTSTR pName;  // offset: 0x0
        };  // offset: 0x18
        union
        {
        public:
            u32 dtiId;  // offset: 0x0
            const MtDTI* pDti;  // offset: 0x0
        };  // offset: 0x20
        union
        {
        public:
            u32 initParamIndex;  // offset: 0x0
            nGUI::INIT_PARAM* pInitParam;  // offset: 0x0
        };  // offset: 0x28
        union
        {
        public:
            u32 extendDataOffset;  // offset: 0x0
            void* pExtendData;  // offset: 0x0
        };  // offset: 0x30
        static const u32 ATTR_HITTEST = 1;
    };
}  // namespace nGUI

namespace nGUI {
    struct KEY
    {
    public:
        enum MODE
        {
            MODE_CONSTANT = 0,
            MODE_OFFSET = 1,
            MODE_TRIGGER = 2,
            MODE_LINEAR = 3,
            MODE_OFFSET_F = 4,
            MODE_HERMITE = 5,
            MODE_EASEIN = 6,
            MODE_EASEOUT = 7,
            MODE_HERMITE2 = 8,
            MODE_NUM = 9,
            MODE_SUMMARY = 10,
            MODE_DEFAULT = 11,
        };
    public:
        u32 frame : 24;  // offset: 0x0
        u32 mode : 8;  // offset: 0x0
        union
        {
        public:
            u32 curveOffset;  // offset: 0x0
            MtHermiteCurve* pCurve;  // offset: 0x0
        };  // offset: 0x8
    };
}  // namespace nGUI

namespace nGUI {
    struct MESSAGE
    {
    public:
        u32 id;  // offset: 0x0
        void* pMessage;  // offset: 0x8
        union
        {
        public:
            u32 pathOffset;  // offset: 0x0
            MT_CTSTR path;  // offset: 0x0
        };  // offset: 0x10
    };
}  // namespace nGUI

namespace nGUI {
    struct MTAG
    {
    public:
        enum TYPE
        {
            TYPE_FONT = 0,
            TYPE_SIZE = 1,
            TYPE_COLOR = 2,
            TYPE_SPEED = 3,
            TYPE_CHAR = 4,
            TYPE_ICON = 5,
            TYPE_SPACE = 6,
            TYPE_WORDWRAP = 7,
            TYPE_ANIM = 8,
            TYPE_TIME = 9,
            TYPE_STAY = 10,
            TYPE_PAGE = 11,
            TYPE_DISP = 12,
            TYPE_RUBY = 13,
            TYPE_RUBY_RB = 14,
            TYPE_RUBY_RT = 15,
            TYPE_CENTER = 16,
            TYPE_LEFT = 17,
            TYPE_RIGHT = 18,
            TYPE_EVENT = 19,
            TYPE_RGB = 20,
            TYPE_LINE = 21,
            TYPE_EXTEND = 22,
            TYPE_DRAW = 23,
            TYPE_FFLINE = 24,
            TYPE_NUM = 25,
        };
    public:
        struct FONT;
        struct SIZE;
        struct COLOR;
        struct SPEED;
        struct ANIM;
        struct WORDWRAP;
        struct TIME;
        struct CHAR;
        struct PAGE;
        struct DISP;
        struct RUBY;
        struct EVENT;
        struct LINE;
        struct EXTEND;
        struct DRAW;
        struct FFLINE;
    public:
        struct FONT
        {
        public:
            rGUIFont* pFont;  // offset: 0x0
        };
    public:
        struct SIZE
        {
        public:
            bool resize;  // offset: 0x0
            f32 fw;  // offset: 0x4
            f32 fh;  // offset: 0x8
        };
    public:
        struct COLOR
        {
        public:
            u32 color;  // offset: 0x0
        };
    public:
        struct SPEED
        {
        public:
            f32 speed;  // offset: 0x0
        };
    public:
        struct ANIM
        {
        public:
            u32 attr;  // offset: 0x0
            u32 id;  // offset: 0x4
            f32 x;  // offset: 0x8
        };
    public:
        struct WORDWRAP
        {
        public:
            u32 hyphen : 1;  // offset: 0x0
            f32 fw;  // offset: 0x4
            f32 fh;  // offset: 0x8
            rGUIFont* pt;  // offset: 0x10
        };
    public:
        struct TIME
        {
        public:
            u32 frame;  // offset: 0x0
        };
    public:
        struct CHAR
        {
        public:
            void* pt;  // offset: 0x0
            f32 x;  // offset: 0x8
            f32 y;  // offset: 0xc
            f32 width;  // offset: 0x10
            f32 offset;  // offset: 0x14
        };
    public:
        struct PAGE
        {
        public:
            f32 width;  // offset: 0x0
            f32 height;  // offset: 0x4
        };
    public:
        struct DISP
        {
        public:
            u32 frame;  // offset: 0x0
        };
    public:
        struct RUBY
        {
        public:
            f32 fontSize;  // offset: 0x0
            f32 width;  // offset: 0x4
            f32 height;  // offset: 0x8
        };
    public:
        struct EVENT
        {
        public:
            u32 type;  // offset: 0x0
            u32 param0;  // offset: 0x4
            u32 param1;  // offset: 0x8
        };
    public:
        struct LINE
        {
        public:
            f32 x;  // offset: 0x0
            f32 y;  // offset: 0x4
            f32 rubyHeight;  // offset: 0x8
            f32 ascent;  // offset: 0xc
            f32 descent;  // offset: 0x10
        };
    public:
        struct EXTEND
        {
        public:
            f32 x;  // offset: 0x0
            f32 y;  // offset: 0x4
            void* pData;  // offset: 0x8
        };
    public:
        struct DRAW
        {
        public:
            u32 totalCharNum : 16;  // offset: 0x0
            u32 charNum : 16;  // offset: 0x0
            u32 totalVertexNum : 16;  // offset: 0x4
            u32 vertexNum : 16;  // offset: 0x4
            u32 vertexPos;  // offset: 0x8
            u32 totalIndexNum : 16;  // offset: 0xc
            u32 indexNum : 16;  // offset: 0xc
            u32 indexPos;  // offset: 0x10
            nDraw::Texture* pTexture;  // offset: 0x18
            nGUI::MTAG* pExtend;  // offset: 0x20
        };
    public:
        struct FFLINE
        {
        public:
            nGUI::MTAG* pLine;  // offset: 0x0
            f32 param[4];  // offset: 0x8
        };
    public:
        u32 type : 8;  // offset: 0x0
        u32 attr : 8;  // offset: 0x0
        nGUI::MTAG* pNext;  // offset: 0x8
        union
        {
        public:
            struct
            {
            public:
                f32 width;  // offset: 0x0
                f32 height;  // offset: 0x4
                union
                {
                public:
                    nGUI::MTAG::FONT font;  // offset: 0x0
                    nGUI::MTAG::SIZE size;  // offset: 0x0
                    nGUI::MTAG::COLOR color;  // offset: 0x0
                    nGUI::MTAG::COLOR rgb;  // offset: 0x0
                    nGUI::MTAG::SPEED speed;  // offset: 0x0
                    nGUI::MTAG::ANIM anim;  // offset: 0x0
                    nGUI::MTAG::WORDWRAP wordwrap;  // offset: 0x0
                    nGUI::MTAG::TIME time;  // offset: 0x0
                    nGUI::MTAG::CHAR ch;  // offset: 0x0
                    nGUI::MTAG::PAGE page;  // offset: 0x0
                    nGUI::MTAG::DISP disp;  // offset: 0x0
                    nGUI::MTAG::RUBY ruby;  // offset: 0x0
                    nGUI::MTAG::EVENT event;  // offset: 0x0
                    nGUI::MTAG::LINE line;  // offset: 0x0
                    nGUI::MTAG::EXTEND extend;  // offset: 0x0
                };  // offset: 0x8
            };  // offset: 0x0
            nGUI::MTAG::DRAW draw;  // offset: 0x0
            nGUI::MTAG::FFLINE ffLine;  // offset: 0x0
        };  // offset: 0x10
        static const u32 ATTR_POP_END = 1;
        static const u32 ATTR_DRAW = 2;
    };
}  // namespace nGUI

namespace nGUI {
    struct OBJECT
    {
    public:
        u32 id;  // offset: 0x0
        u32 initParamNum : 8;  // offset: 0x4
        u32 animateParamNum : 8;  // offset: 0x4
        u32 padding : 16;  // offset: 0x4
        u32 nextIndex;  // offset: 0x8
        u32 childIndex;  // offset: 0xc
        union
        {
        public:
            u32 nameOffset;  // offset: 0x0
            MT_CTSTR pName;  // offset: 0x0
        };  // offset: 0x10
        union
        {
        public:
            u32 dtiId;  // offset: 0x0
            const MtDTI* pDti;  // offset: 0x0
        };  // offset: 0x18
        union
        {
        public:
            u32 initParamIndex;  // offset: 0x0
            nGUI::INIT_PARAM* pInitParam;  // offset: 0x0
        };  // offset: 0x20
        union
        {
        public:
            u32 objSequenceIndex;  // offset: 0x0
            nGUI::OBJ_SEQUENCE* pObjSequence;  // offset: 0x0
        };  // offset: 0x28
        union
        {
        public:
            u32 extendDataOffset;  // offset: 0x0
            void* pExtendData;  // offset: 0x0
        };  // offset: 0x30
    };
}  // namespace nGUI

namespace nGUI {
    struct OBJ_SEQUENCE
    {
    public:
        u32 attr : 16;  // offset: 0x0
        u32 initParamNum : 8;  // offset: 0x0
        u32 paramNum : 8;  // offset: 0x0
        u32 loopStart : 16;  // offset: 0x4
        u32 frameCount : 16;  // offset: 0x4
        union
        {
        public:
            u32 initParamIndex;  // offset: 0x0
            nGUI::INIT_PARAM* pInitParam;  // offset: 0x0
        };  // offset: 0x8
        union
        {
        public:
            u32 paramIndex;  // offset: 0x0
            nGUI::PARAM* pParam;  // offset: 0x0
        };  // offset: 0x10
        static const u32 ATTR_LOOP = 1;
        static const u32 ATTR_FIX_FRAME = 2;
    };
}  // namespace nGUI

namespace nGUI {
    struct PARAM
    {
    public:
        u32 paramType : 8;  // offset: 0x0
        u32 keyNum : 9;  // offset: 0x0
        const nGUI::PROP_SETTER* pFunc;  // offset: 0x8
        u32 parentId;  // offset: 0x10
        union
        {
        public:
            u32 propNameOffset;  // offset: 0x0
            MT_CTSTR propName;  // offset: 0x0
        };  // offset: 0x18
        union
        {
        public:
            u32 frameOffset;  // offset: 0x0
            nGUI::KEY* keyFrame;  // offset: 0x0
        };  // offset: 0x20
        union
        {
        public:
            u32 valueOffset;  // offset: 0x0
            u8* keyValue;  // offset: 0x0
        };  // offset: 0x28
    };
}  // namespace nGUI

namespace nGUI {
    struct PARAM_WORK
    {
    public:
        nGUI::PARAM* pParam;  // offset: 0x0
        u32 currentKey;  // offset: 0x8
        MtObject* pOwner;  // offset: 0x10
    };
}  // namespace nGUI

namespace nGUI {
    struct PROCESS_WORK
    {
    public:
        u32 paramWorkNum;  // offset: 0x0
        nGUI::PARAM_WORK* pParamWork;  // offset: 0x8
        nGUI::FLOW_PROCESS* pFlow;  // offset: 0x10
    };
}  // namespace nGUI

namespace nGUI {
    struct SEQUENCE
    {
    public:
        u32 id;  // offset: 0x0
        u32 frameCount;  // offset: 0x4
        union
        {
        public:
            u32 nameOffset;  // offset: 0x0
            MT_CTSTR pName;  // offset: 0x0
        };  // offset: 0x8
    };
}  // namespace nGUI

namespace nGUI {
    struct SWITCH_CONDITION
    {
    public:
        u32 type;  // offset: 0x0
        u32 operatorNum;  // offset: 0x4
        union
        {
        public:
            u32 nextIndex;  // offset: 0x0
            nGUI::FLOW* nextAdrs;  // offset: 0x0
        };  // offset: 0x8
        union
        {
        public:
            u32 operatorIndex;  // offset: 0x0
            nGUI::SWITCH_OPERATOR* operatorAdrs;  // offset: 0x0
        };  // offset: 0x10
        static const u32 OPERATOR_MAX = 3;
    };
}  // namespace nGUI

namespace nGUI {
    struct SWITCH_OPERATOR
    {
    public:
        s32 value;  // offset: 0x0
        u32 operatorType;  // offset: 0x4
        u32 objectIndex;  // offset: 0x8
    };
}  // namespace nGUI

namespace nGUI {
    class SamplerState : public ::MtObject
    {
    public:
        enum SAMPLER_MODE
        {
            SAMPLER_WrapLinear = 0,
            SAMPLER_ClampLinear = 1,
            SAMPLER_WrapPoint = 2,
            SAMPLER_ClampPoint = 3,
            SAMPLER_MODE_NUM = 4,
        };
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        static SO_HANDLE getHandle(SAMPLER_MODE mode);
    public:
        static MyDTI DTI;
    private:
        static const SO_HANDLE SAMPLER_DATA[4];
    };
}  // namespace nGUI

namespace nGUI {
    struct TEXTURE
    {
    public:
        enum RTYPE
        {
            RTYPE_TEXTURE = 0,
            RTYPE_RENDERTARGET = 1,
            RTYPE_NUM = 2,
        };
    public:
        void init();
    public:
        u32 id;  // offset: 0x0
        u32 rtype : 2;  // offset: 0x4
        u32 resize : 1;  // offset: 0x4
        s32 : 0;
        s32 l : 16;  // offset: 0x8
        s32 t : 16;  // offset: 0x8
        s32 r : 16;  // offset: 0xc
        s32 b : 16;  // offset: 0xc
        f32 clamp[4];  // offset: 0x10
        f32 invSize[2];  // offset: 0x20
        rTexture* pTexture;  // offset: 0x28
        union
        {
        public:
            uintptr pathOffset;  // offset: 0x0
            MT_CTSTR path;  // offset: 0x0
        };  // offset: 0x30
        union
        {
        public:
            uintptr nameOffset;  // offset: 0x0
            MT_CTSTR pName;  // offset: 0x0
        };  // offset: 0x38
    };
}  // namespace nGUI

namespace nGUI {
    struct VARIABLE
    {
    public:
        u32 id;  // offset: 0x0
        u32 isLoopValue : 1;  // offset: 0x4
        union
        {
        public:
            u32 nameOffset;  // offset: 0x0
            MT_CTSTR pName;  // offset: 0x0
        };  // offset: 0x8
        union
        {
        public:
            u32 dtiId;  // offset: 0x0
            const MtDTI* pDti;  // offset: 0x0
        };  // offset: 0x10
        union
        {
        public:
            s32 iInit;  // offset: 0x0
            f32 fInit;  // offset: 0x0
        };  // offset: 0x18
        union
        {
        public:
            s32 iMin;  // offset: 0x0
            f32 fMin;  // offset: 0x0
        };  // offset: 0x1c
        union
        {
        public:
            s32 iMax;  // offset: 0x0
            f32 fMax;  // offset: 0x0
        };  // offset: 0x20
    };
}  // namespace nGUI

namespace nGUI {
    struct VERTEX
    {
    public:
        f32 x;  // offset: 0x0
        f32 y;  // offset: 0x4
        f32 z;  // offset: 0x8
        u32 color;  // offset: 0xc
        f32 u;  // offset: 0x10
        f32 v;  // offset: 0x14
    };
}  // namespace nGUI

inline nGUI::TEXT_STATUS::TEXT_STATUS() {
}
