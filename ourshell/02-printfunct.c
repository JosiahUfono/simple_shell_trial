#include "main.h"


int _putchar(char c)
{
	return (write(1, &c, 1));
}

int _putstring(char *str)
{
	int  k = 0, count = 0;
	while (str[k])
    {
		count += _putchar(str[k++]);
    }
    return (count);
}
