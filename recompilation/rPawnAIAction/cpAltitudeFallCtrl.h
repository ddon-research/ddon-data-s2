#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/cDelegate.h"
#include "../shared/cpComponent.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector3;
class cCharParamEnemy;
class cpJob01;
class uDDOModel;

// Declarations
class cpAltitudeFallCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s8 = signed char;
using size_t = _Sizet;
using u32 = unsigned int;

class cpAltitudeFallCtrl : public cpComponent
{
    // inferred: cpJob01::callbackReplaceHitInfo_Atk names cpAltitudeFallCtrl::mLastFallDistance
    friend class cpJob01;
public:
    enum
    {
        HEIGHT_LEVEL_0 = 0,
        HEIGHT_LEVEL_1 = 1,
        HEIGHT_LEVEL_2 = 2,
        HEIGHT_LEVEL_3 = 3,
        HEIGHT_LEVEL_NONE = 4,
    };
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
    cpAltitudeFallCtrl();
    virtual ~cpAltitudeFallCtrl();
    virtual void setup();  // vtable slot 6
    void init();
    virtual void updatePtr();  // vtable slot 9
    void after();
    void setCharParamEnemy(cCharParamEnemy* pParam);
    void callbackHitLand();
    void callbackFall();
    f32 getFallDistance();
    f32 getLastFallDistance();
    f32 getDamageHeight();
    bool getIsFalling();
    MtVector3 getPos();
    void Invalidation();
    void Activation();
    s8 getLastHeigthLevel(f32 low, f32 middle);
    void setDamageHeight(f32 height);
    bool isAltitudeFall() const;
    f32 getDamageHeightWithAbility();
public:
    cDelegate_0<void> callbackAltitudeFall;  // offset: 0x50
    cDelegate_0<void> callbackAltitudeFallLand;  // offset: 0x68
private:
    f32 mFallDistance;  // offset: 0x80
    f32 mLastFallDistance;  // offset: 0x84
    bool mIsAir;  // offset: 0x88
    bool mIsAltitudeFall;  // offset: 0x89
    f32 mHighestPointY;  // offset: 0x8c
    bool mIsSearching;  // offset: 0x90
    bool mIsFallPath;  // offset: 0x91
    f32 mDamageHeight;  // offset: 0x94
    bool mRequestInitFlg;  // offset: 0x98
    uDDOModel* mpModel;  // offset: 0xa0
public:
    static MyDTI DTI;
};
