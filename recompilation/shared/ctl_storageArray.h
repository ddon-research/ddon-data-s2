#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "cpLockOn.h"
#include "ctl_typetraits.h"

// Forward declarations
class uDDOModel;

// Declarations
namespace ctl { namespace detail { class basic_storageArray; } }
template <typename T, long unsigned int ELEMENT_NUM> class MtTypedStorageArray;
namespace ctl { namespace detail { template <typename T, long unsigned int ELEMENT_NUM, long unsigned int WARN_SIZE, long unsigned int ERR_SIZE> class storageArray; } }

// Type aliases from DWARF
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

namespace ctl {
    namespace detail {
        class basic_storageArray
        {
        public:
            basic_storageArray();
            basic_storageArray(const ctl::detail::basic_storageArray&);
        };
    }  // namespace detail
}  // namespace ctl

namespace ctl {
    namespace detail {
        // Layout verified against DWARF for storageArray<cpLockOn::cLockOnTarget*, 16, 16384, 65536>, storageArray<cpLockOn::cLockOnTarget*, 32, 16384, 65536>, storageArray<uDDOModel*, 8, 16384, 65536>
        template <typename T, long unsigned int ELEMENT_NUM, long unsigned int WARN_SIZE, long unsigned int ERR_SIZE>
        class storageArray : public ctl::detail::basic_storageArray
        {
        public:
            storageArray();
            void fill(u8 value);
            T& operator[](size_t index);
        protected:
            void validate();
            size_t getElementNum() const;
            T* getBuffer();
            size_t getSizeBuffer() const;
            const T* getBuffer() const;
        private:
            T mBuffer[ELEMENT_NUM];  // offset: 0x0
        };
    }  // namespace detail
}  // namespace ctl

template <>
class MtTypedStorageArray<cpLockOn::cLockOnTarget, 16> : public ctl::detail::storageArray<cpLockOn::cLockOnTarget*, 16, 16384, 65536>
{
public:
    using container_type = ctl::traits::add_pointer<cpLockOn::cLockOnTarget>::type;
public:
    MtTypedStorageArray();
    ~MtTypedStorageArray();
    bool isAutoDelete() const;
    void add(container_type pobj);
    void clear(bool dummy);
    void deleteAll(bool dummy);
    container_type& at(size_t index);
    u32 length() const;
    u32 capacity() const;
protected:
    size_t mBufferPt;  // offset: 0x80
    bool mAutoDelete;  // offset: 0x88
};

template <>
class MtTypedStorageArray<cpLockOn::cLockOnTarget, 32> : public ctl::detail::storageArray<cpLockOn::cLockOnTarget*, 32, 16384, 65536>
{
public:
    using container_type = ctl::traits::add_pointer<cpLockOn::cLockOnTarget>::type;
public:
    MtTypedStorageArray();
    ~MtTypedStorageArray();
    bool isAutoDelete() const;
    void add(container_type pobj);
    void clear(bool dummy);
    void deleteAll(bool dummy);
    void erase(u32 index);
    container_type& at(size_t index);
    u32 length() const;
    u32 size() const;
    u32 capacity() const;
    void insert(container_type pobj, u32 index);
protected:
    size_t mBufferPt;  // offset: 0x100
    bool mAutoDelete;  // offset: 0x108
};

template <>
class MtTypedStorageArray<uDDOModel, 8> : public ctl::detail::storageArray<uDDOModel*, 8, 16384, 65536>
{
public:
    using container_type = ctl::traits::add_pointer<uDDOModel>::type;
public:
    MtTypedStorageArray();
    ~MtTypedStorageArray();
    bool isAutoDelete() const;
    void add(container_type pobj);
    void clear(bool dummy);
    void deleteAll(bool dummy);
    void erase(u32 index);
    container_type& at(size_t index);
    const container_type& at(size_t index) const;
    u32 length() const;
    u32 capacity() const;
protected:
    size_t mBufferPt;  // offset: 0x40
    bool mAutoDelete;  // offset: 0x48
};
