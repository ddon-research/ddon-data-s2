// Reconstructed from the game's DWARF debug information.
#include <new>
#include "MtSerializer.h"
#include "MtCollisionPrimitive3D.h"
#include "MtDTI.h"
#include "MtDataReader.h"
#include "MtDataWriter.h"
#include "MtMath.h"
#include "MtMemory.h"
#include "MtPrimitive3D.h"
#include "MtProperty.h"
#include "MtPropertyList.h"
#include "MtStream.h"
#include "MtString.h"
#include "MtTime.h"
#include "MtXmlReader.h"
#include "MtXmlWriter.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

MtSerializer::MtSerializer(s32 MaxClassID) {
    mClassIDMax = MaxClassID;
}

MtSerializer::~MtSerializer() {
}

__attribute__((weak)) bool MtSerializer::serializeXML(MtStream& out, MT_CTSTR name, MtObject* pobj, MtSerializer::MODE mode, MtSerializer::ENCODING encoding) {
    DDON_STUB("MtSerializer::serializeXML")
    return {};
}

__attribute__((weak)) MtObject* MtSerializer::deserializeXML(MtStream& in, MT_CTSTR, MtObject* pobj, MtSerializer::MODE mode, MtSerializer::ENCODING encoding) {
    DDON_STUB("MtSerializer::deserializeXML")
    return nullptr;
}

bool MtSerializer::serializeBinary(MtStream& out, u16 version, MtObject* proot, MtSerializer::MODE mode, const MtDTI* prootdti) {
    if (out.isWritable()) {
        MtDataWriter w(out, 4096u, 4096u);
        return serializeBinary(w, version, proot, mode, prootdti);
    } else {
        return false;
    }
}

__attribute__((weak)) bool MtSerializer::serializeBinary(MtDataWriter& w, u16 version, MtObject* proot, MtSerializer::MODE mode, const MtDTI* prootdti) {
    if (!w.isWritable()) {
        return false;
    }
    mpObjectData = static_cast<OBJECTDATA**>(MtMemory::getAllocator(MtAllocator::TYPE_SHARED)->memAlloc(MAX_OBJECT * sizeof(*mpObjectData), 16));
    memset(mpObjectData, 0, MAX_OBJECT * sizeof(*mpObjectData));
    mObjectDataNum = 0;
    mpStringPool = static_cast<u8*>(MtMemory::getAllocator(MtAllocator::TYPE_SHARED)->memAlloc(MAX_STRINGPOOL, 16));
    memset(mpStringPool, 0, MAX_STRINGPOOL);
    mStringPoolPt = 0;
    mClassIDNum = 0;
    mClassID = static_cast<CLASS_ID*>(MtMemory::getAllocator(MtAllocator::TYPE_SHARED)->memAlloc(mClassIDMax * sizeof(*mClassID), 16));
    memset(mClassID, 0, mClassIDMax * sizeof(*mClassID));
    addObject(proot, mode, prootdti);
    
    HEADER hdr;
    hdr.magic = 0x534658;
    hdr.major_version = MAJOR_VERSION;
    hdr.minor_version = version;
    hdr.object_num = mObjectDataNum;
    hdr.max_object_id = 0;
    hdr.reserved = 0;
    hdr.database_size = hdr.object_num * sizeof(*mpObjectData);
    for (u32 i = 0; i < hdr.object_num; ++i) {
        hdr.database_size += offsetof(OBJECTDATA, prop) + mpObjectData[i]->prop_num * sizeof(PROPERTYDATA);
    }
    u32 stringpool_ofs = hdr.database_size;
    hdr.database_size += (mStringPoolPt + 3u) & ~3u;
    u32 base_pos = w.getPosition();
    w.write(&hdr, sizeof(hdr));
    w.pushLabel();
    for (u32 i = 0; i < mObjectDataNum; ++i) {
        w.writeLabel(mpObjectData[i]);
    }
    for (u32 i = 0; i < mObjectDataNum; ++i) {
        OBJECTDATA* pobj = mpObjectData[i];
        w.addLabel(pobj);
        w.writeUPtr(pobj->id);
        w.writeU32(pobj->param32);
        w.writeU32(0);
        for (u32 j = 0; j < pobj->prop_num; ++j) {
            PROPERTYDATA* pp = &pobj->prop[j];
            w.writeUPtr(static_cast<u32>(reinterpret_cast<uintptr>(pp->name) - reinterpret_cast<uintptr>(mpStringPool)) + stringpool_ofs);
            w.writeU32(pp->param32);
            for (u32 k = 0; k < 17; ++k) {
                w.writeU32(0);
            }
        }
    }
    w.write(mpStringPool, (mStringPoolPt + 3u) & ~3u);
    w.popLabel();
    mClassIDNum = 0;
    writeClass(w, proot, true, mode, prootdti);
    
    MtMemory::getAllocator(MtAllocator::TYPE_SHARED)->memFree(mClassID);
    for (u32 i = 0; i < mObjectDataNum; ++i) {
        MtMemory::getAllocator(MtAllocator::TYPE_SHARED)->memFree(mpObjectData[i]);
    }
    MtMemory::getAllocator(MtAllocator::TYPE_SHARED)->memFree(mpObjectData);
    MtMemory::getAllocator(MtAllocator::TYPE_SHARED)->memFree(mpStringPool);
    mpObjectData = nullptr;
    mObjectDataNum = 0;
    mStringPoolPt = 0;
    mpStringPool = nullptr;
    u32 spos = w.getPosition();
    w.seek(base_pos + offsetof(HEADER, max_object_id), MtStream::ORG_BEGIN);
    w.writeU32(mClassIDNum);
    w.seek(spos, MtStream::ORG_BEGIN);
    return true;
}

