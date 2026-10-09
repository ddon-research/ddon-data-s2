#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/MtString.h"
#include "../shared/cControl.h"
#include "../shared/cEquipData.h"
#include "../shared/cItemParam.h"
#include "../shared/nCharacterData.h"
#include "../shared/nDDOUtility.h"
#include "../shared/nGUIExt.h"
#include "../shared/nGUIItem.h"
#include "../shared/rItemList.h"
#include "../shared/uGUIBase.h"
#include "uGUIPopBase.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtDTI;
class MtObject;
class cContextInstHm;
class cControl;
class cEquipData;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class cGUIObjNull;
class cGUIObjTexture;
class cItemParam;
namespace nGUIItem { class cItem; }
class rGUI;
class uGUIBase;
class uGUIGiveAndTake;
class uGUILoginBonus;
class uGUIPopCraftDetail;
class uUIMockUp;

// Declarations
class uGUIPopDetail01;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class uGUIPopDetail01 : public uGUIPopBase
{
    // inferred: uGUIGiveAndTake::setupCtrl names uGUIPopDetail01::mRefPageDot.mDispPageNum
    friend class uGUIGiveAndTake;
    // inferred: uGUILoginBonus::updateExit names uGUIPopDetail01::mIsDraw
    friend class uGUILoginBonus;
public:
    enum REFRESH_MODE
    {
        REFRESH_MODE_NONE = 0,
        REFRESH_MODE_FORCE = 1,
        REFRESH_MODE_DEFAULT = 2,
    };
    enum PR
    {
        PR_DETAIL = 0,
        PR_MOCKUP = 1,
        PR_CRAFT = 2,
        PR_MAX = 3,
    };
    enum MOCKUP_MODEL
    {
        MOCKUP_MODEL_MANNEQUIN = 0,
        MOCKUP_MODEL_PLAYER = 1,
        MOCKUP_MODEL_PAWN_CONTEXT = 2,
    };
    enum ITEM_TYPE
    {
        ITEM_TYPE_KEY_ITEM = 0,
        ITEM_TYPE_MATERIAL = 1,
        ITEM_TYPE_WEAPON = 2,
        ITEM_TYPE_ARMOR = 3,
        ITEM_TYPE_USE_ITEM = 4,
        ITEM_TYPE_JOB_ITEM = 5,
        ITEM_TYPE_FURNITURE = 6,
        ITEM_TYPE_CRAFT_RECIPE = 7,
        ITEM_TYPE_POINT = 8,
        ITEM_TYPE_UNKNOWN = 9,
    };
    enum PAGE_TYPE
    {
        PAGE_TYPE_NONE = 0,
        PAGE_TYPE_CRAFT = 1,
        PAGE_TYPE_ITEM = 2,
        PAGE_TYPE_MOCKUP = 3,
        PAGE_TYPE_MAX = 4,
    };
    enum GMD
    {
        GMD_DEFAULT = 0,
        GMD_PARAMETER = 1,
        GMD_ITEM_WORK = 2,
        GMD_JEWELRY_CATEGORY = 3,
    };
    enum FLAG
    {
        FLAG_UNUSE_MOCKUP = 0,
        FLAG_ONLY_MOCKUP = 1,
        FLAG_NOT_COMPARE = 2,
        FLAG_FIRST_USE_CRAFT = 3,
        FLAG_USE_CRAFT = 4,
        FLAG_DRAW_OFF_CRAFT_MODE = 5,
        FLAG_CHANGE_WINDOW_SIZE = 6,
        FLAG_ADD_BAGGAGE_ITEM_NUM = 7,
        FLAG_MAX = 8,
    };
    enum SW
    {
        SW_DETAIL = 0,
        SW_MOCKUP = 1,
    };
public:
    class MyDTI;
    class cDupParam;
    class cDupCraftParam;
    struct guiInst;
    struct guiObj;
    class cPartsBase;
    class cPartsCraft;
    class cPartsParam;
    class cPartsItemRank;
    class cPartsStatus;
    class cPartsCaption;
    class cPartsFooter;
    class cPartsJob;
public:
    typedef struct
    {
    public:
        u32 itemNo;  // offset: 0x0
        u32 type;  // offset: 0x4
    } SP_ITEM;
public:
    using cFlag = nDDOUtility::cBitSet<8>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cDupParam : public MtObject
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
        cDupParam();
    public:
        uGUIBase::cDupliInstNull mInst;  // offset: 0x8
        cGUIInstAnimation* mpInst_msg_fix_effect;  // offset: 0x30
        cGUIObjMessage* mpMsgName;  // offset: 0x38
        nDDOUtility::cArray<cGUIObjMessage*, 2> mpMsgParams;  // offset: 0x40
        static MyDTI DTI;
    };
