// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nDrawMaterial.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCRC.h"
#include "../MT/MtColor.h"
#include "../MT/MtDTI.h"
#include "../MT/MtEaseCurve.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cDraw.h"
#include "nDraw.h"
#include "nDrawResource.h"
#include "nDrawTexture.h"
#include "sRender.h"
#include "sScene.h"
#include "sShader2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& nDraw::Animation::getDTI() const {
    return nDraw::Animation::DTI;
}

void* nDraw::Animation::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nDraw::Animation::DTI)->memAlloc(sz, align, ::nDraw::Animation::DTI.mID);
}

inline void nDraw::Animation::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nDraw::Animation::DTI)->memFree(p_addr);
}

inline u32 nDraw::Animation::getAnimationNum() const {
    return this->mpList->animation_num;
}

inline const nDraw::Animation::ANIMATION* nDraw::Animation::getAnimation(u32 no) const {
    return this->mpList->animations[no];
}

inline void* nDraw::Animation::allocBuf(BUFSTATE& bs, u32 size) {
    if (size == 0) {
        return nullptr;
    }
    void* p = bs.pbuf + bs.pt;
    bs.pt += size;
    return p;
}

inline void* nDraw::CBufferSystem::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nDraw::CBufferSystem::DTI)->memAlloc(sz, align, ::nDraw::CBufferSystem::DTI.getID());
}

inline nDraw::CBufferSystem::CBufferSystem(const nDraw::Animation* panm, SO_HANDLE* vdcb, u32 vdcb_num) : mAnimation(nullptr), mVertexDisplacement(nullptr) {
    generate(panm, vdcb, vdcb_num);
}

nDraw::Animation::Animation(const nDraw::Animation::ANIMATION_LIST* list) {
    u32 bufsize = 0;
    void* pbuf = nullptr;
    ANIMATION_LIST* plist = nullptr;
    if (list != nullptr) {
        bufsize = calcBufSize(list);
        pbuf = MtMemoryAllocator::getAllocator(nDraw::Animation::DTI)->memAlloc(bufsize, 16u);
        plist = copyAnimationList(pbuf, bufsize, list);
    }
    mpList = plist;
    mBufferSize = bufsize;
}

__attribute__((noinline)) nDraw::Animation::~Animation() {
    DDON_STUB("nDraw::Animation::~Animation")
    /* stub */
}

s32 nDraw::Animation::getNo(MT_CTSTR name) const {
    u32 crc = ::MtCRC::getCRC(name, 0xFFFFFFFFu);
    nDraw::Animation::ANIMATION_LIST* v0_1 = mpList;
    u32 v0_2 = v0_1->animation_num;
    u32 v2_9;
    if (v0_2 == 0) {
        v2_9 = 0xFFFFFFFF;
    } else {
        for (u32 i = 0;;) {
            if (v0_1->animations[i]->crc != crc) {
                if ((i + 1u) < v0_2) {
                    i = i + 1u;
                } else {
                    break;
                }
            } else {
                v2_9 = i;
                return static_cast<s32>(v2_9);
            }
        }
        v2_9 = 0xFFFFFFFF;
    }
    return static_cast<s32>(v2_9);
}

