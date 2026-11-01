#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "cSystem.h"
#include "nDraw.h"
#include "nDrawInputLayout.h"
#include "nDrawShader.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataWriter;
class MtObject;
class MtPoint;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtString;
class MtUI;
class cArea;
namespace nDraw { class BlendState; }
namespace nDraw { struct CBUFFER; }
namespace nDraw { class DepthStencilState; }
namespace nDraw { struct FUNCTION; }
namespace nDraw { class InputLayout; }
namespace nDraw { struct InputLayouts; }
namespace nDraw { class Material; }
namespace nDraw { struct OBJECT; }
namespace nDraw { struct OBJECT_INFO; }
namespace nDraw { struct PASS; }
namespace nDraw { class RasterizerState; }
namespace nDraw { struct SAMPLER_STATE; }
namespace nDraw { struct SHADER; }
namespace nDraw { struct SHADER_CODE; }
namespace nDraw { struct SHADER_INPUT; }
namespace nDraw { struct SHADER_KEY; }
namespace nDraw { struct SHADER_PARAM; }
namespace nDraw { struct SHADER_PARAMINFO; }
namespace nDraw { struct SHADER_STATE; }
namespace nDraw { struct SQ_BASE; }
namespace nDraw { struct STRUCT; }
namespace nDraw { struct ST_EXPRESSION; }
namespace nDraw { struct ST_SWITCH; }
namespace nDraw { class SamplerState; }
namespace nDraw { struct VARIABLE; }
namespace nPS4 { class BufferObject; }
namespace nPS4 { class GeometryShaderObject; }
namespace nPS4 { class PixelShaderObject; }
namespace nPS4 { class VertexShaderObject; }
class rModel;
class rShader2;
class rShaderCache;
class rShaderPackage;

// Declarations
class sShader2;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_STR = MT_CHAR*;
using u32 = unsigned int;
using SO_HANDLE = u32;
using SV_HANDLE = u32;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
namespace nDraw { using HBlob = nPS4::BufferObject*; }
namespace nDraw { using HComputeShader = void*; }
namespace nDraw { using HDomainShader = void*; }
namespace nDraw { using HGeometryShader = nPS4::GeometryShaderObject*; }
namespace nDraw { using HHullShader = void*; }
namespace nDraw { using HInputLayout = nDraw::InputLayouts*; }
namespace nDraw { using HPixelShader = nPS4::PixelShaderObject*; }
namespace nDraw { using HVertexShader = nPS4::VertexShaderObject*; }
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u64 = __uint64_t;

