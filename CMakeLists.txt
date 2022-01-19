project (graceful-grub)
cmake_minimum_required (VERSION 3.5)

set (CMAKE_C_STANDARD 99)
set (CMAKE_INCLUDE_CURRENT_DIR ON)
set (CMAKE_INCLUDE_CURRENT_DIR YES)
set (CMAKE_INCLUDE_DIRECTORIES_BEFORE ON)

set (CMAKE_PROJECT_VERSION_MAJOR 0)
set (CMAKE_PROJECT_VERSION_MINOR 0)
set (CMAKE_PROJECT_VERSION_PATCH 0)
set (CMAKE_PROJECT_VERSION "${CMAKE_PROJECT_VERSION_MAJOR}.${CMAKE_PROJECT_VERSION_MINOR}.${CMAKE_PROJECT_VERSION_PATCH}")

set (TARGET_NAME "graceful-grub")
set (LIB_CORE_NAME "graceful-grub" CACHE STRING "graceful-grub")

include_directories (${CMAKE_CURRENT_SOURCE_DIR})

add_definitions (
    -DGRUB_TARGET_CPU=\"i386\"
    -DGRUB_FILE=\"TTT\"                             # 此处可能是调试信息输出文件的名字
    -D_FILE_OFFSET_BITS=64
#    -DGRUB_UTIL=1
    -DGRUB_MACHINE=I386_PC
#    -DGRUB_MACHINE_PCBIOS=1

# fixme:// dj-
    -DGRUB_KERNEL_PRELOAD_SPACE_REUSABLE
    )

add_subdirectory (core)
add_subdirectory (utils)

