FILE (GLOB GRUB_SYSLINUX2CFG_SRC
    ${CMAKE_SOURCE_DIR}/util/grub-syslinux2cfg.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/syslinux_parse.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/getline.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/init.c
    ${CMAKE_SOURCE_DIR}/grub-core/kern/emu/hostfs.c
    ${CMAKE_SOURCE_DIR}/grub-core/disk/host.c
    ${CMAKE_SOURCE_DIR}/grub-core/kern/emu/argp_common.c
    )
source_group (grub-syslinux2cfg ${GRUB_SYSLINUX2CFG_SRC})

add_executable(grub-syslinux2cfg ${GRUB_SYSLINUX2CFG_SRC})
target_link_libraries (grub-syslinux2cfg -ldevmapper -lgrubmods -lgrubgcry -lgrubkern -lgnu)
target_include_directories (grub-syslinux2cfg BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/)
target_link_directories (grub-syslinux2cfg BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/.lib)
set_target_properties (grub-syslinux2cfg PROPERTIES OUTPUT_NAME "${CMAKE_BINARY_DIR}/grub-syslinux2cfg")
target_compile_definitions (grub-syslinux2cfg PUBLIC -DGRUB_FILE=\"util/grub-syslinux2cfg.c\")
