#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "cPlatformUtilCommon.h"
#include "cSystem.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPoint;
class MtProperty;
class MtPropertyList;
class MtUI;
struct SceNpOnlineId;
class cGameLiveStream;
class cRemotePlay;
class cScreenshot;
class cSharePlay;
class cSystemService;
class cVideoRecorder;
namespace nPlatformUtil { namespace nSocialFeedback { struct FEEDBACK_COMMAND; } }
namespace nPlatformUtil { namespace nSocialFeedback { struct FEEDBACK_MESSAGE; } }

// Declarations
class sPlatformUtil;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
namespace nPlatformUtil { namespace nSharePlay { using OnlineId = SceNpOnlineId; } }
using u32 = unsigned int;
namespace nPlatformUtil { namespace nSocialFeedback { using EV_GAMELIVESTREAMING = void(MtObject::*)(const u32, const nPlatformUtil::nSocialFeedback::FEEDBACK_MESSAGE*, const u32, const nPlatformUtil::nSocialFeedback::FEEDBACK_COMMAND*); } }
using u8 = unsigned char;
namespace nPlatformUtil { namespace nSystemService { using EVENT = void(*)(const char*, const u32, const u8*, nPlatformUtil::nSystemService::CALL_TYPE::TYPE); } }
namespace nPlatformUtil { namespace nSystemService { using HANDLE = u32; } }
namespace nPlatformUtil { namespace nSystemService { using OBJECTEVENT = void(MtObject::*)(const char*, const u32, const u8*, nPlatformUtil::nSystemService::CALL_TYPE::TYPE); } }
using s32 = int;
using size_t = _Sizet;

class sPlatformUtil : public cSystem
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
    virtual void move();  // vtable slot 7
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    nPlatformUtil::nSystemService::HANDLE registrySystemServiceEvent(nPlatformUtil::nSystemService::EVENT_TYPE::TYPE type, MtObject* pobject, nPlatformUtil::nSystemService::OBJECTEVENT function);
    nPlatformUtil::nSystemService::HANDLE registrySystemServiceEvent(nPlatformUtil::nSystemService::EVENT_TYPE::TYPE type, nPlatformUtil::nSystemService::EVENT function);
    void unregistrySystemServiceEvent(const nPlatformUtil::nSystemService::HANDLE handle);
    bool isSystemServiceEnableEvent(nPlatformUtil::nSystemService::EVENT_TYPE::TYPE type) const;
    void hideSystemServiceSplashScreen(bool immediate);
    void setRemotePlayApprove(const bool enable);
    bool isRemotePlayApprove() const;
    bool isRemotePlayUserApprove(const s32 user_id);
    void setGameLiveStreamingPermit(bool enable);
    bool isGameLiveStreamingPermit() const;
    void setGameLiveStreamingEnable(bool enable);
    bool isGameLiveStreamingEnable() const;
    void setGameLiveStreamingServerSideRecording(bool enable);
    bool isGameLiveStreamingServerSideRecording() const;
    void setGameLiveStreamingStandbyScreenImage(MT_CTSTR path);
    void setGameLiveStreamingCameraFrameSetting(const nPlatformUtil::nGameLiveStram::POSTYPE::TYPE postype, float alpha);
    void postGameLiveStreamingMessage(MT_CTSTR mes);
    bool isGameLiveStreamingOnAir() const;
    void setGameLiveStreamingMaxBitrate(const u32 bitrate);
    void setSocialFeedbackEnable(bool enable);
    bool isSocialFeedbackEnable() const;
    void setSocialFeedbackEvent(MtObject* pobj, nPlatformUtil::nSocialFeedback::EV_GAMELIVESTREAMING function);
    void setSocialFeedbackRefreshInterval(const u32 sec);
    void clearSocialFeedbackCommand();
    void setSocialFeedbackCommandDescription(MT_CTSTR mes);
    void setSocialFeedbackCommand(const u32 no, const u32 id, MT_CTSTR mes);
    void setSocialFeedbackCommandCount(const u32 count);
    void setSharePlayApproveMode(const nPlatformUtil::nSharePlay::APPROVE_MODE::TYPE type);
    nPlatformUtil::nSharePlay::APPROVE_MODE::TYPE getApproveMode() const;
    nPlatformUtil::nSharePlay::STATUS::TYPE getStatus() const;
    nPlatformUtil::nSharePlay::CONTROLLER_MODE::TYPE getControllerMode() const;
    const nPlatformUtil::nSharePlay::OnlineId& getHostOnlineId();
    const nPlatformUtil::nSharePlay::OnlineId& getVisitorOnlineId();
    s32 getHostUserId() const;
    s32 getVisitorUserId() const;
    void setScreenshotOverlayImage(MT_CTSTR path, u32 offset_x, u32 offset_y);
    void setScreenshotOverlayImage(MT_CTSTR path, const MtPoint& point);
    bool startVideoRecorder(MT_CTSTR name, s32 rec_time);
    bool stopVideoRecorder();
    void setEnable(const bool enable, const u32 flags);
    static sPlatformUtil* getInstance();
    static sPlatformUtil* createInstance();
    static void deleteInstance();
private:
    sPlatformUtil();
    virtual ~sPlatformUtil();
    void onLiveStremingUpdate(const char* pparam, const u32 size, const u8* parg, nPlatformUtil::nSystemService::CALL_TYPE::TYPE call_type);
    void hideSplashScreen();
private:
    cSystemService* mpSystemService;  // offset: 0x18
    cRemotePlay* mpRemotePlay;  // offset: 0x20
    cGameLiveStream* mpGameLiveStream;  // offset: 0x28
    cScreenshot* mpScreenshot;  // offset: 0x30
    cVideoRecorder* mpVideoRecorder;  // offset: 0x38
    cSharePlay* mpSharePlay;  // offset: 0x40
    s32 mHideSplashScreenFrame;  // offset: 0x48
public:
    static MyDTI DTI;
private:
    static sPlatformUtil* mpInstance;
};

inline sPlatformUtil* sPlatformUtil::getInstance() {
    return ::sPlatformUtil::mpInstance;
}
