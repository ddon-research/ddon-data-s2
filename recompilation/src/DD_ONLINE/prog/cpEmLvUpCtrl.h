#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "cpComponent.h"
#include "../../generated/shared/nEnemy.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cEmLvUpParam;
class rEmLvUpParam;
class uDDOModel;

// Declarations
class cpEmLvUpCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cpEmLvUpCtrl : public cpComponent
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
    cpEmLvUpCtrl();
    virtual ~cpEmLvUpCtrl();
    virtual void setup();  // vtable slot 6
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    virtual void updatePtr();  // vtable slot 9
    void setResource(rEmLvUpParam* pRes);
    uDDOModel* getDDOModel() const;
    void changeLv(u32 Lv, nEnemy::PARAM_RESET_TYPE resetType);
    const cEmLvUpParam* getLvUpParam() const;
private:
    void calcEmLvUpParam(u32 Lv);
    void weightCopy(cEmLvUpParam* pOutPutParam, f32 upperWeight, const cEmLvUpParam* pUpperParam, const cEmLvUpParam* pLowerParam);
private:
    cEmLvUpParam* mpLvUpParam;  // offset: 0x50
    rEmLvUpParam* mpResource;  // offset: 0x58
    uDDOModel* mpModel;  // offset: 0x60
public:
    static MyDTI DTI;
};

inline void* cpEmLvUpCtrl::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline const cEmLvUpParam* cpEmLvUpCtrl::getLvUpParam() const {
    return this->mpLvUpParam;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* cpEmLvUpCtrl::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::cpEmLvUpCtrl::DTI);
}

inline void cpEmLvUpCtrl::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cpEmLvUpCtrl::DTI)->memFree(p_addr);
}
