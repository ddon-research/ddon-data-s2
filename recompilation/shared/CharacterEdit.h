#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cPacket.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;

// Declarations
class CDataEditInfo;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class CDataEditInfo : public CPacketDataBase
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
    explicit CDataEditInfo();
    explicit CDataEditInfo(u8, u8, u16, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16, u16);
public:
    u8 m_ucSex;  // offset: 0x8
    u8 m_ucVoice;  // offset: 0x9
    u16 m_usVoicePitch;  // offset: 0xa
    u8 m_ucPersonality;  // offset: 0xc
    u8 m_ucSpeechFreq;  // offset: 0xd
    u8 m_ucBodyType;  // offset: 0xe
    u8 m_ucHair;  // offset: 0xf
    u8 m_ucBeard;  // offset: 0x10
    u8 m_ucMakeup;  // offset: 0x11
    u8 m_ucScar;  // offset: 0x12
    u8 m_ucEyePresetNo;  // offset: 0x13
    u8 m_ucNosePresetNo;  // offset: 0x14
    u8 m_ucMouthPresetNo;  // offset: 0x15
    u8 m_ucEyebrowTexNo;  // offset: 0x16
    u8 m_ucColorSkin;  // offset: 0x17
    u8 m_ucColorHair;  // offset: 0x18
    u8 m_ucColorBeard;  // offset: 0x19
    u8 m_ucColorEyebrow;  // offset: 0x1a
    u8 m_ucColorREye;  // offset: 0x1b
    u8 m_ucColorLEye;  // offset: 0x1c
    u8 m_ucColorMakeup;  // offset: 0x1d
    u16 m_usSokutobu;  // offset: 0x1e
    u16 m_usHitai;  // offset: 0x20
    u16 m_usMimiJyouge;  // offset: 0x22
    u16 m_usKannkaku;  // offset: 0x24
    u16 m_usMabisasiJyouge;  // offset: 0x26
    u16 m_usHanakuchiJyouge;  // offset: 0x28
    u16 m_usAgoSakiHaba;  // offset: 0x2a
    u16 m_usAgoZengo;  // offset: 0x2c
    u16 m_usAgoSakiJyouge;  // offset: 0x2e
    u16 m_usHitomiOokisa;  // offset: 0x30
    u16 m_usMeOokisa;  // offset: 0x32
    u16 m_usMeKaiten;  // offset: 0x34
    u16 m_usMayuKaiten;  // offset: 0x36
    u16 m_usMimiOokisa;  // offset: 0x38
    u16 m_usMimiMuki;  // offset: 0x3a
    u16 m_usElfMimi;  // offset: 0x3c
    u16 m_usMikenTakasa;  // offset: 0x3e
    u16 m_usMikenHaba;  // offset: 0x40
    u16 m_usHohoboneRyou;  // offset: 0x42
    u16 m_usHohoboneJyouge;  // offset: 0x44
    u16 m_usHohoniku;  // offset: 0x46
    u16 m_usErahoneJyouge;  // offset: 0x48
    u16 m_usErahoneHaba;  // offset: 0x4a
    u16 m_usHanaJyouge;  // offset: 0x4c
    u16 m_usHanaHaba;  // offset: 0x4e
    u16 m_usHanaTakasa;  // offset: 0x50
    u16 m_usHanaKakudo;  // offset: 0x52
    u16 m_usKuchiHaba;  // offset: 0x54
    u16 m_usKuchiAtsusa;  // offset: 0x56
    u16 m_usEyebrowUVOffsetX;  // offset: 0x58
    u16 m_usEyebrowUVOffsetY;  // offset: 0x5a
    u16 m_usWrinkle;  // offset: 0x5c
    u16 m_usWrinkleAlbedoBlendRate;  // offset: 0x5e
    u16 m_usWrinkleDetailNormalPower;  // offset: 0x60
    u16 m_usMuscleAlbedoBlendRate;  // offset: 0x62
    u16 m_usMuscleDetailNormalPower;  // offset: 0x64
    u16 m_usHeight;  // offset: 0x66
    u16 m_usHeadSize;  // offset: 0x68
    u16 m_usNeckOffset;  // offset: 0x6a
    u16 m_usNeckScale;  // offset: 0x6c
    u16 m_usUpperBodyScaleX;  // offset: 0x6e
    u16 m_usBellySize;  // offset: 0x70
    u16 m_usTeatScale;  // offset: 0x72
    u16 m_usTekubiSize;  // offset: 0x74
    u16 m_usKoshiOffset;  // offset: 0x76
    u16 m_usKoshiSize;  // offset: 0x78
    u16 m_usAnkleOffset;  // offset: 0x7a
    u16 m_usFat;  // offset: 0x7c
    u16 m_usMuscle;  // offset: 0x7e
    u16 m_usMotionFilter;  // offset: 0x80
    static MyDTI DTI;
};
