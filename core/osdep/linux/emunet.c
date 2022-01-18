#include "config.h"
#include "config-util.h"

#include <sys/socket.h>
#include <sys/types.h>
#include <linux/if.h>
#include <linux/if_tun.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <string.h>

#include "core/emu/net.h"

static int fd;

grub_ssize_t
grub_emunet_send (const void *packet, grub_size_t sz)
{
  return write (fd, packet, sz);
}

grub_ssize_t
grub_emunet_receive (void *packet, grub_size_t sz)
{
  return read (fd, packet, sz);
}

int
grub_emunet_create (grub_size_t *mtu)
{
  struct ifreq ifr;
  *mtu = 1500;
  fd = open ("/dev/net/tun", O_RDWR | O_NONBLOCK);
  if (fd < 0)
    return -1;
  memset (&ifr, 0, sizeof (ifr));
  ifr.ifr_flags = IFF_TAP | IFF_NO_PI;
  if (ioctl (fd, TUNSETIFF, &ifr) < 0)
    {
      close (fd);
      fd = -1;
      return -1;
    }
  return 0;
}

void
grub_emunet_close (void)
{
  if (fd < 0)
    return;

  close (fd);
  fd = -1;
}
