#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "uHuman.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector3;
class cEfcHandle;

// Declarations
class uPlayer;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class uPlayer : public uHuman
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
    uPlayer();
    virtual ~uPlayer();
    virtual void setup();  // vtable slot 6
    virtual void createComponent();  // vtable slot 43
    virtual void setupComponentPtr();  // vtable slot 44
    void before();
    void update();
    virtual void kill();  // vtable slot 16
    virtual const MtVector3 getDefaultTargetPos();  // vtable slot 67
    void setIsTargetIconOff(bool flg);
    bool isTargetIconOff() const;
    virtual void updateEfcHandle();  // vtable slot 58
private:
    bool mIsDying;  // offset: 0x376c
    cEfcHandle* mpDyingEfcHandle;  // offset: 0x3770
    bool mIsTargetIconOff;  // offset: 0x3778
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline uPlayer::uPlayer() {
    this->::uHuman::mpKeyCommand = static_cast<cpKeyCommand*>(nullptr);
    this->::uDDOModel::mUnitId = this->::uDDOModel::mUnitId | static_cast<u32>(8);
    this->mpDyingEfcHandle = static_cast<cEfcHandle*>(nullptr);
    this->mIsDying = false;
    this->::uHuman::mIsUpdateAbility = true;
    this->mIsTargetIconOff = false;
}
