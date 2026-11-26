// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rGUI.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemory.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtPrimitive2D.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtStream.h"
#include "../MT/MtString.h"
#include "cGUIFontFilter.h"
#include "cGUIInstance.h"
#include "cGUIObject.h"
#include "cGUIVariable.h"
#include "cResource.h"
#include "nDrawVertexBuffer.h"
#include "nGUI.h"
#include "rGUIFont.h"
#include "rGUIMessage.h"
#include "rRenderTargetTexture.h"
#include "rTexture.h"
#include "sGUI.h"
#include "sResource.h"

#include "../MT/MtColor.h"
#include "../MT/MtStlCustom.h"
#include <string.h>
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rGUI::getDTI() const {
    return rGUI::DTI;
}

inline void* rGUI::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rGUI::DTI)->memAlloc(sz, align, rGUI::DTI.mID);
}

inline void rGUI::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rGUI::DTI)->memFree(p_addr);
}

__attribute__((noinline)) rGUI::~rGUI() {
        clear();
}

bool rGUI::load(MtStream& in) {
    u32 size = in.getLength();
    void* t0 = memAlloc(size);
    if ((mpHeader = static_cast<HEADER*>(t0)) != nullptr) {
        in.read(t0, size);
        if (mpHeader->magic == 0x495547) {
            if (mpHeader->version == 0x21F13) {
                mAttr = mpHeader->attr;
                return setData();
            }
        }
        memFree(static_cast<void*>(mpHeader));
        mpHeader = nullptr;
    }
    return false;
}

__attribute__((weak)) bool rGUI::loadEnd() {
    DDON_STUB("rGUI::loadEnd")
    return {};
}

bool rGUI::save(MtStream& out) {
    return false;
}

MtUI* rGUI::createUI(MtProperty& prop) {
    return this->cResource::createUI(prop);
}

void rGUI::createProperty(MtPropertyList& s) {
    this->cResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "UseAlphaMask", reinterpret_cast<MT_MFUNC>(&::rGUI::isUseAlphaMask), reinterpret_cast<MT_MFUNC>(&::rGUI::setUseAlphaMask), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "BaseZ", reinterpret_cast<MT_MFUNC>(&::rGUI::getBaseZ), reinterpret_cast<MT_MFUNC>(&::rGUI::setBaseZ), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "FrameRateMode", reinterpret_cast<MT_MFUNC>(&::rGUI::getFramerateMode), reinterpret_cast<MT_MFUNC>(&::rGUI::setFramerateMode), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "LanguageSettingNo", reinterpret_cast<MT_MFUNC>(&::rGUI::getLanguageSettingNo), reinterpret_cast<MT_MFUNC>(&::rGUI::setLanguageSettingNo), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "3D", reinterpret_cast<MT_MFUNC>(&::rGUI::is3D), reinterpret_cast<MT_MFUNC>(&::rGUI::set3D), 129u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mInstanceNullNeedNum", &mInstanceNullNeedNum, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mInstanceScissorMaskNeedNum", &mInstanceScissorMaskNeedNum, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mInstanceAnimationNeedNum", &mInstanceAnimationNeedNum, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mInstanceAnimVariableNeedNum", &mInstanceAnimVariableNeedNum, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mInstanceAnimControlNeedNum", &mInstanceAnimControlNeedNum, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGUIObjTextNeedNum", &mGUIObjTextNeedNum, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGUIObjMessageNeedNum", &mGUIObjMessageNeedNum, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGUIObjChildAnimationRootNeedNum", &mGUIObjChildAnimationRootNeedNum, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGUIObjNullNeedNum", &mGUIObjNullNeedNum, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGUIObjTextureSetNeedNum", &mGUIObjTextureSetNeedNum, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGUIObjTextureNeedNum", &mGUIObjTextureNeedNum, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGUIObjPolygonNeedNum", &mGUIObjPolygonNeedNum, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGUIObjScissorMaskNeedNum", &mGUIObjScissorMaskNeedNum, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGUIObjColorAdjustNeedNum", &mGUIObjColorAdjustNeedNum, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGUIObjRootNeedNum", &mGUIObjRootNeedNum, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGUIVarIntNeedNum", &mGUIVarIntNeedNum, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGUIVarFloatNeedNum", &mGUIVarFloatNeedNum, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCreateAnimationBufferSize", &mCreateAnimationBufferSize, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mObjRootNeedSetObjectBufferSize", &mObjRootNeedSetObjectBufferSize, 3u, 0u);
}

MT_CTSTR rGUI::getExt() const {
    return "gui";
}

