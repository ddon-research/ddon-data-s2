#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
class MtDTI;

// Declarations
class cActList;
class cActNetParam;
class cActParam;

// Type aliases from DWARF
using f32 = float;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class cActNetParam
{
public:
    cActNetParam();
    cActNetParam(u8 interpolate, u8 msg, u8 periodic, u8 pri);
    const cActNetParam& operator=(const cActNetParam& src);
    u8 getInterpolateType() const;
    void setInterpolateType(u8 NewValue);
    u8 getMsg() const;
    void setMsg(u8 NewValue);
    u8 getPeriodic() const;
    void setPeriodic(u8 NewValue);
    u8 getPriority() const;
    void setPriority(u8 NewValue);
private:
    u8 mInterpolateType;  // offset: 0x0
    u8 mMsg;  // offset: 0x1
    u8 mPeriodic;  // offset: 0x2
    u8 mPriority;  // offset: 0x3
};

class cActParam
{
public:
    cActParam();
    cActParam(u32 param0, u32 param1, u32 param2, u32 param3, f32 param4, f32 param5, f32 param6, f32 param7, u16 bitwork, u16 turnType, f32 rotSpeed);
    const cActParam& operator=(const cActParam& src);
    u32 getUParam0() const;
    u32 getUParam1() const;
    u32 getUParam2() const;
    u32 getUParam3() const;
    f32 getFParam0() const;
    f32 getFParam1() const;
    f32 getFParam2() const;
    f32 getFParam3() const;
    u32 getMotNo0() const;
    u32 getMotNo1() const;
    u32 getNextAction() const;
    u32 getDmDetailType() const;
    u32 getParam0() const;
    void setParam0(u32 NewValue);
    u32 getParam1() const;
    void setParam1(u32 NewValue);
    u32 getParam2() const;
    void setParam2(u32 NewValue);
    u32 getParam3() const;
    void setParam3(u32 NewValue);
    f32 getParam4() const;
    void setParam4(f32 NewValue);
    f32 getParam5() const;
    void setParam5(f32 NewValue);
    f32 getParam6() const;
    void setParam6(f32 NewValue);
    f32 getParam7() const;
    void setParam7(f32 NewValue);
    u16 getBitWork() const;
    void setBitWork(u16 NewValue);
    u16 getTurnType() const;
    void setTurnType(u16 NewValue);
    f32 getRotSpeed() const;
    void setRotSpeed(f32 NewValue);
private:
    u32 mParam0;  // offset: 0x0
    u32 mParam1;  // offset: 0x4
    u32 mParam2;  // offset: 0x8
    u32 mParam3;  // offset: 0xc
    f32 mParam4;  // offset: 0x10
    f32 mParam5;  // offset: 0x14
    f32 mParam6;  // offset: 0x18
    f32 mParam7;  // offset: 0x1c
    u16 mBitWork;  // offset: 0x20
    u16 mTurnType;  // offset: 0x22
    f32 mRotSpeed;  // offset: 0x24
};

class cActList
{
public:
    cActList(const MtDTI* pDTI, u16 state, cActParam param, cActNetParam net_param);
    const MtDTI* getDtiPtr() const;
    void setDtiPtr(const MtDTI* NewValue);
    u32 getState() const;
    void setState(u32 NewValue);
private:
    const MtDTI* mpDTI;  // offset: 0x0
    u16 mState;  // offset: 0x8
public:
    cActParam mParam;  // offset: 0xc
    cActNetParam mNetParam;  // offset: 0x34
};
