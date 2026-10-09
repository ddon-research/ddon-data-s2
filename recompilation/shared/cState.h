#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtProperty;
class MtPropertyList;
class MtUI;
class uDDOModel;

// Declarations
class cState;
class cStateInfo;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
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
    // Address: 0x01a62c00 - 0x01a62c01 (1 bytes)
    virtual ~cStateInfo() {}
    s32 getState();
    const MtDTI* getDTI();
private:
    s32 State;  // offset: 0x8
    const MtDTI* pDTI;  // offset: 0x10
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline s32 cState::getStateNo() {
    return this->mStateNo;
}
