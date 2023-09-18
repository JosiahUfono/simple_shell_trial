#include "shell.h"

/**
 * main - the simple shell main function
 * @ac: this counts of arguments
 * @argv: Arguments
 * Return: 0 Always (success)
*/

int main (int ac, char **argv)
{
    char *line = NULL, **command = NULL;
    int status = 0, idx = 0;
    (void) ac;
    

    while (1)
    {
        line = read_line();
        if (line == NULL) /* Reach EOF ctr + D */
        {
            if (isatty(STDIN_FILENO))
               write(STDOUT_FILENO, "\n", 1);
            return (status);
        }

        idx++;
        command = tokenizer(line);
        if (!command)
           continue;
        
        status = _execute(command, argv, idx);
         
    }
}    