__attribute__((weak)) void rGUI::clear() {
        if (mpHeader) {
            if (mIsSetData) {
                nGUI::TEXTURE* pTexture = mpHeader->pTexture;
                for (u32 i = 0; i < mpHeader->textureNum; ++i, ++pTexture) {
                    if (pTexture->pTexture) {
                        pTexture->pTexture->release();
                        pTexture->pTexture = nullptr;
                    }
                }
                nGUI::FONT* pFont = mpHeader->pFont;
                for (u32 i = 0; i < mpHeader->fontNum; ++i, ++pFont) {
                    rGUIFont* pResource = pFont->pFont;
                    if (pResource) pResource->release();
                }
                nGUI::MESSAGE* pMessage = mpHeader->pMessage;
                for (u32 i = 0; i < mpHeader->messageNum; ++i, ++pMessage) {
                    cResource* pResource = static_cast<cResource*>(pMessage->pMessage);
                    if (pResource) pResource->release();
                }
                nGUI::GUIRESOURCE* pGUIResource = mpHeader->pGUIResource;
                for (u32 i = 0; i < mpHeader->guiResourceNum; ++i, ++pGUIResource) {
                    cResource* pResource = static_cast<cResource*>(pGUIResource->pResource);
                    if (pResource) pResource->release();
                }
                nGUI::GENERALRESOURCE* pGeneralResource = mpHeader->pGeneralResource;
                for (u32 i = 0; i < mpHeader->generalResourceNum; ++i, ++pGeneralResource) {
                    cResource* pResource = static_cast<cResource*>(pGeneralResource->pResource);
                    if (pResource) pResource->release();
                }
                for (u32 i = 0; i < mpHeader->fontFilterNum; ++i) {
                    if (mpFontFilter[i]) {
                        delete mpFontFilter[i];
                        mpFontFilter[i] = nullptr;
                    }
                }
                memFree(mpFontFilter);
                mpFontFilter = nullptr;
                mIsSetData = 0;
            }
            memFree(mpHeader);
            mpHeader = nullptr;
        }
        if (mpInstanceNeedObjectInfo) {
            memFree(mpInstanceNeedObjectInfo);
            mpInstanceNeedObjectInfo = nullptr;
        }
        mInstanceNullNeedNum = 0;
        mInstanceScissorMaskNeedNum = 0;
        mInstanceAnimationNeedNum = 0;
        mInstanceAnimVariableNeedNum = 0;
        mInstanceAnimControlNeedNum = 0;
        mGUIObjTextNeedNum = 0;
        mGUIObjMessageNeedNum = 0;
        mGUIObjChildAnimationRootNeedNum = 0;
        mGUIObjNullNeedNum = 0;
        mGUIObjTextureSetNeedNum = 0;
        mGUIObjTextureNeedNum = 0;
        mGUIObjPolygonNeedNum = 0;
        mGUIObjScissorMaskNeedNum = 0;
        mGUIObjColorAdjustNeedNum = 0;
        mGUIObjRootNeedNum = 0;
        mGUIVarIntNeedNum = 0;
        mGUIVarFloatNeedNum = 0;
        mCreateAnimationBufferSize = 0;
        mObjRootNeedSetObjectBufferSize = 0;
        if (mpVertexBuffer) {
            mpVertexBuffer->release();
            mpVertexBuffer = nullptr;
        }
}

template <>
inline MtStlAllocator<rGUI::AnimationSearch>::MtStlAllocator() {
}
template <>
inline MtStlAllocator<rGUI::AnimationSearch>::pointer MtStlAllocator<rGUI::AnimationSearch>::allocate(size_type num) {
    return static_cast<pointer>(MtMemory::getAllocator(3)->memAlloc(num * sizeof(rGUI::AnimationSearch), 16u));
}
template <>
inline void MtStlAllocator<rGUI::AnimationSearch>::deallocate(pointer block, size_type) {
    MtMemory::getAllocator(3)->memFree(block);
}
template <>
inline MtStlVector<rGUI::AnimationSearch, MtStlAllocator<rGUI::AnimationSearch> >::MtStlVector() {
}

