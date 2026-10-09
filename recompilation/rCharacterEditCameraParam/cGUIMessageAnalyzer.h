#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/nGUI.h"

// Forward declarations
class MtAllocator;
class MtDTI;
struct MtFloat2;
class MtSize;
class MtSizeF;
class cGUIInstMessage;
class cGUIObjMessage;
namespace nGUI { struct MTAG; }
class rGUIFont;
class uGUI;

// Declarations
class cGUIMessageAnalyzer;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cGUIMessageAnalyzer : public MtObject
{
public:
    enum MODE
    {
        MODE_INSTANCE = 0,
        MODE_OBJECT = 1,
    };
    enum STATE
    {
        STATE_NORMAL = 0,
        STATE_RUBY = 1,
        STATE_RUBY_RB = 2,
        STATE_RUBY_RT = 3,
        STATE_NUM = 4,
    };
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
    cGUIMessageAnalyzer(cGUIInstMessage* pInstance, s32 pageIndex);
    cGUIMessageAnalyzer(cGUIObjMessage* pObject, s32 pageIndex);
    virtual ~cGUIMessageAnalyzer();
    nGUI::MTAG* analyze(MT_CTSTR pMessage, u32 length);
    void recalcFontSize(nGUI::MTAG* pMTagTop);
    void analyzeMessage(MT_CTSTR pMessage, u32 length);
    void pushTagFont(rGUIFont* pFont);
    void popTagFont();
    void pushTagSize(f32 w, f32 h, bool resize);
    void popTagSize();
    void pushTagColor(u32 color);
    void popTagColor();
    void pushTagRGB(u32 color);
    void popTagRGB();
    void pushTagSpeed(f32 speed);
    void popTagSpeed();
    void addTagSpace();
    void addTagWordwrap(bool hyphen);
    void addTagIcon(u32 code);
    void addTagChar(u32 code, nGUI::MTAG::TYPE type);
    void addTagTime(u32 frame);
    void addTagStay();
    void addTagPage();
    void addTagDisp(u32 frame);
    void addTagCenter();
    void addTagLeft();
    void addTagRight();
    void addTagLineAlignment(nGUI::MTAG::TYPE type);
    void addTagEvent(u32 type, u32 param0, u32 param1);
    void addTagExtend(void* pt, f32 w, f32 h);
    f32 getMessageWidth() const;
    f32 getMessageHeight() const;
    u32 getError() const;
    void setSpeakerGender(nGUI::GENDER gender);
    void setListenerGender(nGUI::GENDER gender);
    void setAddMsg(bool isAdd);
    bool isAddMsg() const;
    uGUI* getUnit() const;
    MtObject* getObject() const;
    static u32 getTagNum(nGUI::MTAG* pMTag, nGUI::MTAG::TYPE type);
    static u32 getPageNum(nGUI::MTAG*);
    static u32 getPageIndex(nGUI::MTAG* pMTagTop, nGUI::MTAG* pMTag);
    static nGUI::MTAG* getPage(nGUI::MTAG* pMTag, u32 pageIndex);
    static nGUI::MTAG* getCharMTAG(nGUI::MTAG* pMTag, u32 index, bool countIcon);
    static nGUI::MTAG* getCharMTAG(nGUI::MTAG* pMTag, u32 charIndex, u32 lineIndex, u32 pageIndex, bool countIcon);
    static MtFloat2 getPageSize(nGUI::MTAG* pMTag, u32 pageIndex);
    static u32 getPageCharCount(nGUI::MTAG* pMTag, u32 pageIndex, bool countIcon);
    static u32 getLineCharCount(nGUI::MTAG* pMTag, u32 lineIndex, u32 pageIndex, bool countIcon);
    static u32 getCharCount(nGUI::MTAG* pMTagStart, nGUI::MTAG* pMTagEnd, bool countIcon);
    static MtFloat2 getCharPos(nGUI::MTAG* pMTag, u32 charIndex, u32 lineIndex, u32 pageIndex, bool countIcon);
    static MtSizeF getCharSize(nGUI::MTAG* pMTag, u32 charIndex, u32 lineIndex, u32 pageIndex, bool countIcon);
    static MtFloat2 getLinePos(nGUI::MTAG* pMTag, u32 lineIndex, u32 pageIndex);
protected:
    cGUIMessageAnalyzer();
    virtual void* memAlloc(u32 size);  // vtable slot 6
    void memFree(void*);
    virtual bool analyzeTagAdditional(u32 tag, MT_CTSTR pParam, bool end);  // vtable slot 7
    void calculate();
    void addLine();
    void executeAutoWrap();
    void executeAutoWrap(nGUI::MTAG* pMTagStart);
    bool compareMTAGUnicode(nGUI::MTAG* pMTagL, nGUI::MTAG* pMTagR);
    bool compareMTAGUnicode(u32 unicode, nGUI::MTAG* pMTag);
    void executeAutoScaling();
    void executeAutoScaling(nGUI::MTAG* pMTagStart, nGUI::MTAG* pMTagEnd, f32 scale);
    void calcSize();
    void calcPosition();
    void addTagFont(rGUIFont* pFont);
    void addTagSize(f32 w, f32 h, bool resize);
    void addTagColor(u32 color);
    void addTagRGB(u32 color);
    void addTagSpeed(f32 speed);
    void addRect(nGUI::MTAG* pMTag);
    nGUI::MTAG* getTagFont() const;
    nGUI::MTAG* getTagSize() const;
    nGUI::MTAG* getTagColor() const;
    nGUI::MTAG* getTagRGB() const;
    nGUI::MTAG* getTagSpeed() const;
    nGUI::MTAG* allocMTag(u32 type);
    void adjustLetterSpace();
    nGUI::MTAG* connectNewMTAG(nGUI::MTAG* & pMTag, nGUI::MTAG::TYPE type, u32 attr);
private:
    bool isText() const;
    void setText(bool v);
    bool isSpecifiedPage() const;
    void setSpecifiedPage(bool v);
    bool isPageLineBreak() const;
    void setPageLineBreak(bool v);
    void init();
    bool isBaseTag(u32 tagName) const;
    void analyzeTag(u32 tag, MT_CTSTR pParam, bool end);
    void analyzeTagFont(MT_CTSTR pParam, bool end);
    void analyzeTagSize(MT_CTSTR pParam, bool end);
    void analyzeTagColor(MT_CTSTR pParam, bool end);
    void analyzeTagRGB(MT_CTSTR pParam, bool end);
    void analyzeTagIcon(MT_CTSTR pParam);
    void analyzeTagWordwrap(bool hyphen);
    void analyzeTagSpeed(MT_CTSTR pParam, bool end);
    void analyzeTagTime(MT_CTSTR pParam);
    void analyzeTagStay(MT_CTSTR pParam);
    void analyzeTagPage(MT_CTSTR pParam);
    void analyzeTagDisp(MT_CTSTR pParam);
    void analyzeTagCenter();
    void analyzeTagLeft();
    void analyzeTagRight();
    void analyzeTagSpeaker(MT_CTSTR pParam);
    void analyzeTagListener(MT_CTSTR pParam);
    void analyzeTagRuby(MT_CTSTR pParam, bool end);
    void analyzeTagRubyRB(MT_CTSTR pParam, bool end);
    void analyzeTagRubyRT(MT_CTSTR pParam, bool end);
    void setRuby(nGUI::MTAG* pMTag);
    void setRubyRB(nGUI::MTAG* pMTag);
    void setRubyRT(nGUI::MTAG* pMTag);
    void calcRubyRTPosition();
    void analyzeTagGender(MT_CTSTR pParam, nGUI::GENDER gender);
    u32 getFontSlot() const;
    MtFloat2 getSize() const;
    bool isAutoWrap() const;
    u32 getAutoWrap() const;
    bool isAutoScale() const;
    bool isMonospace() const;
    bool isUseRuby() const;
    bool isAnalyzeTag() const;
    s32 getLineSpace() const;
    s32 getLetterSpace() const;
    u32 getLayout() const;
    u32 getLetterHAlign() const;
    u32 getLetterVAlign() const;
    rGUIFont* getFont(u32 index);
    MtSize getFontSize();
    u32 getSamplerState();
    f32 getSpeed();
protected:
    nGUI::MTAG* mpMTag;  // offset: 0x8
    u32 mError;  // offset: 0x10
    s32 mCurPageIndex;  // offset: 0x14
    union
    {
    public:
        cGUIInstMessage* mpInstance;  // offset: 0x0
        cGUIObjMessage* mpObject;  // offset: 0x0
    };  // offset: 0x18
    f32 mMsgWidth;  // offset: 0x20
    f32 mMsgHeight;  // offset: 0x24
private:
    u32 mMode;  // offset: 0x28
    u32 mAttr;  // offset: 0x2c
    s32 mPageIndex;  // offset: 0x30
    u32 mLineCharCount;  // offset: 0x34
    u32 mState;  // offset: 0x38
    f32 mWidth;  // offset: 0x3c
    f32 mHeight;  // offset: 0x40
    f32 mLetterSpace;  // offset: 0x44
    f32 mRubyHeight;  // offset: 0x48
    nGUI::MTAG* mpMTagTop;  // offset: 0x50
    nGUI::MTAG* mpMTagLine;  // offset: 0x58
    nGUI::MTAG* mpMTagTemp;  // offset: 0x60
    nGUI::MTAG* mpMTagRuby;  // offset: 0x68
    nGUI::MTAG* mpMTagRubyRB;  // offset: 0x70
    nGUI::MTAG* mpMTagRubyRT;  // offset: 0x78
    nGUI::MTAG* mpFontStack;  // offset: 0x80
    nGUI::MTAG* mpSizeStack;  // offset: 0x88
    nGUI::MTAG* mpColorStack;  // offset: 0x90
    nGUI::MTAG* mpRGBStack;  // offset: 0x98
    nGUI::MTAG* mpSpeedStack;  // offset: 0xa0
    nGUI::GENDER mSpeakerGender;  // offset: 0xa8
    nGUI::GENDER mListenerGender;  // offset: 0xac
    bool mIsIgnoreMessage;  // offset: 0xb0
public:
    static MyDTI DTI;
    static const u32 ERROR_RANGEOVER_W = 1;
    static const u32 ERROR_RANGEOVER_H = 2;
    static const u32 ERROR_INVALIDCHAR = 4;
    static const u32 ERROR_INVALIDFONT = 8;
    static const u32 ERROR_MTAG_ALLOC = 16;
    static const u32 ERROR_USING_INVALID_TAG = 32;
    static const u32 ERROR_GENDER = 64;
    static const u32 ERROR_ANALYZE_STATE = 128;
private:
    static const u32 ATTR_TEXT = 1;
    static const u32 ATTR_SPECIFIED_PAGE = 2;
    static const u32 ATTR_PAGE_LINEBREAK = 4;
};
