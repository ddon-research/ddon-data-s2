#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/MtString.h"
#include "cSetInfo.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
struct MtFloat3;
class MtMatrix;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtString;
class MtUI;
class MtVector3;
class cUnit;

// Declarations
class cSetInfoCoord;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cSetInfoCoord : public cSetInfo
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
    cSetInfoCoord();
    virtual ~cSetInfoCoord();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool load(MtDataReader& r);  // vtable slot 7
    virtual bool save(MtDataWriter& w);  // vtable slot 8
    virtual void createToolProperty(MtPropertyList& s);  // vtable slot 6
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual bool applyInfo(cUnit* pu) const;  // vtable slot 9
    virtual void copy(cSetInfo* p);  // vtable slot 11
    MT_CTSTR getcSetName() const;
    void setcSetName(const MtString& name);
    s32 getUnitID() const;
    void setUnitID(s32 id);
    virtual void setPosition(const MtVector3& pos);  // vtable slot 12
    virtual void setAngle(const MtVector3& ang);  // vtable slot 13
    s32 getAreaHitNo() const;
    u32 getVersion() const;
    void setVersion(u32);
    bool getOmitFlag() const;
    void setOmitFlag(bool);
    MtMatrix getMatrix();
    void setMatrix(MtMatrix& mat);
private:
    MtVector3 getPositionForProperty() const;
    void setPositionForProperty(const MtVector3& pos);
    MtVector3 getAngleForProperty() const;
    void setAngleForProperty(const MtVector3& angle);
    MtVector3 getScaleForProperty() const;
    void setScaleForProperty(const MtVector3& scale);
public:
    MtString mName;  // offset: 0x8
    MtFloat3 mPosition;  // offset: 0x10
    MtFloat3 mAngle;  // offset: 0x1c
    MtFloat3 mScale;  // offset: 0x28
    s32 mUnitID;  // offset: 0x34
    s32 mAreaHitNo;  // offset: 0x38
    u32 mVersion;  // offset: 0x3c
    s32 mTblIndex;  // offset: 0x40
    static MyDTI DTI;
};