__attribute__((weak)) nDraw::Animation::ANIMATION_LIST* nDraw::Animation::copyAnimationList(void* pdst, u32 dst_size, const nDraw::Animation::ANIMATION_LIST* psrc) {
    BUFSTATE bs;
    bs.pbuf = static_cast<u8*>(pdst);
    bs.bufsize = dst_size;
    bs.pt = 0;
    ANIMATION_LIST* ptgt = static_cast<ANIMATION_LIST*>(allocBuf(bs, static_cast<u32>(sizeof(ANIMATION_LIST) + sizeof(ANIMATION*) * (psrc->animation_num - 1))));
    ptgt->animation_num = psrc->animation_num;
    for (u32 i = 0; i < ptgt->animation_num; ++i) {
        ANIMATION* psanm = psrc->animations[i];
        ANIMATION* pdanm = static_cast<ANIMATION*>(allocBuf(bs, static_cast<u32>(sizeof(ANIMATION) + sizeof(PARAM*) * (psanm->param_num - 1))));
        pdanm->cbuffers = static_cast<SO_HANDLE*>(allocBuf(bs, static_cast<u32>(sizeof(SO_HANDLE) * psanm->cbuffer_num)));
        pdanm->cbuffer_num = psanm->cbuffer_num;
        pdanm->crc = psanm->crc;
        pdanm->length = psanm->length;
        pdanm->param_num = psanm->param_num;
        pdanm->repeat = psanm->repeat;
        pdanm->run = psanm->run;
        memcpy(pdanm->cbuffers, psanm->cbuffers, sizeof(SO_HANDLE) * pdanm->cbuffer_num);
        for (u32 j = 0; j < pdanm->param_num; ++j) {
            u32 param_size = 0;
            PARAM* psp = psanm->params[j];
            switch (psp->type) {
            case TYPE_FLOAT:
            case TYPE_INT:
                param_size = static_cast<u32>(sizeof(PARAM_INT) + sizeof(KEY_INT) * (psp->key_num - 1));
                break;
            case TYPE_SAMPLER:
                param_size = static_cast<u32>(sizeof(PARAM_SAMPLER) + sizeof(KEY_SAMPLER) * (psp->key_num - 1));
                break;
            case TYPE_TEXCOORD:
            case TYPE_TEXCOORD2:
                param_size = static_cast<u32>(sizeof(PARAM_TEXCOORD) + sizeof(KEY_TEXCOORD) * (psp->key_num - 1));
                break;
            case TYPE_TEX:
                param_size = static_cast<u32>(sizeof(PARAM_TEX) + sizeof(KEY_TEX) * (psp->key_num - 1));
                break;
            case TYPE_VECTOR:
                param_size = static_cast<u32>(sizeof(PARAM_VECTOR) + sizeof(KEY_VECTOR) * (psp->key_num - 1));
                break;
            case TYPE_LEGACY:
                param_size = static_cast<u32>(sizeof(PARAM_LEGACY) + sizeof(LEGACY_ANIMATION) * (psp->key_num - 1));
                break;
            default:
                break;
            }
            PARAM* pdp = static_cast<PARAM*>(allocBuf(bs, param_size));
            memcpy(pdp, psp, param_size);
            if (psp->type == TYPE_TEX) {
                PARAM_TEX* pparam_tex = static_cast<PARAM_TEX*>(pdp);
                for (u32 k = 0; k < pparam_tex->key_num; ++k) {
                    nDraw::Texture* ptex = pparam_tex->keys[k].value;
                    if (ptex != nullptr) {
                        ptex->addRef();
                    }
                }
            }
            pdanm->params[j] = pdp;
        }
        ptgt->animations[i] = pdanm;
    }
    return ptgt;
}

u32 nDraw::Animation::calcBufSize(const nDraw::Animation::ANIMATION_LIST* list) {
        u32 bufsize = 0;
        if (list != nullptr) {
            bufsize = list->animation_num * sizeof(ANIMATION*) + 8;
            for (u32 i = 0; i < list->animation_num; i++) {
                const ANIMATION* panim = list->animations[i];
                bufsize += panim->param_num * sizeof(PARAM*) + panim->cbuffer_num * sizeof(SO_HANDLE) + 24;
                for (u32 j = 0; j < panim->param_num; j++) {
                    const PARAM* pparam = panim->params[j];
                    switch (pparam->type) {
                    case 0:
                        bufsize += pparam->key_num * sizeof(KEY_INT) + 12;
                        break;
                    case 1:
                        bufsize += pparam->key_num * sizeof(KEY_VECTOR) + 12;
                        break;
                    case 2:
                        bufsize += pparam->key_num * sizeof(KEY_FLOAT) + 12;
                        break;
                    case 3:
                        bufsize += pparam->key_num * sizeof(KEY_TEX) + 8;
                        break;
                    case 4:
                        bufsize += pparam->key_num * 80 + 12;
                        break;
                    case 5:
                        bufsize += pparam->key_num * sizeof(KEY_SAMPLER) + 8;
                        break;
                    case 6:
                        bufsize += pparam->key_num * sizeof(KEY_TEXCOORD) + 12;
                        break;
                    case 7:
                        bufsize += pparam->key_num * 24 + 12;
                        break;
                    }
                }
            }
        }
        return bufsize;
}

inline nDraw::Animation::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nDraw::Animation::MyDTI nDraw::Animation::DTI("nDraw::Animation", &::nDraw::Resource::DTI, 40ul, 0u, 0u);

