#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - printf function
 * @format: format
 *
 * Return: printed chars
 */

int _write(const char *str, int len) {
    return write(1, str, len);
}

int _printf(const char *format, ...) {
    if (format == NULL) {
        return -1;
    }

    va_list argp;
    int count = 0;

    va_start(argp, format);

    while (*format) {
        if (*format != '%') {
            _write(format, 1);
            count++;
        } else {
            format++;

            if (*format == 'c') {
                char c = va_arg(argp, int);
                _write(&c, 1);
                count++;
            } else if (*format == 's') {
                char *s = va_arg(argp, char *);
                if (s == NULL) {
                    _write("(null)", 6);
                    count += 6;
                } else {
                    _write(s, strlen(s));
                    count += strlen(s);
                }
            } else if (*format == '%') {
                _write("%", 1);
                count++;
            }
        }
        format++;
    }

    va_end(argp);
    return count;
}


void print_buffer(char buffer[], int *buff_ind);

int _printf(const char *format, ...)
{
	int i, printed_chars = 0, buff_ind = 0, len = 0;
	va_list list;
	char buffer[BUFF_SIZE];
	
	if (format == NULL)
		return (-1);//Handle NULL format edge case
	va_start(list, format);
	for (i = 0; format[i] != '\0'; i++)
		if (format[i] != '%')
	{
		if (buff_ind == BUFF_SIZE - 1)
		{
			print_buffer(buffer, &buff_ind);
			printed_chars += buff_ind;
		}
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				char c = (char)va_arg(list, int);
				buffer[buff_ind++] = c;
			}

					else if (format[i] == 's')
				{
					char *str  = va_arg(list, char *);
					int j;
					for (j = 0; str[j] != '\0'; j++)
					{
						if (buff_ind == BUFF_SIZE - 1)
						{
							print_buffer(buffer, &buff_ind);
							printed_chars += buff_ind;
						}
						buffer[buff_ind++] = str[j];
					}
				}
			else if (format[i] == '%')
			{
				buffer[buff_ind++] = '%';
				len++;
			}
		}
		else
		{
			buffer[buff_ind++] = format[i];
			len++;
		}
	}

	print_buffer(buffer, &buff_ind);
	va_end(list);
	return (printed_chars);
}
/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @buffer: input value
 * @buff_ind: input value
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		write(1, buffer, *buff_ind);
		*buff_ind = 0;
	}
}
