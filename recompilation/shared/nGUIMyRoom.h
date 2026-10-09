#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
class uGUIMyRoom;
class uGUIMyRoomPopup;

// Declarations
namespace nGUIMyRoom { class cListInputEventHandler; }
namespace nGUIMyRoom { class cListItems; }
namespace nGUIMyRoom { class cPopupListInputEventHandler; }
namespace nGUIMyRoom { class cPopupListItems; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using u32 = unsigned int;

namespace nGUIMyRoom {
    class cListInputEventHandler
    {
    public:
        cListInputEventHandler();
        virtual ~cListInputEventHandler() {}
        virtual void onListInputEventSelect(uGUIMyRoom& guiMyRoom, u32 itemIndex);  // vtable slot 2
        virtual void onListInputEventDecide(uGUIMyRoom& guiMyRoom, u32 itemIndex);  // vtable slot 3
        virtual void onListInputEventCancel(uGUIMyRoom& guiMyRoom);  // vtable slot 4
    };
}  // namespace nGUIMyRoom

namespace nGUIMyRoom {
    class cListItems
    {
    public:
        cListItems();
        virtual ~cListItems() {}
        virtual u32 getItemNum() const = 0;  // vtable slot 2
        virtual MT_CTSTR getItemString(u32) const = 0;  // vtable slot 3
        virtual bool isItemDisable(u32 itemIndex) const;  // vtable slot 4
    };
}  // namespace nGUIMyRoom

namespace nGUIMyRoom {
    class cPopupListInputEventHandler
    {
    public:
        cPopupListInputEventHandler();
        virtual ~cPopupListInputEventHandler() {}
        virtual void onPopupListInputEventSelect(uGUIMyRoomPopup& guiMyRoomPopup, u32 itemIndex, u32 itemListIndex);  // vtable slot 2
        virtual void onPopupListInputEventChange(uGUIMyRoomPopup& guiMyRoomPopup, u32 itemIndex, u32 itemListIndex);  // vtable slot 3
        virtual void onPopupListInputEventDecide(uGUIMyRoomPopup& guiMyRoomPopup);  // vtable slot 4
        virtual void onPopupListInputEventCancel(uGUIMyRoomPopup& guiMyRoomPopup);  // vtable slot 5
    };
}  // namespace nGUIMyRoom

namespace nGUIMyRoom {
    class cPopupListItems
    {
    public:
        cPopupListItems();
        virtual ~cPopupListItems() {}
        virtual u32 getItemNum() const = 0;  // vtable slot 2
        virtual MT_CTSTR getItemString(u32) const = 0;  // vtable slot 3
        virtual u32 getItemListIndex(u32) const = 0;  // vtable slot 4
        virtual u32 getItemListSize(u32) const = 0;  // vtable slot 5
        virtual MT_CTSTR getItemListString(u32, u32) const = 0;  // vtable slot 6
    };
}  // namespace nGUIMyRoom
