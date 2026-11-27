#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
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
namespace nZone { class cLayoutElement; }
class rSoundRequest;
class rSoundSequenceSe;
class rSoundStreamRequest;
class uSoundSequenceSe;

// Declarations
class cSoundGeneratorLayoutInfo;
class cSoundGeneratorListener;
namespace nSoundGenerator { class cBaseContents; }
namespace nSoundGenerator { class cCategory; }
namespace nSoundGenerator { class cFreeWorkContents; }
namespace nSoundGenerator { class cSeContents; }
namespace nSoundGenerator { class cSeqSeContents; }
namespace nSoundGenerator { class cStreamContents; }
class uSoundGenerator;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cSoundGeneratorLayoutInfo : public cSoundLayoutInfo
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
    cSoundGeneratorLayoutInfo();
    virtual ~cSoundGeneratorLayoutInfo();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void setContentsIndex(nZone::cLayoutElement* pLayout);  // vtable slot 7
    virtual s32 getContentsIndex(u32 index);  // vtable slot 8
protected:
    s32 mContentsIndex[5];  // offset: 0x14
public:
    static MyDTI DTI;
};

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

namespace nSoundGenerator {
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
}  // namespace nSoundGenerator

namespace nSoundGenerator {
    class cFreeWorkContents : public nSoundGenerator::cCategory
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
        cFreeWorkContents();
        virtual ~cFreeWorkContents();
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual void createPropertyForUI(MtPropertyList& s);  // vtable slot 6
        s32 getFreeWork(u32 index) const;
        void setFreeWork(s32, u32);
    public:
        s32 mFreeWork[4];  // offset: 0x1c
        static MyDTI DTI;
        static const u32 FREE_WORK_NUM = 4;
    };
}  // namespace nSoundGenerator

namespace nSoundGenerator {
    class cSeContents : public nSoundGenerator::cCategory
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
        virtual void createPropertyForUI(MtPropertyList& s);  // vtable slot 6
        u32 getRequestNo() const;
        void setRequestNo(u32);
        rSoundRequest* getRequestResource() const;
        void setRequestResource(rSoundRequest*);
    private:
        u32 mRequestNo;  // offset: 0x1c
        rSoundRequest* mpRequest;  // offset: 0x20
    public:
        static MyDTI DTI;
    };
}  // namespace nSoundGenerator

namespace nSoundGenerator {
    class cSeqSeContents : public nSoundGenerator::cCategory
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
        cSeqSeContents();
        virtual ~cSeqSeContents();
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual void createPropertyForUI(MtPropertyList& s);  // vtable slot 6
        rSoundSequenceSe* getSequenceSeResource() const;
        void setSequenceSeResource(rSoundSequenceSe*);
    private:
        rSoundSequenceSe* mpSequenceSe;  // offset: 0x20
    public:
        static MyDTI DTI;
    };
}  // namespace nSoundGenerator

namespace nSoundGenerator {
    class cStreamContents : public nSoundGenerator::cCategory
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
        virtual void createPropertyForUI(MtPropertyList& s);  // vtable slot 6
        u32 getStreamRequestNo() const;
        void setStreamRequestNo(u32);
        rSoundStreamRequest* getStreamRequestResource() const;
        void setStreamRequestResource(rSoundStreamRequest*);
    private:
        u32 mStreamRequestNo;  // offset: 0x1c
        rSoundStreamRequest* mpStreamRequest;  // offset: 0x20
    public:
        static MyDTI DTI;
    };
}  // namespace nSoundGenerator

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

namespace nSoundGenerator {
    class cBaseContents : public nSoundGenerator::cCategory
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
        virtual void createPropertyForUI(MtPropertyList& s);  // vtable slot 6
        f32 getStopDistance() const;
        void setStopDistance(f32);
    private:
        f32 mStopDist;  // offset: 0x1c
    public:
        static MyDTI DTI;
    };
}  // namespace nSoundGenerator

inline void* cSoundGeneratorLayoutInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cSoundGeneratorLayoutInfo::cSoundGeneratorLayoutInfo() {
    this->mContentsIndex[4] = -1;
    this->mContentsIndex[2] = -1;
    this->mContentsIndex[3] = -1;
    this->mContentsIndex[0] = -1;
    this->mContentsIndex[1] = -1;
}

