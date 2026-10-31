// The deserialization harness's second forced include (024 T882). The
// bundle's `MtStlAllocator<T>` derives from `std::allocator<T>` (DWARF) and
// declares no `rebind`, so in C++17 it inherits `std::allocator<T>::rebind`,
// which names `std::allocator<U>`. Host libstdc++ then rejects every
// container over it (`rebind_alloc<A::value_type> must be A`): 105 of
// merge2b's units. The game's containers hold `_Wrap_alloc<MtStlAllocator<
// std::_Tree_node<…>>>` and `<…_List_node<…>>` (DWARF), so in the game the
// rebind of `MtStlAllocator<T>` is `MtStlAllocator<U>`. SDK 2.500's library
// prefers a member rebind too (`_Get_rebind_type`), and rebinds the bundle's
// class to `std::allocator<U>` (probed with its compiler), so the game's
// class had a rebind of its own that no DIE records.
//
// C++20 gets that by removing `std::allocator::rebind` (P0619): an allocator
// without a rebind of its own is rebound by replacing its first template
// argument ([allocator.traits.types]). The host cannot compile at C++20: it
// also removes `std::allocator<T>::pointer`, which the bundle's `pointer`
// typedef names. So here, in C++17, a rebind found in `std::allocator` through
// a base is ignored, as C++20 does. Allocators with a rebind of their own, and
// `std::allocator` itself, keep libstdc++'s rule: this specialization is
// removed for them by substitution failure. No bundle class is named or
// changed.
#pragma once

#include <bits/alloc_traits.h>

#if __cplusplus <= 201703L
namespace std {

// Whether `_Alloc::rebind<_Up>` is `std::allocator<value_type>`'s own member,
// found through a base of `_Alloc`.
template <typename _Alloc, typename _Up, typename = void>
struct __ddon_inherited_rebind : false_type {};

template <typename _Alloc, typename _Up>
struct __ddon_inherited_rebind<
    _Alloc, _Up,
    __void_t<typename _Alloc::template rebind<_Up>,
             typename allocator<typename _Alloc::value_type>::template rebind<_Up>>>
    : __and_<__not_<is_same<_Alloc, allocator<typename _Alloc::value_type>>>,
             is_same<typename _Alloc::template rebind<_Up>,
                     typename allocator<typename _Alloc::value_type>::template rebind<_Up>>> {};

template <template <typename, typename...> class _Template, typename _Tp, typename... _Args,
          typename _Up>
struct __allocator_traits_base::__rebind<
    _Template<_Tp, _Args...>, _Up,
    __void_t<typename _Template<_Tp, _Args...>::template rebind<_Up>::other,
             typename enable_if<__ddon_inherited_rebind<_Template<_Tp, _Args...>, _Up>::value>::type>>
    : __replace_first_arg<_Template<_Tp, _Args...>, _Up> {
    static_assert(is_same<typename __replace_first_arg<
                              _Template<_Tp, _Args...>,
                              typename _Template<_Tp, _Args...>::value_type>::type,
                          _Template<_Tp, _Args...>>::value,
                  "allocator_traits<A>::rebind_alloc<A::value_type> must be A");
};

}  // namespace std
#endif

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
