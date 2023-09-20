#include "shell.h"
/**
 * freearray2D - Free a 2D array of strings and its individual elements.
 * @array: The 2D array to free.
 */
void freearray2D(char **array)
{
    int m;

    if (!array)
        return;

    for (m = 0; array[m]; m++)
    {
        free(array[m]);
        array[m] = NULL;
    }
    free(array);
    array = NULL;
}

/**
 * print_error - Print an error message to standard error.
 * @name: The name of the program.
 * @cmd: The command that caused the error.
 * @idx: The index of the command in the input.
 */
void print_error(char *name, char *cmd, int idx)
{
    char *index, mssg[] = ": not found\n";
    index = _itoa(idx);

    write(STDERR_FILENO, name, _strlen(name));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, index, _strlen(index));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, cmd, _strlen(cmd));
    write(STDERR_FILENO, mssg, _strlen(mssg));
    free(index);
}
