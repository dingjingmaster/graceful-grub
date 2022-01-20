#ifndef GRUB_BITMAP_H
#define GRUB_BITMAP_H

#include "grub-err.h"
#include "grub-symbol.h"
#include "grub-types.h"
#include "grub-video.h"

struct grub_video_bitmap
{
  /* Bitmap format description.  */
  struct grub_video_mode_info mode_info;

  /* Pointer to bitmap data formatted according to mode_info.  */
  void *data;
};

struct grub_video_bitmap_reader
{
  /* File extension for this bitmap type (including dot).  */
  const char *extension;

  /* Reader function to load bitmap.  */
  grub_err_t (*reader) (struct grub_video_bitmap **bitmap,
                        const char *filename);

  /* Next reader.  */
  struct grub_video_bitmap_reader *next;
};
typedef struct grub_video_bitmap_reader *grub_video_bitmap_reader_t;

void EXPORT_FUNC (grub_video_bitmap_reader_register) (grub_video_bitmap_reader_t reader);
void EXPORT_FUNC (grub_video_bitmap_reader_unregister) (grub_video_bitmap_reader_t reader);

grub_err_t EXPORT_FUNC (grub_video_bitmap_create) (struct grub_video_bitmap **bitmap,
						   unsigned int width, unsigned int height,
						   enum grub_video_blit_format blit_format);

grub_err_t EXPORT_FUNC (grub_video_bitmap_destroy) (struct grub_video_bitmap *bitmap);

grub_err_t EXPORT_FUNC (grub_video_bitmap_load) (struct grub_video_bitmap **bitmap,
						 const char *filename);

/* Return bitmap width.  */
static inline unsigned int
grub_video_bitmap_get_width (struct grub_video_bitmap *bitmap)
{
  if (!bitmap)
    return 0;

  return bitmap->mode_info.width;
}

/* Return bitmap height.  */
static inline unsigned int
grub_video_bitmap_get_height (struct grub_video_bitmap *bitmap)
{
  if (!bitmap)
    return 0;

  return bitmap->mode_info.height;
}

void EXPORT_FUNC (grub_video_bitmap_get_mode_info) (struct grub_video_bitmap *bitmap,
						    struct grub_video_mode_info *mode_info);

void *EXPORT_FUNC (grub_video_bitmap_get_data) (struct grub_video_bitmap *bitmap);

#endif /* ! GRUB_BITMAP_HEADER */
