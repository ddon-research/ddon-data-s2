#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/sGUIExt.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cGUIInstAnimation;
class cGUIObject;
class rGUI;

// Declarations
class uGUITutorialAnnounce;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUITutorialAnnounce : public uGUIBase
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
private:
    void ctrlVisible();
    void setLineFrame(f32 frame);
public:
    uGUITutorialAnnounce();
    virtual ~uGUITutorialAnnounce();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    void setAnnounceType(sGUIExt::ANNOUNCE_TYPE type);
    sGUIExt::ANNOUNCE_TYPE getAnnounceType() const;
private:
    void updateInit();
    void updateWait();
    void updateExit();
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    cGUIInstAnimation* mpInstAnnounce;  // offset: 0x8d0
    cGUIObject* mpObj_Null_icon;  // offset: 0x8d8
    cGUIObject* mpObj_Null_icon_pt;  // offset: 0x8e0
    cGUIObject* mpObj_Null_icon_entry;  // offset: 0x8e8
    cGUIObject* mpObj_Null_icon_matching;  // offset: 0x8f0
    cGUIObject* mpObj_Null_msg;  // offset: 0x8f8
    cGUIObject* mpObj_Null_msg_pt;  // offset: 0x900
    cGUIObject* mpObj_Null_entry;  // offset: 0x908
    cGUIObject* mpObj_line_top00;  // offset: 0x910
    cGUIObject* mpObj_line_top01;  // offset: 0x918
    cGUIObject* mpObj_line_top02;  // offset: 0x920
    cGUIObject* mpObj_line_top03;  // offset: 0x928
    cGUIObject* mpObj_line_top10;  // offset: 0x930
    cGUIObject* mpObj_line_top11;  // offset: 0x938
    cGUIObject* mpObj_line_top12;  // offset: 0x940
    cGUIObject* mpObj_line_top13;  // offset: 0x948
    f32 mLineFrame;  // offset: 0x950
    uGUIBase::cReferenceUIBtnGuide mBtnGuide;  // offset: 0x958
    sGUIExt::ANNOUNCE_TYPE mAnnounceType;  // offset: 0x9f0
    bool mDispObjIcon;  // offset: 0x9f4
    bool mDispObjIconPt;  // offset: 0x9f5
    bool mDispObjIconEntry;  // offset: 0x9f6
    bool mDispObjIconMatching;  // offset: 0x9f7
    bool mDispObjMsg;  // offset: 0x9f8
    bool mDispObjMsgPt;  // offset: 0x9f9
    bool mDispObjMsgEntry;  // offset: 0x9fa
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline sGUIExt::ANNOUNCE_TYPE uGUITutorialAnnounce::getAnnounceType() const {
    return this->mAnnounceType;
}
