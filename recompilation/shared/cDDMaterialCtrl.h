#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtColor.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "nDrawMaterial.h"
#include "sEffectExt.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtColorHLS;
class MtDTI;
struct MtFloat2;
struct MtFloat3;
struct MtFloat4;
class MtPropertyList;
class MtVector2;
class MtVector3;
class MtVector4;
class cBakeModel;
class cpDDMrlMgr;
namespace nDraw { class ConstantTable; }
namespace nDraw { class Material; }
namespace nDraw { class MaterialStdEst; }
class rModel;
class uBaseModel;
class uDDOModel;

// Declarations
class cDDMaterialCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_STR = MT_CHAR*;
using u32 = unsigned int;
using SO_HANDLE = u32;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;

class cDDMaterialCtrl : public MtObject
{
public:
    enum CONTROL_TYPE
    {
        CONTROL_TYPE_BURN = 1,
        CONTROL_TYPE_FREEZE = 2,
        CONTROL_TYPE_CLIP = 4,
        CONTROL_TYPE_EMISSION = 8,
        CONTROL_TYPE_TEXBLEND = 16,
        CONTROL_TYPE_OUTLINE = 32,
        CONTROL_TYPE_MATERIAL = 64,
        CONTROL_TYPE_ALL = -1,
    };
public:
    class MyDTI;
    class cShaderDataDamage;
    class cShaderData;
    class cShaderDataStatusAilments;
    class cShaderDataOutline;
    class cShaderDataEmission;
    class cShaderDataMaterial;
    class cShaderDataAnimation;
    class cShaderDataAnimationToDefault;
    class cShaderDataMaterialOldData;
    class cShaderDataDamageDrawOn;
    class cShaderDataDead;
    class cShaderDataBloodStain;
    class cShaderDataHakuryuStone;
    class cShaderDataFireDamage;
    class cShaderDataFire;
    class cShaderDataFreeze;
    class cShaderDataGeneral;
    class cShaderDataWetOil;
    class cShaderDataStone;
    class cShaderDataGold;
    class cShaderDataErosion;
    class cShaderDataOutlineOn;
    class cShaderDataEmissionEye;
    class cShaderDataMaterialToDefaultColor;
    class cShaderDataMaterialColor;
    class cShaderDataMaterialDead;
    class cShaderDataMaterialEnchantFire;
    class cShaderDataMaterialEnchant;
    class cShaderDataMaterialEnchantIce;
    class cShaderDataMaterialEnchantThunder;
    class cShaderDataMaterialEnchantHoly;
    class cShaderDataMaterialEnchantDark;
    class cShaderDataWaterColor;
    class cShaderDataConstantMaterialColor;
    class cShaderDataSdl;
    class cShaderDataSdlData;
    class cShaderDataMaterialEnchantCraftFire;
    class cShaderDataMaterialEnchantCraft;
    class cShaderDataMaterialEnchantCraftIce;
    class cShaderDataMaterialEnchantCraftThunder;
    class cShaderDataMaterialEnchantCraftHoly;
    class cShaderDataMaterialEnchantCraftDark;
    class cShaderDataMaterialAlchemyShell;
    class cShaderDataMaterialElementEnemyFire;
    class cShaderDataMaterialElementEnemy;
    class cShaderDataMaterialElementEnemyIce;
    class cShaderDataMaterialElementEnemyThunder;
    class cShaderDataMaterialElementEnemyHoly;
    class cShaderDataMaterialElementEnemyDark;
    class cShaderDataMaterialOmBlink;
public:
    using TitleMaterial = nDraw::MaterialStdEst;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cShaderData : public MtObject
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
        cShaderData();
        // Address: 0x01964cc0 - 0x01964cc1 (1 bytes)
        virtual ~cShaderData() {}
        virtual void init(uBaseModel* bm, cBakeModel* pBakeModel, cDDMaterialCtrl* pMaterialCtrl);  // vtable slot 6
        // Address: 0x019645e0 - 0x019645e1 (1 bytes)
        virtual void update() {}  // vtable slot 7
        // Address: 0x019645b0 - 0x019645b1 (1 bytes)
        virtual void end(uBaseModel* bm, u32 next) {}  // vtable slot 8
        // Address: 0x019645f0 - 0x019645f1 (1 bytes)
        virtual void setCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index) {}  // vtable slot 9
        virtual bool isEnd();  // vtable slot 10
        // Address: 0x01964d20 - 0x01964d21 (1 bytes)
        virtual void copy(cDDMaterialCtrl::cShaderData* sd) {}  // vtable slot 11
        virtual bool isSetCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 12
        uBaseModel* getOwner();
        uDDOModel* getOwnerDDO();
        cBakeModel* getBakeModel();
        u32 getMaterialNum();
        cDDMaterialCtrl::TitleMaterial* getMaterial(u32 index);
        bool isLastMaterial(cDDMaterialCtrl::TitleMaterial* pm);
        f32 convertRGBtoHLSRev(MtVector3& col, MtColorHLS* RetHLS);
        cpDDMrlMgr* getRootMaterialManager();
        cDDMaterialCtrl* getRootMaterialCtrl();
        virtual MtVector3 getDefDiffuseColor(u32 index);  // vtable slot 13
        virtual MtVector4 getDefAlbedoBlendColor(u32 index);  // vtable slot 14
        virtual MtVector3 getDefSpecularColor(u32 index);  // vtable slot 15
        virtual MtVector3 getDefReflectiveColor(u32 index);  // vtable slot 16
        virtual MtVector3 getDefEmissionColor(u32 index);  // vtable slot 17
        virtual MtVector3 getDefAlbedoColor(u32 index);  // vtable slot 18
        bool getCacheFlag();
        void setCacheFlag(bool set);
    private:
        uBaseModel* mpOwner;  // offset: 0x8
        cBakeModel* mpBakeModel;  // offset: 0x10
        cDDMaterialCtrl* mpMaterialCtrl;  // offset: 0x18
        bool mIsCacheNone;  // offset: 0x20
    public:
        static MyDTI DTI;
    };
public:
    class cShaderDataStatusAilments : public cDDMaterialCtrl::cShaderData
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
        cShaderDataStatusAilments();
        // Address: 0x01964220 - 0x01964221 (1 bytes)
        virtual ~cShaderDataStatusAilments() {}
        virtual void init(uBaseModel* bm, cBakeModel* pBakeModel, cDDMaterialCtrl* pMaterialCtrl);  // vtable slot 6
        virtual void update();  // vtable slot 7
        virtual bool isEnd();  // vtable slot 10
        virtual bool isSetCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 12
        virtual void setCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 9
        virtual void setCommonCB(cDDMaterialCtrl::TitleMaterial* pm);  // vtable slot 19
        // Address: 0x01964db0 - 0x01964db1 (1 bytes)
        virtual void setExclusiveCB(cDDMaterialCtrl::TitleMaterial* pm) {}  // vtable slot 20
        virtual void setTextureForMaterial(cDDMaterialCtrl::TitleMaterial* pm);  // vtable slot 21
        virtual void copy(cDDMaterialCtrl::cShaderData* sd);  // vtable slot 11
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        f32 getApplicateA();
        f32 getFactorN();
        f32 getFactorS();
        f32 getResetFactorS();
        MtFloat2 getUVOffset();
        f32 getUVScale();
        void setApplicateA(f32 set);
        void setFactorN(f32 set);
        void setFactorS(f32 set);
        void setResetFactorS(f32 set);
        void setUVOffset(MtFloat2& set);
        void setUVScale(f32 set);
        virtual u32 getAlimentsTextureId();  // vtable slot 22
        sEffectExt::cStatusAilmentsTexture* getStatusAilmentsTexture();
        void setStatusAilmentsTexture(sEffectExt::cStatusAilmentsTexture* set);
        void setEnd(bool);
    private:
        sEffectExt::cStatusAilmentsTexture* mpTexture;  // offset: 0x28
        f32 mApplicateA;  // offset: 0x30
        f32 mFactorN;  // offset: 0x34
        f32 mFactorS;  // offset: 0x38
        f32 mResetFactorS;  // offset: 0x3c
        MtFloat2 mUVOffset;  // offset: 0x40
        f32 mUVScale;  // offset: 0x48
        bool mIsEnd;  // offset: 0x4c
    public:
        static MyDTI DTI;
        static const u32 SHADER_TARGET_MATERIAL_MAX_NUM = 8;
        static const u32 SHADER_MATERIAL_ID_DEFAULT = 255;
    };
