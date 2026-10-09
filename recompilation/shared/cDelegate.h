#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "sCollision.h"
#include "uModel.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
class cUnitDieInfo;
class cWallHitInfo;
class cpActionManager;
class cpInput;
class cpSequenceCtrl;
namespace nKeyCommand { struct stGenericParam; }
class uCnsEdit;
class uDDOModel;
class uModel;

// Declarations
class cDelegateBase;
template <typename R, typename T> class cDelegateCore;
template <typename R> class cDelegate_0;
template <typename R, typename _P0> class cDelegate_1;
template <typename R, typename _P0, typename _P1> class cDelegate_2;
template <typename R, typename _P0, typename _P1, typename _P2> class cDelegate_3;
template <typename R, typename _P0, typename _P1, typename _P2, typename _P3> class cDelegate_4;
template <typename R, typename _P0, typename _P1, typename _P2, typename _P3, typename _P4, typename _P5> class cDelegate_6;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cDelegateBase : public MtObject
{
public:
    template <typename F> class cNodeT;
    class MyDTI;
    class cNode;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cNode : public MtObject
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
        cNode();
    public:
        MtObject* mpThis;  // offset: 0x8
        MT_CTSTR mFuncName;  // offset: 0x10
        static MyDTI DTI;
    };
public:
    template <typename F>
    class cNodeT : public cDelegateBase::cNode
    {
    public:
        cNodeT();
    public:
        F mpFunc;  // offset: 0x18
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
    cDelegateBase();
    // Address: 0x01967e60 - 0x01967e61 (1 bytes)
    virtual void createProperty(MtPropertyList& s) {}  // vtable slot 4
public:
    static MyDTI DTI;
};

template <>
class cDelegateCore<MtVector3, MtVector3(MtObject::*)()> : public cDelegateBase
{
public:
    cDelegateCore();
    virtual ~cDelegateCore();
    void resize(u32 size);
    cDelegateBase::cNodeT<MtVector3(MtObject::*)()>* getNodeAt(u32 idx);
public:
    cDelegateBase::cNodeT<MtVector3(MtObject::*)()>* mpArray;  // offset: 0x8
    u32 mArrayLength;  // offset: 0x10
};

template <>
class cDelegateCore<bool, bool(MtObject::*)()> : public cDelegateBase
{
public:
    cDelegateCore();
    virtual ~cDelegateCore();
    void resize(u32 size);
    u32 length();
    cDelegateBase::cNodeT<bool(MtObject::*)()>* getNodeAt(u32 idx);
public:
    cDelegateBase::cNodeT<bool(MtObject::*)()>* mpArray;  // offset: 0x8
    u32 mArrayLength;  // offset: 0x10
};

template <>
class cDelegateCore<bool, bool(MtObject::*)(int)> : public cDelegateBase
{
public:
    cDelegateCore();
    virtual ~cDelegateCore();
    void resize(u32 size);
    u32 length();
    cDelegateBase::cNodeT<bool(MtObject::*)(int)>* getNodeAt(u32 idx);
public:
    cDelegateBase::cNodeT<bool(MtObject::*)(int)>* mpArray;  // offset: 0x8
    u32 mArrayLength;  // offset: 0x10
};

template <>
class cDelegateCore<bool, bool(MtObject::*)(nKeyCommand::stGenericParam&)> : public cDelegateBase
{
public:
    cDelegateCore();
    virtual ~cDelegateCore();
    void resize(u32 size);
    u32 length();
    cDelegateBase::cNodeT<bool(MtObject::*)(nKeyCommand::stGenericParam&)>* getNodeAt(u32 idx);
public:
    cDelegateBase::cNodeT<bool(MtObject::*)(nKeyCommand::stGenericParam&)>* mpArray;  // offset: 0x8
    u32 mArrayLength;  // offset: 0x10
};

template <>
class cDelegateCore<bool, bool(MtObject::*)(unsigned int, unsigned int, MOT_TYPE)> : public cDelegateBase
{
public:
    cDelegateCore();
    virtual ~cDelegateCore();
    void resize(u32 size);
    cDelegateBase::cNodeT<bool(MtObject::*)(unsigned int, unsigned int, MOT_TYPE)>* getNodeAt(u32 idx);
public:
    cDelegateBase::cNodeT<bool(MtObject::*)(unsigned int, unsigned int, MOT_TYPE)>* mpArray;  // offset: 0x8
    u32 mArrayLength;  // offset: 0x10
};

template <>
class cDelegateCore<unsigned int, unsigned int(MtObject::*)()> : public cDelegateBase
{
public:
    cDelegateCore();
    virtual ~cDelegateCore();
    void resize(u32 size);
    u32 length();
    cDelegateBase::cNodeT<unsigned int(MtObject::*)()>* getNodeAt(u32 idx);
    MtObject* getObjectAt(u32 idx);
public:
    cDelegateBase::cNodeT<unsigned int(MtObject::*)()>* mpArray;  // offset: 0x8
    u32 mArrayLength;  // offset: 0x10
};