__attribute__((weak)) MtObject* MtSerializer::deserializeBinary(MtStream& in, u16 version, MtObject* pobj, MtSerializer::MODE mode) {
    if (in.isReadable()) {
        MtDataReader r(in, 0x1000);
        return deserializeBinary(r, version, pobj, mode);
        }
    return nullptr;
}

__attribute__((weak)) MtObject* MtSerializer::deserializeBinary(MtDataReader& r, u16 version, MtObject* pobj, MtSerializer::MODE mode) {
    u8* pdatabase;
    MtObject* pdst = nullptr;
    MtSerializer::HEADER hdr;
    if (!r.isReadable()) {
        return nullptr;
    }
    r.read(&hdr, sizeof(hdr));
    if (hdr.magic != 0x534658 || hdr.major_version != MtSerializer::MAJOR_VERSION || hdr.minor_version != version) {
        return nullptr;
    }
    pdatabase = static_cast<u8*>(MtMemory::getAllocator(MtAllocator::TYPE_SHARED)->memAlloc(hdr.database_size, 16));
    r.read(pdatabase, hdr.database_size);
    mpObjectData = reinterpret_cast<OBJECTDATA**>(pdatabase);
    mObjectDataNum = hdr.object_num;
    for (u32 i = 0; i < mObjectDataNum; ++i) {
        mpObjectData[i] = reinterpret_cast<OBJECTDATA*>(reinterpret_cast<size_t>(mpObjectData[i]) + reinterpret_cast<size_t>(pdatabase));
        OBJECTDATA* pdat = mpObjectData[i];
        pdat->pdti = MtDTI::from(pdat->id);
        if (pdat->pdti == nullptr) {
            MtMemory::getAllocator(MtAllocator::TYPE_SHARED)->memFree(pdatabase);
            return nullptr;
        }
        u32 pn = pdat->prop_num;
        for (u32 j = 0; j < pn; ++j) {
            pdat->prop[j].name = reinterpret_cast<MT_CTSTR>(reinterpret_cast<size_t>(pdat->prop[j].name) + reinterpret_cast<size_t>(pdatabase));
        }
    }
    mClassIDMax = static_cast<s32>(hdr.max_object_id);
    mClassIDNum = 0;
    mClassID = static_cast<CLASS_ID*>(MtMemory::getAllocator(MtAllocator::TYPE_SHARED)->memAlloc(sizeof(CLASS_ID) * mClassIDMax, 16));
    memset(mClassID, 0, sizeof(CLASS_ID) * mClassIDMax);
    for (s32 i = 0; i < MtSerializer::MAX_CUSTOMPARAM; ++i) {
        mCustomParams[i].name = "";
        mCustomParams[i].value = mCustomParamValue[i];
    }
    pdst = readClass(r, pobj);
    MtMemory::getAllocator(MtAllocator::TYPE_SHARED)->memFree(mClassID);
    MtMemory::getAllocator(MtAllocator::TYPE_SHARED)->memFree(pdatabase);
    mpObjectData = nullptr;
    mObjectDataNum = 0;
    return pdst;
}

__attribute__((weak)) void MtSerializer::addClass(MtObject* pobj, bool inst, MtSerializer::MODE mode) {
    DDON_STUB("MtSerializer::addClass")
    /* stub */
}

__attribute__((weak)) void MtSerializer::writeClass(MtXmlWriter& w, MtObject* pobj, bool inst, MtSerializer::MODE mode) {
    DDON_STUB("MtSerializer::writeClass")
    /* stub */
}

