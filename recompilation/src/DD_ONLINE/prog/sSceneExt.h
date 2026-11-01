#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../XFramework/sScene.h"

// Forward declarations
struct MT_ENUM;
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class rTexDetailEdit;

// Declarations
class sSceneExt;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s8 = signed char;
using size_t = _Sizet;
using u32 = unsigned int;

class sSceneExt : public sScene
{
public:
    enum TEX_DETAIL_TYPE
    {
        TEXDETAIL_EVENT = 0,
        TEXDETAIL_EVENT_SUB = 1,
        TEXDETAIL_FILE = 2,
        TEXDETAIL_STAGE = 3,
        TEXDETAIL_MAX_NUM = 4,
        TEXDETAIL_FORCE_DWORD = -1,
    };
public:
    class MyDTI;
    struct TexDetailPack;
    struct TexDetail;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct TexDetailPack
    {
    public:
        sSceneExt::TexDetail* mTable;  // offset: 0x0
        u32 num;  // offset: 0x8
    };
public:
    struct TexDetail
    {
    public:
        void setDetail(MT_CTSTR str, u32 form, s8 type, bool ignore_limit);
    public:
        MT_CHAR mPath[64];  // offset: 0x0
        u32 mForm;  // offset: 0x40
        u32 mType;  // offset: 0x44
        bool mIgnoreLimit;  // offset: 0x48
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
    sSceneExt(u32 max_pool);
    virtual ~sSceneExt();
    virtual const MT_ENUM* getLightGroupType();  // vtable slot 14
    virtual const MT_CTSTR* getLightGroupTips();  // vtable slot 15
    bool isValidLightGroup(u32 bitValue, u32* pOutput);
    MT_CTSTR getLightGroupNameByBitIndex(u32 bitShift);
    virtual u32 getTextureDetail(MT_CTSTR path);  // vtable slot 18
    void reloadTexture();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void move();  // vtable slot 7
    virtual u32 getTextureDetailMain(MT_CTSTR path);  // vtable slot 20
    virtual bool isTextureMipEnable(MT_CTSTR path);  // vtable slot 21
    void loadTxd();
    void loadTxd(rTexDetailEdit* pRes, TEX_DETAIL_TYPE mode);
    void loadTxd(MT_CTSTR name, TEX_DETAIL_TYPE mode);
    void reloadTxd();
    void releaseTxd(TEX_DETAIL_TYPE mode);
    void outputTexDetailInfomation();
private:
    void updateCorrectBloomThreshold();
private:
    TexDetailPack mDetail[4];  // offset: 0x1428
public:
    static MyDTI DTI;
};
