#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../XFramework/cSystem.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class cContextInstance;
class rRoomWearParam;

// Declarations
class sMyRoom;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class sMyRoom : public cSystem
{
public:
    enum
    {
        WEAR_NOTHING = -1,
        WEAR_BATH = 0,
        WEAR_SLEEP = 1,
        DEFAULT_BATH_WEAR = 0,
        DEFAULT_SLEEP_WEAR = 1,
        CAMERA_ROOM_WEAR = 128,
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
    static sMyRoom* getInstance();
    sMyRoom();
    virtual ~sMyRoom();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    void init();
    virtual void move();  // vtable slot 7
    bool isReqPlayerChangeWear(const cContextInstance* pContext);
    bool isChangePlayerWear(u32 category, const cContextInstance* pContext);
    u16 getItemIdPlayerWearNew(u32 category, const cContextInstance* pContext);
    u16 getItemIdPlayerWearNow(u32 category, const cContextInstance* pContext);
    u16 getItemIdPlayerWearSub(u32 category, const cContextInstance* pContext, bool isNow);
    bool isReqPlayerRoomWear(const cContextInstance* pContext);
    bool isPlayerRoomWear(const cContextInstance* pContext);
    void setChangePlayerWear(const cContextInstance* pContext);
    void setRoomWearResource();
    void releaseRoomWearResource();
    u32 getResItemRoomWear(u32 index);
    u32 getResTypeRoomWear(u32 index);
    u16 getResRoomWear(u32 index, u32 category, u32 sex);
    void checkRoomWear(u32 itemId);
    void clearWearInfo();
    void setPawnWear(s32 type);
    s32 getPawnWear();
    s32 getPawnWearNow();
    s32 getPawnWearType();
    bool isPlayerChangeWearRequest();
    bool isPawnChanging();
    bool isPlayerChanging();
private:
    rRoomWearParam* mprRoomWear;  // offset: 0x18
    s32 mPlayerRoomWear;  // offset: 0x20
    s32 mReqPlayerRoomWear;  // offset: 0x24
    s32 mPawnWear;  // offset: 0x28
    s32 mPawnWearType;  // offset: 0x2c
    s32 mPawnRoomWear;  // offset: 0x30
    s32 mPawnSleepWear;  // offset: 0x34
    s32 mPawnBathWear;  // offset: 0x38
public:
    static MyDTI DTI;
private:
    static sMyRoom* mpInstance;
};

inline void* sMyRoom::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline sMyRoom* sMyRoom::getInstance() {
    return ::sMyRoom::mpInstance;
}

inline s32 sMyRoom::getPawnWearNow() {
    return this->mPawnWear;
}

inline s32 sMyRoom::getPawnWearType() {
    return this->mPawnWearType;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* sMyRoom::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::sMyRoom::DTI);
}

inline void sMyRoom::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::sMyRoom::DTI)->memFree(p_addr);
}
