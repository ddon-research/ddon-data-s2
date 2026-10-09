#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtPropertyList;
class cCommonSkyFogData;
class cWeatherFogInfo;

// Declarations
class cIndoorSkyFogParam;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cIndoorSkyFogParam : public MtObject
{
public:
    class MyDTI;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    static MtDTI* getMyDTIPtr();
    static void usage();
    virtual const MtDTI& getDTI() const;  // vtable slot 5
    static MtAllocator* getAllocator();
    static void setAllocator(u32);
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete(void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
    cIndoorSkyFogParam();
    // Address: 0x01a66470 - 0x01a66471 (1 bytes)
    virtual ~cIndoorSkyFogParam() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void setWeatherId(s32 set);
    void setIntensity(f32 set);
    void setDensity(f32 set);
    void setStart(f32 set);
    void setEnd(f32 set);
    s32 getWeatherId();
    f32 getIntensity();
    f32 getDensity();
    f32 getStart();
    f32 getEnd();
    u32 getId();
    void setupFromCopy(const cIndoorSkyFogParam* pData);
    void setupFromCopy(cIndoorSkyFogParam* pData, f32 density);
    void setupFromCopy(cWeatherFogInfo* pData, f32 density, f32 intensity);
    void setupFromCopy(cCommonSkyFogData* pData);
    void setupFromLerp(cIndoorSkyFogParam* pStart, cIndoorSkyFogParam* pEnd, f32 rate);
    void updateWeatherFogInfo(cWeatherFogInfo* pStart, f32 rate);
    bool isSameData(cIndoorSkyFogParam* pData);
private:
    s32 mWeatherId;  // offset: 0x8
    f32 mIntensity;  // offset: 0xc
    f32 mDensity;  // offset: 0x10
    f32 mStart;  // offset: 0x14
    f32 mEnd;  // offset: 0x18
    u32 mId;  // offset: 0x1c
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline f32 cIndoorSkyFogParam::getIntensity() {
    return this->mIntensity;
}

// Inline, no code of its own: checked where it is inlined.
inline f32 cIndoorSkyFogParam::getDensity() {
    return this->mDensity;
}

// Inline, no code of its own: checked where it is inlined.
inline f32 cIndoorSkyFogParam::getStart() {
    return this->mStart;
}

// Inline, no code of its own: checked where it is inlined.
inline f32 cIndoorSkyFogParam::getEnd() {
    return this->mEnd;
}

// Inline, no code of its own: checked where it is inlined.
inline u32 cIndoorSkyFogParam::getId() {
    return this->mId;
}
