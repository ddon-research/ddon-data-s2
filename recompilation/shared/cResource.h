#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "MtXmlReader.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtString;
class MtTime;
class MtUI;
class rAIConditionTree;
class rAIPathBase;
class rArchive;
class rCameraList;
class rCharacterEdit;
class rCollisionHeightField;
class rEffect2D;
class rEffectList;
class rEffectStrip;
class rGUIIconInfo;
class rGeometry2;
class rMotionList;
class rOccluder;
class rRenderTargetTexture;
class rScheduler;
class rSoundAttributeSe;
class rSoundBank;
class rSoundCurveSet;
class rSoundDirectionalSet;
class rStageCustomParts;
class rStarCatalog;
class rSwingModel;
class rTable;
class rTexture;
class rTextureJpeg;
class rVibration;
class sSoundExt;
class uCnsDDOIK;

// Declarations
class cResource;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using time_t = long int;
using t64 = time_t;
using u32 = unsigned int;
using u64 = __uint64_t;

class cResource : public MtObject
{
    // inferred: rAIConditionTree::rAIConditionTree names cResource::mAttr
    friend class rAIConditionTree;
    // inferred: rAIPathBase::rAIPathBase names cResource::mAttr
    friend class rAIPathBase;
    // inferred: rArchive::rArchive names cResource::mAttr
    friend class rArchive;
    // inferred: rCameraList::rCameraList names cResource::mAttr
    friend class rCameraList;
    // inferred: rCharacterEdit::rCharacterEdit names cResource::mAttr
    friend class rCharacterEdit;
    // inferred: rCollisionHeightField::rCollisionHeightField names cResource::mAttr
    friend class rCollisionHeightField;
    // inferred: rEffect2D::rEffect2D names cResource::mAttr
    friend class rEffect2D;
    // inferred: rEffectList::rEffectList names cResource::mAttr
    friend class rEffectList;
    // inferred: rEffectStrip::rEffectStrip names cResource::mAttr
    friend class rEffectStrip;
    // inferred: rGUIIconInfo::rGUIIconInfo names cResource::mAttr
    friend class rGUIIconInfo;
    // inferred: rGeometry2::rGeometry2 names cResource::mAttr
    friend class rGeometry2;
    // inferred: rMotionList::rMotionList names cResource::mAttr
    friend class rMotionList;
    // inferred: rOccluder::rOccluder names cResource::mAttr
    friend class rOccluder;
    // inferred: rRenderTargetTexture::rRenderTargetTexture names cResource::mAttr
    friend class rRenderTargetTexture;
    // inferred: rScheduler::rScheduler names cResource::mAttr
    friend class rScheduler;
    // inferred: rSoundAttributeSe::rSoundAttributeSe names cResource::mAttr
    friend class rSoundAttributeSe;
    // inferred: rSoundBank::rSoundBank names cResource::mAttr
    friend class rSoundBank;
    // inferred: rSoundCurveSet::rSoundCurveSet names cResource::mAttr
    friend class rSoundCurveSet;
    // inferred: rSoundDirectionalSet::rSoundDirectionalSet names cResource::mAttr
    friend class rSoundDirectionalSet;
    // inferred: rStageCustomParts::rStageCustomParts names cResource::mAttr
    friend class rStageCustomParts;
    // inferred: rStarCatalog::rStarCatalog names cResource::mAttr
    friend class rStarCatalog;
    // inferred: rSwingModel::rSwingModel names cResource::mAttr
    friend class rSwingModel;
    // inferred: rTable::rTable names cResource::mAttr
    friend class rTable;
    // inferred: rTexture::rTexture names cResource::mAttr
    friend class rTexture;
    // inferred: rTextureJpeg::decodeJpeg names cResource::mState
    friend class rTextureJpeg;
    // inferred: rVibration::rVibration names cResource::mAttr
    friend class rVibration;
    // inferred: sSoundExt::checkNoStopStream names cResource::mID
    friend class sSoundExt;
    // inferred: uCnsDDOIK::getName names cResource::mPath[0]
    friend class uCnsDDOIK;
public:
    enum CONVERT_TYPE
    {
        CONVERT_DEFAULT = 0,
        CONVERT_360 = 8192,
        CONVERT_PS3 = 16384,
        CONVERT_VITA = 32768,
        CONVERT_CAFE = 65536,
        CONVERT_VITAEMU = 262144,
        CONVERT_XBOXONE = 1048576,
        CONVERT_PS4 = 524288,
    };
    enum QUALITY
    {
        QUALITY_LOWEST = 0,
        QUALITY_LOW = 1,
        QUALITY_NORMAL = 2,
        QUALITY_HIGH = 3,
        QUALITY_HIGHEST = 4,
        QUALITY_STREAM_LOW = 5,
        QUALITY_STREAM_HIGH = 6,
    };
    enum ATTR
    {
        ATTR_XMLNODE = 1,
        ATTR_SAVEABLE = 2,
        ATTR_CREATABLE = 4,
        ATTR_INTERMEDIATE = 8,
        ATTR_NATIVE = 16,
        ATTR_TEMP = 32,
        ATTR_USECACHE = 64,
        ATTR_ARCHIVE = 128,
        ATTR_BACKGROUND = 512,
        ATTR_USEGDATA = 1024,
        ATTR_STREAM = 2048,
        ATTR_COMPACTABLE = 4096,
        ATTR_CONVERTABLE_360 = 8192,
        ATTR_CONVERTABLE_PS3 = 16384,
        ATTR_CONVERTABLE_VITA = 32768,
        ATTR_CONVERTABLE_CAFE = 65536,
        ATTR_NOT_COPYABLE_VITA = 131072,
        ATTR_CONVERTABLE_VITAEMU = 262144,
        ATTR_CONVERTABLE_PS4 = 524288,
        ATTR_CONVERTABLE_XBOXONE = 1048576,
    };
    enum STATE
    {
        STATE_USAGE = 1,
        STATE_UPDATE = 2,
        STATE_MODIFY = 4,
        STATE_RELOAD = 8,
        STATE_FAILED = 16,
        STATE_UPDATEQUERY = 32,
        STATE_CANCEL = 64,
        STATE_RELOADED = 128,
    };
public:
    class MyDTI;
    class XmlHandler;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class XmlHandler : public MtXmlReader::Handler
    {
    public:
        XmlHandler(t64 base_time);
        virtual void startElement(MT_CTSTR localname, MtXmlReader::ATTRIBUTE* attr, u32 attr_num);  // vtable slot 8
        virtual void endElement(MT_CTSTR localname);  // vtable slot 3
    public:
        t64 mBaseTime;  // offset: 0x10
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
    u64 getID() const;
    u32 getSize() const;
    u32 getAttr() const;
    u32 getQuality() const;
    u32 getTag() const;
    bool isNative() const;
    bool isIntermediate() const;
    bool isUsage() const;
    bool isUpdate() const;
    bool isReloaded() const;
    bool isModified() const;
    bool isFailed() const;
    bool isCancel() const;
    MT_CTSTR getPath() const;
    void addRef();
    void release();
    u32 getRefCount() const;
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtTime getUpdateTime(MT_CTSTR fullpath);  // vtable slot 6
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    void reload();
    bool saveAs(MT_CTSTR rpath);
    virtual bool compact(MtStream& out);  // vtable slot 8
    void setModify(bool);
    void setUsage(bool f);
    void updateRequest();
    void cancelRequest();
protected:
    cResource();
    virtual ~cResource();
    virtual bool create();  // vtable slot 9
    virtual bool loadEnd();  // vtable slot 10
    virtual bool load(MtStream&);  // vtable slot 11
    virtual bool save(MtStream&);  // vtable slot 12
    virtual bool convert(MtStream& out);  // vtable slot 13
    virtual bool convertEx(MtStream&, CONVERT_TYPE type);  // vtable slot 14
    virtual void clear();  // vtable slot 15
    void setAttribute(u32 attr);
    u32 getState();
    void errMagic() const;
    void errVer() const;
    void errDTI() const;
    void errSize() const;
    void errDeserializeXml();
    void errDeserializeBin();
private:
    void setState(u32 v);
    void setQuality(u32 q);
    void setTag(u32 tag);
    void setPath(const MtString& s);
private:
    u32 mMagicID : 16;  // offset: 0x8
    u32 mMagicTag : 16;  // offset: 0x8
    MT_CHAR mPath[64];  // offset: 0xc
    s32 mRefCount;  // offset: 0x4c
    u32 mAttr;  // offset: 0x50
    u32 mState : 8;  // offset: 0x54
    u32 mQuality : 3;  // offset: 0x54
    u32 mTag : 21;  // offset: 0x54
    u32 mSize;  // offset: 0x58
    u64 mID;  // offset: 0x60
    u32 _padding0;  // offset: 0x68
    u32 _padding1;  // offset: 0x6c
public:
    static MyDTI DTI;
    static const s32 MAX_RPATH = 64;
private:
    static MtAllocator* mpAllocator;
};

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline u64 cResource::getID() const {
    return this->mID;
}

// Inline, no code of its own: checked where it is inlined.
// inferred: a bit-test accessor's polarity, true when its bits are set: none of its 25 DWARF copies materializes its result
inline bool cResource::isIntermediate() const {
    return (this->mAttr & static_cast<u32>(8)) != static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
// inferred: a bit-test accessor's polarity, true when its bits are set: none of its 76 DWARF copies materializes its result
inline bool cResource::isUsage() const {
    return (this->mState & static_cast<u32>(1)) != static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
// inferred: parameters written where their values stand in every inlined copy; its copies pass (16), (18), (22)
inline void cResource::setAttribute(u32 attr) {
    this->mAttr = attr;
}
