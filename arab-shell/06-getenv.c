#include "shell.h"


char *_getenv(char *variable)
{
    char *tmp, *key, *value, *env;
    int m;

    for (m = 0; environ[m]; m++)
    {
        tmp = _strdup(environ[m]);
        key = strtok(tmp, "=");
        if (_strcmp(key, variable) == 0)
        {
            value = strtok(NULL, "\n");
            env = _strdup(value);
            free(tmp);
            return (env);
        }
        free(tmp), tmp = NULL;
    }
    return (NULL);
}

