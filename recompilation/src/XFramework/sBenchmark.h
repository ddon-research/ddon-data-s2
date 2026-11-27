#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "../MT/MtObject.h"
#include "cSystem.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;

// Declarations
class sBenchmark;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class sBenchmark : public cSystem
{
public:
    enum BENCHMARK_STATE
    {
        BS_OA = 0,
        BS_WAIT = 1,
        BS_START = 2,
        BS_LOAD = 3,
        BS_WARMING = 4,
        BS_UPDATE = 5,
        BS_END = 6,
    };
public:
    class MyDTI;
    class BenchmarkInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class BenchmarkInfo : public MtObject
    {
        friend class sBenchmark;
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
        BenchmarkInfo();
        const MtDTI& getAreaType() const;
        MT_CTSTR getName() const;
        u32 getMeasureFrame() const;
        f32 getAvgFPS() const;
        f32 getPrevAvgFPS() const;
        void setAreaType(const MtDTI& type);
        void setName(MT_CTSTR name);
        void setMeasureFrame(u32 frame);
        void setAvgFPS(f32 f);
        void setPrevAvgFPS(f32 f);
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        const MtDTI* mpArea;  // offset: 0x8
        MT_CTSTR mName;  // offset: 0x10
        u32 mMeasureFrame;  // offset: 0x18
        f32 mAvgFPS;  // offset: 0x1c
        f32 mPrevAvgFPS;  // offset: 0x20
    public:
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
    sBenchmark();
    virtual ~sBenchmark();
    virtual void reset();  // vtable slot 6
    virtual void move();  // vtable slot 7
    static sBenchmark* getInstance();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createMenu(MtPropertyList& s);  // vtable slot 8
    s32 addBenchmark(const MtDTI& area, u32 frame, MT_CTSTR name);
    void startBenchmark(s32 benchmark_index);
    u32 getBenchmarkNum();
    const BenchmarkInfo* getBenchmarkInfo(u32 index);
    const BenchmarkInfo* getCurrentBenchmarkInfo();
    bool close();
protected:
    virtual bool jumpArea(const BenchmarkInfo* pinfo);  // vtable slot 10
    virtual bool isAreaInitialized(const BenchmarkInfo* pinfo);  // vtable slot 11
    void updateOA();
    void setBenchmarkInfo(MtObject*, u32);
    void setBenchmarkNum(u32);
protected:
    BenchmarkInfo mBenchmark[256];  // offset: 0x18
    u32 mBenchmarkNum;  // offset: 0x2818
    u32 mBenchmarkIndex;  // offset: 0x281c
    bool mBenchmarkAll;  // offset: 0x2820
    bool mOAEnable;  // offset: 0x2821
    u32 mBenchmarkState;  // offset: 0x2824
    f32 mFrameTime;  // offset: 0x2828
    u32 mMaxFrameTime;  // offset: 0x282c
    u32 mFrameCount;  // offset: 0x2830
    bool mFrameWait;  // offset: 0x2834
    f32 mMaxFps;  // offset: 0x2838
    bool mToolVisible;  // offset: 0x283c
public:
    static MyDTI DTI;
protected:
    static const u32 MAX_BENCHMARK = 256;
    static sBenchmark* mpInstance;
};

inline void* sBenchmark::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline u32 sBenchmark::getBenchmarkNum() {
    return this->mBenchmarkNum;
}

inline const sBenchmark::BenchmarkInfo* sBenchmark::getBenchmarkInfo(u32 index) {
    return &this->mBenchmark[index];
}

inline void* sBenchmark::BenchmarkInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline sBenchmark::BenchmarkInfo::BenchmarkInfo() {
    this->mPrevAvgFPS = 0.0f;
    this->mMeasureFrame = 0;
    this->mAvgFPS = 0.0f;
    this->mName = nullptr;
    this->mpArea = nullptr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void sBenchmark::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::sBenchmark::DTI)->memFree(p_addr);
}

inline void* sBenchmark::BenchmarkInfo::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::sBenchmark::BenchmarkInfo::DTI)->memAlloc(sz, align, ::sBenchmark::BenchmarkInfo::DTI.::MtDTI::mID);
}

inline void sBenchmark::BenchmarkInfo::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::sBenchmark::BenchmarkInfo::DTI)->memFree(p_addr);
}
