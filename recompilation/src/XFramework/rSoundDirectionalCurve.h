#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtObject.h"
#include "cResource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtUI;

// Declarations
class rSoundDirectionalCurveXml;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class rSoundDirectionalCurveXml : public cResource
{
public:
    enum TargetPlatform
    {
        PF_COMMON = 0,
        PF_XBOX360 = 1,
        PF_PS3 = 2,
        PF_WINDOWS = 3,
        PF_MAX_NUM = 4,
    };
public:
    class MyDTI;
    class Curve;
    class Element;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class Element : public MtObject
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
        Element();
        virtual ~Element();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    public:
        f32 mAngle;  // offset: 0x8
        f32 mValue;  // offset: 0xc
        static MyDTI DTI;
    };
public:
    class Curve : public MtObject
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
        Curve();
        virtual ~Curve();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    public:
        MtTypedArray<rSoundDirectionalCurveXml::Element> mElements;  // offset: 0x8
        f32 mZeroRadianValue;  // offset: 0x28
        f32 mPiRadianValue;  // offset: 0x2c
        bool mEnable;  // offset: 0x30
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
    rSoundDirectionalCurveXml();
    virtual ~rSoundDirectionalCurveXml();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    void add();
    void add(Element* pElem);
    void erase(u32 index);
    void erase(Element* pElem);
    virtual void clear();  // vtable slot 15
    void sort();
    Element* getElement(u32 index) const;
    Element* getNativeElement(u32 index) const;
    u32 getElementNum() const;
    u32 getNativeElementNum() const;
    f32 getZeroRadianValue() const;
    f32 getNativeZeroRadianValue() const;
    void setZeroRadianValue(f32 v);
    f32 getPiRadianValue() const;
    f32 getNativePiRadianValue() const;
    void setPiRadianValue(f32 v);
    bool getEnable() const;
    bool getEnable(u32 prmTarget) const;
    void setEnable(bool b);
    void setEnable(u32 prmTarget, bool b);
    void setCurrentTarget(u32 t);
    u32 getCurrentTarget() const;
private:
    static bool sortFunction(const Element* a, const Element* b, u32 param);
    Curve* getNativeCurve() const;
private:
    MtTypedArray<Curve> mCurves;  // offset: 0x70
    u32 mCurrentTarget;  // offset: 0x90
public:
    static const u32 mMaxElementNum = 32;
    static MyDTI DTI;
};

inline void* rSoundDirectionalCurveXml::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* rSoundDirectionalCurveXml::Curve::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* rSoundDirectionalCurveXml::Element::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
