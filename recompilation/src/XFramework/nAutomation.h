#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtSynchronize.h"

// Forward declarations
class MtCriticalSection;
class MtObject;

// Declarations
namespace nAutomation { class RespawnContext; }
namespace nAutomation { class Envelope; }
namespace nAutomation { class CryptoString; }
namespace nAutomation { class Sender; }
namespace nAutomation { class Ticket; }
namespace nAutomation { class FieldProject; }
namespace nAutomation { class DefaultFieldBase; }
namespace nAutomation { class CustomField; }
namespace nAutomation { class FieldTracker; }
namespace nAutomation { class FieldPriority; }
namespace nAutomation { class FieldHash; }
namespace nAutomation { class cUploader; }
namespace nAutomation { struct UPLOAD_DESC; }
namespace nAutomation { struct IdentityInfo; }
namespace nAutomation { struct ReferVersion; }

namespace nAutomation {
    enum eScreenShotMethod
    {
        SSM_NATIVE = 0,
        SSM_ALTERNATIVE = 1,
    };
}  // namespace nAutomation

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_MFUNC = void(MtObject::*)();
using _Sizet = long unsigned int;
using __int64_t = long int;
using f32 = float;
using s64 = __int64_t;
namespace nAutomation { using socket_t = s64; }
using time_t = long int;
using t64 = time_t;
namespace nAutomation { using time_type = t64; }
using s16 = short;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

namespace nAutomation {

    // Forward declarations
    class RespawnContext;
    class Envelope;
    class CryptoString;
    class Sender;
    class Ticket;
    class FieldProject;
    class DefaultFieldBase;
    class CustomField;
    class FieldTracker;
    class FieldPriority;
    class FieldHash;
    class cUploader;
    struct UPLOAD_DESC;
    struct IdentityInfo;
    struct ReferVersion;

    class RespawnContext
    {
    public:
        RespawnContext();
        ~RespawnContext();
        void setApplicationPath(MT_CTSTR szExe);
        MT_CTSTR getApplicationPath() const;
        void setAttributes(u32 attr);
        u32 getAttributes();
        u32 getSupportedAttributes() const;
        u32 writeSharedBuffer(const void* pSrc, u32 nSize);
        u32 writeSharedBufferU32(u32 value);
        u32 writeSharedBufferF32(f32 value);
        u32 readSharedBuffer(void* pDst, u32 nSize) const;
        u32 readSharedBufferU32() const;
        f32 readSharedBufferF32() const;
        u32 getAvailSharedBufferSize() const;
        const void* getSharedBuffer() const;
        void setDRMKey(const void*);
        const void* getDRMKey() const;
    private:
        u32 getSharedBufferCapacity() const;
    private:
        MT_CHAR mApplicationPath[1025];  // offset: 0x0
        u32 mAttribute;  // offset: 0x404
        u8 mSharedBuffer[512];  // offset: 0x408
        u8* mpSharedBufferPtW;  // offset: 0x608
        u8* mpSharedBufferPtR;  // offset: 0x610
    public:
        static const u32 SHARED_BUFFER_SIZE = 512;
        static const u32 SHARED_BUFFER_PHYSICAL_SIZE = 1020;
        static const u32 ATTR_INVALID = 0;
        static const u32 ATTR_SIGNED = 2;
        static const u32 ATTR_DRM = 2;
        static const u32 ATTR_VERIFY_VERSION = 4;
        static const u32 ATTR_FALLBACK = 8;
    };

