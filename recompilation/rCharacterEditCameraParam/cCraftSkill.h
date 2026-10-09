#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtProperty;
class MtPropertyList;
class MtUI;
class rCraftSkillCost;
class rCraftSkillSpd;

// Declarations
class cCraftSkill;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cCraftSkill : public MtObject
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
    cCraftSkill();
    virtual ~cCraftSkill();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    void setSpdResource(rCraftSkillSpd* pResource);
    rCraftSkillSpd* getSpdResource();
    void releaseSpdResource();
    void setCostResource(rCraftSkillCost* pResource);
    rCraftSkillCost* getCostResource();
    void releaseCostResource();
    u32 getSpdRate(u32 type, u32 Lv);
    f32 getCostRate(u32 Total, u32 Num);
private:
    void init();
private:
    rCraftSkillSpd* mpSpdResource;  // offset: 0x8
    rCraftSkillCost* mpCostResource;  // offset: 0x10
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline void cCraftSkill::init() {
    this->mpCostResource = static_cast<rCraftSkillCost*>(nullptr);
    this->mpSpdResource = static_cast<rCraftSkillSpd*>(nullptr);
}
