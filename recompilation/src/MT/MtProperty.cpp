// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "MtProperty.h"
#include "MtCollisionPrimitive3D.h"
#include "MtColor.h"
#include "MtEaseCurve.h"
#include "MtMath.h"
#include "MtObject.h"
#include "MtOscillator.h"
#include "MtPrimitive2D.h"
#include "MtPrimitive3D.h"
#include "MtPropertyList.h"
#include "MtString.h"
#include "MtTime.h"
#include "MtVariable.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

MtProperty::MtProperty(MtObject* pobj, MT_CTSTR name, MT_CTSTR custom, void* padr, u32 attr, u32 count) {
    mName = name;
    mType = TYPE_CUSTOM;
    mAttr = attr;
    mpOwner = pobj;
    mpAdr = padr;
    mCount = count;
    mIndex = 0;
    mpSetCount = nullptr;
    mpSetter = nullptr;
    mpPrev = nullptr;
    mpNext = nullptr;
    for (u32 i = 0; i < MAX_CUSTOM; ++i) {
        if (mpCustom[i] != nullptr && strcmp(mpCustom[i]->getName(), custom) == 0) {
            mType = TYPE_CUSTOM + i;
            break;
        }
    }
}

MtProperty::MtProperty(MtObject* pthis, MT_CTSTR name, MT_CTSTR custom, MT_MFUNC getter, MT_MFUNC setter, u32 attr, MT_MFUNC getcount, MT_MFUNC setcount) {
    mName = name;
    mType = TYPE_CUSTOM;
    mAttr = attr | ATTR_DYNAMIC;
    mpOwner = pthis;
    mpGetter = getter;
    mpGetCount = getcount;
    mpSetter = setter;
    mpSetCount = setcount;
    mIndex = 0;
    mpPrev = nullptr;
    mpNext = nullptr;
    for (u32 i = 0; i < MAX_CUSTOM; ++i) {
        if (mpCustom[i] != nullptr && strcmp(mpCustom[i]->getName(), custom) == 0) {
            mType = TYPE_CUSTOM + i;
            break;
        }
    }
}

MtProperty::TYPE MtProperty::getType(MT_CTSTR name) {
    for (u32 i = 0; i <= 74u; i = i + 1u) {
        if (strcmp(MtProperty::mTypeName[i], name) == 0) {
            return static_cast<TYPE>(i);
        }
    }
    return static_cast<TYPE>((strcmp(name, "custom") == 0) * 128);
}

__attribute__((weak)) u32 MtProperty::getBytes() const {
    switch (mType) {
    case TYPE_CLASS:
    case TYPE_CLASSREF:
    case TYPE_U64:
    case TYPE_S64:
    case TYPE_F64:
    case TYPE_STRING:
    case TYPE_POINT:
    case TYPE_SIZE:
    case TYPE_CSTRING:
    case TYPE_TIME:
    case TYPE_FLOAT2:
    case TYPE_EASECURVE:
    case TYPE_RANGE:
    case TYPE_RANGEF:
    case TYPE_OSCILLATOR:
    case TYPE_VARIABLE:
    case TYPE_VECTOR2:
    case TYPE_POINTF:
    case TYPE_SIZEF:
    case TYPE_CUSTOM:
        return 8u;
    case TYPE_BOOL:
    case TYPE_U8:
    case TYPE_S8:
        return 1u;
    case TYPE_U16:
    case TYPE_S16:
        return 2u;
    case TYPE_U32:
    case TYPE_S32:
    case TYPE_F32:
    case TYPE_COLOR:
    case TYPE_RANGEU16:
    case TYPE_PLANE_XZ:
        return 4u;
    case TYPE_FLOAT3:
        return 12u;
    case TYPE_RECT:
    case TYPE_VECTOR3:
    case TYPE_VECTOR4:
    case TYPE_QUATERNION:
    case TYPE_FLOAT4:
    case TYPE_PLANE:
    case TYPE_SPHERE:
    case TYPE_RAY_Y:
    case TYPE_RECTF:
        return 16u;
    case TYPE_MATRIX:
    case TYPE_FLOAT4x4:
    case TYPE_HERMITECURVE:
        return 64u;
    case TYPE_PROPERTY:
        return 112u;
    case TYPE_FLOAT3x3:
        return 36u;
    case TYPE_FLOAT4x3:
    case TYPE_CAPSULE:
    case TYPE_CYLINDER:
    case TYPE_TRIANGLE:
    case TYPE_FLOAT3x4:
    case TYPE_MATRIX33:
    case TYPE_RECT3D_XZ:
        return 48u;
    case TYPE_LINE:
    case TYPE_LINESEGMENT:
    case TYPE_RAY:
    case TYPE_AABB:
    case TYPE_CONE:
    case TYPE_TORUS:
    case TYPE_ELLIPSOID:
    case TYPE_RECT3D:
        return 32u;
    case TYPE_OBB:
        return 80u;
    case TYPE_LINESEGMENT4:
    case TYPE_AABB4:
        return 96u;
    case TYPE_RECT3D_COLLISION:
        return 160u;
    default:
        return 0u;
    }
}

MT_CTSTR MtProperty::getTypeName() const {
    if (mType <= 74u) {
        return MtProperty::mTypeName[mType];
    } else {
        return "custom";
    }
}

u32 MtProperty::getCount() const {
    if (isDynamic()) {
        if (mpGetCount != nullptr) {
            typedef u32 (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetCount);
            return (mpOwner->*pfunc)();
        }
        return 0;
    }
    return mCount;
}

__attribute__((weak)) void MtProperty::setCount(u32 count) {
        if (mAttr & 128) {
            (mpOwner->*reinterpret_cast<void (MtObject::*)(u32)>(mpSetCount))(count);
        } else {
            bool isProhibitSetCount = !(mType == 24 || mType == 28 || mType == 74);
            if (!isProhibitSetCount || mCount >= count) {
                mCount = count;
            }
        }
}

__attribute__((weak)) void MtProperty::copy(const MtProperty& prop) {
    DDON_STUB("MtProperty::copy")
    /* stub */
}

__attribute__((weak)) void MtProperty::setInteger(s32 v) {
    switch (mType) {
    case TYPE_BOOL:
        setBool(v != 0);
        break;
    case TYPE_U8:
        setU8(v);
        break;
    case TYPE_U16:
        setU16(v);
        break;
    case TYPE_U32:
        setU32(v);
        break;
    case TYPE_U64:
        setU64(v);
        break;
    case TYPE_S8:
        setS8(v);
        break;
    case TYPE_S16:
        setS16(v);
        break;
    case TYPE_S32:
        setS32(v);
        break;
    case TYPE_S64:
        setS64(v);
        break;
    case TYPE_F32:
        setF32(v);
        break;
    case TYPE_F64:
        setF64(v);
        break;
    }
}

__attribute__((weak)) void MtProperty::setFloat(f32 v) {
    if (mType == TYPE_F64) {
        setF64(v);
    } else if (mType == TYPE_F32) {
        setF32(v);
    }
}

__attribute__((weak)) void MtProperty::setClass(MtObject* pobj) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(MtObject*, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(pobj, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(MtObject*);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(pobj);
        }
    } else {
        static_cast<MtObject**>(mpAdr)[mIndex] = pobj;
    }
}

void MtProperty::setBool(bool value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(bool, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(bool);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<bool*>(mpAdr)[mIndex] = value;
    }
}

void MtProperty::setS8(s8 value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(s8, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(s8);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<s8*>(mpAdr)[mIndex] = value;
    }
}

void MtProperty::setS16(s16 value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(s16, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(s16);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<s16*>(mpAdr)[mIndex] = value;
    }
}