__attribute__((weak)) void MtSerializer::writeClass(MtDataWriter& w, MtObject* pobj, bool inst, MtSerializer::MODE mode, const MtDTI* prootdti) {
    if (pobj == nullptr) {
        w.writeU32(OBJECTDATA_NULL << 1);
        return;
    }
    CLASSDATA cd;
    cd.type = prootdti != nullptr ? 0 : getObjectDataType(pobj);
    cd.inst = inst;
    s32 id = getClassID(pobj);
    if (id >= 0) {
        cd.id = id;
        if (isClassInst(cd.id)) {
            cd.inst = 0;
        }
    } else {
        cd.id = newClassID(pobj);
    }
    w.writeU32(cd.param32);
    if (cd.inst) {
        w.pushLabel();
        w.writeLabel(pobj);
        setClassInst(cd.id);
        MtPropertyList set;
        pobj->createProperty(set);
        for (MtProperty* pp = set.begin(); pp != nullptr; pp = pp->mpNext) {
            if (!isSerializable(*pp, mode)) {
                continue;
            }
            u32 n = pp->isArray() ? pp->getCount() : 1;
            w.writeU32(n);
            for (u32 i = 0; i < n; ++i) {
            pp->mIndex = i;
            switch (pp->mType) {
            case MtProperty::TYPE_CLASS:
            case MtProperty::TYPE_CLASSREF:
                writeClass(w, pp->getClass(), (pp->mAttr & MtProperty::ATTR_NOINSTANCE) == 0, mode, nullptr);
                break;
            case MtProperty::TYPE_PROPERTY:
            case MtProperty::TYPE_PROPERTYLIST: {
                MtProperty prop = pp->getProperty();
                CLASSDATA cd2;
                cd2.inst = 0;
                cd2.type = OBJECTDATA_NULL;
                cd2.id = 0;
                if (prop.mpOwner != nullptr) {
                    cd2.type = getObjectDataType(prop.mpOwner);
                    cd2.id = getClassID(prop.mpOwner);
                }
                w.writeU32(cd2.param32);
                w.writeU8(prop.mType);
                w.writeString(prop.mName);
                break;
            }
            case MtProperty::TYPE_BOOL:
                w.writeU8(pp->getBool() ? 1 : 0);
                break;
            case MtProperty::TYPE_U8:
                w.writeU8(pp->getU8());
                break;
            case MtProperty::TYPE_S8:
                w.writeS8(pp->getS8());
                break;
            case MtProperty::TYPE_U16:
                w.writeU16(pp->getU16());
                break;
            case MtProperty::TYPE_U32:
                w.writeU32(pp->getU32());
                break;
            case MtProperty::TYPE_U64:
                w.writeU64(pp->getU64());
                break;
            case MtProperty::TYPE_S16:
                w.writeS16(pp->getS16());
                break;
            case MtProperty::TYPE_S32:
                w.writeS32(pp->getS32());
                break;
            case MtProperty::TYPE_S64:
                w.writeS64(pp->getS64());
                break;
            case MtProperty::TYPE_F32:
                w.writeF32(pp->getF32());
                break;
            case MtProperty::TYPE_F64:
                w.writeF64(pp->getF64());
                break;
            case MtProperty::TYPE_STRING:
            case MtProperty::TYPE_CSTRING:
                w.writeString(pp->getString());
                break;
            case MtProperty::TYPE_COLOR:
                w.writeU32(pp->getColor().rgba);
                break;
            case MtProperty::TYPE_VECTOR3:
            case MtProperty::TYPE_VECTOR4:
            case MtProperty::TYPE_FLOAT4: {
                MtVector4 v = pp->getVector();
                w.write(&v, sizeof(v));
                break;
            }
            case MtProperty::TYPE_FLOAT2:
            case MtProperty::TYPE_VECTOR2: {
                MtVector4 t = pp->getVector();
                MtFloat2 v;
                v.x = t.x;
                v.y = t.y;
                w.write(&v, sizeof(v));
                break;
            }
            case MtProperty::TYPE_FLOAT3: {
                MtVector4 t = pp->getVector();
                MtFloat3 v;
                v.x = t.x;
                v.y = t.y;
                v.z = t.z;
                w.write(&v, sizeof(v));
                break;
            }
            case MtProperty::TYPE_MATRIX33: {
                const MtMatrix t = pp->getMatrix();
                f32 v[12] = {t.m[0].x, t.m[0].y, 0.0f, 0.0f, t.m[1].x, t.m[1].y, 0.0f, 0.0f, t.m[3].x, t.m[3].y, 1.0f, 0.0f};
                w.write(v, sizeof(v));
                break;
            }
            case MtProperty::TYPE_POINT: {
                const MtPoint v = pp->getPoint();
                w.write(&v, sizeof(v));
                break;
            }
            case MtProperty::TYPE_SIZE: {
                const MtSize v = pp->getSize();
                w.write(&v, sizeof(v));
                break;
            }
            case MtProperty::TYPE_RECT: {
                const MtRect v = pp->getRect();
                w.write(&v, sizeof(v));
                break;
            }
            case MtProperty::TYPE_MATRIX: {
                const MtMatrix v = pp->getMatrix();
                w.write(&v, sizeof(v));
                break;
            }
            case MtProperty::TYPE_QUATERNION: {
                const MtQuaternion v = pp->getQuaternion();
                w.write(&v, sizeof(v));
                break;
            }
            case MtProperty::TYPE_TIME: {
                const MtTime v = pp->getTime();
                w.write(&v, sizeof(v));
                break;
            }
            case MtProperty::TYPE_EASECURVE: {
                const MtEaseCurve v = pp->getEaseCurve();
                w.write(&v, sizeof(v));
                break;
            }
            case MtProperty::TYPE_LINE: {
                const MtLine v = pp->getLine();
                w.write(&v, sizeof(v));
                break;
            }
            case MtProperty::TYPE_LINESEGMENT: {
                const MtLineSegment v = pp->getLineSegment();
                w.write(&v, sizeof(v));
                break;
            }
            case MtProperty::TYPE_RAY: {
                const MtRay v = pp->getRay();
                w.write(&v, sizeof(v));
                break;
            }
            case MtProperty::TYPE_PLANE: {
                const MtPlane v = pp->getPlane();
                w.write(&v, sizeof(v));
                break;
            }
            case MtProperty::TYPE_SPHERE: {
                const MtSphere v = pp->getSphere();
                w.write(&v, sizeof(v));
                break;
            }
            case MtProperty::TYPE_CAPSULE: {
                const MtCapsule v = pp->getCapsule();
                w.write(&v, sizeof(v));
                break;
            }
            case MtProperty::TYPE_AABB: {
                const MtAABB v = pp->getAABB();
                w.write(&v, sizeof(v));
                break;
            }
            case MtProperty::TYPE_OBB: {
                const MtOBB v = pp->getOBB();
                w.write(&v, sizeof(v));
                break;
            }
            case MtProperty::TYPE_CYLINDER: {
                const MtCylinder v = pp->getCylinder();
                w.write(&v, sizeof(v));
                break;
            }
            case MtProperty::TYPE_TRIANGLE: {
                const MtTriangle v = pp->getTriangle();
                w.write(&v, sizeof(v));
                break;
            }
            case MtProperty::TYPE_CONE: {
                const MtCone v = pp->getCone();
                w.write(&v, sizeof(v));
                break;
            }
            case MtProperty::TYPE_TORUS: {
                const MtTorus v = pp->getTorus();
                w.write(&v, sizeof(v));
                break;
            }
            case MtProperty::TYPE_ELLIPSOID: {
                const MtEllipsoid v = pp->getEllipsoid();
                w.write(&v, sizeof(v));
                break;
            }
            case MtProperty::TYPE_RANGE: {
                const MtRange v = pp->getRange();
                w.write(&v, sizeof(v));
                break;
            }
            case MtProperty::TYPE_RANGEF: {
                const MtRangeF v = pp->getRangeF();
                w.write(&v, sizeof(v));
                break;
            }
            case MtProperty::TYPE_RANGEU16: {
                const MtRangeU16 v = pp->getRangeU16();
                w.write(&v, sizeof(v));
                break;
            }
            case MtProperty::TYPE_HERMITECURVE: {
                const MtHermiteCurve v = pp->getHermiteCurve();
                w.write(&v, sizeof(v));
                break;
            }
            case MtProperty::TYPE_LINESEGMENT4: {
                const MtLineSegment4 v = pp->getLineSegment4();
                w.write(&v, sizeof(v));
                break;
            }
            case MtProperty::TYPE_AABB4: {
                const MtAABB4 v = pp->getAABB4();
                w.write(&v, sizeof(v));
                break;
            }
            case MtProperty::TYPE_OSCILLATOR: {
                const MtOscillator v = pp->getOscillator();
                w.write(&v, sizeof(v));
                break;
            }
            case MtProperty::TYPE_VARIABLE: {
                const MtVariable v = pp->getVariable();
                w.write(&v, sizeof(v));
                break;
            }
            case MtProperty::TYPE_RECT3D_XZ: {
                const MtRect3D_XZ v = pp->getRect3D_XZ();
                w.write(&v, sizeof(v));
                break;
            }
            case MtProperty::TYPE_RECT3D: {
                const MtRect3D v = pp->getRect3D();
                w.write(&v, sizeof(v));
                break;
            }
            case MtProperty::TYPE_RECT3D_COLLISION: {
                const MtCollisionUtil::MtRect3DC v = pp->getRect3DC();
                w.write(&v, sizeof(v));
                break;
            }
            case MtProperty::TYPE_PLANE_XZ: {
                const MtPlaneXZ v = pp->getPlaneXZ();
                w.write(&v, sizeof(v));
                break;
            }
            case MtProperty::TYPE_RAY_Y: {
                const MtRayY v = pp->getRayY();
                w.write(&v, sizeof(v));
                break;
            }
            case MtProperty::TYPE_POINTF: {
                const MtPointF v = pp->getPointF();
                w.write(&v, sizeof(v));
                break;
            }
            case MtProperty::TYPE_SIZEF: {
                const MtSizeF v = pp->getSizeF();
                w.write(&v, sizeof(v));
                break;
            }
            case MtProperty::TYPE_RECTF: {
                const MtRectF v = pp->getRectF();
                w.write(&v, sizeof(v));
                break;
            }
            default: {
                MtProperty::Custom::PARAM params[32];
                MtProperty::Custom* pcustom = MtProperty::getCustom(static_cast<MtProperty::TYPE>(pp->mType));
                u32 param_num = pcustom->getParam(pp, params);
                w.writeU8(param_num);
                for (u32 k = 0; k < param_num; ++k) {
                    w.writeString(params[k].value);
                }
                break;
            }
            }
            }
        }
        w.addLabel(pobj);
        w.popLabel();
    }
}

