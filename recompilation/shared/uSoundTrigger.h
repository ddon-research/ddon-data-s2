#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "uSoundZoneBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtLineSegment;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
class cSoundZoneListener;
namespace nSoundTrigger { class cStopSeqSeContents; }
namespace nZone { class ShapeInfoPanel; }
namespace nZone { class cLayoutElement; }
class rSoundCurveSet;
class rSoundDirectionalSet;
class rSoundEQ;
class rSoundRequest;
class rSoundReverb;
class rSoundSequenceSe;
class rSoundStreamRequest;
class rSoundSubMixer;
class rZone;
class uCoord;
class uModel;
class uSoundSequenceSe;

// Declarations
class cSoundTriggerLayoutInfo;
class cSoundTriggerListener;
class uSoundTrigger;

namespace nSoundTrigger {
    enum ARRAY_TYPE
    {
        ARRAY_IN = 0,
        ARRAY_OUT = 1,
        ARRAY_NUM = 2,
    };
}  // namespace nSoundTrigger

namespace nSoundTrigger {
    enum PANEL_TYPE
    {
        PANEL_TYPE_NONE = 0,
        PANEL_TYPE_A = 1,
        PANEL_TYPE_B = 2,
    };
}  // namespace nSoundTrigger

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class cSoundTriggerLayoutInfo : public cSoundLayoutInfo
{
public:
    enum SEQSE_TYPE
    {
        SEQSE_IN = 0,
        SEQSE_OUT = 1,
        SEQSE_NUM = 2,
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
    cSoundTriggerLayoutInfo();
    virtual ~cSoundTriggerLayoutInfo();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void setContentsIndex(nZone::cLayoutElement* pLayout);  // vtable slot 7
    virtual s32 getContentsIndex(u32 index);  // vtable slot 8
    void checkPanelVsLine(const nZone::ShapeInfoPanel& panel, const MtLineSegment& line);
    void calcPanelNormal(nZone::ShapeInfoPanel* pShape);
    void checkSetPanelType(nZone::cLayoutElement* pLayout);
    nSoundTrigger::PANEL_TYPE getPanelType() const;
    MtVector3 getPanelNormal(u32) const;
    uSoundSequenceSe* getSequenceSeUnit(SEQSE_TYPE type);
    void setSequenceSeUnit(uSoundSequenceSe* pUnit, SEQSE_TYPE type);
    void updateSequenceSeUnit();
protected:
    uSoundSequenceSe* mpUSequenceSe[2];  // offset: 0x18
    MtVector3 mPanelNormal[2];  // offset: 0x30
    u32 mPanelType;  // offset: 0x50
    s32 mContentsIndex[11];  // offset: 0x54
public:
    static MyDTI DTI;
    static const u32 PANEL_NORMAL_NUM = 2;
};

class cSoundTriggerListener : public cSoundZoneListener
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
    cSoundTriggerListener();
    virtual ~cSoundTriggerListener();
    virtual void notified(const nZone::cLayoutElement& e);  // vtable slot 6
public:
    static MyDTI DTI;
};

class uSoundTrigger : public uSoundZoneBase
{
public:
    class MyDTI;
    class cTriggerGroupManager;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cTriggerGroupManager : public uSoundZoneBase::cGroupManager
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
        cTriggerGroupManager();
        virtual ~cTriggerGroupManager();
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    public:
        u16 mHitCount;  // offset: 0x38
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
    uSoundTrigger();
    virtual ~uSoundTrigger();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void sync();  // vtable slot 11
    virtual void setupFromResource(rZone* pRes);  // vtable slot 24
    virtual void setupFromResource(rZone* pRes, const MtVector3& pos);  // vtable slot 25
    virtual const MtDTI* getGroupManagerDTI() const;  // vtable slot 26
    virtual cSoundZoneListener* getZoneListener();  // vtable slot 27
    virtual MtVector3 getZoneListenerPos();  // vtable slot 28
    virtual void setZoneListenerPos(const MtVector3& NewListenerPos);  // vtable slot 29
    void clearZoneHit();
protected:
    void triggerMainInOut();
    void triggerMainThrough();
    void checkHitPanel();
    void initPanel();
    void updatePanel();
    void successIn(nZone::cLayoutElement& ListenerInLayout);
    void successOut(nZone::cLayoutElement& ListenerOutLayout);
    void stopSequenceSeFlow(nSoundTrigger::cStopSeqSeContents& contents, nSoundTrigger::ARRAY_TYPE ArrayType);
    void requestSe(rSoundRequest* pRequest, u32 reqNo);
    void requestStream(rSoundStreamRequest* pRequest, u32 reqNo, s32 free0, s32 free1, s32 free2);
    void setReverb(rSoundReverb* pReverb, u32 resId, u32 effectNo, u32 fadeTime);
    void setEQ(rSoundEQ* pEQ, u32 eqId, u32 fadeTime);
    void setSoundCurveSet(rSoundCurveSet* pCurveSet);
    void setDirectionalSet(rSoundDirectionalSet* pDirectionalSet);
    void setSubMixer(rSoundSubMixer* pSubMixer, u16 submixerId);
    void playSequenceSe(cSoundTriggerLayoutInfo* pLayoutInfo, rSoundSequenceSe* pSequenceSe, cSoundTriggerLayoutInfo::SEQSE_TYPE seqType);
    void stopSequenceSe(cSoundTriggerLayoutInfo* pLayoutInfo);
    uCoord* getAttachCoord();
    uModel* getAttachModel();
    void setZoneListener();
protected:
    cSoundTriggerListener mZoneListener;  // offset: 0x100
    MtVector3 mOldListenerPos;  // offset: 0x140
    bool mbCalledBaseBGM;  // offset: 0x150
    bool mbCalledCycleBGM;  // offset: 0x151
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cSoundTriggerListener::cSoundTriggerListener() {
}

// Inline, no code of its own: checked where it is inlined.
inline uSoundTrigger::cTriggerGroupManager::cTriggerGroupManager() {
    this->mHitCount = static_cast<u16>(0);
}
