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
