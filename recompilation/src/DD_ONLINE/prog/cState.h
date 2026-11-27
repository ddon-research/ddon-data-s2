#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "nDDOUtility.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class uDDOModel;

// Declarations
class cState;
class cStateAction;
class cStateInfo;
class cStateLive;
class cStateLiveAlive;
class cStateLiveInjured;
class cStateLiveLost;
class cStateLiveLostEnd;
class cStateLiveReturnTerritory;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class cState : public MtObject
{
public:
    enum STATE_LIVE
    {
        STATE_ALIVE = 512,
        STATE_INJURED = 513,
        STATE_LOST = 514,
        STATE_LOST_END = 515,
        STATE_RETURN_TERRITORY = 516,
    };
    enum STATE_ACTION
    {
        STATE_DEFAULT = 256,
        STATE_GROUND = 257,
        STATE_AIR = 258,
        STATE_CLIFF = 259,
        STATE_ENEMY_CLIMB = 260,
        STATE_DEAD = 261,
        STATE_CLUTCH = 262,
        STATE_CLUTCHED = 263,
        STATE_CATCH = 264,
        STATE_CAUGHT = 265,
        STATE_TAIMA_KENSEIZAN = 266,
        STATE_JOB02_WIRE = 267,
        STATE_DUMMY_12 = 268,
        STATE_JOB05_GUARD = 269,
        STATE_HOVER = 270,
        STATE_FLIGHT = 271,
        STATE_STAMINA_OUT = 272,
        STATE_JOB07_BASE_L = 273,
        STATE_WALL_CLIMB = 274,
        STATE_JOB07_ENDURE = 275,
        STATE_JOB01_BASE_L = 276,
        STATE_BOW = 277,
        STATE_SLIP_SLOPE = 278,
        STATE_JOB05_PROVOKE = 279,
        STATE_BRING_OBJECT = 280,
        STATE_CATAPULT = 281,
        STATE_SIT_CHAIR = 282,
        STATE_DODGE_ACTION = 283,
        STATE_JOB04_CIRCLE_CHANT = 284,
        STATE_PUT_LEVER = 285,
        STATE_CLIMB_LADDER = 286,
        STATE_MAGIC_CHANT = 287,
        STATE_JOB01_GUARD = 288,
        STATE_JOB05_ELEMENT_CHANGE_A = 289,
        STATE_JOB05_ELEMENT_CHANGE_B = 290,
        STATE_MAGIC_SHOT = 291,
        STATE_JOB02_CS_01 = 292,
        STATE_JOB05_CS_08 = 293,
        STATE_JOB04_CIRCLE_SHIFT = 294,
        STATE_JOB05_CS_12 = 295,
        STATE_JOB07_CS_11 = 296,
        STATE_JOB09_CS_05 = 297,
        STATE_JOB09_CS_08 = 298,
        STATE_JOB05_CS_13 = 299,
        STATE_JOB10_LIMIT_BREAK = 300,
        STATE_DUMMY_45 = 301,
        STATE_DUMMY_46 = 302,
        STATE_DUMMY_47 = 303,
        STATE_DUMMY_48 = 304,
        STATE_DUMMY_49 = 305,
        STATE_DUMMY_50 = 306,
        STATE_DUMMY_51 = 307,
        STATE_DUMMY_52 = 308,
        STATE_DUMMY_53 = 309,
        STATE_DUMMY_54 = 310,
        STATE_DUMMY_55 = 311,
        STATE_DUMMY_56 = 312,
        STATE_DUMMY_57 = 313,
        STATE_DUMMY_58 = 314,
        STATE_DUMMY_59 = 315,
        STATE_DUMMY_60 = 316,
        STATE_DUMMY_61 = 317,
        STATE_DUMMY_62 = 318,
        STATE_DUMMY_63 = 319,
        STATE_DUMMY_64 = 320,
        STATE_DUMMY_65 = 321,
        STATE_DUMMY_66 = 322,
        STATE_DUMMY_67 = 323,
        STATE_DUMMY_68 = 324,
        STATE_DUMMY_69 = 325,
        STATE_DUMMY_70 = 326,
        STATE_DUMMY_71 = 327,
        STATE_DUMMY_72 = 328,
        STATE_DUMMY_73 = 329,
        STATE_DUMMY_74 = 330,
        STATE_DUMMY_75 = 331,
        STATE_DUMMY_76 = 332,
        STATE_DUMMY_77 = 333,
        STATE_DUMMY_78 = 334,
        STATE_DUMMY_79 = 335,
        STATE_DUMMY_80 = 336,
        STATE_DUMMY_81 = 337,
        STATE_DUMMY_82 = 338,
        STATE_DUMMY_83 = 339,
        STATE_DUMMY_84 = 340,
        STATE_DUMMY_85 = 341,
        STATE_DUMMY_86 = 342,
        STATE_DUMMY_87 = 343,
        STATE_DUMMY_88 = 344,
        STATE_DUMMY_89 = 345,
        STATE_DUMMY_90 = 346,
        STATE_DUMMY_91 = 347,
        STATE_DUMMY_92 = 348,
        STATE_DUMMY_93 = 349,
        STATE_DUMMY_94 = 350,
        STATE_DUMMY_95 = 351,
        STATE_DUMMY_96 = 352,
        STATE_DUMMY_97 = 353,
        STATE_DUMMY_98 = 354,
        STATE_DUMMY_99 = 355,
        STATE_DUMMY_100 = 356,
        STATE_DUMMY_101 = 357,
        STATE_DUMMY_102 = 358,
        STATE_DUMMY_103 = 359,
        STATE_DUMMY_104 = 360,
        STATE_DUMMY_105 = 361,
        STATE_DUMMY_106 = 362,
        STATE_DUMMY_107 = 363,
        STATE_DUMMY_108 = 364,
        STATE_DUMMY_109 = 365,
        STATE_DUMMY_110 = 366,
        STATE_DUMMY_111 = 367,
        STATE_DUMMY_112 = 368,
        STATE_DUMMY_113 = 369,
        STATE_DUMMY_114 = 370,
        STATE_DUMMY_115 = 371,
        STATE_DUMMY_116 = 372,
        STATE_DUMMY_117 = 373,
        STATE_DUMMY_118 = 374,
        STATE_DUMMY_119 = 375,
        STATE_DUMMY_120 = 376,
        STATE_DUMMY_121 = 377,
        STATE_DUMMY_122 = 378,
        STATE_DUMMY_123 = 379,
        STATE_DUMMY_124 = 380,
        STATE_DUMMY_125 = 381,
        STATE_DUMMY_126 = 382,
        STATE_DUMMY_127 = 383,
        STATE_ACTION_COMMON_NUM = 384,
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
    cState();
    virtual ~cState();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    s32 getStateNo();
    void setStateNo(s32 state);
    s32 getNextState();
    void setNextState(s32 state);
    virtual void init();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void final();  // vtable slot 8
public:
    uDDOModel* mpModel;  // offset: 0x8
private:
    s32 mStateNo;  // offset: 0x10
    s32 mNextState;  // offset: 0x14
public:
    static MyDTI DTI;
};

class cStateAction : public cState
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
    cStateAction();
    virtual ~cStateAction() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    u32 mDefaultEndAction;  // offset: 0x18
    u32 mDefaultLandAction;  // offset: 0x1c
    u32 mDefaultFallAction;  // offset: 0x20
    u32 mDefaultBlowAction;  // offset: 0x24
    u32 mDefaultShrinkAction;  // offset: 0x28
    static MyDTI DTI;
};

