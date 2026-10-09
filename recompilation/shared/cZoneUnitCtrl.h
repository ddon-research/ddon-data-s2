#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "nDDOUtility.h"
#include "nZoneUnitCtrl.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtPropertyList;
class MtVector3;
namespace nZone { class cLayoutElement; }

// Declarations
class cZoneUnitCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s16 = short;
using s32 = int;
using s8 = signed char;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cZoneUnitCtrl : public MtObject
{
public:
    enum
    {
        CKZONE_TYPE_NONE = 0,
        CKZONE_TYPE_OM = 1,
        CKZONE_TYPE_FM = 2,
        CKZONE_TYPE_NUM = 3,
    };
    enum
    {
        OM_CONTENTS_0 = 0,
        OM_CONTENTS_1 = 1,
        OM_CONTENTS_2 = 2,
        OM_CONTENTS_3 = 3,
        OM_CONTENTS_4 = 4,
        OM_CONTENTS_5 = 5,
        OM_CONTENTS_6 = 6,
        OM_CONTENTS_7 = 7,
        OM_CONTENTS_MAX = 8,
    };
public:
    class MyDTI;
    union unZoneGroup;
public:
    using cOmContentsArray = nDDOUtility::cArray<cZoneUnitCtrl::unZoneGroup, 8>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    union unZoneGroup
    {
    public:
        struct
        {
        public:
            s8 handle;  // offset: 0x0
            s8 group;  // offset: 0x1
        };  // offset: 0x0
        s16 all;  // offset: 0x0
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
    cZoneUnitCtrl();
    virtual ~cZoneUnitCtrl();
    void initZoneUnitCtrl(const MtVector3& pos, ZONE_UNIT_CTRL_TYPE type, u32 ckType);
    void initZoneUnitCtrlStg(u32 zoneHandle, u32 ckType);
    void clearZoneUnitCtrl();
    bool checkZone();
    void checkZoneUnitCtrl();
    bool isInited() const;
    u32 getLocalGroupNum() const;
protected:
    bool checkZoneCore();
    void callbackNotified(const nZone::cLayoutElement& e, u32 handle);
    bool isOmContentsArrayCheck(const cOmContentsArray& a, s32 aNum, const cOmContentsArray& b, s32 bNum, ZONE_UNIT_CTRL_TYPE CtrlType) const;
    bool isOmContentsArrayCheckNoHandle(const cOmContentsArray& a, s32 aNum, const cOmContentsArray& b, s32 bNum) const;
public:
    virtual void createPropertyForScrlModel(MtPropertyList& s);  // vtable slot 6
private:
    cOmContentsArray mLocalGroupID;  // offset: 0x8
    s8 mLocalGroupNum;  // offset: 0x18
    u8 mZoneUnitCtrlType;  // offset: 0x19
    u8 mCkZoneType;  // offset: 0x1a
    bool mCheckZoneRet;  // offset: 0x1b
    bool mNoCheckHandle;  // offset: 0x1c
public:
    static MyDTI DTI;
};
