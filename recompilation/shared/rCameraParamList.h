#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtString.h"
#include "cResource.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtStream;
class MtString;
class cCamExParam;
class rCameraList;

// Declarations
class rCameraParamList;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class rCameraParamList : public cResource
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
    rCameraParamList();
    virtual ~rCameraParamList();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void clear();  // vtable slot 15
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    const MtArray& getParamList() const;
    void setParamList(const MtArray& list);
    const cCamExParam* getParam(u32 index) const;
    rCameraList* getCameraListResource();
    void addPriority(u32 add);
protected:
    MtArray mParamList;  // offset: 0x70
    MtString mCameraListPath;  // offset: 0x90
    rCameraList* mprCameraList;  // offset: 0x98
public:
    static MyDTI DTI;
protected:
    static const u8 DATA_VERSION = 6;
};
