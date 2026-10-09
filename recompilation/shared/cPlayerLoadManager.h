#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "cArcLoader.h"
#include "nWeapon.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class cArcLoaderBase;
class cContextInstHm;
class cContextInstance;
class cWeaponResTable;
class rCharacterEdit;
class sPlayerManager;
class uControl;
class uControlNpc;
class uHuman;
class uPlayer;

// Declarations
class cPlayerLoadManager;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using cArcLoader01 = cArcLoader<1>;
using s32 = int;
using s8 = signed char;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class cPlayerLoadManager : public MtObject
{
    // inferred: sPlayerManager::returnTicket names cPlayerLoadManager::mPlayerLoadStatus
    friend class sPlayerManager;
    // inferred: uControlNpc::setPawnId names cPlayerLoadManager::mPlayerLoadStatus
    friend class uControlNpc;
    // inferred: uPlayer::kill names cPlayerLoadManager::mPlayerLoadStatus
    friend class uPlayer;
public:
    enum
    {
        LOAD_TICKET_WEP_TOP = 0,
        LOAD_TICKET_WEP_END = 15,
        LOAD_TICKET_SND_TOP = 15,
        LOAD_TICKET_SND_MAIN = 15,
        LOAD_TICKET_SND_SUB = 16,
        LOAD_TICKET_SND_END = 17,
        LOAD_TICKET_PAWN_TOP = 17,
        LOAD_TICKET_PAWN_MAIN = 17,
        LOAD_TICKET_PAWN_VO = 18,
        LOAD_TICKET_PAWN_TALK = 19,
        LOAD_TICKET_PAWN_TALK_SE = 20,
        LOAD_TICKET_PAWN_END = 21,
        LOAD_TICKET_JOB_TOP = 21,
        LOAD_TICKET_JOB_00 = 22,
        LOAD_TICKET_JOB_01 = 23,
        LOAD_TICKET_JOB_02 = 24,
        LOAD_TICKET_JOB_03 = 25,
        LOAD_TICKET_JOB_04 = 26,
        LOAD_TICKET_CUSTOM_00 = 27,
        LOAD_TICKET_CUSTOM_01 = 28,
        LOAD_TICKET_CUSTOM_02 = 29,
        LOAD_TICKET_CUSTOM_03 = 30,
        LOAD_TICKET_CUSTOM_04 = 31,
        LOAD_TICKET_CUSTOM_05 = 32,
        LOAD_TICKET_CUSTOM_06 = 33,
        LOAD_TICKET_CUSTOM_07 = 34,
        LOAD_TICKET_JOB_END = 35,
        LOAD_TICKET_PL_TOP = 35,
        LOAD_TICKET_PL_VO = 35,
        LOAD_TICKET_PL_END = 36,
        LOAD_TICKET_EDIT_TOP = 36,
        LOAD_TICKET_HAIR = 36,
        LOAD_TICKET_BEARD = 37,
        LOAD_TICKET_EYEBROW = 38,
        LOAD_TICKET_MAKEUP = 39,
        LOAD_TICKET_SCAR = 40,
        LOAD_TICKET_EYE = 41,
        LOAD_TICKET_NOSE = 42,
        LOAD_TICKET_MOUTH = 43,
        LOAD_TICKET_NPC_ITEM = 44,
        LOAD_TICKET_HMEM_EDIT = 45,
        LOAD_TICKET_EDIT_END = 46,
        LOAD_TICKET_MAX = 46,
        LOAD_TICKET_CUSTOM_TOP = 27,
        LOAD_TICKET_CUSTOM_END = 34,
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
    cPlayerLoadManager();
    virtual ~cPlayerLoadManager();
    static void createWeaponEx(uHuman* pPl, u32 index, nWeapon::WEAPON_CATEGORY wepCategory, cWeaponResTable* pWepResData, u8 partsPatern, s8 colorPatern);
    static void createProtectorEx(uHuman* pPl, u32 slot, cWeaponResTable* pWepResData, u8 partsPatern, s8 colorPatern);
    static void setWeaponMotSe(uHuman* pHuman, u32 index, u32 itemId, u32 sex);
    static void setWeaponEPV(uHuman* pHuman, u32 index, u32 itemId);
    static void setProtectorSeType(uHuman* pHuman, u32 sex, u16 armorItemId, u16 wearItemId);
    bool isPlLoad(cContextInstance* pContext);
    void condisionInit(cContextInstance* pContext);
    void condisionReset(cContextInstance* pContext);
    void loadRequest(cContextInstance* pContext, rCharacterEdit* pEdit, u32 prio);
    void loadRequest(uControl* pCtrl, rCharacterEdit* pEdit, u32 prio);
    static cWeaponResTable* getWeaponArcTagEx(u16 wepId, u32 sex);
    bool isLoadFinish();
    s32 getLoadStatus() const;
    void setLoadStatus(s32 status);
    u32 getReqData();
    void setReqData(u32);
    void loadArcEx(u32 tagEx, u32 index, u32 prio);
    void returnTicketOnly(u32 index);
    void returnTicket();
    void loadComplete(uHuman* pPl, cContextInstHm* pContext);
    void loadComplete(uControl* pPl, cContextInstHm* pContext);
    void killWeapon(uHuman* pPl, cContextInstance* pContext);
    void requestHumanEnemyEquipRes(uHuman* pPl, cContextInstHm* pContext);
    bool requestLoadJobArchive(cContextInstance* pContext, bool isChange, u32 prio);
    bool isJobLoadComplete(cContextInstHm* pContext);
    void finishJobChange();
    bool isJobChange() const;
    cArcLoaderBase* getArcTcket(u32);
    void requestChangeCSArchive(cContextInstance* pContext);
public:
    bool mFlagCsLoadRequest;  // offset: 0x8
private:
    s32 mPlayerLoadStatus;  // offset: 0xc
    u32 mReqData;  // offset: 0x10
    bool mIsJobChange;  // offset: 0x14
    cArcLoader01 mArcTicket[46];  // offset: 0x18
public:
    static MyDTI DTI;
};
