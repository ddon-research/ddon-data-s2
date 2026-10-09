#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtDtiSelecter.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtString;
class MtUI;

// Declarations
namespace MtCollisionUtil { class MtArrayBasicBase; }
namespace MtCollisionUtil { class MtArrayEx; }
namespace MtCollisionUtil { class MtDtiObject; }
namespace MtCollisionUtil { class MtDtiSelecter; }
namespace MtCollisionUtil { class MtDtiSelecterIntermediate; }
namespace MtCollisionUtil { template <typename type, bool _flag_class_mode, unsigned int _extend_buffer_over_mul> class MtArrayTemplate; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

namespace MtCollisionUtil {
    class MtArrayBasicBase
    {
    public:
        MtArrayBasicBase();
        virtual ~MtArrayBasicBase() {}
        virtual void clear();  // vtable slot 2
        u32 length() const;
        u32 capacity() const;
        static void* operator new(size_t);
        static void* operator new[](size_t);
        static void* operator new(size_t, void*);
        static void* operator new[](size_t, void*);
        static void operator delete(void* padr);
        static void operator delete[](void*);
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
        static MtAllocator* getAllocator();
    protected:
        u32 mLength;  // offset: 0x8
        u32 mBufsiz;  // offset: 0xc
        void* mpParam;  // offset: 0x10
    };
}  // namespace MtCollisionUtil

namespace MtCollisionUtil {
    class MtDtiObject : public ::MtObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        MtDtiObject(const MtDTI* pDTI);
        virtual ~MtDtiObject();
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void createPropertyEx(MtPropertyList& s, u32 AddAttribute);
        const MtDTI* getRegistDTI() const;
        void registDTI(const MtDTI* pRegistDTI);
        MT_CTSTR getRegistDTIName() const;
        void registDTIName(MtString& NewDTIName);
        u32 getRegistDTI_ID() const;
        void registDTI_ID(u32 NewDTI_ID);
        void copy(MtCollisionUtil::MtDtiObject& src);
    protected:
        const MtDTI* mpRegistDTI;  // offset: 0x8
    public:
        static MyDTI DTI;
    };
}  // namespace MtCollisionUtil

namespace MtCollisionUtil {
    class MtDtiSelecterIntermediate : public ::MtDtiSelecter
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        MtDtiSelecterIntermediate();
        virtual ~MtDtiSelecterIntermediate();
    public:
        static MyDTI DTI;
    };
}  // namespace MtCollisionUtil

namespace MtCollisionUtil {
    // Layout verified against DWARF for MtArrayTemplate<cDynamicBVHCollision::Node*, false, 2>, MtArrayTemplate<sCollision::cSbcMoveReserveInfo, true, 1>, MtArrayTemplate<sCollision::cSbcMoveReserveInfoAll, true, 1>, MtArrayTemplate<sCollision::cSbcMoveResetReserveInfo, false, 1>, MtArrayTemplate<sCollision::cSbcMoveResetReserveInfoAll, false, 1>, MtArrayTemplate<sCollision::cSbcRegistReserveInfo, true, 1>, MtArrayTemplate<unsigned int, false, 1>
    template <typename type, bool _flag_class_mode, unsigned int _extend_buffer_over_mul>
    class MtArrayTemplate : public MtCollisionUtil::MtArrayBasicBase
    {
    public:
        MtArrayTemplate();
        virtual ~MtArrayTemplate();
        type& add(type& obj);
        void deleteAll();
        void setLength(u32 set);
        void extendBuffer(u32 siz);
        type& at(u32 index);
        static void* operator new[](size_t sz);
        static void operator delete(void* padr);
        static void operator delete[](void* padr);
        void* memAlloc(size_t s);
        void memFree(void* padr);
        virtual void clear();  // vtable slot 2
        void reserve(u32 siz);
        type& getElem(u32 index);
    };
}  // namespace MtCollisionUtil

namespace MtCollisionUtil {
    class MtArrayEx : public ::MtArray
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        MtArrayEx();
        virtual ~MtArrayEx();
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void clear();
        void resize(u32 siz);
        void setAutoCreate(const MtDTI* pDti, bool f);
        virtual void setClass(MtObject* pObj, u32 index);  // vtable slot 6
        virtual MtObject* getClass(u32 index);  // vtable slot 7
    protected:
        void setClassForUI(MtObject* pObj, u32 index);
        MtObject* getClassforUI(u32 index);
        MT_CTSTR getElementDtiName();
        void setDummyString(MtString);
    protected:
        MtCollisionUtil::MtDtiObject mAutoCreateDTI;  // offset: 0x20
        bool mAutoCreate;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace MtCollisionUtil

namespace MtCollisionUtil {
    class MtDtiSelecter : public MtCollisionUtil::MtDtiSelecterIntermediate
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        MtDtiSelecter();
        virtual ~MtDtiSelecter();
    public:
        static MyDTI DTI;
    };
}  // namespace MtCollisionUtil
