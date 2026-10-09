#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "cSystem.h"
#include "nGroup.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class cCharacterData;
class cContext;
class cContextInstEm;
class cContextInstHm;
class cContextInstNpc;
class cContextInstOm;
class cContextInstance;
namespace nLayout { struct stLayoutID; }

// Declarations
class sContextManager;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class sContextManager : public cSystem
{
public:
    class MyDTI;
    class List;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class List : public MtObject
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
        List();
        virtual ~List();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        void regist(cContext* pContext);
        void remove(cContext* pContext);
        void removeAll();
        u32 getListNum();
        cContext* getTop();
        cContext* getEnd();
    private:
        cContext* mpTop;  // offset: 0x8
        cContext* mpEnd;  // offset: 0x10
        u32 mNum;  // offset: 0x18
    public:
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
    sContextManager();
    virtual ~sContextManager();
    virtual void createMenu(MtPropertyList& s);  // vtable slot 8
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    static sContextManager* getInstance();
    virtual void move();  // vtable slot 7
    virtual void reset();  // vtable slot 6
    void removeAllContext();
    cContextInstance* requestCreateContextInst(u32 id, u32 uniqueId, s32 encountArea);
    cContextInstance* getContextInstFromUniqueId(u32 UniqueId);
    List* getContextList(nGroup::ID_CONTEXT idContext);
    cContextInstance* createContextInstance(u32 id, u32 uniqueId, s32 stageNo, s32 encountArea);
    void onSyncContextInstance(u32 uniqueId);
    cContext* createContext(u32 id);
    bool registContext(cContext* pContext);
    bool removeContext(cContext* pContext);
    cContextInstHm* searchContext(u32 unitUniqId);
    cContextInstHm* searchContextFromCharId(u32 charId, u32 pawnId, MtArray* pArray);
    cContextInstHm* getContextMyPlayer();
    u32 getMyUniqueId();
    cContextInstHm* getMyPawnPartyContextSequential(u32& cur, u32 pawnType);
    cContextInstHm* getMyPawnContext(u32 pawnId, u32 pawnType);
    void updateContextInstance();
    void updateContextInstanceCore(List& ContextList);
    bool isMemberContext(const cContextInstHm* pContext);
    void entryContextPlayer(u32 characterId, u32 pawnId);
    void removeContextPlayer(u32 characterId, u32 pawnId);
    void removeAllContextPlayer();
    cContextInstHm* getContextPlayer(u32 characterId, u32 pawnId);
    cContextInstHm* getContextPlayerIndex(u32 index, bool validCheck);
    bool isPlayerRPCID(u32 rpcId);
    cContextInstHm* getContextPlayerRPCID(u32 rpcId);
    cContextInstHm* getContextPlayerSender(u32 rpcId, u32 characterId, u32 searchId);
    cContextInstHm* entryContextPartyPlayer(s32 memberIndex, u32 characterId, u32 pawnId);
    void removeContextPartyPlayer(s32 memberIndex, bool bRemoveUI);
    void removeAllContextPartyPlayer(bool bRemoveUI);
    cContextInstHm* getContextPartyPlayer(u32 characterId, u32 pawnId);
    cContextInstHm* getContextPartyPlayerIndex(u32 index, bool validCheck);
    cContextInstHm* getContextPartyPlayerFromMemberIndex(s32 memberIndex);
    const cContextInstHm* getContextPartyLeader();
    bool isPartyMember(u32 characterId, u32 pawnId);
    bool isPartyMember(const cContextInstHm* pContext);
    s32 getPartyPawnEntryNum(u8 pawnType, bool isOwner);
    cContextInstHm* getContextPartyPawn(u8 pawnType, u32 pawnId, bool isOwner);
    bool isExistPartyPawn(u8 pawnType, u32 pawnId, bool isOwner);
    void setContextPawnReaction(u32 pawnId, u32 reactNo, u32 motNo);
    void initChargeInfoAllContext();
    const cContextInstEm* getContextEnemy(s32 sIdx);
    u32 getContextEnemyNum();
    cContextInstance* searchContextInstance(nGroup::ID_CONTEXT Type, u32 UniqueId);
    cContextInstEm* searchContextEnemy(u32 UniqueId);
    cContextInstNpc* searchContextNpc(u32 UniqueId);
    cContextInstOm* searchContextOm(u32 UniqueId);
    void setContextCharacter(cCharacterData& src, cContextInstHm& dst, u32 characterId, bool resetFlag);
    void setReturnPrepareStatus(cContextInstHm* pContext);
    bool isDeadEnemy(u32 uniqueId);
    void getContextEnemytList(u32 stageNo, u32 groupNo, MtArray& list);
    bool removeContextEnemytList(u32 stageNo, u32 groupNo, MtArray& list);
    cContextInstance* getContextEnemyAlive(nLayout::stLayoutID layoutID, u32 setNo);
private:
    cContextInstHm* mpContextPlayer;  // offset: 0x18
    cContextInstHm* mpContextPartyPlayerList[8];  // offset: 0x20
    List mList[13];  // offset: 0x60
    f32 mDeleteInterval;  // offset: 0x200
    f32 mDeleteTimer;  // offset: 0x204
    u32 mEmContextMaxNum;  // offset: 0x208
public:
    static MyDTI DTI;
private:
    static sContextManager* mpInstance;
};

// Inline, no code of its own: checked where it is inlined.
inline sContextManager* sContextManager::getInstance() {
    return ::sContextManager::mpInstance;
}

// Inline, no code of its own: checked where it is inlined.
inline sContextManager::List::List() {
    this->mNum = static_cast<u32>(0);
    this->mpEnd = static_cast<cContext*>(nullptr);
    this->mpTop = static_cast<cContext*>(nullptr);
}
