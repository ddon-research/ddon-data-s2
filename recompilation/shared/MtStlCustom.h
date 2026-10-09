#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtStlAllocator.h"

// Standard library
#include <list>
#include <map>
#include <set>
#include <utility>
#include <vector>

// Declarations
template <typename Type, typename Alloc> class MtStlList;
template <typename Key, typename Val, typename Alloc> class MtStlMap;
template <typename Type, typename Alloc> class MtStlSet;
template <typename Type, typename Alloc> class MtStlVector;

template <typename Type, typename Alloc>
class MtStlList : public std::list<Type, Alloc>
{
public:
    MtStlList();
};

template <typename Key, typename Val, typename Alloc>
class MtStlMap : public std::map<Key, Val, std::less<Key>, Alloc>
{
public:
    MtStlMap();
};

template <typename Type, typename Alloc>
class MtStlSet : public std::set<Type, std::less<Type>, Alloc>
{
public:
    MtStlSet();
};

template <typename Type, typename Alloc>
class MtStlVector : public std::vector<Type, Alloc>
{
public:
    MtStlVector();
};
