# EnochCore Architecture

## Overview

EnochCore is a monolithic x86_64 Unix-like POSIX-compliant operating system written in C with Intel assembly fragments. The system prioritizes code quality and clarity over performance optimization, maintaining a clean and understandable codebase. Version 0.01 includes KDE Plasma desktop environment, NVIDIA GPU support, and adapted musl libc.

## Kernel Architecture

### Monolithic Design
- All kernel components run in privileged mode
- Direct function calls between subsystems
- Shared memory space for all kernel code
- Loadable kernel modules support
- Preemptive multitasking with priority scheduling

### x86_64 Support
- Full 64-bit architecture support
- 4-level paging (48-bit virtual address space)
- Long mode with 64-bit registers
- SSE/SSE2 instruction support
- Advanced CPU features (APIC, local timers)

### Memory Management
- **Physical Memory Manager (PMM)**: Tracks available physical memory
- **Virtual Memory Manager (VMM)**: Manages virtual address spaces
- **Paging**: 4-level page tables with demand paging
- **Memory allocation**: Kernel and user space memory management
- **Memory caching**: Multi-level cache management
- **Advanced memory features**: Memory pooling and optimization

## Core Components

### Bootloader Integration
- **Limine bootloader**: Modern, feature-rich bootloader
- **Kernel loading**: Direct kernel loading with memory mapping
- **Framebuffer setup**: BIOS/UEFI framebuffer initialization
- **Memory map**: Physical memory layout detection
- **Multiboot2 support**: Standard boot protocol

### CPU Management
- **Global Descriptor Table (GDT)**: Segment descriptors for x86_64
- **Interrupt Descriptor Table (IDT)**: Interrupt and exception handlers
- **Interrupt Service Routines (ISR)**: Hardware interrupt handling
- **Advanced Programmable Interrupt Controller (APIC)**: Modern interrupt routing
- **Local APIC Timer**: High-resolution timer for scheduling
- **Fast System Calls**: Optimized syscall entry/exit

### Process Management
- **Task Scheduler**: Round-robin scheduling with priorities
- **Process Creation**: Fork, exec, and process lifecycle management
- **Context Switching**: Fast task switching with register preservation
- **Memory Protection**: User/kernel space separation
- **Process Information**: /proc filesystem integration
- **Task Information**: Real-time process monitoring

### Filesystem Layer
- **Virtual Filesystem (VFS)**: Unified filesystem interface
- **FAT32**: Boot partition filesystem
- **Ext2**: Root filesystem with journaling support
- **Virtual filesystems**: /proc, /sys, /dev for system information
- **Device filesystem**: /dev for device access
- **System filesystem**: /sys for kernel information

### Device Drivers
- **PCI Subsystem**: Automatic device detection and driver loading
- **Storage**: AHCI controller for SATA drives
- **Network**: Intel E1000, Realtek RTL8139, RTL8169 support
- **Input**: PS/2 keyboard and mouse
- **Serial**: COM1, COM2 serial port support
- **Display**: VGA and framebuffer support
- **NVIDIA GPU**: Auto-detection for RTX/GTX series with legacy drivers
- **Character devices**: TTY, console, and serial devices

### Networking Stack
- **lwIP Integration**: Lightweight TCP/IP implementation
- **DHCP Client**: Automatic IP address configuration
- **Network Interfaces**: Support for multiple network cards
- **Socket API**: Unix domain sockets and standard networking
- **IPv6 Support**: Dual-stack networking
- **Network utilities**: ping, netstat, route commands

### System Calls
- **Linux Compatibility**: Linux system call interface
- **POSIX Compliance**: Standard Unix system calls
- **Signal Handling**: Unix signals with BSD extensions
- **Inter-process Communication**: Pipes, sockets, eventfds, futexes
- **Advanced IPC**: Shared memory, message queues
- **File operations**: Complete file I/O support

## Userland Components

### C Library
- **musl libc**: Adapted for EnochCore
- **POSIX Stub Layer**: System call interface
- **Standard library**: Complete C library implementation
- **Math library**: Mathematical functions
- **String handling**: String manipulation functions

