#ifndef GRUB_LEGACY_PARSE_H
#define GRUB_LEGACY_PARSE_H

#include "grub-types.h"

char *grub_legacy_parse (const char *buf, char **entryname, char **suffix);
char *grub_legacy_escape (const char *in, grub_size_t len);

/* Entered has to be GRUB_AUTH_MAX_PASSLEN long, zero-padded.  */
int
grub_legacy_check_md5_password (int argc, char **args,
				char *entered);

#endif
