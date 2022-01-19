project (utils)


add_executable(grub-install grub-install.c)
target_link_libraries (grub-install ${LIB_CORE_NAME} -ldevmapper)
set_target_properties (grub-install PROPERTIES OUTPUT_NAME "${CMAKE_BINARY_DIR}/grub-install")
