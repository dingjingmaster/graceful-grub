FILE (GLOB GRUB_RENDER_LABEL_SRC
    ${CMAKE_SOURCE_DIR}/util/grub-render-label.c
    ${CMAKE_SOURCE_DIR}/util/render-label.c
    ${CMAKE_SOURCE_DIR}/grub-core/kern/emu/argp_common.c
    ${CMAKE_SOURCE_DIR}/grub-core/kern/emu/hostfs.c
    ${CMAKE_SOURCE_DIR}/grub-core/disk/host.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/init.c
    )
source_group (grub-render-label ${GRUB_RENDER_LABEL_SRC})

add_executable(grub-render-label ${GRUB_RENDER_LABEL_SRC})
target_link_libraries (grub-render-label
    ${CMAKE_SOURCE_DIR}/.lib/libgrubmods.a
    -ldevmapper -lgrubmods -lgrubgcry -lgrubkern -lgnu)
target_include_directories (grub-render-label BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/)
target_link_directories (grub-render-label BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/.lib)
set_target_properties (grub-render-label PROPERTIES OUTPUT_NAME "${CMAKE_BINARY_DIR}/grub-render-label")
target_compile_definitions (grub-render-label PUBLIC -DGRUB_FILE=\"util/grub-render-label.c\")
