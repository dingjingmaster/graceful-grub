FILE (GLOB GRUB_PROBE_SRC
    ${CMAKE_SOURCE_DIR}/util/grub-probe.c
    ${CMAKE_SOURCE_DIR}/util/probe.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/ofpath.c
    ${CMAKE_SOURCE_DIR}/grub-core/kern/emu/argp_common.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/init.c
    )
source_group (grub-probe ${GRUB_PROBE_SRC})

add_executable(grub-probe ${GRUB_PROBE_SRC})
target_link_libraries (grub-probe
    ${CMAKE_SOURCE_DIR}/.lib/libgrubmods.a
    -ldevmapper -lgrubmods -lgrubgcry -lgrubkern -lgnu)
target_include_directories (grub-probe BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/)
target_link_directories (grub-probe BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/.lib)
set_target_properties (grub-probe PROPERTIES OUTPUT_NAME "${CMAKE_BINARY_DIR}/grub-probe")
target_compile_definitions (grub-probe PUBLIC -DGRUB_FILE=\"util/grub-probe.c\")
