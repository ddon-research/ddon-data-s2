#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;

// Declarations
class cQuestPhaseComponent;
class cQuestPhaseCpDivide;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cQuestPhaseComponent : public MtObject
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
public:
    static MyDTI DTI;
};

class cQuestPhaseCpDivide : public cQuestPhaseComponent
{
public:
    enum
    {
        DIVIDE_MAX_NUM = 8,
    };
public:
    class MyDTI;
    class cPlayerState;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cPlayerState : public MtObject
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
        cPlayerState();
        // Address: 0x0197fee0 - 0x0197fee1 (1 bytes)
        virtual void createProperty(MtPropertyList& s) {}  // vtable slot 4
        void reset();
    public:
        u32 mCharacterId;  // offset: 0x8
        bool mHasChanged;  // offset: 0xc
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
    void getDivideStage(u32& stageNo, u32& startPosNo) const;
    void setDivideStage(u32 stageNo);
    void setDivideStage(u32 stageNo, u32 startPosNo);
    bool isDivideSetup() const;
    void setDivideSetup(bool isSetup);
    u32 getDivideCharacterId(u32 index) const;
    bool isDividePlayer(u32 characterId) const;
    void setDivideCharacterId(u32 characterId, u32 index);
    bool isReturnPlayer() const;
    bool isReturnPlayer(u32 characterId) const;
    u32 getReturnCharacterId(u32 index) const;
    void setReturnCharacterId(u32 characterId, u32 index);
    bool isNoReturnPlayer() const;
    void returnPlayer(u32 characterId);
    bool isDividePlayer() const;
    void dividePlayer(u32 characterId);
    bool hasSucceededDivide() const;
    bool hasSucceededDivide(u32 characterId) const;
    bool existsDividePlayer() const;
    void setExistDividePlayer(bool exists);
    bool hasRequestedWarpPlayer(u32 characterId);
    void requestWarpPlayer(u32 characterId);
    bool isFinishedEnemyAction() const;
    void finishEnemyAction();
    void callbackLeaveParty(u32 characterId);
    cQuestPhaseCpDivide();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
protected:
    cPlayerState mDividePlayer[8];  // offset: 0x8
    cPlayerState mReturnPlayer[8];  // offset: 0x88
    u32 mHasRequestedCharacterId[8];  // offset: 0x108
    u32 mStageNo;  // offset: 0x128
    u32 mStartPosNo;  // offset: 0x12c
    bool mIsSetup;  // offset: 0x130
    bool mExistDividePlayer;  // offset: 0x131
    bool mIsFinishedEnemyAction;  // offset: 0x132
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cQuestPhaseCpDivide::cPlayerState::cPlayerState() {
    this->mCharacterId = static_cast<u32>(0);
    this->mHasChanged = false;
}
