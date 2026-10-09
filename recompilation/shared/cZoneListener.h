#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "cZoneLayout.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtGeomConvex;
class MtLineSegment;
class MtMatrix;
class MtPropertyList;
class MtVector3;
class cZoneLayout;
namespace nZone { class cLayoutElement; }
class sZone;

// Declarations
class cZoneListener;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cZoneListener : public MtObject
{
    // inferred: sZone::removeListener calls cZoneListener::unregisterTargetZoneLayout
    friend class sZone;
public:
    enum PRIORITY_RULE
    {
        PRIORITY_RULE_GROUP_ENABLE = 0,
        PRIORITY_RULE_ALL_ENABLE = 1,
        PRIORITY_RULE_DISABLE = 2,
        PRIORITY_RULE_NUM = 3,
        PRIORITY_RULE_DEFAULT = 1,
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
    cZoneListener();
    virtual ~cZoneListener();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    // Address: 0x01a66930 - 0x01a66931 (1 bytes)
    virtual void notified(const nZone::cLayoutElement& e) {}  // vtable slot 6
    virtual MtVector3 myPos();  // vtable slot 7
    virtual MtLineSegment myLineSegment();  // vtable slot 8
    virtual MtGeomConvex* myConvex();  // vtable slot 9
    const cZoneLayout* getZoneLayoutConst() const;
    cZoneLayout* getZoneLayout() const;
    const MtVector3& getZoneLayoutWorldOffset() const;
    bool isRotateZoneLayout() const;
    const MtMatrix& getZoneLayoutWorldMatrix() const;
    const MtMatrix& getZoneLayoutWorldInverseMatrix() const;
    u32 getZoneLayoutIndex() const;
    u32 getZoneLayoutHandle() const;
    bool isRegisterTargetGroupManager() const;
    cZoneLayout::cInGameGroupManager* getZoneLayoutInGameGroupManager() const;
    bool isEnableFilteringShapeType() const;
    u32 getTargetShapeType() const;
    void setTargetShapeType(u32);
    u32 getPriorityRuleType() const;
    void setPriorityRuleType(u32);
    bool isCallNotified() const;
    void setCallNotified(bool);
    bool isCallbackOnceContentsGroup() const;
    void setCallbackOnceContentsGroup(bool);
protected:
    void registerTargetZoneLayout(cZoneLayout& TargetZoneLayout, u32 TargetZoneLayoutIndex, u32 TargetZoneLayoutHandle);
    void unregisterTargetZoneLayout();
    void registerTargetGroupManager(cZoneLayout::cInGameGroupManager& TargetGroupManager);
    void unregisterTargetGroupManager();
    bool isCallContentsCallback() const;
    void setCallContentsCallback(bool);
protected:
    u32 mTargetZoneLayoutIndex;  // offset: 0x8
    u32 mTargetZoneLayoutHandle;  // offset: 0xc
    cZoneLayout* mpZoneLayout;  // offset: 0x10
    cZoneLayout::cInGameGroupManager* mpGroupManager;  // offset: 0x18
    u32 mTargetShapeType;  // offset: 0x20
    u32 mPriorityRuleType;  // offset: 0x24
    bool mFlgCallNotifiedFunction;  // offset: 0x28
    bool mFlgCallContentsCallbackFunction;  // offset: 0x29
    bool mFlgCallbackSingleCallContentsGroup;  // offset: 0x2a
public:
    static MyDTI DTI;
    static const u32 FILTERING_DISABLE_SHAPE = 4294967295;
};

// Inline, no code of its own: checked where it is inlined.
inline cZoneLayout* cZoneListener::getZoneLayout() const {
    return this->mpZoneLayout;
}
