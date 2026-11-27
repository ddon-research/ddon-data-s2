// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nNetworkRemoteCalls.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "cRemoteCall.h"
#include "nNetworkCoder.h"
#include "nNetworkTransport.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& nNetwork::RpcNetSystem_AnsDetour::getDTI() const {
    return nNetwork::RpcNetSystem_AnsDetour::DTI;
}

nNetwork::RpcNetSystem_AnsDetour::~RpcNetSystem_AnsDetour() {
    DDON_STUB("nNetwork::RpcNetSystem_AnsDetour::~RpcNetSystem_AnsDetour")
    /* stub */
}

__attribute__((weak)) void nNetwork::RpcNetSystem_AnsDetour::serialize(MtStream& stream) {
    DDON_STUB("nNetwork::RpcNetSystem_AnsDetour::serialize")
    /* stub */
}

__attribute__((weak)) void nNetwork::RpcNetSystem_AnsDetour::deserialize(MtStream& stream) {
    DDON_STUB("nNetwork::RpcNetSystem_AnsDetour::deserialize")
    /* stub */
}

inline nNetwork::RpcNetSystem_AnsDetour::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nNetwork::RpcNetSystem_AnsDetour::MyDTI nNetwork::RpcNetSystem_AnsDetour::DTI("nNetwork::RpcNetSystem_AnsDetour", &::cRemoteCall::DTI, 152ul, 0u, 0u);

MtObject* nNetwork::RpcNetSystem_AnsDetour::MyDTI::newInstance() const {
    return new (16u) ::nNetwork::RpcNetSystem_AnsDetour;
}

const MtDTI& nNetwork::RpcNetSystem_Config::getDTI() const {
    return nNetwork::RpcNetSystem_Config::DTI;
}

nNetwork::RpcNetSystem_Config::~RpcNetSystem_Config() {
    DDON_STUB("nNetwork::RpcNetSystem_Config::~RpcNetSystem_Config")
    /* stub */
}

__attribute__((weak)) void nNetwork::RpcNetSystem_Config::serialize(MtStream& stream) {
    DDON_STUB("nNetwork::RpcNetSystem_Config::serialize")
    /* stub */
}

__attribute__((weak)) void nNetwork::RpcNetSystem_Config::deserialize(MtStream& stream) {
    DDON_STUB("nNetwork::RpcNetSystem_Config::deserialize")
    /* stub */
}

inline nNetwork::RpcNetSystem_Config::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nNetwork::RpcNetSystem_Config::MyDTI nNetwork::RpcNetSystem_Config::DTI("nNetwork::RpcNetSystem_Config", &::cRemoteCall::DTI, 80ul, 0u, 0u);

MtObject* nNetwork::RpcNetSystem_Config::MyDTI::newInstance() const {
    return new (16u) ::nNetwork::RpcNetSystem_Config;
}

const MtDTI& nNetwork::RpcNetSystem_Entry::getDTI() const {
    return nNetwork::RpcNetSystem_Entry::DTI;
}

void nNetwork::RpcNetSystem_Entry::serialize(MtStream& stream) {
    nNetwork::Coder cod(stream);
    cod.writeBit32(mEntry, 1u);
}

void nNetwork::RpcNetSystem_Entry::deserialize(MtStream& stream) {
    nNetwork::Decoder dec(stream);
    mEntry = dec.readBit32(1u) == 1;
}

inline nNetwork::RpcNetSystem_Entry::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nNetwork::RpcNetSystem_Entry::MyDTI nNetwork::RpcNetSystem_Entry::DTI("nNetwork::RpcNetSystem_Entry", &::cRemoteCall::DTI, 16ul, 0u, 0u);

