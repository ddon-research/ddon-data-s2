#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtCollisionUtil.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "MtPrimitive3D.h"
#include "MtString.h"

// Forward declarations
class MtAABB;
class MtAllocator;
class MtCapsule;
namespace MtCollisionUtil { class MtVectorU4; }
class MtDTI;
class MtDataReader;
class MtDataWriter;
struct MtFloat3;
class MtGeometry;
class MtMatrix;
class MtObject;
class MtPlane;
class MtProperty;
class MtPropertyList;
class MtString;
class MtUI;
class MtVector3;
class MtVector4;

// Declarations
namespace MtCollisionUtil { class MtArrayElement; }
namespace MtCollisionUtil { class MtDataBuffer; }
namespace MtCollisionUtil { class MtStack; }
namespace MtCollisionUtil { class MtFunc; }
namespace MtCollisionUtil { class MtFunc32; }
namespace MtCollisionUtil { class MtFunc32X2; }
namespace MtCollisionUtil { class MtFuncPtr; }
namespace MtCollisionUtil { class MtFuncPtr32; }
namespace MtCollisionUtil { class MtListElement; }
namespace MtCollisionUtil { class MtList; }
namespace MtCollisionUtil { class MtTreeDTI; }
namespace MtCollisionUtil { struct EpaFace; }
namespace MtCollisionUtil { struct EpaExpandEdge; }
namespace MtCollisionUtil { struct MtDataPtr32; }
namespace MtCollisionUtil { struct MtU32_U16Two; }

namespace MtCollisionUtil {
    enum AABB_EDGE_ID
    {
        AABB_EDGE_ID_011_TO_111 = 0,
        AABB_EDGE_ID_111_TO_101 = 1,
        AABB_EDGE_ID_101_TO_001 = 2,
        AABB_EDGE_ID_001_TO_011 = 3,
        AABB_EDGE_ID_010_TO_110 = 4,
        AABB_EDGE_ID_110_TO_100 = 5,
        AABB_EDGE_ID_100_TO_000 = 6,
        AABB_EDGE_ID_000_TO_010 = 7,
        AABB_EDGE_ID_010_TO_011 = 8,
        AABB_EDGE_ID_110_TO_111 = 9,
        AABB_EDGE_ID_100_TO_101 = 10,
        AABB_EDGE_ID_000_TO_001 = 11,
        AABB_EDGE_ID_MAX = 12,
    };
}  // namespace MtCollisionUtil

namespace MtCollisionUtil {
    enum AABB_VORONOI_ID
    {
        AABB_X_MIN_BIT = 1,
        AABB_X_MAX_BIT = 2,
        AABB_Y_MIN_BIT = 4,
        AABB_Y_MAX_BIT = 8,
        AABB_Z_MIN_BIT = 16,
        AABB_Z_MAX_BIT = 32,
        AABB_VORONOI_INTERNAL = 0,
        AABB_VORONOI_P_YZX0 = 1,
        AABB_VORONOI_P_YZX1 = 2,
        AABB_VORONOI_P_ZXY0 = 4,
        AABB_VORONOI_P_ZXY1 = 8,
        AABB_VORONOI_P_XYZ0 = 16,
        AABB_VORONOI_P_XYZ1 = 32,
        AABB_VORONOI_E_XY0Z0 = 20,
        AABB_VORONOI_E_XY1Z0 = 24,
        AABB_VORONOI_E_XY0Z1 = 36,
        AABB_VORONOI_E_XY1Z1 = 40,
        AABB_VORONOI_E_YZ0X0 = 17,
        AABB_VORONOI_E_YZ1X0 = 33,
        AABB_VORONOI_E_YZ0X1 = 18,
        AABB_VORONOI_E_YZ1X1 = 34,
        AABB_VORONOI_E_ZX0Y0 = 5,
        AABB_VORONOI_E_ZX1Y0 = 6,
        AABB_VORONOI_E_ZX0Y1 = 9,
        AABB_VORONOI_E_ZX1Y1 = 10,
        AABB_VORONOI_V_X0Y0Z0 = 21,
        AABB_VORONOI_V_X1Y0Z0 = 22,
        AABB_VORONOI_V_X0Y1Z0 = 25,
        AABB_VORONOI_V_X1Y1Z0 = 26,
        AABB_VORONOI_V_X0Y0Z1 = 37,
        AABB_VORONOI_V_X1Y0Z1 = 38,
        AABB_VORONOI_V_X0Y1Z1 = 41,
        AABB_VORONOI_V_X1Y1Z1 = 42,
    };
}  // namespace MtCollisionUtil

