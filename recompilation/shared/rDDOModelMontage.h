#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "cResource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtStream;
class MtVector3;
class MtVector4;
class cBakeModel;
class uModel;

// Declarations
class rDDOModelMontage;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using s8 = signed char;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class rDDOModelMontage : public cResource
{
public:
    enum MODEL_TYPE
    {
        MODEL_TYPE_AH = 0,
        MODEL_TYPE_AB = 1,
        MODEL_TYPE_AL = 2,
        MODEL_TYPE_AA = 3,
        MODEL_TYPE_WB = 4,
        MODEL_TYPE_WL = 5,
        MODEL_TYPE_AC = 6,
        MODEL_TYPE_AO = 7,
        MODEL_TYPE_WP = 8,
        MODEL_TYPE_NP = 9,
        MODEL_TYPE_OTHER = 10,
        MODEL_TYPE_NUM = 11,
    };
    enum PL_PARTS
    {
        PL_PARTS_MUSTACHE_OUT = 0,
        PL_PARTS_MUSTACHE_IN = 1,
        PL_PARTS_HAIR = 2,
        PL_PARTS_FACE = 3,
        PL_PARTS_HEAD = 4,
        PL_PARTS_EAR = 5,
        PL_PARTS_NECK = 6,
        PL_PARTS_COLLAR = 7,
        PL_PARTS_BODY = 8,
        PL_PARTS_ARM = 9,
        PL_PARTS_HAND = 10,
        PL_PARTS_SOULDER_PAD = 11,
        PL_PARTS_SOULDER_PLATE = 12,
        PL_PARTS_EXCEPT_WB_HAND = 13,
        PL_PARTS_WB_HAND = 14,
        PL_PARTS_WAIST = 15,
        PL_PARTS_LEG = 16,
        PL_PARTS_FOOT = 17,
        PL_PARTS_EXCEPT_WL_FOOT = 18,
        PL_PARTS_WL_FOOT = 19,
        PL_PARTS_AA_HAND = 20,
        PL_PARTS_NUM = 21,
    };
    enum SE_TYPE
    {
        SE_TYPE_NONE = 0,
        SE_TYPE_CLOTH_HEAVY = 1,
        SE_TYPE_CLOTH_LIGHT = 2,
        SE_TYPE_METAL_HEAVY = 3,
        SE_TYPE_METAL_LIGHT = 4,
        SE_TYPE_LEATHER_HEAVY = 5,
        SE_TYPE_LEATHER_LIGHT = 6,
        SE_TYPE_SPECIAL = 7,
        SE_TYPE_NUM = 8,
    };
public:
    class MyDTI;
    struct HEADER;
    struct OTHER_INFO;
    struct PARTS;
    struct MONTAGE;
    struct COLOR_INFO;
    struct HIDE_INFO;
    struct SE_INFO;
    struct BODY_INFO;
    struct EXPRESSION_INFO;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct OTHER_INFO
    {
    public:
        u32 swing : 1;  // offset: 0x0
        u32 dummy : 31;  // offset: 0x0
    };
public:
    struct PARTS
    {
    public:
        u16 no;  // offset: 0x0
        u16 type;  // offset: 0x2
        u32 group;  // offset: 0x4
        u32 flg;  // offset: 0x8
    };
public:
    struct MONTAGE
    {
    public:
        u32 kind[8];  // offset: 0x0
        u32 id;  // offset: 0x20
        s8 modelColor;  // offset: 0x24
        s8 dummy[3];  // offset: 0x25
    };
public:
    struct COLOR_INFO
    {
    public:
        MtVector3 specular;  // offset: 0x0
        MtVector3 reflective;  // offset: 0x10
        MtVector4 colormask1;  // offset: 0x20
        MtVector4 colormask2;  // offset: 0x30
        MtVector4 colormask3;  // offset: 0x40
        u32 index;  // offset: 0x50
        u32 padding[3];  // offset: 0x54
    };
public:
    struct HIDE_INFO
    {
    public:
        u32 mustacheOut : 1;  // offset: 0x0
        u32 mustacheIn : 1;  // offset: 0x0
        u32 hair : 1;  // offset: 0x0
        u32 face : 1;  // offset: 0x0
        u32 head : 1;  // offset: 0x0
        u32 ear : 1;  // offset: 0x0
        u32 neck : 1;  // offset: 0x0
        u32 collar : 1;  // offset: 0x0
        u32 body : 1;  // offset: 0x0
        u32 arm : 1;  // offset: 0x0
        u32 hand : 1;  // offset: 0x0
        u32 shoulderPad : 1;  // offset: 0x0
        u32 shoulderPlate : 1;  // offset: 0x0
        u32 exceptWBHand : 1;  // offset: 0x0
        u32 WBHand : 1;  // offset: 0x0
        u32 waist : 1;  // offset: 0x0
        u32 leg : 1;  // offset: 0x0
        u32 foot : 1;  // offset: 0x0
        u32 exceptWLFoot : 1;  // offset: 0x0
        u32 WLFoot : 1;  // offset: 0x0
        u32 dummy : 12;  // offset: 0x0
    };
public:
    struct SE_INFO
    {
    public:
        u8 soundType;  // offset: 0x0
    };
public:
    struct BODY_INFO
    {
    public:
        u8 shakeBust : 1;  // offset: 0x0
        u8 dummy : 7;  // offset: 0x0
    };
public:
    struct EXPRESSION_INFO
    {
    public:
        u8 playExpression : 1;  // offset: 0x0
        u8 dummy : 7;  // offset: 0x0
    };
public:
    struct HEADER
    {
    public:
        u32 magic;  // offset: 0x0
        u32 version;  // offset: 0x4
        u32 modelType;  // offset: 0x8
        u32 parts_num;  // offset: 0xc
        u32 montage_num;  // offset: 0x10
        u32 montage_max;  // offset: 0x14
        u32 color_num;  // offset: 0x18
        u32 material_num;  // offset: 0x1c
        rDDOModelMontage::OTHER_INFO other;  // offset: 0x20
        rDDOModelMontage::PARTS* parts;  // offset: 0x28
        rDDOModelMontage::MONTAGE* * mindex;  // offset: 0x30
        rDDOModelMontage::MONTAGE* montage;  // offset: 0x38
        rDDOModelMontage::COLOR_INFO* color;  // offset: 0x40
        rDDOModelMontage::HIDE_INFO* hide;  // offset: 0x48
        rDDOModelMontage::SE_INFO* se;  // offset: 0x50
        rDDOModelMontage::BODY_INFO* body;  // offset: 0x58
        rDDOModelMontage::EXPRESSION_INFO* expression;  // offset: 0x60
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
    rDDOModelMontage();
    virtual ~rDDOModelMontage();
    virtual void clear();  // vtable slot 15
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    u32 applyMontage(uModel* pmod, u32 no);
    s32 applyRandom(uModel* pmod);
    bool isModelTypeNP(u32 no);
    virtual u32 applyParts(uModel* pmod, u32 no);  // vtable slot 16
    virtual u32 applyPartsBJ(uModel* pmod, u32 no);  // vtable slot 17
    virtual u32 applyColor(uModel* pmod, u32 no, bool compel);  // vtable slot 18
    virtual u32 applyColorBJ(cBakeModel* pBakeModel, u32 no, bool compel);  // vtable slot 19
    virtual u32 applyColorBJ_NPC(cBakeModel* pBakeModel, u32 no);  // vtable slot 20
    u32 getMontageNum();
    u32 getMontageMax();
    u32 getModelType();
    bool isSwing();
    bool isBodyShakeBust(u32 no);
    bool isHideMustacheOut(u32 no);
    bool isHideMustacheIn(u32 no);
    bool isHideHair(u32 no);
    bool isHideFace(u32 no);
    bool isHideHead(u32 no);
    bool isHideEar(u32 no);
    bool isHideNeck(u32 no);
    bool isHideCollar(u32 no);
    bool isHideBody(u32 no);
    bool isHideArm(u32 no);
    bool isHideHand(u32 no);
    bool isHideShoulderPad(u32 no);
    bool isHideShoulderPlate(u32 no);
    bool isHideExceptWBHand(u32 no);
    bool isHideWBHand(u32 no);
    bool isHideWaist(u32 no);
    bool isHideLeg(u32 no);
    bool isHideFoot(u32 no);
    bool isHideExceptWLFoot(u32 no);
    bool isHideWLFoot(u32 no);
    u32 getHideInfo(u32 no);
    bool isPlayExpression(u32 no);
    u8 getSeType(u32 no);
protected:
    void applyCoreParts(uModel* pmod, MONTAGE* pmtg);
    void applyCoreColor(uModel* pmod, COLOR_INFO* pInfo);
    void applyCoreColorBJ(cBakeModel* pBakeModel, COLOR_INFO* pInfo);
protected:
    HEADER* mpHeader;  // offset: 0x70
public:
    static MyDTI DTI;
protected:
    static const u32 DATA_VERSION = 10;
};