__attribute__((weak)) bool rGUI::setData() {
    mViewSize.w = mpHeader->viewSize.w;
    mViewSize.h = mpHeader->viewSize.h;
    mBaseZ = mpHeader->baseZ;
    mFramerateMode = mpHeader->framerateMode;
    mLanguageSettingNo = mpHeader->languageSettingNo;
    mpHeader->pAnimation = mpHeader->animationOffset != 0 ? reinterpret_cast<nGUI::ANIMATION*>(reinterpret_cast<uintptr>(mpHeader) + mpHeader->animationOffset) : nullptr;
    mpHeader->pSequence = mpHeader->sequenceOffset != 0 ? reinterpret_cast<nGUI::SEQUENCE*>(reinterpret_cast<uintptr>(mpHeader) + mpHeader->sequenceOffset) : nullptr;
    mpHeader->pObject = mpHeader->objectOffset != 0 ? reinterpret_cast<nGUI::OBJECT*>(reinterpret_cast<uintptr>(mpHeader) + mpHeader->objectOffset) : nullptr;
    mpHeader->pObjSequence = mpHeader->objSequenceOffset != 0 ? reinterpret_cast<nGUI::OBJ_SEQUENCE*>(reinterpret_cast<uintptr>(mpHeader) + mpHeader->objSequenceOffset) : nullptr;
    mpHeader->pInitParam = mpHeader->initParamOffset != 0 ? reinterpret_cast<nGUI::INIT_PARAM*>(reinterpret_cast<uintptr>(mpHeader) + mpHeader->initParamOffset) : nullptr;
    mpHeader->pParam = mpHeader->paramOffset != 0 ? reinterpret_cast<nGUI::PARAM*>(reinterpret_cast<uintptr>(mpHeader) + mpHeader->paramOffset) : nullptr;
    mpHeader->pInstance = mpHeader->instanceOffset != 0 ? reinterpret_cast<nGUI::INSTANCE*>(reinterpret_cast<uintptr>(mpHeader) + mpHeader->instanceOffset) : nullptr;
    mpHeader->pFlow = mpHeader->flowOffset != 0 ? reinterpret_cast<nGUI::FLOW*>(reinterpret_cast<uintptr>(mpHeader) + mpHeader->flowOffset) : nullptr;
    mpHeader->pFlowProcess = mpHeader->flowProcessOffset != 0 ? reinterpret_cast<nGUI::FLOW_PROCESS*>(reinterpret_cast<uintptr>(mpHeader) + mpHeader->flowProcessOffset) : nullptr;
    mpHeader->pFlowInput = mpHeader->flowInputOffset != 0 ? reinterpret_cast<nGUI::FLOW_INPUT*>(reinterpret_cast<uintptr>(mpHeader) + mpHeader->flowInputOffset) : nullptr;
    mpHeader->pFlowSwitch = mpHeader->flowSwitchOffset != 0 ? reinterpret_cast<nGUI::FLOW_SWITCH*>(reinterpret_cast<uintptr>(mpHeader) + mpHeader->flowSwitchOffset) : nullptr;
    mpHeader->pFlowFunction = mpHeader->flowFunctionOffset != 0 ? reinterpret_cast<nGUI::FLOW_FUNCTION*>(reinterpret_cast<uintptr>(mpHeader) + mpHeader->flowFunctionOffset) : nullptr;
    mpHeader->pAction = mpHeader->actionOffset != 0 ? reinterpret_cast<nGUI::ACTION*>(reinterpret_cast<uintptr>(mpHeader) + mpHeader->actionOffset) : nullptr;
    mpHeader->pInputCondition = mpHeader->inputConditionOffset != 0 ? reinterpret_cast<nGUI::INPUT_CONDITION*>(reinterpret_cast<uintptr>(mpHeader) + mpHeader->inputConditionOffset) : nullptr;
    mpHeader->pSwitchOperator = mpHeader->switchOperatorOffset != 0 ? reinterpret_cast<nGUI::SWITCH_OPERATOR*>(reinterpret_cast<uintptr>(mpHeader) + mpHeader->switchOperatorOffset) : nullptr;
    mpHeader->pSwitchCondition = mpHeader->switchConditionOffset != 0 ? reinterpret_cast<nGUI::SWITCH_CONDITION*>(reinterpret_cast<uintptr>(mpHeader) + mpHeader->switchConditionOffset) : nullptr;
    mpHeader->pVariable = mpHeader->variableOffset != 0 ? reinterpret_cast<nGUI::VARIABLE*>(reinterpret_cast<uintptr>(mpHeader) + mpHeader->variableOffset) : nullptr;
    mpHeader->pTexture = mpHeader->textureOffset != 0 ? reinterpret_cast<nGUI::TEXTURE*>(reinterpret_cast<uintptr>(mpHeader) + mpHeader->textureOffset) : nullptr;
    mpHeader->pFont = mpHeader->fontOffset != 0 ? reinterpret_cast<nGUI::FONT*>(reinterpret_cast<uintptr>(mpHeader) + mpHeader->fontOffset) : nullptr;
    mpHeader->pFontFilter = mpHeader->fontFilterOffset != 0 ? reinterpret_cast<void*>(reinterpret_cast<uintptr>(mpHeader) + mpHeader->fontFilterOffset) : nullptr;
    mpHeader->pMessage = mpHeader->messageOffset != 0 ? reinterpret_cast<nGUI::MESSAGE*>(reinterpret_cast<uintptr>(mpHeader) + mpHeader->messageOffset) : nullptr;
    mpHeader->pGUIResource = mpHeader->guiResourceOffset != 0 ? reinterpret_cast<nGUI::GUIRESOURCE*>(reinterpret_cast<uintptr>(mpHeader) + mpHeader->guiResourceOffset) : nullptr;
    mpHeader->pGeneralResource = mpHeader->generalResourceOffset != 0 ? reinterpret_cast<nGUI::GENERALRESOURCE*>(reinterpret_cast<uintptr>(mpHeader) + mpHeader->generalResourceOffset) : nullptr;
    mpHeader->pCameraSetting = mpHeader->cameraSettingOffset != 0 ? reinterpret_cast<nGUI::CAMERA_SETTING*>(reinterpret_cast<uintptr>(mpHeader) + mpHeader->cameraSettingOffset) : nullptr;
    mpHeader->pString = mpHeader->stringOffset != 0 ? reinterpret_cast<MT_STR>(reinterpret_cast<uintptr>(mpHeader) + mpHeader->stringOffset) : nullptr;
    mpHeader->pKey = mpHeader->keyOffset != 0 ? reinterpret_cast<nGUI::KEY*>(reinterpret_cast<uintptr>(mpHeader) + mpHeader->keyOffset) : nullptr;
    mpHeader->pKeyValue8 = mpHeader->keyValue8Offset != 0 ? reinterpret_cast<u8*>(reinterpret_cast<uintptr>(mpHeader) + mpHeader->keyValue8Offset) : nullptr;
    mpHeader->pKeyValue32 = mpHeader->keyValue32Offset != 0 ? reinterpret_cast<u8*>(reinterpret_cast<uintptr>(mpHeader) + mpHeader->keyValue32Offset) : nullptr;
    mpHeader->pKeyValue128 = mpHeader->keyValue128Offset != 0 ? reinterpret_cast<u8*>(reinterpret_cast<uintptr>(mpHeader) + mpHeader->keyValue128Offset) : nullptr;
    mpHeader->pExtendData = mpHeader->extendDataOffset != 0 ? reinterpret_cast<u8*>(reinterpret_cast<uintptr>(mpHeader) + mpHeader->extendDataOffset) : nullptr;
    mpHeader->startFlowAdrs = &mpHeader->pFlow[mpHeader->startFlowIndex];
    mpHeader->pInstExeParam = &mpHeader->pParam[mpHeader->instExeParamOffset];
    mpHeader->pVertex = mpHeader->vertexOffset != 0 ? reinterpret_cast<nGUI::VERTEX*>(reinterpret_cast<uintptr>(mpHeader) + mpHeader->vertexOffset) : nullptr;
    mInstanceNullNeedNum = 0;
    mInstanceScissorMaskNeedNum = 0;
    mInstanceAnimationNeedNum = 0;
    mInstanceAnimVariableNeedNum = 0;
    mInstanceAnimControlNeedNum = 0;
    mGUIObjTextNeedNum = 0;
    mGUIObjMessageNeedNum = 0;
    mGUIObjChildAnimationRootNeedNum = 0;
    mGUIObjNullNeedNum = 0;
    mGUIObjTextureSetNeedNum = 0;
    mGUIObjTextureNeedNum = 0;
    mGUIObjPolygonNeedNum = 0;
    mGUIObjScissorMaskNeedNum = 0;
    mGUIObjColorAdjustNeedNum = 0;
    mGUIObjRootNeedNum = 0;
    mGUIVarIntNeedNum = 0;
    mGUIVarFloatNeedNum = 0;
    mCreateAnimationBufferSize = 0;
    mObjRootNeedSetObjectBufferSize = 0;
    
    nGUI::KEY* pKey = mpHeader->pKey;
    if (pKey != nullptr) {
        for (u32 i = 0; i < mpHeader->keyNum; ++i, ++pKey) {
            if (pKey->mode == nGUI::KEY::MODE_HERMITE2) {
                pKey->pCurve = reinterpret_cast<MtHermiteCurve*>(mpHeader->pExtendData + pKey->curveOffset);
            }
        }
    }
    
    nGUI::INIT_PARAM* pInitParam = mpHeader->pInitParam;
    if (pInitParam != nullptr) {
        for (u32 i = 0; i < mpHeader->initParamNum; ++i, ++pInitParam) {
            pInitParam->propName = mpHeader->pString + pInitParam->propNameOffset;
            switch (pInitParam->paramType) {
            case nGUI::PARAM_TYPE_INT:
            case nGUI::PARAM_TYPE_FLOAT:
            case nGUI::PARAM_TYPE_TEXTURE:
            case nGUI::PARAM_TYPE_FONT:
            case nGUI::PARAM_TYPE_MESSAGE:
            case nGUI::PARAM_TYPE_VARIABLE:
            case nGUI::PARAM_TYPE_ANIMATION:
            case nGUI::PARAM_TYPE_EVENT:
            case nGUI::PARAM_TYPE_GUIRESOURCE:
            case nGUI::PARAM_TYPE_FONT_FILTER:
            case nGUI::PARAM_TYPE_SEQUENCE:
            case nGUI::PARAM_TYPE_GENERALRESOURCE:
                pInitParam->pValue = mpHeader->pKeyValue32 + pInitParam->valueOffset;
                break;
            case nGUI::PARAM_TYPE_BOOL:
                pInitParam->pValue = mpHeader->pKeyValue8 + pInitParam->valueOffset;
                break;
            case nGUI::PARAM_TYPE_VECTOR:
                pInitParam->pValue = mpHeader->pKeyValue128 + pInitParam->valueOffset;
                break;
            case nGUI::PARAM_TYPE_STRING:
                pInitParam->pValue = reinterpret_cast<u8*>(mpHeader->pString + *reinterpret_cast<uintptr*>(mpHeader->pKeyValue32 + pInitParam->valueOffset));
                break;
            }
        }
    }
    
    nGUI::PARAM* pParam = mpHeader->pParam;
    if (pParam != nullptr) {
        for (u32 i = 0; i < mpHeader->paramNum; ++i, ++pParam) {
            pParam->propName = mpHeader->pString + pParam->propNameOffset;
            pParam->keyFrame = &mpHeader->pKey[pParam->frameOffset];
            switch (pParam->paramType) {
            case nGUI::PARAM_TYPE_INT:
            case nGUI::PARAM_TYPE_FLOAT:
            case nGUI::PARAM_TYPE_TEXTURE:
            case nGUI::PARAM_TYPE_FONT:
            case nGUI::PARAM_TYPE_MESSAGE:
            case nGUI::PARAM_TYPE_VARIABLE:
            case nGUI::PARAM_TYPE_ANIMATION:
            case nGUI::PARAM_TYPE_EVENT:
            case nGUI::PARAM_TYPE_GUIRESOURCE:
            case nGUI::PARAM_TYPE_FONT_FILTER:
            case nGUI::PARAM_TYPE_SEQUENCE:
            case nGUI::PARAM_TYPE_GENERALRESOURCE:
                pParam->keyValue = mpHeader->pKeyValue32 + pParam->valueOffset;
                break;
            case nGUI::PARAM_TYPE_BOOL:
                pParam->keyValue = mpHeader->pKeyValue8 + pParam->valueOffset;
                break;
            case nGUI::PARAM_TYPE_VECTOR:
                pParam->keyValue = mpHeader->pKeyValue128 + pParam->valueOffset;
                break;
            case nGUI::PARAM_TYPE_STRING:
                pParam->keyValue = mpHeader->pKeyValue32 + pParam->valueOffset;
                if (pParam->keyValue != nullptr) {
                    uintptr* pValue = reinterpret_cast<uintptr*>(pParam->keyValue);
                    for (u32 j = 0; j < pParam->keyNum; ++j) {
                        pValue[j] += reinterpret_cast<uintptr>(mpHeader->pString);
                    }
                }
                break;
            }
        }
    }
    
    nGUI::SEQUENCE* pSequence = mpHeader->pSequence;
    if (pSequence != nullptr) {
        for (u32 i = 0; i < mpHeader->sequenceNum; ++i, ++pSequence) {
            pSequence->pName = mpHeader->pString + pSequence->nameOffset;
        }
    }
    
    nGUI::OBJ_SEQUENCE* pObjSequence = mpHeader->pObjSequence;
    if (pObjSequence != nullptr) {
        for (u32 i = 0; i < mpHeader->objSequenceNum; ++i, ++pObjSequence) {
            pObjSequence->pInitParam = &mpHeader->pInitParam[pObjSequence->initParamIndex];
            pObjSequence->pParam = &mpHeader->pParam[pObjSequence->paramIndex];
        }
    }
    
    nGUI::OBJECT* pObject = mpHeader->pObject;
    if (pObject != nullptr) {
        for (u32 i = 0; i < mpHeader->objectNum; ++i, ++pObject) {
            pObject->pName = mpHeader->pString + pObject->nameOffset;
            const MtDTI* pDti = MtDTI::from(pObject->dtiId);
            pObject->pDti = pDti;
            pObject->pInitParam = &mpHeader->pInitParam[pObject->initParamIndex];
            pObject->pObjSequence = &mpHeader->pObjSequence[pObject->objSequenceIndex];
            pObject->pExtendData = pObject->extendDataOffset != 0xffffffff ? mpHeader->pExtendData + pObject->extendDataOffset : nullptr;
            const nGUI::CLASS_INFO* pClassInfo = sGUI::getInstance()->getObjectClassInfo((pDti != nullptr ? pDti : &cGUIObjNull::DTI)->getID());
            nGUI::INIT_PARAM* pInitParam = pObject->pInitParam;
            for (u32 j = 0; j < pObject->initParamNum; ++j, ++pInitParam) {
                pInitParam->pFunc = sGUI::getInstance()->getPropSetter(pClassInfo, pInitParam->propName);
            }
        }
    }
    
    nGUI::ANIMATION* pAnimation = mpHeader->pAnimation;
    if (pAnimation != nullptr) {
        for (u32 i = 0; i < mpHeader->animationNum; ++i, ++pAnimation) {
            pAnimation->pSequence = &mpHeader->pSequence[pAnimation->sequenceIndex];
            pAnimation->pName = mpHeader->pString + pAnimation->nameOffset;
            nGUI::OBJECT* pObject = &mpHeader->pObject[pAnimation->objectIndex];
            for (u32 j = 0; j < pAnimation->objectNum; ++j, ++pObject) {
                const nGUI::CLASS_INFO* pClassInfo = sGUI::getInstance()->getObjectClassInfo((pObject->pDti != nullptr ? pObject->pDti : &cGUIObjNull::DTI)->getID());
                nGUI::OBJ_SEQUENCE* pObjSequence = pObject->pObjSequence;
                for (u32 k = 0; k < pAnimation->sequenceNum; ++k, ++pObjSequence) {
                    nGUI::INIT_PARAM* pInitParam = pObjSequence->pInitParam;
                    for (u32 l = 0; l < pObjSequence->initParamNum; ++l, ++pInitParam) {
                        pInitParam->pFunc = sGUI::getInstance()->getPropSetter(pClassInfo, pInitParam->propName);
                    }
                    nGUI::PARAM* pParam = pObjSequence->pParam;
                    for (u32 l = 0; l < pObjSequence->paramNum; ++l, ++pParam) {
                        pParam->pFunc = sGUI::getInstance()->getPropSetter(pClassInfo, pParam->propName);
                    }
                }
            }
        }
    }
    
    MtStlVector<rGUI::AnimationSearch, MtStlAllocator<rGUI::AnimationSearch> > FoundAnimationIdArray;
    FoundAnimationIdArray.reserve(mpHeader->objectNum);
    
    nGUI::INSTANCE* pInstance = mpHeader->pInstance;
    if (pInstance != nullptr) {
        for (u32 i = 0; i < mpHeader->instanceNum; ++i, ++pInstance) {
            const u32 NowDtiID = pInstance->dtiId;
            if (NowDtiID == cGUIInstNull::DTI.getID()) {
                ++mInstanceNullNeedNum;
            } else if (NowDtiID == cGUIInstScissorMask::DTI.getID()) {
                ++mInstanceScissorMaskNeedNum;
            } else if (NowDtiID == cGUIInstAnimation::DTI.getID()) {
                ++mInstanceAnimationNeedNum;
            } else if (NowDtiID == cGUIInstAnimVariable::DTI.getID()) {
                ++mInstanceAnimVariableNeedNum;
            } else if (NowDtiID == cGUIInstAnimControl::DTI.getID()) {
                ++mInstanceAnimControlNeedNum;
            }
            pInstance->pName = mpHeader->pString + pInstance->nameOffset;
            pInstance->pDti = MtDTI::from(pInstance->dtiId);
            pInstance->pInitParam = &mpHeader->pInitParam[pInstance->initParamIndex];
            pInstance->pExtendData = pInstance->extendDataOffset != 0xffffffff ? mpHeader->pExtendData + pInstance->extendDataOffset : nullptr;
            const nGUI::CLASS_INFO* pClassInfo = sGUI::getInstance()->getInstanceClassInfo(pInstance->pDti->getID());
            nGUI::INIT_PARAM* pInitParam = pInstance->pInitParam;
            for (u32 j = 0; j < pInstance->initParamNum; ++j, ++pInitParam) {
                pInitParam->pFunc = sGUI::getInstance()->getPropSetter(pClassInfo, pInitParam->propName);
            }
        }
    }
    
    nGUI::FLOW* pFlow = mpHeader->pFlow;
    if (pFlow != nullptr) {
        for (u32 i = 0; i < mpHeader->flowNum; ++i, ++pFlow) {
            pFlow->pName = mpHeader->pString + pFlow->nameOffset;
            switch (pFlow->type) {
            case nGUI::FLOW_TYPE_START:
                pFlow->nextAdrs = pFlow->nextIndex != 0xffffffff ? &mpHeader->pFlow[pFlow->nextIndex] : nullptr;
                break;
            case nGUI::FLOW_TYPE_INPUT:
                pFlow->inputAdrs = pFlow->inputIndex != 0xffffffff ? &mpHeader->pFlowInput[pFlow->inputIndex] : nullptr;
                break;
            case nGUI::FLOW_TYPE_SWITCH:
                pFlow->switchAdrs = pFlow->switchIndex != 0xffffffff ? &mpHeader->pFlowSwitch[pFlow->switchIndex] : nullptr;
                break;
            case nGUI::FLOW_TYPE_FUNCTION:
                pFlow->functionAdrs = pFlow->functionIndex != 0xffffffff ? &mpHeader->pFlowFunction[pFlow->functionIndex] : nullptr;
                break;
            }
        }
    }
    
    nGUI::FLOW_PROCESS* pFlowProcess = mpHeader->pFlowProcess;
    if (pFlowProcess != nullptr) {
        for (u32 i = 0; i < mpHeader->flowProcessNum; ++i, ++pFlowProcess) {
            pFlowProcess->nextAdrs = pFlowProcess->nextIndex != 0xffffffff ? &mpHeader->pFlow[pFlowProcess->nextIndex] : nullptr;
            pFlowProcess->actionAdrs = &mpHeader->pAction[pFlowProcess->actionIndex];
        }
    }
    
    nGUI::FLOW_INPUT* pFlowInput = mpHeader->pFlowInput;
    if (pFlowInput != nullptr) {
        for (u32 i = 0; i < mpHeader->flowInputNum; ++i, ++pFlowInput) {
            pFlowInput->conditionAdrs = &mpHeader->pInputCondition[pFlowInput->conditionIndex];
        }
    }
    
    nGUI::FLOW_SWITCH* pFlowSwitch = mpHeader->pFlowSwitch;
    if (pFlowSwitch != nullptr) {
        for (u32 i = 0; i < mpHeader->flowSwitchNum; ++i, ++pFlowSwitch) {
            pFlowSwitch->conditionAdrs = &mpHeader->pSwitchCondition[pFlowSwitch->conditionIndex];
        }
    }
    
    nGUI::FLOW_FUNCTION* pFlowFunction = mpHeader->pFlowFunction;
    if (pFlowFunction != nullptr) {
        for (u32 i = 0; i < mpHeader->flowFunctionNum; ++i, ++pFlowFunction) {
            if (pFlowFunction->startIndex != 0xffffffff) {
                pFlowFunction->startAdrs = &mpHeader->pFlow[pFlowFunction->startIndex];
            } else {
                pFlowFunction->nextAdrs = nullptr;
            }
            pFlowFunction->nextAdrs = pFlowFunction->nextIndex != 0xffffffff ? &mpHeader->pFlow[pFlowFunction->nextIndex] : nullptr;
        }
    }
    
    nGUI::ACTION* pAction = mpHeader->pAction;
    if (pAction != nullptr) {
        for (u32 i = 0; i < mpHeader->actionNum; ++i, ++pAction) {
            pAction->propName = mpHeader->pString + pAction->propNameOffset;
        }
    }
    
    nGUI::INPUT_CONDITION* pInputCondition = mpHeader->pInputCondition;
    if (pInputCondition != nullptr) {
        for (u32 i = 0; i < mpHeader->inputConditionNum; ++i, ++pInputCondition) {
            pInputCondition->nextAdrs = &mpHeader->pFlow[pInputCondition->nextIndex];
        }
    }
    
    nGUI::SWITCH_CONDITION* pSwitchCondition = mpHeader->pSwitchCondition;
    if (pSwitchCondition != nullptr) {
        for (u32 i = 0; i < mpHeader->switchConditionNum; ++i, ++pSwitchCondition) {
            pSwitchCondition->nextAdrs = pSwitchCondition->nextIndex != 0xffffffff ? &mpHeader->pFlow[pSwitchCondition->nextIndex] : nullptr;
            pSwitchCondition->operatorAdrs = pSwitchCondition->operatorIndex != 0xffffffff ? &mpHeader->pSwitchOperator[pSwitchCondition->operatorIndex] : nullptr;
        }
    }
    
    nGUI::VARIABLE* pVariable = mpHeader->pVariable;
    if (pVariable != nullptr) {
        for (u32 i = 0; i < mpHeader->variableNum; ++i, ++pVariable) {
            if (pVariable->dtiId == cGUIVarInt::DTI.getID()) {
                ++mGUIVarIntNeedNum;
            } else if (pVariable->dtiId == cGUIVarFloat::DTI.getID()) {
                ++mGUIVarFloatNeedNum;
            }
            pVariable->pName = mpHeader->pString + pVariable->nameOffset;
            pVariable->pDti = MtDTI::from(pVariable->dtiId);
        }
    }
    
    MT_CHAR path[1024];
    nGUI::TEXTURE* pTexture = mpHeader->pTexture;
    if (pTexture != nullptr) {
        for (u32 i = 0; i < mpHeader->textureNum; ++i, ++pTexture) {
            if (pTexture->pathOffset != 0xffffffff) {
                pTexture->path = mpHeader->pString + pTexture->pathOffset;
                sGUI::getInstance()->getLanguageFilePath(path, pTexture->path, nGUI::LANGUAGE_SETTING0);
                sGUI::getInstance()->getPlatformFilePath(path, path);
                if (pTexture->rtype == nGUI::TEXTURE::RTYPE_RENDERTARGET) {
                    pTexture->pTexture = static_cast<rTexture*>(sResource::getInstance()->create(rRenderTargetTexture::DTI, path, sResource::MODE_NOLOAD));
                    if (pTexture->pTexture == nullptr) {
                        pTexture->pTexture = static_cast<rTexture*>(sResource::getInstance()->create(rRenderTargetTexture::DTI, pTexture->path, sResource::MODE_BLOCKING));
                    }
                } else {
                    pTexture->pTexture = static_cast<rTexture*>(sResource::getInstance()->create(rTexture::DTI, path, sResource::MODE_NOLOAD));
                    if (pTexture->pTexture == nullptr) {
                        pTexture->pTexture = static_cast<rTexture*>(sResource::getInstance()->create(rTexture::DTI, pTexture->path, sResource::MODE_BLOCKING));
                    }
                }
            } else {
                pTexture->path = nullptr;
                pTexture->pTexture = nullptr;
            }
            pTexture->pName = mpHeader->pString + pTexture->nameOffset;
        }
    }
    
    nGUI::FONT* pFont = mpHeader->pFont;
    if (pFont != nullptr) {
        for (u32 i = 0; i < mpHeader->fontNum; ++i, ++pFont) {
            if (pFont->pathOffset != 0xffffffff) {
                pFont->path = mpHeader->pString + pFont->pathOffset;
                sGUI::getInstance()->getLanguageFilePath(path, pFont->path, nGUI::LANGUAGE_SETTING0);
                sGUI::getInstance()->getPlatformFilePath(path, path);
                pFont->pFont = static_cast<rGUIFont*>(sResource::getInstance()->create(rGUIFont::DTI, path, sResource::MODE_NOLOAD));
                if (pFont->pFont == nullptr) {
                    pFont->pFont = static_cast<rGUIFont*>(sResource::getInstance()->create(rGUIFont::DTI, pFont->path, sResource::MODE_BLOCKING));
                }
            } else {
                pFont->path = nullptr;
                pFont->pFont = nullptr;
            }
        }
    }
    
    createFontFilter();
    
    nGUI::MESSAGE* pMessage = mpHeader->pMessage;
    if (pMessage != nullptr) {
        for (u32 i = 0; i < mpHeader->messageNum; ++i, ++pMessage) {
            if (pMessage->pathOffset != 0xffffffff) {
                pMessage->path = mpHeader->pString + pMessage->pathOffset;
                sGUI::getInstance()->getLanguageFilePath(path, pMessage->path, nGUI::LANGUAGE_SETTING0);
                pMessage->pMessage = static_cast<rGUIMessage*>(sResource::getInstance()->create(rGUIMessage::DTI, path, sResource::MODE_NOLOAD));
                if (pMessage->pMessage == nullptr) {
                    pMessage->pMessage = static_cast<rGUIMessage*>(sResource::getInstance()->create(rGUIMessage::DTI, pMessage->path, sResource::MODE_BLOCKING));
                }
            } else {
                pMessage->path = nullptr;
                pMessage->pMessage = nullptr;
            }
        }
    }
    
    nGUI::GUIRESOURCE* pGUIResource = mpHeader->pGUIResource;
    if (pGUIResource != nullptr) {
        for (u32 i = 0; i < mpHeader->guiResourceNum; ++i, ++pGUIResource) {
            if (pGUIResource->pathOffset != 0xffffffff) {
                pGUIResource->path = mpHeader->pString + pGUIResource->pathOffset;
                pGUIResource->pResource = sResource::getInstance()->create(rGUI::DTI, pGUIResource->path, sResource::MODE_BLOCKING);
            } else {
                pGUIResource->path = nullptr;
                pGUIResource->pResource = nullptr;
            }
        }
    }
    
    nGUI::GENERALRESOURCE* pGeneralResource = mpHeader->pGeneralResource;
    if (pGeneralResource != nullptr) {
        for (u32 i = 0; i < mpHeader->generalResourceNum; ++i, ++pGeneralResource) {
            const MtDTI* pDti = MtDTI::from(pGeneralResource->dtiId);
            if (pGeneralResource->pathOffset != 0xffffffff && pDti != nullptr) {
                pGeneralResource->path = mpHeader->pString + pGeneralResource->pathOffset;
                pGeneralResource->pResource = sResource::getInstance()->create(*pDti, pGeneralResource->path, sResource::MODE_BLOCKING);
            } else {
                pGeneralResource->path = nullptr;
                pGeneralResource->pResource = nullptr;
            }
        }
    }
    
    nGUI::CAMERA_SETTING* pCameraSetting = mpHeader->pCameraSetting;
    if (pCameraSetting != nullptr) {
        for (u32 i = 0; i < mpHeader->cameraSettingNum; ++i, ++pCameraSetting) {
            pCameraSetting->pName = pCameraSetting->nameOffset != 0xffffffff ? mpHeader->pString + pCameraSetting->nameOffset : nullptr;
        }
    }
    
    if (mpHeader->vertexBufferSize != 0) {
        mpVertexBuffer = new (16u) nDraw::VertexBuffer(mpHeader->vertexBufferSize, nDraw::USAGE_DEFAULT, nullptr);
        void* pVertex = mpVertexBuffer->map(nDraw::MAP_WRITE_DISCARD);
        if (pVertex != nullptr) {
            memcpy(pVertex, mpHeader->pVertex, mpHeader->vertexBufferSize);
        }
        mpVertexBuffer->unmap();
    }
    mIsSetData = 1;
    return true;
}

