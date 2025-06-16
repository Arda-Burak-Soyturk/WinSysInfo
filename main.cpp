#include <windows.h>
#include <iostream>
#include <iomanip>
#include <string>

void printMemoryInfo() {
    MEMORYSTATUSEX statex;
    statex.dwLength = sizeof(statex);

    if (GlobalMemoryStatusEx(&statex)) {
        std::cout << "[Memory Information]\n";
        std::cout << "Total Physical Memory: " 
                  << (statex.ullTotalPhys / (1024 * 1024)) << " MB\n";
        std::cout << "Available Physical Memory: " 
                  << (statex.ullAvailPhys / (1024 * 1024)) << " MB\n";
    } else {
        std::cerr << "Failed to retrieve memory information.\n";
    }
}

void printProcessorInfo() {
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);

    std::cout << "\n[CPU Information]\n";
    std::cout << "Number of Logical Processors: " << sysInfo.dwNumberOfProcessors << "\n";
    std::cout << "Processor Architecture: ";
    switch (sysInfo.wProcessorArchitecture) {
        case PROCESSOR_ARCHITECTURE_AMD64: std::cout << "x64 (AMD or Intel)\n"; break;
        case PROCESSOR_ARCHITECTURE_INTEL: std::cout << "x86\n"; break;
        default: std::cout << "Other\n"; break;
    }
}

void printDiskInfo() {
    ULARGE_INTEGER freeBytesAvailable, totalNumberOfBytes, totalNumberOfFreeBytes;
    if (GetDiskFreeSpaceEx(NULL, &freeBytesAvailable, &totalNumberOfBytes, &totalNumberOfFreeBytes)) {
        std::cout << "\n[Disk Information]\n";
        std::cout << "Total Disk Space: " 
                  << (totalNumberOfBytes.QuadPart / (1024 * 1024 * 1024)) << " GB\n";
        std::cout << "Free Disk Space: " 
                  << (totalNumberOfFreeBytes.QuadPart / (1024 * 1024 * 1024)) << " GB\n";
    } else {
        std::cerr << "Failed to retrieve disk information.\n";
    }
}

int main() {
    std::cout << "== Windows System Information Tool ==\n\n";
    printMemoryInfo();
    printProcessorInfo();
    printDiskInfo();
    return 0;
}
