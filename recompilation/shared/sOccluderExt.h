#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "MtString.h"
#include "nZone.h"
#include "sOccluder.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtString;
class MtUI;
namespace nZone { class ShapeInfoBase; }
class rOccluder;
class rOccluderEx;
class uCamera;

// Declarations
class sOccluderEx;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class sOccluderEx : public sOccluder
{
public:
    class MyDTI;
    class Area;
    class Shape;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class Area : public MtObject
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
        Area();
        virtual ~Area();
        const sOccluderEx::Area& operator=(const sOccluderEx::Area& other);
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        MtUI* createAreaUI(MtProperty& prop);
        sOccluderEx::Shape* getShape(u32 index);
        void setShape(sOccluderEx::Shape* ps, u32 index);
        u32 getShapeNum();
    public:
        MtString mAreaName;  // offset: 0x8
        u32 mPrio;  // offset: 0x10
        MtArray mShapeList;  // offset: 0x18
        rOccluder* mprOCC;  // offset: 0x38
        bool mbOCC;  // offset: 0x40
        static MyDTI DTI;
    };
public:
    class Shape : public MtObject
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
        Shape();
        Shape(const sOccluderEx::Shape&);
        virtual ~Shape();
        const sOccluderEx::Shape& operator=(const sOccluderEx::Shape& other);
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        nZone::ShapeInfoBase::SHAPE_TYPE getShapeType();
        void setShapeType(nZone::ShapeInfoBase::SHAPE_TYPE type);
        nZone::ShapeInfoBase* getZone();
        void setZone(nZone::ShapeInfoBase* pInfo);
    public:
        bool mbEnable;  // offset: 0x8
        nZone::ShapeInfoBase::SHAPE_TYPE mType;  // offset: 0xc
        nZone::ShapeInfoBase* mpZShape;  // offset: 0x10
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
    sOccluderEx();
    virtual ~sOccluderEx();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void move();  // vtable slot 7
    void final();
    void updateCameraArea();
    u32 getAreaNo();
    void updateOCC();
    rOccluderEx* getOCC();
    void setOCC(rOccluderEx* pr);
    void stageInit();
    void stageFinal();
    void partsInit(rOccluderEx* prOCC);
    void partsFinal();
public:
    u32 mCameraAreaNum;  // offset: 0x8398
    u32 mCameraAreaNo;  // offset: 0x839c
    uCamera* mpFilterTarget;  // offset: 0x83a0
    rOccluderEx* mprOCC;  // offset: 0x83a8
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline sOccluderEx::Area::Area() {
    this->mPrio = static_cast<u32>(512);
    this->mprOCC = static_cast<rOccluder*>(nullptr);
    this->mbOCC = true;
}
