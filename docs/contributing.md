# Contributing to EnochCore
> Thank you for your interest in contributing to EnochCore development!

All contributions are subject to thorough review and testing to ensure the quality and stability of EnochCore. Please be patient during the review process.

## Requirements
- **Proper code formatting:** 
  - Run `make format` before creating a pull request. 
  - Your submission will be checked using `make format_check` to ensure it follows the project's code style.
  - For unsupported file types (assembly, makefile, shell, etc.), keep your code clean and consistent with existing examples.
- **Testing:**
  - Build EnochCore and boot into it to test your changes. Use `make qemu` or `make vmware` for quick testing.
  - **Do NOT submit untested code.**
  - The same applies to utility scripts used by the build system. Test them thoroughly.
  - Test both kernel and userland components.
  - If contributing desktop features, test KDE Plasma integration.
- **Code familiarity:**
  - EnochCore values code simplicity and clarity. Prefer simple, maintainable solutions over unnecessary complexity.
  - Avoid unnecessary assembly unless required for low-level operations.
  - All code comments must be in English only.
  - Submissions may be rejected for any reason to maintain project direction and quality.

## Development Areas

### Kernel Development
- **Memory management**: Paging, virtual memory, memory allocation
- **Device drivers**: Hardware support, driver interfaces
- **Filesystems**: FAT32, Ext2, virtual filesystems
- **Networking**: lwIP integration, network drivers
- **System calls**: Linux compatibility, POSIX support

### Userland Development
- **musl libc**: C library adaptation and extensions
- **System utilities**: BusyBox integration, core utilities
- **Init systems**: OpenRC, systemd support
- **Applications**: Calculator, logic designer, test tools

### Desktop Environment
- **KDE Plasma**: Desktop environment porting and integration
- **KScreenLocker**: Screen locking mechanism
- **Qt applications**: Desktop applications and utilities
- **Graphics support**: NVIDIA GPU integration

### Build System
- **Cross-compilation**: Toolchain setup and maintenance
- **Build scripts**: Automation and optimization
- **Package management**: Software distribution and updates

## Code Style Guidelines

### C Code
- Use consistent indentation (4 spaces)
- Follow K&R brace style
- Use descriptive variable and function names
- Add comprehensive comments for complex logic
- Handle errors appropriately

### Assembly Code
- Use Intel syntax (nasm)
- Add comments explaining complex operations
- Follow x86_64 calling conventions
- Optimize for clarity over performance

### Makefiles
- Use consistent variable naming
- Add helpful comments
- Follow dependency rules properly
- Use phony targets appropriately

## Testing Guidelines

### Kernel Testing
- Test in QEMU with different configurations
- Verify system call compatibility
- Test memory management features
- Check device driver functionality

### Userland Testing
- Test applications in the target environment
- Verify library compatibility
- Check system utility functionality
- Test desktop environment features

### Integration Testing
- Test complete system boot process
- Verify cross-component communication
- Check performance under load
- Test error handling and recovery

## Submission Process

1. **Fork the repository** and create a feature branch
2. **Make your changes** following the guidelines above
3. **Test thoroughly** in the target environment
4. **Update documentation** if needed
5. **Submit a pull request** with clear description

## Go for it!
With everything out of the way, good luck and happy hacking!

Created by MelvinSGjr (GitHub)