public:
    class cDupCraftParam : public MtObject
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
        cDupCraftParam();
    public:
        uGUIBase::cDupliInstNull mInst;  // offset: 0x8
        cGUIInstAnimation* mpINST_msg_fix_crest;  // offset: 0x30
        cGUIObjMessage* mpMsgName;  // offset: 0x38
        static MyDTI DTI;
    };
public:
    struct guiInst
    {
    public:
        cGUIInstNull* Null;  // offset: 0x0
        cGUIInstAnimation* msg_sell;  // offset: 0x8
        cGUIInstAnimation* fix_rarity;  // offset: 0x10
        cGUIInstAnimation* window;  // offset: 0x18
        cGUIInstAnimation* item_icon0;  // offset: 0x20
        cGUIInstAnimation* fix_iconbase;  // offset: 0x28
        cGUIInstAnimation* fix_iconinfo;  // offset: 0x30
        cGUIInstNull* Null_itemicon;  // offset: 0x38
        cGUIInstAnimation* fix_pagedot;  // offset: 0x40
        cGUIInstAnimation* pagebase;  // offset: 0x48
        cGUIInstNull* Null_pagedot;  // offset: 0x50
        cGUIInstNull* Null_footer;  // offset: 0x58
        cGUIInstAnimation* msg_item;  // offset: 0x60
        cGUIInstNull* Null_top;  // offset: 0x68
        cGUIInstAnimation* msg_joblimit;  // offset: 0x70
        cGUIInstAnimation* msg_header;  // offset: 0x78
        cGUIInstAnimation* msg_fix_param;  // offset: 0x80
        cGUIInstAnimation* msg_fix_gauge;  // offset: 0x88
        cGUIInstAnimation* msg_fix_crest;  // offset: 0x90
        cGUIInstNull* Null_craft;  // offset: 0x98
        cGUIInstNull* Null_crest_dup;  // offset: 0xa0
        cGUIInstAnimation* msg_header01;  // offset: 0xa8
        cGUIInstNull* Null_rarity;  // offset: 0xb0
        cGUIInstAnimation* fix_rarity01;  // offset: 0xb8
        cGUIInstAnimation* fix_rarity02;  // offset: 0xc0
        cGUIInstAnimation* fix_rarity03;  // offset: 0xc8
        cGUIInstNull* Null_param;  // offset: 0xd0
        cGUIInstAnimation* msg_fix_effect;  // offset: 0xd8
        cGUIInstAnimation* msg_guide00;  // offset: 0xe0
        cGUIInstNull* Null_all;  // offset: 0xe8
        cGUIInstNull* Null_effect00_dup;  // offset: 0xf0
        cGUIInstNull* Null_caption;  // offset: 0xf8
        cGUIInstAnimation* msg_caption;  // offset: 0x100
        cGUIInstAnimation* msg_header02;  // offset: 0x108
        cGUIInstAnimation* mockup;  // offset: 0x110
        cGUIInstAnimation* msg_guide01;  // offset: 0x118
        cGUIInstAnimation* msg_itemrank;  // offset: 0x120
        cGUIInstAnimation* msg_loadicon;  // offset: 0x128
        cGUIInstNull* Null_itemrank;  // offset: 0x130
        cGUIInstNull* Null_status;  // offset: 0x138
        cGUIInstNull* Null_job;  // offset: 0x140
    };