__attribute__((weak)) void MtSerializer::addObject(MtObject* pobj, MtSerializer::MODE mode, const MtDTI* pdti) {
    if (pobj == nullptr) {
        return;
    }
    if (pdti == nullptr) {
        pdti = &pobj->getDTI();
    }
    u32 id = pdti->getID();
    bool bentry = false;
    for (u32 n = 0; n < mObjectDataNum; ++n) {
        if (mpObjectData[n]->id == id) {
            bentry = true;
            break;
        }
    }
    s32 cid = getClassID(pobj);
    if (cid >= 0) {
        return;
    }
    newClassID(pobj);
    MtPropertyList s;
    pobj->createProperty(s);
    if (!bentry) {
        u32 prop_num = 0;
        for (MtProperty* it = s.begin(); it != nullptr; it = it->mpNext) {
            MtProperty& prop = *it;
            if (isSerializable(prop, mode)) {
                ++prop_num;
            }
        }
        u32 size = offsetof(OBJECTDATA, prop) + prop_num * sizeof(PROPERTYDATA);
        OBJECTDATA* pdat = static_cast<OBJECTDATA*>(MtMemory::getAllocator(MtAllocator::TYPE_SHARED)->memAlloc(size, 16));
        memset(pdat, 0, size);
        pdat->prop_num = prop_num;
        pdat->id = id;
        u32 index = 0;
        for (MtProperty* it = s.begin(); it != nullptr; it = it->mpNext) {
            MtProperty& prop = *it;
            if (isSerializable(prop, mode)) {
                PROPERTYDATA* ppd = &pdat->prop[index];
                ppd->name = addString(prop.mName);
                ppd->type = prop.mType;
                ppd->attr = prop.mAttr;
                ppd->bytes = prop.getBytes();
                if (prop.isDynamic()) {
                    ppd->setter = prop.mpSetter;
                    ppd->setcount = prop.mpSetCount;
                    ppd->getter = prop.mpGetter;
                    ppd->getcount = prop.mpGetCount;
                } else {
                    ppd->offset = static_cast<u32>(reinterpret_cast<uintptr_t>(prop.mpAdr)) - static_cast<u32>(reinterpret_cast<uintptr_t>(prop.mpOwner));
                    ppd->count = prop.mCount;
                }
                ++index;
            }
        }
        mpObjectData[mObjectDataNum++] = pdat;
    }
    for (MtProperty* it = s.begin(); it != nullptr; it = it->mpNext) {
        MtProperty& prop = *it;
        if (isSerializable(prop, mode) && (prop.mType == MtProperty::TYPE_CLASS || prop.mType == MtProperty::TYPE_CLASSREF)) {
            u32 n = prop.isArray() ? prop.getCount() : 1;
            for (u32 i = 0; i < n; ++i) {
                prop.mIndex = i;
                MtObject* pchild = prop.getClass();
                if (pchild != nullptr) {
                    addObject(pchild, mode, nullptr);
                }
            }
        }
    }
}

