#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/cUnit.h"

// Forward declarations
class CDataCraftProgress;
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class uControlNpc;

// Declarations
class uStageCraftPawnCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uStageCraftPawnCtrl : public cUnit
{
public:
    enum
    {
        R0_MOVE_INIT = 0,
        R0_MOVE_MAIN = 1,
        R0_MOVE_EXIT = 2,
        RNO_MOVE_NUM = 3,
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
    uStageCraftPawnCtrl();
    virtual ~uStageCraftPawnCtrl();
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    void requestUpdatePawn();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
protected:
    void moveInit();
    void moveMain();
    void moveExit();
    void updatePawnList();
    void updateMainPawnList();
    void updateRentalPawnList();
    void updateWorkPawnList();
    void updateWaitPawnList();
    void clearPawnList();
    void updatePawnDisp();
private:
    void updateWaitPawnListCore(u32* Dest, u32 WorkNum);
    void updateWorkPawnListCore(u32(*Dest)[4], CDataCraftProgress* pCraftData);
    void updateWaitPawnDispCore(u32* PawnList, const s32* NpcIdList, MtTypedArray<uControlNpc>& NpcList);
    void updateWorkPawnDispCore(u32(*PawnList)[4], const s32(*NpcIdList)[4], MtTypedArray<uControlNpc>& NpcList);
    void offDispPawn(uControlNpc* pCtrlNpc);
    void onDispPawn(uControlNpc* pCtrlNpc, u32 PawnId);
protected:
    u32 mMainPawnList[10];  // offset: 0x48
    u32 mRentalPawnList[10];  // offset: 0x70
    u32 mBlackSmithPawn[10][4];  // offset: 0x98
    u32 mDeskWorkPawn[10][4];  // offset: 0x138
    u32 mCookingPawn[10][4];  // offset: 0x1d8
    u32 mWaitMainPawn[10];  // offset: 0x278
    u32 mWaitRentalPawn[10];  // offset: 0x2a0
    f32 mUpdateTimer;  // offset: 0x2c8
    f32 mUpdateTime;  // offset: 0x2cc
public:
    static const u32 WORK_TASK_DISP_NUM = 2;
    static const u32 WORK_TASK_PAWN_NUM = 4;
    static const u32 PAWN_REGIST_NUM = 10;
    static const u32 WORK_TASK_NUM = 10;
    static MyDTI DTI;
};
