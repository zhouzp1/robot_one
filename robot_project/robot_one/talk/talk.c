#include <unistd.h>
#include "stdio.h"
#include "stdlib.h"
#include <string.h>

#define say printf
char rember[] = "who are you ?";
struct string  *walk_str = "walk";
char robot_self_contr[] = "i am a robot\n";
char listen_buff[200] = {0};

struct string
{
   char buff[100];
};

int talk(){
   struct string *str[100] = {0};
   struct string *str_rember[100] = {0};
   const char *split = " ,.";
   char *p = 0;
   char *p_rember = 0;
   int str_num = 0;
   int str_num_rember = 0;
   say("\033[33m"); gets(listen_buff);
   p = strtok(listen_buff, split);
   while((p != 0) && (str_num < 99)){
      str[str_num] = p;
      str_num++;
      p = strtok(0, split);
   }

   char temp_rember[200] = {0};
   strcpy(temp_rember,rember);
   p_rember = strtok(temp_rember, split);
   while((p_rember != 0) && (str_num_rember < 99)){
      str_rember[str_num_rember] = p_rember;
      str_num_rember++;
      p_rember = strtok(0, split);
   }

   for (int i = str_num - 1; i >=0; i--){
      for(int j = str_num_rember - 1; j >=0; j--){
         if (strcmp(str_rember[j], str[i]) == 0)
         {
            say("\033[31m%s\033[0m", robot_self_contr);
            goto next;
         }
         if(strcmp(walk_str,str[i]) == 0)
         {
            goto next;
         }
      }
   }
next:
   ;
}