__attribute__((weak)) MtObject* nNetwork::RpcNetSystem_Entry::MyDTI::newInstance() const {
    DDON_STUB("nNetwork::RpcNetSystem_Entry::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& nNetwork::RpcNetSystem_HealthCheck::getDTI() const {
    return nNetwork::RpcNetSystem_HealthCheck::DTI;
}

__attribute__((weak)) void nNetwork::RpcNetSystem_HealthCheck::serialize(MtStream& stream) {
    DDON_STUB("nNetwork::RpcNetSystem_HealthCheck::serialize")
    /* stub */
}

__attribute__((weak)) void nNetwork::RpcNetSystem_HealthCheck::deserialize(MtStream& stream) {
    DDON_STUB("nNetwork::RpcNetSystem_HealthCheck::deserialize")
    /* stub */
}

inline nNetwork::RpcNetSystem_HealthCheck::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nNetwork::RpcNetSystem_HealthCheck::MyDTI nNetwork::RpcNetSystem_HealthCheck::DTI("nNetwork::RpcNetSystem_HealthCheck", &::cRemoteCall::DTI, 16ul, 0u, 0u);

__attribute__((weak)) MtObject* nNetwork::RpcNetSystem_HealthCheck::MyDTI::newInstance() const {
    DDON_STUB("nNetwork::RpcNetSystem_HealthCheck::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& nNetwork::RpcNetSystem_LinkState::getDTI() const {
    return nNetwork::RpcNetSystem_LinkState::DTI;
}

nNetwork::RpcNetSystem_LinkState::~RpcNetSystem_LinkState() {
    DDON_STUB("nNetwork::RpcNetSystem_LinkState::~RpcNetSystem_LinkState")
    /* stub */
}

__attribute__((weak)) void nNetwork::RpcNetSystem_LinkState::serialize(MtStream& stream) {
    DDON_STUB("nNetwork::RpcNetSystem_LinkState::serialize")
    /* stub */
}

__attribute__((weak)) void nNetwork::RpcNetSystem_LinkState::deserialize(MtStream& stream) {
    DDON_STUB("nNetwork::RpcNetSystem_LinkState::deserialize")
    /* stub */
}

__attribute__((weak)) void nNetwork::RpcNetSystem_LinkState::init(const nNetwork::SessionDatabase* pdb, const nNetwork::Transport* pt) {
    DDON_STUB("nNetwork::RpcNetSystem_LinkState::init")
    /* stub */
}

inline nNetwork::RpcNetSystem_LinkState::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nNetwork::RpcNetSystem_LinkState::MyDTI nNetwork::RpcNetSystem_LinkState::DTI("nNetwork::RpcNetSystem_LinkState", &::cRemoteCall::DTI, 336ul, 0u, 0u);

MtObject* nNetwork::RpcNetSystem_LinkState::MyDTI::newInstance() const {
    return new (16u) ::nNetwork::RpcNetSystem_LinkState;
}

const MtDTI& nNetwork::RpcNetSystem_Match::getDTI() const {
    return nNetwork::RpcNetSystem_Match::DTI;
}

nNetwork::RpcNetSystem_Match::RpcNetSystem_Match() {
    mMatch = false;
    mList = 0;
    mAttribute = 0;
}

void nNetwork::RpcNetSystem_Match::serialize(MtStream& stream) {
    nNetwork::Coder cod(stream);
    cod.writeBit32(mMatch, 1u);
    cod.writeBit64(mList, 16u);
}

void nNetwork::RpcNetSystem_Match::deserialize(MtStream& stream) {
    nNetwork::Decoder dec(stream);
    mMatch = dec.readBit32(1u) == 1;
    mList = dec.readBit64(16u);
}

__attribute__((weak)) void nNetwork::RpcNetSystem_Match::init(const nNetwork::SessionDatabase* pdb) {
    DDON_STUB("nNetwork::RpcNetSystem_Match::init")
    /* stub */
}

inline nNetwork::RpcNetSystem_Match::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nNetwork::RpcNetSystem_Match::MyDTI nNetwork::RpcNetSystem_Match::DTI("nNetwork::RpcNetSystem_Match", &::cRemoteCall::DTI, 24ul, 0u, 0u);

MtObject* nNetwork::RpcNetSystem_Match::MyDTI::newInstance() const {
    return new (16u) ::nNetwork::RpcNetSystem_Match;
}

const MtDTI& nNetwork::RpcNetSystem_RouteKey::getDTI() const {
    return nNetwork::RpcNetSystem_RouteKey::DTI;
}

nNetwork::RpcNetSystem_RouteKey::~RpcNetSystem_RouteKey() {
    DDON_STUB("nNetwork::RpcNetSystem_RouteKey::~RpcNetSystem_RouteKey")
    /* stub */
}

__attribute__((weak)) void nNetwork::RpcNetSystem_RouteKey::serialize(MtStream& stream) {
    DDON_STUB("nNetwork::RpcNetSystem_RouteKey::serialize")
    /* stub */
}

__attribute__((weak)) void nNetwork::RpcNetSystem_RouteKey::deserialize(MtStream& stream) {
    DDON_STUB("nNetwork::RpcNetSystem_RouteKey::deserialize")
    /* stub */
}

inline nNetwork::RpcNetSystem_RouteKey::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nNetwork::RpcNetSystem_RouteKey::MyDTI nNetwork::RpcNetSystem_RouteKey::DTI("nNetwork::RpcNetSystem_RouteKey", &::cRemoteCall::DTI, 80ul, 0u, 0u);

MtObject* nNetwork::RpcNetSystem_RouteKey::MyDTI::newInstance() const {
    return new (16u) ::nNetwork::RpcNetSystem_RouteKey;
}

const MtDTI& nNetwork::RpcNetSystem_RouteKeyAck::getDTI() const {
    return nNetwork::RpcNetSystem_RouteKeyAck::DTI;
}

__attribute__((weak)) void nNetwork::RpcNetSystem_RouteKeyAck::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nNetwork::RpcNetSystem_RouteKeyAck::DTI)->memFree(p_addr);
}

