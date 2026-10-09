#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtString.h"
#include "cUIObject.h"
#include "nFurnitureMenuFlow.h"
#include "nGUIMyRoom.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;
class cFurniture;
namespace nFurnitureMenuFlow { class cFurnitureGroupListItems; }
namespace nFurnitureMenuFlow { class cFurnitureListItems; }
class rFurnitureGroup;
class rFurnitureLayout;
class rGUIMessage;
class uGUIMyRoom;
class uGUIMyRoomPopup;

// Declarations
class cFurnitureMenuFlow;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cFurnitureMenuFlow : public cUIObject, public nGUIMyRoom::cListInputEventHandler, public nGUIMyRoom::cPopupListInputEventHandler
{
public:
    enum STATE_ID
    {
        STATE_ID_INVALID = 0,
        STATE_ID_MYROOM_LOAD = 1,
        STATE_ID_MYROOM_INPUT = 2,
        STATE_ID_MYROOM_POPUP_LOAD = 3,
        STATE_ID_MYROOM_POPUP_INPUT = 4,
        STATE_ID_MYROOM_POPUP_CANCEL = 5,
        STATE_ID_MYROOM_POPUP_DECIDE = 6,
        STATE_ID_MYROOM_POPUP_WAIT = 7,
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
    cFurnitureMenuFlow();
    virtual ~cFurnitureMenuFlow();
    void updatePtr();
    void start(cFurniture& furniture, rFurnitureGroup* furnitureGroups, rGUIMessage* furnitureGroupNames, rFurnitureLayout* furnitureLayouts, rGUIMessage* furnitureLayoutNames, MT_CTSTR pawnName, u32 pawnJobId, u32 pawnJobLevel, u32 pawnCraftLevel);
    void end();
    void move(cFurniture& furniture);
    bool isMove() const;
    bool isRoomWearCamera() const;
private:
    virtual void onListInputEventSelect(uGUIMyRoom& guiMyRoom, u32 itemIndex);  // vtable slot 6
    virtual void onListInputEventDecide(uGUIMyRoom& guiMyRoom, u32 itemIndex);  // vtable slot 7
    virtual void onListInputEventCancel(uGUIMyRoom& guiMyRoom);  // vtable slot 8
    virtual void onPopupListInputEventSelect(uGUIMyRoomPopup& guiMyRoomPopup, u32 itemIndex, u32 itemListIndex);  // vtable slot 9
    virtual void onPopupListInputEventChange(uGUIMyRoomPopup& guiMyRoomPopup, u32 itemIndex, u32 itemListIndex);  // vtable slot 10
    virtual void onPopupListInputEventDecide(uGUIMyRoomPopup& guiMyRoomPopup);  // vtable slot 11
    virtual void onPopupListInputEventCancel(uGUIMyRoomPopup& guiMyRoomPopup);  // vtable slot 12
    void returnToMyRoomInput(uGUIMyRoom& guiMyRoom);
    void moveStateMyRoomLoad(uGUIMyRoom& guiMyRoom, cFurniture& furniture);
    void moveStateMyRoomInput(uGUIMyRoom& guiMyRoom, cFurniture& furniture);
    void moveStateMyRoomPopupLoad(uGUIMyRoomPopup& guiMyRoomPopup, uGUIMyRoom& guiMyRoom, cFurniture& furniture);
    void moveStateMyRoomPopupInput(uGUIMyRoomPopup& guiMyRoomPopup, uGUIMyRoom& guiMyRoom, cFurniture& furniture);
    void moveStateMyRoomPopupCancel(uGUIMyRoomPopup& guiMyRoomPopup, uGUIMyRoom& guiMyRoom, cFurniture& furniture);
    void moveStateMyRoomPopupDecide(uGUIMyRoomPopup& guiMyRoomPopup, uGUIMyRoom& guiMyRoom, cFurniture& furniture);
    void moveStateMyRoomPopupWait(uGUIMyRoomPopup& guiMyRoomPopup, uGUIMyRoom& guiMyRoom, cFurniture& furniture);
private:
    STATE_ID mStateId;  // offset: 0x18
    rFurnitureGroup* mFurnitureGroups;  // offset: 0x20
    rGUIMessage* mFurnitureGroupNames;  // offset: 0x28
    rFurnitureLayout* mFurnitureLayouts;  // offset: 0x30
    rGUIMessage* mFurnitureLayoutNames;  // offset: 0x38
    uGUIMyRoom* mGUIMyRoom;  // offset: 0x40
    uGUIMyRoomPopup* mGUIMyRoomPopup;  // offset: 0x48
    MtString mPawnName;  // offset: 0x50
    u32 mPawnJobId;  // offset: 0x58
    u32 mPawnJobLevel;  // offset: 0x5c
    u32 mPawnCraftLevel;  // offset: 0x60
    u32 mCameraNo;  // offset: 0x64
    u32 mItemId;  // offset: 0x68
    u32 mItemIdRequest;  // offset: 0x6c
    nFurnitureMenuFlow::cFurnitureGroupListItems mFurnitureGroupListItems;  // offset: 0x70
    nFurnitureMenuFlow::cFurnitureListItems mFurnitureListItems;  // offset: 0xa8
public:
    static MyDTI DTI;
};
