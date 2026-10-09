#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class uHuman;

// Declarations
class cJumpParamCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cJumpParamCtrl : public MtObject
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
    void initialize(uHuman* pHuman, u32 bank, u32 jpIndex, bool isCheckLever);
    void initializeY(uHuman* pHuman, u32 bank, u32 jpIndex);
    void initializeMoveRad(uHuman* pHuman, u32 bank, u32 jpIndex);
    void initializeG(uHuman* pHuman, u32 bank, u32 jpIndex);
    void addInitialize(uHuman* pHuman, u32 bank, u32 jpIndex, bool isCheckLever);
    void updateParam(uHuman* pHuman);
    void updatePadAdjustPos(uHuman* pHuman);
private:
    void setupParam(uHuman* pHuman, u32 bank, u32 jpIndex);
public:
    static MyDTI DTI;
};
