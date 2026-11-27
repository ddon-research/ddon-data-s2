// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cBrowserPS4_h.h"
#include "../../../MT/MtAllocator.h"
#include "../../../MT/MtDTI.h"
#include "../../../MT/MtMemoryAllocator.h"
#include "../../../MT/MtObject.h"
#include "../../../MT/MtPrimitive2D.h"
#include "../../../MT/MtSynchronize.h"
#include "cBrowserApplicationTask.h"
#include "../cGUIUtility.h"
#include "../../../generated/shared/lwgfxcontext.h"
#include "../../../XFramework/nDrawTexture.h"
#include "../sBrowser.h"
#include "../../../XFramework/sMain.h"
#include "../../../XFramework/sMouse.h"
#include "../sMouseExt.h"
#include "../../../XFramework/sPad.h"
#include "../../../XFramework/sRender.h"
#include "../../middleware/snj_browser_ps3/sdk/wave/target/win32/snj_browser.h"
#include "../../middleware/snj_browser_ps3/sdk/wave/target/win32/snj_browser_common.h"
#include "../../../generated/shared/texture.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

static int s_sclsiz[5] = {
    50,
    80,
    100,
    120,
    150,
};

const MtDTI& cBrowserKeepString::getDTI() const {
    return cBrowserKeepString::DTI;
}

cBrowserKeepString::~cBrowserKeepString() {
    DDON_STUB("cBrowserKeepString::~cBrowserKeepString")
    /* stub */
}

inline cBrowserKeepString::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cBrowserKeepString::MyDTI cBrowserKeepString::DTI("cBrowserKeepString", &::MtObject::DTI, 32ul, 0u, 0u);

