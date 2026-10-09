#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/cResource.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtUI;
class rSoundSubMixer;

// Declarations
class rSoundSubMixerSet;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class rSoundSubMixerSet : public cResource
{
public:
    class MyDTI;
    class BasicSubMixers;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class BasicSubMixers : public MtObject
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
        BasicSubMixers();
        virtual ~BasicSubMixers();
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        rSoundSubMixer* getResource0() const;
        void setResource0(rSoundSubMixer* res);
        rSoundSubMixer* getResource1() const;
        void setResource1(rSoundSubMixer* res);
        rSoundSubMixer* getResource2() const;
        void setResource2(rSoundSubMixer* res);
        rSoundSubMixer* getResource3() const;
        void setResource3(rSoundSubMixer* res);
        rSoundSubMixer* getResource4() const;
        void setResource4(rSoundSubMixer* res);
        rSoundSubMixer* getResource5() const;
        void setResource5(rSoundSubMixer* res);
        rSoundSubMixer* getResource6() const;
        void setResource6(rSoundSubMixer* res);
        rSoundSubMixer* getResource7() const;
        void setResource7(rSoundSubMixer* res);
    public:
        u32 mID;  // offset: 0x8
        rSoundSubMixer* mpResource0;  // offset: 0x10
        rSoundSubMixer* mpResource1;  // offset: 0x18
        rSoundSubMixer* mpResource2;  // offset: 0x20
        rSoundSubMixer* mpResource3;  // offset: 0x28
        rSoundSubMixer* mpResource4;  // offset: 0x30
        rSoundSubMixer* mpResource5;  // offset: 0x38
        rSoundSubMixer* mpResource6;  // offset: 0x40
        rSoundSubMixer* mpResource7;  // offset: 0x48
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
    rSoundSubMixerSet();
    virtual ~rSoundSubMixerSet();
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    BasicSubMixers* getBasicSubMixers(u32 index) const;
    u32 getBasicSubMixersNum() const;
    u32 getBasicSubMixersMaxID() const;
    void add();
    void add(BasicSubMixers* pSubMixers);
    void add(u32 id);
    void erase(s32 index);
    void erase(BasicSubMixers* pSubMixers);
    virtual void clear();  // vtable slot 15
private:
    void* memAlloc(u32);
    void memFree(void*);
public:
    MtArray mSubMixerLists;  // offset: 0x70
    static MyDTI DTI;
private:
    static const s32 NativeFileMagic = 1414745427;
    static const s32 NativeFileVersion = 7;
    static const u8 DATA_VERSION = 1;
};

// Inline, no code of its own: checked where it is inlined.
inline rSoundSubMixerSet::BasicSubMixers::BasicSubMixers() {
    this->mID = static_cast<u32>(0);
    this->mpResource7 = static_cast<rSoundSubMixer*>(nullptr);
    this->mpResource6 = static_cast<rSoundSubMixer*>(nullptr);
    this->mpResource5 = static_cast<rSoundSubMixer*>(nullptr);
    this->mpResource4 = static_cast<rSoundSubMixer*>(nullptr);
    this->mpResource3 = static_cast<rSoundSubMixer*>(nullptr);
    this->mpResource2 = static_cast<rSoundSubMixer*>(nullptr);
    this->mpResource1 = static_cast<rSoundSubMixer*>(nullptr);
    this->mpResource0 = static_cast<rSoundSubMixer*>(nullptr);
}
