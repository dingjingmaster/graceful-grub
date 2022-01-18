#include "core/emu/exec.h"
#include "core/util/install.h"

int 
grub_install_compress_gzip (const char *src, const char *dest)
{
  return grub_util_exec_redirect ((const char * []) { "gzip", "--best",
	"--stdout", NULL }, src, dest);
}

int 
grub_install_compress_xz (const char *src, const char *dest)
{
  return grub_util_exec_redirect ((const char * []) { "xz",
	"--lzma2=dict=128KiB", "--check=none", "--stdout", NULL }, src, dest);
}

int 
grub_install_compress_lzop (const char *src, const char *dest)
{
  return grub_util_exec_redirect ((const char * []) { "lzop", "-9",  "-c",
	NULL }, src, dest);
}
