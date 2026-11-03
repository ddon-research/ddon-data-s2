#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "../MT/MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;

// Declarations
class cGUIVarFloat;
class cGUIVarInt;
class cGUIVariable;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
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

class cGUIVarFloat : public cGUIVariable
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
    cGUIVarFloat();
    virtual ~cGUIVarFloat();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual s32 getS32() const;  // vtable slot 8
    void set(f32 value, bool forceUpdate);
    f32 get() const;
    void setOld(f32 value);
    f32 getOld() const;
    void setInit(f32 value);
    f32 getInit() const;
    void setMax(f32 value);
    f32 getMax() const;
    void setMin(f32 value);
    f32 getMin() const;
protected:
    void setValue(f32 value);
private:
    f32 mValue;  // offset: 0x18
    f32 mOldValue;  // offset: 0x1c
    f32 mInitValue;  // offset: 0x20
    f32 mMaxValue;  // offset: 0x24
    f32 mMinValue;  // offset: 0x28
public:
    static MyDTI DTI;
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

inline f32 cGUIVarFloat::get() const {
    return this->mValue;
}

inline f32 cGUIVarFloat::getOld() const {
    return this->mOldValue;
}

inline void cGUIVarFloat::setInit(f32 value) {
    this->mInitValue = value;
}

inline f32 cGUIVarFloat::getInit() const {
    return this->mInitValue;
}

inline void cGUIVarFloat::setMax(f32 value) {
    this->mMaxValue = value;
}

inline f32 cGUIVarFloat::getMax() const {
    return this->mMaxValue;
}

inline void cGUIVarFloat::setMin(f32 value) {
    this->mMinValue = value;
}

inline f32 cGUIVarFloat::getMin() const {
    return this->mMinValue;
}

inline s32 cGUIVarInt::get() const {
    return this->mValue;
}

inline s32 cGUIVarInt::getOld() const {
    return this->mOldValue;
}

inline void cGUIVarInt::setInit(s32 value) {
    this->mInitValue = value;
}

inline s32 cGUIVarInt::getInit() const {
    return this->mInitValue;
}

inline void cGUIVarInt::setMax(s32 value) {
    this->mMaxValue = value;
}

inline s32 cGUIVarInt::getMax() const {
    return this->mMaxValue;
}

inline void cGUIVarInt::setMin(s32 value) {
    this->mMinValue = value;
}

inline s32 cGUIVarInt::getMin() const {
    return this->mMinValue;
}

inline void* cGUIVariable::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline u32 cGUIVariable::getId() const {
    return this->mId;
}

inline void cGUIVariable::setLoopValue(bool v) {
    if (v) {
        this->mAttr = this->mAttr | 2u;
    } else {
        this->mAttr = this->mAttr & 65533u;
    }
}
