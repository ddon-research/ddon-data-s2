#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/cControl.h"
#include "../shared/uGUIBase.h"
#include "uGUIsMenuBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cControl;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class cGUIObjNull;
class cGUIObjTexture;
class rGUI;

// Declarations
class uGUIPopEventTop;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIPopEventTop : public uGUIsMenuBase
{
public:
    enum PR
    {
        PR_TEST = 0,
        PR_MAX = 1,
    };
    enum SW
    {
        SW_TEST = 0,
    };
public:
    class MyDTI;
    struct guiInst;
    struct guiOBJ;
    struct ctgryList;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct guiInst
    {
    public:
        cGUIInstNull* Null;  // offset: 0x0
        cGUIInstAnimation* bg;  // offset: 0x8
        cGUIInstNull* Null_all;  // offset: 0x10
        cGUIInstAnimation* msg_fix_plinfo;  // offset: 0x18
        cGUIInstAnimation* msg_title;  // offset: 0x20
        cGUIInstNull* Null_list;  // offset: 0x28
        cGUIInstAnimation* msg_list;  // offset: 0x30
        cGUIInstAnimation* fix_emblem;  // offset: 0x38
    };
public:
    struct guiOBJ
    {
    public:
        cGUIObjNull* msg_title_null_mission;  // offset: 0x0
        cGUIObjNull* msg_fix_plinfo_Null;  // offset: 0x8
        cGUIObjMessage* msg_fix_plinfo_m_plinfo;  // offset: 0x10
        cGUIObjMessage* msg_title_m_title;  // offset: 0x18
        cGUIObjMessage* msg_title_m_mission;  // offset: 0x20
        cGUIObjMessage* msg_list_m_pt;  // offset: 0x28
        cGUIObjMessage* msg_list_m_num;  // offset: 0x30
        cGUIObjMessage* msg_list_m_ctgry;  // offset: 0x38
        cGUIObjTexture* bg_left_bottom;  // offset: 0x40
        cGUIObjTexture* bg_right_bottom;  // offset: 0x48
        cGUIObjTexture* bg_center_bottom00;  // offset: 0x50
        cGUIObjTexture* bg_left_center00;  // offset: 0x58
        cGUIObjTexture* bg_left_center01;  // offset: 0x60
        cGUIObjTexture* bg_right_center00;  // offset: 0x68
        cGUIObjTexture* bg_right_center01;  // offset: 0x70
        cGUIObjTexture* bg_center_center;  // offset: 0x78
        cGUIObjTexture* msg_fix_plinfo_left_bottom;  // offset: 0x80
        cGUIObjTexture* msg_fix_plinfo_right_bottom;  // offset: 0x88
        cGUIObjTexture* msg_fix_plinfo_center_bottom;  // offset: 0x90
        cGUIObjTexture* msg_fix_plinfo_left_center;  // offset: 0x98
        cGUIObjTexture* msg_fix_plinfo_right_center;  // offset: 0xa0
        cGUIObjTexture* msg_fix_plinfo_center_center;  // offset: 0xa8
    };
public:
    struct ctgryList
    {
    public:
        ctgryList();
    public:
        cGUIInstNull* inst_null;  // offset: 0x0
        cGUIInstAnimation* inst_list;  // offset: 0x8
        cGUIObjMessage* obj_pt;  // offset: 0x10
        cGUIObjMessage* obj_num;  // offset: 0x18
        cGUIObjMessage* obj_ctgry;  // offset: 0x20
        cGUIObjMessage* obj_rank;  // offset: 0x28
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
    uGUIPopEventTop();
    virtual ~uGUIPopEventTop();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    bool setProc(PR proc, bool force);
private:
    virtual void updateInit();  // vtable slot 93
    void updateWait();
    void updateExit();
    void updateInfo();
    bool changeSizeWindow();
    u32 evCtrlVMove(cControl::Message* msg);
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
private:
    guiInst mDataInst;  // offset: 0x958
    guiOBJ mDataObj;  // offset: 0x998
    ctgryList mCtgryList[10];  // offset: 0xa48
    rGUI* mpGUIRes;  // offset: 0xc28
    PR mProc;  // offset: 0xc30
    f32 mOffsetListY;  // offset: 0xc34
    u32 mCategoryNum;  // offset: 0xc38
    cControl* mpButtonCtrl;  // offset: 0xc40
    uGUIBase::cVerticalList* mpVCtrl;  // offset: 0xc48
    uGUIBase::cHorizontalList* mpHCtrl;  // offset: 0xc50
    bool mbSetupInfo;  // offset: 0xc58
public:
    static MyDTI DTI;
    static const u32 ctgry_max = 10;
};