public:
    class cShaderDataOutline : public cDDMaterialCtrl::cShaderData
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
        cShaderDataOutline();
        // Address: 0x019641a0 - 0x019641a1 (1 bytes)
        virtual ~cShaderDataOutline() {}
        virtual void setCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 9
        u32 getBlendType();
        u32 getColorType();
        MtVector4 getOColor();
        MtVector4 getIColor();
        f32 getBalanceOffset();
        f32 getBalanceScale();
        f32 getBalance();
        void setBlendType(u32 set);
        void setColorType(u32 set);
        void setOColor(MtVector4& set);
        void setIColor(MtVector4& set);
        void setBalanceOffset(f32 set);
        void setBalanceScale(f32 set);
        void setBalance(f32 set);
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    private:
        u32 mBlendType;  // offset: 0x24
        MtVector4 mOColor;  // offset: 0x30
        MtVector4 mIColor;  // offset: 0x40
        u32 mColorType;  // offset: 0x50
        f32 mBalanceOffset;  // offset: 0x54
        f32 mBalanceScale;  // offset: 0x58
        f32 mBalance;  // offset: 0x5c
    public:
        static MyDTI DTI;
    };
public:
    class cShaderDataEmission : public cDDMaterialCtrl::cShaderData
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
        cShaderDataEmission();
        // Address: 0x01964180 - 0x01964181 (1 bytes)
        virtual ~cShaderDataEmission() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        MtVector3 getEmissionColor();
        MtVector3 getEmissionBlendColor();
        f32 getEmissionBlendFactor();
        f32 getEmissionIntensity();
        MtVector3 getDiffuseColor();
        MtVector3 getDiffuseBlendColor();
        f32 getDiffuseBlendFactor();
        void setEmissionColor(MtVector3&);
        void setEmissionBlendColor(MtVector3&);
        void setEmissionBlendFactor(f32);
        void setEmissionIntensity(f32);
        void setDiffuseColor(MtVector3&);
        void setDiffuseBlendColor(MtVector3&);
        void setDiffuseBlendFactor(f32);
    private:
        MtVector3 mEmissionColor;  // offset: 0x30
        MtVector3 mEmissionBlendColor;  // offset: 0x40
        f32 mEmissionBlendFactor;  // offset: 0x50
        f32 mEmissionIntensity;  // offset: 0x54
        f32 mDiffuseBlendFactor;  // offset: 0x58
        MtVector3 mDiffuseColor;  // offset: 0x60
        MtVector3 mDiffuseBlendColor;  // offset: 0x70
    public:
        static MyDTI DTI;
        static const u32 SHADER_MATERIAL_ID_DEFAULT = 255;
    };
public:
    class cShaderDataMaterial : public cDDMaterialCtrl::cShaderData
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
        cShaderDataMaterial();
        // Address: 0x01964070 - 0x01964071 (1 bytes)
        virtual ~cShaderDataMaterial() {}
        virtual void end(uBaseModel* bm, u32 next);  // vtable slot 8
        virtual void init(uBaseModel* bm, cBakeModel* pBakeModel, cDDMaterialCtrl* pMaterialCtrl);  // vtable slot 6
        virtual void setEnd(bool f);  // vtable slot 19
        virtual bool isEnd();  // vtable slot 10
    private:
        bool mIsEnd;  // offset: 0x21
    public:
        static MyDTI DTI;
    };
public:
    class cShaderDataAnimation : public cDDMaterialCtrl::cShaderDataMaterial
    {
    public:
        class MyDTI;
        class cAnimData;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class cAnimData : public MtObject
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
            cAnimData();
            void setNextAnimationName(MT_CTSTR AnimName);
            MT_STR getNextAnimationName();
            void setCostFrame(f32 set);
            s32 getCostFrame();
            void setStartFrame(f32 set);
            s32 getStartFrame();
            void setMaterialId(u32 set);
            u32 getMaterialId();
        private:
            char mAnimName[256];  // offset: 0x8
            f32 mCostFrame;  // offset: 0x108
            f32 mStartFrame;  // offset: 0x10c
            u32 mMaterialId;  // offset: 0x110
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
        cShaderDataAnimation();
        virtual ~cShaderDataAnimation();
        virtual void init(uBaseModel* bm, cBakeModel* pBakeModel, cDDMaterialCtrl* pMaterialCtrl);  // vtable slot 6
        virtual void setCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 9
        virtual void update();  // vtable slot 7
        virtual void addRequestData(MT_CTSTR AnimName, u32 MaterialId, f32 CostFrame, f32 StartFrame);  // vtable slot 20
        virtual bool judgeValidAnimation(cDDMaterialCtrl::TitleMaterial* pm);  // vtable slot 21
        virtual s32 getEndValueInt(const nDraw::Animation::PARAM_INT* ParamInt, cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 22
        virtual f32 getEndValueFloat(const nDraw::Animation::PARAM_FLOAT* ParamFloat, cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 23
        virtual MtFloat4 getEndValueVector(const nDraw::Animation::PARAM_VECTOR* ParamVector, cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 24
        virtual void setAnimation(cDDMaterialCtrl::TitleMaterial* pm, s32 AnimIndex, MT_CTSTR AnimName, f32 StartFrame);  // vtable slot 25
        const nDraw::Material* getResMaterial(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);
    private:
        MtTypedArray<cAnimData> mAnimData;  // offset: 0x28
    public:
        static MyDTI DTI;
        static const f32 CHANGE_MRL_ANIM_FRAME;
        static const u32 MRL_ANIM_LEVEL_START_MATERIAL_ID;
    };
public:
    class cShaderDataAnimationToDefault : public cDDMaterialCtrl::cShaderDataAnimation
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
        cShaderDataAnimationToDefault();
        virtual ~cShaderDataAnimationToDefault();
        virtual s32 getEndValueInt(const nDraw::Animation::PARAM_INT* ParamInt, cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 22
        virtual f32 getEndValueFloat(const nDraw::Animation::PARAM_FLOAT* ParamFloat, cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 23
        virtual MtFloat4 getEndValueVector(const nDraw::Animation::PARAM_VECTOR* ParamVector, cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 24
        virtual void setAnimation(cDDMaterialCtrl::TitleMaterial* pm, s32 AnimIndex, MT_CTSTR AnimName, f32 StartFrame);  // vtable slot 25
    public:
        static MyDTI DTI;
    };
public:
    class cShaderDataMaterialOldData : public cDDMaterialCtrl::cShaderDataMaterial
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
        cShaderDataMaterialOldData();
        virtual ~cShaderDataMaterialOldData();
        virtual void init(uBaseModel* bm, cBakeModel* pBakeModel, cDDMaterialCtrl* pMaterialCtrl);  // vtable slot 6
        virtual void setCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 9
        void createData();
        void resetData();
        f32 getBAlphaClipThresholdOld(u32);
    private:
        f32* mpBAlphaClipThreshold;  // offset: 0x28
    public:
        static MyDTI DTI;
    };
public:
    class cShaderDataFire : public cDDMaterialCtrl::cShaderDataStatusAilments
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
        cShaderDataFire();
        // Address: 0x01964210 - 0x01964211 (1 bytes)
        virtual ~cShaderDataFire() {}
        virtual void init(uBaseModel* bm, cBakeModel* pBakeModel, cDDMaterialCtrl* pMaterialCtrl);  // vtable slot 6
        virtual void setCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 9
        virtual u32 getAlimentsTextureId();  // vtable slot 22
        virtual void update();  // vtable slot 7
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    private:
        f32 mPassageFrame;  // offset: 0x50
        f32 mLoopFrame;  // offset: 0x54
    public:
        static MyDTI DTI;
    };
public:
    class cShaderDataFreeze : public cDDMaterialCtrl::cShaderDataStatusAilments
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
        cShaderDataFreeze();
        // Address: 0x01964200 - 0x01964201 (1 bytes)
        virtual ~cShaderDataFreeze() {}
        virtual void init(uBaseModel* bm, cBakeModel* pBakeModel, cDDMaterialCtrl* pMaterialCtrl);  // vtable slot 6
        virtual void setCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 9
        virtual u32 getAlimentsTextureId();  // vtable slot 22
        virtual void update();  // vtable slot 7
    public:
        static MyDTI DTI;
    };
public:
    class cShaderDataGeneral : public cDDMaterialCtrl::cShaderDataFreeze
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
        cShaderDataGeneral();
        // Address: 0x019641f0 - 0x019641f1 (1 bytes)
        virtual ~cShaderDataGeneral() {}
        virtual void init(uBaseModel* bm, cBakeModel* pBakeModel, cDDMaterialCtrl* pMaterialCtrl);  // vtable slot 6
        virtual u32 getAlimentsTextureId();  // vtable slot 22
        virtual void update();  // vtable slot 7
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    private:
        f32 mUVScrSpeed;  // offset: 0x50
    public:
        static MyDTI DTI;
    };
public:
    class cShaderDataWetOil : public cDDMaterialCtrl::cShaderDataStatusAilments
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
        cShaderDataWetOil();
        // Address: 0x019641e0 - 0x019641e1 (1 bytes)
        virtual ~cShaderDataWetOil() {}
        virtual void init(uBaseModel* bm, cBakeModel* pBakeModel, cDDMaterialCtrl* pMaterialCtrl);  // vtable slot 6
        virtual void setCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 9
        virtual void setExclusiveCB(cDDMaterialCtrl::TitleMaterial* pm);  // vtable slot 20
        virtual void setTextureForMaterial(cDDMaterialCtrl::TitleMaterial* pm);  // vtable slot 21
        virtual u32 getAlimentsTextureId();  // vtable slot 22
        virtual void update();  // vtable slot 7
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    private:
        f32 mUVScrSpeed;  // offset: 0x50
        f32 mDefApplicateA;  // offset: 0x54
        f32 mDefFactorN;  // offset: 0x58
    public:
        static MyDTI DTI;
    };
