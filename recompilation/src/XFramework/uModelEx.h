#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "uModel.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
class rModelMontage;

// Declarations
class uActorModel;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uActorModel : public uModel
{
public:
    class MyDTI;
    class Constraint;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class Constraint : public uModel::Constraint
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
        Constraint();
        virtual void adjust(uModel::Joint* pjnt, uModel* pmod);  // vtable slot 6
        void setJointNo(u32 no);
        u32 getJointNo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    public:
        uModel* mpModel;  // offset: 0x8
        u32 mParentJntNo;  // offset: 0x10
        u32 mJntNo;  // offset: 0x14
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
    uActorModel();
    virtual ~uActorModel();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    void setMontage(rModelMontage* pmontage);
    rModelMontage* getMontage();
    void setMontageNo(u32);
    void setLegacyMotionAttribute();
protected:
    Constraint mConstraint[64];  // offset: 0x1f60
    rModelMontage* mpMontage;  // offset: 0x2560
    u32 mMontageNo;  // offset: 0x2568
    MtVector3 mOffsetPos;  // offset: 0x2570
    MtVector3 mOffsetAngle;  // offset: 0x2580
public:
    static MyDTI DTI;
protected:
    static const s32 MAX_CONSTRAINT = 64;
};

inline void* uActorModel::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uActorModel::Constraint::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uActorModel::Constraint::Constraint() {
    this->mParentJntNo = 255;
    this->mJntNo = 255;
}

inline u32 uActorModel::Constraint::getJointNo() {
    return this->mJntNo;
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void uActorModel::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uActorModel::DTI)->memFree(p_addr);
}

inline void* uActorModel::Constraint::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uActorModel::Constraint::DTI)->memAlloc(sz, align, ::uActorModel::Constraint::DTI.::MtDTI::mID);
}

inline void uActorModel::Constraint::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uActorModel::Constraint::DTI)->memFree(p_addr);
}
