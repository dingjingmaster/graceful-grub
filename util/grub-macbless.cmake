FILE (GLOB GRUB_MACBLESS_SRC
    ${CMAKE_SOURCE_DIR}/util/grub-macbless.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/init.c
    ${CMAKE_SOURCE_DIR}/grub-core/kern/emu/argp_common.c
    )
source_group (grub-macbless ${GRUB_MACBLESS_SRC})

add_executable(grub-macbless ${GRUB_MACBLESS_SRC})
target_link_libraries (grub-macbless -ldevmapper -lgrubmods -lgrubgcry -lgrubkern -lgnu)
target_include_directories (grub-macbless BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/)
target_link_directories (grub-macbless BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/.lib)
set_target_properties (grub-macbless PROPERTIES OUTPUT_NAME "${CMAKE_BINARY_DIR}/grub-macbless")
target_compile_definitions (grub-macbless PUBLIC -DGRUB_FILE=\"util/grub-macbless.c\")
