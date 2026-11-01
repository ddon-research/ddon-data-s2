#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "../MT/MtObject.h"
#include "../MT/MtPropertyList.h"
#include "cAIService.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class cAIUserProcessContainer;

// Declarations
class cAISvUserProcess;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cAISvUserProcess : public cAIService
{
public:
    class MyDTI;
    class UserObjectInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class UserObjectInfo : public MtObject
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
        UserObjectInfo();
        virtual ~UserObjectInfo();
        const MtDTI* getObjectDTI();
        MtObject* getObjectInstance();
        MtPropertyList& getObjectProperty();
        bool isSingleton();
        void setListName(MT_CTSTR n);
        MT_CTSTR getListName();
    public:
        const MtDTI* mpObjectDTI;  // offset: 0x8
        MtObject* mpObjectInstance;  // offset: 0x10
        MtPropertyList mObjectProperty;  // offset: 0x18
        cAISvUserProcess::UserObjectInfo* mpPrev;  // offset: 0x28
        cAISvUserProcess::UserObjectInfo* mpNext;  // offset: 0x30
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
    cAISvUserProcess();
    virtual ~cAISvUserProcess();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    static cAISvUserProcess* getInstance(MT_CTSTR n);
    virtual void reset();  // vtable slot 6
    virtual void move();  // vtable slot 7
    void addContainer(cAIUserProcessContainer* pContainer);
    void removeContainer(cAIUserProcessContainer* pContainer);
    void eraseContainer(cAIUserProcessContainer* pContainer);
    void eraseContainerAll();
    u32 getContainerNum();
    void setContainerNum(u32 num);
    cAIUserProcessContainer* getContainer(u32 index);
    cAIUserProcessContainer* searchContainer(MT_CTSTR n);
    cAIUserProcessContainer* searchContainer(MT_CTSTR n, const MtDTI& dti);
    void setContainer(cAIUserProcessContainer* pc, u32 index);
    void entryUserObject(MtObject* pObject, bool isSingleton, MT_CTSTR listName);
    void entryUserObject(const MtDTI* pDTI, MT_CTSTR listName);
    void setUserObjectListName(const MtDTI* pDTI, MT_CTSTR listName);
    void addUserObjectInfo(UserObjectInfo* pInfo);
    void removeUserObjectInfo(UserObjectInfo* pInfo);
    void eraseUserObjectInfo(UserObjectInfo* pInfo);
    void eraseUserObjectInfoAll();
    u32 getUserObjectInfoNum();
    UserObjectInfo* getUserObjectInfo(u32 index);
    UserObjectInfo* searchUserObjectInfo(const MtDTI* pdti);
    UserObjectInfo* searchUserObjectInfo(MT_CTSTR n);
private:
    cAIUserProcessContainer* mpContainerListTop;  // offset: 0x30
    cAIUserProcessContainer* mpContainerListBottom;  // offset: 0x38
    UserObjectInfo* mpUserObjectInfoListTop;  // offset: 0x40
    UserObjectInfo* mpUserObjectInfoListBottom;  // offset: 0x48
public:
    static MyDTI DTI;
};

inline cAISvUserProcess::cAISvUserProcess() {
    this->mpUserObjectInfoListBottom = nullptr;
    this->mpUserObjectInfoListTop = nullptr;
    this->mpContainerListBottom = nullptr;
    this->mpContainerListTop = nullptr;
}
