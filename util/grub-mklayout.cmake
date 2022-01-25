FILE (GLOB GRUB_MKLAYOUT_SRC
    ${CMAKE_SOURCE_DIR}/util/grub-mklayout.c
    ${CMAKE_SOURCE_DIR}/grub-core/kern/emu/argp_common.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/init.c
    )
source_group (grub-mklayout ${GRUB_MKLAYOUT_SRC})

add_executable(grub-mklayout ${GRUB_MKLAYOUT_SRC})
target_link_libraries (grub-mklayout
    ${CMAKE_SOURCE_DIR}/.lib/libgrubmods.a
    -ldevmapper -lgrubmods -lgrubgcry -lgrubkern -lgnu)
target_include_directories (grub-mklayout BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/)
target_link_directories (grub-mklayout BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/.lib)
set_target_properties (grub-mklayout PROPERTIES OUTPUT_NAME "${CMAKE_BINARY_DIR}/grub-mklayout")
target_compile_definitions (grub-mklayout PUBLIC -DGRUB_FILE=\"util/grub-mklayout.c\")
