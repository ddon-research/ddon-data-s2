#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "nCharacterData.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cTalkState;
namespace nCharacterData { struct stCharacterName; }

// Declarations
namespace nTalk { class cSelectData; }
namespace nTalk { class cSelectMember; }

namespace nTalk {
    enum TALK_STATE
    {
        TALK_STATE_NONE = 0,
        TALK_STATE_START_FLOW = 1,
        TALK_STATE_GREETING = 2,
        TALK_STATE_BASE = 3,
        TALK_STATE_QUEST_SELECT = 4,
        TALK_STATE_QUEST = 5,
        TALK_STATE_SPECIAL = 6,
        TALK_STATE_CYCLE_SELECT = 7,
        TALK_STATE_CYCLE = 8,
        TALK_STATE_PAWN = 9,
        TALK_STATE_SHOP_GENERAL = 10,
        TALK_STATE_SHOP_ITEM = 11,
        TALK_STATE_SHOP_EQUIP = 12,
        TALK_STATE_SHOP_MATERIAL = 13,
        TALK_STATE_INN = 14,
        TALK_STATE_SHOP_WEAPON = 15,
        TALK_STATE_SHOP_ARMOR = 16,
        TALK_STATE_SKILL_ABILITY = 17,
        TALK_STATE_JOB_CHANGE = 18,
        TALK_STATE_GRAND_MISSION = 19,
        TALK_STATE_PARTY_MAKE = 20,
        TALK_STATE_CLAN_MAKE = 21,
        TALK_STATE_CRAFT = 22,
        TALK_STATE_BEAUTY_PARLOR = 23,
        TALK_STATE_NEWS_PAPER = 24,
        TALK_STATE_ORB_PL_POWER_UP = 25,
        TALK_STATE_ORB_CREST = 26,
        TALK_STATE_ORB_MATERIAL = 27,
        TALK_STATE_AREA_MASTER = 28,
        TALK_STATE_JOB_MASTER = 29,
        TALK_STATE_BAZAAR = 30,
        TALK_STATE_ITEM_BOX = 31,
        TALK_STATE_DELIVERY_BOX = 32,
        TALK_STATE_RIM_STONE = 33,
        TALK_STATE_WARP_AREA = 34,
        TALK_STATE_WARP_STAGE = 35,
        TALK_STATE_WARP_GOLD_DRAGON = 36,
        TALK_STATE_BOARD_LIGHT_QUEST = 37,
        TALK_STATE_BOARD_EVENT_QUEST = 38,
        TALK_STATE_BOARD_RANKING = 39,
        TALK_STATE_WARP_BOUTO = 40,
        TALK_STATE_WARP_DANGEON = 41,
        TALK_STATE_HISTORY = 42,
        TALK_STATE_PAWN_REVIVE = 43,
        TALK_STATE_END_QUEST = 44,
        TALK_STATE_REVIVAL_RECOVER = 45,
        TALK_STATE_ITEM_BOX_EXT = 46,
        TALK_STATE_STAMP_BONUS = 47,
        TALK_STATE_ACCEPT_REWARD = 48,
        TALK_STATE_GACHA = 49,
        TALK_STATE_SECOND_PAWN = 50,
        TALK_STATE_RECOVER_WEAK = 51,
        TALK_STATE_CREATE_MY_PAWN = 52,
        TALK_STATE_APPRAISE = 53,
        TALK_STATE_PARTNER_PAWN = 54,
        TALK_STATE_ORB_PL_POWER_UP2 = 55,
        TALK_STATE_ACHIEVEMENT = 56,
        TALK_STATE_UNLOCK_JOB = 57,
        TALK_STATE_BOX_GACHA = 58,
        TALK_STATE_PAWN_EXPEDITION_SALLY = 59,
        TALK_STATE_PAWN_EXPEDITION_REWARD = 60,
        TALK_STATE_PP_SHOP = 61,
        TALK_STATE_CLAN_BASE_MANAGE = 62,
        TALK_STATE_TRANING_ROOM = 63,
        TALK_STATE_PAWN_QUEST = 64,
        TALK_STATE_CLAN_BASE_RELEASE = 65,
        TALK_STATE_CLAN_DUNGEON = 66,
        TALK_STATE_DEFINE_END = 67,
        TALK_STATE_NUM = 66,
    };
}  // namespace nTalk

// Type aliases from DWARF
using CHAR_NAME = nCharacterData::stCharacterName;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

namespace nTalk {

    // Forward declarations
    class cSelectData;
    class cSelectMember;

    class cSelectData : public ::MtObject
    {
    public:
        enum SELECT_TYPE
        {
            SELECT_TYPE_QUEST_SELECT = 0,
            SELECT_TYPE_QUEST = 1,
            SELECT_TYPE_FUNCTION = 2,
            SELECT_TYPE_TALK = 3,
            SELECT_TYPE_YESNO = 4,
            SELECT_TYPE_COMMON = 5,
        };
        enum SELECT_ITEM_YESNO
        {
            SELECT_ITEM_YES = 0,
            SELECT_ITEM_NO = 1,
        };
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        SELECT_TYPE getType() const;
        u32 getParam0() const;
        u32 getParam1() const;
        cSelectData();
        cSelectData(SELECT_TYPE type, u32 param0, u32 param1);
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        u32 mType;  // offset: 0x8
        u32 mParam0;  // offset: 0xc
        u32 mParam1;  // offset: 0x10
    public:
        static MyDTI DTI;
    };

    class cSelectMember : public ::MtObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        u32 getSlot() const;
        u32 getPawnId() const;
        CHAR_NAME getName() const;
        cSelectMember();
        cSelectMember(u32 slot, u32 pawnId, CHAR_NAME name);
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        u32 mSlot;  // offset: 0x8
        u32 mPawnId;  // offset: 0xc
        CHAR_NAME mName;  // offset: 0x10
    public:
        static MyDTI DTI;
    };

    cTalkState* getNextState(cTalkState* pCurrentState);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nTalk.cpp:318
    TALK_STATE funcId2TalkState(u32 funcId);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nTalk.cpp:439
    u32 talkState2FuncId(TALK_STATE talkState);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nTalk.cpp:459

}  // namespace nTalk

// Inline, no code of its own: checked where it is inlined.
inline nTalk::cSelectData::cSelectData() {
    this->mType = static_cast<u32>(0);
    this->mParam0 = static_cast<u32>(0);
    this->mParam1 = static_cast<u32>(0);
}