public:
    class cShaderDataStone : public cDDMaterialCtrl::cShaderDataStatusAilments
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
        cShaderDataStone();
        // Address: 0x019641d0 - 0x019641d1 (1 bytes)
        virtual ~cShaderDataStone() {}
        virtual void init(uBaseModel* bm, cBakeModel* pBakeModel, cDDMaterialCtrl* pMaterialCtrl);  // vtable slot 6
        virtual void setCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 9
        virtual u32 getAlimentsTextureId();  // vtable slot 22
        virtual void update();  // vtable slot 7
        void setPassageFrame(f32 set);
    private:
        f32 MAX_FRAME;  // offset: 0x50
        f32 mPassageFrame;  // offset: 0x54
    public:
        static MyDTI DTI;
    };
public:
    class cShaderDataGold : public cDDMaterialCtrl::cShaderDataStone
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
        cShaderDataGold();
        // Address: 0x019641c0 - 0x019641c1 (1 bytes)
        virtual ~cShaderDataGold() {}
        virtual void init(uBaseModel* bm, cBakeModel* pBakeModel, cDDMaterialCtrl* pMaterialCtrl);  // vtable slot 6
        virtual u32 getAlimentsTextureId();  // vtable slot 22
        virtual void update();  // vtable slot 7
        void setPassageFrame(f32 set);
    private:
        f32 MAX_FRAME;  // offset: 0x58
        f32 mPassageFrame;  // offset: 0x5c
    public:
        static MyDTI DTI;
    };
public:
    class cShaderDataErosion : public cDDMaterialCtrl::cShaderDataStatusAilments
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
        cShaderDataErosion();
        // Address: 0x019641b0 - 0x019641b1 (1 bytes)
        virtual ~cShaderDataErosion() {}
        virtual void init(uBaseModel* bm, cBakeModel* pBakeModel, cDDMaterialCtrl* pMaterialCtrl);  // vtable slot 6
        virtual u32 getAlimentsTextureId();  // vtable slot 22
        virtual void update();  // vtable slot 7
        void requestLevel(s32 OcdBadErisionLv);
    private:
        s32 mLevel;  // offset: 0x50
        f32 mApplicateATbl[3];  // offset: 0x54
        f32 mFactorNTbl[3];  // offset: 0x60
        f32 mFactorSTbl[3];  // offset: 0x6c
        f32 USE_FRAME;  // offset: 0x78
        f32 mPassageFrame;  // offset: 0x7c
    public:
        static MyDTI DTI;
        static const u32 EROSION_LEVEL_NUM = 3;
    };
public:
    class cShaderDataOutlineOn : public cDDMaterialCtrl::cShaderDataOutline
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
        cShaderDataOutlineOn();
        // Address: 0x01964190 - 0x01964191 (1 bytes)
        virtual ~cShaderDataOutlineOn() {}
        virtual void setCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 9
    public:
        static MyDTI DTI;
    };
public:
    class cShaderDataEmissionEye : public cDDMaterialCtrl::cShaderDataEmission
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
        cShaderDataEmissionEye();
        // Address: 0x01964170 - 0x01964171 (1 bytes)
        virtual ~cShaderDataEmissionEye() {}
        virtual bool isSetCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 12
        virtual void setCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 9
    public:
        static MyDTI DTI;
        static const u16 MATERIAL_EMISSION_EYE_ID_START = 300;
        static const u16 MATERIAL_EMISSION_EYE_FIXDRATE_ID_END = 349;
        static const u16 MATERIAL_EMISSION_EYE_ID_END = 399;
        static const f32 FIXED_EYE_INTENSITY;
    };
public:
    class cShaderDataMaterialToDefaultColor : public cDDMaterialCtrl::cShaderDataMaterial
    {
    public:
        class MyDTI;
        struct CALC_DATA_TABLEv3;
        struct CALC_DATA_TABLEv4;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        struct CALC_DATA_TABLEv3
        {
        public:
            bool mIsEnd;  // offset: 0x0
            bool mIsCB;  // offset: 0x1
            SO_HANDLE mSoHandle;  // offset: 0x4
            MtVector3* mpFColor;  // offset: 0x8
            MtVector3 mNColor;  // offset: 0x10
        };
    public:
        struct CALC_DATA_TABLEv4
        {
        public:
            bool mIsEnd;  // offset: 0x0
            bool mIsCB;  // offset: 0x1
            SO_HANDLE mSoHandle;  // offset: 0x4
            MtVector4* mpFColor;  // offset: 0x8
            MtVector4 mNColor;  // offset: 0x10
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
        cShaderDataMaterialToDefaultColor();
        virtual ~cShaderDataMaterialToDefaultColor();
        virtual void init(uBaseModel* bm, cBakeModel* pBakeModel, cDDMaterialCtrl* pMaterialCtrl);  // vtable slot 6
        virtual void update();  // vtable slot 7
        virtual void setCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 9
        void createDefaultColors();
        void resetDefaultColors();
        void setForceEquip(bool set);
        virtual MtVector3 getDefDiffuseColor(u32 index);  // vtable slot 13
        virtual MtVector4 getDefAlbedoBlendColor(u32 index);  // vtable slot 14
        virtual MtVector3 getDefSpecularColor(u32 index);  // vtable slot 15
        virtual MtVector3 getDefReflectiveColor(u32 index);  // vtable slot 16
        virtual MtVector3 getDefEmissionColor(u32 index);  // vtable slot 17
        virtual MtVector3 getDefAlbedoColor(u32 index);  // vtable slot 18
        void setVectorF_FromCdt(CALC_DATA_TABLEv3* cdt, cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index, nDraw::ConstantTable* pct);
        void setVectorF_FromCdt(CALC_DATA_TABLEv4* cdt, cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index, nDraw::ConstantTable* pct);
        MtVector3 getVectorF_FromCdt(CALC_DATA_TABLEv3* cdt, cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index, nDraw::ConstantTable* pct);
        MtVector4 getVectorF_FromCdt(CALC_DATA_TABLEv4* cdt, cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index, nDraw::ConstantTable* pct);
        bool isCreateEnchantColor();
        void setEndFrame(f32 set);
        f32 getEndFrame();
        bool allocEnchantWeaponColor();
        bool allocEnchantEnemyColor();
    private:
        MtVector3* mpDiffuseColor;  // offset: 0x28
        MtVector3* mpSpecularColor;  // offset: 0x30
        MtVector4* mpAlbedoBlendColor;  // offset: 0x38
        MtVector3* mpReflectiveColor;  // offset: 0x40
        MtVector3* mpEmissionColor;  // offset: 0x48
        MtVector3* mpAlbedoColor;  // offset: 0x50
        f32 mPastFrame;  // offset: 0x58
        f32 mEndFrame;  // offset: 0x5c
        bool mForceEquip;  // offset: 0x60
        bool mIsCreateEnchantColor;  // offset: 0x61
    public:
        static MyDTI DTI;
    };
public:
    class cShaderDataMaterialColor : public cDDMaterialCtrl::cShaderDataMaterial
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
        cShaderDataMaterialColor();
        // Address: 0x01964150 - 0x01964151 (1 bytes)
        virtual ~cShaderDataMaterialColor() {}
        virtual void setCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 9
        void setTargetAll(bool);
        void setDiffuse(const MtVector4& color, f32 rate);
        void setSpecular(const MtVector4& color, f32 rate);
        virtual bool isSetCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 12
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    private:
        bool mTargetAll;  // offset: 0x22
        MtVector4 mDiffuseColor;  // offset: 0x30
        MtVector4 mSpecularColor;  // offset: 0x40
        f32 mDiffuseColorRate;  // offset: 0x50
        f32 mSpecularColorRate;  // offset: 0x54
    public:
        static MyDTI DTI;
    };
