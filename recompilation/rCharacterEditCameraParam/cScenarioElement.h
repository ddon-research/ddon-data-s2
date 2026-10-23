#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "cScenario.h"

// Forward declarations
class cScenarioArg;

// Declarations
class cScenarioElement;

// Type aliases from DWARF
using SCENARIO_ACTION_FUNC_END = void(*)(cScenarioArg*);
using SCENARIO_ACTION_FUNC_INIT = void(*)(cScenarioArg*);
using SCENARIO_ACTION_FUNC_MAIN = SCENARIO_ACTION_RETURN(*)(cScenarioArg*);

class cScenarioElement
{
public:
    static SCENARIO_ACTION_FUNC_INIT getActionInit(SCENARIO_TASK_ENUM task);
    static SCENARIO_ACTION_FUNC_MAIN getActionMain(SCENARIO_TASK_ENUM task);
    static SCENARIO_ACTION_FUNC_END getActionEnd(SCENARIO_TASK_ENUM task);
};
