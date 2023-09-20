#include "shell.h"
/**
 * exit_shell - Handle the 'exit' built-in shell command.
 * @commnd: The command and its arguments.
 * @argv: The program's arguments.
 * @status: The exit status to update.
 * @idx: Index of the command in the input.
 */
void exit_shell(char **commnd, char **argv, int *status, int idx)
{
    int exit_value = (*status);
    char *index, mssg[] = ": exit: illegal number: ";

    if (commnd[1])
    {
        if (is_positive_number(commnd[1]))
        {
            exit_value = _atoi(commnd[1]);
        }
        else
        {
            index = _itoa(idx);
            write(STDERR_FILENO, argv[0], _strlen(argv[0]));
            write(STDERR_FILENO, ": ", 2);
            write(STDERR_FILENO, index, _strlen(index));
            write(STDERR_FILENO, mssg, _strlen(mssg));
            write(STDERR_FILENO, commnd[1], _strlen(commnd[1]));
            write(STDERR_FILENO, "\n", 1);
            free(index);
            freearray2D(commnd);
            (*status) = 2;
            return;
        }
    }

    freearray2D(commnd);
    exit(exit_value);
}