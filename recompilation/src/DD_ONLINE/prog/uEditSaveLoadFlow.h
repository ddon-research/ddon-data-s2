#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../XFramework/cUnit.h"
#include "sSavedataExt.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cEditParam;
class rGUIMessage;
class uCharacterEdit;
class uGUISaveListComment;
class uGUISystemMsg;

// Declarations
class uEditSaveLoadFlow;

namespace nEditSaveLoadFlow {
    enum SAVE_LOAD_MODE
    {
        MODE_NONE = 0,
        MODE_SELECT = 1,
        MODE_SAVE = 2,
        MODE_LOAD = 3,
    };
}  // namespace nEditSaveLoadFlow

namespace nEditSaveLoadFlow {
    enum SET_MODE
    {
        SET_CHAR_EDIT = 0,
        SET_EDIT_PARAM = 1,
    };
}  // namespace nEditSaveLoadFlow

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uEditSaveLoadFlow : public cUnit
{
public:
    enum SAVE_LOAD_PROCESS
    {
        PROCESS_NONE = 0,
        PROCESS_SELECT = 1,
        PROCESS_SAVE = 2,
        PROCESS_LOAD = 3,
        PROCESS_END = 4,
    };
    enum SELECT_ROUTINE_NO
    {
        SELECT_ROUTINE_INIT = 0,
        SELECT_ROUTINE_WAIT = 1,
        SELECT_ROUTINE_END = 2,
    };
    enum SAVE_ROUTINE_NO
    {
        SAVE_ROUTINE_COMMENT_SETUP = 0,
        SAVE_ROUTINE_COMMENT_WAIT = 1,
        SAVE_ROUTINE_FADE_WAIT = 2,
        SAVE_ROUTINE_SAVE_REQ = 3,
        SAVE_ROUTINE_SAVE_WAIT = 4,
        SAVE_ROUTINE_LOAD_FADE_WAIT = 5,
        SAVE_ROUTINE_END = 6,
    };
    enum LOAD_ROUTINE_NO
    {
        LOAD_ROUTINE_LOAD_INIT = 0,
        LOAD_ROUTINE_FADE_WAIT = 1,
        LOAD_ROUTINE_LOAD_REQ = 2,
        LOAD_ROUTINE_LOAD_WAIT = 3,
        LOAD_ROUTINE_LOAD_FADE_WAIT = 4,
        LOAD_ROUTINE_LOAD_CHECK = 5,
        LOAD_ROUTINE_LOAD_CHECK_WAIT = 6,
        LOAD_ROUTINE_LOAD_SEX_ERROR = 7,
        LOAD_ROUTINE_LOAD_SEX_ERROR_WAIT = 8,
        LOAD_ROUTINE_LOAD_REWARD_ERROR = 9,
        LOAD_ROUTINE_LOAD_REWARD_ERROR_WAIT = 10,
        LOAD_ROUTINE_LOAD_BROKEN = 11,
        LOAD_ROUTINE_END = 12,
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
    uEditSaveLoadFlow();
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void kill();  // vtable slot 16
    void setCharacterEdit(uCharacterEdit* pCharaEdit);
    void setEditParam(cEditParam& editParam);
    void setGmdDialog(rGUIMessage* pGmdDialog);
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void updatePtr();  // vtable slot 17
    void startSaveLoad(nEditSaveLoadFlow::SAVE_LOAD_MODE mode);
    bool isBusy() const;
    void setUseHeader(const cStorageDataBase::UserHeader& useHeader);
    void setCharaInfo(s32 bodyType, MT_CTSTR firstName, MT_CTSTR LastName);
    const cStorageDataBase::UserHeader& getUseHeader() const;
private:
    void changeProcess(SAVE_LOAD_PROCESS process);
    void processSelect();
    void processSave();
    void processLoad();
    void processEnd();
private:
    s32 mProcessRno;  // offset: 0x48
    bool mIsBusy;  // offset: 0x4c
    nEditSaveLoadFlow::SAVE_LOAD_MODE mSaveLoadMode;  // offset: 0x50
    nEditSaveLoadFlow::SET_MODE mSetMode;  // offset: 0x54
    SAVE_LOAD_PROCESS mSaveLoadProcess;  // offset: 0x58
    uCharacterEdit* mpCharacterEdit;  // offset: 0x60
    rGUIMessage* mpGmdDialog;  // offset: 0x68
    uGUISystemMsg* mpGUISystemMsg;  // offset: 0x70
    uGUISaveListComment* mpGUISaveListComment;  // offset: 0x78
    cEditParam* mpEditParam;  // offset: 0x80
    cStorageDataBase::UserHeader mUserHeader;  // offset: 0x88
    f32 mFadeFrame;  // offset: 0x158
public:
    static MyDTI DTI;
private:
    static const s32 ROTINE_INIT = 0;
};

inline void* uEditSaveLoadFlow::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
