#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stddef.h>
#define BUFF_SIZE 1024
#include "functions.h"
#include <unistd.h>
#include <string.h>

int _printf(const char *format, ...);
void print_buffer(char buffer[], int *buff_ind);
int _write(const char *str, int len);
int handle_integer(va_list argp, char *buffer, int buffer_index);
int handle_char(va_list argp, char *buffer, int buffer_index);
int handle_float(va_list argp, char *buffer, int buffer_index);
int handle_unknown(char specifier, char *buffer, int buffer_index);


#endif
