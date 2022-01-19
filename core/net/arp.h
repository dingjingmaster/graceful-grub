#ifndef GRUB_NET_ARP_H
#define GRUB_NET_ARP_H
#include "core/grub-misc.h"
#include "core/grub-net.h"

extern grub_err_t grub_net_arp_receive (struct grub_net_buff *nb,
                                        struct grub_net_card *card,
                                        grub_uint16_t *vlantag);

grub_err_t
grub_net_arp_send_request (struct grub_net_network_level_interface *inf,
                           const grub_net_network_level_address_t *proto_addr);

#endif 