static auto ddon_emit_0x01b9dd40 __attribute__((used)) = &rGUI::getBaseZ;

static auto ddon_emit_0x01b9dda0 __attribute__((used)) = &rGUI::getLanguageSettingNo;

t64 rGUI::getUpdateTime2() const {
    return mpHeader->updateTime;
}

nGUI::ANIMATION* rGUI::getAnimation(u32 id) const {
    u32 v0_0 = mpHeader->animationNum;
    if (v0_0 != 0) {
        unsigned int i0_1 = 0;
        for (nGUI::ANIMATION* p0_2 = mpHeader->pAnimation;;) {
            if (p0_2->id == id) {
                return p0_2;
            } else {
                if ((i0_1 + 1u) < v0_0) {
                    i0_1 += 1u;
                    p0_2 += 1;
                } else {
                    break;
                }
            }
        }
    }
    return nullptr;
}

nGUI::TEXTURE* rGUI::getTextureFromId(u32 id) const {
    if (mpHeader->pTexture != nullptr) {
        u32 v0_2 = mpHeader->textureNum;
        if (v0_2 != 0) {
            nGUI::TEXTURE* pTexture = mpHeader->pTexture;
            for (unsigned int i0_1 = 0;;) {
                if (pTexture->id == id) {
                    return pTexture;
                } else {
                    if ((i0_1 + 1u) < v0_2) {
                        pTexture += 1;
                        i0_1 += 1u;
                    } else {
                        break;
                    }
                }
            }
        }
    }
    return nullptr;
}