__attribute__((weak)) MtObject* MtSerializer::readClass(MtDataReader& r, MtObject* pobj) {
    MtObject* pdst = nullptr;
    MtSerializer::OBJECTDATA* pdat;
    MtSerializer::CLASSDATA cd;
    u32 size;
    u32 i;
    MtSerializer::PROPERTYDATA* ppd;
    cd.param32 = r.readU32();
    if (cd.type != MtSerializer::OBJECTDATA_NULL) {
        if (pobj != nullptr) {
            mClassID[cd.id].pobject = pobj;
            pdst = pobj;
        } else {
            pdst = mClassID[cd.id].pobject;
        }
        pdat = mpObjectData[cd.type];
        if (pdat->pdti != nullptr) {
            if (pdst != nullptr) {
                if (!pdst->isKindOf(*pdat->pdti)) {
                    pdst = nullptr;
                }
            } else {
                pdst = pdat->pdti->newInstance();
                mClassID[cd.id].pobject = pdst;
            }
            if (pdst != nullptr) {
                if (cd.inst) {
                    if (!pdat->init) {
                        mappingObject(pdat, pdst);
                    }
                    size = static_cast<u32>(r.readUPtr());
                    for (i = 0; i < pdat->prop_num; ++i) {
                        ppd = &pdat->prop[i];
                        if (ppd->disable) {
                            skipProperty(r, ppd);
                        } else if (ppd->attr & MtProperty::ATTR_DYNAMIC) {
                            readDynamicProperty(r, pdst, ppd);
                        } else {
                            readStaticProperty(r, pdst, ppd);
                        }
                    }
                }
            } else {
                if (cd.inst) {
                    size = r.readU32();
                    r.skip(size);
                }
            }
        } else {
            pdst = nullptr;
            if (cd.inst) {
                size = r.readU32();
                r.skip(size);
            }
        }
    }
    return pdst;
}

