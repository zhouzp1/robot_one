#include "stdio.h"

void walk(){
   int i = 0;
   while(i < 100000){
      i++;
      sleep(1);
      printf("running>>>>>>>>>>>>>>>>>\n\n");
      talk();
   };
}
