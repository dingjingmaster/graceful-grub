FILE (GLOB GRUB_FSTEST_SRC
    ${CMAKE_SOURCE_DIR}/util/grub-fstest.c
    ${CMAKE_SOURCE_DIR}/grub-core/kern/emu/hostfs.c
    ${CMAKE_SOURCE_DIR}/grub-core/disk/host.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/init.c
    )
source_group (grub-fstest ${GRUB_FSTEST_SRC})

add_executable(grub-fstest ${GRUB_FSTEST_SRC})
target_link_libraries (grub-fstest -ldevmapper -lgrubmods -lgrubgcry -lgrubkern -lgnu)
target_include_directories (grub-fstest BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/)
target_link_directories (grub-fstest BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/.lib)
set_target_properties (grub-fstest PROPERTIES OUTPUT_NAME "${CMAKE_BINARY_DIR}/grub-fstest")
target_compile_definitions (grub-fstest PUBLIC -DGRUB_FILE=\"util/grub-fstest.c\")