template <>
class cDelegateCore<unsigned int, unsigned int(MtObject::*)(MtVector3&, MtVector3&)> : public cDelegateBase
{
public:
    cDelegateCore();
    virtual ~cDelegateCore();
    void resize(u32 size);
    cDelegateBase::cNodeT<unsigned int(MtObject::*)(MtVector3&, MtVector3&)>* getNodeAt(u32 idx);
public:
    cDelegateBase::cNodeT<unsigned int(MtObject::*)(MtVector3&, MtVector3&)>* mpArray;  // offset: 0x8
    u32 mArrayLength;  // offset: 0x10
};

template <>
class cDelegateCore<void, void(MtObject::*)()> : public cDelegateBase
{
public:
    cDelegateCore();
    virtual ~cDelegateCore();
    void resize(u32 size);
    void shrink();
    u32 length();
    cDelegateBase::cNodeT<void(MtObject::*)()>* getNodeAt(u32 idx);
    MtObject* getObjectAt(u32 idx);
public:
    cDelegateBase::cNodeT<void(MtObject::*)()>* mpArray;  // offset: 0x8
    u32 mArrayLength;  // offset: 0x10
};

template <>
class cDelegateCore<void, void(MtObject::*)(cUnitDieInfo&)> : public cDelegateBase
{
public:
    cDelegateCore();
    virtual ~cDelegateCore();
    void resize(u32 size);
    cDelegateBase::cNodeT<void(MtObject::*)(cUnitDieInfo&)>* getNodeAt(u32 idx);
public:
    cDelegateBase::cNodeT<void(MtObject::*)(cUnitDieInfo&)>* mpArray;  // offset: 0x8
    u32 mArrayLength;  // offset: 0x10
};

template <>
class cDelegateCore<void, void(MtObject::*)(cWallHitInfo&)> : public cDelegateBase
{
public:
    cDelegateCore();
    virtual ~cDelegateCore();
    void resize(u32 size);
    cDelegateBase::cNodeT<void(MtObject::*)(cWallHitInfo&)>* getNodeAt(u32 idx);
public:
    cDelegateBase::cNodeT<void(MtObject::*)(cWallHitInfo&)>* mpArray;  // offset: 0x8
    u32 mArrayLength;  // offset: 0x10
};

template <>
class cDelegateCore<void, void(MtObject::*)(const MtVector3&)> : public cDelegateBase
{
public:
    cDelegateCore();
    virtual ~cDelegateCore();
    void resize(u32 size);
    cDelegateBase::cNodeT<void(MtObject::*)(const MtVector3&)>* getNodeAt(u32 idx);
public:
    cDelegateBase::cNodeT<void(MtObject::*)(const MtVector3&)>* mpArray;  // offset: 0x8
    u32 mArrayLength;  // offset: 0x10
};

template <>
class cDelegateCore<void, void(MtObject::*)(cpActionManager*)> : public cDelegateBase
{
public:
    cDelegateCore();
    virtual ~cDelegateCore();
    void resize(u32 size);
    cDelegateBase::cNodeT<void(MtObject::*)(cpActionManager*)>* getNodeAt(u32 idx);
public:
    cDelegateBase::cNodeT<void(MtObject::*)(cpActionManager*)>* mpArray;  // offset: 0x8
    u32 mArrayLength;  // offset: 0x10
};

template <>
class cDelegateCore<void, void(MtObject::*)(cpInput*)> : public cDelegateBase
{
public:
    cDelegateCore();
    virtual ~cDelegateCore();
    void resize(u32 size);
    cDelegateBase::cNodeT<void(MtObject::*)(cpInput*)>* getNodeAt(u32 idx);
public:
    cDelegateBase::cNodeT<void(MtObject::*)(cpInput*)>* mpArray;  // offset: 0x8
    u32 mArrayLength;  // offset: 0x10
};

template <>
class cDelegateCore<void, void(MtObject::*)(cpSequenceCtrl*, unsigned int, unsigned int, unsigned short)> : public cDelegateBase
{
public:
    cDelegateCore();
    virtual ~cDelegateCore();
    void resize(u32 size);
    cDelegateBase::cNodeT<void(MtObject::*)(cpSequenceCtrl*, unsigned int, unsigned int, unsigned short)>* getNodeAt(u32 idx);
public:
    cDelegateBase::cNodeT<void(MtObject::*)(cpSequenceCtrl*, unsigned int, unsigned int, unsigned short)>* mpArray;  // offset: 0x8
    u32 mArrayLength;  // offset: 0x10
};

