// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cWeatherScript.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "nDDOUtility.h"
#include "nWeather.h"
#include "rWeatherScript.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "../../XFramework/sMain.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cWeatherScript::getDTI() const {
    return cWeatherScript::DTI;
}

cWeatherScript::cWeatherScript() {
    DDON_STUB("cWeatherScript::cWeatherScript")
    /* stub */
}

cWeatherScript::~cWeatherScript() {
}

void cWeatherScript::initScript() {
    mScriptStepCur = 0;
    mScriptStepReq = 0;
    mScriptStepReqOn = false;
    mEffectAlphaRate = 1.0f;
}

__attribute__((weak)) void cWeatherScript::setupScript(cWeatherScriptCmdArray& resArray, u32 step) {
    DDON_STUB("cWeatherScript::setupScript")
    /* stub */
}

__attribute__((weak)) void cWeatherScript::updateScript() {
    DDON_STUB("cWeatherScript::updateScript")
    /* stub */
}

void cWeatherScript::updatePtr() {
    mScriptIO.updatePtr();
}

void cWeatherScript::reqStepScript(u32 step) {
    mScriptStepReq = step;
    mScriptStepReqOn = true;
}

void cWeatherScript::endScript() {
    mScriptStepReq = 0;
    mScriptStepReqOn = true;
}

void cWeatherScript::releaseScript() {
    if (mScripts.elems[0].mAutoDelete) {
        u32 v3_0;
        if (mScripts.elems[0].mLength != 0) {
            u32 v0_0 = mScripts.elems[0].mLength;
            unsigned int i0_3 = 0;
            u32 v1_0;
            for (;;) {
                if (mScripts.elems[0].mpArray[i0_3] == nullptr) {
                    v1_0 = v0_0;
                } else {
                    delete mScripts.elems[0].mpArray[i0_3];
                    v1_0 = mScripts.elems[0].mLength;
                }
                if ((i0_3 + 1u) < v1_0) {
                    v0_0 = v1_0;
                    i0_3 += 1u;
                } else {
                    break;
                }
            }
            v3_0 = v1_0;
        } else {
            v3_0 = 0;
        }
        memset(static_cast<void*>(mScripts.elems[0].mpArray), 0, static_cast<size_t>(v3_0) * 8);
    }
    mScripts.elems[0].mLength = 0;
    if (mScripts.elems[1].mAutoDelete) {
        u32 v8_0;
        if (mScripts.elems[1].mLength != 0) {
            u32 v5_0 = mScripts.elems[1].mLength;
            unsigned int i5_3 = 0;
            u32 v6_0;
            for (;;) {
                if (mScripts.elems[1].mpArray[i5_3] == nullptr) {
                    v6_0 = v5_0;
                } else {
                    delete mScripts.elems[1].mpArray[i5_3];
                    v6_0 = mScripts.elems[1].mLength;
                }
                if ((i5_3 + 1u) < v6_0) {
                    v5_0 = v6_0;
                    i5_3 += 1u;
                } else {
                    break;
                }
            }
            v8_0 = v6_0;
        } else {
            v8_0 = 0;
        }
        memset(static_cast<void*>(mScripts.elems[1].mpArray), 0, static_cast<size_t>(v8_0) * 8);
    }
    mScripts.elems[1].mLength = 0;
    if (mScripts.elems[2].mAutoDelete) {
        u32 v13_0;
        if (mScripts.elems[2].mLength != 0) {
            u32 v10_0 = mScripts.elems[2].mLength;
            unsigned int i10_3 = 0;
            u32 v11_0;
            for (;;) {
                if (mScripts.elems[2].mpArray[i10_3] == nullptr) {
                    v11_0 = v10_0;
                } else {
                    delete mScripts.elems[2].mpArray[i10_3];
                    v11_0 = mScripts.elems[2].mLength;
                }
                if ((i10_3 + 1u) < v11_0) {
                    v10_0 = v11_0;
                    i10_3 += 1u;
                } else {
                    break;
                }
            }
            v13_0 = v11_0;
        } else {
            v13_0 = 0;
        }
        memset(static_cast<void*>(mScripts.elems[2].mpArray), 0, static_cast<size_t>(v13_0) * 8);
    }
    mScripts.elems[2].mLength = 0;
    if (mScripts.elems[3].mAutoDelete) {
        u32 v18_0;
        if (mScripts.elems[3].mLength != 0) {
            u32 v15_0 = mScripts.elems[3].mLength;
            unsigned int i15_3 = 0;
            u32 v16_0;
            for (;;) {
                if (mScripts.elems[3].mpArray[i15_3] == nullptr) {
                    v16_0 = v15_0;
                } else {
                    delete mScripts.elems[3].mpArray[i15_3];
                    v16_0 = mScripts.elems[3].mLength;
                }
                if ((i15_3 + 1u) < v16_0) {
                    v15_0 = v16_0;
                    i15_3 += 1u;
                } else {
                    break;
                }
            }
            v18_0 = v16_0;
        } else {
            v18_0 = 0;
        }
        memset(static_cast<void*>(mScripts.elems[3].mpArray), 0, static_cast<size_t>(v18_0) * 8);
    }
    mScripts.elems[3].mLength = 0;
    mScriptIO.releaseWSCParamAll();
    mEffectAlphaRate = 1.0f;
    mScriptStepCur = 0;
    mScriptStepReq = 0;
}

void cWeatherScript::setScriptEffectRate(f32 rate) {
    mEffectAlphaRate = rate;
}

void cWeatherScript::setScriptSoundAddVolume(f32 add) {
    mScriptIO.mReqSoundVolumeAdd = add;
}

__attribute__((weak)) bool cWeatherScript::updateScriptCore(cWeatherScriptCmdCtrlArray& script) {
    DDON_STUB("cWeatherScript::updateScriptCore")
    return {};
}

inline cWeatherScript::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cWeatherScript::MyDTI cWeatherScript::DTI("cWeatherScript", &::cWeatherObjectSys::DTI, 216ul, 0u, 0u);

__attribute__((weak)) MtObject* cWeatherScript::MyDTI::newInstance() const {
    DDON_STUB("cWeatherScript::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cWeatherScriptCmdCtrl::getDTI() const {
    return cWeatherScriptCmdCtrl::DTI;
}

inline cWeatherScriptCmdCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cWeatherScriptCmdCtrl::MyDTI cWeatherScriptCmdCtrl::DTI("cWeatherScriptCmdCtrl", &::cWeatherObjectSys::DTI, 24ul, 0u, 0u);

MtObject* cWeatherScriptCmdCtrl::MyDTI::newInstance() const {
    return new (16u) cWeatherScriptCmdCtrl;
}

template MtTypedArray<cWSCParam>::~MtTypedArray();

template MtTypedArray<cWeatherScriptCmdCtrl>::~MtTypedArray();

