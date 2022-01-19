#ifndef GRUB_NET_TCP_H
#define GRUB_NET_TCP_H

#include "core/grub-types.h"
#include "core/grub-net.h"

struct grub_net_tcp_socket;
typedef struct grub_net_tcp_socket *grub_net_tcp_socket_t;

struct grub_net_tcp_listen;
typedef struct grub_net_tcp_listen *grub_net_tcp_listen_t;

grub_net_tcp_socket_t
grub_net_tcp_open (char *server,
		   grub_uint16_t out_port,
		   grub_err_t (*recv_hook) (grub_net_tcp_socket_t sock,
					    struct grub_net_buff *nb,
					    void *data),
		   void (*error_hook) (grub_net_tcp_socket_t sock,
				       void *data),
		   void (*fin_hook) (grub_net_tcp_socket_t sock,
				     void *data),
		   void *hook_data);

grub_net_tcp_listen_t
grub_net_tcp_listen (grub_uint16_t port,
		     const struct grub_net_network_level_interface *inf,
		     grub_err_t (*listen_hook) (grub_net_tcp_listen_t listen,
						grub_net_tcp_socket_t sock,
						void *data),
		     void *hook_data);

void
grub_net_tcp_stop_listen (grub_net_tcp_listen_t listen);

grub_err_t
grub_net_send_tcp_packet (const grub_net_tcp_socket_t socket,
			  struct grub_net_buff *nb,
			  int push);

enum
  {
    GRUB_NET_TCP_CONTINUE_RECEIVING,
    GRUB_NET_TCP_DISCARD,
    GRUB_NET_TCP_ABORT
  };

void
grub_net_tcp_close (grub_net_tcp_socket_t sock, int discard_received);

grub_err_t
grub_net_tcp_accept (grub_net_tcp_socket_t sock,
		     grub_err_t (*recv_hook) (grub_net_tcp_socket_t sock,
					      struct grub_net_buff *nb,
					      void *data),
		     void (*error_hook) (grub_net_tcp_socket_t sock,
					 void *data),
		     void (*fin_hook) (grub_net_tcp_socket_t sock,
				       void *data),
		     void *hook_data);

void
grub_net_tcp_stall (grub_net_tcp_socket_t sock);

void
grub_net_tcp_unstall (grub_net_tcp_socket_t sock);

#endif
