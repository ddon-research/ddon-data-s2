#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cResource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtUI;
namespace nDraw { class Texture; }
class rGUIFont;

// Declarations
class rTexture;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class rTexture : public cResource
{
    // inferred: rGUIFont::getTexture names rTexture::mpTexture
    friend class rGUIFont;
public:
    class MyDTI;
    struct SHFACTOR;
    struct HEADER;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct SHFACTOR
    {
    public:
        f32 r[9];  // offset: 0x0
        f32 g[9];  // offset: 0x24
        f32 b[9];  // offset: 0x48
    };
public:
    struct HEADER
    {
    public:
        u32 magic;  // offset: 0x0
        u32 version : 16;  // offset: 0x4
        u32 attr : 8;  // offset: 0x4
        u32 prebias : 4;  // offset: 0x4
        u32 type : 4;  // offset: 0x4
        u32 level_count : 6;  // offset: 0x8
        u32 width : 13;  // offset: 0x8
        u32 height : 13;  // offset: 0x8
        u32 array_count : 8;  // offset: 0xc
        u32 format : 8;  // offset: 0xc
        u32 depth : 13;  // offset: 0xc
        u32 auto_resize : 1;  // offset: 0xc
        u32 render_target : 1;  // offset: 0xc
        u32 use_vtf : 1;  // offset: 0xc
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
    rTexture();
    virtual bool load(MtStream& r);  // vtable slot 11
    virtual bool compact(MtStream& out);  // vtable slot 8
    virtual void clear();  // vtable slot 15
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    u32 getType() const;
    u32 getWidth() const;
    u32 getHeight() const;
    u32 getDepth() const;
    f32 getInvWidth() const;
    f32 getInvHeight() const;
    u32 getFormat() const;
    u32 getLevelCount() const;
    const SHFACTOR& getSHFactor() const;
    nDraw::Texture* getHandle() const;
    bool isStream() const;
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
protected:
    u32 getDataVersion();
    virtual ~rTexture();
    void setHandle(nDraw::Texture* ptex);
    bool is2N(u32 v);
protected:
    SHFACTOR mSHFactor;  // offset: 0x70
private:
    nDraw::Texture* mpTexture;  // offset: 0xe0
protected:
    f32 mOrgInvWidth;  // offset: 0xe8
    f32 mOrgInvHeight;  // offset: 0xec
    u32 mOrgWidth;  // offset: 0xf0
    u32 mOrgHeight;  // offset: 0xf4
    u32 mOrgDepth;  // offset: 0xf8
    u32 mDetailBias;  // offset: 0xfc
    bool mbStream;  // offset: 0x100
    u32 mStreamLv;  // offset: 0x104
public:
    static MyDTI DTI;
protected:
    static const s32 MIN_LOADBIAS = 8;
    static const u32 DATA_VERSION = 157;
};
