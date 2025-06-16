# WinSysInfo

A simple Windows-native system information tool written in C++.  
Displays system memory, CPU, and disk information using `Windows.h`.

---

## 🔧 Build Instructions

### Requirements
- Windows
- CMake 3.10+
- C++17 compatible compiler (MSVC recommended)

### Steps

```bash
git clone https://github.com/yourusername/WinSysInfo.git
cd WinSysInfo
mkdir build && cd build
cmake ..
cmake --build .
