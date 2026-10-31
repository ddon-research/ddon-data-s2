#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "nDDOUtility.h"
#include "../../generated/shared/nKeyCustom.h"
#include "uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cGUIInstAnimation;
class cGUIObjMessage;
class cGUIObjPolygon;
class rGUI;

// Declarations
class uGUITextHud;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUITextHud : public uGUIBase
{
public:
    enum BASE_OBJ_COLUMN
    {
        BASE_OBJ_COLUMN_LEFT = 0,
        BASE_OBJ_COLUMN_CENTER = 1,
        BASE_OBJ_COLUMN_RIGHT = 2,
        BASE_OBJ_COLUMN_NUM = 3,
    };
    enum BASE_OBJ_ROW
    {
        BASE_OBJ_ROW_TOP = 0,
        BASE_OBJ_ROW_CENTER = 1,
        BASE_OBJ_ROW_BOTTOM = 2,
        BASE_OBJ_ROW_NUM = 3,
    };
public:
    class MyDTI;
public:
    using BaseObjs = nDDOUtility::cArray<nDDOUtility::cArray<cGUIObjPolygon*, 3>, 3>;
    using BaseObjColumn = nDDOUtility::cArray<cGUIObjPolygon*, 3>;
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
    uGUITextHud();
    virtual ~uGUITextHud();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    void setMessage(u32 hudMsgId, u32 optionHudMsgId);
    void setMessage(u32 hudMsgId, nKeyCustom::KB_CUSTOM keyCustom, bool isIgnoreModifier);
    void erase();
private:
    void updateExit();
    void updateMain();
    bool updateMessage();
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    BaseObjs mBaseObjs;  // offset: 0x8d0
    cGUIInstAnimation* mpINST_msg_text;  // offset: 0x918
    cGUIObjMessage* mpOBJ_msg_text_m_text;  // offset: 0x920
    u32 mHudMsgId;  // offset: 0x928
    u32 mOptionHudMsgId;  // offset: 0x92c
    nKeyCustom::KB_CUSTOM mOptionKeyCustom;  // offset: 0x930
    bool mOptionIsIgnoreModifier;  // offset: 0x934
    u32 mRequestHudMsgId;  // offset: 0x938
    u32 mRequestOptionHudMsgId;  // offset: 0x93c
    nKeyCustom::KB_CUSTOM mRequestOptionKeyCustom;  // offset: 0x940
    bool mRequestOptionIsIgnoreModifier;  // offset: 0x944
    uGUIBase::cInputGuideMonitor mInputGuideMonitor;  // offset: 0x948
public:
    static MyDTI DTI;
private:
    static const u32 BaseObjIds[3][3];
};
