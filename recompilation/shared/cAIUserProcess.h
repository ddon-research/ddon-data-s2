#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtString.h"
#include "cAIObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtString;

// Declarations
class cAICopiableParameter;
class cAIUserProcess;
class cAIUserProcessCallback;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cAICopiableParameter : public cAIResource
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
    cAICopiableParameter();
    virtual ~cAICopiableParameter();
    virtual void copy(cAICopiableParameter* pParam);  // vtable slot 6
public:
    static const u32 MD_ST_ACTIVE = 1;
    static const u32 MD_ST_COMMON_MASK = 65535;
    static MyDTI DTI;
};

class cAIUserProcess : public cAIObject
{
public:
    enum EXAMINE_RESULT
    {
        EXR_FAIL = 0,
        EXR_PASS = 1,
        EXR_PASS_CALLER = 2,
    };
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
    cAIUserProcess(MT_CTSTR n, const MtDTI* pOwnerDTI, const MtDTI* pParamDTI);
    virtual ~cAIUserProcess();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void setName(MT_CTSTR n);
    MtString& getName();
    const MtDTI* getOwnerDTI();
    const MtDTI* getParamDTI();
    s32 callProcessWithExamine(MtObject* pOwner, MtObject* pParam, MtObject* pCaller, bool permitsCaller);
    void setOwnerName(MT_CTSTR n);
    MT_CTSTR getOwnerName();
    virtual s32 process(MtObject* pOwner, MtObject* pParam, MtObject* pCaller);  // vtable slot 6
    virtual EXAMINE_RESULT examine(MtObject* pOwner, MtObject* pParam, MtObject* pCaller, bool permitsCaller);  // vtable slot 7
protected:
    MtString mName;  // offset: 0x8
    const MtDTI* mpOwnerDTI;  // offset: 0x10
    const MtDTI* mpParamDTI;  // offset: 0x18
private:
    cAIUserProcess* mpPrev;  // offset: 0x20
    cAIUserProcess* mpNext;  // offset: 0x28
public:
    static MyDTI DTI;
};

class cAIUserProcessCallback : public cAIUserProcess
{
public:
    class MyDTI;
public:
    using CALLBACK_FUNC = u32(MtObject::*)(MtObject*, MtObject*);
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
    cAIUserProcessCallback(MT_CTSTR n, const MtDTI* pOwnerDTI, CALLBACK_FUNC pfunc, const MtDTI* pParamDTI);
    virtual ~cAIUserProcessCallback();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual s32 process(MtObject* pOwner, MtObject* pParam, MtObject* pCaller);  // vtable slot 6
protected:
    CALLBACK_FUNC mpFunc;  // offset: 0x30
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cAICopiableParameter::cAICopiableParameter() {
}
