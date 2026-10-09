#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/cControl.h"
#include "../shared/nGUIExt.h"
#include "../shared/sGUIExt.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPoint;
class MtProperty;
class MtPropertyList;
class MtUI;
class cGUIInstAnimation;
class cGUIObjMessage;
class cGUIObjNull;
class cGUIObjPolygon;
class cGUIObjTexture;
class rGUI;
class rGUIMessage;
class rTexture;

// Declarations
class uGUIBrowserBG;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIBrowserBG : public uGUIBase
{
public:
    enum
    {
        CANCELMODE_DEFAULT = 0,
        CANCELMODE_NOACTIVE = 1,
    };
    enum
    {
        INPUTEVENT_CANCEL = 66,
        INPUTEVENT_NOACTIVE = 67,
        INPUTEVENT_SLEEP = 68,
        INPUTEVENT_REACTIVE = 69,
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
    MtPoint getBrowserPos();
    void setWebSize(f32 WebSizeW, f32 WebSizeH);
    void restart();
    void restart(bool isMenu, bool isShareNG);
    void reactive();
    void setCancelNoActive();
    void clearGuide();
    void addGuide(sGUIExt::BROWSER_GUIDE Type);
    void sleep();
    void setNoActive();
    nGUIExt::BROWSER_RESULT getBrowserResult();
    void setLowPriority();
    void resetPriority();
    void setBGDispOffMode(bool IsOn);
    void setKeyOff(bool IsOn);
    uGUIBrowserBG();
    virtual ~uGUIBrowserBG();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void adjustScale();  // vtable slot 84
private:
    virtual bool loadResource();  // vtable slot 76
    virtual void updatePtr();  // vtable slot 17
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void updateWait();
    u32 evCtrlCancel(cControl::Message* pMsg);
    u32 evCtrlExit(cControl::Message* pMsg);
    u32 evCtrlMouseClick(cControl::Message* pMsg);
    void initCommon();
    f32 getPanelObjectPosX(cGUIObjTexture* pObj);
    f32 getPanelObjectPosY(cGUIObjTexture* pObj);
    bool isCloseBrowser();
    void manageBrowserTex();
    void reInitBrowserTex();
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    rGUIMessage* mpGMDRes;  // offset: 0x8d0
    uGUIBase::cHorizontalList* mpCtrl;  // offset: 0x8d8
    uGUIBase::cReferenceUICloseBtn mClose;  // offset: 0x8e0
    f32 mWebSizeW;  // offset: 0x938
    f32 mWebSizeH;  // offset: 0x93c
    f32 mOfsActiveBarXFromUC;  // offset: 0x940
    f32 mOfsActiveBarYFromUC;  // offset: 0x944
    f32 mOfsCloseButtonXFromUR;  // offset: 0x948
    f32 mOfsCloseButtonYFromUR;  // offset: 0x94c
    f32 mOfsGuideXFromDL;  // offset: 0x950
    f32 mOfsGuideYFromDL;  // offset: 0x954
    f32 mDefaultW;  // offset: 0x958
    f32 mDefaultH;  // offset: 0x95c
    f32 mDefaultLeftW;  // offset: 0x960
    f32 mDefaultRightW;  // offset: 0x964
    f32 mDefaultTopH;  // offset: 0x968
    f32 mDefaultButtomH;  // offset: 0x96c
    f32 mDefaultLineTopOfsY;  // offset: 0x970
    f32 mDefaultLineButtomOfsY;  // offset: 0x974
    f32 mHeaderOfsX;  // offset: 0x978
    f32 mHeaderOfsY;  // offset: 0x97c
    f32 mActiveBarOfsY;  // offset: 0x980
    f32 mCloseButtonOfsX;  // offset: 0x984
    f32 mCloseButtonOfsY;  // offset: 0x988
    uGUIBase::cReferenceUIBtnGuide mGuide;  // offset: 0x990
    u32 mCancelMode;  // offset: 0xa28
    bool mIsMenu;  // offset: 0xa2c
    bool mIsBGDispOff;  // offset: 0xa2d
    bool mIsKeyOff;  // offset: 0xa2e
    rTexture* mpOrgTex;  // offset: 0xa30
    uGUIBase::cTexArcLoader mBrowserArea;  // offset: 0xa38
    nGUIExt::BROWSER_RESULT mBrowserResult;  // offset: 0xac0
    cGUIInstAnimation* mpHeader;  // offset: 0xac8
    cGUIObjPolygon* mpHeaderBar0;  // offset: 0xad0
    cGUIObjPolygon* mpHeaderBar1;  // offset: 0xad8
    cGUIObjPolygon* mpHeaderBar2;  // offset: 0xae0
    cGUIObjMessage* mpCaption;  // offset: 0xae8
    cGUIInstAnimation* mpCloseButton;  // offset: 0xaf0
    cGUIInstAnimation* mpGuide;  // offset: 0xaf8
    cGUIInstAnimation* mpPanel;  // offset: 0xb00
    cGUIObjNull* mpPanelBase;  // offset: 0xb08
    cGUIObjTexture* mpPanelUL;  // offset: 0xb10
    cGUIObjTexture* mpPanelUC;  // offset: 0xb18
    cGUIObjTexture* mpPanelUR;  // offset: 0xb20
    cGUIObjTexture* mpPanelCL;  // offset: 0xb28
    cGUIObjTexture* mpPanelCC;  // offset: 0xb30
    cGUIObjTexture* mpPanelCR;  // offset: 0xb38
    cGUIObjTexture* mpPanelDL;  // offset: 0xb40
    cGUIObjTexture* mpPanelDC;  // offset: 0xb48
    cGUIObjTexture* mpPanelDR;  // offset: 0xb50
    cGUIObjTexture* mpWebArea;  // offset: 0xb58
    cGUIObjNull* mpPanelULine;  // offset: 0xb60
    cGUIObjNull* mpPanelDLine;  // offset: 0xb68
    cGUIInstAnimation* mpLoadIcon;  // offset: 0xb70
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline nGUIExt::BROWSER_RESULT uGUIBrowserBG::getBrowserResult() {
    return this->mBrowserResult;
}