__attribute__((weak)) rTexture* rGUI::replaceTexture(u32 id, rTexture* pTexture) {
    DDON_STUB("rGUI::replaceTexture")
    return nullptr;
}

nGUI::FONT* rGUI::getFontFromId(u32 id) const {
    if (mpHeader->pFont != nullptr) {
        u32 v0_2 = mpHeader->fontNum;
        if (v0_2 != 0) {
            nGUI::FONT* pFont = mpHeader->pFont;
            for (unsigned int i0_1 = 0;;) {
                if (pFont->id == id) {
                    return pFont;
                } else {
                    if ((i0_1 + 1u) < v0_2) {
                        pFont += 1;
                        i0_1 += 1u;
                    } else {
                        break;
                    }
                }
            }
        }
    }
    return nullptr;
}

u32 rGUI::getFontFilterNum() const {
    return mpHeader->fontFilterNum;
}

cGUIFontFilter* rGUI::getFontFilterFromId(u32 id) const {
    cGUIFontFilter* v2_0;
    if (mpFontFilter == nullptr) {
        v2_0 = nullptr;
    } else {
        if (getFontFilterNum() == 0) {
            v2_0 = nullptr;
        } else {
            for (unsigned int i0_2 = 0;;) {
                if (mpFontFilter[i0_2] != nullptr) {
                    if (mpFontFilter[i0_2]->mId == id) {
                        v2_0 = mpFontFilter[i0_2];
                        break;
                    }
                }
                if ((i0_2 + 1u) < getFontFilterNum()) {
                    i0_2 += 1u;
                } else {
                    v2_0 = nullptr;
                    break;
                }
            }
        }
    }
    return v2_0;
}

