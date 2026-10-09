#pragma once

#include <cstdint>
#include <cstddef>

// Declarations
class MtDebug;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;

class MtDebug
{
public:
    static MtDebug& getInstance();
    void setTraceHandler(void(*tout)(MT_CTSTR, void*), void* param);
    void setWarningHandler(void(*tout)(MT_CTSTR, void*), void* param);
    void setErrorHandler(void(*tout)(MT_CTSTR, void*), void* param);
    void setInfoHandler(void(*tout)(MT_CTSTR, void*), void* param);
    void setAbortHandler(void(*tout)(MT_CTSTR, void*), void* param);
    void abort(MT_CTSTR format, ...);
    static void defaultTraceHandler(MT_CTSTR buf, void*);
    static void defaultWarningHandler(MT_CTSTR buf, void*);
    static void defaultErrorHandler(MT_CTSTR buf, void*);
    static void defaultAbortHandler(MT_CTSTR buf, void*);
    static void defaultInfoHandler(MT_CTSTR buf, void*);
private:
    MtDebug();
    ~MtDebug();
private:
    void(*mTraceHandler)(MT_CTSTR, void*);  // offset: 0x0
    void(*mErrorHandler)(MT_CTSTR, void*);  // offset: 0x8
    void(*mWarningHandler)(MT_CTSTR, void*);  // offset: 0x10
    void(*mAbortHandler)(MT_CTSTR, void*);  // offset: 0x18
    void(*mInfoHandler)(MT_CTSTR, void*);  // offset: 0x20
    void* mTraceParam;  // offset: 0x28
    void* mErrorParam;  // offset: 0x30
    void* mWarningParam;  // offset: 0x38
    void* mAbortParam;  // offset: 0x40
    void* mInfoParam;  // offset: 0x48
    static MtDebug mInstance;
};
