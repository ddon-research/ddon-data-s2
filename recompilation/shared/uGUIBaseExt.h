#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "cResource.h"
#include "uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cResource;
namespace nGUIBaseExt { struct ResInfo; }
class rGUI;

// Declarations
class uGUIBaseExt;
class uGUIBaseExtWindow;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using time_t = long int;
using t64 = time_t;
using u32 = unsigned int;

class uGUIBaseExt : public uGUIBase
{
public:
    enum UPDATE_MODE
    {
        UPDATE_MODE_NONE = 0,
        UPDATE_MODE_HIDE = 1,
        UPDATE_MODE_SHOW = 2,
    };
public:
    class MyDTI;
    union Flags;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    union Flags
    {
    public:
        struct
        {
        public:
            u32 IsFirstSetup : 1;  // offset: 0x0
            u32 IsAutoShow : 1;  // offset: 0x0
            u32 IsPauseInput : 1;  // offset: 0x0
            u32 IsPauseDraw : 1;  // offset: 0x0
        };  // offset: 0x0
        u32 All;  // offset: 0x0
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
protected:
    uGUIBaseExt(u32 initFlags, bool isChatSubMenu);
    virtual ~uGUIBaseExt();
public:
    void setAutoShow(bool isAutoShow);
    bool isShowable() const;
    bool isShow() const;
    bool isHide() const;
    bool show();
    bool hide();
    void pauseInput(bool isPauseInput);
    bool isPauseInput() const;
    bool isPauseDraw() const;
protected:
    virtual MT_CTSTR getLoadArcTagName(u32 arcIndex) const;  // vtable slot 91
    virtual bool isLoadArcKeep(u32 arcIndex) const;  // vtable slot 92
    virtual const nGUIBaseExt::ResInfo* getGuiResInfo() const;  // vtable slot 93
    virtual t64 getGuiResUpdateTime() const;  // vtable slot 94
    virtual const nGUIBaseExt::ResInfo* getGmdResInfo(u32 gmdResIndex) const;  // vtable slot 95
    virtual u32 getGmdResNum() const;  // vtable slot 96
    virtual const nGUIBaseExt::ResInfo* getResInfo(u32 resIndex) const;  // vtable slot 97
    virtual u32 getResNum() const;  // vtable slot 98
    virtual cResource* getRes(u32 resIndex) const;  // vtable slot 99
    virtual void setupAfterLoad();  // vtable slot 100
    virtual bool isDrawable() const;  // vtable slot 101
    virtual void onSetup();  // vtable slot 102
    virtual void onKill();  // vtable slot 103
    virtual void onMoveInput();  // vtable slot 104
    virtual void onMoveEvent();  // vtable slot 105
    virtual void onShow();  // vtable slot 106
    virtual void onHide();  // vtable slot 107
    virtual void onPauseInput(bool isPauseInput);  // vtable slot 108
    virtual void onPauseDraw(bool isPauseDraw);  // vtable slot 109
    virtual void onUpdateShow();  // vtable slot 110
    virtual void onUpdateHide();  // vtable slot 111
    virtual void onAfterUpdate();  // vtable slot 112
private:
    virtual bool loadArchive();  // vtable slot 77
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
public:
    virtual void kill();  // vtable slot 16
private:
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void releaseResources();
    void updateExit();
    void updateMain();
    void setUpdateMode(UPDATE_MODE updateMode);
private:
    Flags mFlags;  // offset: 0x8c8
    rGUI* mpGUIRes;  // offset: 0x8d0
    MtTypedArray<cResource> mResources;  // offset: 0x8d8
    UPDATE_MODE mUpdateMode;  // offset: 0x8f8
public:
    static MyDTI DTI;
};

class uGUIBaseExtWindow : public uGUIBaseExt
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
protected:
    uGUIBaseExtWindow(u32 initFlags, bool isChatSubMenu);
    virtual ~uGUIBaseExtWindow();
public:
    static MyDTI DTI;
};
