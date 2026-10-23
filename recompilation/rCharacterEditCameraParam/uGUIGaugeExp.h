#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class cGUIObjTexture;
class rGUI;

// Declarations
class uGUIGaugeExp;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class uGUIGaugeExp : public uGUIBase
{
public:
    enum
    {
        GAUGE_TYPE_NONE = 0,
        GAUGE_TYPE_EXP_DISABLE_PP = 1,
        GAUGE_TYPE_EXP_ENABLE_PP = 2,
        GAUGE_TYPE_PP = 3,
    };
public:
    class MyDTI;
    struct cGaugeInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct cGaugeInfo : public MtObject
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
        cGaugeInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void initGaugeInfo();
    public:
        u64 mExpLatest;  // offset: 0x8
        u16 mLvLatest;  // offset: 0x10
        u8 mJobIdLatest;  // offset: 0x12
        u32 mPlayPointLatest;  // offset: 0x14
        static MyDTI DTI;
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
    uGUIGaugeExp();
    virtual ~uGUIGaugeExp();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
private:
    void updateInit();
    void updateWait();
    void updateExit();
    void setupType(u8 gaugeType);
    void setupExpDisablePP();
    void setupExpEnablePP();
    void setupPp();
    void updateGaugeType();
    void updateExpDisablePP();
    void updateExpEnablePP();
    void updatePp();
    void updateExpGauge();
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    cGaugeInfo mGaugeInfo;  // offset: 0x8d0
    cGUIInstNull* mpInstNull;  // offset: 0x8e8
    cGUIInstNull* mpINST_PL_gauge00;  // offset: 0x8f0
    cGUIInstAnimation* mpINST_msg_fix_gauge;  // offset: 0x8f8
    cGUIObjTexture* mpOBJ_msg_fix_gauge_f_exp;  // offset: 0x900
    cGUIObjMessage* mpOBJ_msg_fix_gauge_m_lv;  // offset: 0x908
    cGUIObjMessage* mpOBJ_msg_fix_gauge_m_num01;  // offset: 0x910
    cGUIObjMessage* mpOBJ_msg_fix_gauge_m_num02;  // offset: 0x918
    cGUIObjMessage* mpOBJ_msg_fix_gauge_m_xp;  // offset: 0x920
    cGUIObjMessage* mpOBJ_msg_fix_gauge_m_p;  // offset: 0x928
    u8 mGaugeType;  // offset: 0x930
    bool mIsLevelMax;  // offset: 0x931
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline uGUIGaugeExp::cGaugeInfo::cGaugeInfo() {
    this->mExpLatest = static_cast<u64>(-1);
    this->mLvLatest = static_cast<u16>(65535);
    this->mJobIdLatest = static_cast<u8>(255);
    this->mPlayPointLatest = static_cast<u32>(4294967295);
}
