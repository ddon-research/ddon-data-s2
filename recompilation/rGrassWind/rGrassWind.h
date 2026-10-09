#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/MtProperty.h"
#include "../shared/MtString.h"
#include "../shared/cResource.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtStream;
class MtString;
class MtUI;
class cUnit;

// Declarations
class rGrassWind;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class rGrassWind : public cResource
{
public:
    class MyDTI;
    class cParamSet;
    class cParams;
    class cParamSetSync;
    struct HEADER;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cParamSet : public MtObject
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
        cParamSet(MtProperty* prop);
        virtual ~cParamSet();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual bool save(MtStream& out);  // vtable slot 6
        virtual bool load(MtStream& in);  // vtable slot 7
        virtual bool isEnable() const;  // vtable slot 8
        MT_CTSTR getName() const;
        f32 getMax() const;
        f32 getMin() const;
        f32 getValue(u32 param_no, f32 frame);
        f32 getValue(f32 frame);
        void sortParam();
    protected:
        u32 seekFrame(u32 begin_param_no, u32 frame_no);
    protected:
        MtString mName;  // offset: 0x8
        f32 mMax;  // offset: 0x10
        f32 mMin;  // offset: 0x14
        u32 mParamNum;  // offset: 0x18
        rGrassWind::cParams* mpParams;  // offset: 0x20
    public:
        static MyDTI DTI;
    };
public:
    class cParams
    {
    public:
        cParams();
        cParams(u16, u16);
        cParams(rGrassWind::cParams& param);
        u32 getKey() const;
        u32 getFrameNo() const;
        f32 getValue() const;
        bool isSelect() const;
        void setFrameNo(u32);
        void setValue(f32);
        void setSelect(bool);
    protected:
        union
        {
        public:
            struct
            {
            public:
                u32 mSelect : 1;  // offset: 0x0
                u32 mValue : 16;  // offset: 0x0
                u32 mFrameNo : 15;  // offset: 0x0
            };  // offset: 0x0
            u32 mKey;  // offset: 0x0
        };  // offset: 0x0
    };
public:
    class cParamSetSync
    {
    public:
        struct syncParams;
    public:
        struct syncParams
        {
        public:
            MtProperty mProp;  // offset: 0x0
            rGrassWind::cParamSet* mpParams;  // offset: 0x70
        };
    public:
        cParamSetSync();
        ~cParamSetSync();
        void play(f32 dt);
        bool isSynced();
        void synchronization(cUnit* p_unit, rGrassWind* p_resource);
        void setCurrentFrame(f32 frame);
    protected:
        f32 mCurrentFrame;  // offset: 0x0
        rGrassWind* mpResource;  // offset: 0x8
        cUnit* mpUnit;  // offset: 0x10
        u32 mPropNum;  // offset: 0x18
        syncParams mProps[32];  // offset: 0x20
        static const u32 MAX_PROP_NUM = 32;
    };
public:
    struct HEADER
    {
    public:
        u32 magic;  // offset: 0x0
        u16 version;  // offset: 0x4
        u16 dummy;  // offset: 0x6
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
    rGrassWind();
    virtual ~rGrassWind();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool save(MtStream& out);  // vtable slot 12
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    u32 getMaxFrame() const;
    bool getAutoDeath() const;
    bool getLoop() const;
    MtArray* getArray();
    u32 getUnitDTI() const;
    u32 getPriority() const;
protected:
    MtArray mParamSetArray;  // offset: 0x70
    u32 mMaxFrame;  // offset: 0x90
    u32 mDTI;  // offset: 0x94
    bool mLoop;  // offset: 0x98
    bool mAutoDeath;  // offset: 0x99
    u32 mPriority;  // offset: 0x9c
public:
    static MyDTI DTI;
protected:
    static const u32 HEADER_MAGIC = 5722695;
    static const u16 DATA_VERSION = 3396;
};
