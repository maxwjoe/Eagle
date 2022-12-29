#ifndef EAGLE_LOG_H
#define EAGLE_LOG

#include "stdio.h"

#define LOG_RED(X) printf("\e[0;31m%s\x1b[0m", X);
#define LOG_GREEN(X) printf("\e[0;32m%s\x1b[0m", X);

#endif