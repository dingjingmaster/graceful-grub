/* Based on sys/io.h from GNU libc. */

#ifndef	GRUB_IO_H
#define	GRUB_IO_H	1

typedef unsigned short int grub_port_t;

static __inline unsigned char
grub_inb (unsigned short int port)
{
  unsigned char _v;

  asm volatile ("inb %w1,%0":"=a" (_v):"Nd" (port));
  return _v;
}

static __inline unsigned short int
grub_inw (unsigned short int port)
{
  unsigned short _v;

  asm volatile ("inw %w1,%0":"=a" (_v):"Nd" (port));
  return _v;
}

static __inline unsigned int
grub_inl (unsigned short int port)
{
  unsigned int _v;

  asm volatile ("inl %w1,%0":"=a" (_v):"Nd" (port));
  return _v;
}

static __inline void
grub_outb (unsigned char value, unsigned short int port)
{
  asm volatile ("outb %b0,%w1": :"a" (value), "Nd" (port));
}

static __inline void
grub_outw (unsigned short int value, unsigned short int port)
{
  asm volatile ("outw %w0,%w1": :"a" (value), "Nd" (port));

}

static __inline void
grub_outl (unsigned int value, unsigned short int port)
{
  asm volatile ("outl %0,%w1": :"a" (value), "Nd" (port));
}

#endif /* _SYS_IO_H */