    class Envelope
    {
    public:
        enum eReceiverType
        {
            RECEIVER_TO = 0,
            RECEIVER_CC = 1,
            RECEIVER_BCC = 2,
        };
        enum eCharset
        {
            CHARSET_UNKNOWN = 0,
            CHARSET_JIS = 1,
            CHARSET_SJIS = 2,
        };
    public:
        struct attachment;
        struct receiver;
        struct HASH;
    public:
        struct attachment
        {
        public:
            MT_CHAR* pBuffer;  // offset: 0x0
            u32 sizeBuffer;  // offset: 0x8
            MT_CHAR name[64];  // offset: 0xc
        };
    public:
        struct receiver
        {
        public:
            nAutomation::Envelope::eReceiverType type;  // offset: 0x0
            MT_CHAR address[256];  // offset: 0x4
        };
    public:
        struct HASH
        {
        public:
            struct ATTACHMENT;
        public:
            struct ATTACHMENT
            {
            public:
                u32 name;  // offset: 0x0
                u32 size;  // offset: 0x4
                u32 buffer;  // offset: 0x8
            };
        public:
            ATTACHMENT attachment[16];  // offset: 0x0
            u32 address[16];  // offset: 0xc0
            u32 from;  // offset: 0x100
            u32 reply;  // offset: 0x104
            u32 subject;  // offset: 0x108
            u32 body;  // offset: 0x10c
            u32 isBusy;  // offset: 0x110
        };
    public:
        Envelope();
        virtual ~Envelope();
        void clear();
        const nAutomation::Envelope& operator=(const nAutomation::Envelope& lhs);
        void setFrom(const char* format, ...);
        void setReplyTo(const char* format, ...);
        void addReceiver(eReceiverType type, const char* format, ...);
        void addReceiver(eReceiverType type, const nAutomation::CryptoString& receiver);
        void writeSubject(const char* format, ...);
        void writeBody(const char* format, ...);
        bool attach(const char* pFilePath, const char* format, ...);
        bool attach(const void* pBuffer, u32 sizeBuffer, const char* format, ...);
        bool attachBase64(const char* pBuffer, u32 sizeBuffer, const char* format, ...);
        void post();
        virtual bool validate() const;  // vtable slot 2
        void setBodyPrefixCallback(MtObject*, MT_MFUNC);
        void setBodyPostfixCallback(MtObject*, MT_MFUNC);
        void setCharset(eCharset charset);
        void addRef();
        u16 getReferenceCount() const;
        void release();
    protected:
        MT_CTSTR getSender() const;
        MT_CTSTR getReplyTo() const;
        MT_CTSTR getSubject() const;
        MT_CTSTR getBody() const;
        u32 getAttachmentNum() const;
        const attachment* getAttachment(u32 index) const;
        u32 getReceiverNum() const;
        const receiver* getReceiver(u32 index) const;
        MT_CTSTR getBodyPrefix() const;
        MT_CTSTR getBodyPostfix() const;
        eCharset getCharset() const;
        bool entryAttachment(void* pAttachment, u32 sizeBuffer, const char* name);
        void calcHash(HASH* pHash) const;
    protected:
        u32 mRefCount;  // offset: 0x8
        u32 mAttachmentNum;  // offset: 0xc
        attachment mAttachment[16];  // offset: 0x10
        u32 mReceiverNum;  // offset: 0x510
        receiver mReceiver[16];  // offset: 0x514
        MT_CHAR mFrom[256];  // offset: 0x1554
        MT_CHAR mReplyTo[256];  // offset: 0x1654
        MT_CHAR* mpSubject;  // offset: 0x1758
        MT_CHAR* mpBody;  // offset: 0x1760
        MtObject* mpPrefixOwner;  // offset: 0x1768
        MT_MFUNC mpPrefixCb;  // offset: 0x1770
        MtObject* mpPostfixOwner;  // offset: 0x1780
        MT_MFUNC mpPostfixCb;  // offset: 0x1788
        eCharset mCharset;  // offset: 0x1798
        static const u32 ADDRESS_LENGTH = 256;
        static const u32 ATTACHMENT_NUM = 16;
        static const u32 RECEIVER_NUM = 16;
        static const u32 SUBJECT_LENGTH = 128;
        static const u32 BODY_LENGTH = 128;
    };

    class CryptoString
    {
    public:
        CryptoString(const u8* pEncrypted, u32 size);
        virtual ~CryptoString() {}
        u32 getEncryptedSize() const;
        bool getDecryptedString(char* pDecrypted, u32 sizeBuffer) const;
    private:
        CryptoString();
    private:
        const u8* mpEncrypted;  // offset: 0x8
        u32 mEncryptedSize;  // offset: 0x10
    };

    class Sender
    {
    public:
        Sender();
        ~Sender();
        void acquire();
        void setServerName(const char* serverName);
        void send(const nAutomation::Envelope* pEnv);
        void release();
        static void getUrgentDLLPath(MT_CHAR* pPath, u32 sizeBuffer);
    private:
        static void sendBuffer(const char* format, ...);
        static void sendBufferDirect(const char* pBuffer);
        void recvBuffer();
        void buildLocalHost();
        nAutomation::socket_t getSocket() const;
        MT_CTSTR getLocalHost() const;
        MT_CTSTR getServerName() const;
        const nAutomation::Envelope* getEnvelope() const;
        void setEnvelope(const nAutomation::Envelope* pEnv);
        void postFromTo(void(*sendBuffer)(const char*, ...));
        void postSubjectBody(void(*sendBuffer)(const char*, ...));
        void postAttachment(void(*sendBuffer)(const char*, ...));
    private:
        MT_CHAR mServerName[128];  // offset: 0x0
        nAutomation::socket_t mSocket;  // offset: 0x80
        MT_CHAR mRecvBuffer[1024];  // offset: 0x88
        MT_CHAR mLocalName[128];  // offset: 0x488
        nAutomation::Envelope::HASH mSentHash[8];  // offset: 0x508
        const nAutomation::Envelope* mpEnvelope;  // offset: 0xda8
        MtCriticalSection mCs;  // offset: 0xdb0
        static const u32 SERVERNAME_LENGTH = 128;
        static const u32 LOCALNAME_LENGTH = 128;
        static const u32 RECVBUFFER_LENGTH = 1024;
        static const u32 SENDHASH_LENGTH = 8;
    };

