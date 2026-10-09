#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
struct MT_ENUM;
class MtAABB;
class MtAABB4;
class MtCapsule;
namespace MtCollisionUtil { class MtRect3DC; }
class MtColor;
class MtCone;
class MtCylinder;
class MtEaseCurve;
class MtEllipsoid;
struct MtFloat2;
struct MtFloat2A;
struct MtFloat3;
struct MtFloat3A;
struct MtFloat3x3;
struct MtFloat3x4;
struct MtFloat4;
struct MtFloat4A;
struct MtFloat4x3;
struct MtFloat4x4;
class MtHermiteCurve;
class MtLine;
class MtLineSegment;
class MtLineSegment4;
class MtMatrix;
class MtMatrix33;
class MtOBB;
class MtObject;
class MtOscillator;
class MtPlane;
class MtPlaneXZ;
class MtPoint;
class MtPointF;
class MtPropertyList;
class MtQuaternion;
class MtRange;
class MtRangeF;
class MtRangeU16;
class MtRay;
class MtRayY;
class MtRect;
class MtRect3D;
class MtRect3D_XZ;
class MtRectF;
class MtSize;
class MtSizeF;
class MtSphere;
class MtString;
class MtTime;
class MtTorus;
class MtTriangle;
class MtVariable;
class MtVector2;
class MtVector3;
class MtVector4;

// Declarations
class MtProperty;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_MFUNC = void(MtObject::*)();
using u32 = unsigned int;
using MT_MFUNC32 = void(MtObject::*)(u32);
using __uint64_t = long unsigned int;
using u64 = __uint64_t;
using MT_MFUNC64 = void(MtObject::*)(u64);
using __int64_t = long int;
using f32 = float;
using f64 = double;
using s16 = short;
using s32 = int;
using s64 = __int64_t;
using s8 = signed char;
using u16 = unsigned short;
using u8 = unsigned char;

