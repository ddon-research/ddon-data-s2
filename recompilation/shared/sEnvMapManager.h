#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "cSystem.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
class MtVector4;
class cDraw;
class rRenderTargetTexture;
class rTexture;

// Declarations
class sEnvMapManager;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class sEnvMapManager : public cSystem
{
public:
    enum MANAGE_ENVMAP
    {
        ENVMAP_DEFAULT = 0,
        ENVMAP_EFFECT = 1,
        ENVMAP_MAX_NUM = 2,
        ENVMAP_FORCE_UNSIGNED_INTEGER = -1,
    };
public:
    class MyDTI;
    class cManageEnvMapBase;
    class cManageEnvMapField;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cManageEnvMapBase : public MtObject
    {
    public:
        enum UPDATE_STATE
        {
            UPDATE_RIGHT = 0,
            UPDATE_LEFT = 1,
            UPDATE_UP = 2,
            UPDATE_DOWN = 3,
            UPDATE_FORWORD = 4,
            UPDATE_BACKGROUND = 5,
            UPDATE_NUM = 6,
            UPDATE_BEGIN = 0,
            UPDATE_END = 5,
            UPDATE_COMPULSORY = 6,
            UPDATE_NOBODY = 7,
            UPDATE_FORCE_UNSIGNED_INTEGER = -1,
        };
    public:
        struct CUBIC_BLUR_VERTEX;
        class MyDTI;
    public:
        struct CUBIC_BLUR_VERTEX
        {
        public:
            f32 x;  // offset: 0x0
            f32 y;  // offset: 0x4
            f32 tx;  // offset: 0x8
            f32 ty;  // offset: 0xc
            f32 tz;  // offset: 0x10
        };
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
        cManageEnvMapBase();
        virtual ~cManageEnvMapBase();
        rRenderTargetTexture* getRtt() const;
        rTexture* getTexture() const;
        void setRenderTargetTexture(rRenderTargetTexture* prtt);
        void setTexture(rTexture* ptex);
        void raiseUnit();
        void update();
        static void raiseDraw(MtObject* object, cDraw* pdraw);
        // Address: 0x01ac3f30 - 0x01ac3f31 (1 bytes)
        virtual void draw(cDraw* pdraw) {}  // vtable slot 6
    public:
        rRenderTargetTexture* mpRtt;  // offset: 0x8
        rTexture* mpTexture;  // offset: 0x10
        bool bCompulsory;  // offset: 0x18
        bool bUpdate;  // offset: 0x19
        bool isDraw;  // offset: 0x1a
        u32 mUpdateState;  // offset: 0x1c
        u32 mLive;  // offset: 0x20
        bool mbInitialRendering;  // offset: 0x24
        void(*mfCallDraw)(MtObject*, cDraw*);  // offset: 0x28
    protected:
        static const CUBIC_BLUR_VERTEX maBlurVertex[];
    public:
        static MyDTI DTI;
    };
public:
    class cManageEnvMapField : public sEnvMapManager::cManageEnvMapBase
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
        cManageEnvMapField();
        virtual ~cManageEnvMapField();
        virtual void draw(cDraw* pdraw);  // vtable slot 6
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        rTexture* getBlendTexture() const;
        void setBlendTexture(rTexture*);
        void setMapBlendFactor(f32);
        void setBlendColor(const MtVector4&);
        void setBaseBlendColor(const MtVector3&);
    private:
        rTexture* mpBlendTexture;  // offset: 0x30
        f32 mMapBlendFactor;  // offset: 0x38
        MtVector4 mBlendColor;  // offset: 0x40
        MtVector3 mBaseBlendColor;  // offset: 0x50
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
    sEnvMapManager();
    virtual ~sEnvMapManager();
    virtual void move();  // vtable slot 7
    cManageEnvMapBase* getEnvMap(MANAGE_ENVMAP);
    static sEnvMapManager* getInstance();
public:
    cManageEnvMapBase* mapManagedEnvMap[2];  // offset: 0x18
    static MyDTI DTI;
    static sEnvMapManager* mpInstance;
};
