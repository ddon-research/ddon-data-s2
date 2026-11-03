#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtString.h"
#include "uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;
class MtVector2;
class cArcLoaderBase;
class cGUIInstAnimation;
class cGUIObjTextureRef;
class cGUIObject;
class rGUI;
class rGUIMessage;
class rLoadingParam;
class rTexture;

// Declarations
class uGUILoading;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using TICKET = cArcLoaderBase*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUILoading : public uGUIBase
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
    uGUILoading();
    virtual ~uGUILoading();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    void setAreaNo(u32 uAreaNo);
    void setStageNo(u32 uStageNo);
private:
    void updateInit();
    void updateWait();
    void updateExit();
    void updateDisp();
protected:
    virtual void adjustScale();  // vtable slot 84
    void changeUVSize();
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    rLoadingParam* mpLoadingParam;  // offset: 0x8d0
    cGUIInstAnimation* mpInstMsg;  // offset: 0x8d8
    cGUIObject* mpObjMsgText;  // offset: 0x8e0
    cGUIObjTextureRef* mpObjTexRefBack;  // offset: 0x8e8
    bool mEnable;  // offset: 0x8f0
    bool mIsUseLoadingInfoSdl;  // offset: 0x8f1
    u32 mAreaNo;  // offset: 0x8f4
    u32 mStageNo;  // offset: 0x8f8
    s32 mLoadingId;  // offset: 0x8fc
    u32 mMsgIdx;  // offset: 0x900
    u32 mImgId;  // offset: 0x904
    TICKET mArcTicket;  // offset: 0x908
    rTexture* mpTexImg;  // offset: 0x910
    rGUIMessage* mpLoadingMsg;  // offset: 0x918
    MtString mMsg;  // offset: 0x920
    MtVector2 mPos2InstMsgInit;  // offset: 0x928
public:
    static MyDTI DTI;
};

inline void* uGUILoading::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
