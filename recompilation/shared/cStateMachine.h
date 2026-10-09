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

// Generic (024 T808): every instance that renders gives this body; the unit of each instance's compile unit, else cStateMachine.cpp, instantiates it for the body oracle.
template <typename YContext>
void TStateMachine<YContext>::initializeStateMachine(Context* context) {
    this->::cStateMachineBase::initializeStateMachineBase(static_cast<void*>(context));
}
