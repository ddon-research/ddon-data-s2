#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/nDDOUtility.h"
#include "../shared/nHumanMsg.h"
#include "../shared/uGUIBaseExt.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cGUIInstAnimation;
namespace nGUIBaseExt { struct ResInfo; }

// Declarations
class uGUIHudCustomSkillPallet;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using time_t = long int;
using t64 = time_t;
using u32 = unsigned int;

class uGUIHudCustomSkillPallet : public uGUIBaseExtHud
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
    uGUIHudCustomSkillPallet();
    virtual ~uGUIHudCustomSkillPallet();
    void initCustomSkillGroup(nHuman::CUSTOM_SKILL_GROUP customSkillGroup);
    void switchCustomSkillGroup(nHuman::CUSTOM_SKILL_GROUP customSkillGroup);
protected:
    virtual MT_CTSTR getLoadArcTagName(u32 arcIndex) const;  // vtable slot 91
    virtual const nGUIBaseExt::ResInfo* getGuiResInfo() const;  // vtable slot 93
    virtual t64 getGuiResUpdateTime() const;  // vtable slot 94
    virtual void onSetupAfterLoad();  // vtable slot 113
    virtual void onShow();  // vtable slot 106
    virtual void onUpdateShow();  // vtable slot 110
    void setupInstances();
protected:
    nHuman::CUSTOM_SKILL_GROUP mCustomSkillGroup;  // offset: 0x904
    nHuman::CUSTOM_SKILL_GROUP mCustomSkillGroupSwitchRequest;  // offset: 0x908
    nDDOUtility::cArray<cGUIInstAnimation*, 2> mINST_msg_skillsets;  // offset: 0x910
    u32 mDefaultPriority;  // offset: 0x920
public:
    static MyDTI DTI;
};
