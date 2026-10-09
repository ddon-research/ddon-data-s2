#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "nDraw.h"
#include "nDrawMaterial.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class cDraw;

// Declarations
namespace nDraw { class MaterialStd; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

namespace nDraw {
    class MaterialStd : public nDraw::Material
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        MaterialStd();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    protected:
        virtual u32 setDrawState(cDraw* pdraw, nDraw::PASS_TYPE overrideDrawPass);  // vtable slot 13
        virtual bool beginDraw(cDraw* pdraw, u32 pass);  // vtable slot 14
        virtual void endDraw(cDraw* pdraw, u32 pass);  // vtable slot 15
        virtual ~MaterialStd();
    private:
        u32 setDeferredLightingState(cDraw* pdraw, u32 pass);
        u32 setRSMState(cDraw* pdraw, u32 pass);
    public:
        static MyDTI DTI;
    };
}  // namespace nDraw