void MtProperty::setS32(s32 value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(s32, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(s32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<s32*>(mpAdr)[mIndex] = value;
    }
}

void MtProperty::setS64(s64 value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(s64, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(s64);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<s64*>(mpAdr)[mIndex] = value;
    }
}

void MtProperty::setU8(u8 value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(u8, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(u8);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<u8*>(mpAdr)[mIndex] = value;
    }
}

void MtProperty::setU16(u16 value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(u16, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(u16);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<u16*>(mpAdr)[mIndex] = value;
    }
}

void MtProperty::setU32(u32 value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(u32, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<u32*>(mpAdr)[mIndex] = value;
    }
}

void MtProperty::setU64(u64 value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(u64, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(u64);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<u64*>(mpAdr)[mIndex] = value;
    }
}

void MtProperty::setF32(f32 value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(f32, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(f32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<f32*>(mpAdr)[mIndex] = value;
    }
}

void MtProperty::setF64(f64 value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(f64, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(f64);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<f64*>(mpAdr)[mIndex] = value;
    }
}

__attribute__((weak)) void MtProperty::setString(const MtString& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(const MtString&, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(const MtString&);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<MtString*>(mpAdr)[mIndex] = value;
    }
}

__attribute__((weak)) void MtProperty::setCString(const MtString& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(MT_CTSTR, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value.ptr(), mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(MT_CTSTR);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value.ptr());
        }
    } else {
        strcpy(static_cast<MT_CHAR*>(mpAdr) + mIndex, value.ptr());
    }
}

__attribute__((weak)) void MtProperty::setColor(const MtColor& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(const MtColor&, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(const MtColor&);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<MtColor*>(mpAdr)[mIndex] = value;
    }
}

__attribute__((weak)) void MtProperty::setPoint(const MtPoint& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(const MtPoint&, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(const MtPoint&);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<MtPoint*>(mpAdr)[mIndex] = value;
    }
}

__attribute__((weak)) void MtProperty::setSize(const MtSize& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(const MtSize&, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(const MtSize&);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<MtSize*>(mpAdr)[mIndex] = value;
    }
}

__attribute__((weak)) void MtProperty::setRect(const MtRect& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(const MtRect&, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(const MtRect&);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<MtRect*>(mpAdr)[mIndex] = value;
    }
}

__attribute__((weak)) void MtProperty::setPointF(const MtPointF& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(const MtPointF&, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(const MtPointF&);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<MtPointF*>(mpAdr)[mIndex] = value;
    }
}

__attribute__((weak)) void MtProperty::setSizeF(const MtSizeF& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(const MtSizeF&, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(const MtSizeF&);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<MtSizeF*>(mpAdr)[mIndex] = value;
    }
}

__attribute__((weak)) void MtProperty::setRectF(const MtRectF& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(const MtRectF&, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(const MtRectF&);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<MtRectF*>(mpAdr)[mIndex] = value;
    }
}

__attribute__((weak)) void MtProperty::setVector(const MtVector4& value) {
    switch (mType) {
    case TYPE_COLOR:
    {
        MtColor v;
        v.r = value.x > 1.0f ? 255u : static_cast<u32>(static_cast<s32>(value.x * 255.0f));
        v.g = value.y > 1.0f ? 255u : static_cast<u32>(static_cast<s32>(value.y * 255.0f));
        v.b = value.z > 1.0f ? 255u : static_cast<u32>(static_cast<s32>(value.z * 255.0f));
        v.a = value.w > 1.0f ? 255u : static_cast<u32>(static_cast<s32>(value.w * 255.0f));
        if (isDynamic()) {
            if (isArray()) {
                typedef void (MtObject::*MT_SETTER)(const MtColor&, u32);
                MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
                (mpOwner->*pfunc)(v, mIndex);
            } else {
                typedef void (MtObject::*MT_SETTER)(const MtColor&);
                MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
                (mpOwner->*pfunc)(v);
            }
        } else {
            static_cast<MtColor*>(mpAdr)[mIndex] = v;
        }
        break;
    }
    case TYPE_VECTOR3:
    {
        MtVector3 v;
        v.x = value.x;
        v.y = value.y;
        v.z = value.z;
        if (isDynamic()) {
            if (isArray()) {
                typedef void (MtObject::*MT_SETTER)(const MtVector3&, u32);
                MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
                (mpOwner->*pfunc)(v, mIndex);
            } else {
                typedef void (MtObject::*MT_SETTER)(const MtVector3&);
                MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
                (mpOwner->*pfunc)(v);
            }
        } else {
            static_cast<MtVector3*>(mpAdr)[mIndex] = v;
        }
        break;
    }
    case TYPE_VECTOR4:
    {
        MtVector4 v;
        v.x = value.x;
        v.y = value.y;
        v.z = value.z;
        v.w = value.w;
        if (isDynamic()) {
            if (isArray()) {
                typedef void (MtObject::*MT_SETTER)(const MtVector4&, u32);
                MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
                (mpOwner->*pfunc)(v, mIndex);
            } else {
                typedef void (MtObject::*MT_SETTER)(const MtVector4&);
                MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
                (mpOwner->*pfunc)(v);
            }
        } else {
            static_cast<MtVector4*>(mpAdr)[mIndex] = v;
        }
        break;
    }
    case TYPE_FLOAT2:
    {
        MtFloat2 v;
        v.x = value.x;
        v.y = value.y;
        if (isDynamic()) {
            if (isArray()) {
                typedef void (MtObject::*MT_SETTER)(const MtFloat2&, u32);
                MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
                (mpOwner->*pfunc)(v, mIndex);
            } else {
                typedef void (MtObject::*MT_SETTER)(const MtFloat2&);
                MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
                (mpOwner->*pfunc)(v);
            }
        } else {
            static_cast<MtFloat2*>(mpAdr)[mIndex] = v;
        }
        break;
    }
    case TYPE_VECTOR2:
    {
        MtVector2 v;
        v.x = value.x;
        v.y = value.y;
        if (isDynamic()) {
            if (isArray()) {
                typedef void (MtObject::*MT_SETTER)(const MtVector2&, u32);
                MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
                (mpOwner->*pfunc)(v, mIndex);
            } else {
                typedef void (MtObject::*MT_SETTER)(const MtVector2&);
                MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
                (mpOwner->*pfunc)(v);
            }
        } else {
            static_cast<MtVector2*>(mpAdr)[mIndex] = v;
        }
        break;
    }
    case TYPE_FLOAT3:
    {
        MtFloat3 v;
        v.x = value.x;
        v.y = value.y;
        v.z = value.z;
        if (isDynamic()) {
            if (isArray()) {
                typedef void (MtObject::*MT_SETTER)(const MtFloat3&, u32);
                MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
                (mpOwner->*pfunc)(v, mIndex);
            } else {
                typedef void (MtObject::*MT_SETTER)(const MtFloat3&);
                MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
                (mpOwner->*pfunc)(v);
            }
        } else {
            static_cast<MtFloat3*>(mpAdr)[mIndex] = v;
        }
        break;
    }
    case TYPE_FLOAT4:
    {
        MtFloat4 v;
        v.x = value.x;
        v.y = value.y;
        v.z = value.z;
        v.w = value.w;
        if (isDynamic()) {
            if (isArray()) {
                typedef void (MtObject::*MT_SETTER)(const MtFloat4&, u32);
                MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
                (mpOwner->*pfunc)(v, mIndex);
            } else {
                typedef void (MtObject::*MT_SETTER)(const MtFloat4&);
                MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
                (mpOwner->*pfunc)(v);
            }
        } else {
            static_cast<MtFloat4*>(mpAdr)[mIndex] = v;
        }
        break;
    }
    case TYPE_EASECURVE:
    {
        MtEaseCurve v;
        v.p1 = value.x;
        v.p2 = value.y;
        if (isDynamic()) {
            if (isArray()) {
                typedef void (MtObject::*MT_SETTER)(const MtEaseCurve&, u32);
                MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
                (mpOwner->*pfunc)(v, mIndex);
            } else {
                typedef void (MtObject::*MT_SETTER)(const MtEaseCurve&);
                MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
                (mpOwner->*pfunc)(v);
            }
        } else {
            static_cast<MtEaseCurve*>(mpAdr)[mIndex] = v;
        }
        break;
    }
    case TYPE_SPHERE:
    {
        MtSphere v;
        v.pos.x = value.x;
        v.pos.y = value.y;
        v.pos.z = value.z;
        v.r = value.w;
        if (isDynamic()) {
            if (isArray()) {
                typedef void (MtObject::*MT_SETTER)(const MtSphere&, u32);
                MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
                (mpOwner->*pfunc)(v, mIndex);
            } else {
                typedef void (MtObject::*MT_SETTER)(const MtSphere&);
                MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
                (mpOwner->*pfunc)(v);
            }
        } else {
            memcpy(static_cast<MtSphere*>(mpAdr) + mIndex, &v, sizeof(v));
        }
        break;
    }
    case TYPE_RANGE:
    {
        MtRange v;
        s32 a = static_cast<s32>(value.x);
        s32 b = static_cast<s32>(value.y);
        v.s = a < b ? a : b;
        v.r = a < b ? b - a : a - b;
        if (isDynamic()) {
            if (isArray()) {
                typedef void (MtObject::*MT_SETTER)(const MtRange&, u32);
                MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
                (mpOwner->*pfunc)(v, mIndex);
            } else {
                typedef void (MtObject::*MT_SETTER)(const MtRange&);
                MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
                (mpOwner->*pfunc)(v);
            }
        } else {
            memcpy(static_cast<MtRange*>(mpAdr) + mIndex, &v, sizeof(v));
        }
        break;
    }
    case TYPE_RANGEF:
    {
        MtRangeF v;
        v.s = value.y > value.x ? value.x : value.y;
        v.r = value.y > value.x ? value.y - value.x : value.x - value.y;
        if (isDynamic()) {
            if (isArray()) {
                typedef void (MtObject::*MT_SETTER)(const MtRangeF&, u32);
                MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
                (mpOwner->*pfunc)(v, mIndex);
            } else {
                typedef void (MtObject::*MT_SETTER)(const MtRangeF&);
                MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
                (mpOwner->*pfunc)(v);
            }
        } else {
            memcpy(static_cast<MtRangeF*>(mpAdr) + mIndex, &v, sizeof(v));
        }
        break;
    }
    case TYPE_RANGEU16:
    {
        MtRangeU16 v;
        u32 a = static_cast<u16>(static_cast<s32>(value.x));
        u32 b = static_cast<u16>(static_cast<s32>(value.y));
        v.s = a < b ? a : b;
        v.r = a < b ? b - a : a - b;
        if (isDynamic()) {
            if (isArray()) {
                typedef void (MtObject::*MT_SETTER)(const MtRangeU16&, u32);
                MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
                (mpOwner->*pfunc)(v, mIndex);
            } else {
                typedef void (MtObject::*MT_SETTER)(const MtRangeU16&);
                MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
                (mpOwner->*pfunc)(v);
            }
        } else {
            memcpy(static_cast<MtRangeU16*>(mpAdr) + mIndex, &v, sizeof(v));
        }
        break;
    }
    default:
        break;
    }
}

