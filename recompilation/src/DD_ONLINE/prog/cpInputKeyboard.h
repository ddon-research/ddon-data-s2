#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "cpComponent.h"
#include "cpInput.h"
#include "../../generated/shared/nKeyCustom.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cpInput;

// Declarations
class cpInputKeyboard;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cpInputKeyboard : public cpComponent
{
public:
    class MyDTI;
    union unMovePrio;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    union unMovePrio
    {
    public:
        struct
        {
        public:
            u8 forward : 1;  // offset: 0x0
            u8 backward : 1;  // offset: 0x0
            u8 left : 1;  // offset: 0x0
            u8 right : 1;  // offset: 0x0
            u8 padding : 4;  // offset: 0x0
        };  // offset: 0x0
        u8 prio;  // offset: 0x0
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
    cpInputKeyboard();
    virtual ~cpInputKeyboard();
    virtual void setup();  // vtable slot 6
    virtual void updatePtr();  // vtable slot 9
    void updateInputInfo(cpInput* pInput);
protected:
    void checkDash(cpInput::unBtnInfo trg);
protected:
    u32 mDashRno;  // offset: 0x50
    f32 mDashKeyTimer;  // offset: 0x54
    nKeyCustom::KB_CUSTOM mDashKey;  // offset: 0x58
private:
    bool mTrgDash;  // offset: 0x5c
    bool mOnDash;  // offset: 0x5d
    bool mRelDash;  // offset: 0x5e
    unMovePrio mTrgMove;  // offset: 0x5f
    unMovePrio mOnMove;  // offset: 0x60
public:
    static MyDTI DTI;
};

inline void* cpInputKeyboard::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
