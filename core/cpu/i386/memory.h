
#ifndef GRUB_MEMORY_CPU_HEADER
#define GRUB_MEMORY_CPU_HEADER	1

#define PAGE_SHIFT		12

/* The flag for protected mode.  */
#define GRUB_MEMORY_CPU_CR0_PE_ON		0x1
#define GRUB_MEMORY_CPU_CR4_PAE_ON		0x00000020
#define GRUB_MEMORY_CPU_CR4_PSE_ON		0x00000010
#define GRUB_MEMORY_CPU_CR0_PAGING_ON		0x80000000
#define GRUB_MEMORY_CPU_AMD64_MSR		0xc0000080
#define GRUB_MEMORY_CPU_AMD64_MSR_ON		0x00000100

#define GRUB_MEMORY_MACHINE_UPPER_START			0x100000	/* 1 MiB */
#define GRUB_MEMORY_MACHINE_LOWER_SIZE			GRUB_MEMORY_MACHINE_UPPER_START

/* Some PTE definitions. */
#define GRUB_PAGE_PRESENT			0x00000001
#define GRUB_PAGE_RW				0x00000002
#define GRUB_PAGE_USER				0x00000004

#ifndef ASM_FILE

#define GRUB_MMAP_MALLOC_LOW 1

#include "core/grub-types.h"

struct grub_e820_mmap_entry
{
  grub_uint64_t addr;
  grub_uint64_t len;
  grub_uint32_t type;
} GRUB_PACKED;

grub_uint64_t grub_mmap_get_upper (void);
grub_uint64_t grub_mmap_get_lower (void);
grub_uint64_t grub_mmap_get_post64 (void);

typedef grub_addr_t grub_phys_addr_t;

static inline grub_phys_addr_t
grub_vtop (void *a)
{
  return (grub_phys_addr_t) a;
}

static inline void *
grub_map_memory (grub_phys_addr_t a, grub_size_t size __attribute__ ((unused)))
{
  return (void *) a;
}

static inline void
grub_unmap_memory (void *a __attribute__ ((unused)),
		   grub_size_t size __attribute__ ((unused)))
{
}

#endif

#endif /* ! GRUB_MEMORY_CPU_HEADER */
