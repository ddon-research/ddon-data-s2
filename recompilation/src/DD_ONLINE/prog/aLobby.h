#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "aStage.h"
#include "uDDOModel.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cArcLoaderBase;
class uDDOModel;
class uScheduler;
class uUIMockUp;

// Declarations
class aLobby;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using TICKET = cArcLoaderBase*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class aLobby : public aStage
{
public:
    enum
    {
        MOVE_SEARCH_GAME_INIT = 0,
        MOVE_SEARCH_GAME_MOVE = 1,
        MOVE_SEARCH_GAME_SUCCESS = 2,
        MOVE_SEARCH_GAME_ERROR = 3,
    };
    enum
    {
        SAVE_NEXT_TITLE = 0,
        SAVE_NEXT_MENU = 1,
    };
    enum
    {
        LOAD_R1_ST_INIT = 0,
        LOAD_R1_ST_MOVE = 1,
        LOAD_R1_ST_EXIT = 2,
    };
    enum
    {
        MOVE_DIALOG_INIT = 0,
        MOVE_DIALOG_MAIN = 1,
        MOVE_DIALOG_EXIT = 2,
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
    aLobby();
    virtual ~aLobby();
    virtual bool load();  // vtable slot 6
    virtual void init();  // vtable slot 7
    virtual void move();  // vtable slot 8
protected:
    virtual void moveMain();  // vtable slot 15
    virtual void execDbgGameMenu();  // vtable slot 18
private:
    void movePauseLobby();
    void moveToStageLobby();
    s32 moveDialogLobby();
public:
    virtual void final();  // vtable slot 9
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MT_CTSTR getShaderSegment();  // vtable slot 12
private:
    TICKET mArcTicket;  // offset: 0x3d0
    s32 mPauseMenuCursor;  // offset: 0x3d8
    s32 mSessionListCursor;  // offset: 0x3dc
    s32 mStageSelectCursor;  // offset: 0x3e0
    s32 mStageNo;  // offset: 0x3e4
    s32 mSearchGameSessionRno;  // offset: 0x3e8
    u32 mSearchGameSessionDialogHandle;  // offset: 0x3ec
    s32 mSaveNext;  // offset: 0x3f0
    MtTypedArray<uDDOModel> mLayoutUnitList;  // offset: 0x3f8
    uUIMockUp* mpUIMockUp;  // offset: 0x418
    uScheduler* mpSdl;  // offset: 0x420
public:
    static MyDTI DTI;
};

inline void* aLobby::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"
#include "sArchiveManager.h"

inline void* aLobby::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::aLobby::DTI)->memAlloc(sz, align, ::aLobby::DTI.::MtDTI::getID());
}

inline void aLobby::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::aLobby::DTI)->memFree(p_addr);
}

inline aLobby::aLobby() {
    this->::aStage::mStageType = 1;
    this->mpSdl = nullptr;
    this->mpUIMockUp = nullptr;
    this->mArcTicket = ::sArchiveManager::INVALID_TICKET;
    this->mSaveNext = 0;
    this->mSearchGameSessionRno = 0;
    this->mSearchGameSessionDialogHandle = 0;
    this->mStageSelectCursor = 0;
    this->mStageNo = 0;
    this->mPauseMenuCursor = 0;
    this->mSessionListCursor = 0;
}