__attribute__((weak)) MtObject* nDraw::Animation::MyDTI::newInstance() const {
    DDON_STUB("nDraw::Animation::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& nDraw::CBuffer::getDTI() const {
    return nDraw::CBuffer::DTI;
}

inline void nDraw::CBuffer::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nDraw::CBuffer::DTI)->memFree(p_addr);
}

nDraw::CBuffer::~CBuffer() {
    mHandleCount = 0;
    mTempCount = 0;
    if (mHandles != nullptr) {
        ::MtMemoryAllocator::getAllocator(::nDraw::CBuffer::DTI)->memFree(static_cast<void*>(mHandles));
        mHandles = nullptr;
    }
    mppCBuffers[2] = nullptr;
    mppCBuffers[1] = nullptr;
    mppCBuffers[0] = nullptr;
}

__attribute__((weak)) void nDraw::CBuffer::generate() {
    DDON_STUB("nDraw::CBuffer::generate")
    /* stub */
}

__attribute__((weak)) void nDraw::CBuffer::setConstantTable(cDraw* pdraw, SO_HANDLE handle) {
    DDON_STUB("nDraw::CBuffer::setConstantTable")
    /* stub */
}

inline nDraw::CBuffer::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nDraw::CBuffer::MyDTI nDraw::CBuffer::DTI("nDraw::CBuffer", &::nDraw::Resource::DTI, 56ul, 0u, 0u);

