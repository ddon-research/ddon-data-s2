#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../generated/shared/nKeyCustom.h"
#include "uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class cGUIObjTexture;
class rGUI;

// Declarations
class uGUIGaugeSkill;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class uGUIGaugeSkill : public uGUIBase
{
public:
    enum MODE
    {
        MODE_DEFAULT = 0,
        MODE_RENDA = 1,
    };
public:
    class MyDTI;
    struct UpdateParam;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct UpdateParam
    {
    public:
        UpdateParam(u32 seqId, f32 rate, u8 lv, u8 lvMax);
    public:
        u32 mSeqId;  // offset: 0x0
        f32 mRate;  // offset: 0x4
        u8 mLv;  // offset: 0x8
        u8 mLvMax;  // offset: 0x9
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
    uGUIGaugeSkill();
    virtual ~uGUIGaugeSkill();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    void rendaStart(nKeyCustom::KB_CUSTOM keyCustom, bool isIgnoreModifierKey);
    void rendaEnd();
    void rendaUpdate(u32 count, u32 countMax, u32 level, u32 levelMax);
private:
    void updateInit();
    void updateWait();
    void updateExit();
    void updateDisp();
    bool updateModeDefault(UpdateParam& updateParam);
    bool updateModeRenda(UpdateParam& updateParam);
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    cGUIInstNull* mpINST_Null;  // offset: 0x8d0
    cGUIInstNull* mpINST_Null_all;  // offset: 0x8d8
    cGUIInstAnimation* mpINST_fix_charge;  // offset: 0x8e0
    cGUIInstAnimation* mpINST_fix_charges[5];  // offset: 0x8e8
    cGUIInstAnimation* mpINST_fix_gauge;  // offset: 0x910
    cGUIInstAnimation* mpINST_gauge_flash;  // offset: 0x918
    cGUIObjTexture* mpOBJ_fix_gauge_f_gauge;  // offset: 0x920
    cGUIObjTexture* mpOBJ_fix_gauge_f_gaugemax;  // offset: 0x928
    f32 mAlpha;  // offset: 0x930
    f32 mRateLast;  // offset: 0x934
    u8 mLvOld;  // offset: 0x938
    uGUIBase::cInputGuideMonitor mInputGuideMonitor;  // offset: 0x93c
    MODE mMode;  // offset: 0x944
    u32 mRendaCount;  // offset: 0x948
    u32 mRendaCountMax;  // offset: 0x94c
    u32 mRendaLevel;  // offset: 0x950
    u32 mRendaLevelMax;  // offset: 0x954
    nKeyCustom::KB_CUSTOM mRendaKeyCustom;  // offset: 0x958
    bool mIsIgnoreModifierKey;  // offset: 0x95c
    cGUIInstNull* mpINST_Null_push;  // offset: 0x960
    cGUIObjMessage* mpOBJ_push_m_button;  // offset: 0x968
public:
    static MyDTI DTI;
    static const u32 LV_NUM = 5;
};
