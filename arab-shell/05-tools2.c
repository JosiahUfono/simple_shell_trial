#include "shell.h"
/**
 * _itoa - Convert an integer to a string.
 * @o: The integer to convert.
 *
 * Return: A dynamically allocated string representing the integer.
 */
char *_itoa(int o)
{
    char buffer[20];
    int m = 0;

    if (o == 0)
        buffer[m++] = '\0';
    else
    {
        while (o > 0)
        {
            buffer[m++] = (o % 10) + '0';
            o /= 10;
        }
    }
    buffer[m] = '\0';
    reverse_string(buffer, m);
    return (_strdup(buffer));
}

/**
 * reverse_string - Reverse a string in place.
 * @str: The string to reverse.
 * @len: The length of the string.
 */
void reverse_string(char *str, int len)
{
    int start = 0;
    int end = len - 1;
    char tmp;

    while (start < end)
    {
        tmp = str[start];
        str[start] = str[end];
        str[end] = tmp;
        start++;
        end--;
    }
}