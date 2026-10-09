#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "nDDOUtility.h"
#include "nObjCondition.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtPropertyList;
class cpOcdCtrl;
namespace nObjCondition { struct stOcdActiveData; }
class uDDOModel;

// Declarations
class cOcdMsgCtrl2;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using cOcdActiveDataArray = nDDOUtility::cArray<nDDOUtility::cArray<nObjCondition::stOcdActiveData, 32>, 7>;
using size_t = _Sizet;
using u32 = unsigned int;

class cOcdMsgCtrl2 : public MtObject
{
    // inferred: cpOcdCtrl::isRecoverEnd names cpOcdCtrl::mOcdMsgCtrl2.mIsRecoverEnd
    friend class cpOcdCtrl;
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
    cOcdMsgCtrl2();
    virtual ~cOcdMsgCtrl2();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void updatePtr();
    void setOwner(cpOcdCtrl* pOwner, uDDOModel* pModel);
    void checkReceiveData();
    void updateMsgData();
    void notifyReceiveMsg(bool recvFlag);
    bool isRecoverEnd() const;
    void notifyEndRecover();
private:
    void receiveOcdMsgData();
    void callBackReceiveActiveLv(u32 OcdUID, u32 currentLv, u32 receiveLv, bool initFlag, bool isAction);
    void callBackReceiveImmuneLv(u32 OcdUID, u32 currentLv, u32 receiveLv);
    bool isReceiveMsg() const;
    bool isRecoverMsg() const;
    void clearReceiveFlag();
    u32 checkResetActOcd() const;
private:
    cpOcdCtrl* mpOcdCtrl;  // offset: 0x8
    uDDOModel* mpModel;  // offset: 0x10
    cOcdActiveDataArray mCurrentData;  // offset: 0x18
    bool mIsReceiveMsg;  // offset: 0x1d8
    bool mInitFlag;  // offset: 0x1d9
    bool mIsRecoverEnd;  // offset: 0x1da
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline bool cOcdMsgCtrl2::isReceiveMsg() const {
    return this->mIsReceiveMsg;
}
