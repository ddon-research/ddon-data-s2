#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
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
namespace nSoundTrigger { class cBaseContents; }
namespace nSoundTrigger { class cCategory; }
namespace nSoundTrigger { class cPlaySeqSeContents; }
namespace nSoundTrigger { class cSeContents; }
namespace nSoundTrigger { class cStopSeqSeContents; }
namespace nSoundTrigger { class cStreamContents; }
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
using s16 = short;
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

namespace nSoundTrigger {
    class cCategory : public nSoundZoneBase::cSoundZoneContents
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
        cCategory();
        virtual ~cCategory();
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    public:
        static MyDTI DTI;
    };
}  // namespace nSoundTrigger

namespace nSoundTrigger {
    class cPlaySeqSeContents : public nSoundTrigger::cCategory
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
        cPlaySeqSeContents();
        virtual ~cPlaySeqSeContents();
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void copyAToB();
        void copyBToA();
        rSoundSequenceSe* getSequenceSeResourceA() const;
        void setSequenceSeResourceA(rSoundSequenceSe*);
        rSoundSequenceSe* getSequenceSeResourceB() const;
        void setSequenceSeResourceB(rSoundSequenceSe*);
    private:
        rSoundSequenceSe* mpSequenceSeA;  // offset: 0x20
        rSoundSequenceSe* mpSequenceSeB;  // offset: 0x28
    public:
        static MyDTI DTI;
    };
}  // namespace nSoundTrigger

namespace nSoundTrigger {
    class cSeContents : public nSoundTrigger::cCategory
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
        cSeContents();
        virtual ~cSeContents();
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void copyAToB();
        void copyBToA();
        u32 getRequestNoA() const;
        void setRequestNoA(u32);
        u32 getRequestNoB() const;
        void setRequestNoB(u32);
        rSoundRequest* getRequestResourceA() const;
        void setRequestResourceA(rSoundRequest*);
        rSoundRequest* getRequestResourceB() const;
        void setRequestResourceB(rSoundRequest*);
    private:
        u32 mRequestNoA;  // offset: 0x1c
        u32 mRequestNoB;  // offset: 0x20
        rSoundRequest* mpRequestA;  // offset: 0x28
        rSoundRequest* mpRequestB;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nSoundTrigger

namespace nSoundTrigger {
    class cStopSeqSeContents : public nSoundTrigger::cCategory
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
        cStopSeqSeContents();
        virtual ~cStopSeqSeContents();
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void copyAToB();
        void copyBToA();
        s16 getStopGroupId(nSoundTrigger::ARRAY_TYPE type, u32 TargetIndex) const;
        void setStopGroupId(nSoundTrigger::ARRAY_TYPE, s16, u32);
    private:
        s16 mStopGroupId[2][4];  // offset: 0x1a
    public:
        static MyDTI DTI;
        static const u32 STOP_SEQUENCESE_NUM = 4;
        static const s16 STOP_SEQUENCESE_ID_NONE = -1;
        static const s16 STOP_SEQUENCESE_ID_ALL = -2;
    };
}  // namespace nSoundTrigger

namespace nSoundTrigger {
    class cStreamContents : public nSoundTrigger::cCategory
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
        cStreamContents();
        virtual ~cStreamContents();
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void copyAToB();
        void copyBToA();
        u32 getStreamRequestNoA() const;
        void setStreamRequestNoA(u32);
        u32 getStreamRequestNoB() const;
        void setStreamRequestNoB(u32);
        rSoundStreamRequest* getStreamRequestResourceA() const;
        void setStreamRequestResourceA(rSoundStreamRequest*);
        rSoundStreamRequest* getStreamRequestResourceB() const;
        void setStreamRequestResourceB(rSoundStreamRequest*);
    private:
        u32 mStreamRequestNoA;  // offset: 0x1c
        u32 mStreamRequestNoB;  // offset: 0x20
        rSoundStreamRequest* mpStreamRequestA;  // offset: 0x28
        rSoundStreamRequest* mpStreamRequestB;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nSoundTrigger

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

namespace nSoundTrigger {
    class cBaseContents : public nSoundTrigger::cCategory
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
        cBaseContents();
        virtual ~cBaseContents();
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        u32 getOption() const;
        void setOption(u32);
    private:
        u32 mOption;  // offset: 0x1c
    public:
        static MyDTI DTI;
    };
}  // namespace nSoundTrigger

inline void* cSoundTriggerLayoutInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cSoundTriggerListener::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cSoundTriggerListener::cSoundTriggerListener() {
}

inline void* nSoundTrigger::cBaseContents::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* nSoundTrigger::cCategory::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* nSoundTrigger::cPlaySeqSeContents::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* nSoundTrigger::cSeContents::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* nSoundTrigger::cStopSeqSeContents::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* nSoundTrigger::cStreamContents::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uSoundTrigger::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uSoundTrigger::cTriggerGroupManager::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uSoundTrigger::cTriggerGroupManager::cTriggerGroupManager() {
    this->mHitCount = 0;
}
