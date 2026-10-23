#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cPrimObj.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
namespace nPrim { struct Texture; }
class sPrimitive;

// Declarations
class cPrimTexHandleManager;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cPrimTexHandleManager : public cPrimObj
{
    // inferred: sPrimitive::reserveTex names cPrimTexHandleManager::mTextureMax
    friend class sPrimitive;
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
    cPrimTexHandleManager(u32 max_tex);
    virtual ~cPrimTexHandleManager();
    nPrim::Texture* getTexture() const;
    nPrim::Texture* getTexture(u32 idx) const;
    u32 getMaxNumOfTex() const;
    u32 getNumOfUsedTex() const;
    u32 reserveTex(nPrim::Texture* * p_tex, u32* idx, u32 num_tex);
    void clear();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& prop_list);  // vtable slot 4
protected:
    nPrim::Texture* mpTexture;  // offset: 0x8
    u32 mTextureMax;  // offset: 0x10
    u32 mUsedTex;  // offset: 0x14
public:
    static MyDTI DTI;
};
