#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cArcLoader.h"
#include "cSystem.h"
#include "nDDOUtility.h"
#include "rArchiveListArray.h"
#include "res_ptr.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cArcLoaderBase;
class cArchiveListNode;
class cArchiveListTag;
class cResource;
class rArchive;
class rArchiveListArray;

// Declarations
class sArchiveManager;

// Type aliases from DWARF
using u32 = unsigned int;
using ARC_SEARCHID = u32;
using ARC_TAGID = u32;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using TICKET = cArcLoaderBase*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using s16 = short;
using s32 = int;
using size_t = _Sizet;
using u64 = __uint64_t;

class sArchiveManager : public cSystem
{
public:
    enum
    {
        ERR_NONE = 0,
        ERR_ALA = 1,
        ERR_CREATE = 2,
    };
    enum
    {
        ARC_LOAD_MODE_ALL = 0,
        ARC_LOAD_MODE_ONCE = 1,
        ARC_LOAD_MODE_NUM = 2,
    };
public:
    class MyDTI;
public:
    using PickArcLoaderFunc = bool(*)(cArcLoaderBase*, cArcLoaderBase*);
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
    TICKET IssueTicket();
    void returnTicket(TICKET ticket);
    bool addTagEx(TICKET ticket, ARC_TAGID tag);
    bool addTagEx(TICKET ticket, MT_CTSTR tagName);
    bool attestationTicket(TICKET ticket);
    bool isTicketLoadFinish(TICKET ticket);
    void setTicketPriority(TICKET ticket, s16 priority);
    bool annulmentTicketArchive(TICKET ticket);
private:
    void initTicket();
    void moveTicket();
    void destroyTicketArchive();
    s32 findEnableTicketStack(s32 beginIdx, bool enable);
public:
    bool addArcLoader(cArcLoaderBase* pBase);
    void eraseArcLoader(cArcLoaderBase* pBase);
private:
    void initArcLoader();
    void moveArcLoader();
    void moveArcLoaderErase();
    bool moveArcLoaderLoadReq(cArcLoaderBase* pLoader);
    rArchive* loadArchiveTag(ARC_TAGID tag, u32 mode);
    void moveArcLoaderLoadFinish(cArcLoaderBase* pLoader);
    void pickArcLoaderInit();
    bool isArcLoaderLoadFinish(cArcLoaderBase* pSrc);
    cArcLoaderBase* pickArcLoader(PickArcLoaderFunc func);
    s32 findEnableArcLoaderStack(s32 beginIdx, bool enable);
    void clearArcLoaderStack(cArcLoaderBase* pDst);
public:
    cResource* createRes(u64 resId, u32 mode, bool warningOff);
    cResource* createRes(ARC_TAGID tag, ARC_SEARCHID searchId, u32 mode, bool warningOff);
    cResource* createRes(const MtDTI& dti, MT_CTSTR path, u32 mode, bool warningOff);
    cResource* createRes(MT_CTSTR tagName, MT_CTSTR searchName, u32 mode, bool warningOff);
    u32 getTagLoadState(ARC_TAGID t);
    MT_CTSTR getArchivePath(ARC_TAGID tag);
    void loadAlaFileAll();
    void clearAlaFiles();
    bool isEnableArcTag(ARC_TAGID tagId);
    bool isEnableArcRes(ARC_TAGID tagId, ARC_SEARCHID searchId);
private:
    rArchiveListArray* getAlaFile(ARC_TAGID tagId);
    cArchiveListTag* getArchiveListTag(ARC_TAGID tagId);
    cArchiveListNode* getArchiveListNode(ARC_TAGID tagId, ARC_SEARCHID searchId);
    void loadAlaFile(u32 targetTagNo);
public:
    u64 convResourceId(const MtDTI& dti, MT_CTSTR path);
    ARC_TAGID getArchiveListNodeOnTag(ARC_TAGID tagId, ARC_SEARCHID searchId);
    void setArcLoadMode(u32 mode);
    sArchiveManager();
    virtual ~sArchiveManager();
    void init();
    virtual void move();  // vtable slot 7
    virtual void reset();  // vtable slot 6
    static sArchiveManager* getInstance();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void initPack();
    void finalPack();
    bool isPackOK();
private:
    nDDOUtility::cArray<cArcLoader<16>, 2048> mTicket3Pool;  // offset: 0x18
    nDDOUtility::cArray<cArcLoader<16>*, 2048> mTicket3Stack;  // offset: 0x78018
    s32 mTicket3UseNum;  // offset: 0x7c018
    s32 mTicket3ReqIndex;  // offset: 0x7c01c
    bool mTicket3Release;  // offset: 0x7c020
    nDDOUtility::cArray<cArcLoaderBase*, 256> mArcLoaderStack;  // offset: 0x7c028
    s32 mArcLoaderNum;  // offset: 0x7c828
    s32 mArcLoaderReqIndex;  // offset: 0x7c82c
    bool mArcLoaderRelease;  // offset: 0x7c830
    cArcLoaderBase* mpArcLoaderActive;  // offset: 0x7c838
public:
    u32 mLastError;  // offset: 0x7c840
private:
    nDDOUtility::cArray<res_ptr<rArchiveListArray>, 128> mpArchiveListArray;  // offset: 0x7c848
    rArchive* mpAla;  // offset: 0x7cc48
public:
    u32 mArcLoaderMode;  // offset: 0x7cc50
private:
    rArchive* mprPack[64];  // offset: 0x7cc58
public:
    static MyDTI DTI;
    static const TICKET INVALID_TICKET;
    static const u32 MAX_TICKET = 2048;
private:
    static const u32 ARC_LOAD_NUM = 256;
public:
    static sArchiveManager* mpInstance;
private:
    static const u32 PACK_NUM = 64;
};

// Inline, no code of its own: checked where it is inlined.
inline sArchiveManager* sArchiveManager::getInstance() {
    return ::sArchiveManager::mpInstance;
}
