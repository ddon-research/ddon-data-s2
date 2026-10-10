#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/MtString.h"
#include "../shared/cUIObject.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtString;
class MtVector3;
class cGUIInstNull;
class cGUIObjNull;
class uGUICaplinkFilter;
class uGUICaplinkMessage;
class uGUICaplinkProfile;
class uGUICaplinkTopMenu;
class uGUIDialogTextBox;
class uGUIPopCmd01;
class uGUISystemMsg;

// Declarations
class uGUICaplinkMenuBase;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUICaplinkMenuBase : public uGUIBase
{
public:
    enum
    {
        SUB_RESULT_NONE = 0,
        SUB_RESULT_SUCCESS = 1,
        SUB_RESULT_CHAT = 2,
        SUB_RESULT_TALK_LIST = 3,
    };
public:
    class MyDTI;
    class cCmdVal;
    struct stSubMenuInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cCmdVal : public cUIObject
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
        virtual const MtDTI& getDTI() const;  // vtable slot 5
        static MtAllocator* getAllocator();
        static void setAllocator(u32);
        static void operator delete(void* p_addr);
        static void usage();
        static void* operator new(size_t sz, u32 align);
        static void* operator new[](size_t sz, u32 align);
        static void* operator new(size_t sz, void* p_addr);
        static void* operator new[](size_t sz, void* p_addr);
        static void operator delete[](void* p_addr);
        static void operator delete(void* p_addr, u32 align);
        static void operator delete[](void* p_addr, u32 align);
        cCmdVal();
        cCmdVal(u32 val);
    public:
        u32 mVal;  // offset: 0x8
        static MyDTI DTI;
    };
public:
    struct stSubMenuInfo
    {
    public:
        u32 ret;  // offset: 0x0
        bool enable;  // offset: 0x4
        MT_CTSTR msg;  // offset: 0x8
    };
public:
    static MtDTI* getMyDTIPtr();
    virtual const MtDTI& getDTI() const;  // vtable slot 5
    static MtAllocator* getAllocator();
    static void setAllocator(u32);
    static void usage();
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete(void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
    uGUICaplinkMenuBase(u32 initFlags);
    virtual ~uGUICaplinkMenuBase();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    virtual void update();  // vtable slot 78
    void setOwner(uGUICaplinkTopMenu* pOwner);
    uGUICaplinkTopMenu* getOwner();
    u32 getSubMenuResult();
protected:
    void initProf(MT_CTSTR unique_id);
    void updateProf();
    void initFriendRequest(MT_CTSTR unique_id, MT_CTSTR name);
    void updateFriendRequest();
    void initAttribute(MT_CTSTR unique_id);
    bool updateAttribute();
    void initTag(MT_CTSTR unique_id);
    void updateTag();
    void initInvite(MT_CTSTR unique_id, MT_CTSTR name);
    void updateInvite();
    void initReport(MT_CTSTR unique_id, s32 place);
    void updateReport();
    void initBeginTalk();
    bool updateBeginTalk();
    void initAddTalk(s32 id_type, MT_CTSTR id);
    bool updateAddTalk();
    void initRelease(MT_CTSTR unique_id, MT_CTSTR name);
    bool updateRelease();
    void initLeave(s32 id_type, MT_CTSTR id, MT_CTSTR name);
    bool updateLeave();
    void initRename(MT_CTSTR id);
    bool updateRename();
    void initResign(MT_CTSTR id, MT_CTSTR name);
    bool updateResign();
    void initDelete(s32 id_type, MT_CTSTR id, MT_CTSTR name);
    bool updateDelete();
    void reqNotice(MT_CTSTR msg, MT_CTSTR analyze0, MT_CTSTR analyze1);
    void setSystemMsgText(MT_CTSTR msg, MT_CTSTR analyze0, MT_CTSTR analyze1);
    bool isEndNotice();
    void reqDialog(MT_CTSTR msg, MT_CTSTR analyze0, MT_CTSTR analyze1, s32 def_pos);
    s32 updateDialog();
    void reqMessageDialog(MT_CTSTR title, MT_CTSTR msg, MT_CTSTR text, MT_CTSTR text_analyze, MT_CTSTR decide, MT_CTSTR cancel, bool isInput);
    s32 updateMessageDialog();
    void createSubMenu();
    void addSubMenu(MT_CTSTR pMsg, bool isEnable, u32 index);
    bool isEndSubMenu();
    u32 callbackCmd(MtObject* pCaller, MtObject* pVal);
    u32 getSubMenuSelect();
    // Address: 0x01ae17d0 - 0x01ae17d1 (1 bytes)
    virtual void returnFlow() {}  // vtable slot 91
    // Address: 0x01ae17e0 - 0x01ae17e1 (1 bytes)
    virtual void returnEnd() {}  // vtable slot 92
    void clearString();
    void setOwnerChatInfo(s32 id_type, MT_CTSTR id);
    void callPointer();
protected:
    u32 mRnoSubMenu;  // offset: 0x8c8
    u32 mCmdSelect;  // offset: 0x8cc
    u32 mSubResult;  // offset: 0x8d0
    MtString mUniqueId;  // offset: 0x8d8
    MtString mName;  // offset: 0x8e0
    MtString mMessage;  // offset: 0x8e8
    s32 mVal[4];  // offset: 0x8f0
    MtVector3 mSubMenuPos;  // offset: 0x900
    cGUIInstNull* mpInstNullPointer;  // offset: 0x910
    cGUIObjNull* mpObjNullPointer;  // offset: 0x918
    MtTypedArray<cCmdVal> mCmdVal;  // offset: 0x920
    uGUICaplinkTopMenu* mpOwner;  // offset: 0x940
    uGUIDialogTextBox* mpGUITextBox;  // offset: 0x948
    uGUISystemMsg* mpGUISystemMsg;  // offset: 0x950
    uGUIPopCmd01* mpGUIPopCmd;  // offset: 0x958
    uGUICaplinkProfile* mpGUICaplinkProfile;  // offset: 0x960
    uGUICaplinkMessage* mpGUICaplinkMessage;  // offset: 0x968
    uGUICaplinkFilter* mpGUICaplinkFilter;  // offset: 0x970
public:
    static MyDTI DTI;
protected:
    static const u32 val_num = 4;
};

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline uGUICaplinkMenuBase::cCmdVal::cCmdVal() {
    // inferred: the base constructor inlined with no DWARF copy left no code: cUIObject() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->mVal = static_cast<u32>(0);
}