__attribute__((weak)) MtObject* nDraw::CBuffer::MyDTI::newInstance() const {
    DDON_STUB("nDraw::CBuffer::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& nDraw::CBufferSystem::getDTI() const {
    return nDraw::CBufferSystem::DTI;
}

nDraw::CBufferSystem::~CBufferSystem() {
    if (mVertexDisplacement != nullptr) {
        delete mVertexDisplacement;
        mVertexDisplacement = nullptr;
    }
    if (mAnimation == nullptr) {
        return;
    }
    delete mAnimation;
    mAnimation = nullptr;
}

__attribute__((weak)) void nDraw::CBufferSystem::generate(const nDraw::Animation* panm, SO_HANDLE* vdcb, u32 vdcb_num) {
    DDON_STUB("nDraw::CBufferSystem::generate")
    /* stub */
}

inline nDraw::CBufferSystem::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nDraw::CBufferSystem::MyDTI nDraw::CBufferSystem::DTI("nDraw::CBufferSystem", &::nDraw::Resource::DTI, 40ul, 0u, 0u);

__attribute__((weak)) MtObject* nDraw::CBufferSystem::MyDTI::newInstance() const {
    DDON_STUB("nDraw::CBufferSystem::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& nDraw::Material::getDTI() const {
    return nDraw::Material::DTI;
}

nDraw::Material::Material(SO_HANDLE technique) {
    mTechnique = technique;
    mAlphaTestEnable = 0;
    mAlphaTestCmpFunc = nDraw::CMP_GREATER;
    mAlphaTestRopTest = 1;
    mAlphaTestRef = 0;
    mSelect = 0;
    mLayerID = 0;
    mDeferredShadowEnable = 1;
    mDrawPass = 12;
    mFogEnable = 1;
    mStateNum = 0;
    mProceduralTextureNum = 0;
    mDeferredLighting = 1;
    mAlbedoAlpha = 0;
    mTangent = 0;
    mHalfLambert = 0;
    mID = 0;
    mAnimationSpeed = 1.0f;
    mpBlendState = nullptr;
    mpRasterizerState = nullptr;
    mpDepthStencilState = nullptr;
    mBlendStateHandle = 0;
    mStates = nullptr;
    mProceduralTexture = nullptr;
    mpAnimation = nullptr;
    mpCBuffer = nullptr;
    mLegacyAnimation = true;
    memset(mAnimationState, 0, sizeof(mAnimationState));
    for (u32 i = 0; i < 4; ++i) {
        mAnimationState[i].no = -1;
    }
    mBlendFactor = MtColorF::Black;
    mpBlendState = sShader2::getInstance()->getBlendState(0x4d2c8185u);
    mBlendStateHandle = 0x4d2c8185u;
    mStencilRef = 0;
    mpDepthStencilState = sShader2::getInstance()->getDepthStencilState(0x1b9u);
    mpRasterizerState = sShader2::getInstance()->getRasterizerState(0x1c2u);
    mpStateAccessTable[0] = nullptr;
    memset(mStateAccessTableNum, 0, sizeof(mStateAccessTableNum));
}

void nDraw::Material::createProperty(MtPropertyList& s) {
    this->::nDraw::Resource::createProperty(s);
    s << ::MtProperty(static_cast<MtObject*>(this), ::MtProperty::TYPE_VECTOR4, "BaseColor", reinterpret_cast<MT_MFUNC>(&::nDraw::Material::getBaseColor), reinterpret_cast<MT_MFUNC>(&::nDraw::Material::setBaseColor), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << ::MtProperty(static_cast<MtObject*>(this), ::MtProperty::TYPE_VECTOR2, "UVOffset", reinterpret_cast<MT_MFUNC>(&::nDraw::Material::getBaseUVOffset), reinterpret_cast<MT_MFUNC>(&::nDraw::Material::setBaseUVOffset), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << ::MtProperty(static_cast<MtObject*>(this), ::MtProperty::TYPE_VECTOR2, "UVScale", reinterpret_cast<MT_MFUNC>(&::nDraw::Material::getBaseUVScale), reinterpret_cast<MT_MFUNC>(&::nDraw::Material::setBaseUVScale), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << ::MtProperty(static_cast<MtObject*>(this), ::MtProperty::TYPE_U8, "StencilRef", reinterpret_cast<MT_MFUNC>(&::nDraw::Material::getStencilRef), reinterpret_cast<MT_MFUNC>(&::nDraw::Material::setStencilRef), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << ::MtProperty(static_cast<MtObject*>(this), ::MtProperty::TYPE_U32, "ID", reinterpret_cast<MT_MFUNC>(&::nDraw::Material::getID), reinterpret_cast<MT_MFUNC>(&::nDraw::Material::setID), 129u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << ::MtProperty(static_cast<MtObject*>(this), "mAnimationSpeed", &mAnimationSpeed, 0u, 0u);
}

MtUI* nDraw::Material::createUI(MtProperty& prop) {
    return this->::MtObject::createUI(prop);
}

__attribute__((weak)) nDraw::Material* nDraw::Material::duplicate() const {
    DDON_STUB("nDraw::Material::duplicate")
    return nullptr;
}

static auto ddon_emit_0x01b83090 __attribute__((used)) = &nDraw::Material::getID;

static auto ddon_emit_0x01b830a0 __attribute__((used)) = &nDraw::Material::setID;

void nDraw::Material::update(f32 dt) {
    if (mpAnimation == nullptr) {
        return;
    }
    applyAnimation(dt);
}

__attribute__((weak)) void nDraw::Material::setTechniqueState(cDraw* pdraw, u32 pass) {
    DDON_STUB("nDraw::Material::setTechniqueState")
    /* stub */
}

static auto ddon_emit_0x01b83080 __attribute__((used)) = &nDraw::Material::setStencilRef;

u8 nDraw::Material::getStencilRef() const {
    return static_cast<u8>(mStencilRef);
}

inline nDraw::BlendState* sShader2::getBlendState(SO_HANDLE handle) {
    return static_cast<nDraw::BlendState*>(this->mShaderStates[handle & 0xfffu].pvalue);
}

inline nDraw::RasterizerState* sShader2::getRasterizerState(SO_HANDLE handle) {
    return static_cast<nDraw::RasterizerState*>(this->mShaderStates[handle & 0xfffu].pvalue);
}

inline nDraw::DepthStencilState* sShader2::getDepthStencilState(SO_HANDLE handle) {
    return static_cast<nDraw::DepthStencilState*>(this->mShaderStates[handle & 0xfffu].pvalue);
}

__attribute__((weak)) void nDraw::Material::setBlendState(SO_HANDLE state, const MtColorF& blendfactor) {
    mBlendFactor = blendfactor;
    mpBlendState = sShader2::getInstance()->getBlendState(state);
    mBlendStateHandle = state;
}

__attribute__((weak)) void nDraw::Material::setRasterizerState(SO_HANDLE state) {
    mpRasterizerState = sShader2::getInstance()->getRasterizerState(state);
}

__attribute__((weak)) void nDraw::Material::setDepthStencilState(SO_HANDLE state, u8 ref) {
    mStencilRef = ref;
    mpDepthStencilState = sShader2::getInstance()->getDepthStencilState(state);
}

__attribute__((weak)) void nDraw::Material::setStateBuffer(const nDraw::Material::STATE* states, u32 state_num, u32 bufsize, bool maketable) {
    DDON_STUB("nDraw::Material::setStateBuffer")
    /* stub */
}

__attribute__((weak)) void nDraw::Material::resetAllAnimation() {
    nDraw::Animation* panm = mpAnimation;
    memset(mAnimationState, 0, sizeof(mAnimationState));
    for (u32 i = 0; i < 4; ++i) {
        mAnimationState[i].no = -1;
    }
    if (panm != nullptr) {
        u32 slot = 0;
        const u32 n = panm->getAnimationNum();
        for (u32 i = 0; i < n; ++i) {
            const nDraw::Animation::ANIMATION* pa = panm->getAnimation(i);
            if (pa->run && slot < 4) {
                ANIMATION_STATE astate;
                astate.no = static_cast<s32>(i);
                astate.state = 0;
                astate.frame = 0.0f;
                mAnimationState[slot] = astate;
                ++slot;
            }
        }
    }
}

__attribute__((weak)) void nDraw::Material::setAnimationData(nDraw::Animation* panm) {
    if (mpAnimation != panm) {
        if (mpAnimation != nullptr) {
            mpAnimation->release();
            mpAnimation = nullptr;
        }
        if (mpCBuffer != nullptr) {
            mpCBuffer->release();
            mpCBuffer = nullptr;
        }
        mpAnimation = panm;
        if (panm != nullptr) {
            panm->addRef();
            for (u32 i = 0; i < mpAnimation->getAnimationNum(); ++i) {
                const nDraw::Animation::ANIMATION* pa = mpAnimation->getAnimation(i);
                if (pa->cbuffer_num != 0) {
                    mpCBuffer = new (16u) nDraw::CBufferSystem(mpAnimation, nullptr, 0);
                    break;
                }
            }
        }
    }
    nDraw::Animation* preset = mpAnimation;
    memset(mAnimationState, 0, sizeof(mAnimationState));
    for (u32 i = 0; i < 4; ++i) {
        mAnimationState[i].no = -1;
    }
    if (preset != nullptr) {
        u32 slot = 0;
        const u32 n = preset->getAnimationNum();
        for (u32 i = 0; i < n; ++i) {
            const nDraw::Animation::ANIMATION* pa = preset->getAnimation(i);
            if (pa->run && slot < 4) {
                ANIMATION_STATE astate;
                astate.no = static_cast<s32>(i);
                astate.state = 0;
                astate.frame = 0.0f;
                mAnimationState[slot] = astate;
                ++slot;
            }
        }
    }
}

void nDraw::Material::setAnimation(nDraw::Material::SLOT_TYPE slot, s32 no) {
    mAnimationState[slot].frame = 0.0f;
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&mAnimationState[slot]) + 0) = static_cast<unsigned short>(no);
}

__attribute__((weak)) s32 nDraw::Material::getAnimation(nDraw::Material::SLOT_TYPE slot) {
    DDON_STUB("nDraw::Material::getAnimation")
    return {};
}

bool nDraw::Material::isCBuffer() const {
    if (mpCBuffer != nullptr) {
        if (mpCBuffer->mAnimation == nullptr) {
            return mpCBuffer->mVertexDisplacement != nullptr;
        } else {
            return true;
        }
    } else {
        return false;
    }
}

__attribute__((weak)) nDraw::ConstantTable* nDraw::Material::getConstantBuffer(SO_HANDLE cbuffer) const {
    DDON_STUB("nDraw::Material::getConstantBuffer")
    return nullptr;
}

__attribute__((weak)) SO_HANDLE nDraw::Material::getFunction(SO_HANDLE handle) const {
    DDON_STUB("nDraw::Material::getFunction")
    return {};
}

__attribute__((weak)) nDraw::Texture* nDraw::Material::getTexture(SO_HANDLE handle) const {
    DDON_STUB("nDraw::Material::getTexture")
    return nullptr;
}

__attribute__((weak)) bool nDraw::Material::setFunction(SO_HANDLE handle, SO_HANDLE function) {
    DDON_STUB("nDraw::Material::setFunction")
    return {};
}

__attribute__((weak)) bool nDraw::Material::setTexture(SO_HANDLE handle, nDraw::Texture* ptex) {
    DDON_STUB("nDraw::Material::setTexture")
    return {};
}

__attribute__((weak)) bool nDraw::Material::setSamplerState(SO_HANDLE handle, SO_HANDLE sampler_handle) {
    DDON_STUB("nDraw::Material::setSamplerState")
    return {};
}

__attribute__((weak)) void nDraw::Material::setBaseColor(const MtVector4& color) {
    DDON_STUB("nDraw::Material::setBaseColor")
    /* stub */
}

__attribute__((weak)) MtVector4 nDraw::Material::getBaseColor() const {
    DDON_STUB("nDraw::Material::getBaseColor")
    __builtin_unreachable();
}

void nDraw::Material::setBaseMap(nDraw::Texture* ptex) {
    setTexture(0xCD06F36Du, ptex);
}

nDraw::Texture* nDraw::Material::getBaseMap() const {
    return static_cast<const ::nDraw::Material*>(this)->getTexture(0xCD06F36Du);
}

__attribute__((weak)) void nDraw::Material::setBaseUVOffset(const MtVector2& v) {
    DDON_STUB("nDraw::Material::setBaseUVOffset")
    /* stub */
}

__attribute__((weak)) MtVector2 nDraw::Material::getBaseUVOffset() const {
    DDON_STUB("nDraw::Material::getBaseUVOffset")
    __builtin_unreachable();
}

__attribute__((weak)) void nDraw::Material::setBaseUVScale(const MtVector2& v) {
    DDON_STUB("nDraw::Material::setBaseUVScale")
    /* stub */
}

__attribute__((weak)) MtVector2 nDraw::Material::getBaseUVScale() const {
    DDON_STUB("nDraw::Material::getBaseUVScale")
    __builtin_unreachable();
}

__attribute__((weak)) u32 nDraw::Material::setDrawState(cDraw* pdraw, nDraw::PASS_TYPE overrideDrawPass) {
    DDON_STUB("nDraw::Material::setDrawState")
    return {};
}

bool nDraw::Material::beginDraw(cDraw* pdraw, u32 pass) {
    return false;
}

__attribute__((weak)) void nDraw::Material::endDraw(cDraw* pdraw, u32 pass) {
}

__attribute__((weak)) void nDraw::Material::setScalarF(SV_HANDLE handle, f32 v) {
    DDON_STUB("nDraw::Material::setScalarF")
    /* stub */
}

__attribute__((weak)) void nDraw::Material::setVectorF(SV_HANDLE handle, const f32* v) {
    DDON_STUB("nDraw::Material::setVectorF")
    /* stub */
}

__attribute__((weak)) f32 nDraw::Material::getScalarF(SV_HANDLE handle) const {
    DDON_STUB("nDraw::Material::getScalarF")
    return {};
}

__attribute__((weak)) const MtFloat3& nDraw::Material::getVector3F(SV_HANDLE handle) const {
    DDON_STUB("nDraw::Material::getVector3F")
    __builtin_unreachable();
}

__attribute__((weak)) const MtVector4& nDraw::Material::getVector4F(SV_HANDLE handle) const {
    DDON_STUB("nDraw::Material::getVector4F")
    __builtin_unreachable();
}

__attribute__((weak)) void nDraw::Material::duplicateAnimationCBuffer() {
    DDON_STUB("nDraw::Material::duplicateAnimationCBuffer")
    /* stub */
}

__attribute__((weak)) void nDraw::Material::duplicateAnimationConstant(cDraw* pdraw) {
    DDON_STUB("nDraw::Material::duplicateAnimationConstant")
    /* stub */
}

__attribute__((weak)) void nDraw::Material::applyAnimation(f32 dt) {
    DDON_STUB("nDraw::Material::applyAnimation")
    /* stub */
}

__attribute__((weak)) bool nDraw::Material::setOutlineState(cDraw* pdraw, nDraw::PASS_TYPE drawpass) {
    DDON_STUB("nDraw::Material::setOutlineState")
    return {};
}

__attribute__((weak)) bool nDraw::Material::setVelocityState(cDraw* pdraw, nDraw::PASS_TYPE drawpass) {
    DDON_STUB("nDraw::Material::setVelocityState")
    return {};
}

__attribute__((weak)) bool nDraw::Material::setShadowCastState(cDraw* pdraw, u32 group, nDraw::PASS_TYPE drawpass) {
    DDON_STUB("nDraw::Material::setShadowCastState")
    return {};
}

__attribute__((weak)) bool nDraw::Material::setShadowRecvState(cDraw* pdraw, u32 group, nDraw::PASS_TYPE drawpass) {
    DDON_STUB("nDraw::Material::setShadowRecvState")
    return {};
}

__attribute__((weak)) void nDraw::Material::releaseStateBuffer() {
    for (u32 i = 0; i < mStateNum; ++i) {
        STATE* pstate = &mStates[i];
        switch (pstate->type) {
        case STATE_SAMPLER: {
            nDraw::Resource* pss = static_cast<nDraw::Resource*>(pstate->state.pvalue);
            if (mRefFrame >= nDraw::Resource::mRenderFrame && pss != nullptr) {
                pss->mRefFrame = nDraw::Resource::mRenderFrame + nDraw::Resource::mProtectFrame;
            }
            if (pss != nullptr) {
                pss->release();
            }
            break;
        }
        case STATE_TEXTURE: {
            nDraw::Resource* pt = static_cast<nDraw::Resource*>(pstate->state.pvalue);
            if (mRefFrame >= nDraw::Resource::mRenderFrame && pt != nullptr) {
                pt->mRefFrame = nDraw::Resource::mRenderFrame + nDraw::Resource::mProtectFrame;
            }
            if (pt != nullptr) {
                pt->release();
            }
            break;
        }
        default:
            break;
        }
    }
    MtMemoryAllocator::getAllocator(nDraw::Material::DTI)->memFree(mStates);
    mStates = nullptr;
    mStateNum = 0;
    MtMemoryAllocator::getAllocator(nDraw::Material::DTI)->memFree(mProceduralTexture);
    mProceduralTextureNum = 0;
    mProceduralTexture = nullptr;
    MtMemoryAllocator::getAllocator(nDraw::Material::DTI)->memFree(mpStateAccessTable[0]);
    memset(mpStateAccessTable, 0, sizeof(mpStateAccessTable));
    memset(mStateAccessTableNum, 0, sizeof(mStateAccessTableNum));
}

nDraw::Material::~Material() {
    releaseStateBuffer();
    if (mpAnimation != nullptr) {
        mpAnimation->release();
        mpAnimation = nullptr;
    }
    if (mpCBuffer == nullptr) {
        return;
    }
    mpCBuffer->release();
    mpCBuffer = nullptr;
}

void nDraw::Material::setSamplerAnimation(SO_HANDLE handle, SO_HANDLE sampler_handle) {
    setSamplerState(handle, sampler_handle);
}

__attribute__((weak)) void nDraw::Material::setIntAnimation(SO_HANDLE handle, SV_HANDLE svhandle, s32 value) {
    DDON_STUB("nDraw::Material::setIntAnimation")
    /* stub */
}

__attribute__((weak)) void nDraw::Material::setFloatAnimation(SO_HANDLE handle, SV_HANDLE svhandle, f32 value) {
    DDON_STUB("nDraw::Material::setFloatAnimation")
    /* stub */
}

__attribute__((weak)) void nDraw::Material::setVectorAnimation(SO_HANDLE handle, SV_HANDLE svhandle, const MtVector4& value) {
    DDON_STUB("nDraw::Material::setVectorAnimation")
    /* stub */
}

__attribute__((weak)) void nDraw::Material::setTexcoordAnimation(SO_HANDLE handle, SV_HANDLE svhandle, const f32* value) {
    DDON_STUB("nDraw::Material::setTexcoordAnimation")
    /* stub */
}

void nDraw::Material::setTextureAnimation(SO_HANDLE handle, nDraw::Texture* ptex) {
    setTexture(handle, ptex);
}

__attribute__((weak)) void nDraw::Material::setState(cDraw* pdraw) {
    DDON_STUB("nDraw::Material::setState")
    /* stub */
}

inline nDraw::Material::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nDraw::Material::MyDTI nDraw::Material::DTI("nDraw::Material", &::nDraw::Resource::DTI, 208ul, 0u, 0u);

__attribute__((weak)) MtObject* nDraw::Material::MyDTI::newInstance() const {
    DDON_STUB("nDraw::Material::MyDTI::newInstance")
    return nullptr;
}

