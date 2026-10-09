#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "MtPrimitive3D.h"
#include "MtSynchronize.h"
#include "cAIObject.h"
#include "cZoneListener.h"
#include "nDDOUtility.h"
#include "rZone.h"
#include "res_ptr.h"

// Forward declarations
class MtAllocator;
class MtCriticalSection;
class MtDTI;
class MtLineSegment;
class MtObject;
class MtPropertyList;
class MtQuaternion;
class MtVector3;
class cZoneCategoryUnitCtrl;
namespace nZone { class ShapeInfoBase; }
namespace nZone { class cLayoutElement; }
class rZone;

// Declarations
class cZoneContactInfo;
class cZoneContactInfoList;
class cZoneContactPairInfo;
class cZoneListenerMulti;
class cZoneMultiListener;
class cZoneMultiStack;
class cZoneMultiStackNode;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using s8 = signed char;
using size_t = _Sizet;
using u32 = unsigned int;

class cZoneContactInfo : public MtObject
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
    cZoneContactInfo();
    // Address: 0x01a66b30 - 0x01a66b31 (1 bytes)
    virtual ~cZoneContactInfo() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void setHandle(s32 set);
    void setGroupId(s32 set);
    void setOffset(const MtVector3& set);
    s32 getHandle();
    s32 getGroupId();
    MtVector3& getOffset();
    bool isSameData(cZoneContactInfo* pData);
private:
    MtVector3 mOffset;  // offset: 0x10
    s32 mHandle;  // offset: 0x20
    s32 mGroupId;  // offset: 0x24
public:
    static MyDTI DTI;
};

class cZoneContactPairInfo : public MtObject
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
    cZoneContactPairInfo();
    // Address: 0x01a66af0 - 0x01a66af1 (1 bytes)
    virtual ~cZoneContactPairInfo() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void setBasicHandle(s32 set);
    void setBasicGroupId(s32 set);
    void setBasicOffset(const MtVector3& set);
    void setObjectHandle(s32 set);
    void setObjectGroupId(s32 set);
    void setObjectOffset(const MtVector3& set);
    s32 getBasicHandle();
    s32 getBasicGroupId();
    MtVector3& getBasicOffset();
    s32 getObjectHandle();
    s32 getObjectGroupId();
    MtVector3& getObjectOffset();
    cZoneContactInfo* getBasic();
    cZoneContactInfo* getObject();
    bool isContact(cZoneContactPairInfo* pData);
private:
    cZoneContactInfo mBasic;  // offset: 0x10
    cZoneContactInfo mObject;  // offset: 0x40
public:
    static MyDTI DTI;
};

class cZoneMultiListener : public cZoneListener
{
public:
    class MyDTI;
    struct stStack;
public:
    using CallbackFunc = void(MtObject::*)(const nZone::cLayoutElement&);
    using cStackArray = nDDOUtility::cArray<cZoneMultiListener::stStack, 48>;
    using cResultArray = nDDOUtility::cArray<cZoneMultiListener::stStack, 16>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stStack
    {
    public:
        stStack();
    public:
        const nZone::cLayoutElement* pElement;  // offset: 0x0
        u32 Handle;  // offset: 0x8
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
    cZoneMultiListener();
    virtual ~cZoneMultiListener();
    void setMyPos(const MtVector3& pos);
    void setMyLine(const MtLineSegment&);
    void moveMultiListener(cZoneMultiStack* pStack);
    u32 getLastHitNum() const;
    const nZone::cLayoutElement* getLastHit(u32 idx) const;
    u32 getLastHitHandle(u32 idx) const;
protected:
    virtual void notified(const nZone::cLayoutElement& e);  // vtable slot 6
    virtual MtVector3 myPos();  // vtable slot 7
    virtual MtLineSegment myLineSegment();  // vtable slot 8
private:
    MtObject* mpCallbackOwner;  // offset: 0x30
    CallbackFunc mpCallbackFunc;  // offset: 0x38
    cStackArray mNotifiedStack;  // offset: 0x48
    u32 mNotifiedStackNum;  // offset: 0x348
    MtVector3 mCheckPos;  // offset: 0x350
    MtLineSegment mCheckLine;  // offset: 0x360
    u32 mCheckHandle;  // offset: 0x380
    cResultArray mpLastHit;  // offset: 0x388
    u32 mLastHitNum;  // offset: 0x488
    bool mIsLine;  // offset: 0x48c
public:
    static MyDTI DTI;
};

class cZoneContactInfoList : public MtObject
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
    cZoneContactInfoList();
    virtual ~cZoneContactInfoList();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void initList();
    void addStartList(cZoneContactPairInfo* pSet);
    void addEndList(cZoneContactPairInfo* pSet);
    bool isContact(cZoneContactPairInfo* pData, MtTypedArray<cZoneContactPairInfo> Target);
    bool isContactStart(cZoneContactPairInfo* pData);
    bool isContactEnd(cZoneContactPairInfo* pData);
private:
    MtTypedArray<cZoneContactPairInfo> mContactPairListStart;  // offset: 0x8
    MtTypedArray<cZoneContactPairInfo> mContactPairListEnd;  // offset: 0x28
public:
    static MyDTI DTI;
};

