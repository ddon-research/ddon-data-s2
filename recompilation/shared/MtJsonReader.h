#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
class MtStream;

// Declarations
class MtJsonReader;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using __int64_t = long int;
using __uint64_t = long unsigned int;
using f64 = double;
using s32 = int;
using s64 = __int64_t;
using u32 = unsigned int;
using u64 = __uint64_t;

class MtJsonReader
{
public:
    class Handler;
public:
    class Handler
    {
    public:
        Handler();
        virtual ~Handler();
        virtual void beginArray();  // vtable slot 2
        virtual void endArray();  // vtable slot 3
        virtual void beginObject();  // vtable slot 4
        virtual void endObject();  // vtable slot 5
        virtual void fieldName(MT_CTSTR chars, const u32);  // vtable slot 6
        virtual void string(MT_CTSTR chars, const u32);  // vtable slot 7
        virtual void number(u64 num);  // vtable slot 8
        virtual void number(s64 num);  // vtable slot 9
        virtual void number(f64 num);  // vtable slot 10
        virtual void booleanTrue();  // vtable slot 11
        virtual void booleanFalse();  // vtable slot 12
        virtual void nullValue();  // vtable slot 13
        virtual void error(MT_CTSTR error);  // vtable slot 14
        bool isError();
    protected:
        bool mError;  // offset: 0x8
    };
public:
    MtJsonReader(MtStream& in);
    virtual ~MtJsonReader();
    virtual bool parse(Handler& handler);  // vtable slot 2
private:
    const MtJsonReader& operator=(const MtJsonReader&);
    u32 Utf16ToUtf8(u32 n);
private:
    MtStream& mStream;  // offset: 0x8
    static const s32 MAX_SRC_BUFSIZE = 4096;
};
