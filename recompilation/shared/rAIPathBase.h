#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "MtString.h"
#include "cResource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtGeometry;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtString;
class MtUI;

// Declarations
class rAIPathBase;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s16 = short;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class rAIPathBase : public cResource
{
public:
    class MyDTI;
    class HierarchyArea;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class HierarchyArea : public MtObject
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
        HierarchyArea();
        virtual ~HierarchyArea();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        void setName(MT_CTSTR str);
        MT_CTSTR getName();
        u32 getNameLength();
        void setNumberOfGeometry(u32 n);
        u32 getNumberOfGeometry();
        void setGeometry(MtGeometry* geom, u32 index);
        MtGeometry* getGeometry(u32 index);
        void setElement(u32 min, u32 max);
        u32 getFirst();
        u32 getLast();
        void setID(u32 id);
        u32 getID();
        void setAttribute(u32 attr);
        u32 getAttribute();
        void setParent(u32 id);
        u32 getParent();
        void addChild(u32 id);
        void setChild(u32 id, u32 index);
        s32 getChild(u32 id);
        void setNumberOfChild(u32 size);
        u32 getNumberOfChild();
        void removeChild(u32 id);
        void removeChild();
        void addLink(u32 id);
        void setLink(u32 id, u32 index);
        s32 getLink(u32 id);
        void setNumberOfLink(u32 size);
        u32 getNumberOfLink();
        void removeLink(u32 id);
        void removeLink();
        rAIPathBase::HierarchyArea* copy();
        void setNumberOfChildResize(u32 size);
    protected:
        MtString mName;  // offset: 0x8
        u8 mNumberOfGeometry;  // offset: 0x10
        MtGeometry* * mpGeometryList;  // offset: 0x18
        u16 mID;  // offset: 0x20
        u16 mFirstIndex;  // offset: 0x22
        u16 mLastIndex;  // offset: 0x24
        u32 mAttribute;  // offset: 0x28
        s16 mParentID;  // offset: 0x2c
        u8* mpChild;  // offset: 0x30
        u8 mNumberOfChild;  // offset: 0x38
        u8* mpLink;  // offset: 0x40
        u8 mNumberOfLink;  // offset: 0x48
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
    rAIPathBase();
    virtual ~rAIPathBase();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    void save(MtDataWriter* w);
    void load(MtDataReader* r);
    void setNumberOfArea(u32 size);
    u32 getNumberOfArea();
    void addArea(HierarchyArea* area);
    void setArea(HierarchyArea* area, u32 index);
    HierarchyArea* getArea(u32 index);
    HierarchyArea* getRootArea();
    void removeArea(u32 id);
    void removeArea();
    u32 getNumberOfAreaChild();
    u32 getNumberOfAreaLink();
    void setNumberOfAreaResize(u32 size);
protected:
    HierarchyArea* * mpHierarchyArea;  // offset: 0x70
    u16 mNumberOfArea;  // offset: 0x78
    u16 mNumberOfTotalAreaChild;  // offset: 0x7a
    u16 mNumberOfTotalAreaLink;  // offset: 0x7c
public:
    static MyDTI DTI;
};