__attribute__((weak)) void MtProperty::setVector4(const MtVector4& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(const MtVector4&, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(const MtVector4&);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<MtVector4*>(mpAdr)[mIndex] = value;
    }
}

__attribute__((weak)) void MtProperty::setVector3(const MtVector3& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(const MtVector3&, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(const MtVector3&);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<MtVector3*>(mpAdr)[mIndex] = value;
    }
}

__attribute__((weak)) void MtProperty::setFloat2(const MtFloat2& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(const MtFloat2&, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(const MtFloat2&);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<MtFloat2*>(mpAdr)[mIndex] = value;
    }
}

__attribute__((weak)) void MtProperty::setFloat3(const MtFloat3& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(const MtFloat3&, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(const MtFloat3&);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<MtFloat3*>(mpAdr)[mIndex] = value;
    }
}

__attribute__((weak)) void MtProperty::setFloat4(const MtFloat4& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(const MtFloat4&, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(const MtFloat4&);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<MtFloat4*>(mpAdr)[mIndex] = value;
    }
}

__attribute__((weak)) void MtProperty::setMatrix(const MtMatrix& value) {
    DDON_STUB("MtProperty::setMatrix")
    /* stub */
}

__attribute__((weak)) void MtProperty::setQuaternion(const MtQuaternion& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(const MtQuaternion&, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(const MtQuaternion&);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<MtQuaternion*>(mpAdr)[mIndex] = value;
    }
}

__attribute__((weak)) void MtProperty::setEaseCurve(const MtEaseCurve& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(const MtEaseCurve&, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(const MtEaseCurve&);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<MtEaseCurve*>(mpAdr)[mIndex] = value;
    }
}

__attribute__((weak)) void MtProperty::setHermiteCurve(const MtHermiteCurve& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(const MtHermiteCurve&, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(const MtHermiteCurve&);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<MtHermiteCurve*>(mpAdr)[mIndex] = value;
    }
}

__attribute__((weak)) void MtProperty::setTime(const MtTime& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(const MtTime&, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(const MtTime&);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<MtTime*>(mpAdr)[mIndex] = value;
    }
}

__attribute__((weak)) void MtProperty::setLine(const MtLine& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(const MtLine&, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(const MtLine&);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<MtLine*>(mpAdr)[mIndex] = value;
    }
}

__attribute__((weak)) void MtProperty::setLineSegment(const MtLineSegment& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(const MtLineSegment&, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(const MtLineSegment&);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<MtLineSegment*>(mpAdr)[mIndex] = value;
    }
}

__attribute__((weak)) void MtProperty::setLineSegment4(const MtLineSegment4& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(const MtLineSegment4&, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(const MtLineSegment4&);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<MtLineSegment4*>(mpAdr)[mIndex] = value;
    }
}

__attribute__((weak)) void MtProperty::setRay(const MtRay& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(const MtRay&, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(const MtRay&);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<MtRay*>(mpAdr)[mIndex] = value;
    }
}

__attribute__((weak)) void MtProperty::setPlane(const MtPlane& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(const MtPlane&, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(const MtPlane&);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<MtPlane*>(mpAdr)[mIndex] = value;
    }
}

__attribute__((weak)) void MtProperty::setSphere(const MtSphere& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(const MtSphere&, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(const MtSphere&);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        MtSphere& s = static_cast<MtSphere*>(mpAdr)[mIndex];
        s.pos.x = value.pos.x;
        s.pos.y = value.pos.y;
        s.pos.z = value.pos.z;
        s.r = value.r;
    }
}

__attribute__((weak)) void MtProperty::setCapsule(const MtCapsule& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(const MtCapsule&, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(const MtCapsule&);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<MtCapsule*>(mpAdr)[mIndex] = value;
    }
}

__attribute__((weak)) void MtProperty::setAABB(const MtAABB& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(const MtAABB&, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(const MtAABB&);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<MtAABB*>(mpAdr)[mIndex] = value;
    }
}

