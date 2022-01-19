#ifndef GRUB_ENV_PRIVATE_H
#define GRUB_ENV_PRIVATE_H

#include "core/grub-env.h"

/* The size of the hash table.  */
#define	HASHSZ	13

/* A hashtable for quick lookup of variables.  */
struct grub_env_context
{
  /* A hash table for variables.  */
  struct grub_env_var *vars[HASHSZ];

  /* One level deeper on the stack.  */
  struct grub_env_context *prev;
};

/* This is used for sorting only.  */
struct grub_env_sorted_var
{
  struct grub_env_var *var;
  struct grub_env_sorted_var *next;
};

extern struct grub_env_context *EXPORT_VAR(grub_current_context);

#endif /* ! GRUB_ENV_PRIVATE_HEADER */
