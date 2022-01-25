FILE (GLOB GRUB_SCRIPT_CHECK_SRC
    ${CMAKE_SOURCE_DIR}/util/grub-script-check.c
    ${CMAKE_SOURCE_DIR}/grub-core/kern/emu/argp_common.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/init.c
    )
source_group (grub-script-check ${GRUB_SCRIPT_CHECK_SRC})

add_executable(grub-script-check ${GRUB_SCRIPT_CHECK_SRC})
target_link_libraries (grub-script-check
    ${CMAKE_SOURCE_DIR}/.lib/libgrubmods.a
    -ldevmapper -lgrubmods -lgrubgcry -lgrubkern -lgnu)
target_include_directories (grub-script-check BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/)
target_link_directories (grub-script-check BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/.lib)
set_target_properties (grub-script-check PROPERTIES OUTPUT_NAME "${CMAKE_BINARY_DIR}/grub-script-check")
target_compile_definitions (grub-script-check PUBLIC -DGRUB_FILE=\"util/grub-script-check.c\")