public:
    struct guiObj
    {
    public:
        cGUIObjMessage* msg_sell_m_money;  // offset: 0x0
        cGUIObjMessage* msg_sell_m_num;  // offset: 0x8
        cGUIObjMessage* msg_sell_m_gold;  // offset: 0x10
        cGUIObjMessage* msg_sell_m_sell;  // offset: 0x18
        cGUIObjMessage* msg_sell_m_bazzar;  // offset: 0x20
        cGUIObjMessage* msg_sell_m_ok;  // offset: 0x28
        cGUIObjMessage* msg_caption_m_caption;  // offset: 0x30
        cGUIObjMessage* msg_item_m_item;  // offset: 0x38
        cGUIObjMessage* msg_item_m_ctgry;  // offset: 0x40
        cGUIObjNull* msg_item_Null_num;  // offset: 0x48
        cGUIObjMessage* msg_item_m_num00;  // offset: 0x50
        cGUIObjMessage* msg_item_m_num01;  // offset: 0x58
        cGUIObjNull* msg_item_Null_num01;  // offset: 0x60
        cGUIObjMessage* msg_item_m_txt;  // offset: 0x68
        cGUIObjTexture* msg_item_icon_equip;  // offset: 0x70
        cGUIObjMessage* msg_item_m_num02;  // offset: 0x78
        cGUIObjTexture* msg_item_icon_equip01;  // offset: 0x80
        cGUIObjTexture* msg_item_icon_equip02;  // offset: 0x88
        cGUIObjMessage* msg_item_m_num03;  // offset: 0x90
        cGUIObjMessage* msg_joblimit_m_lv;  // offset: 0x98
        cGUIObjMessage* msg_joblimit_m_num;  // offset: 0xa0
        cGUIObjMessage* msg_joblimit_m_gender;  // offset: 0xa8
        cGUIObjMessage* msg_header_m_header00;  // offset: 0xb0
        cGUIObjMessage* msg_header_m_header01;  // offset: 0xb8
        cGUIObjMessage* msg_header_m_header02;  // offset: 0xc0
        cGUIObjMessage* msg_fix_effect_m_list;  // offset: 0xc8
        cGUIObjMessage* msg_fix_effect_m_num00;  // offset: 0xd0
        cGUIObjMessage* msg_fix_effect_m_num01;  // offset: 0xd8
        cGUIObjMessage* msg_fix_param_m_header00;  // offset: 0xe0
        cGUIObjMessage* msg_fix_param_m_f_num00;  // offset: 0xe8
        cGUIObjMessage* msg_fix_param_m_f_num01;  // offset: 0xf0
        cGUIObjMessage* msg_fix_param_m_header01;  // offset: 0xf8
        cGUIObjMessage* msg_fix_param_m_f_num02;  // offset: 0x100
        cGUIObjMessage* msg_fix_param_m_f_num03;  // offset: 0x108
        cGUIObjMessage* msg_fix_gauge_m_point;  // offset: 0x110
        cGUIObjMessage* msg_fix_gauge_m_ratio;  // offset: 0x118
        cGUIObjMessage* msg_fix_gauge_m_pt;  // offset: 0x120
        cGUIObjMessage* msg_fix_crest_m_crest;  // offset: 0x128
        cGUIObjMessage* msg_itemrank_m_itemrank;  // offset: 0x130
        cGUIObjMessage* msg_itemrank_m_num02;  // offset: 0x138
        cGUIObjNull* Null_element00;  // offset: 0x140
        cGUIObjNull* Null_compare00;  // offset: 0x148
        cGUIObjNull* Null_compare000;  // offset: 0x150
        cGUIObjNull* Null_element02;  // offset: 0x158
        cGUIObjNull* Null_compare01;  // offset: 0x160
        cGUIObjNull* Null_compare010;  // offset: 0x168
        cGUIObjTexture* f_arrow00;  // offset: 0x170
        cGUIObjTexture* f_arrow01;  // offset: 0x178
        cGUIObjTexture* f_arrow000;  // offset: 0x180
        cGUIObjTexture* f_arrow0000;  // offset: 0x188
        cGUIObjTexture* f_element00;  // offset: 0x190
        cGUIObjTexture* f_element01;  // offset: 0x198
        cGUIObjTexture* f_element02;  // offset: 0x1a0
        cGUIObjTexture* f_element03;  // offset: 0x1a8
        cGUIObjTexture* msg_fix_gauge_f_gauge00;  // offset: 0x1b0
        cGUIObjTexture* mockup00;  // offset: 0x1b8
    };
public:
    class cPartsBase : public MtObject
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
        cPartsBase();
    public:
        uGUIBase::cDupliInstNull mInst;  // offset: 0x8
        static MyDTI DTI;
    };
public:
    class cPartsCraft : public uGUIPopDetail01::cPartsBase
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
        cPartsCraft();
    public:
        static MyDTI DTI;
    };
public:
    class cPartsParam : public uGUIPopDetail01::cPartsBase
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
        cPartsParam();
    public:
        static MyDTI DTI;
    };
public:
    class cPartsItemRank : public uGUIPopDetail01::cPartsBase
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
        cPartsItemRank();
    public:
        static MyDTI DTI;
    };
