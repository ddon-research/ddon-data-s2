#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector4;

// Declarations
class cSoundMultiBandEQ;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cSoundMultiBandEQ : public MtObject
{
public:
    enum EQ_FILTER_TYPE
    {
        EQFT_PEQ = 0,
        EQFT_LSF = 1,
        EQFT_HPF = 2,
        EQFT_HSF = 3,
        EQFT_LPF = 4,
    };
    enum EQUnit
    {
        LOW = 0,
        MIDLOW = 1,
        MIDHIGH = 2,
        HIGH = 3,
    };
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
    void setEQParam(u32 unit);
    void setPeakingEQ(u32 unit);
    void setLPF();
    void setHPF();
    void setLSF();
    void setHSF();
    void setCoefficient(u32 unit, f32 a0, f32 a1, f32 a2, f32 b0, f32 b1, f32 b2);
    void setBypassCoefficient(u32 unit);
    void setUnitEnable(u32 unit, bool b);
    bool getUnitEnable(u32 unit) const;
    void setUnitFreq(u32 unit, f32 freq);
    void setUnitGain(u32 unit, f32 gain);
    void setUnitQ(u32 unit, f32 q);
    f32 getUnitFreq(u32 unit) const;
    f32 getUnitQ(u32 unit) const;
    f32 getUnitGain(u32 unit) const;
    void computeAllUnit(f32* pSampleBuffer, u32 sampleNum);
    void computeAllUnit(f32* * ppSampleBuffer, u32 sampleNum);
    void computeSingleUnit(f32* pSampleBuffer, u32 sampleNum, u32 unit_num);
    void computeSingleUnit(f32* * ppSampleBuffer, u32 sampleNum, u32 unit_num);
    cSoundMultiBandEQ();
    virtual ~cSoundMultiBandEQ();
    void setChannelNum(u32 num);
    void setBypass(bool b);
    void setEnable(bool b);
    bool getBypass() const;
    bool getEnable() const;
    bool isAnyEnable() const;
    void setLowEnable(bool b);
    void setLowFreq(f32 freq);
    void setLowGain(f32 gain);
    void setLowQ(f32 q);
    bool getLowEnable() const;
    f32 getLowFreq() const;
    f32 getLowGain() const;
    f32 getLowQ() const;
    void setLowType(EQ_FILTER_TYPE type);
    EQ_FILTER_TYPE getLowType() const;
    void setMidLowEnable(bool b);
    void setMidLowFreq(f32 freq);
    void setMidLowGain(f32 gain);
    void setMidLowQ(f32 q);
    bool getMidLowEnable() const;
    f32 getMidLowFreq() const;
    f32 getMidLowGain() const;
    f32 getMidLowQ() const;
    void setMidHighEnable(bool b);
    void setMidHighFreq(f32 freq);
    void setMidHighGain(f32 gain);
    void setMidHighQ(f32 q);
    bool getMidHighEnable() const;
    f32 getMidHighFreq() const;
    f32 getMidHighGain() const;
    f32 getMidHighQ() const;
    void setHighEnable(bool b);
    void setHighFreq(f32 freq);
    void setHighGain(f32 gain);
    void setHighQ(f32 q);
    bool getHighEnable() const;
    f32 getHighFreq() const;
    f32 getHighGain() const;
    f32 getHighQ() const;
    void setHighType(EQ_FILTER_TYPE type);
    EQ_FILTER_TYPE getHighType() const;
    void setLowUnit(bool enable, EQ_FILTER_TYPE type, f32 freq, f32 gain, f32 q);
    void setMidLowUnit(bool enable, f32 freq, f32 gain, f32 q);
    void setMidHighUnit(bool enable, f32 freq, f32 gain, f32 q);
    void setHighUnit(bool enable, EQ_FILTER_TYPE type, f32 freq, f32 gain, f32 q);
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
public:
    MtVector4 mCoefficient[5];  // offset: 0x10
    MtVector4 mPastData[8][4];  // offset: 0x60
    MtVector4 mFreq;  // offset: 0x260
    MtVector4 mGain;  // offset: 0x270
    MtVector4 mQ;  // offset: 0x280
    u32 mChannelNum;  // offset: 0x290
    bool mBypass;  // offset: 0x294
    bool mEnable;  // offset: 0x295
    u32 mUnitEnable;  // offset: 0x298
    EQ_FILTER_TYPE mLowType;  // offset: 0x29c
    EQ_FILTER_TYPE mHighType;  // offset: 0x2a0
private:
    static const f32 FEEDBACK_EPSILON;
    static const u32 BASE_FREQUENCY;
public:
    static MyDTI DTI;
    static s32 mEnableUnitTable[16];
};
