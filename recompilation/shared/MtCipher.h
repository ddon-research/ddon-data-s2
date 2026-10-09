#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtBigInt.h"

// Forward declarations
class MtBigInt;

// Declarations
class MtCipher;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class MtCipher
{
public:
    enum
    {
        nr = 10,
        nb = 4,
        nk = 4,
    };
public:
    template <typename TC, void(MtCipher::*TE)(const u8*, u8*), void(MtCipher::*TD)(const u8*, u8*), int bSize, int kSize> class CBC;
    union half_block;
public:
    union half_block
    {
    public:
        u32 word;  // offset: 0x0
        u8 byte[4];  // offset: 0x0
        struct
        {
        public:
            u32 byte3 : 8;  // offset: 0x0
            u32 byte2 : 8;  // offset: 0x0
            u32 byte1 : 8;  // offset: 0x0
            u32 byte0 : 8;  // offset: 0x0
        } w;  // offset: 0x0
    };
public:
    MtCipher();
    virtual ~MtCipher();
    void setKeyString(MT_CTSTR key_str);
    void getSHA1(u8* in, size_t size, u32* hash_out) const;
    void scrambleXOR(const u8* in, u8* out, u32 size) const;
    u32 getEncryptBufferSize(u32 buff_size) const;
    u32 getPlainBufferSizePKCS1v15() const;
    u32 encryptRSA(const u8* in, u8* out, u32 size) const;
    void decryptRSA(const u8* in, u8* out, u32 size) const;
    void encryptRSASub(const MtBigInt& plain, MtBigInt& cipher) const;
    void decryptRSASub(const MtBigInt& cipher, MtBigInt& plain) const;
    u32 encryptRSA_PKCS1v15(const u8* in, u8* out, u32 size) const;
    u32 decryptRSA_PKCS1v15(const u8* in, u8* out, u32 size) const;
    MtBigInt getModulo() const;
    MtBigInt getOpenExpo() const;
    u32 getBlockSize() const;
    void setKeys(const MtBigInt& modp, const MtBigInt& modq, const MtBigInt& expo);
    void setKeys(const MtBigInt& modulo, const MtBigInt& expo);
    MtBigInt createPrimeCandidacy(u32 figure) const;
    bool primaryTest(const MtBigInt& p) const;
    void initializeBF();
    u32 encryptBF(u8* in, u8* out, u32 size) const;
    void decryptBF(u8* in, u8* out, u32 size) const;
    void setDESKEY(const u8* key);
    void encryptDES(const u8* in, u8* out) const;
    void decryptDES(const u8* in, u8* out) const;
    void setTriDESKEY(const u8* key);
    void encryptTriDES(const u8* in, u8* out) const;
    void decryptTriDES(const u8* in, u8* out) const;
    void setAESKEY(const u8* key);
    void encryptAES(const u8* in, u8* out) const;
    void decryptAES(const u8* in, u8* out) const;
private:
    const MtCipher& operator=(const MtCipher&);
    u32 getf(s32 t, u32 word_b, u32 word_c, u32 word_d) const;
    u32 getK(s32 t) const;
    void calcBlock(u8* block, u32* hash) const;
    MtBigInt getPoweredMod(const MtBigInt& code, const MtBigInt& expo, const MtBigInt& modulo) const;
    MtBigInt getPoweredModEx(const MtBigInt& code, const MtBigInt& expo, const MtBigInt& modulo) const;
    MtBigInt getPrivateKey(const MtBigInt& lcm, const MtBigInt& open_key) const;
    MtBigInt getGcd(const MtBigInt& m_in, const MtBigInt& n_in) const;
    MtBigInt getLcm(const MtBigInt& m_in, const MtBigInt& n_in) const;
    MtBigInt getGcdEx(const MtBigInt& a, const MtBigInt& b) const;
    void mont_init(const MtBigInt& modulo, MtBigInt& n, MtBigInt& r2) const;
    MtBigInt mont_rdct(const MtBigInt& modulo, const MtBigInt& n, const MtBigInt& am) const;
    void encodeBF(u32* lx, u32* rx) const;
    void decodeBF(u32* lx, u32* rx) const;
    void encodeBF_ForInitialize(u32* lx, u32* rx) const;
    void getTransKey_Private(MT_CHAR* output) const;
    void setTransKey_Private(const MT_CHAR* NewValue);
    u32 getKeyLength_Private() const;
    void setKeyLength_Private(u32 NewValue);
    const MtBigInt& getModuloP_Private() const;
    void setModuloP_Private(const MtBigInt& NewValue);
    const MtBigInt& getModuloQ_Private() const;
    void setModuloQ_Private(const MtBigInt& NewValue);
    const MtBigInt& getModulo_Private() const;
    void setModulo_Private(const MtBigInt& NewValue);
    const MtBigInt& getOpenExpo_Private() const;
    void setOpenExpo_Private(const MtBigInt& NewValue);
    const MtBigInt& getPrivExpo_Private() const;
    void setPrivExpo_Private(const MtBigInt& NewValue);
    const u32& getBlockSize_Private() const;
    void setBlockSize_Private(const u32& NewValue);
    const MtBigInt& getModuloPQ_1_Private() const;
    void setModuloPQ_1_Private(const MtBigInt& NewValue);
    const MtBigInt& getModuloQP_1_Private() const;
    void setModuloQP_1_Private(const MtBigInt& NewValue);
    void getAesKey_Private(MT_CHAR* output) const;
    void setAesKey_Private(const MT_CHAR* NewValue);
private:
    MT_CHAR mTransKey_Guard[56];  // offset: 0x8
    u32 mKeyLength_Guard;  // offset: 0x40
    MtBigInt mModuloP_Guard;  // offset: 0x48
    MtBigInt mModuloQ_Guard;  // offset: 0x468
    MtBigInt mModulo_Guard;  // offset: 0x888
    MtBigInt mOpenExpo_Guard;  // offset: 0xca8
    MtBigInt mPrivExpo_Guard;  // offset: 0x10c8
    u32 mBlockSize_Guard;  // offset: 0x14e8
    MtBigInt mModuloPQ_1_Guard;  // offset: 0x14f0
    MtBigInt mModuloQP_1_Guard;  // offset: 0x1910
    u32* mpPArray;  // offset: 0x1d30
    u32* mpSBox;  // offset: 0x1d38
    u64 desKey;  // offset: 0x1d40
    u64 desKey1;  // offset: 0x1d48
    u64 desKey2;  // offset: 0x1d50
    u8 aeskey_Guard[16];  // offset: 0x1d58
public:
    static const u32 KEY_STR_MAX = 56;
};
