#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"

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
    friend class cpKeyCommand;
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
    virtual void move() {}  // vtable slot 7
    virtual void kill() {}  // vtable slot 8
    virtual void updatePtr();  // vtable slot 9
    virtual void updateEfcHandle() {}  // vtable slot 10
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {}  // vtable slot 11
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

inline bool cpComponent::isActive() {
    return this->mActive;
}

inline cpComponent* cpComponent::getRootComponent() const {
    return this->mpRootComponent;
}

inline MtObject* cpComponent::getOwner() const {
    return this->mpOwner;
}

inline void cpComponent::addChild(cpComponent* pNewComp) {
    pNewComp->mpParent = this;
    pNewComp->mpRootComponent = this->mpRootComponent;
    if (this->mpChildTop != nullptr) {
        if (this->mpChildBottom != nullptr) {
            this->mpChildBottom->mpNext = pNewComp;
            pNewComp->mpPrev = this->mpChildBottom;
            this->mpChildBottom = pNewComp;
        }
    } else {
        if (this->mpChildBottom != nullptr) {
            this->mpChildBottom->mpNext = pNewComp;
            pNewComp->mpPrev = this->mpChildBottom;
        } else {
            this->mpChildTop = pNewComp;
        }
        this->mpChildBottom = pNewComp;
    }
}
