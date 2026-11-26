#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "uShlAlchemyTrap.h"
#include "uShlBase.h"
#include "uShlEnchant.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cEfcHandle;
class cHitInfo;
class cShlParamBase;
class uShlAlchemyTrapAttack;
class uShlBase;
class uShlEnchant;

// Declarations
template <typename shlclass, typename ParentClass> class cShlParamAlchemCol;
template <typename ParentClass> class uShlAlchemCol;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

template <>
class cShlParamAlchemCol<uShlAlchemCol<uShlBase>, cShlParamBase> : public cShlParamBase
{
public:
    enum AL_SHL_OPTION
    {
        ASO_ATTACK_SHL_CONST = 1,
    };
public:
    class MyDTI;
public:
    using ThisClass = cShlParamAlchemCol<uShlAlchemCol<uShlBase>, cShlParamBase>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    static void usage();
    virtual const MtDTI& getDTI() const;  // vtable slot 5
    static MtAllocator* getAllocator();
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete(void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
    virtual MtDTI& getShlDTI() const;  // vtable slot 6
    cShlParamAlchemCol();
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createPropertyEffect(MtPropertyList& s);  // vtable slot 8
public:
    bool mFlgUseAreaEffect;  // offset: 0x160
    u32 mAreaEffectTime;  // offset: 0x164
    u32 mAlchemyShlOption;  // offset: 0x168
    s32 mAttackShlNo;  // offset: 0x16c
    static MyDTI DTI;
};

template <>
class cShlParamAlchemCol<uShlAlchemCol<uShlEnchant>, cShlParamEnchant> : public cShlParamEnchant
{
public:
    enum AL_SHL_OPTION
    {
        ASO_ATTACK_SHL_CONST = 1,
    };
public:
    class MyDTI;
public:
    using ThisClass = cShlParamAlchemCol<uShlAlchemCol<uShlEnchant>, cShlParamEnchant>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    static void usage();
    virtual const MtDTI& getDTI() const;  // vtable slot 5
    static MtAllocator* getAllocator();
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete(void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
    virtual MtDTI& getShlDTI() const;  // vtable slot 6
    cShlParamAlchemCol();
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createPropertyEffect(MtPropertyList& s);  // vtable slot 8
public:
    bool mFlgUseAreaEffect;  // offset: 0x1cc
    u32 mAreaEffectTime;  // offset: 0x1d0
    u32 mAlchemyShlOption;  // offset: 0x1d4
    s32 mAttackShlNo;  // offset: 0x1d8
    static MyDTI DTI;
};

template <>
class cShlParamAlchemCol<uShlAlchemCol<uShlAlchemyTrapAttack>, cShlParamAlchemyTrapAttack> : public cShlParamAlchemyTrapAttack
{
public:
    enum AL_SHL_OPTION
    {
        ASO_ATTACK_SHL_CONST = 1,
    };
public:
    class MyDTI;
public:
    using ThisClass = cShlParamAlchemCol<uShlAlchemCol<uShlAlchemyTrapAttack>, cShlParamAlchemyTrapAttack>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    static void usage();
    virtual const MtDTI& getDTI() const;  // vtable slot 5
    static MtAllocator* getAllocator();
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete(void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
    virtual MtDTI& getShlDTI() const;  // vtable slot 6
    cShlParamAlchemCol();
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createPropertyEffect(MtPropertyList& s);  // vtable slot 8
public:
    bool mFlgUseAreaEffect;  // offset: 0x160
    u32 mAreaEffectTime;  // offset: 0x164
    u32 mAlchemyShlOption;  // offset: 0x168
    s32 mAttackShlNo;  // offset: 0x16c
    static MyDTI DTI;
};

template <>
class uShlAlchemCol<uShlAlchemyTrapAttack> : public uShlAlchemyTrapAttack
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
    static void usage();
    virtual const MtDTI& getDTI() const;  // vtable slot 5
    static MtAllocator* getAllocator();
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete(void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
    uShlAlchemCol();
    virtual ~uShlAlchemCol();
    virtual void setup();  // vtable slot 6
    virtual void updateSub();  // vtable slot 175
    virtual void kill();  // vtable slot 16
    virtual void callbackAttack(cHitInfo* pHitInfo);  // vtable slot 83
    virtual void updateEfcHandle();  // vtable slot 58
private:
    void callbackAttackJob09(cHitInfo* pHitInfo);
public:
    cEfcHandle* mpEfcAreaHandle;  // offset: 0x2ac8
    static MyDTI DTI;
};

inline cShlParamAlchemCol<uShlAlchemCol<uShlBase>, cShlParamBase>::cShlParamAlchemCol() : mFlgUseAreaEffect(false), mAreaEffectTime(0u), mAlchemyShlOption(0u), mAttackShlNo(-1) {
}

inline cShlParamAlchemCol<uShlAlchemCol<uShlEnchant>, cShlParamEnchant>::cShlParamAlchemCol() : mFlgUseAreaEffect(false), mAreaEffectTime(0u), mAlchemyShlOption(0u), mAttackShlNo(-1) {
}

inline cShlParamAlchemCol<uShlAlchemCol<uShlAlchemyTrapAttack>, cShlParamAlchemyTrapAttack>::cShlParamAlchemCol() : mFlgUseAreaEffect(false), mAreaEffectTime(0u), mAlchemyShlOption(0u), mAttackShlNo(-1) {
}

template <>
class uShlAlchemCol<uShlBase> : public uShlBase
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
    static void usage();
    virtual const MtDTI& getDTI() const;  // vtable slot 5
    static MtAllocator* getAllocator();
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete(void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
    uShlAlchemCol();
    virtual ~uShlAlchemCol();
    virtual void setup();  // vtable slot 6
    virtual void updateSub();  // vtable slot 175
    virtual void kill();  // vtable slot 16
    virtual void callbackAttack(cHitInfo* pHitInfo);  // vtable slot 83
    virtual void updateEfcHandle();  // vtable slot 58
private:
    void callbackAttackJob09(cHitInfo* pHitInfo);
public:
    cEfcHandle* mpEfcAreaHandle;  // offset: 0x2ab0
    static MyDTI DTI;
};

template <>
class uShlAlchemCol<uShlEnchant> : public uShlEnchant
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
    static void usage();
    virtual const MtDTI& getDTI() const;  // vtable slot 5
    static MtAllocator* getAllocator();
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete(void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
    uShlAlchemCol();
    virtual ~uShlAlchemCol();
    virtual void setup();  // vtable slot 6
    virtual void updateSub();  // vtable slot 175
    virtual void kill();  // vtable slot 16
    virtual void callbackAttack(cHitInfo* pHitInfo);  // vtable slot 83
    virtual void updateEfcHandle();  // vtable slot 58
private:
    void callbackAttackJob09(cHitInfo* pHitInfo);
public:
    cEfcHandle* mpEfcAreaHandle;  // offset: 0x2ab8
    static MyDTI DTI;
};
