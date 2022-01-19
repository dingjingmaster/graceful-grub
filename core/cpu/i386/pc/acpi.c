#include "core/grub-acpi.h"
#include "core/grub-misc.h"

struct grub_acpi_rsdp_v10 *
grub_machine_acpi_get_rsdpv1 (void)
{
  int ebda_len;
  grub_uint8_t *ebda, *ptr;

  grub_dprintf ("acpi", "Looking for RSDP. Scanning EBDA\n");
  ebda = (grub_uint8_t *) ((* ((grub_uint16_t *) 0x40e)) << 4);
  ebda_len = * (grub_uint16_t *) ebda;
  if (! ebda_len) /* FIXME do we really need this check? */
    goto scan_bios;
  for (ptr = ebda; ptr < ebda + 0x400; ptr += 16)
    if (grub_memcmp (ptr, GRUB_RSDP_SIGNATURE, GRUB_RSDP_SIGNATURE_SIZE) == 0
	&& grub_byte_checksum (ptr, sizeof (struct grub_acpi_rsdp_v10)) == 0
	&& ((struct grub_acpi_rsdp_v10 *) ptr)->revision == 0)
      return (struct grub_acpi_rsdp_v10 *) ptr;

scan_bios:
  grub_dprintf ("acpi", "Looking for RSDP. Scanning BIOS\n");
  for (ptr = (grub_uint8_t *) 0xe0000; ptr < (grub_uint8_t *) 0x100000;
       ptr += 16)
    if (grub_memcmp (ptr, GRUB_RSDP_SIGNATURE, GRUB_RSDP_SIGNATURE_SIZE) == 0
	&& grub_byte_checksum (ptr, sizeof (struct grub_acpi_rsdp_v10)) == 0
	&& ((struct grub_acpi_rsdp_v10 *) ptr)->revision == 0)
      return (struct grub_acpi_rsdp_v10 *) ptr;
  return 0;
}

struct grub_acpi_rsdp_v20 *
grub_machine_acpi_get_rsdpv2 (void)
{
  int ebda_len;
  grub_uint8_t *ebda, *ptr;

  grub_dprintf ("acpi", "Looking for RSDP. Scanning EBDA\n");
  ebda = (grub_uint8_t *) ((* ((grub_uint16_t *) 0x40e)) << 4);
  ebda_len = * (grub_uint16_t *) ebda;
  if (! ebda_len) /* FIXME do we really need this check? */
    goto scan_bios;
  for (ptr = ebda; ptr < ebda + 0x400; ptr += 16)
    if (grub_memcmp (ptr, GRUB_RSDP_SIGNATURE, GRUB_RSDP_SIGNATURE_SIZE) == 0
	&& grub_byte_checksum (ptr, sizeof (struct grub_acpi_rsdp_v10)) == 0
	&& ((struct grub_acpi_rsdp_v10 *) ptr)->revision != 0
	&& ((struct grub_acpi_rsdp_v20 *) ptr)->length < 1024
	&& grub_byte_checksum (ptr, ((struct grub_acpi_rsdp_v20 *) ptr)->length)
	== 0)
      return (struct grub_acpi_rsdp_v20 *) ptr;

scan_bios:
  grub_dprintf ("acpi", "Looking for RSDP. Scanning BIOS\n");
  for (ptr = (grub_uint8_t *) 0xe0000; ptr < (grub_uint8_t *) 0x100000;
       ptr += 16)
    if (grub_memcmp (ptr, GRUB_RSDP_SIGNATURE, GRUB_RSDP_SIGNATURE_SIZE) == 0
	&& grub_byte_checksum (ptr, sizeof (struct grub_acpi_rsdp_v10)) == 0
	&& ((struct grub_acpi_rsdp_v10 *) ptr)->revision != 0
	&& ((struct grub_acpi_rsdp_v20 *) ptr)->length < 1024
	&& grub_byte_checksum (ptr, ((struct grub_acpi_rsdp_v20 *) ptr)->length)
	== 0)
      return (struct grub_acpi_rsdp_v20 *) ptr;
  return 0;
}
