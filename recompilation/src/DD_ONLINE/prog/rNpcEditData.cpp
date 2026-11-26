// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rNpcEditData.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtDataWriter.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cResource.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rNpcEditData::getDTI() const {
    return rNpcEditData::DTI;
}

inline void* rNpcEditData::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rNpcEditData::DTI)->memAlloc(sz, align, rNpcEditData::DTI.getID());
}

inline void rNpcEditData::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rNpcEditData::DTI)->memFree(p_addr);
}

MT_CTSTR rNpcEditData::getExt() const {
    return "ned";
}

void rNpcEditData::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mEquip", &this->mEquip[0], 32u, 16u);
    s << MtProperty(static_cast<MtObject*>(this), "mItem", &mItem, 0u, 0u);
}

bool rNpcEditData::load(MtStream& in) {
    MtDataReader r(in, 4096u);
    u32 header = (&r)->readU32();
    if (header == 0x44454E) {
        u32 dataVersion = (&r)->readU32();
        if (dataVersion == 3) {
            unsigned int* held0 = &this->mEquip[0];
            u32 t3 = (&r)->readU32();
            (&r)->read(static_cast<void*>(held0), t3 * 4u);
            mItem = (&r)->readU32();
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool rNpcEditData::save(MtStream& out) {
    MtDataWriter w(out, 4096u, 4096u);
    (&w)->writeU32(0x44454Eu);
    (&w)->writeU32(3u);
    unsigned int* held0 = &this->mEquip[0];
    (&w)->writeU32(16u);
    (&w)->write(static_cast<const void*>(held0), 64u);
    (&w)->writeU32(mItem);
    return true;
}

inline rNpcEditData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rNpcEditData::MyDTI rNpcEditData::DTI("rNpcEditData", &::cResource::DTI, 184ul, 0u, 0u);

MtObject* rNpcEditData::MyDTI::newInstance() const {
    return new (16u) rNpcEditData;
}

