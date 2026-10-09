#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "cAction.h"
#include "uDDOModel.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector3;
class cArcLoaderBase;
class cEfcHandle;

// Declarations
class uAnimal;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using TICKET = cArcLoaderBase*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class uAnimal : public uDDOModel
{
public:
    enum
    {
        ANML_TYPE_NONE = 0,
        ANML_TYPE_DEER_MALE = 1,
        ANML_TYPE_DEER_FEMALE = 2,
        ANML_TYPE_RABBIT = 3,
        ANML_TYPE_COW = 4,
        ANML_TYPE_COW_BIG = 5,
        ANML_TYPE_BUTI_PIG = 6,
        ANML_TYPE_BUTI_PIG_CHILD = 7,
        ANML_TYPE_RABBIT_EMO = 8,
        ANML_TYPE_GRIFFIN = 9,
        ANML_TYPE_MAX = 10,
    };
    enum
    {
        R0_MOVE_INIT = 0,
        R0_MOVE_ARC_WAIT = 1,
        R0_MOVE_SET_RES = 2,
        R0_MOVE_MAIN = 3,
    };
    enum
    {
        ACT_INVALID = 0,
        ACT_FOOTWORK = 1,
        ACT_WALK = 2,
        ACT_RUN = 3,
        ACT_TURN = 4,
        ACT_COLLAPSE = 5,
        ACT_ESCAPE = 6,
        ACT_APPROACH = 7,
        ACT_FLAP = 8,
        ACT_SLEEP = 9,
        ACT_NUM = 10,
    };
    enum
    {
        ACT_BANK_ANIMAL = 0,
    };
    enum
    {
        MONTAGE_BODY = 1,
        MONTAGE_HORN = 2,
        MONTAGE_COLOR = 32768,
        MONTAGE_BODY_ONLY = 1,
        MONTAGE_BODY_HORN = 3,
        MONTAGE_COLOR_5 = 32773,
    };
public:
    class MyDTI;
    struct MODEL_TBL;
    class ActBase;
    class ActFootwork;
    class ActWalk;
    class ActRun;
    class ActTurn;
    class ActCollapse;
    class ActEscape;
    class ActApproach;
    class ActFlap;
    class ActSleep;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct MODEL_TBL
    {
    public:
        u32 em_id;  // offset: 0x0
        f32 scale;  // offset: 0x4
        u16 montage;  // offset: 0x8
        f32 radius;  // offset: 0xc
        f32 height;  // offset: 0x10
    };
public:
    class ActBase : public cAction
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
        ActBase();
        virtual ~ActBase();
        virtual void init();  // vtable slot 7
        // Address: 0x01ad0370 - 0x01ad0371 (1 bytes)
        virtual void move() {}  // vtable slot 8
        virtual void updatePtr();  // vtable slot 11
        void setMotion(u32 motNo, bool isForce, u32 attr, f32 hokan, f32 frame, f32 speed);
        void setAction(u32 actNo);
        void randomAction();
    protected:
        uAnimal* mpAnimal;  // offset: 0x28
    public:
        static MyDTI DTI;
    };
public:
    class ActFootwork : public uAnimal::ActBase
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
        ActFootwork();
        virtual ~ActFootwork();
        virtual void init();  // vtable slot 7
        virtual void move();  // vtable slot 8
    public:
        f32 mTimer;  // offset: 0x30
        static MyDTI DTI;
    };
public:
    class ActWalk : public uAnimal::ActBase
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
        ActWalk();
        virtual ~ActWalk();
        virtual void init();  // vtable slot 7
        virtual void move();  // vtable slot 8
    public:
        f32 mTimer;  // offset: 0x30
        MtVector3 mOldPos;  // offset: 0x40
        static MyDTI DTI;
    };
public:
    class ActRun : public uAnimal::ActBase
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
        ActRun();
        virtual ~ActRun();
        virtual void init();  // vtable slot 7
        virtual void move();  // vtable slot 8
    public:
        u32 mMotionStart;  // offset: 0x30
        f32 mTimer;  // offset: 0x34
        MtVector3 mOldPos;  // offset: 0x40
        static MyDTI DTI;
    };
public:
    class ActTurn : public uAnimal::ActBase
    {
    public:
        enum
        {
            ACT_TURN_R = 0,
            ACT_TURN_L = 1,
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
        ActTurn();
        virtual ~ActTurn();
        virtual void init();  // vtable slot 7
        virtual void move();  // vtable slot 8
    public:
        u32 mType;  // offset: 0x30
        f32 mTurnAngleY;  // offset: 0x34
        static MyDTI DTI;
    };
public:
    class ActCollapse : public uAnimal::ActBase
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
        ActCollapse();
        virtual ~ActCollapse();
        virtual void init();  // vtable slot 7
        virtual void move();  // vtable slot 8
    public:
        f32 mTimer;  // offset: 0x30
        static MyDTI DTI;
    };
public:
    class ActEscape : public uAnimal::ActBase
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
        ActEscape();
        virtual ~ActEscape();
        virtual void init();  // vtable slot 7
        virtual void move();  // vtable slot 8
    public:
        f32 mRotSpeed;  // offset: 0x30
        f32 mTimer;  // offset: 0x34
        MtVector3 mOldPos;  // offset: 0x40
        static MyDTI DTI;
    };
public:
    class ActApproach : public uAnimal::ActBase
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
        ActApproach();
        virtual ~ActApproach();
        virtual void init();  // vtable slot 7
        virtual void move();  // vtable slot 8
    public:
        f32 mRotSpeed;  // offset: 0x30
        f32 mTimer;  // offset: 0x34
        static MyDTI DTI;
    };
public:
    class ActFlap : public uAnimal::ActBase
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
        ActFlap();
        virtual ~ActFlap();
        virtual void init();  // vtable slot 7
        virtual void move();  // vtable slot 8
    public:
        static MyDTI DTI;
    };
public:
    class ActSleep : public uAnimal::ActBase
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
        ActSleep();
        virtual ~ActSleep();
        virtual void init();  // vtable slot 7
        virtual void move();  // vtable slot 8
    public:
        f32 mTimer;  // offset: 0x30
        cEfcHandle* mpEfcHandle;  // offset: 0x38
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
    uAnimal();
    virtual ~uAnimal();
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void kill();  // vtable slot 16
    void checkAction();
    void updateMotion();
    virtual void updateMatrix();  // vtable slot 71
    virtual void createComponent();  // vtable slot 43
    void setModelType(u32 type);
    u32 getModelType() const;
    bool setResource();
    void move_main();
    u32 checkWall(f32 dist);
    virtual void updateObjStatus();  // vtable slot 69
private:
    u32 mModelType;  // offset: 0x246c
    bool mIsGround;  // offset: 0x2470
    TICKET mArcTicket;  // offset: 0x2478
    MtVector3 mSafePos;  // offset: 0x2480
    f32 mInitFrame;  // offset: 0x2490
public:
    static MyDTI DTI;
    static const MODEL_TBL mModelTbl[10];
};

// Inline, no code of its own: checked where it is inlined.
inline uAnimal::ActBase::ActBase() {
    this->mpAnimal = static_cast<uAnimal*>(nullptr);
}
