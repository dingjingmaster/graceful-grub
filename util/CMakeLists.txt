project (util)


FILE (GLOB GRUB_FILE_SRC
    grub-file.c
    render-label.c
    ../grub-core/commands/file.c
    ../grub-core/commands/file32.c
    ../grub-core/commands/file64.c
    ../grub-core/loader/i386/xen_file.c
    ../grub-core/loader/i386/xen_file32.c
    ../grub-core/loader/i386/xen_file64.c
    ../grub-core/io/offset.c
    ../grub-core/kern/elf.c
    ../grub-core/loader/lzss.c
    ../grub-core/loader/macho.c
    ../grub-core/loader/macho32.c
    ../grub-core/loader/macho64.c
    ../grub-core/kern/emu/hostfs.c
    ../grub-core/disk/host.c
    ../grub-core/osdep/init.c
    )
source_group (grub_file ${GRUB_FILE_SRC})

add_executable(grub-file ${GRUB_FILE_SRC})
target_link_libraries (grub-file -ldevmapper -lgrubmods -lgrubgcry -lgrubkern -lgnu  #[[-lintl]]  #[[-lzfs -lnvpair -lgeom]])
target_include_directories (grub-file BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/)
target_link_directories (grub-file BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/.lib)
set_target_properties (grub-file PROPERTIES OUTPUT_NAME "${CMAKE_BINARY_DIR}/grub-file")
target_compile_definitions (grub-file PUBLIC -DGRUB_FILE=\"util/grub-file.c\")