namespace MtCollisionUtil {
    enum TRI_VORONOI_ID
    {
        TRI_VORONOI_INTERNAL = 0,
        TRI_VORONOI_EDGE01 = 1,
        TRI_VORONOI_EDGE20 = 2,
        TRI_VORONOI_V0 = 3,
        TRI_VORONOI_EDGE12 = 4,
        TRI_VORONOI_V1 = 5,
        TRI_VORONOI_V2 = 6,
    };
}  // namespace MtCollisionUtil

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_MFUNC = void(MtObject::*)();
using u32 = unsigned int;
using MT_MFUNC32 = void(MtObject::*)(u32);
using MT_MFUNC32X2 = void(MtObject::*)(u32, u32);
namespace MtCollisionUtil { using MT_FUNC_PTR = void(MtObject::*)(void*); }
namespace MtCollisionUtil { using MT_FUNC_PTR_32 = void(MtObject::*)(void*, u32); }
namespace MtCollisionUtil { using MT_FUNC_STRING_U32_PTR = void(MtObject::*)(MT_CTSTR, u32, void*); }
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u16 = unsigned short;
using u8 = unsigned char;

namespace MtCollisionUtil {

    enum
    {
        RECT3D_L_BIT = 1,
        RECT3D_R_BIT = 2,
        RECT3D_T_BIT = 4,
        RECT3D_B_BIT = 8,
        RECT3D_INTERNAL = 0,
        RECT3D_EDGE_L_BIT = 1,
        RECT3D_EDGE_R_BIT = 2,
        RECT3D_EDGE_T_BIT = 4,
        RECT3D_EDGE_B_BIT = 8,
        RECT3D_VERTEX_LT_BIT = 5,
        RECT3D_VERTEX_LB_BIT = 9,
        RECT3D_VERTEX_RT_BIT = 6,
        RECT3D_VERTEX_RB_BIT = 10,
    };

    enum
    {
        RECT3DXZ_L_BIT = 1,
        RECT3DXZ_R_BIT = 2,
        RECT3DXZ_T_BIT = 4,
        RECT3DXZ_B_BIT = 8,
        RECT3DXZ_INTERNAL = 0,
        RECT3DXZ_EDGE_L_BIT = 1,
        RECT3DXZ_EDGE_R_BIT = 2,
        RECT3DXZ_EDGE_T_BIT = 4,
        RECT3DXZ_EDGE_B_BIT = 8,
        RECT3DXZ_VERTEX_LT_BIT = 5,
        RECT3DXZ_VERTEX_LB_BIT = 9,
        RECT3DXZ_VERTEX_RT_BIT = 6,
        RECT3DXZ_VERTEX_RB_BIT = 10,
    };

    // Forward declarations
    class MtArrayElement;
    class MtDataBuffer;
    class MtStack;
    class MtFunc;
    class MtFunc32;
    class MtFunc32X2;
    class MtFuncPtr;
    class MtFuncPtr32;
    class MtListElement;
    class MtList;
    class MtTreeDTI;
    struct EpaFace;
    struct EpaExpandEdge;
    struct MtDataPtr32;
    struct MtU32_U16Two;

