// Reconstructed from the game's DWARF debug information.
#include <new>
#include "Server.h"
#include "../../../../MT/MtAllocator.h"
#include "../../../../MT/MtDTI.h"
#include "../../../../MT/MtObject.h"
#include "../../../../MT/MtString.h"
#include "../../cPacket.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& CDataGameServerListInfo::getDTI() const {
    return CDataGameServerListInfo::DTI;
}

void* CDataGameServerListInfo::operator new(size_t sz, u32 align) {
    return CDataGameServerListInfo::getAllocator()->memAlloc(sz, align, CDataGameServerListInfo::DTI.getID());
}

__attribute__((weak)) void CDataGameServerListInfo::operator delete(void* p_addr) {
    CDataGameServerListInfo::getAllocator()->memFree(p_addr);
}

inline CDataGameServerListInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataGameServerListInfo::MyDTI CDataGameServerListInfo::DTI("CDataGameServerListInfo", &::CPacketDataBase::DTI, 72ul, 0u, 0u);

MtObject* CDataGameServerListInfo::MyDTI::newInstance() const {
    return new (16u) CDataGameServerListInfo;
}

const MtDTI& CDataGameTime::getDTI() const {
    return CDataGameTime::DTI;
}

__attribute__((weak)) void CDataGameTime::operator delete(void* p_addr) {
    CDataGameTime::getAllocator()->memFree(p_addr);
}

inline CDataGameTime::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataGameTime::MyDTI CDataGameTime::DTI("CDataGameTime", &::CPacketDataBase::DTI, 24ul, 0u, 0u);

MtObject* CDataGameTime::MyDTI::newInstance() const {
    return new (16u) CDataGameTime;
}

const MtDTI& CDataURLInfo::getDTI() const {
    return CDataURLInfo::DTI;
}

void* CDataURLInfo::operator new(size_t sz, u32 align) {
    return CDataURLInfo::getAllocator()->memAlloc(sz, align, CDataURLInfo::DTI.getID());
}

__attribute__((weak)) void CDataURLInfo::operator delete(void* p_addr) {
    CDataURLInfo::getAllocator()->memFree(p_addr);
}

inline CDataURLInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataURLInfo::MyDTI CDataURLInfo::DTI("CDataURLInfo", &::CPacketDataBase::DTI, 24ul, 0u, 0u);

MtObject* CDataURLInfo::MyDTI::newInstance() const {
    return new (16u) CDataURLInfo;
}

const MtDTI& CDataWeatherForecast::getDTI() const {
    return CDataWeatherForecast::DTI;
}

void* CDataWeatherForecast::operator new(size_t sz, u32 align) {
    return CDataWeatherForecast::getAllocator()->memAlloc(sz, align, CDataWeatherForecast::DTI.getID());
}

__attribute__((weak)) void CDataWeatherForecast::operator delete(void* p_addr) {
    CDataWeatherForecast::getAllocator()->memFree(p_addr);
}

inline CDataWeatherForecast::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataWeatherForecast::MyDTI CDataWeatherForecast::DTI("CDataWeatherForecast", &::CPacketDataBase::DTI, 16ul, 0u, 0u);

MtObject* CDataWeatherForecast::MyDTI::newInstance() const {
    return new (16u) CDataWeatherForecast;
}

const MtDTI& CDataWorldInfo::getDTI() const {
    return CDataWorldInfo::DTI;
}

__attribute__((weak)) void CDataWorldInfo::operator delete(void* p_addr) {
    CDataWorldInfo::getAllocator()->memFree(p_addr);
}

inline CDataWorldInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataWorldInfo::MyDTI CDataWorldInfo::DTI("CDataWorldInfo", &::CPacketDataBase::DTI, 96ul, 0u, 0u);

MtObject* CDataWorldInfo::MyDTI::newInstance() const {
    return new (16u) CDataWorldInfo;
}

