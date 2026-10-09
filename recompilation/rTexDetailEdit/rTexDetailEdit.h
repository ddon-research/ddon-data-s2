#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/MtString.h"
#include "../shared/cResource.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtString;
class MtUI;

// Declarations
class rTexDetailEdit;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class rTexDetailEdit : public cResource
{
public:
    enum DETAIL_TYPE
    {
        DETAIL_TYPE_HIGHEST = 0,
        DETAIL_TYPE_HIGH = 1,
        DETAIL_TYPE_MEDIUM = 2,
        DETAIL_TYPE_LOW = 3,
        DETAIL_TYPE_LOWEST = 4,
    };
    enum TEX_LIMIT
    {
        TEX_LIMIT_ON = 0,
        TEX_LIMIT_OFF = 1,
        TEX_LIMIT_NUM = 2,
    };
public:
    class MyDTI;
    class DetailParam;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class DetailParam : public MtObject
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
        DetailParam();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        MT_CTSTR getPath();
        void setPath(const MtString& n);
        u32 getForm();
        void setForm(const u32 n);
        u32 getType();
        void setType(u32 n);
        u32 getIgnoreLimit() const;
        void setIgnoreLimit(u32);
    protected:
        MtString mPath;  // offset: 0x8
        u32 mForm;  // offset: 0x10
        u32 mType;  // offset: 0x14
        u32 mIgnoreLimit;  // offset: 0x18
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
    rTexDetailEdit();
    virtual ~rTexDetailEdit();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual bool create();  // vtable slot 9
    virtual void clear();  // vtable slot 15
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    u32 getEditListNum();
    MtArray* getEditList();
    DetailParam* getEditWork(u32 idx);
private:
    MtArray mEditList;  // offset: 0x70
public:
    static MyDTI DTI;
    static const s32 DATA_VERSION = 6;
};

// Inline, no code of its own: checked where it is inlined.
inline rTexDetailEdit::DetailParam::DetailParam() {
    this->mForm = static_cast<u32>(4294967295);
    this->mType = static_cast<u32>(0);
    this->mIgnoreLimit = static_cast<u32>(0);
}
