#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtObject.h"
#include "cResource.h"
#include "sSound.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtString;
class MtUI;

// Declarations
class rSoundEQ;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class rSoundEQ : public cResource
{
public:
    class MyDTI;
    struct HEADER;
    class cEQData;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct HEADER
    {
    public:
        u32 Magic;  // offset: 0x0
        u8 Version;  // offset: 0x4
        u16 ArrayNum;  // offset: 0x6
        u16 OneSize;  // offset: 0x8
    };
public:
    class cEQData : public MtObject
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
        cEQData();
        virtual ~cEQData();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual void copy(sSound::EQParameter* p_src, u32 id, u32 category, const MtString& com);  // vtable slot 6
        u32 getEQCategory();
        sSound::EQParameter* getEQData();
        u32 getEQId();
        void setEQId(u32);
        MtString getComment();
        bool convert(MtStream& out);
    protected:
        u32 mId;  // offset: 0x8
        u32 mCategory;  // offset: 0xc
        sSound::EQParameter mEQData;  // offset: 0x10
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
    rSoundEQ();
    virtual ~rSoundEQ();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool load(MtStream& in);  // vtable slot 11
    s32 getEQDataNum();
    cEQData* getEQData(u32 index);
    cEQData* getEQDataFromId(s32 id);
    void addData(cEQData*);
    void deleteAllData();
protected:
    void createIdToIndexTbl();
    void* memAlloc(u32 size, u32 align);
    void memFree(void* p_addr);
protected:
    HEADER mHeader;  // offset: 0x70
    MtTypedArray<cEQData> mSoundEQ;  // offset: 0x80
    u16* mpIdToIndexTbl;  // offset: 0xa0
    u16 mIdToIndexTblNum;  // offset: 0xa8
public:
    static MyDTI DTI;
protected:
    static const u32 NativeFileMagic = 1381323077;
    static const s32 NativeFileVersion = 1;
};

inline void* rSoundEQ::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* rSoundEQ::cEQData::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* rSoundEQ::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rSoundEQ::DTI)->memAlloc(sz, align, rSoundEQ::DTI.getID());
}

inline rSoundEQ::rSoundEQ()
    : mpIdToIndexTbl(nullptr)
    , mIdToIndexTblNum(0)
{
    memset(&mHeader, 0, sizeof(HEADER));
    mHeader.Magic = NativeFileMagic;
    mHeader.Version = NativeFileVersion;
    mHeader.ArrayNum = 0;
    mHeader.OneSize = 0;
    mSoundEQ.setAutoDelete(true);
    setAttribute(ATTR_NATIVE | ATTR_SAVEABLE | ATTR_CREATABLE);
}

inline s32 rSoundEQ::getEQDataNum() {
    return mSoundEQ.length();
}

inline rSoundEQ::cEQData* rSoundEQ::getEQData(u32 index) {
    return mSoundEQ.at(index);
}

inline void rSoundEQ::addData(cEQData* p_data) {
    mSoundEQ.add(p_data);
}

inline void rSoundEQ::deleteAllData() {
    mSoundEQ.deleteAll(true);
}

inline void* rSoundEQ::memAlloc(u32 size, u32 align) {
    return MtMemoryAllocator::getAllocator(rSoundEQ::DTI)->memAlloc(size, align, rSoundEQ::DTI.getID());
}

inline void rSoundEQ::memFree(void* p_addr) {
    MtMemoryAllocator::getAllocator(rSoundEQ::DTI)->memFree(p_addr);
}

inline void* rSoundEQ::cEQData::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rSoundEQ::cEQData::DTI)->memAlloc(sz, align, rSoundEQ::cEQData::DTI.getID());
}

inline rSoundEQ::cEQData::cEQData()
    : mId(0xFFFFFFFFu)
    , mCategory(0)
{
    mEQData.mEnable = 0;
    mEQData.mLowType = 0;
    mEQData.mHighType = 0;
    mEQData.mLowFreq = sSound::EQ_DEFAULT_LOW_FREQ;
    mEQData.mLowGain = sSound::EQ_DEFAULT_GAIN;
    mEQData.mLowQ = sSound::EQ_DEFAULT_Q;
    mEQData.mMidLowFreq = sSound::EQ_DEFAULT_MID_LOW_FREQ;
    mEQData.mMidLowGain = sSound::EQ_DEFAULT_GAIN;
    mEQData.mMidLowQ = sSound::EQ_DEFAULT_Q;
    mEQData.mMidHighFreq = sSound::EQ_DEFAULT_MID_HIGH_FREQ;
    mEQData.mMidHighGain = sSound::EQ_DEFAULT_GAIN;
    mEQData.mMidHighQ = sSound::EQ_DEFAULT_Q;
    mEQData.mHighFreq = sSound::EQ_DEFAULT_HIGH_FREQ;
    mEQData.mHighGain = sSound::EQ_DEFAULT_GAIN;
    mEQData.mHighQ = sSound::EQ_DEFAULT_Q;
}

inline u32 rSoundEQ::cEQData::getEQId() {
    return mId;
}
