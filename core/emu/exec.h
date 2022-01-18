#ifndef GRUB_EMU_EXEC_H
#define GRUB_EMU_EXEC_H 1

#include "config.h"
#include <stdarg.h>

#include <sys/types.h>
pid_t
grub_util_exec_pipe (const char *const *argv, int *fd);
pid_t
grub_util_exec_pipe_stderr (const char *const *argv, int *fd);

int
grub_util_exec_redirect_all (const char *const *argv, const char *stdin_file,
			     const char *stdout_file, const char *stderr_file);
int
grub_util_exec (const char *const *argv);
int
grub_util_exec_redirect (const char *const *argv, const char *stdin_file,
			 const char *stdout_file);
int
grub_util_exec_redirect_null (const char *const *argv);

#endif
