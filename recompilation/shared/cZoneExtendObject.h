#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "nZone.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
namespace nZone { class cLayoutElement; }

// Declarations
class cZoneExtendObject;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cZoneExtendObject : public nZone::cAllocaterIntermediate
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
    cZoneExtendObject();
    virtual ~cZoneExtendObject();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    // Address: 0x01b713b0 - 0x01b713b1 (1 bytes)
    virtual void evChangeEnable(bool flag) {}  // vtable slot 6
    nZone::cLayoutElement* getOwner();
private:
    void registerOwner(nZone::cLayoutElement* pOwner);
private:
    nZone::cLayoutElement* mpOwner;  // offset: 0x8
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline nZone::cLayoutElement* cZoneExtendObject::getOwner() {
    return this->mpOwner;
}
