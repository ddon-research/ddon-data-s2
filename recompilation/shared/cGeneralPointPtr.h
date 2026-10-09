#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
class cGeneralPoint;
class cpJob06;

// Declarations
class cGeneralPointPtr;

// Type aliases from DWARF
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;

class cGeneralPointPtr
{
    // inferred: cpJob06::kill names cpJob06::mBeforeMagicTarget.mRefIdx
    friend class cpJob06;
public:
    cGeneralPointPtr();
    cGeneralPointPtr(const cGeneralPointPtr& src);
    ~cGeneralPointPtr();
    void releaseGpPtr();
    cGeneralPoint* operator=(cGeneralPoint* p);
    cGeneralPoint* operator=(const cGeneralPointPtr& ptr);
    operator cGeneralPoint *();
    operator const cGeneralPoint *() const;
    cGeneralPoint* get();
    const cGeneralPoint* get() const;
    bool operator==(const cGeneralPoint* p) const;
    bool operator!=(const cGeneralPoint* p) const;
    bool operator==(const cGeneralPointPtr&) const;
    bool operator!=(const cGeneralPointPtr& p) const;
    static void* operator new(size_t s);
    static void operator delete(void* padr);
    static void* operator new[](size_t s);
    static void operator delete[](void* padr);
protected:
    cGeneralPoint* mpPtr;  // offset: 0x0
    s32 mRefIdx;  // offset: 0x8
};
