#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"

// Forward declarations
class CDataFurnitureLayout;
class MtAllocator;
class MtDTI;
class MtVector3;
class cOmControl;
class rFurnitureData;
class rFurnitureItem;
class rFurnitureLayout;

// Declarations
class cFurniture;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cFurniture : public MtObject
{
public:
    enum
    {
        RESULT_NONE = 0,
        RESULT_LIST_GET = 1,
        RESULT_LIST_OK = 2,
        RESULT_LIST_NG = 3,
        RESULT_LAYOUT = 4,
        RESULT_LAYOUT_OK = 5,
        RESULT_LAYOUT_NG = 6,
    };
    enum
    {
        R0_INIT = 0,
        R0_SETUP = 1,
        R0_MAIN = 2,
        R0_LAYOUT = 3,
    };
public:
    class MyDTI;
    class Info;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class Info : public MtObject
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
        Info();
        virtual ~Info();
        void copy(cFurniture::Info* src);
        void createUnit();
        void deleteUnit();
    public:
        u8 mLayoutId;  // offset: 0x8
        bool mOnOff;  // offset: 0x9
        u32 mItemId;  // offset: 0xc
        u32 mOmId;  // offset: 0x10
        cOmControl* mpOmCtrl;  // offset: 0x18
        MtVector3 mPos;  // offset: 0x20
        MtVector3 mAngle;  // offset: 0x30
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
    cFurniture();
    virtual ~cFurniture();
    void init();
    void move();
    bool setFurnitureLayout(const MtTypedArray<CDataFurnitureLayout>& list);
    bool changeFurniture(u32 item_id, bool onoff);
    bool sendFurniture();
    void updateFurniture();
    bool resetFurniture();
    u32 getInfoNum() const;
    Info* getInfo(u32 idx);
    Info* searchInfo(u32 item_id);
    const MtTypedArray<Info>& getInfo() const;
    void copyInfo(MtTypedArray<Info>& src, MtTypedArray<Info>& dst);
    s32 getLayoutId(u32 itemID);
    bool isSetFurniture(u32 idx);
    bool isSetItem(u32 item_id);
    bool isSetOm(u32 om_id);
    bool isSetLayout(u32 layout_id);
    void setResult(u8);
    u32 getResult() const;
    bool isBusy() const;
    void setRoomWear();
    void setRoomWearTrial();
private:
    void setup();
    void change(u32 item_id, bool onoff);
    void update();
    void release();
private:
    union
    {
    public:
        u32 mRno;  // offset: 0x0
        struct
        {
        public:
            u32 mRno0 : 8;  // offset: 0x0
            u32 mRno1 : 8;  // offset: 0x0
            u32 mRno2 : 8;  // offset: 0x0
            u32 mRno3 : 8;  // offset: 0x0
        };  // offset: 0x0
    };  // offset: 0x8
    bool mIsSetup;  // offset: 0xc
    u8 mResult;  // offset: 0xd
    rFurnitureData* mpFurnitureData;  // offset: 0x10
    rFurnitureItem* mpFurnitureItem;  // offset: 0x18
    rFurnitureLayout* mpFurnitureLayout;  // offset: 0x20
    MtTypedArray<Info> mInfoMaster;  // offset: 0x28
    MtTypedArray<Info> mInfoDisp;  // offset: 0x48
public:
    static MyDTI DTI;
};
