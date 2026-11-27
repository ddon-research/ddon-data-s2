#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "cEquipData.h"
#include "nDDOUtility.h"
#include "uCharacterEdit.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cCharacterData;
class cEquipData;
class uCharacterEditCameraBase;
class uGUICharacterSelect;

// Declarations
class uCharacterSelect;
class uCharacterSelectCamera;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uCharacterSelect : public uCharacterEditBase
{
public:
    enum
    {
        MOVE_MAIN_SELECT = 0,
        MOVE_MAIN_LOAD_WEP_REMOVE = 1,
        MOVE_MAIN_LOAD_WEP = 2,
    };
    enum
    {
        MOTION_FACE = 0,
        MOTION_MAX = 1,
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
    uCharacterSelect();
    virtual ~uCharacterSelect();
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    virtual void release();  // vtable slot 24
    virtual bool moveLoadArc();  // vtable slot 25
    virtual void moveLoadUnit();  // vtable slot 26
    virtual void moveMain();  // vtable slot 27
    virtual void moveEnd() {}  // vtable slot 28
    void setCharacterData(cCharacterData* * p);
    void setCharacterDataNum(s32* p);
    bool isSafeCharacterData();
    u32 getEndMode();
    u32 getSelectCharaIndex();
    void wakeup();
    void updateModel();
    void setIsWakeup(bool flg);
protected:
    void init();
    virtual uCharacterEditCameraBase* createCamera();  // vtable slot 31
protected:
    u32 mSelectIndex;  // offset: 0x270
    uGUICharacterSelect* mpGUI;  // offset: 0x278
    cCharacterData* * mppCharData;  // offset: 0x280
    s32* mpCharaNum;  // offset: 0x288
    s32 mCharaNumOld;  // offset: 0x290
    cEquipData mEquipData;  // offset: 0x298
    f32 mLoadingTimer;  // offset: 0x1500
    nDDOUtility::cArray<float, 1> mMotionWaits;  // offset: 0x1504
public:
    static MyDTI DTI;
};

class uCharacterSelectCamera : public uCharacterEditCameraBase
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
    uCharacterSelectCamera();
    virtual ~uCharacterSelectCamera();
    virtual void updateCameraParam();  // vtable slot 28
public:
    static MyDTI DTI;
};

inline void* uCharacterSelect::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void uCharacterSelect::setCharacterData(cCharacterData* * p) {
    this->mppCharData = p;
}

inline void* uCharacterSelectCamera::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uCharacterSelectCamera::uCharacterSelectCamera() {
    this->::uCharacterEditCameraBase::mIsLSenableRotate = true;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* uCharacterSelect::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::uCharacterSelect::DTI);
}

inline void uCharacterSelect::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uCharacterSelect::DTI)->memFree(p_addr);
}

inline void* uCharacterSelectCamera::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uCharacterSelectCamera::DTI)->memAlloc(sz, align, ::uCharacterSelectCamera::DTI.::MtDTI::getID());
}

inline void uCharacterSelectCamera::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uCharacterSelectCamera::DTI)->memFree(p_addr);
}
