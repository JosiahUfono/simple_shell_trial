#include "shell.h"

/**
 * _strdup - Duplicate a string.
 * @str: The string to duplicate.
 *
 * Return: A pointer to the duplicated string, or NULL on failure.
 */
char *_strdup(const char *str)
{
    char *ptr;
    int m, len = 0;

    if (str == NULL)
        return (NULL);

    while (str[len])
        len++;

    ptr = malloc(sizeof(char) * (len + 1));
    if (ptr == NULL)
        return (NULL);
        
    for (m = 0; m <= len; m++)
    {
        ptr[m] = str[m];
    }

    return (ptr);
}