#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/Craft.h"
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/MtString.h"
#include "../shared/nCharacterData.h"
#include "rCraftRecipe.h"
#include "../shared/rItemList.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtProperty;
class MtPropertyList;
class MtString;
class MtUI;
class cCraftCapPassData;
class rCraftCapPass;

// Declarations
class cCraftRecipe;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cCraftRecipe : public MtObject
{
public:
    enum RECIPE_TYPE
    {
        RECIPE_TYPE_CREATE = 0,
        RECIPE_TYPE_UPGRADE = 1,
    };
    enum SORT_DIR
    {
        DEC_DIR = 0,
        INC_DIR = 1,
    };
public:
    class MyDTI;
    class cCraftRecipeList;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cCraftRecipeList : public MtObject
    {
    public:
        enum
        {
            RECIPE_TYPE_NORMAL = 0,
            RECIPE_TYPE_TEST = 1,
            RECIPE_TYPE_OTHER = 2,
        };
    public:
        class MyDTI;
    public:
        typedef union
        {
        public:
            u32 mSubSort;  // offset: 0x0
            u32 mQuality;  // offset: 0x0
            u32 mGold;  // offset: 0x0
        } SUB_SORT_KEY;
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
        cCraftRecipeList();
        virtual ~cCraftRecipeList();
        void setRecipeId(u32 recipeId);
        u32 getRecipeId() const;
        void setCategoryNo(u32 categoryNo);
        u32 getCategoryNo() const;
        void setSortNo(u32 sortNo);
        u32 getSortNo() const;
        void setRankNo(u32 rank);
        u32 getRankNo() const;
        void setUID(MT_CTSTR UID);
        MT_CTSTR getUID() const;
        void setBagType(u32 type);
        u32 getBagType() const;
        void setType(u32 type);
        u32 getType() const;
        void setQuality(u32 quality);
        u32 getQuality() const;
        void setGoldKey(u32 gold);
        u32 getGoldKey() const;
        void setElementNum(u32 num);
        u32 getElementNum() const;
        void setEquipPoint(u32 point);
        u32 getEquipPoint() const;
        void setColorSortNo(u8 no);
        u32 getColorSortNo() const;
    private:
        u32 mRecipeId;  // offset: 0x8
        u32 mCategoryNo;  // offset: 0xc
        u32 mSortNo;  // offset: 0x10
        u32 mRank;  // offset: 0x14
        u32 mBagType;  // offset: 0x18
        u32 mType;  // offset: 0x1c
        SUB_SORT_KEY mSubKey;  // offset: 0x20
        u32 mElementNum;  // offset: 0x24
        u32 mEquipPoint;  // offset: 0x28
        u8 mColorSortNo;  // offset: 0x2c
        MtString mUID;  // offset: 0x30
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
    cCraftRecipe();
    virtual ~cCraftRecipe();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    u32 convCategoryToIndex(rItemList::ITEM_CATEGORY category);
    rItemList::ITEM_CATEGORY convIndexToCategory(u32 index);
    u32 convEquipCategoryToIndex(nCharacterData::EQUIP_CATEGORY category);
    nCharacterData::EQUIP_CATEGORY convIndexToEquipCategory(u32 index);
    cCraftCapPassData* getCapRecipe(rCraftCapPass* pRes, u32 recipeId);
    rCraftRecipe::cCraftRecipe* getCapRecipeFromLimit(rCraftCapPass* pRes, u32 rankLimit);
    rCraftRecipe::cCraftRecipe* getCapRecipeFromCapLv(rCraftCapPass* pRes, u32 capLv);
    void clearRecipeList();
    void createRecipeList(u32 rankCap, nCraft::E_CRAFT_RECIPE_CATEGORY_TYPE category);
    void clearUpGradeList();
    void createUpGradeList(nCraft::E_CRAFT_RECIPE_CATEGORY_TYPE category, bool isEffect);
    bool sortByGold(const cCraftRecipeList* src, const cCraftRecipeList* dst, u32 param);
    bool sortByPrio(const cCraftRecipeList* src, const cCraftRecipeList* dst, u32 param);
    bool sortByGrade(const cCraftRecipeList* src, const cCraftRecipeList* dst, u32 param);
    bool sortByCategory(const cCraftRecipeList* src, const cCraftRecipeList* dst, u32 param);
    u32 getCategoryNum();
    u32 getItemCategoyNum(rItemList::ITEM_CATEGORY category);
    u32 getEquipCategoryNum();
    u32 getEquipItemCategoyNum(nCharacterData::EQUIP_CATEGORY category);
    rCraftRecipe::cCraftRecipe* getRecipeList(u32 itemCate, u32 index);
    u32 getRecipeId(u32 itemCate, u32 index);
    u32 getRecipeType(u32 itemCate, u32 index);
    rCraftRecipe::cCraftRecipe* getRecipeList(u32 recipeId);
    u32 getRecipeIndex(u32 itemCate, u32 recipeId);
    MT_CTSTR getSelectUID(u32 category, u32 index);
    u32 getSelectItemBagType(u32 category, u32 index);
    MT_CTSTR getRecipeItemName(rCraftRecipe::cCraftRecipe* pRecipe);
    void getRecipeItemInfo(rCraftRecipe::cCraftRecipe* pRecipe, MtString& retStr);
    u32 getRecipeItemGrade(rCraftRecipe::cCraftRecipe* pRecipe);
    u32 getRecipeItemRank(rCraftRecipe::cCraftRecipe* pRecipe);
    u32 getRecipeItemRank(u32 recipeId);
    bool isCreate(u32 recipeId, bool isEffect);
    void setRecipeType(RECIPE_TYPE type);
private:
    void init();
    rCraftRecipe::cCraftRecipe* getCreateRecipeList(u32 itemCate, u32 index);
    rCraftRecipe::cCraftRecipe* getGradeupRecipeList(u32 itemCate, u32 index);
    rCraftRecipe::cCraftRecipe* getCreateRecipeList(u32 recipeId);
    rCraftRecipe::cCraftRecipe* getGradeupRecipeList(u32 recipeId);
    void createRecipeListAll(u32 rankCap);
    void createRecipeListCategory(u32 rankCap, nCraft::E_CRAFT_RECIPE_CATEGORY_TYPE category);
    void createUpGradeListAll(bool isEffect);
    void createUpGradeListCategory(nCraft::E_CRAFT_RECIPE_CATEGORY_TYPE category, bool isEffect);
private:
    RECIPE_TYPE mRecipeType;  // offset: 0x8
    MtTypedArray<cCraftRecipeList> mRecipeList[9];  // offset: 0x10
public:
    static MyDTI DTI;
private:
    static const u32 CREATE_CRAFT_ITEM_CATEGORY_NUM = 9;
    static const rItemList::ITEM_CATEGORY mCategoryTbl[];
    static const nCharacterData::EQUIP_CATEGORY mEquipCategoryTbl[];
};

// Inline, no code of its own: checked where it is inlined.
inline u32 cCraftRecipe::cCraftRecipeList::getRecipeId() const {
    return this->mRecipeId;
}

// Inline, no code of its own: checked where it is inlined.
inline u32 cCraftRecipe::cCraftRecipeList::getBagType() const {
    return this->mBagType;
}

// Inline, no code of its own: checked where it is inlined.
inline u32 cCraftRecipe::cCraftRecipeList::getType() const {
    return this->mType;
}
