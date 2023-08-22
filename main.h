#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stddef.h>
#define BUFF_SIZE 1024
#include "functions.h"
#include <unistd.h>
int _printf(const char *format, ...);
int _printf(const char *format, ...);
void print_buffer(char buffer[], int *buff_ind);
int (*handler)(va_list, char *, int);
int _write(const char *str, int len);
int _printf(const char *format, ...);
va_start(argp, format);
int handle_char(va_list argp, char *buffer, int buffer_index);
#endif