    class MtArrayElement : public ::MtObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        MtArrayElement();
        virtual ~MtArrayElement();
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void allocateParam(u16 type, u32 num);
        void inputParam(const MtProperty& prop);
        void outputParam(MtProperty& prop);
        void allocateParam(u32 size);
        void allocateParam(const MtDTI& dti);
        void setParam(void* pParam);
        void deleteParam();
        MT_CTSTR getName();
        void setName(MT_CTSTR str);
        void setNameForUI(const MtString& str);
        void* getParam();
        u32 getType();
        u32 getParamNum();
        void* memAlloc(size_t s);
        void memFree(void* padr);
        size_t memSize(void*);
    protected:
        MT_CHAR mName[64];  // offset: 0x8
        const MtDTI* mpParamDti;  // offset: 0x48
        void* mpParam;  // offset: 0x50
        u16 mType;  // offset: 0x58
        bool mFlgUndefineAllocate;  // offset: 0x5a
        u32 mParamNum;  // offset: 0x5c
    public:
        static MyDTI DTI;
    };

    class MtDataBuffer : public ::MtObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        MtDataBuffer();
        virtual ~MtDataBuffer();
        void registData(void*, u16);
        void registData(u16);
        void unregistData();
        void* getDataBuffer();
        u32 getDataSize();
        u32 getDataMax();
        void* memAlloc(size_t);
        void memFree(void* padr);
        size_t memSize(void*);
    protected:
        void* mpData;  // offset: 0x8
        u16 mSize;  // offset: 0x10
        u16 mMax;  // offset: 0x12
    public:
        static MyDTI DTI;
    };

    class MtStack
    {
    public:
        MtStack();
        ~MtStack();
        void initializeToNoUse();
        void allocateBuffer(u32, u32);
        void releaseBuffer();
        void* getBuffer(u32);
        void* getLastElement();
        void* push();
        void* pop();
        void releasePopData();
        u32 getPushNum();
        static void setAllocator(MtAllocator*);
        static void* operator new(size_t);
        static void* operator new[](size_t);
        static void* operator new(size_t, void*);
        static void* operator new[](size_t, void*);
        static void operator delete(void*);
        static void operator delete[](void*);
        void* memAlloc(size_t);
        void memFree(void*);
        size_t memSize(void*);
        static MtAllocator* getAllocator();
    protected:
        void* mpTotalBuffer;  // offset: 0x0
        void* mpUsingBuffer;  // offset: 0x8
        void* * mppPushBuffer;  // offset: 0x10
        void* * mppNoUseBuffer;  // offset: 0x18
        u32 mElementSize;  // offset: 0x20
        u32 mTotalBufferNum;  // offset: 0x24
        u32 mUseStackNum;  // offset: 0x28
        u32 mNoUseStackNum;  // offset: 0x2c
        static MtAllocator* mpAllocator;
    };

    class MtFunc : public MtCollisionUtil::MtFuncBase
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        MtFunc();
        virtual ~MtFunc();
        void registFunc(MT_CTSTR CallbackName, MtObject* pOwner, MT_MFUNC Param);
        void runFunc();
    protected:
        MT_MFUNC mRegistParam;  // offset: 0x18
    public:
        static MyDTI DTI;
    };

    class MtFunc32 : public MtCollisionUtil::MtFuncBase
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        MtFunc32();
        virtual ~MtFunc32();
        void registFunc32(MT_CTSTR CallbackName, MtObject* pOwner, MT_MFUNC32 Param, u32 SendParamDefault);
        void runFunc32(u32 param);
        void runFunc32();
    protected:
        MT_MFUNC32 mRegistParam;  // offset: 0x18
        u32 mSendParamDefault;  // offset: 0x28
    public:
        static MyDTI DTI;
    };

    class MtFunc32X2 : public MtCollisionUtil::MtFuncBase
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        MtFunc32X2();
        virtual ~MtFunc32X2();
        void registFunc32X2(MT_CTSTR CallbackName, MtObject* pOwner, MT_MFUNC32X2 Param, u32 SendParamDefault0, u32 SendParamDefault1);
        MT_MFUNC32X2 getFunc32X2();
        void runFunc32X2(u32 param0, u32 param1);
        void runFunc32X2(u32);
        void runFunc32X2();
    protected:
        MT_MFUNC32X2 mRegistParam;  // offset: 0x18
        u32 mSendParamDefault0;  // offset: 0x28
        u32 mSendParamDefault1;  // offset: 0x2c
    public:
        static MyDTI DTI;
    };

    class MtFuncPtr : public MtCollisionUtil::MtFuncBase
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        MtFuncPtr();
        virtual ~MtFuncPtr();
        void registFuncPtr(MT_CTSTR CallbackName, MtObject* pOwner, MtCollisionUtil::MT_FUNC_PTR pRegistParam);
        MtCollisionUtil::MT_FUNC_PTR getFuncPtr();
        void runFuncPtr(void* ptr);
    protected:
        MtCollisionUtil::MT_FUNC_PTR mRegistParam;  // offset: 0x18
    public:
        static MyDTI DTI;
    };

    class MtFuncPtr32 : public MtCollisionUtil::MtFuncBase
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        MtFuncPtr32();
        virtual ~MtFuncPtr32();
        void registFuncPtr32(MT_CTSTR CallbackName, MtObject* pOwner, MtCollisionUtil::MT_FUNC_PTR_32 pRegistParam);
        MtCollisionUtil::MT_FUNC_PTR_32 getFuncPtr32();
        void runFuncPtr32(void* ptr, u32 param);
    protected:
        MtCollisionUtil::MT_FUNC_PTR_32 mRegistParam;  // offset: 0x18
    public:
        static MyDTI DTI;
    };

    class MtListElement : public ::MtObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        MtListElement();
        virtual ~MtListElement();
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void separate();
        MT_CTSTR getName() const;
        void setName(MT_CTSTR NewName);
        MtObject* getObject();
        void setObject(MtObject* pNewObject);
        MtCollisionUtil::MtListElement* getNext();
        const MtCollisionUtil::MtListElement* getNextConst() const;
        void setNext(MtCollisionUtil::MtListElement* pNewNext);
        MtCollisionUtil::MtListElement* getBack();
        const MtCollisionUtil::MtListElement* getBackConst() const;
        void setBack(MtCollisionUtil::MtListElement* pNewBack);
        bool isAutoDelete() const;
        void setAutoDelete(bool FlgNewAutoDelete);
    protected:
        MtString mName;  // offset: 0x8
        MtObject* mpObject;  // offset: 0x10
        MtCollisionUtil::MtListElement* mpNext;  // offset: 0x18
        MtCollisionUtil::MtListElement* mpBack;  // offset: 0x20
        bool mFlgAutoDelete;  // offset: 0x28
    public:
        static MyDTI DTI;
    };

    class MtList : public ::MtObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        MtList();
        virtual ~MtList();
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        MtCollisionUtil::MtListElement* getRoot();
        MtCollisionUtil::MtListElement* getTail();
        void insertElementRoot(MtCollisionUtil::MtListElement* pListElement);
        void insertElementTail(MtCollisionUtil::MtListElement* pListElement);
        void insertElement(MtCollisionUtil::MtListElement* pListElement, u32 IndexFromRoot);
        void insertElementNext(MtCollisionUtil::MtListElement* pNewListElement, MtCollisionUtil::MtListElement* pBaseListElement);
        void insertElementBack(MtCollisionUtil::MtListElement* pNewListElement, MtCollisionUtil::MtListElement* pBaseListElement);
        void insertObjectRoot(MtObject* pNewObject);
        void insertObjectTail(MtObject* pNewObject);
        void insertObject(MtObject* pNewObject, u32 IndexFromRoot);
        MtCollisionUtil::MtListElement* getElement(u32 IndexFromRoot);
        u32 countElementNum() const;
        bool getAutoDelete() const;
        void setAutoDelete(bool FlgNewAutoDelete);
    protected:
        MtCollisionUtil::MtListElement* mpRoot;  // offset: 0x8
        MtCollisionUtil::MtListElement* mpTail;  // offset: 0x10
        bool mFlgAutoDelete;  // offset: 0x18
    public:
        static MyDTI DTI;
    };

    class MtTreeDTI : public ::MtTree
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        MtTreeDTI();
        virtual ~MtTreeDTI();
        void correctDTI(const MtDTI& RootDti);
    protected:
        void correctDTICore(MtTree::Node* pNowTreeElement, const MtDTI* pDtiNow);
    public:
        static MyDTI DTI;
    };

    struct EpaFace
    {
    public:
        MtPlane mFacePlane;  // offset: 0x0
        MtFloat3 mNearestPos;  // offset: 0x10
        f32 mFacePlaneDistanceSq;  // offset: 0x1c
        u8 mFlgObsolute;  // offset: 0x20
        u8 mAdjacentEdgeIndex[3];  // offset: 0x21
        u16 mVertexIndex[3];  // offset: 0x24
        MtCollisionUtil::EpaFace* mpAdjacentFace[3];  // offset: 0x30
        bool mFlgFaceReverse;  // offset: 0x48
        u16 mUseFaceIndex;  // offset: 0x4a
    };

    struct EpaExpandEdge
    {
    public:
        MtCollisionUtil::EpaFace* mpFace;  // offset: 0x0
        u8 mFaceEdgeIndex;  // offset: 0x8
    };

    struct MtDataPtr32
    {
    public:
        void* ptr;  // offset: 0x0
        u32 param;  // offset: 0x8
    };

    struct MtU32_U16Two
    {
    public:
        union
        {
        public:
            struct
            {
            public:
                u16 high;  // offset: 0x0
                u16 low;  // offset: 0x2
            };  // offset: 0x0
            u32 param;  // offset: 0x0
        };  // offset: 0x0
    };

    void getBoundingAABBFromTwoCapsule(MtAABB& aabb_out, const MtCapsule& cap0, const MtCapsule& cap1, f32 epcilon);
    MtGeometry* allocateGeometryFromGeometryType(u32 GeometryType);
    MtGeometry* loadGeometry(MtDataReader& r);
    bool saveGeometry(MtDataWriter& w, MtGeometry* pTargetGeometry);
    bool loadString(MtDataReader& r, MtString& OutputString, MtAllocator* pAllocator, MT_CHAR* pReadBuffer);
    bool saveString(MtDataWriter& w, MtString& OutputString);
    const MtDTI* loadDTI(MtDataReader& r);
    bool saveDTI(MtDataWriter& w, const MtDTI* pSaveDTI);
    bool saveObjectDTI(MtDataWriter& w, const MtObject* pSaveObject);
    void getTargetDirectoryInsideFileNameAll(MT_CTSTR BaseDirectory, MtObject* pCallbackOwner, MT_FUNC_STRING_U32_PTR pCallbackFunc, void* pFuncSendParam, bool FlgSubDirectoryCheck, bool FlgHideDirectoryPath, bool FlgPathMask, MT_CTSTR MaskPattern);
    void getTargetDirectoryInsideDataNameAll(MT_CTSTR BaseDirectory, MtObject* pCallbackOwner, MT_FUNC_STRING_U32_PTR pCallbackFunc, void* pFuncSendParam, bool FlgSubDirectoryCheck, bool FlgHideDirectoryPath, bool FlgDirectoryCallbackPath, bool FlgFileCallbackPath, bool FlgPathMask, MT_CTSTR MaskPattern);
    void getTargetDirectoryInsideFolderNameAll(MT_CTSTR BaseDirectory, MtObject* pCallbackOwner, MT_FUNC_STRING_U32_PTR pCallbackFunc, void* pFuncSendParam, bool FlgSubDirectoryCheck, bool FlgHideDirectoryPath, bool FlgPathMask, MT_CTSTR MaskPattern);
    bool isMatchFileName(MT_CTSTR TargetString, MT_CTSTR MaskString);
    MtProperty searchPropertyListAll(MtPropertyList& s, MT_CTSTR PropertyName, u32 PropertyType);
    f32 getF32Minimize(f32 a, f32 b);
    f32 getF32Maximize(f32 a, f32 b);
    void calcVec3Dot(MtVector3& out, const MtVector3& vec0, const MtVector3& vec1);
    MtVector3 calcVec3Dot(const MtVector3& vec0, const MtVector3& vec1);
    MtVector3 calcVec3MAdd(const MtVector3& _base, const MtVector3& _mul, const MtVector3& _add);
    void calcVec3InfoSafe(const MtVector3& SrcVec, MtVector3& DestLen4, MtVector3& DestLenR4, MtVector3& DestLenSq4, MtVector3& DestVecN, const MtVector3& LenZeroOutputLenN);
    MtVector4 calcVec3MtxTransform(const MtVector3& v, const MtMatrix& m);
    MtVector3 calcVec3MtxTransformPos(const MtVector3& v, const MtMatrix& m);
    MtVector3 calcVec3MtxTransformNormal(const MtVector3& v, const MtMatrix& m);
    MtVectorU4 cmpVec3LE(const MtVector3& v0, const MtVector3& v1);
    MtVectorU4 cmpVec3GT(const MtVector3& v0, const MtVector3& v1);
    MtVectorU4 cmpVec3GE(const MtVector3& v0, const MtVector3& v1);
    u32 cmpVec3AllEQ(const MtVector3& v0, const MtVector3& v1, bool FlgIgnoreW);
    MtVector3 getVec3Splat(const MtVector3& v, u32 id);
    MtVector3 getVec3Select(const MtVector3& v0, const MtVector3& v1, const MtVectorU4& pattern);
    MtVector3 getVec3Sqrt(const MtVector3& v);
    MtVector3 getVec3RSqrt(const MtVector3& v);
    f32 getVec3MaxElement(const MtVector3& vec);
    bool isVec3Empty(const MtVector3& vec, f32 epsilon);
    bool isVec3Empty(const MtVector3& v0, const MtVector3& v1, f32 epsilon);
    bool isVec3EQ(const MtVector3& v0, const MtVector3& v1, f32 epsilon);
    MtVector3 insertVec3ZeroToW(const MtVector3& vec);
    MtVector4 calcVec4MAdd(const MtVector4& _base, const MtVector4& _mul, const MtVector4& _add);
    MtVectorU4 cmpVec4EQ(const MtVector4& v0, const MtVector4& v1);
    MtVectorU4 cmpVec4LT(const MtVector4& v0, const MtVector4& v1);
    MtVectorU4 cmpVec4LE(const MtVector4& v0, const MtVector4& v1);
    MtVectorU4 cmpVec4GE(const MtVector4& v0, const MtVector4& v1);
    MtVectorU4 cmpVec4GT(const MtVector4& v0, const MtVector4& v1);
    u32 cmpVec4AllEQ(const MtVector4& v0, const MtVector4& v1);
    bool isVec4EQ(const MtVector4& v0, const MtVector4& v1, f32 epsilon);
    MtMatrix getMatrix3x4(const MtMatrix& mat1);
    f32 getMatrixScaleMaxScalar(const MtMatrix& mat);
    bool isMatrixNearEQ(const MtMatrix& m0, const MtMatrix& m1, f32 epsilon);
    bool isMatrixEQ(const MtMatrix& m0, const MtMatrix& m1);
    f32 calcF32Reciprocal(f32 v);
    MtVector3 calcVec3DotByMatrixLine3(const MtVector3& vec, const MtMatrix& mat);
    void calcVec3Info(const MtVector3& SrcVec, MtVector3& DestLen4, MtVector3& DestLenR4, MtVector3& DestLenSq4, MtVector3& DestVecN);
    MtVectorU4 cmpVec3LT(const MtVector3& v0, const MtVector3& v1);
    u32 cmpVec3AllLT(const MtVector3& v0, const MtVector3& v1, bool FlgIgnoreW);
    u32 cmpVec3AnyGT(const MtVector3& v0, const MtVector3& v1, bool FlgIgnoreW);
    u32 cmpVec3DotResultGT(const MtVector3& v0, const MtVector3& v1, const MtVector3& CmpParamXYZW);
    u32 cmpVec3DotResultGE(const MtVector3& v0, const MtVector3& v1, const MtVector3& CmpParamXYZW);
    u32 cmpVec3DotResultLT(const MtVector3& v0, const MtVector3& v1, const MtVector3& CmpParamXYZW);
    MtVector3 getVec3Permute(const MtVector3& v0, const MtVector3& v1, const MtVectorU4& pattern);
    MtVector3 getVec3ReciprocalSafe(const MtVector3& v);
    u32 getVec3MaxElementID(const MtVector3& vec);
    u32 cmpVec4AllLT(const MtVector4& v0, const MtVector4& v1);
    u32 cmpVec4AnyGT(const MtVector4& v0, const MtVector4& v1);
    MtVector4 getVec4ReciprocalSafe(const MtVector4& v);
    MtVector4 getVec4Select(const MtVector4& v0, const MtVector4& v1, const MtVectorU4& pattern);
    MtMatrix getNormalizedMatrix3x3(const MtMatrix& mat1);
    MtMatrix getAbsoluteMatrix3x4(const MtMatrix& mat1);

}  // namespace MtCollisionUtil

inline MtCollisionUtil::MtArrayElement::MtArrayElement() {
}

inline MtCollisionUtil::MtStack::MtStack() {
}

inline MtCollisionUtil::MtTreeDTI::MtTreeDTI() {
}
