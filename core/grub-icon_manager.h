#ifndef GRUB_ICON_MANAGER_H
#define GRUB_ICON_MANAGER_H

#include "core/grub-menu.h"
#include "core/grub-bitmap.h"

/* Forward declaration of opaque structure handle type.  */
typedef struct grub_gfxmenu_icon_manager *grub_gfxmenu_icon_manager_t;

grub_gfxmenu_icon_manager_t grub_gfxmenu_icon_manager_new (void);
void grub_gfxmenu_icon_manager_destroy (grub_gfxmenu_icon_manager_t mgr);
void grub_gfxmenu_icon_manager_clear_cache (grub_gfxmenu_icon_manager_t mgr);
void grub_gfxmenu_icon_manager_set_theme_path (grub_gfxmenu_icon_manager_t mgr,
                                               const char *path);
void grub_gfxmenu_icon_manager_set_icon_size (grub_gfxmenu_icon_manager_t mgr,
                                              int width, int height);
struct grub_video_bitmap *
grub_gfxmenu_icon_manager_get_icon (grub_gfxmenu_icon_manager_t mgr,
                                    grub_menu_entry_t entry);

#endif /* GRUB_ICON_MANAGER_HEADER */

