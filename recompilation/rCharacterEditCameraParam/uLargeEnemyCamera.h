#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/cUnit.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class uEnemy;

// Declarations
class uLargeEnemyCamera;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class uLargeEnemyCamera : public cUnit
{
public:
    enum
    {
        EM_LARGE_CAMERA_OFFSET = 100,
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
    uLargeEnemyCamera();
    virtual ~uLargeEnemyCamera();
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    bool isLargeCamera();
private:
    bool isSameGroupEnemy(uEnemy* pEnemy);
private:
    f32 mStartDistance;  // offset: 0x48
    f32 mEndDistance;  // offset: 0x4c
    bool mIsLargeCamera;  // offset: 0x50
    bool mIsDissolveEmLarge;  // offset: 0x51
    f32 mTimer;  // offset: 0x54
    f32 mRange2;  // offset: 0x58
    u32 mCamera;  // offset: 0x5c
    u32 mEnemyID;  // offset: 0x60
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline bool uLargeEnemyCamera::isLargeCamera() {
    return this->mIsLargeCamera;
}
