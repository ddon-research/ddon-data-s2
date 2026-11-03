#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cDraw;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
namespace nGUI { struct FLOW; }
class rGUI;

// Declarations
class uGUISkillLvUp;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUISkillLvUp : public uGUIBase
{
public:
    enum
    {
        TYPE_JOB_CHANGE = 0,
        TYPE_JOB_RELEASE = 1,
        TYPE_NORMAL_SKILL_GET = 2,
        TYPE_CUSTOM_SKILL_GET = 3,
        TYPE_ABILITY_GET = 4,
        TYPE_NORMAL_SKILL_LV_UP = 5,
        TYPE_CUSTOM_SKILL_LV_UP = 6,
        TYPE_ABILITY_LV_UP = 7,
        TYPE_CUSTOM_SKILL_RELEASE = 8,
        TYPE_ABILITY_RELEASE = 9,
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
    uGUISkillLvUp();
    virtual ~uGUISkillLvUp();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    void setLvUpInfo(u32 type, u32 job_id, u32 id, u32 icon_id, u32 lv);
private:
    void updateMove();
    void updateExit();
    virtual void evChangeFlow(const nGUI::FLOW* pNewFlow, const nGUI::FLOW* pNowFlow);  // vtable slot 47
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    cGUIInstNull* mpInstNull;  // offset: 0x8d0
    u32 mType;  // offset: 0x8d8
    u32 mJobId;  // offset: 0x8dc
    u32 mId;  // offset: 0x8e0
    u32 mIconId;  // offset: 0x8e4
    u32 mLv;  // offset: 0x8e8
    cGUIInstNull* mpInstNullSkillIcon;  // offset: 0x8f0
    cGUIInstAnimation* mpInstAnim;  // offset: 0x8f8
    cGUIObjMessage* mpObjMsgName;  // offset: 0x900
    cGUIObjMessage* mpObjMsgLv;  // offset: 0x908
    cGUIObjMessage* mpObjMsgLvUnit;  // offset: 0x910
    cGUIObjMessage* mpObjMsgJobName;  // offset: 0x918
    uGUIBase::cReferenceUIIconSkill mSkill;  // offset: 0x920
    uGUIBase::cReferenceUIIconJob mJob;  // offset: 0x9e0
    f32 mTimer;  // offset: 0xa38
public:
    static MyDTI DTI;
};

inline void* uGUISkillLvUp::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
