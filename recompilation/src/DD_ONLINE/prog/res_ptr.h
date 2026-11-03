#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
class cResource;

// Declarations
class cResPtrBase;
template <typename T> class res_ptr;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;

class cResPtrBase
{
public:
    cResPtrBase();
    ~cResPtrBase();
protected:
    void setPtr(cResource* & pDst, cResource* pRes);
    void setNative(cResource* & pDst, cResource* pRes);
    void toNative(cResource* & pDst);
    void toIntermediate(cResource* & pDst);
    void saveAs(cResource* pRes, MT_CTSTR path);
    void releasePtr(cResource* & pRes);
};

template <typename T>
class res_ptr : public cResPtrBase
{
public:
    res_ptr();
    ~res_ptr();
    void setPtr(res_ptr<T>& src);
    void setPtr(T* src);
    void releasePtr();
    T* getResPtr();
    res_ptr<T>& operator=(res_ptr<T>& src);
    res_ptr<T>& operator=(T* pRes);
    bool operator!=(res_ptr<T>& src);
    bool isResUsage() const;
    const T* getResPtr() const;
    bool isNull() const;
    res_ptr(T* src);
public:
    T* mpPtr;  // offset: 0x0
};

inline cResPtrBase::cResPtrBase() {
}
