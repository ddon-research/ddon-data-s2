#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "cQuestFunctionManagerBAse.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;

// Declarations
class cAreaReleaseManager;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class cAreaReleaseManager : public cQuestFunctionManagerBase
{
public:
    class MyDTI;
    class cAreaReleaseInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cAreaReleaseInfo : public MtObject
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
        cAreaReleaseInfo();
        virtual ~cAreaReleaseInfo() {}
    public:
        u16 mId;  // offset: 0x8
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
    u32 getAreaId() const;
    void setAreaId(u32 areaId);
    bool isAreaRelease(u16 id) const;
    void setAreaRelease(u16 id);
    void setAreaReleaseByRankUp(u16 id);
    u16 getAreaReleaseByRankUp(u32 index) const;
    u32 getAreaReleaseNumByRankUp() const;
    bool reqGetAreaReleaseInfo();
    bool getAreaReleaseInfo();
    void resetAreaRelease();
    void resetAreaReleaseByRankUp();
    void resetReleaseInfoRequest();
    void disableReleaseInfoRequest();
    bool isEnableRequest();
    void callbackInstanceAreaReset();
    bool isEnableSendMsg();
    cAreaReleaseManager();
    virtual ~cAreaReleaseManager();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    u32 mAreaId;  // offset: 0x8
    MtTypedArray<cAreaReleaseInfo> mAreaReleaseInfo;  // offset: 0x10
    MtTypedArray<cAreaReleaseInfo> mAreaReleaseInfoByRankUp;  // offset: 0x30
    bool mIsRequested;  // offset: 0x50
    s32 mResetStageNo;  // offset: 0x54
    s32 mResetStageNoPt[8];  // offset: 0x58
    static MyDTI DTI;
    static const u16 INVALID_AREA_RELEASE_ID = 65535;
};

inline void* cAreaReleaseManager::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline u32 cAreaReleaseManager::getAreaId() const {
    return this->mAreaId;
}

inline void* cAreaReleaseManager::cAreaReleaseInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cAreaReleaseManager::cAreaReleaseInfo::cAreaReleaseInfo() {
    this->mId = 0xFFFF;
}