public:
    class cPartsStatus : public uGUIPopDetail01::cPartsBase
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
        cPartsStatus();
    public:
        static MyDTI DTI;
    };
public:
    class cPartsCaption : public uGUIPopDetail01::cPartsBase
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
        cPartsCaption();
    public:
        static MyDTI DTI;
    };
public:
    class cPartsFooter : public uGUIPopDetail01::cPartsBase
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
        cPartsFooter();
    public:
        static MyDTI DTI;
    };
public:
    class cPartsJob : public uGUIPopDetail01::cPartsBase
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
        cPartsJob();
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
    uGUIPopDetail01(uGUIBase* owner, bool isChatSubMenu);
    virtual ~uGUIPopDetail01();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    virtual void move();  // vtable slot 9
    void setPopDetailPriority();
    void resetPopDetailPriority();
    u32 getPopDetailPriority();
    void setItemParam(nGUIItem::cItem* p, nCharacterData::EQUIP_SLOT_TYPE equipSlotType);
    void setItemParam(cItemParam* pItemParam, rItemList::rItemParam* prItemParam, nCharacterData::EQUIP_SLOT_TYPE equipSlotType);
    void reqRefresh();
    nGUIItem::cItem& getItemParam();
    void setDraw(bool b);
    bool isDrawLocal();
    bool setProc(PR proc, bool force);
    s32 getPageNum();
    s32 getMaxPageNum();
    bool isUseCompare(s32 param1, s32 param2) const;
    void setUseCompare(bool b);
    const MtColor& getStatusColor(s32 val1, s32 val2);
    void setCompereEquipData(cEquipData& source);
    void setOwner(uGUIBase* owner);
    void setContext(cContextInstHm* pContext, bool isSetupEquip);
    void setMockupModel(MOCKUP_MODEL);
    bool isUseMockup();
    void setUseMockup(bool b);
    bool isUseMockupOnly();
    void setUseMockupOnly(bool b);
    void initMockUp();
    void refreshMockUp();
    void setTargetChara(nGUIExt::TARGET target, u32 id, bool isRequestServer);
    void setPageType(PAGE_TYPE type);
    bool isUseCraftMode();
    void setCraftMode(bool b);
    void resetPageType();
    void setCraftDetail(uGUIPopCraftDetail* pCraftDetail);
    bool isAddBaggageItemNum() const;
    void setAddBaggageItemNum(bool);
private:
    virtual void updateInit();  // vtable slot 93
    void updateWait();
    void updateExit();
    void executeWindow();
    void buildParts();
    bool isDouble();
    u8 getGrade();
    u8 getElementNum();
    void setupParam(u32& idx, bool isCompere, MT_CTSTR name, MT_CTSTR param1, MT_CTSTR param2, const MtColor& col);
    bool setupParam2(u32& idx, bool isCompere, MT_CTSTR name, s32 param1, s32 param2, const MtColor& col, bool isUse);
    void setupParamSt(u32& idx, MT_CTSTR name, MT_CTSTR param1, MT_CTSTR param2, const MtColor& col);
    void setupParamStatus(u32& idx, u32 start, u32 end, MT_CTSTR name, MT_CTSTR val, bool isUse);
    void setupParamStatus(u32& idx, u32 start, u32 end, MT_CTSTR name, s32 val, bool isUse);
    void setupParamUseItem(u32& idx, u32 start, u32 end, MT_CTSTR name, rItemList::rParam* pParam, bool isUse);
    void setupParamWepItem(u32& idx, u32 start, u32 end, MT_CTSTR name, s32 param1, s32 param2, const MtColor& col, bool isUse);
    void setupParamWepItem2(u32& idx, u32 start, u32 end, MT_CTSTR name, s32 param1, s32 param2, const MtColor& col, bool isUse);
    u32 setupParamRegist(u32 startIdx, u32 page, bool isUse);
    u32 setupParamWeapon(u32 startIdx, u32 page, bool isUse);
    bool setupParamCraft(u32 startIdx, u32 page);
    void setupEquipMainParam(s32 paramDisp, s32 paramBase, cGUIObjNull* objNullCompare, cGUIObjMessage* objMsgNumDisp, cGUIObjMessage* objMsgNumBase, cGUIObjTexture* objTexArrow);
    void setupEquipElementParam(s32 frameDisp, s32 frameBase, cGUIObjNull* objNullElement, cGUIObjNull* objNullCompare, cGUIObjTexture* objTexDisp, cGUIObjTexture* objTexBase, cGUIObjTexture* objTexArrow);
    void refresh(bool isChangeItem);
    ITEM_TYPE getItemType(nGUIItem::cItem& item);
    MT_CTSTR getMsgParam(u32 id);
    MT_CTSTR getMsgItemWork(u32 id);
    MT_CTSTR getMsgJewelryCategory(u32);
    u32 calcPageNum();
    void updatePageDotNum();
    u32 getDispInfoPage();
    void createParamList();
    const SP_ITEM* getSpItem(u32 itemNo);
    bool isMoneyItem(rItemList::rItemParam* pParam);
    void updateEquipData();
    nCharacterData::EQUIP_SLOT_TYPE getEquipSlotType();
    void createPartsParam();
    void createPartsCraft();
    void createPartsItemRank();
    void createPartsItemGrade();
    void createPartsItemNum(rItemList::rItemParam* pParam);
    void createPartsSpItemNum(const SP_ITEM* pSp);
    void createPartsStatus();
    void createPartsRegist();
    void createPartsCaption();
    void createPartsFooter();
    void createPartsJob();
    void createEquipIcon();
    void createPartsCrest();
    void createPartsPoint();
    MT_CTSTR getEquipCategoryName();
    u32 evCtrlTop(cControl::Message* msg);
