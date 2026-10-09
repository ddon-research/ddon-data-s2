#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "nDDOUtility.h"

// Declarations
class cZoneIndoorHandle;

class cZoneIndoorHandle
{
public:
    enum INZN_IDX
    {
        INZN_IDX_COM_SCR = 0,
        INZN_IDX_COM_EFC = 1,
        INZN_IDX_COM_SND = 2,
        INZN_IDX_SP_SCR = 3,
        INZN_IDX_SP_EFC = 4,
        INZN_IDX_NUM = 5,
    };
public:
    cZoneIndoorHandle();
    void clear();
public:
    nDDOUtility::cArray<unsigned int, 5> mHandles;  // offset: 0x0
};
