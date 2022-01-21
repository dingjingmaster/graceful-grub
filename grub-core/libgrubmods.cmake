FILE (GLOB LIB_GRUBMODS_SRC
    ${CMAKE_SOURCE_DIR}/grub-core/commands/blocklist.c
    ${CMAKE_SOURCE_DIR}/grub-core/commands/macbless.c
    ${CMAKE_SOURCE_DIR}/grub-core/commands/xnu_uuid.c
    ${CMAKE_SOURCE_DIR}/grub-core/commands/testload.c
    ${CMAKE_SOURCE_DIR}/grub-core/commands/ls.c
    ${CMAKE_SOURCE_DIR}/grub-core/disk/dmraid_nvidia.c
    ${CMAKE_SOURCE_DIR}/grub-core/disk/loopback.c
    ${CMAKE_SOURCE_DIR}/grub-core/disk/lvm.c
    ${CMAKE_SOURCE_DIR}/grub-core/disk/mdraid_linux.c
    ${CMAKE_SOURCE_DIR}/grub-core/disk/mdraid_linux_be.c
    ${CMAKE_SOURCE_DIR}/grub-core/disk/mdraid1x_linux.c
    ${CMAKE_SOURCE_DIR}/grub-core/disk/raid5_recover.c
    ${CMAKE_SOURCE_DIR}/grub-core/disk/raid6_recover.c
    ${CMAKE_SOURCE_DIR}/grub-core/font/font.c
    ${CMAKE_SOURCE_DIR}/grub-core/gfxmenu/font.c
    ${CMAKE_SOURCE_DIR}/grub-core/normal/charset.c
    ${CMAKE_SOURCE_DIR}/grub-core/video/fb/fbblit.c
    ${CMAKE_SOURCE_DIR}/grub-core/video/fb/fbutil.c
    ${CMAKE_SOURCE_DIR}/grub-core/video/fb/fbfill.c
    ${CMAKE_SOURCE_DIR}/grub-core/video/fb/video_fb.c
    ${CMAKE_SOURCE_DIR}/grub-core/video/video.c
    ${CMAKE_SOURCE_DIR}/grub-core/video/capture.c
    ${CMAKE_SOURCE_DIR}/grub-core/video/colors.c
    ${CMAKE_SOURCE_DIR}/grub-core/unidata.c
    ${CMAKE_SOURCE_DIR}/grub-core/io/bufio.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/affs.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/afs.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/bfs.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/btrfs.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/cbfs.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/cpio.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/cpio_be.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/odc.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/newc.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/ext2.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/fat.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/exfat.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/f2fs.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/fshelp.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/hfs.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/hfsplus.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/hfspluscomp.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/iso9660.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/jfs.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/minix.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/minix2.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/minix3.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/minix_be.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/minix2_be.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/minix3_be.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/nilfs2.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/ntfs.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/ntfscomp.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/reiserfs.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/romfs.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/sfs.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/squash4.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/tar.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/udf.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/ufs2.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/ufs.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/ufs_be.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/xfs.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/zfs/zfscrypt.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/zfs/zfs.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/zfs/zfsinfo.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/zfs/zfs_lzjb.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/zfs/zfs_lz4.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/zfs/zfs_sha256.c
    ${CMAKE_SOURCE_DIR}/grub-core/fs/zfs/zfs_fletcher.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/envblk.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/hexdump.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/LzFind.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/LzmaEnc.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/crc.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/adler32.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/crc64.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/datetime.c
    ${CMAKE_SOURCE_DIR}/grub-core/normal/misc.c
    ${CMAKE_SOURCE_DIR}/grub-core/partmap/acorn.c
    ${CMAKE_SOURCE_DIR}/grub-core/partmap/amiga.c
    ${CMAKE_SOURCE_DIR}/grub-core/partmap/apple.c
    ${CMAKE_SOURCE_DIR}/grub-core/partmap/sun.c
    ${CMAKE_SOURCE_DIR}/grub-core/partmap/plan.c
    ${CMAKE_SOURCE_DIR}/grub-core/partmap/dvh.c
    ${CMAKE_SOURCE_DIR}/grub-core/partmap/sunpc.c
    ${CMAKE_SOURCE_DIR}/grub-core/partmap/bsdlabel.c
    ${CMAKE_SOURCE_DIR}/grub-core/partmap/dfly.c
    ${CMAKE_SOURCE_DIR}/grub-core/script/function.c
    ${CMAKE_SOURCE_DIR}/grub-core/script/lexer.c
    ${CMAKE_SOURCE_DIR}/grub-core/script/main.c
    ${CMAKE_SOURCE_DIR}/grub-core/script/script.c
    ${CMAKE_SOURCE_DIR}/grub-core/script/argv.c
    ${CMAKE_SOURCE_DIR}/grub-core/io/gzio.c
    ${CMAKE_SOURCE_DIR}/grub-core/io/xzio.c
    ${CMAKE_SOURCE_DIR}/grub-core/io/lzopio.c
    ${CMAKE_SOURCE_DIR}/grub-core/kern/ia64/dl_helper.c
    ${CMAKE_SOURCE_DIR}/grub-core/kern/arm/dl_helper.c
    ${CMAKE_SOURCE_DIR}/grub-core/kern/arm64/dl_helper.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/minilzo/minilzo.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/xzembed/xz_dec_bcj.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/xzembed/xz_dec_lzma2.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/xzembed/xz_dec_stream.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/zstd/debug.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/zstd/entropy_common.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/zstd/error_private.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/zstd/fse_decompress.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/zstd/huf_decompress.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/zstd/module.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/zstd/xxhash.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/zstd/zstd_common.c
    ${CMAKE_SOURCE_DIR}/grub-core/lib/zstd/zstd_decompress.c
    )
