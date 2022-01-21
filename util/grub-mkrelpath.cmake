FILE (GLOB GRUB_MKRELPATH_SRC
    ${CMAKE_SOURCE_DIR}/util/grub-mkrelpath.c
    ${CMAKE_SOURCE_DIR}/grub-core/kern/emu/argp_common.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/init.c
    )
source_group (grub-mkrelpath ${GRUB_MKRELPATH_SRC})

add_executable(grub-mkrelpath ${GRUB_MKRELPATH_SRC})
target_link_libraries (grub-mkrelpath -ldevmapper -lgrubmods -lgrubgcry -lgrubkern -lgnu)
target_include_directories (grub-mkrelpath BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/)
target_link_directories (grub-mkrelpath BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/.lib)
set_target_properties (grub-mkrelpath PROPERTIES OUTPUT_NAME "${CMAKE_BINARY_DIR}/grub-mkrelpath")
target_compile_definitions (grub-mkrelpath PUBLIC -DGRUB_FILE=\"util/grub-mkrelpath.c\")