class MtProperty
{
    // inferred: MtPropertyList::length names MtProperty::mpPrev
    friend class MtPropertyList;
public:
    enum TYPE
    {
        TYPE_UNDEFINED = 0,
        TYPE_CLASS = 1,
        TYPE_CLASSREF = 2,
        TYPE_BOOL = 3,
        TYPE_U8 = 4,
        TYPE_U16 = 5,
        TYPE_U32 = 6,
        TYPE_U64 = 7,
        TYPE_S8 = 8,
        TYPE_S16 = 9,
        TYPE_S32 = 10,
        TYPE_S64 = 11,
        TYPE_F32 = 12,
        TYPE_F64 = 13,
        TYPE_STRING = 14,
        TYPE_COLOR = 15,
        TYPE_POINT = 16,
        TYPE_SIZE = 17,
        TYPE_RECT = 18,
        TYPE_MATRIX = 19,
        TYPE_VECTOR3 = 20,
        TYPE_VECTOR4 = 21,
        TYPE_QUATERNION = 22,
        TYPE_PROPERTY = 23,
        TYPE_EVENT = 24,
        TYPE_GROUP = 25,
        TYPE_PAGE_BEGIN = 26,
        TYPE_PAGE_END = 27,
        TYPE_EVENT32 = 28,
        TYPE_ARRAY = 29,
        TYPE_PROPERTYLIST = 30,
        TYPE_GROUP_END = 31,
        TYPE_CSTRING = 32,
        TYPE_TIME = 33,
        TYPE_FLOAT2 = 34,
        TYPE_FLOAT3 = 35,
        TYPE_FLOAT4 = 36,
        TYPE_FLOAT3x3 = 37,
        TYPE_FLOAT4x3 = 38,
        TYPE_FLOAT4x4 = 39,
        TYPE_EASECURVE = 40,
        TYPE_LINE = 41,
        TYPE_LINESEGMENT = 42,
        TYPE_RAY = 43,
        TYPE_PLANE = 44,
        TYPE_SPHERE = 45,
        TYPE_CAPSULE = 46,
        TYPE_AABB = 47,
        TYPE_OBB = 48,
        TYPE_CYLINDER = 49,
        TYPE_TRIANGLE = 50,
        TYPE_CONE = 51,
        TYPE_TORUS = 52,
        TYPE_ELLIPSOID = 53,
        TYPE_RANGE = 54,
        TYPE_RANGEF = 55,
        TYPE_RANGEU16 = 56,
        TYPE_HERMITECURVE = 57,
        TYPE_ENUMLIST = 58,
        TYPE_FLOAT3x4 = 59,
        TYPE_LINESEGMENT4 = 60,
        TYPE_AABB4 = 61,
        TYPE_OSCILLATOR = 62,
        TYPE_VARIABLE = 63,
        TYPE_VECTOR2 = 64,
        TYPE_MATRIX33 = 65,
        TYPE_RECT3D_XZ = 66,
        TYPE_RECT3D = 67,
        TYPE_RECT3D_COLLISION = 68,
        TYPE_PLANE_XZ = 69,
        TYPE_RAY_Y = 70,
        TYPE_POINTF = 71,
        TYPE_SIZEF = 72,
        TYPE_RECTF = 73,
        TYPE_EVENT64 = 74,
        TYPE_END = 75,
        TYPE_CUSTOM = 128,
    };
public:
    class Custom;
public:
    class Custom
    {
    public:
        struct PARAM;
    public:
        struct PARAM
        {
        public:
            MT_CTSTR name;  // offset: 0x0
            MT_CTSTR value;  // offset: 0x8
        };
    public:
        virtual ~Custom() {}
        virtual MT_CTSTR getName() = 0;  // vtable slot 2
        virtual u32 getParam(MtProperty*, PARAM*) = 0;  // vtable slot 3
        virtual void setParam(MtProperty*, const PARAM*, u32) = 0;  // vtable slot 4
    };
public:
    MtProperty();
    MtProperty(MtObject* pthis, MT_CTSTR name, TYPE type, void* padr, u32 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, MtObject* padr, u32 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, MtObject* * padr, u32 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, bool* padr, u32 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, u8* padr, u32 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, u16* padr, u32 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, u32* padr, u32 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, u64* padr, u32 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, s8* padr, u32 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, s16* padr, u32 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, s32* padr, u32 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, s64* padr, u32 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, f32* padr, u32 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, f64* padr, u32 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, MtString* padr, u32 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, MtColor* padr, u32 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, MtPoint* padr, u32 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, MtSize* padr, u32 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, MtRect* padr, u32 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, MtPointF* padr, u16 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, MtSizeF* padr, u16 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, MtRectF* padr, u16 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, MtVector2* padr, u32 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, MtVector3* padr, u32 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, MtVector4* padr, u32 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, MtFloat2* padr, u32 attr, u32 count);
    MtProperty(MtObject*, MT_CTSTR, MtFloat2A*, u32, u32);
    MtProperty(MtObject* pthis, MT_CTSTR name, MtFloat3* padr, u32 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, MtFloat3A* padr, u32 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, MtFloat4* padr, u32 attr, u32 count);
    MtProperty(MtObject*, MT_CTSTR, MtFloat4A*, u32, u32);
    MtProperty(MtObject*, MT_CTSTR, MtFloat3x3*, u32, u32);
    MtProperty(MtObject*, MT_CTSTR, MtFloat3x4*, u32, u32);
    MtProperty(MtObject*, MT_CTSTR, MtFloat4x3*, u32, u32);
    MtProperty(MtObject*, MT_CTSTR, MtFloat4x4*, u32, u32);
    MtProperty(MtObject* pthis, MT_CTSTR name, MtMatrix* padr, u32 attr, u32 count);
    MtProperty(MtObject*, MT_CTSTR, MtMatrix33*, u32, u32);
    MtProperty(MtObject* pthis, MT_CTSTR name, MtQuaternion* padr, u32 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, MtEaseCurve* padr, u32 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, MtHermiteCurve* padr, u32 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, MtTime* padr, u32 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, MtLine* padr, u32 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, MtLineSegment* padr, u32 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, MtLineSegment4* padr, u32 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, MtRay* padr, u32 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, MtPlane* padr, u32 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, MtSphere* padr, u32 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, MtCapsule* padr, u32 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, MtAABB* padr, u32 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, MtOBB* padr, u32 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, MtAABB4* padr, u32 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, MtCylinder* padr, u32 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, MtTriangle* padr, u32 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, MtCone* padr, u32 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, MtTorus* padr, u32 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, MtEllipsoid* padr, u32 attr, u32 count);
    MtProperty(MtObject*, MT_CTSTR, MtRange*, u32, u32);
    MtProperty(MtObject*, MT_CTSTR, MtRangeF*, u32, u32);
    MtProperty(MtObject*, MT_CTSTR, MtRangeU16*, u32, u32);
    MtProperty(MtObject*, MT_CTSTR, MtProperty*, u32, u32);
    MtProperty(MtObject* pthis, MT_CTSTR name, MT_MFUNC pevent, u32 attr);
    MtProperty(MtObject* pthis, MT_CTSTR name, MT_MFUNC32 pevent, u32 attr, u32 id);
    MtProperty(MtObject* pthis, MT_CTSTR name, MT_MFUNC64 pevent, u32 attr, u64 id);
    MtProperty(MtObject* pthis, MT_CTSTR name, TYPE type, u32 attr);
    MtProperty(MtObject* pobj, MT_CTSTR name, MT_CTSTR custom, void* padr, u32 attr, u32 count);
    MtProperty(MtObject* pobj, MT_CTSTR name, MtPropertyList* padr, u32 attr, u32);
    MtProperty(MtObject* pthis, MT_CTSTR name, MT_CTSTR* padr, u32 attr, u32 count);
    MtProperty(MtObject*, MT_CTSTR, const MT_ENUM*, u32, u32);
    MtProperty(MtObject* pthis, TYPE type, MT_CTSTR name, MT_MFUNC getter, MT_MFUNC setter, u32 attr, MT_MFUNC getcount, MT_MFUNC setcount);
    MtProperty(MtObject* pthis, MT_CTSTR name, MT_CTSTR custom, MT_MFUNC getter, MT_MFUNC setter, u32 attr, MT_MFUNC getcount, MT_MFUNC setcount);
    MtProperty(MtObject* pthis, MT_CTSTR name, MtOscillator* padr, u32 attr, u32 count);
    MtProperty(MtObject* pthis, MT_CTSTR name, MtVariable* padr, u32 attr, u32 count);
    MtProperty(MtObject*, MT_CTSTR, MtRect3D_XZ*, u32, u32);
    MtProperty(MtObject*, MT_CTSTR, MtRect3D*, u32, u32);
    MtProperty(MtObject*, MT_CTSTR, MtCollisionUtil::MtRect3DC*, u32, u32);
    MtProperty(MtObject* pthis, MT_CTSTR name, MtPlaneXZ* padr, u32 attr, u32 count);
    MtProperty(MtObject*, MT_CTSTR, MtRayY*, u32, u32);
    ~MtProperty();
    static TYPE getType(MT_CTSTR name);
    TYPE getType() const;
    u32 getBytes() const;
    u32 getAttr() const;
    void setAttr(u32 attr);
    void setName(MT_CTSTR name);
    MT_CTSTR getName() const;
    MtProperty* getNext() const;
    MtProperty* getPrev() const;
    MT_CTSTR getTypeName() const;
    MtObject* getOwner() const;
    u32 getCount() const;
    void setCount(u32 count);
    u32 getIndex() const;
    void setIndex(u32 i);
    bool isEvent() const;
    bool isArray() const;
    bool isSingle() const;
    bool isReadonly() const;
    bool isDynamic() const;
    bool isSerializable() const;
    bool isEventRepeatable() const;
    bool isDevelop() const;
    bool operator==(MT_CTSTR str) const;
    bool operator!=(MT_CTSTR str) const;
    void copy(const MtProperty& prop);
    MT_MFUNC getGetter() const;
    MT_MFUNC getSetter() const;
    void setInteger(s32 v);
    void setFloat(f32 v);
    void setClass(MtObject* pobj);
    void setBool(bool value);
    void setS8(s8 value);
    void setS16(s16 value);
    void setS32(s32 value);
    void setS64(s64 value);
    void setU8(u8 value);
    void setU16(u16 value);
    void setU32(u32 value);
    void setU64(u64 value);
    void setF32(f32 value);
    void setF64(f64 value);
    void setString(const MtString& value);
    void setCString(const MtString& value);
    void setColor(const MtColor& value);
    void setPoint(const MtPoint& value);
    void setSize(const MtSize& value);
    void setRect(const MtRect& value);
    void setPointF(const MtPointF& value);
    void setSizeF(const MtSizeF& value);
    void setRectF(const MtRectF& value);
    void setVector(const MtVector4& value);
    void setVector4(const MtVector4& value);
    void setVector3(const MtVector3& value);
    void setVector2(const MtVector2& value);
    void setFloat2(const MtFloat2& value);
    void setFloat3(const MtFloat3& value);
    void setFloat4(const MtFloat4& value);
    void setFloat3x3(const MtFloat3x3& value);
    void setFloat3x4(const MtFloat3x4& value);
    void setFloat4x3(const MtFloat4x3& value);
    void setFloat4x4(const MtFloat4x4& value);
    void setMatrix(const MtMatrix& value);
    void setQuaternion(const MtQuaternion& value);
    void setEaseCurve(const MtEaseCurve& value);
    void setHermiteCurve(const MtHermiteCurve& value);
    void setTime(const MtTime& value);
    void setLine(const MtLine& value);
    void setLineSegment(const MtLineSegment& value);
    void setLineSegment4(const MtLineSegment4& value);
    void setRay(const MtRay& value);
    void setPlane(const MtPlane& value);
    void setSphere(const MtSphere& value);
    void setCapsule(const MtCapsule& value);
    void setAABB(const MtAABB& value);
    void setOBB(const MtOBB& value);
    void setAABB4(const MtAABB4& value);
    void setCylinder(const MtCylinder& value);
    void setTriangle(const MtTriangle& value);
    void setCone(const MtCone& value);
    void setTorus(const MtTorus& value);
    void setEllipsoid(const MtEllipsoid& value);
    void setRange(const MtRange& value);
    void setRangeF(const MtRangeF& value);
    void setRangeU16(const MtRangeU16& value);
    void setProperty(const MtProperty& value);
    void setOscillator(const MtOscillator& value);
    void setVariable(const MtVariable& value);
    void setRect3D_XZ(const MtRect3D_XZ& value);
    void setRect3D(const MtRect3D& value);
    void setRect3DC(const MtCollisionUtil::MtRect3DC& value);
    void setPlaneXZ(const MtPlaneXZ& value);
    void setRayY(const MtRayY& value);
    s32 getInteger() const;
    f32 getFloat() const;
    MtObject* getClass() const;
    bool getBool() const;
    s8 getS8() const;
    s16 getS16() const;
    s32 getS32() const;
    s64 getS64() const;
    u8 getU8() const;
    u16 getU16() const;
    u32 getU32() const;
    u64 getU64() const;
    f32 getF32() const;
    f64 getF64() const;
    const MT_ENUM* getEnumList() const;
    MT_CTSTR getString() const;
    const MtColor getColor() const;
    const MtPoint getPoint() const;
    const MtSize getSize() const;
    const MtRect getRect() const;
    const MtPointF getPointF() const;
    const MtSizeF getSizeF() const;
    const MtRectF getRectF() const;
    const MtVector4 getVector() const;
    const MtVector4 getVector4() const;
    const MtVector3 getVector3() const;
    const MtVector2 getVector2() const;
    const MtFloat2 getFloat2() const;
    const MtFloat3 getFloat3() const;
    const MtFloat4 getFloat4() const;
    const MtFloat3x3 getFloat3x3() const;
    const MtFloat3x4 getFloat3x4() const;
    const MtFloat4x3 getFloat4x3() const;
    const MtFloat4x4 getFloat4x4() const;
    const MtMatrix getMatrix() const;
    const MtQuaternion getQuaternion() const;
    const MtEaseCurve getEaseCurve() const;
    const MtHermiteCurve getHermiteCurve() const;
    const MtTime getTime() const;
    const MtLine getLine() const;
    const MtLineSegment getLineSegment() const;
    const MtLineSegment4 getLineSegment4() const;
    const MtRay getRay() const;
    const MtPlane getPlane() const;
    const MtSphere getSphere() const;
    const MtCapsule getCapsule() const;
    const MtAABB getAABB() const;
    const MtOBB getOBB() const;
    const MtAABB4 getAABB4() const;
    const MtCylinder getCylinder() const;
    const MtTriangle getTriangle() const;
    const MtCone getCone() const;
    const MtTorus getTorus() const;
    const MtEllipsoid getEllipsoid() const;
    const MtRange getRange() const;
    const MtRangeF getRangeF() const;
    const MtRangeU16 getRangeU16() const;
    const MtProperty getProperty() const;
    const MtOscillator getOscillator() const;
    const MtVariable getVariable() const;
    const MtRect3D_XZ getRect3D_XZ() const;
    const MtRect3D getRect3D() const;
    const MtCollisionUtil::MtRect3DC getRect3DC() const;
    const MtPlaneXZ getPlaneXZ() const;
    const MtRayY getRayY() const;
    void callEvent() const;
    static void registCustom(Custom* pcustom);
    static Custom* getCustom(MT_CTSTR name);
    static Custom* getCustom(TYPE type);
private:
    MT_CTSTR mName;  // offset: 0x0
    u32 mType : 16;  // offset: 0x8
    u32 mAttr : 16;  // offset: 0x8
    MtObject* mpOwner;  // offset: 0x10
    union
    {
    public:
        void* mpAdr;  // offset: 0x0
        MT_MFUNC mpGetter;  // offset: 0x0
        MT_MFUNC32 mpGetter32;  // offset: 0x0
        MT_MFUNC64 mpGetter64;  // offset: 0x0
    };  // offset: 0x18
    union
    {
    public:
        u32 mCount;  // offset: 0x0
        u64 mCount64;  // offset: 0x0
        MT_MFUNC mpGetCount;  // offset: 0x0
    };  // offset: 0x28
    MT_MFUNC mpSetter;  // offset: 0x38
    MT_MFUNC mpSetCount;  // offset: 0x48
    u32 mIndex;  // offset: 0x58
    MtProperty* mpNext;  // offset: 0x60
    MtProperty* mpPrev;  // offset: 0x68
public:
    static const TYPE TYPE_UPTR = static_cast<TYPE>(7);
    static const TYPE TYPE_SPTR = static_cast<TYPE>(11);
    static const TYPE TYPE_EVENTPTR = static_cast<TYPE>(74);
    static const u32 ATTR_READONLY = 1;
    static const u32 ATTR_NOSERIALIZE = 2;
    static const u32 ATTR_EVENT = 8;
    static const u32 ATTR_NOINSTANCE = 16;
    static const u32 ATTR_ARRAY = 32;
    static const u32 ATTR_SINGLE = 64;
    static const u32 ATTR_DYNAMIC = 128;
    static const u32 ATTR_AUTO_CREATE = 4096;
    static const u32 ATTR_NOBINARY = 8192;
    static const u32 ATTR_DEVELOP = 512;
    static const u32 ATTR_UI_EXPAND = 4;
    static const u32 ATTR_UI_SEPARATE = 2048;
    static const u32 ATTR_EVENT_REPEATABLE = 4;
    static const u32 ATTR_CONFIG = 256;
    static const u32 ATTR_STATE = 1024;
    static const u32 ATTR_EXPAND = 4;
    static MtProperty Null;
private:
    static const s32 MAX_CUSTOM = 16;
    static MT_CTSTR mTypeName[75];
    static Custom* mpCustom[16];
};
