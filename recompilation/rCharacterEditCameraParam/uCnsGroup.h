#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/uConstraint.h"
#include "../shared/uModel.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class cDraw;
class cResource;
class uModel;

// Declarations
class uCnsGroup;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uCnsGroup : public uConstraint
{
public:
    class MyDTI;
    class cGroup;
    class cNode;
    class cCnsChild;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cGroup : public MtObject
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
        cGroup(uCnsGroup* pCnsGroup, u32 idx);
        virtual ~cGroup();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        uModel* getModel();
        virtual void setPri(u32 pri);  // vtable slot 6
        virtual bool update(bool resetFlg);  // vtable slot 7
        virtual void remove(bool resetFlg);  // vtable slot 8
        // Address: 0x01bbd720 - 0x01bbd721 (1 bytes)
        virtual void adjust(u32 idx, uModel::Joint* pJnt, uModel* pMod) {}  // vtable slot 9
        virtual u32 getDependentJointNum(u32 cnsIdx);  // vtable slot 10
        virtual uModel::Joint* getDependentJoint(u32 cnsIdx, u32 dependIdx);  // vtable slot 11
        // Address: 0x01bbd740 - 0x01bbd741 (1 bytes)
        virtual void init() {}  // vtable slot 12
        // Address: 0x01bbd750 - 0x01bbd751 (1 bytes)
        virtual void reset() {}  // vtable slot 13
        bool isReady();
    protected:
        virtual uCnsGroup::cNode* createNode(u32 idx);  // vtable slot 14
        // Address: 0x01bbd7b0 - 0x01bbd7b1 (1 bytes)
        virtual void resetNodeRef() {}  // vtable slot 15
        void clearNode();
    public:
        // Address: 0x01b686a0 - 0x01b686a1 (1 bytes)
        virtual void setNode(uCnsGroup::cNode* pNode, u32 idx) {}  // vtable slot 16
        virtual uCnsGroup::cNode* getNode(u32 idx);  // vtable slot 17
        void setNodeNum(u32 num);
        u32 getNodeNum();
        bool insertNode(u32 idx);
        bool deleteNode(u32 idx);
        void resizeCnsChildlen();
    private:
        void updateForProperty(u32 updateDepend);
    public:
        uCnsGroup* mpCnsGroup;  // offset: 0x8
        u32 mIndex;  // offset: 0x10
        u32 mNodeNum;  // offset: 0x14
        uCnsGroup::cNode* * mppNodes;  // offset: 0x18
        uCnsGroup::cCnsChild* mpCnsChildlen;  // offset: 0x20
        bool mIsReady;  // offset: 0x28
        static MyDTI DTI;
    };
public:
    class cNode : public MtObject
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
        cNode();
        virtual ~cNode();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        void setJointNo(u32);
        u32 getJointNo();
    public:
        u32 mJointNo;  // offset: 0x8
        static MyDTI DTI;
    };
public:
    class cCnsChild : public uConstraint
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
        // Address: 0x01bbd810 - 0x01bbd811 (1 bytes)
        virtual void createProperty(MtPropertyList& s) {}  // vtable slot 4
        // Address: 0x01bbd830 - 0x01bbd831 (1 bytes)
        virtual void setup() {}  // vtable slot 6
        // Address: 0x01bbd840 - 0x01bbd841 (1 bytes)
        virtual void moveAfter() {}  // vtable slot 10
        // Address: 0x01bbd850 - 0x01bbd851 (1 bytes)
        virtual void draw(cDraw* pDraw) {}  // vtable slot 12
        virtual void adjust(uModel::Joint* pjnt, uModel* pmod);  // vtable slot 29
        // Address: 0x01bbd8d0 - 0x01bbd8d1 (1 bytes)
        virtual void setResource(cResource* pRes) {}  // vtable slot 32
        virtual cResource* getResource();  // vtable slot 33
        virtual u32 getDependentJointNum();  // vtable slot 26
        virtual uModel::Joint* getDependentJoint(u32 Idx);  // vtable slot 27
    public:
        uCnsGroup::cGroup* mpGroup;  // offset: 0x98
        u32 mIndex;  // offset: 0xa0
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
    uCnsGroup();
    virtual ~uCnsGroup();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void move();  // vtable slot 9
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    // Address: 0x01bbd660 - 0x01bbd661 (1 bytes)
    virtual void setResource(cResource* pRes) {}  // vtable slot 32
    virtual cResource* getResource();  // vtable slot 33
    // Address: 0x01bbd650 - 0x01bbd651 (1 bytes)
    virtual void adjust(uModel::Joint* pjnt, uModel* pmod) {}  // vtable slot 29
    virtual void remove();  // vtable slot 31
    virtual void update();  // vtable slot 30
    virtual void setPri(u32 pri);  // vtable slot 28
    virtual u32 getDependentJointNum();  // vtable slot 26
    virtual uModel::Joint* getDependentJoint(u32 idx);  // vtable slot 27
    virtual void evSetJoints(uModel::Joint* * pJnts, u32 Num);  // vtable slot 37
    virtual void reset();  // vtable slot 39
    virtual void setModelUpdate(uModel* pModel);  // vtable slot 36
protected:
    virtual bool preupdate();  // vtable slot 40
    virtual cGroup* createGroup(u32 idx);  // vtable slot 41
    // Address: 0x01bbd700 - 0x01bbd701 (1 bytes)
    virtual void resetGroupRef() {}  // vtable slot 42
    void clearGroup();
public:
    void setGroupNum(u32 num);
    u32 getGroupNum();
    s32 addGroup();
    virtual bool insertGroup(u32 idx);  // vtable slot 43
    virtual bool deleteGroup(u32 idx);  // vtable slot 44
    void setGroup(cGroup*, u32);
    cGroup* getGroup(u32);
    void setResourceNextMove(cResource* pRes);
protected:
    u32 mGroupNum;  // offset: 0x94
    cGroup* * mppGroups;  // offset: 0x98
    cResource* mpTmpResource;  // offset: 0xa0
    bool mIsReady;  // offset: 0xa8
    bool mIsAdjustCalculated;  // offset: 0xa9
public:
    static MyDTI DTI;
    static const u32 NODE_MAX = 255;
    static const u32 GROUP_MAX = 255;
};
