// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "rRigidBody.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtDataReader.h"
#include "../MT/MtDataWriter.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtPrimitive3D.h"
#include "../MT/MtStream.h"
#include "cResource.h"
#include "rConvexHull.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rRigidBody::getDTI() const {
    return rRigidBody::DTI;
}

inline void rRigidBody::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rRigidBody::DTI)->memFree(p_addr);
}

rRigidBody::rRigidBody() {
    setAttribute(16u);
    mBuffer = nullptr;
    clear();
}

rRigidBody::~rRigidBody() {
    clear();
}

MT_CTSTR rRigidBody::getExt() const {
    return "rbd";
}

bool rRigidBody::save(MtStream& output) {
    MtDataWriter writer(output, 4096u, 4096u);
    saveCore(writer);
    return true;
}

bool rRigidBody::load(MtStream& input) {
    clear();
    if (input.getLength() != 0) {
        MtDataReader reader(input, 4096u);
        return loadCore(reader);
    } else {
        return false;
    }
}

__attribute__((weak)) bool rRigidBody::saveCore(MtDataWriter& writer) {
    writer.writeFormat(&mHeader, "d,d,{8,24}d,ddd,d,dddd", 1);
    u32 size = mHeader.NumRigidBody * sizeof(RIGID_BODY) + mHeader.NumGeometry * sizeof(GEOMETRY) + mHeader.NumParameter * sizeof(f32);
    BYTE* buffer = static_cast<BYTE*>(MtMemoryAllocator::getAllocator(rRigidBody::DTI)->memAlloc(size, 16));
    memcpy(buffer, mBuffer, size);
    RIGID_BODY* rigid_body_top = reinterpret_cast<RIGID_BODY*>(buffer);
    GEOMETRY* geometry_top = reinterpret_cast<GEOMETRY*>(rigid_body_top + mHeader.NumRigidBody);
    f32* parameter_top = reinterpret_cast<f32*>(geometry_top + mHeader.NumGeometry);
    for (u32 i = 0; i < mHeader.NumRigidBody; ++i) {
        rigid_body_top[i].Geometry = nullptr;
        writer.writeFormat(&rigid_body_top[i], "dddd,dddd,ddd,d,dddd,ddddddddd,d,ldd,ddd,d,ddd,d,dddddddd", 1);
    }
    for (u32 i = 0; i < mHeader.NumGeometry; ++i) {
        geometry_top[i].Parameter = nullptr;
        writer.writeFormat(&geometry_top[i], "{16,16}dldd", 1);
    }
    for (u32 i = 0; i < mHeader.NumParameter; ++i) {
        writer.writeF32(parameter_top[i]);
    }
    MtMemoryAllocator::getAllocator(rRigidBody::DTI)->memFree(buffer);
    return true;
}

__attribute__((weak)) bool rRigidBody::loadCore(MtDataReader& reader) {
    reader.read(&mHeader, sizeof(HEADER));
    if (mHeader.Magic != 0x444252) {
        return false;
    }
    if (mHeader.Version != 0x77de39d8) {
        return false;
    }
    u32 save_size = mHeader.NumRigidBody * sizeof(RIGID_BODY) + mHeader.NumGeometry * sizeof(GEOMETRY) + mHeader.NumParameter * sizeof(f32);
    mBuffer = static_cast<BYTE*>(MtMemoryAllocator::getAllocator(rRigidBody::DTI)->memAlloc(save_size, 16));
    reader.read(mBuffer, save_size);
    mRigidBody = reinterpret_cast<RIGID_BODY*>(mBuffer);
    GEOMETRY* geometry_top = reinterpret_cast<GEOMETRY*>(mRigidBody + mHeader.NumRigidBody);
    f32* parameter_top = reinterpret_cast<f32*>(geometry_top + mHeader.NumGeometry);
    u32 geometry_index = 0;
    u32 parameter_index = 0;
    for (u32 i = 0; i < mHeader.NumRigidBody; ++i) {
        mRigidBody[i].Geometry = &geometry_top[geometry_index];
        geometry_index += mRigidBody[i].NumGeometry;
        for (u32 j = 0; j < mRigidBody[i].NumGeometry; ++j) {
            GEOMETRY& geometry = mRigidBody[i].Geometry[j];
            geometry.Parameter = &parameter_top[parameter_index];
            switch (geometry.Type) {
            case 5:
                parameter_index += 4;
                break;
            case 6:
            case 9:
                parameter_index += 7;
                break;
            case 8:
                parameter_index += 15;
                break;
            case 10: {
                MT_STR path = reinterpret_cast<MT_STR>(&geometry.Parameter[3]);
                parameter_index += 3 + (static_cast<u32>(strlen(path)) + 1 + 3) / 4;
                break;
            }
            }
        }
    }
    return true;
}

void rRigidBody::clear() {
    memset(&mHeader, 0, sizeof(HEADER));
    if (mBuffer != nullptr) {
        MtMemoryAllocator::getAllocator(rRigidBody::DTI)->memFree(mBuffer);
        mBuffer = nullptr;
    }
    mRigidBody = nullptr;
}

inline rRigidBody::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rRigidBody::MyDTI rRigidBody::DTI("rRigidBody", &::cResource::DTI, 176ul, 0u, 0u);

__attribute__((weak)) MtObject* rRigidBody::MyDTI::newInstance() const {
    // workaround
    void* memory = MtMemoryAllocator::getAllocator(rRigidBody::DTI)->memAlloc(sizeof(rRigidBody), 16u, rRigidBody::DTI.getID());
    return new (memory) rRigidBody;
}

__attribute__((weak)) MtSphere rRigidBody::GEOMETRY::getSphere() const {
    DDON_STUB("rRigidBody::GEOMETRY::getSphere")
    __builtin_unreachable();
}

__attribute__((weak)) MtCapsule rRigidBody::GEOMETRY::getCapsule() const {
    DDON_STUB("rRigidBody::GEOMETRY::getCapsule")
    __builtin_unreachable();
}

__attribute__((weak)) MtOBB rRigidBody::GEOMETRY::getOBB() const {
    DDON_STUB("rRigidBody::GEOMETRY::getOBB")
    __builtin_unreachable();
}

__attribute__((weak)) MtCylinder rRigidBody::GEOMETRY::getCylinder() const {
    DDON_STUB("rRigidBody::GEOMETRY::getCylinder")
    __builtin_unreachable();
}

