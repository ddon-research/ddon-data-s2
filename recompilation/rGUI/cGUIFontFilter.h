#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/nGUI.h"
#include "../shared/rGUIFont.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtDTI;
class MtProperty;
class MtPropertyList;
class MtUI;
namespace nGUI { class Draw; }
namespace nGUI { struct MTAG; }
namespace nGUI { struct MessageDrawState; }
namespace nGUI { struct VERTEX; }

// Declarations
class cGUIFontFilter;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cGUIFontFilter : public MtObject
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
    cGUIFontFilter();
    virtual ~cGUIFontFilter();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createParamProperty(MtPropertyList&) = 0;  // vtable slot 6
    virtual void calcBufferSize(nGUI::MTAG::DRAW& dw);  // vtable slot 7
    virtual bool isValid() const;  // vtable slot 8
    virtual void updateDrawMTagChar(nGUI::MessageDrawState&, nGUI::MTAG*) = 0;  // vtable slot 9
    virtual void updateDrawMTagDraw(nGUI::MessageDrawState& state, nGUI::MTAG* pMTag);  // vtable slot 10
    virtual void updateDrawMTagLine(nGUI::MessageDrawState& state, nGUI::MTAG* pMTag);  // vtable slot 11
    virtual void beginDraw(nGUI::Draw& drawObj);  // vtable slot 12
    virtual void endDraw(nGUI::Draw& drawObj);  // vtable slot 13
    virtual void executeDrawLine(nGUI::Draw& drawObj, nGUI::MTAG* pDrawMTag);  // vtable slot 14
    u32 getId() const;
    virtual bool isDrawFont() const;  // vtable slot 15
    virtual bool isChangeLine() const;  // vtable slot 16
    virtual u32 getDrawCharCount() const;  // vtable slot 17
protected:
    u32 getCharVertexCount() const;
    nGUI::VERTEX* writeCharVertices(nGUI::VERTEX* pVertex, f32 l, f32 t, f32 r, f32 b, f32 z, MtColor color, const rGUIFont::CHAR& ch) const;
private:
    void setId(u32 id);
private:
    u32 mId;  // offset: 0x8
    u32 mType : 4;  // offset: 0xc
public:
    static MyDTI DTI;
};
