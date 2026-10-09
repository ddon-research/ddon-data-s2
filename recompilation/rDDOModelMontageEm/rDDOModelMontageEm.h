#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/cResource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtStream;
class MtVector3;
class uModel;

// Declarations
class rDDOModelMontageEm;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using s8 = signed char;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class rDDOModelMontageEm : public cResource
{
public:
    enum PARTS_DISP
    {
        PARTS_SET = 0,
        PARTS_ON = 1,
        PARTS_OFF = 2,
    };
public:
    class MyDTI;
    struct HEADER;
    struct PARTS;
    struct MONTAGE;
    struct COLOR_INFO;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct HEADER
    {
    public:
        u32 magic;  // offset: 0x0
        u32 version;  // offset: 0x4
        u32 parts_num;  // offset: 0x8
        u32 montage_num;  // offset: 0xc
        u32 montage_max;  // offset: 0x10
        u32 color_num;  // offset: 0x14
        u32 material_num;  // offset: 0x18
        rDDOModelMontageEm::PARTS* parts;  // offset: 0x20
        rDDOModelMontageEm::MONTAGE* * mindex;  // offset: 0x28
        rDDOModelMontageEm::MONTAGE* montage;  // offset: 0x30
        rDDOModelMontageEm::COLOR_INFO* cindex;  // offset: 0x38
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
        MtVector3 albedo;  // offset: 0x10
        u32 index;  // offset: 0x20
        u32 padding[3];  // offset: 0x24
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
    rDDOModelMontageEm();
    virtual ~rDDOModelMontageEm();
    virtual void clear();  // vtable slot 15
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    bool isValidMontage(u32 no);
    s32 applyRandom(uModel* pmod);
    virtual u32 applyMontage(uModel* pmod, u32 no, PARTS_DISP dispType, bool setColor);  // vtable slot 16
    virtual u32 applyMontageFirstSet(uModel* pmod, u32 no);  // vtable slot 17
    u32 getMontageNum();
    u32 getMontageMax();
protected:
    void applyCore(uModel* pmod, MONTAGE* pmtg, PARTS_DISP dispType, bool setColor);
protected:
    HEADER* mpHeader;  // offset: 0x70
public:
    static MyDTI DTI;
protected:
    static const u32 DATA_VERSION = 2;
};
