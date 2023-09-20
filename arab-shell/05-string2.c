#include "shell.h"
/**
 * _strcmp - Compare two strings.
 * @s1: The first string.
 * @s2: The second string.
 * Return: An integer less than, equal to, or greater than zero if s1 is found,
 *         respectively, to be less than, to match, or be greater than s2.
 */
int _strcmp(const char *s1, const char *s2)
{
    int cmp;
    cmp = (int)*s1 - (int)*s2;
    while (*s1)
    {
        if (*s1 != *s2)
            break;
        s1++;
        s2++;
        cmp = (int)*s1 - (int)*s2;
    }
    return (cmp);
}

/**
 * _strlen - Calculate the length of a string.
 * @s: The input string.
 *
 * Return: The length of the string.
 */
int _strlen(const char *s)
{
    int len = 0;

    while (s[len])
        len++;

    return (len);
}