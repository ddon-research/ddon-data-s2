// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIInputText.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtPrimitive2D.h"
#include "../../MT/MtString.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cGUIObject.h"
#include "cGUIUtility.h"
#include "../../XFramework/cResource.h"
#include "nDDOUtility.h"
#include "nInputText.h"
#include "../../generated/shared/nUnicode.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "uGUIBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIInputText::getDTI() const {
    return uGUIInputText::DTI;
}

void* uGUIInputText::operator new(size_t sz, u32 align) {
    return uGUIInputText::getAllocator()->memAlloc(sz, align, uGUIInputText::DTI.getID());
}

uGUIInputText::~uGUIInputText() {
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

bool uGUIInputText::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_INPUT_TEXT_GUI"), 129u, 1430112267l))) == nullptr)) {
        return false;
    }
    return true;
}

void uGUIInputText::setup() {
    this->uGUIBase::setup();
    if (!mIsEndLoadResource) {
        return;
    }
    setPriority(static_cast<sGUIExt*>(sGUI::getInstance())->issuePriority(14u), true);
    setPlay(true);
    setFlowAndInit(3u, false);
    mpINST_Null_all = static_cast<cGUIInstNull*>(getInstance(4u, false));
    mpINST_msg_text = static_cast<cGUIInstAnimation*>(getInstance(3u, false));
    cGUIObjMessage* obj_msg_text = static_cast<cGUIObjMessage*>(getObjectFromId(3u, 20u));
    if (obj_msg_text != nullptr) {
        obj_msg_text->mMsgAttr = obj_msg_text->mMsgAttr & 0xFFFFFFF7u;
        mpOBJ_msg_texts.elems[0] = obj_msg_text;
        cGUIObject* t0 = getObjectFromId(3u, 29u);
        if (t0 != nullptr) {
            *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t0) + 296) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t0) + 296)) & 247;
            mpOBJ_msg_texts.elems[1] = static_cast<cGUIObjMessage*>(t0);
            cGUIObject* t1 = getObjectFromId(3u, 30u);
            if (t1 != nullptr) {
                *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t1) + 296) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t1) + 296)) & 247;
                mpOBJ_msg_texts.elems[2] = static_cast<cGUIObjMessage*>(t1);
                cGUIObject* t2 = getObjectFromId(3u, 31u);
                if (t2 != nullptr) {
                    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t2) + 296) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t2) + 296)) & 247;
                    mpOBJ_msg_texts.elems[3] = static_cast<cGUIObjMessage*>(t2);
                }
                mpOBJ_msg_text_caret = static_cast<cGUIObjPolygon*>(getObjectFromId(3u, 34u));
                mpOBJ_msg_text_wallpaper = static_cast<cGUIObjPolygon*>(getObjectFromId(3u, 40u));
                mpOBJ_msg_text_mask_center = static_cast<cGUIObjPolygon*>(getObjectFromId(3u, 37u));
                mpOBJ_msg_text_Null_txt = static_cast<cGUIObjNull*>(getObjectFromId(3u, 39u));
                if (mpINST_Null_all != nullptr) {
                    mpINST_Null_all->setVisible(false);
                    if (mpINST_Null_all != nullptr) {
                        mpINST_Null_all->setExecute(false);
                    }
                }
                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIInputText::updateInit);
            } else {
                cGUIObject* t2 = getObjectFromId(3u, 31u);
                if (t2 != nullptr) {
                    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t2) + 296) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t2) + 296)) & 247;
                    mpOBJ_msg_texts.elems[3] = static_cast<cGUIObjMessage*>(t2);
                }
                mpOBJ_msg_text_caret = static_cast<cGUIObjPolygon*>(getObjectFromId(3u, 34u));
                mpOBJ_msg_text_wallpaper = static_cast<cGUIObjPolygon*>(getObjectFromId(3u, 40u));
                mpOBJ_msg_text_mask_center = static_cast<cGUIObjPolygon*>(getObjectFromId(3u, 37u));
                mpOBJ_msg_text_Null_txt = static_cast<cGUIObjNull*>(getObjectFromId(3u, 39u));
                if (mpINST_Null_all != nullptr) {
                    mpINST_Null_all->setVisible(false);
                    if (mpINST_Null_all != nullptr) {
                        mpINST_Null_all->setExecute(false);
                    }
                }
                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIInputText::updateInit);
            }
        } else {
            cGUIObject* t1 = getObjectFromId(3u, 30u);
            if (t1 != nullptr) {
                *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t1) + 296) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t1) + 296)) & 247;
                mpOBJ_msg_texts.elems[2] = static_cast<cGUIObjMessage*>(t1);
                cGUIObject* t2 = getObjectFromId(3u, 31u);
                if (t2 != nullptr) {
                    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t2) + 296) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t2) + 296)) & 247;
                    mpOBJ_msg_texts.elems[3] = static_cast<cGUIObjMessage*>(t2);
                }
                mpOBJ_msg_text_caret = static_cast<cGUIObjPolygon*>(getObjectFromId(3u, 34u));
                mpOBJ_msg_text_wallpaper = static_cast<cGUIObjPolygon*>(getObjectFromId(3u, 40u));
                mpOBJ_msg_text_mask_center = static_cast<cGUIObjPolygon*>(getObjectFromId(3u, 37u));
                mpOBJ_msg_text_Null_txt = static_cast<cGUIObjNull*>(getObjectFromId(3u, 39u));
                if (mpINST_Null_all != nullptr) {
                    mpINST_Null_all->setVisible(false);
                    if (mpINST_Null_all != nullptr) {
                        mpINST_Null_all->setExecute(false);
                    }
                }
                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIInputText::updateInit);
            } else {
                cGUIObject* t2 = getObjectFromId(3u, 31u);
                if (t2 != nullptr) {
                    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t2) + 296) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t2) + 296)) & 247;
                    mpOBJ_msg_texts.elems[3] = static_cast<cGUIObjMessage*>(t2);
                }
                mpOBJ_msg_text_caret = static_cast<cGUIObjPolygon*>(getObjectFromId(3u, 34u));
                mpOBJ_msg_text_wallpaper = static_cast<cGUIObjPolygon*>(getObjectFromId(3u, 40u));
                mpOBJ_msg_text_mask_center = static_cast<cGUIObjPolygon*>(getObjectFromId(3u, 37u));
                mpOBJ_msg_text_Null_txt = static_cast<cGUIObjNull*>(getObjectFromId(3u, 39u));
                if (mpINST_Null_all != nullptr) {
                    mpINST_Null_all->setVisible(false);
                    if (mpINST_Null_all != nullptr) {
                        mpINST_Null_all->setExecute(false);
                    }
                }
                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIInputText::updateInit);
            }
        }
    } else {
        cGUIObject* t0 = getObjectFromId(3u, 29u);
        if (t0 != nullptr) {
            *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t0) + 296) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t0) + 296)) & 247;
            mpOBJ_msg_texts.elems[1] = static_cast<cGUIObjMessage*>(t0);
            cGUIObject* t1 = getObjectFromId(3u, 30u);
            if (t1 != nullptr) {
                *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t1) + 296) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t1) + 296)) & 247;
                mpOBJ_msg_texts.elems[2] = static_cast<cGUIObjMessage*>(t1);
                cGUIObject* t2 = getObjectFromId(3u, 31u);
                if (t2 != nullptr) {
                    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t2) + 296) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t2) + 296)) & 247;
                    mpOBJ_msg_texts.elems[3] = static_cast<cGUIObjMessage*>(t2);
                }
                mpOBJ_msg_text_caret = static_cast<cGUIObjPolygon*>(getObjectFromId(3u, 34u));
                mpOBJ_msg_text_wallpaper = static_cast<cGUIObjPolygon*>(getObjectFromId(3u, 40u));
                mpOBJ_msg_text_mask_center = static_cast<cGUIObjPolygon*>(getObjectFromId(3u, 37u));
                mpOBJ_msg_text_Null_txt = static_cast<cGUIObjNull*>(getObjectFromId(3u, 39u));
                if (mpINST_Null_all != nullptr) {
                    mpINST_Null_all->setVisible(false);
                    if (mpINST_Null_all != nullptr) {
                        mpINST_Null_all->setExecute(false);
                    }
                }
                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIInputText::updateInit);
            } else {
                cGUIObject* t2 = getObjectFromId(3u, 31u);
                if (t2 != nullptr) {
                    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t2) + 296) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t2) + 296)) & 247;
                    mpOBJ_msg_texts.elems[3] = static_cast<cGUIObjMessage*>(t2);
                }
                mpOBJ_msg_text_caret = static_cast<cGUIObjPolygon*>(getObjectFromId(3u, 34u));
                mpOBJ_msg_text_wallpaper = static_cast<cGUIObjPolygon*>(getObjectFromId(3u, 40u));
                mpOBJ_msg_text_mask_center = static_cast<cGUIObjPolygon*>(getObjectFromId(3u, 37u));
                mpOBJ_msg_text_Null_txt = static_cast<cGUIObjNull*>(getObjectFromId(3u, 39u));
                if (mpINST_Null_all != nullptr) {
                    mpINST_Null_all->setVisible(false);
                    if (mpINST_Null_all != nullptr) {
                        mpINST_Null_all->setExecute(false);
                    }
                }
                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIInputText::updateInit);
            }
        } else {
            cGUIObject* t1 = getObjectFromId(3u, 30u);
            if (t1 != nullptr) {
                *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t1) + 296) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t1) + 296)) & 247;
                mpOBJ_msg_texts.elems[2] = static_cast<cGUIObjMessage*>(t1);
                cGUIObject* t2 = getObjectFromId(3u, 31u);
                if (t2 != nullptr) {
                    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t2) + 296) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t2) + 296)) & 247;
                    mpOBJ_msg_texts.elems[3] = static_cast<cGUIObjMessage*>(t2);
                }
                mpOBJ_msg_text_caret = static_cast<cGUIObjPolygon*>(getObjectFromId(3u, 34u));
                mpOBJ_msg_text_wallpaper = static_cast<cGUIObjPolygon*>(getObjectFromId(3u, 40u));
                mpOBJ_msg_text_mask_center = static_cast<cGUIObjPolygon*>(getObjectFromId(3u, 37u));
                mpOBJ_msg_text_Null_txt = static_cast<cGUIObjNull*>(getObjectFromId(3u, 39u));
                if (mpINST_Null_all != nullptr) {
                    mpINST_Null_all->setVisible(false);
                    if (mpINST_Null_all != nullptr) {
                        mpINST_Null_all->setExecute(false);
                    }
                }
                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIInputText::updateInit);
            } else {
                cGUIObject* t2 = getObjectFromId(3u, 31u);
                if (t2 != nullptr) {
                    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t2) + 296) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t2) + 296)) & 247;
                    mpOBJ_msg_texts.elems[3] = static_cast<cGUIObjMessage*>(t2);
                }
                mpOBJ_msg_text_caret = static_cast<cGUIObjPolygon*>(getObjectFromId(3u, 34u));
                mpOBJ_msg_text_wallpaper = static_cast<cGUIObjPolygon*>(getObjectFromId(3u, 40u));
                mpOBJ_msg_text_mask_center = static_cast<cGUIObjPolygon*>(getObjectFromId(3u, 37u));
                mpOBJ_msg_text_Null_txt = static_cast<cGUIObjNull*>(getObjectFromId(3u, 39u));
                if (mpINST_Null_all != nullptr) {
                    mpINST_Null_all->setVisible(false);
                    if (mpINST_Null_all != nullptr) {
                        mpINST_Null_all->setExecute(false);
                    }
                }
                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIInputText::updateInit);
            }
        }
    }
}

