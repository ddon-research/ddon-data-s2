// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nPhysicsConstraintObject.h"
#include "../MT/MtDTI.h"
#include "nPhysicsBase.h"
#include "nPhysicsList.h"
#include "nPhysicsStruct.h"
#include "nPhysicsSystem.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& nPhysics::Constraint::Object::getDTI() const {
    return nPhysics::Constraint::Object::DTI;
}

nPhysics::Constraint::Object::Object(const nPhysics::CONSTRAINT::TYPE type) {
    DDON_STUB("nPhysics::Constraint::Object::Object")
    /* stub */
}

nPhysics::Constraint::Object::~Object() {
    DDON_STUB("nPhysics::Constraint::Object::~Object")
    /* stub */
}

nPhysics::CONSTRAINT* nPhysics::Constraint::Object::CreateConstraintInstance() {
    return (::nPhysics::System::mInstance)->::nPhysics::System::create_constraint_instance();
}

void nPhysics::Constraint::Object::RemoveConstraintInstance(nPhysics::CONSTRAINT* constraint) {
    if (constraint == nullptr) {
        return;
    }
    (::nPhysics::System::mInstance)->::nPhysics::System::remove_constraint_instance(constraint);
}

inline nPhysics::Constraint::Object::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nPhysics::Constraint::Object::MyDTI nPhysics::Constraint::Object::DTI("nPhysics::Constraint::Object", &::nPhysics::Base::DTI, 104ul, 0u, 1u);

MtObject* nPhysics::Constraint::Object::MyDTI::newInstance() const {
    return nullptr;
}

