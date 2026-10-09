#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "uShlBase.h"
#include "uShlKeepOwnerLog.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cDraw;
class cEfcHandle;
class cShlParamBakuensen;

// Declarations
class uBakuenseSpark;
class uShlBakuensen;

namespace nShlBakuensen {
    enum BAKUENSEN_PHASE
    {
        MODE_BAKUEN_INVALID = 0,
        MODE_BAKUEN_TRACE = 1,
        MODE_BAKUEN_SET_UP_REVERSE = 2,
        MODE_BAKUEN_REVERSE = 3,
        MODE_BAKUEN_SHOT_WAIT = 4,
        MODE_BAKUEN_SHOT = 5,
        MODE_BAKUEN_END = 6,
        MODE_BAKUEN_NUM = 7,
    };
}  // namespace nShlBakuensen

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class uBakuenseSpark : public uShlBase
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
    uBakuenseSpark();
    virtual ~uBakuenseSpark();
    virtual void setup();  // vtable slot 6
    virtual void update();  // vtable slot 174
    virtual void after();  // vtable slot 176
    virtual void updateMatrix();  // vtable slot 71
    virtual void updatePtr();  // vtable slot 17
    virtual void createComponent();  // vtable slot 43
    void setOwner(uShlBakuensen*);
    void requesetSetCollision();
protected:
    uShlBakuensen* mpOwner;  // offset: 0x2ab0
    bool mRequestSetCollision;  // offset: 0x2ab8
public:
    static MyDTI DTI;
};

class uShlBakuensen : public uShlKeepOwnerLog
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
    const cShlParamBakuensen* getShlParam() const;
    virtual const MtDTI* getLogNodeDTI();  // vtable slot 186
    uShlBakuensen();
    virtual ~uShlBakuensen();
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    virtual void updateEfcHandle();  // vtable slot 58
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    virtual void initSub();  // vtable slot 177
    virtual void updateSub();  // vtable slot 175
    void requestIgnite();
protected:
    void traceWait();
    bool setupReverse();
    void updateReverse();
    void waitShot();
    void requestShotBakuen();
    void shotBakuensen();
    void missFire();
    void killFireUnitDummy();
protected:
    nShlBakuensen::BAKUENSEN_PHASE mBakuenPhase;  // offset: 0x2af4
    f32 mLimitTimer;  // offset: 0x2af8
    f32 mReverseSpeed;  // offset: 0x2afc
    f32 mGoalRange;  // offset: 0x2b00
    f32 mShotWaitTimer;  // offset: 0x2b04
    cEfcHandle* mpBakuenEfcHandle;  // offset: 0x2b08
    uBakuenseSpark* mpFireUnitDummy;  // offset: 0x2b10
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline uBakuenseSpark::uBakuenseSpark() {
    this->mpOwner = static_cast<uShlBakuensen*>(nullptr);
    this->mRequestSetCollision = false;
}
