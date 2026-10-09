#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtColor.h"
#include "MtDTI.h"
#include "MtEaseCurve.h"
#include "MtMath.h"
#include "nDraw.h"
#include "nDrawResource.h"

// Forward declarations
class MtAllocator;
class MtColorF;
class MtDTI;
struct MtFloat2;
struct MtFloat3;
struct MtFloat4;
class MtHermiteCurve;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector2;
class MtVector4;
class cDraw;
namespace nDraw { class BlendState; }
namespace nDraw { class ConstantTable; }
namespace nDraw { class DepthStencilState; }
namespace nDraw { class MaterialStdEst; }
namespace nDraw { class RasterizerState; }
namespace nDraw { struct SHADER_STATE; }
namespace nDraw { class Texture; }

// Declarations
namespace nDraw { class Animation; }
namespace nDraw { class CBuffer; }
namespace nDraw { class CBufferSystem; }
namespace nDraw { class Material; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using u32 = unsigned int;
using SO_HANDLE = u32;
using SV_HANDLE = u32;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u8 = unsigned char;

namespace nDraw {
    class Animation : public nDraw::Resource
    {
    public:
        enum TYPE
        {
            TYPE_FLOAT = 0,
            TYPE_VECTOR = 1,
            TYPE_INT = 2,
            TYPE_TEX = 3,
            TYPE_LEGACY = 4,
            TYPE_SAMPLER = 5,
            TYPE_TEXCOORD = 6,
            TYPE_TEXCOORD2 = 7,
        };
        enum IP_TYPE
        {
            IP_CONSTANT = 0,
            IP_LINEAR = 1,
            IP_HERMITE = 2,
            IP_CTLINEAR = 3,
            IP_CTHERMITE = 4,
        };
        enum LEGACY_REPEAT_TYPE
        {
            LEGACY_REPEAT_DEFAULT = 0,
            LEGACY_REPEAT_MIRROR = 1,
            LEGACY_REPEAT_REVERSE = 2,
        };
    public:
        class MyDTI;
        struct ANIMATION_LIST;
        struct ANIMATION;
        struct PARAM;
        struct BUFSTATE;
        struct PARAM_TEX;
        struct KEY_TEX;
        struct KEY;
        struct PARAM_SAMPLER;
        struct KEY_SAMPLER;
        struct PARAM_INT;
        struct KEY_INT;
        struct PARAM_FLOAT;
        struct KEY_FLOAT;
        struct PARAM_VECTOR;
        struct KEY_VECTOR;
        struct PARAM_TEXCOORD;
        struct KEY_TEXCOORD;
        struct PARAM_LEGACY;
        struct LEGACY_ANIMATION;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        struct ANIMATION_LIST
        {
        public:
            u32 animation_num;  // offset: 0x0
            u32 padding;  // offset: 0x4
            nDraw::Animation::ANIMATION* animations[1];  // offset: 0x8
        };
    public:
        struct ANIMATION
        {
        public:
            u32 length;  // offset: 0x0
            u32 repeat : 1;  // offset: 0x4
            u32 run : 1;  // offset: 0x4
            u32 param_num : 16;  // offset: 0x4
            u32 cbuffer_num : 14;  // offset: 0x4
            SO_HANDLE* cbuffers;  // offset: 0x8
            u32 crc;  // offset: 0x10
            u32 padding;  // offset: 0x14
            nDraw::Animation::PARAM* params[1];  // offset: 0x18
        };
    public:
        struct PARAM
        {
        public:
            SO_HANDLE handle;  // offset: 0x0
            u32 type : 4;  // offset: 0x4
            u32 interpolate : 4;  // offset: 0x4
            u32 key_num : 24;  // offset: 0x4
        };
    public:
        struct BUFSTATE
        {
        public:
            u8* pbuf;  // offset: 0x0
            u32 bufsize;  // offset: 0x8
            u32 pt;  // offset: 0xc
        };
    public:
        struct KEY
        {
        public:
            u32 frame;  // offset: 0x0
        };
    public:
        struct KEY_SAMPLER : public nDraw::Animation::KEY
        {
        public:
            s32 value;  // offset: 0x4
        };
    public:
        struct KEY_INT : public nDraw::Animation::KEY
        {
        public:
            s32 value;  // offset: 0x4
        };
    public:
        struct KEY_FLOAT : public nDraw::Animation::KEY
        {
        public:
            f32 value;  // offset: 0x4
        };
    public:
        struct KEY_VECTOR : public nDraw::Animation::KEY
        {
        public:
            MtFloat4 value;  // offset: 0x4
        };
    public:
        struct KEY_TEXCOORD : public nDraw::Animation::KEY
        {
        public:
            MtFloat4 value;  // offset: 0x4
            f32 rad;  // offset: 0x14
        };
    public:
        struct LEGACY_ANIMATION
        {
        public:
            u32 curve_type : 4;  // offset: 0x0
            u32 repeat_type : 4;  // offset: 0x0
            u32 frame_count : 24;  // offset: 0x0
            f32 min_value;  // offset: 0x4
            f32 max_value;  // offset: 0x8
            f32 curve_param;  // offset: 0xc
            MtHermiteCurve curve;  // offset: 0x10
        };
    public:
        struct KEY_TEX : public nDraw::Animation::KEY
        {
        public:
            u32 padding;  // offset: 0x4
            nDraw::Texture* value;  // offset: 0x8
        };
    public:
        struct PARAM_SAMPLER : public nDraw::Animation::PARAM
        {
        public:
            nDraw::Animation::KEY_SAMPLER keys[1];  // offset: 0x8
        };
    public:
        struct PARAM_INT : public nDraw::Animation::PARAM
        {
        public:
            SV_HANDLE svhandle;  // offset: 0x8
            nDraw::Animation::KEY_INT keys[1];  // offset: 0xc
        };
    public:
        struct PARAM_FLOAT : public nDraw::Animation::PARAM
        {
        public:
            SV_HANDLE svhandle;  // offset: 0x8
            nDraw::Animation::KEY_FLOAT keys[1];  // offset: 0xc
        };
    public:
        struct PARAM_VECTOR : public nDraw::Animation::PARAM
        {
        public:
            SV_HANDLE svhandle;  // offset: 0x8
            nDraw::Animation::KEY_VECTOR keys[1];  // offset: 0xc
        };
    public:
        struct PARAM_TEXCOORD : public nDraw::Animation::PARAM
        {
        public:
            SV_HANDLE svhandle;  // offset: 0x8
            nDraw::Animation::KEY_TEXCOORD keys[1];  // offset: 0xc
        };
    public:
        struct PARAM_LEGACY : public nDraw::Animation::PARAM
        {
        public:
            SV_HANDLE svhandle;  // offset: 0x8
            nDraw::Animation::LEGACY_ANIMATION legacy[1];  // offset: 0xc
        };
    public:
        struct PARAM_TEX : public nDraw::Animation::PARAM
        {
        public:
            nDraw::Animation::KEY_TEX keys[1];  // offset: 0x8
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
        Animation(const ANIMATION_LIST* list);
        virtual ~Animation();
        s32 getNo(MT_CTSTR name) const;
        u32 getAnimationNum() const;
        u32 getAnimationLength(u32 no) const;
        const ANIMATION* getAnimation(u32 no) const;
        const ANIMATION_LIST* getAnimationList() const;
        u32 getAnimationListSize() const;
        ANIMATION_LIST* copyAnimationList(void* pdst, u32 dst_size, const ANIMATION_LIST* psrc);
    protected:
        u32 calcBufSize(const ANIMATION_LIST* list);
        void* allocBuf(BUFSTATE& bs, u32 size);
    protected:
        ANIMATION_LIST* mpList;  // offset: 0x18
        u32 mBufferSize;  // offset: 0x20
    public:
        static MyDTI DTI;
    };
}  // namespace nDraw

namespace nDraw {
    class CBuffer : public nDraw::Resource
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
        CBuffer(u32 tempSize);
        virtual ~CBuffer();
        void reset();
        void add(const SO_HANDLE handle);
        void generate();
        void setConstantTable(cDraw* pdraw);
        void setConstantTable(cDraw* pdraw, SO_HANDLE handle);
        void duplicate(SO_HANDLE handle, const nDraw::ConstantTable* src);
        void duplicateAll(SO_HANDLE handle, const nDraw::ConstantTable* src);
    private:
        u32 mHandleCount : 16;  // offset: 0x14
        u32 mTempCount : 16;  // offset: 0x14
        SO_HANDLE* mHandles;  // offset: 0x18
        void* * mppCBuffers[3];  // offset: 0x20
        static const u32 BUFFER_NUM = 3;
    public:
        static MyDTI DTI;
    };
}  // namespace nDraw

namespace nDraw {
    class CBufferSystem : public nDraw::Resource
    {
        // inferred: nDraw::Material::isCBuffer names nDraw::CBufferSystem::mAnimation
        friend class nDraw::Material;
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
        CBufferSystem(const nDraw::Animation* panm, SO_HANDLE* vdcb, u32 vdcb_num);
        virtual ~CBufferSystem();
        void duplicateAllAnim(SO_HANDLE handle, const nDraw::ConstantTable* src);
        void duplicateAllVD(SO_HANDLE handle, const nDraw::ConstantTable* src);
        void setConstantTableAnim(cDraw* pdraw, SO_HANDLE handle);
        void setConstantTableVD(cDraw* pdraw);
        void duplicateAnim(SO_HANDLE handle, const nDraw::ConstantTable* src);
        void duplicateVD(SO_HANDLE handle, const nDraw::ConstantTable* src);
        const nDraw::CBuffer* getAnimationCBuffer() const;
        const nDraw::CBuffer* getVertexDisplacementCBuffer() const;
    private:
        void generate(const nDraw::Animation* panm, SO_HANDLE* vdcb, u32 vdcb_num);
    private:
        nDraw::CBuffer* mAnimation;  // offset: 0x18
        nDraw::CBuffer* mVertexDisplacement;  // offset: 0x20
    public:
        static MyDTI DTI;
    };
}  // namespace nDraw

namespace nDraw {
    class Material : public nDraw::Resource
    {
        // inferred: nDraw::MaterialStdEst::MaterialStdEst names nDraw::Material::mTechnique
        friend class nDraw::MaterialStdEst;
    public:
        enum SLOT_TYPE
        {
            SLOT_0 = 0,
            SLOT_1 = 1,
            SLOT_2 = 2,
            SLOT_3 = 3,
            MAX_SLOT = 4,
        };
        enum STATE_TYPE
        {
            STATE_FUNCTION = 0,
            STATE_CBUFFER = 1,
            STATE_SAMPLER = 2,
            STATE_TEXTURE = 3,
            STATE_PROCEDURAL = 4,
        };
    public:
        class MyDTI;
        struct STATE;
        struct ANIMATION_STATE;
        struct PROCEDURAL_TEXTURE;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        struct STATE
        {
        public:
            u32 type : 4;  // offset: 0x0
            u32 group : 16;  // offset: 0x0
            u32 index : 12;  // offset: 0x0
            u32 padding;  // offset: 0x4
            nDraw::SHADER_STATE state;  // offset: 0x8
        };
    public:
        struct ANIMATION_STATE
        {
        public:
            s32 no : 16;  // offset: 0x0
            u32 state : 16;  // offset: 0x0
            f32 frame;  // offset: 0x4
        };
    public:
        struct PROCEDURAL_TEXTURE
        {
        public:
            nDraw::Texture* ptex;  // offset: 0x0
            u32 crc;  // offset: 0x8
            u32 pass : 16;  // offset: 0xc
            u32 state_num : 16;  // offset: 0xc
            nDraw::Material::STATE states[4];  // offset: 0x10
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
        Material(SO_HANDLE technique);
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual nDraw::Material* duplicate() const;  // vtable slot 7
        u32 getID();
        void setID(u32 id);
        SO_HANDLE getTechnique() const;
        virtual void update(f32 dt);  // vtable slot 8
        void setDrawPass(nDraw::PASS_TYPE drawpass);
        nDraw::PASS_TYPE getDrawPass() const;
        void setTechniqueState(cDraw* pdraw, u32 pass);
        void setStencilRef(u8 ref);
        u8 getStencilRef() const;
        u8 getAlphaTestRef() const;
        nDraw::COMPARISON_FUNC getAlphaTestFunc() const;
        bool isAlphaTestEnable() const;
        void setAlphaTest(bool enable, nDraw::COMPARISON_FUNC func, u8 ref);
        void setBlendState(SO_HANDLE state, const MtColorF& blendfactor);
        void setRasterizerState(SO_HANDLE state);
        void setDepthStencilState(SO_HANDLE state, u8 ref);
        void setFogEnable(bool v);
        bool isFogEnable() const;
        void setStateBuffer(const STATE* states, u32 state_num, u32 bufsize, bool maketable);
        STATE* getStateBuffer() const;
        u32 getStateNum() const;
        void resetAllAnimation();
        void setAnimationData(nDraw::Animation* panm);
        nDraw::Animation* getAnimationData() const;
        void setAnimation(SLOT_TYPE slot, s32 no);
        s32 getAnimation(SLOT_TYPE slot);
        void setFrame(SLOT_TYPE slot, f32 frame);
        f32 getFrame(SLOT_TYPE slot) const;
        void setSpeed(f32 v);
        f32 getSpeed() const;
        bool isCBuffer() const;
        nDraw::ConstantTable* getConstantBuffer(SO_HANDLE cbuffer) const;
        SO_HANDLE getFunction(SO_HANDLE handle) const;
        nDraw::Texture* getTexture(SO_HANDLE handle) const;
        u32 getTextures(nDraw::Texture* * pdst, u32 num);
        bool setFunction(SO_HANDLE handle, SO_HANDLE function);
        bool setTexture(SO_HANDLE handle, nDraw::Texture* ptex);
        bool setSamplerState(SO_HANDLE handle, SO_HANDLE sampler_handle);
        virtual void setBaseColor(const MtVector4& color);  // vtable slot 9
        virtual MtVector4 getBaseColor() const;  // vtable slot 10
        virtual void setBaseMap(nDraw::Texture* ptex);  // vtable slot 11
        virtual nDraw::Texture* getBaseMap() const;  // vtable slot 12
        void setBaseUVOffset(const MtVector2& v);
        MtVector2 getBaseUVOffset() const;
        void setBaseUVScale(const MtVector2& v);
        MtVector2 getBaseUVScale() const;
        virtual u32 setDrawState(cDraw* pdraw, nDraw::PASS_TYPE overrideDrawPass);  // vtable slot 13
        virtual bool beginDraw(cDraw* pdraw, u32 pass);  // vtable slot 14
        virtual void endDraw(cDraw* pdraw, u32 pass);  // vtable slot 15
        void setSelect(bool);
        bool isSelect();
        void setLayerID(u32 id);
        u32 getLayerID() const;
        void setDeferredLightingEnable(bool v);
        bool isDeferredLightingEnable() const;
        void setHalfLambertEnable(bool v);
        bool isHalfLambertEnable() const;
        void setTangentEnable(bool v);
        bool isTangentEnable() const;
        const nDraw::BlendState* getBlendState() const;
        const nDraw::RasterizerState* getRasterizerState() const;
        const nDraw::DepthStencilState* getDepthStencilState() const;
        // Address: 0x01a6c070 - 0x01a6c071 (1 bytes)
        virtual void updateStateBuffer() {}  // vtable slot 16
        bool isValid() const;
        void setScalarB(SV_HANDLE handle, bool v);
        void setScalarI(SV_HANDLE handle, s32 v);
        void setScalarF(SV_HANDLE handle, f32 v);
        void setVectorF(SV_HANDLE handle, const f32* v);
        bool getScalarB(SV_HANDLE handle) const;
        s32 getScalarI(SV_HANDLE handle) const;
        f32 getScalarF(SV_HANDLE handle) const;
        const MtFloat2& getVector2F(SV_HANDLE handle) const;
        const MtFloat3& getVector3F(SV_HANDLE handle) const;
        const MtVector4& getVector4F(SV_HANDLE handle) const;
        void duplicateAnimationCBuffer();
        void setLegacyAnimation(bool enabe);
    protected:
        void duplicateAnimationConstant(cDraw* pdraw);
        void applyAnimation(f32 dt);
        void setTechnique(SO_HANDLE handle);
        bool setOutlineState(cDraw* pdraw, nDraw::PASS_TYPE drawpass);
        bool setVelocityState(cDraw* pdraw, nDraw::PASS_TYPE drawpass);
        bool setShadowCastState(cDraw* pdraw, u32 group, nDraw::PASS_TYPE drawpass);
        bool setShadowRecvState(cDraw* pdraw, u32 group, nDraw::PASS_TYPE drawpass);
        void setDeferredShadowEnable(bool v);
        void releaseStateBuffer();
        virtual ~Material();
        virtual void setSamplerAnimation(SO_HANDLE handle, SO_HANDLE sampler_handle);  // vtable slot 17
        virtual void setIntAnimation(SO_HANDLE handle, SV_HANDLE svhandle, s32 value);  // vtable slot 18
        virtual void setFloatAnimation(SO_HANDLE handle, SV_HANDLE svhandle, f32 value);  // vtable slot 19
        virtual void setVectorAnimation(SO_HANDLE handle, SV_HANDLE svhandle, const MtVector4& value);  // vtable slot 20
        virtual void setTexcoordAnimation(SO_HANDLE handle, SV_HANDLE svhandle, const f32* value);  // vtable slot 21
        virtual void setTextureAnimation(SO_HANDLE handle, nDraw::Texture* ptex);  // vtable slot 22
        void setAlbedoAlpha(bool);
        void setAnimationCBuffer(cDraw* pdraw);
        bool isLegacyAnimation() const;
        virtual void setState(cDraw* pdraw);  // vtable slot 23
    private:
        STATE* searchState(STATE_TYPE state, SO_HANDLE handle) const;
        STATE* getState(STATE_TYPE state, u32 index) const;
        u32 getStateNum(STATE_TYPE state) const;
    private:
        SO_HANDLE mTechnique;  // offset: 0x14
        u32 mStencilRef : 8;  // offset: 0x18
        u32 mAlphaTestEnable : 1;  // offset: 0x18
        u32 mAlphaTestCmpFunc : 4;  // offset: 0x18
        u32 mAlphaTestRopTest : 1;  // offset: 0x18
        u32 mAlphaTestRef : 8;  // offset: 0x18
        u32 mSelect : 1;  // offset: 0x18
        u32 mLayerID : 2;  // offset: 0x18
        u32 mDeferredShadowEnable : 1;  // offset: 0x18
        u32 mDrawPass : 5;  // offset: 0x18
        u32 mFogEnable : 1;  // offset: 0x18
        u32 mStateNum : 9;  // offset: 0x1c
        u32 mAnimationNum : 9;  // offset: 0x1c
        u32 mProceduralTextureNum : 4;  // offset: 0x1c
        u32 mReserve_fId : 6;  // offset: 0x1c
        u32 mDeferredLighting : 1;  // offset: 0x1c
        u32 mAlbedoAlpha : 1;  // offset: 0x1c
        u32 mTangent : 1;  // offset: 0x1c
        u32 mHalfLambert : 1;  // offset: 0x1c
        u16 mID;  // offset: 0x20
        f32 mAnimationSpeed;  // offset: 0x24
        nDraw::BlendState* mpBlendState;  // offset: 0x28
        nDraw::RasterizerState* mpRasterizerState;  // offset: 0x30
        nDraw::DepthStencilState* mpDepthStencilState;  // offset: 0x38
        SO_HANDLE mBlendStateHandle;  // offset: 0x40
        STATE* mStates;  // offset: 0x48
        MtColorF mBlendFactor;  // offset: 0x50
        ANIMATION_STATE mAnimationState[4];  // offset: 0x60
        PROCEDURAL_TEXTURE* mProceduralTexture;  // offset: 0x80
        nDraw::Animation* mpAnimation;  // offset: 0x88
        nDraw::CBufferSystem* mpCBuffer;  // offset: 0x90
        bool mLegacyAnimation;  // offset: 0x98
        u32* mpStateAccessTable[4];  // offset: 0xa0
        u32 mStateAccessTableNum[4];  // offset: 0xc0
    public:
        static MyDTI DTI;
    };
}  // namespace nDraw
