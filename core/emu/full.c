#include "config.h"
#include "core/grub-dl.h"
#include "core/grub-env.h"
#include "core/grub-kernel.h"
#include "core/grub-misc.h"
#include "core/emu/misc.h"
#include "core/grub-disk.h"

const int grub_no_modules = 1;

void
grub_register_exported_symbols (void)
{
}

grub_err_t
grub_arch_dl_check_header (void *ehdr)
{
  (void) ehdr;
  return GRUB_ERR_BAD_MODULE;
}

grub_err_t
grub_arch_dl_relocate_symbols (grub_dl_t mod, void *ehdr,
			       Elf_Shdr *s, grub_dl_segment_t seg)
{
  (void) mod;
  (void) ehdr;
  (void) s;
  (void) seg;
  return GRUB_ERR_BAD_MODULE;
}

#if !defined (__i386__) && !defined (__x86_64__)
grub_err_t
grub_arch_dl_get_tramp_got_size (const void *ehdr __attribute__ ((unused)),
			         grub_size_t *tramp, grub_size_t *got)
{
  *tramp = 0;
  *got = 0;
  return GRUB_ERR_BAD_MODULE;
}
#endif

#ifdef GRUB_LINKER_HAVE_INIT
void
grub_arch_dl_init_linker (void)
{
}
#endif

