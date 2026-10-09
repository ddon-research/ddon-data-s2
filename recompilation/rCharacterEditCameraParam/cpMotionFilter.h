#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/cpComponent.h"
#include "../shared/uModel.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtMatrix;
class MtObject;
class MtPropertyList;
class MtVector3;
class rMotionFilter;
class uCnsMotFilter;
class uDDOModel;
class uModel;

// Declarations
class cpMotionFilter;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cpMotionFilter : public cpComponent
{
public:
    enum DATA_ENUM
    {
        DATA_HARA = 0,
        DATA_MUNE = 1,
        DATA_SAKOTSU_R = 2,
        DATA_SAKOTSU_L = 3,
        DATA_UDE_R = 4,
        DATA_UDE_L = 5,
        DATA_ASHI_R = 6,
        DATA_ASHI_L = 7,
        DATA_ASHIKUBI_R = 8,
        DATA_ASHIKUBI_L = 9,
        DATA_MAX = 10,
    };
    enum ROT_ENUM
    {
        ROT_UDE_R = 0,
        ROT_UDE_L = 1,
        ROT_ASHI_R = 2,
        ROT_ASHI_L = 3,
        ROT_ATAMA = 4,
        ROT_MAX = 5,
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
    cpMotionFilter();
    virtual ~cpMotionFilter();
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void kill();  // vtable slot 8
    virtual void updatePtr();  // vtable slot 9
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void init();
    void createConstraint();
    void removeConstraint();
    void update();
    void setSleep(bool);
    bool isSleep() const;
    void setBlend(f32 Blend, f32 Speed);
    void setSex(u32 sex);
    void setManWoman(f32 rate);
    MtVector3 getLocalRot(uModel::Joint* pJnt);
    MtMatrix calc_hara(uModel::Joint* pJnt, uModel* pModel);
    MtMatrix calc_mune(uModel::Joint* pJnt, uModel* pModel);
    MtMatrix calc_sakotsu_R(uModel::Joint* pJnt, uModel* pModel);
    MtMatrix calc_sakotsu_L(uModel::Joint* pJnt, uModel* pModel);
    MtMatrix calc_ashikubi_R(uModel::Joint* pJnt, uModel* pModel);
    MtMatrix calc_ashikubi_L(uModel::Joint* pJnt, uModel* pModel);
    MtMatrix calc_rotate(uModel::Joint* pJnt, uModel* pModel);
    void setResource(rMotionFilter* pRes);
    rMotionFilter* getResource();
private:
    f32 cond(bool flag, f32 true_val, f32 false_val);
private:
    uDDOModel* mpModel;  // offset: 0x50
    rMotionFilter* mpResource;  // offset: 0x58
    u32 mSex;  // offset: 0x60
    f32 mManWomanRate;  // offset: 0x64
    f32 mManWoman;  // offset: 0x68
    bool mSleep;  // offset: 0x6c
    uCnsMotFilter* mpMotFilter[10];  // offset: 0x70
    f32 mNormalR;  // offset: 0xc0
    f32 mNormalL;  // offset: 0xc4
public:
    static MyDTI DTI;
private:
    static MtVector3 mRotData[5];
};
