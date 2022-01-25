FILE (GLOB LIB_GRUBGCRY_SRC
    ${CMAKE_SOURCE_DIR}/grub-core/lib/libgcrypt-grub/cipher/arcfour.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/libgcrypt-grub/cipher/blowfish.c

    ${CMAKE_SOURCE_DIR}/grub-core/lib/libgcrypt-grub/cipher/camellia-glue.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/libgcrypt-grub/cipher/camellia.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/libgcrypt-grub/cipher/cast5.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/libgcrypt-grub/cipher/crc.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/libgcrypt-grub/cipher/des.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/libgcrypt-grub/cipher/idea.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/libgcrypt-grub/cipher/md4.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/libgcrypt-grub/cipher/md5.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/libgcrypt-grub/cipher/rfc2268.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/libgcrypt-grub/cipher/rijndael.c

    ${CMAKE_SOURCE_DIR}/grub-core/lib/libgcrypt-grub/cipher/rmd160.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/libgcrypt-grub/cipher/seed.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/libgcrypt-grub/cipher/serpent.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/libgcrypt-grub/cipher/sha1.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/libgcrypt-grub/cipher/sha256.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/libgcrypt-grub/cipher/sha512.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/libgcrypt-grub/cipher/tiger.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/libgcrypt-grub/cipher/twofish.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/libgcrypt-grub/cipher/whirlpool.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/libgcrypt-grub/cipher/init.c
    )
source_group (libgrubgcry STATIC ${LIB_GRUBGCRY_SRC})

SET (INDEX 0)
foreach (f ${LIB_GRUBGCRY_SRC})
    string (REPLACE "${CMAKE_SOURCE_DIR}/" "_" f1 ${f})
    string (REGEX REPLACE "(/|\\.c)" "_" keyt "${f1}")                              # key
    string (REPLACE "${CMAKE_SOURCE_DIR}" "${CMAKE_BINARY_DIR}" val1t "${f}")       # 目标 .o 路径
    string (REPLACE "${CMAKE_SOURCE_DIR}/" " " val2t "${f}")

    MATH (EXPR key "${key}+1")
    string (REPLACE ".c" ".o" val1 "${val1t}")
    string (STRIP ${val2t} val2)

    set ("1_gcy${key}" ${val1})
    set ("2_gcy${key}" ${val2})
    set ("3_gcy${key}" ${f})

    list (APPEND LIB_GRUBGCRY_SRC_KEY "gcy${key}")
endforeach ()

exec_program (rm ARGS -rf "${CMAKE_BINARY_DIR}/.libgrubgcry/")
exec_program (mkdir ARGS "${CMAKE_BINARY_DIR}/.libgrubgcry/")

foreach (f ${LIB_GRUBGCRY_SRC_KEY})
    add_custom_target ("${f}" ALL
        COMMAND ${CMAKE_C_COMPILER} -std=gnu99
        -DGRUB_UTIL=1
        -DHAVE_CONFIG_H
        -DGRUB_FILE=\\\"${2_${f}}\\\"
        -D_FILE_OFFSET_BITS=64
        -D_GCRYPT_IN_LIBGCRYPT=1
        -DMINILZO_HAVE_CONFIG_H
        -I${CMAKE_SOURCE_DIR}
        -I${CMAKE_SOURCE_DIR}/include
        -I${CMAKE_SOURCE_DIR}/grub-core/lib/libgcrypt-grub/src/
        -I${CMAKE_SOURCE_DIR}/grub-core/lib/libgcrypt_wrap
        -I${CMAKE_SOURCE_DIR}/grub-core/lib/posix_wrap
        -I${CMAKE_SOURCE_DIR}/include/grub/gcrypt
        -c ${3_${f}}
        -o "${CMAKE_BINARY_DIR}/.libgrubgcry/${f}.o"
        )
endforeach ()

add_custom_command (OUTPUT ${CMAKE_SOURCE_DIR}/.lib/libgrubgcry.a COMMAND ${CMAKE_AR} rcv "${CMAKE_SOURCE_DIR}/.lib/libgrubgcry.a" "*.o" WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/.libgrubgcry")
add_custom_target (grubgcry ALL COMMAND ranlib ${CMAKE_SOURCE_DIR}/.lib/libgrubgcry.a DEPENDS ${CMAKE_SOURCE_DIR}/.lib/libgrubgcry.a)
