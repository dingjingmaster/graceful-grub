FILE (GLOB GRUB_MENULST2CFG_SRC
    ${CMAKE_SOURCE_DIR}/util/grub-menulst2cfg.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/legacy_parse.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/i386/pc/vesa_modes_table.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/init.c
    )
source_group (grub-menulst2cfg ${GRUB_MENULST2CFG_SRC})

add_executable(grub-menulst2cfg ${GRUB_MENULST2CFG_SRC})
target_link_libraries (grub-menulst2cfg
    ${CMAKE_SOURCE_DIR}/.lib/libgrubmods.a
    -ldevmapper -lgrubmods -lgrubgcry -lgrubkern -lgnu)
target_include_directories (grub-menulst2cfg BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/)
target_link_directories (grub-menulst2cfg BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/.lib)
set_target_properties (grub-menulst2cfg PROPERTIES OUTPUT_NAME "${CMAKE_BINARY_DIR}/grub-menulst2cfg")
target_compile_definitions (grub-menulst2cfg PUBLIC -DGRUB_FILE=\"util/grub-menulst2cfg.c\")
