#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "nCollision.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;

// Declarations
class cColliderGeometryParam;
class cColliderNodeParam;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class cColliderGeometryParam : public nCollision::cAllocaterIntermediate
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
    cColliderGeometryParam();
    virtual ~cColliderGeometryParam();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    u16 getVersion() const;
    u32 getAttribute() const;
    void setAttribute(u32 param);
protected:
    void setDummyU16(u16);
protected:
    u32 mAttribute;  // offset: 0x8
public:
    static MyDTI DTI;
    static const u16 VERSION = 1;
};

class cColliderNodeParam : public nCollision::cAllocaterIntermediate
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
    cColliderNodeParam();
    virtual ~cColliderNodeParam();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    u16 getVersion() const;
    u32 getColliderGroup() const;
    void setColliderGroup(u32 param);
    u32 getColliderType() const;
    void setColliderType(u32 param);
    bool getFlgUseActive() const;
    void setFlgUseActive(bool param);
    bool getFlgUsePassive() const;
    void setFlgUsePassive(bool param);
    bool getFlgUsePush() const;
    void setFlgUsePush(bool param);
    u32 getAttribute() const;
    void setAttribute(u32 param);
    u32 getActiveUseFunctionID() const;
    void setActiveUseFunctionID(u32 param);
    MtObject* getUserDataPtr() const;
    void setUserDataPtr(MtObject* pUserObject);
    size_t getUserDataPtrAddrBySizeT() const;
    void setAutoDeleteUserDataPtr(bool FlgAutoDelete);
    bool isAutoDeleteUserDataPtr() const;
protected:
    void setDummyU16(u16);
    void setDummyU32(u32);
protected:
    u32 mColliderType;  // offset: 0x8
    bool mFlgUseActive;  // offset: 0xc
    bool mFlgUsePassive;  // offset: 0xd
    bool mFlgUsePush;  // offset: 0xe
    u32 mGroup;  // offset: 0x10
    u32 mAttribute;  // offset: 0x14
    u32 mActiveUseFunctionID;  // offset: 0x18
    MtObject* mpUserDataPtr;  // offset: 0x20
    bool mFlgAutoDeleteUserDataPtr;  // offset: 0x28
public:
    static MyDTI DTI;
    static const u16 VERSION = 1;
};

inline void* cColliderGeometryParam::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline u16 cColliderGeometryParam::getVersion() const {
    return 1;
}

inline void* cColliderNodeParam::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cColliderNodeParam::cColliderNodeParam() {
    this->mColliderType = 0xFFFFFFFF;
    this->mFlgUseActive = false;
    this->mFlgUsePassive = true;
    this->mFlgUsePush = false;
    this->mGroup = 0xFFFFFFFF;
    this->mAttribute = 0xFFFFFFFF;
    this->mActiveUseFunctionID = 1;
    this->mpUserDataPtr = nullptr;
    this->mFlgAutoDeleteUserDataPtr = false;
}

inline u16 cColliderNodeParam::getVersion() const {
    return 1;
}
