#include "main.h"
#define BUFF_SIZE 1024

/**
 * _printf - printf function
 * @format: format
 *
 * Return: printed chars
 */
typedef struct 
{
	char *format;
	int (*handler)(va_list, char *, int);
} FormatHandler;

int _write(const char *str, int len)
{
	return write(1, str, int len);
}
int _printf(const char *format, ...) {
    if (format == NULL) {
        return -1;  // Handle NULL format edge case
    }

    va_list argp;
    int count = 0;
    char buffer[BUFF_SIZE];
    int buffer_index = 0;

    va_start(argp, format);

    while (*format) {
        if (*format != '%') {
            buffer[buffer_index++] = *format++;
            count++;
        } else {
            format++;

            FormatHandler handlers[] = {
                {"c", handle_char},
                {"s", handle_string},
                /* Add more format handlers as needed */
            };

            int found = 0;
            for (size_t i = 0; i < sizeof(handlers) / sizeof(handlers[0]); i++) {
                if (strncmp(format, handlers[i].format, strlen(handlers[i].format)) == 0) {
                    found = 1;
                    format += strlen(handlers[i].format);
                    buffer_index = handlers[i].handler(argp, buffer, buffer_index);
                    break;
                }
            }

            if (!found) {
                buffer[buffer_index++] = '%';
                count++;
            }
        }

        if (buffer_index >= BUFSIZE - 1) {
            _write(buffer, buffer_index);
            buffer_index = 0;
        }
    }
 }

    va_end(argp);
    if (buffer_index > 0) {
        _write(buffer, buffer_index);
    }

    return count;
}

int handle_char(va_list argp, char *buffer, int buffer_index) {
    char c = va_arg(argp, int);
    buffer[buffer_index++] = c;
    return buffer_index;
}

int handle_string(va_list argp, char *buffer, int buffer_index) {
    char *s = va_arg(argp, char *);
    if (s == NULL) {
        s = "(null)";  // Handle NULL string edge case
    }
    strcpy(buffer + buffer_index, s);
    buffer_index += strlen(s);
    return buffer_index;
}

void print_buffer(char buffer[], int *buff_ind);


int _printf(const char *format, ...)
{
	int i, printed_chars = 0, buff_ind = 0;
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
				}
		}
		else
		{
			buffer[buff_ind++] = format[i];
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
