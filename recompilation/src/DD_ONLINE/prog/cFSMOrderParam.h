#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../XFramework/cAIUserProcess.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;

// Declarations
class cFSMOrderParam;
class cFSMOrderParamCamera;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cFSMOrderParam : public cAICopiableParameter
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
public:
    static MyDTI DTI;
};

class cFSMOrderParamCamera : public cFSMOrderParam
{
public:
    enum
    {
        CAM_TYPE_WITH_FADE = 0,
        CAM_TYPE_WITHOUT_FADE = 1,
        CAM_TYPE_ENEMY = 2,
    };
    enum
    {
        CAM_ACT_START = 0,
        CAM_ACT_END = 1,
        CAM_ACT_ONCE = 2,
    };
    enum
    {
        CAM_RES_STAGE = 0,
        CAM_RES_EVENT = 1,
    };
    enum
    {
        SET_POS_NO = 0,
        SET_POS_MANUAL = 1,
        SET_POS_STARTPOS = 2,
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
    cFSMOrderParamCamera();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
public:
    s32 mCamId;  // offset: 0x8
    u8 mCamType;  // offset: 0xc
    u8 mActType;  // offset: 0xd
    u8 mCamRes;  // offset: 0xe
    bool mCantActPl;  // offset: 0xf
    bool mIsFsmEvent;  // offset: 0x10
    bool mIsSelfDisplayed;  // offset: 0x11
    bool mIsEnemyAndNpcDisplayed;  // offset: 0x12
    bool mIsMessageCleared;  // offset: 0x13
    bool mIsSelfStopped;  // offset: 0x14
    u8 mSetPosType;  // offset: 0x15
    u32 mStartPosNo;  // offset: 0x18
    f32 mPlStopTime;  // offset: 0x1c
    static MyDTI DTI;
};

inline void* cFSMOrderParam::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cFSMOrderParamCamera::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
