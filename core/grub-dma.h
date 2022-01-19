#ifndef	GRUB_DMA_H
#define	GRUB_DMA_H	1

struct grub_pci_dma_chunk;

struct grub_pci_dma_chunk *EXPORT_FUNC(grub_memalign_dma32) (grub_size_t align,
							     grub_size_t size);
void EXPORT_FUNC(grub_dma_free) (struct grub_pci_dma_chunk *ch);
volatile void *EXPORT_FUNC(grub_dma_get_virt) (struct grub_pci_dma_chunk *ch);
grub_uint32_t EXPORT_FUNC(grub_dma_get_phys) (struct grub_pci_dma_chunk *ch);

static inline void *
grub_dma_phys2virt (grub_uint32_t phys, struct grub_pci_dma_chunk *chunk)
{
  return ((grub_uint8_t *) grub_dma_get_virt (chunk)
	  + (phys - grub_dma_get_phys (chunk)));
}

static inline grub_uint32_t
grub_dma_virt2phys (volatile void *virt, struct grub_pci_dma_chunk *chunk)
{
  return (((grub_uint8_t *) virt - (grub_uint8_t *) grub_dma_get_virt (chunk))
	  + grub_dma_get_phys (chunk));
}

#endif
