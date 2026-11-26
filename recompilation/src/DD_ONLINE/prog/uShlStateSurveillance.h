#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "uShlStick.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cShlParamBase;

// Declarations
class cShlParamStateSurveillance;
class uShlStateSurveillance;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

class uShlStateSurveillance : public uShlStick
{
public:
    class MyDTI;
    class cStateSurveillanceInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cStateSurveillanceInfo : public MtObject
    {
    public:
        enum CHECK_TYPE
        {
            CHECK_TYPE_NONE = 0,
            CHECK_TYPE_ON = 1,
            CHECK_TYPE_OFF = 2,
            CHECK_TYPE_TRG_ON = 3,
            CHECK_TYPE_TRG_OFF = 4,
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
        cStateSurveillanceInfo();
        virtual ~cStateSurveillanceInfo() {}
        void copyData(const uShlStateSurveillance::cStateSurveillanceInfo& data);
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    public:
        s32 mCheckType;  // offset: 0x8
        u64 mCheckObjStatus;  // offset: 0x10
        s32 mResultCallSeNo;  // offset: 0x18
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
    const cShlParamStateSurveillance* getShlParam() const;
    uShlStateSurveillance();
    virtual ~uShlStateSurveillance();
    virtual void setup();  // vtable slot 6
    virtual void updateSub();  // vtable slot 175
private:
    bool checkData(cStateSurveillanceInfo& info);
private:
    u32 mCheckIndex;  // offset: 0x2ab0
    MtTypedArray<cStateSurveillanceInfo> mCheckArray;  // offset: 0x2ab8
public:
    static MyDTI DTI;
};

class cShlParamStateSurveillance : public cShlParamStick
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
    virtual MtDTI& getShlDTI() const;  // vtable slot 6
    cShlParamStateSurveillance();
    virtual ~cShlParamStateSurveillance();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
    virtual void addShlList(const cShlParamStateSurveillance* pParam);  // vtable slot 12
public:
    MtTypedArray<uShlStateSurveillance::cStateSurveillanceInfo> mArrayInfo;  // offset: 0x168
    static MyDTI DTI;
};

inline void* cShlParamStateSurveillance::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamStateSurveillance::cShlParamStateSurveillance() {
    mArrayInfo.setAutoDelete(true);
}

inline void* uShlStateSurveillance::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uShlStateSurveillance::cStateSurveillanceInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uShlStateSurveillance::cStateSurveillanceInfo::cStateSurveillanceInfo() {
    this->mCheckType = 0;
    this->mCheckObjStatus = 0;
    this->mResultCallSeNo = -1;
}
