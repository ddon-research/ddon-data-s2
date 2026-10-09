#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/MtObject.h"
#include "../shared/nDDOUtility.h"
#include "uFreeCamera.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
class cCharacterEditCameraParam;
class rCharacterEditCameraParam;
class uCharacterEditBase;
class uMockUpModel;

// Declarations
class uCharacterEditCameraBase;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uCharacterEditCameraBase : public uFreeCamera
{
public:
    enum CAMERA_MOVE
    {
        CAMERA_MOVE_NONE = 0,
        CAMERA_MOVE_L = 1,
        CAMERA_MOVE_R = 2,
    };
    enum MODE
    {
        MODE_DEFAULT = 0,
        MODE_RESET = 1,
    };
public:
    class MyDTI;
    class cLimit;
    class cInterpolationVector3;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cLimit : public MtObject
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
        cLimit();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        f32 length();
        bool load(MtDataReader& r);
        bool save(MtDataWriter& w);
        void set(f32 _max, f32 _min);
    public:
        f32 max;  // offset: 0x8
        f32 min;  // offset: 0xc
        static MyDTI DTI;
    };
public:
    class cInterpolationVector3
    {
    public:
        void set(const MtVector3& v, f32 speed);
        MtVector3 get();
        void setMinPower(f32);
        void setFixDelta(bool);
        void execute();
        f32 getPow();
    public:
        uGUIBase::cInterpolationValue mX;  // offset: 0x0
        uGUIBase::cInterpolationValue mY;  // offset: 0x28
        uGUIBase::cInterpolationValue mZ;  // offset: 0x50
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
    uCharacterEditCameraBase();
    virtual ~uCharacterEditCameraBase();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void setResetMode();  // vtable slot 27
    cCharacterEditCameraParam* getCameraParam(MT_CTSTR str);
    virtual void updateCameraParam();  // vtable slot 28
    void updateCameraData();
    void updateInterPos();
    void moveKey();
    void rotateModel();
    void reset();
    void isLimitCheck(f32& value, cLimit& limit);
    void setCameraRiviseSpeed(f32 f);
    void lockCameraMove();
    void clearLock();
    bool isLock() const;
    void addRotateRSY(f32 add_y);
protected:
    void convertCameraParam(f32& f);
    void initCameraParam();
protected:
    rCharacterEditCameraParam* mpCameraParam;  // offset: 0xe8
    cCharacterEditCameraParam* mpNowCameraParam;  // offset: 0xf0
    cCharacterEditCameraParam* mpOldCameraParam;  // offset: 0xf8
    f32 mLength;  // offset: 0x100
    uGUIBase::cInterpolationValue mInterLength;  // offset: 0x108
    MtVector3 mRotateRS;  // offset: 0x130
    MtVector3 mRotateLS;  // offset: 0x140
    bool mIsLSenableRotate;  // offset: 0x150
    f32 mZoomSpeed;  // offset: 0x154
    f32 mRotateSpeed;  // offset: 0x158
    cInterpolationVector3 mInterTargetPos;  // offset: 0x160
    cInterpolationVector3 mInterCameraPos;  // offset: 0x1d8
    f32 mAngle;  // offset: 0x250
    f32 mAngleAdd;  // offset: 0x254
    MtVector3 mResetAngle;  // offset: 0x260
    f32 mResetMaxSpeed;  // offset: 0x270
    CAMERA_MOVE mCameraMode;  // offset: 0x274
    s32 mWaitFrame;  // offset: 0x278
    uMockUpModel* mpModel;  // offset: 0x280
    uCharacterEditBase* mpEditUnit;  // offset: 0x288
    nDDOUtility::cArray<MtVector3, 2> mParamCameraPos;  // offset: 0x290
    nDDOUtility::cArray<MtVector3, 2> mParamTargetPos;  // offset: 0x2b0
    nDDOUtility::cArray<MtVector3, 2> mParamGlobalOffset;  // offset: 0x2d0
    f32 mCameraRiviseSpeed;  // offset: 0x2f0
    MODE mMode;  // offset: 0x2f4
    bool mIsLock;  // offset: 0x2f8
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline uCharacterEditCameraBase::cLimit::cLimit() {
    this->max = 0.0f;
    this->min = 0.0f;
}
