# NodeAuth-Bitset

A low-overhead device validation sub-system written in C99 for memory-constrained microcontrollers. It skips heavy tracking tables, managing network permission maps inside flat, raw integer arrays using custom **Bitset Bit-Manipulation Vectors** to check access rights instantly.

## ⚡ Data Structure Mappings
* **Memory Optimization:** Packages 32 binary permission profiles into single flat integer records.
* **Time Complexity:** Constant-time $O(1)$ authorization reads and permission write lookups.
