project (graceful-grub)
cmake_minimum_required (VERSION 3.5)

set (CMAKE_C_STANDARD 99)
set (CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_INCLUDE_CURRENT_DIR ON)
set (CMAKE_INCLUDE_CURRENT_DIR YES)
set (CMAKE_INCLUDE_DIRECTORIES_BEFORE ON)

set (CMAKE_PROJECT_VERSION_MAJOR 0)
set (CMAKE_PROJECT_VERSION_MINOR 0)
set (CMAKE_PROJECT_VERSION_PATCH 0)
set (CMAKE_PROJECT_VERSION "${CMAKE_PROJECT_VERSION_MAJOR}.${CMAKE_PROJECT_VERSION_MINOR}.${CMAKE_PROJECT_VERSION_PATCH}")

#set (TARGET_NAME "graceful-grub")
#set (LIB_CORE_NAME "graceful-grub" CACHE STRING "graceful-grub")

include_directories (${CMAKE_CURRENT_SOURCE_DIR})
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/include)

# 检查 gnulib 是否 ok
if (NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/grub-core/lib/gnulib/stdlib.in.h")
    message (FATAL_ERROR "Gnulib not yet bootstrapped; run:
        cd ${CMAKE_CURRENT_SOURCE_DIR} && ./bootstrap instead.")
endif()

# 检查 python 是否 ok
set (PYTHON_BIN python3 python)
foreach (p ${PYTHON_BIN})
    exec_program (command ARGS -v ${p} OUTPUT_VARIABLE PYTHON_VERSION)
    if (EXISTS ${PYTHON_VERSION})
        MESSAGE (STATUS "Found ${p} -- ${PYTHON_VERSION}")
        set (PYTHON ${PYTHON_VERSION})
        break ()
    endif ()
endforeach ()
if (NOT EXISTS ${PYTHON})
    message (FATAL_ERROR "Unable to find Python executable command!")
endif()

# unicode ...
message (STATUS "Importing unicode...")
exec_program (${PYTHON} ARGS ${CMAKE_CURRENT_SOURCE_DIR}/util/import_unicode.py ${CMAKE_CURRENT_SOURCE_DIR}/unicode/UnicodeData.txt ${CMAKE_CURRENT_SOURCE_DIR}/unicode/BidiMirroring.txt ${CMAKE_CURRENT_SOURCE_DIR}/unicode/ArabicShaping.txt ${CMAKE_CURRENT_SOURCE_DIR}/grub-core/unidata.c RETURN_VALUE RET)
if (NOT 0 EQUAL ${RET})
    message (FATAL_ERROR "error!")
endif()

message (STATUS "Importing libgcrypt...")
execute_process (COMMAND "${PYTHON}" ${CMAKE_CURRENT_SOURCE_DIR}/util/import_gcry.py ${CMAKE_CURRENT_SOURCE_DIR}/grub-core/lib/libgcrypt/ ${CMAKE_CURRENT_SOURCE_DIR}/grub-core WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}" RESULT_VARIABLE RET)
if (NOT 0 EQUAL ${RET})
    message (FATAL_ERROR "error!")
endif()

exec_program (sed ARGS -n -f ${CMAKE_CURRENT_SOURCE_DIR}/util/import_gcrypth.sed
    < ${CMAKE_CURRENT_SOURCE_DIR}/grub-core/lib/libgcrypt/src/gcrypt.h.in
    > ${CMAKE_CURRENT_SOURCE_DIR}/include/grub/gcrypt/gcrypt.h RETURN_VALUE RET)
if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/include/grub/gcrypt/g10lib.h")
    exec_program (rm ARGS "${CMAKE_CURRENT_SOURCE_DIR}/include/grub/gcrypt/g10lib.h")
endif()

if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/grub-core/lib/libgcrypt-grub/mpi/generic")
    exec_program (rm ARGS -rf "${CMAKE_CURRENT_SOURCE_DIR}/grub-core/lib/libgcrypt-grub/mpi/generic")
endif()

exec_program (cp ARGS "${CMAKE_CURRENT_SOURCE_DIR}/grub-core/lib/libgcrypt-grub/src/g10lib.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/grub/gcrypt/g10lib.h")
exec_program (cp ARGS -R "${CMAKE_CURRENT_SOURCE_DIR}/grub-core/lib/libgcrypt/mpi/generic"
    "${CMAKE_CURRENT_SOURCE_DIR}/grub-core/lib/libgcrypt-grub/mpi/generic")

set (TEMP mpi-asm-defs.h mpih-add1.c mpih-sub1.c mpih-mul1.c mpih-mul2.c mpih-mul3.c mpih-lshift.c mpih-rshift.c)
foreach (x in ${TEMP})
    exec_program (test -f "${CMAKE_CURRENT_SOURCE_DIR}/grub-core/lib/libgcrypt-grub/mpi/${x}" RETURN_VALUE RET)
    if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/grub-core/lib/libgcrypt-grub/mpi/${x}")
        exec_program (rm ARGS "${CMAKE_CURRENT_SOURCE_DIR}/grub-core/lib/libgcrypt-grub/mpi/${x}")
    endif ()
    exec_program (cp ARGS "${CMAKE_CURRENT_SOURCE_DIR}/grub-core/lib/libgcrypt-grub/mpi/generic/${x}"
        "${CMAKE_CURRENT_SOURCE_DIR}/grub-core/lib/libgcrypt-grub/mpi/${x}")
endforeach ()

execute_process (COMMAND "${PYTHON}" ${CMAKE_CURRENT_SOURCE_DIR}/util/import_gcry.py ${CMAKE_CURRENT_SOURCE_DIR}/grub-core/lib/libgcrypt/ ${CMAKE_CURRENT_SOURCE_DIR}/grub-core WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}" RESULT_VARIABLE RET)
if (NOT 0 EQUAL ${RET})
    message (FATAL_ERROR "error!")
endif()

execute_process (COMMAND "${PYTHON}" gentpl.py Makefile.util.def Makefile.utilgcry.def OUTPUT_FILE Makefile.util.am WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}" RESULT_VARIABLE RET)
if (NOT 0 EQUAL ${RET})
    message (FATAL_ERROR "error!")
endif()
execute_process (COMMAND "${PYTHON}" gentpl.py grub-core/Makefile.core.def grub-core/Makefile.gcry.def OUTPUT_FILE grub-core/Makefile.core.am  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}" RESULT_VARIABLE RET)
if (NOT 0 EQUAL ${RET})
    message (FATAL_ERROR "error!")
endif()

# AC_CONFIG_AUX_DIR     在指定目录下找脚本
# AC_CANONICAL_HOST     获取系统信息
# AC_CANONICAL_BUILD    跨平台编译支持

## 此处需要自动检测一些关键信息
#set (PLATFORM "pc")
set (TARGET_CPU "i386")
#set (HOST_KERNEL "linux")
#set (MACHINE_CPPFLAGS " -DGRUB_MACHINE_PCBIOS=1")
#set (TARGET_CPPFLAGS "-Wall -W -DGRUB_MACHINE_PCBIOS=1")
#set (HOST_CFLAGS "${HOST_CFLAGS} -fno-builtin-gettext")

# 检查一些命令是否存在
exec_program (command ARGS -v cmp OUTPUT_VARIABLE RET)
if (EXISTS ${RET})
    MESSAGE (STATUS "Found cmp -- ${RET}")
else ()
    MESSAGE (FATAL_ERROR "NOT Found cmp -- ${RET}")
endif ()

exec_program (command ARGS -v bison OUTPUT_VARIABLE RET)
if (EXISTS ${RET})
    MESSAGE (STATUS "Found bison -- ${RET}")
else ()
    MESSAGE (FATAL_ERROR "NOT Found bison -- ${RET}")
endif ()

exec_program (command ARGS -v gcc OUTPUT_VARIABLE RET)
if (EXISTS ${RET})
    MESSAGE (STATUS "Found gcc -- ${RET}")
else ()
    MESSAGE (FATAL_ERROR "NOT Found gcc -- ${RET}")
endif ()

#check_function_exists (posix_memalign memalign getextmntent )
#check_include_files (sys/param.h sys/mount.h sys/mnttab.h limits.h)

# COND_i386_pc
# COND_HOST_LINUX


# 头
add_definitions (
    -DHAVE_CONFIG_H
    -DGRUB_UTIL=1
    -DGRUB_MACHINE=I386_PC
    -DGRUB_TARGET_CPU=\"${TARGET_CPU}\"
    -D_FILE_OFFSET_BITS=64
    )

# 删除旧的库信息
if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/.lib")
    exec_program (rm ARGS -rf "${CMAKE_CURRENT_SOURCE_DIR}/.lib/libgrubmods.a")
    exec_program (rm ARGS -rf "${CMAKE_CURRENT_SOURCE_DIR}/.lib/libgrubgcry.a")
endif()

add_subdirectory (grub-core)
add_subdirectory (tests)
add_subdirectory (util)

