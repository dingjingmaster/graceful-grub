FILE (GLOB GRUB_MKFONT_SRC
    ${CMAKE_SOURCE_DIR}/util/grub-mkfont.c
    ${CMAKE_SOURCE_DIR}/grub-core/kern/emu/argp_common.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/init.c
    )
source_group (grub-mkfont ${GRUB_MKFONT_SRC})

# FIXME://
add_executable(grub-mkfont ${GRUB_MKFONT_SRC})
target_link_libraries (grub-mkfont
    ${CMAKE_SOURCE_DIR}/.lib/libgrubmods.a
    -ldevmapper -lgrubmods -lgrubgcry -lgrubkern -lgnu -lfreetype)
target_include_directories (grub-mkfont BEFORE PUBLIC
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/
    /usr/include/freetype2
    /usr/include/libpng16
    /usr/include/harfbuzz
    /usr/include/glib-2.0
    /usr/lib/glib-2.0/include
    )
target_link_directories (grub-mkfont BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/.lib)
set_target_properties (grub-mkfont PROPERTIES OUTPUT_NAME "${CMAKE_BINARY_DIR}/grub-mkfont")
target_compile_definitions (grub-mkfont PUBLIC -DGRUB_FILE=\"util/grub-mkfont.c\" -DGRUB_MKFONT=1)