inline void* cSoundGeneratorListener::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cSoundGeneratorListener::cSoundGeneratorListener() {
}

inline void* nSoundGenerator::cBaseContents::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* nSoundGenerator::cCategory::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* nSoundGenerator::cFreeWorkContents::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* nSoundGenerator::cSeContents::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* nSoundGenerator::cSeqSeContents::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* nSoundGenerator::cStreamContents::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uSoundGenerator::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uSoundGenerator::cGeneratorGroupManager::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uSoundGenerator::cGeneratorGroupManager::cGeneratorGroupManager() {
    this->mpPlayInfomation = nullptr;
}

inline void* uSoundGenerator::cGeneratorGroupManager::cSoundPlayInfomation::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../XFramework/cZoneContents.h"

inline void* cSoundGeneratorLayoutInfo::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cSoundGeneratorLayoutInfo::DTI)->memAlloc(sz, align, ::cSoundGeneratorLayoutInfo::DTI.::MtDTI::getID());
}

inline void cSoundGeneratorLayoutInfo::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cSoundGeneratorLayoutInfo::DTI)->memFree(p_addr);
}

inline void* cSoundGeneratorListener::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cSoundGeneratorListener::DTI)->memAlloc(sz, align, ::cSoundGeneratorListener::DTI.::MtDTI::getID());
}

inline void cSoundGeneratorListener::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cSoundGeneratorListener::DTI)->memFree(p_addr);
}

inline void nSoundGenerator::cBaseContents::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nSoundGenerator::cBaseContents::DTI)->memFree(p_addr);
}

inline void nSoundGenerator::cCategory::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nSoundGenerator::cCategory::DTI)->memFree(p_addr);
}

inline nSoundGenerator::cCategory::cCategory() {
    this->::cZoneContents::setCategoryName("SoundGenerator");
    this->::cZoneContents::setExtendObjectDTI(::cSoundGeneratorLayoutInfo::DTI);
    this->::cZoneContents::setBroadPhaseSearchMode(2u);
    this->::cZoneContents::setAttribute(0x10000u, true);
}

inline void nSoundGenerator::cFreeWorkContents::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nSoundGenerator::cFreeWorkContents::DTI)->memFree(p_addr);
}

inline void nSoundGenerator::cSeContents::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nSoundGenerator::cSeContents::DTI)->memFree(p_addr);
}

inline void nSoundGenerator::cSeqSeContents::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nSoundGenerator::cSeqSeContents::DTI)->memFree(p_addr);
}

inline void nSoundGenerator::cStreamContents::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nSoundGenerator::cStreamContents::DTI)->memFree(p_addr);
}

inline MtAllocator* uSoundGenerator::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::uSoundGenerator::DTI);
}

inline void uSoundGenerator::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uSoundGenerator::DTI)->memFree(p_addr);
}

inline void* uSoundGenerator::cGeneratorGroupManager::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uSoundGenerator::cGeneratorGroupManager::DTI)->memAlloc(sz, align, ::uSoundGenerator::cGeneratorGroupManager::DTI.::MtDTI::getID());
}

inline void uSoundGenerator::cGeneratorGroupManager::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uSoundGenerator::cGeneratorGroupManager::DTI)->memFree(p_addr);
}

inline void* uSoundGenerator::cGeneratorGroupManager::cSoundPlayInfomation::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uSoundGenerator::cGeneratorGroupManager::cSoundPlayInfomation::DTI)->memAlloc(sz, align, ::uSoundGenerator::cGeneratorGroupManager::cSoundPlayInfomation::DTI.::MtDTI::getID());
}

inline void uSoundGenerator::cGeneratorGroupManager::cSoundPlayInfomation::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uSoundGenerator::cGeneratorGroupManager::cSoundPlayInfomation::DTI)->memFree(p_addr);
}

inline uSoundGenerator::cGeneratorGroupManager::cSoundPlayInfomation::cSoundPlayInfomation() {
    this->mRequestPos = ::MtVector3::Zero;
    this->mLayoutUniqueId = -1;
    this->mpUSequenceSe = nullptr;
}
