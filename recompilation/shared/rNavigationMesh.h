#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "MtPrimitive3D.h"
#include "MtString.h"
#include "rAIPathBase.h"

// Forward declarations
class MtAABB;
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtString;
class MtUI;
class MtVector3;
class cAIQuadTree;

// Declarations
class rNavigationMesh;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class rNavigationMesh : public rAIPathBase
{
public:
    enum
    {
        TYPE_MESH = 0,
        TYPE_POINT = 1,
    };
public:
    class MyDTI;
    struct HEADER;
    class nodeData;
    class nodeInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct HEADER
    {
    public:
        u32 magic;  // offset: 0x0
        u32 version;  // offset: 0x4
        u32 type;  // offset: 0x8
        u32 attributeBuffer;  // offset: 0xc
    };
public:
    class nodeData : public MtObject
    {
    public:
        class MyDTI;
        struct PolygonArea;
        struct LinkInfo;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        struct PolygonArea
        {
        public:
            s32* mpVertexIndex;  // offset: 0x0
            u32 mNumberOfIndex;  // offset: 0x8
        };
    public:
        struct LinkInfo
        {
        public:
            s32 mLinkNodeIndex;  // offset: 0x0
            u32 mAttribute;  // offset: 0x4
            u32 mPortalNumber;  // offset: 0x8
            f32 mLinkCost;  // offset: 0xc
            f32 mSize;  // offset: 0x10
            f32 mHeight;  // offset: 0x14
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
        nodeData();
        virtual ~nodeData();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        s32 getIndex();
        s32 getNodeArea(u32 index);
        u32 getNodeOfPolygon();
        u32 getNodeAttribute(u32 index);
        u32 getNumberOfAttribute();
        u32 getNumberOfLink();
        s32 getLinkIndex(u32 index);
        u32 getLinkAttr(u32 index);
        u32 getPortal(u32 index);
        f32 getLinkCost(u32 index);
        LinkInfo getLinkInfo(u32);
        f32 getSize(u32 index);
        f32 getHeight(u32 index);
        void setNumberOfPos(u32);
        void setNodeArea(s32* index, u32 polygon);
        void setNodeArea(s32 vertex, u32 index);
        void setNodeAttribute(u32 attr, u32 index);
        void setNumberOfAttribute(u32 num);
        bool getConnect();
        MtVector3 getConnectDir();
        f32 getConnectLength();
        u32 getNumberOfCAttribute();
        u32 getCAttribute(u32);
    protected:
        s32 mIndex;  // offset: 0x8
        u32* mpAttribute;  // offset: 0x10
        u32 mNumberOfAttribute;  // offset: 0x18
        MtVector3 mDir;  // offset: 0x20
        f32 mLength;  // offset: 0x30
        u32* mpCAttribute;  // offset: 0x38
        u32 mNumberOfCAttribute;  // offset: 0x40
        PolygonArea mPolygonArea;  // offset: 0x48
        LinkInfo* mpLinkInformation;  // offset: 0x58
        u32 mNumberOfLink;  // offset: 0x60
        bool mConnect;  // offset: 0x64
        bool mNoMemFree;  // offset: 0x65
    public:
        static MyDTI DTI;
    };
public:
    class nodeInfo : public MtObject
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
        nodeInfo();
        // Address: 0x01b92f60 - 0x01b92f61 (1 bytes)
        virtual ~nodeInfo() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    public:
        u32 mNodeOffset;  // offset: 0x8
        MtAABB mAABB;  // offset: 0x10
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
    rNavigationMesh();
    virtual ~rNavigationMesh();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void saveNavigation(MtDataWriter& w);
    void loadNavigation(MtDataReader& r);
    MtVector3 getVertex(u32 index);
    u32 getNumberOfVertex();
    nodeData* getNode(u32 i);
    u32 getNumberOfNode();
    MtVector3 getNodePos(u32 index);
    nodeInfo* getNodeInfo(u32 i);
    u32 getNumberOfNodeInfo();
    u32 getNumberOfTotalLink();
    u32 getNumberOfTotalAttr();
    u32 getNumberOfTotalIndex();
    u32 getType();
    MT_CTSTR getName();
    bool getNearWall(u32 index);
    u16 getWallDistance(u32 index);
protected:
    void setVertex(MtVector3& pos, u32 index);
    void setNumberOfVertex(u32 size);
    void setNode(nodeData& node, u32 i);
    void setNumberOfNode(u32 size);
    void setNodeInfo(nodeInfo& info, u32 i);
    void setNumberOfNodeInfo(u32 size);
    void setNumberOfNearWall(u32 n);
    void setNearWall(bool, u32);
    void setNumberOfWallDistance(u32 n);
    void setWallDistance(u16, u32);
    void createTreeNode(const MtAABB& r, bool use);
public:
    HEADER mCoreHeader;  // offset: 0x80
    cAIQuadTree* mpQuadTree;  // offset: 0x90
protected:
    MtString mName;  // offset: 0x98
    MtVector3* mpPolygonVertex;  // offset: 0xa0
    bool* mpNearWall;  // offset: 0xa8
    u16* mpWallDistance;  // offset: 0xb0
    u32 mNumberOfVertex;  // offset: 0xb8
    nodeData* mpNode;  // offset: 0xc0
    u32 mNumberOfNode;  // offset: 0xc8
    nodeInfo* mpNodeInfo;  // offset: 0xd0
    u32 mNumberOfNodeInfo;  // offset: 0xd8
    u32 mNumberOfTotalAttribute;  // offset: 0xdc
    u32 mNumberOfTotalLink;  // offset: 0xe0
    u32 mNumberOfTotalIndex;  // offset: 0xe4
    u32* mpNodeBuffer;  // offset: 0xe8
public:
    static MyDTI DTI;
    static const u32 DATA_VERSION = 33;
    static const u32 MAX_ATTRIBUTE = 4;
    static const u32 MAX_LINK = 8;
    static const u32 MAX_NEST = 6;
};
