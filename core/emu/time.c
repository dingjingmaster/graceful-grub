#include "../grub-datetime.h"
#include <time.h>

grub_err_t
grub_get_datetime (struct grub_datetime *datetime)
{
  struct tm *mytm;
  time_t mytime;

  mytime = time (&mytime);
  mytm = gmtime (&mytime);

  datetime->year = mytm->tm_year + 1900;
  datetime->month = mytm->tm_mon + 1;
  datetime->day = mytm->tm_mday;
  datetime->hour = mytm->tm_hour;
  datetime->minute = mytm->tm_min;
  datetime->second = mytm->tm_sec;

  return GRUB_ERR_NONE;
}

grub_err_t
grub_set_datetime (struct grub_datetime *datetime __attribute__ ((unused)))
{
  return grub_error (GRUB_ERR_NOT_IMPLEMENTED_YET,
		     "no clock setting routine available");
}
