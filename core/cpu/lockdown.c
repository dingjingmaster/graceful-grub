#include "core/grub-dl.h"
#include "core/grub-env.h"
#include "core/grub-file.h"
#include "core/grub-lockdown.h"
#include "core/grub-verify.h"

static int lockdown = GRUB_LOCKDOWN_DISABLED;

static grub_err_t
lockdown_verifier_init (grub_file_t io __attribute__ ((unused)),
                    enum grub_file_type type,
                    void **context __attribute__ ((unused)),
                    enum grub_verify_flags *flags)
{
  *flags = GRUB_VERIFY_FLAGS_SKIP_VERIFICATION;

  switch (type & GRUB_FILE_TYPE_MASK)
    {
    case GRUB_FILE_TYPE_GRUB_MODULE:
    case GRUB_FILE_TYPE_LINUX_KERNEL:
    case GRUB_FILE_TYPE_MULTIBOOT_KERNEL:
    case GRUB_FILE_TYPE_XEN_HYPERVISOR:
    case GRUB_FILE_TYPE_BSD_KERNEL:
    case GRUB_FILE_TYPE_XNU_KERNEL:
    case GRUB_FILE_TYPE_PLAN9_KERNEL:
    case GRUB_FILE_TYPE_NTLDR:
    case GRUB_FILE_TYPE_TRUECRYPT:
    case GRUB_FILE_TYPE_FREEDOS:
    case GRUB_FILE_TYPE_PXECHAINLOADER:
    case GRUB_FILE_TYPE_PCCHAINLOADER:
    case GRUB_FILE_TYPE_COREBOOT_CHAINLOADER:
    case GRUB_FILE_TYPE_EFI_CHAINLOADED_IMAGE:
    case GRUB_FILE_TYPE_ACPI_TABLE:
    case GRUB_FILE_TYPE_DEVICE_TREE_IMAGE:
      *flags = GRUB_VERIFY_FLAGS_DEFER_AUTH;

      /* Fall through. */

    default:
      return GRUB_ERR_NONE;
    }
}

struct grub_file_verifier lockdown_verifier =
  {
    .name = "lockdown_verifier",
    .init = lockdown_verifier_init,
  };

void
grub_lockdown (void)
{
  lockdown = GRUB_LOCKDOWN_ENABLED;

  grub_verifier_register (&lockdown_verifier);

  grub_env_set ("lockdown", "y");
  grub_env_export ("lockdown");
}

int
grub_is_lockdown (void)
{
  return lockdown;
}
