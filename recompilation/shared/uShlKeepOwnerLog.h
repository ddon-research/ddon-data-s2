#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "uShlBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
class cDraw;
class cShlParamKeepLog;
class uDDOModel;
class uShlBakuensen;

// Declarations
class cShlLogNode;
class uShlKeepOwnerLog;

namespace nShlKeepLog {
    enum KEEP_LOG_PHASE
    {
        MODE_INVALID = 0,
        MODE_STOP = 1,
        MODE_KEEP_LOG = 2,
        MODE_END = 3,
        MODE_NUM = 4,
    };
}  // namespace nShlKeepLog

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlLogNode : public MtObject
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
    cShlLogNode();
    virtual ~cShlLogNode();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void updatePtr();  // vtable slot 6
    // Address: 0x01b0f740 - 0x01b0f741 (1 bytes)
    virtual void updateEfcHandle() {}  // vtable slot 7
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 8
    void setPos(const MtVector3&);
    void setDir(const MtVector3&);
    void setOwnerUnit(uDDOModel* pModel, uShlKeepOwnerLog* pOwnerShl);
    virtual void init();  // vtable slot 9
    virtual void final();  // vtable slot 10
    virtual void keepLog();  // vtable slot 11
    const MtVector3& getPos() const;
    const MtVector3& getDir() const;
protected:
    MtVector3 mPos;  // offset: 0x10
    MtVector3 mDir;  // offset: 0x20
    uDDOModel* mpModel;  // offset: 0x30
    uShlKeepOwnerLog* mpOwnerShl;  // offset: 0x38
public:
    static MyDTI DTI;
};

class uShlKeepOwnerLog : public uShlBase
{
    // inferred: uShlBakuensen::requestIgnite names uShlKeepOwnerLog::mLogPhase
    friend class uShlBakuensen;
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
    const cShlParamKeepLog* getShlParam() const;
    virtual const MtDTI* getLogNodeDTI() = 0;  // vtable slot 186
    uShlKeepOwnerLog();
    virtual ~uShlKeepOwnerLog();
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    virtual void updateEfcHandle();  // vtable slot 58
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
protected:
    virtual void initSub();  // vtable slot 177
    virtual void updateSub();  // vtable slot 175
    void changeLogPhase(nShlKeepLog::KEEP_LOG_PHASE phase);
    void addLogNode();
    cShlLogNode* findTopNode();
    void eraseTopNode();
    cShlLogNode* findLastNode();
    void eraseLastNode();
private:
    void updateLog();
    bool isLogAble();
    void checkLogExecute();
    bool checkLogWait();
    void resetLogParam();
    void requestTrace();
    void clearRequestTrace();
    bool isLogOptionOn(u32 option);
    bool isExecuteAttrOn(u32 attr);
    bool isWaitAttrOn(u32 attr);
protected:
    MtTypedArray<cShlLogNode> mLogNodeArray;  // offset: 0x2ab0
private:
    nShlKeepLog::KEEP_LOG_PHASE mLogPhase;  // offset: 0x2ad0
    f32 mKeepLogTimer;  // offset: 0x2ad4
    MtVector3 mKeepLogPosLast;  // offset: 0x2ae0
    bool mIsKeepLogReqest;  // offset: 0x2af0
public:
    static MyDTI DTI;
};
