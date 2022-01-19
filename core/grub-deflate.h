#ifndef GRUB_DEFLATE_H
#define GRUB_DEFLATE_H

grub_ssize_t
grub_zlib_decompress (char *inbuf, grub_size_t insize, grub_off_t off,
		      char *outbuf, grub_size_t outsize);

grub_ssize_t
grub_deflate_decompress (char *inbuf, grub_size_t insize, grub_off_t off,
			 char *outbuf, grub_size_t outsize);

#endif
