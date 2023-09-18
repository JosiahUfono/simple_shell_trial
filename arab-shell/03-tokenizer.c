#include "shell.h"

char **tokenizer(char *line)
{
    int m = 0, n = 0;
    char *token, *tmp, **array = NULL;
    
    if (!line)
       return (NULL);

    tmp = _strdup(line);
    token = strtok(tmp, DELIM);
    if (!token)
    {
        free(line), line = NULL;
        free(tmp), tmp = NULL;
        return (NULL);
    }

    while (token)
    {
        n++;
        token = strtok(NULL, DELIM);
    }
    free(tmp), tmp = NULL;

    array = malloc(sizeof(char *) * (n + 1));
    if (!array)
    {
        free(line), line = NULL;
        free(tmp), tmp = NULL;
        return (NULL);
    }
    
    token = strtok(line, DELIM);
    while (token)
    {
        array[m++] = _strdup(token);
        token = strtok(NULL, DELIM);
    }
    array[m] = NULL;
    free(line), line = NULL;

    return (array);
}