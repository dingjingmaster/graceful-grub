#ifndef GRUB_EMU_HOSTFILE_H
#define GRUB_EMU_HOSTFILE_H 1

#include <config.h>
#include <stdarg.h>

#include <windows.h>
typedef HANDLE grub_util_fd_t;
#define GRUB_UTIL_FD_INVALID INVALID_HANDLE_VALUE
#define GRUB_UTIL_FD_IS_VALID(x) ((x) != GRUB_UTIL_FD_INVALID)
#define GRUB_UTIL_FD_STAT_IS_FUNCTIONAL 0

#define DEFAULT_DIRECTORY	"C:\\"GRUB_BOOT_DIR_NAME"\\"GRUB_DIR_NAME
#define DEFAULT_DEVICE_MAP	DEFAULT_DIRECTORY "/device.map"

struct grub_util_fd_dirent
{
  char d_name[0];
};
struct grub_util_fd_dir;
typedef struct grub_util_fd_dirent *grub_util_fd_dirent_t;
typedef struct grub_util_fd_dir *grub_util_fd_dir_t;

int
grub_util_rename (const char *from, const char *to);
int
grub_util_unlink (const char *name);
void
grub_util_mkdir (const char *dir);

grub_util_fd_dir_t
grub_util_fd_opendir (const char *name);

void
grub_util_fd_closedir (grub_util_fd_dir_t dirp);

grub_util_fd_dirent_t
grub_util_fd_readdir (grub_util_fd_dir_t dirp);

int
grub_util_rmdir (const char *pathname);

enum grub_util_fd_open_flags_t
  {
    GRUB_UTIL_FD_O_RDONLY = 1,
    GRUB_UTIL_FD_O_WRONLY = 2,
    GRUB_UTIL_FD_O_RDWR = 3,
    GRUB_UTIL_FD_O_CREATTRUNC = 4,
    GRUB_UTIL_FD_O_SYNC = 0,
  };

#if defined (__MINGW32__) && !defined (__MINGW64__)

/* 32 bit on Mingw-w64 already redefines them if _FILE_OFFSET_BITS=64 */
#ifndef _W64
#define fseeko fseeko64
#define ftello ftello64
#endif

#endif

LPTSTR
grub_util_utf8_to_tchar (const char *in);
char *
grub_util_tchar_to_utf8 (LPCTSTR in);

#endif
