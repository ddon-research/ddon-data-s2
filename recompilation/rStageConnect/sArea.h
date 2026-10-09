#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/cSystem.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class aStage;
class cArea;
class cFSMBase;
class cLayoutSet;
class cNetGameServer;
class sGame;
class uControlNpc;
class uGUIPopTopSel;
class uHuman;

// Declarations
class sArea;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class sArea : public cSystem
{
    // inferred: aStage::getJointAreaNo names sArea::mpArea[2]
    friend class aStage;
    // inferred: cFSMBase::isMessageEnded names sArea::mpArea[2]
    friend class cFSMBase;
    // inferred: cLayoutSet::isSplitSbc names sArea::mpArea[2]
    friend class cLayoutSet;
    // inferred: cNetGameServer::updateMyRoomBgm names sArea::mpArea[2]
    friend class cNetGameServer;
    // inferred: sGame::getNextStage names sArea::mpArea[2]
    friend class sGame;
    // inferred: uControlNpc::isUseMotionListLight names sArea::mpArea[2]
    friend class uControlNpc;
    // inferred: uGUIPopTopSel::isExitEntryBoard names sArea::mpArea[2]
    friend class uGUIPopTopSel;
    // inferred: uHuman::initBake names sArea::mpArea[2]
    friend class uHuman;
public:
    class MyDTI;
    class AreaInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class AreaInfo : public MtObject
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
        AreaInfo();
        MT_CTSTR getName() const;
        const MtDTI& getAreaDTI() const;
        sArea::AreaInfo* getNext();
        sArea::AreaInfo* getPrev();
        sArea::AreaInfo* getParent();
        sArea::AreaInfo* getChild();
    protected:
        MT_CTSTR mName;  // offset: 0x8
        const MtDTI* mpDTI;  // offset: 0x10
        sArea::AreaInfo* mpParent;  // offset: 0x18
        sArea::AreaInfo* mpChild;  // offset: 0x20
        sArea::AreaInfo* mpNext;  // offset: 0x28
        sArea::AreaInfo* mpPrev;  // offset: 0x30
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
    sArea();
    virtual ~sArea();
    virtual void move();  // vtable slot 7
    virtual void reload();  // vtable slot 10
    virtual void reset();  // vtable slot 6
    virtual void jump(const MtDTI& dti);  // vtable slot 11
    void jumpUp();
    virtual void createMenu(MtPropertyList& s);  // vtable slot 8
    static sArea* getInstance();
    AreaInfo* getAreaInfo(const MtDTI& dti);
    cArea* getArea(u32 pt) const;
    u32 getAreaCount() const;
    u32 getAreaNum() const;
    void setArea(cArea* p, u32 pt);
    void setAreaNum(u32);
protected:
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void createAreaInfo(const MtDTI& dti);
    virtual void setupArea(const MtDTI* pdti);  // vtable slot 12
    void addMenu(MtPropertyList& s, AreaInfo* pinfo);
protected:
    AreaInfo mAreaInfo[512];  // offset: 0x18
    u32 mAreaNum;  // offset: 0x7018
    u32 mAreaPt;  // offset: 0x701c
    const MtDTI* mpJumpArea;  // offset: 0x7020
    cArea* mpArea[8];  // offset: 0x7028
public:
    static MyDTI DTI;
protected:
    static sArea* mpInstance;
    static const s32 MAX_AREAINFO = 512;
    static const s32 MAX_STACK = 8;
};

// Inline, no code of its own: checked where it is inlined.
inline sArea* sArea::getInstance() {
    return ::sArea::mpInstance;
}
