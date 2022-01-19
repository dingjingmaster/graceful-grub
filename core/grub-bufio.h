#ifndef GRUB_BUFIO_H
#define GRUB_BUFIO_H

#include "grub-file.h"

grub_file_t EXPORT_FUNC (grub_bufio_open) (grub_file_t io, grub_size_t size);
grub_file_t EXPORT_FUNC (grub_buffile_open) (const char *name,
					     enum grub_file_type type,
					     grub_size_t size);

#endif /* ! GRUB_BUFIO_H */
