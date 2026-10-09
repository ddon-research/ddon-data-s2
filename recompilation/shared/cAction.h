#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "uModel.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtPropertyList;
class MtVector3;
class cpActionManager;
class cpActionRequest;
namespace nActionManager { struct stActExParam; }
class uDDOModel;

// Declarations
class cAction;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cAction : public MtObject
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
    cAction();
    virtual ~cAction();
    virtual void preInit();  // vtable slot 6
    virtual void init();  // vtable slot 7
    virtual void move();  // vtable slot 8
    virtual void final();  // vtable slot 9
    virtual void moveAfter();  // vtable slot 10
    // Address: 0x0194fa20 - 0x0194fa21 (1 bytes)
    virtual void updatePtr() {}  // vtable slot 11
    // Address: 0x0194fa30 - 0x0194fa31 (1 bytes)
    virtual void updateEfcHandle() {}  // vtable slot 12
    // Address: 0x0194fa40 - 0x0194fa41 (1 bytes)
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {}  // vtable slot 13
    virtual bool checkInit();  // vtable slot 14
    virtual bool checkMove();  // vtable slot 15
    virtual bool checkFinal();  // vtable slot 16
    virtual bool checkMoveAfter();  // vtable slot 17
    void setup(cpActionManager* pActMgr, cpActionRequest* pActReq, uDDOModel* pModel);
    const nActionManager::stActExParam* getActExParam();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void setEndAction(u32 ActNo);
    void setLandAction(u32 ActNo);
    void setFallAction(u32 ActNo);
    void requestAction(u32 ActNo);
    void endAction();
    void endActionNoSend();
    bool isActionMotionEnd(MOT_TYPE type);
    bool isAttackHit(u32 filter);
    bool isDamageHit(u32 filter);
    bool isCheckHit(u32 filter);
    bool isCheckedHit(u32 filter);
    bool isCatchHit(u32 filter);
    bool isCaughtHit(u32 filter);
    bool isPushHit(u32 filter);
    bool isGuardHit(u32 filter);
    bool isGuardedHit(u32 filter);
    bool isHealHit(u32 filter);
    bool isHealedHit(u32 filter);
    bool isAttackTestHit(u32 filter);
    bool isDamageTestHit(u32 filter);
    bool isCheckTestHit(u32 filter);
    bool isCheckedTestHit(u32 filter);
    bool isCatchTestHit(u32 filter);
    bool isCaughtTestHit(u32 filter);
    bool isGuardTestHit(u32 filter);
    bool isHealTestHit(u32 filter);
    bool isHealedTestHit(u32 filter);
    void setObjColNoneThrow(bool isMyPlayerOnly);
private:
    bool isFrameEnd(MOT_TYPE type);
    bool isBlendCtrlEnable(MOT_TYPE type);
    void addColNodeFlag(u32 flag, bool isMyPlayerOnly);
public:
    cpActionManager* mpActMgr;  // offset: 0x8
    cpActionRequest* mpActReq;  // offset: 0x10
    uDDOModel* mpModel;  // offset: 0x18
    union
    {
    public:
        struct
        {
        public:
            u8 mRno0;  // offset: 0x0
            u8 mRno1;  // offset: 0x1
            u8 mRno2;  // offset: 0x2
            u8 mRno3;  // offset: 0x3
        };  // offset: 0x0
        u32 mRno;  // offset: 0x0
    };  // offset: 0x20
    static MyDTI DTI;
};
