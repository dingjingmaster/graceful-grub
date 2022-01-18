#include "core/grub-types.h"
#include "core/grub-fs.h"
#include "core/util/install.h"

#include <string.h>
#pragma GCC diagnostic ignored      "-Wmissing-prototypes"
#pragma GCC diagnostic ignored      "-Wmissing-declarations"
#include <argp.h>
#pragma GCC diagnostic error        "-Wmissing-prototypes"
#pragma GCC diagnostic error        "-Wmissing-declarations"


static char            *target;
static int              removable = 0;
static int              recheck = 0;
static int              updateNvram = 1;
static char            *installDevice = NULL;
static char            *debugImage = NULL;
static char            *rootdir = NULL;
static char            *bootdir = NULL;
static int              allowFloppy = 0;
static int              forceFileID = 0;
static char            *diskModule = NULL;
static char            *efidir = NULL;
static char            *macppcdir = NULL;
static int              force = 0;
static int              haveAbstractions = 0;
static int              haveCryptodisk = 0;
static char            *bootloaderID;
static int              haveLoadCfg = 0;
static FILE            *loadCfgF = NULL;
static char            *loadCfg;
static int              installBootsector = 1;
static char            *labelFont;
static char            *labelColor;
static char            *labelBgcolor;
static char            *productVersion;
static int              addRsCodes = 1;

enum
{
    OPTION_BOOT_DIRECTORY = 0x301,
    OPTION_ROOT_DIRECTORY,
    OPTION_TARGET,
    OPTION_SETUP,
    OPTION_MKRELPATH,
    OPTION_MKDEVICEMAP,
    OPTION_PROBE,
    OPTION_EDITENV,
    OPTION_ALLOW_FLOPPY,
    OPTION_RECHECK,
    OPTION_FORCE,
    OPTION_FORCE_FILE_ID,
    OPTION_NO_NVRAM,
    OPTION_REMOVABLE,
    OPTION_BOOTLOADER_ID,
    OPTION_EFI_DIRECTORY,
    OPTION_FONT,
    OPTION_DEBUG,
    OPTION_DEBUG_IMAGE,
    OPTION_NO_FLOPPY,
    OPTION_DISK_MODULE,
    OPTION_NO_BOOTSECTOR,
    OPTION_NO_RS_CODES,
    OPTION_MACPPC_DIRECTORY,
    OPTION_LABEL_FONT,
    OPTION_LABEL_COLOR,
    OPTION_LABEL_BGCOLOR,
    OPTION_PRODUCT_VERSION
};

static int fs_probe = 1;

int main (int argc, char* argv[])
{
    int                         isEFI = 0;
    const char                 *efiDistributor = NULL;
    const char                 *efiFile = NULL;
    char                      **grubDevices = NULL;
    grub_fs_t                   grubFS;
    grub_device_t               grubDev = NULL;
    enum grub_install_plat      platform;
    char                       *grubdir, *deviceMap;
    char                      **curdev, **curdrive;
    char                      **grubDrives;
    char                       *relativeGrubdir;
    char                      **efidirDeviceNames = NULL;
    grub_device_t               efidirGrubDev = NULL;
    char                       *efidirGrubDevname;
    int                         efidirIsMac = 0;
    int                         isPrep = 0;
    const char                 *pkgdatadir;

    grub_util_host_init (&argc, &argv);
    productVersion = xstrdup (PACKAGE_VERSION);
    pkgdatadir = grub_util_get_pkgdatadir ();
    labelFont = grub_util_path_concat (2, pkgdatadir, "unicode.pf2");
}
