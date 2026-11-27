#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../XFramework/cSystem.h"
#include "cTalkMsgData.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cTalkMsgData;

// Declarations
class sClanKyoten;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class sClanKyoten : public cSystem
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
    sClanKyoten();
    virtual ~sClanKyoten();
    static sClanKyoten* getInstance();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void reset();  // vtable slot 6
    void init();
    void final();
    void clear();
    virtual void move();  // vtable slot 7
    void initLobby();
    bool isInitLobby();
    void finalLobby();
    void initKyoten(bool isClanK);
    bool isInitKyoten();
    void finalKyoten();
    bool isEnableReleaseTalk();
    void clrOpenLot();
    void initPawn();
    void finalPawn();
    void movePawn();
    void initPawnExpeditionTalkMsgData();
    void initPawnExpeditionTalkMsgDataCore(cTalkMsgData* pTalkData, u32 Personality);
    cTalkMsgData* getPawnExpeditionTalkMsgData(u32 Personality);
    void initPawnClanBaseTalkMsgData();
    void initPawnClanBaseTalkMsgDataCore(cTalkMsgData* pTalkData, u32 Personality);
    cTalkMsgData* getPawnClanBaseTalkMsgData(u32 Personality);
    bool isReleasePawnExpedition() const;
    void initPawnKyoten();
    bool isInitPawnKyoten();
    void finalPawnKyoten();
    void createPawnProperty(MtPropertyList& s);
    void initShop();
    void finalShop();
    void moveShop();
    void initShopKyoten();
    bool isInitShopKyoten();
    void finalShopKyoten();
    void createShopProperty(MtPropertyList& s);
public:
    bool mbClanK;  // offset: 0x11
    bool mbOpenLot[6];  // offset: 0x12
protected:
    cTalkMsgData mPawnExpeditionTalkData[9];  // offset: 0x18
    cTalkMsgData mPawnClanBaseTalkData[9];  // offset: 0x2e8
public:
    static MyDTI DTI;
private:
    static sClanKyoten* mpInstance;
};

inline void* sClanKyoten::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline sClanKyoten* sClanKyoten::getInstance() {
    return ::sClanKyoten::mpInstance;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* sClanKyoten::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::sClanKyoten::DTI);
}

inline void sClanKyoten::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::sClanKyoten::DTI)->memFree(p_addr);
}
