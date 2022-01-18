project (utils)


add_executable(grub-install grub-install.c)
set_target_properties (grub-install PROPERTIES OUTPUT_NAME "${CMAKE_BINARY_DIR}/grub-install")
