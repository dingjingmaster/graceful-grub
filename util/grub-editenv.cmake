FILE (GLOB GRUB_EDITENV_SRC
    ${CMAKE_SOURCE_DIR}/util/grub-editenv.c
    ${CMAKE_SOURCE_DIR}/util/editenv.c
    ${CMAKE_SOURCE_DIR}/util/grub-install-common.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/init.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/compress.c
    ${CMAKE_SOURCE_DIR}/util/mkimage.c
    ${CMAKE_SOURCE_DIR}/util/grub-mkimage32.c
    ${CMAKE_SOURCE_DIR}/util/grub-mkimage64.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/config.c
    ${CMAKE_SOURCE_DIR}/util/config.c
    ${CMAKE_SOURCE_DIR}/util/resolve.c
    )
source_group (grub-editenv ${GRUB_EDITENV_SRC})

add_executable(grub-editenv ${GRUB_EDITENV_SRC})
target_link_libraries (grub-editenv -ldevmapper -lgrubmods -lgrubgcry -lgrubkern -lgnu -llzma)
target_include_directories (grub-editenv BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/)
target_link_directories (grub-editenv BEFORE PUBLIC ${CMAKE_SOURCE_DIR}/.lib)
set_target_properties (grub-editenv PROPERTIES OUTPUT_NAME "${CMAKE_BINARY_DIR}/grub-editenv")
target_compile_definitions (grub-editenv PUBLIC -DGRUB_FILE=\"util/grub-editenv.c\")
