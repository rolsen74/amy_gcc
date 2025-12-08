# GCC Cross Compiler for AmigaOS 4 (with SDK)

**⚠️ IMPORTANT — PROJECT STATUS (Alpha / Experimental)**  
This project is based on **adtools**, but has been heavily modified.  
It is **very unstable**, still in active development, and tightly linked to the ongoing work on **Amy C Lib**.

This GCC port is used as a test platform for AmyCLib — a classic *chicken’n egg* situation.  
Include files **will change frequently**, and things may break at any time.

👉 **Do NOT use this toolchain for anything serious yet.**

The **default C library has been changed from newlib → amyclib**.  

Use:
 -mcrt=<amyclib|newlib|clib2|clib4>

Currently supported C runtimes:
- **amyclib (default)**
- **newlib**
- **clib2**
- **clib4**

Removed:
- **libnix**
- **ixemul**

Regards,  
**René W. Olsen**  
*8-Dec-2025*  


Ref:
- [adtools](https://github.com/AmigaLabs/adtools)
- [amyclib](https://github.com/rolsen74/amy)
- [clib2](https://github.com/sodero/clib2)
- [clib4](https://github.com/AmigaLabs/clib4)

---

## 📦 Component Version Overview

This build uses **GCC 11.5.0** and its classic dependency set.

| Component   | Your Version | Release (Y/M) | Latest Stable (Y/M) | Age Difference |
|------------|--------------|----------------|-----------------------|----------------|
| **GMP**        | 5.1.3        | 2013-02        | 6.3.0 (2024-09)       | ~11.5 years    |
| **MPFR**       | 3.1.6        | 2017-10        | 4.2.1 (2023-08)       | ~6 years       |
| **MPC**        | 1.0.3        | 2015-02        | 1.3.1 (2023-11)       | ~8.5 years     |
| **binutils**   | 2.23.2       | 2013-01        | 2.43 (2024-08)        | ~11.5 years    |
| **coreutils**  | 5.2.1        | 2004-02        | 9.5 (2024-10)         | ~20 years      |
| **GCC**        | 11.5.0       | 2023-05        | 14.2 (2025-06)        | ~2 years       |

### ✔ Notes

- **binutils 2.23.2** is the most outdated; upgrading is recommended long-term.
- **coreutils 5.2.1** is extremely old, but mostly harmless for AmigaOS.
- **GMP/MPFR/MPC** are old but compatible with GCC 11.x.
- **GCC 11.5.0** is still stable; GCC 14.x introduces major internal changes.

---

## 📁 Directory Layout

.
├── _download/ # Tarballs + git repositories
├── _touch/ # Status markers for each build stage
├── _temp/ # Build scratch directory (cleaned often)
│
├── _data/
│ ├── lib_amyclib/ # Bootstrap libc.a + crt*.o for stage1
│ ├── patch<version>/ # Auto-generated + manual patches
│ └── work<version>/ # Custom source files and overrides
│
├── aos4_cross/ # Cross-compiler installation (x86 → PPC)
├── aos4_native/ # Native PowerPC AmigaOS GCC build
│
├── makefile_cross # Builds the cross compiler
├── makefile_native # Builds the native compiler (requires cross)
├── makefile_patch # Generates patch files per component
└── README.md

---

## 🧰 Usage

### Build the cross-compiler (x86 → AmigaOS4)

```bash
make -f makefile_cross

Build the native GCC (AmigaOS4 PPC)

(Requires the cross-compiler first!)

make -f makefile_native

Generate patch files for all components

make -f makefile_patch
