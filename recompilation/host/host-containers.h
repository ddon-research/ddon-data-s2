// host-stl.h's SDK containers' layout, for a host whose C++ library is
// not libstdc++ (the inherited-rebind half before it is libstdc++'s).
#pragma once

// The SDK containers' layout (026 plan-P118, ruling P118-A). The game's
// library (SDK 2.500's Dinkumware, `_HAS_DEBUG_COMPATIBILITY` 1 in yvals.h)
// puts an 8-byte `_Container_base0::_Myproxy` at offset 0 of every container,
// so DWARF's `std::vector<T, MtStlAllocator<T>>` is 32 bytes and its map and
// set are 24, where the host's libstdc++ gives 24 and 48: 136 of the golden's
// layout.json records differed on this host. Over
// the bundle's allocator, these specializations hold DWARF's members, with
// their names, types, order and offsets (the DIEs below, from the first CU
// that holds them). A specialization of a std template on a program-defined
// allocator is allowed ([namespace.std]).
//
// Their API is the one the bundle's units use, which is none (the census of
// the units: no unit calls a member of an MtStlVector, MtStlMap or
// MtStlSet, nor reads one of these data members): a container is built empty
// and destroyed, and nothing here allocates. The PS4's map and set allocate
// their head node on construction; here `_Myhead` stays null, as no unit
// reaches it. A member function a unit comes to call is added here, its
// storage behind these members.
#include <cstddef>
#include <functional>
#include <map>
#include <set>
#include <utility>
#include <vector>

template <typename Type> class MtStlAllocator;

namespace std {

// `_Container_base0::_Myproxy`'s pointee (DIE 0x5d85's type); only pointed to.
struct _Container_proxy;
// The tree's node (`_Tree_val<…>::_Nodeptr` is `_Tree_node<value_type,
// _Voidptr>*`, DIE 0x17641ce); only pointed to.
template <typename _Value_type, typename _Voidptr> struct _Tree_node;

// DIE 0x751a (`_Vector_alloc<false, _Vec_base_types<unsigned int,
// MtStlAllocator<unsigned int>>>`, 0x20, no allocator member) : 0x7582
// (`_Vector_val`, 0x20) : `_Container_base0` (0x5d7d, 0x08).
template <typename _Ty>
class vector<_Ty, MtStlAllocator<_Ty>> {
public:
    using value_type = _Ty;
    using allocator_type = MtStlAllocator<_Ty>;
    using size_type = size_t;
    using difference_type = ptrdiff_t;
    using pointer = _Ty*;
    using const_pointer = const _Ty*;
    using reference = _Ty&;
    using const_reference = const _Ty&;

    _Container_proxy* _Myproxy = nullptr;  // 0x00 (DIE 0x5d85)
    pointer _Myfirst = nullptr;            // 0x08 (DIE 0x7593)
    pointer _Mylast = nullptr;             // 0x10 (DIE 0x75af)
    pointer _Myend = nullptr;              // 0x18 (DIE 0x75be)
};

// DIE 0x1763ec5 (`map<unsigned int, unsigned int, less<unsigned int>,
// MtStlAllocator<pair<const unsigned int, unsigned int>>>`, 0x18) : `_Tree`
// : `_Tree_comp<false, …>` : `_Tree_buy` : `_Tree_alloc<false, …>` (no
// comparator or allocator member) : `_Tree_val` (0x17641b0) :
// `_Container_base0`.
template <typename _Kty, typename _Ty, typename _Pr>
class map<_Kty, _Ty, _Pr, MtStlAllocator<pair<const _Kty, _Ty>>> {
public:
    using key_type = _Kty;
    using mapped_type = _Ty;
    using key_compare = _Pr;
    using value_type = pair<const _Kty, _Ty>;
    using allocator_type = MtStlAllocator<value_type>;
    using size_type = size_t;
    using difference_type = ptrdiff_t;

    _Container_proxy* _Myproxy = nullptr;              // 0x00 (DIE 0x5d85)
    _Tree_node<value_type, void*>* _Myhead = nullptr;  // 0x08 (DIE 0x17641c0)
    size_type _Mysize = 0;                             // 0x10 (DIE 0x17641da)
};

// DIE 0x697b (`set<MtString, less<MtString>, MtStlAllocator<MtString>>`,
// 0x18) : `_Tree<_Tset_traits<…>>` and the same chain to `_Tree_val`
// (0x6bc1: `_Myhead` 0x6bd2, `_Mysize` 0x6bee) : `_Container_base0`.
template <typename _Kty, typename _Pr>
class set<_Kty, _Pr, MtStlAllocator<_Kty>> {
public:
    using key_type = _Kty;
    using value_type = _Kty;
    using key_compare = _Pr;
    using value_compare = _Pr;
    using allocator_type = MtStlAllocator<_Kty>;
    using size_type = size_t;
    using difference_type = ptrdiff_t;

    _Container_proxy* _Myproxy = nullptr;              // 0x00 (DIE 0x5d85)
    _Tree_node<value_type, void*>* _Myhead = nullptr;  // 0x08 (DIE 0x6bd2)
    size_type _Mysize = 0;                             // 0x10 (DIE 0x6bee)
};

}  // namespace std