public:
    class cShaderDataMaterialDead : public cDDMaterialCtrl::cShaderDataMaterial
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
        cShaderDataMaterialDead();
        // Address: 0x01964140 - 0x01964141 (1 bytes)
        virtual ~cShaderDataMaterialDead() {}
        virtual void init(uBaseModel* bm, cBakeModel* pBakeModel, cDDMaterialCtrl* pMaterialCtrl);  // vtable slot 6
        virtual void setCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 9
    private:
        MtVector3 mSubColor;  // offset: 0x30
    public:
        static MyDTI DTI;
        static const f32 PL_COLOR_DOWN;
        static const f32 EM_COLOR_DOWN;
        static const f32 PL_DEAD_COLMAX;
        static const f32 CL_DEAD_COLMIN;
    };
public:
    class cShaderDataMaterialEnchant : public cDDMaterialCtrl::cShaderDataMaterial
    {
    public:
        class MyDTI;
        struct CALC_DATA_TABLEv3;
        struct CALC_DATA_TABLEv4;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        struct CALC_DATA_TABLEv3
        {
        public:
            MtColorHLS EndColHLS;  // offset: 0x0
            MtColorHLS StaColHLS;  // offset: 0x10
            f32 EndIntensity;  // offset: 0x20
            f32 StaIntensity;  // offset: 0x24
        };
    public:
        struct CALC_DATA_TABLEv4
        {
        public:
            MtColorHLS EndColHLS;  // offset: 0x0
            MtColorHLS StaColHLS;  // offset: 0x10
            f32 EndIntensity;  // offset: 0x20
            f32 StaIntensity;  // offset: 0x24
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
        cShaderDataMaterialEnchant();
        // Address: 0x01965560 - 0x01965561 (1 bytes)
        virtual ~cShaderDataMaterialEnchant() {}
        virtual void update();  // vtable slot 7
        virtual void setCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 9
        virtual bool isSetCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 12
        MtVector4 getFoundationAlbedoBlendColor();
        MtVector3 getFoundationSpecularColor();
        MtVector3 getFoundationReflectiveColor();
        MtVector3 getFoundationEmissionColor();
        f32 getPassageFrame();
        void setFoundationAlbedoBlendColor(MtVector4& set);
        void setFoundationSpecularColor(MtVector3& set);
        void setFoundationReflectiveColor(MtVector3& set);
        void setFoundationEmissionColor(MtVector3& set);
        void setPassageFrame(f32);
        MtVector3 makeEnchantColor(CALC_DATA_TABLEv3* cdt);
        MtVector4 makeEnchantColor(CALC_DATA_TABLEv4* cdt);
    private:
        MtVector4 mFoundationAlbedoBlendColor;  // offset: 0x30
        MtVector3 mFoundationSpecularColor;  // offset: 0x40
        MtVector3 mFoundationReflectiveColor;  // offset: 0x50
        MtVector3 mFoundationEmissionColor;  // offset: 0x60
        f32 mPassageFrame;  // offset: 0x70
    public:
        static MyDTI DTI;
        static const f32 USE_FRAME;
    };
public:
    class cShaderDataMaterialEnchantIce : public cDDMaterialCtrl::cShaderDataMaterialEnchant
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
        virtual void setCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 9
    public:
        static MyDTI DTI;
    };
public:
    class cShaderDataMaterialEnchantThunder : public cDDMaterialCtrl::cShaderDataMaterialEnchant
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
        virtual void setCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 9
    public:
        static MyDTI DTI;
    };
public:
    class cShaderDataMaterialEnchantHoly : public cDDMaterialCtrl::cShaderDataMaterialEnchant
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
        virtual void setCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 9
    public:
        static MyDTI DTI;
    };
public:
    class cShaderDataMaterialEnchantDark : public cDDMaterialCtrl::cShaderDataMaterialEnchant
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
        cShaderDataMaterialEnchantDark();
        virtual void setCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 9
        MtVector3 getFoundationAlbedoColor();
        void setFoundationAlbedoColor(MtVector3& set);
    private:
        MtVector3 mFoundationAlbedoColor;  // offset: 0x80
    public:
        static MyDTI DTI;
    };
public:
    class cShaderDataWaterColor : public cDDMaterialCtrl::cShaderDataMaterial
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
        cShaderDataWaterColor();
        virtual ~cShaderDataWaterColor();
        virtual void init(uBaseModel* bm, cBakeModel* pBakeModel, cDDMaterialCtrl* pMaterialCtrl);  // vtable slot 6
        virtual bool isSetCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 12
        virtual void setCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 9
        void createDefaultColors();
        bool isCreatedDefaultColors();
        void dungeonCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);
        MtVector3 getDungeonRevisionLColor(f32 Border, f32 NightRate, MtVector3& DefCol);
        MtVector3 getDungeonRevisionLSColor(f32 BorderL, f32 BorderS, f32 NightRate, MtVector3& DefCol);
    private:
        MtVector3* mpDefWaterColorBottom;  // offset: 0x28
        MtVector3* mpDefReflectiveColor;  // offset: 0x30
        MtVector3* mpDefWaterColorTop;  // offset: 0x38
    public:
        static MyDTI DTI;
        static const u32 MATERIAL_DAYNIGHT_ID_START = 100;
        static const u32 MATERIAL_DAYNIGHT_ID_END = 199;
        static const u32 MATERIAL_DAYNIGHT_WEATHER_ID_START = 110;
        static const u32 MATERIAL_DAYNIGHT_WEATHER_ID_END = 119;
        static const u32 MATERIAL_DAYNIGHT_WEATHER_DUNGEON_ID_START = 120;
        static const u32 MATERIAL_DAYNIGHT_WEATHER_DUNGEON_ID_END = 129;
    };
public:
    class cShaderDataConstantMaterialColor : public cDDMaterialCtrl::cShaderDataMaterialColor
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
        cShaderDataConstantMaterialColor();
        // Address: 0x01964080 - 0x01964081 (1 bytes)
        virtual ~cShaderDataConstantMaterialColor() {}
        virtual bool isSetCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 12
    public:
        static MyDTI DTI;
    };
