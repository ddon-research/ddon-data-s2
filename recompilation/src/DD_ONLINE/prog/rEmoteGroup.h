#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../XFramework/cResource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtStream;

// Declarations
class rEmoteGroup;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s16 = short;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class rEmoteGroup : public cResource
{
public:
    class MyDTI;
    class InfoBinary;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class InfoBinary : public MtObject
    {
    public:
        class MyDTI;
        class MotDataBinary;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class MotDataBinary : public MtObject
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
            MotDataBinary();
            void copy(rEmoteGroup::InfoBinary::MotDataBinary* src);
        public:
            s16 mEmo;  // offset: 0x8
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
        InfoBinary();
        virtual ~InfoBinary();
        s16 getEmotionNo(u32 idx);
        virtual MotDataBinary* getMotList(u32 index);  // vtable slot 6
        virtual u32 getMotListNum();  // vtable slot 7
    public:
        MotDataBinary* mpMotList;  // offset: 0x8
        u32 mMotListNum;  // offset: 0x10
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
    rEmoteGroup();
    virtual ~rEmoteGroup();
    virtual void clear();  // vtable slot 15
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    u32 getMagicHeader() const;
    u32 getDataVersion() const;
    void destruct();
    virtual u32 getInfoNum() const;  // vtable slot 16
    virtual InfoBinary* getInfo(u32 index) const;  // vtable slot 17
public:
    InfoBinary* mpArray;  // offset: 0x70
    u32 mArrayNum;  // offset: 0x78
    static MyDTI DTI;
    static const u8 DATA_VERSION = 1;
};

inline void* rEmoteGroup::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* rEmoteGroup::InfoBinary::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline rEmoteGroup::InfoBinary::InfoBinary() {
    this->mpMotList = nullptr;
    this->mMotListNum = 0;
}

inline void* rEmoteGroup::InfoBinary::MotDataBinary::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline rEmoteGroup::InfoBinary::MotDataBinary::MotDataBinary() {
    this->mEmo = -1;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void* rEmoteGroup::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::rEmoteGroup::DTI)->memAlloc(sz, align, ::rEmoteGroup::DTI.::MtDTI::getID());
}

inline void rEmoteGroup::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::rEmoteGroup::DTI)->memFree(p_addr);
}

inline rEmoteGroup::rEmoteGroup() {
    this->::cResource::setAttribute(18u);
    this->mpArray = nullptr;
    this->mArrayNum = 0;
}

inline void rEmoteGroup::destruct() {
    unsigned int i0 = 0;
    if (this->mArrayNum != 0) {
        do {
            this->mpArray[i0].~InfoBinary();
            i0 += 1u;
        } while (i0 < this->mArrayNum);
    }
    ::MtMemoryAllocator::getAllocator(::rEmoteGroup::DTI)->memFree(static_cast<void*>(this->mpArray));
    this->mpArray = nullptr;
    this->mArrayNum = 0;
}

inline void* rEmoteGroup::InfoBinary::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::rEmoteGroup::InfoBinary::DTI)->memAlloc(sz, align, ::rEmoteGroup::InfoBinary::DTI.::MtDTI::getID());
}

inline void rEmoteGroup::InfoBinary::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::rEmoteGroup::InfoBinary::DTI)->memFree(p_addr);
}

inline void* rEmoteGroup::InfoBinary::MotDataBinary::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::rEmoteGroup::InfoBinary::MotDataBinary::DTI)->memAlloc(sz, align, ::rEmoteGroup::InfoBinary::MotDataBinary::DTI.::MtDTI::getID());
}

inline void rEmoteGroup::InfoBinary::MotDataBinary::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::rEmoteGroup::InfoBinary::MotDataBinary::DTI)->memFree(p_addr);
}
