FILE (GLOB LIB_GRUBGNU_SRC
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/argp-ba.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/argp-eexst.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/argp-fmtstream.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/argp-fs-xinl.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/argp-help.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/argp-parse.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/argp-pin.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/argp-pv.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/argp-pvh.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/argp-xinl.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/base64.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/cloexec.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/dirname-lgpl.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/basename-lgpl.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/stripslash.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/exitfail.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/fd-hook.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/fd-safer-flag.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/dup-safer-flag.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/filenamecat-lgpl.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/getprogname.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/hard-locale.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/localcharset.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/glthread/lock.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/malloca.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/mbswidth.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/openat-die.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/progname.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/save-cwd.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/stat-time.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/strnlen1.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/glthread/threadlib.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/unistd.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/dup-safer.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/fd-safer.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/pipe-safer.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/uniwidth/width.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/wctype-h.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/xsize.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/asnprintf.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/chdir-long.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/fcntl.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/getopt.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/getopt1.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/mbrtowc.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/openat-proc.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/printf-args.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/printf-parse.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/regex.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/vasnprintf.c
    )
source_group (libgnu STATIC ${LIB_GRUBGNU_SRC})

SET (INDEX 0)
foreach (f ${LIB_GRUBGNU_SRC})
    string (REPLACE "${CMAKE_SOURCE_DIR}/" "_" f1 ${f})
    string (REGEX REPLACE "(/|\\.c)" "_" keyt "${f1}")                              # key
    string (REPLACE "${CMAKE_SOURCE_DIR}" "${CMAKE_BINARY_DIR}" val1t "${f}")       # 目标 .o 路径
    string (REPLACE "${CMAKE_SOURCE_DIR}/" " " val2t "${f}")

    MATH (EXPR key "${key}+1")
    string (REPLACE ".c" ".o" val1 "${val1t}")
    string (STRIP ${val2t} val2)

    set ("1_gnu${key}" ${val1})
    set ("2_gnu${key}" ${val2})
    set ("3_gnu${key}" ${f})

    list (APPEND LIB_GRUBGNU_SRC_KEY "gnu${key}")
endforeach ()

exec_program (rm ARGS -rf "${CMAKE_BINARY_DIR}/.libgnu/")
exec_program (mkdir ARGS "${CMAKE_BINARY_DIR}/.libgnu/")

foreach (f ${LIB_GRUBGNU_SRC_KEY})
    add_custom_target ("${f}" ALL
        COMMAND ${CMAKE_C_COMPILER} -std=gnu99
        -DHAVE_CONFIG_H
        -D_FILE_OFFSET_BITS=64
        -I${CMAKE_SOURCE_DIR}
        -I${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib
        -c ${3_${f}}
        -o "${CMAKE_BINARY_DIR}/.libgnu/${f}.o"
        )
endforeach ()

add_custom_command (OUTPUT ${CMAKE_SOURCE_DIR}/.lib/libgnu.a COMMAND ${CMAKE_AR} rcv "${CMAKE_SOURCE_DIR}/.lib/libgnu.a" "*.o" WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/.libgnu")
add_custom_target (gnu ALL COMMAND ranlib ${CMAKE_SOURCE_DIR}/.lib/libgnu.a DEPENDS ${CMAKE_SOURCE_DIR}/.lib/libgnu.a)
