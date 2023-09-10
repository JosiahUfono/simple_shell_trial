#include "main.h"

/*While loop recalls the prompt until it is exited (CTRL+C). But exit or end of file eof returns a 
	-1 which is same value returned but stringVariable which holds the number of strings
	from the prompt*/

	/*To ensure there is no memory leaks, its imperrative we free buffer after every possible case
	whether successful or not */

	/*execve() takes in a path of the file or dir where the command is executed ans the comand itself */
	/*To get data from the cli, we'll be using a stdin function getline()
	getline takes thre params, a pointer to the string (passed as an address (&...)), the length or size of the string
	of type size_t ( also passed as an address (&...)) and the stdin text

	sample:
	#include <stdio.h>
	#include <stdlib.h>
	int main(void)
	{
	char *line =NULL;
	size_t len = 0;
	ssize_t lineSize = 0;

	printf("Please enter a line:\n");
	lineSize = getline(&line, &len, stdin);

	printf("You entered %s, which has %zu chars.\n", line, lineSize -1);

	free(line);
	return 0;
	}
	*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}

int _putstring(char *str)
{
	int count = 0, k = 0;

	while (str[k] != 0)
		count += _putchar(str[k++]);
	return (count);
}

int main(int c, char **env)
{

	(void)c;
	char *prompt = "(enter command)$ ", *buffer = NULL;
	char *arg[128], *delim = " \n";
	size_t buffersize = 0;
	ssize_t stringVariable;
	pid_t Child_id;
	int status, i, j, exe;
    const char *name = "PATH";
    char *value;

    value = getenv(name);
	
	while(1)
	{
		if (isatty(0))
			_putstring(prompt);

		stringVariable = getline(&buffer, &buffersize, stdin);

		if (stringVariable == -1)
		{
			/*If end of file or CTRL+C, exit prompt*/
			free(buffer);
			exit(0);
		}

		/*for execeve to be executed, it should be terminated with a null terminator*/
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

		/*allocate momery to the arg[0] for the buffer (inputed data)*/
		Child_id = fork();

		if (Child_id < 0)
		{
			_putstring("Fork failed");
			free(buffer);
			exit(0);
		}
		else if(Child_id == 0)
		{
            char * word = strtok(buffer, " ");
        char path[128] = "/bin/";
        strcat(path, word);

    // Execute the process
        char * newenvp[] = { NULL };
        char * newargv[] = { path, NULL };
    	exe = execve(path, newargv, newenvp);

        if(exe == -1)
        perror("execve error");
        return EXIT_SUCCESS;
	}
		else
			wait(&status);

	}
	free(buffer);
	return (0);
}