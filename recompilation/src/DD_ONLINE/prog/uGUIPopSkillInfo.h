#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtString.h"
#include "uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cGUIInstNull;
class cGUIObjMessage;
class rGUI;
class rGUIMessage;

// Declarations
class uGUIPopSkillInfo;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIPopSkillInfo : public uGUIBase
{
public:
    enum
    {
        MODE_STATUS = 0,
        MODE_SKILL = 1,
    };
    enum
    {
        TYPE_CUSTOM = 0,
        TYPE_NORMAL = 1,
        TYPE_ABILITY = 2,
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
    uGUIPopSkillInfo(bool isChatSubMenu);
    virtual ~uGUIPopSkillInfo();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    void setMode(u32 mode);
    void setupInfo(u32 type, u32 job_id, u32 id, u32 lv, bool isPlayer, u32 need_pl_lv, u32 now_pl_lv, u32 need_jp, u32 now_jp);
private:
    void updateMove();
    void updateExit();
    MT_CTSTR getMsg(u32 index);
    MT_CTSTR getCmnMsg(u32 index);
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    rGUIMessage* mpGMDRes;  // offset: 0x8d0
    rGUIMessage* mpGMDAbilityInfo;  // offset: 0x8d8
    cGUIInstNull* mpInstNull;  // offset: 0x8e0
    u32 mMode;  // offset: 0x8e8
    cGUIObjMessage* mpObjMsgTitle;  // offset: 0x8f0
    cGUIObjMessage* mpObjMsgName;  // offset: 0x8f8
    cGUIObjMessage* mpObjMsgLv;  // offset: 0x900
    cGUIObjMessage* mpObjMsgLvVal;  // offset: 0x908
    cGUIObjMessage* mpObjMsgEffectTitle;  // offset: 0x910
    cGUIObjMessage* mpObjMsgEffectText;  // offset: 0x918
    cGUIObjMessage* mpObjMsgCaptionTitle;  // offset: 0x920
    cGUIObjMessage* mpObjMsgCaptionText;  // offset: 0x928
    cGUIObjMessage* mpObjMsgTermTitle;  // offset: 0x930
    cGUIObjMessage* mpObjMsgTerm00;  // offset: 0x938
    cGUIObjMessage* mpObjMsgTerm01;  // offset: 0x940
    cGUIObjMessage* mpObjMsgTerm02;  // offset: 0x948
    cGUIInstNull* mpInstNullLvIcon;  // offset: 0x950
    uGUIBase::cReferenceUIIconSkill mIcon;  // offset: 0x958
    MtStringEx<64> mTempStr;  // offset: 0xa18
public:
    static MyDTI DTI;
};

inline void* uGUIPopSkillInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
