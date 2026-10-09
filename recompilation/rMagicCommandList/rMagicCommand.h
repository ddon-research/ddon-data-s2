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
class cMagicCommand;
class cMagicCommandList;
class rMagicCommandList;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cMagicCommand : public MtObject
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
    cMagicCommand();
    virtual ~cMagicCommand();
    virtual void createProperty(MtPropertyList& proplist);  // vtable slot 4
    f32 getDegree();
private:
    bool importBinary(MtDataReader& reader);
    bool exportBinary(MtDataWriter& writer);
private:
    f32 mDegree;  // offset: 0x8
public:
    static MyDTI DTI;
};

class cMagicCommandList : public MtObject
{
    // inferred: rMagicCommandList::save calls cMagicCommandList::exportBinary
    friend class rMagicCommandList;
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
    cMagicCommandList();
    virtual ~cMagicCommandList();
    virtual void createProperty(MtPropertyList& proplist);  // vtable slot 4
    void clear();
    MtTypedArray<cMagicCommand>& getParamListEasy();
    MtTypedArray<cMagicCommand>& getParamListNormal();
    MtTypedArray<cMagicCommand>& getParamListHard();
    cMagicCommand* getParamEasy(u32 index) const;
    cMagicCommand* getParamNormal(u32 index) const;
    cMagicCommand* getParamHard(u32 index) const;
private:
    bool importBinary(MtDataReader& reader);
    bool exportBinary(MtDataWriter& writer);
public:
    MtTypedArray<cMagicCommand> mMagicCommandListEasy;  // offset: 0x8
    MtTypedArray<cMagicCommand> mMagicCommandListNormal;  // offset: 0x28
    MtTypedArray<cMagicCommand> mMagicCommandListHard;  // offset: 0x48
    static MyDTI DTI;
};

class rMagicCommandList : public cResource
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
    rMagicCommandList();
    virtual ~rMagicCommandList();
    virtual void createProperty(MtPropertyList& proplist);  // vtable slot 4
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual void clear();  // vtable slot 15
    MtTypedArray<cMagicCommandList>& getTbl();
    cMagicCommandList* getMagicCommandList(u32 tblIndex) const;
protected:
    MtTypedArray<cMagicCommandList> mMagicCommandList;  // offset: 0x70
public:
    static MyDTI DTI;
protected:
    static const u8 DATA_VERSION = 1;
};

// Inline, no code of its own: checked where it is inlined.
inline cMagicCommand::cMagicCommand() {
    this->mDegree = 0.0f;
}
