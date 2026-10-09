#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/cResource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtStream;
namespace nGUI { struct ICON_INFO; }

// Declarations
class rGUIIconInfo;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class rGUIIconInfo : public cResource
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
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    rGUIIconInfo();
    virtual ~rGUIIconInfo();
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual void clear();  // vtable slot 15
    const nGUI::ICON_INFO* getIconInfo();
    bool createIconInfo(nGUI::ICON_INFO* * ppIconInfo, MT_CHAR* * ppNameBuffer, MtAllocator* pAllocator);
protected:
    void* memAlloc(u32 sz);
    void memFree(void* p_addr);
protected:
    u32 mVersion;  // offset: 0x70
    nGUI::ICON_INFO* mpIconInfo;  // offset: 0x78
    MT_CHAR* mpNameBuffer;  // offset: 0x80
public:
    static MyDTI DTI;
    static const u32 VERSION = 65536;
};

// Inline, no code of its own: checked where it is inlined.
// inferred: the constructor from _ZNK12rGUIIconInfo5MyDTI11newInstanceEv at 0x01377850-0x0137788f, code DWARF attributes to no inlined copy
inline rGUIIconInfo::rGUIIconInfo() {
    this->::cResource::mAttr = static_cast<u32>(16);
    this->mVersion = static_cast<u32>(65536);
    this->mpNameBuffer = static_cast<MT_CHAR*>(nullptr);
    this->mpIconInfo = static_cast<nGUI::ICON_INFO*>(nullptr);
}
