#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "nWeapon.h"
#include "rSoundHitInfo.h"
#include "sCollision.h"
#include "sSound.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtQuaternion;
class MtString;
class MtVector3;
class cArcLoaderBase;
class cSndPitchLimitData;
class rSndPitchLimit;
class rSoundAreaInfo;
class rSoundAttributeSe;
class rSoundHitInfo;
class rSoundOptData;
class rSoundParamOfs;
class rSoundRequest;
class rSoundStreamRequest;
class rSoundSubMixer;
class rSoundSubMixerSet;
class uCoord;
class uDDOModel;
class uModel;
class uSoundOcclusion;
class uSoundSubMixer;

// Declarations
class cSplitBgm;
class sSoundExt;

// Type aliases from DWARF
using u32 = unsigned int;
using ARC_TAGID = u32;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using TICKET = cArcLoaderBase*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using __uintptr_t = __uint64_t;
using f32 = float;
using s32 = int;
using s8 = signed char;
using size_t = _Sizet;
using u64 = __uint64_t;
using uintptr = __uintptr_t;

class cSplitBgm : public MtObject
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
    cSplitBgm();
    void setAreaResource(rSoundAreaInfo* pResource);
    rSoundAreaInfo* getAreaResource();
    void setThisId(uintptr thisId);
    uintptr getThisId();
    void setAreaNo(s8 AreaNo);
    s8 getAreaNo();
    bool isBgmChange(rSoundStreamRequest* pResource);
public:
    rSoundAreaInfo* mpAreaInfo;  // offset: 0x8
    uintptr mThisId;  // offset: 0x10
    s32 mAreaNo;  // offset: 0x18
    static MyDTI DTI;
};

