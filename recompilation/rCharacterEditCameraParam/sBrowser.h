#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/MtPrimitive2D.h"
#include "../shared/MtString.h"
#include "../shared/cSystem.h"
#include "snj_browser.h"
#include "snj_browser_common.h"

// Forward declarations
class MtAllocator;
class MtDTI;
struct MtInt2;
class MtObject;
class MtPoint;
class MtPropertyList;
class MtRect;
class MtSize;
class MtString;
class cArcLoaderBase;
class cBrowserPS4;
class cDraw;
namespace nDraw { class RasterizerState; }
namespace nDraw { class Texture; }
namespace nDraw { class VertexBuffer; }
class rGUIFont;
class rTexture;
class rTextureMemory;
class sGUIExt;
class uGUIBrowserBG;

// Declarations
class cBrowserRequest;
class sBrowser;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using TICKET = cArcLoaderBase*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cBrowserRequest : public MtObject
{
public:
    cBrowserRequest();
    cBrowserRequest(u32 Request, u32 Status);
    virtual ~cBrowserRequest();
    void setRequest(const u32, const u32);
    u32 getRequest();
    u32 getStatus();
    void setStringParam(MT_CTSTR);
    MtString& getStringParam();
private:
    u32 mRequest;  // offset: 0x8
    u32 mStatus;  // offset: 0xc
    MtString mString;  // offset: 0x10
};

typedef struct
{
public:
    const char* mpName;  // offset: 0x0
    int mWidth;  // offset: 0x8
    int mHeight;  // offset: 0xc
} stBrowserSizeParam;

