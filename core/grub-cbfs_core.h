#ifndef _CBFS_CORE_H_
#define _CBFS_CORE_H_

#include "core/grub-types.h"

/** These are standard values for the known compression
    alogrithms that coreboot knows about for stages and
    payloads.  Of course, other CBFS users can use whatever
    values they want, as long as they understand them. */

#define CBFS_COMPRESS_NONE  0
#define CBFS_COMPRESS_LZMA  1

/** These are standard component types for well known
    components (i.e - those that coreboot needs to consume.
    Users are welcome to use any other value for their
    components */

#define CBFS_TYPE_STAGE      0x10
#define CBFS_TYPE_PAYLOAD    0x20
#define CBFS_TYPE_OPTIONROM  0x30
#define CBFS_TYPE_BOOTSPLASH 0x40
#define CBFS_TYPE_RAW        0x50
#define CBFS_TYPE_VSA        0x51
#define CBFS_TYPE_MBI        0x52
#define CBFS_TYPE_MICROCODE  0x53
#define CBFS_COMPONENT_CMOS_DEFAULT 0xaa
#define CBFS_COMPONENT_CMOS_LAYOUT 0x01aa

#define CBFS_HEADER_MAGIC  0x4F524243
#define CBFS_HEADER_VERSION1 0x31313131
#define CBFS_HEADER_VERSION2 0x31313132
#define CBFS_HEADER_VERSION  CBFS_HEADER_VERSION2

#define CBFS_HEADER_INVALID_ADDRESS	((void*)(0xffffffff))

/** this is the master cbfs header - it need to be located somewhere available
    to bootblock (to load romstage).  Where it actually lives is up to coreboot.
    On x86, a pointer to this header will live at 0xFFFFFFFC.
    For other platforms, you need to define CONFIG_CBFS_HEADER_ROM_OFFSET */

struct cbfs_header {
	grub_uint32_t magic;
	grub_uint32_t version;
	grub_uint32_t romsize;
	grub_uint32_t bootblocksize;
	grub_uint32_t align;
	grub_uint32_t offset;
	grub_uint32_t architecture;
	grub_uint32_t pad[1];
} GRUB_PACKED;

/* "Unknown" refers to CBFS headers version 1,
 * before the architecture was defined (i.e., x86 only).
 */
#define CBFS_ARCHITECTURE_UNKNOWN  0xFFFFFFFF
#define CBFS_ARCHITECTURE_X86      0x00000001
#define CBFS_ARCHITECTURE_ARMV7    0x00000010

/** This is a component header - every entry in the CBFS
    will have this header.

    This is how the component is arranged in the ROM:

    --------------   <- 0
    component header
    --------------   <- sizeof(struct component)
    component name
    --------------   <- offset
    data
    ...
    --------------   <- offset + len
*/

#define CBFS_FILE_MAGIC "LARCHIVE"

struct cbfs_file {
	char magic[8];
	grub_uint32_t len;
	grub_uint32_t type;
	grub_uint32_t checksum;
	grub_uint32_t offset;
} GRUB_PACKED;

/*** Component sub-headers ***/

/* Following are component sub-headers for the "standard"
   component types */

/** This is the sub-header for stage components.  Stages are
    loaded by coreboot during the normal boot process */

struct cbfs_stage {
	grub_uint32_t compression;  /** Compression type */
	grub_uint64_t entry;  /** entry point */
	grub_uint64_t load;   /** Where to load in memory */
	grub_uint32_t len;          /** length of data to load */
	grub_uint32_t memlen;	   /** total length of object in memory */
} GRUB_PACKED;

/** this is the sub-header for payload components.  Payloads
    are loaded by coreboot at the end of the boot process */

struct cbfs_payload_segment {
	grub_uint32_t type;
	grub_uint32_t compression;
	grub_uint32_t offset;
	grub_uint64_t load_addr;
	grub_uint32_t len;
	grub_uint32_t mem_len;
} GRUB_PACKED;

struct cbfs_payload {
	struct cbfs_payload_segment segments;
};

#define PAYLOAD_SEGMENT_CODE   0x45444F43
#define PAYLOAD_SEGMENT_DATA   0x41544144
#define PAYLOAD_SEGMENT_BSS    0x20535342
#define PAYLOAD_SEGMENT_PARAMS 0x41524150
#define PAYLOAD_SEGMENT_ENTRY  0x52544E45

struct cbfs_optionrom {
	grub_uint32_t compression;
	grub_uint32_t len;
} GRUB_PACKED;

#endif
