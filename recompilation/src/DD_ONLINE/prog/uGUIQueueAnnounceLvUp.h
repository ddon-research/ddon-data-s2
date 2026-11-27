#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtString.h"
#include "uGUIQueueAnnounce.h"

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
class uGUIQueueAnnounceLvUp;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIQueueAnnounceLvUp : public uGUIQueueAnnounce
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
    uGUIQueueAnnounceLvUp();
    virtual ~uGUIQueueAnnounceLvUp();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    void setCraftRank(u32 rank);
    void setupVisible();
private:
    void updateInit();
    void updateIn();
    void updateWait();
    void updateOut();
    void updateExit();
private:
    rGUI* mpGUIRes;  // offset: 0xaf8
    cGUIInstNull* mpINST_Null;  // offset: 0xb00
    cGUIInstAnimation* mpINST_msg_joblv;  // offset: 0xb08
    cGUIObjMessage* mpOBJ_msg_joblv_m_lvup;  // offset: 0xb10
    cGUIObjTexture* mpOBJ_msg_joblv_craft;  // offset: 0xb18
    cGUIObjTexture* mpOBJ_msg_joblv_symbol00;  // offset: 0xb20
    u32 mCraftRank;  // offset: 0xb28
    MtStringEx<32> mLevelName;  // offset: 0xb2c
public:
    static MyDTI DTI;
private:
    static const u32 FADECOUNTCHK_SEC = 3;
};

inline void* uGUIQueueAnnounceLvUp::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* uGUIQueueAnnounceLvUp::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::uGUIQueueAnnounceLvUp::DTI);
}

inline void uGUIQueueAnnounceLvUp::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIQueueAnnounceLvUp::DTI)->memFree(p_addr);
}
