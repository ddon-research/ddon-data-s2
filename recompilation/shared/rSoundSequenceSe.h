#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "cResource.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtUI;
class rSoundRequest;

// Declarations
class rSoundSequenceSe;

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

class rSoundSequenceSe : public cResource
{
public:
    enum
    {
        COMMOND_NULL = 0,
        COMMOND_REQUEST = 1,
        COMMOND_REQUEST_RANDOM = 2,
        COMMOND_VOLUME = 3,
        COMMOND_TUNE = 4,
        COMMOND_REST = 5,
        COMMOND_LOOP_START = 6,
        COMMOND_LOOP_END = 7,
    };
public:
    class MyDTI;
    struct HEADER;
    class SequenceSe;
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
    };
public:
    class SequenceSe : public MtObject
    {
    public:
        class MyDTI;
        class Command;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class Command : public MtObject
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
            Command();
            virtual ~Command();
            virtual void createProperty(MtPropertyList& s);  // vtable slot 4
            virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
            MtColor getValueLabelColor();
        public:
            u8 mCommand;  // offset: 0x8
            f32 mValue[2];  // offset: 0xc
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
        SequenceSe();
        virtual ~SequenceSe();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        Command* getCommand(u32 index);
        u32 getDataNum();
        void deleteAll();
        void add(Command*);
        void deleteObj(s32);
        MtTypedArray<Command>* getCommandArray();
        u16 getIndex();
        void setIndex(u16);
        u16 getRequestNo();
        MtObject* getToolAdrs();
        void setToolAdrs(MtObject*);
    protected:
        MtObject* mpToolAdrs;  // offset: 0x8
        u16 mRequestNo;  // offset: 0x10
        u16 mIndex;  // offset: 0x12
        MtTypedArray<Command> mCommand;  // offset: 0x18
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
    rSoundSequenceSe();
    virtual ~rSoundSequenceSe();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    void add(SequenceSe*);
    void deleteObj(s32);
    void deleteAll();
    u32 getDataNum();
    MtTypedArray<SequenceSe>* getSequenceSeArray();
    SequenceSe* getSequenceSe(u32 index);
    rSoundRequest* getSoundRequest();
    void setSoundRequest(rSoundRequest* pRes);
    s32 getPauseStatus();
protected:
    void checkToNativeResource();
    void checkToIntermediateResource();
protected:
    rSoundRequest* mpRequest;  // offset: 0x70
    s32 mPauseStatus;  // offset: 0x78
    HEADER mHeader;  // offset: 0x7c
    MtTypedArray<SequenceSe> mSeqSe;  // offset: 0x88
public:
    static const u32 VALUE_NUM = 2;
    static MyDTI DTI;
protected:
    static const u32 NativeFileMagic = 1381061459;
    static const s32 NativeFileVersion = 1;
};
