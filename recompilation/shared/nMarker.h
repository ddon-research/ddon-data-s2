#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;

// Declarations
namespace nMarker { class cMarkerInfo; }
namespace nMarker { class cWarpMarkerInfo; }
namespace nMarker { class cWarpMarkerInfoStage; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s16 = short;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

namespace nMarker {
    class cMarkerInfo : public ::MtObject
    {
    public:
        class MyDTI;
        class cVector3;
        class cCtrlFlag;
    public:
        using Vector3Array = MtTypedArray<nMarker::cMarkerInfo::cVector3>;
        using CtrlFlagArray = MtTypedArray<nMarker::cMarkerInfo::cCtrlFlag>;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class cVector3 : public ::MtObject
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
            operator MtVector3();
            cVector3();
            cVector3(const MtVector3& pos);
            virtual void createProperty(MtPropertyList& s);  // vtable slot 4
            const MtVector3& getVector3() const;
        protected:
            MtVector3 mRealPos;  // offset: 0x10
        public:
            static MyDTI DTI;
        };
    public:
        class cCtrlFlag : public ::MtObject
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
            u32 getQuestId() const;
            u32 getFalgNo() const;
            cCtrlFlag();
            cCtrlFlag(u32 questId, u32 flagNo);
            virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        protected:
            u32 mQuestId;  // offset: 0x8
            u32 mFlagNo;  // offset: 0xc
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
        const Vector3Array& getPosList() const;
        nMarker::cMarkerInfo& addPosition(const MtVector3& pos);
        const CtrlFlagArray& getCtrlFlagList() const;
        nMarker::cMarkerInfo& addCtrlFlag(u32 questId, u32 flagNo);
        nMarker::cMarkerInfo& setPosition(u32 idx, const MtVector3& pos);
        s16 getStageNo() const;
        nMarker::cMarkerInfo& setStageNo(s16 stageNo);
        bool isAdjoin() const;
        nMarker::cMarkerInfo& setIsAdjoin(bool isAdj);
        cMarkerInfo();
        virtual ~cMarkerInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        Vector3Array mPosList;  // offset: 0x8
        CtrlFlagArray mCtrlFlagList;  // offset: 0x28
        s16 mStageNo;  // offset: 0x48
        bool mIsAdjoin;  // offset: 0x4a
    public:
        static MyDTI DTI;
    };
}  // namespace nMarker

namespace nMarker {
    class cWarpMarkerInfo : public nMarker::cMarkerInfo
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
        const nMarker::cMarkerInfo::Vector3Array& getTargetPosList() const;
        bool hasTargetPos(const MtVector3& pos) const;
        nMarker::cWarpMarkerInfo& addTargetPos(const MtVector3& pos);
        s32 getTargetFloorGroupNo() const;
        nMarker::cWarpMarkerInfo& setTargetFloorGroupNo(s32 floorGroupNo);
        nMarker::cWarpMarkerInfo& clearPosList();
        cWarpMarkerInfo();
        virtual ~cWarpMarkerInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        nMarker::cMarkerInfo::Vector3Array mTargetPos;  // offset: 0x50
        s32 mTargetFloorGroupNo;  // offset: 0x70
    public:
        static MyDTI DTI;
    };
}  // namespace nMarker

namespace nMarker {
    class cWarpMarkerInfoStage : public nMarker::cMarkerInfo
    {
    public:
        class MyDTI;
        class cTargetInfo;
    public:
        using TargetInfoArray = MtTypedArray<nMarker::cWarpMarkerInfoStage::cTargetInfo>;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class cTargetInfo : public ::MtObject
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
            const MtVector3& getTargetPos() const;
            const MtVector3& getTargetPos(u32 index) const;
            u32 getTargetPosNum() const;
            cTargetInfo();
            cTargetInfo(const MtVector3& pos);
            virtual ~cTargetInfo();
            virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        protected:
            nMarker::cMarkerInfo::Vector3Array mTargetPosList;  // offset: 0x8
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
        s16 getTargetStageNo() const;
        nMarker::cWarpMarkerInfoStage& setTargetStageNo(s16 stageNo);
        const TargetInfoArray& getTargetInfoList() const;
        nMarker::cWarpMarkerInfoStage& addTargetInfo(const MtVector3& targetPos);
        nMarker::cWarpMarkerInfoStage& clearPosList();
        cWarpMarkerInfoStage();
        virtual ~cWarpMarkerInfoStage();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    protected:
        TargetInfoArray mTargetInfoList;  // offset: 0x50
        s16 mTargetStageNo;  // offset: 0x70
    public:
        static MyDTI DTI;
    };
}  // namespace nMarker

// Inline, no code of its own: checked where it is inlined.
inline nMarker::cMarkerInfo::cCtrlFlag::cCtrlFlag() {
    this->mQuestId = static_cast<u32>(0);
    this->mFlagNo = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline nMarker::cWarpMarkerInfoStage::cTargetInfo::cTargetInfo() {
}
