FILE (GLOB GRUB_MKPASSWD_PBKDF2_SRC
    ${CMAKE_SOURCE_DIR}/util/grub-mkpasswd-pbkdf2.c
    ${CMAKE_SOURCE_DIR}/grub-core/kern/emu/argp_common.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/random.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/init.c
    )
source_group (grub-mkpasswd-pbkdf2 ${GRUB_MKPASSWD_PBKDF2_SRC})

add_executable(grub-mkpasswd-pbkdf2 ${GRUB_MKPASSWD_PBKDF2_SRC})
target_link_libraries (grub-mkpasswd-pbkdf2 -ldevmapper -lgrubmods -lgrubgcry -lgrubkern -lgnu)
target_include_directories (grub-mkpasswd-pbkdf2 BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/)
target_link_directories (grub-mkpasswd-pbkdf2 BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/.lib)
set_target_properties (grub-mkpasswd-pbkdf2 PROPERTIES OUTPUT_NAME "${CMAKE_BINARY_DIR}/grub-mkpasswd-pbkdf2")
target_compile_definitions (grub-mkpasswd-pbkdf2 PUBLIC -DGRUB_FILE=\"util/grub-mkpasswd-pbkdf2.c\")
