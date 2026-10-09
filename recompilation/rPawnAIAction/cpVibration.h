#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/cpComponent.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector3;
class rVibration;
class uBaseModel;
class uCoord;
class uModel;

// Declarations
class cpVibration;

// Type aliases from DWARF
using u32 = unsigned int;
using ARC_TAGID = u32;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u8 = unsigned char;

class cpVibration : public cpComponent
{
public:
    enum
    {
        SEQ_VIB_REQ_TYPE_DEFAULT = 0,
        SEQ_VIB_REQ_TYPE_DISTANCE = 1,
    };
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
    cpVibration();
    virtual ~cpVibration();
    virtual void updatePtr();  // vtable slot 9
    void setVibration(rVibration* pVibration, u32 ResType);
    void setVibrationByPath(MT_CTSTR Path, u32 ResType);
    void setVibrationByArc(ARC_TAGID ArchiveTagId, s32 SearchId, u32 ResType);
    void releaseVibration(u32 ResType);
    void releaseVibrationAll();
    rVibration* getVibration(u32 Type);
    u32 getVibrationNum();
    void setVibrationNum(u32);
    uBaseModel* getOwnerModel() const;
    void setOwnerModel(uBaseModel* pModel);
    void setViewModel(uCoord* pViewModel);
    uCoord* getViewModel() const;
    void reqVibration(u32 ResType, u32 ListNo, u32 Priority);
    void reqVibrationDistance(u32 ResType, u32 ListNo, u32 Priority);
    void reqVibrationPos(u32 ResType, u32 ListNo, const MtVector3& pos, u32 Priority);
    void setSeqCtrlModel(uModel* pModel);
    void setSeqCtrl(bool isSet);
    bool isSeqCtrl() const;
    void setSeqCtrlPageNo(u8);
    u8 getSeqCtrlPageNo() const;
    void setSeqCtrlSeqNoFlag(u32);
    u32 getSeqCtrlSeqNoFlag() const;
    void setSeqVibPriority(u32);
    u32 getSeqVibPriority() const;
    void setSeqVibReqType(u8 Type);
    u8 getSeqVibReqType() const;
    void updateSequence();
protected:
    rVibration* mprVibration[4];  // offset: 0x50
    uBaseModel* mpOwnerModel;  // offset: 0x70
    uCoord* mpViewModel;  // offset: 0x78
    uModel* mpSeqCtrlModel;  // offset: 0x80
    bool mIsSeqCtrl;  // offset: 0x88
    u8 mSeqPage;  // offset: 0x89
    u8 mSeqVibReqType;  // offset: 0x8a
    u8 _padding[2];  // offset: 0x8b
    u32 mSeqNoFlag;  // offset: 0x90
    u32 mPriority;  // offset: 0x94
public:
    static MyDTI DTI;
    static const u32 RESOURCE_TYPE_NUM = 4;
    static const u32 SEQ_CTRL_PAGE_NO = 2;
    static const u32 SEQ_CTRL_SEQ_NO_FLAG = 58720256;
};
