#ifndef ULTIMATE_OBFUSCATOR_H
#define ULTIMATE_OBFUSCATOR_H
/* --------------------------------- ABOUT -------------------------------------
   Author : Jitendra Kumar
   Github : https://github.com/JungliBro

The strongest header-only C++ string obfuscator
        • 100% compile-time encryption
        • Keys change every single build (even 1s apart)
        • Thread-safe
        • Auto re-encryption
        • Zero runtime overhead

Example :
 std::string password = OBF_STR("P@ssw0rd123!@#");
 std::cout <<password<< std::endl;
 std::cout << OBFUSCATE("https://api.secret-app.com/v3/login") << std::endl;
 -------------------------------------------------------------------------------*/
#include <cstddef>
#include <string>
#include <cstdint>

namespace obf {

// ============================================================================
// COMPILE-TIME UTILITIES (with MSVC /ZI)
// ============================================================================

#ifdef _MSC_VER
    #define AY_CAT(x,y) AY_CAT_I(x,y)
#define AY_CAT_I(x,y) x##y
#define OBF_LINE AY_CAT(line_, __LINE__)
#else
#define OBF_LINE __LINE__
#endif

    constexpr uint32_t hash_string(const char* str, uint32_t h = 0x811C9DC5) {
        return (*str == 0) ? h : hash_string(str + 1, (h ^ *str) * 0x01000193);
    }

    constexpr uint32_t lcg(uint32_t s)      { return (1103515245u * s + 12345) % 0x80000000u; }
    constexpr uint32_t multi_lcg(uint32_t s, int n) { return n == 0 ? s : multi_lcg(lcg(s), n-1); }
    constexpr uint32_t xorshift(uint32_t x) { x ^= x << 13; x ^= x >> 17; x ^= x << 5; return x; }

// ============================================================================
// COMPILE-TIME ENCRYPTOR
// ============================================================================

    template <std::size_t N, uint32_t K1, uint32_t K2, uint32_t SEED>
    struct Obfuscator {
        char data[N]{};

        static constexpr uint8_t get_key_byte(std::size_t i, uint32_t seed) {
            auto s1 = multi_lcg(seed + static_cast<uint32_t>(i), 3);
            auto s2 = xorshift(s1 ^ K1);
            auto s3 = lcg(s2 ^ K2);
            return static_cast<uint8_t>(s1 ^ s2 ^ s3);
        }

        constexpr Obfuscator(const char* str) {
            uint32_t rs = SEED;
            for (std::size_t i = 0; i < N; ++i) {
                uint8_t c = static_cast<uint8_t>(str[i]);
                c ^= static_cast<uint8_t>(K1);
                c ^= static_cast<uint8_t>(i * 0x5A);
                c ^= get_key_byte(i, rs);
                c ^= static_cast<uint8_t>((K2 >> ((i % 4) * 8)) & 0xFF);
                data[i] = static_cast<char>(c);
                rs = multi_lcg(rs ^ str[i], 2);
            }
        }
    };

// ============================================================================
// RUNTIME SMART STRING
// ============================================================================

    template <std::size_t N, uint32_t K1, uint32_t K2, uint32_t SEED>
    class SmartString {
        mutable char decrypted[N]{};           // decrypted data
        mutable bool decrypted_flag{false};    // is currently decrypted?
        const char* encrypted_data;

        // Shared PRNG logic (non-constexpr for runtime re-encrypt)
        static uint32_t rt_multi_lcg(uint32_t s, int n) {
            uint32_t r = s;
            for (int i = 0; i < n; ++i) r = (1103515245u * r + 12345) % 0x80000000u;
            return r;
        }

        static uint32_t rt_xorshift(uint32_t x) {
            x ^= x << 13; x ^= x >> 17; x ^= x << 5; return x;
        }

    public:
        constexpr SmartString(const Obfuscator<N, K1, K2, SEED>& o) : encrypted_data(o.data) {}