class cStateInfo : public MtObject
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
    cStateInfo();
    cStateInfo(s32 state, const MtDTI* pDti);
    virtual ~cStateInfo() {}
    s32 getState();
    const MtDTI* getDTI();
private:
    s32 State;  // offset: 0x8
    const MtDTI* pDTI;  // offset: 0x10
public:
    static MyDTI DTI;
};

class cStateLive : public cState
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
    cStateLive();
    virtual ~cStateLive() {}
public:
    static MyDTI DTI;
};

class cStateLiveAlive : public cStateLive
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
    cStateLiveAlive();
    virtual ~cStateLiveAlive() {}
public:
    static MyDTI DTI;
};

class cStateLiveInjured : public cStateLive
{
public:
    class MyDTI;
public:
    using u32Array = nDDOUtility::cArray<unsigned int, 8>;
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
    cStateLiveInjured();
    virtual ~cStateLiveInjured() {}
    virtual void init();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void final();  // vtable slot 8
    void addInjurePlayer(u32 newId);
private:
    f32 checkIsInjured();
    void checkAbility();
public:
    f32 getNowResPawnTime();
    f32 getNeedResPawnTime();
    f32 getMaxResPawnTime();
private:
    f32 mNeedRespawnTimer;  // offset: 0x18
    f32 mMaxRespawnTimer;  // offset: 0x1c
    f32 mTimerRate;  // offset: 0x20
    u32Array mUniqueId;  // offset: 0x24
    bool mIsRescuing;  // offset: 0x44
    bool mActionSwitch;  // offset: 0x45
    u32 mRno;  // offset: 0x48
public:
    static MyDTI DTI;
private:
    static const u16 MAX_PLAYER = 8;
    static const u16 MAX_GAGE = 1000;
};

