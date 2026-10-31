#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
class CDataStageLayoutID;
class MtDTI;

// Declarations
namespace nLayout { struct stLayoutID; }
namespace nLayout { struct stReserveID; }
namespace nLayout { struct stSplitID; }
namespace nLayout { struct stUniqueID; }

namespace nLayout {
    enum GROUP_CLASS
    {
        GROUP_CLASS_A = 0,
        GROUP_CLASS_B = 1,
        GROUP_CLASS_C = 2,
        GROUP_CLASS_NUM = 3,
    };
}  // namespace nLayout

namespace nLayout {
    enum UNIT_PRIO
    {
        UNIT_PRIO_LOW = 100,
        UNIT_PRIO_NORMAL = 101,
        UNIT_PRIO_NORMAL_Q = 102,
        UNIT_PRIO_HIGH = 103,
        UNIT_PRIO_HIGH_EV = 104,
    };
}  // namespace nLayout

namespace nLayout {
    enum U_KIND
    {
        U_NONE = 0,
        U_PL = 1,
        U_ENEMY = 2,
        U_OM = 3,
        U_OM_SCR = 4,
        U_NPC = 5,
        U_SHL = 6,
        U_QUEST = 7,
    };
}  // namespace nLayout

// Type aliases from DWARF
using s32 = int;
using u32 = unsigned int;
using u8 = unsigned char;

namespace nLayout {

    enum
    {
        EM_TARGET_TYPE_NONE = 1,
        EM_TARGET_TYPE_RARE = 2,
        EM_TARGET_TYPE_SQRARE = 3,
        EM_TARGET_TYPE_QT = 4,
        EM_TARGET_TYPE_QTSQRARE = 5,
        EM_TARGET_TYPE_AREA_BOSS = 6,
        EM_TARGET_TYPE_STAGE_BOSS = 7,
        EM_TARGET_TYPE_MAX = 8,
    };

    // Forward declarations
    struct stUniqueID;

    struct stUniqueID
    {
    public:
        stUniqueID(nLayout::U_KIND kind, u32 layoutGroup, u32 layoutId, s32 stageId);
        stUniqueID(nLayout::U_KIND kind, u32 layoutGroup, u32 layoutId, u32 innerId, s32 stageId);
        stUniqueID(nLayout::U_KIND kind, u32 memberIndex, bool lobby);
        stUniqueID(nLayout::U_KIND kind, u32 q_no, u32 blockNo);
        stUniqueID(nLayout::U_KIND kind, u32 q_no, u32 blockNo, u8 processNo);
        stUniqueID(u32 id);
    public:
        union
        {
        public:
            struct
            {
            public:
                u32 mKind : 3;  // offset: 0x0
                u32 mStageId : 9;  // offset: 0x0
                u32 mLayoutGroup : 9;  // offset: 0x0
                u32 mLayoutId : 5;  // offset: 0x0
                u32 mInnerId : 5;  // offset: 0x0
                u32 mReserve : 1;  // offset: 0x0
            };  // offset: 0x0
            struct
            {
            public:
                u32 mType : 3;  // offset: 0x0
                u32 mLobby : 1;  // offset: 0x0
                u32 mMemberIndex : 20;  // offset: 0x0
                u32 mFree : 7;  // offset: 0x0
                u32 mReserved : 1;  // offset: 0x0
            };  // offset: 0x0
            struct
            {
            public:
                u32 mKind2 : 3;  // offset: 0x0
                u32 mStgId : 9;  // offset: 0x0
                u32 mQuestNo : 8;  // offset: 0x0
                u32 mBlockNo : 6;  // offset: 0x0
                u32 mProcessNo : 5;  // offset: 0x0
                u32 mRsrv : 1;  // offset: 0x0
            };  // offset: 0x0
            struct
            {
            public:
                u32 mQstKind : 3;  // offset: 0x0
                u32 mQstStageId : 9;  // offset: 0x0
                u32 mQstSeq : 11;  // offset: 0x0
                u32 mQstLayoutGroup : 4;  // offset: 0x0
                u32 mQstLayoutId : 4;  // offset: 0x0
                u32 mQstRsrv : 1;  // offset: 0x0
            };  // offset: 0x0
            u32 mUniqueId;  // offset: 0x0
        };  // offset: 0x0
    };

