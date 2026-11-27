// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "rMaterial.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCRC.h"
#include "../MT/MtDTI.h"
#include "../MT/MtEaseCurve.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtStream.h"
#include "cResource.h"
#include "nDrawMaterial.h"
#include "nDrawTexture.h"
#include "rTexture.h"
#include "sResource.h"
#include "sShader2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rMaterial::getDTI() const {
    return rMaterial::DTI;
}

rMaterial::~rMaterial() {
    this->rMaterial::clear();
}

MT_CTSTR rMaterial::getExt() const {
    return "mrl";
}

__attribute__((weak)) void rMaterial::clear() {
    if (this->mpMaterials != nullptr) {
        for (u32 i = 0; i < this->mpHeader->texture_num; ++i) {
            if (this->mpHeader->textures[i].ptex != nullptr) {
                this->mpHeader->textures[i].ptex->release();
                this->mpHeader->textures[i].ptex = nullptr;
            }
            if (this->mpHeader->textures[i].plut != nullptr) {
                this->mpHeader->textures[i].plut->release();
                this->mpHeader->textures[i].plut = nullptr;
            }
        }
        for (u32 i = 0; i < this->mpHeader->material_num; ++i) {
            if (this->mpMaterials[i] != nullptr) {
                this->mpMaterials[i]->release();
                this->mpMaterials[i] = nullptr;
            }
        }
        }
    MtMemoryAllocator::getAllocator(rMaterial::DTI)->memFree(this->mpMaterials);
    MtMemoryAllocator::getAllocator(rMaterial::DTI)->memFree(this->mpHeader);
    this->mpHeader = nullptr;
    this->mpMaterials = nullptr;
}

__attribute__((weak)) bool rMaterial::load(MtStream& in) {
        u32 size = in.getLength();
        mpHeader = static_cast<HEADER*>(MtMemoryAllocator::getAllocator(rMaterial::DTI)->memAlloc(size, 16));
        in.read(mpHeader, size);
        if (mpHeader->magic != 0x4C524D) {
            return false;
        }
        if (mpHeader->version != 34) {
            return false;
        }
        if (mpHeader->shader_version != sShader2::mpInstance->mShaderVersion) {
            return false;
        }
        if (mpHeader->materials != nullptr) {
            mpHeader->materials = reinterpret_cast<MATERIAL_INFO*>(reinterpret_cast<u8*>(mpHeader) + reinterpret_cast<size_t>(mpHeader->materials));
        } else {
            mpHeader->materials = nullptr;
        }
        if (mpHeader->textures != nullptr) {
            mpHeader->textures = reinterpret_cast<TEXTURE_INFO*>(reinterpret_cast<u8*>(mpHeader) + reinterpret_cast<size_t>(mpHeader->textures));
        } else {
            mpHeader->textures = nullptr;
        }
        for (u32 i = 0; i < mpHeader->texture_num; i++) {
            TEXTURE_INFO* pinfo = &mpHeader->textures[i];
            if (pinfo->dti != 0) {
                const MtDTI* pdti = MtDTI::from(pinfo->dti);
                if (pdti == nullptr) {
                    return false;
                }
                pinfo->ptex = static_cast<rTexture*>(sResource::mpInstance->create(*pdti, pinfo->rpath, 1));
            } else {
                LUT_INFO* pli = &pinfo->lutinfo;
                f32 lut[512];
                createLUT(lut, *pli);
                pinfo->plut = new (16u) nDraw::Texture(pli->width, pli->height, 1, static_cast<nDraw::FORMAT_TYPE>(pli->format), nDraw::USAGE_DEFAULT, 0, nullptr, 0, lut, nDraw::TEXMEMORY_VRAM);
            }
        }
        mpMaterials = static_cast<nDraw::Material**>(MtMemoryAllocator::getAllocator(rMaterial::DTI)->memAlloc(sizeof(nDraw::Material*) * mpHeader->material_num, 16));
        memset(mpMaterials, 0, sizeof(nDraw::Material*) * mpHeader->material_num);
        return true;
}

