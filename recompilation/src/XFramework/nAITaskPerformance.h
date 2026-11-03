#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "../MT/MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtProperty;
class MtPropertyList;
class MtString;
class MtUI;
class sAI;

// Declarations
namespace nAI { class TaskPerformanceInfo; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

namespace nAI {
    class TaskPerformanceInfo : public ::MtObject
    {
        friend class ::sAI;
    public:
        class MyDTI;
        class LOD;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class LOD : public ::MtObject
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
            LOD(bool pm, f32 pi, u32 olmt);
            virtual ~LOD() {}
            virtual void createProperty(MtPropertyList& s);  // vtable slot 4
            virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
            void setEnablePerformanceManage(bool);
            bool enablePerformanceManage();
            void setPerformanceIndicator(f32);
            f32 getPerformanceIndicator();
            void setOverloadManageType(u32);
            u32 getOverloadManageType();
        private:
            bool mEnablePerformanceManage;  // offset: 0x8
            f32 mPerformanceIndicator;  // offset: 0xc
            u32 mOverloadManageType;  // offset: 0x10
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
        TaskPerformanceInfo();
        virtual ~TaskPerformanceInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        void setDTI(const MtDTI*);
        const MtDTI* getDTI();
        MT_CTSTR getName();
        void setPerformanceIndicator(f32);
        f32 getPerformanceIndicator();
        void setAllowTime(f32);
        f32 getAllowTime();
        void setOverloadManageType(u32);
        u32 getOverloadManageType();
        bool createLODList(u32 num);
        LOD* getLOD(u32 level);
        u32 getLODNum();
        void setLODInfo(const LOD& lod, u32 level);
        void expandLODList();
        void deleteLOD(u32 level);
    private:
        void setName(MtString& s);
        void destroyLODList();
        void setLOD(LOD* pl, u32 level);
        void setLODNum(u32 n);
    private:
        const MtDTI* mpDTI;  // offset: 0x8
        u32 mOverloadManageType;  // offset: 0x10
        f32 mPerformanceIndicator;  // offset: 0x14
        f32 mAllowTime;  // offset: 0x18
        u32 mLODNum;  // offset: 0x1c
        LOD* mLODList;  // offset: 0x20
    public:
        static MyDTI DTI;
    };
}  // namespace nAI

inline void* nAI::TaskPerformanceInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline u32 nAI::TaskPerformanceInfo::getLODNum() {
    return this->mLODNum;
}

inline void* nAI::TaskPerformanceInfo::LOD::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
