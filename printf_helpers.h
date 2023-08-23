#ifndef PRINTF_HELPERS_H
#define PRINTF_HELPERS_H

#include <stdarg.h>

#define BUFF_SIZE 1024

// Function declarations
int get_flags(const char *format, int *index);
int get_width(const char *format, int *index, va_list args);
int get_precision(const char *format, int *index, va_list args);
int get_size(const char *format, int *index);
int handle_print(const char *format, int *index, va_list args,
                 char buffer[], int flags, int width, int precision, int size);

#endif // PRINTF_HELPERS_H

