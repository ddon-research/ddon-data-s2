#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "uShlBase.h"
#include "uShlHoming.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
class cEfcHandle;
class cHitInfo;
class uDDOModel;
class uShlHoming;

// Declarations
class cShlParamRenmadanCtrl;
class cShlParamRenmadanMain;
class uShlRenmadanCtrl;
class uShlRenmadanMain;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamRenmadanCtrl : public cShlParamBase
{
public:
    class MyDTI;
    class cRenmaSubCtrlParam;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cRenmaSubCtrlParam : public MtObject
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
        cRenmaSubCtrlParam();
        virtual ~cRenmaSubCtrlParam() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual void createPropertyTool(MtPropertyList& s);  // vtable slot 6
    public:
        f32 waitFrame;  // offset: 0x8
        s32 shlNo;  // offset: 0xc
        MtVector3 offset;  // offset: 0x10
        f32 degX;  // offset: 0x20
        f32 degY;  // offset: 0x24
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
    virtual MtDTI& getShlDTI() const;  // vtable slot 6
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    cShlParamRenmadanCtrl();
    virtual ~cShlParamRenmadanCtrl();
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
    virtual void addShlList(const cShlParamRenmadanCtrl* pParam);  // vtable slot 12
public:
    s32 renmaMainShotNo;  // offset: 0x160
    s32 renmaHitHomingNo;  // offset: 0x164
    s32 renmaNoHitShlNo;  // offset: 0x168
    f32 renmaSubWaitTime;  // offset: 0x16c
    f32 renmaSubInterval;  // offset: 0x170
    MtArray renmaSubList;  // offset: 0x178
    static MyDTI DTI;
};

class cShlParamRenmadanMain : public cShlParamHoming
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
    virtual MtDTI& getShlDTI() const;  // vtable slot 6
    cShlParamRenmadanMain();
    virtual ~cShlParamRenmadanMain();
public:
    static MyDTI DTI;
};

class uShlRenmadanCtrl : public uShlBase
{
public:
    enum
    {
        RENMA_WAIT = 0,
        RENMA_HIT_ATTACK = 1,
        RENMA_NO_HIT = 2,
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
    const cShlParamRenmadanCtrl* getShlParam() const;
    uShlRenmadanCtrl();
    virtual ~uShlRenmadanCtrl();
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void updateSub();  // vtable slot 175
    virtual void updatePtr();  // vtable slot 17
    virtual void updateEfcHandle();  // vtable slot 58
    u32 getSetNum() const;
protected:
    uShlBase* setShl(u32 shlNo, const MtVector3& offset, f32 degX, f32 degY, u32 tagUid, s32 lockIndex);
    u32 getShlSetNum();
private:
    u32 mShlSetNum;  // offset: 0x2ab0
    f32 mShlSetFrame;  // offset: 0x2ab4
    f32 mSubWaitTimer;  // offset: 0x2ab8
    f32 mSubDelayTimer;  // offset: 0x2abc
    uShlRenmadanMain* mpRenmaMain;  // offset: 0x2ac0
    uDDOModel* mpRenmaTarget;  // offset: 0x2ac8
    MtTypedArray<uShlHoming> mSubHomingFirstArray;  // offset: 0x2ad0
    MtTypedArray<uShlHoming> mSubHomingSecondArray;  // offset: 0x2af0
    cEfcHandle* mpTargetEfcHandle;  // offset: 0x2b10
public:
    u32 mSubTargetUID;  // offset: 0x2b18
    s32 mJointNo;  // offset: 0x2b1c
    MtVector3 mOffset;  // offset: 0x2b20
    u32 mRenmaState;  // offset: 0x2b30
    static MyDTI DTI;
};

class uShlRenmadanMain : public uShlHoming
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
    const cShlParamRenmadanMain* getShlParam() const;
    uShlRenmadanMain();
    virtual ~uShlRenmadanMain();
    virtual void updatePtr();  // vtable slot 17
    virtual void callbackAttack(cHitInfo* pHitInfo);  // vtable slot 83
    void setRenmaCtrl(uShlRenmadanCtrl* pRenma);
private:
    uShlRenmadanCtrl* mpRenmaCtrl;  // offset: 0x2be0
public:
    static MyDTI DTI;
};

inline void* cShlParamRenmadanCtrl::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamRenmadanCtrl::cShlParamRenmadanCtrl() {
    this->renmaMainShotNo = -1;
    this->renmaHitHomingNo = -1;
    this->renmaNoHitShlNo = -1;
    this->renmaSubWaitTime = 0.0f;
    this->renmaSubInterval = 0.0f;
    this->renmaSubList.mAutoDelete = true;
}

inline void* cShlParamRenmadanCtrl::cRenmaSubCtrlParam::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamRenmadanCtrl::cRenmaSubCtrlParam::cRenmaSubCtrlParam() {
    this->waitFrame = 0.0f;
    this->shlNo = -1;
    this->degX = 0.0f;
    this->degY = 0.0f;
    this->offset.z = 0.0f;
    this->offset.pad_ = 0.0f;
    this->offset.x = 0.0f;
    this->offset.y = 0.0f;
}

inline void* cShlParamRenmadanMain::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamRenmadanMain::cShlParamRenmadanMain() {
}

inline void* uShlRenmadanCtrl::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uShlRenmadanMain::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uShlRenmadanMain::uShlRenmadanMain() {
    this->mpRenmaCtrl = nullptr;
}

inline void uShlRenmadanMain::setRenmaCtrl(uShlRenmadanCtrl* pRenma) {
    this->mpRenmaCtrl = pRenma;
}