class sBrowser : public cSystem
{
    // inferred: sGUIExt::setBrowserNoCloseMode names sBrowser::mIsInputEnable
    friend class sGUIExt;
    // inferred: uGUIBrowserBG::moveEvent names sBrowser::mIsInputEnable
    friend class uGUIBrowserBG;
public:
    enum
    {
        FUNCTION_BUTTON_BACK = 1,
        FUNCTION_BUTTON_FORWARD = 2,
        FUNCTION_BUTTON_RELOAD = 4,
        FUNCTION_BUTTON_ENTER = 8,
    };
    enum
    {
        BROWSER_RNO_IDLE = 0,
        BROWSER_RNO_MOVE = 1,
        BROWSER_RNO_CLOSE = 2,
        BROWSER_RNO_RESTART = 3,
        BROWSER_RNO_FEEDBACK = 4,
    };
    enum
    {
        BROWSER_DISPLAY_MODE_HD = 0,
        BROWSER_DISPLAY_MODE_SD = 1,
    };
    enum
    {
        BROWSER_REQ_NONE = 0,
        BROWSER_REQ_EXEC = 1,
        BROWSER_REQ_CLOSE = 2,
        BROWSER_REQ_RESTART = 3,
        BROWSER_REQ_CALL_JS_FUNC = 4,
    };
    enum
    {
        BROWSER_STATUS_NONE = 0,
        BROWSER_STATUS_EXEC = 1,
        BROWSER_STATUS_REQ_EXEC = 2,
        BROWSER_STATUS_CLOSE = 3,
        BROWSER_STATUS_REQ_CLOSE = 4,
        BROWSER_STATUS_RESTART = 5,
        BROWSER_STATUS_REQ_RESTART = 6,
        BROWSER_STATUS_REQ_CALL_JS_FUNC = 7,
    };
    enum
    {
        BROWSER_SIZE_TYPE_BNR = 0,
        BROWSER_SIZE_TYPE_WIN = 1,
        BROWSER_SIZE_TYPE_WINFULL = 2,
        BROWSER_SIZE_TYPE_FULL = 3,
        BROWSER_SIZE_TYPE_NUM = 4,
    };
    enum
    {
        VALID_DEVICE_MOUSE = 0,
        VALID_DEVICE_PAD = 1,
        VALID_DEVIDE_INVALID = 2,
    };
public:
    class MyDTI;
    struct FONT_WORK_STATE;
    struct VERTEX;
public:
    using JSCallback_jumpSetSizeByType = void(MtObject::*)(s32&, s32&, MT_CTSTR, MT_CTSTR);
    using JSCallback_jumpSetPos = void(MtObject::*)(s32&, s32&, MT_CTSTR);
    using JSCallback_jumpSetSize = void(MtObject::*)(s32&, s32&, MT_CTSTR);
    using JSCallback_jumpSetPosSize = void(MtObject::*)(s32&, s32&, s32&, s32&, MT_CTSTR);
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct FONT_WORK_STATE
    {
    public:
        enum DECL
        {
            READY = 0,
            IMPACT = 1,
            FEEDBACK = 2,
        };
    };
public:
    struct VERTEX
    {
    public:
        f32 x;  // offset: 0x0
        f32 y;  // offset: 0x4
        f32 z;  // offset: 0x8
        u32 color;  // offset: 0xc
        f32 u;  // offset: 0x10
        f32 v;  // offset: 0x14
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
    static sBrowser* getInstance();
    cBrowserPS4* getBrowser();
    sBrowser();
    virtual ~sBrowser();
    void exec();
    void close();
    void restart();
    void kill();
    void resetError();
    void begin();
    virtual void move();  // vtable slot 7
    void feedbackorder();
    void draw();
    void draw2(cDraw* pDraw, u32 param);
    void setDrawBufferAlpha();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void callJSFunction(MT_CTSTR func_str);
    u32 getBrowserStatus();
    bool isBusy();
    void setErrorType(int type);
    int getErrorType();
    void setErrorKind(int kind);
    int getErrorKind();
    void setErrorCategory(int category);
    int getErrorCategory();
    void setErrorFlowType(int FlowType);
    int getErrorFlowType();
    void setDraw(bool isDraw);
    bool isDraw();
    void seCursortDraw(bool isDraw);
    bool isCursorDraw();
    int setupIMECore(const void* p);
    void moveIMECore();
    void drawIMECore();
    int setupErrorCore(int type, int kind);
    void moveErrorCore();
    void drawErrorCore();
    int setupJSDCore(const void*);
    void moveJSDCore();
    void drawJSDCore();
    void setBufferSize(u32 buf_size);
    void resetBufferSize();
    void gotoURL();
    void setURL(const MtString url);
    bool setPos(const MtPoint pos);
    void setSize(const MtSize size);
    void setSize2(const MtSize size);
    MtPoint getPos() const;
    MtSize getSize() const;
    void setCursorPos(const MtPoint pos);
    MtPoint getCursorPos() const;
    void* getFontData(u32 Index);
    u32 getFontDataSize(u32);
    bool loadFontData();
    void releaseFontData();
    u32 getDisplayMode();
    void setCOGAuthKey(MT_CTSTR pKey);
    MT_CTSTR getCOGAUthKey();
    void resetCOGAuthKey();
    void setOnetimeToken(MT_CTSTR pKey);
    MT_CTSTR getOnetimeToken();
    void resetOnetimeToken();
    void setLoginServerHost(MT_CTSTR pKey);
    MT_CTSTR getLoginServerHost();
    void resetLoginServerHost();
    void setLoginServerPort(u32 port);
    u32 getLoginServerPort();
    void resetLoginServerPort();
    void setCharacterToken(MT_CTSTR pKey);
    MT_CTSTR getCharacterToken();
    void resetCharacterToken();
    void setCogLoginSkip(bool flag);
    bool isCogLoginSkip();
    void setInputEnable(const bool isEnable);
    bool isInputEnable();
    rGUIFont* getGUIFont();
    bool isSNJFontDisp();
    void setFunctionButtonEnable(u32 FunctionButton);
    void setFunctionButtonDisable(u32 FunctionButton);
    u32 getFunctionButton() const;
    static void setPut1Code(SNJ_BROWSER_BITMAP* dstbmp, int dstx, int dsty, int dstdrww, int dstdrwh, unsigned short cod, unsigned int col, const SNJ_BROWSER_RECT* clp, const SNJ_BROWSER_FONTINFO* fntinf, int* pResult);
    void setSaveCOGID(MT_CTSTR COGID_string);
    MT_CTSTR getSaveCOGID();
    bool isLoadFinish();
    void setLoadFihish(bool);
    void setJSCallback_jumpSetSizeByType(MtObject* pThis, JSCallback_jumpSetSizeByType pFunc);
    void resetJSCallback_jumpSetSizeByType();
    void callJSCallback_jumpSetSizeByType(s32& Width, s32& Height, MT_CTSTR TypeName, MT_CTSTR Url);
    void setJSCallback_jumpSetSize(MtObject* pThis, JSCallback_jumpSetSize pFunc);
    void resetJSCallback_jumpSetSize();
    void callJSCallback_jumpSetSize(s32& Width, s32& Height, MT_CTSTR Url);
    void setJSCallback_jumpSetPos(MtObject* pThis, JSCallback_jumpSetPos pFunc);
    void resetJSCallback_jumpSetPos();
    void callJSCallback_jumpSetPos(s32& PosX, s32& PosY, MT_CTSTR Url);
    void setJSCallback_jumpSetPosSize(MtObject* pThis, JSCallback_jumpSetPosSize pFunc);
    void resetJSCallback_jumpSetPosSize();
    void callJSCallback_jumpSetPosSize(s32& PosX, s32& PosY, s32& Width, s32& Height, MT_CTSTR Url);
    bool getBrowserSizeFromType(MT_CTSTR TypeName, MtSize& Size);
    rTexture* getBrowserTexture();
    void* getDrawTextureHandele();
    u32 checkValidDevice();
    s32 getNFBFreeMemory();
    s32 getNFBLongestFreeMemory();
protected:
    void execCore();
    void closeCore();
    void setTextureAccessEnable(bool isEnable);
    bool isTextureAccessEnable();
    MtInt2 getScroll() const;
    static int setupIME(const void* p);
    static void moveIME();
    static void drawIME();
    static int setupError(int type, int kind);
    static void moveError();
    static void drawError();
    static int setupJSD(const void* p);
    static void moveJSD();
    static void drawJSD();
public:
    u32 mFunctionButton;  // offset: 0x14
protected:
    cBrowserPS4* mpBrowser;  // offset: 0x18
    u32 mBufferSize;  // offset: 0x20
    void* mpBuffer;  // offset: 0x28
    u32 mRno;  // offset: 0x30
    MtString mURL;  // offset: 0x38
    MtPoint mPos;  // offset: 0x40
    MtSize mSize;  // offset: 0x48
    MtSize mSize2;  // offset: 0x50
    bool mIsSNJFontDisp;  // offset: 0x58
    u32 mDrawPrioBase;  // offset: 0x5c
    u32 mDrawPrioFont;  // offset: 0x60
    s32 mDrawDepth;  // offset: 0x64
    MtRect mDrawRect;  // offset: 0x68
    nDraw::RasterizerState* mpRSS;  // offset: 0x78
    u32 mDisplayMode;  // offset: 0x80
    u32 mFontVertexNum;  // offset: 0x84
    nDraw::VertexBuffer* mpFontVertex;  // offset: 0x88
    MtRect mpFontClipRect[2048];  // offset: 0x90
    TICKET mArcTichet;  // offset: 0x8090
    MtString mSaveCOGID;  // offset: 0x8098
    s32 mErrorType;  // offset: 0x80a0
    s32 mErrorKind;  // offset: 0x80a4
    s32 mErrorCategory;  // offset: 0x80a8
    s32 mErrorFlowType;  // offset: 0x80ac
    MT_CHAR mInputText_utf8[2048];  // offset: 0x80b0
    u8 mOutputText_utf8[6144];  // offset: 0x88b0
    u32 mOutputText_utf8Length;  // offset: 0xa0b0
    u8 mOutputText_sjis[2048];  // offset: 0xa0b4
    u32 mOutputText_sjisLength;  // offset: 0xa8b4
    MtString mOutputText;  // offset: 0xa8b8
    void* mpBrowserFontBinary[2];  // offset: 0xa8c0
    void* mpBrowserFont[2];  // offset: 0xa8d0
    u32 mBrowserFontDataSize[2];  // offset: 0xa8e0
    rGUIFont* mprGUIFont;  // offset: 0xa8e8
    rTexture* mprBrowserFont[2];  // offset: 0xa8f0
    MtString mCOGAuthKey;  // offset: 0xa900
    MtString mOnetimeToken;  // offset: 0xa908
    MtString mLoginServerHost;  // offset: 0xa910
    MtString mCharacterToken;  // offset: 0xa918
    u32 mLoginServerPort;  // offset: 0xa920
    u32 mBrowserRequest;  // offset: 0xa924
    u32 mBrowserStatus;  // offset: 0xa928
    bool mIsDraw;  // offset: 0xa92c
    bool mIsCursorDraw;  // offset: 0xa92d
    bool mIsInputEnable;  // offset: 0xa92e
    bool mIsCogLoginSkip;  // offset: 0xa92f
    bool mIsInputEnableMenu;  // offset: 0xa930
    MtString mJSFunction;  // offset: 0xa938
    JSCallback_jumpSetSizeByType mJSCallback_jumpSetSizeByType;  // offset: 0xa940
    MtObject* mpJSCallback_jumpSetSizeByType_this;  // offset: 0xa950
    JSCallback_jumpSetPos mJSCallback_jumpSetPos;  // offset: 0xa958
    MtObject* mpJSCallback_jumpSetPos_this;  // offset: 0xa968
    JSCallback_jumpSetSize mJSCallback_jumpSetSize;  // offset: 0xa970
    MtObject* mpJSCallback_jumpSetSize_this;  // offset: 0xa980
    JSCallback_jumpSetPosSize mJSCallback_jumpSetPosSize;  // offset: 0xa988
    MtObject* mpJSCallback_jumpSetPosSize_this;  // offset: 0xa998
    MtTypedArray<cBrowserRequest> mRequest;  // offset: 0xa9a0
    nDraw::Texture* mpDrawTexture;  // offset: 0xa9c0
    nDraw::Texture* mpFontRenerWorkTexture;  // offset: 0xa9c8
    FONT_WORK_STATE::DECL mpFontState;  // offset: 0xa9d0
    rTextureMemory* mpTextureMemory;  // offset: 0xa9d8
    bool mIsTextureAccessEnable;  // offset: 0xa9e0
    bool mIsNextFeedBack;  // offset: 0xa9e1
    bool mFontFeedBack;  // offset: 0xa9e2
private:
    static sBrowser* mpInstance;
public:
    static MyDTI DTI;
    static const stBrowserSizeParam mBrowserSizeTable[4];
};

// Inline, no code of its own: checked where it is inlined.
inline sBrowser* sBrowser::getInstance() {
    return ::sBrowser::mpInstance;
}

// Inline, no code of its own: checked where it is inlined.
inline cBrowserPS4* sBrowser::getBrowser() {
    return this->mpBrowser;
}

// Inline, no code of its own: checked where it is inlined.
inline int sBrowser::getErrorType() {
    return this->mErrorType;
}

// Inline, no code of its own: checked where it is inlined.
inline int sBrowser::getErrorKind() {
    return this->mErrorKind;
}

// Inline, no code of its own: checked where it is inlined.
inline int sBrowser::getErrorFlowType() {
    return this->mErrorFlowType;
}

// Inline, no code of its own: checked where it is inlined.
inline bool sBrowser::isInputEnable() {
    return this->mIsInputEnable;
}