template <>
class cDelegateCore<void, void(MtObject::*)(int)> : public cDelegateBase
{
public:
    cDelegateCore();
    virtual ~cDelegateCore();
    void resize(u32 size);
    cDelegateBase::cNodeT<void(MtObject::*)(int)>* getNodeAt(u32 idx);
public:
    cDelegateBase::cNodeT<void(MtObject::*)(int)>* mpArray;  // offset: 0x8
    u32 mArrayLength;  // offset: 0x10
};

template <>
class cDelegateCore<void, void(MtObject::*)(sCollision::TriangleInfo&)> : public cDelegateBase
{
public:
    cDelegateCore();
    virtual ~cDelegateCore();
    void resize(u32 size);
    cDelegateBase::cNodeT<void(MtObject::*)(sCollision::TriangleInfo&)>* getNodeAt(u32 idx);
public:
    cDelegateBase::cNodeT<void(MtObject::*)(sCollision::TriangleInfo&)>* mpArray;  // offset: 0x8
    u32 mArrayLength;  // offset: 0x10
};

template <>
class cDelegateCore<void, void(MtObject::*)(uDDOModel*)> : public cDelegateBase
{
public:
    cDelegateCore();
    virtual ~cDelegateCore();
    void resize(u32 size);
    void shrink();
    u32 length();
    cDelegateBase::cNodeT<void(MtObject::*)(uDDOModel*)>* getNodeAt(u32 idx);
public:
    cDelegateBase::cNodeT<void(MtObject::*)(uDDOModel*)>* mpArray;  // offset: 0x8
    u32 mArrayLength;  // offset: 0x10
};

template <>
class cDelegateCore<void, void(MtObject::*)(uModel::Joint*, uModel*, uCnsEdit*)> : public cDelegateBase
{
public:
    cDelegateCore();
    virtual ~cDelegateCore();
    void resize(u32 size);
    cDelegateBase::cNodeT<void(MtObject::*)(uModel::Joint*, uModel*, uCnsEdit*)>* getNodeAt(u32 idx);
public:
    cDelegateBase::cNodeT<void(MtObject::*)(uModel::Joint*, uModel*, uCnsEdit*)>* mpArray;  // offset: 0x8
    u32 mArrayLength;  // offset: 0x10
};

template <>
class cDelegateCore<void, void(MtObject::*)(unsigned int, unsigned int, float, float, float, unsigned int)> : public cDelegateBase
{
public:
    cDelegateCore();
    virtual ~cDelegateCore();
    void resize(u32 size);
    cDelegateBase::cNodeT<void(MtObject::*)(unsigned int, unsigned int, float, float, float, unsigned int)>* getNodeAt(u32 idx);
public:
    cDelegateBase::cNodeT<void(MtObject::*)(unsigned int, unsigned int, float, float, float, unsigned int)>* mpArray;  // offset: 0x8
    u32 mArrayLength;  // offset: 0x10
};

template <typename R>
class cDelegate_0 : public cDelegateCore<R, R(MtObject::*)()>
{
public:
    R operator()();
    R executeAt(u32 index);
};

template <typename R, typename _P0>
class cDelegate_1 : public cDelegateCore<R, R(MtObject::*)(_P0)>
{
public:
    R executeAt(u32 index, _P0 p0);
    R operator()(_P0 p0);
};

template <>
class cDelegate_2<unsigned int, MtVector3&, MtVector3&> : public cDelegateCore<unsigned int, unsigned int(MtObject::*)(MtVector3&, MtVector3&)>
{
public:
    unsigned int operator()(MtVector3& p0, MtVector3& p1);
};

template <typename R, typename _P0, typename _P1, typename _P2>
class cDelegate_3 : public cDelegateCore<R, R(MtObject::*)(_P0, _P1, _P2)>
{
public:
    R operator()(_P0 p0, _P1 p1, _P2 p2);
};

template <>
class cDelegate_4<void, cpSequenceCtrl*, unsigned int, unsigned int, unsigned short> : public cDelegateCore<void, void(MtObject::*)(cpSequenceCtrl*, unsigned int, unsigned int, unsigned short)>
{
public:
    void operator()(cpSequenceCtrl* p0, unsigned int p1, unsigned int p2, unsigned short p3);
};

template <>
class cDelegate_6<void, unsigned int, unsigned int, float, float, float, unsigned int> : public cDelegateCore<void, void(MtObject::*)(unsigned int, unsigned int, float, float, float, unsigned int)>
{
public:
    void operator()(unsigned int p0, unsigned int p1, float p2, float p3, float p4, unsigned int p5);
};

// Inline, no code of its own: checked where it is inlined.
inline cDelegateBase::cDelegateBase() {
}

// Inline, no code of its own: checked where it is inlined.
inline cDelegateBase::cNode::cNode() {
    this->mpThis = static_cast<MtObject*>(nullptr);
    this->mFuncName = "";
}
