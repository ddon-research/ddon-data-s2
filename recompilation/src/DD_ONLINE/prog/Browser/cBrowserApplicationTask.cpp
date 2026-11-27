// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cBrowserApplicationTask.h"
#include "../../../MT/MtAllocator.h"
#include "../../../MT/MtDTI.h"
#include "../../../MT/MtObject.h"
#include "cBrowserPS4_h.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cBrowserApplicationTask::getDTI() const {
    return cBrowserApplicationTask::DTI;
}

void* cBrowserApplicationTask::operator new(size_t sz, u32 align) {
    return cBrowserApplicationTask::getAllocator()->memAlloc(sz, align, cBrowserApplicationTask::DTI.getID());
}

cBrowserApplicationTask::cBrowserApplicationTask(cBrowserPS4* brw) {
    m_brw = brw;
    reset_member();
}

cBrowserApplicationTask::~cBrowserApplicationTask() {
    if (m_tskidx != 0) {
        m_tskidx = 0;
        m_rno0 = 0;
        m_prm = nullptr;
        m_brw->pause_end();
    }
    m_brw->pause_end();
    m_ini = 0;
    m_rno0 = 0;
    m_tskidx = 0;
    m_prm = nullptr;
}

int cBrowserApplicationTask::initialize() {
    if (m_ini != 0) {
        if (m_tskidx != 0) {
            m_tskidx = 0;
            m_rno0 = 0;
            m_prm = nullptr;
            m_brw->pause_end();
        }
        m_brw->pause_end();
        m_ini = 0;
        m_rno0 = 0;
        m_tskidx = 0;
        m_prm = nullptr;
    }
    m_ini = 1;
    return 1;
}

void cBrowserApplicationTask::finalize() {
    if (m_tskidx != 0) {
        m_tskidx = 0;
        m_rno0 = 0;
        m_prm = nullptr;
        m_brw->pause_end();
    }
    m_brw->pause_end();
    m_ini = 0;
    m_rno0 = 0;
    m_tskidx = 0;
    m_prm = nullptr;
}

void cBrowserApplicationTask::move() {
    if (m_ini == 0) {
        return;
    }
    if (m_tskidx == 0) {
        return;
    }
    if (m_rno0 != 2) {
        if (m_rno0 == 1) {
            m_rno0 = 2;
        } else {
            if (m_rno0 == 0) {
                m_tskidx = 0;
                m_rno0 = 0;
                m_prm = nullptr;
                m_brw->pause_end();
            }
        }
    } else {
        m_tskidx = 0;
        m_rno0 = 0;
        m_prm = nullptr;
        m_brw->pause_end();
    }
}

__attribute__((weak)) void cBrowserApplicationTask::draw() {
}

inline cBrowserApplicationTask::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cBrowserApplicationTask::MyDTI cBrowserApplicationTask::DTI("cBrowserApplicationTask", &::MtObject::DTI, 40ul, 0u, 0u);

MtObject* cBrowserApplicationTask::MyDTI::newInstance() const {
    return new (16u) cBrowserApplicationTask;
}

