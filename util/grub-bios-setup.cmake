FILE (GLOB GRUB_BIOS_SETUP_SRC
    ${CMAKE_SOURCE_DIR}/util/grub-setup.c
    ${CMAKE_SOURCE_DIR}/util/setup_bios.c
    ${CMAKE_SOURCE_DIR}/grub-core/kern/emu/argp_common.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/reed_solomon.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/blocklist.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/init.c
    )
source_group (grub-bios-setup ${GRUB_BIOS_SETUP_SRC})

add_executable(grub-bios-setup ${GRUB_BIOS_SETUP_SRC})
target_link_directories (grub-bios-setup BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/.lib)
target_link_libraries (grub-bios-setup -lgrubmods -ldevmapper -lgrubgcry -lgrubkern -lgnu)
target_include_directories (grub-bios-setup BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/)
set_target_properties (grub-bios-setup PROPERTIES OUTPUT_NAME "${CMAKE_BINARY_DIR}/grub-bios-setup")
target_compile_definitions (grub-bios-setup PUBLIC -DGRUB_FILE=\"util/grub-bios-setup.c\" -DGRUB_SETUP_FUNC=grub_util_bios_setup)

