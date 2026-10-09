#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "cResource.h"
#include "nStamina.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtUI;

// Declarations
class cStaminaDecList;
class cStaminaDecParam;
class rStaminaDecTbl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cStaminaDecParam : public MtObject
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
    cStaminaDecParam();
    // Address: 0x01ab3c00 - 0x01ab3c01 (1 bytes)
    virtual ~cStaminaDecParam() {}
    virtual void createProperty(MtPropertyList& proplist);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    f32 getStamina() const;
private:
    bool importBinary(MtDataReader& reader);
    bool exportBinary(MtDataWriter& writer);
private:
    f32 mStamina;  // offset: 0x8
public:
    static MyDTI DTI;
};

class cStaminaDecList : public MtObject
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
    cStaminaDecList();
    virtual ~cStaminaDecList();
    virtual void createProperty(MtPropertyList& proplist);  // vtable slot 4
    void clear();
    MtTypedArray<cStaminaDecParam>& getParamList();
    cStaminaDecParam* getParam(u32 index) const;
    u32 getStaminaType();
    nStamina::VALUE_TYPE getValueType() const;
    nStamina::CONTINUATION_TYPE getContinuationType() const;
    nStamina::UPDATE_TYPE getExecuteType() const;
private:
    bool importBinary(MtDataReader& reader);
    bool exportBinary(MtDataWriter& writer);
private:
    MtTypedArray<cStaminaDecParam> mStaminaDecList;  // offset: 0x8
    u32 mStaminaType;  // offset: 0x28
    nStamina::VALUE_TYPE mValueType;  // offset: 0x2c
    nStamina::CONTINUATION_TYPE mCType;  // offset: 0x30
    nStamina::UPDATE_TYPE mExecuteType;  // offset: 0x34
public:
    static MyDTI DTI;
};

class rStaminaDecTbl : public cResource
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
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    u32 getMagic() const;
    rStaminaDecTbl();
    virtual ~rStaminaDecTbl();
    virtual void createProperty(MtPropertyList& proplist);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual void clear();  // vtable slot 15
    MtTypedArray<cStaminaDecList>& getTbl();
    cStaminaDecList* getStaminaDecList(u32 tblIndex) const;
private:
    MtTypedArray<cStaminaDecList> mDecTbl;  // offset: 0x70
public:
    static MyDTI DTI;
    static const u32 DATA_VERSION;
};

// Inline, no code of its own: checked where it is inlined.
inline cStaminaDecList::cStaminaDecList() {
    this->mCType = static_cast<nStamina::CONTINUATION_TYPE>(0);
    this->mExecuteType = static_cast<nStamina::UPDATE_TYPE>(0);
    this->mStaminaType = static_cast<u32>(0);
    this->mValueType = static_cast<nStamina::VALUE_TYPE>(0);
    this->mStaminaDecList.::MtArray::mAutoDelete = true;
}

// Inline, no code of its own: checked where it is inlined.
inline cStaminaDecParam::cStaminaDecParam() {
    this->mStamina = 0.0f;
}
