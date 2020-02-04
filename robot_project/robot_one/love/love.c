#include "stdio.h"
#include "math.h"
#include <termios.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <unistd.h>

extern int love_core(double zoom);
static once = 0;

int love_core(double zoom){
   double row_mov = 0.0l, row_size = 0.0l, col_size = 0.0l, col_mov = 0.0l;
   struct winsize size = {0};

   ioctl(STDIN_FILENO, TIOCGWINSZ, &size);
   row_mov = size.ws_col / 2.0l;
   row_size = size.ws_col / 2.0l / 2.0l;
   col_size = size.ws_row / 2.5l;
   int size_ws_row = size.ws_row;

   double symble = 1.0l;
   int col = 0, col_max = 0, col_all_max = 0;
   double row_min = -row_size + row_mov;

   row_size = zoom * row_size;
   col_size = zoom * col_size;
   double row_max = row_size + row_mov;
   for(double row_add = row_max; row_add >= row_min; row_add
         = row_add - 0.0002l / zoom){
      double row_tra = (row_add - row_mov) / row_size;

      if((1.0l - row_tra * row_tra) < 0) continue;
      if (rand() % 2)
         symble = 1.0l;
      else
         symble = -1.0l;

      col = (int)(((pow((1.0l - row_tra * row_tra), 1.0l / 2.0l) * symble) +
               pow(row_tra * row_tra, 1.0l / 3.0l)) *
            col_size);

      if (col > col_max) col_max = col;
      if ((row_tra == 0) && (symble < 0)) col_all_max = col_max - col;
      int row = (row_add);
      if (once == 1)
         printf("%d\33[%d;%dH", 0, (col_max - col + (int)col_mov), row);
   }
   once = 1;
}

int love_clean(){
   struct winsize size = {0};
   ioctl(STDIN_FILENO, TIOCGWINSZ, &size);
   printf("\33[%d;%dH", size.ws_row, 0);
}

int show_love(){
   system("clear");
   double zoom = 1.0L;
   for(zoom = 1; zoom >= 0.1; zoom = zoom - 0.2l / zoom) {
      love_core(zoom);
   }
   once = 1;
   love_clean();
   sleep(1);
}
