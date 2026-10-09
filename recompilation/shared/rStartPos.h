#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "cResource.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtUI;
class MtVector3;

// Declarations
class cStartPos;
class rStartPos;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class rStartPos : public cResource
{
public:
    class MyDTI;
    class Info;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class Info : public MtObject
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
        Info();
        virtual ~Info();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        MtVector3 getOfsPos(u32 idx) const;
        void setOfsPos(MtVector3& ofs, u32 idx);
        u32 getOfsPosNum();
        void setOfsPosNum(u32 num);
        f32 getOfsAng(u32 idx) const;
        void setOfsAng(f32 ang, u32 idx);
        u32 getOfsAngNum();
        void setOfsAngNum(u32 num);
    public:
        MtVector3 mPos;  // offset: 0x10
        f32 mAng;  // offset: 0x20
        MtVector3 mOfsPos[7];  // offset: 0x30
        f32 mOfsAng[7];  // offset: 0xa0
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
    rStartPos();
    virtual ~rStartPos();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual MT_CTSTR getName() const;  // vtable slot 16
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    void getData(cStartPos& data, u32 posNo);
    u32 getInfoNum();
public:
    MtArray mInfoList;  // offset: 0x70
    static MyDTI DTI;
    static const u16 DATA_VERSION = 2;
};

class cStartPos
{
public:
    cStartPos();
    MtVector3 getPos(u32 no) const;
    MtVector3 getAng(u32 no) const;
    void setPos(MtVector3& ps);
    void setAng(f32 ag);
    void setOfsPos(u32 index, MtVector3& ps);
    void setOfsAng(u32 index, f32 ag);
    void copy(rStartPos::Info* pinfo);
protected:
    MtVector3 pos;  // offset: 0x0
    MtVector3 ang;  // offset: 0x10
    MtVector3 ofspos[7];  // offset: 0x20
    MtVector3 ofsang[7];  // offset: 0x90
};
