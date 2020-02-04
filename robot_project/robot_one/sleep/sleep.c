#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <time.h>
time_t  g_now;
struct  tm  *w;
 
void sleep_func()
{
    static count = 0;
    printf("sleeping.....time: %02d h\n", w -> tm_hour);
}
 
void init_sigaction()
{
    struct sigaction act;
          
    act.sa_handler = sleep_func; //设置处理信号的函数
    act.sa_flags  = 0;
 
    sigemptyset(&act.sa_mask);
    sigaction(SIGPROF, &act, NULL);//时间到发送SIGROF信号
}
 
void init_time()
{
    struct itimerval val;
         
    val.it_value.tv_sec = 1; //1秒后启用定时器
    val.it_value.tv_usec = 0;
 
    val.it_interval = val.it_value; //定时器间隔为1s
 
    setitimer(ITIMER_PROF, &val, NULL);
}
 
int sleeping()
{
 
   time(&g_now);
   w = localtime(&g_now);
   
   init_sigaction();
   init_time();
   while((w -> tm_hour >= 22) || (w -> tm_hour <=7));
   return 0;
}
