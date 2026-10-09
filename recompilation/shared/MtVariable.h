#pragma once

#include <cstdint>
#include <cstddef>

// Declarations
class MtVariable;

// Type aliases from DWARF
using f32 = float;
using s32 = int;
using u32 = unsigned int;

class MtVariable
{
public:
    enum Type
    {
        UINT = 0,
        INT = 1,
        FLOAT = 2,
        FORCEWORD = -1,
    };
public:
    MtVariable();
    MtVariable(u32 ui);
    MtVariable(s32);
    MtVariable(f32 ff);
    MtVariable(Type type);
    ~MtVariable();
    Type getType() const;
    void setType(Type type);
    MtVariable& operator=(u32 ui);
    MtVariable& operator=(s32 ii);
    MtVariable& operator=(f32 ff);
    operator unsigned int() const;
    operator int() const;
    operator float() const;
    MtVariable operator+(const MtVariable& res) const;
    MtVariable operator-(const MtVariable& res) const;
    MtVariable operator*(const MtVariable& res) const;
    MtVariable operator/(const MtVariable& res) const;
    u32 getUint() const;
    void setUint(u32);
    s32 getInt() const;
    void setInt(s32);
    f32 getFloat() const;
    void setFloat(f32);
private:
    Type mType;  // offset: 0x0
    union
    {
    public:
        u32 mUint;  // offset: 0x0
        s32 mInt;  // offset: 0x0
        f32 mFloat;  // offset: 0x0
    };  // offset: 0x4
};
