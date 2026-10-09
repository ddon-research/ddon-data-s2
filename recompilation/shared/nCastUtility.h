#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
class uBaseModel;

// Declarations
class estUnitTypeBase;
template <typename BaseType, typename T> class estUnitType;

class estUnitTypeBase
{
public:
    estUnitTypeBase(uBaseModel* pUnit);
    operator bool();
private:
    estUnitTypeBase();
protected:
    uBaseModel* mpUnit;  // offset: 0x0
};

template <typename BaseType, typename T>
class estUnitType : public estUnitTypeBase
{
public:
    estUnitType(BaseType* pUnit);
};
