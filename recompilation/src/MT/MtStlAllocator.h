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
    template <class U> struct rebind { typedef MtStlAllocator<U> other; };
    template <typename Type1> MtStlAllocator(const MtStlAllocator<Type1>& allocator);
public:
    MtStlAllocator();
    MtStlAllocator(const MtStlAllocator<Type>& allocator);
    pointer allocate(size_type num);
    void deallocate(pointer block, size_type);
};
