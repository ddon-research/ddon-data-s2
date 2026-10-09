#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cpComponent.h"
#include "nDDOUtility.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
namespace nKeyCommand { struct stKeyCommand; }
class uDDOModel;
class uHuman;
class uModel;

// Declarations
class cpItemThrow;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cpItemThrow : public cpComponent
{
    // inferred: uHuman::setThrowItemId names cpItemThrow::mThrowItemId
    friend class uHuman;
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
    cpItemThrow();
    virtual ~cpItemThrow();
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 8
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    virtual void updatePtr();  // vtable slot 9
    bool requestThrowItem(u32 id, MT_CTSTR uid);
    void checkItemMode();
    uModel* getItemModel() const;
    bool isItemMode() const;
    MT_CTSTR getNowThrowItemUId() const;
    MT_CTSTR getThrowItemUId() const;
    void changeCommandItemTbl();
    void onItemMode();
    void offItemMode();
    void createItemOmModel();
    void releaseItemModel();
    void setThrowItemId(u32 id);
    u32 getThrowItemId() const;
protected:
    void setThrowItemUId(MT_CTSTR);
    bool isUseThrowItemEnable();
protected:
    bool mIsItemMode;  // offset: 0x50
    bool mIsRequestThrowAct;  // offset: 0x51
    f32 mItemReqKeepTime;  // offset: 0x54
    u32 mThrowItemId;  // offset: 0x58
    MT_CTSTR mThrowItemUId;  // offset: 0x60
    uHuman* mpHuman;  // offset: 0x68
    uDDOModel* mpItemModel;  // offset: 0x70
    nDDOUtility::cArray<nKeyCommand::stKeyCommand*, 4> mBackUpItemTblList;  // offset: 0x78
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline bool cpItemThrow::isItemMode() const {
    return this->mIsItemMode;
}

// Inline, no code of its own: checked where it is inlined.
inline MT_CTSTR cpItemThrow::getThrowItemUId() const {
    return this->mThrowItemUId;
}

// Inline, no code of its own: checked where it is inlined.
inline u32 cpItemThrow::getThrowItemId() const {
    return this->mThrowItemId;
}