nGUI::MESSAGE* rGUI::getMessageFromId(u32 id) const {
    if (mpHeader->pMessage != nullptr) {
        u32 v0_2 = mpHeader->messageNum;
        if (v0_2 != 0) {
            nGUI::MESSAGE* pMessage = mpHeader->pMessage;
            for (unsigned int i0_1 = 0;;) {
                if (pMessage->id == id) {
                    return pMessage;
                } else {
                    if ((i0_1 + 1u) < v0_2) {
                        pMessage += 1;
                        i0_1 += 1u;
                    } else {
                        break;
                    }
                }
            }
        }
    }
    return nullptr;
}

nGUI::GUIRESOURCE* rGUI::getGUIResourceFromId(u32 id) const {
    if (mpHeader->pGUIResource != nullptr) {
        u32 v0_2 = mpHeader->guiResourceNum;
        if (v0_2 != 0) {
            nGUI::GUIRESOURCE* pGUIResource = mpHeader->pGUIResource;
            for (unsigned int i0_1 = 0;;) {
                if (pGUIResource->id == id) {
                    return pGUIResource;
                } else {
                    if ((i0_1 + 1u) < v0_2) {
                        pGUIResource += 1;
                        i0_1 += 1u;
                    } else {
                        break;
                    }
                }
            }
        }
    }
    return nullptr;
}

