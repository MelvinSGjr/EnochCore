// EnochCore FUSE driver for Linux package managers
#include "pkg_fuse.h"

void apk_translate_request(struct fuse_ops* ops) {
    // Intercept apk install and dependency resolution
    ops->install = native_syscall(SYS_PKG_ADD, ALPINE_MODE);
    ops->resolve_deps = convert_alpine_deps_to_native();
}

void xbps_translate_request(struct fuse_ops* ops) {
    // Intercept xbps install and dependency resolution
    ops->install = native_syscall(SYS_PKG_ADD, VOID_MODE);
    ops->resolve_deps = convert_void_deps_to_native();
} 