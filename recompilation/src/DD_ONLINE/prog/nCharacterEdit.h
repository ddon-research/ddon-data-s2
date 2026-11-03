#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;

// Declarations
namespace nCharacterEdit { class cPaletteParams; }
namespace nCharacterEdit { struct stEquipIconCash; }
namespace nCharacterEdit { struct stStageIconCash; }

namespace nCharacterEdit {
    enum BODY_TYPE
    {
        MALE = 0,
        FEMALE = 1,
    };
}  // namespace nCharacterEdit

namespace nCharacterEdit {
    enum CATE
    {
        CATE_NAME = 0,
        CATE_SEX = 1,
        CATE_PRISET = 2,
        CATE_FACE = 3,
        CATE_HAIR = 4,
        CATE_FACE_RINKAKU = 5,
        CATE_EYE = 6,
        CATE_EYEBROW = 7,
        CATE_NOSE = 8,
        CATE_MOUSE = 9,
        CATE_EAR = 10,
        CATE_MAKE = 11,
        CATE_COLOR = 12,
        CATE_BODY = 13,
        CATE_VOICE = 14,
        CATE_PERSONAL = 15,
        CATE_VOICE_FREQUENTLY = 16,
        CATE_MAX = 17,
    };
}  // namespace nCharacterEdit

namespace nCharacterEdit {
    enum CHARGE_TYPE
    {
        EDIT_CHARGE_NONE = 0,
        EDIT_CHARGE_YET = 1,
        EDIT_CHARGE_BUY = 2,
    };
}  // namespace nCharacterEdit

namespace nCharacterEdit {
    enum DIR
    {
        DIR_UP = 0,
        DIR_DOWN = 1,
    };
}  // namespace nCharacterEdit

namespace nCharacterEdit {
    enum EDIT_HAIR_COLOR_INDEX
    {
        HAIR_COLOR_INDEX_HAIR = 0,
        HAIR_COLOR_INDEX_EYEBLOW = 1,
        HAIR_COLOR_INDEX_BEARD = 2,
        EDIT_HAIR_COLOR_NUM = 3,
    };
}  // namespace nCharacterEdit

namespace nCharacterEdit {
    enum EDIT_NAME_CHECK
    {
        NAME_CHECK_INIT = 0,
        NAME_CHECK_OK = 1,
        NAME_CHECK_NONE_BOTH = 2,
        NAME_CHECK_NONE_EACH = 3,
        NAME_CHECK_FORBIT_LENGTH = 4,
        NAME_CHECK_FORBIT_NAME_FORBIT_CHAR = 5,
        NAME_CHECK_OTHER = 6,
    };
}  // namespace nCharacterEdit

namespace nCharacterEdit {
    enum EDIT_NAME_TYPE
    {
        EDIT_NAME_FIRST = 0,
        EDIT_NAME_LAST = 1,
        EDIT_NAME_TYPE_NUM = 2,
    };
}  // namespace nCharacterEdit

namespace nCharacterEdit {
    enum EDIT_TYPE
    {
        EDIT_TYPE_NONE = 0,
        EDIT_TYPE_SEX = 1,
        EDIT_TYPE_COLOR_SKIN = 2,
        EDIT_TYPE_HAIR = 3,
        EDIT_TYPE_HAIR_COLOR = 4,
        EDIT_TYPE_BEARD = 5,
        EDIT_TYPE_BEARD_COLOR = 6,
        EDIT_TYPE_MAKEUP = 7,
        EDIT_TYPE_WRINKLE = 8,
        EDIT_TYPE_SCAR = 9,
        EDIT_TYPE_MAKEUP_COLOR = 10,
        EDIT_TYPE_EYEBLOW_TEX_NO = 11,
        EDIT_TYPE_EYEBLOW_COLOR = 12,
        EDIT_TYPE_EYEBLOW_UV_OFFSET_X = 13,
        EDIT_TYPE_EYEBLOW_UV_OFFSET_Y = 14,
        EDIT_TYPE_EYEBLOW_MAYUKAITEN = 15,
        EDIT_TYPE_EYEBLOW_MIKEN_TAKASA = 16,
        EDIT_TYPE_EYEBLOW_MIKEN_HABA = 17,
        EDIT_TYPE_SOKUTOUBU = 18,
        EDIT_TYPE_HITAI = 19,
        EDIT_TYPE_EYE = 20,
        EDIT_TYPE_EYE_HITOMI_SIZE = 21,
        EDIT_TYPE_EYE_SIZE = 22,
        EDIT_TYPE_EYE_ANGLE = 23,
        EDIT_TYPE_EYE_INTERVAL = 24,
        EDIT_TYPE_EYE_COLOR_L = 25,
        EDIT_TYPE_EYE_COLOR_R = 26,
        EDIT_TYPE_EYE_HEIGHT = 27,
        EDIT_TYPE_EYE_MABISASI_UPDOWN = 28,
        EDIT_TYPE_EAR_SIZE = 29,
        EDIT_TYPE_EAR_DIR = 30,
        EDIT_TYPE_EAR_ELF = 31,
        EDIT_TYPE_NOSE = 32,
        EDIT_TYPE_NOSE_POS_Y = 33,
        EDIT_TYPE_NOSE_SIZE_X = 34,
        EDIT_TYPE_NOSE_HEIGHT = 35,
        EDIT_TYPE_NOSE_DIR = 36,
        EDIT_TYPE_HOBONE_UPDOWN = 37,
        EDIT_TYPE_HOBONE_VALUE = 38,
        EDIT_TYPE_HOHONIKU = 39,
        EDIT_TYPE_ERAHONE_JYOUGE = 40,
        EDIT_TYPE_ERAHONE_HABA = 41,
        EDIT_TYPE_AGOSAKI_JYOUGE = 42,
        EDIT_TYPE_AGOSAKI_HABA = 43,
        EDIT_TYPE_MOTION_FILTER = 44,
        EDIT_TYPE_MOUSE = 45,
        EDIT_TYPE_HANAKUCHI_UPDOWN = 46,
        EDIT_TYPE_AGO_ZENGO = 47,
        EDIT_TYPE_KUCHI_HABA = 48,
        EDIT_TYPE_KUCHI_ATSUSA = 49,
        EDIT_TYPE_HEIGHT = 50,
        EDIT_TYPE_HEAD_SIZE = 51,
        EDIT_TYPE_NECK_POS = 52,
        EDIT_TYPE_NECK_SCALE = 53,
        EDIT_TYPE_SHOULDER_SIZE = 54,
        EDIT_TYPE_KUBIRE = 55,
        EDIT_TYPE_CHEST = 56,
        EDIT_TYPE_WRIST_SIZE = 57,
        EDIT_TYPE_WEST_POS = 58,
        EDIT_TYPE_WEST_SIZE = 59,
        EDIT_TYPE_FOOT_SIZE = 60,
        EDIT_TYPE_FAT = 61,
        EDIT_TYPE_MASSLE = 62,
        EDIT_TYPE_VOICE = 63,
        EDIT_TYPE_VOICE_PITCH = 64,
        EDIT_TYPE_PRISET = 65,
        EDIT_TYPE_PERSONAL = 66,
        EDIT_TYPE_VOICE_FREQUENTLY = 67,
        EDIT_TYPE_REDOUNDO_INIT = 68,
        EDIT_TYPE_REDOUNDO_RANDOM = 69,
        EDIT_TYPE_LOAD = 70,
        EDIT_TYPE_DEFAULT = 71,
        EDIT_TYPE_MAX = 72,
    };
}  // namespace nCharacterEdit

