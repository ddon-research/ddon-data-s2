#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "aStage.h"
#include "cArcLoader.h"
#include "cCharacterData.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class rSoundStreamRequest;
class uCharacterEdit;

// Declarations
class aCharacterEditGame;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using cArcLoader04 = cArcLoader<4>;
using size_t = _Sizet;
using u32 = unsigned int;

class aCharacterEditGame : public aStage
{
public:
    enum
    {
        MOVE_R1_INIT = 0,
        MOVE_R1_CREATE_PAWN_INIT = 1,
        MOVE_R1_BEAUTY_PARLOR_PLAYER_INIT = 2,
        MOVE_R1_BEAUTY_PARLOR_PAWN_INIT = 3,
        MOVE_R1_GET_PAWN_WAIT = 4,
        MOVE_R1_LOAD_INIT = 5,
        MOVE_R1_LOAD_WAIT = 6,
        MOVE_R1_GUI_INIT = 7,
        MOVE_R1_EDIT = 8,
        MOVE_R1_EDIT_INPUT_NAME = 9,
        MOVE_R1_EDIT_END = 10,
        MOVE_R1_TO_CHARA_EDIT = 11,
        MOVE_R1_CHARA_EDIT_INIT = 12,
        MOVE_R1_CHARA_EDIT = 13,
        MOVE_R1_CHARA_EDIT_END = 14,
        MOVE_R1_PERSONALITY_INIT = 15,
        MOVE_R1_PERSONALITY = 16,
        MOVE_R1_PERSONALITY_END = 17,
        MOVE_R1_PAWN_REGISTER = 18,
        MOVE_R1_PAWN_REGISTER_WAIT = 19,
        MOVE_R1_GET_PAWN_DATA_WAIT = 20,
        MOVE_R1_JOIN_PARTY_MY_PAWN = 21,
        MOVE_R1_JOIN_PARTY_MY_PAWN_WAIT = 22,
        MOVE_R1_MOVE = 23,
        MOVE_R1_END = 24,
        MOVE_R1_NUM = 25,
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
    aCharacterEditGame();
    virtual ~aCharacterEditGame();
    virtual void init();  // vtable slot 7
    virtual void move();  // vtable slot 8
    virtual void moveMain();  // vtable slot 15
    virtual void final();  // vtable slot 9
    void clearMemer();
public:
    cCharacterData::stPawnData mEditData;  // offset: 0x3d0
    uCharacterEdit* mpCharacterEdit;  // offset: 0x1d38
    u32 mEditType;  // offset: 0x1d40
    u32 mCharEditPawnSlotNo;  // offset: 0x1d44
    rSoundStreamRequest* mprBgm;  // offset: 0x1d48
    cArcLoader04 mArcLoader;  // offset: 0x1d50
    static MyDTI DTI;
};

inline void* aCharacterEditGame::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/rSoundStreamRequest.h"

inline void aCharacterEditGame::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::aCharacterEditGame::DTI)->memFree(p_addr);
}

inline void aCharacterEditGame::clearMemer() {
    if (this->mprBgm == nullptr) {
        return;
    }
    this->mprBgm->::cResource::release();
    this->mprBgm = nullptr;
}
