#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class rGUI;
class rSoundRequest;

// Declarations
class uGUIRankUp;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIRankUp : public uGUIBase
{
public:
    enum
    {
        FLOW_NONE = 0,
        FLOW_IN = 1,
        FLOW_WAIT = 2,
        FLOW_OUT = 3,
        FLOW_END = 4,
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
    uGUIRankUp();
    virtual ~uGUIRankUp();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    void setRank(u32 rank);
private:
    void setFlowId(u32 flow_id);
    void updateMove();
    void updateExit();
    void setupIn();
    void updateIn();
    void setupWait();
    void updateWait();
    void setupOut();
    void updateOut();
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    rSoundRequest* mpSeRes;  // offset: 0x8d0
    u32 mFlowId;  // offset: 0x8d8
    cGUIInstNull* mpInstNull;  // offset: 0x8e0
    cGUIInstAnimation* mpInstAnim;  // offset: 0x8e8
    cGUIObjMessage* mpObjMsgNum;  // offset: 0x8f0
    u32 mRank;  // offset: 0x8f8
    f32 mDispFrame;  // offset: 0x8fc
public:
    static MyDTI DTI;
private:
    static const s32 disp_frame = 90;
};