nNetwork::RpcNetSystem_RouteKeyAck::~RpcNetSystem_RouteKeyAck() {
    DDON_STUB("nNetwork::RpcNetSystem_RouteKeyAck::~RpcNetSystem_RouteKeyAck")
    /* stub */
}

inline nNetwork::RpcNetSystem_RouteKeyAck::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nNetwork::RpcNetSystem_RouteKeyAck::MyDTI nNetwork::RpcNetSystem_RouteKeyAck::DTI("nNetwork::RpcNetSystem_RouteKeyAck", &::cRemoteCall::DTI, 16ul, 0u, 0u);

__attribute__((weak)) MtObject* nNetwork::RpcNetSystem_RouteKeyAck::MyDTI::newInstance() const {
    DDON_STUB("nNetwork::RpcNetSystem_RouteKeyAck::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& nNetwork::RpcNetSystem_Terminate::getDTI() const {
    return nNetwork::RpcNetSystem_Terminate::DTI;
}

nNetwork::RpcNetSystem_Terminate::RpcNetSystem_Terminate() {
    mTerminate = false;
    mList = 0;
    mAttribute = 0;
}

void nNetwork::RpcNetSystem_Terminate::serialize(MtStream& stream) {
    nNetwork::Coder cod(stream);
    cod.writeBit32(mTerminate, 1u);
    cod.writeBit64(mList, 16u);
}

void nNetwork::RpcNetSystem_Terminate::deserialize(MtStream& stream) {
    nNetwork::Decoder dec(stream);
    mTerminate = dec.readBit32(1u) == 1;
    mList = dec.readBit64(16u);
}

__attribute__((weak)) void nNetwork::RpcNetSystem_Terminate::init(const nNetwork::SessionDatabase* pdb) {
    DDON_STUB("nNetwork::RpcNetSystem_Terminate::init")
    /* stub */
}

inline nNetwork::RpcNetSystem_Terminate::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nNetwork::RpcNetSystem_Terminate::MyDTI nNetwork::RpcNetSystem_Terminate::DTI("nNetwork::RpcNetSystem_Terminate", &::cRemoteCall::DTI, 24ul, 0u, 0u);

MtObject* nNetwork::RpcNetSystem_Terminate::MyDTI::newInstance() const {
    return new (16u) ::nNetwork::RpcNetSystem_Terminate;
}

const MtDTI& nNetwork::RpcNetSystem_TryConnect::getDTI() const {
    return nNetwork::RpcNetSystem_TryConnect::DTI;
}

__attribute__((weak)) void nNetwork::RpcNetSystem_TryConnect::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nNetwork::RpcNetSystem_TryConnect::DTI)->memFree(p_addr);
}

nNetwork::RpcNetSystem_TryConnect::~RpcNetSystem_TryConnect() {
    DDON_STUB("nNetwork::RpcNetSystem_TryConnect::~RpcNetSystem_TryConnect")
    /* stub */
}

inline nNetwork::RpcNetSystem_TryConnect::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nNetwork::RpcNetSystem_TryConnect::MyDTI nNetwork::RpcNetSystem_TryConnect::DTI("nNetwork::RpcNetSystem_TryConnect", &::cRemoteCall::DTI, 16ul, 0u, 0u);

__attribute__((weak)) MtObject* nNetwork::RpcNetSystem_TryConnect::MyDTI::newInstance() const {
    DDON_STUB("nNetwork::RpcNetSystem_TryConnect::MyDTI::newInstance")
    return nullptr;
}

