#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class cFSMOrderParamCamera;
class uCameraGame;

// Declarations
namespace nFsm { class cCameraCtrl; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

namespace nFsm {

    // Forward declarations
    class cCameraCtrl;

    class cCameraCtrl : private ::MtObject
    {
    public:
        enum
        {
            R0_NONE = 0,
            R0_START = 1,
            R0_UPDATE = 2,
            R0_END = 3,
        };
        enum
        {
            R1_UPDATE_WAIT_START_CAMERA = 0,
            R1_UPDATE_WAIT_END_CAMERA = 1,
        };
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
        u8 getRno0() const;
        bool isEnable() const;
        bool isDisable() const;
        bool isCameraEnded() const;
        u32 getCameraId() const;
        u32 getCameraRes() const;
    protected:
        void setRno0(u8 r0, u8 r1);
        u8 getRno1() const;
        void setRno1(u8 r1 = 1);
    public:
        void start(const cFSMOrderParamCamera* const pParamCamera);
        void end();
        virtual void move();  // vtable slot 6
    protected:
        bool moveUpdate();
    public:
        cCameraCtrl();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    protected:
        bool mIsCameraEnemy;  // offset: 0x8
        u8 mRno0;  // offset: 0x9
        u8 mRno1;  // offset: 0xa
        u8 mSetPosType;  // offset: 0xb
        u32 mStartPosNo;  // offset: 0xc
        u32 mCamId;  // offset: 0x10
        u32 mCamRes;  // offset: 0x14
        f32 mPlStopTimer;  // offset: 0x18
    public:
        static MyDTI DTI;
    };

    f32 getDeltaSec();
    uCameraGame* getTargetCamera();

}  // namespace nFsm

inline void* nFsm::cCameraCtrl::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline bool nFsm::cCameraCtrl::isDisable() const {
    return this->mRno0 != 0;
}

inline void nFsm::cCameraCtrl::setRno1(u8 r1) {
    this->mRno1 = 1;
}
