FILE (GLOB GRUB_GLUE_EFI_SRC
    ${CMAKE_SOURCE_DIR}/util/grub-glue-efi.c
    ${CMAKE_SOURCE_DIR}/util/glue-efi.c
    ${CMAKE_SOURCE_DIR}/grub-core/kern/emu/argp_common.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/init.c
    )
source_group (grub-glue-efi ${GRUB_GLUE_EFI_SRC})

add_executable(grub-glue-efi ${GRUB_GLUE_EFI_SRC})
target_link_libraries (grub-glue-efi
    ${CMAKE_SOURCE_DIR}/.lib/libgrubmods.a
    -ldevmapper -lgrubmods -lgrubgcry -lgrubkern -lgnu)
target_include_directories (grub-glue-efi BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/)
target_link_directories (grub-glue-efi BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/.lib)
set_target_properties (grub-glue-efi PROPERTIES OUTPUT_NAME "${CMAKE_BINARY_DIR}/grub-glue-efi")
target_compile_definitions (grub-glue-efi PUBLIC -DGRUB_FILE=\"util/grub-glue-efi.c\")