void uGUIInputText::kill() {
    this->uGUIBase::kill();
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

void uGUIInputText::moveAfter() {
    this->uGUIBase::moveAfter();
    if (mpINST_Null_all == nullptr) {
        return;
    }
    mpINST_Null_all->setScaleX(mScale);
    mpINST_Null_all->setScaleY(mScale);
    mpINST_Null_all->setPositionX(mPos.x);
    mpINST_Null_all->setPositionY(mPos.y);
}

f32 uGUIInputText::getCaretWidth() const {
    if (mpOBJ_msg_text_caret != nullptr) {
        return mpOBJ_msg_text_caret->mSize.x;
    } else {
        return MtFloat2::Zero.x;
    }
}

__attribute__((weak)) void uGUIInputText::setPosScale(const cGUIObjMessage* objMessage, const MtVector3& unitPos, f32 scale) {
    DDON_STUB("uGUIInputText::setPosScale")
    /* stub */
}

__attribute__((weak)) void uGUIInputText::setProperty(const MtFloat2& pos, const MtSize& fontSize, const MtFloat2& messageSize, u32 autoWrap, u32 layout, u32 controlPoint, f32 instNullScale, f32 inputModeIconWidth, bool isWallpaper, const MtFloat2* maskSize) {
    DDON_STUB("uGUIInputText::setProperty")
    /* stub */
}

__attribute__((weak)) void uGUIInputText::setProperty(const cGUIObjMessage* objMessage, const MtVector3& unitPos, f32 instNullScale, f32 inputModeIconWidth, const cGUIObjPolygon* objMask) {
    DDON_STUB("uGUIInputText::setProperty")
    /* stub */
}

__attribute__((weak)) const MtRectF& uGUIInputText::applyInputTextContext(const nInputText::Context& inputTextContext) {
    DDON_STUB("uGUIInputText::applyInputTextContext")
    __builtin_unreachable();
}

bool uGUIInputText::isTextVisible() const {
    if (!mIsVisible) {
        if (mpINST_Null_all != nullptr) {
            return static_cast<bool>((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(mpINST_Null_all) + 88)) & 1);
        } else {
            return false;
        }
    } else {
        return true;
    }
}

void uGUIInputText::updateInit() {
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIInputText::updateIdle);
}

__attribute__((weak)) void uGUIInputText::updateIdle() {
    DDON_STUB("uGUIInputText::updateIdle")
    /* stub */
}

__attribute__((weak)) void uGUIInputText::updateCaretPosition(u32 characterIndex, u32 characterCount, const cGUIObjMessage* objMessage) {
    DDON_STUB("uGUIInputText::updateCaretPosition")
    /* stub */
}

__attribute__((weak)) MtPointF uGUIInputText::updateTextPosition() {
    DDON_STUB("uGUIInputText::updateTextPosition")
    __builtin_unreachable();
}

inline uGUIInputText::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIInputText::MyDTI uGUIInputText::DTI("uGUIInputText", &::uGUIBase::DTI, 39344ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIInputText::MyDTI::newInstance() const {
    DDON_STUB("uGUIInputText::MyDTI::newInstance")
    return nullptr;
}

