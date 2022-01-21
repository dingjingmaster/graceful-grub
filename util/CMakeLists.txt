project (util)


FILE (GLOB GRUB_FILE_SRC
    ${CMAKE_SOURCE_DIR}/util/grub-file.c
    ${CMAKE_SOURCE_DIR}/util/render-label.c
    ${CMAKE_SOURCE_DIR}/grub-core/commands/file.c
    ${CMAKE_SOURCE_DIR}/grub-core/commands/file32.c
    ${CMAKE_SOURCE_DIR}/grub-core/commands/file64.c
    ${CMAKE_SOURCE_DIR}/grub-core/loader/i386/xen_file.c
    ${CMAKE_SOURCE_DIR}/grub-core/loader/i386/xen_file32.c
    ${CMAKE_SOURCE_DIR}/grub-core/loader/i386/xen_file64.c
    ${CMAKE_SOURCE_DIR}/grub-core/io/offset.c
    ${CMAKE_SOURCE_DIR}/grub-core/kern/elf.c
    ${CMAKE_SOURCE_DIR}/grub-core/loader/lzss.c
    ${CMAKE_SOURCE_DIR}/grub-core/loader/macho.c
    ${CMAKE_SOURCE_DIR}/grub-core/loader/macho32.c
    ${CMAKE_SOURCE_DIR}/grub-core/loader/macho64.c
    ${CMAKE_SOURCE_DIR}/grub-core/kern/emu/hostfs.c
    ${CMAKE_SOURCE_DIR}/grub-core/disk/host.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/init.c
    )
source_group (grub-file ${GRUB_FILE_SRC})

add_executable(grub-file ${GRUB_FILE_SRC})
target_link_libraries (grub-file -ldevmapper -lgrubmods -lgrubgcry -lgrubkern -lgnu)
target_include_directories (grub-file BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/)
target_link_directories (grub-file BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/.lib)
set_target_properties (grub-file PROPERTIES OUTPUT_NAME "${CMAKE_BINARY_DIR}/grub-file")
target_compile_definitions (grub-file PUBLIC -DGRUB_FILE=\"util/grub-file.c\")


FILE (GLOB GRUB_INSTALL_SRC
    ${CMAKE_SOURCE_DIR}/util/grub-install.c
    ${CMAKE_SOURCE_DIR}/util/probe.c
    ${CMAKE_SOURCE_DIR}/util/mkimage.c
    ${CMAKE_SOURCE_DIR}/util/grub-mkimage32.c
    ${CMAKE_SOURCE_DIR}/util/grub-mkimage64.c
    ${CMAKE_SOURCE_DIR}/util/grub-install-common.c
    ${CMAKE_SOURCE_DIR}/util/setup_bios.c
    ${CMAKE_SOURCE_DIR}/util/setup_sparc.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/reed_solomon.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/random.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/ofpath.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/platform.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/platform_unix.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/compress.c
    ${CMAKE_SOURCE_DIR}/util/editenv.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/blocklist.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/config.c
    ${CMAKE_SOURCE_DIR}/util/config.c
    ${CMAKE_SOURCE_DIR}/util/render-label.c
    ${CMAKE_SOURCE_DIR}/grub-core/kern/emu/hostfs.c
    ${CMAKE_SOURCE_DIR}/grub-core/disk/host.c
    ${CMAKE_SOURCE_DIR}/util/resolve.c
    ${CMAKE_SOURCE_DIR}/grub-core/kern/emu/argp_common.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/init.c
    )
source_group (grub-install ${GRUB_INSTALL_SRC})

add_executable(grub-install ${GRUB_INSTALL_SRC})
target_link_libraries (grub-install -ldevmapper -lgrubmods -lgrubgcry -lgrubkern -lgnu -llzma)
target_include_directories (grub-install BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/)
target_link_directories (grub-install BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/.lib)
set_target_properties (grub-install PROPERTIES OUTPUT_NAME "${CMAKE_BINARY_DIR}/grub-install")
target_compile_definitions (grub-install PUBLIC -DGRUB_FILE=\"util/grub-install.c\")
