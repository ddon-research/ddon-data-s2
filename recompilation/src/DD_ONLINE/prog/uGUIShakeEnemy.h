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
class cGUIInstance;
class cGUIObjMessage;
class rGUI;

// Declarations
class uGUIShakeEnemy;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIShakeEnemy : public uGUIBase
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
    uGUIShakeEnemy();
    virtual ~uGUIShakeEnemy();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
private:
    void updateInit();
    void updateWait();
    void updateExit();
    void updateDisp();
    void updateActPltType();
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    cGUIInstance* mpInstNullD;  // offset: 0x8d0
    cGUIInstAnimation* mpInstButton;  // offset: 0x8d8
    cGUIObjMessage* mpOBJ_btn_m_btn_txt;  // offset: 0x8e0
    bool mExecute;  // offset: 0x8e8
    uGUIBase::cInputGuideMonitor mInputGuideMonitor;  // offset: 0x8ec
public:
    static MyDTI DTI;
};