__attribute__((weak)) void MtSerializer::readDynamicProperty(MtDataReader& r, MtObject* pdst, MtSerializer::PROPERTYDATA* ppd) {
    u32 count = r.readU32();
    MtProperty prop;
    u32 j;
    MtProperty::Custom* pcustom;
    u32 param_num;
    u32 k;
    MtObject* pobj;
    MtObject* pc;
    MtSerializer::CLASSDATA cd2;
    MT_CHAR str[512];
    
    prop.mName = "";
    prop.mType = ppd->type;
    prop.mAttr = ppd->attr;
    prop.mpOwner = reinterpret_cast<MtObject*>(reinterpret_cast<u8*>(pdst) + ppd->ownerofs);
    prop.mpGetter = ppd->getter;
    prop.mpGetCount = ppd->getcount;
    prop.mpSetter = ppd->setter;
    prop.mpSetCount = ppd->setcount;
    prop.mIndex = 0;
    if (ppd->attr & MtProperty::ATTR_ARRAY) prop.setCount(count);
    for (j = 0; j < count; ++j) {
        prop.mIndex = j;
        switch (ppd->type) {
        case MtProperty::TYPE_CLASS:
        case MtProperty::TYPE_CLASSREF:
            pobj = readClass(r, prop.getClass());
            prop.setClass(pobj);
            break;
        case MtProperty::TYPE_BOOL:
            prop.setBool(r.readU8() != 0);
            break;
        case MtProperty::TYPE_U8:
            prop.setU8(r.readU8());
            break;
        case MtProperty::TYPE_U16:
            prop.setU16(r.readU16());
            break;
        case MtProperty::TYPE_U32:
            prop.setU32(r.readU32());
            break;
        case MtProperty::TYPE_U64:
            prop.setU64(r.readU64());
            break;
        case MtProperty::TYPE_S8:
            prop.setS8(r.readS8());
            break;
        case MtProperty::TYPE_S16:
            prop.setS16(r.readS16());
            break;
        case MtProperty::TYPE_S32:
            prop.setS32(r.readS32());
            break;
        case MtProperty::TYPE_S64:
            prop.setS64(r.readS64());
            break;
        case MtProperty::TYPE_F32:
            prop.setF32(r.readF32());
            break;
        case MtProperty::TYPE_F64:
            prop.setF64(r.readF64());
            break;
        case MtProperty::TYPE_STRING:
        case MtProperty::TYPE_CSTRING:
            r.readString(str, 512);
            if (ppd->type == MtProperty::TYPE_STRING) prop.setString(MtString(str));
            else prop.setCString(MtString(str));
            break;
        case MtProperty::TYPE_CUSTOM:
            pcustom = MtProperty::getCustom(static_cast<MtProperty::TYPE>(ppd->type));
            param_num = r.readU8();
            for (k = 0; k < param_num; ++k) {
                r.readString(mCustomParamValue[k], MtSerializer::MAX_CUSTOMPARAM_VALUE);
                mCustomParams[k].name = "";
                mCustomParams[k].value = mCustomParamValue[k];
            }
            if (pcustom != nullptr) {
                pcustom->setParam(&prop, mCustomParams, param_num);
            }
            break;
        case MtProperty::TYPE_POINT:
            { MtPoint v; r.read(&v, sizeof(v)); prop.setPoint(v); }
            break;
        case MtProperty::TYPE_SIZE:
            { MtSize v; r.read(&v, sizeof(v)); prop.setSize(v); }
            break;
        case MtProperty::TYPE_RECT:
            { MtRect v; r.read(&v, sizeof(v)); prop.setRect(v); }
            break;
        case MtProperty::TYPE_MATRIX:
            { MtMatrix v; r.read(&v, sizeof(v)); prop.setMatrix(v); }
            break;
        case MtProperty::TYPE_COLOR:
            prop.setColor(MtColor(r.readU32()));
            break;
        case MtProperty::TYPE_VECTOR3:
        case MtProperty::TYPE_VECTOR4:
        case MtProperty::TYPE_FLOAT4:
            { MtVector4 v; r.read(&v, sizeof(v)); prop.setVector(v); }
            break;
        case MtProperty::TYPE_FLOAT2:
        case MtProperty::TYPE_VECTOR2:
            { MtFloat2 v; r.read(&v, sizeof(v)); prop.setVector(MtVector4(v.x, v.y, 0.0f, 0.0f)); }
            break;
        case MtProperty::TYPE_FLOAT3:
            { MtFloat3 v; r.read(&v, sizeof(v)); prop.setVector(MtVector4(v.x, v.y, v.z, 0.0f)); }
            break;
        case MtProperty::TYPE_PROPERTY:
        case MtProperty::TYPE_PROPERTYLIST:
            cd2.param32 = r.readU32();
            if (cd2.type != MtSerializer::OBJECTDATA_NULL) {
                pc = mClassID[cd2.id].pobject;
                if (pc != nullptr) {
                    MtPropertyList list;
                    pc->createProperty(list);
                    u32 type = r.readU8();
                    r.readString(str, 512);
                    MtProperty* ppp = list.find(static_cast<MtProperty::TYPE>(type), str);
                    if (ppp != nullptr) {
                        prop.setProperty(*ppp);
                    }
                }
            }
            break;
        case MtProperty::TYPE_MATRIX33:
            {
                f32 v[12];
                r.read(v, sizeof(v));
                MtMatrix m;
                m.m[0] = MtVector4(v[0], v[1], 0.0f, 0.0f);
                m.m[1] = MtVector4(v[4], v[5], 0.0f, 0.0f);
                m.m[2] = MtVector4(0.0f, 0.0f, 1.0f, 0.0f);
                m.m[3] = MtVector4(v[8], v[9], 0.0f, 1.0f);
                prop.setMatrix(m);
            }
            break;
        case MtProperty::TYPE_QUATERNION:
            { MtQuaternion v; r.read(&v, sizeof(v)); prop.setQuaternion(v); }
            break;
        case MtProperty::TYPE_TIME:
            { MtTime v; r.read(&v, sizeof(v)); prop.setTime(v); }
            break;
        case MtProperty::TYPE_EASECURVE:
            { MtEaseCurve v; r.read(&v, sizeof(v)); prop.setEaseCurve(v); }
            break;
        case MtProperty::TYPE_LINE:
            { MtLine v; r.read(&v, sizeof(v)); prop.setLine(v); }
            break;
        case MtProperty::TYPE_LINESEGMENT:
            { MtLineSegment v; r.read(&v, sizeof(v)); prop.setLineSegment(v); }
            break;
        case MtProperty::TYPE_RAY:
            { MtRay v; r.read(&v, sizeof(v)); prop.setRay(v); }
            break;
        case MtProperty::TYPE_PLANE:
            { MtPlane v; r.read(&v, sizeof(v)); prop.setPlane(v); }
            break;
        case MtProperty::TYPE_SPHERE:
            { MtSphere v; r.read(&v, sizeof(v)); prop.setSphere(v); }
            break;
        case MtProperty::TYPE_CAPSULE:
            { MtCapsule v; r.read(&v, sizeof(v)); prop.setCapsule(v); }
            break;
        case MtProperty::TYPE_AABB:
            { MtAABB v; r.read(&v, sizeof(v)); prop.setAABB(v); }
            break;
        case MtProperty::TYPE_OBB:
            { MtOBB v; r.read(&v, sizeof(v)); prop.setOBB(v); }
            break;
        case MtProperty::TYPE_CYLINDER:
            { MtCylinder v; r.read(&v, sizeof(v)); prop.setCylinder(v); }
            break;
        case MtProperty::TYPE_TRIANGLE:
            { MtTriangle v; r.read(&v, sizeof(v)); prop.setTriangle(v); }
            break;
        case MtProperty::TYPE_CONE:
            { MtCone v; r.read(&v, sizeof(v)); prop.setCone(v); }
            break;
        case MtProperty::TYPE_TORUS:
            { MtTorus v; r.read(&v, sizeof(v)); prop.setTorus(v); }
            break;
        case MtProperty::TYPE_ELLIPSOID:
            { MtEllipsoid v; r.read(&v, sizeof(v)); prop.setEllipsoid(v); }
            break;
        case MtProperty::TYPE_RANGE:
            { MtRange v; r.read(&v, sizeof(v)); prop.setRange(v); }
            break;
        case MtProperty::TYPE_RANGEF:
            { MtRangeF v; r.read(&v, sizeof(v)); prop.setRangeF(v); }
            break;
        case MtProperty::TYPE_RANGEU16:
            { MtRangeU16 v; r.read(&v, sizeof(v)); prop.setRangeU16(v); }
            break;
        case MtProperty::TYPE_HERMITECURVE:
            { MtHermiteCurve v; r.read(&v, sizeof(v)); prop.setHermiteCurve(v); }
            break;
        case MtProperty::TYPE_LINESEGMENT4:
            { MtLineSegment4 v; r.read(&v, sizeof(v)); prop.setLineSegment4(v); }
            break;
        case MtProperty::TYPE_AABB4:
            { MtAABB4 v; r.read(&v, sizeof(v)); prop.setAABB4(v); }
            break;
        case MtProperty::TYPE_OSCILLATOR:
            { MtOscillator osc; r.read(&osc, sizeof(osc)); prop.setOscillator(osc); }
            break;
        case MtProperty::TYPE_VARIABLE:
            { MtVariable var; r.read(&var, sizeof(var)); prop.setVariable(var); }
            break;
        case MtProperty::TYPE_RECT3D_XZ:
            { MtRect3D_XZ v; r.read(&v, sizeof(v)); prop.setRect3D_XZ(v); }
            break;
        case MtProperty::TYPE_RECT3D:
            { MtRect3D v; r.read(&v, sizeof(v)); prop.setRect3D(v); }
            break;
        case MtProperty::TYPE_RECT3D_COLLISION:
            { MtCollisionUtil::MtRect3DC v; r.read(&v, sizeof(v)); prop.setRect3DC(v); }
            break;
        case MtProperty::TYPE_PLANE_XZ:
            { MtPlaneXZ v; r.read(&v, sizeof(v)); prop.setPlaneXZ(v); }
            break;
        case MtProperty::TYPE_RAY_Y:
            { MtRayY v; r.read(&v, sizeof(v)); prop.setRayY(v); }
            break;
        case MtProperty::TYPE_POINTF:
            { MtPointF v; r.read(&v, sizeof(v)); prop.setPointF(v); }
            break;
        case MtProperty::TYPE_SIZEF:
            { MtSizeF v; r.read(&v, sizeof(v)); prop.setSizeF(v); }
            break;
        case MtProperty::TYPE_RECTF:
            { MtRectF v; r.read(&v, sizeof(v)); prop.setRectF(v); }
            break;
        default:
            r.skip(ppd->bytes);
            break;
        }
        }
}

