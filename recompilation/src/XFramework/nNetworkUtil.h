#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "../MT/MtNetSession.h"
#include "../MT/MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
struct MtNetSessionInfo;
class MtProperty;
class MtPropertyList;
class MtString;
class MtUI;

// Declarations
namespace nNetwork { class SearchFilterListPtr; }
namespace nNetwork { class SearchFilterPtr; }
namespace nNetwork { class SearchKeyListPtr; }
namespace nNetwork { class SearchKeyPtr; }
namespace nNetwork { class SearchResultListPtr; }
namespace nNetwork { class SearchResultPtr; }
namespace nNetwork { class SessionBinaryPtr; }
namespace nNetwork { class SessionInfoPtr; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

namespace nNetwork {
    class SearchKeyPtr : public ::MtObject
    {
        friend class nNetwork::SearchResultListPtr;
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
        SearchKeyPtr();
        virtual ~SearchKeyPtr() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void init(MtNetSessionInfo::SearchKey& key);
        void exportString(MtString& str);
        void trace();
    private:
        MtNetSessionInfo::SearchKey* mpKey;  // offset: 0x8
    public:
        static MyDTI DTI;
    };
}  // namespace nNetwork

namespace nNetwork {
    class SessionBinaryPtr : public ::MtObject
    {
        friend class nNetwork::SearchResultListPtr;
    public:
        SessionBinaryPtr();
        SessionBinaryPtr(MtNetSessionInfo::Binary& bin);
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        void exportHex(MtString& str);
        void importHex(MtString& str);
        void exportString(MtString& str);
    private:
        MtNetSessionInfo::Binary* mpBinary;  // offset: 0x8
    };
}  // namespace nNetwork

namespace nNetwork {
    class SearchFilterPtr : public ::MtObject
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
        SearchFilterPtr();
        virtual ~SearchFilterPtr() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void init(MtNetSession::SearchKeyFilter& filter);
        void exportString(MtString& str);
        void trace();
    private:
        MtNetSession::SearchKeyFilter* mpFilter;  // offset: 0x8
        nNetwork::SearchKeyPtr mKey;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nNetwork

namespace nNetwork {
    class SearchKeyListPtr : public ::MtObject
    {
        friend class nNetwork::SearchResultListPtr;
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
        SearchKeyListPtr();
        virtual ~SearchKeyListPtr() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        const MtNetSessionInfo::SearchKeyList* getSearchKeyList() const;
        void init(MtNetSessionInfo::SearchKeyList& list);
        void exportString(MtString& str);
        void trace();
    private:
        MtNetSessionInfo::SearchKeyList* mpSearchKeyList;  // offset: 0x8
        nNetwork::SearchKeyPtr mList[8];  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nNetwork

namespace nNetwork {
    class SessionInfoPtr : public ::MtObject
    {
        friend class nNetwork::SearchResultListPtr;
    public:
        SessionInfoPtr();
        virtual ~SessionInfoPtr() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        void init(MtNetSessionInfo& info);
    private:
        MtNetSessionInfo* mpSessionInfo;  // offset: 0x8
        nNetwork::SearchKeyListPtr mList;  // offset: 0x10
        nNetwork::SessionBinaryPtr mBinary;  // offset: 0xa0
    };
}  // namespace nNetwork

namespace nNetwork {
    class SearchFilterListPtr : public ::MtObject
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
        SearchFilterListPtr();
        virtual ~SearchFilterListPtr() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        const MtNetSession::SearchKeyFilterList* getFilterList() const;
        void init(MtNetSession::SearchKeyFilterList& list);
        void exportString(MtString& str);
        void trace();
    private:
        MtNetSession::SearchKeyFilterList* mpList;  // offset: 0x8
        nNetwork::SearchFilterPtr mList[8];  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nNetwork

namespace nNetwork {
    class SearchResultPtr : public ::MtObject
    {
        friend class nNetwork::SearchResultListPtr;
    public:
        SearchResultPtr();
        virtual ~SearchResultPtr() {}
        void setPing(MtNetSession::Ping* ping);
        const MtNetSession::Ping* getPing() const;
        void setBinary(MtNetSessionInfo::Binary* binary);
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        void init(MtNetSession::SearchResult& result);
    private:
        MtNetSession::SearchResult* mpSearchResult;  // offset: 0x8
        nNetwork::SessionInfoPtr mInfo;  // offset: 0x10
        MT_CTSTR mName;  // offset: 0xc0
        MtNetSession::Ping mPing;  // offset: 0xc8
    };
}  // namespace nNetwork

namespace nNetwork {
    class SearchResultListPtr : public ::MtObject
    {
    public:
        SearchResultListPtr();
        virtual ~SearchResultListPtr() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        u32 getNum() const;
        void setNum(u32 num);
        nNetwork::SearchResultPtr* getSearchResultPtr(u32 index);
        const nNetwork::SearchResultPtr* getSearchResultPtr(u32) const;
        void setSearchResultPtr(nNetwork::SearchResultPtr* pptr, u32 index);
        void init(MtNetSession::SearchResultList& list);
    private:
        MtNetSession::SearchResultList* mpSearchResultList;  // offset: 0x8
        nNetwork::SearchResultPtr mResult[32];  // offset: 0x10
    };
}  // namespace nNetwork
