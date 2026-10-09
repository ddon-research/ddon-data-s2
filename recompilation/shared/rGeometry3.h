#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "cResource.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtStream;
namespace nCollision { class cGeometryJointGroup; }

// Declarations
class rGeometry3;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class rGeometry3 : public cResource
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
    rGeometry3();
    virtual ~rGeometry3();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void clear();  // vtable slot 15
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    nCollision::cGeometryJointGroup* getGeometryGroupFromIndex(u32 TargetIndex);
    nCollision::cGeometryJointGroup* getGeometryGroupFromID(u32 TargetID);
    const nCollision::cGeometryJointGroup* getGeometryGroupFromIndexConst(u32 TargetIndex) const;
    u32 getGeometryGroupNum() const;
    bool isEnableMotionSequenceSync() const;
    void* memAlloc(u32 s);
    void memFree(void* padr);
protected:
    u32 getGroupUniqueIDForIO(u32 UniqueIDIndex);
    void setGroupUniqueIDForIO(u32 UniqueID, u32 UniqueIDIndex);
    u32 getGroupUniqueIDNumForIO();
    void setGroupUniqueIDNumForIO(u32 UniqueIDNum);
protected:
    MtArray mGroupArray;  // offset: 0x70
    u32* mpUniqueIDTable;  // offset: 0x90
    u32 mUniqueIDNum;  // offset: 0x98
    bool mFlgEnableMotionSequence;  // offset: 0x9c
public:
    static MyDTI DTI;
    static const u32 MAGIC = 862938471;
    static const u32 VERSION = 2010111900;
};
