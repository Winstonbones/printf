#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stddef.h>
#define BUFF_SIZE 1024
#include "functions.h"
#include <unistd.h>
int _printf(const char *format, ...);
void print_buffer(char buffer[], int *buff_ind);

#endif
