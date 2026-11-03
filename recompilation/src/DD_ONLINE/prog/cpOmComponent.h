#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtGeomOBB.h"
#include "../../MT/MtString.h"
#include "cpComponent.h"
#include "../../generated/shared/nDDOModel.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtGeomOBB;
class MtObject;
class MtPropertyList;
class MtString;
class cDraw;
class cHitNode;
class cTalkMsgData;
class uDDOModel;
class uGUIBase;
class uOmModel;

// Declarations
class cpOmBase;
class cpOmLadder;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cpOmBase : public cpComponent
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
    cpOmBase();
    virtual ~cpOmBase();
    virtual void move();  // vtable slot 7
    virtual void kill();  // vtable slot 8
    virtual void updatePtr();  // vtable slot 9
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void setTouch(uDDOModel* pUnit);  // vtable slot 15
    virtual void finishTouch(nDDOModel::TOUCH_RELEASE_TYPE type);  // vtable slot 16
    virtual void cancelTouch();  // vtable slot 17
    bool isCanTouch(uDDOModel* pu);
    bool isUIOpen();
    bool reqDialog(s32 dialogType, MT_CTSTR mainMsg, s32 defPos, MT_CTSTR choice1, MT_CTSTR choice2, MT_CTSTR choice3, MT_CTSTR choice4);
    bool reqDialogEx(MT_CTSTR title, s32 defPos, MT_CTSTR* pselect, u32 selectNum);
    bool reqText(u32 textType, u32 textNo, u32 questNo);
    cTalkMsgData* getMsgData(u32 textType, u32 textNo, u32 questNo);
    void createGUISingleton(const MtDTI* pDTI);
    void createGUISingleton(MT_CTSTR name);
    void deleteGUISingleton();
    bool isMoveGUISingleton();
    bool isEndGUISingleton();
private:
    void reqTextDialog(cTalkMsgData* pMsgData);
    void reqTextAnnounce(cTalkMsgData* pMsgData, u32 color);
public:
    virtual void initAction(uOmModel* puom);  // vtable slot 18
    bool isAreaMaster();
    bool hasKeyNo(u32 keyNo, bool isUse);
    void setPLAct(u32 actNo, bool isLoop);
    bool getLinkNav();
    void setLinkNav(bool islink);
    void setLinkNavEnd(bool islink);
    void setLinkNavExt(bool islink, bool update_obb, bool force_update);
    bool getUseItem();
    void setUseItem(bool isUsed);
    void setUseItemRno(bool isUsed, u32 rno);
    void setRno(u32 rno);
    void setRnoGimmick(u32 rno);
    void setGimmick(bool isUsed);
public:
    uOmModel* mpModel;  // offset: 0x50
    uDDOModel* mpTouchUnit;  // offset: 0x58
    bool mbSlave;  // offset: 0x60
    MtString mMessage;  // offset: 0x68
    bool mbDialog;  // offset: 0x70
protected:
    uGUIBase* mpGUISingleton;  // offset: 0x78
public:
    bool mbAreaMaster;  // offset: 0x80
    bool mbLoopAct;  // offset: 0x81
    bool mbFirst;  // offset: 0x82
    bool mbLinkNav;  // offset: 0x83
    bool mbNavEnd;  // offset: 0x84
    MtGeomOBB mNavOBB;  // offset: 0x90
    static MyDTI DTI;
};

class cpOmLadder : public cpComponent
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
    cpOmLadder();
    virtual ~cpOmLadder();
    virtual void updatePtr();  // vtable slot 9
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void kill();  // vtable slot 8
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void compMoveAfter();
    void setupModelUnit();
    virtual void draw(cDraw* pDraw) {}  // vtable slot 15
public:
    uOmModel* mpuOm;  // offset: 0x50
    bool mbSetup;  // offset: 0x58
    u32 mHeight;  // offset: 0x5c
    cHitNode* mpHitNode[3];  // offset: 0x60
    f32 mOfsY[24];  // offset: 0x78
    static MyDTI DTI;
    static const u32 UnitNum = 24;
};

inline void* cpOmBase::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cpOmLadder::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
