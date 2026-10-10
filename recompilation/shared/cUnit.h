#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtProperty;
class MtPropertyList;
class MtSphere;
class MtUI;
class MtVector3;
class cDraw;
class cParticle;
class cpCatchCtrl;
class cpIKCtrl;
class cpJob02;
class cpJob06;
class sUnit;
class uArmor;
class uBaseEffect;
class uCnsTinyChain;
class uConstraint;
class uEffect;
class uEnemy;
class uFilter;
class uGUI;
class uHuman;
class uLight;
class uScrollCollisionGeometryModel;
class uShadow;
class uShlBase;
class uSimSoftBody;
class uWeapon;

// Declarations
class cUnit;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

class cUnit : public MtObject
{
    // inferred: cParticle::updateSynchroEnable names cUnit::mBeFlag
    friend class cParticle;
    // inferred: cpCatchCtrl::checkCaught names cUnit::mUnitParam
    friend class cpCatchCtrl;
    // inferred: cpIKCtrl::updateIKHandle names cUnit::mBeFlag
    friend class cpIKCtrl;
    // inferred: cpJob02::update names cUnit::mDeltaTime
    friend class cpJob02;
    // inferred: cpJob06::decreaseCS14Timer names cUnit::mDeltaTime
    friend class cpJob06;
    // inferred: sUnit::addBottom names cUnit::mUnitGroup
    friend class sUnit;
    // inferred: uArmor::setup names cUnit::mDrawMode
    friend class uArmor;
    // inferred: uBaseEffect::updateDeltaTimeRate names cUnit::mDeltaTime
    friend class uBaseEffect;
    // inferred: uCnsTinyChain::move names cUnit::mBeFlag
    friend class uCnsTinyChain;
    // inferred: uConstraint::setup names cUnit::mDrawMode
    friend class uConstraint;
    // inferred: uEffect::updateParentEnable names cUnit::mBeFlag
    friend class uEffect;
    // inferred: uEnemy::updateEnchantColInfo names cUnit::mDeltaTime
    friend class uEnemy;
    // inferred: uFilter::uFilter names cUnit::mDrawMode
    friend class uFilter;
    // inferred: uGUI::moveAfter names cUnit::mDeltaTime
    friend class uGUI;
    // inferred: uHuman::updateEnchantColInfo names cUnit::mDeltaTime
    friend class uHuman;
    // inferred: uLight::setPS3DisableMode names cUnit::mpHardwareDispCtrl
    friend class uLight;
    // inferred: uScrollCollisionGeometryModel::uScrollCollisionGeometryModel names cUnit::mDrawMode
    friend class uScrollCollisionGeometryModel;
    // inferred: uShadow::setPS3DisableMode names cUnit::mpHardwareDispCtrl
    friend class uShadow;
    // inferred: uShlBase::moveAfter names cUnit::mDeltaTime
    friend class uShlBase;
    // inferred: uSimSoftBody::isTargetEnable names cUnit::mBeFlag
    friend class uSimSoftBody;
    // inferred: uWeapon::moveAfter names cUnit::mDrawMode
    friend class uWeapon;
public:
    enum BEFLAG
    {
        BEFLAG_DISABLE = 0,
        BEFLAG_PRE_MOVE = 1,
        BEFLAG_MOVE = 2,
        BEFLAG_PRE_DELETE = 3,
        BEFLAG_DELETE = 4,
    };
    enum UNIT_ATTR
    {
        UATTR_MOVE = 1,
        UATTR_DRAW = 2,
        UATTR_SELECT = 4,
        UATTR_FIX = 8,
        UATTR_VISIBLE = 16,
    };
    enum DRAW_VIEW
    {
        VIEW_0 = 1,
        VIEW_1 = 2,
        VIEW_2 = 4,
        VIEW_3 = 8,
        VIEW_4 = 16,
        VIEW_5 = 32,
        VIEW_6 = 64,
        VIEW_7 = 128,
        VIEW_OVERLAY = 256,
        VIEW_COMMON = 512,
    };
public:
    class MyDTI;
    class cHardwareDispCtrl;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cHardwareDispCtrl : public MtObject
    {
        // inferred: uLight::setPS3DisableMode names cUnit::cHardwareDispCtrl::mFlag
        friend class uLight;
        // inferred: uShadow::setPS3DisableMode names cUnit::cHardwareDispCtrl::mFlag
        friend class uShadow;
    public:
        enum UNIT_HDC_KIND_BIT
        {
            PS3_OFF_BIT = 1,
            PS4_OFF_BIT = 2,
            PC_OFF_BIT = 4,
        };
        enum UNIT_HDC_KIND_ID
        {
            PS3_ID = 0,
            PS4_ID = 1,
            PC_ID = 2,
            UNIT_HDC_KIND_MAX = 3,
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
        cHardwareDispCtrl();
        cHardwareDispCtrl(cUnit* pOwner);
        // Address: 0x01b5bd20 - 0x01b5bd21 (1 bytes)
        virtual ~cHardwareDispCtrl() {}
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
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual void init();  // vtable slot 6
        virtual void update();  // vtable slot 7
        virtual bool isDispOperateHard();  // vtable slot 8
        virtual bool isDispOperateHardOld();  // vtable slot 9
        void setFlag(UNIT_HDC_KIND_BIT set);
        void relFlag(UNIT_HDC_KIND_BIT set);
        void setHard(u32 HardId);
        u32 getFlag();
        u32 getOldFlag();
        u32 getHard();
        cUnit* getOwner();
    private:
        cUnit* mpOwner;  // offset: 0x8
        u32 mHard;  // offset: 0x10
        u32 mFlag;  // offset: 0x14
        u32 mOldFlag;  // offset: 0x18
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
    cUnit();
    virtual ~cUnit();
    virtual void setup();  // vtable slot 6
    s32 getMoveLine() const;
    u64 getUnitGroup() const;
    bool checkUnitGroup(u32 group) const;
    virtual u64 getDefaultUnitGroup() const;  // vtable slot 7
    virtual u64 getSystemUnitGroup() const;  // vtable slot 8
    // Address: 0x01b0a690 - 0x01b0a691 (1 bytes)
    virtual void move() {}  // vtable slot 9
    // Address: 0x01989b90 - 0x01989b91 (1 bytes)
    virtual void moveAfter() {}  // vtable slot 10
    // Address: 0x01989ba0 - 0x01989ba1 (1 bytes)
    virtual void sync() {}  // vtable slot 11
    // Address: 0x01989bb0 - 0x01989bb1 (1 bytes)
    virtual void draw(cDraw* pdraw) {}  // vtable slot 12
    virtual bool getBoundary(MtSphere* pdst);  // vtable slot 13
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual MT_CTSTR getName();  // vtable slot 14
    cUnit* getNextUnit() const;
    cUnit* getPrevUnit() const;
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    // Address: 0x01ad0850 - 0x01ad0851 (1 bytes)
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {}  // vtable slot 15
    virtual void kill();  // vtable slot 16
    bool isEnable() const;
    void setFix(bool fix);
    void setMove(bool move);
    void setDraw(bool draw);
    void setDrawMode(u32 draw_mode);
    u32 getDrawMode() const;
    void setDrawView(u32 draw_scene);
    u32 getDrawView() const;
    f32 getDeltaTime() const;
    void setDeltaTime(f32 dt);
    u32 getBeFlag() const;
    void setSelect(bool);
    void setVisible(bool visible);
    bool isVisible() const;
    bool isSelect() const;
    bool isFix() const;
    bool isMove() const;
    bool isDraw() const;
    u32 getUnitParam() const;
    void setUnitParam(u32 v);
    // Address: 0x01989bc0 - 0x01989bc1 (1 bytes)
    virtual void updatePtr() {}  // vtable slot 17
    cUnit* getSelfPtr();
    u32 getUnitAttr() const;
    virtual void getDrawUnitState(u32& type, u32& priority) const;  // vtable slot 18
    // Address: 0x01989bd0 - 0x01989bd1 (1 bytes)
    virtual void callbackChangeVisibleTrueToFalse() {}  // vtable slot 19
    virtual u32 getUseCommandCacheNum();  // vtable slot 20
    virtual u32 getUseMaxCommandCacheNum();  // vtable slot 21
    virtual bool isPossibleDrawFromDrawBuffer();  // vtable slot 22
protected:
    virtual bool isEnableInstance() const;  // vtable slot 3
    void setBeFlag(u32 bf);
private:
    bool getTrans() const;
    void setUnitAttr(u32);
    void setMoveLine(u32 line);
    void setName(MT_CTSTR);
public:
    virtual cHardwareDispCtrl* createHardwareDispCtrl();  // vtable slot 23
    void deleteHardwareDispCtrl();
    cHardwareDispCtrl* getHardwareDispCtrl();
    void setHardwareDispCtrl(cHardwareDispCtrl* set);
protected:
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
    u32 mUnitParam;  // offset: 0xc
private:
    u32 mBeFlag : 3;  // offset: 0x10
    u32 mMoveLine : 7;  // offset: 0x10
    u32 mUnitAttr : 6;  // offset: 0x10
    u32 mDrawView : 10;  // offset: 0x10
    u32 mDrawMode;  // offset: 0x14
    cUnit* mpNextUnit;  // offset: 0x18
    cUnit* mpPrevUnit;  // offset: 0x20
    f32 mDeltaTime;  // offset: 0x28
    u64 mUnitGroup;  // offset: 0x30
    u32 padding[2];  // offset: 0x38
    cHardwareDispCtrl* mpHardwareDispCtrl;  // offset: 0x40
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline u64 cUnit::getUnitGroup() const {
    return this->mUnitGroup;
}

// Inline, no code of its own: checked where it is inlined.
inline bool cUnit::isEnable() const {
    return (this->mBeFlag - static_cast<u32>(1)) <= static_cast<u32>(1);
}

// Inline, no code of its own: checked where it is inlined.
inline f32 cUnit::getDeltaTime() const {
    return this->mDeltaTime;
}

// Inline, no code of its own: checked where it is inlined.
// inferred: a bit-test accessor's polarity, true when its bits are set: none of its 22 DWARF copies materializes its result
inline bool cUnit::isVisible() const {
    return (this->mUnitAttr & static_cast<u32>(16)) != static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline u32 cUnit::getUnitParam() const {
    return this->mUnitParam;
}
