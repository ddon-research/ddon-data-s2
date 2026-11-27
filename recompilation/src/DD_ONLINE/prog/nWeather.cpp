// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nWeather.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cWeatherObjectRes::getDTI() const {
    return cWeatherObjectRes::DTI;
}

inline cWeatherObjectRes::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cWeatherObjectRes::MyDTI cWeatherObjectRes::DTI("cWeatherObjectRes", &::MtObject::DTI, 8ul, 0u, 0u);

MtObject* cWeatherObjectRes::MyDTI::newInstance() const {
    return new (16u) cWeatherObjectRes;
}

const MtDTI& cWeatherObjectSys::getDTI() const {
    return cWeatherObjectSys::DTI;
}

inline cWeatherObjectSys::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cWeatherObjectSys::MyDTI cWeatherObjectSys::DTI("cWeatherObjectSys", &::MtObject::DTI, 8ul, 0u, 0u);

MtObject* cWeatherObjectSys::MyDTI::newInstance() const {
    return new (16u) cWeatherObjectSys;
}