class sSoundExt : public sSound
{
public:
    enum SE_SEARCH_KEY
    {
        SE_SEARCH_KEY_RESOURCE = 0,
        SE_SEARCH_KEY_RESOURCE_REQNO = 1,
        SE_SEARCH_KEY_THISID = 2,
        SE_SEARCH_KEY_ALL = 3,
    };
    enum STREAM_SEARCH_KEY
    {
        STREAM_SEARCH_KEY_RESOURCE = 0,
        STREAM_SEARCH_KEY_RESOURCE_REQNO = 1,
        STREAM_SEARCH_KEY_THISID = 2,
        STREAM_SEARCH_KEY_ALL = 3,
        STREAM_SEARCH_KEY_UCOORD = 4,
    };
    enum
    {
        CALLBACK_TYPE_SETUP = 0,
        CALLBACK_TYPE_ONCE = 1,
        CALLBACK_TYPE_EVERY = 2,
    };
    enum
    {
        SOUND_AMB_NO_CHANGE = 0,
        SOUND_AMB_BASE_CHANGE = 1,
        SOUND_AMB_DAY_CHANGE = 2,
        SOUND_AMB_NIGHT_CHANGE = 3,
        SOUND_AMB_WEATHER_CHANGE = 4,
    };
    enum
    {
        SE_CALL_REJECT = -3,
        EQ_INDEX_NO_SET = -2,
        EQ_INDEX_STD = -1,
        EQ_INDEX_0 = 0,
        EQ_INDEX_1 = 1,
        EQ_INDEX_2 = 2,
        EQ_INDEX_INTERSECT = 3,
    };
    enum
    {
        SOUND_INTERSECT_EQ_ON = 0,
        SOUND_INTERSECT_EQ_OFF = 1,
    };
    enum
    {
        LISTENER_MODE_SCREEN = 0,
    };
    enum
    {
        OPT_CATEGORY_SYSTEM = 0,
        OPT_CATEGORY_VOICE = 1,
        OPT_CATEGORY_BGM = 2,
        OPT_CATEGORY_SE = 3,
        OPT_CATEGORY_ALL = 4,
        OPT_CATEGORY_NUM = 5,
    };
    enum
    {
        OPT_VOL_SE_00 = 0,
        OPT_VOL_SE_01 = 1,
        OPT_VOL_SE_02 = 2,
        OPT_VOL_SE_03 = 3,
        OPT_VOL_SE_04 = 4,
        OPT_VOL_SE_05 = 5,
        OPT_VOL_SE_06 = 6,
        OPT_VOL_SE_07 = 7,
        OPT_VOL_SE_NUM = 8,
    };
    enum
    {
        PARAM_OFS_VOLUME = 0,
        PARAM_OFS_PITCH_SHIFT = 1,
        PARAM_OFS_PROGRAM_NO = 2,
        PARAM_OFS_PRIORITY = 3,
        PARAM_OFS_GLOBAL = 4,
        PARAM_OFS_ID1 = 5,
        PARAM_OFS_ID2 = 6,
        PARAM_OFS_ID3 = 7,
        PARAM_OFS_LIMIT = 8,
        PARAM_OFS_CENTER_VOL = 9,
        PARAM_OFS_VOLUME_CURVE_ID = 10,
        PARAM_OFS_EFFECT_CURVE_ID = 11,
        PARAM_OFS_LFE_CURVE_ID = 12,
        PARAM_OFS_DIRECTIONAL_CURVE_ID = 13,
        PARAM_OFS_SUBMIXSER = 14,
        PARAM_OFS_NUM = 15,
    };
    enum
    {
        SOUND_DISTANCE_REJECT_ON = 0,
        SOUND_DISTANCE_REJECT_OFF = 1,
    };
    enum
    {
        SOUND_EQ_DISTANCE_ON = 0,
        SOUND_EQ_DISTANCE_OFF = 1,
    };
    enum GAME_VOLUME_FADE_CTR
    {
        GAME_VOLUME_FADE_IDLE = 0,
        GAME_VOLUME_FADE_IN = 1,
        GAME_VOLUME_FADE_OUT = 2,
    };
    enum
    {
        OPT_VOL_SYSTEM_00 = 0,
        OPT_VOL_SYSTEM_01 = 1,
        OPT_VOL_SYSTEM_02 = 2,
        OPT_VOL_SYSTEM_03 = 3,
        OPT_VOL_SYSTEM_04 = 4,
        OPT_VOL_SYSTEM_05 = 5,
        OPT_VOL_SYSTEM_06 = 6,
        OPT_VOL_SYSTEM_07 = 7,
        OPT_VOL_SYSTEM_NUM = 8,
    };
    enum
    {
        OPT_VOL_VOICE_00 = 0,
        OPT_VOL_VOICE_01 = 1,
        OPT_VOL_VOICE_02 = 2,
        OPT_VOL_VOICE_03 = 3,
        OPT_VOL_VOICE_04 = 4,
        OPT_VOL_VOICE_05 = 5,
        OPT_VOL_VOICE_06 = 6,
        OPT_VOL_VOICE_07 = 7,
        OPT_VOL_VOICE_NUM = 8,
    };
    enum
    {
        OPT_VOL_BGM_00 = 0,
        OPT_VOL_BGM_01 = 1,
        OPT_VOL_BGM_02 = 2,
        OPT_VOL_BGM_03 = 3,
        OPT_VOL_BGM_04 = 4,
        OPT_VOL_BGM_05 = 5,
        OPT_VOL_BGM_06 = 6,
        OPT_VOL_BGM_07 = 7,
        OPT_VOL_BGM_NUM = 8,
    };
public:
    class MyDTI;
    class cVoiceRequest;
    class cNonStopStream;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cVoiceRequest : public MtObject
    {
    public:
        enum
        {
            VOICE_TYPE_NONE = 0,
            VOICE_TYPE_NPC = 1,
            VOICE_TYPE_PAWN = 2,
            VOICE_TYPE_CHAT = 3,
            VOICE_TYPE_NUM = 4,
        };
        enum
        {
            VOICE_STATUS_NONE = 0,
            VOICE_STATUS_PLAY = 1,
            VOICE_STATUS_PAUSE = 2,
            VOICE_STATUS_STOP = 3,
            VOICE_STATUS_CANSEL = 4,
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
        cVoiceRequest();
        virtual ~cVoiceRequest();
        void setResource(rSoundStreamRequest* pResource);
        rSoundStreamRequest* getResource();
        void setReqNo(u32 reqNo);
        u32 getReqNo();
        void setVoiceType(u32 voiceType);
        u32 getVoiceType();
        void setThisId(uintptr thisId);
        uintptr getThisId();
        void setStatus(u32 status);
        u32 getStatus();
        void setPrepareType(bool);
        bool isPrepareType();
        void setHandle(u32 handle);
        u32 getHandle();
        void setPrio(u32 prio);
        u32 getPrio();
        bool sortByPrio(const sSoundExt::cVoiceRequest* src, const sSoundExt::cVoiceRequest* dst, u32 param);
    public:
        rSoundStreamRequest* mpResource;  // offset: 0x8
        u32 mReqNo;  // offset: 0x10
        u32 mVoiceType;  // offset: 0x14
        uintptr mThisId;  // offset: 0x18
        u32 mPrio;  // offset: 0x20
        u32 mHandleId;  // offset: 0x24
        bool mIsPrepare;  // offset: 0x28
        u32 mStatus;  // offset: 0x2c
        static MyDTI DTI;
    };
public:
    class cNonStopStream : public MtObject
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
        cNonStopStream();
        // Address: 0x01acf6b0 - 0x01acf6b1 (1 bytes)
        virtual ~cNonStopStream() {}
        void setStreamRequest(rSoundStreamRequest* pRequest, const MtDTI* pdti);
        rSoundStreamRequest* getStreamRequest();
        const MtDTI* getDTI();
    private:
        rSoundStreamRequest* mpNoStopStream;  // offset: 0x8
        const MtDTI* mpNoStopStreamDTI;  // offset: 0x10
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
    sSoundExt(u32 efx0, u32 efx1, sSound::SOUNDDRIVER_INIT_PARAM* pParams);
    virtual ~sSoundExt();
    void init();
    virtual void move();  // vtable slot 7
    virtual void setup();  // vtable slot 11
    virtual void reset();  // vtable slot 6
    void requestSeEx(rSoundRequest* pRequest, u32 reqNo, MtObject* thisId);
    void requestSeEx(rSoundRequest* pRequest, u32 reqNo, MtObject* thisId, const MtVector3& position);
    void requestSeEx(rSoundRequest* pRequest, u32 reqNo, MtObject* thisId, const MtVector3& position, const MtQuaternion& quaternion);
    void requestSeEx(rSoundRequest* pRequest, u32 reqNo, MtObject* thisId, const uCoord* pCoord, s32 jointNo);
    uintptr requestSe(rSoundRequest* pRequest, u32 reqNo, uintptr thisId, u32 paramIndex, sSound::CALLBACK_FUNC cb, void* arg);
    uintptr requestSe(rSoundRequest* pRequest, u32 reqNo, uintptr thisId, const MtVector3& position, u32 paramIndex, sSound::CALLBACK_FUNC cb, void* arg);
    uintptr requestSe(rSoundRequest* pRequest, u32 reqNo, uintptr thisId, const MtVector3& position, const MtQuaternion& quaternion, u32 paramIndex, sSound::CALLBACK_FUNC cb, void* arg);
    uintptr requestSe(rSoundRequest* pRequest, u32 reqNo, uintptr thisId, const uCoord* pCoord, s32 jointNo, u32 paramIndex, sSound::CALLBACK_FUNC cb, void* arg);
    void keyOffSe(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, SE_SEARCH_KEY searchKey);
    void stopAllSe();
private:
    s32 getRandomPitch(s32 index);
    void checkRandomRequest(rSoundRequest* pRequest, u32 reqNo, uintptr thisId);
    bool checkVolumeZero(rSoundRequest* pRequest, u32 reqNo, uintptr thisId, const MtVector3& position);
    bool checkVolumeZero(rSoundRequest* pRequest, u32 reqNo, uintptr thisId, const MtVector3& position, const MtQuaternion& quaternion);
    bool checkVolumeZero(rSoundRequest* pRequest, u32 reqNo, uintptr thisId, const MtVector3& position, const uCoord* pCoord, s32 jointNo);
public:
    uintptr requestStream(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, sSound::CALLBACK_FUNC cb, void* arg);
    uintptr requestStreamEx(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, sSound::CALLBACK_FUNC cb, void* arg);
    uintptr requestStream(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, const MtVector3& position, sSound::CALLBACK_FUNC cb, void* arg);
    uintptr requestStream(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, const MtVector3& position, const MtQuaternion& quaternion, sSound::CALLBACK_FUNC cb, void* arg);
    uintptr requestStream(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, const uCoord* pCoord, s32 jointNo, sSound::CALLBACK_FUNC cb, void* arg);
    void stopStream(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, STREAM_SEARCH_KEY searchKey);
    void stopAllStream();
    void fadeInStream(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, u32 fadeSpd);
    void fadeOutStream(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, u32 fadeSpd, STREAM_SEARCH_KEY searchKey);
    void stopAllStreamToFade();
    u32 getPlayPos(rSoundStreamRequest* pr, const u32 reqNo, const uintptr thisId);
    void setPlayPos(rSoundStreamRequest* pr, const u32 reqNo, const uintptr thisId, u32 playPos);
    void playPositionStream(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, u32 sample, STREAM_SEARCH_KEY searchKey);
    void pauseStream(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, STREAM_SEARCH_KEY searchKey);
    void resumeStream(rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, STREAM_SEARCH_KEY searchKey);
    void pauseAllStream();
    void resumeAllStream();
    bool checkStreamVoice();
    bool checkStreamVoice(rSoundStreamRequest* pr, const u32 reqNo);
    bool isEventStreamReady();
    bool checkPrepareStream(rSoundStreamRequest* pRequest, u32 reqNo);
    bool checkPlayStream(rSoundStreamRequest* pRequest, u32 reqNo);
    bool isPrepareOK(rSoundStreamRequest* pr, u32 reqNo);
    rSoundAttributeSe* loadAttributeSeResource();
    u32 getScrAttributeSeIdfromBase(u32 attr);
    u32 getSoundAttSeIndex(sCollision::TriangleInfo* pTriangle);
    rSoundHitInfo::cSoundHitInfo* getHitSeTableResource(u32 wepCategory, u32 attackType, u32 attackLevel, u32 attackReaction, u32 emCategory, bool isThrust);
    rSoundRequest* getHitSeSrqResource(u32 Surface);
    rSoundRequest* getHitSePlAddSrqResource();
private:
    void loadHitSeSrqResource();
    void loadHitSeTableResource();
    void releaseHitSeSrqResource();
    void releaseHitSeTableResource();
public:
    rSoundRequest* getArmorSeSrqResource(u32 SeType);
private:
    void loadArmorSeSrqResource();
    void releaseArmorSeSrqResource();
public:
    void requestEnchantSe(u32 enchantType, nWeapon::WEAPON_CATEGORY wepCategory, uDDOModel* pOwner, bool isStop, u32 lrType);
    rSoundRequest* getHitEnchantResource();
    rSoundRequest* getEnchantResource();
private:
    void setEnchantResource(rSoundRequest* pRequest);
    void releaseEnchantResource();
    u32 getEnchantSeReqNo(u32 enchantType, nWeapon::WEAPON_CATEGORY wepCategory, u32 lrType);
    void setHitEnchantResource(rSoundRequest* pRequest);
    void releaseHitEnchantResource();
public:
    void loadGameCommon();
    void loadBgmResource(bool isLobby, bool isSplit, rSoundAreaInfo* pInfo);
    void loadBattleCommon();
    void releaseGameCommon();
    void releaseBgmResource();
    void releaseBattleCommon();
    rSoundStreamRequest* getBattleBgmResource();
    rSoundStreamRequest* getEventBgmResource();
    rSoundStreamRequest* getFsmEvBgmResource();
    rSoundRequest* getGameBuffResource();
    rSoundRequest* getMagicResource();
    rSoundRequest* getEnemyShareSeResource();
    rSoundRequest* getShlJobShareResource();
private:
    void setMagicResource(rSoundRequest* pRequest);
    void releaseMagicResource();
    void setGameBuffResource(rSoundRequest* pRequest);
    void releaseGameBuffResource();
    void setShlJobShareResource(rSoundRequest* pRequest);
    void releaseShlJobShareResource();
    void setEnemyShareSeResource(rSoundRequest* pRequest);
    void releaseEnemyShareSeResource();
public:
    rSoundAreaInfo* getSoundAreaInfo(const MtVector3& targetPos);
    rSoundAreaInfo* getSoundAreaInfo(s8 areaNo);
    rSoundAreaInfo* getSAR(const MtVector3& targetPos);
    rSoundAreaInfo* getSoundAreaInfoToInn();
    rSoundRequest* getSndWepCategoryResource(u32 wepCategory);
    rSoundRequest* getSndWepResource(u32 itemId, u32 sex);
    cSndPitchLimitData* getSndPitchLimit(rSndPitchLimit* pRes, u32 voiceType, u32 sex);
    void loadCommonData();
    void releaseCommonData();
private:
    void setHmParamOfsResource(rSoundParamOfs* pParam);
    rSoundParamOfs* getHmParamOfsResource();
    void loadHmParamOfsResource();
    void releaseHmParamOfsResource();
    u32 getKindParamOfs(uModel* pModel);
    void setExtractParamOfs(rSoundRequest* pRequest, u32 reqNo, uintptr conThisId, u32 paramIndex);
    void setExVolumeParamOfs(rSoundRequest* pRequest, u32 reqNo, uintptr conThisId, u32 paramIndex);
    s32 getEditPitch(rSoundRequest* pRes, u32 reqNo, uModel* pModel);
public:
    f32 getParamOfsData(s32 index, u32 param);
private:
    void moveVoice();
    cVoiceRequest* requestVoiceCore(u32 voiceType, rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, const u32 handle);
public:
    u32 requestVoice(const u32 voiceType, rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, s32 pitch);
    u32 requestVoice(const u32 voiceType, rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, const MtVector3& position, s32 pitch);
    u32 requestVoice(const u32 voiceType, rSoundStreamRequest* pRequest, const u32 reqNo, const uintptr thisId, const uCoord* pCoord, s32 jointNo, s32 pitch);
    void requestPresetChatVoice(u32 voiceId, s32 memberIdx);
    void resumeVoice(const u32 handleId);
    u32 getVoiceStatus(const u32 handleId);
    void releaseRequestVoice();
    void releaseRequestVoice(const u32 handleId);
    rSoundRequest* loadPlVoiceSRQResource(u32 type, u32 no);
    rSoundRequest* loadPawnVoiceSRQResource(u32 type, u32 no, u32 personality);
    rSoundStreamRequest* loadChatVoiceStreamResource(u32 type, u32 no);
    rSoundStreamRequest* loadPawnVoiceStreamResource(u32 type, u32 no, u32 personality);
    ARC_TAGID createPawnVoiceArcTag(u32 type, u32 no, u32 personality);
    ARC_TAGID createPlVoiceArcTag(u32 type, u32 no);
    ARC_TAGID createPawnTalkVoiceArcTag(u32 type, u32 no);
    void createPlVoiceArcStr(MtString& rStr, u32 type, u32 no);
    void createPawnVoiceArcStr(MtString& rStr, u32 type, u32 no, u32 personality);
    void loadBgmSplitAreaResource(rSoundAreaInfo* pRes, s8 AreaNo, uintptr thisId);
    void releaseBgmSplitAreaResource(uintptr thisId);
    cSplitBgm* getSplitAreaBgmInfo(s8 areaNo);
    rSoundStreamRequest* getNowAreaBgmSrq(u64 resID);
    void moveArea();
    void setSePause(bool bpause);
    void moveShareNG();
private:
    s32 checkDistance(rSoundRequest* pRequest, u32 reqNo, const MtVector3& position);
    s32 getEQbyDist(f32 dist);
public:
    void setEQDistToArea(u32 i, f32 dist);
    void moveAmbientVolumeChange(u32 hour, f32 changeDb, u32 changeType, sSound::VoiceAccessor& va);
    void moveWeatherVolumeChange(sSound::VoiceAccessor& va);
    void changeSubMixer(u32 no);
private:
    void moveSubMixer();
    void checkSubMixerSet(rSoundRequest* pRequest, u32 reqNo);
    void checkSubMixerSet(rSoundStreamRequest* pRequest, u32 reqNo);
    rSoundSubMixerSet* getSoundSubMixerSetResource();
    void setSubMixerResource();
    void setSoundSubMixerSetResource(rSoundSubMixerSet* pResource);
    void releaseSoundSubMixerSetResource();
    void releaseSubMixerResource();
    void moveSoundZoneCtrl();
public:
    bool isGlobalTriggerZoneOut();
    bool isGlobalGeneratorZoneOut();
    void setGlobalTriggerZoneOut(bool isOut);
    void setGlobalGeneratorZoneOut(bool isOut);
    void setGlobalOcclusionZoneOut(bool isOut);
    void setOtherGeneratorZoneIn(bool isIn);
    void setOtherTriggerZoneIn(bool isIn);
private:
    void moveListeningPosition();
    uintptr convertThisID(rSoundRequest* pRequest, u32 reqNo, uintptr thisId);
    uintptr convertThisID(rSoundStreamRequest* pRequest, u32 reqNo, uintptr thisId);
    uintptr checkParentFreeArea(rSoundRequest* pRequest, u32 reqNo, uintptr thisId);
    uintptr checkFreeAreaSetting(rSoundRequest* pRequest, u32 reqNo, uintptr thisId);
public:
    void setSeVolumeRatio(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, f32 volume, bool isLink);
    void setSeEffectVolumeRatio(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, f32 volume, bool isLink);
    void setSeVolumeOfAllRatio(rSoundRequest* pRequest, const u32 reqNo, const uintptr thisId, f32 volume, bool isLink);
    rSoundStreamRequest* getNoStopStream(const MtDTI* pdti);
    void addNoStopStreamArcTicket(ARC_TAGID tagId);
    bool isNoStopStreamArcLoadFinish();
    void returnTicketNoStopAtream();
    bool setNoStopStream(rSoundStreamRequest* pRequest, const MtDTI* pdti);
    bool releaseNoStopStream(rSoundStreamRequest* pRequest);
    void releaseNoStopStreamAll();
    cNonStopStream* checkNoStopStream();
    cNonStopStream* checkNoStopStream(rSoundStreamRequest* pRequest);
    void stopAllStreamEx();
private:
    void initNoStopStream();
    void moveVolume();
    void moveVolumeCtrl();
public:
    bool calcOptionVolumeRate(sSound::VoiceAccessor& va, f32* pRate);
    bool calcOptionVolumeRate(rSoundRequest* pRequest, u32 reqNo, f32* pRate);
    void setOptVolumeFromSaveData();
    void initMasterVolumeParam();
    void setMasterVolumeParam(u32 fadeType, f32 fadeTime, f32 volume);
    void setOptionVolume(sSound::VoiceAccessor& va);
    void setOptVolume(u32 category, u32 item, f32 vol);
private:
    void loadOptionDataResource();
    void releaseOptionDataResource();
    bool searchOptionChannel(u32& category, u32& item, s32 channel);
    f32 getOptVolume(u32 category, u32 item);
private:
    rSoundRequest* mprHitSeRequest[12];  // offset: 0x48010
    rSoundRequest* mprHitSePlAddRequest;  // offset: 0x48070
    rSoundHitInfo* mprHitInfoResource[15];  // offset: 0x48078
    rSoundHitInfo* mprHitInfoEmResource[3];  // offset: 0x480f0
    rSoundRequest* mprArmorSeRequest[8];  // offset: 0x48108
    rSoundRequest* mprEnchantRequest;  // offset: 0x48148
    rSoundRequest* mprHitEnchantRequest;  // offset: 0x48150
public:
    rSoundStreamRequest* mprStageBgmRequest;  // offset: 0x48158
    rSoundStreamRequest* mprBattleBgmRequest;  // offset: 0x48160
    rSoundStreamRequest* mprFsmEvBgmRequest;  // offset: 0x48168
    rSoundRequest* mprMagicRequest;  // offset: 0x48170
    rSoundRequest* mprGameBuffRequest;  // offset: 0x48178
    rSoundRequest* mprEnemyShareRequest;  // offset: 0x48180
    rSoundRequest* mprShlJobShareRequest;  // offset: 0x48188
private:
    rSoundParamOfs* mprHmParamOfs;  // offset: 0x48190
    MtTypedArray<cVoiceRequest> mVoiceRequest;  // offset: 0x48198
    u32 mVoiceRequestHandleCtr;  // offset: 0x481b8
public:
    bool mbPLPos;  // offset: 0x481bc
    MtVector3 mPLPos;  // offset: 0x481c0
    MtTypedArray<cSplitBgm> mStageSplitAreaResource;  // offset: 0x481d0
    uSoundOcclusion* mpuOCC;  // offset: 0x481f0
    bool mbShareNG;  // offset: 0x481f8
private:
    f32 mEqLength[4];  // offset: 0x481fc
    uSoundSubMixer* mpSoundSubMixer;  // offset: 0x48210
    rSoundSubMixerSet* mprSoundSubMixerSet;  // offset: 0x48218
    rSoundSubMixer* mprSoundSubMixer;  // offset: 0x48220
    bool mIsGlobalGeneratorZoneOut;  // offset: 0x48228
    bool mIsGlobalTriggerZoneOut;  // offset: 0x48229
    bool mIsGlobalOcclusionZoneOut;  // offset: 0x4822a
    bool mIsOtherGeneratorZoneIn;  // offset: 0x4822b
    bool mIsOtherTriggerZoneIn;  // offset: 0x4822c
    u32 mListenerMode;  // offset: 0x48230
    cNonStopStream mNoStopStream[8];  // offset: 0x48238
    TICKET mBgmSystemTicket;  // offset: 0x482f8
    rSoundOptData* mprOptionData;  // offset: 0x48300
    f32 mGameVolCtrlVolume;  // offset: 0x48308
    f32 mSeMasterVolume;  // offset: 0x4830c
    f32 mBgmMasterVolume;  // offset: 0x48310
    f32 mEnvMasterVolume;  // offset: 0x48314
    f32 mVoiceMasterVolume;  // offset: 0x48318
    f32 mSystemMasterVolume;  // offset: 0x4831c
    u32 mGameVolCtrlFadeStatus;  // offset: 0x48320
    f32 mGameVolCtrlFadeTime;  // offset: 0x48324
    f32 mGameVolCtrlFadeVolumeRatio;  // offset: 0x48328
    f32 mGameVolCtrlFadeTargetVolume;  // offset: 0x4832c
    f32 mGameVolCtrlFadeVolume;  // offset: 0x48330
    f32 mLocalVolume[5][8];  // offset: 0x48334
public:
    static MyDTI DTI;
private:
    static const u32 SOUND_LINK_RANDOM_FREE_NO = 0;
    static const u32 SOUND_VOLUME_ZERO_FREE_NO = 3;
public:
    static const u32 INVALID_REQ_NO = 4294967295;
    static const u32 SAMPLE_RATE = 96000;
    static const u32 STREAM_STOP_FADE_TIME = 300;
private:
    static const u32 EM_HIT_TABLE_NUM = 3;
    static const u32 SOUND_EDIT_PITCH_FREE_NO = 4;
public:
    static const u32 PARAM_OFS_WORK_CALLBACK_TYPE = 1;
    static const u32 MAX_VOICE_STOCK_NUM = 7;
    static const u32 VOICE_WORK_CALLBACK_TYPE = 0;
    static const u32 SOUND_INTERSECT_FREE_NO = 1;
    static const u32 SOUND_INTERSECT_EQ_FREE_NO = 2;
private:
    static const u32 SOUND_EQ_DISTANCE_FREE_NO = 8;
    static const u32 SOUND_DISTANCE_REJECT_FREE_NO = 7;
public:
    static const u32 SOUND_AMB_DAY_AND_NIGHT = 9;
    static const u32 AMB_DAY_TO_NIGHT_START = 17;
    static const u32 AMB_DAY_TO_NIGHT_END = 18;
    static const u32 AMB_NIGHT_TO_DAY_START = 5;
    static const u32 AMB_NIGHT_TO_DAY_END = 6;
private:
    static const u32 SOUND_SUBMIXER_TABLE_ID_FREE_NO = 11;
    static const u32 SOUND_FADER_ID_FREE_NO = 10;
    static const u32 MAX_SUBMIXER = 8;
    static const u32 SOUND_THIS_ID_FREE_NO = 6;
    static const u32 SOUND_PARENT_FREE_NO = 5;
    static const u32 SOUND_RESOURCE_FREE_PLAY_ID = 4294967294;
public:
    static const u32 NO_STOP_STREAM_ENTRY_MAX = 8;
};

// Inline, no code of its own: checked where it is inlined.
inline cSplitBgm::cSplitBgm() {
    this->mThisId = static_cast<uintptr>(0);
    this->mpAreaInfo = static_cast<rSoundAreaInfo*>(nullptr);
    this->mAreaNo = static_cast<s32>(-1);
}

// Inline, no code of its own: checked where it is inlined.
inline rSoundRequest* sSoundExt::getGameBuffResource() {
    return this->mprGameBuffRequest;
}

// Inline, no code of its own: checked where it is inlined.
inline sSoundExt::cVoiceRequest::cVoiceRequest() {
    this->mpResource = static_cast<rSoundStreamRequest*>(nullptr);
    this->mReqNo = static_cast<u32>(4294967295);
    this->mVoiceType = static_cast<u32>(0);
    this->mThisId = static_cast<uintptr>(0);
    this->mIsPrepare = false;
    this->mStatus = static_cast<u32>(3);
    this->mPrio = static_cast<u32>(0);
    this->mHandleId = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline rSoundStreamRequest* sSoundExt::cNonStopStream::getStreamRequest() {
    return this->mpNoStopStream;
}
