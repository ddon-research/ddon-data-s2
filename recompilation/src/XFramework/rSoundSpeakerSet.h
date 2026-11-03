#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "cResource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
struct MtFloat3;
class MtMatrix;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtUI;
class MtVector3;
class MtVector4;
class rSoundDirectionalCurveXml;

// Declarations
class rSoundSpeakerSetXml;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class rSoundSpeakerSetXml : public cResource
{
public:
    enum COORDINATE
    {
        C_LISTENER = 0,
        C_WORLD = 1,
        C_LOCAL = 2,
        C_FIXED_ORIENTATION = 3,
    };
    enum SPEAKER_SETTING
    {
        SP_NONE = 0,
        SP_MONARAUL = 1,
        SP_STEREO = 2,
        SP_SURROUND = 3,
    };
public:
    class MyDTI;
    struct NativeData;
    struct SpeakerSet;
    struct Speaker;
    struct DirectionalCurve;
    struct DirectionalCurveElement;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct NativeData
    {
    public:
        u32 mSpeakerSetNum;  // offset: 0x0
        u32 mSpeakerNum;  // offset: 0x4
        u32 mDirectionalCurveNum;  // offset: 0x8
        u32 mDirectionalCurveElementNum;  // offset: 0xc
        rSoundSpeakerSetXml::SpeakerSet* mpSpeakerSets;  // offset: 0x10
        rSoundSpeakerSetXml::Speaker* mpSpeakers;  // offset: 0x18
        rSoundSpeakerSetXml::DirectionalCurve* mpDirectionalCurves;  // offset: 0x20
        rSoundSpeakerSetXml::DirectionalCurveElement* mpDirectionalCurveElements;  // offset: 0x28
    };
public:
    struct SpeakerSet
    {
    public:
        u32 mCoordinate;  // offset: 0x0
        u32 mSpeakerNum;  // offset: 0x4
        rSoundSpeakerSetXml::Speaker* mpSpeaker;  // offset: 0x8
    };
public:
    struct Speaker
    {
    public:
        MtFloat3 mPosition;  // offset: 0x0
        MtFloat3 mOrientation;  // offset: 0xc
        rSoundSpeakerSetXml::DirectionalCurve* mpDirectionalCurve;  // offset: 0x18
    };
public:
    struct DirectionalCurve
    {
    public:
        u32 mElementNum;  // offset: 0x0
        f32 mZeroRadianValue;  // offset: 0x4
        f32 mPiRadianValue;  // offset: 0x8
        rSoundSpeakerSetXml::DirectionalCurveElement* mpElement;  // offset: 0x10
    };
public:
    struct DirectionalCurveElement
    {
    public:
        f32 mAngle;  // offset: 0x0
        f32 mValue;  // offset: 0x4
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
    rSoundSpeakerSetXml();
    virtual ~rSoundSpeakerSetXml();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    u32 getCoordinate() const;
    void setCoordinate(u32 c);
    u32 getSpeakerSetting() const;
    void setSpeakerSetting(u32 s);
    MtVector3 getSpeakerPosition(u32 num) const;
    void setSpeakerPosition(u32 num, const MtVector3& pos);
    MtVector3 getSpeakerOrientation(u32 num) const;
    void setSpeakerOrientation(u32 num, const MtVector3& pos);
    rSoundDirectionalCurveXml* getDirectionalCurve(u32 num) const;
    void setDirectionalCurve(u32 num, rSoundDirectionalCurveXml* pCurve);
    u32 getSpeakerNum() const;
    static void build(NativeData* pData, const MtTypedArray<rSoundSpeakerSetXml>& speaker_set_list);
    static MtVector4 getPositionAndIntensity(void* pSpeakerSet, u32 spk_num, const MtMatrix& lmtx, const MtMatrix& smtx, const MtVector3& listenerPos);
private:
    static f32 getDirectionalIntensity(DirectionalCurve* pCurve, f32 cos_theta);
    static void buildDirectionalCurve(NativeData* pData, const MtTypedArray<rSoundDirectionalCurveXml>& curve_list);
    static void buildSpeakerSet(NativeData* pData, const MtTypedArray<rSoundDirectionalCurveXml>& curve_list, const MtTypedArray<rSoundSpeakerSetXml>& speaker_set_list);
private:
    u32 mCoordinate;  // offset: 0x70
    u32 mSpeakerSetting;  // offset: 0x74
    MtVector3 mSpeakerPosition[6];  // offset: 0x80
    MtVector3 mSpeakerOrientation[6];  // offset: 0xe0
    rSoundDirectionalCurveXml* mpDirectionalCurve[6];  // offset: 0x140
public:
    static const u32 mMaxSpeakerNum = 6;
    static MyDTI DTI;
};

inline void* rSoundSpeakerSetXml::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
