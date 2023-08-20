#include <unistd.h>


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
