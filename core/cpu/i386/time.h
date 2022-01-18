#ifndef KERNEL_CPU_TIME_H
#define KERNEL_CPU_TIME_H

static __inline void
grub_cpu_idle (void)
{
  /* FIXME: this can't work until we handle interrupts.  */
/*  asm volatile ("hlt"); */
}

#endif /* ! KERNEL_CPU_TIME_HEADER */