public:
    MtTypedArray<cDupParam> mDupParamArray;  // offset: 0x988
    MtTypedArray<cDupCraftParam> mDupCraftParamArray;  // offset: 0x9a8
private:
    rGUI* mpGUIRes;  // offset: 0x9c8
    uGUIBase* mpOwner;  // offset: 0x9d0
    guiInst mDataInst;  // offset: 0x9d8
    guiObj mDataObj;  // offset: 0xb20
    uGUIBase::cAdjustableWindow mWindow;  // offset: 0xce0
    uUIMockUp* mpMockUp;  // offset: 0xd80
    cContextInstHm* mpContext;  // offset: 0xd88
    nGUIExt::TARGET mTarget;  // offset: 0xd90
    u32 mTargetId;  // offset: 0xd94
    uGUIBase::cReferenceUIPageDot mRefPageDot;  // offset: 0xd98
    uGUIBase::cReferenceUIIconItem mRefIconItem;  // offset: 0xe20
    uGUIBase::cReferenceUIBtnGuide mRefBtnGuide;  // offset: 0xfa0
    uGUIBase::cReferenceUIIconJob mRefIconJob[10];  // offset: 0x1038
    MtTypedArray<cPartsBase> mPartsArray;  // offset: 0x13a8
    nGUIItem::cItem mItem;  // offset: 0x13c8
    cItemParam mItemParam;  // offset: 0x1428
    nCharacterData::EQUIP_SLOT_TYPE mEquipSlotType;  // offset: 0x14a0
    cControl* mpCtrl;  // offset: 0x14a8
    bool mIsDraw;  // offset: 0x14b0
    bool mIsVisibleMockup;  // offset: 0x14b1
    REFRESH_MODE mRequestRefresh;  // offset: 0x14b4
    s32 mPartsY;  // offset: 0x14b8
    s32 mSpacing;  // offset: 0x14bc
    s32 mCraftUpgradeGaugeHeight;  // offset: 0x14c0
    s32 mPage;  // offset: 0x14c4
    cFlag mFlag;  // offset: 0x14c8
    PR mProc;  // offset: 0x14cc
    nDDOUtility::cArray<MtStringEx<64>, 2> mTmpStrs;  // offset: 0x14d0
    MOCKUP_MODEL mMockupModel;  // offset: 0x1558
    u32 mRegistMax;  // offset: 0x155c
    u32 mVisibleRegistNum;  // offset: 0x1560
    u32 mRegistRow;  // offset: 0x1564
    cEquipData mEquipData;  // offset: 0x1568
    cEquipData mEquipDataDisp;  // offset: 0x27d0
    cEquipData mEquipDataBase;  // offset: 0x3a38
    uGUIPopCraftDetail* mpCraftDetail;  // offset: 0x4ca0
    ITEM_TYPE mItemType;  // offset: 0x4ca8
    PAGE_TYPE mPageType;  // offset: 0x4cac
    u32 mIssueIdx;  // offset: 0x4cb0
    u32 mNowIssueIdx;  // offset: 0x4cb4
public:
    static MyDTI DTI;
    static const u32 MAX_ROW = 10;
    static const u32 DEFAULT_PRIORITY = 11;
    static const SP_ITEM special_item_tbl[];
};
