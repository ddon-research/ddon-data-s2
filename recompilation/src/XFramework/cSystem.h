#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "../MT/MtObject.h"
#include "../MT/MtSynchronize.h"

// Forward declarations
class MtAllocator;
class MtCriticalSection;
class MtDTI;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
class sAIPawnSys;
class sArchiveManager;
class sAreaHit;
class sBakingJointOrder;
class sBrowser;
class sCamera;
class sCameraExt;
class sCaplinkManager;
class sChat;
class sCollision;
class sContextManager;
class sEffect;
class sEffectExt;
class sGUI;
class sGUIExt;
class sInputManager;
class sNetwork;
class sObjCollision;
class sOccluder;
class sOmManager;
class sPrimitive;
class sQuestManagerExt;
class sRender;
class sResource;
class sScene;
class sSetManager;
class sShadow;
class sSound;
class sSoundExt;
class sSoundManager;
class sUnit;
class sUnitManager;
class sZone;
class uGUIMenuComm;

// Declarations
class cSystem;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cSystem : public MtObject
{
    friend class sAIPawnSys;
    friend class sArchiveManager;
    friend class sAreaHit;
    friend class sBakingJointOrder;
    friend class sBrowser;
    friend class sCamera;
    friend class sCameraExt;
    friend class sCaplinkManager;
    friend class sChat;
    friend class sCollision;
    friend class sContextManager;
    friend class sEffect;
    friend class sEffectExt;
    friend class sGUI;
    friend class sGUIExt;
    friend class sInputManager;
    friend class sNetwork;
    friend class sObjCollision;
    friend class sOccluder;
    friend class sOmManager;
    friend class sPrimitive;
    friend class sQuestManagerExt;
    friend class sRender;
    friend class sResource;
    friend class sScene;
    friend class sSetManager;
    friend class sShadow;
    friend class sSound;
    friend class sSoundExt;
    friend class sSoundManager;
    friend class sUnit;
    friend class sUnitManager;
    friend class sZone;
    friend class uGUIMenuComm;
public:
    class MyDTI;
    class cAutoCriticalSection;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cAutoCriticalSection
    {
    public:
        cAutoCriticalSection(cSystem* p);
        ~cAutoCriticalSection();
    protected:
        cSystem* mpSys;  // offset: 0x0
    };
public:
    static MtDTI* getMyDTIPtr();
    virtual const MtDTI& getDTI() const;  // vtable slot 5
    static MtAllocator* getAllocator();
    static void setAllocator(u32);
    virtual void reset() {}  // vtable slot 6
    virtual void move() {}  // vtable slot 7
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createMenu(MtPropertyList&) {}  // vtable slot 8
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {}  // vtable slot 9
protected:
    cSystem();
    virtual ~cSystem();
    void lock();
    bool tryLock();
    void unlock();
    void setThreadSafe(bool f);
    bool isThreadSafe();
    static bool isJobSafe();
public:
    static void usage();
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete(void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
protected:
    static void setJobSafe(bool f);
private:
    MtCriticalSection mCS;  // offset: 0x8
    bool mThreadSafe;  // offset: 0x10
public:
    static MyDTI DTI;
    static const u32 MAX_JOBTHREAD = 6;
private:
    static MtAllocator* mpAllocator;
    static bool mJobSafe;
};
