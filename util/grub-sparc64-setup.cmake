FILE (GLOB GRUB_SPARC64_SETUP_SRC
    ${CMAKE_SOURCE_DIR}/util/grub-setup.c
    ${CMAKE_SOURCE_DIR}/util/setup_sparc.c
    ${CMAKE_SOURCE_DIR}/grub-core/kern/emu/argp_common.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/reed_solomon.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/ofpath.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/blocklist.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/init.c
    )
source_group (grub-sparc64-setup ${GRUB_SPARC64_SETUP_SRC})

add_executable(grub-sparc64-setup ${GRUB_SPARC64_SETUP_SRC})
target_link_libraries (grub-sparc64-setup -ldevmapper -lgrubmods -lgrubgcry -lgrubkern -lgnu)
target_include_directories (grub-sparc64-setup BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/)
target_link_directories (grub-sparc64-setup BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/.lib)
set_target_properties (grub-sparc64-setup PROPERTIES OUTPUT_NAME "${CMAKE_BINARY_DIR}/grub-sparc64-setup")
target_compile_definitions (grub-sparc64-setup PUBLIC -DGRUB_FILE=\"util/grub-sparc64-setup.c\" -DGRUB_SETUP_FUNC=grub_util_sparc_setup)