    class CustomField
    {
    public:
        CustomField();
        virtual ~CustomField() = 0;
        virtual MT_CTSTR getName() = 0;  // vtable slot 2
        virtual MT_CTSTR getValue() = 0;  // vtable slot 3
        void remove();
    private:
        void setPrev(nAutomation::CustomField* pField);
        void setNext(nAutomation::CustomField* pField);
        void setOwner(nAutomation::Ticket* pOwner);
        nAutomation::CustomField* getPrev();
        nAutomation::CustomField* getNext();
        nAutomation::Ticket* getOwner();
    private:
        nAutomation::CustomField* mpPrev;  // offset: 0x8
        nAutomation::CustomField* mpNext;  // offset: 0x10
        nAutomation::Ticket* mpOwner;  // offset: 0x18
    };

    class cUploader
    {
    public:
        using progressRoutine = void(*)(f32, void*);
    public:
        cUploader();
        ~cUploader();
        void setCallback(progressRoutine pProgress, void* pParam);
        void setLocalPrefix(MT_CTSTR);
        void setRemotePrefix(MT_CTSTR);
        bool upload(MT_CTSTR szLocalPath, MT_CTSTR szRemotePath);
    private:
        progressRoutine mpProgress;  // offset: 0x0
        void* mpCbParam;  // offset: 0x8
        MT_CTSTR mpLocalPrefix;  // offset: 0x10
        MT_CTSTR mpRemotePrefix;  // offset: 0x18
    };

    struct UPLOAD_DESC
    {
    public:
        MT_CHAR szBase[1024];  // offset: 0x0
        MT_CHAR szExe[1024];  // offset: 0x400
        MT_CHAR szPdb[1024];  // offset: 0x800
        MT_CHAR szLog[1024];  // offset: 0xc00
        MT_CHAR szConLog[1024];  // offset: 0x1000
        MT_CHAR szDmp[1024];  // offset: 0x1400
        MT_CHAR szBmp[1024];  // offset: 0x1800
    };

    struct IdentityInfo
    {
    public:
        IdentityInfo();
    public:
        u32 sdkVersion;  // offset: 0x0
        MT_CTSTR szCompilerVersion;  // offset: 0x8
        MT_CHAR szExePath[256];  // offset: 0x10
        MT_CHAR szExeDate[64];  // offset: 0x110
        nAutomation::time_type exeDate;  // offset: 0x150
    };

    struct ReferVersion
    {
    public:
        ReferVersion();
        ReferVersion(u32);
    public:
        u32 ship_id;  // offset: 0x0
    };

    class DefaultFieldBase : public nAutomation::CustomField
    {
    public:
        DefaultFieldBase();
        virtual ~DefaultFieldBase() {}
        virtual MT_CTSTR getValue();  // vtable slot 3
        void setValue(MT_CTSTR szValue);
    private:
        MT_CTSTR mpValue;  // offset: 0x20
    };

    class FieldTracker : public nAutomation::DefaultFieldBase
    {
    public:
        FieldTracker();
        virtual ~FieldTracker() {}
        virtual MT_CTSTR getName();  // vtable slot 2
    };

    class FieldPriority : public nAutomation::DefaultFieldBase
    {
    public:
        FieldPriority();
        virtual ~FieldPriority() {}
        virtual MT_CTSTR getName();  // vtable slot 2
    };

    class FieldHash : public nAutomation::DefaultFieldBase
    {
    public:
        FieldHash();
        virtual ~FieldHash() {}
        virtual MT_CTSTR getName();  // vtable slot 2
    };

    class FieldProject : public nAutomation::DefaultFieldBase
    {
    public:
        FieldProject();
        virtual ~FieldProject() {}
        virtual MT_CTSTR getName();  // vtable slot 2
    };

