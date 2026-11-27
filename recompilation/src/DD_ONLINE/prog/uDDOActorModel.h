#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "cComponentManager.h"
#include "../../XFramework/uModelEx.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cComponentManager;
class cDraw;
class cpComponent;
class cpDDMrlMgr;
class cpJointEx2;
class cpResetCtrl;
class rDDOModelMontage;

// Declarations
class uDDOActorModel;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uDDOActorModel : public uActorModel
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
    uDDOActorModel();
    virtual ~uDDOActorModel();
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void sync();  // vtable slot 11
    virtual void moveAfter();  // vtable slot 10
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    virtual void kill();  // vtable slot 16
    void createComponent();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void initJointEx();
    void setEquipMontage(rDDOModelMontage* pRes);
    rDDOModelMontage* getEquipMontage();
    void setEquipMontageId(s32 id);
    s32 getEquipMontageId();
    void setEquipColorId(s32 id);
    s32 getEquipColorId();
    cpDDMrlMgr* getMrlMgr();
    virtual bool isOkMrlCtrl();  // vtable slot 43
    cpComponent* getRootComponent() const;
    virtual bool chkJointForEditDelete(u32 jntNo);  // vtable slot 44
    virtual u32 getHitLightToModel();  // vtable slot 36
private:
    bool mEditEnable;  // offset: 0x2590
    bool mMayaScale;  // offset: 0x2591
    bool mParentScale;  // offset: 0x2592
    cpJointEx2* mpJointEx2;  // offset: 0x2598
    cpResetCtrl* mpResetCtrl;  // offset: 0x25a0
    cpDDMrlMgr* mpDDMrlMgr;  // offset: 0x25a8
    bool mIsInit;  // offset: 0x25b0
    rDDOModelMontage* mpEquipMontage;  // offset: 0x25b8
    s32 mEquipMontageId;  // offset: 0x25c0
    s32 mEquipColorId;  // offset: 0x25c4
public:
    cComponentManager mComponentMgr;  // offset: 0x25c8
    static MyDTI DTI;
};

inline void* uDDOActorModel::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline rDDOModelMontage* uDDOActorModel::getEquipMontage() {
    return this->mpEquipMontage;
}

inline s32 uDDOActorModel::getEquipMontageId() {
    return this->mEquipMontageId;
}

inline s32 uDDOActorModel::getEquipColorId() {
    return this->mEquipColorId;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void uDDOActorModel::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uDDOActorModel::DTI)->memFree(p_addr);
}
