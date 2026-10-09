#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "MtPrimitive2D.h"
#include "MtProperty.h"
#include "cSystem.h"

// Forward declarations
struct MT_ENUM;
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtSize;
class MtUI;
class sMain;

// Declarations
class sApp;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_MFUNC = void(MtObject::*)();
using MT_STR = MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class sApp : public cSystem
{
    // inferred: sMain::freeDefaultMemory calls sApp::finalAppInStableMem
    friend class sMain;
public:
    enum USERDEFINEDPARAM
    {
        USERDEFINEDPARAM_1 = 0,
        USERDEFINEDPARAM_2 = 1,
        USERDEFINEDPARAM_3 = 2,
        USERDEFINEDPARAM_4 = 3,
        MAX_USERDEFINEDPARAM = 4,
    };
    enum APPLICATION_TYPE
    {
        APPLICATION_TRIAL = 1,
        APPLICATION_FULL = 3,
        APPLICATION_UNKNOWN = 255,
    };
    enum BUTTON_ASSIGN
    {
        ENTER_BUTTON_ASSIGN_CIRCLE = 0,
        ENTER_BUTTON_ASSIGN_CROSS = 1,
    };
    enum LANGUAGE
    {
        LANGUAGE_JAPANESE = 0,
        LANGUAGE_ENGLISH = 1,
        LANGUAGE_FRENCH = 2,
        LANGUAGE_SPANISH = 3,
        LANGUAGE_GERMAN = 4,
        LANGUAGE_ITALIAN = 5,
        LANGUAGE_KOREAN = 9,
        LANGUAGE_CHINESE_T = 10,
        LANGUAGE_CHINESE_S = 11,
        LANGUAGE_PORTUGUESE = 7,
        LANGUAGE_RUSSIAN = 8,
        LANGUAGE_POLISH = 16,
        LANGUAGE_DUTCH = 6,
        LANGUAGE_FINNISH = 12,
        LANGUAGE_SWEDISH = 13,
        LANGUAGE_DANISH = 14,
        LANGUAGE_NORWEGIAN = 15,
        LANGUAGE_PORTUGUESE_BRA = 17,
        LANGUAGE_ENGLISH_GBR = 18,
        LANGUAGE_TURKISH = 19,
        LANGUAGE_SPANISH_LA = 20,
    };
public:
    class MyDTI;
    class Item;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class Item : public MtObject
    {
    public:
        enum TYPE
        {
            TYPE_UNKNOWN = 0,
            TYPE_ENUM = 1,
            TYPE_FLAG = 2,
            TYPE_FLOAT = 3,
            TYPE_INT = 4,
            TYPE_BOOL = 5,
        };
        enum GROUP
        {
            GROUP_GAME = 1,
            GROUP_GRAPHICS = 2,
            GROUP_DISPLAY = 8,
            GROUP_ETC = 16,
            GROUP_DEVELOP = 32,
            GROUP_SOUNDS = 4,
            GROUP_CPU = 64,
            GROUP_JOYPAD = 128,
            GROUP_ALL = 65535,
            MAX_GROUP = 8,
        };
        enum ATTR
        {
            ATTR_NOREALTIME = 1,
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
        Item();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual void createMenu(MtPropertyList& s);  // vtable slot 6
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        MT_CTSTR getName();
        u32 getGroup();
        TYPE getType();
        bool isEnable();
        u32 getEnumCount();
        const MT_ENUM& getEnum(u32 index);
        bool check(s32 v);
        bool check(f32 v);
        void reset();
        void setInt(s32 v);
        s32 getInt();
        void setBool(bool v);
        bool getBool();
        void setFloat(f32 v);
        f32 getFloat();
        void toString(MT_STR str);
        void fromString(MT_CTSTR str);
        bool isRealTime();
        s32 getMinInt();
        s32 getMaxInt();
        f32 getMinFloat();
        f32 getMaxFloat();
    protected:
        void setEnumValue(s32 v);
        MT_CTSTR getEnumName();
        void setEnumName(MT_CTSTR);
    protected:
        u16 mGroup;  // offset: 0x8
        u8 mType;  // offset: 0xa
        u8 mAttr;  // offset: 0xb
        MtProperty mProp;  // offset: 0x10
        MT_MFUNC mpGetMask;  // offset: 0x80
        MT_MFUNC mpIsEnable;  // offset: 0x90
        union
        {
        public:
            f32 mMinFValue;  // offset: 0x0
            s32 mMinIValue;  // offset: 0x0
        };  // offset: 0xa0
        union
        {
        public:
            f32 mMaxFValue;  // offset: 0x0
            s32 mMaxIValue;  // offset: 0x0
        };  // offset: 0xa4
        const MT_ENUM* mpEnum;  // offset: 0xa8
    public:
        static MyDTI DTI;
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
    sApp(MT_CTSTR remote_config_name);
    virtual ~sApp();
    static sApp* getInstance();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    bool isActive();
    virtual void createMenu(MtPropertyList& s);  // vtable slot 8
    void init(const MtDTI& dti, s32 argc, const char* * argv);
    void execute();
    s32 getUserDefinedParam(const USERDEFINEDPARAM) const;
    MtSize getPS4Resolution() const;
    APPLICATION_TYPE getApplicationType();
    bool isAbort();
    bool addEnumItem(u32 group, MtProperty prop, const MT_ENUM* penum, MT_MFUNC getmask, MT_MFUNC isenable, u32 attr);
    bool addFlagItem(u32 group, MtProperty prop, const MT_ENUM* pflag, MT_MFUNC getmask, MT_MFUNC isenable, u32 attr);
    bool addFloatItem(u32 group, MtProperty prop, f32 minvalue, f32 maxvalue, MT_MFUNC isenable, u32 attr);
    bool addIntItem(u32 group, MtProperty prop, s32 minvalue, s32 maxvalue, MT_MFUNC isenable, u32 attr);
    bool addBoolItem(u32 group, MtProperty prop, MT_MFUNC isenable, u32 attr);
    const MT_ENUM* getItemGroup();
    u32 getItemGroupNum();
    u32 getItemNum();
    Item* getItem(u32 index);
    s32 getItemIndexFromName(MT_CTSTR name, u32 group);
    virtual void resetItem(u32 group);  // vtable slot 10
    virtual void loadItem(u32 group_mask);  // vtable slot 11
    virtual void saveItem();  // vtable slot 12
    void setItemGroupKeyword(u32 group, MT_CTSTR keyword);
    static MT_CTSTR getCommandLine(s32 index);
    static s32 getCommandLineNum();
    s32 getCountry();
    s32 getLanguage();
    u32 getEnterButtonAssign();
    void setEnterButtonAssign(const BUTTON_ASSIGN);
private:
    static void abortHandler(MT_CTSTR buf, void* param);
    void setItem(Item*, u32);
    void setItemNum();
    void initApp();
    void initAppInStableMem();
    void initPS4Resolution();
    void finalApp();
    void finalAppInStableMem();
    Item* addItem(Item::TYPE type, u32 group, MtProperty& prop, MT_MFUNC isenable, u32 attr);
private:
    Item* mpItem[256];  // offset: 0x18
    u32 mItemNum;  // offset: 0x818
    MT_CHAR mItemGroupKeyword[16][512];  // offset: 0x81c
    sMain* mpMain;  // offset: 0x2820
    s32 mCountry;  // offset: 0x2828
    s32 mLanguage;  // offset: 0x282c
    bool mAbort;  // offset: 0x2830
    bool mActive;  // offset: 0x2831
    u32 mEnterButtonAssign;  // offset: 0x2834
    s32 mUserDefinedParam[4];  // offset: 0x2838
    MtSize mPS4Resolution;  // offset: 0x2848
public:
    static MyDTI DTI;
private:
    static const u32 MAX_ITEM = 256;
    static const MT_ENUM mItemGroup[];
    static sApp* mpInstance;
    static s32 mArgumentCount;
    static MT_CHAR* * mArgumentVector;
};
