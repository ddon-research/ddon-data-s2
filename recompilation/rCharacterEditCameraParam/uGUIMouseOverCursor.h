#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/MtPrimitive2D.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtRect;
class cDraw;
class cGUIInstAnimation;
class cGUIObjTexture;
class rGUI;

// Declarations
class uGUIMouseOverCursor;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class uGUIMouseOverCursor : public uGUIBase
{
public:
    enum
    {
        CELL_LT = 0,
        CELL_CT = 1,
        CELL_RT = 2,
        CELL_LC = 3,
        CELL_CC = 4,
        CELL_RC = 5,
        CELL_LB = 6,
        CELL_CB = 7,
        CELL_RB = 8,
        CELL_MAX = 9,
    };
public:
    class MyDTI;
    class cMOC;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cMOC : public MtObject
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
        cMOC();
        // Address: 0x01af8990 - 0x01af8991 (1 bytes)
        virtual ~cMOC() {}
        void setAlpha(u8 uAlpha);
        u8 getAlpha();
        void setRect(MtRect rect);
        void setFadeStartCnt(f32 fCnt);
    public:
        cGUIInstAnimation* mpInst;  // offset: 0x8
        cGUIObjTexture* mpObjTbl[9];  // offset: 0x10
        MtRect mRect;  // offset: 0x58
        u8 mAlphaU8;  // offset: 0x68
        f32 mFadeStartCnt;  // offset: 0x6c
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
    uGUIMouseOverCursor();
    virtual ~uGUIMouseOverCursor();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    void reqMouseOverCursor(MtRect rect, u32 uType);
    void beginMouseOverCursor();
private:
    void updateInit();
    void updateWait();
    void updateExit();
protected:
    // Address: 0x01af8960 - 0x01af8961 (1 bytes)
    virtual void adjustScale() {}  // vtable slot 84
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    cGUIInstAnimation* mpInstDupli[1];  // offset: 0x8d0
    cGUIObjTexture* mpObjDupli[1][9];  // offset: 0x8d8
    MtTypedArray<cMOC> mMOC;  // offset: 0x920
public:
    static MyDTI DTI;
    static const u32 DUPLI_MAX = 1;
    static const u32 CNT_FADESTART = 3;
};
