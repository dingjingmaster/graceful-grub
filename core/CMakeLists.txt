project (core)

FILE (GLOB GNULIB_HDR
    gnulib/assure.h
    gnulib/progname.h
    gnulib/chdir-long.h
    gnulib/save-cwd.h
    gnulib/fcntl.h
    gnulib/unistd--.h
    gnulib/pathmax.h
    gnulib/unistd-safer.h
    )
FILE (GLOB GNULIB_SRC
    gnulib/chdir-long.c
    gnulib/progname.c
    gnulib/fcntl.c
    gnulib/save-cwd.c
    )
source_group (gnulib ${GNULIB_HDR} ${GNULIB_SRC})



FILE (GLOB OSDEP_UNIX_SRC
    osdep/unix/compress.c
    osdep/unix/hostdisk.c
    osdep/unix/config.c
    osdep/unix/password.c
    osdep/unix/cputime.c
    osdep/unix/platform.c
    osdep/unix/dl.c
    osdep/unix/random.c
    osdep/unix/emuconsole.c
    osdep/unix/relpath.c
    osdep/unix/exec.c
    osdep/unix/sleep.c
    osdep/unix/getroot.c
    )
FILE (GLOB OSDEP_HDR
    osdep/hostfile.h
    )
FILE (GLOB OSDEP_SRC
    osdep/blocklist.c
    osdep/hostdisk.c
    osdep/compress.c
    osdep/init.c
    osdep/config.c
    osdep/ofpath.c
    osdep/cputime.c
    osdep/password.c
    osdep/dl.c
    osdep/platform.c
    osdep/emuconsole.c
    osdep/platform_unix.c
    osdep/emunet.c
    osdep/random.c
    osdep/exec.c
    osdep/relpath.c
    osdep/getroot.c
    osdep/sleep.c
    )
source_group (osdep ${OSDEP_HDR} ${OSDEP_SRC} ${OSDEP_UNIX_SRC})



FILE (GLOB KERNEL_SRC
    kernel/acpi.c
    kernel/acpi_module-acpi.o
    kernel/buffer.c
    kernel/command.c
    kernel/compiler-rt.c
    kernel/corecmd.c
    kernel/device.c
    kernel/disk.c
    kernel/disk_common.c
    kernel/dl.c
    kernel/elf.c
    kernel/elfXX.c
    kernel/env.c
    kernel/err.c
    kernel/file.c
    kernel/fs.c
    kernel/list.c
    kernel/lockdown.c
    kernel/main.c
    kernel/misc.c
    kernel/mm.c
    kernel/parser.c
    kernel/partition.c
    kernel/rescue_parser.c
    kernel/rescue_reader.c
    kernel/term.c
    kernel/time.c
    kernel/verifiers.c
    kernel/vga_init.c
    )


set (CORE_SRC
    ${GNULIB_HDR}   ${GNULIB_SRC}
    ${OSDEP_HDR}    ${OSDEP_SRC}        ${OSDEP_UNIX_SRC}
    ${KERNEL_SRC}
    )


add_library (${LIB_CORE_NAME} STATIC ${CORE_SRC})
