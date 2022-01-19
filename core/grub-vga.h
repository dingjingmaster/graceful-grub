#ifndef GRUB_VGA_H
#define GRUB_VGA_H

#ifndef GRUB_MACHINE_MIPS_QEMU_MIPS
#include "core/grub-pci.h"
#else
// FIXME:// DJ-
#include "core/cpu/i386/io.h"
#define GRUB_MACHINE_PCI_IO_BASE  0xb4000000
#endif

#include "core/grub-vgaregs.h"

static inline void
grub_vga_gr_write (grub_uint8_t val, grub_uint8_t addr)
{
  grub_outb (addr, GRUB_MACHINE_PCI_IO_BASE + GRUB_VGA_IO_GR_INDEX);
  grub_outb (val, GRUB_MACHINE_PCI_IO_BASE + GRUB_VGA_IO_GR_DATA);
}

static inline grub_uint8_t
grub_vga_gr_read (grub_uint8_t addr)
{
  grub_outb (addr, GRUB_MACHINE_PCI_IO_BASE + GRUB_VGA_IO_GR_INDEX);
  return grub_inb (GRUB_MACHINE_PCI_IO_BASE + GRUB_VGA_IO_GR_DATA);
}

static inline void
grub_vga_cr_write (grub_uint8_t val, grub_uint8_t addr)
{
  grub_outb (addr, GRUB_MACHINE_PCI_IO_BASE + GRUB_VGA_IO_CR_INDEX);
  grub_outb (val, GRUB_MACHINE_PCI_IO_BASE + GRUB_VGA_IO_CR_DATA);
}

static inline grub_uint8_t
grub_vga_cr_read (grub_uint8_t addr)
{
  grub_outb (addr, GRUB_MACHINE_PCI_IO_BASE + GRUB_VGA_IO_CR_INDEX);
  return grub_inb (GRUB_MACHINE_PCI_IO_BASE + GRUB_VGA_IO_CR_DATA);
}

static inline void
grub_vga_cr_bw_write (grub_uint8_t val, grub_uint8_t addr)
{
  grub_outb (addr, GRUB_MACHINE_PCI_IO_BASE + GRUB_VGA_IO_CR_BW_INDEX);
  grub_outb (val, GRUB_MACHINE_PCI_IO_BASE + GRUB_VGA_IO_CR_BW_DATA);
}

static inline grub_uint8_t
grub_vga_cr_bw_read (grub_uint8_t addr)
{
  grub_outb (addr, GRUB_MACHINE_PCI_IO_BASE + GRUB_VGA_IO_CR_BW_INDEX);
  return grub_inb (GRUB_MACHINE_PCI_IO_BASE + GRUB_VGA_IO_CR_BW_DATA);
}

static inline void
grub_vga_sr_write (grub_uint8_t val, grub_uint8_t addr)
{
  grub_outb (addr, GRUB_MACHINE_PCI_IO_BASE + GRUB_VGA_IO_SR_INDEX);
  grub_outb (val, GRUB_MACHINE_PCI_IO_BASE + GRUB_VGA_IO_SR_DATA);
}

static inline grub_uint8_t
grub_vga_sr_read (grub_uint8_t addr)
{
  grub_outb (addr, GRUB_MACHINE_PCI_IO_BASE + GRUB_VGA_IO_SR_INDEX);
  return grub_inb (GRUB_MACHINE_PCI_IO_BASE + GRUB_VGA_IO_SR_DATA);
}

static inline void
grub_vga_palette_read (grub_uint8_t addr, grub_uint8_t *r, grub_uint8_t *g,
		       grub_uint8_t *b)
{
  grub_outb (addr, GRUB_MACHINE_PCI_IO_BASE + GRUB_VGA_IO_PALLETTE_READ_INDEX);
  *r = grub_inb (GRUB_MACHINE_PCI_IO_BASE + GRUB_VGA_IO_PALLETTE_DATA);
  *g = grub_inb (GRUB_MACHINE_PCI_IO_BASE + GRUB_VGA_IO_PALLETTE_DATA);
  *b = grub_inb (GRUB_MACHINE_PCI_IO_BASE + GRUB_VGA_IO_PALLETTE_DATA);
}

static inline void
grub_vga_palette_write (grub_uint8_t addr, grub_uint8_t r, grub_uint8_t g,
			grub_uint8_t b)
{
  grub_outb (addr, GRUB_MACHINE_PCI_IO_BASE + GRUB_VGA_IO_PALLETTE_WRITE_INDEX);
  grub_outb (r, GRUB_MACHINE_PCI_IO_BASE + GRUB_VGA_IO_PALLETTE_DATA);
  grub_outb (g, GRUB_MACHINE_PCI_IO_BASE + GRUB_VGA_IO_PALLETTE_DATA);
  grub_outb (b, GRUB_MACHINE_PCI_IO_BASE + GRUB_VGA_IO_PALLETTE_DATA);
}

static inline void
grub_vga_write_arx (grub_uint8_t val, grub_uint8_t addr)
{
  grub_inb (GRUB_MACHINE_PCI_IO_BASE + GRUB_VGA_IO_INPUT_STATUS1_REGISTER);
  grub_inb (GRUB_MACHINE_PCI_IO_BASE + 0x3ba);

  grub_outb (addr, GRUB_MACHINE_PCI_IO_BASE + GRUB_VGA_IO_ARX);
  grub_inb (GRUB_MACHINE_PCI_IO_BASE + GRUB_VGA_IO_ARX_READ);
  grub_outb (val, GRUB_MACHINE_PCI_IO_BASE + GRUB_VGA_IO_ARX);
}

static inline grub_uint8_t
grub_vga_read_arx (grub_uint8_t addr)
{
  grub_uint8_t val;
  grub_inb (GRUB_MACHINE_PCI_IO_BASE + GRUB_VGA_IO_INPUT_STATUS1_REGISTER);
  grub_outb (addr, GRUB_MACHINE_PCI_IO_BASE + GRUB_VGA_IO_ARX);
  val = grub_inb (GRUB_MACHINE_PCI_IO_BASE + GRUB_VGA_IO_ARX_READ);
  grub_outb (val, GRUB_MACHINE_PCI_IO_BASE + GRUB_VGA_IO_ARX);
  return val;
}

#endif
