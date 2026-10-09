#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/cResource.h"
#include "../shared/sSound.h"

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
class rSoundReverb;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class rSoundReverb : public cResource
{
public:
    class MyDTI;
    struct HEADER;
    class cSoundReverbData;
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
    class cSoundReverbData : public MtObject
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
        cSoundReverbData();
        virtual ~cSoundReverbData();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual void copy(sSound::ReverbParameter* p_src, u32 id, f32 outputLevel, const MtString& com);  // vtable slot 6
        MtString getComment();
        sSound::ReverbParameter* getReverbData();
        f32 getOutputLevel();
        f32 getOutputLevelRatio();
        u32 getReverbId();
        void setReverbId(u32);
        bool convert(MtStream& out);
    protected:
        u32 mId;  // offset: 0x8
        sSound::ReverbParameter mReverbData;  // offset: 0xc
        f32 mOutputLevel;  // offset: 0x44
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
    rSoundReverb();
    virtual ~rSoundReverb();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool load(MtStream& in);  // vtable slot 11
    s32 getReverbDataNum();
    cSoundReverbData* getReverbData(s32 index);
    cSoundReverbData* getReverbDataFromId(s32 id);
    void addData(cSoundReverbData*);
    void deleteAllData();
protected:
    bool createIdToIndexTbl();
    void* memAlloc(u32 size, u32 align);
    void memFree(void* p_addr);
protected:
    HEADER mHeader;  // offset: 0x70
    MtTypedArray<cSoundReverbData> mReverb;  // offset: 0x80
    u16* mpIdToIndexTbl;  // offset: 0xa0
    u16 mIdToIndexTblNum;  // offset: 0xa8
public:
    static MyDTI DTI;
    static const f32 MIN_OUTPUTLEVEL_DB;
    static const f32 MAX_OUTPUTLEVEL_DB;
    static const f32 DEF_OUTPUTLEVEL_DB;
protected:
    static const u32 NativeFileMagic = 1381385554;
    static const s32 NativeFileVersion = 1;
};
