#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "MtString.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtPropertyList;
class MtString;
namespace nZone { class cLayoutElement; }

// Declarations
class cZoneContents;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cZoneContents : public MtObject
{
public:
    class MyDTI;
    struct stContentsDrawInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stContentsDrawInfo
    {
    public:
        stContentsDrawInfo(nZone::cLayoutElement*, bool, bool);
    public:
        nZone::cLayoutElement* mpOwnerLayoutElement;  // offset: 0x0
        bool mIsToolSelected;  // offset: 0x8
        bool mIsZTest;  // offset: 0x9
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
    cZoneContents();
    virtual ~cZoneContents();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createPropertyForUI(MtPropertyList& s);  // vtable slot 6
    virtual void copy(cZoneContents* pContents);  // vtable slot 7
    virtual bool copyResource(cZoneContents* pContents);  // vtable slot 8
    // Address: 0x01a65dc0 - 0x01a65dc1 (1 bytes)
    virtual void draw(const stContentsDrawInfo& info) {}  // vtable slot 9
    void createPropertyContentsBase(MtPropertyList& s);
    bool isLegacyContentsClass() const;
    bool isCategoryClass() const;
    bool isContentsClass(MT_CTSTR) const;
    bool isContentsClass() const;
    const MtString& getName() const;
    const MtString& getContensName() const;
    const MtString& getCategoryName() const;
    bool isUse() const;
    void setUse(bool flag);
    bool isNativeData() const;
protected:
    void setCategoryName(MT_CTSTR CategoryName);
    void setContentsName(MT_CTSTR ContentsName);
    void setAttribute(u32 attr);
    void setAttribute(u32 TargetAttribute, bool flag);
    void setBroadPhaseSearchMode(u32 SearchMode);
    void setDefaultShapeType(u32 DefaultShapeType);
    void setExtendObjectDTI(const MtDTI& NewExtendObjectDTI);
private:
    void copyMainFromGame(cZoneContents* pSourceContents);
protected:
    MtString mName;  // offset: 0x8
    MtString mCategoryName;  // offset: 0x10
    bool mFlgUse;  // offset: 0x18
    bool mIsNativeData;  // offset: 0x19
public:
    static MyDTI DTI;
    static const u32 ATTR_NONE = 0;
    static const u32 ATTR_EDIT_SHAPE_SPHERE = 1;
    static const u32 ATTR_EDIT_SHAPE_CAPSULE = 2;
    static const u32 ATTR_EDIT_SHAPE_CYLINDER = 4;
    static const u32 ATTR_EDIT_SHAPE_CONE = 8;
    static const u32 ATTR_EDIT_SHAPE_AABB = 16;
    static const u32 ATTR_EDIT_SHAPE_OBB = 32;
    static const u32 ATTR_EDIT_SHAPE_AREA = 64;
    static const u32 ATTR_EDIT_SHAPE_POINT = 128;
    static const u32 ATTR_EDIT_SHAPE_LINE = 256;
    static const u32 ATTR_EDIT_SHAPE_PANEL = 512;
    static const u32 ATTR_EDIT_SHAPE_GLOBAL = 1024;
    static const u32 ATTR_MULTIPLE_CONTENTS = 2048;
    static const u32 ATTR_ZONE_CONTENTS_GROUP = 4096;
    static const u32 ATTR_ZONE_SHAPE_GROUP = 8192;
    static const u32 ATTR_LOCK_USE_FLAG = 16384;
    static const u32 ATTR_COPY_SHALLOW_SHAPE = 32768;
    static const u32 ATTR_COPY_SHALLOW_CONTENTS = 65536;
    static const u32 ATTR_EDIT_SHAPE_CURVE_SURFACE = 15;
    static const u32 ATTR_EDIT_SHAPE_BOX = 112;
    static const u32 ATTR_EDIT_SHAPE_SPECIAL = 896;
    static const u32 ATTR_EDIT_SHAPE_ALL = 2047;
    static const u32 ATTR_DEFAULT = 6143;
    static const u32 ATTR_INVALID = 2147483648;
};

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline bool cZoneContents::isUse() const {
    return this->mFlgUse;
}
