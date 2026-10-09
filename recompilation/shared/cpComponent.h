#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "MtString.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtPropertyList;
class MtString;
class MtVector3;
class cpKeyCommand;
class uNpc;

// Declarations
class cpComponent;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cpComponent : public MtObject
{
    // inferred: cpKeyCommand::getMoveSpeed names cpComponent::mActive
    friend class cpKeyCommand;
    // inferred: uNpc::setHeadCtrlEnable names cpComponent::mActive
    friend class uNpc;
public:
    class MyDTI;
    class Iterator;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class Iterator
    {
    public:
        Iterator(cpComponent* pBegin);
        void begin(cpComponent* pBegin);
        void next();
        bool isEnd();
        cpComponent* getComponent();
        s32 getDepth();
        s32 getIndex();
    protected:
        cpComponent* mpRoot;  // offset: 0x0
        cpComponent* mpCurrent;  // offset: 0x8
        bool mEnd;  // offset: 0x10
        s32 mDepth;  // offset: 0x14
        s32 mIndex;  // offset: 0x18
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
    cpComponent();
    virtual ~cpComponent();
    virtual void setup();  // vtable slot 6
    // Address: 0x0197b520 - 0x0197b521 (1 bytes)
    virtual void move() {}  // vtable slot 7
    // Address: 0x0197b460 - 0x0197b461 (1 bytes)
    virtual void kill() {}  // vtable slot 8
    virtual void updatePtr();  // vtable slot 9
    // Address: 0x0197b470 - 0x0197b471 (1 bytes)
    virtual void updateEfcHandle() {}  // vtable slot 10
    // Address: 0x0197b480 - 0x0197b481 (1 bytes)
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {}  // vtable slot 11
    // Address: 0x0197b490 - 0x0197b491 (1 bytes)
    virtual void setupComponentPtr() {}  // vtable slot 12
    virtual void setActive(bool active);  // vtable slot 13
    bool isActive();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    cpComponent* getRootComponent() const;
    cpComponent* find(const MtDTI& DTI, bool IsKindOf, bool from_root);
    cpComponent* find(MT_CTSTR name, bool from_root);
    s32 size();
    MT_CTSTR getName();
    void setName(const MtString& name);
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    MtObject* getOwner() const;
    void setParent(cpComponent* pParent);
    cpComponent* getParent() const;
private:
    cpComponent* getChildTop() const;
    cpComponent* getChildBottom() const;
    cpComponent* getNext() const;
    cpComponent* getPrev() const;
    void addChild(cpComponent* pNewComp);
    void removeFromParent();
protected:
    MtObject* mpOwner;  // offset: 0x8
    MtString mName;  // offset: 0x10
    bool mActive;  // offset: 0x18
private:
    cpComponent* mpParent;  // offset: 0x20
    cpComponent* mpChildTop;  // offset: 0x28
    cpComponent* mpChildBottom;  // offset: 0x30
    cpComponent* mpPrev;  // offset: 0x38
    cpComponent* mpNext;  // offset: 0x40
    cpComponent* mpRootComponent;  // offset: 0x48
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline bool cpComponent::isActive() {
    return this->mActive;
}

// Inline, no code of its own: checked where it is inlined.
inline cpComponent* cpComponent::getRootComponent() const {
    return this->mpRootComponent;
}

// Inline, no code of its own: checked where it is inlined.
inline MtObject* cpComponent::getOwner() const {
    return this->mpOwner;
}
