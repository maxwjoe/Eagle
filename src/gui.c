#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "gui.h"

#define MAX_ARGS 31

// int str_arr_len(char **print) {
//    for(int i = 0; i < )
// }

void space_cent(char *print, int contents, int sides) {
   struct winsize w;
   ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
   
   int i = 0;
   
   while(i < (w.ws_col - contents - sides) / 2) {
      printf("%s", print);
      i++;
   }
}

void space_side(char *print, int contents, int sides) {
   struct winsize w;
   ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
   
   int i = 0;
   
   while(i < (w.ws_col - contents - sides)) {
      printf("%s", print);
      i++;
   }
}

void line(char *lSide, char *print, char *rSide) {
   
   printf("%s", lSide);
   space_cent(print, 0, 2);
   space_cent(print, 0, 2);
   printf("%s\n", rSide);
}


// FIX UP - STRLEN IS READING ARROWS AS MULT CHARS, MESSING UP CENTRING
void cent(char *lSide, char *rSide, const char *fmt, ...) {
   struct winsize w;
   ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

   va_list va;

   va_start(va, fmt);
   const int len = vsnprintf(NULL, 0, fmt, va);
   va_end(va);

   va_start(va, fmt);

   printf("%s", lSide);
   space_cent(" ", len, 2);
   if((w.ws_col - len - 2)%2) printf(" ");
   vprintf(fmt, va);
   space_cent(" ", len, 2);
   printf("%s\n", rSide);

   va_end(va);
}

void left(char *lSide, char *rSide, const char *fmt, ...) {
   struct winsize w;
   ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

   va_list va;

   va_start(va, fmt);
   const int len = vsnprintf(NULL, 0, fmt, va);
   va_end(va);

   va_start(va, fmt);

   printf("%s", lSide);
   vprintf(fmt, va);
   space_side(" ", len, 2);
   printf("%s\n", rSide);

   va_end(va);
}

void right(char *lSide, char *rSide, const char *fmt, ...) {
   struct winsize w;
   ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

   va_list va;

   va_start(va, fmt);
   const int len = vsnprintf(NULL, 0, fmt, va);
   va_end(va);

   va_start(va, fmt);

   printf("%s", lSide);
   space_side(" ", len, 2);
   vprintf(fmt, va);
   printf("%s\n", rSide);

   va_end(va);
}
