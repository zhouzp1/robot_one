#include <stdio.h>
#include <time.h>

struct tm *get_time()
{
   time_t  g_now;
   struct  tm  *g_w;
   time(&g_now);
   g_w = localtime(&g_now);
   printf("%p\n", g_w);
   printf("%04d/%02d/%02d %02d:%02d:%02d\n", g_w -> tm_year + 1900,
	  g_w -> tm_mon + 1, g_w -> tm_mday, g_w -> tm_hour,
	  g_w -> tm_min, g_w -> tm_sec);
   return (struct tm *)g_w;
}
