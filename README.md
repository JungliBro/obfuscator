# 🔥 ULTIMATE OBFUSCATOR 🔒
<div align="center">

### The Most Powerful Header-Only C++ String Obfuscator
**Zero plaintext in binary** • **Unique keys on every build** • **Defeats IDA, Hex-Rays, Ghidra & FLOSS**

[![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)
[![C++](https://img.shields.io/badge/C%2B%2B-17%2B-00599C.svg)](https://isocpp.org/)
[![Platform](https://img.shields.io/badge/platform-Windows%20%7C%20Linux%20%7C%20macOS-lightgrey.svg)](https://github.com)

</div>

---

## 🎯 Why This Changes Everything

Traditional obfuscates leave patterns. **ULTIMATE OBFUSCATOR** makes every build unique.

<table>
<thead>
<tr>
<th>Feature</th>
<th align="center">Basic XOR</th>
<th align="center">AY_OBFUSCATE</th>
<th align="center"><strong>ULTIMATE OBFUSCATOR</strong></th>
</tr>
</thead>
<tbody>
<tr>
<td>Compile-time encryption</td>
<td align="center">✅</td>
<td align="center">✅</td>
<td align="center">✅</td>
</tr>
<tr>
<td>Keys change <strong>every single compilation</strong></td>
<td align="center">❌</td>
<td align="center">❌</td>
<td align="center">✅</td>
</tr>
<tr>
<td>Thread-safe, on-demand decryption</td>
<td align="center">❌</td>
<td align="center">❌</td>
<td align="center">✅</td>
</tr>
<tr>
<td>Automatic re-encryption & memory wipe</td>
<td align="center">❌</td>
<td align="center">❌</td>
<td align="center">✅</td>
</tr>
<tr>
<td>Zero plaintext strings in binary</td>
<td align="center">❌</td>
<td align="center">✅</td>
<td align="center">✅</td>
</tr>
<tr>
<td>No virtual machine required</td>
<td align="center">✅</td>
<td align="center">✅</td>
<td align="center">✅</td>
</tr>
</tbody>
</table>

---

## 🚀 Quick Start

### Installation

Simply include the header file:

```cpp
#include "obfuscate.h"
```

No dependencies. No compilation flags. Just works.

### Basic Usage

```cpp
#include "obfuscate.h"
#include <iostream>

int main() {
    // These strings do NOT exist in the binary
    std::cout << OBFUSCATE("Secret API Key: sk_live_abc123...") << std::endl;
    std::cout << OBFUSCATE("https://internal-admin.company.com") << std::endl;
    
    return 0;
}
```

---

## 💎 Real-World Examples

### 🔐 Protect API Keys & Endpoints

```cpp
#include "obfuscate.h"
#include <iostream>

int main() {
    // API endpoints - completely hidden from reverse engineers
    std::cout << OBFUSCATE("https://api.secret-app.com/v3/login") << std::endl;
    
    // Authentication tokens
    std::cout << OBFUSCATE("x-api-key: sk_live_9X7aB3mZ4pQ2rN8vK5jL1wD6fH3gT7y") << std::endl;
    
    // Sensitive file paths
    std::cout << OBFUSCATE("C:\\Users\\Admin\\secret_config.dat") << std::endl;
    
    return 0;
}
```

### 🎲 Deterministic Keys (Same Across Builds)

When you need consistency:

```cpp
// Use OBF_KEY with custom seeds for deterministic encryption
const char* db_url = OBF_KEY(
    "postgres://user:pass@localhost/malware", 
    0xCAFEBABE,  // Seed 1
    0x1337C0DE,  // Seed 2
    999          // Seed 3
);
```

### 📝 Direct String Objects

```cpp
// Returns std::string directly (rarely needed)
std::string password = OBF_STR("P@ssw0rd123!@#");
```

---

<div align="center">

### 🌟 Star this repo if you find it useful!

**Made with 🔥 for the security community**

</div>
