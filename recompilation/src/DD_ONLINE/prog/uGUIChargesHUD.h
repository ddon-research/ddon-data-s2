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
class cDraw;
class rGUI;

// Declarations
class uGUIChargesHUD;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIChargesHUD : public uGUIBase
{
public:
    enum CHARGES_DISP_TYPE
    {
        COURSE_DISPLAY = 0,
        EFFECT_DISPLAY = 1,
        DISP_TYPE_NUM = 2,
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
    uGUIChargesHUD();
    virtual ~uGUIChargesHUD();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    virtual void sync();  // vtable slot 11
    void addData(u32 charges, u32 disp_flag, MT_CTSTR edit);
    void addAttribute(u32 attr, u32 disp_flag);
    void deleteData();
    void setUseEffect(bool isUse);
private:
    void updateInit();
    void updateWait();
    void updateExit();
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    uGUIBase::cReferenceUIChargesInfo mRefCharges[2];  // offset: 0x8d0
    bool mIsUseEffect;  // offset: 0xb80
public:
    static MyDTI DTI;
};