    U_KIND getUniqueIDKind(u32 uniqueId);
    u32 createUniqueID(U_KIND kind, u32 layoutGroup, u32 layoutId, s32 stageNo);
    u32 createUniqueID(U_KIND kind, u32 layoutGroup, u32 layoutId, u32 innerId, s32 stageNo);
    u32 createUniqueID(U_KIND kind, u32 memberIndex, bool lobby);
    u32 createUniqueIDQuest(u32 q_no, u32 blockNo, s32 stageNo);
    u32 createUniqueIDQuestProcess(u32 q_no, u32 blockNo, s32 stageNo, u8 processNo);
    u32 createUniqueIDQuestSet(u32 QuestNo, s32 StageNo, u32 LayoutGroup, u32 LayoutId);
    u32 createUniqueIDQuestSetSeq(u32 QuestSeq, s32 StageNo, u32 LayoutGroup, u32 LayoutId);
    u32 getUniqueIDStageId(u32 uniqueId);
    u32 getUniqueIDLayoutGroup(u32 uniqueId);
    u32 getUniqueIDLayoutID(u32 uniqueId);
    u32 getUniqueIDInnerID(u32 uniqueId);
    u32 addInnerIDToUniqueID(u32 uniqueId, u32 innerId);
    u32 delInnerIDToUniqueID(u32 uniqueId);
    u32 getUniqueIdQstSeq(u32 uniqueId);
    CDataStageLayoutID createStageLayoutId(u32 stageNo, u32 layerNo, u32 groupNo);
    s32 searchSetInfoDtiTableIndex(const MtDTI* pDti);
    const MtDTI* getSetInfoDtiFromTable(s32 index);

}  // namespace nLayout

namespace nLayout {
    struct stLayoutID
    {
    public:
        stLayoutID();
        stLayoutID(const nLayout::stLayoutID& layoutID);
        stLayoutID(u32 area, u32 group);
        nLayout::stLayoutID& operator=(const nLayout::stLayoutID& r);
        bool operator==(const nLayout::stLayoutID& r) const;
        bool operator!=(const nLayout::stLayoutID&) const;
        bool operator<(const nLayout::stLayoutID&) const;
        bool operator>(const nLayout::stLayoutID&) const;
    public:
        union
        {
        public:
            struct
            {
            public:
                u32 mArea : 10;  // offset: 0x0
                u32 mGroup : 22;  // offset: 0x0
            };  // offset: 0x0
            u32 mLayoutID;  // offset: 0x0
        };  // offset: 0x0
    };
}  // namespace nLayout

namespace nLayout {
    struct stReserveID
    {
    public:
        stReserveID();
        stReserveID(const nLayout::stReserveID& layoutID);
        stReserveID(u32 group, u32 id);
        nLayout::stReserveID& operator=(const nLayout::stReserveID& r);
        bool operator==(const nLayout::stReserveID& r) const;
        bool operator!=(const nLayout::stReserveID&) const;
        bool operator<(const nLayout::stReserveID&) const;
        bool operator>(const nLayout::stReserveID&) const;
    public:
        union
        {
        public:
            struct
            {
            public:
                u32 mGroup : 16;  // offset: 0x0
                u32 mID : 16;  // offset: 0x0
            };  // offset: 0x0
            u32 mReserveID;  // offset: 0x0
        };  // offset: 0x0
    };
}  // namespace nLayout

namespace nLayout {
    struct stSplitID
    {
    public:
        stSplitID();
        stSplitID(const nLayout::stSplitID& layoutID);
        stSplitID(u32 x, u32 z);
        nLayout::stSplitID& operator=(const nLayout::stSplitID& r);
        bool operator==(const nLayout::stSplitID& r) const;
        bool operator!=(const nLayout::stSplitID&) const;
        bool operator<(const nLayout::stSplitID&) const;
        bool operator>(const nLayout::stSplitID&) const;
        bool isValid() const;
        bool isZero() const;
    public:
        union
        {
        public:
            struct
            {
            public:
                u32 mSplitX : 16;  // offset: 0x0
                u32 mSplitZ : 16;  // offset: 0x0
            };  // offset: 0x0
            u32 mSplitID;  // offset: 0x0
        };  // offset: 0x0
    };
}  // namespace nLayout

inline nLayout::stLayoutID::stLayoutID() {
    this->mLayoutID = 0;
}

inline nLayout::stReserveID::stReserveID() {
}

inline nLayout::stSplitID::stSplitID() {
    this->mSplitID = 0;
}
