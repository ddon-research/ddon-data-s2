#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cpComponent.h"
#include "uSoundMotionSe.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector3;
class rSoundAreaInfo;
class rSoundAttributeSe;
class rSoundMotionSe;
class rSoundRequest;
class rSoundStreamRequest;
class uDDOModel;
class uSoundMotionSe;

// Declarations
class cpMotionSe;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class cpMotionSe : public cpComponent
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
    cpMotionSe();
    virtual ~cpMotionSe();
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void updatePtr();  // vtable slot 9
    void setMotionSe(rSoundMotionSe* pMotionSe);
    rSoundMotionSe* getMotionSe();
    void setRequest(rSoundRequest* pReq, u32 type);
    rSoundRequest* getRequest(u32 type);
    void setRequestNum();
    u32 getRequestNum();
    void setStreamRequest(rSoundStreamRequest* pReq);
    rSoundStreamRequest* getStreamRequest();
    void setAttributeSe(rSoundAttributeSe* pAttributeSe);
    rSoundAttributeSe* getAttributeSe();
    void setAttributeRequestAll(const MtVector3& pos);
    void setAttributeRequestAll(rSoundAreaInfo* pInfo, bool isClear);
    void setAttributeRequest(rSoundRequest* pReq, u32 index, bool isClear);
    rSoundRequest* getAttributeRequest(u32 index);
    void setChatStreamRequest(rSoundStreamRequest* pReq);
    rSoundStreamRequest* getChatStreamRequest();
    u32 getAttributeRequestNum();
    void setDummyU32(u32);
    void setMotType(u8 type);
    void setReqIdType(u32 type);
    void setMotionSeVoice(u32 sex, u32 voiceType);
    void setMotionSeVoicePawn(u32 sex, u32 voiceType, u32 personality);
    void setChatVoice(u32 sex, u32 voiceType);
    void calcPartsArea();
    void requestMotionSe(u16 id);
    void setMotionSeCallFlag(u32 Index, bool Flag);
    void setSeqFilter(u32 seq);
    void clearSeqFilter();
protected:
    void updateMotion();
public:
    uSoundMotionSe mMotionSe;  // offset: 0x50
    rSoundStreamRequest* mpChatVoice;  // offset: 0x1c8
    s32 mNowX;  // offset: 0x1d0
    s32 mNowZ;  // offset: 0x1d4
    uDDOModel* mpModel;  // offset: 0x1d8
    static MyDTI DTI;
};