class sShader2 : public cSystem
{
    friend class rModel;
public:
    enum PACK_MODE
    {
        PACK_NONE = 0,
        PACK_SEQUENTIAL = 1,
        PACK_LIMITATION = 2,
    };
    enum SHADER_CACHE_TYPE
    {
        SHADER_CACHE_UNUSED = 0,
        SHADER_CACHE_VS = 1,
        SHADER_CACHE_PS = 2,
        SHADER_CACHE_GS = 3,
        SHADER_CACHE_IA = 4,
        SHADER_CACHE_SS = 5,
        SHADER_CACHE_HS = 6,
        SHADER_CACHE_DS = 7,
        SHADER_CACHE_CS = 8,
    };
    enum SEMANTIC_STAGE
    {
        STAGE_VS_IN = 1,
        STAGE_VS_OUT = 2,
        STAGE_PS_IN = 4,
        STAGE_PS_OUT = 8,
        STAGE_GS_IN = 16,
        STAGE_GS_OUT = 32,
        STAGE_HS_IN = 64,
        STAGE_HS_OUT = 128,
        STAGE_DS_IN = 256,
        STAGE_DS_OUT = 512,
        STAGE_CS_IN = 1024,
        STAGE_CS_OUT = 2048,
    };
public:
    class MyDTI;
    struct SHADER_CACHE;
    struct SHADER_POOL;
    struct SHADER_QUERY;
    struct SEMANTIC_INFO;
    struct SHADER_REFERENCE;
    struct CONTEXT;
    struct INTERPOLATOR;
    struct ATTRIBUTE;
    struct OP_CAST;
    struct MICRO_CODE;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct SHADER_CACHE
    {
    public:
        union SHADER;
    public:
        union SHADER
        {
        public:
            nDraw::HVertexShader vs;  // offset: 0x0
            nDraw::HPixelShader ps;  // offset: 0x0
            nDraw::HGeometryShader gs;  // offset: 0x0
            nDraw::HHullShader hs;  // offset: 0x0
            nDraw::HDomainShader ds;  // offset: 0x0
            nDraw::HComputeShader cs;  // offset: 0x0
            nDraw::HInputLayout ia;  // offset: 0x0
            nDraw::SHADER* ss;  // offset: 0x0
        };
    public:
        SHADER pshader;  // offset: 0x0
        u32 type : 16;  // offset: 0x8
        u32 shared : 15;  // offset: 0x8
        u32 segment : 1;  // offset: 0x8
        u32 crc;  // offset: 0xc
    };
public:
    struct SHADER_POOL
    {
    public:
        nDraw::SHADER* pshader;  // offset: 0x0
        u32 type : 16;  // offset: 0x8
        u32 shared : 15;  // offset: 0x8
        u32 segment : 1;  // offset: 0x8
        u64 id;  // offset: 0x10
    };
public:
    struct SHADER_QUERY
    {
    public:
        rShaderCache* pcache;  // offset: 0x0
        nDraw::SHADER_KEY* pshaderkey;  // offset: 0x8
        u32 segmentation : 1;  // offset: 0x10
        u32 newshader : 1;  // offset: 0x10
    };
public:
    struct SEMANTIC_INFO
    {
    public:
        MT_CTSTR sname;  // offset: 0x0
        u32 stype;  // offset: 0x8
        u32 sindex;  // offset: 0xc
        u32 stage : 16;  // offset: 0x10
        u32 ctype : 8;  // offset: 0x10
        u32 dtype : 8;  // offset: 0x10
    };
public:
    struct SHADER_REFERENCE
    {
    public:
        u32 target_index;  // offset: 0x0
        nDraw::SHADER_STATE reference_state;  // offset: 0x8
    };
public:
    struct ATTRIBUTE
    {
    public:
        MT_CTSTR sname;  // offset: 0x0
        u32 sindex : 8;  // offset: 0x8
        u32 svalue : 4;  // offset: 0x8
        u32 offset : 6;  // offset: 0x8
        u32 start : 7;  // offset: 0x8
        u32 count : 6;  // offset: 0x8
        u32 usage : 1;  // offset: 0x8
    };
public:
    struct OP_CAST
    {
    public:
        bool benable;  // offset: 0x0
        u32 op_count;  // offset: 0x4
        u32 depth;  // offset: 0x8
        u32 stack[8];  // offset: 0xc
        static const u32 MAX_DEPTH = 8;
    };
public:
    struct MICRO_CODE
    {
    public:
        u32 op_num : 4;  // offset: 0x0
        u32 dest_reg : 5;  // offset: 0x0
        u32 dest_mask : 4;  // offset: 0x0
        u32 src0_reg : 5;  // offset: 0x0
        u32 src0_mask : 4;  // offset: 0x0
        u32 src1_reg : 5;  // offset: 0x0
        u32 src1_mask : 4;  // offset: 0x0
        u32 src2_reg : 5;  // offset: 0x4
        u32 src2_mask : 4;  // offset: 0x4
        u32 eoc : 1;  // offset: 0x4
        u32 scalar : 1;  // offset: 0x4
    };
public:
    struct INTERPOLATOR
    {
    public:
        sShader2::ATTRIBUTE attrs[32];  // offset: 0x0
        u32 attr_num;  // offset: 0x200
        u32 slot_num;  // offset: 0x204
    };
public:
    struct CONTEXT
    {
    public:
        MT_STR ptop;  // offset: 0x0
        MT_STR pdst;  // offset: 0x8
        MT_STR pend;  // offset: 0x10
        const nDraw::OBJECT* * pobjects;  // offset: 0x18
        const nDraw::SHADER_STATE* states;  // offset: 0x20
        const nDraw::OBJECT* poutputs[1024];  // offset: 0x28
        u32 output_num;  // offset: 0x2028
        u32 encode_targets;  // offset: 0x202c
        bool encode_srgb;  // offset: 0x2030
        nDraw::FEATURE_LV flv;  // offset: 0x2034
        const nDraw::STRUCT* phsinput;  // offset: 0x2038
        sShader2::INTERPOLATOR interpolator;  // offset: 0x2040
        nDraw::SQ_BASE sqbuf[4096];  // offset: 0x2248
        nDraw::SQ_BASE* sqstack[32];  // offset: 0x6248
        u32 sqnum[32];  // offset: 0x6348
        sShader2::OP_CAST cast;  // offset: 0x63c8
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
    sShader2(MT_CTSTR shader_path, bool isLoadRootShader, MT_CTSTR RootShaderName, MtStream* pMFXStream, MtStream* pRootStream);
    virtual ~sShader2();
    void setExtendShaderPackage(rShaderPackage* ppkg, u32 slot);
    void releaseSegmentShaderPackage();
    rShaderPackage* getExtendShaderPackage(u32);
    bool isDynamicShaderLoading();
    void setDynamicShaderLoading(bool v);
    bool isSRGBEnable();
    void setSRGBEnable(bool);
    bool getReferenceShaderEnable();
    u32 getShaderQueryNum();
    void writeShaderHandle(MtStream& out);
    virtual void move();  // vtable slot 7
    static sShader2* getInstance();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    rShader2* getShader();
    virtual nDraw::FEATURE_LV getFeatureLevel();  // vtable slot 10
    virtual MT_CTSTR getProfile(nDraw::FEATURE_LV flv);  // vtable slot 11
    virtual MT_CTSTR getReferenceShaderPrefix();  // vtable slot 12
    bool isReferenceFunction(SO_HANDLE handle);
    void overwriteTechnique(SO_HANDLE target, SO_HANDLE src);
    void overwriteFunction(SO_HANDLE target, SO_HANDLE src);
    u32 getShaderVersion();
    SO_HANDLE remapObjectHandle(SO_HANDLE handle) const;
    SO_HANDLE getObjectHandle(u32 index);
    const nDraw::SHADER* requestShader(SO_HANDLE technique, u32 tech_pass, const nDraw::SHADER_STATE* states, const SO_HANDLE* layouts, u32 encode_targets, SO_HANDLE dummy_technique);
    nDraw::InputLayout* getInputLayout(SO_HANDLE handle);
    nDraw::SamplerState* getSamplerState(SO_HANDLE handle);
    nDraw::BlendState* getBlendState(SO_HANDLE handle);
    nDraw::DepthStencilState* getDepthStencilState(SO_HANDLE handle);
    nDraw::RasterizerState* getRasterizerState(SO_HANDLE handle);
    const nDraw::OBJECT* getObject(SO_HANDLE handle);
    const nDraw::OBJECT_INFO* getObjectInfos();
    const nDraw::OBJECT_INFO* getObjectInfo(u32 index) const;
    const nDraw::OBJECT* * getObjects() const;
    u32 getObjectNum() const;
    const nDraw::SHADER_STATE* getDefaultStates();
    nDraw::Material* getNullMaterial();
    bool isGlobalHandle(SO_HANDLE handle);
protected:
    void reloadShaders();
    u32 calcShaderID(const nDraw::PASS* ppass, const nDraw::SHADER_STATE* states, const SO_HANDLE* layouts, u32 encode_targets, u32* phigh_id);
    void calcShaderVersion(const nDraw::SHADER_KEY* pskey, u32* hash, nDraw::FEATURE_LV flv);
    u32 calcObjectCRC(const nDraw::OBJECT* pobj, const nDraw::OBJECT* * pobjects, nDraw::FEATURE_LV flv);
    nDraw::HBlob compileShader(MT_STR phlsl, u32 len, nDraw::SHADER_TYPE shader_type, MT_CTSTR entrypoint);
    nDraw::HVertexShader createVertexShader(nDraw::SHADER_CODE* pshader, bool asEs);
    nDraw::HPixelShader createPixelShader(nDraw::SHADER_CODE* pshader);
    nDraw::HGeometryShader createGeometryShader(nDraw::SHADER_CODE* pshader);
    nDraw::HHullShader createHullShader(nDraw::SHADER_CODE* pshader);
    nDraw::HDomainShader createDomainShader(nDraw::SHADER_CODE* pshader);
    nDraw::HComputeShader createComputeShader(nDraw::SHADER_CODE* pshader);
    nDraw::HInputLayout createInputLayout(nDraw::SHADER_INPUT* pinput, nDraw::SHADER_CODE* pshader);
    bool convertToHLSL(nDraw::FEATURE_LV flv, MT_STR pdst, u32 max_dst, const nDraw::OBJECT* pobj, const nDraw::OBJECT* * pobjects);
    bool convertToHLSL(nDraw::FEATURE_LV flv, MT_STR pdst, u32 max_dst, const nDraw::VARIABLE* pval, const nDraw::OBJECT* * pobjects);
    bool convertToHLSL(nDraw::FEATURE_LV flv, MT_STR pdst, u32 max_dst, const nDraw::PASS* ppass, const nDraw::OBJECT* * pobjects);
    bool convertToHLSL(nDraw::FEATURE_LV flv, MT_STR pdst, u32 max_dst, const nDraw::SHADER_KEY* pskey);
    MtString convertToString(MT_CTSTR path, const nDraw::SHADER_KEY* pskey);
    nDraw::SHADER_KEY* convertFromString(MT_CTSTR str);
    bool verifyShaderKey(const nDraw::SHADER_KEY* pskey);
    void writeShaderKey(MtDataWriter& w, nDraw::SHADER_KEY* pskey);
    SO_HANDLE createObjectHandle(nDraw::OBJECT_TYPE type, MT_CTSTR name);
    SV_HANDLE createVariableHandle(MT_CTSTR name);
    const nDraw::SHADER* createShader(u64 id, nDraw::SHADER_CODE* pvshader, nDraw::SHADER_CODE* pgshader, nDraw::SHADER_CODE* ppshader, nDraw::SHADER_INPUT* pinput, nDraw::SHADER_CODE* phshader, nDraw::SHADER_CODE* pdshader, nDraw::SHADER_CODE* pcshader, bool segmentation);
    nDraw::SHADER_KEY* createShaderKey(u64 id, SO_HANDLE technique, u32 tech_pass, const nDraw::SHADER_STATE* states, const SO_HANDLE* layouts, u32 encode_targets);
    nDraw::SHADER_KEY* createReferenceShaderKey(const nDraw::SHADER_KEY* pskey);
    void createShaderObjectKey(SO_HANDLE handle, const nDraw::SHADER_STATE* states, nDraw::SHADER_KEY* pskey);
    void calcShaderObjectKey(SO_HANDLE handle, const nDraw::SHADER_STATE* states, u32& key_num);
    rShaderCache* createNewShaderCache(MT_CTSTR path, nDraw::SHADER_KEY* pskey, bool async);
    u32 createParam(nDraw::SHADER* pshader, nDraw::SHADER_CODE* pcode, nDraw::SHADER_PARAMINFO* pinfo, nDraw::SHADER_PARAM* params, nDraw::SHADER_TYPE shader_type);
    nDraw::HVertexShader addVertexShader(nDraw::SHADER_CODE* pshader, bool segmentation, bool asEs);
    nDraw::HPixelShader addPixelShader(nDraw::SHADER_CODE* pshader, bool segmentation);
    nDraw::HGeometryShader addGeometryShader(nDraw::SHADER_CODE* pshader, bool segmentation);
    nDraw::HHullShader addHullShader(nDraw::SHADER_CODE* pshader, bool segmentation);
    nDraw::HDomainShader addDomainShader(nDraw::SHADER_CODE* pshader, bool segmentation);
    nDraw::HComputeShader addComputeShader(nDraw::SHADER_CODE* pshader, bool segmentation);
    nDraw::HInputLayout addInputLayout(nDraw::SHADER_INPUT* pinput, nDraw::SHADER_CODE* pshader, bool segmentation);
    u32 addBindSampler(nDraw::SHADER* pshader, u32 index);
    u32 addBindTexture(nDraw::SHADER* pshader, u32 index);
    u32 addBindCBuffer(nDraw::SHADER* pshader, u32 index);
    u32* addShaderCRC(SO_HANDLE handle, const nDraw::SHADER_STATE* states, u32* pcrc);
    u32 calcShaderHash(u32* pbuf, u32 bytes, u32 hash);
    void castInc(CONTEXT* pcontext);
    void castDec(CONTEXT* pcontext);
    void castBegin(CONTEXT* pcontext);
    void castEnd(CONTEXT* pcontext);
    const nDraw::SHADER* getShader(u32 id);
    const nDraw::SHADER* getShader(u64 id);
    void queryShader(MT_CTSTR path, u64 id, SO_HANDLE technique, u32 tech_pass, const nDraw::SHADER_STATE* states, const SO_HANDLE* layouts, u32 encode_targets);
    void writeFetchDecode(CONTEXT* pcontext, u32 stream, const nDraw::InputLayout::FETCH_INFO& fi);
    u32 writeImmediateSequence(CONTEXT* pcontext, nDraw::SQ_BASE* pdst, nDraw::VARIABLE* pval, nDraw::SQ_BASE* pimmediate);
    u32 writeImmediateConstract(CONTEXT* pcontext, nDraw::SQ_BASE* pdst, nDraw::VARIABLE* pval, nDraw::SQ_BASE* pimmediate);
    void writeStatementAttribute(CONTEXT* pcontext, u32 scope, u32 type, u32 count);
    void writeTab(CONTEXT* pcontext, u32 n);
    void writeChar(CONTEXT* pcontext, MT_CHAR c);
    void writeString(CONTEXT* pcontext, MT_CTSTR str);
    void writeAttributes(CONTEXT* pcontext, u32 attr);
    void writeVariableType(CONTEXT* pcontext, nDraw::CLASS_TYPE ct, nDraw::DATA_TYPE dt, u32 col_num, u32 row_num);
    void writeVariableType(CONTEXT* pcontext, const nDraw::VARIABLE* pval);
    void writeVariable(CONTEXT* pcontext, const nDraw::VARIABLE* pval, const void* pinitvalues, bool static_const, MT_CTSTR packed_name);
    void writeObject(CONTEXT* pcontext, const nDraw::OBJECT* pobj, const nDraw::SHADER_STATE* pstate);
    void writeStaticCBuffer(CONTEXT* pcontext, const nDraw::CBUFFER* pcbuf, const void* pdata);
    void writeStateObject(CONTEXT* pcontext, const nDraw::OBJECT* pobj);
    void writeStatement(CONTEXT* pcontext, u32 scope, const nDraw::FUNCTION* pfunc, const void* pstt);
    void writeSwitchStatement(CONTEXT* pcontext, u32 scope, const nDraw::FUNCTION* pfunc, const nDraw::ST_SWITCH* pst);
    void writeSequence(CONTEXT* pcontext, const nDraw::FUNCTION* pfunc, const nDraw::SQ_BASE* pbase);
    void parseExpression(CONTEXT* pcontext, const nDraw::FUNCTION* pfunc, const nDraw::ST_EXPRESSION* pexp);
    void writeExpression(CONTEXT* pcontext, const nDraw::FUNCTION* pfunc, const nDraw::ST_EXPRESSION* pexp);
    void writeInitValue(CONTEXT* pcontext, const u32* pinitvalues, const nDraw::VARIABLE* pval);
    void writeInputValue(CONTEXT* pcontext, const u32* pinitvalues, const nDraw::VARIABLE* pval, const SO_HANDLE* layouts);
    void writeInterpolateOut(CONTEXT* pcontext, const nDraw::VARIABLE* pval, const INTERPOLATOR* pip);
    void writeInterpolateOut2(CONTEXT* pcontext, const nDraw::VARIABLE* pval, const INTERPOLATOR* pip);
    void writePacked(CONTEXT* pcontext, const nDraw::VARIABLE* pval, bool subscript, MT_CTSTR packed_name);
    bool isPacked(const nDraw::VARIABLE* pval);
    void writeInputLayout(CONTEXT* pcontext, const SO_HANDLE* layouts);
    void writeVertexShader(CONTEXT* pcontext, const nDraw::FUNCTION* pfunc, const INTERPOLATOR* pip, const SO_HANDLE* layouts);
    void writePixelShader(CONTEXT* pcontext, const nDraw::FUNCTION* pfunc, const INTERPOLATOR* pip);
    void writeHullShader(CONTEXT* pcontext, const nDraw::FUNCTION* pfunc);
    void writeSamplerState(CONTEXT* pcontext, const nDraw::SAMPLER_STATE* pss);
    void writeSystemValue(CONTEXT* pcontext, const nDraw::VARIABLE* pval);
    void writeInterpolator(CONTEXT* pcontext, const INTERPOLATOR* pip);
    void writeInterpolateIn(CONTEXT* pcontext, const u32* pinitvalues, const nDraw::VARIABLE* pval, const INTERPOLATOR* pip, MT_CTSTR sname, u32 sindex, u32 soffset);
    bool writeInterpolateOutElement(CONTEXT* pcontext, const nDraw::VARIABLE* pval, MT_CTSTR sname, u32 sindex, u32 element_index);
    void writeImmediateValue(CONTEXT* pcontext, const u32* pinitvalues, const nDraw::VARIABLE* pval, u32 offset);
    bool writeOutputTarget(CONTEXT* pcontext, const nDraw::VARIABLE* pval, s32 target_index);
    void writeShaderAttributes(CONTEXT* pcontext, const nDraw::FUNCTION* pfunc);
    void addOutputObjects(CONTEXT* pcontext, const nDraw::OBJECT* pobj);
    void initObjectTable();
    bool isExistHandle(nDraw::SHADER_KEY* pskey, SO_HANDLE handle);
    bool createInterpolator(CONTEXT* pcontext, const nDraw::PASS* ppass, INTERPOLATOR* pip);
    u32 createAttributes(CONTEXT* pcontext, const nDraw::VARIABLE* pval, ATTRIBUTE* attr);
    void setUsageAttributes(CONTEXT* pcontext, const nDraw::VARIABLE* pval, INTERPOLATOR* pip);
    u32* addOutputObjectsCRC(CONTEXT* pcontext, const nDraw::OBJECT* pobj, u32* pcrc);
    void replaceStatement(void* pstt, SO_HANDLE target, SO_HANDLE src);
    void changeShaderSegment(cArea* parea);
    u32 packAttributes(INTERPOLATOR* pip, PACK_MODE mode);
    MtPoint getInterpolateLocate(const INTERPOLATOR* pip, MT_CTSTR sname, u32 sindex, u32 index);
    void getShaderCachePath(MT_STR path, MT_CTSTR segment, u64 id);
    MICRO_CODE nextMicroCode(MT_CTSTR& mc);
    void initShader(rShader2* pshader);
    void traceErrorLine(MT_STR error, MT_STR hlsl);
    rShaderPackage* loadShaderPackage(MT_CTSTR segment, MtStream* p_stream);
    void writeText(MtStream& out, MT_CTSTR format, ...);
    void freeShaderCache(SHADER_CACHE* pcache);
    void replaceReferenceShader(const nDraw::SHADER_STATE* states, nDraw::SHADER_STATE* p_backup);
    void restoreReferenceShader(const nDraw::SHADER_STATE* states, nDraw::SHADER_STATE* p_backup);
    void onUpdateShaderPackage();
    void registerConflictInfo(u32 sid);
    void setRootShaderName(MT_CTSTR);
    MT_CTSTR getRootShaderName();
protected:
    rShader2* mpShader;  // offset: 0x18
    const nDraw::OBJECT* * mpObjects;  // offset: 0x20
    nDraw::OBJECT_INFO* mObjectInfos;  // offset: 0x28
    u32* mpRemapObjectHandleSearchAccessTable;  // offset: 0x30
    u16* mObjectIndices;  // offset: 0x38
    u32 mObjectNum;  // offset: 0x40
    bool mUpdateObjectTable;  // offset: 0x44
    bool mDynamicShaderLoading;  // offset: 0x45
    nDraw::SHADER_STATE mShaderStates[4096];  // offset: 0x48
    SHADER_CACHE mCaches[8192];  // offset: 0x10048
    SHADER_POOL mShaders[24576];  // offset: 0x30048
    u32 mCacheNum;  // offset: 0xc0048
    u32 mShaderNum;  // offset: 0xc004c
    u32 mShaderVersion;  // offset: 0xc0050
    SHADER_QUERY mShaderQuery[1024];  // offset: 0xc0058
    u32 mShaderQueryReadPt;  // offset: 0xc6058
    u32 mShaderQueryWritePt;  // offset: 0xc605c
    nDraw::Material* mpNullMaterial;  // offset: 0xc6060
    SO_HANDLE mEncodeFunctionTable[16];  // offset: 0xc6068
    u32 mReferenceFunctionNum;  // offset: 0xc60a8
    SHADER_REFERENCE mReferenceFunction[8];  // offset: 0xc60b0
    bool mTraceHLSLCode;  // offset: 0xc6170
    bool mTracePreHLSLCode;  // offset: 0xc6171
    bool mTracePreAssemblyCode;  // offset: 0xc6172
    bool mSRGBEnable;  // offset: 0xc6173
    bool mUseReferenceShader;  // offset: 0xc6174
    rShaderPackage* mpRootShaderPackage;  // offset: 0xc6178
    rShaderPackage* mpSegmentShaderPackage;  // offset: 0xc6180
    rShaderPackage* mpExtendShaderPackage[4];  // offset: 0xc6188
    MT_CHAR mCurrentSegment[1024];  // offset: 0xc61a8
    u32 mConflictSID[1024];  // offset: 0xc65a8
    u32 mConflictSIDNum;  // offset: 0xc75a8
    u32 mDuplicatedShader;  // offset: 0xc75ac
    u32 FORCE_DEFAULTPARAMETER_NONE;  // offset: 0xc75b0
    MT_CTSTR mRootShaderName;  // offset: 0xc75b8
public:
    static const u32 HLSL_CODESIZE = 131072;
    static MyDTI DTI;
protected:
    static const u32 MAX_OUTPUT_OBJECTS = 1024;
    static const u32 MAX_SQBUF = 4096;
    static const u32 MAX_SQSTACK = 32;
    static sShader2* mpInstance;
    static const u32 MAX_SHADER_POOL = 24576;
    static const u32 MAX_SHADER_CACHE = 8192;
    static const u32 MAX_SHADER_STACK = 16;
    static const u32 MAX_SHADER_QUERY = 1024;
    static const SEMANTIC_INFO mPSSemantic[];
    static const SEMANTIC_INFO mPSSysSemantic[];
    static const u32 MAX_EXTEND_PACKAGE = 4;
    static const u32 MAX_CONFLICT_SID = 1024;
};