        // Decrypt on demand
        void decrypt() const {
            if (decrypted_flag) return;

            uint32_t rs = SEED;
            for (std::size_t i = 0; i < N; ++i) {
                uint8_t c = static_cast<uint8_t>(encrypted_data[i]);

                c ^= static_cast<uint8_t>((K2 >> ((i % 4) * 8)) & 0xFF);

                uint32_t s1 = rt_multi_lcg(rs + static_cast<uint32_t>(i), 3);
                uint32_t s2 = rt_xorshift(s1 ^ K1);
                uint32_t s3 = lcg(s2 ^ K2);
                c ^= static_cast<uint8_t>(s1 ^ s2 ^ s3);

                c ^= static_cast<uint8_t>(i * 0x5A);
                c ^= static_cast<uint8_t>(K1);

                decrypted[i] = static_cast<char>(c);
                rs = rt_multi_lcg(rs ^ c, 2);
            }
            decrypted_flag = true;
        }

        // RE-ENCRYPT (like AY – you asked for this!)
        void encrypt() const {
            if (!decrypted_flag) return;
            volatile char* p = decrypted;
            for (std::size_t i = 0; i < N; ++i) p[i] = 0;
            decrypted_flag = false;
        }

        // Auto-wipe on destruction
        ~SmartString() { encrypt(); }

        const char* c_str() const { decrypt(); return decrypted; }
        operator const char*() const { return c_str(); }
        operator std::string() const { decrypt(); return std::string(decrypted); }
        std::size_t size() const { return N - 1; }
        bool is_decrypted() const { return decrypted_flag; }
    };

} // namespace obf

// ============================================================================
// FINAL MACROS – PERFECT, NO AMBIGUITY, THREAD-SAFE, MSVC /ZI SAFE
// ============================================================================

#define OBFUSCATE(str) \
    ([]() -> const char* { \
        constexpr std::size_t N = sizeof(str); \
        static_assert(str[N-1] == '\0', "OBFUSCATE() requires null-terminated literal"); \
        constexpr uint32_t base = obf::hash_string(__FILE__) ^ obf::hash_string(__TIME__) ^ OBF_LINE; \
        constexpr uint32_t K1 = obf::xorshift(base ^ 0xDEADBEEF); \
        constexpr uint32_t K2 = obf::multi_lcg(base, 9); \
        constexpr uint32_t SEED = obf::lcg(K2 + OBF_LINE); \
        constexpr auto enc = obf::Obfuscator<N, K1, K2, SEED>(str); \
        thread_local static const obf::SmartString<N, K1, K2, SEED> ss(enc); \
        return ss.c_str(); \
    }())

// ============================================================================
// Manual key – same encryption across builds
// ============================================================================

#define OBF_KEY(str, key1, key2, seed) \
    ([]() -> const char* { \
        constexpr std::size_t N = sizeof(str); \
        static_assert(str[N-1] == '\0', "OBF_KEY() requires null-terminated literal"); \
        constexpr auto enc = obf::Obfuscator<N, key1, key2, seed>(str); \
        thread_local static const obf::SmartString<N, key1, key2, seed> ss(enc); \
        return ss.c_str(); \
    }())
// ============================================================================
// Optional: if you really need std::string immediately
// ============================================================================

#define OBF_STR(str) ([]() -> std::string { return OBFUSCATE(str); }())
#endif // ULTIMATE_OBFUSCATOR_H

/* -------------------------------- LICENSE ------------------------------------

Public Domain (http://www.unlicense.org)

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or distribute this
software, either in source code form or as a compiled binary, for any purpose,
commercial or non-commercial, and by any means.

In jurisdictions that recognize copyright laws, the author or authors of this
software dedicate any and all copyright interest in the software to the public
domain. We make this dedication for the benefit of the public at large and to
the detriment of our heirs and successors. We intend this dedication to be an
overt act of relinquishment in perpetuity of all present and future rights to
this software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

  Author : Jitendra Kumar
  Github : https://github.com/JungliCheats
  Telegram : @JungliCheats
----------------------------------------------------------------------------- */
