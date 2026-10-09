#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "cSystem.h"
#include "nGUI.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtDTI;
class MtMatrix;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class cDraw;
class cGUIFontFilter;
class cGUIMessageAnalyzer;
class cGUIObjMessage;
namespace nDraw { class IndexBuffer; }
namespace nDraw { class Texture; }
namespace nDraw { class VertexBuffer; }
namespace nGUI { struct BufferObject; }
namespace nGUI { struct CLASS_INFO; }
namespace nGUI { struct ICON_INFO; }
namespace nGUI { struct MTAG; }
namespace nGUI { struct PROP_SETTER; }
namespace nGUI { class WrapPoint; }
class rGUI;
class rGUIFont;
class rGUIIconInfo;
class uGUI;

// Declarations
class sGUI;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_STR = MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class sGUI : public cSystem
{
    // inferred: cGUIMessageAnalyzer::~cGUIMessageAnalyzer names sGUI::mpInstance
    friend class cGUIMessageAnalyzer;
    // inferred: cGUIObjMessage::clearDrawMTag names sGUI::mpInstance
    friend class cGUIObjMessage;
public:
    class MyDTI;
    struct DESC;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct DESC
    {
    public:
        u32 mMTAGCount;  // offset: 0x0
        u32 mVertexBuffer;  // offset: 0x4
        u32 mIndexBuffer;  // offset: 0x8
        bool mInitDefaultWrapPoint;  // offset: 0xc
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
    sGUI(const DESC& desc);
    sGUI(u32 tempMTagCount, u32 polygonCount, u32 indexBuffer);
    virtual ~sGUI();
    virtual void reset();  // vtable slot 6
    virtual void setup();  // vtable slot 10
    virtual void begin();  // vtable slot 11
    virtual void move();  // vtable slot 7
    virtual void end();  // vtable slot 12
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createMenu(MtPropertyList& s);  // vtable slot 8
    virtual void draw(cDraw* pDraw);  // vtable slot 13
    static sGUI* getInstance();
    u32 getPlatform() const;
    void getPlatformFilePath(MT_STR outPath, MT_CTSTR inPath);
    const nGUI::CLASS_INFO* getObjectClassInfo(const u32 dtiId) const;
    const nGUI::CLASS_INFO* getInstanceClassInfo(const u32 dtiId) const;
    const nGUI::PROP_SETTER* getPropSetter(const nGUI::CLASS_INFO* pInfo, MT_CTSTR name) const;
    void setUseSystemFont(bool v);
    bool isUseSystemFont() const;
    void createAlphaMap();
    void releaseAlphaMap();
    nDraw::Texture* getAlphaMap() const;
    void setLanguageId(nGUI::LANGUAGE language, nGUI::LANGUAGE_SETTING setting);
    void setLanguageSettingNum(u32 v);
    u32 getLanguageSettingNum() const;
    nGUI::LANGUAGE getLanguageId(nGUI::LANGUAGE_SETTING setting) const;
    void setLanguageIdForProperty(u32 value, u32 setting);
    void getLanguageFilePath(MT_STR outPath, MT_CTSTR inPath, nGUI::LANGUAGE_SETTING setting);
    void setEnableRubySpace(nGUI::LANGUAGE lang, bool v);
    bool isEnableRubySpace(nGUI::LANGUAGE_SETTING setting) const;
    void setFontCount(s32 slot);
    s32 getFontCount() const;
    void setFont(rGUIFont* pFont, u32 slot);
    rGUIFont* getFont(u32 slot);
    void setRubyLineSpace(s32 space);
    s32 getRubyLineSpace() const;
    void setRubyRatio(f32 ratio);
    f32 getRubyRatio() const;
    void setRubyFont(rGUIFont* pResource);
    rGUIFont* getRubyFont() const;
    void updateDynamicFont();
    bool isLayoutingFont() const;
    void cancelLayoutFont(bool all);
    void requestLayoutFont(rGUIFont* pFont);
    bool loadFontFilter(MT_CTSTR path);
    cGUIFontFilter* getFontFilter(u32 id);
    rGUI* getFontFilterResource();
    nGUI::MTAG* allocTempMTag(u32 type);
    nGUI::MTAG* allocTempMTagArray(u32 count);
    void freeTempMTag(nGUI::MTAG* pMTag);
    virtual void freeMTagExtendData(void* pt);  // vtable slot 14
    void freeMTAGList(nGUI::MTAG* & pMTag);
    void setTempMTagOffset(u32 v);
    u32 getTempMTagOffset() const;
    void setTempMTagBufferCount(u32 count);
    u32 getTempMTagBufferCount() const;
    void setUseTempMTagCount(u32 count);
    u32 getUseTempMTagCount();
    virtual bool callbackInvalidCharacter(cGUIMessageAnalyzer* pAnalyzer, rGUIFont* pFont, u32 code);  // vtable slot 15
    // Address: 0x01b9fdc0 - 0x01b9fdc1 (1 bytes)
    virtual void callbackAllocMTagError() {}  // vtable slot 16
    virtual void analyzeTagExtend(cGUIMessageAnalyzer* pAnalyzer, u32 tag, MT_CTSTR pParam, bool end, uGUI* pUnit);  // vtable slot 17
    u32 analyzeTagIcon(MT_CTSTR pParam);
    virtual u32 analyzeTagIcon(MT_CTSTR pParam, nGUI::ICON_INFO* pIconInfo);  // vtable slot 18
    void setUseIconFontFilter(bool v);
    bool isUseIconFontFilter() const;
    void setIconInfo(nGUI::ICON_INFO* pIconInfo);
    void setIconInfo(rGUIIconInfo* pResource);
    nGUI::ICON_INFO* getIconInfo() const;
    void setIconFont(rGUIFont* pResource);
    rGUIFont* getIconFont() const;
    const MtMatrix& getBaseMatrix(bool is3D) const;
    const MtMatrix& getMatrixIdentity() const;
    u32 getBufferIndex() const;
    u32 getBufferIndexBit() const;
    u32 getBufferUpdateFlag() const;
    void setUpdateBuffer(nGUI::BufferObject& bufferObject) const;
    bool isUpdateBuffer(nGUI::BufferObject& bufferObject) const;
    void resetUpdateBuffer(nGUI::BufferObject& bufferObject) const;
    bool isRequestBufferCompaction() const;
    void requestBufferCompaction();
private:
    void executeBufferCompaction(nGUI::BufferObject& bufferObject);
    void forceUpdateBuffer(nGUI::BufferObject& bufferObject);
public:
    bool allocVertexBuffer(nGUI::BufferObject& bufferObject, u32 size);
    void freeVertexBuffer(nGUI::BufferObject& bufferObject);
    void resetUpdateVertexBuffer(nGUI::BufferObject& bufferObject) const;
    void* getVertexBuffer(nGUI::BufferObject& bufferObject) const;
    nDraw::VertexBuffer* getVertexBuffer() const;
    bool allocIndexBuffer(nGUI::BufferObject& bufferObject, u32 size);
    void freeIndexBuffer(nGUI::BufferObject& bufferObject);
    void resetUpdateIndexBuffer(nGUI::BufferObject& bufferObject) const;
    void* getIndexBufferTop() const;
    void* getIndexBuffer(nGUI::BufferObject& bufferObject) const;
    nDraw::IndexBuffer* getIndexBuffer() const;
protected:
    virtual void* memAlloc(u32 size);  // vtable slot 19
    virtual void memFree(void* p_addr);  // vtable slot 20
private:
    nGUI::CLASS_INFO* buildClassInfo(const MtDTI* pDti);
    void buildClassInfo(const MtDTI* pDti, nGUI::CLASS_INFO* pInfo, u32& index);
    u32 getClassNum(const MtDTI* pDti);
    void createClassInfo(const MtDTI* pDti, nGUI::CLASS_INFO& info);
    void deleteClassInfo(nGUI::CLASS_INFO* & pInfo);
    const nGUI::CLASS_INFO* getClassInfo(const nGUI::CLASS_INFO* pInfo, const u32 dtiId) const;
public:
    s32 getWrapPointIndexByUnicode(u32 unicode) const;
    nGUI::WrapPoint* getWrapPointByUnicode(u32 unicode) const;
    void addWrapPoint(nGUI::WrapPoint* pWrapPointAdd);
    void addWrapPointByProp(u32 unicode, bool isContinual, bool isValid);
    nGUI::WrapPoint* getWrapPoint(u32 index) const;
    u32 getWrapPointNum() const;
private:
    void setWrapPoint(nGUI::WrapPoint*, u32);
    void setWrapPointNum(u32);
public:
    bool isEnableGUIPlacementNew() const;
    void setEnableGUIPlacementNew(bool);
private:
    nDraw::Texture* mpAlphaMap;  // offset: 0x18
    u32 mAttr;  // offset: 0x20
    nGUI::LANGUAGE mLanguageId[3];  // offset: 0x24
    rGUIFont* mpFontArray[8];  // offset: 0x30
    rGUIFont* mpLayoutingFont;  // offset: 0x70
    rGUIFont* mpIconFont;  // offset: 0x78
    nGUI::ICON_INFO* mpIconInfo;  // offset: 0x80
    MT_CHAR* mpIconNameBuffer;  // offset: 0x88
    rGUI* mpFontFilterResource;  // offset: 0x90
    u32 mEnableRubySpace;  // offset: 0x98
    s32 mRubyLineSpace;  // offset: 0x9c
    f32 mRubyRatio;  // offset: 0xa0
    rGUIFont* mpRubyFont;  // offset: 0xa8
    u32 mTempMTagOffset;  // offset: 0xb0
    u32 mTempMTagBufferCount;  // offset: 0xb4
    nGUI::MTAG* mpTempMTagBuffer;  // offset: 0xb8
    nGUI::MTAG* * mpEmptyTempMTagBuffer;  // offset: 0xc0
    nGUI::CLASS_INFO* mpObjectClassInfo;  // offset: 0xc8
    nGUI::CLASS_INFO* mpInstanceClassInfo;  // offset: 0xd0
    u32 mBufferBit;  // offset: 0xd8
    u32 mBufferIndex;  // offset: 0xdc
    u32 mBufferIndexBit;  // offset: 0xe0
    u32 mVertexBufferSize;  // offset: 0xe4
    u32 mVertexBufferBlankSize;  // offset: 0xe8
    nDraw::VertexBuffer* mpVertexBuffer[3];  // offset: 0xf0
    void* mpVertexBufferTop;  // offset: 0x108
    nGUI::BufferObject mVertexBufferObject;  // offset: 0x110
    u32 mIndexBufferSize;  // offset: 0x128
    u32 mIndexBufferBlankSize;  // offset: 0x12c
    nDraw::IndexBuffer* mpIndexBuffer[3];  // offset: 0x130
    void* mpIndexBufferTop;  // offset: 0x148
    nGUI::BufferObject mIndexBufferObject;  // offset: 0x150
    MtArray mWrapPointList;  // offset: 0x168
    bool mIsEnableGUIPlacementNew;  // offset: 0x188
public:
    static MyDTI DTI;
    static const u32 FONT_NUM = 8;
    static const DESC DEFAULT_DESC;
private:
    static const u32 ATTR_USE_ICONFONTFILTER = 1;
    static const u32 ATTR_USE_SYSTEMFONT = 2;
    static const u32 ATTR_BUFFER_COMPACTION = 4;
    static sGUI* mpInstance;
};

// Inline, no code of its own: checked where it is inlined.
inline sGUI* sGUI::getInstance() {
    return ::sGUI::mpInstance;
}
