FILE (GLOB LIB_GRUBKERN_SRC
    ${CMAKE_SOURCE_DIR}/util/misc.c
    ${CMAKE_SOURCE_DIR}/grub-core/kern/command.c
    ${CMAKE_SOURCE_DIR}/grub-core/kern/device.c
    ${CMAKE_SOURCE_DIR}/grub-core/kern/disk.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/disk.c
    ${CMAKE_SOURCE_DIR}/util/getroot.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/unix/getroot.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/getroot.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/devmapper/getroot.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/relpath.c
    ${CMAKE_SOURCE_DIR}/grub-core/kern/emu/hostdisk.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/devmapper/hostdisk.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/hostdisk.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/unix/hostdisk.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/exec.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/sleep.c
    ${CMAKE_SOURCE_DIR}/grub-core/osdep/password.c
    ${CMAKE_SOURCE_DIR}/grub-core/kern/emu/misc.c
    ${CMAKE_SOURCE_DIR}/grub-core/kern/emu/mm.c
    ${CMAKE_SOURCE_DIR}/grub-core/kern/env.c
    ${CMAKE_SOURCE_DIR}/grub-core/kern/err.c
    ${CMAKE_SOURCE_DIR}/grub-core/kern/file.c
    ${CMAKE_SOURCE_DIR}/grub-core/kern/fs.c
    ${CMAKE_SOURCE_DIR}/grub-core/kern/list.c
    ${CMAKE_SOURCE_DIR}/grub-core/kern/misc.c
    ${CMAKE_SOURCE_DIR}/grub-core/kern/partition.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/crypto.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/json/json.c
    ${CMAKE_SOURCE_DIR}/grub-core/disk/luks.c
    ${CMAKE_SOURCE_DIR}/grub-core/disk/luks2.c
    ${CMAKE_SOURCE_DIR}/grub-core/disk/geli.c
    ${CMAKE_SOURCE_DIR}/grub-core/disk/cryptodisk.c
    ${CMAKE_SOURCE_DIR}/grub-core/disk/AFSplitter.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/pbkdf2.c
    ${CMAKE_SOURCE_DIR}/grub-core/commands/extcmd.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/arg.c
    ${CMAKE_SOURCE_DIR}/grub-core/disk/ldm.c
    ${CMAKE_SOURCE_DIR}/grub-core/disk/diskfilter.c
    ${CMAKE_SOURCE_DIR}/grub-core/partmap/gpt.c
    ${CMAKE_SOURCE_DIR}/grub-core/partmap/msdos.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/proc.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/archelp.c
    )
source_group (libgrubkern STATIC ${LIB_GRUBKERN_SRC})

SET (INDEX 0)
foreach (f ${LIB_GRUBKERN_SRC})
    string (REPLACE "${CMAKE_SOURCE_DIR}/" "_" f1 ${f})
    string (REGEX REPLACE "(/|\\.c)" "_" keyt "${f1}")                              # key
    string (REPLACE "${CMAKE_SOURCE_DIR}" "${CMAKE_BINARY_DIR}" val1t "${f}")       # 目标 .o 路径
    string (REPLACE "${CMAKE_SOURCE_DIR}/" " " val2t "${f}")

    MATH (EXPR key "${key}+1")
    string (REPLACE ".c" ".o" val1 "${val1t}")
    string (STRIP ${val2t} val2)

    set ("1_kern${key}" ${val1})
    set ("2_kern${key}" ${val2})
    set ("3_kern${key}" ${f})

    list (APPEND LIB_GRUBKERN_SRC_KEY "kern${key}")
endforeach ()

exec_program (rm ARGS -rf "${CMAKE_BINARY_DIR}/.libgrubkern/")
exec_program (mkdir ARGS "${CMAKE_BINARY_DIR}/.libgrubkern/")

foreach (f ${LIB_GRUBKERN_SRC_KEY})
    add_custom_target ("${f}" ALL
        COMMAND ${CMAKE_C_COMPILER} -std=gnu99
        -DGRUB_UTIL=1
        -DHAVE_CONFIG_H
        -DGRUB_FILE=\\\"${2_${f}}\\\"
        -D_FILE_OFFSET_BITS=64
        -DMINILZO_HAVE_CONFIG_H
        -I.
        -I${CMAKE_SOURCE_DIR}
        -I${CMAKE_SOURCE_DIR}/include
        -I${CMAKE_SOURCE_DIR}/grub-core/lib/libgcrypt-grub/src/
        -I${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib
        -I${CMAKE_SOURCE_DIR}/grub-core/lib/json
        -c ${3_${f}}
        -o "${CMAKE_BINARY_DIR}/.libgrubkern/${f}.o"
        )
endforeach ()

add_custom_command (OUTPUT ${CMAKE_SOURCE_DIR}/.lib/libgrubkern.a COMMAND ${CMAKE_AR} rcv "${CMAKE_SOURCE_DIR}/.lib/libgrubkern.a" "*.o" WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/.libgrubkern")
add_custom_target (grubkern ALL COMMAND ranlib ${CMAKE_SOURCE_DIR}/.lib/libgrubkern.a DEPENDS ${CMAKE_SOURCE_DIR}/.lib/libgrubkern.a)
