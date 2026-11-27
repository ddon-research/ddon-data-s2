#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../../../../MT/MtCollisionUtil.h"

enum HPDErrCategory
{
    HPDE_None = 0,
    HPDE_Http = 1,
    HPDE_HttpDlNotAll = 2,
    HPDE_Cert = 3,
    HPDE_Hash = 4,
    HPDE_Disk = 5,
    HPDE_Empty = 6,
    HPDE_MkDir = 7,
    HPDE_RmDir = 8,
    HPDE_FOpen = 9,
    HPDE_FRead = 10,
    HPDE_FWrite = 11,
    HPDE_FCopy = 12,
    HPDE_FDelete = 13,
    HPDE_FSignature = 14,
    HPDE_FVersion = 15,
    HPDE_FContent = 16,
    HPDE_NoMem = 17,
    HPDE_FHash = 18,
    HPDE_Max = 19,
};

// Declarations
namespace MtCollisionUtil { template <typename type, bool _flag_class_mode, unsigned int _extend_buffer_over_mul> class MtArrayTemplateEx; }

// Type aliases from DWARF
using __int64_t = long int;
using f32 = float;
using s32 = int;
using s64 = __int64_t;
using u32 = unsigned int;

typedef struct
{
public:
    s32 lsrValid;  // offset: 0x0
    s32 lsrTimeLimit;  // offset: 0x4
    f32 lsrAveMbps;  // offset: 0x8
    u32 maxRtCount;  // offset: 0xc
} HTTPDL_RETRY_PARAMS;

typedef struct
{
public:
    s64 nsTimeAll;  // offset: 0x0
    s64 nsTime_1;  // offset: 0x8
    u32 cntLowSP;  // offset: 0x10
    u32 cntDLSP;  // offset: 0x14
    u32 cntTOUT;  // offset: 0x18
    u32 cntNALL;  // offset: 0x1c
    u32 cntELSE;  // offset: 0x20
    u32 cntNonSupport;  // offset: 0x24
    u32 nowSleeping;  // offset: 0x28
    f32 rate;  // offset: 0x2c
    u32 ipAdrs[8];  // offset: 0x30
} HTTPDL_RETRY_STATUS;

namespace MtCollisionUtil {
    template <typename type, bool _flag_class_mode, unsigned int _extend_buffer_over_mul>
    class MtArrayTemplateEx
    {
    public:
        MtArrayTemplateEx();
        virtual ~MtArrayTemplateEx();
        type& add(type& obj);
        type& add(const type& obj);
        u32 length() const;
        const type& at_const(u32 index) const;
        void clear();
        void erase(u32 index);
        type& operator[](u32 index);
        void reserve(u32 siz);
        const MtCollisionUtil::MtArrayTemplateEx<type, _flag_class_mode, _extend_buffer_over_mul>& copy(const MtCollisionUtil::MtArrayTemplateEx<type, _flag_class_mode, _extend_buffer_over_mul>& src);
        const MtCollisionUtil::MtArrayTemplateEx<type, _flag_class_mode, _extend_buffer_over_mul>& operator=(const MtCollisionUtil::MtArrayTemplateEx<type, _flag_class_mode, _extend_buffer_over_mul>& src);
        type& at(u32 index);
    public:
        MtCollisionUtil::MtArrayTemplate<type, _flag_class_mode, _extend_buffer_over_mul> mThis;  // offset: 0x8
    };
}  // namespace MtCollisionUtil

typedef struct
{
public:
    HTTPDL_RETRY_PARAMS param;  // offset: 0x0
    HTTPDL_RETRY_STATUS state;  // offset: 0x10
} HTTPDL_RETRY_INFO;
