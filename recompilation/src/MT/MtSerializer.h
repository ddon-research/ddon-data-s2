#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtProperty.h"
#include "MtPropertyList.h"
#include "MtXmlReader.h"

// Forward declarations
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtXmlWriter;

// Declarations
class MtSerializer;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_MFUNC = void(MtObject::*)();
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class MtSerializer
{
public:
    enum MODE
    {
        MODE_STATE = 0,
        MODE_CONFIG = 1,
        MODE_USER = 2,
    };
    enum ENCODING
    {
        ENCODING_AUTO = 0,
        ENCODING_AS_IS = 1,
    };
public:
    struct CLASS_ID;
    struct OBJECTDATA;
    struct PROPERTYDATA;
    class XmlHandler;
    struct HEADER;
    struct CLASSDATA;
public:
    struct CLASS_ID
    {
    public:
        MtObject* pobject;  // offset: 0x0
        u32 refcount : 31;  // offset: 0x8
        u32 binst : 1;  // offset: 0x8
    };
public:
    struct PROPERTYDATA
    {
    public:
        union
        {
        public:
            MT_CTSTR name;  // offset: 0x0
            u32 ownerofs;  // offset: 0x0
        };  // offset: 0x0
        union
        {
        public:
            struct
            {
            public:
                u32 type : 8;  // offset: 0x0
                u32 attr : 8;  // offset: 0x0
                u32 bytes : 15;  // offset: 0x0
                u32 disable : 1;  // offset: 0x0
            };  // offset: 0x0
            u32 param32;  // offset: 0x0
        };  // offset: 0x8
        u32 padding1;  // offset: 0xc
        union
        {
        public:
            struct
            {
            public:
                u32 offset;  // offset: 0x0
                u32 count;  // offset: 0x4
            };  // offset: 0x0
            struct
            {
            public:
                MT_MFUNC getter;  // offset: 0x0
                MT_MFUNC getcount;  // offset: 0x10
            };  // offset: 0x0
        };  // offset: 0x10
        struct
        {
        public:
            MT_MFUNC setter;  // offset: 0x0
            MT_MFUNC setcount;  // offset: 0x10
        };  // offset: 0x30
    };
public:
    class XmlHandler : public MtXmlReader::Handler
    {
    public:
        class Context;
    public:
        class Context
        {
        public:
            Context();
        public:
            MtProperty* mpArray;  // offset: 0x0
            MtPropertyList mPropList;  // offset: 0x8
            u32 mCount;  // offset: 0x18
            bool mEnable;  // offset: 0x1c
        };
    public:
        XmlHandler(MtSerializer* psz, MtObject* pobj, MtSerializer::MODE mode);
        virtual void startElement(MT_CTSTR localname, MtXmlReader::ATTRIBUTE* attr, u32 attr_num);  // vtable slot 8
        virtual void endElement(MT_CTSTR localname);  // vtable slot 3
        MtObject* getObject();
    private:
        MtSerializer* mpSerializer;  // offset: 0x10
        Context mContext[510];  // offset: 0x18
        MtObject* mpObject;  // offset: 0x3fd8
        s32 mStackPt;  // offset: 0x3fe0
        MtSerializer::MODE mMode;  // offset: 0x3fe4
        static const s32 MAX_STACK = 510;
    };
public:
    struct HEADER
    {
    public:
        u32 magic;  // offset: 0x0
        u16 major_version;  // offset: 0x4
        u16 minor_version;  // offset: 0x6
        u32 max_object_id;  // offset: 0x8
        u32 reserved;  // offset: 0xc
        u32 object_num;  // offset: 0x10
        u32 database_size;  // offset: 0x14
    };
public:
    struct CLASSDATA
    {
    public:
        union
        {
        public:
            u32 param32;  // offset: 0x0
            struct
            {
            public:
                u32 inst : 1;  // offset: 0x0
                u32 type : 15;  // offset: 0x0
                u32 id : 16;  // offset: 0x0
            };  // offset: 0x0
        };  // offset: 0x0
    };
public:
    struct OBJECTDATA
    {
    public:
        union
        {
        public:
            u32 id;  // offset: 0x0
            const MtDTI* pdti;  // offset: 0x0
        };  // offset: 0x0
        union
        {
        public:
            struct
            {
            public:
                u32 prop_num : 15;  // offset: 0x0
                u32 init : 1;  // offset: 0x0
                u32 reserved : 16;  // offset: 0x0
            };  // offset: 0x0
            u32 param32;  // offset: 0x0
        };  // offset: 0x8
        u32 padding1;  // offset: 0xc
        MtSerializer::PROPERTYDATA prop[1];  // offset: 0x10
    };
public:
    MtSerializer(s32 MaxClassID);
    ~MtSerializer();
    bool serializeXML(MtStream& out, MT_CTSTR name, MtObject* pobj, MODE mode, ENCODING encoding);
    MtObject* deserializeXML(MtStream& in, MT_CTSTR, MtObject* pobj, MODE mode, ENCODING encoding);
    bool serializeBinary(MtStream& out, u16 version, MtObject* proot, MODE mode, const MtDTI* prootdti);
    bool serializeBinary(MtDataWriter& w, u16 version, MtObject* proot, MODE mode, const MtDTI* prootdti);
    MtObject* deserializeBinary(MtStream& in, u16 version, MtObject* pobj, MODE mode);
    MtObject* deserializeBinary(MtDataReader& r, u16 version, MtObject* pobj, MODE mode);
private:
    void addClass(MtObject* pobj, bool inst, MODE mode);
    void writeClass(MtXmlWriter& w, MtObject* pobj, bool inst, MODE mode);
    void writeClass(MtDataWriter& w, MtObject* pobj, bool inst, MODE mode, const MtDTI* prootdti);
    s32 getClassID(MtObject* pobj);
    s32 newClassID(MtObject* pobj);
    void setClass(s32 id, MtObject* pobj);
    MtObject* getClass(s32 id);
    void addRef(s32 id);
    u32 getRefCount(s32 id);
    void setClassInst(u32 id);
    bool isClassInst(u32 id);
    MtObject* getClassInst(MT_CTSTR name, s32 id);
    void addObject(MtObject* pobj, MODE mode, const MtDTI* pdti);
    MT_CTSTR addString(MT_CTSTR str);
    u32 getObjectDataType(MtObject* pobj);
    MtObject* readClass(MtDataReader& r, MtObject* pobj);
    bool isSerializable(MtProperty& prop, MODE mode);
    void readDynamicProperty(MtDataReader& r, MtObject* pdst, PROPERTYDATA* ppd);
    void readStaticProperty(MtDataReader& r, MtObject* pdst, PROPERTYDATA* ppd);
    void skipProperty(MtDataReader& r, PROPERTYDATA* ppd);
    void mappingObject(OBJECTDATA* pdat, MtObject* pobj);
private:
    MT_CHAR mTempBuffer[256];  // offset: 0x0
    s32 mClassIDMax;  // offset: 0x100
    s32 mClassIDNum;  // offset: 0x104
    CLASS_ID* mClassID;  // offset: 0x108
    OBJECTDATA* * mpObjectData;  // offset: 0x110
    u32 mObjectDataNum;  // offset: 0x118
    u8* mpStringPool;  // offset: 0x120
    size_t mStringPoolPt;  // offset: 0x128
    MtProperty::Custom::PARAM mCustomParams[4];  // offset: 0x130
    MT_CHAR mCustomParamValue[4][128];  // offset: 0x170
    static const u16 MAJOR_VERSION = 15;
    static const s32 MAX_OBJECT = 4096;
    static const s32 MAX_STRINGPOOL = 1048576;
    static const u32 OBJECTDATA_NULL = 32767;
    static const s32 MAX_CUSTOMPARAM_VALUE = 128;
    static const s32 MAX_CUSTOMPARAM = 4;
};
