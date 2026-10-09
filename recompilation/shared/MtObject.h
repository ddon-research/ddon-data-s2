#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"

// Forward declarations
class MtDTI;
class MtProperty;
class MtPropertyList;
class MtUI;

// Declarations
class MtObject;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class MtObject
{
public:
    class MyDTI;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    MtObject();
    // Address: 0x01b26d90 - 0x01b26d91 (1 bytes)
    virtual ~MtObject() {}
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    void trace();
    static void usage();
    static void* operator new(size_t s);
    static void operator delete(void* padr);
    static void* operator new[](size_t s);
    static void operator delete[](void* padr);
    virtual bool isEnableInstance() const;  // vtable slot 3
    // Address: 0x0194e9d0 - 0x0194e9d1 (1 bytes)
    virtual void createProperty(MtPropertyList&) {}  // vtable slot 4
    virtual const MtDTI& getDTI() const;  // vtable slot 5
    bool isKindOf(const MtDTI& dti) const;
    static MtDTI* getMyDTIPtr();
    MtObject* cast(const MtDTI& target_type);
    const MtObject* cast(const MtDTI& target_type) const;
public:
    static const u32 INITIAL_ALLOCATOR = 0;
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline MtObject::MtObject() {
}
