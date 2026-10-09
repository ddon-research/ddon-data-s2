#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cResource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtObject;
class MtStream;

// Declarations
class rTbl2Base;
template <typename T> class rTbl2;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class rTbl2Base : public cResource
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
    rTbl2Base();
protected:
    void readDataValue(MtDataReader& r, u32& data);
    void writeDataValue(MtDataWriter& w, u32 data);
public:
    static MyDTI DTI;
};

template <typename T>
class rTbl2 : public rTbl2Base
{
public:
    rTbl2();
    virtual ~rTbl2();
    virtual bool loadData(MtDataReader&, T*) = 0;  // vtable slot 16
    virtual T* getData(u32 idx);  // vtable slot 17
    virtual const T* getData(u32 idx) const;  // vtable slot 18
    virtual u32 getDataNum() const;  // vtable slot 19
    virtual MT_CTSTR getExt() const = 0;  // vtable slot 7
    virtual bool load(MtStream& in);  // vtable slot 11
    bool loadRoot(MtDataReader& r);
    virtual u32 getDataVersion() const = 0;  // vtable slot 20
protected:
    virtual bool loadCore(MtDataReader& r);  // vtable slot 21
    void allocData(u32 num);
    void deleteData();
public:
    T* mpData;  // offset: 0x70
    u32 mDataNum;  // offset: 0x78
};

// Included after the classes: the generic bodies below need these complete.
#include "MtDataReader.h"

// Generic (024 T808): every instance that renders gives this body; the unit of each instance's compile unit, else rTbl2.cpp, instantiates it for the body oracle.
template <typename T>
T* rTbl2<T>::getData(u32 idx) {
    if (idx < this->mDataNum) {
        return &this->mpData[idx];
    } else {
        return static_cast<T*>(nullptr);
    }
}

// Generic (024 T808): every instance that renders gives this body; the unit of each instance's compile unit, else rTbl2.cpp, instantiates it for the body oracle.
template <typename T>
bool rTbl2<T>::load(MtStream& in) {
    MtDataReader r(in, static_cast<u32>(4096));
    return this->::rTbl2<T>::loadRoot(r);
}

// Generic (024 T808): every instance that renders gives this body; the unit of each instance's compile unit, else rTbl2.cpp, instantiates it for the body oracle.
// approximate: the family's one template definition, for an instance the renderer refused (constitution 2.4.0); its verdict is reported
template <typename T>
bool rTbl2<T>::loadCore(MtDataReader& r) {
    u32 dat_num;
    this->::rTbl2Base::readDataValue(r, dat_num);
    this->::rTbl2<T>::allocData(dat_num);
    if (dat_num != static_cast<u32>(0)) {
        u32 i = static_cast<u32>(0);
        T* p_dat = this->mpData;
        do {
            if (this->loadData(r, &p_dat[i]) == false) {
                return false;
            }
            i += static_cast<u32>(1);
        } while (i < dat_num);
    }
    return true;
}

// Generic (024 T808): every instance that renders gives this body; the unit of each instance's compile unit, else rTbl2.cpp, instantiates it for the body oracle.
template <typename T>
const T* rTbl2<T>::getData(u32 idx) const {
    if (idx < this->mDataNum) {
        return &this->mpData[idx];
    } else {
        return static_cast<const T*>(nullptr);
    }
}

// Generic (024 T808): every instance that renders gives this body; the unit of each instance's compile unit, else rTbl2.cpp, instantiates it for the body oracle.
template <typename T>
u32 rTbl2<T>::getDataNum() const {
    return this->mDataNum;
}

// Generic (024 T863c): every instance's inlined copies give this body; no code of its own, checked where it is inlined (rendered.json inline_proofs).
template <typename T>
inline bool rTbl2<T>::loadRoot(MtDataReader& r) {
    u32 ver;
    this->::rTbl2Base::readDataValue(r, ver);
    // inferred: a temporary for `ver` read before a later call; no DWARF local holds it
    u32 t0 = ver;
    if (t0 == this->getDataVersion()) {
        return this->loadCore(r);
    } else {
        return false;
    }
}

// Generic (024 T863c): every instance's inlined copies give this body; no code of its own, checked where it is inlined (rendered.json inline_proofs).
template <typename T>
inline rTbl2<T>::rTbl2() {
    this->::cResource::setAttribute(static_cast<u32>(16));
    this->mpData = static_cast<T*>(nullptr);
    this->mDataNum = static_cast<u32>(0);
}
