#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive3D.h"
#include "uSoundZoneBase.h"

// Forward declarations
class MtAABB;
class MtAllocator;
class MtDTI;
class MtLineSegment;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
class cDraw;
class cSoundZoneListener;
class cZoneLayout;
namespace nZone { class ShapeInfoPanel; }
namespace nZone { class cLayoutElement; }
class rZone;

// Declarations
class cSoundOcclusionLayoutInfo;
class cSoundOcclusionListener;
namespace nSoundOcclusion { class cBaseContents; }
namespace nSoundOcclusion { class cCategory; }
namespace nSoundOcclusion { class cFreeWorkContents; }
class uSoundOcclusion;

namespace nSoundOcclusion {
    enum OPTION
    {
        OPTION_NONE = 0,
        OPTION_DYNAMIC_MOVE = 1,
        OPTION_FLIP = 2,
    };
}  // namespace nSoundOcclusion

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s16 = short;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class cSoundOcclusionLayoutInfo : public cSoundLayoutInfo
{
public:
    enum USE_TYPE
    {
        USE_TYPE_NONE = 0,
        USE_TYPE_STATIC = 1,
        USE_TYPE_DYNAMIC = 2,
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
    cSoundOcclusionLayoutInfo();
    virtual ~cSoundOcclusionLayoutInfo();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void setContentsIndex(nZone::cLayoutElement* pLayout);  // vtable slot 7
    virtual s32 getContentsIndex(u32 index);  // vtable slot 8
    USE_TYPE getUseType() const;
    void setUseType(USE_TYPE type);
    u16 getBoundingBoxIndex() const;
    void setBoundingBoxIndex(u16 index);
    u16 getHollowManagerIndex() const;
    void setHollowManagerIndex(u16 index);
protected:
    u32 mUseType;  // offset: 0x14
    u16 mBoundingBoxIndex;  // offset: 0x18
    s16 mHollowManagerIndex;  // offset: 0x1a
    s32 mContentsIndex[2];  // offset: 0x1c
public:
    static MyDTI DTI;
};

class cSoundOcclusionListener : public cSoundZoneListener
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
    cSoundOcclusionListener();
    virtual ~cSoundOcclusionListener();
    virtual void notified(const nZone::cLayoutElement& e);  // vtable slot 6
public:
    static MyDTI DTI;
};

namespace nSoundOcclusion {
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
}  // namespace nSoundOcclusion

namespace nSoundOcclusion {
    class cFreeWorkContents : public nSoundOcclusion::cCategory
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
    public:
        s32 mFreeWork[4];  // offset: 0x1c
        static MyDTI DTI;
        static const u32 FREE_WORK_NUM = 4;
    };
}  // namespace nSoundOcclusion

