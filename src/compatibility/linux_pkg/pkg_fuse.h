#ifndef PKG_FUSE_H
#define PKG_FUSE_H

struct fuse_ops {
    int (*install)(const char* pkg);
    int (*resolve_deps)(const char* pkg);
};

void apk_translate_request(struct fuse_ops* ops);
void xbps_translate_request(struct fuse_ops* ops);

int native_syscall(int sysno, int mode);
int convert_alpine_deps_to_native(void);
int convert_void_deps_to_native(void);

#define ALPINE_MODE 1
#define VOID_MODE 2
#define SYS_PKG_ADD 1001

#endif // PKG_FUSE_H 