inline void nDraw::Material::setAlphaTest(bool enable, nDraw::COMPARISON_FUNC func, u8 ref) {
    this->mAlphaTestEnable = enable;
    this->mAlphaTestCmpFunc = enable ? func : nDraw::CMP_ALWAYS;
    this->mAlphaTestRef = ref;
}

inline void nDraw::Material::setDrawPass(nDraw::PASS_TYPE drawpass) {
    this->mDrawPass = drawpass;
}

inline void nDraw::Material::setFogEnable(bool v) {
    this->mFogEnable = v;
}

inline void nDraw::Material::setLayerID(u32 id) {
    this->mLayerID = id;
}

inline void nDraw::Material::setDeferredLightingEnable(bool v) {
    this->mDeferredLighting = v;
}

inline void nDraw::Material::setTangentEnable(bool v) {
    this->mTangent = v;
}

inline void nDraw::Material::setHalfLambertEnable(bool v) {
    this->mHalfLambert = v;
}

inline u32 nDraw::Resource::getCRC() const {
    return this->mCRC;
}

__attribute__((weak)) bool rMaterial::loadEnd() {
    const nDraw::SHADER_STATE* defaultstates = sShader2::mpInstance->mShaderStates;
    for (u32 i = 0; i < mpHeader->material_num; ++i) {
        HEADER* phdr = mpHeader;
        MATERIAL_INFO* pinfo = &phdr->materials[i];
        pinfo->animation_list = pinfo->animation_list != nullptr ? reinterpret_cast<nDraw::Animation::ANIMATION_LIST*>(reinterpret_cast<uintptr>(pinfo->animation_list) + reinterpret_cast<uintptr>(phdr)) : nullptr;
        pinfo->states = pinfo->states != nullptr ? reinterpret_cast<nDraw::Material::STATE*>(reinterpret_cast<uintptr>(pinfo->states) + reinterpret_cast<uintptr>(phdr)) : nullptr;
        pinfo->dsstate = sShader2::mpInstance->remapObjectHandle(pinfo->dsstate);
        pinfo->rsstate = sShader2::mpInstance->remapObjectHandle(pinfo->rsstate);
        pinfo->bsstate = sShader2::mpInstance->remapObjectHandle(pinfo->bsstate);
        if (pinfo->dsstate == 0) {
            return false;
        }
        if (pinfo->rsstate == 0) {
            return false;
        }
        if (pinfo->bsstate == 0) {
            return false;
        }
        for (u32 j = 0; j < pinfo->state_num; ++j) {
            nDraw::Material::STATE* pstate = &pinfo->states[j];
            SO_HANDLE handle = sShader2::mpInstance->remapObjectHandle(pstate->state.crc);
            if (handle == 0) {
                return false;
            }
            pstate->index = handle;
            switch (pstate->type) {
            case nDraw::Material::STATE_CBUFFER:
                pstate->state.ivalue = pstate->state.ivalue != 0 ? pstate->state.ivalue + reinterpret_cast<uintptr>(pinfo->states) : 0;
                pstate->state.crc = 0;
                break;
            case nDraw::Material::STATE_TEXTURE:
                if (pstate->state.ivalue != 0) {
                    if (pstate->state.ivalue > mpHeader->texture_num) {
                        return false;
                    }
                    TEXTURE_INFO* ptex = &mpHeader->textures[pstate->state.ivalue - 1];
                    if (ptex->ptex != nullptr) {
                        pstate->state.pvalue = ptex->ptex->mpTexture;
                        pstate->state.crc = (handle & 0xfffff000u) | ptex->ptex->mpTexture->getCRC();
                    } else if (ptex->plut != nullptr) {
                        pstate->state.pvalue = ptex->plut;
                        pstate->state.crc = (handle & 0xfffff000u) | ptex->plut->getCRC();
                    } else {
                        pstate->state.pvalue = nullptr;
                        pstate->state.crc = 0;
                    }
                } else {
                    pstate->state = defaultstates[handle & 0xfffu];
                }
                break;
            case nDraw::Material::STATE_FUNCTION:
            case nDraw::Material::STATE_PROCEDURAL: {
                SO_HANDLE function_handle = sShader2::mpInstance->remapObjectHandle(static_cast<SO_HANDLE>(pstate->state.ivalue));
                if (function_handle == 0) {
                    return false;
                }
                pstate->state.pvalue = defaultstates[function_handle & 0xfffu].pvalue;
                pstate->state.crc = ((handle ^ function_handle) & 0xfffff000u) | (function_handle & 0xfffu);
                break;
            }
            case nDraw::Material::STATE_SAMPLER: {
                SO_HANDLE sampler_handle = sShader2::mpInstance->remapObjectHandle(static_cast<SO_HANDLE>(pstate->state.ivalue));
                if (sampler_handle == 0) {
                    return false;
                }
                pstate->state = defaultstates[sampler_handle & 0xfffu];
                break;
            }
            default:
                break;
            }
        }
        if (pinfo->animation_list != nullptr) {
            for (u32 j = 0; j < pinfo->animation_list->animation_num; ++j) {
                nDraw::Animation::ANIMATION_LIST* plist = pinfo->animation_list;
                nDraw::Animation::ANIMATION* pa = plist->animations[j] != nullptr ? reinterpret_cast<nDraw::Animation::ANIMATION*>(reinterpret_cast<uintptr>(plist->animations[j]) + reinterpret_cast<uintptr>(plist)) : nullptr;
                pa->cbuffers = pa->cbuffers != nullptr ? reinterpret_cast<SO_HANDLE*>(reinterpret_cast<uintptr>(pa->cbuffers) + reinterpret_cast<uintptr>(plist)) : nullptr;
                for (u32 k = 0; k < pa->cbuffer_num; ++k) {
                    pa->cbuffers[k] = sShader2::mpInstance->remapObjectHandle(pa->cbuffers[k]);
                }
                for (u32 k = 0; k < pa->param_num; ++k) {
                    nDraw::Animation::PARAM* pp = pa->params[k] != nullptr ? reinterpret_cast<nDraw::Animation::PARAM*>(reinterpret_cast<uintptr>(pa->params[k]) + reinterpret_cast<uintptr>(pinfo->animation_list)) : nullptr;
                    pp->handle = sShader2::mpInstance->remapObjectHandle(pp->handle);
                    if (pp->type == 3) {
                        nDraw::Animation::PARAM_TEX* ptp = static_cast<nDraw::Animation::PARAM_TEX*>(pp);
                        for (u32 m = 0; m < ptp->key_num; ++m) {
                            if (ptp->keys[m].value != nullptr) {
                                rTexture* ptex = mpHeader->textures[reinterpret_cast<uintptr>(ptp->keys[m].value) - 1].ptex;
                                if (ptex != nullptr) {
                                    ptp->keys[m].value = ptex->mpTexture;
                                }
                            }
                        }
                    }
                    if (pp->type == 5) {
                        nDraw::Animation::PARAM_SAMPLER* pip = static_cast<nDraw::Animation::PARAM_SAMPLER*>(pp);
                        for (u32 m = 0; m < pip->key_num; ++m) {
                            pip->keys[m].value = sShader2::mpInstance->remapObjectHandle(pip->keys[m].value);
                        }
                    }
                    pa->params[k] = pp;
                }
                pinfo->animation_list->animations[j] = pa;
            }
        }
        const MtDTI* pdti = MtDTI::from(pinfo->dti);
        if (pdti == nullptr) {
            return false;
        }
        nDraw::Material* pmat = static_cast<nDraw::Material*>(pdti->newInstance());
        const MtDTI* pt = &pmat->getDTI();
        if (pt->mName != nDraw::Material::DTI.mName) {
            do {
                pt = pt->mpParent;
                if (pt == nullptr) {
                    return false;
                }
            } while (pt->mName != nDraw::Material::DTI.mName);
        }
        pmat->setAlphaTest(pinfo->alphatest, static_cast<nDraw::COMPARISON_FUNC>(pinfo->alphatest_func), pinfo->alphatest_ref);
        pmat->setDepthStencilState(pinfo->dsstate, pinfo->stencil_ref);
        MtColorF c;
        c.r = pinfo->blend_factor.x;
        c.g = pinfo->blend_factor.y;
        c.b = pinfo->blend_factor.z;
        c.a = pinfo->blend_factor.w;
        pmat->setBlendState(pinfo->bsstate, c);
        pmat->setRasterizerState(pinfo->rsstate);
        pmat->setDrawPass(static_cast<nDraw::PASS_TYPE>(pinfo->draw_pass));
        pmat->setFogEnable(pinfo->fog);
        pmat->setID(pinfo->id);
        pmat->setLayerID(pinfo->layer_id);
        pmat->setDeferredLightingEnable(pinfo->deferred_lighting);
        pmat->setTangentEnable(pinfo->tangent);
        pmat->setHalfLambertEnable(pinfo->half_lambert);
        pmat->setStateBuffer(pinfo->states, pinfo->state_num, pinfo->state_bufsize, true);
        if (pinfo->animation_list != nullptr) {
            nDraw::Animation* panm = new (16u) nDraw::Animation(pinfo->animation_list);
            pmat->setAnimationData(panm);
            if (panm != nullptr) {
                panm->release();
            }
        }
        mpMaterials[i] = pmat;
    }
    return true;
}

