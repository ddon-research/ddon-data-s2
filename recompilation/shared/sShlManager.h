#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "nCastUtility.h"
#include "nShlBase.h"
#include "sUnitManager.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class cCustomShlLimit;
class cShlLimit;
class rCustimShlLimit;
class rShlLimit;
class rShlParamList;
class uDDOModel;
class uShlBase;

// Declarations
class sShlManager;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class sShlManager : public sUnitManager
{
public:
    enum
    {
        SHL_CNT_MENBER_NUM = 15,
    };
public:
    class MyDTI;
    class cShlLimitCtrl;
    class cShlLimitCnt;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cShlLimitCtrl : public MtObject
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
        cShlLimitCtrl();
        virtual ~cShlLimitCtrl();
    public:
        uShlBase* mpShl;  // offset: 0x8
        nShlBase::LIMIT_ID mLimitId;  // offset: 0x10
        static MyDTI DTI;
    };
public:
    class cShlLimitCnt : public MtObject
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
        cShlLimitCnt();
        virtual ~cShlLimitCnt();
    public:
        uDDOModel* mpOwner;  // offset: 0x8
        u32 mShlCnt;  // offset: 0x10
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
    sShlManager();
    virtual ~sShlManager();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void move();  // vtable slot 7
    static sShlManager* getInstance();
    estUnitType<uDDOModel, void> createUnit(rShlParamList* pr, s32 group, s32 index, u32 unique_id, uDDOModel* pOwner, uDDOModel* pCpOwner, bool isOnline);
    u32 getShlUniqueId();
    void releaseResource();
private:
    void moveShlLimit();
    bool checkFollowLimitCount(uDDOModel* pOwner);
    bool checkShlLimitCount(cShlLimit* pLimit, uDDOModel* pOwner);
    void clearLimitCount();
    void killLimitShl(cShlLimit* pLimit, uDDOModel* pOwner, MtTypedArray<uShlBase> ar);
    void progCustomLimit(cCustomShlLimit* pLimit, uShlBase* pAddShl, MtTypedArray<uShlBase> ar);
    bool checkCustomShlLimitId(uShlBase* pShl, s32 limit_id);
public:
    rShlParamList* createShlParamList(MT_CTSTR relativePath, u32 groupNo);
    void makeArcPath(MT_CHAR* outPath, MT_CTSTR resPath, u32 groupNo);
    void makeArcPathFromFullPath(MT_CHAR* outPath, MT_CTSTR fullPath, u32 groupNo);
    void makeAltPath(MT_CHAR* outPath, MT_CTSTR resPath, u32 groupNo);
    void makeAltPathFromFullPath(MT_CHAR* outPath, MT_CTSTR fullPath, u32 groupNo);
    void makeSearchNameShlParamList(MT_CHAR* outName);
    void makeSearchNameEpvCom(MT_CHAR* outName);
    void makeSearchNameSeCom(MT_CHAR* outName);
    void makeSearchNameEpvGr(MT_CHAR* outName, u32 no);
    void makeSearchNameSeGr(MT_CHAR* outName, u32 no);
    void makeSearchNameColGr(MT_CHAR* outName);
    void makeSearchNameModelIn(MT_CHAR* outName, u32 index);
    void searchShlFromShlId(nShlBase::SHL_ID id, MtTypedArray<uShlBase>* pAr, uDDOModel* pOwner);
    void createShlLimitResource();
    void deleteShlFromOwner(uDDOModel* pOwner);
private:
    rShlLimit* mprShlLimit;  // offset: 0xa0
    rCustimShlLimit* mprCustomShlLimit;  // offset: 0xa8
    u32 mShlShotCnt[8];  // offset: 0xb0
    MtTypedArray<cShlLimitCtrl> mLimitShlArray;  // offset: 0xd0
    cShlLimitCnt mShlLimitCount[15];  // offset: 0xf0
    static sShlManager* mpInstance;
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline sShlManager* sShlManager::getInstance() {
    return ::sShlManager::mpInstance;
}

// Inline, no code of its own: checked where it is inlined.
inline sShlManager::cShlLimitCtrl::cShlLimitCtrl() {
    this->mpShl = static_cast<uShlBase*>(nullptr);
    this->mLimitId = static_cast<nShlBase::LIMIT_ID>(-1);
}

// Inline, no code of its own: checked where it is inlined.
inline sShlManager::cShlLimitCnt::cShlLimitCnt() {
    this->mpOwner = static_cast<uDDOModel*>(nullptr);
    this->mShlCnt = static_cast<u32>(0);
}
