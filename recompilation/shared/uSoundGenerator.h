#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "uSoundZoneBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
class cSoundZoneListener;
class cZoneLayout;
namespace nSoundGenerator { class cSeqSeContents; }
namespace nZone { class cLayoutElement; }
class rSoundRequest;
class rSoundStreamRequest;
class uSoundSequenceSe;

// Declarations
class cSoundGeneratorListener;
class uSoundGenerator;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cSoundGeneratorListener : public cSoundZoneListener
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
    cSoundGeneratorListener();
    virtual ~cSoundGeneratorListener();
    virtual void notified(const nZone::cLayoutElement& e);  // vtable slot 6
public:
    static MyDTI DTI;
};

class uSoundGenerator : public uSoundZoneBase
{
public:
    class MyDTI;
    class cGeneratorGroupManager;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cGeneratorGroupManager : public uSoundZoneBase::cGroupManager
    {
    public:
        class MyDTI;
        class cSoundPlayInfomation;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class cSoundPlayInfomation : public MtObject
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
            cSoundPlayInfomation();
            virtual ~cSoundPlayInfomation();
            virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
            virtual void createProperty(MtPropertyList& s);  // vtable slot 4
            void update();
            const MtVector3& getRequestPos() const;
            void setRequestPos(const MtVector3& NewRequestPos);
            s32 getLayoutUniqueId() const;
            void setLayoutUniqueId(s32 NewUniqueID);
            uSoundSequenceSe* getSequenceSeUnit() const;
            void setSequenceSeUnit(uSoundSequenceSe* pNewUnit);
        private:
            void updateSequenceSeUnit();
        private:
            MtVector3 mRequestPos;  // offset: 0x10
            s32 mLayoutUniqueId;  // offset: 0x20
            uSoundSequenceSe* mpUSequenceSe;  // offset: 0x28
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
        cGeneratorGroupManager();
        virtual ~cGeneratorGroupManager();
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void update();
        const MtVector3& getRequestPos(nZone::cLayoutElement& NowLayout) const;
        void setRequestPos(const MtVector3& NewRequestPos, nZone::cLayoutElement& NowLayout);
        s32 getLayoutUniqueId(nZone::cLayoutElement& NowLayout) const;
        void setLayoutUniqueId(nZone::cLayoutElement& NowLayout);
        void clearLayoutUniqueId(nZone::cLayoutElement& NowLayout);
        uSoundSequenceSe* getSequenceSeUnit(nZone::cLayoutElement& NowLayout) const;
        uSoundSequenceSe* makeSequenceSeUnit(nZone::cLayoutElement& NowLayout);
        const MtVector3& getRequestPosForDefault() const;
        void setRequestPosForDefault(const MtVector3& NewRequestPos);
        s32 getLayoutUniqueIdForDefault() const;
        void setLayoutUniqueIdForDefault(s32 NewUniqueID);
        uSoundSequenceSe* getSequenceSeUnitForDefault() const;
        void setSequenceSeUnitForDefault(uSoundSequenceSe* pNewUnit);
        const MtVector3& getRequestPosForNonGroup(u32 index) const;
        void setRequestPosForNonGroup(const MtVector3& NewRequestPos, u32 index);
        s32 getLayoutUniqueIdForNonGroup(u32 index) const;
        void setLayoutUniqueIdForNonGroup(s32 NewUniqueID, u32 index);
        uSoundSequenceSe* getSequenceSeUnitForNonGroup(u32 index) const;
        void setSequenceSeUnitForNonGroup(uSoundSequenceSe* pNewUnit, u32 index);
    private:
        virtual void evRegisterResource();  // vtable slot 7
        cSoundPlayInfomation* getPlayInfomation(u32 index);
        u32 getPlayInfomationNum() const;
    protected:
        cSoundPlayInfomation* mpPlayInfomation;  // offset: 0x38
    public:
        static MyDTI DTI;
        static const s32 LAYOUT_UNIQUEID_NONE = -1;
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
    uSoundGenerator();
    virtual ~uSoundGenerator();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void move();  // vtable slot 9
    virtual void sync();  // vtable slot 11
    virtual const MtDTI* getGroupManagerDTI() const;  // vtable slot 26
    virtual cSoundZoneListener* getZoneListener();  // vtable slot 27
    virtual MtVector3 getZoneListenerPos();  // vtable slot 28
    virtual void setZoneListenerPos(const MtVector3& NewListenerPos);  // vtable slot 29
    void allStopNowRequest();
    s32 getOcclusionMoveLine();
    void setOcclusionMoveLine(s32);
protected:
    void generateMain();
    void allStopNowRequestForGroup(cGeneratorGroupManager& TargetGroupManager);
    void allStopNowRequestForNonGroup(cGeneratorGroupManager& TargetGroupManager);
    void allStopNowRequestCommon(cGeneratorGroupManager& TargetGroupManager, u32 PlayLayoutUniqueID);
    void generate(cZoneLayout& MyZoneLayout, cGeneratorGroupManager& TargetGroupManager, nZone::cLayoutElement& TargetLayoutElement, const MtVector3& pos);
    void requestSe(rSoundRequest* pRequest, u32 reqNo, u32 thisId, const MtVector3& pos);
    void requestStream(rSoundStreamRequest* pRequest, u32 reqNo, u32 thisId, const MtVector3& pos, s32 free0, s32 free1);
    void playSequenceSe(nZone::cLayoutElement* pLayout, nSoundGenerator::cSeqSeContents* pContents, const MtVector3& pos);
    void keyOffSe(rSoundRequest* pRequest, u32 reqNo, u32 thisId);
    void stopStream(rSoundStreamRequest* pRequest, u32 reqNo, u32 thisId, s32 free0, s32 free1);
    void stopSequenceSe(nZone::cLayoutElement* pLayout);
    void setSePosition(rSoundRequest* pRequest, u32 reqNo, u32 thisId, const MtVector3& pos);
    void setStreamPosition(rSoundStreamRequest* pRequest, u32 reqNo, u32 thisId, const MtVector3& pos);
    void setSequenceSePosition(nZone::cLayoutElement* pLayout, const MtVector3& pos);
    s32 checkInLayout(cGeneratorGroupManager* pGroupManager);
    bool isHitLayout(const nZone::cLayoutElement& TargetLayoutElement) const;
    void checkLayoutPosDist(cGeneratorGroupManager* pGroupManager, const MtVector3& listenerPos, nZone::cLayoutElement* * ppLayout, MtVector3* pPos);
    void calcLayoutPosDistMain(const nZone::cLayoutElement& TargetLayout, const MtVector3& pos, MtVector3& NearPos, f32& Dist);
    void setZoneListener();
protected:
    cSoundGeneratorListener mZoneListener;  // offset: 0x100
    s32 mOcclusionMoveLine;  // offset: 0x140
public:
    static MyDTI DTI;
    static const s32 OCC_MOVE_LINE_ALL = -1;
};

// Inline, no code of its own: checked where it is inlined.
inline cSoundGeneratorListener::cSoundGeneratorListener() {
}

// Inline, no code of its own: checked where it is inlined.
inline uSoundGenerator::cGeneratorGroupManager::cGeneratorGroupManager() {
    this->mpPlayInfomation = static_cast<uSoundGenerator::cGeneratorGroupManager::cSoundPlayInfomation*>(nullptr);
}