__attribute__((weak)) nDraw::Material* rMaterial::getMaterial(MT_CTSTR name) {
    if (mpHeader != nullptr) {
        const u32 crc = MtCRC::getCRC(name, 0xFFFFFFFFu);
        const u32 n = getMaterialNum();
        for (u32 i = 0; i < n; ++i) {
            if (mpHeader->materials[i].name == crc) {
                return mpMaterials[i];
            }
        }
    }
    return sShader2::mpInstance->mpNullMaterial;
}

nDraw::Material* rMaterial::getMaterial(u32 index) {
    return mpMaterials[index];
}

u32 rMaterial::getMaterialNum() {
    return mpHeader->material_num;
}

u32 rMaterial::getTextureNum() {
    return mpHeader->texture_num;
}

u32 rMaterial::getMaterialIndexFromName(MT_CTSTR name) {
    unsigned int v2_8;
    if (mpHeader == nullptr) {
        v2_8 = 0x7FFFFFFF;
    } else {
        u32 crc = MtCRC::getCRC(name, 0xFFFFFFFFu);
        u32 n = getMaterialNum();
        if (n == 0) {
            v2_8 = 0x7FFFFFFF;
        } else {
            MATERIAL_INFO* p0_1 = mpHeader->materials;
            for (unsigned int i0_2 = 0;;) {
                if (p0_1->name != crc) {
                    if ((i0_2 + 1u) < n) {
                        p0_1 += 1;
                        i0_2 += 1u;
                    } else {
                        break;
                    }
                } else {
                    v2_8 = i0_2;
                    return v2_8;
                }
            }
            v2_8 = 0x7FFFFFFF;
        }
    }
    return v2_8;
}

__attribute__((weak)) void rMaterial::createLUT(void* pdst, const rMaterial::LUT_INFO& info) {
    DDON_STUB("rMaterial::createLUT")
    /* stub */
}

inline rMaterial::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rMaterial::MyDTI rMaterial::DTI("rMaterial", &::cResource::DTI, 128ul, 0u, 0u);

MtObject* rMaterial::MyDTI::newInstance() const {
    return new (16u) rMaterial;
}

