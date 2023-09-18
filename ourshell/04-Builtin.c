#include "main.h"

int _builtin(char **arg)
{
    if (strcmp(arg[0], "exit") == 0)
    {
        _putstring("Exiting shell.....\n");
        exit(0);
    }
    else if (strcmp(arg[0], "cd") == 0)
    {
        if (arg[1] == NULL)
            chdir(getenv("HOME"));
        else 
           (chdir(arg[1]));
    }


    return(0);
}
