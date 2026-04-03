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
- **[amyclib](https://github.com/rolsen74/amy) (default)**
- **newlib**
- **[clib2](https://github.com/sodero/clib2)**
- **[clib4](https://github.com/AmigaLabs/clib4)**

Removed:
- **libnix**
- **ixemul**

Ref:
- [adtools](https://github.com/AmigaLabs/adtools)

Regards,  
**René W. Olsen**  
*21-Mar-2026*  

---

## 📦 Component Version Overview

This build uses **GCC 11.5.0** and its classic dependency set.

| Component      | Your Version | Release (Y/M) | Latest Stable (Y/M) | Age Difference |
|----------------|--------------|---------------|---------------------|----------------|
| **GMP**        | 6.3.0        | 2024-09       | 6.3.0 (2024-09)     | Current        |
| **MPFR**       | 4.2.2        | 2025-03       | 4.2.2 (2025-03)     | Current        |
| **MPC**        | 1.3.1        | 2023-11       | 1.3.1 (2023-11)     | Current        |
| **binutils**   | 2.23.2       | 2013-01       | 2.46 (2026-02)      | ~13 years      |
| **coreutils**  | 5.2.1        | 2004-02       | 9.10 (2026-02)      | ~22 years      |
| **GCC**        | 11.5.0       | 2023-05       | 15.2 (2025-08)      | ~2 years       |
| **GCC**        | 13.4.0       | 2025-06       | 15.2 (2025-08)      | <1 year        |

### Notes

- **binutils 2.23.2** is very outdated.
- **coreutils 5.2.1** is extremely outdated.

---

## Directory Layout

```
.
├── _download/             # Tarballs + git repositories
├── _touch/                # Status markers for each build stage
├── _temp/                 # Build scratch directory (cleaned often)
│
├── _data/
│   ├── lib_amyclib/       # Bootstrap libc.a + crt*.o for stage1
│   ├── patch_<version>/   # Auto-generated + manual patches
│   └── work_<version>/    # Custom source files and overrides
│
├── aos4_cross/            # Cross-compiler installation (x86 → PPC)
├── aos4_native/           # Native PowerPC AmigaOS GCC build
│
├── makefile_cross         # Builds the cross compiler
├── makefile_native        # Builds the native compiler (requires cross)
├── makefile_patch         # Generates patch files per component
│
└── README.md
```

---

## Usage

### Build the cross-compiler (x86 → AmigaOS4)

```bash
make -f makefile_cross_1x

Build the native GCC (AmigaOS4 PPC)

(Requires the cross-compiler first!)

make -f makefile_native_11
