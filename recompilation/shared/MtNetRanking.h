#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtNetBuffer.h"
#include "MtNetObject.h"
#include "MtNetRequest.h"
#include "_rtc.h"
#include "np_npid.h"
#include "np_ranking.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtNetContext;
struct MtNetError;
class MtNetRequest;
class MtNetRequestController;
class MtNetUniqueId;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
struct SceNpId;
struct SceNpScoreComment;
struct SceNpScoreGameInfo;
struct SceNpScorePlayerRankData;
struct SceNpScoreRankData;
struct SceRtcTick;

// Declarations
class MtNetRanking;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using __uint32_t = unsigned int;
using uint32_t = __uint32_t;
using SceNpScoreRankNumber = uint32_t;
using _Sizet = long unsigned int;
using __int64_t = long int;
using __uint64_t = long unsigned int;
using f32 = float;
using f64 = double;
using s16 = short;
using s32 = int;
using s64 = __int64_t;
using s8 = signed char;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class MtNetRanking : public MtNetObject, public MtNetRequestController::Listener
{
public:
    enum
    {
        PHASE_AUTO_FINALIZE_NONE = 0,
        PHASE_AUTO_FINALIZE_DROP = 1,
        PHASE_AUTO_FINALIZE_WAIT = 2,
        PHASE_AUTO_FINALIZE_END = 3,
    };
public:
    class MyDTI;
    class Listener;
    class ScoreList;
    class Score;
    struct ScoreOption;
    struct Attach;
    struct RegisterRequest;
    struct Updater;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class Listener
    {
    public:
        Listener();
        virtual ~Listener() {}
        virtual void onNtcDestruct();  // vtable slot 2
        virtual void onNtcFinalize();  // vtable slot 3
        virtual void onNtcDrop(MtNetError* net_err);  // vtable slot 4
        virtual void onAnsUpdateSucceed(u32 req_seq);  // vtable slot 5
        virtual void onAnsUpdateFail(u32 req_seq, MtNetError* net_err);  // vtable slot 6
        virtual void onAnsGetScoreListSucceed(u32 req_seq, MtNetRanking::ScoreList* list);  // vtable slot 7
        virtual void onAnsGetScoreListFail(u32 req_seq, MtNetError* net_err);  // vtable slot 8
        virtual void onAnsGetAttachSucceed(u32 req_seq, MtNetRanking::Attach* attach);  // vtable slot 9
        virtual void onAnsGetAttachFail(u32 req_seq, MtNetError* net_err);  // vtable slot 10
    };
public:
    struct ScoreOption
    {
    public:
        u8 mKind;  // offset: 0x0
        union
        {
        public:
            s8 mInt8;  // offset: 0x0
            s16 mInt16;  // offset: 0x0
            s32 mInt32;  // offset: 0x0
            s64 mInt64;  // offset: 0x0
            f32 mFloat32;  // offset: 0x0
            f64 mFloat64;  // offset: 0x0
            u64 mTime;  // offset: 0x0
        };  // offset: 0x8
    };
public:
    struct Attach
    {
    public:
        s32 mSize;  // offset: 0x0
        void* mpData;  // offset: 0x8
    };
public:
    struct RegisterRequest
    {
    public:
        int scoreId;  // offset: 0x0
        int attachId;  // offset: 0x4
        s32 result;  // offset: 0x8
        SceNpScoreComment comment;  // offset: 0xc
        SceNpScoreGameInfo gameInfo;  // offset: 0x50
        SceNpScoreRankNumber tempRank;  // offset: 0x118
    };
public:
    struct Updater
    {
    public:
        s32 mBoardId;  // offset: 0x0
        MtNetUniqueId mUniqueId;  // offset: 0x8
        s64 mValue;  // offset: 0x80
        s32 mOptionNum;  // offset: 0x88
        MtNetRanking::ScoreOption mOption[8];  // offset: 0x90
        MtNetRanking::Attach mAttach;  // offset: 0x110
    };
public:
    class Score : public MtNetObject
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
        Score();
        Score(const MtNetRanking::Score& score);
        virtual ~Score();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void clear();
        MtNetRanking::Score& operator=(const MtNetRanking::Score& src_score);
        void setUniqueId(MtNetUniqueId* uniq_id);
        MtNetUniqueId* getUniqueId();
        void setName(MT_CTSTR name);
        MT_CTSTR getName();
        void setRank(s32 rank);
        s32 getRank();
        void setValue(s64 value);
        s64 getValue();
        void clearOption();
        void setOptionNum(s32 num);
        s32 getOptionNum();
        void setOption(s32 no, MtNetRanking::ScoreOption* option);
        bool isOmittedName();
        void setIsOmittedName(bool flag);
        MtNetRanking::ScoreOption* getOption(s32 no);
    private:
        MtNetUniqueId mUniqueId;  // offset: 0x28
        MT_CHAR mName[32];  // offset: 0xa0
        bool mIsOmittedName;  // offset: 0xc0
        s32 mRank;  // offset: 0xc4
        s64 mValue;  // offset: 0xc8
        s32 mOptionNum;  // offset: 0xd0
        MtNetRanking::ScoreOption mOption[8];  // offset: 0xd8
    public:
        static MyDTI DTI;
    };