class cZoneMultiStackNode : public cAIObject
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
    cZoneMultiStackNode();
    virtual ~cZoneMultiStackNode();
    void releaseZone();
    void setZone(rZone* pZone, const MtVector3& pos);
    void setZone(rZone* pZone, const MtVector3& pos, const MtQuaternion& quat);
    u32 getZoneHandle() const;
    rZone* getZoneRes();
    void resetZoneContactInfo();
    void addZoneContactInfoListStart(cZoneContactPairInfo* pSet);
    void addZoneContactInfoListEnd(cZoneContactPairInfo* pSet);
    bool isZoneContactStart(cZoneContactPairInfo* pData);
    bool isZoneContactEnd(cZoneContactPairInfo* pData);
private:
    u32 mZoneHandle;  // offset: 0x8
    res_ptr<rZone> mRes;  // offset: 0x10
    cZoneContactInfoList mZoneContactInfoList;  // offset: 0x18
public:
    static MyDTI DTI;
};

class cZoneMultiStack : public cAIObject
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
    cZoneMultiStack();
    virtual ~cZoneMultiStack();
    u32 addZone(rZone* pZone, const MtVector3& pos);
    u32 addZone(rZone* pZone, const MtVector3& pos, const MtQuaternion& quat);
    void releaseZone(rZone* pZone);
    void releaseZone(u32 handle);
    void releaseZoneAll();
    u32 getZoneNum() const;
    u32 getZoneHandle(u32 idx);
private:
    void resetZoneContactInfo();
    void createZoneContactInfo();
    void createZoneContactInfo(u32 BasicHandle, u32 ObjectHandle, u32 BasicIdx, u32 ObjectIdx);
    bool createZoneContactInfo(const nZone::cLayoutElement* BasicLERes, u32 ObjectHandle, s32 ObjectLinkType, cZoneContactPairInfo* dst);
    bool isContactShape(const nZone::ShapeInfoBase* pBasicShape, const nZone::ShapeInfoBase* pObjectShape, cZoneContactPairInfo* dst);
    cZoneCategoryUnitCtrl* getZoneCategoryUnitCtrl(const nZone::cLayoutElement* LERes);
public:
    void updateZoneContactInfo();
    bool isZoneContact(u32 BasicHandle, u32 ObjectHandle, s8 BasicGroupNo, s32 ObjectGroupNo);
private:
    MtTypedArray<cZoneMultiStackNode> mNotifiedStack;  // offset: 0x8
    MtCriticalSection mCS;  // offset: 0x28
public:
    static MyDTI DTI;
};

class cZoneListenerMulti : public cZoneMultiListener
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
    cZoneListenerMulti();
    virtual ~cZoneListenerMulti();
    void moveMultiListener();
    u32 addZone(rZone* pZone, const MtVector3& pos);
    u32 addZone(rZone* pZone, const MtVector3& pos, const MtQuaternion& quat);
    void releaseZone(rZone*);
    void releaseZone(u32 handle);
    void releaseZoneAll();
private:
    cZoneMultiStack mStack;  // offset: 0x490
public:
    static MyDTI DTI;
};
