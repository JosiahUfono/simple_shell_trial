#include "shell.h"
/**
 * print_env - Handle the 'env' built-in shell command.
 * @commnd: The command and its arguments.
 * @status: The exit status to update.
 */

void print_env(char **commnd, int *status)
{
    int i;

    for (i = 0; environ[i]; i++)
    {
        write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
        write(STDOUT_FILENO, "\n", 1);
    }

    freearray2D(commnd);
    (*status) = 0;
}