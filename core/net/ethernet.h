#ifndef GRUB_NET_ETHERNET_H
#define GRUB_NET_ETHERNET_H
#include "core/grub-types.h"
#include "core/grub-net.h"

/* IANA Ethertype */
typedef enum
  {
    GRUB_NET_ETHERTYPE_IP = 0x0800,
    GRUB_NET_ETHERTYPE_ARP = 0x0806,
    GRUB_NET_ETHERTYPE_IP6 = 0x86DD,
  } grub_net_ethertype_t;

grub_err_t 
send_ethernet_packet (struct grub_net_network_level_interface *inf,
		      struct grub_net_buff *nb,
		      grub_net_link_level_address_t target_addr,
		      grub_net_ethertype_t ethertype);
grub_err_t 
grub_net_recv_ethernet_packet (struct grub_net_buff *nb,
			       struct grub_net_card *card);

#endif 
