#include "shell.h"

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
        ptr[m] = str [m];
    }
        return (ptr);
        
}


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


int _strlen(const char *s)
{
    int len = 0;

    while (s[len])
       len++;
    return (len);
}


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