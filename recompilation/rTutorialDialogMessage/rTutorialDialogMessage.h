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
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtObject;
class MtPropertyList;
class MtStream;

// Declarations
class rTutorialDialogMessage;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class rTutorialDialogMessage : public cResource
{
public:
    class MyDTI;
    class cDialogPage;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cDialogPage : public MtObject
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
        cDialogPage();
        virtual ~cDialogPage();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        bool load(MtDataReader& r);
        bool save(MtDataWriter& w);
    public:
        u32 mTextGmdIdx;  // offset: 0x8
        u32 mImageId;  // offset: 0xc
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
    u32 getMagicHeader() const;
    u32 getDataVersion() const;
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    rTutorialDialogMessage();
    virtual ~rTutorialDialogMessage();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual bool load(MtStream& in);  // vtable slot 11
public:
    u32 mTitleGmdIdx;  // offset: 0x70
    u32 mCategoryGmdIdx;  // offset: 0x74
    MtTypedArray<cDialogPage> mPageInfo;  // offset: 0x78
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline rTutorialDialogMessage::cDialogPage::cDialogPage() {
    this->mTextGmdIdx = static_cast<u32>(0);
    this->mImageId = static_cast<u32>(0);
}
