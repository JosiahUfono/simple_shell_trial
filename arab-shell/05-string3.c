#include "shell.h"
/**
 * _strcat - Concatenate two strings.
 * @dest: The destination string.
 * @src: The source string to append.
 * Return: A pointer to the concatenated string.
 */
char *_strcat(char *dest, const char *src)
{
    char *q = dest;

    while (*q)
        q++;
    while (*src)
    {
        *q = *src;
        q++;
        src++;
    }
    *q = '\0';
    return (dest);
}

/**
 * _strcpy - Copy a string from src to dest.
 * @dest: The destination string.
 * @src: The source string to copy.
 * Return: A pointer to the destination string.
 */
char *_strcpy(char *dest, const char *src)
{
    int m = 0;

    while (src[m])
    {
        dest[m] = src[m];
        m++;
    }
    dest[m] = '\0';
    return (dest);
}