### Desktop Environment
- **KDE Plasma**: Full desktop environment ported from FreeBSD
- **KScreenLocker**: Screen locking mechanism
- **Window management**: X11 and Wayland support
- **Application framework**: Qt-based applications
- **System settings**: Configuration management

### System Utilities
- **BusyBox**: Core utilities (ls, cp, sh, etc.)
- **Init systems**: OpenRC (default), systemd (optional)
- **System tools**: Process management, file utilities
- **Network tools**: Network configuration and monitoring

## Memory Layout

```
Kernel Space (High Memory)
├── Kernel Code & Data
├── Kernel Stack
├── Device Memory
├── Kernel Heap
└── Module Space

User Space (Low Memory)
├── User Code
├── User Data
├── User Stack
├── Shared Libraries
└── Application Memory
```

## Boot Process

1. **Limine Bootloader**
   - Loads kernel from disk
   - Sets up initial memory mapping
   - Initializes framebuffer
   - Passes control to kernel

2. **Kernel Initialization**
   - Parse bootloader information
   - Initialize memory management
   - Set up CPU structures (GDT, IDT)
   - Initialize device drivers
   - Load kernel modules

3. **System Startup**
   - Mount filesystems
   - Start init system (OpenRC/systemd)
   - Launch desktop environment (KDE)
   - Initialize user services

## Filesystem Structure

```
/
├── boot/          # FAT32 boot partition
├── bin/           # System binaries
├── lib/           # Shared libraries
├── etc/           # Configuration files
├── dev/           # Device files
├── proc/          # Process information
├── sys/           # System information
├── home/          # User directories
├── usr/           # User programs
└── var/           # Variable data
```

## Device Driver Architecture

### Driver Types
- **Character drivers**: Serial ports, keyboards, mice, TTY
- **Block drivers**: Storage devices, filesystems
- **Network drivers**: Network interface cards
- **Framebuffer drivers**: Display output
- **GPU drivers**: NVIDIA graphics cards

### Driver Interface
- **Registration**: Drivers register with kernel subsystems
- **Probing**: Automatic device detection
- **Initialization**: Device-specific setup
- **Interrupt handling**: Hardware interrupt processing
- **Module loading**: Dynamic driver loading

## Networking Architecture

### Protocol Stack
```
Application Layer
├── Socket API
├── TCP/UDP
├── IP (IPv4/IPv6)
├── ARP
└── Ethernet
```

### Network Interfaces
- **Intel E1000**: Gigabit Ethernet support
- **Realtek RTL8139**: Fast Ethernet support
- **Realtek RTL8169**: Gigabit Ethernet support
- **Virtual interfaces**: Loopback, bridge support

## System Call Interface

### Linux Compatibility
- **System call numbers**: Match Linux x86_64 ABI
- **Parameter passing**: Standard x86_64 calling convention
- **Return values**: Linux-compatible error codes
- **Signal handling**: Unix signal semantics

### POSIX Support
- **File operations**: open, read, write, close
- **Process management**: fork, exec, wait
- **Memory management**: mmap, brk, sbrk
- **Inter-process communication**: pipe, socket
- **Threading**: pthread support

## Development Guidelines

### Code Quality
- Clean, readable code structure
- Comprehensive comments (English only)
- Consistent naming conventions
- Error handling and validation

### Performance Considerations
- Avoid premature optimization
- Profile before optimizing
- Use appropriate data structures
- Minimize memory allocations

### Maintainability
- Modular code organization
- Clear interfaces between components
- Comprehensive testing
- Documentation for all public APIs

## Build System

### Cross-compilation
- **Target**: x86_64-unknown-enochcore
- **Compiler**: x86_64-enochcore-gcc
- **Linker**: x86_64-enochcore-ld
- **Assembler**: nasm

### Build Process
1. Compile kernel source files
2. Assemble assembly files
3. Link kernel binary
4. Build userland applications
5. Create bootable disk image

### Version Information
- **Current Version**: 0.01
- **Kernel**: Monolithic x86_64
- **Bootloader**: Limine
- **Filesystems**: FAT32 (boot), Ext2 (root)
- **Desktop**: KDE Plasma
- **C Library**: musl libc (adapted)
- **GPU Support**: NVIDIA (auto-detection)
- **Network**: lwIP stack
- **Build System**: GNU Make 