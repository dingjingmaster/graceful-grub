#ifndef GRUB_DECOMPRESSOR_H
#define GRUB_DECOMPRESSOR_H

void
grub_decompress_core (void *src, void *dst, unsigned long srcsize,
		      unsigned long dstsize);

void
find_scratch (void *src, void *dst, unsigned long srcsize,
	      unsigned long dstsize);

#define GRUB_DECOMPRESSOR_DICT_SIZE (1 << 16)

extern void *grub_decompressor_scratch;

#endif