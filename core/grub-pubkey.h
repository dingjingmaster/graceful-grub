#ifndef GRUB_PUBKEY_H
#define GRUB_PUBKEY_H

#include "core/grub-file.h"
#include "core/grub-crypto.h"

struct grub_public_key *
grub_load_public_key (grub_file_t f);

grub_err_t
grub_verify_signature (grub_file_t f, const char *fsig,
		       struct grub_public_key *pk);


struct grub_public_subkey *
grub_crypto_pk_locate_subkey (grub_uint64_t keyid, struct grub_public_key *pkey);

struct grub_public_subkey *
grub_crypto_pk_locate_subkey_in_trustdb (grub_uint64_t keyid);

#endif
