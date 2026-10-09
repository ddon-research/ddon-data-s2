#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cOcdBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cHitInfoAfter;
namespace nObjCondition { struct stHolyAbsorpReqMsg; }
class uDDOModel;

// Declarations
class cOcdHolyAbsorp;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class cOcdHolyAbsorp : public cOcdBase
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
    cOcdHolyAbsorp();
    virtual ~cOcdHolyAbsorp();
    virtual void init(bool initFlag);  // vtable slot 9
    virtual void move();  // vtable slot 10
    virtual void final();  // vtable slot 11
    virtual void update();  // vtable slot 14
    virtual void callbackDamage(cHitInfoAfter* pHitInfo);  // vtable slot 21
    static bool isWhiteHpDamage(uDDOModel* pModel);
    static bool isHpAbsorpAble(uDDOModel* pModel);
private:
    void checkHolyAbsorp(cHitInfoAfter* pHitInfo);
    bool createAbsorpReqMsg(nObjCondition::stHolyAbsorpReqMsg& outMsg, cHitInfoAfter* pHitInfo) const;
    u16 calcHealVal(cHitInfoAfter* pHitInfo) const;
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cOcdHolyAbsorp::cOcdHolyAbsorp() {
}