public:
    class cShaderDataSdlData : public MtObject
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
        cShaderDataSdlData();
        // Address: 0x01965f50 - 0x01965f51 (1 bytes)
        virtual ~cShaderDataSdlData() {}
        void copy(cDDMaterialCtrl::cShaderDataSdlData* sdsd);
        u32 getTargetMaterialId();
        MtVector2 getUVTransForm0Offset();
        MtVector2 getUVTransForm1Offset();
        MtVector2 getUVTransForm2Offset();
        MtVector2 getUVTransForm0Scale();
        MtVector2 getUVTransForm1Scale();
        MtVector2 getUVTransForm2Scale();
        f32 getDetailNormalUVScale();
        f32 getDetailNormalPower();
        f32 getTransparency();
        f32 getShininess();
        MtVector3 getAlbedoColor();
        MtVector3 getDiffuseColor();
        MtVector3 getSpecularColor();
        MtVector3 getEmissionColor();
        MtVector3 getReflectiveColor();
        f32 getBAlphaClipThreshold();
        f32 getBBlendAlphaBand();
        f32 getBBlendAlphaThreshold();
        f32 getBAlbedoBlendRate();
        MtVector3 getBBlendMapColor();
        f32 getEmissionFactor();
        f32 getVtxDispStart();
        f32 getVtxDispScale();
        f32 getVtxDispStart2();
        f32 getVtxDispScale2();
        void setTargetMaterialId(u32 set);
        void setUVTransForm0Offset(MtVector2& set);
        void setUVTransForm1Offset(MtVector2& set);
        void setUVTransForm2Offset(MtVector2& set);
        void setUVTransForm0Scale(MtVector2& set);
        void setUVTransForm1Scale(MtVector2& set);
        void setUVTransForm2Scale(MtVector2& set);
        void setDetailNormalUVScale(f32 set);
        void setDetailNormalPower(f32 set);
        void setTransparency(f32 set);
        void setShininess(f32 set);
        void setAlbedoColor(MtVector3& set);
        void setDiffuseColor(MtVector3& set);
        void setSpecularColor(MtVector3& set);
        void setEmissionColor(MtVector3& set);
        void setReflectiveColor(MtVector3& set);
        void setBAlphaClipThreshold(f32 set);
        void setBBlendAlphaBand(f32 set);
        void setBBlendAlphaThreshold(f32 set);
        void setBAlbedoBlendRate(f32 set);
        void setBBlendMapColor(MtVector3& set);
        void setEmissionFactor(f32 set);
        void setVtxDispStart(f32 set);
        void setVtxDispScale(f32 set);
        void setVtxDispStart2(f32 set);
        void setVtxDispScale2(f32 set);
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    public:
        u32 mTargetMaterialId;  // offset: 0x8
        MtVector2 mUVTransForm0Offset;  // offset: 0x10
        MtVector2 mUVTransForm1Offset;  // offset: 0x18
        MtVector2 mUVTransForm2Offset;  // offset: 0x20
        MtVector2 mUVTransForm0Scale;  // offset: 0x28
        MtVector2 mUVTransForm1Scale;  // offset: 0x30
        MtVector2 mUVTransForm2Scale;  // offset: 0x38
        f32 mDetailNormalUVScale;  // offset: 0x40
        f32 mDetailNormalPower;  // offset: 0x44
        f32 mTransparency;  // offset: 0x48
        f32 mShininess;  // offset: 0x4c
        f32 mVtxDispStart;  // offset: 0x50
        f32 mVtxDispScale;  // offset: 0x54
        MtVector3 mAlbedoColor;  // offset: 0x60
        MtVector3 mDiffuseColor;  // offset: 0x70
        MtVector3 mSpecularColor;  // offset: 0x80
        MtVector3 mEmissionColor;  // offset: 0x90
        MtVector3 mReflectiveColor;  // offset: 0xa0
        f32 mBAlphaClipThreshold;  // offset: 0xb0
        f32 mBBlendAlphaBand;  // offset: 0xb4
        f32 mBBlendAlphaThreshold;  // offset: 0xb8
        f32 mBAlbedoBlendRate;  // offset: 0xbc
        MtVector3 mBBlendMapColor;  // offset: 0xc0
        f32 mBEmissionFactor;  // offset: 0xd0
        f32 mVtxDispStart2;  // offset: 0xd4
        f32 mVtxDispScale2;  // offset: 0xd8
        static MyDTI DTI;
    };
public:
    class cShaderDataMaterialEnchantCraft : public cDDMaterialCtrl::cShaderDataMaterial
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
        cShaderDataMaterialEnchantCraft();
        cShaderDataMaterialEnchantCraft(MtColorHLS, MtColorHLS);
        virtual void init(uBaseModel* bm, cBakeModel* pBakeModel, cDDMaterialCtrl* pMaterialCtrl);  // vtable slot 6
        virtual void update();  // vtable slot 7
        virtual void setCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 9
        virtual bool isSetCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 12
        f32 getCoef();
        void setAlbedoBlendColor(MtColorHLS Color);
        void setEmissionColor(MtColorHLS Color);
        void setEmissionIntensity(f32 set);
    private:
        MtVector4 mAlbedoBlendColor;  // offset: 0x30
        MtVector3 mEmissionColor;  // offset: 0x40
        f32 mAlbedoIntensity;  // offset: 0x50
        f32 mEmissionIntensity;  // offset: 0x54
        f32 mChangeFrame;  // offset: 0x58
        f32 mStayFrame;  // offset: 0x5c
        f32 mPastFrame;  // offset: 0x60
    public:
        static MyDTI DTI;
        static const f32 CRAFT_ENCHANT_CHANGE_FRAME;
        static const f32 CRAFT_ENCHANT_STAY_FRAME;
        static const f32 CRAFT_ENCHANT_ALBEDOBLEND_INTENSITY;
        static const f32 CRAFT_ENCHANT_EMISSION_INTENSITY;
    };
public:
    class cShaderDataMaterialEnchantCraftIce : public cDDMaterialCtrl::cShaderDataMaterialEnchantCraft
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
        cShaderDataMaterialEnchantCraftIce();
    public:
        static MyDTI DTI;
    };
public:
    class cShaderDataMaterialEnchantCraftThunder : public cDDMaterialCtrl::cShaderDataMaterialEnchantCraft
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
        cShaderDataMaterialEnchantCraftThunder();
    public:
        static MyDTI DTI;
    };
public:
    class cShaderDataMaterialEnchantCraftHoly : public cDDMaterialCtrl::cShaderDataMaterialEnchantCraft
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
        cShaderDataMaterialEnchantCraftHoly();
    public:
        static MyDTI DTI;
    };
public:
    class cShaderDataMaterialEnchantCraftDark : public cDDMaterialCtrl::cShaderDataMaterialEnchantCraft
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
        cShaderDataMaterialEnchantCraftDark();
        virtual void setCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 9
        void setSpecularColor(MtColorHLS Color);
        void setReflectiveColor(MtColorHLS Color);
        void setAlbedoColor(MtColorHLS Color);
    private:
        f32 mSpecularIntencity;  // offset: 0x64
        f32 mReflectiveIntencity;  // offset: 0x68
        f32 mAlbedoIntencity;  // offset: 0x6c
        MtVector3 mSpecularColor;  // offset: 0x70
        MtVector3 mReflectiveColor;  // offset: 0x80
        MtVector3 mAlbedoColor;  // offset: 0x90
    public:
        static MyDTI DTI;
    };