__attribute__((weak)) void MtProperty::setOBB(const MtOBB& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(const MtOBB&, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(const MtOBB&);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<MtOBB*>(mpAdr)[mIndex] = value;
    }
}

__attribute__((weak)) void MtProperty::setAABB4(const MtAABB4& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(const MtAABB4&, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(const MtAABB4&);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<MtAABB4*>(mpAdr)[mIndex] = value;
    }
}

__attribute__((weak)) void MtProperty::setCylinder(const MtCylinder& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(const MtCylinder&, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(const MtCylinder&);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<MtCylinder*>(mpAdr)[mIndex] = value;
    }
}

__attribute__((weak)) void MtProperty::setTriangle(const MtTriangle& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(const MtTriangle&, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(const MtTriangle&);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<MtTriangle*>(mpAdr)[mIndex] = value;
    }
}

__attribute__((weak)) void MtProperty::setCone(const MtCone& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(const MtCone&, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(const MtCone&);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<MtCone*>(mpAdr)[mIndex] = value;
    }
}

__attribute__((weak)) void MtProperty::setTorus(const MtTorus& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(const MtTorus&, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(const MtTorus&);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<MtTorus*>(mpAdr)[mIndex] = value;
    }
}

__attribute__((weak)) void MtProperty::setEllipsoid(const MtEllipsoid& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(const MtEllipsoid&, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(const MtEllipsoid&);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<MtEllipsoid*>(mpAdr)[mIndex] = value;
    }
}

__attribute__((weak)) void MtProperty::setRange(const MtRange& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(const MtRange&, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(const MtRange&);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<MtRange*>(mpAdr)[mIndex] = value;
    }
}

__attribute__((weak)) void MtProperty::setRangeF(const MtRangeF& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(const MtRangeF&, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(const MtRangeF&);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<MtRangeF*>(mpAdr)[mIndex] = value;
    }
}

__attribute__((weak)) void MtProperty::setRangeU16(const MtRangeU16& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(const MtRangeU16&, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(const MtRangeU16&);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<MtRangeU16*>(mpAdr)[mIndex] = value;
    }
}

__attribute__((weak)) void MtProperty::setProperty(const MtProperty& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(const MtProperty&, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(const MtProperty&);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else if (mType == TYPE_PROPERTY) {
        static_cast<MtProperty*>(mpAdr)[mIndex] = value;
    } else {
        MtPropertyList& s = *static_cast<MtPropertyList*>(mpAdr);
        if (mIndex < s.length()) {
            *s[mIndex] = value;
        } else {
            s << value;
        }
    }
}

__attribute__((weak)) void MtProperty::setOscillator(const MtOscillator& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(const MtOscillator&, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(const MtOscillator&);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<MtOscillator*>(mpAdr)[mIndex] = value;
    }
}

__attribute__((weak)) void MtProperty::setVariable(const MtVariable& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(const MtVariable&, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(const MtVariable&);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<MtVariable*>(mpAdr)[mIndex] = value;
    }
}

__attribute__((weak)) void MtProperty::setRect3D_XZ(const MtRect3D_XZ& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(const MtRect3D_XZ&, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(const MtRect3D_XZ&);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<MtRect3D_XZ*>(mpAdr)[mIndex] = value;
    }
}

__attribute__((weak)) void MtProperty::setRect3D(const MtRect3D& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(const MtRect3D&, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(const MtRect3D&);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<MtRect3D*>(mpAdr)[mIndex] = value;
    }
}

__attribute__((weak)) void MtProperty::setRect3DC(const MtCollisionUtil::MtRect3DC& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(const MtCollisionUtil::MtRect3DC&, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(const MtCollisionUtil::MtRect3DC&);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<MtCollisionUtil::MtRect3DC*>(mpAdr)[mIndex] = value;
    }
}

__attribute__((weak)) void MtProperty::setPlaneXZ(const MtPlaneXZ& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(const MtPlaneXZ&, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(const MtPlaneXZ&);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<MtPlaneXZ*>(mpAdr)[mIndex] = value;
    }
}

__attribute__((weak)) void MtProperty::setRayY(const MtRayY& value) {
    if (isDynamic()) {
        if (isArray()) {
            typedef void (MtObject::*MT_SETTER)(const MtRayY&, u32);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value, mIndex);
        } else {
            typedef void (MtObject::*MT_SETTER)(const MtRayY&);
            MT_SETTER pfunc = reinterpret_cast<MT_SETTER>(mpSetter);
            (mpOwner->*pfunc)(value);
        }
    } else {
        static_cast<MtRayY*>(mpAdr)[mIndex] = value;
    }
}

__attribute__((weak)) s32 MtProperty::getInteger() const {
    switch (mType) {
    case TYPE_BOOL:
        return getBool();
    case TYPE_U8:
        return getU8();
    case TYPE_U16:
        return getU16();
    case TYPE_U32:
        return getU32();
    case TYPE_U64:
        return getU64();
    case TYPE_S8:
        return getS8();
    case TYPE_S16:
        return getS16();
    case TYPE_S32:
        return getS32();
    case TYPE_S64:
        return getS64();
    case TYPE_F32:
        return getF32();
    case TYPE_F64:
        return getF64();
    default:
        return 0;
    }
}

__attribute__((weak)) f32 MtProperty::getFloat() const {
    switch (mType) {
    case TYPE_F32:
        return getF32();
    case TYPE_F64:
        return getF64();
    default:
        return 0.0f;
    }
}

