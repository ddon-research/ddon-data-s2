#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/cSystem.h"
#include "nDialog.h"

// Forward declarations
class MtAllocator;
class MtDTI;
struct MtNetError;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class cNetGameServer;
class cNetLoginServer;
namespace nDialog { struct stInfo; }

// Declarations
class sDialogBase;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class sDialogBase : public cSystem
{
    // inferred: cNetGameServer::isDispErrorDialog calls sDialogBase::getInfo
    friend class cNetGameServer;
    // inferred: cNetLoginServer::isDispErrorDialog calls sDialogBase::getInfo
    friend class cNetLoginServer;
public:
    class MyDTI;
    struct stDialogTbl;
    struct stConvRetMsgNo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stDialogTbl
    {
    public:
        MT_CTSTR pStr;  // offset: 0x0
        s32 msgId;  // offset: 0x8
    };
public:
    struct stConvRetMsgNo
    {
    public:
        s32 srcMsgNo;  // offset: 0x0
        s32 dstMsgNo;  // offset: 0x4
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
    sDialogBase();
    virtual ~sDialogBase();
    virtual void reset();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    static sDialogBase* getInstance();
private:
    bool isCellMsgDialog(const u32 errcode);
public:
    bool isDialogExecute();
    bool isDialogRequestEmpty();
    bool checkPause();
    bool checkPlayerStop();
    u32 request(nDialog::MSG_NO msgNo, nDialog::DLOG_TYPE type, nDialog::DLOG_ATTR attr, nDialog::DLOG_PRIO prio, const MtNetError* pNetError, void(*pFuncYes)(), void(*pFuncNo)(), void(*pFuncOk)(), void(*pFuncSel0)(), void(*pFuncSel1)(), void(*pFuncSel2)());
    void setFreeMessage(u32 handle, MT_CTSTR str);
    void closeDialog(u32 handle);
    void endRequestAll();
    void endRequestAllNetwork();
    static void callbackNativeMsgDialog(s32 buttonType, void* data);
    s32 reqNativeMsgDialog(nDialog::MSG_NO msgNo);
    void callbackCommonDialog(s32 result);
private:
    void clearStInfo(nDialog::stInfo& info);
    void setResult(nDialog::stInfo& info, nDialog::RESULT rlt);
    nDialog::stInfo* getInfo(u32 handle);
    bool isValidInfo(const nDialog::stInfo& info);
public:
    bool isActiveInfo(const nDialog::stInfo& info);
private:
    nDialog::stInfo* pullInfo();
    void setOrderInfo(nDialog::stInfo& info);
    void insertOrder(s32 orderId, s32 info_id);
    bool updateOrder();
    void deleteOrder(s32 info_id);
public:
    nDialog::RESULT getResult(u32 handle, bool auto_end);
    nDialog::SEL_CUR getRltSel(u32);
    void setAttr(u32, nDialog::DLOG_ATTR);
    void addAttr(u32, nDialog::DLOG_ATTR);
    nDialog::DLOG_ATTR getAttr(u32);
private:
    void setFunction(nDialog::stInfo& info, nDialog::FUNC f);
    nDialog::FUNC getFunction(nDialog::stInfo& info);
    bool isFuncEnd(nDialog::stInfo& info);
    bool isFuncFastEnd(nDialog::stInfo& info);
    MT_CTSTR getMsg(nDialog::MSG_NO msgNo);
    void dbgDialog();
public:
    const nDialog::stInfo& getCurrentInfo();
    u32 getAutoCloseTimer();
    u32 getYesOrNo();
    u32 getSelectCursor();
    static void callbackReturnTitle();
    bool isReqReturnTitle();
    void setReqReturnTitle(bool bFlg);
    static void callbackReturnLauncher();
    bool isReqReturnLauncher();
    void setReqReturnLauncher(bool bFlg);
    static void callbackOffline();
    s32 convReturnMsgNo(s32 msgNo);
private:
    nDialog::stInfo mInfo[8];  // offset: 0x18
    s32 mInfoOrderTbl[8];  // offset: 0xb58
    u32 mHandleNo;  // offset: 0xb78
    f32 mAutoCloseTimer;  // offset: 0xb7c
    u32 mYesOrNo;  // offset: 0xb80
    u32 mSelectCursor;  // offset: 0xb84
    bool mIsReqReturnTitle;  // offset: 0xb88
    bool mIsReqReturnLauncher;  // offset: 0xb89
public:
    static MyDTI DTI;
protected:
    static sDialogBase* mpInstance;
private:
    static const stDialogTbl msgTbl[23];
    static MT_CTSTR msg_no_tbl[23];
    static const stConvRetMsgNo convReturnMsgNoTbl[];
};

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline sDialogBase* sDialogBase::getInstance() {
    return ::sDialogBase::mpInstance;
}