namespace nCharacterEdit {
    enum EDIT_UPDATE_FLAG
    {
        EDIT_UPDATE_FLAG_NONE = 0,
        EDIT_UPDATE_FLAG_PAY = 1,
        EDIT_UPDATE_FLAG_FREE = 2,
        EDIT_UPDATE_FLAG_ERROR = 1073741824,
    };
}  // namespace nCharacterEdit

namespace nCharacterEdit {
    enum EDIT_WARN_TYPE
    {
        INIT_WARN_NONE = 0,
        INIT_WARN_RANDOM = 1,
        INIT_WARN_SEX = 2,
        INIT_WARN_PRISET = 3,
        INIT_WARN_DEFAULT = 4,
        CHRGE_VOICE_GP_SHOP = 5,
        INIT_WARN_TYPE_NUM = 6,
    };
}  // namespace nCharacterEdit

namespace nCharacterEdit {
    enum EQUIP_PRESET_OPOTION
    {
        PRESET_OPTION_NOHEAD = 1,
        PRESET_OPTION_MINE = 2,
    };
}  // namespace nCharacterEdit

namespace nCharacterEdit {
    enum PALETTE
    {
        PALETTE_HAIR = 0,
        PALETTE_BEARD = 1,
        PALETTE_EYEBROW = 2,
        PALETTE_MAKE = 3,
        PALETTE_SCAR = 4,
        PALETTE_EYE = 5,
        PALETTE_NOSE = 6,
        PALETTE_MOUSE = 7,
        PALETTE_MAX = 8,
    };
}  // namespace nCharacterEdit

namespace nCharacterEdit {
    enum PARTS_EVENT
    {
        PARTS_EVENT_DECIDE = 0,
        PARTS_EVENT_CANCEL = 1,
        PARTS_EVENT_SELECTING = 2,
        PARTS_EVENT_LEAVE = 3,
        PARTS_EVENT_TOP = 4,
    };
}  // namespace nCharacterEdit

namespace nCharacterEdit {
    enum SAVE_LOAD_MODE
    {
        SAVE_LOAD_MODE_SAVE = 0,
        SAVE_LOAD_MODE_LOAD = 1,
        SAVE_LOAD_MODE_MAX = 2,
        SAVE_LOAD_MODE_NONE = 3,
    };
}  // namespace nCharacterEdit

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

namespace nCharacterEdit {
    class cPaletteParams : public ::MtObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        cPaletteParams();
    public:
        u32 mUID;  // offset: 0x8
        u32 mRandom;  // offset: 0xc
        u32 mFlag;  // offset: 0x10
        static MyDTI DTI;
    };
}  // namespace nCharacterEdit

namespace nCharacterEdit {
    struct stEquipIconCash
    {
    public:
        stEquipIconCash();
        void copy(const nCharacterEdit::stEquipIconCash& src);
    public:
        bool mIsLeft;  // offset: 0x0
    };
}  // namespace nCharacterEdit

namespace nCharacterEdit {
    struct stStageIconCash
    {
    public:
        stStageIconCash();
        void copy(const nCharacterEdit::stStageIconCash& src);
    public:
        bool mIsLeft;  // offset: 0x0
    };
}  // namespace nCharacterEdit

inline void* nCharacterEdit::cPaletteParams::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline nCharacterEdit::cPaletteParams::cPaletteParams() {
    this->mUID = 0;
    this->mRandom = 0;
    this->mFlag = 0;
}

inline nCharacterEdit::stEquipIconCash::stEquipIconCash() {
}
