#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "MtString.h"
#include "cAreaHit.h"
#include "rStageCustomParts.h"
#include "uSkyFog.h"

// Forward declarations
class AreaHitShape;
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtObject;
class MtPropertyList;
class MtStream;
class MtString;
class MtVector3;
class cDayNightColorFogParam;

// Declarations
class rStageCustomPartsEx;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class rStageCustomPartsEx : public rStageCustomParts
{
public:
    class MyDTI;
    class Pattern;
    class ColorFog;
    class HemiSphLight;
    class InfiLight;
    class AreaParam;
    class InfoEx;
    class FilterEx;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class Pattern : public MtObject
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
        Pattern();
        virtual ~Pattern();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void copy(rStageCustomPartsEx::Pattern* src);
        bool load(MtDataReader& r);
        bool save(MtDataWriter& w);
        void clear();
    public:
        s32 mColorFogNo;  // offset: 0x8
        s32 mHemiSphLightNo;  // offset: 0xc
        s32 mInfiLightNo;  // offset: 0x10
        MtString mComment;  // offset: 0x18
        static MyDTI DTI;
    };
public:
    class ColorFog : public MtObject
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
        ColorFog();
        virtual ~ColorFog();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void copy(rStageCustomPartsEx::ColorFog* src);
        bool load(MtDataReader& r);
        bool save(MtDataWriter& w);
        void clear();
    public:
        cDayNightColorFogParam mBase;  // offset: 0x10
        cDayNightColorFogParam mNight;  // offset: 0x80
        MtString mComment;  // offset: 0xf0
        static MyDTI DTI;
    };
public:
    class HemiSphLight : public MtObject
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
        HemiSphLight();
        virtual ~HemiSphLight();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void copy(rStageCustomPartsEx::HemiSphLight* src);
        bool load(MtDataReader& r);
        bool save(MtDataWriter& w);
        void clear();
    public:
        MtVector3 mLightColor;  // offset: 0x10
        MtVector3 mRevColor;  // offset: 0x20
        MtVector3 mNightColor;  // offset: 0x30
        MtVector3 mNightRevColor;  // offset: 0x40
        MtString mComment;  // offset: 0x50
        static MyDTI DTI;
    };
public:
    class InfiLight : public MtObject
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
        InfiLight();
        virtual ~InfiLight();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void copy(rStageCustomPartsEx::InfiLight* src);
        bool load(MtDataReader& r);
        bool save(MtDataWriter& w);
        void clear();
    public:
        MtVector3 mLightColor;  // offset: 0x10
        MtVector3 mNightColor;  // offset: 0x20
        MtString mComment;  // offset: 0x30
        static MyDTI DTI;
    };
public:
    class AreaParam : public MtObject
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
        AreaParam();
        virtual ~AreaParam();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void copy(rStageCustomPartsEx::AreaParam* src);
        bool load(MtDataReader& r);
        bool save(MtDataWriter& w);
        void clear();
        bool hitCheck(const MtVector3& pos);
    public:
        bool mUseAllFilter;  // offset: 0x8
        s32 mFilterNo;  // offset: 0xc
        s32 mPatternNo;  // offset: 0x10
        MtTypedArray<AreaHitShape> mAreaHitShapeList;  // offset: 0x18
        MtString mComment;  // offset: 0x38
        static MyDTI DTI;
    };
public:
    class InfoEx : public rStageCustomParts::Info
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
        InfoEx();
        virtual ~InfoEx();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        bool load(MtDataReader& r);
        bool save(MtDataWriter& w);
        void clear();
        rStageCustomPartsEx::AreaParam* getAreaParam(const MtVector3& pos, s32 filterNo);
    public:
        u32 mAddVersion;  // offset: 0x340
        MtTypedArray<rStageCustomPartsEx::AreaParam> mAreaParamList;  // offset: 0x348
        static MyDTI DTI;
    };
public:
    class FilterEx : public rStageCustomParts::Filter
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
        FilterEx();
        virtual ~FilterEx();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void copy(rStageCustomPartsEx::FilterEx* src);
        bool load(MtDataReader& r);
        bool save(MtDataWriter& w);
        void clear();
    public:
        u32 mAddVersion;  // offset: 0x48
        MtString mComment;  // offset: 0x50
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
    rStageCustomPartsEx();
    virtual ~rStageCustomPartsEx();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    u32 getMagicHeader() const;
    u32 getDataVersion() const;
    void destruct();
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual rStageCustomParts::Info* getInfo(u32 index) const;  // vtable slot 16
    virtual u32 getInfoNum() const;  // vtable slot 17
    virtual rStageCustomParts::Filter* getFilter(u32 index) const;  // vtable slot 18
    virtual u32 getFilterNum() const;  // vtable slot 19
    virtual Pattern* getPattern(u32 index) const;  // vtable slot 21
    virtual u32 getPatternNum() const;  // vtable slot 22
    virtual ColorFog* getColorFog(u32 index) const;  // vtable slot 23
    virtual u32 getColorFogNum() const;  // vtable slot 24
    virtual HemiSphLight* getHemiSphLight(u32 index) const;  // vtable slot 25
    virtual u32 getHemiSphLightNum() const;  // vtable slot 26
    virtual InfiLight* getInfiLight(u32 index) const;  // vtable slot 27
    virtual u32 getInfiLightNum() const;  // vtable slot 28
    virtual rStageCustomParts::Info* searchInfo(u32 areaNo) const;  // vtable slot 20
    f32 getChangeFrame() const;
protected:
    f32 mChangeFrame;  // offset: 0x9c
    Pattern* mpArrayPattern;  // offset: 0xa0
    u32 mArrayPatternNum;  // offset: 0xa8
    ColorFog* mpArrayColorFog;  // offset: 0xb0
    u32 mArrayColorFogNum;  // offset: 0xb8
    HemiSphLight* mpArrayHemiSphLight;  // offset: 0xc0
    u32 mArrayHemiSphLightNum;  // offset: 0xc8
    InfiLight* mpArrayInfiLight;  // offset: 0xd0
    u32 mArrayInfiLightNum;  // offset: 0xd8
public:
    static MyDTI DTI;
protected:
    static const u8 DATA_VERSION = 5;
};

// Inline, no code of its own: checked where it is inlined.
inline rStageCustomPartsEx::rStageCustomPartsEx() {
    this->mChangeFrame = 60.0f;
    this->mpArrayColorFog = static_cast<rStageCustomPartsEx::ColorFog*>(nullptr);
    this->mArrayColorFogNum = static_cast<u32>(0);
    this->mpArrayHemiSphLight = static_cast<rStageCustomPartsEx::HemiSphLight*>(nullptr);
    this->mArrayHemiSphLightNum = static_cast<u32>(0);
    this->mpArrayInfiLight = static_cast<rStageCustomPartsEx::InfiLight*>(nullptr);
    this->mArrayInfiLightNum = static_cast<u32>(0);
    this->mpArrayPattern = static_cast<rStageCustomPartsEx::Pattern*>(nullptr);
    this->mArrayPatternNum = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline rStageCustomPartsEx::Pattern::Pattern() {
    this->mColorFogNo = static_cast<s32>(-1);
    this->mHemiSphLightNo = static_cast<s32>(-1);
    this->mInfiLightNo = static_cast<s32>(-1);
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline rStageCustomPartsEx::FilterEx::FilterEx() {
    this->mAddVersion = static_cast<u32>(512);
}