nGUI::GENERALRESOURCE* rGUI::getGeneralResourceFromId(u32 id) const {
    if (mpHeader->pGeneralResource != nullptr) {
        u32 v0_2 = mpHeader->generalResourceNum;
        if (v0_2 != 0) {
            nGUI::GENERALRESOURCE* pGeneralResource = mpHeader->pGeneralResource;
            for (unsigned int i0_1 = 0;;) {
                if (pGeneralResource->id == id) {
                    return pGeneralResource;
                } else {
                    if ((i0_1 + 1u) < v0_2) {
                        pGeneralResource += 1;
                        i0_1 += 1u;
                    } else {
                        break;
                    }
                }
            }
        }
    }
    return nullptr;
}

bool rGUI::isUseAlphaMask() const {
    return static_cast<bool>(mAttr & 1u);
}

bool rGUI::is3D() const {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 120)) & 2) >> 1);
}

static auto ddon_emit_0x01b9dd70 __attribute__((used)) = &rGUI::getFramerateMode;

static auto ddon_emit_0x01b9dd80 __attribute__((used)) = &rGUI::setFramerateMode;

const rGUI::InstanceNeedObjectInfo* rGUI::getInstanceNeedObjectInfoPtr(u32 InstanceID) const {
    u32 v0_2 = mpHeader->instanceNum;
    InstanceNeedObjectInfo* v2_0;
    if (v0_2 == 0) {
        v2_0 = nullptr;
    } else {
        u32 i = 0;
        for (nGUI::INSTANCE* p0_1 = mpHeader->pInstance;;) {
            if (p0_1->id != InstanceID) {
                if ((i + 1u) < v0_2) {
                    i = i + 1u;
                    p0_1 += 1;
                } else {
                    break;
                }
            } else {
                v2_0 = &mpInstanceNeedObjectInfo[i];
                return v2_0;
            }
        }
        v2_0 = nullptr;
    }
    return v2_0;
}

