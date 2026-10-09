#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cPrimObj.h"
#include "nPrim.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class cPrimBuffer;
namespace nPrim { struct DepthOrder; }
namespace nPrim { struct Material; }

// Declarations
class cPrimTagList;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cPrimTagList : public cPrimObj
{
public:
    class MyDTI;
    struct ObjState;
    struct PrimTag;
    struct IndexTag;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct ObjState
    {
    public:
        cPrimTagList::PrimTag* tag_ptr;  // offset: 0x0
        cPrimTagList::IndexTag* index_ptr;  // offset: 0x8
        u32 tag_num;  // offset: 0x10
        bool sorted;  // offset: 0x14
    };
public:
    struct PrimTag
    {
    public:
        PrimTag();
        PrimTag(const nPrim::Material& mat, const nPrim::DepthOrder& dp, cPrimBuffer* pp, void* pm, void* va, void* ia, u32 v_cnt, u32 i_cnt);
        cPrimTagList::PrimTag& operator=(const cPrimTagList::PrimTag& tag);
    public:
        nPrim::Material material;  // offset: 0x0
        nPrim::DepthOrder depth;  // offset: 0x8
        cPrimBuffer* p_primbuffer;  // offset: 0x10
        void* p_metadata;  // offset: 0x18
        void* v_addr;  // offset: 0x20
        void* i_addr;  // offset: 0x28
        u32 vtx_cnt;  // offset: 0x30
        u32 idx_cnt;  // offset: 0x34
    };
public:
    struct IndexTag
    {
    public:
        IndexTag();
        cPrimTagList::IndexTag& operator=(const cPrimTagList::IndexTag& tag);
    public:
        cPrimTagList::PrimTag* prim_addr;  // offset: 0x0
        nPrim::DepthOrder depth;  // offset: 0x8
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
    cPrimTagList();
    virtual ~cPrimTagList();
    s32 addTag(const PrimTag& tag);
    s32 addTag(const PrimTag* tags, u32 n_tag);
    u32 getNumOfTags() const;
    bool isSorted() const;
    PrimTag* getTags(u32) const;
    IndexTag* getSortedTags(u32) const;
    IndexTag* getIndexTags(u32 tag_no) const;
    IndexTag* getSortedTags() const;
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& prop_list);  // vtable slot 4
    void sortTags(u32);
    void setWorkBuffer(void*);
    u32 getRequiredWorkBuffer() const;
    s32 push();
    s32 pop();
    void assignTags(u32 n_tags, PrimTag* p_tag, IndexTag* p_itag);
private:
    void sort(s32 first, s32 last);
    ObjState* getCurrentState();
    void clearTag();
private:
    ObjState mStack[6];  // offset: 0x8
    u32 mCurrentStack;  // offset: 0x98
    PrimTag* mpTags;  // offset: 0xa0
    IndexTag* mpSorted;  // offset: 0xa8
    void* mpWork;  // offset: 0xb0
    PrimTag* mpCurrentTagPtr;  // offset: 0xb8
    IndexTag* mpCurrentIdxPtr;  // offset: 0xc0
    u32 mTagSize;  // offset: 0xc8
    u32 mCurrentTagSize;  // offset: 0xcc
public:
    static MyDTI DTI;
};
