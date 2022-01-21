FILE (GLOB GRUB_OFPATHNAME_SRC
    ${CMAKE_SOURCE_DIR}/util/ieee1275/grub-ofpathname.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/ofpath.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/init.c
    )
source_group (grub-ofpathname ${GRUB_OFPATHNAME_SRC})

add_executable(grub-ofpathname ${GRUB_OFPATHNAME_SRC})
target_link_libraries (grub-ofpathname -ldevmapper -lgrubmods -lgrubgcry -lgrubkern -lgnu)
target_include_directories (grub-ofpathname BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/)
target_link_directories (grub-ofpathname BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/.lib)
set_target_properties (grub-ofpathname PROPERTIES OUTPUT_NAME "${CMAKE_BINARY_DIR}/grub-ofpathname")
target_compile_definitions (grub-ofpathname PUBLIC -DGRUB_FILE=\"util/grub-ofpathname.c\")