void rGUI::setBaseZ(u32 type) {
    mBaseZ = type;
}

void rGUI::setLanguageSettingNo(u32 v) {
    mLanguageSettingNo = v;
}

void rGUI::setUseAlphaMask(bool e) {
    mAttr = !e ? (mAttr & 0xFFFFFFFEu) : (mAttr | 1u);
}

void rGUI::set3D(bool e) {
    mAttr = !e ? (mAttr & 0xFFFFFFFDu) : (mAttr | 2u);
}

void* rGUI::memAlloc(u32 size) {
    return MtMemoryAllocator::getAllocator(rGUI::DTI)->memAlloc(size, 16u);
}

void rGUI::memFree(void* p_addr) {
    MtMemoryAllocator::getAllocator(rGUI::DTI)->memFree(p_addr);
}

__attribute__((weak)) void rGUI::createFontFilter() {
    if (mpHeader != nullptr && mpHeader->fontFilterNum != 0) {
        mpFontFilter = static_cast<cGUIFontFilter**>(memAlloc(sizeof(cGUIFontFilter*) * mpHeader->fontFilterNum));
        memset(mpFontFilter, 0, sizeof(cGUIFontFilter*) * mpHeader->fontFilterNum);
        u32* pt = static_cast<u32*>(mpHeader->pFontFilter);
        for (u32 i = 0; i < mpHeader->fontFilterNum; ++i) {
            u32 dtiId = *pt;
            if (dtiId == 0) {
                pt += 2;
                continue;
            }
            const MtDTI* pDti = MtDTI::from(dtiId);
            ++pt;
            if (pDti == nullptr) {
                continue;
            }
            mpFontFilter[i] = static_cast<cGUIFontFilter*>(pDti->newInstance());
            if (mpFontFilter[i] == nullptr) {
                return;
            }
            mpFontFilter[i]->mId = *pt++;
            MtPropertyList s;
            mpFontFilter[i]->createParamProperty(s);
            for (u32 j = 0; j < s.length(); ++j) {
                MtProperty* pProperty = s[j];
                if (pProperty == nullptr) {
                    continue;
                }
                switch (static_cast<u32>(pProperty->getType())) {
                case MtProperty::TYPE_U32:
                    pProperty->setU32(*pt++);
                    break;
                case MtProperty::TYPE_S32:
                    pProperty->setS32(*pt++);
                    break;
                case MtProperty::TYPE_F32:
                    pProperty->setF32(static_cast<f32>(*pt++));
                    break;
                case MtProperty::TYPE_COLOR: {
                    MtColor color(*pt++);
                    pProperty->setColor(color);
                    break;
                }
                case 128:
                    if (pt[0] != 0xffffffff) {
                        const MtDTI* pDti = MtDTI::from(pt[0]);
                        if (pDti != nullptr && pt[1] != 0xffffffff) {
                            cResource* pResource = sResource::getInstance()->create(*pDti, mpHeader->pString + pt[1], sResource::MODE_BLOCKING);
                            pProperty->setClass(pResource);
                            if (pResource != nullptr) {
                                pResource->release();
                            }
                        }
                    }
                    pt += 2;
                    break;
                }
            }
        }
    } else {
        mpFontFilter = nullptr;
    }
}

inline rGUI::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rGUI::MyDTI rGUI::DTI("rGUI", &::cResource::DTI, 248ul, 0u, 0u);

MtObject* rGUI::MyDTI::newInstance() const {
    return new (16u) rGUI;
}

