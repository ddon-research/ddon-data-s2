#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "MtPrimitive3D.h"

// Forward declarations
class MtAllocator;
class MtCapsule;
class MtDTI;
class MtQuaternion;
class MtVector3;
class cHitGeom;
class uDDOModel;

// Declarations
namespace nShlStick { class cStickObjectCtrl; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

namespace nShlStick {
    class cStickObjectCtrl : public ::MtObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        cStickObjectCtrl();
        virtual ~cStickObjectCtrl();
        virtual void updatePtr();  // vtable slot 6
        bool findStickCapsule(uDDOModel* pMod, const MtVector3& pos);
        void storeStickInfo(const cHitGeom* pGeom, uDDOModel* pDDOModel);
        bool calcHitPos(const MtCapsule& cap, const MtVector3& pos, MtVector3* pPos, MtVector3* pNormal, f32 offset);
        void setTargetUID(u32);
        void setJoint0(u32);
        void setOffset0(const MtVector3&);
        const uDDOModel* getStickModel() const;
        void copy(const nShlStick::cStickObjectCtrl& ctrl);
    public:
        u32 mTargetUID;  // offset: 0x8
        u32 mShape;  // offset: 0xc
        s32 mJoint0;  // offset: 0x10
        s32 mJoint1;  // offset: 0x14
        MtVector3 mOffset0;  // offset: 0x20
        MtVector3 mOffset1;  // offset: 0x30
        MtVector3 mStickPos;  // offset: 0x40
        MtQuaternion mTgtQuat;  // offset: 0x50
        uDDOModel* mpStickModel;  // offset: 0x60
        MtCapsule mCapsule;  // offset: 0x70
        bool mIsCalcOnce;  // offset: 0xa0
        static MyDTI DTI;
    };
}  // namespace nShlStick
