#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/cResource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtUI;

// Declarations
class rSoundSimpleCurve;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class rSoundSimpleCurve : public cResource
{
public:
    enum CURVE_STYLE
    {
        CURVE_STYLE_LINEAR = 1,
        CURVE_STYLE_HERMITE = 2,
    };
public:
    class MyDTI;
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
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        void copy(rSoundSimpleCurve::Element* src);
    public:
        f32 mX;  // offset: 0x8
        f32 mY;  // offset: 0xc
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
    rSoundSimpleCurve();
    virtual ~rSoundSimpleCurve();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual MT_CTSTR getName() const;  // vtable slot 16
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
protected:
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
public:
    u32 getElementNum();
    u32 getElementNumAll();
    Element* getElement(u32 index);
    f32 getValue(f32 xPos, bool reverse, u32 curveStyle);
    f32 getValueHermite(f32 xPos, bool reverse);
    f32 getValueLinear(f32 xPos, bool reverse);
    void updateData();
    void addData(Element* pElement);
    void setData(u32 index, f32 x, f32 y);
    void deleteData(u32 index);
    s32 getIndex(f32 xval, f32 yval);
    void sort();
private:
    void* memAlloc(u32 size);
    void memFree(void* p_addr);
    u32 memSize(void* p_addr);
public:
    MtTypedArray<Element> mElementArray;  // offset: 0x70
    f32* mpX;  // offset: 0x90
    f32* mpY;  // offset: 0x98
    static MyDTI DTI;
    static const u32 DATA_VERSION = 1;
};

// Inline, no code of its own: checked where it is inlined.
inline rSoundSimpleCurve::Element::Element() {
    this->mX = 0.0f;
    this->mY = 0.0f;
}
