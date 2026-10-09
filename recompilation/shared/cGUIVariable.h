#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;

// Declarations
class cGUIVarInt;
class cGUIVariable;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cGUIVariable : public MtObject
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
    cGUIVariable();
    virtual ~cGUIVariable();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createEventProperty(MtPropertyList& s);  // vtable slot 6
    virtual const MT_CTSTR* getEventPropertyTooltip();  // vtable slot 7
    void setStaticName(MT_CTSTR pName);
    MT_CTSTR getStaticName() const;
    void setId(u32 id);
    u32 getId() const;
    virtual s32 getS32() const = 0;  // vtable slot 8
    bool isDynamic() const;
    void setLoopValue(bool v);
    bool isLoopValue() const;
    bool isUpdate() const;
protected:
    void setUpdateFlag(bool flag);
private:
    void setDynamic(bool v);
private:
    u32 mId;  // offset: 0x8
    u32 mAttr : 16;  // offset: 0xc
    u32 mUpdate : 1;  // offset: 0xc
    u32 padding : 15;  // offset: 0xc
    MT_CTSTR mpName;  // offset: 0x10
public:
    static MyDTI DTI;
private:
    static const u32 ATTR_DYNAMIC = 1;
    static const u32 ATTR_LOOP_VALUE = 2;
};

class cGUIVarInt : public cGUIVariable
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
    cGUIVarInt();
    virtual ~cGUIVarInt();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createEventProperty(MtPropertyList& s);  // vtable slot 6
    virtual const MT_CTSTR* getEventPropertyTooltip();  // vtable slot 7
    virtual s32 getS32() const;  // vtable slot 8
    void set(s32 value, bool forceUpdate);
    s32 get() const;
    void setOld(s32 value);
    s32 getOld() const;
    void setInit(s32 value);
    s32 getInit() const;
    void setMax(s32 value);
    s32 getMax() const;
    void setMin(s32 value);
    s32 getMin() const;
    s32 increment();
    s32 decrement();
protected:
    void setValue(s32 value);
private:
    void incrementForProperty();
    void decrementForProperty();
private:
    s32 mValue;  // offset: 0x18
    s32 mOldValue;  // offset: 0x1c
    s32 mInitValue;  // offset: 0x20
    s32 mMaxValue;  // offset: 0x24
    s32 mMinValue;  // offset: 0x28
public:
    static MyDTI DTI;
};
