#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/cGUIObject.h"
#include "../shared/nGUI.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
namespace nGUI { class Draw; }
namespace nGUI { struct TEXTURE; }
class rTexture;

// Declarations
class cGUIObjTextureRef;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cGUIObjTextureRef : public cGUIObjTexture
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
    cGUIObjTextureRef();
    virtual ~cGUIObjTextureRef();
    void setReferenceTexture(rTexture* pTexture);
    rTexture* getReferenceTexture();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
protected:
    virtual void draw(nGUI::Draw& drawObj);  // vtable slot 13
private:
    nGUI::TEXTURE mTexReplace;  // offset: 0x140
    nGUI::TEXTURE* mpTextureOrigin;  // offset: 0x180
public:
    static MyDTI DTI;
};
