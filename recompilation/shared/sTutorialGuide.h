#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "cSystem.h"
#include "rTutorialList.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cArcLoaderBase;
class rGUIMessage;
class rTutorialDialogMessage;
class rTutorialList;
class uGUISystemMsg;
class uGUITutorialPop;

// Declarations
class sTutorialGuide;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using TICKET = cArcLoaderBase*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class sTutorialGuide : public cSystem
{
    // inferred: uGUITutorialPop::kill names sTutorialGuide::mpTutorialDetail
    friend class uGUITutorialPop;
public:
    class MyDTI;
    class cOpenGuideNo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cOpenGuideNo : public MtObject
    {
    public:
        enum
        {
            RNO_ARC_LOAD_WAIT = 0,
            RNO_WAIT = 1,
            RNO_NUM = 2,
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
        operator unsigned int() const;
        bool operator==(u32) const;
        bool operator!=(u32 n) const;
        cOpenGuideNo(u32 guideNo, u32 sortNo);
        virtual ~cOpenGuideNo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void requestArchive();
        void releaseArchive();
        bool isArcLoadFinish();
        bool isDataLoadFinish();
        void move();
        MT_CTSTR getMessage(u32 PageIdx);
        u32 getImageId(u32 PageIdx);
    public:
        u32 mGuideNo;  // offset: 0x8
        u32 mSortNo;  // offset: 0xc
        rTutorialDialogMessage* mpDialogMsg;  // offset: 0x10
        rGUIMessage* mpMessage;  // offset: 0x18
        TICKET mArcTicket;  // offset: 0x20
        u32 mRno;  // offset: 0x28
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
    const MtTypedArray<cOpenGuideNo>& getOpenGuideList() const;
    void openGuide(u32 guideNo);
protected:
    bool isOpenGuide(u32 guideNo) const;
    static bool guideSort(const cOpenGuideNo* a, const cOpenGuideNo* b, u32 param);
public:
    void createResouce();
    virtual void move();  // vtable slot 7
    void loadGuideArc(u32 GuideNo);
    bool isFinishLoadGuideArc(u32 GuideNo);
    bool isFinishLoadGuideData(u32 GuideNo);
    void createGuideData(u32 GuideNo);
    void releaseGuideData();
    rTutorialList::cTutorialNode* getTutorialNode(u32 GuideNo) const;
    cOpenGuideNo* getOpenGuideData(u32 GuideNo);
    MT_CTSTR getGuideName(u32 GuideNo);
    u32 getSortNo(u32 GuideNo);
    u32 getCategory(u32 GuideNo);
    void registerGuideFromSavedata();
    u32 getLatestTutorialGuideNum();
    u32 getLatestTutorialGuide(u32 index);
    void registerLatestGuide(u32 guideNo);
    u32 getGuidePageNum();
    MT_CTSTR getGuideMsg(u32 uPage);
    u32 getDispGuideNo();
    void setDispGuideNo(u32);
    void addOpenGuideNo(u32 openGuideNo);
    void finalGame();
    static sTutorialGuide* getInstance();
    sTutorialGuide();
    virtual ~sTutorialGuide();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
protected:
    MtTypedArray<cOpenGuideNo> mOpenGuideList;  // offset: 0x18
    u32 mDispGuideNo;  // offset: 0x38
    uGUISystemMsg* mpGUISystemMsg;  // offset: 0x40
    rTutorialList* mpTutorialList;  // offset: 0x48
    rGUIMessage* mpTutorialName;  // offset: 0x50
    rGUIMessage* mpTutorialDetail;  // offset: 0x58
    TICKET mArcTicketTGuide;  // offset: 0x60
public:
    static MyDTI DTI;
protected:
    static sTutorialGuide* mpInstance;
};

// Inline, no code of its own: checked where it is inlined.
inline sTutorialGuide* sTutorialGuide::getInstance() {
    return ::sTutorialGuide::mpInstance;
}
