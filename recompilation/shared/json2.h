#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
namespace sce { namespace Json { class Array; } }
namespace sce { namespace Json { class Object; } }
namespace sce { namespace Json { struct RootParam; } }

// Declarations
namespace sce { namespace Json { class MemAllocator; } }
namespace sce { namespace Json { class String; } }
namespace sce { namespace Json { class Value; } }

namespace sce {
namespace Json {
    enum ValueType
    {
        kValueTypeNull = 0,
        kValueTypeBoolean = 1,
        kValueTypeInteger = 2,
        kValueTypeUInteger = 3,
        kValueTypeReal = 4,
        kValueTypeString = 5,
        kValueTypeArray = 6,
        kValueTypeObject = 7,
    };
}  // namespace Json
}  // namespace sce

// Type aliases from DWARF
using _Sizet = long unsigned int;
using __int32_t = int;
using __int64_t = long int;
using __uint64_t = long unsigned int;
using int32_t = __int32_t;
using int64_t = __int64_t;
using size_t = _Sizet;
using uint64_t = __uint64_t;

namespace sce {
    namespace Json {
        class MemAllocator
        {
        public:
            MemAllocator();
            virtual ~MemAllocator() {}
            virtual void* allocate(size_t, void*) = 0;  // vtable slot 2
            virtual void deallocate(void*, void*) = 0;  // vtable slot 3
        };
    }  // namespace Json
}  // namespace sce

namespace sce {
    namespace Json {
        class String
        {
        public:
            String();
            String(const char*);
            String(const sce::Json::String&);
            ~String();
            const char* c_str() const;
        private:
            void* m_impl;  // offset: 0x0
        public:
            static const size_t npos;
        };
    }  // namespace Json
}  // namespace sce

namespace sce {
    namespace Json {
        class Value
        {
        public:
            using NullAccessFunction = const sce::Json::Value& (*)(sce::Json::ValueType, const sce::Json::Value*, void*);
        public:
            ~Value();
            Value();
            Value(int64_t);
            Value(const sce::Json::String&);
            Value(const sce::Json::Array&);
            Value(const sce::Json::Object&);
            Value(const sce::Json::Value&);
            sce::Json::Value& operator=(const sce::Json::Value&);
            sce::Json::String toString() const;
            void toString(sce::Json::String&) const;
            int32_t serialize(sce::Json::String&);
            void clear();
            void set(sce::Json::ValueType);
            void set(const sce::Json::Object&);
            const sce::Json::String& getString() const;
            const int64_t& getInteger() const;
            const bool& getBoolean() const;
            const sce::Json::Value& operator[](size_t) const;
            const sce::Json::Value& operator[](const char*) const;
            int32_t count() const;
            int32_t setNullAccessCallBack(NullAccessFunction, void*);
        private:
            sce::Json::Value* m_parent;  // offset: 0x0
            sce::Json::RootParam* m_rootparam;  // offset: 0x8
            union
            {
            public:
                bool m_boolean;  // offset: 0x0
                int64_t m_integer;  // offset: 0x0
                uint64_t m_uinteger;  // offset: 0x0
                double m_real;  // offset: 0x0
                sce::Json::String* m_string;  // offset: 0x0
                sce::Json::Array* m_array;  // offset: 0x0
                sce::Json::Object* m_object;  // offset: 0x0
            };  // offset: 0x10
            char _padding[4];  // offset: 0x18
            sce::Json::ValueType m_type;  // offset: 0x1c
        public:
            static const sce::Json::String* s_nullstring;
            static const sce::Json::Array* s_nullarray;
            static const sce::Json::Object* s_nullobject;
            static const int64_t s_nullinteger;
            static const uint64_t s_nulluinteger;
            static const double s_nullreal;
            static const bool s_nullbool;
        };
    }  // namespace Json
}  // namespace sce
