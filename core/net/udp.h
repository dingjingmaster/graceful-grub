#ifndef GRUB_NET_UDP_H
#define GRUB_NET_UDP_H

#include "core/grub-types.h"
#include "core/grub-net.h"

struct udphdr
{
  grub_uint16_t src;
  grub_uint16_t dst;
  grub_uint16_t len;
  grub_uint16_t chksum;
} GRUB_PACKED;

struct grub_net_udp_socket;
typedef struct grub_net_udp_socket *grub_net_udp_socket_t;

grub_net_udp_socket_t
grub_net_udp_open (grub_net_network_level_address_t addr,
		   grub_uint16_t out_port,
		   grub_err_t (*recv_hook) (grub_net_udp_socket_t sock,
					    struct grub_net_buff *nb,
					    void *data),
		   void *recv_hook_data);

void
grub_net_udp_close (grub_net_udp_socket_t sock);

grub_err_t
grub_net_send_udp_packet (const grub_net_udp_socket_t socket,
			  struct grub_net_buff *nb);


#endif 