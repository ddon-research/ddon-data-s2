#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "../MT/MtObject.h"
#include "cAIService.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class cAIFSM;

// Declarations
class cAISvFSM;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using __uintptr_t = __uint64_t;
using size_t = _Sizet;
using u32 = unsigned int;
using uintptr = __uintptr_t;

class cAISvFSM : public cAIService
{
public:
    class MyDTI;
    class FSMInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class FSMInfo : public MtObject
    {
        friend class cAISvFSM;
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
        FSMInfo(cAIFSM* pFSM, cAISvFSM* po);
        virtual ~FSMInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        void clear();
    protected:
        cAISvFSM* getOwner();
    private:
        uintptr getInfoID();
        void setInfoID(uintptr);
    public:
        cAIFSM* mpFSM;  // offset: 0x8
    private:
        cAISvFSM::FSMInfo* mpPrev;  // offset: 0x10
        cAISvFSM::FSMInfo* mpNext;  // offset: 0x18
        cAISvFSM* mpOwner;  // offset: 0x20
    public:
        static MyDTI DTI;
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
    cAISvFSM();
    virtual ~cAISvFSM();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void reset();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void drawDebug();  // vtable slot 8
    void entryFSM(cAIFSM* pFSM);
    void removeFSM(cAIFSM* pFSM);
    FSMInfo* getFSMInfo(u32 index);
    FSMInfo* searchFSMInfo(cAIFSM* pFSM);
    u32 getFSMInfoNum();
private:
    void destroyFSMList();
    void setFSMInfo(FSMInfo*, u32);
    void setFSMInfoNum(u32);
private:
    FSMInfo* mpFSMTop;  // offset: 0x30
    FSMInfo* mpFSMBottom;  // offset: 0x38
public:
    static const u32 DEBUG_DRAW_SIZE_W = 120;
    static const u32 DEBUG_DRAW_SIZE_H = 30;
    static MyDTI DTI;
};

inline void* cAISvFSM::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cAISvFSM::cAISvFSM() {
    this->mpFSMBottom = nullptr;
    this->mpFSMTop = nullptr;
}

inline void* cAISvFSM::FSMInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void* cAISvFSM::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cAISvFSM::DTI)->memAlloc(sz, align, ::cAISvFSM::DTI.::MtDTI::mID);
}

inline void cAISvFSM::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cAISvFSM::DTI)->memFree(p_addr);
}

inline void cAISvFSM::FSMInfo::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cAISvFSM::FSMInfo::DTI)->memFree(p_addr);
}
