/**
 * @brief 检查文件是否为指定的类型
 *
 */

#include <config.h>

#include <grub/util/misc.h>
#include <grub/i18n.h>
#include <grub/term.h>
#include <grub/font.h>
#include <grub/gfxmenu_view.h>
#include <grub/color.h>
#include <grub/util/install.h>
#include <grub/command.h>
#include <grub/env.h>

#define _GNU_SOURCE	1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include "progname.h"

void grub_file_init (void);
void grub_host_init (void);
void grub_hostfs_init (void);

int main (int argc, char *argv[])
{
    char **argv2;
    int i;
    int had_file = 0, had_separator = 0;
    grub_command_t cmd;
    grub_err_t err;

    // 本地化，语言绑定
    grub_util_host_init (&argc, &argv);

    // stdlib 里 calloc (size_t, size_t) 的别称
    argv2 = xcalloc (argc, sizeof (argv2[0]));

    if (argc == 2 && strcmp (argv[1], "--version") == 0) {
        printf ("%s (%s) %s\n", program_name, PACKAGE_NAME, PACKAGE_VERSION);
    }

    for (i = 1; i < argc; i++) {
        if (argv[i][0] == '-' && argv[i][1] == '-' && argv[i][2] == '\0' && !had_separator) {
	        had_separator = 1;
	        argv2[i - 1] = xstrdup (argv[i]);
	        continue;
	    }

        if (argv[i][0] == '-' && !had_separator) {
	        argv2[i - 1] = xstrdup (argv[i]);
	        continue;
	    }

        if (had_file) {
            grub_util_error ("one argument expected");
        }

        // 要检测的指定文件，grub_canonicalize_file_name 返回规范后的绝对路径
        argv2[i - 1] = grub_canonicalize_file_name (argv[i]);
        if (!argv2[i - 1]) {
	        grub_util_error (_("cannot open `%s': %s"), argv[i], strerror (errno));
        }

        had_file = 1;
    }

    argv2[i - 1] = NULL;

    /* Initialize all modules. */
    grub_init_all ();           // 文件系统初始化(ps://很多文件系统)
    grub_file_init ();
    grub_hostfs_init ();        // hostfs
    grub_host_init ();

    grub_env_set ("root", "host");

    cmd = grub_command_find ("file");
    if (!cmd) {
        grub_util_error (_("can't find command `%s'"), "file");
    }

    // 执行命令 + 传入的参数列表
    err = (cmd->func) (cmd, argc - 1, argv2);
    if (err && err != GRUB_ERR_TEST_FAILURE) {
        grub_print_error ();
    }

    return err;
}
