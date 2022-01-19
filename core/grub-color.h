#ifndef GRUB_VIDEO_COLOR_H
#define GRUB_VIDEO_COLOR_H

#include "core/grub-video.h"

int grub_video_get_named_color (const char *name,
				grub_video_rgba_color_t *color);

grub_err_t grub_video_parse_color (const char *s,
				   grub_video_rgba_color_t *color);

#endif
