#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "MtSynchronize.h"

// Forward declarations
class MtAllocator;
class MtCriticalSection;
class MtDTI;
class MtProperty;
class MtPropertyList;
class MtUI;
class rEvaluationTable;
class uDDOModel;

// Declarations
namespace cEvaluationName { class cEvaluation; }
namespace cEvaluationName { class cEvaluationData; }
namespace cEvaluationName { class cEvaluationPoint; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

namespace cEvaluationName {
    class cEvaluationPoint : public ::MtObject
    {
    public:
        enum CATEGORY
        {
            CAT_UNKNOWN = 0,
            CAT_DAMAGE = 1,
            CAT_DAMAGEREACT = 2,
            CAT_DAMAGE_EX = 3,
            CAT_DISTANCE = 4,
            CAT_PROVO = 5,
            CAT_MAGIC_HEAL = 6,
            CAT_ITEM = 7,
            CAT_NPC = 8,
            CAT_OBJ = 9,
            CAT_ENEMY_1 = 10,
            CAT_MAGIC_DMG = 11,
            CAT_DAMAGE2 = 12,
            CAT_SPECIAL = 13,
            CAT_YOJINOBORI_DMG = 14,
            CAT_ENEMY_TARGET = 15,
            CAT_ENEMY_SENSER = 16,
            CAT_SPECIAL_DELETE = 17,
            CAT_MAX = 18,
        };
        enum EXCLUDE
        {
            EXCLUDE_DEAD = 1,
            EXCLUDE_HANGED = 2,
        };
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        cEvaluationPoint();
        void clr();
        cEvaluationPoint(rEvaluationTable* pRes, u32 categorys, f32 add, f32 dec);
        void setEvaluationPoint(rEvaluationTable* pRes, u32 categorys, f32 add, f32 dec);
        // Address: 0x01987fb0 - 0x01987fb1 (1 bytes)
        virtual ~cEvaluationPoint() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    public:
        bool mEnable;  // offset: 0x8
        u32 mCategory;  // offset: 0xc
        f32 mAddValue;  // offset: 0x10
        f32 mDecValue;  // offset: 0x14
        static MyDTI DTI;
    };
}  // namespace cEvaluationName

namespace cEvaluationName {
    class cEvaluationData : public ::MtObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        cEvaluationData();
        virtual ~cEvaluationData();
        void clr();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        bool deleteCategory(u32 categorys);
        void clrAllPointDataList();
    public:
        bool mEnable;  // offset: 0x8
        uDDOModel* mpObject;  // offset: 0x10
        cEvaluationName::cEvaluationPoint mEvaPointList[32];  // offset: 0x18
        f32 mNeverAddValue;  // offset: 0x318
        bool mIsSessionLost;  // offset: 0x31c
        f32 mSessionStateUpdateTimer;  // offset: 0x320
        static MyDTI DTI;
        static const u32 POINTLIST_MAX = 32;
    };
}  // namespace cEvaluationName

namespace cEvaluationName {
    class cEvaluation : public ::MtObject
    {
    public:
        class MyDTI;
        struct EVALUATION_RESULT;
    public:
        using EVALUATION_RESULT = cEvaluationName::cEvaluation::EVALUATION_RESULT;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        struct EVALUATION_RESULT
        {
        public:
            u32 mEvalutionCategory;  // offset: 0x0
            u32 mEvalutionCategoryMax;  // offset: 0x4
            f32 mEvalutionCategoryDecPer;  // offset: 0x8
            f32 mEvalutionCategoryHosei;  // offset: 0xc
            f32 mEvalutionCategoryEizokuHosei;  // offset: 0x10
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
        cEvaluation();
        virtual ~cEvaluation();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        void setMyObject(uDDOModel* pObj);
        bool isEvaEnable(cEvaluationName::cEvaluationData* pEvaData, u32 excludeFlag);
        f32 getEvaPoint();
        uDDOModel* getEvaHighUnit();
        uDDOModel* getEvaHigh(u32 excludeFlag);
        f32 getUnitEvaPoint(uDDOModel* pMod, u32 categoryNo);
        f32 getCatDamageRate();
        void setCatDamageRate(f32);
        void deleteCategory(uDDOModel* pObjModel, u32 category);
        void deleteCategory(u32 category);
        void deleteCategoryAll(uDDOModel* pObjModel);
        bool addEvaluation(uDDOModel* pObjModel, u32 category, f32 addValue, f32 decValue, bool scription, bool isPlHosei, f32 neverAdd, bool ignoreAbility);
        bool addEvaluationLimitHeight(uDDOModel* pObjModel, u32 category, f32 addValue, f32 decValue, bool scription, bool isPlHosei, f32 neverAdd, bool ignoreAbility, f32 height);
        void updatePtr();
        void calcAllEvaValue();
        void decNeverEvaValue(MtObject* pSrcObject, f32 decNever);
        void perNeverEvaValue(MtObject* pSrcObject, f32 perData);
        void setResource(rEvaluationTable* pRes);
        rEvaluationTable* getResource();
        EVALUATION_RESULT getCategoryData(u32 categorys);
        void updateEvaSessionState();
        void checkEvaSessionState(cEvaluationName::cEvaluationData& data);
        bool checkIsSessionLost(uDDOModel& objModel);
        static f32 getCategoryMax(rEvaluationTable* pRes, u32 categorys);
        static f32 getCategoryDec(rEvaluationTable* pRes, u32 categorys);
    public:
        cEvaluationName::cEvaluationData mEvaList[16];  // offset: 0x8
    private:
        uDDOModel* mpMyObj;  // offset: 0x3288
        uDDOModel* mpEvaTopObj;  // offset: 0x3290
        f32 mTopEvaPoint;  // offset: 0x3298
        f32 mCatDamageRate;  // offset: 0x329c
    public:
        MtCriticalSection mCS;  // offset: 0x32a0
    private:
        rEvaluationTable* mpEvaluationTableRes;  // offset: 0x32a8
    public:
        static MyDTI DTI;
        static const u32 EVADATALIST_MAX = 16;
    };
}  // namespace cEvaluationName

// Inline, no code of its own: checked where it is inlined.
inline cEvaluationName::cEvaluationPoint::cEvaluationPoint() {
    this->mCategory = static_cast<u32>(0);
    this->mAddValue = 0.0f;
    this->mDecValue = 0.0f;
    this->mEnable = false;
}
