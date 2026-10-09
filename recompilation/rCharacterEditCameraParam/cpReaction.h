#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/cpComponent.h"
#include "../shared/nAction.h"
#include "../shared/rReaction.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cHitInfo;
class cHitInfoAfter;
class cReaction;
class rReaction;
class uDDOModel;

// Declarations
class cpReaction;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

class cpReaction : public cpComponent
{
public:
    enum
    {
        FLG_TURN_TO_ATTAKER = 1,
        FLG_DEAD_REACTION = 2,
        FLG_TARGET_CHANGE_ATTACKER = 4,
    };
public:
    class MyDTI;
    class cTriggerFree;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cTriggerFree : public MtObject
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
        cTriggerFree();
        // Address: 0x01981d20 - 0x01981d21 (1 bytes)
        virtual ~cTriggerFree() {}
    public:
        f32 mF32Free;  // offset: 0x8
        u32 mU32Free;  // offset: 0xc
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
    cpReaction();
    virtual ~cpReaction();
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    void setResource(rReaction* pRes);
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void updatePtr();  // vtable slot 9
    bool isChoiceActNo();
    void clearChoiceActNo();
    bool isChoiceOptionFlgOr(u32 flg);
    bool isChoiceOptionFlgAnd(u32);
    void clearChoiceOptionFlg();
    u32 callbackShrink(cHitInfoAfter* pHitInfo);
    u32 callbackBlow(cHitInfoAfter* pHitInfo);
    u32 callbackDown(cHitInfoAfter* pHitInfo);
    u32 callbackShake(cHitInfoAfter* pHitInfo);
    u32 callbackRegionBreak(cHitInfoAfter* pHitInfo);
    u32 callbackRegionHit(cHitInfoAfter* pHitInfo);
    u32 callbackDamageAfter(cHitInfoAfter* pHitInfo);
    u32 callbackYoroyoro(cHitInfoAfter* pHitInfo);
    u32 callbackGuard(cHitInfo* pHitInfo);
private:
    void setTriggerFlag();
    u32 selectReaction(cHitInfoAfter& hitInfo, nAction::REACT_TRG trg);
    bool checkForceReaction(cHitInfoAfter& hitInfo, cReaction* pReact, nAction::REACT_TRG trg);
    u32 requestReaction(cReaction* pReact, u32 index);
    bool isTriggerCheck(cHitInfoAfter& hitInfo, cReaction* pReact, nAction::REACT_TRG trg, u32 index);
    bool checkCondition(cReaction* pReact, cHitInfoAfter& hitInfo);
    bool checkCondAction(cReaction::cCondition& cond);
    bool checkCondObjStatus(cReaction::cCondition& cond);
    bool checkCondMotSequence(cReaction::cCondition& cond);
    bool checkCondLife(cReaction::cCondition& cond);
    bool checkCondCondition(cReaction::cCondition& cond);
    bool checkCondDamageAng(cReaction::cCondition& cond, cHitInfoAfter& hitInfo);
    bool checkCondRegionBreak(cReaction::cCondition& cond);
    bool checkCondObjStatusExt(cReaction::cCondition& cond);
    bool checkCondRage(cReaction::cCondition& cond);
    bool checkCondDistAttacker(cReaction::cCondition& cond, cHitInfoAfter& hitInfo);
public:
    uDDOModel* mpModel;  // offset: 0x50
private:
    rReaction* mprReaction;  // offset: 0x58
    u32 mChoiceActNo;  // offset: 0x60
    u64 mTriggerFlag;  // offset: 0x68
    u32 mChoiceOptionFlg;  // offset: 0x70
    MtTypedArray<cTriggerFree> mTriggerFreeWorkArray;  // offset: 0x78
public:
    static MyDTI DTI;
private:
    static const u64 BIT_REACT_TRG_SHRINK = 2;
    static const u64 BIT_REACT_TRG_BLOW = 4;
    static const u64 BIT_REACT_TRG_DOWN = 8;
    static const u64 BIT_REACT_TRG_TIRED = 16;
    static const u64 BIT_REACT_TRG_REGION_BREAK = 256;
    static const u64 BIT_REACT_TRG_ALL_REGION_BREAK = 512;
    static const u64 BIT_REACT_TRG_REGION_HIT = 1024;
    static const u64 BIT_REACT_TRG_EROSION_BREAK = 65536;
    static const u64 BIT_REACT_TRG_ALL_EROSION_BREAK = 131072;
    static const u64 BIT_REACT_TRG_BIT_TABLE = 4294967296;
    static const u64 BIT_REACT_TRG_YOROYORO = 8589934592;
    static const u64 BIT_REACT_TRG_CONTINUE_DAMAGE = 17179869184;
    static const u64 BIT_REACT_TRG_GUARD = 34359738368;
};

// Inline, no code of its own: checked where it is inlined.
inline cpReaction::cTriggerFree::cTriggerFree() {
    this->mF32Free = 0.0f;
    this->mU32Free = static_cast<u32>(0);
}
