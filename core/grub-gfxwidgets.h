#ifndef GRUB_GFXWIDGETS_H
#define GRUB_GFXWIDGETS_H

#include "grub-video.h"

typedef struct grub_gfxmenu_box *grub_gfxmenu_box_t;

struct grub_gfxmenu_box
{
  /* The size of the content.  */
  int content_width;
  int content_height;

  struct grub_video_bitmap **raw_pixmaps;
  struct grub_video_bitmap **scaled_pixmaps;

  void (*draw) (grub_gfxmenu_box_t self, int x, int y);
  void (*set_content_size) (grub_gfxmenu_box_t self,
                            int width, int height);
  int (*get_border_width) (grub_gfxmenu_box_t self);
  int (*get_left_pad) (grub_gfxmenu_box_t self);
  int (*get_top_pad) (grub_gfxmenu_box_t self);
  int (*get_right_pad) (grub_gfxmenu_box_t self);
  int (*get_bottom_pad) (grub_gfxmenu_box_t self);
  void (*destroy) (grub_gfxmenu_box_t self);
};

grub_gfxmenu_box_t grub_gfxmenu_create_box (const char *pixmaps_prefix,
                                            const char *pixmaps_suffix);

#endif /* ! GRUB_GFXWIDGETS_HEADER */
