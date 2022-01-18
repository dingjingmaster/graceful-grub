#ifndef GRUB_AUTH_H
#define GRUB_AUTH_H

#include "grub-err.h"
#include "grub-crypto.h"

#define GRUB_AUTH_MAX_PASSLEN 1024

typedef grub_err_t (*grub_auth_callback_t) (const char *, const char *, void *);

grub_err_t grub_auth_register_authentication (const char *user,
					      grub_auth_callback_t callback,
					      void *arg);
grub_err_t grub_auth_unregister_authentication (const char *user);

grub_err_t grub_auth_authenticate (const char *user);
grub_err_t grub_auth_deauthenticate (const char *user);
grub_err_t grub_auth_check_authentication (const char *userlist);

#endif /* ! GRUB_AUTH_HEADER */
