#ifndef GRUB_PS2_H
#define GRUB_PS2_H

#include "core/grub-types.h"

#define GRUB_AT_ACK                     0xfa
#define GRUB_AT_NACK                    0xfe
#define GRUB_AT_TRIES                   5

/* Make sure it's zeroed-out and set current_set at init.  */
struct grub_ps2_state
{
  int e0_received;
  int f0_received;
  grub_uint8_t led_status;
  short at_keyboard_status;
  grub_uint8_t current_set;
};

/* If there is a key pending, return it; otherwise return GRUB_TERM_NO_KEY.  */
int
grub_ps2_process_incoming_byte (struct grub_ps2_state *ps2_state,
				grub_uint8_t data);

#endif
