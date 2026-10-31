#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtNetObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;

// Declarations
class MtNetBuffer;
class MtNetFriendList;
class MtNetUniqueId;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_STR = MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class MtNetBuffer : public MtNetObject
{
public:
    MtNetBuffer();
    virtual ~MtNetBuffer();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void create(u8* data_buf, u32 data_buf_size);  // vtable slot 11
    virtual void clear();  // vtable slot 12
    virtual void cast(u8* data_buf, u32 data_len);  // vtable slot 13
    virtual s32 serialize(u8* data_buf, u32 data_buf_size) const;  // vtable slot 14
    virtual s32 deserialize(const u8* data_buf, u32 data_size);  // vtable slot 15
    virtual s32 duplicate(const MtNetBuffer* obj);  // vtable slot 16
    virtual bool equals(const MtNetBuffer* obj) const;  // vtable slot 17
    virtual void encrypt(u8 key_byte, u32 offset, u32 data_len);  // vtable slot 18
    virtual void decrypt(u8 key_byte, u32 offset, u32 data_len);  // vtable slot 19
    virtual u16 getCRC16(u32 data_len) const;  // vtable slot 20
    virtual void dump(u32 offset, u32 size);  // vtable slot 21
protected:
    u8* mpBuffer;  // offset: 0x28
    u32 mBufferSize;  // offset: 0x30
    u32 mDataLength;  // offset: 0x34
};

class MtNetUniqueId : public MtNetBuffer
{
public:
    enum
    {
        TARGET_NONE = 0,
        TARGET_LAMM = 1,
        TARGET_LIVE = 2,
        TARGET_PSN = 3,
        TARGET_UDS = 4,
        TARGET_NEX = 5,
        TARGET_6 = 6,
        _RESERVED_VITA_PSN = 7,
        TARGET_VITA_ADHOC = 8,
        TARGET_9 = 9,
        TARGET_10 = 10,
        TARGET_11 = 11,
        TARGET_12 = 12,
        TARGET_NNAC = 13,
        TARGET_14 = 14,
        TARGET_STEAM = 15,
        TARGET_16 = 16,
        TARGET_17 = 17,
        TARGET_18 = 18,
        TARGET_19 = 19,
        TARGET_XBOXONE_LIVE = 20,
        TARGET_PS4_PSN = 21,
        TARGET_MAX = 22,
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
    MtNetUniqueId();
    MtNetUniqueId(const MtNetUniqueId& uniq_id);
    virtual ~MtNetUniqueId();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    bool isValid() const;
    void importFrom(u8 target, const void* data, u32 size);
    void importFrom(u8 target, MT_CTSTR str);
    void exportTo(void* data, u32 size) const;
    void exportTo(MT_STR str, u32 size) const;
    MtNetUniqueId& operator=(const MtNetUniqueId& uniq_id);
    bool equals(const MtNetUniqueId* uniq_id) const;
    bool operator==(const MtNetUniqueId& uniq_id) const;
private:
    virtual bool equals(const MtNetBuffer* obj) const;  // vtable slot 17
private:
    u8 mData[64];  // offset: 0x38
public:
    static MyDTI DTI;
    static const s32 MAX_SIZE_DATA = 64;
    static const s32 SIZE_HEAD = 4;
    static const s32 WCHAR_SIZE = 30;
};

class MtNetFriendList : public MtNetObject
{
public:
    MtNetFriendList();
    MtNetFriendList(const MtNetFriendList& src_list);
    virtual ~MtNetFriendList();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    void setUserIndex(s32 user_index);
    s32 getUserIndex() const;
    void clear();
    MtNetFriendList& operator=(const MtNetFriendList& src_list);
    bool isFriend(MtNetUniqueId* uniq_id);
    s32 getNum() const;
    void getUniqueId(MtNetUniqueId* uniq_id, s32 no);
    s32 getUniqueIdList(MtNetUniqueId* uniq_id_list, s32 uniq_id_max_num);
    void add(MtNetUniqueId* uniq_id);
    void remove(MtNetUniqueId* uniq_id);
private:
    bool inUniqueIdList(MtNetUniqueId* uniq_id);
private:
    s32 mUserIndex;  // offset: 0x24
    s32 mValidNum;  // offset: 0x28
    MtNetUniqueId mUniqueId[2000];  // offset: 0x30
public:
    static const s32 MAX_NUM_FRIEND = 2000;
};
