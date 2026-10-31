#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "cAreaHit.h"
#include "../../XFramework/cSystem.h"

// Forward declarations
struct AH_CREATE_INFO;
class MtAllocator;
class MtArray;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
class cAreaHit;

// Declarations
class sAreaHit;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using __uintptr_t = __uint64_t;
using f32 = float;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using uintptr = __uintptr_t;

class sAreaHit : public cSystem
{
public:
    class MyDTI;
    struct MoveJob;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct MoveJob
    {
    public:
        cAreaHit* * ah_array;  // offset: 0x0
        u32 array_num;  // offset: 0x8
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
    sAreaHit();
    virtual ~sAreaHit();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    void init();
    virtual void reset();  // vtable slot 6
    virtual void move();  // vtable slot 7
    void final();
    static sAreaHit* getInstance();
    virtual void areaReset();  // vtable slot 10
    void setPause(bool);
    bool isPause() const;
    void setParallel(bool);
    bool isParallel() const;
    virtual void moveJob(uintptr move);  // vtable slot 11
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 9
    cAreaHit* create(MtObject* pOwner);
    cAreaHit* create(AREAHIT_SHAPE_TYPE_ENUM shape, MtObject* pOwner);
    cAreaHit* create(AH_CREATE_INFO& ci, MtObject* pOwner);
    void release(cAreaHit* p);
    u32 getNum();
    static f32 yaw(const MtVector3& vec);
private:
    MtArray mArray;  // offset: 0x18
    bool mbPause;  // offset: 0x38
    bool mbParallel;  // offset: 0x39
    u16 mUID;  // offset: 0x3a
    cAreaHit* mAHPointer[1024];  // offset: 0x40
    MoveJob mJobInfo[6];  // offset: 0x2040
    static sAreaHit* mpInstance;
public:
    static MyDTI DTI;
};

inline sAreaHit* sAreaHit::getInstance() {
    return ::sAreaHit::mpInstance;
}
