# Building EnochCore

EnochCore is a monolithic x86_64 Unix-like POSIX-compliant operating system. Building it requires a cross-compiler and standard Unix tools. Version 0.01 includes KDE Plasma desktop, NVIDIA GPU support, and adapted musl libc.

> **Warning!** If any step fails, do NOT proceed. Double-check your dependencies and, if the issue persists, report it. EnochCore is under active development!

## Requirements

### Essential Tools
- **Cross-compiler**: `x86_64-enochcore-gcc` and `x86_64-enochcore-ld`
- **Assembler**: `nasm` for x86_64 assembly files
- **Disk tools**: `parted`, `mkdosfs`, `fatlabel` for creating bootable images
- **Build tools**: `make`, `gcc`, `autoconf`, `automake`
- **Qt development**: For KDE Plasma desktop environment

### Cross-compiler Information
The kernel requires a custom cross-compiler targeting `x86_64-unknown-enochcore`. The toolchain should be installed in `~/opt/cross/bin/`.

## Dependencies by Distribution

### Ubuntu/Debian
```bash
sudo apt install -y nasm dosfstools parted bison flex libgmp3-dev libmpc-dev libmpfr-dev texinfo libisl-dev parted dosfstools build-essential autoconf automake wget qt6-base-dev qt6-declarative-dev qt6-tools-dev
```

### Fedora
```bash
sudo dnf install -y nasm gcc xorriso parted dosfstools make bison flex gmp-devel libmpc-devel mpfr-devel texinfo autoconf automake patch gcc-c++ isl-devel wget qt6-qtbase-devel qt6-qtdeclarative-devel qt6-qttools-devel
```

### Arch Linux
```bash
sudo pacman -S --noconfirm nasm xorriso gcc parted dosfstools base-devel gmp libmpc mpfr autoconf automake wget qt6-base qt6-declarative qt6-tools
```

### Other Distributions
If your distribution is not listed, try using [distrobox](https://github.com/89luca89/distrobox) to create a compatible environment.

## Cross-compiler Setup

### Automatic Setup
Run the following command to automatically download and build the cross-compiler:
```bash
make tools
```

### Manual Setup
If automatic setup fails, you can build the cross-compiler manually:
1. Download and build binutils for `x86_64-unknown-enochcore`
2. Download and build GCC for `x86_64-unknown-enochcore`
3. Install to `~/opt/cross/`

### Toolchain Verification
```bash
export PATH="$HOME/opt/cross/bin:$PATH"
x86_64-enochcore-gcc --version
x86_64-enochcore-ld --version
```

## Building EnochCore

### Quick Build
```bash
# Set up cross-compilation toolchain
export PATH="$HOME/opt/cross/bin:$PATH"

# Build the complete system
make clean
make -j$(nproc)

# Create bootable disk image
make disk
```

### Build Options
- **`make`**: Build kernel, userland, and desktop environment
- **`make kernel`**: Build only the kernel binary
- **`make userland`**: Build userland applications and libraries
- **`make desktop`**: Build KDE Plasma desktop environment
- **`make disk`**: Create full bootable disk image
- **`make clean`**: Clean all build artifacts

### Build Output
- **Kernel binary**: `build/enochcore.elf`
- **Disk image**: `disk.img` (bootable with Limine)
- **Userland applications**: `target/bin/`
- **Desktop environment**: `target/usr/share/`

## Testing EnochCore

### QEMU (Recommended)
```bash
# Run with basic configuration
make qemu

# Run with debugging and network capture
make qemu_dbg

# Run with KDE desktop
make qemu_desktop
```

### QEMU Options
- **Basic**: 4GB RAM, E1000 network, VMware SVGA
- **Debug**: 8GB RAM, network capture, SMP support, GDB debugging
- **Desktop**: 8GB RAM, accelerated graphics, KDE Plasma

### Other Virtualization
- **VMware**: Use `make vmware` to create `.vmdk` file
- **VirtualBox**: Can use the same `.vmdk` file as VMware
- **Real hardware**: Write `disk.img` to USB drive or hard disk

## System Requirements

### Virtual Machine
- **CPU**: x86_64 compatible
- **RAM**: 4GB minimum, 8GB recommended for desktop
- **Storage**: 20GB minimum for full system with desktop
- **Network**: Optional, for networking features
- **Graphics**: VGA or accelerated graphics for desktop

### Real Hardware
- **CPU**: x86_64 processor with 64-bit support
- **RAM**: 4GB minimum, 8GB recommended
- **Storage**: 20GB minimum
- **Boot**: UEFI or BIOS boot support
- **Graphics**: VGA, framebuffer, or NVIDIA GPU support
- **Network**: Ethernet or wireless network adapter

## Desktop Environment

### KDE Plasma
- Full desktop environment ported from FreeBSD
- Qt6-based applications and framework
- System settings and configuration
- Application launcher and panel

### KScreenLocker
- Screen locking mechanism
- Integration with KDE Plasma
- Security features and timeouts

### GPU Support
- **NVIDIA Auto-Detection**: RTX 3060 Ti, RTX 3070, RTX 3080, RTX 3090
- **Legacy Support**: GTX 1660, GTX 1070, GTX 1080
- **Driver Management**: Automatic driver selection

## Troubleshooting

### Common Issues
1. **Cross-compiler not found**: Run `make tools` to build it
2. **Permission denied**: Ensure you have write access to build directories
3. **QEMU not found**: Install QEMU system emulator
4. **Disk creation fails**: Check that you have sufficient disk space
5. **KDE build fails**: Install Qt6 development packages
6. **NVIDIA detection fails**: Check GPU compatibility

### Debugging
- Use `make qemu_dbg` for debugging with GDB
- Check serial output for kernel messages
- Network capture is available in debug mode
- Desktop logs available in `/var/log/`

## Next Steps

After successful build and testing:
1. Explore the source code in `src/kernel/`
2. Read the architecture documentation in `docs/architecture.md`
3. Try the KDE Plasma desktop environment
4. Test NVIDIA GPU auto-detection
5. Try modifying kernel features
6. Contribute improvements back to the project

## Support

If you encounter issues:
1. Check the troubleshooting section above
2. Review the architecture documentation
3. Check the CHANGELOG.md for known issues
4. Report bugs with detailed information about your environment
5. Ask questions in the project discussions

## Version Information
- **Current Version**: 0.01
- **Kernel**: Monolithic x86_64
- **Bootloader**: Limine
- **Filesystems**: FAT32 (boot), Ext2 (root)
- **Desktop**: KDE Plasma
- **C Library**: musl libc (adapted)
- **GPU Support**: NVIDIA (auto-detection)
- **Network**: lwIP stack
- **Build System**: GNU Make
