#include "shell.h"

/**
 * is_builtin - Check if a command is a built-in shell command.
 * @commnd: The command to check.
 *
 * Return: 1 if the command is built-in, 0 otherwise.
 */
int is_builtin(char *commnd)
{
    char *builtins[] =
    {
        "exit", "env", "setenv", "cd", NULL
    };
    int i;

    for (i = 0; builtins[i]; i++)
    {
        if (_strcmp(commnd, builtins[i]) == 0)
            return (1);
    }

    return (0);
}

/**
 * handle_builtin - Handle execution of built-in shell commands.
 * @commnd: The command and its arguments.
 * @argv: The program's arguments.
 * @status: The exit status to update.
 * @idx: Index of the command in the input.
 */
void handle_builtin(char **commnd, char **argv, int *status, int idx)
{
    if (_strcmp(commnd[0], "exit") == 0)
        exit_shell(commnd, argv, status, idx);
    else if (_strcmp(commnd[0], "env") == 0)
        print_env(commnd, status);
}