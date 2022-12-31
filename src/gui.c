#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/ioctl.h>
#include "gui.h"

size_t utf8len(char *s) {
    size_t len = 0;
    for (; *s; ++s) if ((*s & 0xC0) != 0x80) ++len;
    return len;
}

void repeat_print(char *print, int n, int option, int is_odd) {
   int print_len = utf8len(print);
   int remainder = n % print_len;
   if(option == JUSTIFY_LEFT && remainder) {
      char trunc[remainder];
      strncpy(trunc, print, remainder);
      printf("%s", trunc);
   }
   int i = 0;
   while(i < n / print_len) {
      printf("%s", print);
      i++;
   }
   if(option == JUSTIFY_RIGHT && remainder) {
      char trunc[remainder];
      strncpy(trunc, print, remainder);
      printf("%s", trunc);
   }
   if(is_odd) printf("%c", print[0]);
}

void space_cent(char *print, int contents, int sides, int option, int is_odd) {
   struct winsize w;
   ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
   repeat_print(print, (w.ws_col - contents - sides)/2, option, is_odd);
}

void space_side(char *print, int contents, int sides) {
   struct winsize w;
   ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
   repeat_print(print, (w.ws_col - contents - sides), JUSTIFY_RIGHT, false);
}

void line(char *lSide, char *print, char *rSide) {
   const int side_len = utf8len(lSide) + utf8len(rSide);
   printf("%s", lSide);
   space_side(print, 0, side_len);
   printf("%s\n", rSide);
}


// Passing va_list: https://groups.google.com/g/comp.lang.c/c/ebSEB3V3iP0
//                  https://cplusplus.com/reference/cstdarg/va_copy/

// Calculates displayable string length (naive causes ANSI control [zero width], 
//                                       arrow chars, emojis to count incorrect)
int disp_str_len(const char *fmt, va_list va) {
   // Calculates naive length
   char *buffer = malloc(MAX_STR_LEN*sizeof(char));
   vsnprintf(buffer, MAX_STR_LEN, fmt, va);
   int len = utf8len(buffer);
   free(buffer);
   // Inspects fmt, noting that '\x1B' is already excluded by vsnprintf
   // --> only [_m needs to be excluded (but varies as _ can be double digit)
   int i = 0;
   int j = 0;
   int num_ctrl = 0;
   char curr_c = -1;
   char next_c = -1;
   while(curr_c != '\0') {
      curr_c = fmt[i];
      if(curr_c == '\x1B') {
         j = 0;
         next_c = -1;
         while(next_c != 'm' && next_c != '\0') {
            next_c = fmt[i+j];
            num_ctrl++;
            j++;
         }
      }
      i++;
   }
   return (len-num_ctrl);
}

void justify(char *lSide, char *fill, char *rSide, int option, const char *fmt, ...) {
   // Defaults fill to whitespace
   if(fill[0] == '\0') {
      fill = " ";
   }
   // Retrieves winodw dimensions --> w.ws_col and w.ws_row available for use
   struct winsize w;
   ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

   const int side_len = utf8len(lSide) + utf8len(rSide);

   // Pointer to va (of caller) passed in as "..."
   va_list va;
   va_list *va_pointer;
   // Retrieves ... into va (in this case, just said pointer)
   va_start(va, fmt);
   // Retrieves first (and only) arg, and assigns (future uses must be *dereferenced)
   va_pointer = va_arg(va, va_list *);

   // Makes copy of va for character counting
   va_list va_count;
   va_copy(va_count, *va_pointer);
   // const int len = vsnprintf(NULL, 0, fmt, va_count);
   const int len = disp_str_len(fmt, va_count);
   va_end(va_count);

   printf("%s", lSide);
   if(option == JUSTIFY_CENT) {
      space_cent(fill, len, side_len, JUSTIFY_LEFT, false);
   } else if(option == JUSTIFY_RIGHT) {
      space_side(fill, len, side_len);
   }
   vprintf(fmt, *va_pointer);
   if(option == JUSTIFY_CENT) {
      if((w.ws_col - len - side_len)%2) {
         space_cent(fill, len, side_len, JUSTIFY_RIGHT, true);
      } else {
         space_cent(fill, len, side_len, JUSTIFY_RIGHT, false);
      }
      // if((w.ws_col - len - side_len)%2) printf("%c", fill[0]);
   } else if(option == JUSTIFY_LEFT) {
      space_side(fill, len, side_len);
   }
   printf("%s\n", rSide);
   va_end(va);
}

void cent(char *lSide, char *fill, char *rSide, const char *fmt, ...) {
   va_list va;
   va_start(va, fmt);
   justify(lSide, fill, rSide, JUSTIFY_CENT, fmt, &va);
   va_end(va);
}

void left(char *lSide, char *fill, char *rSide, const char *fmt, ...) {
   va_list va;
   va_start(va, fmt);
   justify(lSide, fill, rSide, JUSTIFY_LEFT, fmt, &va);
   va_end(va);
}

void right(char *lSide, char *fill, char *rSide, const char *fmt, ...) {
   va_list va;
   va_start(va, fmt);
   justify(lSide, fill, rSide, JUSTIFY_RIGHT, fmt, &va);
   va_end(va);
}
