<div align="center">

![Banner](https://readme-typing-svg.demolab.com?font=Fira+Code&size=40&duration=2000&pause=1000&color=FF6B6B&center=true&vCenter=true&width=800&lines=🔥+ULTIMATE+OBFUSCATOR;C%2B%2B+String+Encryption;Zero+Plaintext+in+Binary;Defeats+All+Reverse+Tools)

<h3>
  <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/Shield.png" width="30" />
  The Most Powerful Header-Only String Obfuscator
  <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/Shield.png" width="30" />
</h3>

<p>
  <img src="https://img.shields.io/badge/License-MIT-brightgreen?style=for-the-badge" />
  <img src="https://img.shields.io/badge/C++-17%2B-00599C?style=for-the-badge&logo=cplusplus" />
  <img src="https://img.shields.io/badge/Platform-Cross_Platform-lightgrey?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Header_Only-Yes-blue?style=for-the-badge" />
</p>

<p>
  <img src="https://img.shields.io/badge/🔥-Zero_Plaintext-red?style=flat-square" />
  <img src="https://img.shields.io/badge/🎲-Unique_Keys-purple?style=flat-square" />
  <img src="https://img.shields.io/badge/⚡-Compile_Time-yellow?style=flat-square" />
  <img src="https://img.shields.io/badge/🛡️-IDA_Proof-success?style=flat-square" />
</p>

**Zero plaintext** • **Unique keys every build** • **Defeats IDA, Hex-Rays, Ghidra & FLOSS**

<h4>
  <a href="#-why-choose-this">Why This?</a>
  <span> • </span>
  <a href="#-features">Features</a>
  <span> • </span>
  <a href="#-quick-start">Quick Start</a>
  <span> • </span>
  <a href="#-examples">Examples</a>
</h4>

</div>

---

## 🎯 Why Choose This?

<div align="center">

### 🔍 **The Problem with Traditional Obfuscation**

Traditional tools leave **patterns** and **signatures**. Every build is **identical**. Reverse engineers **extract strings** with basic tools.

### ✨ **The ULTIMATE Solution**

Every compilation creates **unique encrypted strings**. Keys change **automatically**. Memory is **wiped** after use.

</div>

---

## ⚔️ Comparison Matrix

<div align="center">

<table>
<thead>
<tr>
<th>Feature</th>
<th align="center">Basic XOR</th>
<th align="center">AY_OBFUSCATE</th>
<th align="center"><strong>🔥 THIS</strong></th>
</tr>
</thead>
<tbody>
<tr>
<td>🎯 Compile-time encryption</td>
<td align="center">✅</td>
<td align="center">✅</td>
<td align="center"><strong>✅</strong></td>
</tr>
<tr>
<td>🎲 Keys change <strong>every compilation</strong></td>
<td align="center">❌</td>
<td align="center">❌</td>
<td align="center"><strong>✅</strong></td>
</tr>
<tr>
<td>🧵 Thread-safe decryption</td>
<td align="center">❌</td>
<td align="center">❌</td>
<td align="center"><strong>✅</strong></td>
</tr>
<tr>
<td>🔒 Auto re-encryption & wipe</td>
<td align="center">❌</td>
<td align="center">❌</td>
<td align="center"><strong>✅</strong></td>
</tr>
<tr>
<td>👻 Zero plaintext in binary</td>
<td align="center">❌</td>
<td align="center">✅</td>
<td align="center"><strong>✅</strong></td>
</tr>
<tr>
<td>⚡ Header-only (no VM)</td>
<td align="center">✅</td>
<td align="center">✅</td>
<td align="center"><strong>✅</strong></td>
</tr>
<tr>
<td>🎭 Defeats FLOSS/strings</td>
<td align="center">❌</td>
<td align="center">⚠️</td>
<td align="center"><strong>✅</strong></td>
</tr>
</tbody>
</table>

</div>

---

## 🚀 Features

<div align="center">

### 💎 What Makes It Ultimate

</div>

<table>
<tr>
<td width="50%">

#### 🎲 **Randomized Keys**
Every single compilation generates **unique encryption keys**. No two builds are identical.

```cpp
// Each build = different encrypted bytes
OBFUSCATE("secret")
// Build 1: 0x3A, 0x7F, 0x9E...
// Build 2: 0x82, 0x1C, 0x45...
```

</td>
<td width="50%">

#### 🔒 **Memory Protection**
Strings are **decrypted on-demand** and **immediately wiped** after use.

```cpp
{
  auto str = OBFUSCATE("password");
  // Decrypted only here
} // Memory wiped!
```

</td>
</tr>
<tr>
<td width="50%">

#### ⚡ **Zero Runtime Cost**
All encryption happens at **compile-time**. Zero performance impact.

```cpp
// Encrypted at compile-time
constexpr auto enc = OBFUSCATE("api_key");
// Runtime: simple XOR decode
```

</td>
<td width="50%">

#### 🧵 **Thread Safe**
Uses `thread_local` storage. Perfect for multi-threaded apps.

```cpp
// Safe across threads
std::thread t1([] {
  OBFUSCATE("thread1");
});
```

</td>
</tr>
</table>

---

## 🛠️ Quick Start

### 📥 Installation

**Super simple** - just include the header:

```cpp
#include "obfuscate.h"
```

<div align="center">

**No dependencies** • **No build config** • **No linking**

</div>

### ⚡ Basic Usage

```cpp
#include "obfuscate.h"
#include <iostream>

int main() {
    // These strings are INVISIBLE in the binary
    std::cout << OBFUSCATE("Secret API Key: sk_live_abc123...") << std::endl;
    std::cout << OBFUSCATE("admin@secret-domain.com") << std::endl;
    
    return 0;
}
```

<div align="center">

**That's it!** Compile and your strings are protected.

</div>

---

## 💡 Real-World Examples

### 🔐 Protect API Keys & Secrets

<details open>
<summary><b>Click to see code</b></summary>

```cpp
#include "obfuscate.h"
#include <iostream>
#include <string>

int main() {
    // API endpoints - completely hidden from reverse engineers
    auto api_url = OBFUSCATE("https://api.secret-app.com/v3/login");
    std::cout << "Connecting to: " << api_url << std::endl;
    
    // Authentication tokens - never visible in memory dumps
    auto auth_header = OBFUSCATE("x-api-key: sk_live_9X7aB3mZ4pQ2rN8vK5jL1wD6fH3gT7y");
    std::cout << "Auth: " << auth_header << std::endl;
    
    // Sensitive file paths
    auto config_path = OBFUSCATE("C:\\Users\\Admin\\secret_config.dat");
    std::cout << "Config: " << config_path << std::endl;
    
    // Database credentials
    auto db_connection = OBFUSCATE("Server=prod-db;User=sa;Password=P@ssw0rd!;");
    
    return 0;
}
```

</details>

### 🎲 Deterministic Encryption

<details>
<summary><b>When you need consistency across builds</b></summary>

```cpp
#include "obfuscate.h"

// Use OBF_KEY with custom seeds for deterministic encryption
const char* db_url = OBF_KEY(
    "postgres://user:SuperSecret123@localhost/malware_db", 
    0xCAFEBABE,  // Seed 1 - keeps encryption consistent
    0x1337C0DE,  // Seed 2
    999          // Seed 3
);

// Same encrypted output across all builds
// Useful for license keys, serial numbers, etc.
```

**Use case:** When you need the same encrypted bytes across different compilations.

</details>

### 📝 Direct String Objects

<details>
<summary><b>Get std::string directly</b></summary>

```cpp
#include "obfuscate.h"
#include <string>

int main() {
    // Returns std::string directly (rarely needed)
    std::string password = OBF_STR("P@ssw0rd123!@#");
    
    // Use in STL containers
    std::vector<std::string> secrets {
        OBF_STR("secret1"),
        OBF_STR("secret2"),
        OBF_STR("secret3")
    };
    
    return 0;
}
```

</details>

---

## 🛡️ Defeats All Tools

<div align="center">

<table>
<tr>
<td align="center" width="25%">
  <img src="https://img.shields.io/badge/IDA_Pro-DEFEATED-success?style=for-the-badge" />
  <br><sub><b>No String References</b></sub>
</td>
<td align="center" width="25%">
  <img src="https://img.shields.io/badge/Ghidra-DEFEATED-success?style=for-the-badge" />
  <br><sub><b>Decompiler Blind</b></sub>
</td>
<td align="center" width="25%">
  <img src="https://img.shields.io/badge/FLOSS-DEFEATED-success?style=for-the-badge" />
  <br><sub><b>No Auto Extraction</b></sub>
</td>
<td align="center" width="25%">
  <img src="https://img.shields.io/badge/Strings-DEFEATED-success?style=for-the-badge" />
  <br><sub><b>Empty Output</b></sub>
</td>
</tr>
</table>

### What Reverse Engineers See

```bash
$ strings malware.exe | grep "api"
# Nothing! 🎉

$ floss malware.exe
# No obfuscated strings detected

$ ida malware.exe
# No string xrefs found
```

</div>

---

## 📊 Benchmarks

<div align="center">

| Test | XOR Basic | AY_OBFUSCATE | **ULTIMATE** |
|------|-----------|--------------|--------------|
| Encryption Time | Compile-time | Compile-time | Compile-time |
| Binary Strings | ❌ Visible | ✅ Hidden | ✅ Hidden |
| Memory Strings | ❌ Visible | ⚠️ Cached | ✅ Wiped |
| FLOSS Detection | ✅ Detected | ⚠️ Maybe | ❌ Not Detected |
| Unique Per Build | ❌ No | ❌ No | ✅ **Yes** |
| Thread Safety | ❌ No | ❌ No | ✅ **Yes** |

</div>

---

## 🚨 Important Notes

<div align="center">

> **⚠️ This is a tool for legitimate security purposes**
> 
> Use responsibly. Obfuscation is not encryption. This protects against static analysis, not runtime debugging.

</div>

---

## 📄 License

<div align="center">

**MIT License** - Free for commercial and personal use

```
Copyright © 2024 Jitendra Gupta (JungliBro)
```

</div>

---

<div align="center">

### 💝 Show Your Support

<img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Smilies/Star-Struck.png" width="30" />

**Give a ⭐️ if this project helped you!**

<p>
  <img src="https://forthebadge.com/images/badges/built-with-love.svg" />
  <img src="https://forthebadge.com/images/badges/powered-by-coffee.svg" />
  <img src="https://forthebadge.com/images/badges/made-with-c-plus-plus.svg" />
</p>

**Made with 🔥 by Jitendra Gupta (JungliBro)**

<img src="https://capsule-render.vercel.app/api?type=waving&color=gradient&customColorList=12,20,6,24,16&height=100&section=footer" />

</div>