    class Ticket : public nAutomation::Envelope
    {
    public:
        Ticket();
        virtual ~Ticket();
        const nAutomation::Ticket& operator=(const nAutomation::Ticket& lhs);
        void clear();
        void setHostName(MT_CTSTR szHostName, MT_CTSTR szPort);
        void setRemotePath(MT_CTSTR szRemotePath);
        void setAPIKey(MT_CTSTR szKey);
        void setProject(MT_CTSTR szProject);
        void setTracker(MT_CTSTR szTracker);
        void setPriority(MT_CTSTR szPriority);
        void setHash(const char* format, ...);
        void addCustomField(nAutomation::CustomField* pField);
        void removeCustomField(nAutomation::CustomField* pField);
        void setSubject(const char* format, ...);
        void setBody(const char* format, ...);
        void setSubmitter(const char* format, ...);
        void setSubmitter(const nAutomation::CryptoString& submitter);
        bool issue();
        virtual bool validate() const;  // vtable slot 2
    protected:
        static void collectRFC(const char* format, ...);
        void lockRFC(nAutomation::Ticket*);
        void unlockRFC();
        bool openConnection(const char* szHost, const char* szPort);
        void closeConnection();
        void sendBuffer(const char* format, ...);
        void sendBufferDirect(const char* pBuffer);
        char* recvBuffer();
        bool postHTTP(const char* host, const char* remote_path, const char* port, const char* format, ...);
        MT_CTSTR getProject() const;
        MT_CTSTR getTracker() const;
        MT_CTSTR getPriority() const;
        MT_CTSTR getHash() const;
        MT_CTSTR getHostName() const;
        MT_CTSTR getHostPort() const;
        MT_CTSTR getRemotePath() const;
        MT_CTSTR getAPIKey() const;
    private:
        void setFrom(const char*, ...);
        void setReplyTo(const char*, ...);
        void addReceiver(nAutomation::Envelope::eReceiverType, const char*, ...);
        void addReceiver(nAutomation::Envelope::eReceiverType, const nAutomation::CryptoString&);
        void writeSubject(const char*, ...);
        void writeBody(const char*, ...);
        bool attachBase64(const char*, u32, const char*, ...);
        void post();
        void setCharset(nAutomation::Envelope::eCharset);
    protected:
        MT_CHAR* mpProject;  // offset: 0x17a0
        MT_CHAR* mpTracker;  // offset: 0x17a8
        MT_CHAR* mpPriority;  // offset: 0x17b0
        MT_CHAR* mpHash;  // offset: 0x17b8
        MT_CHAR* mpHostName;  // offset: 0x17c0
        MT_CHAR* mpHostPort;  // offset: 0x17c8
        MT_CHAR* mpRemotePath;  // offset: 0x17d0
        MT_CHAR* mpAPIKey;  // offset: 0x17d8
        nAutomation::FieldProject mProjectField;  // offset: 0x17e0
        nAutomation::FieldTracker mTrackerField;  // offset: 0x1808
        nAutomation::FieldPriority mPriorityField;  // offset: 0x1830
        nAutomation::FieldHash mHashField;  // offset: 0x1858
        nAutomation::CustomField* mpField;  // offset: 0x1880
        MtCriticalSection mFieldCs;  // offset: 0x1888
        nAutomation::socket_t mSocket;  // offset: 0x1890
        static nAutomation::Ticket* mpOwner;
        static MT_CHAR* mpRFCBuffer;
        static u32 mRFCBufferLength;
        static MtCriticalSection mCs;
    };

    s32 getDefaultArgc();
    MT_CTSTR getDefaultArgv(s32 index);
    MT_CTSTR getExecWorkingPath();
    void initialize();
    void buildIdentityInfo();
    void* allocate(const size_t size);
    void executeRespawn();
    void finalize();
    bool isRespawnRequested();
    void deallocate(void* p);
    bool isRespawnedProcess();
    const RespawnContext& getRespawnContext();
    bool requestRespawn(const RespawnContext& ctx);
    bool requestRespawn(int argc, char* * argv);
    void killApplication();
    bool registerKilledCallback(void(*callback)());
    void captureScreen(eScreenShotMethod method, MT_CHAR* szFile);
    void traceIdentityString(void(*traceHandler)(const char*, ...));
    u32 encode64(void* pDstOut, const void* pSrcIn, u32 sizeIn, bool isText);
    char fromByteToBase(char c);
    Sender* getSender();
    Envelope* allocateEnvelope();
    u32 encodeURL(MT_CHAR* pDst, const MT_CHAR* pSrc);
    bool uploadUrgentFile(cUploader& uploader, MT_CTSTR szBasePath, MT_CTSTR szDumpPath, MT_CTSTR szSShotPath, MT_CTSTR szLogPath, MT_CTSTR szConLogPath, UPLOAD_DESC* pDesc);
    bool createShortcut(const char* szOutput, const char* szTarget, const char* szArg, const char* szWorkingDir);
    bool isElapsedSinceBuilt(s16 day);
    const IdentityInfo* getIdentityInfo();
    bool isValidOSVersion(const ReferVersion& ref);

}  // namespace nAutomation

inline nAutomation::CryptoString::CryptoString() {
}

inline nAutomation::CustomField::CustomField() {
}

inline nAutomation::cUploader::cUploader() {
}

inline nAutomation::IdentityInfo::IdentityInfo() {
}

inline nAutomation::ReferVersion::ReferVersion() {
}
