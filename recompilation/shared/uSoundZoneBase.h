#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "cUnit.h"
#include "cZoneExtendObject.h"
#include "cZoneLayout.h"
#include "cZoneListener.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtMatrix;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtQuaternion;
class MtUI;
class MtVector3;
class cZoneLayout;
namespace nZone { class ShapeInfoBase; }
namespace nZone { class cLayoutElement; }
class rZone;
class uModel;

// Declarations
class cSoundLayoutInfo;
class cSoundZoneListener;
class uSoundZoneBase;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class cSoundLayoutInfo : public cZoneExtendObject
{
public:
    enum ZONE_HIT
    {
        ZONE_HIT_NONE = 0,
        ZONE_HIT_IN = 1,
        ZONE_HIT_IN_OLD = 2,
        ZONE_HIT_THROUGH_A = 4,
        ZONE_HIT_THROUGH_B = 8,
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
    cSoundLayoutInfo();
    virtual ~cSoundLayoutInfo();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void evChangeEnable(bool flag);  // vtable slot 6
    // Address: 0x01b25d40 - 0x01b25d41 (1 bytes)
    virtual void setContentsIndex(nZone::cLayoutElement* pLayout) {}  // vtable slot 7
    virtual s32 getContentsIndex(u32 index);  // vtable slot 8
    void onZoneHit(ZONE_HIT bit);
    void offZoneHit(ZONE_HIT bit);
    bool checkZoneHit(ZONE_HIT bit) const;
    bool isInZoneHit() const;
    bool isOutToInZoneHit() const;
    bool isInToOutZoneHit() const;
    const nZone::ShapeInfoBase* getOriginalShape();
protected:
    u32 mZoneHit;  // offset: 0x10
public:
    static MyDTI DTI;
    static const s32 CONTENTS_INDEX_NONE = -1;
};

class cSoundZoneListener : public cZoneListener
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
    cSoundZoneListener();
    virtual ~cSoundZoneListener();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtVector3 myPos();  // vtable slot 7
    virtual void setMyPos(const MtVector3& pos);  // vtable slot 10
protected:
    MtVector3 mMyPos;  // offset: 0x30
public:
    static MyDTI DTI;
};

class uSoundZoneBase : public cUnit
{
public:
    class MyDTI;
    class cGroupManager;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cGroupManager : public cZoneLayout::cInGameGroupManager
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
        cGroupManager();
        virtual ~cGroupManager();
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
    uSoundZoneBase();
    virtual ~uSoundZoneBase();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void setup();  // vtable slot 6
    virtual void sync();  // vtable slot 11
    virtual void setupFromResource(rZone* pRes);  // vtable slot 24
    virtual void setupFromResource(rZone* pRes, const MtVector3& pos);  // vtable slot 25
    virtual const MtDTI* getGroupManagerDTI() const;  // vtable slot 26
    virtual cSoundZoneListener* getZoneListener();  // vtable slot 27
    virtual MtVector3 getZoneListenerPos();  // vtable slot 28
    virtual void setZoneListenerPos(const MtVector3& NewListenerPos);  // vtable slot 29
    virtual cSoundLayoutInfo* getLayoutInfo(u32 index);  // vtable slot 30
    void setModel(uModel* pModel, u8 jntNo);
    uModel* getModel();
    u8 getParentJntNo();
    cZoneLayout* getZoneLayout();
    nZone::cLayoutElement* getLayoutFromUniqueId(cZoneLayout* pZone, u32 uniqueId);
    u32 getZoneHandle();
    cGroupManager* getGroupManager(u32 index);
    u32 getGroupManagerNum();
    void setEnableGroup(bool flag, cGroupManager* pManager);
    void setEnableGroup(bool, u16);
    void setQuat(MtQuaternion& quat);
protected:
    // Address: 0x01b25570 - 0x01b25571 (1 bytes)
    virtual void errorCheckZoneLayout(cZoneLayout* pZone) {}  // vtable slot 31
    // Address: 0x01b25580 - 0x01b25581 (1 bytes)
    virtual void disableGroupProc(cGroupManager* pGroupManager) {}  // vtable slot 32
    cGroupManager* getGroupManagerFromLayout(nZone::cLayoutElement* pLayoutElement);
    cGroupManager* getGroupManagerFromGroupId(s32 groupId);
public:
    void updateZoneHit();
    void clearZoneHit();
protected:
    void followMatrix();
    void followQuatMatrix();
    void multipleShape(nZone::ShapeInfoBase* pDstShape, const nZone::ShapeInfoBase* pSrcShape, const MtMatrix& mat);
public:
    MtQuaternion mQuat;  // offset: 0x50
protected:
    u32 mZoneHandle;  // offset: 0x60
    uModel* mpParentModel;  // offset: 0x68
    u8 mParentJntNo;  // offset: 0x70
    MtMatrix mFollowMatrix;  // offset: 0x80
    MtMatrix mFollowMatrixOld;  // offset: 0xc0
public:
    static MyDTI DTI;
    static const u32 CONTENTS_NAME_LEN_MAX = 32;
    static const u32 CATEGORY_NAME_LEN_MAX = 32;
    static const u16 ID_TO_INDEX_TABLE_NONE = 65535;
};
