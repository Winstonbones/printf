#include <unistd.h>
<<<<<<< HEAD


=======
#include "functions.h"

>>>>>>> 013e741c452aec0e494c6de77df8778be0f05559
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
