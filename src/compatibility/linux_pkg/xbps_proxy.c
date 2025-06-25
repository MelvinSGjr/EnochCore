// EnochCore xbps proxy handler for Void Linux
#include <compatibility/linux_pkg/xbps_proxy.h>
#include <syscalls/syscall.h>

int void_install(const char* pkg) {
    // TODO: implement xbps install logic via IPC
    return 0;
}

void void_remove(const char *data) {
    // Parse the data: it may be a string with packages to remove
    // Example: "xbps-remove package1 package2 ..."
    // Emulate xbps-remove call in an isolated environment (chroot or namespace)
    // This requires:
    //   - Creating a temporary filesystem with Void libraries
    //   - Copying the xbps binary (statically linked) or using an emulator
    // Here is a simple stub:
    syscall(SYS_exec, "/compat/void/bin/xbps-remove", data, NULL);
} 