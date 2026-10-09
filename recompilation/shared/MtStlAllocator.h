#pragma once

#include <cstdint>
#include <cstddef>

// Standard library
#include <memory>

// Declarations
template <typename Type> class MtStlAllocator;

template <typename Type>
class MtStlAllocator : public std::allocator<Type>
{
public:
    using pointer = typename std::allocator<Type>::pointer;
    using size_type = typename std::allocator<Type>::size_type;
public:
    // inferred: an allocator's rebind, from DWARF's MtStlAllocator<std::_Tree_node<value_type, _Voidptr> > (DIE 0x7393c), an instance for the library's node std::_Tree_node<value_type, _Voidptr>
    template <class U> struct rebind { typedef MtStlAllocator<U> other; };
    template <typename Type1> MtStlAllocator(const MtStlAllocator<Type1>& allocator);
public:
    MtStlAllocator();
    MtStlAllocator(const MtStlAllocator<Type>& allocator);
    pointer allocate(size_type num);
    void deallocate(pointer block, size_type);
};
