#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "cEffect.h"
#include "uFilter.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector4;
class cDraw;
class cEffectTransparency;
class rTexture;

// Declarations
namespace nEffect { class FilterParam; }
class uMultiBloomFilter;
class uMultiBlurFilter;
class uMultiColorCorrectFilter;
class uMultiFilter;
class uMultiGodRaysFilter;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

namespace nEffect {
    class FilterParam
    {
    public:
        void initSubPriority();
        void updateCommon(nEffect::FilterParam* pParam);
        bool isUpdate(nEffect::FilterParam* pParam) const;
    public:
        u32 mDrawView;  // offset: 0x0
        u32 mPriority;  // offset: 0x4
        u32 mRemainderFrame;  // offset: 0x8
        u32 mSubPriority[3];  // offset: 0xc
        u32 mForceUpdate;  // offset: 0x18
        u32 mFilterParam321c;  // offset: 0x1c
        cEffectTransparency mTransparencyParam;  // offset: 0x20
    };
}  // namespace nEffect

class uMultiFilter : public uFilter
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
    uMultiFilter();
    virtual ~uMultiFilter();
    virtual void move();  // vtable slot 9
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    u32 getDrawNum() const;
    void setDrawNum(u32 DrawNum);
    u32 getDrawMax() const;
    void setDrawMax(u32 DrawMax);
    u32 getEntry() const;
    void clearEntry();
protected:
    virtual u32 allocFilterParam(u32 DrawNum);  // vtable slot 24
    virtual void freeFilterParam();  // vtable slot 25
    virtual nEffect::FilterParam* getFilterParam(u32) = 0;  // vtable slot 26
    virtual f32 calcTransparency(cDraw*, nEffect::FilterParam*) = 0;  // vtable slot 27
    virtual s32 getFilterOrder(const MtVector4&, u32) = 0;  // vtable slot 28
    virtual void drawFilter(cDraw*, u32, f32) = 0;  // vtable slot 29
protected:
    u32 mDrawNum;  // offset: 0x54
    u32 mDrawMax;  // offset: 0x58
    u32 mEntry;  // offset: 0x5c
    nEffect::FilterParam* mpFilterParam;  // offset: 0x60
    bool mClearFlag;  // offset: 0x68
public:
    static MyDTI DTI;
};

class uMultiGodRaysFilter : public uMultiFilter
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
    uMultiGodRaysFilter();
    virtual ~uMultiGodRaysFilter();
    bool setFilterParam(nEffect::FilterParam* pSrcParam);
protected:
    virtual u32 allocFilterParam(u32 DrawNum);  // vtable slot 24
    virtual void freeFilterParam();  // vtable slot 25
    virtual nEffect::FilterParam* getFilterParam(u32 No);  // vtable slot 26
    virtual f32 calcTransparency(cDraw* pdraw, nEffect::FilterParam* pFilterParam);  // vtable slot 27
    virtual s32 getFilterOrder(const MtVector4& ViewVec, u32 No);  // vtable slot 28
    virtual void drawFilter(cDraw* pDraw, u32 EntryNo, f32 Transparency);  // vtable slot 29
public:
    static const u32 MAX_LEVEL = 5;
    static MyDTI DTI;
};

class uMultiBloomFilter : public uMultiFilter
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
    uMultiBloomFilter();
    virtual ~uMultiBloomFilter();
    bool setFilterParam(nEffect::FilterParam* pSrcParam);
protected:
    virtual u32 allocFilterParam(u32 DrawNum);  // vtable slot 24
    virtual void freeFilterParam();  // vtable slot 25
    virtual nEffect::FilterParam* getFilterParam(u32 No);  // vtable slot 26
    virtual f32 calcTransparency(cDraw* pdraw, nEffect::FilterParam* pFilterParam);  // vtable slot 27
    virtual s32 getFilterOrder(const MtVector4& ViewVec, u32 No);  // vtable slot 28
    virtual void drawFilter(cDraw* pDraw, u32 EntryNo, f32 Transparency);  // vtable slot 29
public:
    static MyDTI DTI;
};

class uMultiBlurFilter : public uMultiFilter
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
    uMultiBlurFilter();
    virtual ~uMultiBlurFilter();
    bool setFilterParam(nEffect::FilterParam* pSrcParam, rTexture* pAlphaMap);
protected:
    virtual u32 allocFilterParam(u32 DrawNum);  // vtable slot 24
    virtual void freeFilterParam();  // vtable slot 25
    virtual nEffect::FilterParam* getFilterParam(u32 No);  // vtable slot 26
    virtual f32 calcTransparency(cDraw* pdraw, nEffect::FilterParam* pFilterParam);  // vtable slot 27
    virtual s32 getFilterOrder(const MtVector4& ViewVec, u32 No);  // vtable slot 28
    virtual void drawFilter(cDraw* pDraw, u32 EntryNo, f32 Transparency);  // vtable slot 29
public:
    static MyDTI DTI;
};

class uMultiColorCorrectFilter : public uMultiFilter
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
    uMultiColorCorrectFilter();
    virtual ~uMultiColorCorrectFilter();
    virtual void move();  // vtable slot 9
    virtual void moveAfter();  // vtable slot 10
    bool setFilterParam(nEffect::FilterParam* pSrcParam);
protected:
    virtual u32 allocFilterParam(u32 DrawNum);  // vtable slot 24
    virtual void freeFilterParam();  // vtable slot 25
    virtual nEffect::FilterParam* getFilterParam(u32 No);  // vtable slot 26
    virtual f32 calcTransparency(cDraw* pdraw, nEffect::FilterParam* pFilterParam);  // vtable slot 27
    virtual s32 getFilterOrder(const MtVector4& ViewVec, u32 No);  // vtable slot 28
    virtual void drawFilter(cDraw* pDraw, u32 EntryNo, f32 Transparency);  // vtable slot 29
public:
    static MyDTI DTI;
};

inline void* uMultiBloomFilter::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uMultiBlurFilter::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uMultiColorCorrectFilter::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uMultiFilter::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uMultiGodRaysFilter::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