class cStateLiveLost : public cStateLive
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
    cStateLiveLost();
    virtual ~cStateLiveLost() {}
    virtual void init();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void final();  // vtable slot 8
public:
    f32 mTimer;  // offset: 0x18
    static MyDTI DTI;
};

class cStateLiveLostEnd : public cStateLive
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
    cStateLiveLostEnd();
    virtual ~cStateLiveLostEnd() {}
    virtual void init();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void final();  // vtable slot 8
public:
    static MyDTI DTI;
};

class cStateLiveReturnTerritory : public cStateLive
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
    cStateLiveReturnTerritory();
    virtual ~cStateLiveReturnTerritory() {}
    virtual void init();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void final();  // vtable slot 8
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
private:
    u32 mStateRno;  // offset: 0x18
public:
    static MyDTI DTI;
};

inline void* cState::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline s32 cState::getStateNo() {
    return this->mStateNo;
}

inline void* cStateAction::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cStateInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cStateInfo::cStateInfo() {
    this->State = 0;
    this->pDTI = nullptr;
}

inline void* cStateLive::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cStateLive::cStateLive() {
}

inline void* cStateLiveAlive::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cStateLiveAlive::cStateLiveAlive() {
}

inline void* cStateLiveInjured::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cStateLiveInjured::cStateLiveInjured() {
}

inline void* cStateLiveLost::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cStateLiveLost::cStateLiveLost() {
}

inline void* cStateLiveLostEnd::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cStateLiveLostEnd::cStateLiveLostEnd() {
}

inline void* cStateLiveReturnTerritory::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cStateLiveReturnTerritory::cStateLiveReturnTerritory() {
    this->mStateRno = 0;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void cState::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cState::DTI)->memFree(p_addr);
}

inline void* cStateAction::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cStateAction::DTI)->memAlloc(sz, align, ::cStateAction::DTI.::MtDTI::getID());
}

inline void cStateAction::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cStateAction::DTI)->memFree(p_addr);
}

inline MtAllocator* cStateInfo::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::cStateInfo::DTI);
}

inline void cStateInfo::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cStateInfo::DTI)->memFree(p_addr);
}

inline void* cStateLiveAlive::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cStateLiveAlive::DTI)->memAlloc(sz, align, ::cStateLiveAlive::DTI.::MtDTI::getID());
}

inline void cStateLiveAlive::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cStateLiveAlive::DTI)->memFree(p_addr);
}

inline void* cStateLiveInjured::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cStateLiveInjured::DTI)->memAlloc(sz, align, ::cStateLiveInjured::DTI.::MtDTI::getID());
}

inline void cStateLiveInjured::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cStateLiveInjured::DTI)->memFree(p_addr);
}

inline void* cStateLiveLost::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cStateLiveLost::DTI)->memAlloc(sz, align, ::cStateLiveLost::DTI.::MtDTI::getID());
}

inline void cStateLiveLost::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cStateLiveLost::DTI)->memFree(p_addr);
}

inline void* cStateLiveLostEnd::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cStateLiveLostEnd::DTI)->memAlloc(sz, align, ::cStateLiveLostEnd::DTI.::MtDTI::getID());
}

inline void cStateLiveLostEnd::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cStateLiveLostEnd::DTI)->memFree(p_addr);
}

inline void* cStateLiveReturnTerritory::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cStateLiveReturnTerritory::DTI)->memAlloc(sz, align, ::cStateLiveReturnTerritory::DTI.::MtDTI::getID());
}

inline void cStateLiveReturnTerritory::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cStateLiveReturnTerritory::DTI)->memFree(p_addr);
}