__attribute__((weak)) void MtSerializer::readStaticProperty(MtDataReader& r, MtObject* pdst, MtSerializer::PROPERTYDATA* ppd) {
    u32 count = r.readU32();
    void* padr = reinterpret_cast<u8*>(pdst) + ppd->offset;
    switch (ppd->type) {
    case MtProperty::TYPE_CLASS:
        {
            u32 size = reinterpret_cast<MtObject*>(padr)->getDTI().getSize();
            for (u32 j = 0; j < count; ++j) {
                readClass(r, reinterpret_cast<MtObject*>(static_cast<u8*>(padr) + j * size));
            }
        }
        break;
    case MtProperty::TYPE_CUSTOM:
        {
            MtProperty::Custom* pcustom = MtProperty::getCustom(MtProperty::TYPE_CUSTOM);
            MtProperty prop;
            prop.mName = ppd->name;
            prop.mType = ppd->type;
            prop.mAttr = ppd->attr;
            prop.mpOwner = pdst;
            prop.mpAdr = padr;
            prop.mCount = ppd->count;
            for (u32 j = 0; j < count; ++j) {
                prop.mIndex = j;
                u32 param_num = r.readU8();
                for (u32 k = 0; k < param_num; ++k) {
                    r.readString(mCustomParamValue[k], MtSerializer::MAX_CUSTOMPARAM_VALUE);
                    mCustomParams[k].name = "";
                    mCustomParams[k].value = mCustomParamValue[k];
                }
                pcustom->setParam(&prop, mCustomParams, param_num);
            }
        }
        break;
    case MtProperty::TYPE_CLASSREF:
        {
            MtObject** ppo = static_cast<MtObject**>(padr);
            for (u32 j = 0; j < count; ++j) {
                *ppo = readClass(r, *ppo);
                ++ppo;
            }
        }
        break;
    case MtProperty::TYPE_STRING:
        {
            MT_CHAR str[512];
            for (u32 j = 0; j < count; ++j) {
                r.readString(str, 512);
                static_cast<MtString*>(padr)[j] = str;
            }
        }
        break;
    case MtProperty::TYPE_PROPERTYLIST:
        {
            MtPropertyList& s = *static_cast<MtPropertyList*>(padr);
            for (u32 j = 0; j < count; ++j) {
                MtSerializer::CLASSDATA cd2;
                cd2.param32 = r.readU32();
                if (cd2.type != MtSerializer::OBJECTDATA_NULL) {
                    MtObject* pc = mClassID[cd2.id].pobject;
                    if (pc != nullptr) {
                        MtPropertyList list;
                        pc->createProperty(list);
                        u32 type = r.readU8();
                        MT_CHAR str[512];
                        r.readString(str, 512);
                        MtProperty* ppp = list.find(static_cast<MtProperty::TYPE>(type), str);
                        if (ppp != nullptr) {
                            s << *ppp;
                        }
                    }
                }
            }
        }
        break;
    case MtProperty::TYPE_PROPERTY:
        {
            MtProperty* pa = static_cast<MtProperty*>(padr);
            for (u32 j = 0; j < count; ++j) {
                MtSerializer::CLASSDATA cd2;
                cd2.param32 = r.readU32();
                if (cd2.type != MtSerializer::OBJECTDATA_NULL) {
                    MtObject* pc = mClassID[cd2.id].pobject;
                    if (pc != nullptr) {
                        MtPropertyList list;
                        pc->createProperty(list);
                        u32 type = r.readU8();
                        MT_CHAR str[512];
                        r.readString(str, 512);
                        MtProperty* ppp = list.find(static_cast<MtProperty::TYPE>(type), str);
                        if (ppp != nullptr) {
                            pa[j] = *ppp;
                        }
                    }
                }
            }
        }
        break;
    case MtProperty::TYPE_CSTRING:
        {
            MT_CHAR str[512];
            for (u32 j = 0; j < count; ++j) {
                r.readString(str, 512);
                strcpy(static_cast<MT_CHAR*>(padr), str);
                padr = static_cast<u8*>(padr) + 1;
            }
        }
        break;
    default:
        r.read(padr, count * ppd->bytes);
        break;
    }
}