public:
    class cShaderDataMaterialAlchemyShell : public cDDMaterialCtrl::cShaderDataMaterial
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
        cShaderDataMaterialAlchemyShell();
        // Address: 0x01963f70 - 0x01963f71 (1 bytes)
        virtual ~cShaderDataMaterialAlchemyShell() {}
        virtual void update();  // vtable slot 7
        virtual void setCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 9
        virtual bool isSetCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 12
        void requestLevel(u32 level);
    private:
        MtVector3 mAlbedoColor;  // offset: 0x30
        MtVector4 mAlbedoBlendColor;  // offset: 0x40
        MtVector3 mSpecularColor;  // offset: 0x50
        MtVector3 mReflectiveColor;  // offset: 0x60
        MtVector3 mEmissionColor;  // offset: 0x70
        f32 mAlbedoBlendIntensity;  // offset: 0x80
        f32 mAlbedoIntensity;  // offset: 0x84
        f32 mSpecularIntensity;  // offset: 0x88
        f32 mReflectiveIntensity;  // offset: 0x8c
        f32 mEmissionIntensity;  // offset: 0x90
        f32 mPastFrame;  // offset: 0x94
        u32 mLevel;  // offset: 0x98
    public:
        static MyDTI DTI;
    };
public:
    class cShaderDataMaterialElementEnemy : public cDDMaterialCtrl::cShaderDataMaterial
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
        cShaderDataMaterialElementEnemy();
        virtual void init(uBaseModel* bm, cBakeModel* pBakeModel, cDDMaterialCtrl* pMaterialCtrl);  // vtable slot 6
        virtual void update();  // vtable slot 7
        virtual bool isSetCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 12
        virtual void setCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 9
        void setEmissionColorHLS(MtColorHLS set);
        void setEmissionColorColor(MtColor&);
        void setEndEmissionIntensity(f32 set);
        MtColorHLS getEmissionColorHLS();
        MtColor getEmissionColorColor();
    private:
        MtVector3 mEmissionColor;  // offset: 0x30
        f32 mStartEmissionIntensity;  // offset: 0x40
        f32 mEndEmissionIntensity;  // offset: 0x44
        f32 mPastFrame;  // offset: 0x48
        f32 mAnimationFrame;  // offset: 0x4c
        f32 mInterpolateFrame;  // offset: 0x50
    public:
        static MyDTI DTI;
        static const u16 MATERIAL_ELEMENT_ENEMY_ID_START = 500;
        static const u16 MATERIAL_ELEMENT_ENEMY_ID_END = 520;
    };
public:
    class cShaderDataMaterialElementEnemyIce : public cDDMaterialCtrl::cShaderDataMaterialElementEnemy
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
        cShaderDataMaterialElementEnemyIce();
    public:
        static MyDTI DTI;
    };
public:
    class cShaderDataMaterialElementEnemyThunder : public cDDMaterialCtrl::cShaderDataMaterialElementEnemy
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
        cShaderDataMaterialElementEnemyThunder();
    public:
        static MyDTI DTI;
    };
public:
    class cShaderDataMaterialElementEnemyHoly : public cDDMaterialCtrl::cShaderDataMaterialElementEnemy
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
        cShaderDataMaterialElementEnemyHoly();
    public:
        static MyDTI DTI;
    };
public:
    class cShaderDataMaterialElementEnemyDark : public cDDMaterialCtrl::cShaderDataMaterialElementEnemy
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
        cShaderDataMaterialElementEnemyDark();
    public:
        static MyDTI DTI;
    };
public:
    class cShaderDataMaterialOmBlink : public cDDMaterialCtrl::cShaderDataMaterial
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
        cShaderDataMaterialOmBlink();
        // Address: 0x01963f10 - 0x01963f11 (1 bytes)
        virtual ~cShaderDataMaterialOmBlink() {}
        virtual void init(uBaseModel* bm, cBakeModel* pBakeModel, cDDMaterialCtrl* pMaterialCtrl);  // vtable slot 6
        virtual void update();  // vtable slot 7
        virtual bool isSetCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 12
        virtual void setCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 9
    private:
        f32 mPassageFrame;  // offset: 0x24
        f32 mLoopFrame;  // offset: 0x28
        f32 mIntensity;  // offset: 0x2c
    public:
        static MyDTI DTI;
        static const u32 TARGET_MATERIAL_ID = 0;
    };
public:
    class cShaderDataDamage : public cDDMaterialCtrl::cShaderData
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
        cShaderDataDamage();
        // Address: 0x01964280 - 0x01964281 (1 bytes)
        virtual ~cShaderDataDamage() {}
        virtual bool isSetCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 12
        virtual void setCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 9
        virtual void setCommonCB(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 19
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual u32 getMyShaderMode();  // vtable slot 20
        f32 getAlphaClipThreshold();
        f32 getBlendAlphaThreshold();
        f32 getBlendAlphaBand();
        f32 getAlbedoBlendRate();
        f32 getEmissionFactor();
        void setAlphaClipThreshold(f32 set);
        void setBlendAlphaThreshold(f32 set);
        void setBlendAlphaBand(f32 set);
        void setAlbedoBlendRate(f32 set);
        void setEmissionFactor(f32);
    private:
        f32 mAlphaClipThreshold;  // offset: 0x24
        f32 mBlendAlphaThreshold;  // offset: 0x28
        f32 mBlendAlphaBand;  // offset: 0x2c
        f32 mAlbedoBlendRate;  // offset: 0x30
        f32 mEmissionFactor;  // offset: 0x34
    public:
        static MyDTI DTI;
        static const u32 SHADER_TARGET_MATERIAL_MAX_NUM = 8;
        static const u32 SHADER_MATERIAL_ID_DEFAULT = 255;
    };
public:
    class cShaderDataDamageDrawOn : public cDDMaterialCtrl::cShaderDataDamage
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
        virtual u32 getMyShaderMode();  // vtable slot 20
    public:
        static MyDTI DTI;
    };
public:
    class cShaderDataDead : public cDDMaterialCtrl::cShaderDataDamage
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
        cShaderDataDead();
        // Address: 0x01964260 - 0x01964261 (1 bytes)
        virtual ~cShaderDataDead() {}
        virtual void init(uBaseModel* bm, cBakeModel* pBakeModel, cDDMaterialCtrl* pMaterialCtrl);  // vtable slot 6
        virtual void setCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 9
        virtual u32 getMyShaderMode();  // vtable slot 20
        virtual bool isEnd();  // vtable slot 10
    private:
        f32 mPassageFrame;  // offset: 0x38
        bool mIsEnd;  // offset: 0x3c
    public:
        static MyDTI DTI;
        static const f32 ALL_USE_FRAME;
        static const f32 BLACK_USE_FRAME;
        static const f32 ALPHA_USE_FRAME;
        static const f32 CLIP_USE_FRAME;
    };
public:
    class cShaderDataBloodStain : public cDDMaterialCtrl::cShaderDataDamage
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
        cShaderDataBloodStain();
        // Address: 0x01964250 - 0x01964251 (1 bytes)
        virtual ~cShaderDataBloodStain() {}
        bool isBloodStainMild(u32 MaterialId);
        bool isBloodStainStrong(u32 MaterialId);
        virtual u32 getMyShaderMode();  // vtable slot 20
        virtual void setCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 9
        virtual bool isSetCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 12
        virtual void requestPhase(u32 phase);  // vtable slot 21
    private:
        u32 mPhase;  // offset: 0x38
    public:
        static MyDTI DTI;
        static const u32 PARAM_NUM = 2;
        static const u32 PHASE_NUM = 4;
        static const u16 MATERIAL_BLOOD_ID_START = 100;
        static const u16 MATERIAL_BLOOD_ID_END = 199;
        static const u16 MATERIAL_BLOOD_MILD_ID_START = 100;
        static const u16 MATERIAL_BLOOD_MILD_ID_END = 109;
        static const u16 MATERIAL_CAUSED_LOSS_ID_START = 400;
        static const u16 MATERIAL_CAUSED_LOSS_ID_END = 499;
        static const u16 MATERIAL_BLOOD_MILD_ID_START2 = 500;
        static const u16 MATERIAL_BLOOD_MILD_ID_END2 = 509;
        static const u16 MATERIAL_BLOOD_STRONG_ID1 = 110;
        static const u16 MATERIAL_BLOOD_STRONG_ID2 = 510;
    };
