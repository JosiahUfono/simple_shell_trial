#include "shell.h"

char *read_line(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t o;
    
    write(STDOUT_FILENO, "$ ", 2);
    o = getline(&line, &len, stdin);
    if ( o == -1)
    {
        free (line);
        return (NULL);
    }
    

    return (line);
}