#ifndef GUI_H
#define GUI_H

#define MAX_ARGS 31
#define MAX_STR_LEN 512

#define NORM   "\x1B[0m"
#define SELECT "\x1B[7m"
#define BOLD   "\x1B[1m"
#define GREEN  "\x1B[32m"
#define RED    "\x1B[31m"
#define GREY   "\x1B[37m"
#define BLINK  "\x1B[5m"

#define BACKSPACE 8
#define DELETE 127
#define ESCAPE '\033'

#define EXITING_PROGRAM -1

#define JUSTIFY_LEFT -1
#define JUSTIFY_CENT 0
#define JUSTIFY_RIGHT 1

void line(char *lSide, char *print, char *rSide);

void cent(char *lSide, char *fill, char *rSide, const char *fmt, ...);
void left(char *lSide, char *fill, char *rSide, const char *fmt, ...);
void right(char *lSide, char *fill, char *rSide, const char *fmt, ...);

#endif