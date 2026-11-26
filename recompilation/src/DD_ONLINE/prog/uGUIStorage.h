#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "cControl.h"
#include "sItemManager.h"
#include "uGUIBase.h"
#include "uGUIItem01.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
namespace nGUIItem { class cItem; }

// Declarations
class uGUIStorage;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class uGUIStorage : public uGUIItemBase01
{
public:
    enum STO_GUIDE_BIT
    {
        STO_CHECK = 1,
        STO_TRANS = 2,
        STO_CHECK_ALL = 4,
        STO_CHECK_ALL_CLEAR = 8,
        STO_CATCH = 16,
        STO_CHG_INF = 32,
        STO_CHG_TGL = 64,
        STO_BIT_MAX = 7,
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
    uGUIStorage();
    virtual ~uGUIStorage();
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    virtual void move();  // vtable slot 9
    virtual void adjustScale();  // vtable slot 84
    virtual u32 evCtrlCatch(cControl::Message* msg);  // vtable slot 178
    virtual u32 evCtrlDecide(cControl::Message* msg);  // vtable slot 179
    u32 evCtrlToggle(cControl::Message* msg);
    virtual sItemManager::cItemBag::ITEM_CATEGORY getTab2Category();  // vtable slot 164
protected:
    virtual void setGuideBtn();  // vtable slot 170
    virtual void setWindowMouseOver();  // vtable slot 171
    virtual bool isMatrixHeightLimitOver();  // vtable slot 137
    virtual bool isChangeRow();  // vtable slot 188
    virtual void loadItem();  // vtable slot 139
    virtual void loadItemEx();  // vtable slot 189
    virtual void updateInit();  // vtable slot 93
    virtual void updateDetail();  // vtable slot 151
    virtual void setTitle();  // vtable slot 141
    virtual void setupGuideBtn();  // vtable slot 169
    void setupToggleBtn();
    virtual u32 getToggleType();  // vtable slot 190
    virtual u32 getToggleSwitchMsg();  // vtable slot 191
    virtual uGUIItemBase01* createShareUnit();  // vtable slot 192
    void killShareUnit();
    virtual u8 getRowEx();  // vtable slot 193
    virtual void setShareUnitStorageChange(nGUIItem::cItem* pItem);  // vtable slot 194
protected:
    uGUIBase::cReferenceUIToggleBtn mRefToggle;  // offset: 0xf98
    bool mIsBoxErrAna;  // offset: 0x1048
    bool mIsResetTab;  // offset: 0x1049
    bool mIsShareSameUnit;  // offset: 0x104a
    uGUIBase::cReferenceUIBtnGuide::stGuideBtnData mTblGuideSTO[7];  // offset: 0x1050
public:
    static MyDTI DTI;
protected:
    static const u8 STORAGE_ROW_NUM = 8;
};

inline void* uGUIStorage::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
