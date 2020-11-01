#include <stdarg.h>
#include <stdio.h>

void dbg_printf(const char *fmt, ...)
{
    printf("\n");
    va_list args;
    va_start(args, fmt);
    vfprintf(stdout, fmt, args);
    va_end(args);
}


#define DEBUG_MSG_PRINT(msg, ...) dbg_printf(msg)