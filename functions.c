#include <unistd.h>
#include "functions.h"
#include <stdarg.h>
#include <stdio.h>
void print_char(char c)
{
	write(1, &c, 1);
}

void print_string(const char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		print_char(str[i]);
		i++;
	}
}

void print_percent(void)
{
	print_char('%');
}

int handle_integer(va_list argp, char *buffer, int buffer_index)
{
        int num = va_arg(argp, int);
        char int_buffer[20];
        int digits = 0;

        if (num < 0)
        {
                buffer[buffer_index++] = '-';
                num  = -num;
        }

        do
        {
                int_buffer[digits++] = (num % 10) + '0';
                num /= 10;
        }
        while
                (num > 0);
                while (digits > 0)
                {
                        buffer[buffer_index++] = int_buffer[--digits];
                }

                return buffer_index;
}

int handle_float(va_list argp, char *buffer, int buffer_index)
{
        double num = va_arg(argp, double);

        int len = sprintf(&buffer[buffer_index], "%.2f", num);

        return len;
}

int handle_char(va_list argp, char *buffer, int buffer_index)
{
    char c = (char)va_arg(argp, int);
    buffer[buffer_index] = c;
    return 1;
}

int handle_unknown(char specifier, char *buffer, int buffer_index)
{
	buffer[buffer_index++] = '%';
	buffer[buffer_index++] = specifier;
	return buffer_index;
}
#include <stdlib.h> // For malloc and free

char *itoa(int num)
{
    int sign = (num < 0) ? -1 : 1; // Store the sign of the number
    num = abs(num); // Make the number positive

    int num_digits = 1; // Count the number of digits in the number
    int temp = num;
    while (temp >= 10)
    {
        temp /= 10;
        num_digits++;
    }

    // Allocate memory for the string
    char *str = (char *)malloc((num_digits + 1) * sizeof(char));
    if (str == NULL)
        return NULL; // Memory allocation failed

    // Convert the integer to string in reverse order
    int i = 0;
    while (num > 0)
    {
        str[i++] = num % 10 + '0';
        num /= 10;
    }

    // Add the sign character if the original number was negative
    if (sign == -1)
        str[i++] = '-';

    // Null-terminate the string
    str[i] = '\0';

    // Reverse the string to get the correct order
    int start = 0;
    int end = i - 1;
    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }

    return str;
}