public:
    class cShaderDataHakuryuStone : public cDDMaterialCtrl::cShaderDataBloodStain
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
        cShaderDataHakuryuStone();
        // Address: 0x01964240 - 0x01964241 (1 bytes)
        virtual ~cShaderDataHakuryuStone() {}
        virtual void setCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 9
        virtual u32 getMyShaderMode();  // vtable slot 20
        virtual bool isSetCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 12
        virtual void requestPhase(u32 phase);  // vtable slot 21
    public:
        static MyDTI DTI;
        static const u32 PARAM_NUM = 2;
        static const u32 PHASE_NUM = 4;
    };
public:
    class cShaderDataFireDamage : public cDDMaterialCtrl::cShaderDataDamage
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
        cShaderDataFireDamage();
        // Address: 0x01964230 - 0x01964231 (1 bytes)
        virtual ~cShaderDataFireDamage() {}
        virtual u32 getMyShaderMode();  // vtable slot 20
        virtual bool isSetCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 12
        void requestPhase(u32 phase);
    public:
        static MyDTI DTI;
        static const u32 PARAM_NUM = 2;
        static const u32 PHASE_NUM = 4;
    };
public:
    class cShaderDataMaterialEnchantFire : public cDDMaterialCtrl::cShaderDataMaterialEnchant
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
        virtual void setCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 9
    public:
        static MyDTI DTI;
    };
public:
    class cShaderDataSdl : public cDDMaterialCtrl::cShaderDataMaterial
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
        cShaderDataSdl();
        virtual ~cShaderDataSdl();
        virtual void init(uBaseModel* bm, cBakeModel* pBakeModel, cDDMaterialCtrl* pMaterialCtrl);  // vtable slot 6
        virtual void update();  // vtable slot 7
        virtual void setCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 9
        virtual bool isSetCommonState(cDDMaterialCtrl::TitleMaterial* pm, rModel* pBaseModel, const u32 index);  // vtable slot 12
        virtual void copy(cDDMaterialCtrl::cShaderData* sd);  // vtable slot 11
        u32 getTargetArrayPos(cDDMaterialCtrl::TitleMaterial* pm);
        void allDelete();
        bool getTargetMaterialAll();
        bool getTargetChildAll();
        bool getUVTransformEnable();
        MtVector2 getUVOffset1(u32 index);
        MtVector2 getUVOffset2(u32 index);
        MtVector2 getUVScale1(u32 index);
        MtVector2 getUVScale2(u32 index);
        void setTargetMaterialAll(bool set);
        void setTargetChildAll(bool set);
        void setUVTransformEnable(bool set);
        void setUVOffset1(MtVector2& set, u32 index);
        void setUVOffset2(MtVector2& set, u32 index);
        void setUVScale1(MtVector2& set, u32 index);
        void setUVScale2(MtVector2& set, u32 index);
        cDDMaterialCtrl::cShaderDataSdlData* getSdlData(u32 index);
        void setSdlData(cDDMaterialCtrl::cShaderDataSdlData* set, u32 index);
        u32 getSdlDataNum();
        void setSdlDataNum(u32 set);
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    private:
        bool mTargetMaterialAll;  // offset: 0x22
        bool mTargetChildAll;  // offset: 0x23
        bool mUVTransformEnable;  // offset: 0x24
        MtTypedArray<cDDMaterialCtrl::cShaderDataSdlData> mSdlData;  // offset: 0x28
    public:
        static MyDTI DTI;
    };
public:
    class cShaderDataMaterialEnchantCraftFire : public cDDMaterialCtrl::cShaderDataMaterialEnchantCraft
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
        cShaderDataMaterialEnchantCraftFire();
    public:
        static MyDTI DTI;
    };
public:
    class cShaderDataMaterialElementEnemyFire : public cDDMaterialCtrl::cShaderDataMaterialElementEnemy
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
        cShaderDataMaterialElementEnemyFire();
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
    cDDMaterialCtrl();
    virtual ~cDDMaterialCtrl();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void update();
    void setCommonState();
    void setCommonState(nDraw::Material* * pamaterial, const u32 num, rModel* pBaseModel);
    void setCommonState(nDraw::Material* pmaterial, rModel* pBaseModel, const u32 index);
    void setCacheNone();
    void setBaseShaderCommonState(TitleMaterial* pm, rModel* pBaseModel, const u32 index);
    void setShaderCommonState(TitleMaterial* pm, rModel* pBaseModel, const u32 index);
    void setClipCommonState(TitleMaterial* pm, rModel* pBaseModel, const u32 index);
    void setEmissionCommonState(TitleMaterial* pm, rModel* pBaseModel, const u32 index);
    void setTexBlendCommonState(TitleMaterial* pm, rModel* pBaseModel, const u32 index);
    void setOutlineCommonState(TitleMaterial* pm, rModel* pBaseModel, const u32 index);
    void setMaterialCommonState(TitleMaterial* pm, rModel* pBaseModel, const u32 index);
    void setAnimRetCommonState(TitleMaterial* pm, rModel* pBaseModel, const u32 index);
    void setAnimAdvCommonState(TitleMaterial* pm, rModel* pBaseModel, const u32 index);
    void setOldDataCommonState(TitleMaterial* pm, rModel* pBaseModel, const u32 index);
    void setControlEnable(u32 flag);
    u32 getControlEnable() const;
    void setBaseShaderMode(u32 mode);
    u32 getBaseShaderMode() const;
    void setShaderMode(u32 mode);
    u32 getShaderMode() const;
    void setClipMode(u32 mode);
    u32 getClipMode() const;
    void setEmissionMode(u32 mode);
    u32 getEmissionMode() const;
    void setTexBlendMode(u32 mode);
    u32 getTexBlendMode() const;
    void setOutlineMode(u32 mode);
    u32 getOutlineMode() const;
    void setOutlineModeFromSdl(u32 mode);
    void setMaterialMode(u32 mode);
    u32 getMaterialMode() const;
    void setDefaultMaterialMode(u32 set);
    void setOwnerModelKind(u32 set);
    void setDataMaterialDiffuseColor(const MtVector4& color);
    void setDataMaterialSpecularColor(const MtVector4& color);
    void resetDataMaterialDefaultColors();
    void getTargetModelArray(MtTypedArray<uDDOModel>* pTargetArray);
    void copyMode(uDDOModel* pObject, u32 mode);
    void copyModeToEquip(u32 mode);
    void copyDataToEquip(cShaderData* sd, u32 mode, u32 index);
    void setOwner(uBaseModel* pOwner);
    void setBakeModel(cBakeModel* pBakeModel);
    void init();
    void resetAllMode();
    cShaderData* getShaderData(u32 mode, u32 index);
    cShaderDataDamage* getDamageData();
    cShaderDataBloodStain* getBloodStainData();
    cShaderDataBloodStain* getHakuryuStoneData();
    cShaderDataFireDamage* getFireDamageData();
    cShaderDataDamage* getDeadData();
    cShaderDataOutline* getOutlineData();
    cShaderDataConstantMaterialColor* getConstantMaterialColor();
    cShaderDataMaterialAlchemyShell* getAlchemyShellData();
    cShaderDataMaterialToDefaultColor* getToDefaultData();
    cShaderDataAnimation* getAdvAnimData();
    cShaderDataAnimationToDefault* getRetAnimData();
    cShaderDataDamage* getBaseShaderData(u32 index);
    cShaderDataStatusAilments* getShaderData(u32 index);
    cShaderDataEmission* getEmissionData(u32 index);
    cShaderDataOutline* getOutlineData(u32 index);
    cShaderDataMaterial* getMaterialData(u32 index);
    void setBaseShaderData(cShaderDataDamage*, u32 index);
    void setShaderData(cShaderDataStatusAilments*, u32 index);
    void setEmissionData(cShaderDataEmission*, u32 index);
    void setOutlineData(cShaderDataOutline*, u32 index);
    void setMaterialData(cShaderDataMaterial*, u32 index);
    u32 getBaseShaderDataNum();
    u32 getShaderDataNum();
    u32 getEmissionDataNum();
    u32 getOutlineDataNum();
    u32 getMaterialDataNum();
    void setBaseShaderDataNum(u32 num);
    void setShaderDataNum(u32 num);
    void setEmissionDataNum(u32 num);
    void setOutlineDataNum(u32 num);
    void setMaterialDataNum(u32 num);
