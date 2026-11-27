// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nPrim.h"
#include "../MT/MtColor.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtPropertyList.h"
#include "sPrimitive.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

s32 nPrim::calcDepthOrder(const MtVector3& pos, const MtVector4& v_vec, f32 pers_rt) {
    return static_cast<s32>((static_cast<int>(static_cast<long>(pers_rt * (v_vec.w + (((v_vec.x * pos.x) + (v_vec.y * pos.y)) + (v_vec.z * pos.z))))) <= 32765) ? static_cast<unsigned int>(static_cast<long>(pers_rt * (v_vec.w + (((v_vec.x * pos.x) + (v_vec.y * pos.y)) + (v_vec.z * pos.z))))) : 32765u);
}

s32 nPrim::calcDepthOrder2D(f32, const MtVector4&) {
    return 0;
}

__attribute__((weak)) void nPrim::setAlphaBlendState(cDraw* p_draw, const nPrim::Material& material) {
    DDON_STUB("nPrim::setAlphaBlendState")
    /* stub */
}

s32 nPrim::beginBranch(cDraw* p_draw, cDraw* sub_draw, u32 nsub_draw, bool use_vscr) {
    return (sPrimitive::mpInstance)->beginBranch(p_draw, sub_draw, nsub_draw, use_vscr);
}

s32 nPrim::endBranch(cDraw* p_draw, cDraw* sub_draw, u32 nsub_draw) {
    return (sPrimitive::mpInstance)->endBranch(p_draw, sub_draw, nsub_draw);
}

const MtDTI& nPrim::PrimVertex::getDTI() const {
    return nPrim::PrimVertex::DTI;
}

__attribute__((weak)) void nPrim::PrimVertex::createProperty(MtPropertyList& prop_list) {
    DDON_STUB("nPrim::PrimVertex::createProperty")
    /* stub */
}

MtUI* nPrim::PrimVertex::createUI(MtProperty& prop) {
    return this->::MtObject::createUI(prop);
}

inline nPrim::PrimVertex::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nPrim::PrimVertex::MyDTI nPrim::PrimVertex::DTI("nPrim::PrimVertex", &::MtObject::DTI, 96ul, 0u, 0u);

__attribute__((weak)) MtObject* nPrim::PrimVertex::MyDTI::newInstance() const {
    DDON_STUB("nPrim::PrimVertex::MyDTI::newInstance")
    return nullptr;
}

