#include "main.h"


int main(int c, char **env)
{
    (void)c;
    char *prompt = "(enter_command)$ ", *buffer = NULL, *path;
    size_t buffersize = 0;
    char *arg[101], *delim = " \n";
    ssize_t stringVariable;
    pid_t Child_id;
    int i, j, status, executable;

    while (1)
    {
       if(isatty(0))
       _putstring(prompt);

        stringVariable = getline(&buffer, &buffersize, stdin);
    
    if (stringVariable == -1)
    {
        free(buffer);
       _putstring("\n"); 
        exit(0);
    }

    i = 0;
    while (buffer[i])
    {
        if (buffer[i] == '\n')
           buffer[i] = 0;
           i++;
    }

    j = 0;
    arg[j] = strtok(buffer, delim);
    while (arg[j])
    {
        arg[++j] = strtok(NULL, delim);
        
    }
    arg[j] = NULL;


    path = path_getter(arg[0]);

    if (path == NULL)
    {
       if (_builtin(arg) != 0)
       {
        continue;
       }
       else
          _putstring("Command not found\n");
          continue;
       
    }

    Child_id = fork();
    if (Child_id < 0)
    {
        _putstring("fork failed");
        free(buffer);
        exit(0);
    }
    else if (Child_id == 0)
    {
        executable = execve(path, arg, env);
			if (executable == -1)
        _putstring("Command does not exist\n");
    }
    else 
      wait(&status);
    
     /*_putstring(buffer);*/

    }
    free(path);
    free(buffer);
    
    return (0);

}
