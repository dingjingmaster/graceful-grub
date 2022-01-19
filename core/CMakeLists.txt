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
#    kernel/elfXX.c
    kernel/env.c
    kernel/err.c
    kernel/file.c
    kernel/fs.c
    kernel/list.c
#    kernel/lockdown.c
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
#    kernel/vga_init.c
    )
source_group (kernel ${KERNEL_SRC})

FILE (GLOB CPU_HDR
    cpu/at_keyboard.h
    cpu/bsd.h
    cpu/cmos.h
    cpu/cpuid.h
    cpu/efiemu.h
    cpu/floppy.h
    cpu/freebsd_linker.h
    cpu/freebsd_reboot.h
    cpu/gdb.h
    cpu/io.h
    cpu/linux.h
    cpu/macho.h
    cpu/memory.h
    cpu/memory_raw.h
    cpu/multiboot.h
    cpu/netbsd_bootinfo.h
    cpu/netbsd_reboot.h
    cpu/openbsd_bootarg.h
    cpu/openbsd_reboot.h
    cpu/pci.h
    cpu/pit.h
    cpu/pmtimer.h
    cpu/rdmsr.h
    cpu/reboot.h
    cpu/relocator.h
    cpu/relocator_private.h
    cpu/setjmp.h
    cpu/time.h
    cpu/tsc.h
    cpu/types.h
    cpu/wrmsr.h
    cpu/xnu.h
    )
FILE (GLOB CPU_SRC
    cpu/acpi.c
    cpu/buffer.c
    cpu/command.c
    cpu/compiler-rt.c
    cpu/corecmd.c
    cpu/device.c
    cpu/disk.c
#    cpu/disk_common.c
    cpu/dl.c
    cpu/elf.c
#    cpu/elfXX.c
    cpu/env.c
    cpu/err.c
    cpu/file.c
    cpu/fs.c
    cpu/list.c
#    cpu/lockdown.c
    cpu/main.c
    cpu/misc.c
    cpu/mm.c
    cpu/parser.c
    cpu/partition.c
    cpu/rescue_parser.c
    cpu/rescue_reader.c
    cpu/term.c
    cpu/time.c
    cpu/verifiers.c
#    cpu/vga_init.c
    )
source_group (cpu ${CPU_HDR} ${CPU_SRC})


FILE (GLOB CPU_I386_HDR
    cpu/i386/at_keyboard.h
    cpu/i386/bsd.h
    cpu/i386/cmos.h
    cpu/i386/cpuid.h
    cpu/i386/efiemu.h
    cpu/i386/floppy.h
    cpu/i386/freebsd_linker.h
    cpu/i386/freebsd_reboot.h
    cpu/i386/gdb.h
    cpu/i386/io.h
    cpu/i386/linux.h
    cpu/i386/macho.h
    cpu/i386/memory.h
    cpu/i386/memory_raw.h
    cpu/i386/multiboot.h
    cpu/i386/netbsd_bootinfo.h
    cpu/i386/netbsd_reboot.h
    cpu/i386/openbsd_bootarg.h
    cpu/i386/openbsd_reboot.h
    cpu/i386/pci.h
    cpu/i386/pit.h
    cpu/i386/pmtimer.h
    cpu/i386/rdmsr.h
    cpu/i386/reboot.h
    cpu/i386/relocator.h
    cpu/i386/relocator_private.h
    cpu/i386/setjmp.h
    cpu/i386/time.h
    cpu/i386/tsc.h
    cpu/i386/types.h
    cpu/i386/wrmsr.h
    cpu/i386/xnu.h

    cpu/i386/pc/apm.h
    cpu/i386/pc/biosdisk.h
    cpu/i386/pc/biosnum.h
    cpu/i386/pc/boot.h
    cpu/i386/pc/chainloader.h
    cpu/i386/pc/console.h
    cpu/i386/pc/int.h
    cpu/i386/pc/int_types.h
    cpu/i386/pc/kernel.h
    cpu/i386/pc/memory.h
    cpu/i386/pc/pxe.h
    cpu/i386/pc/time.h
    cpu/i386/pc/vbe.h
    cpu/i386/pc/vesa_modes_table.h
    )

FILE (GLOB CPU_I386_SRC
    cpu/i386/dl.c
#    cpu/i386/multiboot_mmap.c
    cpu/i386/tsc.c
    cpu/i386/tsc_pit.c
    cpu/i386/tsc_pmtimer.c

    cpu/i386/pc/acpi.c
    cpu/i386/pc/init.c
    cpu/i386/pc/mmap.c
    )
source_group (cpu_i386 ${CPU_I386_HDR} ${CPU_I386_SRC})

FILE (GLOB EMU_HDR
    emu/config.h
    emu/console.h
    emu/exec.h
    emu/getroot.h
    emu/hostdisk.h
    emu/hostfile.h
    emu/misc.h
    emu/net.h
    )

FILE (GLOB EMU_SRC
    emu/argp_common.c
#    emu/cache.c
#    emu/full.c
    emu/hostdisk.c
    emu/hostfs.c
#    emu/lite.c
    emu/main.c
    emu/misc.c
    emu/mm.c
    emu/time.c

    )
source_group (emu ${EMU_HDR} ${EMU_SRC})

FILE (GLOB TERM_HDR
    )
FILE (GLOB TERM_SRC
#    term/at_keyboard.c
#    term/gfxterm_background.c
#    term/gfxterm.c
#    term/morse.c
#    term/ns8250.c
#    term/ps2.c
#    term/serial.c
#    term/spkmodem.c
    term/terminfo.c
    term/tparm.c
#    term/usb_keyboard.c
    )
source_group (term ${TERM_HDR} ${TERM_SRC})

set (CORE_SRC
    ${GNULIB_HDR}       ${GNULIB_SRC}
    ${OSDEP_HDR}        ${OSDEP_SRC}            ${OSDEP_UNIX_SRC}

    ${KERNEL_SRC}
    ${CPU_HDR}          ${CPU_SRC}
    ${CPU_I386_HDR}     ${CPU_I386_SRC}
    ${EMU_HDR}          ${EMU_SRC}
    ${TERM_HDR}         ${TERM_SRC}
    )


add_library (${LIB_CORE_NAME} STATIC ${CORE_SRC})
