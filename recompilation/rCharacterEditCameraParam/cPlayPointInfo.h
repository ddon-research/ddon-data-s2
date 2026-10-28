#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;

// Declarations
class cPlayPointInfo;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cPlayPointInfo : public MtObject
{
public:
    class MyDTI;
    class cPlayPoint;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cPlayPoint : public MtObject
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
        cPlayPoint(u8 jobId, u8 expMode, u32 playpoint);
        cPlayPoint();
    public:
        u8 mJobId;  // offset: 0x8
        u8 mExpMode;  // offset: 0x9
        u32 mPlayPoint;  // offset: 0xc
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
    cPlayPointInfo();
    virtual ~cPlayPointInfo();
    cPlayPoint* getPlayPoint(u8 jobId);
    cPlayPoint* getMyPlayPoint();
    MtTypedArray<cPlayPoint>& getPlayPointList();
    void addPlayPoint(u8 jobId, u8 mode, u32 playpoint);
    void updatePlayPoint(u8 jobId, u8 mode, u32 playpoint);
    void updatePlayPointMode(u8 jobId, u8 mode);
    void updaptePlayPointValue(u8 jobId, u32 playpoint);
    void setPlayPointLimit(u32 limit);
    u32 getPlayPointLimit();
    void setPlayPointJobLevel(u32 jobLevel);
    u32 getPlayPointJobLevel();
private:
    MtTypedArray<cPlayPoint> mJobPlayPointList;  // offset: 0x8
    u32 mPlayPointLimit;  // offset: 0x28
    u32 mPlayPointJobLevel;  // offset: 0x2c
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
// inferred: a single inlined copy's body: the copy inlined in aMenu::move at 0x4a2a-0x4a2d; it may reflect that caller's specialization (constants folded in, dead stores dropped), so read it with caution (026 plan-P76, ruling D-C2); approximate: no recompile checks it
inline void cPlayPointInfo::setPlayPointLimit(u32 limit) {
    this->mPlayPointLimit = limit;
}

// Inline, no code of its own: checked where it is inlined.
// inferred: a single inlined copy's body: the copy inlined in aMenu::move at 0x4a21-0x4a24; it may reflect that caller's specialization (constants folded in, dead stores dropped), so read it with caution (026 plan-P76, ruling D-C2); approximate: no recompile checks it
inline void cPlayPointInfo::setPlayPointJobLevel(u32 jobLevel) {
    this->mPlayPointJobLevel = jobLevel;
}

// Inline, no code of its own: checked where it is inlined.
// inferred: a single inlined copy's body: the copy inlined in uGUIPPShop::initPPShop at 0xbd9e23-0xbd9e26; it may reflect that caller's specialization (constants folded in, dead stores dropped), so read it with caution (026 plan-P76, ruling D-C2); approximate: no recompile checks it
inline u32 cPlayPointInfo::getPlayPointJobLevel() {
    return this->mPlayPointJobLevel;
}

// Inline, no code of its own: checked where it is inlined.
inline cPlayPointInfo::cPlayPoint::cPlayPoint() {
    this->mJobId = 0;
    this->mExpMode = 0;
    this->mPlayPoint = 0;
}