public:
    class ScoreList : public MtNetObject
    {
    public:
        enum
        {
            SORT_MODE_NONE = 0,
            SORT_MODE_RANK_ASCEND = 1,
            SORT_MODE_RANK_DESCEND = 2,
        };
    public:
        ScoreList();
        ScoreList(const MtNetRanking::ScoreList& score_list);
        virtual ~ScoreList();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        void clear();
        MtNetRanking::ScoreList& operator=(const MtNetRanking::ScoreList& src_list);
        void sort(s32 mode);
        void setBoardId(s32 board_id);
        s32 getBoardId();
        void setOffset(s32 offset);
        s32 getOffset();
        void setNum(s32 num);
        s32 getNum();
        void setRegistNum(s32 num);
        s32 getRegistNum();
        void setScore(s32 no, MtNetRanking::Score* score);
        MtNetRanking::Score* getScore(s32 no);
    private:
        s32 mBoardId;  // offset: 0x24
        s32 mOffset;  // offset: 0x28
        s32 mNum;  // offset: 0x2c
        s32 mRegistNum;  // offset: 0x30
        MtNetRanking::Score mScore[101];  // offset: 0x38
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
    static void clearUpdater(Updater* updater);
    MtNetRanking();
    MtNetRanking(MtNetContext* context);
    virtual ~MtNetRanking();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void addListener(Listener* listener);
    void removeListener(Listener* listener);
    void move();
    ScoreList* getScoreList();
    void reqUpdate(u32* req_seq, Updater* updater_list, s32 updater_num);
    void reqGetScoreListByRange(u32* req_seq, s32 board_id, s32 offset, s32 max_num);
    void reqGetScoreListByUniqueId(u32* req_seq, s32 board_id, MtNetUniqueId* uniq_id_list, s32 uniq_id_num);
    void reqGetAttach(u32* req_seq, s32 board_id, MtNetUniqueId* uniq_id, void* buf_ptr, s32 buf_size);
    void abortRequest(u32 req_seq);
private:
    void cbAnsUpdateSucceed(MtNetRequest* req);
    void cbAnsUpdateFail(MtNetRequest* req, MtNetError* net_err);
    void cbAnsGetScoreListSucceed(MtNetRequest* req, ScoreList* list);
    void cbAnsGetScoreListFail(MtNetRequest* req, MtNetError* net_err);
    void cbAnsGetAttachSucceed(MtNetRequest* req, Attach* attach);
    void cbAnsGetAttachFail(MtNetRequest* req, MtNetError* net_err);
    virtual bool canMoveRequest(MtNetRequest* req);  // vtable slot 11
    virtual s32 startRequest(MtNetRequest* req);  // vtable slot 12
    virtual s32 moveRequest(MtNetRequest* req);  // vtable slot 13
    virtual void endRequest(MtNetRequest* req);  // vtable slot 14
    virtual void startFailRequest(MtNetRequest* req);  // vtable slot 15
    s32 startEmpty(MtNetRequest* req);
    void endEmpty(MtNetRequest* req);
    s32 moveUpdate(MtNetRequest* req);
    s32 moveGetScoreListByRange(MtNetRequest* req);
    s32 moveGetScoreListByUniqueId(MtNetRequest* req);
    s32 moveGetAttach(MtNetRequest* req);
    void nativeConstructor();
    void nativeDestructor();
    void nativeCreateProperty(MtPropertyList& s);
    void nativeMove();
    void serializeScoreOption(SceNpScoreGameInfo* info, ScoreOption* list, s32 num);
    void deserializeScoreOption(Score* score, SceNpScoreGameInfo* info);
private:
    MtNetContext* mpContext;  // offset: 0x30
    MtNetRequestController mRequestController;  // offset: 0x38
    Listener* mpListener;  // offset: 0xb0
    s32 mPhaseAutoFinalize;  // offset: 0xb8
    bool mIsDestructor;  // offset: 0xbc
    ScoreList mScoreList;  // offset: 0xc0
    int mScoreContextId;  // offset: 0x88b0
    RegisterRequest mRegisterRequestTbl[6];  // offset: 0x88b8
    Attach mAttach;  // offset: 0x8f78
    s32 mRequestId;  // offset: 0x8f88
    alignas(8) SceNpId mRequestNpIdTbl[101];  // offset: 0x8f90
    s32 mGetRequestNum;  // offset: 0x9dc4
    s32 mGetResultNum;  // offset: 0x9dc8
    SceNpScoreRankData mGetRankData[101];  // offset: 0x9dd0
    SceNpScorePlayerRankData mGetPlayerRankData[101];  // offset: 0xd050
    SceNpScoreComment mGetComment[101];  // offset: 0x105f8
    SceNpScoreGameInfo mGetGameInfo[101];  // offset: 0x11f38
    SceNpScoreRankNumber mGetTotalRec;  // offset: 0x16e20
    SceRtcTick mGetLastDate;  // offset: 0x16e28
    size_t mGetAttachSize;  // offset: 0x16e30
public:
    static MyDTI DTI;
    static const s32 MAX_NUM_SCORE = 101;
    static const s32 MAX_NUM_SCORE_OPTION = 8;
    static const s32 MAX_SIZE_BUF_SCORE_NAME = 32;
private:
    static const s32 REQUEST_ID_UPDATE = 2305;
    static const s32 REQUEST_ID_GET_SCORE_LIST_BY_RANGE = 2306;
    static const s32 REQUEST_ID_GET_SCORE_LIST_BY_UNIQUE_ID = 2307;
    static const s32 REQUEST_ID_GET_ATTACH = 2309;
    static const s32 MAX_NUM_REGISTER_INFO = 6;
};