__attribute__((weak)) void MtSerializer::skipProperty(MtDataReader& r, MtSerializer::PROPERTYDATA* ppd) {
    u32 count = r.readU32();
    switch (ppd->type) {
    case MtProperty::TYPE_CLASS:
    case MtProperty::TYPE_CLASSREF:
        for (u32 i = 0; i < count; ++i) {
            MtSerializer::CLASSDATA cd;
            cd.param32 = r.readU32();
            if (cd.inst) {
                u32 classsize = r.readU32();
                r.skip(classsize);
            }
        }
        break;
    case MtProperty::TYPE_CUSTOM:
        {
            for (u32 i = 0; i < count; ++i) {
                MT_CHAR str[512];
                u32 param_num = r.readU8();
                for (u32 k = 0; k < param_num; ++k) {
                    r.readString(str, 512);
                }
            }
        }
        break;
    case MtProperty::TYPE_STRING:
    case MtProperty::TYPE_CSTRING:
        {
            for (u32 i = 0; i < count; ++i) {
                MT_CHAR str[512];
                r.readString(str, 512);
            }
        }
        break;
    case MtProperty::TYPE_PROPERTY:
        {
            for (u32 i = 0; i < count; ++i) {
                MT_CHAR str[512];
                r.readU32();
                r.readU8();
                r.readString(str, 512);
            }
        }
        break;
    default:
        r.skip(count * ppd->bytes);
        break;
    }
}

__attribute__((weak)) void MtSerializer::mappingObject(MtSerializer::OBJECTDATA* pdat, MtObject* pobj) {
    MtPropertyList s;
    pobj->createProperty(s);
    for (u32 i = 0; i < pdat->prop_num; ++i) {
        MtSerializer::PROPERTYDATA* ppd = &pdat->prop[i];
        MtProperty* pp = s.find(static_cast<MtProperty::TYPE>(ppd->type), ppd->name);
        if (pp == nullptr) {
            ppd->disable = 1;
        } else {
            ppd->attr = pp->mAttr;
            ppd->disable = 0;
            ppd->ownerofs = static_cast<u32>(reinterpret_cast<size_t>(pp->mpOwner) - reinterpret_cast<size_t>(pobj));
            if (pp->mAttr & MtProperty::ATTR_DYNAMIC) {
                ppd->setter = pp->mpSetter;
                ppd->setcount = pp->mpSetCount;
                ppd->getter = pp->mpGetter;
                ppd->getcount = pp->mpGetCount;
            } else {
                ppd->offset = static_cast<u32>(reinterpret_cast<size_t>(pp->mpAdr) - reinterpret_cast<size_t>(pobj));
                ppd->count = pp->mCount;
            }
        }
    }
    pdat->init = 1;
}

__attribute__((weak)) void MtSerializer::XmlHandler::startElement(MT_CTSTR localname, MtXmlReader::ATTRIBUTE* attr, u32 attr_num) {
    DDON_STUB("MtSerializer::XmlHandler::startElement")
    /* stub */
}

__attribute__((weak)) void MtSerializer::XmlHandler::endElement(MT_CTSTR localname) {
    DDON_STUB("MtSerializer::XmlHandler::endElement")
    /* stub */
}