class uSoundOcclusion : public uSoundZoneBase
{
public:
    enum HIT_TRIANGLE_TYPE
    {
        HIT_TRIANGLE_NONE = 0,
        HIT_TRIANGLE_301 = 1,
        HIT_TRIANGLE_231 = 2,
    };
public:
    class MyDTI;
    class cBoundingBox;
    class cHollowManager;
    struct HIT_PANEL_INFO;
    class cOcclusionGroupManager;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cBoundingBox : public MtObject
    {
    public:
        class MyDTI;
        struct BoundingWork;
        struct PairWork;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        struct BoundingWork
        {
        public:
            BoundingWork();
            static void* operator new(size_t);
            static void* operator new[](size_t sz);
            static void operator delete(void*);
            static void operator delete[](void* padr);
        public:
            u32 PairIndex[2];  // offset: 0x0
            MtAABB AABB;  // offset: 0x10
        };
    public:
        struct PairWork
        {
        public:
            PairWork();
            static void* operator new(size_t);
            static void* operator new[](size_t sz);
            static void operator delete(void*);
            static void operator delete[](void* padr);
        public:
            bool IsEnd;  // offset: 0x0
            bool IsSetBounding;  // offset: 0x1
            u32 MyLayoutIndex;  // offset: 0x4
            u32 NearWorkIndex;  // offset: 0x8
            f32 NearDist;  // offset: 0xc
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
        cBoundingBox();
        cBoundingBox(uSoundOcclusion::cBoundingBox& src);
        virtual ~cBoundingBox();
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void createAllBoundingBox(cZoneLayout* pZone);
        void createStaticBoundingBox(cZoneLayout* pZone);
        void createDynamicBoundingBox(cZoneLayout* pZone);
        BoundingWork* getStaticBounding();
        BoundingWork* getDynamicBounding();
        u16 getStaticBoundingNum();
        u16 getDynamicBoundingNum();
        bool* checkHitBounding(BoundingWork* pBounding, u32 boundingNum, const MtLineSegment& line);
        void checkHitBounding(BoundingWork* pBounding, bool* hitFlagArray, u32 boundingNum, const MtLineSegment& line);
        uSoundOcclusion::cBoundingBox& operator=(const uSoundOcclusion::cBoundingBox& src);
    protected:
        PairWork* createPairWork(cZoneLayout* pZone, bool isDynamic, u32* pPairWorkNum);
        BoundingWork* createBoundingBox(cZoneLayout* pZone, PairWork* pairWork, const u32 pairWorkNum, u16* pBoundingNum);
        void calcSetAABB(cZoneLayout* pZone, BoundingWork* pBoundingWork);
        MtVector3 checkGetMin(const MtVector3& a, const MtVector3& b, const MtVector3& c, const MtVector3& d) const;
        MtVector3 checkGetMax(const MtVector3& a, const MtVector3& b, const MtVector3& c, const MtVector3& d) const;
    protected:
        BoundingWork* mpStaticBoundingArray;  // offset: 0x8
        BoundingWork* mpDynamicBoundingArray;  // offset: 0x10
        u16 mStaticBoundingNum;  // offset: 0x18
        u16 mDynamicBoundingNum;  // offset: 0x1a
    public:
        static MyDTI DTI;
        static const u32 INDEX_NONE = 4294967295;
    };
public:
    class cHollowManager : public MtObject
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
        cHollowManager();
        virtual ~cHollowManager();
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        s16 getHollowID() const;
        void setHollowID(s16 id);
        s16 getMaxVolumeRate() const;
        void setMaxVolumeRate(s32 rate);
        u32 getZoneLayoutIndex(u32 ArrayIndex) const;
        void setZoneLayoutIndex(u32 index, u32 ArrayIndex) const;
        u32 getZoneLayoutIndexNum() const;
        void setZoneLayoutIndexNum(u32 num);
        void swapZoneLayoutIndex(u32 index0, u32 index1);
    private:
        s16 mHollowId;  // offset: 0x8
        s16 mMaxVolumeRate;  // offset: 0xa
        u32* mpIndexArray;  // offset: 0x10
        u32 mIndexArrayNum;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
public:
    struct HIT_PANEL_INFO
    {
    public:
        uSoundOcclusion::HIT_TRIANGLE_TYPE HitType;  // offset: 0x0
        MtVector3 HitPos;  // offset: 0x10
    };
public:
    class cOcclusionGroupManager : public uSoundZoneBase::cGroupManager
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
        cOcclusionGroupManager();
        virtual ~cOcclusionGroupManager();
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
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
    uSoundOcclusion();
    virtual ~uSoundOcclusion();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    virtual const MtDTI* getGroupManagerDTI() const;  // vtable slot 26
    virtual cSoundZoneListener* getZoneListener();  // vtable slot 27
    virtual MtVector3 getZoneListenerPos();  // vtable slot 28
    virtual void setZoneListenerPos(const MtVector3& NewListenerPos);  // vtable slot 29
    virtual void setupFromResource(rZone* pRes);  // vtable slot 24
    virtual void setupFromResource(rZone* pRes, const MtVector3& pos);  // vtable slot 25
    cHollowManager* getHollowManager(u32 index);
    cBoundingBox* getBoundingBox();
    f32 calcOcclusionVolumeRate(const MtVector3& listenerPos, const MtVector3& requestPos);
protected:
    virtual void errorCheckZoneLayout(cZoneLayout* pZone);  // vtable slot 31
    f32 calcOcclusionVolumeRateSub(const MtLineSegment& line, cBoundingBox::BoundingWork* boundingArray, const u32 arrayNum, bool* pIsHit);
    f32 occlusionSurrounding(nZone::ShapeInfoPanel* pPanel, nSoundOcclusion::cBaseContents* pContents, const HIT_PANEL_INFO& hitInfo);
    u32 checkHitHollow(cZoneLayout* pZone, nZone::cLayoutElement* pHitLayout, cSoundOcclusionLayoutInfo* pHitLayoutInfo, nSoundOcclusion::cBaseContents* pHitContents, const MtLineSegment& line, HIT_PANEL_INFO* pHitInfo);
    bool isHitPanelVsLine(const nZone::ShapeInfoPanel& Panel, const MtLineSegment& line, HIT_PANEL_INFO* pHitInfo) const;
    bool followMatrixOcc();
    void createHollowManager(rZone* pRZone);
    void setMaxVolumeRateToHollowManagerAll(rZone* pRZone);
    void setUseTypeAll();
protected:
    cSoundOcclusionListener mZoneListener;  // offset: 0x100
    cBoundingBox mBoundingBox;  // offset: 0x140
    cHollowManager* mpHollowManager;  // offset: 0x160
    u16 mHollowManagerNum;  // offset: 0x168
    u32 mContentsIndex[2];  // offset: 0x16c
    bool mIsUseZoneSystemSpaceDivision;  // offset: 0x174
public:
    static MyDTI DTI;
};

namespace nSoundOcclusion {
    class cBaseContents : public nSoundOcclusion::cCategory
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
    public:
        nSoundOcclusion::OPTION mOption;  // offset: 0x1c
        s16 mHollowId;  // offset: 0x20
        s16 mHollowPriority;  // offset: 0x22
        f32 mVolumeRate;  // offset: 0x24
        f32 mSurroundDist[4];  // offset: 0x28
        static MyDTI DTI;
        static const s16 HOLLOW_ID_NONE = -1;
    };
}  // namespace nSoundOcclusion

inline void* cSoundOcclusionLayoutInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cSoundOcclusionListener::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cSoundOcclusionListener::cSoundOcclusionListener() {
}

inline void* nSoundOcclusion::cBaseContents::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* nSoundOcclusion::cCategory::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* nSoundOcclusion::cFreeWorkContents::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uSoundOcclusion::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uSoundOcclusion::cBoundingBox::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uSoundOcclusion::cBoundingBox::cBoundingBox() {
    this->mStaticBoundingNum = 0;
    this->mDynamicBoundingNum = 0;
    this->mpDynamicBoundingArray = nullptr;
    this->mpStaticBoundingArray = nullptr;
}

inline void* uSoundOcclusion::cHollowManager::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uSoundOcclusion::cHollowManager::cHollowManager() {
    this->mHollowId = 0;
    this->mIndexArrayNum = 0;
    this->mpIndexArray = nullptr;
    this->mMaxVolumeRate = 0;
}

inline void* uSoundOcclusion::cOcclusionGroupManager::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uSoundOcclusion::cOcclusionGroupManager::cOcclusionGroupManager() {
}