__attribute__((weak)) MtObject* cBrowserKeepString::MyDTI::newInstance() const {
    DDON_STUB("cBrowserKeepString::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cBrowserPS4::getDTI() const {
    return cBrowserPS4::DTI;
}

void* cBrowserPS4::operator new(size_t sz, u32 align) {
    return cBrowserPS4::getAllocator()->memAlloc(sz, align, cBrowserPS4::DTI.getID());
}

cBrowserPS4::cBrowserPS4() {
    DDON_STUB("cBrowserPS4::cBrowserPS4")
    /* stub */
}

__attribute__((noinline)) cBrowserPS4::~cBrowserPS4() {
    DDON_STUB("cBrowserPS4::~cBrowserPS4")
    /* stub */
}

__attribute__((weak)) int cBrowserPS4::initialize(void* memptr, size_t memsiz, int x, int y, int vw, int vh, int tw, int th, unsigned int flg, int(*imeprcini)(const void*), void(*imeprcmov)(), void(*imeprcdrw)(), int(*errprcini)(int, int), void(*errprcmov)(), void(*errprcdrw)(), int(*jsdprcini)(const void*), void(*jsdprcmov)(), void(*jsdprcdrw)()) {
    DDON_STUB("cBrowserPS4::initialize")
    return {};
}

__attribute__((weak)) void cBrowserPS4::ime_exit(const char* str) {
    DDON_STUB("cBrowserPS4::ime_exit")
    /* stub */
}

__attribute__((weak)) void cBrowserPS4::err_exit() {
    DDON_STUB("cBrowserPS4::err_exit")
    /* stub */
}

__attribute__((weak)) void cBrowserPS4::jsd_exit(int ret, char* iptres) {
    DDON_STUB("cBrowserPS4::jsd_exit")
    /* stub */
}

__attribute__((weak)) void cBrowserPS4::set_url(const char* url) {
    DDON_STUB("cBrowserPS4::set_url")
    /* stub */
}

__attribute__((weak)) void cBrowserPS4::set_error_url(int knd, const char* url) {
    DDON_STUB("cBrowserPS4::set_error_url")
    /* stub */
}

__attribute__((weak)) void cBrowserPS4::goto_error_page(int knd) {
    DDON_STUB("cBrowserPS4::goto_error_page")
    /* stub */
}

__attribute__((weak)) void cBrowserPS4::pause_end() {
    DDON_STUB("cBrowserPS4::pause_end")
    /* stub */
}

__attribute__((weak)) void cBrowserPS4::add_js_function(const char* fncnam, SNJ_BROWSER_JSFUNC fnc) {
    DDON_STUB("cBrowserPS4::add_js_function")
    /* stub */
}

__attribute__((weak)) int cBrowserPS4::get_error_category(int typ, int knd) {
    DDON_STUB("cBrowserPS4::get_error_category")
    return {};
}

__attribute__((weak)) int cBrowserPS4::get_error_flowtype(int typ, int knd) {
    DDON_STUB("cBrowserPS4::get_error_flowtype")
    return {};
}

__attribute__((weak)) void cBrowserPS4::move(const bool isControl, const bool isDispCursor) {
    DDON_STUB("cBrowserPS4::move")
    /* stub */
}

__attribute__((weak)) void cBrowserPS4::draw() {
    DDON_STUB("cBrowserPS4::draw")
    /* stub */
}

__attribute__((weak)) void cBrowserPS4::finalize() {
    DDON_STUB("cBrowserPS4::finalize")
    /* stub */
}

__attribute__((weak)) void cBrowserPS4::call_js_function(const char* pFunctionStr) {
    DDON_STUB("cBrowserPS4::call_js_function")
    /* stub */
}

u32 cBrowserPS4::checkValidDevice() {
    if (mValidDevice == 1) {
        if (checkInputMouse()) {
            mValidDevice = 0;
            return 0;
        }
    } else {
        if (mValidDevice == 0) {
            if ((sPad::mpInstance)->sPad::isActive()) {
                if ((sPad::mpInstance)->mPad[0].Data.On != 0) {
                    mValidDevice = 1;
                    return 1;
                }
            }
            return 0;
        }
    }
    return mValidDevice;
}

__attribute__((weak)) bool cBrowserPS4::checkInputMouse() {
    sMouse::TYPE mouse_type = static_cast<sMouseExt*>(sMouse::getInstance())->getCurrentType();
    if (sMouse::getInstance()->isActive()) {
        u64 t0 = sMouse::getInstance()->mState[mouse_type].pos.xy;
        u64 t1 = (sBrowser::mpInstance)->mPos.xy;
        s32 t2 = (sBrowser::mpInstance)->mSize.w;
        f32 t3 = cGUIUtility::getScaleForDefaultResolution(1.0f);
        if (static_cast<int>(t0) >= static_cast<int>(t1)) {
            if (static_cast<int>(static_cast<unsigned long>(t1) + static_cast<unsigned long>(static_cast<int>(t3 * static_cast<float>(t2)))) >= static_cast<int>(t0)) {
                if (static_cast<int>(static_cast<unsigned long>(t1 >> 32) + static_cast<unsigned long>(static_cast<int>(t3 * static_cast<float>(t2)))) >= static_cast<int>(t0 >> 32)) {
                    if (static_cast<int>(t0 >> 32) >= static_cast<int>(t1 >> 32)) {
                        if (sMouse::getInstance()->mState[mouse_type].ax == 0) {
                            if (sMouse::getInstance()->mState[mouse_type].ay == 0) {
                                if (sMouse::getInstance()->mState[mouse_type].az == 0) {
                                    return (static_cast<sMouseExt*>(sMouse::getInstance())->mStateExt.on | sMouse::getInstance()->mState[mouse_type].on) != 0;
                                }
                            }
                        }
                        return true;
                    }
                }
            }
        }
        return false;
    } else {
        return false;
    }
}

__attribute__((weak)) bool cBrowserPS4::setDrawBuffer(void* pDst, u32 pitch, u32 width, u32 height, u32 bpp) {
    DDON_STUB("cBrowserPS4::setDrawBuffer")
    return {};
}

inline cBrowserPS4::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cBrowserPS4::MyDTI cBrowserPS4::DTI("cBrowserPS4", &::MtObject::DTI, 576ul, 0u, 0u);

const char* cBrowserPS4::mUserAgentTable[2][2] = {
    {"DDON-Viewer-GAME-PS4-HD/1.2", "DDON-Viewer-LAUNCHER-PS4-HD/1.2"},
    {"DDON-Viewer-GAME-PS4-SD/1.2", "DDON-Viewer-LAUNCHER-PS4-SD/1.2"},
};

__attribute__((weak)) MtObject* cBrowserPS4::MyDTI::newInstance() const {
    DDON_STUB("cBrowserPS4::MyDTI::newInstance")
    return nullptr;
}

