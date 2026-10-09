#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/MtString.h"
#include "../shared/cResource.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtStream;
class MtString;
class cShlParamBase;

// Declarations
class cShlGroupParam;
class rShlParamList;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cShlGroupParam : public MtObject
{
public:
    enum
    {
        SE_OP_NONE = 0,
        SE_OP_PL_RESOURCE = 1,
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
    cShlGroupParam();
    virtual ~cShlGroupParam();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    const cShlGroupParam& operator=(const cShlGroupParam&);
    void copy(const cShlGroupParam* pGroup);
    void setup();
    const cShlParamBase* getParam(u32 index) const;
    void setEpvPath(const MtString&, u32);
    void setSePath(const MtString&, u32);
    void setColPath(const MtString&);
    MT_CTSTR getEpvPath(u32 no) const;
    MT_CTSTR getSePath(u32 no) const;
    MT_CTSTR getColPath() const;
    u32 getEpvPathNum() const;
    u32 getSePathNum() const;
    void setEpvPathNum(u32);
    void setSePathNum(u32);
    u32 getSEOption() const;
    u32 getParamNum() const;
public:
    MtArray mShlList;  // offset: 0x8
    MtString name;  // offset: 0x28
    MtString epvPath[2];  // offset: 0x30
    MtString sePath[2];  // offset: 0x40
    MtString colPath;  // offset: 0x50
    u32 ddoVersion;  // offset: 0x58
    u32 seOption;  // offset: 0x5c
    bool isNoArc;  // offset: 0x60
    static MyDTI DTI;
    static const u32 PATH_NUM = 2;
};

class rShlParamList : public cResource
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
    rShlParamList();
    rShlParamList(const rShlParamList&);
    virtual ~rShlParamList();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void clear();  // vtable slot 15
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    const MtArray& getGroupList() const;
    void setGroupList(const MtArray& list);
    MT_CTSTR getCmnEpvPath() const;
    void setCmnEpvPath(MT_CTSTR);
    MT_CTSTR getCmnSePath() const;
    void setCmnSePath(MT_CTSTR);
    const cShlGroupParam* getGroup(u32 group) const;
    const cShlParamBase* getParam(u32 group, u32 index) const;
    const rShlParamList& operator=(const rShlParamList&);
    void setupGroup();
    u32 getGroupNum() const;
protected:
    MtArray mParamList;  // offset: 0x70
    MtString mCmnEpvPath;  // offset: 0x90
    MtString mCmnSePath;  // offset: 0x98
public:
    static MyDTI DTI;
protected:
    static const u8 DATA_VERSION = 31;
};
