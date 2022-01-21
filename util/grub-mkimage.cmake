FILE (GLOB GRUB_MKIMAGE_SRC
    ${CMAKE_SOURCE_DIR}/util/grub-mkimage.c
    ${CMAKE_SOURCE_DIR}/util/mkimage.c
    ${CMAKE_SOURCE_DIR}/util/grub-mkimage32.c
    ${CMAKE_SOURCE_DIR}/util/grub-mkimage64.c
    ${CMAKE_SOURCE_DIR}/util/resolve.c
    ${CMAKE_SOURCE_DIR}/grub-core/kern/emu/argp_common.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/init.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/config.c
    ${CMAKE_SOURCE_DIR}/util/config.c
    )
source_group (grub-mkimage ${GRUB_MKIMAGE_SRC})

add_executable(grub-mkimage ${GRUB_MKIMAGE_SRC})
target_link_libraries (grub-mkimage -ldevmapper -lgrubmods -lgrubgcry -lgrubkern -lgnu -llzma)
target_include_directories (grub-mkimage BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/)
target_link_directories (grub-mkimage BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/.lib)
set_target_properties (grub-mkimage PROPERTIES OUTPUT_NAME "${CMAKE_BINARY_DIR}/grub-mkimage")
target_compile_definitions (grub-mkimage PUBLIC -DGRUB_FILE=\"util/grub-mkimage.c\")