public:
    MtTypedArray<cShaderDataDamage> mBaseShaderData;  // offset: 0x8
    MtTypedArray<cShaderDataStatusAilments> mShaderData;  // offset: 0x28
    MtTypedArray<cShaderDataOutline> mOutlineData;  // offset: 0x48
    MtTypedArray<cShaderDataEmission> mEmissionData;  // offset: 0x68
    MtTypedArray<cShaderData> mClipData;  // offset: 0x88
    MtTypedArray<cShaderData> mTexBlendData;  // offset: 0xa8
    MtTypedArray<cShaderDataMaterial> mMaterialData;  // offset: 0xc8
    MtTypedArray<cShaderDataAnimation> mAnimAdvData;  // offset: 0xe8
    MtTypedArray<cShaderDataAnimationToDefault> mAnimRetData;  // offset: 0x108
    MtTypedArray<cShaderDataMaterialOldData> mOldData;  // offset: 0x128
    cShaderDataDamage mBaseShaderMode_DefaultDrawOff;  // offset: 0x148
    cShaderDataDamageDrawOn mBaseShaderMode_DefaultDrawOn;  // offset: 0x180
    cShaderDataDead mBaseShaderMode_BurnEM;  // offset: 0x1b8
    cShaderDataBloodStain mBaseShaderMode_BloodStain;  // offset: 0x1f8
    cShaderDataHakuryuStone mBaseShaderMode_HakuryuStone;  // offset: 0x238
    cShaderDataFireDamage mBaseShaderMode_FireDamage;  // offset: 0x278
    cShaderDataStatusAilments mShaderMode_ModeDefault;  // offset: 0x2b0
    cShaderDataFire mShaderMode_ModeFire;  // offset: 0x300
    cShaderDataFreeze mShaderMode_ModeFreeze;  // offset: 0x358
    cShaderDataGeneral mShaderMode_ModeGeneral;  // offset: 0x3a8
    cShaderDataWetOil mShaderMode_ModeWetOil;  // offset: 0x400
    cShaderDataStone mShaderMode_ModeStone;  // offset: 0x460
    cShaderDataGold mShaderMode_ModeGold;  // offset: 0x4b8
    cShaderDataErosion mShaderMode_ModeErosion;  // offset: 0x518
    cShaderDataOutline mOutlineMode_None;  // offset: 0x5a0
    cShaderDataOutlineOn mOutlineMode_Default;  // offset: 0x600
    cShaderDataOutlineOn mOutlineMode_Event;  // offset: 0x660
    cShaderDataEmission mEmissionMode_None;  // offset: 0x6c0
    cShaderDataEmissionEye mEmissionMode_Eye;  // offset: 0x740
    cShaderDataMaterialToDefaultColor mMaterialMode_Default;  // offset: 0x7c0
    cShaderDataMaterialColor mMaterialMode_Color;  // offset: 0x830
    cShaderDataMaterialDead mMaterialMode_Dead;  // offset: 0x890
    cShaderDataMaterialEnchantFire mMaterialMode_EnchantFire;  // offset: 0x8d0
    cShaderDataMaterialEnchantIce mMaterialMode_EnchantIce;  // offset: 0x950
    cShaderDataMaterialEnchantThunder mMaterialMode_EnchantThunder;  // offset: 0x9d0
    cShaderDataMaterialEnchantHoly mMaterialMode_EnchantHoly;  // offset: 0xa50
    cShaderDataMaterialEnchantDark mMaterialMode_EnchantDark;  // offset: 0xad0
    cShaderDataWaterColor mMaterialMode_WaterColor;  // offset: 0xb60
    cShaderDataConstantMaterialColor mMaterialMode_ConstantColor;  // offset: 0xba0
    cShaderDataMaterial mMaterialMode_NoUse_Animation;  // offset: 0xc00
    cShaderDataMaterial mMaterialMode_NoUse_AnimDefault;  // offset: 0xc28
    cShaderDataSdl mMaterialMode_SDL;  // offset: 0xc50
    cShaderDataMaterialEnchantCraftFire mMaterialMode_EnchantCraftFire;  // offset: 0xca0
    cShaderDataMaterialEnchantCraftIce mMaterialMode_EnchantCraftIce;  // offset: 0xd10
    cShaderDataMaterialEnchantCraftThunder mMaterialMode_EnchantCraftThunder;  // offset: 0xd80
    cShaderDataMaterialEnchantCraftHoly mMaterialMode_EnchantCraftHoly;  // offset: 0xdf0
    cShaderDataMaterialEnchantCraftDark mMaterialMode_EnchantCraftDark;  // offset: 0xe60
    cShaderDataMaterialAlchemyShell mMaterialMode_AlchemyShell;  // offset: 0xf00
    cShaderDataMaterialElementEnemyFire mMaterialMode_ElementEmFire;  // offset: 0xfa0
    cShaderDataMaterialElementEnemyIce mMaterialMode_ElementEmIce;  // offset: 0x1000
    cShaderDataMaterialElementEnemyThunder mMaterialMode_ElementEmThunder;  // offset: 0x1060
    cShaderDataMaterialElementEnemyHoly mMaterialMode_ElementEmHoly;  // offset: 0x10c0
    cShaderDataMaterialElementEnemyDark mMaterialMode_ElementEmDark;  // offset: 0x1120
    cShaderDataMaterialOmBlink mMaterialMode_OmBlink;  // offset: 0x1180
    cShaderDataAnimation mAnimAdvDataElement;  // offset: 0x11b0
    cShaderDataAnimationToDefault mAnimRetDataElement;  // offset: 0x11f8
    cShaderDataMaterialOldData mOldDataElement;  // offset: 0x1240
    u32 mControlEnable;  // offset: 0x1270
    u32 mBaseShaderMode;  // offset: 0x1274
    u32 mShaderMode;  // offset: 0x1278
    u32 mClipMode;  // offset: 0x127c
    u32 mEmissionMode;  // offset: 0x1280
    u32 mTexBlendMode;  // offset: 0x1284
    u32 mOutlineMode;  // offset: 0x1288
    u32 mMaterialMode;  // offset: 0x128c
    u32 mDefMaterialMode;  // offset: 0x1290
    u32 mOwnerModelKind;  // offset: 0x1294
    uBaseModel* mpOwner;  // offset: 0x1298
    cBakeModel* mpBakeModel;  // offset: 0x12a0
    static const SO_HANDLE outlineBlendType[4];
    static const SO_HANDLE outlineColorType[3];
    static const MtFloat3 outlineColorMaskType[3];
    static const MtFloat4 outlineBlendMaskType[4];
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cDDMaterialCtrl::cShaderData::cShaderData() {
    this->mIsCacheNone = false;
    this->mpMaterialCtrl = static_cast<cDDMaterialCtrl*>(nullptr);
    this->mpBakeModel = static_cast<cBakeModel*>(nullptr);
    this->mpOwner = static_cast<uBaseModel*>(nullptr);
}

// Inline, no code of its own: checked where it is inlined.
inline uBaseModel* cDDMaterialCtrl::cShaderData::getOwner() {
    return this->mpOwner;
}

// Inline, no code of its own: checked where it is inlined.
inline f32 cDDMaterialCtrl::cShaderDataStatusAilments::getApplicateA() {
    return this->mApplicateA;
}

// Inline, no code of its own: checked where it is inlined.
inline f32 cDDMaterialCtrl::cShaderDataStatusAilments::getFactorN() {
    return this->mFactorN;
}

// Inline, no code of its own: checked where it is inlined.
inline f32 cDDMaterialCtrl::cShaderDataStatusAilments::getFactorS() {
    return this->mFactorS;
}

// Inline, no code of its own: checked where it is inlined.
inline cDDMaterialCtrl::cShaderDataAnimation::cAnimData::cAnimData() {
    this->mAnimName[0] = static_cast<char>(0);
    this->mCostFrame = 60.0f;
    this->mStartFrame = 0.0f;
    this->mMaterialId = static_cast<u32>(0);
}