source_group (libgrubmods STATIC ${LIB_GRUBMODS_SRC})

foreach (f ${LIB_GRUBMODS_SRC})
    string (REPLACE "${CMAKE_SOURCE_DIR}/" "_" f1 ${f})
    string (REGEX REPLACE "(/|\\.c)" "_" keyt "${f1}")                              # key
    string (REPLACE "${CMAKE_SOURCE_DIR}" "${CMAKE_BINARY_DIR}" val1t "${f}")       # 目标 .o 路径
    string (REPLACE "${CMAKE_SOURCE_DIR}/" " " val2t "${f}")

    string (HEX key ${keyt})
    string (REPLACE ".c" ".o" val1 "${val1t}")
    string (STRIP ${val2t} val2)

    set ("1_${key}" ${val1})
    set ("2_${key}" ${val2})
    set ("3_${key}" ${f})

    list (APPEND LIB_GRUBMODS_SRC_KEY ${key})
endforeach ()

exec_program (rm ARGS -rf "${CMAKE_BINARY_DIR}/.libgrubmods/")
exec_program (mkdir ARGS "${CMAKE_BINARY_DIR}/.libgrubmods/")

foreach (f ${LIB_GRUBMODS_SRC_KEY})
#    add_library ("${f}" STATIC "${3_${f}}" "${CMAKE_SOURCE_DIR}/grub_script.yy.c")

#    message (STATUS "${CMAKE_C_COMPILER} -std=gnu99
#        -DGRUB_UTIL=1
#        -DHAVE_CONFIG_H
#        -DGRUB_FILE=\\\"${2_${f}}\\\"
#        -D_FILE_OFFSET_BITS=64
#        -I.
#        -I${CMAKE_SOURCE_DIR}
#        -I${CMAKE_SOURCE_DIR}/include
#        -I${CMAKE_SOURCE_DIR}/grub-core/lib/minilzo
#        -I${CMAKE_SOURCE_DIR}/grub-core/lib/xzembed
#        -I${CMAKE_SOURCE_DIR}/grub-core/lib/zstd
#        -I${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib/
#        -c ${3_${f}}
#        -o ${1_${f}}"
#    )

    add_custom_target ("${f}" ALL
        COMMAND ${CMAKE_C_COMPILER} -std=gnu99
        -DGRUB_UTIL=1
        -DHAVE_CONFIG_H
        -DGRUB_FILE=\\\"${2_${f}}\\\"
        -D_FILE_OFFSET_BITS=64
        -DMINILZO_HAVE_CONFIG_H
        -DGRUB_TARGET_CPU=${TARGET_CPU}
        -I.
        -I${CMAKE_SOURCE_DIR}
        -I${CMAKE_SOURCE_DIR}/include
        -I${CMAKE_SOURCE_DIR}/grub-core/lib/zstd
        -I${CMAKE_SOURCE_DIR}/grub-core/lib/gnulib
        -I${CMAKE_SOURCE_DIR}/grub-core/lib/minilzo
        -I${CMAKE_SOURCE_DIR}/grub-core/lib/xzembed
        -I${CMAKE_SOURCE_DIR}/grub-core/lib/libgcrypt-grub/src/
        -c ${3_${f}}
        -o "${CMAKE_BINARY_DIR}/.libgrubmods/${f}.o"
        )

    SET (LIB_GRUBMODS_OBJ "${LIB_GRUBMODS_OBJ} .libgrubmods/${f}.o")
endforeach ()

#FILE (GLOB LIB_GRUBMODS_OBJ ${CMAKE_BINARY_DIR}/.libgrubmods/*.o)

message (STATUS "${LIB_GRUBMODS_OBJ}")

message (STATUS "${CMAKE_AR} rc libgrubmods.a ${LIB_GRUBMODS_OBJ}")
add_custom_target (grubmods ALL COMMAND ${CMAKE_AR} rc "libgrubmods.a" "${LIB_GRUBMODS_OBJ}")
