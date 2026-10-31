#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "cStateMachineBase.h"

// Declarations
template <typename YContext> class TStateMachine;

template <typename YContext>
class TStateMachine : public cStateMachineBase
{
public:
    class TState;
public:
    using Context = YContext;
public:
    class TState : public cStateMachineBase::StateBase
    {
    protected:
        TStateMachine::Context* getContext() const;
    };
public:
    virtual void initializeStateMachine(Context* context);  // vtable slot 3
    Context* getContext();
};

template <typename YContext>
void TStateMachine<YContext>::initializeStateMachine(Context* context) {
    this->::cStateMachineBase::initializeStateMachineBase(static_cast<void*>(context));
}
