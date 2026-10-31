#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObject;
class rGUI;

// Declarations
class uGUIShakeStick;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class uGUIShakeStick : public uGUIBase
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
    uGUIShakeStick();
    virtual ~uGUIShakeStick();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    void setCount(s32 count, s32 countMax);
    void setSuccess();
    void setFailure();
    void setDefault();
    void setHide();
private:
    void updateInit();
    void updateHide();
    void updateWait();
    void updateSuccess();
    void updateFailure();
    void updateDefault();
    void updateExit();
    void updateDisp();
    void setActPltType(u8 actPltType);
    void updateActPltType();
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    cGUIObject* mpOBJ_fix_gauge_f_gauge;  // offset: 0x8d0
    cGUIInstAnimation* mpInstAnim_gauge;  // offset: 0x8d8
    cGUIInstAnimation* mpInstAnim_lever;  // offset: 0x8e0
    f32 mCurrent;  // offset: 0x8e8
    u8 mActPltType;  // offset: 0x8ec
    cGUIInstNull* mpINST_Null_charges;  // offset: 0x8f0
    uGUIBase::cReferenceUIChargesInfo mChargesInfo;  // offset: 0x8f8
public:
    static MyDTI DTI;
};
