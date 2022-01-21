FILE (GLOB GRUB_MOUNT_SRC
    ${CMAKE_SOURCE_DIR}/util/grub-mount.c
    ${CMAKE_SOURCE_DIR}/grub-core/kern/emu/hostfs.c
    ${CMAKE_SOURCE_DIR}/grub-core/disk/host.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/init.c
    )
source_group (grub-mount ${GRUB_MOUNT_SRC})

add_executable(grub-mount ${GRUB_MOUNT_SRC})
target_link_libraries (grub-mount -ldevmapper -lgrubmods -lgrubgcry -lgrubkern -lgnu -lfuse)
target_include_directories (grub-mount BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/)
target_link_directories (grub-mount BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/.lib)
set_target_properties (grub-mount PROPERTIES OUTPUT_NAME "${CMAKE_BINARY_DIR}/grub-mount")
target_compile_definitions (grub-mount PUBLIC -DGRUB_FILE=\"util/grub-mount.c\")
