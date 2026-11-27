// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cGUIObjTextureRef.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../XFramework/cGUIObject.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/nGUI.h"
#include "../../XFramework/rTexture.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cGUIObjTextureRef::getDTI() const {
    return cGUIObjTextureRef::DTI;
}

cGUIObjTextureRef::~cGUIObjTextureRef() {
    if (mTexReplace.pTexture != nullptr) {
        mTexReplace.pTexture->release();
        mTexReplace.pTexture = nullptr;
    }
    if (mpTextureOrigin == nullptr) {
        return;
    }
    mpTexture = mpTextureOrigin;
}

__attribute__((weak)) void cGUIObjTextureRef::setReferenceTexture(rTexture* pTexture) {
    DDON_STUB("cGUIObjTextureRef::setReferenceTexture")
    /* stub */
}

void cGUIObjTextureRef::createProperty(MtPropertyList& s) {
    this->cGUIObjTexture::createProperty(s);
}

void cGUIObjTextureRef::draw(nGUI::Draw& drawObj) {
    if (mTexReplace.pTexture != nullptr) {
        if (mTexReplace.pTexture->isUsage()) {
            mpTexture = &mTexReplace;
        } else {
            if (mpTextureOrigin != nullptr) {
                mpTexture = mpTextureOrigin;
            }
        }
    } else {
        if (mpTextureOrigin != nullptr) {
            mpTexture = mpTextureOrigin;
        }
    }
    this->cGUIObjTexture::draw(drawObj);
}

inline cGUIObjTextureRef::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cGUIObjTextureRef::MyDTI cGUIObjTextureRef::DTI("cGUIObjTextureRef", &::cGUIObjTexture::DTI, 400ul, 0u, 0u);

__attribute__((weak)) MtObject* cGUIObjTextureRef::MyDTI::newInstance() const {
    DDON_STUB("cGUIObjTextureRef::MyDTI::newInstance")
    return nullptr;
}

