#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cResource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtUI;
namespace cAcquirement { class cSkillDataBase; }
class sGUIExt;
class sNpcManager;
class sTalkManager;

// Declarations
class rGUIMessage;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_STR = MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using time_t = long int;
using t64 = time_t;
using u32 = unsigned int;

class rGUIMessage : public cResource
{
    // inferred: cAcquirement::cSkillDataBase::getMsg names rGUIMessage::mMessageNum
    friend class cAcquirement::cSkillDataBase;
    // inferred: sGUIExt::getEnemyNameFromGroupId names rGUIMessage::mMessageNum
    friend class sGUIExt;
    // inferred: sNpcManager::getNpcClassName names rGUIMessage::mMessageNum
    friend class sNpcManager;
    // inferred: sTalkManager::getTalkItemName names rGUIMessage::mMessageNum
    friend class sTalkManager;
public:
    enum INSERT_RESULT
    {
        INSERT_SUCCESS = 0,
        INSERT_FAILURE_NULL_NAME = 1,
        INSERT_FAILURE_NULL_INSERT_PTR = 2,
        INSERT_FAILURE_HASH_TABLE_OVERFLOW = 3,
        INSERT_FAILURE_HASH_MODE_UNKNOWN = 4,
    };
public:
    class MyDTI;
    struct INDEX;
    union HASH_TABLE_NODE;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct INDEX
    {
    public:
        u32 index : 31;  // offset: 0x0
        u32 isSameHashDiffName : 1;  // offset: 0x0
        u32 hashA;  // offset: 0x4
        u32 hashB;  // offset: 0x8
        u32 padding;  // offset: 0xc
        union
        {
        public:
            size_t offset;  // offset: 0x0
            MT_CTSTR pName;  // offset: 0x0
        };  // offset: 0x10
        union
        {
        public:
            size_t linkOffst;  // offset: 0x0
            rGUIMessage::INDEX* pLink;  // offset: 0x0
        };  // offset: 0x18
    };
public:
    union HASH_TABLE_NODE
    {
    public:
        size_t offset;  // offset: 0x0
        rGUIMessage::INDEX* pIndex;  // offset: 0x0
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
    rGUIMessage();
    virtual ~rGUIMessage();
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual void clear();  // vtable slot 15
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    t64 getUpdateTime2() const;
    bool checkUpdateTime(t64) const;
    MT_CTSTR getPackageName() const;
    u32 getLanguageId() const;
    u32 getIndexNum() const;
    const INDEX* getIndex(u32 index) const;
    const INDEX* getIndex(MT_CTSTR name) const;
    u32 getIndexFromName(MT_CTSTR name) const;
    u32 getMessageNum() const;
    MT_CTSTR getMessage(u32 index) const;
    static bool isValidMessage(MT_CTSTR pMessage);
    static MT_CTSTR getInvalidMessage();
    static MT_CTSTR getDummyMessage();
    static MT_CTSTR getHardDummyMessage();
protected:
    virtual void* memAlloc(u32 size);  // vtable slot 16
    virtual void memFree(void* p_addr);  // vtable slot 17
    u32 hashString(MT_CTSTR name, u32 crc32_base) const;
    const INDEX* searchINDEXFromHashTable(MT_CTSTR name, u32 hashMode) const;
    u32 insertINDEXIntoHashTable(MT_CTSTR name, INDEX* pInsertIndex, u32 hashMode);
protected:
    u32 mVersion;  // offset: 0x70
    u32 mLanguageId;  // offset: 0x74
    t64 mUpdateTime;  // offset: 0x78
    u32 mIndexNum;  // offset: 0x80
    INDEX* mpIndex;  // offset: 0x88
    u32 mIndexNameBufferSize;  // offset: 0x90
    MT_CTSTR mIndexNameBuffer;  // offset: 0x98
    u32 mMessageNum;  // offset: 0xa0
    MT_CTSTR mPackageName;  // offset: 0xa8
    u32 mBufferSize;  // offset: 0xb0
    MT_STR mBufferTop;  // offset: 0xb8
    MT_STR* mpMessage;  // offset: 0xc0
    HASH_TABLE_NODE mpHashTable[256];  // offset: 0xc8
public:
    static MyDTI DTI;
    static const u32 VERSION = 66306;
protected:
    static MT_CTSTR INVALID_MESSAGE;
    static MT_CTSTR DUMMY_MESSAGE;
    static MT_CTSTR HARDUMMY_MESSAGE;
    static const u32 MAX_HASH = 256;
};
