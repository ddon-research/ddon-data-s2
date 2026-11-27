// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rMagicCommandWord.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cResource.h"
#include "../../generated/shared/nDDOIO.h"
#include "nDDOUtility.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cMagicCommandWord::getDTI() const {
    return cMagicCommandWord::DTI;
}

void cMagicCommandWord::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "01\346\226\207\345\255\227\347\233\256", &mWord.elems[0], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "02\346\226\207\345\255\227\347\233\256", &mWord.elems[1], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "03\346\226\207\345\255\227\347\233\256", &mWord.elems[2], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "04\346\226\207\345\255\227\347\233\256", &mWord.elems[3], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "05\346\226\207\345\255\227\347\233\256", &mWord.elems[4], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "06\346\226\207\345\255\227\347\233\256", &mWord.elems[5], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "07\346\226\207\345\255\227\347\233\256", &mWord.elems[6], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "08\346\226\207\345\255\227\347\233\256", &mWord.elems[7], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "09\346\226\207\345\255\227\347\233\256", &mWord.elems[8], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "10\346\226\207\345\255\227\347\233\256", &mWord.elems[9], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "11\346\226\207\345\255\227\347\233\256", &mWord.elems[10], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "12\346\226\207\345\255\227\347\233\256", &mWord.elems[11], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "13\346\226\207\345\255\227\347\233\256", &mWord.elems[12], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "14\346\226\207\345\255\227\347\233\256", &mWord.elems[13], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "15\346\226\207\345\255\227\347\233\256", &mWord.elems[14], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "16\346\226\207\345\255\227\347\233\256", &mWord.elems[15], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "17\346\226\207\345\255\227\347\233\256", &mWord.elems[16], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "18\346\226\207\345\255\227\347\233\256", &mWord.elems[17], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "19\346\226\207\345\255\227\347\233\256", &mWord.elems[18], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "20\346\226\207\345\255\227\347\233\256", &mWord.elems[19], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "21\346\226\207\345\255\227\347\233\256", &mWord.elems[20], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "22\346\226\207\345\255\227\347\233\256", &mWord.elems[21], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "23\346\226\207\345\255\227\347\233\256", &mWord.elems[22], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "24\346\226\207\345\255\227\347\233\256", &mWord.elems[23], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "25\346\226\207\345\255\227\347\233\256", &mWord.elems[24], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "26\346\226\207\345\255\227\347\233\256", &mWord.elems[25], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "27\346\226\207\345\255\227\347\233\256", &mWord.elems[26], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "28\346\226\207\345\255\227\347\233\256", &mWord.elems[27], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "29\346\226\207\345\255\227\347\233\256", &mWord.elems[28], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "30\346\226\207\345\255\227\347\233\256", &mWord.elems[29], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "31\346\226\207\345\255\227\347\233\256", &mWord.elems[30], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "32\346\226\207\345\255\227\347\233\256", &mWord.elems[31], 0u, 0u);
}

inline cMagicCommandWord::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cMagicCommandWord::MyDTI cMagicCommandWord::DTI("cMagicCommandWord", &::MtObject::DTI, 136ul, 0u, 0u);

MtObject* cMagicCommandWord::MyDTI::newInstance() const {
    return new (16u) cMagicCommandWord;
}

const MtDTI& rMagicCommandWord::getDTI() const {
    return rMagicCommandWord::DTI;
}

__attribute__((weak)) bool rMagicCommandWord::loadData(MtDataReader& in, cMagicCommandWord* pData) {
        for (s16 i = 0; i < 32; ++i) {
            nDDOIO::readData(in, pData->mWord.elems[i]);
        }
        return true;
}

MT_CTSTR rMagicCommandWord::getExt() const {
    return "mcw";
}

u32 rMagicCommandWord::getDataVersion() const {
    return 1;
}

void rMagicCommandWord::createProperty(MtPropertyList& s) {
    this->cResource::createProperty(s);
}

inline rMagicCommandWord::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rMagicCommandWord::MyDTI rMagicCommandWord::DTI("rMagicCommandWord", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rMagicCommandWord::MyDTI::newInstance() const {
    return new (16u) rMagicCommandWord;
}

template cMagicCommandWord* rTbl2<cMagicCommandWord>::getData(unsigned int);

template bool rTbl2<cMagicCommandWord>::load(MtStream&);

template bool rTbl2<cMagicCommandWord>::loadCore(MtDataReader&);

template const cMagicCommandWord* rTbl2<cMagicCommandWord>::getData(unsigned int) const;

template unsigned int rTbl2<cMagicCommandWord>::getDataNum() const;

template rTbl2<cMagicCommandWord>::~rTbl2();

