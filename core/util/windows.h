#ifndef GRUB_WINDOWS_UTIL_H
#define GRUB_WINDOWS_UTIL_H

#include <windows.h>

LPTSTR
grub_util_get_windows_path (const char *unix_path);

char *
grub_util_tchar_to_utf8 (LPCTSTR in);

TCHAR *
grub_get_mount_point (const TCHAR *path);

#endif