__attribute__((weak)) MtObject* MtProperty::getClass() const {
    if (isDynamic()) {
        if (isArray()) {
            if (getCount() == 0) {
                return nullptr;
            }
            typedef MtObject* (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef MtObject* (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    } else {
        if (isArray()) {
            if (mpAdr == nullptr) {
                return nullptr;
            }
            if (mType == TYPE_CLASS) {
                if (mCount == 0) {
                    return nullptr;
                }
                u32 size = static_cast<MtObject*>(mpAdr)->getDTI().getSize();
                return reinterpret_cast<MtObject*>(static_cast<u8*>(mpAdr) + size * mIndex);
            } else {
                return static_cast<MtObject**>(mpAdr)[mIndex];
            }
        } else {
            if (mType == TYPE_CLASS) {
                return static_cast<MtObject*>(mpAdr);
            } else {
                if (mpAdr == nullptr) {
                    return nullptr;
                }
                return *static_cast<MtObject**>(mpAdr);
            }
        }
    }
}

bool MtProperty::getBool() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef bool (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef bool (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    } else {
        return static_cast<bool*>(mpAdr)[mIndex];
    }
}

s8 MtProperty::getS8() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef s8 (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef s8 (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    } else {
        return static_cast<s8*>(mpAdr)[mIndex];
    }
}

s16 MtProperty::getS16() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef s16 (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef s16 (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    } else {
        return static_cast<s16*>(mpAdr)[mIndex];
    }
}

s32 MtProperty::getS32() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef s32 (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef s32 (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    } else {
        return static_cast<s32*>(mpAdr)[mIndex];
    }
}

s64 MtProperty::getS64() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef s64 (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef s64 (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    } else {
        return static_cast<s64*>(mpAdr)[mIndex];
    }
}

u8 MtProperty::getU8() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef u8 (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef u8 (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    } else {
        return static_cast<u8*>(mpAdr)[mIndex];
    }
}

u16 MtProperty::getU16() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef u16 (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef u16 (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    } else {
        return static_cast<u16*>(mpAdr)[mIndex];
    }
}

u32 MtProperty::getU32() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef u32 (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef u32 (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    } else {
        return static_cast<u32*>(mpAdr)[mIndex];
    }
}

u64 MtProperty::getU64() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef u64 (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef u64 (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    } else {
        return static_cast<u64*>(mpAdr)[mIndex];
    }
}

__attribute__((weak)) f32 MtProperty::getF32() const {
    if (isDynamic()) {
        if (isArray()) {
            if (getCount() == 0) {
                return 0.0f;
            }
            typedef f32 (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef f32 (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    } else {
        return static_cast<f32*>(mpAdr)[mIndex];
    }
}

f64 MtProperty::getF64() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef f64 (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef f64 (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    } else {
        return static_cast<f64*>(mpAdr)[mIndex];
    }
}

__attribute__((weak)) MT_CTSTR MtProperty::getString() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef MT_CTSTR (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef MT_CTSTR (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    }
    if (mpAdr == nullptr) {
        return "";
    }
    if (mType == TYPE_STRING) {
        return static_cast<MtString*>(mpAdr)[mIndex].ptr();
    }
    MT_CTSTR str = static_cast<MT_CTSTR*>(mpAdr)[mIndex];
    if (str == nullptr) {
        return "";
    }
    return str;
}

__attribute__((weak)) const MtColor MtProperty::getColor() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef const MtColor (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef const MtColor (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    }
    return static_cast<MtColor*>(mpAdr)[mIndex];
}

__attribute__((weak)) const MtPoint MtProperty::getPoint() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef const MtPoint (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef const MtPoint (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    } else {
        MtPoint v;
        const MtPoint& p = static_cast<MtPoint*>(mpAdr)[mIndex];
        v.xy = p.xy;
        return v;
    }
}

__attribute__((weak)) const MtSize MtProperty::getSize() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef const MtSize (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef const MtSize (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    }
    return static_cast<MtSize*>(mpAdr)[mIndex];
}

__attribute__((weak)) const MtRect MtProperty::getRect() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef const MtRect (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef const MtRect (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    }
    return static_cast<MtRect*>(mpAdr)[mIndex];
}

__attribute__((weak)) const MtPointF MtProperty::getPointF() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef const MtPointF (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef const MtPointF (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    }
    return static_cast<MtPointF*>(mpAdr)[mIndex];
}

__attribute__((weak)) const MtSizeF MtProperty::getSizeF() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef const MtSizeF (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef const MtSizeF (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    } else {
        MtSizeF v;
        const MtSizeF& p = static_cast<MtSizeF*>(mpAdr)[mIndex];
        v.w = p.w;
        v.h = p.h;
        return v;
    }
}

__attribute__((weak)) const MtRectF MtProperty::getRectF() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef const MtRectF (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef const MtRectF (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    }
    return static_cast<MtRectF*>(mpAdr)[mIndex];
}

__attribute__((weak)) const MtVector4 MtProperty::getVector() const {
    MtVector4 ret;
    switch (mType) {
    case TYPE_COLOR:
        if (isDynamic()) {
            if (isArray()) {
                typedef MtColor (MtObject::*MT_GETTER)(u32);
                MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
                const MtColor v = (mpOwner->*pfunc)(mIndex);
                ret.x = static_cast<f32>(v.r) * (1.0f / 255.0f);
                ret.y = static_cast<f32>(v.g) * (1.0f / 255.0f);
                ret.z = static_cast<f32>(v.b) * (1.0f / 255.0f);
                ret.w = static_cast<f32>(v.a) * (1.0f / 255.0f);
            } else {
                typedef MtColor (MtObject::*MT_GETTER)();
                MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
                const MtColor v = (mpOwner->*pfunc)();
                ret.x = static_cast<f32>(v.r) * (1.0f / 255.0f);
                ret.y = static_cast<f32>(v.g) * (1.0f / 255.0f);
                ret.z = static_cast<f32>(v.b) * (1.0f / 255.0f);
                ret.w = static_cast<f32>(v.a) * (1.0f / 255.0f);
            }
        } else {
            const MtColor& v = static_cast<MtColor*>(mpAdr)[mIndex];
            ret.x = static_cast<f32>(v.r) * (1.0f / 255.0f);
            ret.y = static_cast<f32>(v.g) * (1.0f / 255.0f);
            ret.z = static_cast<f32>(v.b) * (1.0f / 255.0f);
            ret.w = static_cast<f32>(v.a) * (1.0f / 255.0f);
        }
        break;
    case TYPE_VECTOR3:
        if (isDynamic()) {
            if (isArray()) {
                typedef MtVector3 (MtObject::*MT_GETTER)(u32);
                MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
                const MtVector3 v = (mpOwner->*pfunc)(mIndex);
                ret.x = v.x;
                ret.y = v.y;
                ret.z = v.z;
                ret.w = 0.0f;
            } else {
                typedef MtVector3 (MtObject::*MT_GETTER)();
                MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
                const MtVector3 v = (mpOwner->*pfunc)();
                ret.x = v.x;
                ret.y = v.y;
                ret.z = v.z;
                ret.w = 0.0f;
            }
        } else {
            const MtVector3& v = static_cast<MtVector3*>(mpAdr)[mIndex];
            ret.x = v.x;
            ret.y = v.y;
            ret.z = v.z;
            ret.w = 0.0f;
        }
        break;
    case TYPE_VECTOR4:
        if (isDynamic()) {
            if (isArray()) {
                typedef MtVector4 (MtObject::*MT_GETTER)(u32);
                MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
                const MtVector4 v = (mpOwner->*pfunc)(mIndex);
                ret.x = v.x;
                ret.y = v.y;
                ret.z = v.z;
                ret.w = v.w;
            } else {
                typedef MtVector4 (MtObject::*MT_GETTER)();
                MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
                const MtVector4 v = (mpOwner->*pfunc)();
                ret.x = v.x;
                ret.y = v.y;
                ret.z = v.z;
                ret.w = v.w;
            }
        } else {
            const MtVector4& v = static_cast<MtVector4*>(mpAdr)[mIndex];
            ret.x = v.x;
            ret.y = v.y;
            ret.z = v.z;
            ret.w = v.w;
        }
        break;
    case TYPE_FLOAT2:
        if (isDynamic()) {
            if (isArray()) {
                typedef MtFloat2 (MtObject::*MT_GETTER)(u32);
                MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
                const MtFloat2 v = (mpOwner->*pfunc)(mIndex);
                ret.x = v.x;
                ret.y = v.y;
                ret.z = 0.0f;
                ret.w = 0.0f;
            } else {
                typedef MtFloat2 (MtObject::*MT_GETTER)();
                MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
                const MtFloat2 v = (mpOwner->*pfunc)();
                ret.x = v.x;
                ret.y = v.y;
                ret.z = 0.0f;
                ret.w = 0.0f;
            }
        } else {
            const MtFloat2& v = static_cast<MtFloat2*>(mpAdr)[mIndex];
            ret.x = v.x;
            ret.y = v.y;
            ret.z = 0.0f;
            ret.w = 0.0f;
        }
        break;
    case TYPE_VECTOR2:
        if (isDynamic()) {
            if (isArray()) {
                typedef MtVector2 (MtObject::*MT_GETTER)(u32);
                MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
                const MtVector2 v = (mpOwner->*pfunc)(mIndex);
                ret.x = v.x;
                ret.y = v.y;
                ret.z = 0.0f;
                ret.w = 0.0f;
            } else {
                typedef MtVector2 (MtObject::*MT_GETTER)();
                MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
                const MtVector2 v = (mpOwner->*pfunc)();
                ret.x = v.x;
                ret.y = v.y;
                ret.z = 0.0f;
                ret.w = 0.0f;
            }
        } else {
            const MtVector2& v = static_cast<MtVector2*>(mpAdr)[mIndex];
            ret.x = v.x;
            ret.y = v.y;
            ret.z = 0.0f;
            ret.w = 0.0f;
        }
        break;
    case TYPE_FLOAT3:
        if (isDynamic()) {
            if (isArray()) {
                typedef MtFloat3 (MtObject::*MT_GETTER)(u32);
                MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
                const MtFloat3 v = (mpOwner->*pfunc)(mIndex);
                ret.x = v.x;
                ret.y = v.y;
                ret.z = v.z;
                ret.w = 0.0f;
            } else {
                typedef MtFloat3 (MtObject::*MT_GETTER)();
                MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
                const MtFloat3 v = (mpOwner->*pfunc)();
                ret.x = v.x;
                ret.y = v.y;
                ret.z = v.z;
                ret.w = 0.0f;
            }
        } else {
            const MtFloat3& v = static_cast<MtFloat3*>(mpAdr)[mIndex];
            ret.x = v.x;
            ret.y = v.y;
            ret.z = v.z;
            ret.w = 0.0f;
        }
        break;
    case TYPE_FLOAT4:
        if (isDynamic()) {
            if (isArray()) {
                typedef MtFloat4 (MtObject::*MT_GETTER)(u32);
                MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
                const MtFloat4 v = (mpOwner->*pfunc)(mIndex);
                ret.x = v.x;
                ret.y = v.y;
                ret.z = v.z;
                ret.w = v.w;
            } else {
                typedef MtFloat4 (MtObject::*MT_GETTER)();
                MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
                const MtFloat4 v = (mpOwner->*pfunc)();
                ret.x = v.x;
                ret.y = v.y;
                ret.z = v.z;
                ret.w = v.w;
            }
        } else {
            const MtFloat4& v = static_cast<MtFloat4*>(mpAdr)[mIndex];
            ret.x = v.x;
            ret.y = v.y;
            ret.z = v.z;
            ret.w = v.w;
        }
        break;
    case TYPE_EASECURVE:
        if (isDynamic()) {
            if (isArray()) {
                typedef MtEaseCurve (MtObject::*MT_GETTER)(u32);
                MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
                const MtEaseCurve v = (mpOwner->*pfunc)(mIndex);
                ret.x = v.p1;
                ret.y = v.p2;
                ret.z = 0.0f;
                ret.w = 0.0f;
            } else {
                typedef MtEaseCurve (MtObject::*MT_GETTER)();
                MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
                const MtEaseCurve v = (mpOwner->*pfunc)();
                ret.x = v.p1;
                ret.y = v.p2;
                ret.z = 0.0f;
                ret.w = 0.0f;
            }
        } else {
            const MtEaseCurve& v = static_cast<MtEaseCurve*>(mpAdr)[mIndex];
            ret.x = v.p1;
            ret.y = v.p2;
            ret.z = 0.0f;
            ret.w = 0.0f;
        }
        break;
    case TYPE_SPHERE:
        if (isDynamic()) {
            if (isArray()) {
                typedef MtSphere (MtObject::*MT_GETTER)(u32);
                MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
                const MtSphere v = (mpOwner->*pfunc)(mIndex);
                ret.x = v.pos.x;
                ret.y = v.pos.y;
                ret.z = v.pos.z;
                ret.w = v.r;
            } else {
                typedef MtSphere (MtObject::*MT_GETTER)();
                MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
                const MtSphere v = (mpOwner->*pfunc)();
                ret.x = v.pos.x;
                ret.y = v.pos.y;
                ret.z = v.pos.z;
                ret.w = v.r;
            }
        } else {
            const MtSphere& v = static_cast<MtSphere*>(mpAdr)[mIndex];
            ret.x = v.pos.x;
            ret.y = v.pos.y;
            ret.z = v.pos.z;
            ret.w = v.r;
        }
        break;
    case TYPE_RANGE:
        if (isDynamic()) {
            if (isArray()) {
                typedef MtRange (MtObject::*MT_GETTER)(u32);
                MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
                const MtRange v = (mpOwner->*pfunc)(mIndex);
                ret.x = static_cast<f32>(v.s);
                ret.y = static_cast<f32>(static_cast<s32>(v.s + v.r));
                ret.z = 0.0f;
                ret.w = 0.0f;
            } else {
                typedef MtRange (MtObject::*MT_GETTER)();
                MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
                const MtRange v = (mpOwner->*pfunc)();
                ret.x = static_cast<f32>(v.s);
                ret.y = static_cast<f32>(static_cast<s32>(v.s + v.r));
                ret.z = 0.0f;
                ret.w = 0.0f;
            }
        } else {
            const MtRange& v = static_cast<MtRange*>(mpAdr)[mIndex];
            ret.x = static_cast<f32>(v.s);
            ret.y = static_cast<f32>(static_cast<s32>(v.s + v.r));
            ret.z = 0.0f;
            ret.w = 0.0f;
        }
        break;
    case TYPE_RANGEF:
        if (isDynamic()) {
            if (isArray()) {
                typedef MtRangeF (MtObject::*MT_GETTER)(u32);
                MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
                const MtRangeF v = (mpOwner->*pfunc)(mIndex);
                ret.x = v.s;
                ret.y = v.s + v.r;
                ret.z = 0.0f;
                ret.w = 0.0f;
            } else {
                typedef MtRangeF (MtObject::*MT_GETTER)();
                MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
                const MtRangeF v = (mpOwner->*pfunc)();
                ret.x = v.s;
                ret.y = v.s + v.r;
                ret.z = 0.0f;
                ret.w = 0.0f;
            }
        } else {
            const MtRangeF& v = static_cast<MtRangeF*>(mpAdr)[mIndex];
            ret.x = v.s;
            ret.y = v.s + v.r;
            ret.z = 0.0f;
            ret.w = 0.0f;
        }
        break;
    case TYPE_RANGEU16:
        if (isDynamic()) {
            if (isArray()) {
                typedef MtRangeU16 (MtObject::*MT_GETTER)(u32);
                MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
                const MtRangeU16 v = (mpOwner->*pfunc)(mIndex);
                ret.x = static_cast<f32>(v.s);
                ret.y = static_cast<f32>(v.s + v.r);
                ret.z = 0.0f;
                ret.w = 0.0f;
            } else {
                typedef MtRangeU16 (MtObject::*MT_GETTER)();
                MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
                const MtRangeU16 v = (mpOwner->*pfunc)();
                ret.x = static_cast<f32>(v.s);
                ret.y = static_cast<f32>(v.s + v.r);
                ret.z = 0.0f;
                ret.w = 0.0f;
            }
        } else {
            const MtRangeU16& v = static_cast<MtRangeU16*>(mpAdr)[mIndex];
            ret.x = static_cast<f32>(v.s);
            ret.y = static_cast<f32>(v.s + v.r);
            ret.z = 0.0f;
            ret.w = 0.0f;
        }
        break;
    default:
        ret.x = 0.0f;
        ret.y = 0.0f;
        ret.z = 0.0f;
        ret.w = 0.0f;
        break;
    }
    return ret;
}

__attribute__((weak)) const MtVector4 MtProperty::getVector4() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef const MtVector4 (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef const MtVector4 (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    }
    return static_cast<MtVector4*>(mpAdr)[mIndex];
}

__attribute__((weak)) const MtVector3 MtProperty::getVector3() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef const MtVector3 (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef const MtVector3 (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    }
    return static_cast<MtVector3*>(mpAdr)[mIndex];
}

__attribute__((weak)) const MtFloat2 MtProperty::getFloat2() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef const MtFloat2 (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef const MtFloat2 (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    }
    return static_cast<MtFloat2*>(mpAdr)[mIndex];
}

__attribute__((weak)) const MtFloat3 MtProperty::getFloat3() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef const MtFloat3 (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef const MtFloat3 (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    }
    return static_cast<MtFloat3*>(mpAdr)[mIndex];
}

__attribute__((weak)) const MtFloat4 MtProperty::getFloat4() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef const MtFloat4 (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef const MtFloat4 (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    }
    return static_cast<MtFloat4*>(mpAdr)[mIndex];
}

__attribute__((weak)) const MtMatrix MtProperty::getMatrix() const {
    switch (mType) {
    case TYPE_MATRIX:
        if (isDynamic()) {
            if (isArray()) {
                typedef const MtMatrix (MtObject::*MT_GETTER)(u32);
                MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
                return (mpOwner->*pfunc)(mIndex);
            } else {
                typedef const MtMatrix (MtObject::*MT_GETTER)();
                MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
                return (mpOwner->*pfunc)();
            }
        }
        return static_cast<MtMatrix*>(mpAdr)[mIndex];
    case TYPE_FLOAT3x3:
        if (isDynamic()) {
            if (isArray()) {
                typedef const MtFloat3x3 (MtObject::*MT_GETTER)(u32);
                MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
                return MtMatrix((mpOwner->*pfunc)(mIndex));
            } else {
                typedef const MtFloat3x3 (MtObject::*MT_GETTER)();
                MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
                return MtMatrix((mpOwner->*pfunc)());
            }
        }
        return MtMatrix(static_cast<MtFloat3x3*>(mpAdr)[mIndex]);
    case TYPE_FLOAT4x3:
        if (isDynamic()) {
            if (isArray()) {
                typedef const MtFloat4x3 (MtObject::*MT_GETTER)(u32);
                MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
                return MtMatrix((mpOwner->*pfunc)(mIndex));
            } else {
                typedef const MtFloat4x3 (MtObject::*MT_GETTER)();
                MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
                return MtMatrix((mpOwner->*pfunc)());
            }
        }
        return MtMatrix(static_cast<MtFloat4x3*>(mpAdr)[mIndex]);
    case TYPE_FLOAT4x4:
    case TYPE_HERMITECURVE:
        if (isDynamic()) {
            if (isArray()) {
                typedef const MtFloat4x4 (MtObject::*MT_GETTER)(u32);
                MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
                return MtMatrix((mpOwner->*pfunc)(mIndex));
            } else {
                typedef const MtFloat4x4 (MtObject::*MT_GETTER)();
                MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
                return MtMatrix((mpOwner->*pfunc)());
            }
        }
        return MtMatrix(static_cast<MtFloat4x4*>(mpAdr)[mIndex]);
    case TYPE_FLOAT3x4:
        if (isDynamic()) {
            if (isArray()) {
                typedef const MtFloat3x4 (MtObject::*MT_GETTER)(u32);
                MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
                return MtMatrix((mpOwner->*pfunc)(mIndex));
            } else {
                typedef const MtFloat3x4 (MtObject::*MT_GETTER)();
                MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
                return MtMatrix((mpOwner->*pfunc)());
            }
        }
        return MtMatrix(static_cast<MtFloat3x4*>(mpAdr)[mIndex]);
    case TYPE_MATRIX33:
        if (isDynamic()) {
            if (isArray()) {
                typedef const MtFloat3x4 (MtObject::*MT_GETTER)(u32);
                MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
                const MtFloat3x4 t1 = (mpOwner->*pfunc)(mIndex);
                MtMatrix t2;
                t2.m[0] = MtVector4(t1.m[0][0], t1.m[0][1], 0.0f, 0.0f);
                t2.m[1] = MtVector4(t1.m[1][0], t1.m[1][1], 0.0f, 0.0f);
                t2.m[2] = MtVector4(0.0f, 0.0f, 1.0f, 0.0f);
                t2.m[3] = MtVector4(t1.m[2][0], t1.m[2][1], 0.0f, 1.0f);
                return t2;
            } else {
                typedef const MtFloat3x4 (MtObject::*MT_GETTER)();
                MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
                const MtFloat3x4 t1 = (mpOwner->*pfunc)();
                MtMatrix t2;
                t2.m[0] = MtVector4(t1.m[0][0], t1.m[0][1], 0.0f, 0.0f);
                t2.m[1] = MtVector4(t1.m[1][0], t1.m[1][1], 0.0f, 0.0f);
                t2.m[2] = MtVector4(0.0f, 0.0f, 1.0f, 0.0f);
                t2.m[3] = MtVector4(t1.m[2][0], t1.m[2][1], 0.0f, 1.0f);
                return t2;
            }
        }
        {
            const MtFloat3x4& t1 = static_cast<MtFloat3x4*>(mpAdr)[mIndex];
            MtMatrix t2;
            t2.m[0] = MtVector4(t1.m[0][0], t1.m[0][1], 0.0f, 0.0f);
            t2.m[1] = MtVector4(t1.m[1][0], t1.m[1][1], 0.0f, 0.0f);
            t2.m[2] = MtVector4(0.0f, 0.0f, 1.0f, 0.0f);
            t2.m[3] = MtVector4(t1.m[2][0], t1.m[2][1], 0.0f, 1.0f);
            return t2;
        }
    default:
        return MtMatrix::Identity;
    }
}

__attribute__((weak)) const MtQuaternion MtProperty::getQuaternion() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef const MtQuaternion (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef const MtQuaternion (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    }
    return static_cast<MtQuaternion*>(mpAdr)[mIndex];
}

__attribute__((weak)) const MtEaseCurve MtProperty::getEaseCurve() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef const MtEaseCurve (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef const MtEaseCurve (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    }
    return static_cast<MtEaseCurve*>(mpAdr)[mIndex];
}

__attribute__((weak)) const MtHermiteCurve MtProperty::getHermiteCurve() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef const MtHermiteCurve (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef const MtHermiteCurve (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    }
    return static_cast<MtHermiteCurve*>(mpAdr)[mIndex];
}

__attribute__((weak)) const MtTime MtProperty::getTime() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef const MtTime (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef const MtTime (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    }
    return static_cast<MtTime*>(mpAdr)[mIndex];
}

__attribute__((weak)) const MtLine MtProperty::getLine() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef const MtLine (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef const MtLine (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    }
    return static_cast<MtLine*>(mpAdr)[mIndex];
}

__attribute__((weak)) const MtLineSegment MtProperty::getLineSegment() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef const MtLineSegment (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef const MtLineSegment (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    }
    return static_cast<MtLineSegment*>(mpAdr)[mIndex];
}

__attribute__((weak)) const MtLineSegment4 MtProperty::getLineSegment4() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef const MtLineSegment4 (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef const MtLineSegment4 (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    }
    return static_cast<MtLineSegment4*>(mpAdr)[mIndex];
}

__attribute__((weak)) const MtRay MtProperty::getRay() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef const MtRay (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef const MtRay (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    }
    return static_cast<MtRay*>(mpAdr)[mIndex];
}

__attribute__((weak)) const MtPlane MtProperty::getPlane() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef const MtPlane (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef const MtPlane (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    }
    return static_cast<MtPlane*>(mpAdr)[mIndex];
}

__attribute__((weak)) const MtSphere MtProperty::getSphere() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef const MtSphere (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef const MtSphere (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    }
    return static_cast<MtSphere*>(mpAdr)[mIndex];
}

__attribute__((weak)) const MtCapsule MtProperty::getCapsule() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef const MtCapsule (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef const MtCapsule (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    }
    return static_cast<MtCapsule*>(mpAdr)[mIndex];
}

__attribute__((weak)) const MtAABB MtProperty::getAABB() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef const MtAABB (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef const MtAABB (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    }
    return static_cast<MtAABB*>(mpAdr)[mIndex];
}

__attribute__((weak)) const MtOBB MtProperty::getOBB() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef const MtOBB (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef const MtOBB (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    }
    return static_cast<MtOBB*>(mpAdr)[mIndex];
}

__attribute__((weak)) const MtAABB4 MtProperty::getAABB4() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef const MtAABB4 (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef const MtAABB4 (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    }
    return static_cast<MtAABB4*>(mpAdr)[mIndex];
}

__attribute__((weak)) const MtCylinder MtProperty::getCylinder() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef const MtCylinder (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef const MtCylinder (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    }
    return static_cast<MtCylinder*>(mpAdr)[mIndex];
}

__attribute__((weak)) const MtTriangle MtProperty::getTriangle() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef const MtTriangle (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef const MtTriangle (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    }
    return static_cast<MtTriangle*>(mpAdr)[mIndex];
}

__attribute__((weak)) const MtCone MtProperty::getCone() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef const MtCone (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef const MtCone (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    }
    return static_cast<MtCone*>(mpAdr)[mIndex];
}

__attribute__((weak)) const MtTorus MtProperty::getTorus() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef const MtTorus (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef const MtTorus (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    }
    return static_cast<MtTorus*>(mpAdr)[mIndex];
}

__attribute__((weak)) const MtEllipsoid MtProperty::getEllipsoid() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef const MtEllipsoid (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef const MtEllipsoid (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    }
    return static_cast<MtEllipsoid*>(mpAdr)[mIndex];
}

__attribute__((weak)) const MtRange MtProperty::getRange() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef const MtRange (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef const MtRange (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    }
    return static_cast<MtRange*>(mpAdr)[mIndex];
}

__attribute__((weak)) const MtRangeF MtProperty::getRangeF() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef const MtRangeF (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef const MtRangeF (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    }
    return static_cast<MtRangeF*>(mpAdr)[mIndex];
}

__attribute__((weak)) const MtRangeU16 MtProperty::getRangeU16() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef const MtRangeU16 (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef const MtRangeU16 (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    }
    return static_cast<MtRangeU16*>(mpAdr)[mIndex];
}

__attribute__((weak)) const MtProperty MtProperty::getProperty() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef const MtProperty (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef const MtProperty (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    }
    if (mType == TYPE_PROPERTY) {
        return static_cast<MtProperty*>(mpAdr)[mIndex];
    }
    MtPropertyList& s = *static_cast<MtPropertyList*>(mpAdr);
    return *s[mIndex];
}

__attribute__((weak)) const MtOscillator MtProperty::getOscillator() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef const MtOscillator (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef const MtOscillator (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    }
    return static_cast<MtOscillator*>(mpAdr)[mIndex];
}

__attribute__((weak)) const MtVariable MtProperty::getVariable() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef const MtVariable (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef const MtVariable (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    }
    return static_cast<MtVariable*>(mpAdr)[mIndex];
}

__attribute__((weak)) const MtRect3D_XZ MtProperty::getRect3D_XZ() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef const MtRect3D_XZ (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef const MtRect3D_XZ (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    }
    return static_cast<MtRect3D_XZ*>(mpAdr)[mIndex];
}

__attribute__((weak)) const MtRect3D MtProperty::getRect3D() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef const MtRect3D (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef const MtRect3D (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    }
    return static_cast<MtRect3D*>(mpAdr)[mIndex];
}

__attribute__((weak)) const MtCollisionUtil::MtRect3DC MtProperty::getRect3DC() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef const MtCollisionUtil::MtRect3DC (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef const MtCollisionUtil::MtRect3DC (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    }
    return static_cast<MtCollisionUtil::MtRect3DC*>(mpAdr)[mIndex];
}

__attribute__((weak)) const MtPlaneXZ MtProperty::getPlaneXZ() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef const MtPlaneXZ (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef const MtPlaneXZ (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    }
    return static_cast<MtPlaneXZ*>(mpAdr)[mIndex];
}

__attribute__((weak)) const MtRayY MtProperty::getRayY() const {
    if (isDynamic()) {
        if (isArray()) {
            typedef const MtRayY (MtObject::*MT_GETTER)(u32);
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)(mIndex);
        } else {
            typedef const MtRayY (MtObject::*MT_GETTER)();
            MT_GETTER pfunc = reinterpret_cast<MT_GETTER>(mpGetter);
            return (mpOwner->*pfunc)();
        }
    }
    return static_cast<MtRayY*>(mpAdr)[mIndex];
}

__attribute__((weak)) void MtProperty::callEvent() const {
    if (mType == TYPE_EVENT64) {
        (mpOwner->*mpGetter64)(mCount64);
    } else if (mType == TYPE_EVENT32) {
        (mpOwner->*mpGetter32)(mCount);
    } else if (mType == TYPE_EVENT) {
        (mpOwner->*mpGetter)();
    }
}

void MtProperty::registCustom(MtProperty::Custom* pcustom) {
    Custom* * p0 = MtProperty::mpCustom;
    u32 i = 0;
    do {
        if ((*p0) == nullptr) {
            *p0 = pcustom;
            return;
        }
        p0 += static_cast<int>(1);
        i += 1u;
    } while (i <= 15u);
}

MtProperty::Custom* MtProperty::getCustom(MT_CTSTR name) {
    u32 i = 0;
    for (Custom* * p0_8 = MtProperty::mpCustom; i <= 15u; i += 1u, p0_8 += 1) {
        if ((*p0_8) != nullptr) {
            if (strcmp((*p0_8)->getName(), name) == 0) {
                return *p0_8;
            }
        }
    }
    return nullptr;
}

MtProperty::Custom* MtProperty::getCustom(MtProperty::TYPE type) {
    if (type > 127) {
        return MtProperty::mpCustom[type - 128];
    } else {
        return nullptr;
    }
}

MT_CTSTR MtProperty::mTypeName[75] = {
    "undefined",
    "class",
    "classref",
    "bool",
    "u8",
    "u16",
    "u32",
    "u64",
    "s8",
    "s16",
    "s32",
    "s64",
    "f32",
    "f64",
    "string",
    "color",
    "point",
    "size",
    "rect",
    "matrix44",
    "vector3",
    "vector4",
    "quaternion",
    "property",
    "event",
    "group",
    "pagebegin",
    "pageend",
    "event32",
    "array",
    "propertylist",
    "groupend",
    "cstring",
    "time",
    "float2",
    "float3",
    "float4",
    "float3x3",
    "float4x3",
    "float4x4",
    "easecurve",
    "line",
    "linesegment",
    "ray",
    "Plane",
    "sphere",
    "capsule",
    "aabb",
    "obb",
    "cylinder",
    "triangle",
    "cone",
    "torus",
    "ellpsoid",
    "range",
    "rangef",
    "rangeu16",
    "hermitecurve",
    "enumlist",
    "float3x4",
    "linesegment4",
    "aabb4",
    "oscillator",
    "variable",
    "vector2",
    "matrix33",
    "rect3d_xz",
    "rect3d",
    "rect3d_collision",
    "plane_xz",
    "ray_y",
    "pointf",
    "sizef",
    "rectf",
    "event64",
};

MtProperty::Custom* MtProperty::mpCustom[16];

