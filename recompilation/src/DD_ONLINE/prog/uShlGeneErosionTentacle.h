#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "uShlBase.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtDTI;
class MtObject;
class MtPropertyList;

// Declarations
class cShlParamGeneErosionTentacle;
class uShlGeneErosionTentacle;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamGeneErosionTentacle : public cShlParamBase
{
public:
    class MyDTI;
    class cShootCtrlParamGeneErosionTentacle;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cShootCtrlParamGeneErosionTentacle : public MtObject
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
        cShootCtrlParamGeneErosionTentacle();
        virtual ~cShootCtrlParamGeneErosionTentacle() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    public:
        s32 shlNo;  // offset: 0x8
        s32 shlPawnNoticeNo;  // offset: 0xc
        s32 coretype;  // offset: 0x10
        s32 constJointNo;  // offset: 0x14
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
    virtual MtDTI& getShlDTI() const;  // vtable slot 6
    cShlParamGeneErosionTentacle();
    virtual ~cShlParamGeneErosionTentacle();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
    virtual void addShlList(const cShlParamGeneErosionTentacle* pParam);  // vtable slot 12
public:
    MtArray shlList;  // offset: 0x160
    f32 mWaitTime;  // offset: 0x180
    f32 mStartWaitTime;  // offset: 0x184
    bool mFlgReqTentacleNoticeSe;  // offset: 0x188
    static MyDTI DTI;
};

class uShlGeneErosionTentacle : public uShlBase
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
    const cShlParamGeneErosionTentacle* getShlParam() const;
    uShlGeneErosionTentacle();
    virtual ~uShlGeneErosionTentacle();
    virtual void setup();  // vtable slot 6
    virtual void initSub();  // vtable slot 177
    virtual void updateSub();  // vtable slot 175
protected:
    void setShlOrg(u32 shlNo, s32 jointNo);
private:
    f32 mShlSetFrame;  // offset: 0x2ab0
    u32 mShlSetNum;  // offset: 0x2ab4
    bool mFlgTentacleInit[4];  // offset: 0x2ab8
public:
    static MyDTI DTI;
};

inline void* cShlParamGeneErosionTentacle::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamGeneErosionTentacle::cShlParamGeneErosionTentacle() {
    this->shlList.mAutoDelete = true;
    this->mWaitTime = 5.0f;
    this->mStartWaitTime = 15.0f;
    this->mFlgReqTentacleNoticeSe = true;
}

inline void* cShlParamGeneErosionTentacle::cShootCtrlParamGeneErosionTentacle::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamGeneErosionTentacle::cShootCtrlParamGeneErosionTentacle::cShootCtrlParamGeneErosionTentacle() {
    this->coretype = -1;
    this->constJointNo = -1;
    this->shlNo = -1;
    this->shlPawnNoticeNo = -1;
}

inline void* uShlGeneErosionTentacle::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uShlGeneErosionTentacle::uShlGeneErosionTentacle() {
    this->mShlSetFrame = 0.0f;
    this->mShlSetNum = 0;
}
