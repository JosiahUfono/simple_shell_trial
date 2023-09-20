#include "shell.h"

/**
 * _getenv - Get the value of an environment variable.
 * @variable: The name of the environment variable.
 *
 * Return: The value of the environment variable, or NULL if not found.
 */
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
            return env;
        }
        free(tmp);
    }

    return NULL;
}
